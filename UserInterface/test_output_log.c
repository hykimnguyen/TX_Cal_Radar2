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
*    @file    test_output_log.c
*    @brief   Log test measurement outputs
*    @author  Arxtron Technologies Inc.
*    @date    2013.9.6
*    Functions to log test measurement outputs  
*    
*/ 
#include "Global.h"    
#include "toolbox.h"
#include <utility.h>
#include <userint.h>
#include <ansi_c.h>
#include <stdio.h>
#include <time.h>  
#include "test_output_log.h"
#include "DateTimeUtils.h"




/********************************************************
*
* FUNCTION NAME: get_test_output_log_filename
* 
* DESCRIPTION: Get filename of test output log
*
* ARGUMENT LIST: 
* 
* ARGUMENT           TYPE     I/O    DESCRIPTION       
* --------           ----     ---    -----------
* N/A
*
* RETURNS: 			 
*				
* 
* 
*********************************************************/
/********************************************//**
* Get test output log filename
***********************************************/
void get_test_output_log_filename(void)
{
	char dir[MAX_PATHNAME_LEN];
	GetProjectDir(dir);

	for(int i=0; i<NUMBER_OF_FILES; i++)
	{
		sprintf(testOutputFilename[i],"%s\\Log\\TestOutput_Nest%i",dir,i+1);
	}
} // end get_test_result_log_filename


/********************************************************
*
* FUNCTION NAME: add_header_to_test_output_log
* 
* DESCRIPTION: add header to test output log file
*
* ARGUMENT LIST: 
* 
* ARGUMENT           TYPE     I/O    DESCRIPTION       
* --------           ----     ---    -----------
* N/A
*
* RETURNS: 			 
*				
* 
* 
*********************************************************/
/********************************************//**
* Build and Add header to test output log
***********************************************/
int add_header_to_test_output_log(int dutNumber)
{
	char resHeader[1000];
	
	sprintf(resHeader,"TestDate,");
	strcat(resHeader,"Time,");
	//strcat(resHeader,"MIS,");
	//strcat(resHeader,"current,");
	//strcat(resHeader,"Celsius,");
	//strcat(resHeader,"SwVersion,");
	for (int i=0; i<NumOfTests; i++)
	{
		if (funcptr10[dutNumber][i] != NULL)
		{
			if(!strcmp(mtgTestStepInfo[dutNumber][i].testSkip, "N"))
			{
				if (strstr(mtgTestStepInfo[0][i].testFuncName,"ReadTemperature") != NULL) 
				{
					strcat(resHeader,"Temperature,");
					if(strstr(mtgTestStepInfo[0][i].testParam,"delta") != NULL)  
					{
						strcat(resHeader,"Delta,"); 	
					}
				}
				else if (strstr(mtgTestStepInfo[0][i].testFuncName,"Proceed_Request") != NULL) 
				{
					strcat(resHeader,"MIS,");
				}
				else if (strstr(mtgTestStepInfo[0][i].testFuncName,"WriteDUTData") != NULL) 
				{
					strcat(resHeader,"Point 1571,Point 1572,Point 1573,Point 1574,Point 1575,Point 1576,");
				}				
				else if (strstr(mtgTestStepInfo[0][i].testFuncName,"GetOccupiedBw") != NULL) 
				{
					if (strstr(mtgTestStepInfo[0][i].testParam,"RCTA") != NULL)   
						strcat(resHeader,"RCTA Occupied BW,");
					else if (strstr(mtgTestStepInfo[0][i].testParam,"BSD") != NULL)   
						strcat(resHeader,"BSD Occupied BW,");
					else   
						strcat(resHeader,"Occupied BW,");
					
				}
				else if (strstr(mtgTestStepInfo[0][i].testFuncName,"GetTxPower") != NULL) 
				{
					if (strstr(mtgTestStepInfo[0][i].testParam,"Antenna1") != NULL)   
						strcat(resHeader,"Antenna1 GetTxPower,");
					else if (strstr(mtgTestStepInfo[0][i].testParam,"Antenna2") != NULL)   
						strcat(resHeader,"Antenna2 GetTxPower,");
					else   
						strcat(resHeader,"GetTxPower,");
					
				}
				else if (strstr(mtgTestStepInfo[0][i].testFuncName,"GetCenterFrequency") != NULL) 
				{
					if (strstr(mtgTestStepInfo[0][i].testParam,"Antenna1") != NULL)   
						strcat(resHeader,"Antenna1 GetCenterFrequency,");
					else if (strstr(mtgTestStepInfo[0][i].testParam,"Antenna2") != NULL)   
						strcat(resHeader,"Antenna2 GetCenterFrequency,");
					else   
						strcat(resHeader,"GetCenterFrequency,");
					
				}
				else if (strstr(mtgTestStepInfo[0][i].testFuncName,"GetCwLeakage") != NULL) 
				{
					if (strstr(mtgTestStepInfo[0][i].testParam,"Antenna1") != NULL)   
						strcat(resHeader,"Antenna1 GetCwLeakage,");
					else if (strstr(mtgTestStepInfo[0][i].testParam,"Antenna2") != NULL)   
						strcat(resHeader,"Antenna2 GetCwLeakage,");
					else   
						strcat(resHeader,"GetCwLeakage,");
					
				}
				
				else if (strstr(mtgTestStepInfo[0][i].testFuncName,"SetHondaTxPowerCal") != NULL) 
				{
					strcat(resHeader,"InitDAC_amp, InitDAC_sw, Power, Point 1481,Point 1666,Point 1667,Point 1668,Point 1669,");					
				}
			
				else if (strstr(mtgTestStepInfo[0][i].testFuncName,"SetGMTxPowerCal") != NULL) 
				{
					strcat(resHeader,"Tx1 BSD,Tx1 RCTA,Tx2 BSD,Tx2 RCTA,Point 1481,Point 1482,Point 1666,Point 1667,Point 1668,Point 1669,Point 1792,Point 1883,Point 1884,Point 1885,Point 1886,Point 1887,Point 1888,");					
				}				
				
				else if (strstr(mtgTestStepInfo[0][i].testFuncName,"AnalogVoltMeas") != NULL) 
				{
					strcat(resHeader,"Current,");
				}
				
				else
				{
					// do nothing
				}   // end if
				
			}  // end if
		}  // end if
	} // end for loop
	
	add_data_to_test_output_log(dutNumber,resHeader);
	return(0);	
} // end add_header_to_test_output_log


/********************************************************
*
* FUNCTION NAME: add_header_to_test_output_log
* 
* DESCRIPTION: add header to test output log file
*
* ARGUMENT LIST: 
* 
* ARGUMENT           TYPE     I/O    DESCRIPTION       
* --------           ----     ---    -----------
* N/A
*
* RETURNS: 			 
*				
* 
* 
*********************************************************/
/********************************************//**
* add header to test output log file
***********************************************///kim
int add_data_to_test_output_log(int dutNumber, char *result)
{
	int error = 0;

	if (TestOutputIsLog)
	{
		CmtGetLock(WriteTestOutput_LockHandle);
		// open file
		LocalDateTime dt;
		int addHeaderToFile = 0;
		char fName[512]; 
		dt = GetLocalDateTime();
		-+sprintf(fName,"%s_%2i%02i%02i.csv",testOutputFilename[dutNumber],dt.year,dt.month,dt.day);
		if (FileExists(fName,0) == 0)
		{
			addHeaderToFile = 1;	
		}
	
		FILE *fp;
		fp = fopen(fName,"a");
		if (fp == NULL)
		{
			printf("Error: could not open file %s",fName);
			error = -1;
		}
		else
		{
			if (addHeaderToFile)
			{
				add_header_to_test_output_log(dutNumber);
			}
			fprintf(fp,"%s,",result);   
			fclose(fp);
		}
		CmtReleaseLock(WriteTestOutput_LockHandle);
	}

	return(error);
		
} // end add_data_to_test_output_log

/********************************************************
*
* FUNCTION NAME: add_datetime
* 
* DESCRIPTION: add datetime to test output log file
*
* ARGUMENT LIST: 
* 
* ARGUMENT           TYPE     I/O    DESCRIPTION       
* --------           ----     ---    -----------
* N/A
*
* RETURNS: 			 
*				
* 
* 
*********************************************************/
/********************************************//**
* add datetime to test output log file   
***********************************************/
void add_datetime_to_test_output_log(int dutNumber)
{
	LocalDateTime dt;
	dt = GetLocalDateTime();
	char msg[120];
	sprintf(msg,"\n%4i-%02i-%02i,%02i:%02i:%02i",dt.year,dt.month,dt.day,dt.hour,dt.minutes,dt.second);
	add_data_to_test_output_log(dutNumber,msg);
} // end add datetime_to_test_output_log

