/***********************************************************************
 *
 *
 *  COPYRIGHT: Arxtron Technologies Inc. All Rights Reserved.
 *
 *  PURPOSE: - C6 Calibration CAN commands functions
 *
 *  DEVELOPMENT HISTORY:
 *
 *  Date        Name           Rev.   Description
 *  ----------  -------------  -----  -----------------------
 *  08-14-2013  Arxtron    		1.0      Initial Release
 *  
 *  
 *********************************************************************/

#ifndef __CANCommand_H__
#define __CANCommand_H__

#ifdef __cplusplus
    extern "C" {
#endif

#include "cvidef.h"

int CANportIsOpen[6];					 // 6 test units

typedef struct 
{
	char PartNumber[11];			
	char Variant[3];
	char SMD_Flavor[5];
	char SMD_LineCode[2];
	char SerialNumber[13];
	char DaughterBoard[2];
} MISFields;					// 22 characters

MISFields mis, dutMIS[6]; 


int OpenCAN(int CANport);
int CloseCAN(int CANport); 

int SendTxBand0HiFreq(int CANport);
int SendTxBand0LowFreq(int CANport);   
int SendTxBand1LowFreq(int CANport);   
int SendTxBand1HiFreq(int CANport);
int SendTx1OnTx2Off(int freqMHz, int CANport);  
int SendTx1OffTx2On(int freqMHz, int CANport);   
int SendTx1OffTx2Off(int freqMHz, int CANport);    

int SendTxBand(int band, int freqMHz, int CANport);  // We should switch to one function rather than 4 
int SendTxAnt(int ant1, int ant2);					// We should switch to one fucntion rather than 3

int SendTxUwbNominalMode(int CANport);  
int SendTxUwbDac(int UwbDac, int CANport);
int SendReset(int CANport); 
int SendClearFaults(int CANport);
int SetCalUwbDacValue(int value, int CANport);  
int SetEEPROMValue(int address, int value, int CANport);
int SetEEPROMBlockValues(int startAddress, int stopAddress, int *nDacArr, int CANport); 
int SetUutInCompensationMode(int uwbDacValue, int CANport);
int GetEEPROMValue(int address, int CANport);  
int SendIsmPowerCommand(int ismDac, int CANport);
int SendIsmPulsingCommand(int CANport);
int SendIsmNonPulsingCommand(int CANport);
int SendDisableIsmFmCommand(int CANport); 
int SendTxPulseRestoreCommand(int CANport);



#ifdef __cplusplus
    }
#endif

#endif  /* ndef __CANCommand_H__ */
