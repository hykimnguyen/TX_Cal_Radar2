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
/*!
*    @file    DateTimeUtils.c
*    @brief   Date time utilities functions.
*    @author  Arxtron Technologies Inc.
*    @date    2013.9.6
*    Date time utilities functions. Function to obtain the Date in different formats. 
*/ 
#include <ansi_c.h>
#include <utility.h>
#include "DateTimeUtils.h"

#define TRUE	1
#define FALSE	0


LocalDateTime dt; 


/********************************************//**
*  return the date properly formated to be used to generate CSN number             
***********************************************/
LocalDateTime GetLocalDateTime(void)
{
	CVIAbsoluteTime absoluteTime;
	int error=0;
	
	dt.year = 2000;
	dt.month = 1;
	dt.day = 1;
	dt.hour = 0;
	dt.minutes = 0;
	dt.second = 0;
	dt.millisecond = 0;
	dt.D = 0;
	dt.DDD = 0;
	dt.WW = 0;
	strcpy(dt.WXX,"W00");
	strcpy(dt.Y,"0");   	
	strcpy(dt.YY,"00");
	
	error |= GetCurrentCVIAbsoluteTime(&absoluteTime);
	error |= CVIAbsoluteTimeToLocalCalendar(absoluteTime,&dt.year,&dt.month,&dt.day,
		&dt.hour,&dt.minutes,&dt.second,&dt.millisecond,&dt.D);
	
	GetDayOfYear();
	GetWeekOfYear();
	GetYear();
	
	return(dt);
} // end GetLocalDateTime


/********************************************//**
*  from current date to day in the year           
***********************************************/
void GetDayOfYear(void)
{
	unsigned int numDays=0;
	unsigned int months = dt.month-1;
	for(unsigned int i=months;i>0;i--)
	{
		switch(i)
		{
			case 11:
				numDays += 30;
				break;
			case 10:
				numDays += 31;
				break;
			case 9:
				numDays += 30;
				break;
			case 8:
				numDays += 31;
				break;
			case 7:
				numDays += 31;
				break;
			case 6:
				numDays += 30;
				break;
			case 5:
				numDays += 31;
				break;
			case 4:
				numDays += 30;
				break;
			case 3:
				numDays += 31;
				break;
			case 2:
				numDays += 28;
				break;
			case 1:
				numDays += 31;
				break;
			default:
				break;
		} // end switch
	} // end for loop
	
	numDays += dt.day;
	
	if (IsLeapYear(dt.year))
	{
		numDays += 1;
	}
	dt.DDD = numDays;
}  // end GetDayOfYear


/********************************************//**
*  from current date to week in the year           
***********************************************/
void GetWeekOfYear(void)
{
	int numWeeks;
	numWeeks = floor(dt.DDD/7);
	sprintf(dt.WXX,"W%2i",numWeeks);
	dt.WW=numWeeks;
} // end GetWeekOfYear

/********************************************//**
*  current year in differetn format         
***********************************************/
void GetYear(void)
{
	char yyyy[5];
	sprintf(yyyy,"%i",dt.year);
	dt.Y[0]=yyyy[3];
	dt.YY[0]=yyyy[2];
	dt.YY[1]=yyyy[3];
} // end GetYear

/********************************************//**
*  determine if its a leap year           
***********************************************/
int IsLeapYear(unsigned int year)
{
	 if(((year%4==0)&&(year%100!=0))||(year%400==0))
	 {
         return(TRUE);
	 }
    else
	{
         return(FALSE);
	}
} // end IsLeapYear
