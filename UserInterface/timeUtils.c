/***********************************************************************
 *
 *
 *  COPYRIGHT: Arxtron Technologies Inc. All Rights Reserved.
 *
 *
 *  DEVELOPMENT HISTORY:
 *
 *  Date        Name           Rev.   Description
 *  ----------  -------------  -----  -----------------------
 *  05-15-2013  Arxtron        1      Initial Release
 *  
 *  
 *********************************************************************/ 
/*!
*    @file    timeUtils.c
*    @brief   Time and delay utilities
*    @author  Arxtron Technologies Inc.
*    @date    2013.9.6
*    Time and delay utilities  
*    
*/ 
#include <utility.h>
#include <ansi_c.h>
#include <userint.h>

/********************************************//**
* custom delay implmentation with processsystemevents, timeing is seconds
***********************************************/
void NonBlockDelay(float timeToWait)
{	  
	double  EndTime; 

    EndTime = Timer() + timeToWait ; 
	
	while (Timer() < EndTime)
	{
		ProcessSystemEvents();
	}
} // end NonBlockDelay
