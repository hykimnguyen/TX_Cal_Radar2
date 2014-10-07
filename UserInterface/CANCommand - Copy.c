/***********************************************************************
 *
 *
 *  COPYRIGHT: Arxtron Technologies Inc. All Rights Reserved.
 *
 *  PURPOSE: - C6 Calibration CAN command functions
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
*    @file    CANCommand.c
*    @brief   CAN command to open CAN unit and send commands
*    @author  Arxtron Technologies Inc.
*    @date    2013.10.09
*	 Functions for open CAN unit and send commands
*    
*/ 

#include <windows.h>
#include <ansi_c.h>
#include "CANDrv.h"
#include "app_log.h"
#include "CANCommand.h"

//==============================================================================
// Constants
#define NI_CAN         							1		// CAN_Hardware -- 0 CANCARD2
#define BAUDRATE_500K       					2		// BaudRate -- 2 500K
#define CNTRL_MODE_SIC10      					2	    // Valid input, 0 for SRS100, 1 for CNX, 2 for SIC10
#define EEPROM_SIZE								1024	// size of EEPROM in words

#define INNER_ANTENNA							0x00	// BIT0 = 0
#define OUTER_ANTENNA							0x01	// BIT0 = 1
#define ISM_INNER_ANTENNA						0x04	// BIT0 = 0, BIT2 = 1
#define ISM_OUTER_ANTENNA						0x05	// BIT0 = 1, BIT2 = 1

#define TRANSMITTER_ENABLED						0x00	// BIT1 = 0  
#define TRANSMITTER_DISABLED					0x02	// BIT1 = 1

#define SensorAddress							1		// MPIO_0 and MPIO_1 are GND
#define RESET_TIMEOUT_MSEC						3500

#define BAND0									0		// Select Band0
#define BAND1									4		// Select Band1
#define UWB_DAC_CAL_ADDRESS						177


/********************************************************
*
* FUNCTION NAME: OpenCAN
* 
* DESCRIPTION: Open CAN port
*
* ARGUMENT LIST: 
* 
* ARGUMENT           TYPE     I/O    DESCRIPTION       
* --------           ----     ---    -----------
* CANport	 	   	 int
*
* RETURNS: 			 int
*					(0 = no error)
*				
* 
* 
*********************************************************/
/********************************************//**
 *  Open CAN port  
 ***********************************************/
int OpenCAN(int CANport)
{
	int error=0;
	char msg[80];

	
	if (CANportIsOpen[CANport]==0)
	{
		error |= SetCANparameters_c6(NI_CAN,BAUDRATE_500K);
		if (error != 0)
		{
			decode_error(error,__FUNCTION__,"Unable to SetCANparameters."); 
			return(-1);
		}
	
		error |= InitCAN_c6(CANport);
		if (error != 0)
		{
			decode_error(error,__FUNCTION__,"Unable to InitCAN."); 
			return(-2);
		}
	
		error |= SetControllerMode_c6(CNTRL_MODE_SIC10);
		if (error != 0)
		{
			decode_error(error,__FUNCTION__,"Unable to SetControllerMode."); 
			return(-3);
		}
	
		error |= InitController_c6(CANport);  
		if (error)
		{
			CANportIsOpen[CANport] = 0;
			sprintf(msg,"%s, Fail to open CANport=%i",__FUNCTION__,CANport);  
		}
		else
		{
			CANportIsOpen[CANport]=1;
			sprintf(msg,"%s, CANport=%i",__FUNCTION__,CANport);  
		}
		
	}
	else
	{
		sprintf(msg,"%s, CANport=%i is already opened.",__FUNCTION__,CANport); 
		add_log(msg);
	}
	check_error(error,__FUNCTION__,msg);
	return(error);
} // end OpenCAN


/********************************************************
*
* FUNCTION NAME: CloseCAN
* 
* DESCRIPTION: Close CAN port
*
* ARGUMENT LIST: 
* 
* ARGUMENT           TYPE     I/O    DESCRIPTION       
* --------           ----     ---    -----------
* CANport	 	   	 int
*
* RETURNS: 			 int
*					(0 = no error)
*				
* 
* 
*********************************************************/
/********************************************//**
 *  Close CAN port  
 ***********************************************/
int CloseCAN(int CANport)
{
	int error=0;
	char msg[80];
	
	if (CANportIsOpen[CANport] == 1)
	{
		error |= CloseController_c6(CANport);
		error |= CloseCAN_c6(CANport);
		sprintf(msg,"%s, CANport=%i",__FUNCTION__,CANport);
		check_error(error,msg,"Command failed.");  
	}
	else
	{
		sprintf(msg,"%s, CANport=%i is not opened.",__FUNCTION__,CANport); 
		add_log(msg);
	}
	
	return(error);
} // end CloseCAN

/********************************************************
*
* FUNCTION NAME: SendTxBand1HiFreq
* 
* DESCRIPTION: Set transmitter to transmit at highest possible frequency on Band1
*
* ARGUMENT LIST: 
* 
* ARGUMENT           TYPE     I/O    DESCRIPTION       
* --------           ----     ---    -----------
* CANport	 	   	 int
*
* RETURNS: 			 int
*					(0 = no error)
*				
* 
* 
*********************************************************/
/********************************************//**
 *  Set transmitter to transmit at highest possible frequency on Band1  
 ***********************************************/
int SendTxBand1HiFreq(int CANport)
{
	int error;

	// PLL cmd = {2, 39, 14, 0, 6D, 60, 0, 4}   // 28 GHz 
	int freq_MHz= 28000;	
	int Command[8] = {2, 57, 20, 0, (freq_MHz >> 8), (freq_MHz & 0xFF), 0, BAND1};   // set TXPowerCalibration
	int nNumOfBytes	= 8; 
	
	error = SendCommand_c6(SensorAddress,nNumOfBytes,Command,CANport);
	
	check_error(error,__FUNCTION__,"Command failed.");
	
	return(error);
} // end SendTxBand1HiFreq

/********************************************************
*
* FUNCTION NAME: SendTxBand1LowFreq
* 
* DESCRIPTION: Set transmitter to transmit at lowest possible frequency on Band1
*
* ARGUMENT LIST: 
* 
* ARGUMENT           TYPE     I/O    DESCRIPTION       
* --------           ----     ---    -----------
* CANport	 	   	 int
*
* RETURNS: 			 int
*					(0 = no error)
*				
* 
* 
*********************************************************/
/********************************************//**
 *  Set transmitter to transmit at lowest possible frequency on Band1  
 ***********************************************/
int SendTxBand1LowFreq(int CANport)
{
	int error;
	
	// PLL cmd = {2, 39, 14, 0, 4E, 20, 0, 4}   // 20 GHz 
	int freq_MHz = 20000;		
	int Command[8] = {2, 57, 20, 0, (freq_MHz >> 8), (freq_MHz & 0xFF), 0, BAND1};   // set TXPowerCalibration
	int nNumOfBytes	= 8; 
	
	error = SendCommand_c6(SensorAddress,nNumOfBytes,Command,CANport);
	
	check_error(error,__FUNCTION__,"Command failed.");
	
	return(error);
} // end SendTxBand1LowFreq

/********************************************************
*
* FUNCTION NAME: SendTxBand0LowFreq
* 
* DESCRIPTION: Set transmitter to transmit at lowest possible frequency on Band0
*    
* ARGUMENT LIST: 
* 
* ARGUMENT           TYPE     I/O    DESCRIPTION       
* --------           ----     ---    -----------
* CANport	 	   	 int
*
* RETURNS: 			 int
*					(0 = no error)
*				
* 
* 
*********************************************************/
/********************************************//**
 *  Set transmitter to transmit at lowest possible frequency on Band0   
 ***********************************************/
int SendTxBand0LowFreq(int CANport)
{
	int error;	
	
	// PLL cmd = {2, 39, 14, 0, 4E, 20, 0, 0}  // 20 GHz = 4E20
	int freq_MHz = 20000;		
	int Command[8] = {2, 57, 20, 0, (freq_MHz >> 8), (freq_MHz & 0xFF), 0, BAND0};   // set TXPowerCalibration
	int nNumOfBytes	= 8; 
	
	error = SendCommand_c6(SensorAddress,nNumOfBytes,Command,CANport);
	
	check_error(error,__FUNCTION__,"Command failed.");  
	
	return(error);
} // end SendTxBand0LowFreq


/********************************************************
*
* FUNCTION NAME: SendTxBand0HiFreq
* 
* DESCRIPTION: Set transmitter to transmit at highest possible frequency on Band0
*    
* ARGUMENT LIST: 
* 
* ARGUMENT           TYPE     I/O    DESCRIPTION       
* --------           ----     ---    -----------
* CANport	 	   	 int
*
* RETURNS: 			 int
*					(0 = no error)
*				
* 
* 
*********************************************************/
/********************************************//**
 *  Set transmitter to transmit at highest possible frequency on Band0   
 ***********************************************/
int SendTxBand0HiFreq(int CANport)
{
	int error;

	// PLL cmd = {2, 39, 14, 0, 6D, 60, 0, 0}  // 20 GHz = 4E20
	int freq_MHz = 28000;		
	int Command[8] = {2, 57, 20, 0, (freq_MHz >> 8), (freq_MHz & 0xFF), 0, BAND0};   // set TXPowerCalibration
	int nNumOfBytes	= 8; 
	
	error = SendCommand_c6(SensorAddress,nNumOfBytes,Command,CANport);
	
	check_error(error,__FUNCTION__,"Command failed.");  
	
	return(error);
} // end SendTxBand0HiFreq


/********************************************************
*
* FUNCTION NAME: SendTxUwbNominalMode
* 
* DESCRIPTION: Set transmitter to transmit at Nominal condition
*
* ARGUMENT LIST: 
* 
* ARGUMENT           TYPE     I/O    DESCRIPTION       
* --------           ----     ---    -----------
* CANport	 	   	 int
*
* RETURNS: 			 int
*					(0 = no error)
*				
* 
* 
*********************************************************/
/********************************************//**
 *  Set transmitter to transmit at Nominal condition   
 ***********************************************/
int SendTxUwbNominalMode(int CANport)
{
	int error;
	
	error = SendReset(CANport);

	check_error(error,__FUNCTION__,"Command failed.");  
	
	return(error);
} // end SendTxUwbNominalMode


/********************************************************
*
* FUNCTION NAME: SendTxUwbDac
* 
* DESCRIPTION: Set transmitter to transmit at input UWB DAC value
*
* ARGUMENT LIST: 
* 
* ARGUMENT           TYPE     I/O    DESCRIPTION       
* --------           ----     ---    -----------
* UwbDac			 int
* CANport	 	   	 int
*
* RETURNS: 			 int
*					(0 = no error)
*				
* 
* 
*********************************************************/
/********************************************//**
 *  Set transmitter to transmit at input UWB DAC value   
 ***********************************************/
int SendTxUwbDac(int UwbDac, int CANport)
{
	int error;
	char msg[80];
	
	// Power command = {2, 39, 0E, 0, 0, AA, FF, FF}  // Set UWB DAC to 170 
	int DAC_Command[8] = {2, 57, 14, 0, 0, UwbDac, 255, 255};   // power command
	int nNumOfBytes	= 8; 
	
	error = SendCommand_c6(SensorAddress,nNumOfBytes,DAC_Command,CANport);

	sprintf(msg,"%s,UwbDac=%i",__FUNCTION__,UwbDac);
	check_error(error,msg,"Command failed.");  
	return(error);
} // end SendTxUwbDac

/********************************************//**
 *  Send clear faults command  
 ***********************************************/
int SendClearFaults(int CANport)
{
	int error;
	
	error = FastWriteEEPROM_c6(SensorAddress, 922, 0, CANport); // clear faults   	
	
	check_error(error,__FUNCTION__,"Command failed.");  
	return(error);
} // end SendClearFaults


/********************************************************
*
* FUNCTION NAME: SetCalUwbDacValue
* 
* DESCRIPTION: Store calibrated UWB DAC value to EEPROM (addr=177)
*
* ARGUMENT LIST: 
* 
* ARGUMENT           TYPE     I/O    DESCRIPTION       
* --------           ----     ---    -----------
* value				 int
* CANport	 	   	 int
*
* RETURNS: 			 int
*					(0 = no error)
*				
* 
* 
*********************************************************/
/********************************************//**
 *  Store calibrated UWB DAC value to EEPROM 
 ***********************************************/
int SetCalUwbDacValue(int value, int CANport)
{
	int error;
	
	error = SetEEPROMValue(UWB_DAC_CAL_ADDRESS,value,CANport);	  // calibrated UWBDACAddress = 177;	
	
	check_error(error,__FUNCTION__,"Command failed.");  
	return(error);
} // end SetCalUwbDacValue


/********************************************************
*
* FUNCTION NAME: SetEEPROMValue
* 
* DESCRIPTION: Store UWB DAC value to an EEPROM address 
*
* ARGUMENT LIST: 
* 
* ARGUMENT           TYPE     I/O    DESCRIPTION       
* --------           ----     ---    -----------
* address			 int
* value				 int
* CANport	 	   	 int
*
* RETURNS: 			 int
*					(0 = no error)
*				
* 
* 
*********************************************************/
/********************************************//**
 *  Store UWB DAC value to an EEPROM address 
 ***********************************************/
int SetEEPROMValue(int address, int value, int CANport)
{
	int error;
	char msg[80];
	
	// WriteEEPROM cmd = {2, 8, 0A, 0, 0, 4D, 60, 94}	// set Address 77 with 24724
	error = WriteEEPROM_c6(SensorAddress,address,address,&value,CANport);
	Sleep(100);
	
	sprintf(msg,"%s,UwbDacAddress=%i,value=%i",__FUNCTION__,address,value); 
	check_error(error,msg,"Command failed.");  
	return(error);
} // end SetEEPROMValue


/********************************************************
*
* FUNCTION NAME: SetEEPROMBlockValues
* 
* DESCRIPTION: Store an array of UWB DAC values to EEPROM addresses
*
* ARGUMENT LIST: 
* 
* ARGUMENT           TYPE     I/O    DESCRIPTION       
* --------           ----     ---    -----------
* startAddress		 int
* stopAddress		 int
* nDacArr			 int *
* CANport	 	   	 int
*
* RETURNS: 			 int
*					(0 = no error)
*				
* 
* 
*********************************************************/
/********************************************//**
 *  Store an array of UWB DAC values to EEPROM addresses   
 ***********************************************/
int SetEEPROMBlockValues(int startAddress, int stopAddress, int *nDacArr, int CANport)
{
	int error;
	
	error = WriteEEPROM_c6(SensorAddress,startAddress,stopAddress,nDacArr,CANport);
	Sleep(200);  // PS.  This is clearly not sufficient wait time.
	
	check_error(error,__FUNCTION__,"Command failed.");  
	return(error);
} // end SetEEPROMBlockValues


/********************************************************
*
* FUNCTION NAME: SetUutInCompensationMode
* 
* DESCRIPTION: Set bit0 at EEPROM address 177 to make UUT 
*    use the calibrated UWB DAC power table in address 80L-86H
*
* ARGUMENT LIST: 
* 
* ARGUMENT           TYPE     I/O    DESCRIPTION       
* --------           ----     ---    -----------
* uwbDacValue	 	 int 
* CANport	 	   	 int
*
* RETURNS: 			 int
*					(0 = no error)
*				
* 
* 
*********************************************************/
/********************************************//**
 *  Set bit0 at EEPROM address 177 to make UUT 
 *    use the calibrated UWB DAC power table in address 80L-86H  
 ***********************************************/
int SetUutInCompensationMode(int uwbDacValue, int CANport)
{
	int error;
	
	// Set the UUT so that it uses 100MHz bin calibration table values
	// UWB DAC is stored in low byte at address 177 
	uwbDacValue = uwbDacValue | 0x0100;
	
	error = SetCalUwbDacValue(uwbDacValue,CANport);

	check_error(error,__FUNCTION__,"Command failed.");  
	return(error);
} // end SetUutInCompensationMode



/********************************************************
*
* FUNCTION NAME: GetEEPROMValue
* 
* DESCRIPTION: Get UWB DAC value from an EEPROM address
*
* ARGUMENT LIST: 
* 
* ARGUMENT           TYPE     I/O    DESCRIPTION       
* --------           ----     ---    -----------
* address			 int
* CANport	 	   	 int
*
* RETURNS: 			 int
*					(0 = no error)
*				
* 
* 
*********************************************************/
/********************************************//**
 *  Get UWB DAC value from an EEPROM address  
 ***********************************************/
int GetEEPROMValue(int address, int CANport)
{
	int error;
	int valueE2P;
	
	error = ReadEEPROMPart_c6(SensorAddress,address,address,&valueE2P,CANport);
	//Sleep(200);  // Why the heck wait after a read?
	
	if (error == 0)
	{
		add_log(__FUNCTION__);
		return(valueE2P);
	}
	else
	{
		decode_error(error,__FUNCTION__,"Command failed");
		return(-1);
	}
} // end GetEEPROMValue

/********************************************************
*
* FUNCTION NAME: SendTx1OnTx2Off
* 
* DESCRIPTION: Set Tx1 On and Tx2 Off at a set frequency
*
* ARGUMENT LIST: 
* 
* ARGUMENT           TYPE     I/O    DESCRIPTION       
* --------           ----     ---    -----------
* freqMHz			 int
* CANport	 	   	 int
*
* RETURNS: 			 int
*					(0 = no error)
*				
* 
* 
*********************************************************/
/********************************************//**
 *  Set Tx1 On and Tx2 Off at a set frequency 
 ***********************************************/
int SendTx1OnTx2Off(int freqMHz, int CANport)
{
	int error;
	char msg[80];	
	
	// PLL Command = {2, 39, 14, 0, 60, 18, 0, 0}  // Set Tx1 ON
	int Tx1OnTx2Off = INNER_ANTENNA | TRANSMITTER_ENABLED;	  // 0
	int Command[8] = {2, 57, 20, 0, (freqMHz >> 8), (freqMHz & 0xFF), 0, Tx1OnTx2Off};   // PLL command
	int nNumOfBytes	= 8; 								 
	
	error = SendCommand_c6(SensorAddress,nNumOfBytes,Command,CANport);
	
	sprintf(msg,"%s,FrequencyMHz=%i",__FUNCTION__,freqMHz);
	check_error(error,msg,"Command failed.");  
	return(error);
} // end SendTx1OnTx2Off 


/********************************************************
*
* FUNCTION NAME: SendTx1OffTx2On
* 
* DESCRIPTION: Set Tx1 Off and Tx2 On at a set frequency
*
* ARGUMENT LIST: 
* 
* ARGUMENT           TYPE     I/O    DESCRIPTION       
* --------           ----     ---    -----------
* freqMHz			 int
* CANport	 	   	 int
*
* RETURNS: 			 int
*					(0 = no error)
*				
* 
* 
*********************************************************/
/********************************************//**
 *  Set Tx1 Off and Tx2 On at a set frequency  
 ***********************************************/
int SendTx1OffTx2On(int freqMHz, int CANport)
{
	int error;
	char msg[80];	

	// PLL Command = {2, 39, 14, 0, 60, 18, 0, 1}  // TX2 ON
	int Tx1OffTx2On = OUTER_ANTENNA | TRANSMITTER_ENABLED;	  // 1
	int Command[8] = {2, 57, 20, 0, (freqMHz >> 8), (freqMHz & 0xFF), 0, Tx1OffTx2On};   // PLL command
	int nNumOfBytes	= 8;
	
	error = SendCommand_c6(SensorAddress,nNumOfBytes,Command,CANport);
	
	sprintf(msg,"%s,FrequencyMHz=%i",__FUNCTION__,freqMHz);  
	check_error(error,msg,"Command failed.");  
	return(error);
} // end SendTx1OffTx2On


/********************************************************
*
* FUNCTION NAME: SendTx1OffTx2Off
* 
* DESCRIPTION: Set Tx1 Off and Tx2 Off at a set frequency
*
* ARGUMENT LIST: 
* 
* ARGUMENT           TYPE     I/O    DESCRIPTION       
* --------           ----     ---    -----------
* freqMHz			 int
* CANport	 	   	 int
*
* RETURNS: 			 int
*					(0 = no error)
*				
* 
* 
*********************************************************/
/********************************************//**
 *  Set Tx1 Off and Tx2 Off at a set frequency  
 ***********************************************/
int SendTx1OffTx2Off(int freqMHz, int CANport)
{
	int error;
	char msg[80];
	
	// PLL command = {2, 39, 14, 0, 60, 18, 0, 2}  // TX1 OFF
	int Tx1OffTx2Off = INNER_ANTENNA | TRANSMITTER_DISABLED;  // 2
	int Command[8] = {2, 57, 20, 0, (freqMHz >> 8), (freqMHz & 0xFF), 0, Tx1OffTx2Off};   // PLL command
	int nNumOfBytes	= 8; 
	
	error = SendCommand_c6(SensorAddress,nNumOfBytes,Command,CANport);

	sprintf(msg,"%s,FrequencyMHz=%i",__FUNCTION__,freqMHz);  
	check_error(error,msg,"Command failed.");  
	return(error);
} // end Tx1OffTx2Off

/********************************************************
*
* FUNCTION NAME: SendReset
* 
* DESCRIPTION: Perform a soft reset
*
* ARGUMENT LIST: 
* 
* ARGUMENT           TYPE     I/O    DESCRIPTION       
* --------           ----     ---    -----------
* CANport	 	   	 int
*
* RETURNS: 			 int
*					(0 = no error)
*				
* 
* 
*********************************************************/
/********************************************//**
 *  Perform a soft reset  
 ***********************************************/
int SendReset(int CANport)
{
	int error;
	int Reset_Command[8] = {2, 6, 0, 0, 0, 0, 0, 0};   // reset command
	int nNumOfBytes	= 8; 

	error = SendCommand_c6(SensorAddress,nNumOfBytes,Reset_Command,CANport);
	Sleep(RESET_TIMEOUT_MSEC);
	
	check_error(error,__FUNCTION__,"Command failed.");  
	return(error);
} // end SendReset

/********************************************************
*
* FUNCTION NAME: SendIsmPowerCommand
* 
* DESCRIPTION: Set transmitter to transmit ISM at a set DAC
*
* ARGUMENT LIST: 
* 
* ARGUMENT           TYPE     I/O    DESCRIPTION       
* --------           ----     ---    -----------
* ismDac			 int
* CANport	 	   	 int
*
* RETURNS: 			 int
*					(0 = no error)
*				
* 
* 
*********************************************************/
/********************************************//**
 *  Set transmitter to transmit ISM at a set DAC  
 ***********************************************/
int SendIsmPowerCommand(int ismDac, int CANport)
{
	int error;
	char msg[80];
	
	int ISM_DAC_Command[8] = {2, 57, 15, 0, 0, ismDac, 255, 255};     
	int nNumOfBytes	= 8; 

	error = SendCommand_c6(SensorAddress,nNumOfBytes,ISM_DAC_Command,CANport);

	sprintf(msg,"%s,IsmDac=%i",__FUNCTION__,ismDac);  
	check_error(error,msg,"Command failed.");  
	return(error);			
}  // end SendIsmPowerCommand


/********************************************************
*
* FUNCTION NAME: SendIsmPulsingCommand
* 
* DESCRIPTION: Set transmitter to transmit in ISM Pulsing mode
*
* ARGUMENT LIST: 
* 
* ARGUMENT           TYPE     I/O    DESCRIPTION       
* --------           ----     ---    -----------
* CANport	 	   	 int
*
* RETURNS: 			 int
*					(0 = no error)
*				
* 
* 
*********************************************************/
/********************************************//**
 *  Set transmitter to transmit in ISM Pulsing mode   
 ***********************************************/
int SendIsmPulsingCommand(int CANport)
{
	int error;
	int ISM_Pulsing_Command[8] = {2, 62, 1, 0, 0, 4, 0, 0};     
	int nNumOfBytes	= 8; 

	error = SendCommand_c6(SensorAddress,nNumOfBytes,ISM_Pulsing_Command,CANport);

	check_error(error,__FUNCTION__,"Command failed.");  
	return(error);			
}  // end SendIsmPulsingCommand


/********************************************************
*
* FUNCTION NAME: SendIsmNonPulsingCommand
* 
* DESCRIPTION: Set transmitter to transmit in ISM non-Pulsing mode
*
* ARGUMENT LIST: 
* 
* ARGUMENT           TYPE     I/O    DESCRIPTION       
* --------           ----     ---    -----------
* CANport	 	   	 int
*
* RETURNS: 			 int
*					(0 = no error)
*				
* 
* 
*********************************************************/
/********************************************//**
 *  Set transmitter to transmit in ISM non-Pulsing mode  
 ***********************************************/
int SendIsmNonPulsingCommand(int CANport)
{
	int error;
	int ISM_Non_Pulsing_Command[8] = {2, 62, 1, 0, 0, 7, 0, 0};     // ISM DAC Command
	int nNumOfBytes	= 8; 

	error = SendCommand_c6(SensorAddress,nNumOfBytes,ISM_Non_Pulsing_Command,CANport);
	
	check_error(error,__FUNCTION__,"Command failed.");  
	return(error);			
}  // end SendIsmNonPulsingCommand


/********************************************************
*
* FUNCTION NAME: SendDisableIsmFmCommand
* 
* DESCRIPTION: Disable ISM FM mode
*
* ARGUMENT LIST: 
* 
* ARGUMENT           TYPE     I/O    DESCRIPTION       
* --------           ----     ---    -----------
* CANport	 	   	 int
*
* RETURNS: 			 int
*					(0 = no error)
*				
* 
* 
*********************************************************/
/********************************************//**
 *  Disable ISM FM mode   
 ***********************************************/
int SendDisableIsmFmCommand(int CANport)
{
	int error;
	int Disable_ISM_FM_Command[8] = {2, 56, 13, 0, 0, 1, 0, 0};
	int nNumOfBytes	= 8; 

	error = SendCommand_c6(SensorAddress,nNumOfBytes,Disable_ISM_FM_Command,CANport);
	
	check_error(error,__FUNCTION__,"Command failed.");  
	return(error);			
}  // end SendDisableIsmFmCommand


/********************************************************
*
* FUNCTION NAME: SendTxPulseRestoreCommand
* 
* DESCRIPTION:  Set transmitter to restore transmit pulse
*
* ARGUMENT LIST: 
* 
* ARGUMENT           TYPE     I/O    DESCRIPTION       
* --------           ----     ---    -----------
* CANport	 	   	 int
*
* RETURNS: 			 int
*					(0 = no error)
*				
* 
* 
*********************************************************/
/********************************************//**
 *  Set transmitter to restore transmit pulse    
 ***********************************************/
int SendTxPulseRestoreCommand(int CANport)
{
	int error;
	int Tx_Pulse_Restore_Command[8] = {2, 56, 13, 0, 0, 255, 0, 0};     // ISM DAC Command
	int nNumOfBytes	= 8; 

	error = SendCommand_c6(SensorAddress,nNumOfBytes,Tx_Pulse_Restore_Command,CANport);
	
	check_error(error,__FUNCTION__,"Command failed.");  
	return(error);			
}  // end SendTxPulseRestoreCommand
