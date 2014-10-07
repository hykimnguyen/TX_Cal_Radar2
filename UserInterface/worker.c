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
/*!
*    @file    worker.c
*    @brief   Function to perform the assign parallel task
*    @author  Arxtron Technologies Inc.
*    @date    2013.9.6
*    Functions to initialize and perform a single parallel task.
*
*/
#include <ansi_c.h>
#include "worker.h"
#include "Global.h"
#include "CANCommand.h"
#include "Measurements.h"
#include "TestConfiguration_Def.h"
#include "TestSteps.h"
#include "frmMain.h"
#include "DIO6515UtilsDef.h"
#include "timeUtils.h"
#include "MainDef.h"
#include "parallel_LIB.h"
#include "YieldData.h"
#include "itacLayer_LIB.h"
#include "DataLib.h"

static int fail_chute_lock=0; 
static int NestLock[3]={-1,-1,-1};  // nest is unlock

/********************************************************
*
* FUNCTION NAME: DoWork
*
*/
/********************************************//**
*Worker perform test sequence and update result
***********************************************/
/*
*
* ARGUMENT LIST:
*
* ARGUMENT           TYPE     I/O    DESCRIPTION
* --------           ----     ---    -----------
* dutNumber	 	   	 int
*
* RETURNS: 			 int
*					(0 = no error)
*
*
*
*********************************************************/
int DoWork(int dutNumber)
{
	int error = 0;
	double totalTestTime;
	double StartTime;
	
	if (WorkIsReady(dutNumber)) // start testing dut
	{
		
		strcpy (dutMIS[dutNumber].ITACvalid,"");
		// Initialize worker and perform work
		InitializeWorker(dutNumber);
		updateCycleCountDisplay(dutNumber);
		StartTime = Timer();
		DoTestSequence(dutNumber);

		totalTestTime = Timer() - StartTime;
		TestPassFailResult(dutNumber,NumOfTests);
		
		
		
		
		UnlockTestInstrument(dutNumber);  // Should be released in sequence, but
		UnlockOtherNest(dutNumber);	   // Release again in case we aborted

		

		
		DisconnectTXCal (dutNumber) ;  
		DisconnectCan (dutNumber) ;  
	//	DiscardHanles (dutNumber);



	// Write output result
		CmtGetLock(WriteToFile_LockHandle); 
	    WriteTestResultsToFile (totalResult[dutNumber], dutNumber, !(test_mode == CAPABILITY), totalTestTime);  
		CmtReleaseLock(WriteToFile_LockHandle); 




		// TODO test upload data to ITAC
		UploadToResultItac(dutNumber,totalTestTime);



		// tidy up and update GUI for new test
		SetHistoYield(totalResult[dutNumber]);
		SetCtrlVal(MainPanelHandle, gTestTime[dutNumber], totalTestTime);

		
		
		
		
		
		if (totalResult[dutNumber] == GLB_TRUE)
		{
			///// Test PASS operation /////
		    setDutIndicators (dutNumber, 1, 0, 0);   // set test pass
			setSelectValve(dutNumber,0);

			MsgBoxAttribute(dutNumber, "Remove Unit", 0x00E0E0E0, VAL_BLACK, 35);
			while(getDutPresence(dutNumber) && !ExitStatus)
				ProcessSystemEvents ();
		}
		else // Test FAIL
		{
			while(getFailChute() && !ExitStatus)
			{
				MsgBoxAttribute(dutNumber, "Fail Chute is Full.\nPlease Empty\nFail Chute", 0x00E0E0E0, VAL_BLACK, 35);
				ProcessSystemEvents ();
			}
				
			setDutIndicators (dutNumber, 0, 0, 1);   // set test fail
			MsgBoxAttribute(dutNumber, "Press Red button to release unit.", 0x00E0E0E0, VAL_BLACK, 35);
			while((!getDutRejectButton(dutNumber) || fail_chute_lock==1) && !ExitStatus)
				ProcessSystemEvents ();

			fail_chute_lock=1;
			setSelectValve(dutNumber,0);

			MsgBoxAttribute(dutNumber, "Remove Unit", 0x00E0E0E0, VAL_BLACK, 35); 
			while(getDutPresence(dutNumber) && !ExitStatus)
				ProcessSystemEvents ();

			MsgBoxAttribute(dutNumber, "Place Unit in Reject Bin", 0x00E0E0E0, VAL_RED, 35); 
			while(!getFailChute() && !ExitStatus)
				ProcessSystemEvents ();
			
			fail_chute_lock=0;
			SetCtrlAttribute (MainPanelHandle, gBoxTxt[dutNumber], ATTR_VISIBLE, 1);
		} // end if
		resetNest(dutNumber);
		NonBlockDelay(1);
		
		
	}
	else // work isn't ready
	{
		
			ProcessSystemEvents ();
			if ((GetNumberOfRunningBoard() == 0) && (dutNumber%2 == 1))
			{
				MsgBoxAttribute(dutNumber, "", 0x00E0E0E0, VAL_BLACK, 35); 
			}
			else
			{
				MsgBoxAttribute(dutNumber, "Place Unit\n to start testing", 0x00E0E0E0, VAL_BLACK, 35);
			}
			clearNestLed(dutNumber);
			
	}


	return(error);
} // end DoWork



/********************************************************
*
* FUNCTION NAME: DoTestSequence
*
*/
/********************************************//**
*Perform test sequence task
***********************************************/
/*
*
* ARGUMENT LIST:
*
* ARGUMENT           TYPE     I/O    DESCRIPTION
* --------           ----     ---    -----------
* dutNumber	 	   	 int
*
* RETURNS: 			 int
*					(0 = no error)
*
*
*
*********************************************************/
 int DoTestSequence(int dutNumber)
{
	bool status =0;
	int attempt = 0, repeat=1;
	double StartTime;
	char testTime[50];
	char txtMsg[100];
	char FamilyToBeTested[256]={0};
	BoardRunning[dutNumber]=1;   
	strcpy(FamilyToBeTested,GetCfgMiscValue("ProgramTested",80));
	//reset "Test Measurements" text message
	sprintf(txtMsg, "Test Measurements                                             Low Limit    High Limit");
	SetCtrlVal(MainPanelHandle, gReportLabel[dutNumber], txtMsg);

	for(int i=0; funcptr10[dutNumber][i] != NULL; i++)
	{
		//T6AA
		if  ((strcmp(selRecipe.PartNum,FamilyToBeTested)!=0 )&& 
				(!strcmp(mtgTestStepInfo[dutNumber][i].testFuncName,"WritePointCsvValue") || !strcmp(mtgTestStepInfo[dutNumber][i].testFuncName,"ReadPointCSV") ))
		{
				if (strstr(mtgTestStepInfo[dutNumber][i].testParam,"Tx_H_CAL_20") !=NULL)
					strcpy(mtgTestStepInfo[dutNumber][i].testSkip,"Y");		
		}
		
		if(!strcmp(mtgTestStepInfo[dutNumber][i].testSkip, "N"))
		{
			StartTime=Timer();
	
			status=funcptr10[dutNumber][i](i+1, dutNumber);  // 0 == pass
	
			sprintf(testTime, "%4.1f", Timer() - StartTime);
			DisplayPassFailResult(!status, i+1, testTime, GLB_FALSE, i, dutNumber+1, repeat);
		
			ProcessSystemEvents();
			
			if(status == 0 || !strcmp(mtgTestStepInfo[dutNumber][i].testType,"R"))  // check if test passed or it is just a report
				strcpy(mtgTestStepInfo[dutNumber][i].testResult,"Pass");
			else
				strcpy(mtgTestStepInfo[dutNumber][i].testResult,"Fail");
				

			// Deterrmine if Test Passed or Fail and Check if Continue on Fail or Stop on Fail
			if(EStopIsEnable[dutNumber])
			{
				CmtGetLock(ESTOP_LockHandle);  
				setDutIndicators (dutNumber, 0, 0, 1);  
				BoardRunning[dutNumber] =0; 
				EStopIsEnable[dutNumber] = GLB_FALSE; 
				CmtReleaseLock(ESTOP_LockHandle);
				totalResult[dutNumber] = GLB_FALSE;
				strcpy(mtgTestStepInfo[dutNumber][i].testResult, "Fail");
				strcpy(mtgTestStepInfo[dutNumber][i].testResultVal, "ESTOP Pressed");
				return 0;
			}
		//Air Pressure Sensor
			if(VacFault[dutNumber])
			{
				CmtGetLock(VacSensor_LockHandle);  
				BoardRunning[dutNumber] =0; 
				VacFault[dutNumber] = GLB_FALSE; 
				CmtReleaseLock(VacSensor_LockHandle);
				totalResult[dutNumber] = GLB_FALSE;
				strcpy(mtgTestStepInfo[dutNumber][i].testResult, "Fail");
				strcpy(mtgTestStepInfo[dutNumber][i].testResultVal, "Vacuum Fault Occured");
				return 0;
			}   
			if(AirIsDisabled[dutNumber])
			{
				CmtGetLock(VacSensor_LockHandle);  
				BoardRunning[dutNumber] =0; 
				AirIsDisabled[dutNumber] = GLB_FALSE; 
				CmtReleaseLock(VacSensor_LockHandle);
				totalResult[dutNumber] = GLB_FALSE;
				strcpy(mtgTestStepInfo[dutNumber][i].testResult, "Fail");
				strcpy(mtgTestStepInfo[dutNumber][i].testResultVal, "Fixture not locked");
				return 0;
			} 
			
			//end			
		}
		else if(!strcmp(mtgTestStepInfo[dutNumber][i].testSkip, "Y"))
		{
			strcpy(mtgTestStepInfo[dutNumber][i].testResult,"Skip"); 			
		}
		

		if( (!strcmp(mtgTestStepInfo[dutNumber][i].testResult, "Fail")) && (!strcmp(mtgTestStepInfo[dutNumber][i].testAbort, "Y")) )
		{
			totalResult[dutNumber] = GLB_FALSE;
			break;
		}
	}  // end for loop
	BoardRunning[dutNumber]=0;   
	return status;
} // end DoTestSequence

/********************************************************
*
* FUNCTION NAME: InitializeWorker
*
*/
/********************************************//**
*Initialize worker
***********************************************/
/*
*
* ARGUMENT LIST:
*
* ARGUMENT           TYPE     I/O    DESCRIPTION
* --------           ----     ---    -----------
* dutNumber	 	   	 int
*
* RETURNS: 			 int
*					(0 = no error)
*
*
*
*********************************************************/
void InitializeWorker(int dutNumber)
{
	int i = dutNumber;

	setDutIndicators (dutNumber, 0, 1, 0);

	setDutPower(dutNumber,0);
	setSelectValve(dutNumber,1);

	totalResult[i] = GLB_TRUE;
	itacResult[i]=0;
	
	for(int j=0; j<testARRAY_SIZE; j++)
	{
		strcpy(mtgTestStepInfo[i][j].testResult     		 , "");
		strcpy(mtgTestStepInfo[i][j].testResultVal		     , "");
	}

	ClearListCtrl(MainPanelHandle, gStepList[dutNumber]);
	ClearListCtrl(MainPanelHandle, gReportList[dutNumber]);
	SetCtrlVal(MainPanelHandle, gTestTime[dutNumber], 0.0);

	MsgBoxAttribute(dutNumber, "", 0x00E0E0E0, VAL_BLACK, 35);

	// Lock other pair nest so to delay unit from heating up before test
	while(NestIsLocked(dutNumber))
		NonBlockDelay(0.1);
	
	resetItacTestStep(dutNumber);
	LockOtherNest(dutNumber);
} // end InitializeWorker


/********************************************************
*
* FUNCTION NAME: GetDutNumber
*
* DESCRIPTION: Get the test dut number from test instrument number
*
* ARGUMENT LIST:
*
* ARGUMENT           TYPE     I/O    DESCRIPTION
* --------           ----     ---    -----------
* testInstrument   	 int
*
* RETURNS: 			 dutNumber
*
*
*
*********************************************************/
/********************************************//**
* Get the test dut number from test instrument number
***********************************************/
int GetDutNumber(int testInstrument)
{
	/////////////////////////////////////////////
	// TestInstrument	TestUnitA		TestUnitB
	// 	0				0				1
	//  1				2				3
	//  2				4				5
	/////////////////////////////////////////////
	int dutNumber;
	int testUnitA=2*testInstrument;
	int testUnitB=2*testInstrument+1;
	if (getDutPresence(testUnitA) && getDutPosition(testUnitA))
	{
		dutNumber = testUnitA;
	}
	else if (getDutPresence(testUnitB) && getDutPosition(testUnitB))
	{
		dutNumber = testUnitB;
	}
	else
	{
		dutNumber = -1;
	}
	return(dutNumber);
} // end GetDutNumber

/********************************************//**
* Check if worker is ready for work
***********************************************/
int WorkIsReady(int dutNumber)
{
	if (getDutPresence(dutNumber) && getDutPosition(dutNumber) && !MainTestingIsPause) // start testing dut    
	{
		return(TRUE);
	}
	else
	{
		return(FALSE);
	}
} // end WorkIsReady

/********************************************//**
* UploadToResultItac
***********************************************/
void UploadToResultItac(int dutNumber, double totalTestTime)
{
	if ((ITACIsEnable &&  ExitStatus == GLB_FALSE) && (stricmp (dutMIS[dutNumber].ITACvalid,"") != 0))
	{
		int error, status;
		char errorString[1000];
		char tmpMsg[200];
		char tempMsg[200];
		CmtGetLock(ITAC_LockHandle);
		char serialNumber[100];
		strcpy(serialNumber,dutMIS[dutNumber].SerialNumber);
		int ITAC_StoreType = atoi(GetCfgMiscValue("LogOnlyFailTests",80));
		
		//DUMMY TEST SERIAL NUMBER
		//strcpy(serialNumber,"151160004863");


		error = upItacDataAndRecipe(totalResult,itacResult,ITAC_StoreType, serialNumber,&mtgItacTestStep,dutNumber, totalTestTime,ITS_Idx[dutNumber],errorString); 
		
		if(error<0)
		{
			sprintf(tmpMsg,"Upload results to Itac failed with error code %d\n Press Yes to to retry again\n Press No to exit software",error);
			while(1)
			{
				if(!ConfirmPopup ("ITAC Failed", tmpMsg))
					break;
				LogOutSession();
				ewMII_close ();
				if((status=ewMII_init(errorString))<0)
				{
					sprintf(tempMsg,"ewMII_init status:%d ",status);
					MessagePopup("Error",tempMsg);
					continue;
				}
				checkSession();
				if((status = LogInSession(GetCfgMiscValue("ITACSystemID",80),GetCfgMiscValue("ITACStationID",80),errorString))<0)
				{
					sprintf(tempMsg,"LogInSession status:%d",status);
					MessagePopup("Error",tempMsg);
					continue;
				}
				
				// upload result to ITAC using new ItacTestStep data structure
				if(	(status = upItacDataAndRecipe(totalResult,itacResult,ITAC_StoreType, serialNumber,&mtgItacTestStep,dutNumber, totalTestTime,ITS_Idx[dutNumber],errorString)))  
				{
					sprintf(tempMsg,"upItacDataAndRecipe status:%d",status);
					MessagePopup("Error",tempMsg);
					continue;
				}
				else
				{
					break;
				}
			} // end while
			if(status<0)
			{
				FILE *fp;
				char* timeStamp;
				if(VerifyOpenFileWrite(SystemFileName, "a", &fp))
				{
					timeStamp = TimeStr();
					fprintf(fp,"%s: Unable Load results to Itac Function:%s Returned:%d \n", timeStamp,"uploadResultDataAndRecipe",error);
			    	if (fclose(fp) != 0)
			    	{
						///MessagePopup ("FILE ERROR: Unable to close file \n", res_file);
			      		///return;
			    	}
				}
				else
					fclose(fp);
				ExitStatus = GLB_TRUE;
			}
		}
		CmtReleaseLock(ITAC_LockHandle);
	}


} // end UploadToResultItac


/********************************************//**
*Performed lock on other nest pair to delay unit heating up
***********************************************/
void LockOtherNest(int dutNumber)
{
	NestLock[dutNumber/2]=dutNumber;
} // end LockOtherNest

/********************************************//**
*Unlock other nest pair
***********************************************/
void UnlockOtherNest(int dutNumber)
{
	if(NestLock[dutNumber/2] == (dutNumber) )
		NestLock[dutNumber/2]=-1;
} // end UnlockOtherNest

/********************************************//**
* Get nest lock status
***********************************************/
int NestIsLocked(int dutNumber)
{
	return(NestLock[dutNumber/2] != -1);
} // end NestIsLocked
