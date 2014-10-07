/***********************************************************************
 *
 *
 *  COPYRIGHT: Arxtron Technologies Inc. All Rights Reserved.
 *
 *  PURPOSE: - Create worker tasks
 *
 *  DEVELOPMENT HISTORY:
 *
 *  Date        Name           Rev.   Description
 *  ----------  -------------  -----  -----------------------
 *  08-06-2013  Arxtron    		1.0      Initial Release
 *  
 *  
 *********************************************************************/ 


#ifndef __worker_H__
#define __worker_H__

#ifdef __cplusplus
    extern "C" {
#endif


#include "cvidef.h"


int DoWork(int dutNumber);
int DoTestSequence(int dutNumber);
void InitializeWorker(int dutNumber);
int GetDutNumber(int testInstrumentNumber);
int GetDutNumber(int testInstrument);
int WorkIsReady(int dutNumber);
void UploadToResultItac(int dutNumber, double totalTestTime);
void LockOtherNest(int dutNumber);
void UnlockOtherNest(int dutNumber);
int NestIsLocked(int dutNumber);


#ifdef __cplusplus
    }
#endif

#endif  /* ndef __worker_H__ */
