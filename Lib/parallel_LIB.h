/***********************************************************************
 *
 *
 *  COPYRIGHT: Arxtron Technologies Inc. All Rights Reserved.
 *
 *  PURPOSE: - Create parallel test sequence
 *
 *  DEVELOPMENT HISTORY:
 *
 *  Date        Name           Rev.   Description
 *  ----------  -------------  -----  -----------------------
 *  07-24-2013  Arxtron    		1.0      Initial Release
 *
 *
 *********************************************************************/

#ifndef __parallel_H__
#define __parallel_H__

#ifdef __cplusplus
    extern "C" {
#endif


#include "cvidef.h"


static int gWorkerPool;
int __stdcall InitializeParallelWorkers(void);
void __stdcall ReleaseParallelWorkers(void);
int __stdcall TestSequenceParallel(void);
static int NewWorker(void *workerData);


#ifdef __cplusplus
    }
#endif

#endif  /* ndef __parallel_H__ */
