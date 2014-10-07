/***********************************************************************
 *
 *
 *  COPYRIGHT: Arxtron Technologies Inc. All Rights Reserved.
 *
 *  PURPOSE: - Driver configuration header file for Digital IO 6515   
 *
 *  DEVELOPMENT HISTORY:
 *
 *  Date        Name           Rev.   Description
 *  ----------  -------------  -----  -----------------------
 *  07-29-2013  Arxtron        1      Initial Release
 *  
 *  
 *********************************************************************/ 

#ifndef __DIO6515Def_H__
#define __DIO6515Def_H__

#ifdef __cplusplus
    extern "C" {
#endif

#define DIO6515_NUMBER_OF_ROWS			64
#define DIO6515_NUMBER_OF_COLUMNS		10

#include "cvidef.h"


		
int	DYN_6515_TABLE_DIO_CONFIG, DYN_6515_TABLE_DIO2_CONFIG;


void CreateDigitalIO6515ConfigurationTable(void);
void CreateDigitalIO6515ConfigurationTable2(void);
void DisplayDIO6515Control(int firstTab, int editConfig);
void EnableDIO6515ControlSaving(void);

#ifdef __cplusplus
    }
#endif

#endif  /* ndef __DIO6515Def_H__ */
