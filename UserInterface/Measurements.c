/***********************************************************************
 *
 *
 *  COPYRIGHT: Arxtron Technologies Inc. All Rights Reserved.
 *
 *  PURPOSE: - C6 Calibration measurement functions
 *
 *  DEVELOPMENT HISTORY:
 *
 *  Date        Name           Rev.   Description
 *  ----------  -------------  -----  -----------------------
 *  08-14-2013  Arxtron    		1.0      Initial Release
 *  
 *  
 *********************************************************************/
/*!
*    @file    Measurements.c
*    @brief   Perform calibrations and measurements
*    @author  Arxtron Technologies Inc.
*    @date    2013.10.09
*    Functions to calibrate and measure RF signals
*    
*/ 
#ifndef _DEBUG
#define _DEBUG
#endif

#include <windows.h>  
#include "cvixml.h"
#include <analysis.h>
#include <formatio.h>
#include <utility.h>
#include <ansi_c.h>  
#include <userint.h>

#include "Global.h"
#include "Measurements.h"
#include "CANCommand.h"  
#include "CANDrv.h"
#include "SIC_MRR.h"
#include "SpectrumDrv.h"
#include "app_log.h"
#include "itacLayer_LIB.h"
#include "timeUtils.h"
#include "TestSteps.h"

// SRR Configuration and Limit - should probably be moved to Config file
#define UWB_INIT_SLOPE								-0.27   // db/DAC step
#define UWB_INITIAL_DAC								170 	//  
#define UWB_TARGET_PEAK_POWER						-14.2   //-14.0

#define ISM_INITIAL_DAC								100 // Daimlwe 145 // default 100  

#define CROSS_OVER_FREQUENCY_ADDRESS				77				

#define UWB_DAC_CAL_ADDRESS							177
#define DAC_E2P_LOW_ADDRESS							80
#define DAC_E2P_HIGH_ADDRESS						86

#define MAX_NUM_CAL_ATTEMPTS						7				

#define TRUE										1
#define FALSE										0
#define PASS										1
#define FAIL										0

static int trace = 1;								// Spectrum Analyzer trace number
static int marker = 1;							    // Spectrum Analyzer marker number
static int SensorAddress = 1;						// Both MPIO and MPI1 are grounded

/********************************************************
*
* FUNCTION NAME: GetSensorTemperature
* 
* DESCRIPTION: Get DUT temperature
*
* ARGUMENT LIST: 
* 
* ARGUMENT           TYPE     I/O    DESCRIPTION       
* --------           ----     ---    -----------
* testUnit	 	   	 int
*
* OUTPUTS
* temperature		 int 
*
* RETURNS: 			 int
*					(0 = no error)
*				
* 
* 
*********************************************************/
/********************************************//**
* Get DUT temperature
***********************************************/ 
int GetSensorTemperature(int testUnit, int *temperature)
{
	int error=1, numAttempts = 0, maxAttempts = 4;
	char msg[80];				
    unsigned char MeasData[128];                

	for(int i = 0; i < 128; i++)
      MeasData[i] = 255;
	
    // Get Sensor Temperature
    while ((error != 0) && (numAttempts++ < maxAttempts))
    {
		error = Get_MeasData_Array_c6(SensorAddress,MeasData,testUnit); 
		if(error)
			NonBlockDelay(0.2);
    }
    *temperature = (int)MeasData[12];

	sprintf(msg,"%s, Temperature=%i",__FUNCTION__,*temperature);
	check_error(error,msg,"Command failed.");
	
	return(error);
} // end GetSensorTemperature

/********************************************************
*
* FUNCTION NAME: ProceedRequest
* 
* DESCRIPTION: Read MIS number from UUT EEPROM and check with ITAC to proceed.
*
* ARGUMENT LIST: 
* 
* ARGUMENT           TYPE     I/O    DESCRIPTION       
* --------           ----     ---    -----------
* testUnit	 	   	 int
* SensorAddress		 int
*
* OUTPUTS
* MIS				 char[23] 
*
* RETURNS: 			 int
*					 (0 = no error)
*				
* 
* 
*********************************************************/
/********************************************//**
* Read MIS number from UUT EEPROM and check with ITAC to proceed.
***********************************************/ 
int ProceedRequest(int testUnit, char *MIS, char ErrorMsg[256])
{
	char msg[80]={0};
	int error=0;
	char txtMsg[100];
    
//DisableSICMsgs(testUnit);
	//error |= GetMISnumber_c6(SensorAddress,testUnit,MIS);
	error |= GetSerialNumberDUT(testUnit, MIS);
	sprintf(dutMIS[testUnit].SerialNumber, MIS); 

	if (ITACIsEnable)
	{
		CmtGetLock(ITAC_LockHandle);  
		itacResult[testUnit]=1;		 //  invalidate itac status in case we fail FID or MIS
		CmtReleaseLock(ITAC_LockHandle);
	}

	if (error != 0)
	{
		decode_error(error,__FUNCTION__,"Unable to get MISnumber");
		return(-1);
	}
	
	// Verify the unit FlavorId
	strncpy(msg, MIS, 4);
	if (atoi(msg) != selRecipe.FlavorId && selRecipe.FlavorId != 0)
	{
		sprintf(ErrorMsg,"Error: Unmatch FlavorId, Unit=%i, Test=%i",atoi(msg),selRecipe.FlavorId);
		return(-2);
	}
	
	sprintf(msg,"MIS #:%s", MIS);
	add_log(msg);
	
	if (ITACIsEnable)
	{
		CmtGetLock(ITAC_LockHandle);  
		// determine if itac allow UUT to proceed
		error |= itac_proceed_request(testUnit, MIS, ErrorMsg);  
		CmtReleaseLock(ITAC_LockHandle);
	}
	
	if (error != 0)
	{
		// sprintf(ErrorMsg,"Unit fails ITAC check.  Verify upstream process.");
		decode_error(error,__FUNCTION__,ErrorMsg);
		return(-3);
	}
	
	//Update "Test Measurements" text message with MIS number.
	sprintf(txtMsg, "Test Measurements - %s                                Low Limit    High Limit", MIS);
	SetCtrlVal(MainPanelHandle, gReportLabel[testUnit], txtMsg);
	
	return(error);
} // end ProceedRequest

/********************************************************
*
* FUNCTION NAME: itac_proceed_request
* 
*/
/********************************************//**
*Send Proceed Request to iTAC
***********************************************/
/*   
*
* ARGUMENT LIST: 
* 
* ARGUMENT           TYPE     I/O    DESCRIPTION       
* --------           ----     ---    -----------
* MIS	 	   	 	 char *
*
* RETURNS: 			 int
*					(0 = no error)
*				
* 
* 
*********************************************************/
int itac_proceed_request(int testUnit, char *MIS_SerialNumber, char ErrorMsg[1000])
{
	int error=0;
	char tempText[100];
	
	itacResult[testUnit] = verifySerial(MIS_SerialNumber, ErrorMsg);

	// get and update ITAC process count  
	sprintf(tempText,"%d",getProcessCount()); 	   
	//SetCtrlVal(MainPanelHandle, gItacCount[testUnit], tempText); 
	ResetTextBox (MainPanelHandle, gItacCount[testUnit], tempText); 

	if (getProcessCount()>=MaxItacProceedRequestCount)
	{
		sprintf(ErrorMsg,"Reached max test count (%d)", getProcessCount());  
		itacResult[testUnit]=1;
	}
	
	if (itacResult[testUnit] == 0)
	{
		add_log(__FUNCTION__);
		return 0;
	}
	else
	{
		decode_error(error,__FUNCTION__,"Command failed");	
		return 1;
	}
	
} // end itac_proceed_request

/********************************************************
*
* FUNCTION NAME: GetFirmwareVersion
* 
* DESCRIPTION: Read firmware version from CAN device
*
* ARGUMENT LIST: 
* 
* ARGUMENT           TYPE     I/O    DESCRIPTION       
* --------           ----     ---    -----------
* testUnit	 	   	 int
* SensorAddress		 int
*
* OUTPUTS
* MIS				 char[23] 
*
* RETURNS: 			 int
*					 (0 = no error)
*				
* 
* 
*********************************************************/
/********************************************//**
* Read firmware version from CAN device
***********************************************/ 
int GetFirmwareVersion(int testUnit, char *swVer)
{
	int error=0;
	int SensorIDArray[5][8]={0};
	int SensorAddress = 1; 
	int numOfFoundSensors;
	char msg[80];

	numOfFoundSensors = Ping_new_c6(SensorIDArray,testUnit); 
	sprintf(swVer, "%d.%d.%d.%d.%d", SensorIDArray[SensorAddress][6],    // boot major version
										SensorIDArray[SensorAddress][7],  // boot minor version
										SensorIDArray[SensorAddress][2],  // app major version
										SensorIDArray[SensorAddress][3],  // app minor version
										SensorIDArray[SensorAddress][4]); // some random digit that means something to someone.

	if (numOfFoundSensors != 1) 
	{
		error = -1;
		sprintf(msg,"Unable to ping @ address %d, sensor cnt = %d",SensorAddress, numOfFoundSensors);
	}
	
	sprintf(msg,"%s, swVer=%s",__FUNCTION__,swVer);
	check_error(error,msg,"Command failed.");
	
	return(error);
} // end GetFirmwareVersion


/********************************************************
*
* FUNCTION NAME: ResetTestUnit
* 
* DESCRIPTION: Perform a soft reset of the test unit.
*
* ARGUMENT LIST: 
* 
* ARGUMENT           TYPE     I/O    DESCRIPTION       
* --------           ----     ---    -----------
* testUnit	 	   	 int
*
* RETURNS: 			 int
*					 (0 = no error)
*				
* 
* 
*********************************************************/
/********************************************//**
* Perform a soft reset of the test unit.
***********************************************/ 
int ResetTestUnit(int testUnit)
{
	int error;
	
	error = SendReset(testUnit);
	
	check_error(error,__FUNCTION__,"Command failed."); 
	return(error);
} // end ResetTestUnit

/********************************************************
*
* FUNCTION NAME: SetSpectrum
* 
* DESCRIPTION: Set spectrum analyzer state
*
* ARGUMENT LIST: 
* 
* ARGUMENT           TYPE     I/O    DESCRIPTION       
* --------           ----     ---    -----------
* sa	 	   	 	 RSSpecAn
*
* RETURNS: 			 int
*					 (0 = no error)
*				
* 
* 
*********************************************************/
/********************************************//**
* Set spectrum analyzer state 
***********************************************/ 
int SetSpectrum(RSSpecAn sa)
{
	int error=0;
	char msg[256];
					
	// check if spectrum is open
	if (!sa.isOpen)
	{
		error = -1;
		sprintf(msg,"%s %s", "Spectrum Analyzer is not open",sa.address);
		decode_error(error,__FUNCTION__,msg);
		return(error); 
	}  // end if
	
	error |= setDisplayUpdate(sa.session,TRUE);
	
	error |= setPreset(sa.session);
	error |= setCenterFreqSpan(sa.session,sa.centerFreq,sa.freqSpan); 
	error |= setResBw(sa.session,sa.resBw);
	error |= setVidBw(sa.session,sa.vidBw);
	error |= setSweepNpts(sa.session,sa.npts);
	error |= setSweepTime(sa.session,sa.sweepTime);
	error |= setAttnValue(sa.session,sa.attn);
	error |= setPreAmp(sa.session,sa.preAmpPow);
	error |= setRefLevel(sa.session,sa.refLevel);
	error |= setRefLevelOffset(sa.session,sa.refLevelOffset);
	
	check_error(error,__FUNCTION__,"Command failed."); 
	
	return(error);
} // end SetSpectrum

/********************************************************
*
* FUNCTION NAME: SetSpectrumNominalCondition
* 
* DESCRIPTION: Set spectrum analyzer to nominal conditions state
*
* ARGUMENT LIST: 
* 
* ARGUMENT           TYPE     I/O    DESCRIPTION       
* --------           ----     ---    -----------
* sa	 	   	 	 RSSpecAn
*
* RETURNS: 			 void
*				
* 
* 
*********************************************************/
/********************************************//**
* Set spectrum analyzer to nominal conditions state 
***********************************************/ 
void SetSpectrumNominalCondition(RSSpecAn sa)
{
	sa.npts = 2001;
	sa.attn = 10.0;
	sa.resBw = 10.0;
	sa.vidBw = 10.0;
	sa.refLevel = 0.0;
	sa.refLevelOffset = 0.0;
} // end SetSpectrumNominalCondition

/********************************************************
*
* FUNCTION NAME: CloseSpectrum
* 
* DESCRIPTION: Close spectrum analyzer session
*
* ARGUMENT LIST: 
* 
* ARGUMENT           TYPE     I/O    DESCRIPTION       
* --------           ----     ---    -----------
* sa	 	   	 	 RSSpecAn
*
* RETURNS: 			 int
*					 (0 = no error)
*				
* 
* 
*********************************************************/
/********************************************//**
* Close spectrum analyzer session 
***********************************************/ 
int CloseSpectrum(RSSpecAn sa)
{
	int error=0;
	
	if (sa.isOpen)
	{	
		error = closeSpectrum(sa.session);
	}
	
	check_error(error,__FUNCTION__,"Unable to close spectrum instrument."); 
	
	return(error);
} // end CloseSpectrum


/********************************************************
*
* FUNCTION NAME: SetSpectrumPreset
* 
* DESCRIPTION: Set spectrum analyzer to a preset state
*
* ARGUMENT LIST: 
* 
* ARGUMENT           TYPE     I/O    DESCRIPTION       
* --------           ----     ---    -----------
* sa		 	   	 RSSpecAn
*
* RETURNS: 			 int
*					 (0 = no error)
*				
* 
* 
*********************************************************/
/********************************************//**
* Set spectrum analyzer to a preset state 
***********************************************/ 
int SetSpectrumPreset(RSSpecAn sa)
{
	int error=-1;
	
	if (sa.isOpen)
	{
		error = setPreset(sa.session);
	}
	
	check_error(error,__FUNCTION__,"Command failed."); 
	
	return(error);
} // end SetSpectrumPreset

/********************************************************
*
* FUNCTION NAME: CalTxBandCrossOverFrequency
* 
* DESCRIPTION: Calibrate UUT transmitter Band1/Band0 crossover frequency
*
* ARGUMENT LIST: 
* 
* ARGUMENT           			TYPE     I/O    DESCRIPTION       
* --------           			----     ---    -----------
* sa	 		   	 			RSSpecAn
* testUnit			 			int
*
* OUTPUTS  
* Band0_Low_FrequencyMHz		int
* Band0_High_FrequencyMHz		int 
* Band1_Low_FrequencyMHz		int 
* Band1_High_FrequencyMHz		int
* TransitionFrequencyMHz		int
*
* RETURNS: 			 			int
*								(0 = no error)
*				
* 
* 
*********************************************************/
/********************************************//**
* Calibrate UUT transmitter Band1/Band0 crossover frequency 
***********************************************/ 
int CalTxBandCrossOverFrequency(RSSpecAn sa, int testUnit, int *Band0_Low_FrequencyMHz, int *Band0_High_FrequencyMHz, int *Band1_Low_FrequencyMHz, int *Band1_High_FrequencyMHz, int *TransitionFrequencyMHz, int only_measure)
{
	int error = 0;
	double pathLoss = UwbPathLossdB[testUnit];
	double TxBand0LoPower = 0.0, TxBand0HiPower = 0.0;
	double TxBand1LoPower = 0.0, TxBand1HiPower = 0.0;  
	 
	// Output values
	double TxBand0LoFreq = 0.0, TxBand0HiFreq = 0.0; 
	double TxBand1LoFreq = 0.0, TxBand1HiFreq = 0.0;    
	int crossOverFreqMHz = 0;
	
	
	/////////////////////////////////////////////////////////////////
	// 1. Set spectrum analyzer for measurement
	////////////////////////////////////////////////////////////////
	SetSpectrumNominalCondition(sa);
	sa.sweepTime = 0.2;
	sa.centerFreq = 24.0;
	sa.freqSpan =  5.0;
	sa.preAmpPow = 0;	 // Disable pre-amp	
	sa.refLevelOffset = pathLoss;
	sa.refLevel = getRefLevel(UWB_TARGET_PEAK_POWER,pathLoss);	   // -14.0dB, 35.0
	error |= SetSpectrum(sa);
	if (error != 0 )
	{
		decode_error(error,__FUNCTION__,"SetSpectrum failed");
		return(-1);
	}
	error |= setMaxHold(sa.session,trace);  

	/////////////////////////////////////////////////////////////////
	// 2. Set DUT to measure TxBand1Hi Power and Freq
	////////////////////////////////////////////////////////////////
	error |= SendTxBand(28000, TX_BAND_1,testUnit);
	error |= getPeakPowerFreq(sa.session,marker,&TxBand1HiPower,&TxBand1HiFreq);
	
	
	/////////////////////////////////////////////////////////////////
	// 3. Set DUT to measure TxBand0Lo Power and Freq
	////////////////////////////////////////////////////////////////
	error |= SendTxBand(20000, TX_BAND_0, testUnit);
	error |= getPeakPowerFreq(sa.session,marker,&TxBand0LoPower,&TxBand0LoFreq);
	
	
	/////////////////////////////////////////////////////////////////
	// 4. calculate CrossOverFreq and store to EEPROM
	////////////////////////////////////////////////////////////////
	crossOverFreqMHz = CalculateTxCrossOverFreq(TxBand1HiFreq,TxBand0LoFreq);
	if ((crossOverFreqMHz > 0) && (error ==0) && !only_measure) // only measure if we are doing a check rather than a cal
	{
		error |= SetEEPROMValue(CROSS_OVER_FREQUENCY_ADDRESS,crossOverFreqMHz, testUnit);  // addr = 77
	//	error |= SensorReset_mt(8, testUnit); //carol added  CLEAN_CODE
		error |= SendReset(testUnit);
	}
	else if(!only_measure)  // Don't error out if we are only measuring.
	{
		error = -1;
	}
	
	// assign output value and update error in log file
	*Band0_Low_FrequencyMHz = TxBand0LoFreq/1e6;
	*Band1_High_FrequencyMHz = TxBand1HiFreq/1e6;
	*TransitionFrequencyMHz = crossOverFreqMHz;
	check_error(error,__FUNCTION__,"Command failed.");
	
	sa.freqSpan =  8.0; 
	error |= SetSpectrum(sa);
		
	/////////////////////////////////////////////////////////////////
	// 5. Set DUT to measure TxBand1Lo Power and Freq
	////////////////////////////////////////////////////////////////
	error |= SendTxBand(20000, TX_BAND_1, testUnit);
	error |= getPeakPowerFreq(sa.session,marker,&TxBand1LoPower,&TxBand1LoFreq);
	
	
	/////////////////////////////////////////////////////////////////
	// 6. Set DUT to measure TxBand0High Power and Freq
	////////////////////////////////////////////////////////////////
	error |= SendTxBand(28000, TX_BAND_0, testUnit);
	error |= getPeakPowerFreq(sa.session,marker,&TxBand0HiPower,&TxBand0HiFreq);
	
	*Band1_Low_FrequencyMHz = TxBand1LoFreq/1e6;
	*Band0_High_FrequencyMHz = TxBand0HiFreq/1e6;
	
	return(error);
} // end CalTxBandCrossOverFrequency





/********************************************************
*
* FUNCTION NAME: CalTxUwbPower
* 
* DESCRIPTION: Calibrate transmitter UWB power
*
* ARGUMENT LIST: 
* 
* ARGUMENT           					TYPE     I/O    DESCRIPTION       
* --------           					----     ---    -----------
* sa				 					RSSpecAn
* testUnit	 	   	 					int
*
* OUTPUTS  
* TxCalibratedUwbPeakPwr				double
* TxCalibratedUwbPeakFrequency			double
* TxAdjustmentMargin					double
* CalibratedDacValue					int
* CalibratedDACValues100MHzBins			int[]
*
* RETURNS: 			 					int
*										(0 = no error)
*				
* 
* 
*********************************************************/
/********************************************//**
* Calibrate transmitter UWB power
***********************************************/ 
int CalTxUwbPower(RSSpecAn sa,int testUnit,
				double *TxCalibratedUwbPeakPwr,
				double *TxCalibratedUwbPeakFrequency,
				double *TxAdjustmentMargin,
				int *CalibratedDacValue,
				int CalibratedDACValues100MHzBins[14],
				double *deltaPowerOverUwbBand)
{
	int error = 0;
	double pathLoss = UwbPathLossdB[testUnit];  
	char msg[256];
	
	// Parameters in calibration phase 1
	int calStep=0;
	int calIsSuccessful=FALSE;  
	int calIsCompleted=FALSE;
	double calSlope; 
	int numAttempts = 0;
	double uwbInitialPower = 0.0;
	
	// Parameters in calibration phase 2 and 3
	int nPoints = 2001;
	double traceData[2001]={0.0};
	int currentPoint=0.0; 
	int traceLen=0;
	int nBins = 14;
	double peakPowerInBin[14]={0.0};
	int nPointsInEachBin=0; 
	double currentPeakPowerInBin=0.0;
	double maxBinPower = -99.9;
	double minBinPower = 99.9;
		
	double powerAtMaxUwbDac = 0.0;  
	
	// Output parameters
	*TxCalibratedUwbPeakPwr = 0.0;
	*TxCalibratedUwbPeakFrequency = 0.0;
	*TxAdjustmentMargin = 0.0;
	*CalibratedDacValue = 0;
	memset(CalibratedDACValues100MHzBins,0,14);
	*deltaPowerOverUwbBand = 0.0;
	
	
		
	/////////////////////////////////////////////////////////////////
	// 1. Set instrument ready for measurement
	////////////////////////////////////////////////////////////////
	SetSpectrumNominalCondition(sa); 
	sa.sweepTime = 2.0;
	sa.centerFreq = 24.9;
	sa.freqSpan =  1.4;
	sa.npts = 2001;
	sa.refLevelOffset = pathLoss;
	sa.refLevel = getRefLevel(UWB_TARGET_PEAK_POWER,pathLoss); 
	
	error |= SetSpectrum(sa);
	error |= setMaxHold(sa.session,trace);
	error |= setPreAmp(sa.session,1);  // enable pre-amp
	
	
	// Start DUT in normal UWB operation mode
	/////////////////////////////////////////////////////////////////////// 
	// 2. Do Phase 1 calibration using following steps
	//	0) Initial UWB DAC value
	//	1) Using initial UWB DAC slope
	//  2) Using calculated UWB DAC slope
	//  3) Increment UWB DAC step to decrease power 
	//  4) or Decrement UWB DAC step to increase power
	/////////////////////////////////////////////////////////////////////// 

	calSlope = UWB_INIT_SLOPE;
	while(!calIsCompleted)
	{
		switch(calStep)
		{
			case 0:
				/////////////////////////////////////////////////////////////////
				// 2.0. calibrate using initial DAC value 
				////////////////////////////////////////////////////////////////
				*CalibratedDacValue=UWB_INITIAL_DAC;
				error |= GetCalibratedTxUwbPower(calStep,sa.session,testUnit,*CalibratedDacValue,TxCalibratedUwbPeakPwr,TxCalibratedUwbPeakFrequency,&calIsSuccessful,&calIsCompleted);
				
				if (!calIsCompleted)
				{
					uwbInitialPower=*TxCalibratedUwbPeakPwr;
					calStep = 1;		// goto next calStep
				}
				numAttempts++;
				break;
			case 1:	
				/////////////////////////////////////////////////////////////////
				// 2.1. calibration using initial slope 
				////////////////////////////////////////////////////////////////
				*CalibratedDacValue = adjustedDac(UWB_INITIAL_DAC,UWB_TARGET_PEAK_POWER,uwbInitialPower,calSlope); 	// slope = -0.27dB/DAC step
				error |= GetCalibratedTxUwbPower(calStep,sa.session,testUnit,*CalibratedDacValue,TxCalibratedUwbPeakPwr,TxCalibratedUwbPeakFrequency,&calIsSuccessful,&calIsCompleted);
				
				if (!calIsCompleted)
				{
					calStep = 2;		// goto next calStep
				}
				numAttempts++;
				break;
			case 2: 
				/////////////////////////////////////////////////////////////////
				// 2.2. calibrate using calculated slope 
				////////////////////////////////////////////////////////////////
				calSlope = (*TxCalibratedUwbPeakPwr-uwbInitialPower)/(*CalibratedDacValue-UWB_INITIAL_DAC);
				*CalibratedDacValue = adjustedDac(*CalibratedDacValue,UWB_TARGET_PEAK_POWER,*TxCalibratedUwbPeakPwr,calSlope); 
				error |= GetCalibratedTxUwbPower(calStep,sa.session,testUnit,*CalibratedDacValue,TxCalibratedUwbPeakPwr,TxCalibratedUwbPeakFrequency,&calIsSuccessful,&calIsCompleted);
				
				if (!calIsCompleted)
				{
					if (*TxCalibratedUwbPeakPwr > UwbPowerHighLimit)
					{
						calStep = 3;		// continue cal by increase DAC to reduce power
					}
					else if (*TxCalibratedUwbPeakPwr < UwbPowerLowLimit)
					{
						calStep = 4; 		// continue cal by decrease DAC to increase power
					}
					else
					{
						calIsCompleted = TRUE;
						calIsSuccessful = TRUE;
					}
				}
				numAttempts++;
				break;
			case 3:	 
				////////////////////////////////////////////////////////////////////////////////
				// 2.3. calibrate by increase DAC value to reduce power when power is too high 
				/////////////////////////////////////////////////////////////////////////////////
				*CalibratedDacValue += 1;   // start cal
				
				if ((*CalibratedDacValue < UwbDacHighLimit) && (numAttempts < MAX_NUM_CAL_ATTEMPTS))
				{
					error |= GetCalibratedTxUwbPower(calStep,sa.session,testUnit,*CalibratedDacValue,TxCalibratedUwbPeakPwr,TxCalibratedUwbPeakFrequency,&calIsSuccessful,&calIsCompleted);
				
					if (!calIsCompleted)
					{
						// check if calibration power overshoot its limit and redo cal from last previous CalibratedDacValue 
						if (*TxCalibratedUwbPeakPwr < UwbPowerLowLimit)
						{
							*CalibratedDacValue -= 2; 		 
						}
					}
				} 
				else
				{
					calIsCompleted = TRUE;
					calIsSuccessful = FALSE;	
				}
				numAttempts++; 
				break;
			case 4: 
				////////////////////////////////////////////////////////////////////////////////
				// 2.4. calibrate by decrease DAC value to increase power when power is too low 
				/////////////////////////////////////////////////////////////////////////////////
				*CalibratedDacValue -= 1;
				
				if ((*CalibratedDacValue > UwbDacLowLimit) && (numAttempts < MAX_NUM_CAL_ATTEMPTS))
				{
					error |= GetCalibratedTxUwbPower(calStep,sa.session,testUnit,*CalibratedDacValue,TxCalibratedUwbPeakPwr,TxCalibratedUwbPeakFrequency,&calIsSuccessful,&calIsCompleted);
				
					if (!calIsCompleted)
					{
						if (*TxCalibratedUwbPeakPwr > UwbPowerHighLimit)
						{
							*CalibratedDacValue += 2; 		// redo previous calibration if overshoot cal limit  
						}
					}
				} 
				else
				{
					calIsCompleted = TRUE;
					calIsSuccessful = FALSE;
				}
				numAttempts++;   
				break;
			default:
				calIsCompleted = TRUE;
				calIsSuccessful = FALSE;								  
				sprintf(msg,"CalTxUwbPower incorrect calStep");
				decode_error(error,__FUNCTION__,msg);
				break;
		} // end switch
	} // end while
	
	/////////////////////////////////////////////////////////////////////// 
	// 3.  Do Phase 2
	// 	Capture the power trace and calculate the adjust UWB DAC value for each 100 MHz bin
	// 	Use only BIN3 to BIN14 data as UWB signal is Tx from 24.6-25.6 GHz
	/////////////////////////////////////////////////////////////////////// 
	error |= fetchTraceData(sa.session,trace,nPoints,traceData,&traceLen);
	if (error != 0)
	{
		sprintf(msg,"Unable to read trace data");
		decode_error(error,__FUNCTION__,msg);
		return(-1);
	}
		
	
	///// calculate the peak power per 100MHz bins  /////
	nPointsInEachBin = traceLen/nBins;				 // 142 points/bin
	for(int i=0;i<nBins;i++)
	{
		currentPeakPowerInBin = -999.9;
		for (int j=0;j<nPointsInEachBin;j++)
		{
			currentPoint = i*nPointsInEachBin+j;
			if(traceData[currentPoint] > currentPeakPowerInBin)
			{
				currentPeakPowerInBin = traceData[currentPoint];
			}
		}
		peakPowerInBin[i]=currentPeakPowerInBin;	
		sprintf(msg,"Bin=%i, peakPowerInBin=%10.2f",i,peakPowerInBin[i]);
		add_log(msg);
	} // end for loop
	
	
	///// Calculate the adjusted DAC values per 100 MHz bins  /////
	for(int i=0;i<nBins;i++)
	{
		CalibratedDACValues100MHzBins[i]=adjustedDac(*CalibratedDacValue,*TxCalibratedUwbPeakPwr,peakPowerInBin[i],calSlope);    // TODO  
			
		// Don't allow DAC less than 10 or UWB_MIN_DAC
		if(CalibratedDACValues100MHzBins[i] < UwbDacLowLimit)
			CalibratedDACValues100MHzBins[i] = UwbDacLowLimit;
		
		if(CalibratedDACValues100MHzBins[i] > UwbDacHighLimit)
			CalibratedDACValues100MHzBins[i] = UwbDacHighLimit;
	} // end for loop
	
	// Use the same DAC for the first 4 bins
	CalibratedDACValues100MHzBins[0]=CalibratedDACValues100MHzBins[3];
	CalibratedDACValues100MHzBins[1]=CalibratedDACValues100MHzBins[3];
	CalibratedDACValues100MHzBins[2]=CalibratedDACValues100MHzBins[3];
	
	///// Compute the store adjusted DAC values ////
	int nDacStoredValues = 7;
	int calDacStoredArray[nDacStoredValues];
	for(int i=0; i<nDacStoredValues; i++)
	{
		calDacStoredArray[i]=((CalibratedDACValues100MHzBins[2*i] << 8) & 0xff00) + CalibratedDACValues100MHzBins[2*i+1];   
		sprintf(msg,"DacAddress=%i, low=%i, hi=%i, calDacStoredArray=%i",80+i,CalibratedDACValues100MHzBins[2*i],CalibratedDACValues100MHzBins[2*i+1],calDacStoredArray[i]);
		add_log(msg);
	}
	

	///// Calculate the delta power over UWB band /////
	for (int i=3; i<nBins; i++)
	{
		if (peakPowerInBin[i] > maxBinPower)
		{
			maxBinPower = peakPowerInBin[i];
		}
		if (peakPowerInBin[i] < minBinPower)
		{
			minBinPower = peakPowerInBin[i];
		}
	}
	*deltaPowerOverUwbBand = maxBinPower - minBinPower;
	
	
	///////////////////////////////////////////////////////////////////////
	// 4.  Do Phase 3
	//  Calculate and validate against the adjust power margin
	/////////////////////////////////////////////////////////////////////// 
	error |= SendTxUwbDac(255,testUnit);
	error |= getPeakPower(sa.session,marker,&powerAtMaxUwbDac);

	*TxAdjustmentMargin=  *TxCalibratedUwbPeakPwr-powerAtMaxUwbDac;
	
	sprintf(msg,"TxAdjustmentMarginCal=%.2f, powerAtMaxUwbDac=%.2f, TxCalibrateedUwbPeakPwr=%.2f",*TxAdjustmentMargin,powerAtMaxUwbDac,*TxCalibratedUwbPeakPwr);
	add_log(msg);
	
	if (calIsSuccessful && (fabs(*TxAdjustmentMargin) > UwbCalMarginLowLimit))
	{
		error |= SetEEPROMValue(UWB_DAC_CAL_ADDRESS,*CalibratedDacValue,testUnit);	
		error |= SetEEPROMBlockValues(DAC_E2P_LOW_ADDRESS, DAC_E2P_HIGH_ADDRESS, calDacStoredArray,testUnit);
		error |= SendReset(testUnit); 
		
	}
	else
	{
		error = -1;
	}
	
	check_error(error,__FUNCTION__,"Command failed.");
	return(error);
} // end CalTxUwbPower



/********************************************************
*
* FUNCTION NAME: GetCalibratedTxUwbPower
* 
* DESCRIPTION: Get power and frequency from calibrated UWB DAC value
*
* ARGUMENT LIST: 
* 
* ARGUMENT           TYPE     I/O    DESCRIPTION       
* --------           ----     ---    -----------
* phase				 int			 cal phase
* session			 ViSession       SpecAn session
* testUnit	 	   	 int
* uwbDac             int
* power              double
* frequency          double
* calIsSuccessful    int
* calIsCompleted     int
*
* OUTPUTS  
*
*
* RETURNS: 			 int
*				
* 
* 
*********************************************************/
/********************************************//**
* Get power and frequency from calibrated UWB DAC value 
***********************************************/ 
int GetCalibratedTxUwbPower(int phase, ViSession session, int testUnit, int uwbDac, double *power, double *frequency, int *calIsSuccessful, int *calIsCompleted) 
{
	int error = 0;
	char msg[120];
	
	error |= SendTxUwbDac(uwbDac,testUnit);
	error |= getPeakPowerFreq(session,marker,power,frequency);
	
	if (VerifyTxUwbPowerIsInLimit(*power)) 
	{
		// power is within limit, assign cal values
		*calIsSuccessful = TRUE;
		*calIsCompleted = TRUE;
	}
	else
	{   
		// power is not within limit, continue to next cal phase 1
		*calIsCompleted = FALSE;
	}
	sprintf(msg,"CalTxUwbPower Phase %i, %i, %.2f, %.2e",phase, uwbDac,*power,*frequency);
	add_log(msg);
	return(error);
} // end GetCalibratedTxUwbPower


/********************************************************
*
* FUNCTION NAME: VerifyTxUwbPowerIsInLimit
* 
* DESCRIPTION: Verify if power is within Tx UWB Power calibrated limit
*
* ARGUMENT LIST: 
* 
* ARGUMENT           TYPE     I/O    DESCRIPTION       
* --------           ----     ---    -----------
* value	 	   	 	 int
*
* RETURNS: 			 int
*				
* 
* 
*********************************************************/
/********************************************//**
* Verify if power is within Tx UWB Power calibrated limit
***********************************************/ 
int VerifyTxUwbPowerIsInLimit(double power)
{
	if ((power>=UwbPowerLowLimit) && (power<=UwbPowerHighLimit)) 
	{
		return(TRUE);
	}
	else
	{
		return(FALSE);
	}
} // end VerifyTxUwbPowerIsInLimit

/********************************************************
*
* FUNCTION NAME: VerifyTxUwbDacCalIsInLimit
* 
* DESCRIPTION: Verify if Tx UWB DAC is within calibrated limit
*
* ARGUMENT LIST: 
* 
* ARGUMENT           TYPE     I/O    DESCRIPTION       
* --------           ----     ---    -----------
* value	 	   	 	 int
*
* RETURNS: 			 int
*				
* 
* 
*********************************************************/
/********************************************//**
* Verify if Tx UWB DAC is within calibrated limit 
***********************************************/ 
int VerifyTxUwbDacCalIsInLimit(int uwbDac)
{
	if ((uwbDac<=UwbDacHighLimit) && (uwbDac>=UwbDacLowLimit))
	{
		return(TRUE);
	}
	else
	{
		return(FALSE);
	}
} // end VerifyTxUwbDacCalIsInLimit

/********************************************************
*
* FUNCTION NAME: ValidateUwbDacValue
* 
* DESCRIPTION: Verify the calibrated  was correctly stored in EEPROM
*
* ARGUMENT LIST: 
* 
* ARGUMENT           			TYPE     I/O    DESCRIPTION       
* --------           			----     ---    -----------
* calUwbDac			 			int
* testUnit	 	   	 			int
*
* OUTPUTS  
* ReadBackUwbDacValue 			int
*
*
* RETURNS: 			 			int
*								(0 = no error)
*				
* 
* 
*********************************************************/
/********************************************//**
* Verify the calibrated  was correctly stored in EEPROM 
***********************************************/ 
int ValidateUwbDacValue(int calUwbDac, int testUnit, int *ReadBackUwbDacValue)
{
	int error = 0;
	
	*ReadBackUwbDacValue = 0;
	char msg[80];

	*ReadBackUwbDacValue = GetEEPROMValue(UWB_DAC_CAL_ADDRESS,testUnit); // address 177
	sprintf(msg,"calUWBDAC=%i,E2PValue=%i",calUwbDac,*ReadBackUwbDacValue);  
	
	if (*ReadBackUwbDacValue == calUwbDac)
	{
		error = 0;
	}
	else
	{
		error = -1;
	}
	check_error(error,__FUNCTION__,msg);	
	return(error);
} // end ValidateUwbDacValue


/********************************************************
*
* FUNCTION NAME: MeasureIsmPullingAndPowerCal
* 
* DESCRIPTION: Verify the Tx frequency does not deviate too much on transmit
*
* ARGUMENT LIST: 
* 
* ARGUMENT           						TYPE     I/O    DESCRIPTION       
* --------           						----     ---    -----------
* sa				 						RSSpecAn
* testUnit	 	   	 						int
*
* OUTPUTS  
* IsmPeakPower								double
* IsmDeltaFrequency							double
* calIsmDac									int
* DeltaIsmPowerAtMinus2_5MHz				double
* DeltaIsmPowerAtPlus2_5MHz					double
*
* RETURNS: 			 						int
*											(0 = no error)
*				
* 
* 
*********************************************************/
/********************************************//**
* Verify the Tx frequency does not deviate too much on transmit 
***********************************************/ 
int MeasureIsmPullingAndPowerCal(RSSpecAn sa,int testUnit,double *IsmPeakPower,double *IsmDeltaFrequency,int *IsmDac,
						double *DeltaIsmPowerAtMinus2_5MHz,double *DeltaIsmPowerAtPlus2_5MHz)
{

	int error = 0;
	double pathLoss = IsmPathLossdB[testUnit];  
 
	
	// output parameters
	*IsmDac = IsmInitalDAC;  				// initial ISM DAC value = 100
	*IsmDeltaFrequency = 0.0;
	*IsmPeakPower = 0.0;
	*DeltaIsmPowerAtMinus2_5MHz = 0.0;
	*DeltaIsmPowerAtPlus2_5MHz = 0.0;
		
	double power_m2_5MHz = 0.0;
	double power_p2_5MHz = 0.0;
	
	double freq_m2_5MHz = 0.0;
	double freq_p2_5MHz = 0.0;
	
	int IsmCalIsCompleted=FALSE; 
	int IsmCalIsSuccessful=FALSE;
	

	int RequestedNumPoints = 2001;
	int ActualNumPoints=0;
	int timeout = 5000;
	double TraceAmpBuffer[2001]={0.0};

	double averagedArrayPulsing[2001]={0.0};
	double normalizedArrayPulsing[2001]={0.0};
	double ArrayFreqResolutionMHz;
	double readMarkerFreq=0.0;
	double readMarkerPower=0.0;
	double moveMarkerFreq=0.0;
	double moveDeltaMarkerFreq = 2.5e6;		// 2.5MHz
	int numAttempts = 0;
	char msg[256]; 

	
	/////////////////////////////////////////////////////////////////
	// 1. Set instrument ready for measurement
	////////////////////////////////////////////////////////////////
	SetSpectrumNominalCondition(sa); 
	sa.sweepTime = 1.0;  // 2.0;
	sa.centerFreq = 24.07;
	sa.freqSpan =  0.02;  // 0.6;  previous span is too high
	sa.preAmpPow = 0;
	sa.resBw = 0.01;
	sa.vidBw = 0.01;
	sa.refLevelOffset = pathLoss; 
	sa.refLevel =  getRefLevel(IsmPowerLowLimit,pathLoss);
	
	error |= SetSpectrum(sa);
	error |= setMaxHold(sa.session,trace);
	error |= setDetectorMaxPeak(sa.session,trace);
	sa.preAmpPow = 0;
	error |= setPreAmp(sa.session,sa.preAmpPow); // disable pre-amp
	
	/////////////////////////////////////////////////////////////////
	// 2. Perform ISM calibration by stepping up IsmDac value by 10/step since no Pulling Limit value
	////////////////////////////////////////////////////////////////
  
	// Resolution given in MHz
	ArrayFreqResolutionMHz = sa.freqSpan*1e9 / ((RequestedNumPoints-1)*1E6);  // resolution given in MHz 

/*  
	// turn off ISM FM
	SendDisableIsmFmCommand(testUnit);
*/	
	
	do
	{
		error |= SendIsmPowerCommand(*IsmDac,testUnit);
		error |= SendIsmPulsingCommand(testUnit);
		
		error |= setCenterFreqSpan(sa.session,sa.centerFreq,sa.freqSpan);
		error |= setResBw(sa.session,sa.resBw);
		error |= setVidBw(sa.session,sa.vidBw);
		error |= readTraceData(sa.session,trace,RequestedNumPoints,timeout,TraceAmpBuffer,&ActualNumPoints);
		//error |= fetchTraceData(sa.session,trace,RequestedNumPoints,TraceAmpBuffer,&ActualNumPoints); 
	
		// Filter the signal with 11-point windowed average  
		AverageSamples(TraceAmpBuffer,RequestedNumPoints,11,averagedArrayPulsing);
		
		// Normalize measurement data u[n]=10^((a[n]-max(a[n]))/10) and set u[n] to 0.0 if u[n] < 0.1 
		NormalizeData(averagedArrayPulsing,RequestedNumPoints,normalizedArrayPulsing);
		
		//Calculate energy offset center frequency in pulsed mode 
		CalculateEnergyCenter(normalizedArrayPulsing, RequestedNumPoints, sa.centerFreq*1E9, sa.freqSpan*1E9, IsmDeltaFrequency);   
		
		// 	// Do another measurement   
		error |= setCenterFreqSpan(sa.session,sa.centerFreq,0.4);   // set span to 400MHz
		error |= setResBw(sa.session,10.0);	   // set resBw to 10MHz
		error |= setVidBw(sa.session,10.0);	   // set vidBw to 10MHz
		
		error |= getPeakPowerFreq(sa.session,marker,&readMarkerPower,&readMarkerFreq); 
		*IsmPeakPower = readMarkerPower;
		sprintf(msg,"IsmDac=%i,PeakPower=%.2f,DeltaFreq=%.2f",*IsmDac,*IsmPeakPower,*IsmDeltaFrequency); 
		add_log(msg);
		
		numAttempts++;
		
		// Measure Freq Dev within Limit
		if (fabs(*IsmDeltaFrequency) < IsmFreqDevHighLimit)		// 650KHz
		{
			//  Measure ISM peak power is within limit
			if (*IsmPeakPower > IsmPowerLowLimit)	   // -2.0 dB
			{
				IsmCalIsSuccessful = TRUE;	   // ISM DAC cal is successful
				IsmCalIsCompleted = TRUE;
			}
			else
			{
				// Measure power is too low, decrease IsmDac to increase power
				*IsmDac -= 10;
			}	
		}
		else
		{
			// Measure power is too high, increase IsmDac to decrease power
			*IsmDac += 10;
		} // end if
		
		// verify new calibrated IsmDac is within limit
		if (!VerifyIsmDacCalIsInLimit(*IsmDac) || (numAttempts > MAX_NUM_CAL_ATTEMPTS))
		{
			IsmCalIsCompleted = TRUE;
			IsmCalIsSuccessful = FALSE;
		}
	
	} while(IsmCalIsCompleted==FALSE);
	


	/////////////////////////////////////////////////////////////////
	// 3. Measure ISM Width
	////////////////////////////////////////////////////////////////
	
	error |= setCenterFreqSpan(sa.session,sa.centerFreq,0.05); // set span to 50MHz
	error |= setResBw(sa.session,0.3);  // set resBw to 300KHz
	error |= setVidBw(sa.session,0.3);	// set vidBw to 300KHz
	
	error |= getPeakPowerFreq(sa.session,marker,&readMarkerPower,&readMarkerFreq); 
	
	moveMarkerFreq = readMarkerFreq - moveDeltaMarkerFreq;
	error |= moveMarker(sa.session,marker,moveMarkerFreq);
	error |= getMarkerPowerFreq(sa.session,marker,&power_m2_5MHz,&freq_m2_5MHz);
	*DeltaIsmPowerAtMinus2_5MHz = readMarkerPower - power_m2_5MHz;	 // set output value
	
	moveMarkerFreq = readMarkerFreq + moveDeltaMarkerFreq;
	error |= moveMarker(sa.session,marker,moveMarkerFreq);
	error |= getMarkerPowerFreq(sa.session,marker,&power_p2_5MHz,&freq_p2_5MHz);
	*DeltaIsmPowerAtPlus2_5MHz = readMarkerPower - power_p2_5MHz; 	  // set output value

	//  This is left in (but commented out)because some variants need it.
	// set ISM pulse back to normal
	//error = SendTxPulseRestoreCommand(testUnit);
	
	// Set back to Pulsing mode
	error |= SendIsmPulsingCommand(testUnit);

	
	if (IsmCalIsSuccessful == TRUE)
	{
		// STORE THE CALIBRATED DAC VALUE IN EEPROM    
		error |= SetEEPROMValue(178,*IsmDac,testUnit);
	//	error |= SensorReset_mt(8, testUnit); //carol added  CLEAN_CODE
		error |= SendReset(testUnit);
		
	}
	else
	{
		error = -1;  // set error
	}
	
	sprintf(msg,"PeakPower=%.2f,DeltaPowerAtm2_5MHz=%.2f,DeltaPwrAtp2_5MHz=%.2f",readMarkerPower,*DeltaIsmPowerAtMinus2_5MHz,*DeltaIsmPowerAtPlus2_5MHz);  
	check_error(error,msg,"MeasureIsmPullingAndPowerCal failed.");
	return(error);
} // end MeasureIsmPullingAndPowerCal

/********************************************//**
* Measure ISM frequency deviation and power without cal
***********************************************/ 
int MeasureIsmPullingAndPower(RSSpecAn sa,int testUnit,double *IsmPeakPower,double *IsmDeltaFrequency,
						double *DeltaIsmPowerAtMinus2_5MHz,double *DeltaIsmPowerAtPlus2_5MHz)
{
	int error = 0;
	double pathLoss = IsmPathLossdB[testUnit];  
 
	
	// output parameters
	*IsmDeltaFrequency = 0.0;
	*IsmPeakPower = 0.0;
	*DeltaIsmPowerAtMinus2_5MHz = 0.0;
	*DeltaIsmPowerAtPlus2_5MHz = 0.0;
		
	double power_m2_5MHz = 0.0;
	double power_p2_5MHz = 0.0;
	
	double freq_m2_5MHz = 0.0;
	double freq_p2_5MHz = 0.0;
	
	int IsmDacCalAddress = 178;
	int IsmDacCal;

	int RequestedNumPoints = 2001;
	int ActualNumPoints=0;
	int timeout = 5000;
	double TraceAmpBuffer[2001]={0.0};

	double averagedArrayPulsing[2001]={0.0};
	double normalizedArrayPulsing[2001]={0.0};
	double ArrayFreqResolutionMHz;
	double readMarkerFreq=0.0;
	double readMarkerPower=0.0;
	double moveMarkerFreq=0.0;
	double moveDeltaMarkerFreq = 2.5e6;		// 2.5MHz
	char msg[256]; 

	
	
	/////////////////////////////////////////////////////////////////
	// 1. Set instrument ready for measurement
	////////////////////////////////////////////////////////////////
	SetSpectrumNominalCondition(sa); 
	sa.sweepTime = 1.0;  // 2.0;
	sa.centerFreq = 24.07;
	sa.freqSpan =  0.02;  // 0.6;  previous span is too high
	sa.preAmpPow = 0;
	sa.resBw = 0.01;
	sa.vidBw = 0.01;
	sa.refLevelOffset = pathLoss; 
	sa.refLevel =  getRefLevel(IsmPowerLowLimit,pathLoss);
	
	error |= SetSpectrum(sa);
	error |= setMaxHold(sa.session,trace);
	error |= setDetectorMaxPeak(sa.session,trace);
	sa.preAmpPow = 0;
	error |= setPreAmp(sa.session,sa.preAmpPow); // disable pre-amp
	
	/////////////////////////////////////////////////////////////////
	// 2. Perform ISM calibration by stepping up IsmDac value by 10/step since no Pulling Limit value
	////////////////////////////////////////////////////////////////
  
	// Resolution given in MHz
	ArrayFreqResolutionMHz = sa.freqSpan*1e9 / ((RequestedNumPoints-1)*1E6);  // resolution given in MHz 

/*  
	// turn off ISM FM
	SendDisableIsmFmCommand(testUnit);
*/	
		// Get IsmDacCal value from EEPROM 
	IsmDacCal = GetEEPROMValue(IsmDacCalAddress,testUnit); // address 178  
	//IsmDacCal = 10; 										//Carol added for hightest power test
	error |= SendIsmPowerCommand(IsmDacCal,testUnit);
	error |= SendIsmPulsingCommand(testUnit);
		
	error |= setCenterFreqSpan(sa.session,sa.centerFreq,sa.freqSpan);
	error |= setResBw(sa.session,sa.resBw);
	error |= setVidBw(sa.session,sa.vidBw);
	error |= readTraceData(sa.session,trace,RequestedNumPoints,timeout,TraceAmpBuffer,&ActualNumPoints);
	
	// Filter the signal with 11-point windowed average  
	AverageSamples(TraceAmpBuffer,RequestedNumPoints,11,averagedArrayPulsing);
		
	// Normalize measurement data u[n]=10^((a[n]-max(a[n]))/10) and set u[n] to 0.0 if u[n] < 0.1 
	NormalizeData(averagedArrayPulsing,RequestedNumPoints,normalizedArrayPulsing);
		
	//Calculate energy offset center frequency in pulsed mode 
	CalculateEnergyCenter(normalizedArrayPulsing, RequestedNumPoints, sa.centerFreq*1E9, sa.freqSpan*1E9, IsmDeltaFrequency);   
		
		
	// 	// Do another measurement   
	error |= setCenterFreqSpan(sa.session,sa.centerFreq,0.4);   // set span to 400MHz
	error |= setResBw(sa.session,10.0);	   // set resBw to 10MHz
	error |= setVidBw(sa.session,10.0);	   // set vidBw to 10MHz
		
	error |= getPeakPowerFreq(sa.session,marker,&readMarkerPower,&readMarkerFreq); 
	*IsmPeakPower = readMarkerPower;
	sprintf(msg,"PeakPower=%.2f,DeltaFreq=%.2f",*IsmPeakPower,*IsmDeltaFrequency); 
	add_log(msg);
	
	
	/////////////////////////////////////////////////////////////////
	// 3. Measure ISM Width
	////////////////////////////////////////////////////////////////
	
	error |= setCenterFreqSpan(sa.session,sa.centerFreq,0.05); // set span to 50MHz
	error |= setResBw(sa.session,0.3);  // set resBw to 300KHz
	error |= setVidBw(sa.session,0.3);	// set vidBw to 300KHz
	
	error |= getPeakPowerFreq(sa.session,marker,&readMarkerPower,&readMarkerFreq); 
	
	moveMarkerFreq = readMarkerFreq - moveDeltaMarkerFreq;
	error |= moveMarker(sa.session,marker,moveMarkerFreq);
	error |= getMarkerPowerFreq(sa.session,marker,&power_m2_5MHz,&freq_m2_5MHz);
	*DeltaIsmPowerAtMinus2_5MHz = readMarkerPower - power_m2_5MHz;	 // set output value
	
	moveMarkerFreq = readMarkerFreq + moveDeltaMarkerFreq;
	error |= moveMarker(sa.session,marker,moveMarkerFreq);
	error |= getMarkerPowerFreq(sa.session,marker,&power_p2_5MHz,&freq_p2_5MHz);
	*DeltaIsmPowerAtPlus2_5MHz = readMarkerPower - power_p2_5MHz; 	  // set output value

	//  This is left in (but commented out)because some variants need it.
	// set ISM pulse back to normal
	//error = SendTxPulseRestoreCommand(testUnit);
	
	// Set back to Pulsing mode
	error |= SendIsmPulsingCommand(testUnit);

	
	sprintf(msg,"PeakPower=%.2f,DeltaPowerAtm2_5MHz=%.2f,DeltaPwrAtp2_5MHz=%.2f",readMarkerPower,*DeltaIsmPowerAtMinus2_5MHz,*DeltaIsmPowerAtPlus2_5MHz);  
	check_error(error,msg,"MeasureIsmPullingAndPower failed.");
	return(error);
} // end MeasureIsmPullingAndPower


/********************************************************
*
* FUNCTION NAME: VerifyIsmDacCalIsInLimit
* 
* DESCRIPTION: Verify the ISM DAC is within calibrated limit
*
* ARGUMENT LIST: 
* 
* ARGUMENT           TYPE     I/O    DESCRIPTION       
* --------           ----     ---    -----------
* value		 	   	 int
*
* RETURNS: 			 int
*				
* 
* 
*********************************************************/
/********************************************//**
* Verify the ISM DAC is within calibrated limit
***********************************************/ 
int VerifyIsmDacCalIsInLimit(int value)
{
	if ((value<=IsmDacHighLimit) && (value>=IsmDacLowLimit))
	{
		return(TRUE);
	}
	else
	{
		return(FALSE);
	}
} // end VerifyIsmDacCalIsInLimit


/********************************************************
*
* FUNCTION NAME: MeasureUwbPeakPower
* 
* DESCRIPTION: Measure UWB peak power
*
* ARGUMENT LIST: 
* 
* ARGUMENT           			TYPE     I/O    DESCRIPTION       
* --------           			----     ---    -----------
* sa				 			RSSpecAn
* testUnit	 	   	 			int
*
* OUTPUTS  
* PeakPowerUWB					double
* PeakFrequencyUWB				double
*
* RETURNS: 			 			int
*								(0 = no error)
*				
* 
* 
*********************************************************/
/********************************************//**
* Measure UWB peak power  
***********************************************/ 
int MeasureUwbPeakPower(RSSpecAn sa,int testUnit,int calUwbDac, double *PeakPowerUWB,double *PeakFrequencyUWB)
{
	int error = 0;
	int status = 0;
	double pathLoss = UwbPathLossdB[testUnit];  
		
	*PeakPowerUWB = 0.0;
	*PeakFrequencyUWB = 0.0;
	
	char msg[120];
	
	
	
	/////////////////////////////////////////////////////////////////
	// Set instrument ready for measurement
	////////////////////////////////////////////////////////////////
	SetSpectrumNominalCondition(sa); 
	sa.sweepTime = 2.0;
	sa.centerFreq = 25.1;
	sa.freqSpan =  1.0;
	sa.refLevel = getRefLevel(UWB_TARGET_PEAK_POWER,pathLoss);
	sa.refLevelOffset = pathLoss;
	
	error |= SetSpectrum(sa);
	error |= setMaxHold(sa.session,trace); 
	error |= setPreAmp(sa.session,1);
	
	// do power measurement
	error |= getPeakPowerFreq(sa.session,marker,PeakPowerUWB,PeakFrequencyUWB);
	
	if (error == 0)
	{
		// Verify if UWB Power Check is within limit
		if ((*PeakPowerUWB >= UwbPowerCheckLowLimit) && (*PeakPowerUWB <= UwbPowerCheckHighLimit))
		{
			status = TRUE;
		}
		else
		{
			status = FALSE;
		}
	}

	sprintf(msg,"%s, MeasUwbPeakPower=%.2f, MeasUwbPeakFreq=%.2e",__FUNCTION__,*PeakPowerUWB,*PeakFrequencyUWB); 
	check_error(error,msg,"Command failed");
	return(!status);
} // end MeasureUwbPeakPower

/********************************************************
*
* FUNCTION NAME: MeasureTxDiffPower
* 
* DESCRIPTION: Measure Tx1-Tx2 diff at highest power
*
* ARGUMENT LIST: 
* 
* ARGUMENT           TYPE     I/O    DESCRIPTION       
* --------           ----     ---    -----------
* sa				 RSSpecAn
* testUnit	 	   	 int
*
* OUTPUTS  
* TxDiffRes			 double[]
*
* RETURNS: 			 int
*					 (0 = no error)
*				
* 
* 
*********************************************************/
/********************************************//**
* Measure Tx1-Tx2 diff at highest power 
***********************************************/ 
int MeasureTxDiffPower(RSSpecAn sa,int testUnit, double TxDiffRes[6])
{
	int error = 0;
	double pathLoss = UwbPathLossdB[testUnit];  
	
	double measureFreqList[]={24.6,24.8,25.0,25.2,25.4,25.6};
	int numFreq = sizeof(measureFreqList)/sizeof(measureFreqList[0]);
	double powerTx1[numFreq];
	double powerTx2[numFreq];
	
	double peakPower=0.0;   
	double TxDiff=0.0;      
	char msg[256];
	
	/////////////////////////////////////////////////////////////////
	// 1. Set instrument ready for measurement
	////////////////////////////////////////////////////////////////
	SetSpectrumNominalCondition(sa); 
	sa.sweepTime = 0.05;
	sa.centerFreq = 24.6;
	sa.freqSpan =  0.2;
	sa.refLevelOffset = pathLoss; 
	sa.refLevel = getRefLevel(10.0 ,pathLoss);  // The most we can put out it 10 dBm?
	error |= SetSpectrum(sa);
	error |= setMaxHold(sa.session,trace);
	error |= setPreAmp(sa.session,0);
	
	/////////////////////////////////////////////////////////////////
	// 2. Measure power with Tx1 ON and Tx2 OFF
	////////////////////////////////////////////////////////////////
	for(int i=0; i<numFreq; i++)
	{
		error |= setCenterFreqSpan(sa.session,measureFreqList[i],sa.freqSpan);
		error |= SendTxAnt(measureFreqList[i]*1000,INNER_ANTENNA, testUnit);
		
		error |= getPeakPower(sa.session,marker,&peakPower);
		powerTx1[i]=peakPower;
	}
	
	/////////////////////////////////////////////////////////////////
	// 3. Measure power with Tx1 OFF and Tx2 ON
	////////////////////////////////////////////////////////////////
	for(int i=0; i<numFreq; i++)
	{
		error |= setCenterFreqSpan(sa.session,measureFreqList[i],sa.freqSpan);
		error |= SendTxAnt(measureFreqList[i]*1000, OUTER_ANTENNA, testUnit);

		error |= getPeakPower(sa.session,marker,&peakPower);
		powerTx2[i]=peakPower;
	}
	
	
	/////////////////////////////////////////////////////////////////
	// 4.  Calculate the power differences of Tx1 and Tx2
	////////////////////////////////////////////////////////////////
	for (int i=0; i<numFreq; i++)
	{
		TxDiff = powerTx1[i]-powerTx2[i];
		TxDiffRes[i]=TxDiff;
		if ((TxDiff<TxDiffLowLimit) || (TxDiff>TxDiffHighLimit))
		{
			error = -1;
			sprintf(msg,"Tx1=%lf,Tx2=%lf,TxDiff=%lf",powerTx1[i],powerTx2[i],TxDiff);
			decode_error(error,__FUNCTION__,msg);
		}
	} // end for loop
	
	check_error(error,__FUNCTION__,"Command failed.");
	return(error);
} // end MeasureTxDiffPower


/********************************************************
*
* FUNCTION NAME: MeasureTxIsolation
* 
* DESCRIPTION: Measure Isolation at highest power
*
* ARGUMENT LIST: 
* 
* ARGUMENT           				TYPE     I/O    DESCRIPTION       
* --------           				----     ---    -----------
* sa				 				RSSpecAn
* testUnit	 	   	 				int
* CalibratedUwbDac			        int
*
* OUTPUTS  
* TxSwitchIsolationRes			 	double[]
*
* RETURNS: 			 				int
*									(0 = no error)
*				
* 
* 
*********************************************************/
/********************************************//**
* Measure Isolation at highest power  
***********************************************/ 
int MeasureTxIsolation(RSSpecAn sa, int testUnit, int CalibratedUwbDac, double TxSwitchIsolationRes[6])
{
	int error = 0;
	double pathLoss = UwbPathLossdB[testUnit];  
	
	double measureFreqList[]={24.6,24.8,25.0,25.2,25.4,25.6};
	//double measureFreqList[]={24.8,24.6,25.0,25.2,25.4,25.6};
	int numFreq = sizeof(measureFreqList)/sizeof(measureFreqList[0]);   
	double powerTx1OnIsolation[numFreq];
	double powerTx1OffIsolation[numFreq];

int tempVal=-1;	

	double peakPower = 0;  
	double TxDiff=0.0;
	int TxIsolationIsAtCalibratedUwbDac;
	double TxIsolationLowerLimit;
	double TxIsolationUpperLimit;
	char msg[256];
	
	// Check if TxIsolation is at Calibrated UWB DAC
	if (CalibratedUwbDac > 0)
	{
		// Set Tx Isolation at Calibrated UWB DAC limits
		TxIsolationIsAtCalibratedUwbDac = TRUE;	
		TxIsolationLowerLimit = TxIsolCalLowLimit;		// 0 dB
		TxIsolationUpperLimit = TxIsolCalHighLimit; 	// 100 dB
	}
	else
	{
		// Set Tx Isolation at Highest Power limits   
		TxIsolationIsAtCalibratedUwbDac = FALSE;	
		TxIsolationLowerLimit = TxIsolLowLimit;	   		// 35 dB
		TxIsolationUpperLimit = 100; //TxIsolCalHighLimit; 	// Use 100 dB
	}
	
	/////////////////////////////////////////////////////////////////
	// 1. Set instrument ready for measurement
	////////////////////////////////////////////////////////////////
	SetSpectrumNominalCondition(sa); 
	sa.sweepTime = 0.05;   // 0.1
	sa.centerFreq = 24.6;
	sa.freqSpan =  0.2;
	sa.refLevelOffset = pathLoss;  
	sa.refLevel = getRefLevel(7.5 ,pathLoss); 		// 7.5 dB
	sa.preAmpPow = 0;
	error |= SetSpectrum(sa);
	error |= setMaxHold(sa.session,trace);
	
	/////////////////////////////////////////////////////////////////
	// 2. Measure power with Tx1 ON and Tx2 OFF
	//////////////////////////////////////////////////////////////// 
	for(int i=0; i<numFreq; i++)
	{
		error |= setCenterFreqSpan(sa.session,measureFreqList[i],sa.freqSpan);
		error |= SendTxAnt(measureFreqList[i]*1000, INNER_ANTENNA, testUnit);  
		
		if (TxIsolationIsAtCalibratedUwbDac)
		{
			error |= SendTxUwbDac(CalibratedUwbDac,testUnit);  
		}
		else	//alex wang 20140214 added for isolation test at peak power for EMC hardware. (Peijun says for EMC hardware, set it to highest value for max power)
		{
			if(i==0){
				//error |= SendTxUwbDac(0,testUnit); 
				error |= SetEEPROMValue(177, 10 ,testUnit); //write UWBDAC=0 into EEPROM 177 
			//	error |= SensorReset_mt(8, testUnit); //carol added   CLEAN_CODE
				error |= SendReset(testUnit);
				//tempVal = GetEEPROMValue(177, testUnit); 
				
				//run a dummy test for the first meaus - Carol added 
				error |= getPeakPower(sa.session,marker,&peakPower);
				Sleep(500);
				error |= setCenterFreqSpan(sa.session,measureFreqList[i],sa.freqSpan);
				error |= SendTxAnt(measureFreqList[i]*1000, INNER_ANTENNA, testUnit);  
				
			}
		}
		error |= getPeakPower(sa.session,marker,&peakPower);
		powerTx1OnIsolation[i]=peakPower;
	} // end for loop
	
	/////////////////////////////////////////////////////////////////
	// 3. Measure power with Tx1 OFF for Tx Isolation and reuse value for Tx Isolation at Cal UWBDAC
	//////////////////////////////////////////////////////////////// 
	
	error |= setRefLevelOffset(sa.session,pathLoss); 
	error |= setRefLevel(sa.session,-20.0);  
	
	error |= setMaxHold(sa.session,trace); 
	error |= setPreAmp(sa.session,1);  //Enable Pre-Amplifier
	
	
	for(int i=0; i<numFreq; i++)
	{
		error |= setCenterFreqSpan(sa.session,measureFreqList[i],sa.freqSpan);   // 200 MHz
		error |= SendTxAnt(measureFreqList[i]*1000, TRANSMITTER_DISABLED, testUnit);
	
		error |= getPeakPower(sa.session,marker,&peakPower);
		powerTx1OffIsolation[i]=peakPower;
	} // end for
	
	error |= setPreAmp(sa.session,0);  //Disable Pre-Amplifier
	
	
	/////////////////////////////////////////////////////////////////
	// 4. Calculate the Tx Isolation power and validate its limit
	////////////////////////////////////////////////////////////////
	for (int i=0; i<numFreq; i++)
	{
		TxDiff = powerTx1OnIsolation[i]-powerTx1OffIsolation[i];
		TxSwitchIsolationRes[i]=TxDiff;
		
		if ((TxDiff < TxIsolationLowerLimit) || (TxDiff > TxIsolationUpperLimit))
		{
			error = -1;
			sprintf(msg,"Tx1 ON=%lf,Tx1 OFF=%lf,TxDiff=%lf",powerTx1OnIsolation[i],powerTx1OffIsolation[i],TxDiff);
			decode_error(error,__FUNCTION__,msg);
		}
		sprintf(msg,"freqGHz=%.2f, Tx1=%.2f, Tx1OffIsol=%.2f, TxDiff=%.2f",measureFreqList[i],powerTx1OnIsolation[i],powerTx1OffIsolation[i],TxDiff);
		add_log(msg);
	} // end for loop
	
	error |= SendClearFaults(testUnit);  // temporary clear faults 
	
	if (TxIsolationIsAtCalibratedUwbDac == 0)   
		error |= SetEEPROMValue(UWB_DAC_CAL_ADDRESS,CalUwbDac[testUnit],testUnit); //write CalibratedDacValue back to EEPROM 177
	//	error |= SensorReset_mt(8, testUnit); //carol added 	CLEAN_CODE
		error |= SendReset(testUnit);

		
	check_error(error,__FUNCTION__,"Command failed.");  
	return(error);
} // end MeasureTxIsolation

/********************************************************
*
* FUNCTION NAME: MeasureTxIsolationAtHighestPower
* 
* DESCRIPTION: Measure power difference between Tx1 ON and OFF over UWB frequency range
*
* ARGUMENT LIST: 
* 
* ARGUMENT           				TYPE     I/O    DESCRIPTION       
* --------           				----     ---    -----------
* sa				 				RSSpecAn
* testUnit	 	   	 				int
*
* OUTPUTS  
* TxSwitchIsolationRes			 	double[]
*
* RETURNS: 			 				int
*									(0 = no error)
*				
* 
* 
*********************************************************/
/********************************************//**
* Measure power difference between Tx1 ON and OFF over UWB frequency range 
***********************************************/ 
int MeasureTxIsolationAtHighestPower(RSSpecAn sa, int testUnit, double TxSwitchIsolationRes[6])
{
	int error = 0;
	int withCalibratedUwbDac = 0;
	
	error = MeasureTxIsolation(sa,testUnit,withCalibratedUwbDac,TxSwitchIsolationRes);
	
	check_error(error,__FUNCTION__,"Command failed");
	return(error);
}  // end MeasureTxIsolationAtHighestPower

/********************************************************
*
* FUNCTION NAME: MeasureTxIsolationAtCalibratedUwbDac
* 
* DESCRIPTION: Measure power difference between Tx1 ON and OFF over UWB frequency 
*		range using calibrated UWB DAC value
*
* ARGUMENT LIST: 
* 
* ARGUMENT           				TYPE     I/O    DESCRIPTION       
* --------           				----     ---    -----------
* sa				 				RSSpecAn
* testUnit	 	   	 				int
*
* OUTPUTS  
* TxSwitchIsolationResAtCalUwbDac 	double[]
*
* RETURNS: 			 				int
*									(0 = no error)
*				
* 
* 
*********************************************************/
/********************************************//**
* Measure power difference between Tx1 ON and OFF over UWB frequency 
*		range using calibrated UWB DAC value
***********************************************/ 
int MeasureTxIsolationAtCalibratedUwbDac(RSSpecAn sa, int testUnit, int calUwbDac, double TxSwitchIsolationResAtCalUwbDac[6])
{
	int error = 0;
	
	error = MeasureTxIsolation(sa,testUnit,calUwbDac,TxSwitchIsolationResAtCalUwbDac);
	
	check_error(error,__FUNCTION__,"Command failed");
	return(error);
}  // end MeasureTxIsolationAtCalibratedUwbDac


/********************************************************
*
* FUNCTION NAME: getRefLevel
* 
* DESCRIPTION: Get reference level for measurement 
*
* ARGUMENT LIST: 
* 
* ARGUMENT           TYPE     I/O    DESCRIPTION       
* --------           ----     ---    -----------
* cableLoss	 	   	 int
*
* RETURNS: 			 double
*				
* 
* 
*********************************************************/
/********************************************//**
* Get reference level for measurement 
***********************************************/ 
double getRefLevel(double expectedPower, double cableLoss)
{
	return(expectedPower-cableLoss+15);  // We set the ref leve to the expected power +15
}  // end getRefLevel

/********************************************************
*
* FUNCTION NAME: CalculateTxCrossOverFreq
* 
* DESCRIPTION: Calculate the transmitted cross over frequency
*
* ARGUMENT LIST: 
* 
* ARGUMENT           TYPE     I/O    DESCRIPTION       
* --------           ----     ---    -----------
* TxBand1Freq	   	 double
* TxBand0Freq		 double
*
* RETURNS: 			 int
*				
* 
* 
*********************************************************/
/********************************************//**
* Calculate the transmitted cross over frequency
***********************************************/ 
int CalculateTxCrossOverFreq(double TxBand1HiFreq, double TxBand0LoFreq)
{
	int error=0;
	char msg[256];  
	
	// calculate and validate CrossOver frequency is within limit
	int crossOverFreqMHz;
	crossOverFreqMHz = (int)((TxBand1HiFreq+TxBand0LoFreq)/2.0e6);
	if ((crossOverFreqMHz >= Band0LowLimit) && (crossOverFreqMHz <= Band1HighLimit))
	{
		sprintf(msg," %s, TxBand1HiFreq=%.2e, TxBand0LoFreq=%.2e, crossOverFrequencyMHz=%i",__FUNCTION__,TxBand1HiFreq,TxBand0LoFreq,crossOverFreqMHz);
		add_log(msg);
		return(crossOverFreqMHz);
	}
	else
	{
		error = -1;
		sprintf(msg,"Unable to calculate crossOverFreq, XFreqLo=%lf, XFreqHi=%lf, XFreq=%i",TxBand0LoFreq,TxBand1HiFreq,crossOverFreqMHz);
		decode_error(error,__FUNCTION__,msg);
		return(error);
	}
}  // end  CalculateCrossOverFreq

/********************************************************
*
* FUNCTION NAME: adjustedDac
* 
* DESCRIPTION: Calculated the adjusted DAC value 
*
* ARGUMENT LIST: 
* 
* ARGUMENT           TYPE     I/O    DESCRIPTION       
* --------           ----     ---    -----------
* currentDac	 	 int
* targetPower		 double
* currentPower		 double
* slope				 double
*
* RETURNS: 			 int
*				
* 
* 
*********************************************************/
/********************************************//**
* Calculated the adjusted DAC value 
***********************************************/ 
int adjustedDac(int currentDac,double targetPower,double currentPower,double slope)
{
	int newDac;
	newDac = (int)(currentDac + ceil((targetPower - currentPower)/slope));
	
	if (!VerifyTxUwbDacCalIsInLimit(newDac))
	{
		// set DAC value to minimum
		if (newDac < UwbDacLowLimit)
		{
			newDac = UwbDacLowLimit;
		}
		// set DAC value to maximum
		if (newDac > UwbDacHighLimit)
		{
			newDac = UwbDacHighLimit;
		}
	}
	return(newDac);
} // end adjustedDac

/********************************************************
*
* FUNCTION NAME: AverageSamples
* 
* DESCRIPTION: Filter the signal with 11-point windowed average
*
* ARGUMENT LIST: 
* 
* ARGUMENT           			TYPE     I/O    DESCRIPTION       
* --------           			----     ---    -----------
* dArray	 	   	 			double[]
* nNumOfArraySamples			int
* nOddNumOfSamplesToAverage		int
*
* OUTPUTS  
* dAveragedArray				double[]
*
* RETURNS: 			 int
*					(0 = no error)
*				
* 
* 
*********************************************************/
/********************************************//**
* Filter the signal with 11-point windowed average 
***********************************************/ 
void AverageSamples(double dArray[], int nNumOfArraySamples, int nOddNumOfSamplesToAverage, double dAveragedArray[])
{
	int ii = 0;
	int iy = 0;
	int nNumSamplesAveraged = 0;
	int nHalfWindowWidth;
	double dSum = 0.0;

	nHalfWindowWidth = (nOddNumOfSamplesToAverage - 1) / 2;
	
	for (iy = 0; iy < nNumOfArraySamples; iy++)
	{
		dSum = 0.0;
		nNumSamplesAveraged = 0;
		
		for  (ii = 0; ii < nOddNumOfSamplesToAverage; ii++)
		{
			if ( ((iy - nHalfWindowWidth + ii) > -1) && ((iy - nHalfWindowWidth + ii) < nNumOfArraySamples) )
			{
				dSum+= dArray[iy - nHalfWindowWidth + ii];
				nNumSamplesAveraged++;
			}
		}
		
		dAveragedArray[iy] = dSum/nNumSamplesAveraged;
	}

} // end AverageSamples

/********************************************************
*
* FUNCTION NAME: NormalizeData
* 
* DESCRIPTION: Normalize measurement data u[n]=10^((a[n]-max(a[n]))/10) and set u[n] to 0.0 if u[n] < 0.1 
*
* ARGUMENT LIST: 
* 
* ARGUMENT           						TYPE     I/O    DESCRIPTION       
* --------           						----     ---    -----------
* dArrayToBeNormalized						double[]
* NumberOfPoints				 	   	    int
*
* OUTPUTS  
* dNormalizedArray							double[]
*
* RETURNS: 			 int
*					(0 = no error)
*				
* 
* 
*********************************************************/
/********************************************//**
* Normalize measurement data 
***********************************************/ 
void NormalizeData(double dArrayToBeNormalized[], int NumberOfPoints, double dNormalizedArray[])
{
	double dMaxValue = 0.0;
	double dMinValue = 0.0;
	int ix, maxIx, minIx;
	
	MaxMin1D(dArrayToBeNormalized, NumberOfPoints, &dMaxValue, &maxIx, &dMinValue, &minIx); 

	for (ix = 0; ix < NumberOfPoints; ix++)
	{
		dNormalizedArray[ix] = pow(10.0, (dArrayToBeNormalized[ix] - dMaxValue) / 10.0);
		
		if (dNormalizedArray[ix] < 0.1)
			dNormalizedArray[ix] = 0.0;
	}
} // end NormalizeData


/********************************************************
*
* FUNCTION NAME: CalculateEnergyCenter
* 
* DESCRIPTION: Calculate energy offset center frequency in pulsed mode
*
* ARGUMENT LIST: 
* 
* ARGUMENT           					TYPE     I/O    DESCRIPTION       
* --------           					----     ---    -----------
* dInputArray		 					double[]
* NumberOfPoints   	 					int
* ArrayFreqResolution 					double
*
* OUTPUTS  
* dEnergyCenterFrequency				double
*
* RETURNS: 			 int
*					(0 = no error)
*				
* 
* 
*********************************************************/
/********************************************//**
* Calculate energy offset center frequency in pulsed mode 
***********************************************/ 
void CalculateEnergyCenter(double dInputArray[], int NumberOfPoints, double cf, double span, double *dEnergyCenterFrequency)
{
	int i;
	double freq_x_amp_sum=0, amp_sum=0, freq;
	
	for (i = 0; i < NumberOfPoints; i++)
	{
		freq =  (cf - span/2) + i * (span/NumberOfPoints);
		freq_x_amp_sum+=freq*dInputArray[i];
		amp_sum+=dInputArray[i];
	}
	
	// Return the center offset frequency in Hz
	*dEnergyCenterFrequency = fabs(cf-freq_x_amp_sum/amp_sum);
	
} // end CalculateEnergyCenter
 
/********************************************************
*
* FUNCTION NAME: LoadCableLossCompensationFile
* 
* DESCRIPTION: Load cable loss compensation file
*
* ARGUMENT LIST: 
* 
* ARGUMENT           TYPE     I/O    DESCRIPTION       
* --------           ----     ---    -----------
*
* OUTPUTS
*
*
* RETURNS: 			 int
*					(0 = no error) 			 
*				
* 
* 
*********************************************************/
/********************************************//**
* Load cable loss compensation file   
***********************************************/ 
int LoadCableLossCompensationFile(void)
{
	// load xml file
	CVIXMLDocument   doc;     
	CVIXMLElement    rootElem = 0;
	CVIXMLElement 	 testSetElem = 0;
	CVIXMLElement 	 dataElem = 0;
	char dir[MAX_PATHNAME_LEN];
	char filePath[MAX_PATHNAME_LEN];
	int numChild = 0;
	char tag[120];
	char value[120];
	int testUnitIx;
	
	GetProjectDir(dir);
	sprintf(filePath,"%s%s",dir,"\\Configuration\\CableLossCompensation.xml");
	// clear path loss array with separate compensation loss for ISM and UWB path
	for (int i=0;i<NUMBER_OF_TEST_UNITS;i++)
	{
		IsmPathLossdB[i] = 0.0;
		UwbPathLossdB[i] = 0.0;
	}
	// load xml document
	CVIXMLLoadDocument(filePath,&doc);
	CVIXMLGetRootElement(doc,&rootElem);
	CVIXMLGetNumChildElements(rootElem,&numChild);	  // get number of test sets in xml file
	
	for (int i=0;i<NUMBER_OF_TEST_UNITS;i++)
	{
		// Get TestSet element
		CVIXMLGetChildElementByIndex(rootElem,i,&testSetElem);
		CVIXMLGetNumChildElements(testSetElem,&numChild);    // get data element in test set node
		for(int j=0;j<numChild;j++)
		{
			CVIXMLGetChildElementByIndex(testSetElem,j,&dataElem);
			CVIXMLGetElementTag(dataElem,tag);
			if(strstr(tag,"Number"))
			{
				CVIXMLGetElementValue(dataElem,value);
				testUnitIx = atoi(value);
			}
			else if (strstr(tag,"IsmPathLoss")) 
			{
				CVIXMLGetElementValue(dataElem,value);
				IsmPathLossdB[testUnitIx] = atof(value);
			}
			else
			{
				CVIXMLGetElementValue(dataElem,value);
				UwbPathLossdB[testUnitIx] = atof(value);
			}
		}
	} // end for loop
	
	if(dataElem)
	{
		CVIXMLDiscardElement(dataElem);
	}
	if(rootElem)
	{
		CVIXMLDiscardElement(rootElem);
	}
	if(doc)
	{
		CVIXMLDiscardDocument(doc);
	}
	
	return(0);	
} // end LoadCableLossCompensationFile


/********************************************************
*
* FUNCTION NAME: InitSpecAn
* 
* DESCRIPTION: Initialize spectrum analyzer instrument
*
* ARGUMENT LIST: 
* 
* ARGUMENT           TYPE     I/O    DESCRIPTION       
* --------           ----     ---    -----------
* testInstrument     int
*
* OUTPUTS
*
*
* RETURNS: 			 int
*					(0 = no error) 			 
*				
* 
* 
*********************************************************/
/********************************************//**
* Initialize spectrum analyzer instrument  
***********************************************/ 
int InitSpecAn(int testInstrument)
{
	int error = 0;
	RSSpecAn sa;
	char msg[256];
	char address[60];
	sprintf(address,"TCPIP::192.168.0.%i::INSTR",testInstrument+1);
	
	// set to Nominal condition
	sa.idNumber = testInstrument;  
	strcpy(sa.address,address);
	
	sa.isOpen = 0;
	sa.npts = 2001;
	sa.sweepTime = 0.5;
	sa.centerFreq = 25.0;			  // GHz
	sa.freqSpan = 1.0;				  // GHz
	sa.vidBw = 10.0;				  // MHz
	sa.resBw = 10.0;				  // MHz
	sa.attn = 10.0;					  // dB
	sa.preAmpPow = 0;
	sa.refLevel = 0;
	sa.refLevelOffset = 0;
	
	error |= openSpectrum(sa.address,&sa.session); 
	if (error==0)
	{
		sa.isOpen = 1;
		specAn[testInstrument]=sa;
		error |= SetSpectrum(sa);
	}
	else
	{
		sa.isOpen = 0;
	}
	sprintf(msg,"Initialize Spectrum Analyzer %s",sa.address);
	check_error(error,__FUNCTION__,msg);
	return(error);
} // end InitSpecAn


// Function developed by Patrick to reset bad Units E2P and Tx signal at UWB Power Check measurement
// Function is a temporary fixed and and will be removed
int init_eeprom_and_cpld(char *SN, char *E2P_file, double cpld_timeout_s, int CANport)
{ 
	int timeout_s = 20, error = 0, intSN[10], address, val;
	int InitEEpromMess[]={0x02,0x08,0x63,0x00,0x55,0xAA,0x00,0x00};
	char temp_str[1000];
	FILE *EEPROM_init_file;
	
	// Don't do anything if EEPROM is already initialized 
//	if(GetEEPROMValue(0,CANport) == 0x55)
//		return(0);
	if(GetEEPROMValue(66,CANport) == -1)	// Return -1 if we are dead
		return(-1);

	// Blow away the EEPROM
	SendCommand_c6(1, 8, InitEEpromMess, CANport);
	WaitUntilNoEepromWritesRemains(1, timeout_s, CANport);

	// Convert char MIS to int array
	for(int i=0; i < 6; i++)
		intSN[i] = ((((int) SN[i*2]) << 8) + (int) SN[i*2+1]);

	// Write the SN #  & any values in E2P file (if it exists)
//	error |= WriteEEPROM_mt(1, 71, 76, intSN, CANport); CLEAN_CODE
	if (E2P_file != 0)
	{
		if((EEPROM_init_file=fopen(E2P_file, "r")) == NULL)
			MessagePopup("Error could not open file", E2P_file);
		else
		{
			fscanf(EEPROM_init_file, "%[^\n] ", temp_str); // Eat the first line of the file 
			while(fscanf(EEPROM_init_file, " %d,==,%d ", &address, &val) != EOF)
				//error |= FastWriteEEPROM_mt(1,address,val,CANport);  CODE_CLEAN
			fclose(EEPROM_init_file);
		}
	}
	WaitUntilNoEepromWritesRemains(1, timeout_s, CANport);
	
	// Wait long enough for CPLD to be initialized
	SendReset(CANport);
	NonBlockDelay(cpld_timeout_s);
	DisableSICMsgs(CANport);
	return(0);
 } // end init_eeprom_and_cpld



// Sort array and calculate median
int ArrMedian(double arr[],int NumElements,double *Median)
{
	double t = 0;
	double tempArray[NumElements];
	
	memcpy(tempArray,arr,sizeof(tempArray));
	
	/* Sorting begins */
	for (int i = 1 ; i <= NumElements-1 ; i++)
	{
		/* Trip-i begins  */
		for (int j = 1 ; j <= NumElements-i ; j++)
		{
			if (tempArray[j] <= tempArray[j+1])
			{
				/* Interchanging values */

				t = tempArray[j];
				tempArray[j] = tempArray[j+1];
				tempArray[j+1] = t;
			}
			else
			{
				continue ;
			}
		}
	} /* sorting ends */
	/* calculation of median  */
	if (NumElements % 2 == 0)
	{
		*Median = (tempArray[NumElements/2] + tempArray[NumElements/2+1])/2.0 ;
	}
	else
	{
		*Median = tempArray[NumElements/2 + 1];
	}

}
