/***********************************************************************
 *
 *
 *  COPYRIGHT: Arxtron Technologies Inc. All Rights Reserved.
 *
 *  PURPOSE: - Application to log execution event.
 *
 *  DEVELOPMENT HISTORY:
 *
 *  Date        Name           Rev.   Description
 *  ----------  -------------  -----  -----------------------
 *  07-24-2013  Arxtron    		1.0      Initial Release
 *  
 *  
 *********************************************************************/ 
/*!
*    @file    app_log.c
*    @brief   Application to log execution event
*    @author  Arxtron Technologies Inc.
*    @date    2013.9.6
*    Functions used to log errors and debug message during development  
*    
*/ 
#include <userint.h>
#include <ansi_c.h>
#include <stdio.h>
#include <time.h>  
#include "app_log.h"
#include "DateTimeUtils.h"


static char *pLogFilename = "C:\\tmp\\Log\\app_log";
static char *pLogErrorFile = "C:\\tmp\\Log\\\\Error\\app_err.txt"; 


/********************************************//**
 *  Add message to log file  
 ***********************************************/
int add_log(char *msg)
{
	return(add_to_file(pLogFilename,msg));
} // end add_log


/********************************************//**
 *  Add message to error log file     
 ***********************************************/
int add_error(char *msg)
{
	return(add_to_file(pLogErrorFile,msg)); 	
} // end add_error


/********************************************//**
 *  Add message to log and error file       
 ***********************************************/
int add_log_error(char *msg)
{
	int logRet = add_log(msg);
	int errRet = add_error(msg);
	return(logRet+errRet);
} // end add_log_error


/********************************************//**
 *  Write message to filename      
 ***********************************************/
int add_to_file(char *pFilename, char *msg)
{
	int error = 0;
    if (ApplicationExecutionIsLog)
	{
		// open file
		LocalDateTime dt;
		char oFilename[120]; 
		dt = GetLocalDateTime();
		sprintf(oFilename,"%s_%4i%02i%02i.txt",pFilename,dt.year,dt.month,dt.day);
	
		FILE *fp;
		fp = fopen(oFilename,"a");
		if (fp == NULL)
		{
			printf("Error: could not open file %s",oFilename);
			error = 1;
		}
		else
		{
			fprintf(fp,"%s - %s\n",get_time(),msg);   
			fclose(fp);
		}
	}
	return(error);
} // end add_to_file

/********************************************//**
 *  Get current time   
 ***********************************************/
char* get_time(void)
{
	time_t t;
	time(&t);	// get current time
	char *pTime = ctime(&t);
	pTime[(strlen(pTime)-1)] = '\0';	// remove the new line char
	return(pTime);

} // end get_time


/********************************************//**
 *  Decode error and add message to log and error file.    
 ***********************************************/
void decode_error(int error, char *func, char *desc)
{
	char msg[256]; 
	sprintf(msg,"Error=%i, %s, %s",error,func, desc);
	add_log_error(msg);	
} // end decode_error


/********************************************//**
 *  Check error and add message to log and error file.     
 ***********************************************/
void check_error(int error, char *func, char *desc)
{
	if (error == 0)
	{
		add_log(func);
	}
	else
	{
		decode_error(error,func,desc);	
	}
} // end check_error


