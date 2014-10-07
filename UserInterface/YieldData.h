//==============================================================================
//
// Title:		YieldData.h
// Purpose:		A short description of the interface.
//
// Created on:	26/08/2013 at 3:15:30 PM by Hy-Kim.
// Copyright:	. All Rights Reserved.
//
//==============================================================================

#ifndef __YieldData_H__
#define __YieldData_H__

#ifdef __cplusplus
    extern "C" {
#endif
 
#include "cvidef.h"


int YieldData_LockHandle;

int InitializeLongTermCount(void);
void LongTermYield(int longTermFail, int longTermPass, char * DateCleared, char * FileLocation);
void ShortTermYield(int shortTermFail, int shortTermPass);
void SetHistoYield(int isPassStatus);
void ClearShortTerm(void);
void ClearLongTerm(void);
int readYield(char * fileLocation,char * field_return);
int writeYield(char * fileLocation,char * msg);
int InitializeCycleCount(void);
void updateCycleCountDisplay(int nest);

#ifdef __cplusplus
    }
#endif

#endif  /* ndef __YieldData_H__ */
