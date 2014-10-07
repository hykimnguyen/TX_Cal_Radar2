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

#define TX_BAND_0									0		// Select Band0
#define TX_BAND_1									4		// Select Band1
#define INNER_ANTENNA							0x00	// BIT0 = 0
#define OUTER_ANTENNA							0x01	// BIT0 = 1
#define TRANSMITTER_ENABLED						0x00	// BIT1 = 0  
#define TRANSMITTER_DISABLED					0x02	// BIT1 = 1
#define UWB_DAC_CAL_ADDRESS						177

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
	char ITACvalid[13]; 	
	char DaughterBoard[2];
} MISFields;					// 22 characters

MISFields mis, dutMIS[6]; 


int Open_CAN(int CANport);
int Close_CAN(int CANport); 
int SendTxBand(int band, int freqMHz, int CANport);  
int SendTxAnt(int freqMHz, int tx_state, int CANport);
//int SendTxUwbNominalMode(int CANport);  
int SendTxUwbDac(int UwbDac, int CANport);
int SendReset(int CANport); 
int SendClearFaults(int CANport);
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
