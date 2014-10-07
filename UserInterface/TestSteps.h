//==============================================================================
//
// Title:		TestSteps.h
// Purpose:		A short description of the interface.
//
// Created on:	23/06/2013 at 12:23:54 PM by Arxtron Technologies.
// Copyright:	. All Rights Reserved.
//
//==============================================================================

#ifndef __TestSteps_H__
#define __TestSteps_H__

#ifdef __cplusplus
    extern "C" {
#endif


#include "cvidef.h"
#include <ansi_c.h>
		
#define  NUMBER_OF_TEST_UNITS			6
#define	 testARRAY_SIZE 				150   
#define  BUFFER_SIZE 					256

		
typedef struct
{ 
	char		testNum[BUFFER_SIZE];
	char   		testName[BUFFER_SIZE];
	char   		testFuncName[BUFFER_SIZE];	
	char   		testSkip[BUFFER_SIZE];
	char   		testType[BUFFER_SIZE]; 
	char   		testAbort[BUFFER_SIZE];  	
	char   		testLowLimit[BUFFER_SIZE];  
	char   		testHighLimit[BUFFER_SIZE];
	char 		testUnit[BUFFER_SIZE];     
	char 		testResult[BUFFER_SIZE];
	char 		testNest[BUFFER_SIZE];
	char 		testResultVal[BUFFER_SIZE];

}ItacTestStepStruct;	
ItacTestStepStruct mtgItacTestStep[10][testARRAY_SIZE];   // data structure to upload data to ITAC similar to mtgTestStepInfo but expand test to include multiple data measurements and limits
int ITS_Idx[10];  // ITAC Test Step Count for each nest

void resetTestStation(void);  
void powerTestStation(int state);
bool Bat_Ctrl(int testNumber, int nestNum);
bool Restart_Unit (int testNumber, int nestNum);
//all new NB functions
bool InitInterfaces (void);  
bool InitCanInterface(int testNumber, int nestNum);
bool InitCanInterfaceDbg(int nestNum);
bool Sensor_Comm_Init(int testNumber, int nestNum);
bool Sensor_Comm_InitDbg(int nestNum);


bool GetSerialNumber (int testNumber, int nestNum);   
bool GetSWVersion (int testNumber, int nestNum);   
bool Init_Tx_Cal(int testNumber, int nestNum);
bool Init_Tx_CalDbg(int nestNum);
bool PingDut(int testNumber, int nestNum);
bool PingDutDbg(int nestNum);
bool ReadPoint (int testNumber, int nestNum);
bool ReadPointCSV (int testNumber, int nestNum);
bool WritePoint (int testNumber, int nestNum);
bool WritePoint (int testNumber, int nestNum);
bool WritePointCsvValue  (int testNumber, int nestNum);  

bool SaveConfigPoints (int testNumber, int nestNum);   
bool Make_Path (int testNumber, int nestNum);   
bool Force_Radar_Mode (int testNumber, int nestNum);   
bool GetOccupiedBw (int testNumber, int nestNum);   
bool Select_TX_Antenna (int testNumber, int nestNum);   
bool SetCWMode (int testNumber, int nestNum);   
bool SetHondaTxPowerCal (int testNumber, int nestNum);   
bool GetTxPower (int testNumber, int nestNum);   
bool GetCenterFrequency (int testNumber, int nestNum);   
bool GetCwLeakage (int testNumber, int nestNum);   
bool DisconnectTXCal (int nestNum) ;  
bool DisconnectCan (int nestNum) ;  
bool DiscardHanles (int nestNum);   
char * Get_Dll_Version (void);
bool Get_Test_Instrument(int testNumber, int nestNum);
bool Get_Test_InstrumentDbg(int nestNum);
bool WriteDUTData(int testNumber, int nestNum);  //aa
bool SerialpointsCheck(int testNumber, int nestNum);   //aa
bool Proceed_Request (int testNumber, int nestNum); 
bool SerialpointsCheck(int testNumber, int nestNum);
bool Release_Test_Instrument (int testNumber, int nestNum);
bool Init_Spec_An (int testNumber, int nestNum);
bool Close_Spec_An (int testNumber, int nestNum);
bool WriteNBMailboxPoints(int testNumber, int nestNum);
bool VerifyNBMailboxPoints(int testNumber, int nestNum);
void resetNest(int nestNum);
void setDutIndicators (int dutNumber, int setPass, int setBusy, int setFail);
int LockTestInstrument(int dutNumber, int TimeoutSec);
int UnlockTestInstrument(int dutNumber);
int GetTestInstrumentNumber(int nestNum); 
void RestartTestUnit(int testUnit);
void GetTestStepLimits(void);
bool Release_Other_Nest (int testNumber, int nestNum);
void clearNestLed(int nestNum);
int GetNumberOfRunningBoard(void);   
void addItacTestStep(int testNumber,int nestNum, int itsTestNumber);
void clearItacTestStep(int nestNum, int itsTestNumber);
void resetItacTestStep(int nestNum);
void addSensorTemperatureToIts(int testNumber,int nestNum,int low_thresh,int high_thresh,int temperature);
void addMeasureCurrentToIts(int testNumber,int nestNum,double low_thresh,double high_thresh,double aValue, int status);
void addProceedRequestToIts(int testNumber,int nestNum, int status);
void addFirmwareVersionToIts(int testNumber,int nestNum);
void addCrossOverFrequencyToIts(int testNumber,int nestNum,int Band0_Low_FrequencyMHz,int Band0_High_FrequencyMHz,int Band1_Low_FrequencyMHz,int Band1_High_FrequencyMHz,int TransitionFrequencyMHz);
void addCalTxUwbPowerToIts(int testNumber,int nestNum,double TxCalibratedUwbPeakPwr,double TxCalibratedUwbPeakFrequency,double TxAdjustmentMargin,int CalibratedDacValue,int CalibratedDACValues100MHzBins[14],double uwbDeltaPower);
void addVerifyCalUwbDacToIts(int testNumber,int nestNum,int ReadBackUwbDacValue);
void addMeasureIsmPullingAndPowerCalToIts(int testNumber,int nestNum,double IsmPeakPower,double IsmDeltaFrequency,int calIsmDac,double DeltaIsmPowerAtMinus2_5MHz,double DeltaIsmPowerAtPlus2_5MHz);
void addMeasureIsmPullingAndPowerToIts(int testNumber,int nestNum,double IsmPeakPower,double IsmDeltaFrequency,double DeltaIsmPowerAtMinus2_5MHz,double DeltaIsmPowerAtPlus2_5MHz);
void addMeasureUwbPeakPowerToIts(int testNumber,int nestNum,double PeakPowerUWB,double PeakFrequencyUWB);
void addMeasureTxDiffPowerToIts(int testNumber,int nestNum,double TxDiffRes[6]);
void addMeasureTxIsolationPowerToIts(int testNumber,int nestNum,double TxIsolationDiffRes[6]);
void addMeasureTxIsolationAtCalUwbToIts(int testNumber,int nestNum,double TxIsolationResAtCalUwbDac[6]);
void addWriteNBMailboxPointsToIts(int testNumber,int nestNum, char *points, bool testResult);
void addVerifyNBMailboxPointsToIts(int testNumber,int nestNum, char *points, bool testResult);
void addSWVersionToIts(	int testNumber,int nestNum,
					  	char *HpApp, char *requiredHPApp,
					 	char *HpBoot, char *requiredHPBoot,
					 	char *DspApp, char *requiredDSPApp,
					 	char *DspBoot, char* requiredDSPBoot, int error);    
void addMakePathStatusToIts(int testNumber, int nestNum, int status);
void addSetTemperatureCompensationToIts(int testNumber, int nestNum, char *Point1, char *Point1Val,char *Point2, char *Point2Val, int errorStatus);     
void addSetMaxPowerForOccupiedBWToIts(int testNumber,int nestNum,int point, char * value, char *min, char *max, int status);
void addSaveConfigPointsToIts(int testNumber,int nestNum, int errorStatus);
void addForce_Radar_ModeToIts(int testNumber, int nestNum, char *pmode, int errorStatus);
void addGetOccupiedBwToIts(int testNumber, int nestNum, char *pmode, double Bandwidth, char *unit, char *Low_Limit,char *High_Limit,int errorStatus);
void addSelect_TX_AntennaToIts(int testNumber, int nestNumchar, char *pmode, int errorStatus);
void addSetCWModeToIts(int testNumber, int nestNum, int mode, int errorstatus);
void addSetHondaTxPowerCalToIts(int testNumber, int nestNum, char *value, char *Low_Limit, char *High_Limit, int returnVal);
void addGetTxPowerToIts(int testNumber, int nestNum, double main_power, char *Low_Limit, char *High_Limit, int retrunVal);
void addGetCenterFrequencyToIts(int testNumber, int nestNum, double main_frequency, char *Low_Limit, char *High_Limit, int returnVal);
void addGetCwLeakageToIts(int testNumber, int nestNum, double main_Leakage, char *unit, char *Low_Limit, char *High_Limit, int returnVal);
void addReadTemperatureToIts(int testNumber, int nestNum, int TempMeasurement, double TCelsius, double minCelsius, double maxCelsius, double Delta_T, double Delta_L, int returnVal);
int CompareValueWithLimits (char *TestName, char *value, char *Low_Limit, char *High_Limit );
bool ReadTemperature (int testNumber, int nestNum);
int GetSerialNumberDUT (int nestNum, char *serial);
bool SetTemperatureCompensation (int testNumber, int nestNum);
bool SetMaxPowerForOccupiedBW (int testNumber, int nestNum);
bool DiscardAllHandles (void);
void addVerifyDUTDataToIts(int testNumber,int nestNum,char * value, int status);
void addWriteToPointResultsToIts(int testNumber,int nestNum,int point, char * value, char *min, char *max, int status);
void addReadPointResultsToIts(int testNumber,int nestNum,int point, char * value, char *min, char *max, int status);
void addFailFctResultsToIts(int testNumber,int nestNum,char * name, char * value, char *min, char *max, int status);
bool SetGMTxPowerCal (int testNumber, int nestNum);   
bool Reset_Bat(int testNumber, int nestNum);

#ifdef __cplusplus
    }
#endif

#endif  /* ndef __TestSteps_H__ */
