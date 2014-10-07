/***********************************************************************
 *
 *
 *  COPYRIGHT: Arxtron Technologies Inc. All Rights Reserved.
 *
 *  PURPOSE: - Date time utilities functions
 *
 *  DEVELOPMENT HISTORY:
 *
 *  Date        Name           Rev.   Description
 *  ----------  -------------  -----  -----------------------
 *  08-06-2013  Arxtron    		1.0      Initial Release
 *  
 *  
 *********************************************************************/ 

#ifndef __DateTimeUtils_H__
#define __DateTimeUtils_H__

#ifdef __cplusplus
    extern "C" {
#endif


#include "cvidef.h"


typedef struct 
{
	unsigned int year;
	unsigned int month;
	unsigned int day;
	unsigned int hour;
	unsigned int minutes;
	unsigned int second;
	double millisecond;
	unsigned  int D;			// day of week
	unsigned int DDD;			// day of year
	unsigned int WW;			// week of year
	char WXX[4];				// week of year
	char Y[2];					// year
	char YY[3];    				// year
} LocalDateTime;


LocalDateTime GetLocalDateTime(void);
void GetDayOfYear(void);
void GetWeekOfYear(void);
void GetYear(void);
int IsLeapYear(unsigned int year);


	


#ifdef __cplusplus
    }
#endif

#endif  /* ndef __DateTimeUtils_H__ */
