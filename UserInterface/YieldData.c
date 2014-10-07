/*!
*    @file    YieldData.c
*    @brief   Long term and short term counters control functions
*    @author  Arxtron Technologies Inc.
*    @date    2013.9.6
*    Long term and short term counters control functions  
*    
*/ 
#include "Global.h"
#include "TextUtils.h"
#include "YieldData.h"

static int longTermFailCnt;
static int longTermPassCnt;
static char DateStampCleared[256];
static char yieldFileLocation[256];
static int numPass = 0;
static int numFail = 0;
static int cycleCount[NUMOFNESTS];
static char CycleCountFileLocation[256];

/********************************************//**
* Initialize long term counter
***********************************************/
int InitializeLongTermCount(void)
{
	char currentDir[512];
	char yield_return[256];
	
	GetProjectDir(currentDir);
	sprintf(yieldFileLocation, "%s%s", currentDir,"\\Configuration\\yield.csv");

	if (readYield(yieldFileLocation,yield_return))
	{
		sscanf(yield_return, "%d, %d, %[^\n]", &longTermPassCnt, &longTermFailCnt, DateStampCleared);
		LongTermYield(longTermFailCnt, longTermPassCnt, DateStampCleared,yieldFileLocation);
		return 0;
	}
	return 1;
}

/********************************************//**
* Initialize Cycle counter
***********************************************/
int InitializeCycleCount(void)
{
	char currentDir[512];
	char yield_return[256];
	char temp[256];
	
	GetProjectDir(currentDir);
	sprintf(CycleCountFileLocation, "%s\\Configuration\\CycleCount.csv", currentDir);

	if (readYield(CycleCountFileLocation,yield_return))
	{
		sscanf(yield_return, "%d,%d,%d,%d,%d,%d", &cycleCount[0],&cycleCount[1],&cycleCount[2],&cycleCount[3],&cycleCount[4],&cycleCount[5]);
			
		for (int i=0; i<totalNest; i++)
		{
			sprintf(temp,"%d",cycleCount[i]);
			DeleteTextBoxLines(MainPanelHandle, gCycleCount[i],0,-1);
			SetCtrlVal(MainPanelHandle, gCycleCount[i], temp);
		}
		return 0;
	}
	else
	{
		MessagePopup("Error","Unable to read CycleCount config file.");
		return 1; 
	}
	
} // end InitializeCycle Count



//**********************************************************************************************************************************************
//Function:		LongTermYield
//
//Description:	Calculate, display and log long term yield
//
//Parameters:   
//Inputs:     	None
//              
//Outputs     	None
//**********************************************************************************************************************************************
/********************************************//**
*Calculate long term yield
***********************************************/
void LongTermYield(int longTermFail, int longTermPass, char * DateCleared, char * FileLocation)
{
	int histoTotal = longTermFail+longTermPass; 
	double Percentage = 0.0;
	char tempMsg[100];

	if(histoTotal > 0)
	{
		Percentage = 100 * ((double)longTermPass / (double)histoTotal);
	}
	sprintf(tempMsg,"%d,%d,%s",longTermPass,longTermFail,DateCleared);
	writeYield(FileLocation,tempMsg);

	SetCtrlVal(MainPanelHandle, HISTO_TEST_PASS, longTermPass);
	SetCtrlVal(MainPanelHandle, HISTO_TEST_FAIL, longTermFail);
	SetCtrlVal(MainPanelHandle, HISTO_TEST_YIELD, Percentage);
	SetCtrlVal(MainPanelHandle, HISTO_CLEAR_DATE, DateCleared);			
}
//**********************************************************************************************************************************************
//Function:		ShortTermYield
//
//Description:	Calculate, display short term yield. Is initialized each time software is re-started
//
//Parameters:   
//Inputs:     	None
//              
//Outputs     	None
//**********************************************************************************************************************************************.
/********************************************//**
* Calculate and display short term yield
***********************************************/
void ShortTermYield(int shortTermFail, int shortTermPass)
{
	int histoTotal = shortTermFail+shortTermPass; 
	double Percentage = 0.0;
	//char tempMsg[100];
	
	if(histoTotal > 0)
	{
		Percentage = 100 * ((double)shortTermPass / (double)histoTotal);
	}

	SetCtrlVal(MainPanelHandle, MAIN_TEST_PASS, shortTermPass);
	SetCtrlVal(MainPanelHandle, MAIN_TEST_FAIL, shortTermFail);
	SetCtrlVal(MainPanelHandle, MAIN_TEST_YIELD, Percentage);
}

/********************************************//**
*Upade cycle count display
***********************************************/
void updateCycleCountDisplay(int nest)
{
	char tempMsg[100];						// TODO ID 19
	cycleCount[nest]++;
	CmtGetLock(YieldData_LockHandle);   
	sprintf(tempMsg,"%d,%d,%d,%d,%d,%d",cycleCount[0],cycleCount[1],cycleCount[2],cycleCount[3],cycleCount[4],cycleCount[5]);
	writeYield(CycleCountFileLocation,tempMsg);
	CmtReleaseLock(YieldData_LockHandle);
	sprintf(tempMsg,"%d",cycleCount[nest]);
	DeleteTextBoxLines(MainPanelHandle, gCycleCount[nest],0,-1);
	SetCtrlVal(MainPanelHandle, gCycleCount[nest], tempMsg);
} // updateCycleCountDisplay


/********************************************//**
* set long term yiled
***********************************************/
void SetHistoYield(int isPassStatus)
{
	CmtGetLock(YieldData_LockHandle);   
	if (isPassStatus)
	{
		numPass++;
		longTermPassCnt++;
	}
	else
	{
		numFail++;
		longTermFailCnt++;
	}

	ShortTermYield(numFail,numPass);
	LongTermYield(longTermFailCnt, longTermPassCnt, DateStampCleared,yieldFileLocation);
	CmtReleaseLock(YieldData_LockHandle);

}
/********************************************//**
* Clear short term counter
***********************************************/
void ClearShortTerm(void)
{
	CmtGetLock(YieldData_LockHandle);   
	numPass = 0;
	numFail = 0;
	ShortTermYield(numFail,numPass);
	CmtReleaseLock(YieldData_LockHandle);
}
/********************************************//**
*Clear long term counter
***********************************************/
void ClearLongTerm(void)
{
	CmtGetLock(YieldData_LockHandle);   
	longTermFailCnt = 0;
	longTermPassCnt = 0;
	sprintf(DateStampCleared, "Started on %s", DateStr());					
	LongTermYield(longTermFailCnt, longTermPassCnt, DateStampCleared,yieldFileLocation);
	CmtReleaseLock(YieldData_LockHandle);
}	
/********************************************************
*
* FUNCTION NAME: readYield
* 
* DESCRIPTION: read the long term yield (pass,fail) from a file  
*
*
* ARGUMENT LIST: 
* 
* ARGUMENT           TYPE     I/O    DESCRIPTION       
* --------           ----     ---    -----------
* fileLocation       char	   I	 yield.csv file location
* field_return 		 char	   O	 first line read from the file
* 
* 
* RETURNS: 1 for success, 0 for failure
* 
* 
*********************************************************/
/********************************************//**
*read the long term yield (pass,fail) from a file    
***********************************************/
int readYield(char * fileLocation,char * field_return)
{
	FILE * stream;

	if ((stream = fopen(fileLocation, "r")) == NULL)
	{
		return 0;
	}

	if (fgets(field_return, 254, stream) !=0)
	{
		fclose(stream);
		return 1;
	}
	else
	{
		fclose(stream);
		return 0;
	}
}
/********************************************************
*
* FUNCTION NAME: writeYield
* 
* DESCRIPTION: write the long term yield (pass,fail) to a file  
*
*
* ARGUMENT LIST: 
* 
* ARGUMENT           TYPE     I/O    DESCRIPTION       
* --------           ----     ---    -----------
* fileLocation       char	   I	 yield.csv file location
* msg 		         char	   I	 comma separated value of the pas and fail (i.e. pass,fail)
* 
* 
* RETURNS: 1 for success, 0 for failure
* 
* 
*********************************************************/
/********************************************//**
*write pass fail data to file  
***********************************************/
int writeYield(char * fileLocation,char * msg)
{
	FILE * stream;
	if ((stream = fopen(fileLocation, "w" )) != NULL)
	{
		fputs(msg, stream);
		fclose(stream);
		return 1;
	}
	else
	{
		fclose(stream);
		return 0;
	}
}
