//==============================================================================
//
// Title:		DutMemory_Def.h
// Purpose:		A short description of the interface.
//
// Created on:	19/09/2013 at 2:39:02 PM by test.
// Copyright:	. All Rights Reserved.
//
//==============================================================================

#ifndef __DutMemory_Def_H__
#define __DutMemory_Def_H__

#ifdef __cplusplus
    extern "C" {
#endif

#include "cvidef.h"
int DutMemoryPanelHandle;  


int ConvertHexStrToInteger(char hexStr[10]);
void ConvertIntegerToHexStr(int value, char hexStr[10]);
int LoadMessageLibrary(char *filename);
void ResetAllTestUnits(void);

#ifdef __cplusplus
    }
#endif

#endif  /* ndef __DutMemory_Def_H__ */
