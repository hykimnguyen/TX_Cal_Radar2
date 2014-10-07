/***********************************************************************
 *
 *
 *  COPYRIGHT: Arxtron Technologies Inc. All Rights Reserved.
 *
 *  PURPOSE: - File utilities functions
 *
 *  DEVELOPMENT HISTORY:
 *
 *  Date        Name           Rev.   Description
 *  ----------  -------------  -----  -----------------------
 *  08-06-2013  Arxtron    		1.0      Initial Release
 *  
 *  
 *********************************************************************/

#ifndef __FileUtils_H__
#define __FileUtils_H__

#ifdef __cplusplus
    extern "C" {
#endif


#include "cvidef.h"

int RemoveFile(const char *pFilename);

#ifdef __cplusplus
    }
#endif

#endif  /* ndef __FileUtils_H__ */
