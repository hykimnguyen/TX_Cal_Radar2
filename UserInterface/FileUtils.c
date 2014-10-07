/***********************************************************************
 *
 *
 *  COPYRIGHT: Arxtron Technologies Inc. All Rights Reserved.
 *
 *  PURPOSE: - File utility functions
 *
 *  DEVELOPMENT HISTORY:
 *
 *  Date        Name           Rev.   Description
 *  ----------  -------------  -----  -----------------------
 *  07-24-2013  S.L        		1.0      Initial Release
 *  
 *  
 *********************************************************************/ 
/*!
*    @file    FileUtils.c
*    @brief   File utility to process file functions
*    @author  Arxtron Technologies Inc.
*    @date    2013.10.01
*    File utility tools 
*/ 
#include "toolbox.h"
#include <ansi_c.h>
#include <userint.h>
#include "FileUtils.h"
#include "app_log.h"


/********************************************//**
*  Remove an existing file      
***********************************************/
int RemoveFile(const char *pFilename)
{
	int error;
	char msg[80];
	
	// remove old label file if exist
	if (FileExists(pFilename,0))
	{
		if (remove(pFilename) != 0)
		{
			error=-1;
			sprintf(msg,"Could not remove file %s",pFilename);
			add_log(msg);
		}
		else
		{
			error = 0;
		}
	}	
	else
	{
		error = 0;
	}
	
	return(error);
}  // end RemoveFile
