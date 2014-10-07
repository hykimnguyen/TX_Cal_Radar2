/***********************************************************************
 *
 *
 *  COPYRIGHT: Arxtron Technologies Inc. All Rights Reserved.
 *
 *  PURPOSE: ITAC function calls
 *
 *  DEVELOPMENT HISTORY:
 *
 *  Date        Name           Rev.   Description
 *  ----------  -------------  -----  -----------------------
 *  05-15-2013  Arxtron        1      Initial Release
 *
 *
 *********************************************************************/

 /* Include global parameters */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "Global.h"
#include "DataLib.h"
#include <formatio.h>
#include "ewMII.h" //ITAC API
#include "itacLayer_LIB.h"

static char sITACStationId[100];  // ITAC station ID
static long sessionID;  		  // ITAC session handle
static long ProcessCount=0;  	  // Count from ITAC of # times DUT was tested 
static long itacUploadResult[10]; // last result of uploadstate
 
void __stdcall LogITCError(char errorString[])
{
	/*FILE *fp;
	char* timeStamp;

	if(VerifyOpenFileWrite(FlashProgrammingFileName, "a", &fp))
	{
		timeStamp = TimeStr();

		fprintf(fp,"%s: %s \n", timeStamp, errorString);

    	if (fclose(fp) != 0)
    	{
			///MessagePopup ("FILE ERROR: Unable to close file \n", res_file);
      		///return;
    	}
	}  */

}
/********************************************************************
	Module: ewMII_init
	Description: start the ITAC API server
    Input: ewMII.options file
	Input/Output:
		out -> result	   (0 = pass, other = fail)
		out -> errorString

*********************************************************************/
APILONG __stdcall ewMII_init (char * errorString)
{
	APILONG result;
	int loop_count = 0;
	char dir[MAX_PATHNAME_LEN], tempDir[100], tempStr[100];

	GetProjectDir(dir);
	CopyString(tempDir, 0, dir, 0, 3);
	sprintf(tempStr, "%s%s", tempDir, "ewMII\\ewMII.options");
	do
	{
    	//result=apiInit(tempStr,&errorString);
		result=apiInit(NULL,&errorString);
		//"C:/ewMII/ewMII.options"
		loop_count++;
	}while((result != 0) && (loop_count<2));

	if (result != 0)
	{
		messageLog(errorString);
		LogITCError(errorString);
	}
    return result;


}
/********************************************************************
	Module: ewMII_close
	Description: shutdown the ITAC API server
    Input: ewMII.options file
	Input/Output:
		Out -> result (always pass).
		Out -> errorString

*********************************************************************/
APILONG __stdcall ewMII_close (void)
{
	APISTRING errorString;
	APILONG result;

	result = apiShutdown(&errorString);
	return result;
}

/********************************************************************
	Module: LogInSession
	Description: log into ITAC server and return session id
	Input/Output:
	    In  ->  station id
		In  ->  system ID
		Out ->  session id
		Out ->  error message
*********************************************************************/
APILONG __stdcall LogInSession(char ITACSystemID[100], char ITACStationID[100],char * errorString)
{
	struct ApiSessionValidationStruct sessValData;

	sessValData.user = ITACStationID;
	sessValData.password = "";
	sessValData.client = "01";
	sessValData.isVip = 1;
	sessValData.isStation = 1;
    sessValData.systemIdentifier =ITACSystemID;
	sprintf(sITACStationId,"%s",ITACStationID);

	for(int loop_count = 0; (sessionID <=0) && (loop_count<3); loop_count++)
	{
		sessionID = apiLogin(&sessValData, &errorString);
	}


	if (sessionID>0)
	{
		storeSession();
	}
	else
	{
		messageLog(errorString);
		LogITCError(errorString);
	}
	apiFreeBuffers();

	return sessionID;
}
/********************************************************************
	Module: verifySerial
	Description: check board id against ITAC server using
	             ITAC API call checkSnrStateBySnrRef
	Input/Output:
	    In ->  station id
		In ->  session id
		In ->  serial number
		Out ->  board status array
		Out ->  API call status
		Out ->  error message
*********************************************************************/
APILONG __stdcall verifySerial(char* serialNumber, char *errorString)
{
	APILONG result;
	APILONG processLayer=2;	  /// Position Independent
	APISTRING tmpErrorString;

	ProcessCount = 0;  
  
	//strcpy(serialNumber,"151160004863");  //DUMMY SERIAL NUMBER
	result = checkSerialNumberState(sessionID, sITACStationId, processLayer, serialNumber, "-1", &ProcessCount, &tmpErrorString);
	sprintf(errorString,"Error=%d:%s",result,tmpErrorString);

	apiFreeBuffers();
	return result;
}
/********************************************************************
	Module: getProcessCount
	Description: Get # of times a UUT has been tested
	Input/Output:
*********************************************************************/
int getProcessCount(void)
{
	return 	ProcessCount;
}

/********************************************************************
	Module: LogOutSession
	Description: log out from ITAC server
	Input/Output:
		In -> session id
*********************************************************************/
void __stdcall LogOutSession(void)
{
	APISTRING errorString;
	remove ("session.tmp");
	/* logout, no output */
	apiLogout(sessionID, &errorString);

	apiFreeBuffers();
}

/********************************************************************
	Module: checkSession
	Description: look for unclosed ITAC session and return session id
	Input/Output:
		In -> session id (-1 if there's no session pending)
*********************************************************************/
void __stdcall checkSession(void)
{
	FILE *stream;
	ssize_t fileSize =999999;

	if ((stream = (FILE *)fopen("session.tmp", "r" )) != NULL)
	{
		char msg[1000] = "-1";
		APISTRING errorString;
		
		fgets(msg, 254, stream);
		fclose(stream);
		remove("session.tmp");
		sessionID = atol(msg);
		apiLogout(sessionID, &errorString);
	}

	apiFreeBuffers();
}

/********************************************************************
	Module: storeSession
	Arxtron Tecnologies
	Description: store ITAC session ID in a temp file
	Input/Output:
		In -> session id
*********************************************************************/
void __stdcall storeSession(void)
{
	FILE * out;

	remove("session.tmp");

	if ((out = fopen((char *)"session.tmp", "w" )) != NULL)
	{
		fprintf(out, "%ld", sessionID);
		fclose(out);
	}
}

/********************************************************************
	Module: messageLog
	Description: store ITAC session ID in a temp file
	Input/Output:
		msg -> failure message to be logged to itacuci.log
*********************************************************************/
void __stdcall messageLog(char * msgIn)
{
	FILE * out;
	time_t timer;
	struct tm *tblock;
	
	timer = time(NULL);
	tblock = localtime(&timer);
	
	if ((out = fopen((char *)"c:\\ewMII\\itacuci.log", "a" )) != NULL)
	{
		fprintf(out, "%s->%s", asctime(tblock), msgIn);
		fclose(out);
	}
}


/********************************************************************
	Module: uploadResult
	Customer Service Associates Canada
	Description: send board status to ITAC server using
	             ITAC API call uploadState
	Revision, date and by:
    Rev 1.0: 11/07/08 by Hy-Kim Nguyen (CSA)
	Input/Output:
	    ph 1 -> pointer to station id
		ph 2 -> pointer to session id
		ph 3 -> pointer to serial number
		ph 4 -> pointer to board position
		ph 5 -> pointer to board status
		ph 6 -> pointer to API call status
		ph 7 -> pointer to error message
*********************************************************************/
APILONG __stdcall uploadResult(int startNest, int totalNest,int totalResult[100],int itacResult[100],char* SerialNumber, APISTRING errorString)
{
	APILONG result = -999;
	APILONG processLayer = 2;
	APILONG serialNumberState;
	APILONG duplicateSerialNumber = 0;
	APILONG checkActiveWorkOrder = 0;
	APISTRING serialNumberRefPos; 

	for (int i = startNest; i<totalNest+startNest; i++)
	{
		serialNumberState = !totalResult[i]; // serialNumberState = 0 = pass

		if (itacResult[i] == 0)
		{
			sprintf(serialNumberRefPos,"%d", i+1);
			//sprintf(serialNumberRef, "%s%s%s", ManufacturingData.FlavorID, ManufacturingData.SerialNumber,serialNumberRefPos);

			// result 0 = pass, result 4 = scrap - either is acceptable.
			for(int loop_count = 0; (result != 0) && (result != 4) && (loop_count<2); loop_count++)
			{
				result = uploadState(sessionID, sITACStationId, processLayer, SerialNumber, serialNumberRefPos , serialNumberState, duplicateSerialNumber, checkActiveWorkOrder, &errorString);
				itacUploadResult[i] = result;
			}

			if  ( (result != 0) && (result != 4))
			{
				/*if(VerifyOpenFileWrite(FlashProgrammingFileName, "a", &fp))
				{
					fprintf(fp,"%s: ITAC STATUS: %s: %d Error Code %d %s \n", TimeStr(), "Board #", ii+1 , result, errorString);
					fclose(fp);
				}	   */
			}
		}
	}
	apiFreeBuffers();
	return result;
}

/******************************************************************************************/
/*                                                                                        */
/* upResultDataAndRecipe                                       		                  */
/*                                                                                        */
/* upload test result data and recipe to itac                       					  */
/*                                                                                        */
/* parameters:                                                                            */
/* in     APILONG                               sessionId                                 */
/* in     APISTRING                             stationNr                                 */
/* in     APILONG                               processLayer                              */
/* in     APISTRING                             serialNumberRef                           */
/* in     APISTRING                             serialNumberRefPos                        */
/* in     APILONG                               serialNumberState                         */
/* in     APISTRING                             produktNo                                 */
/* in     APISTRING                             produktRev                                */
/* in     APILONG                               bookDate                                  */
/* in     APIFLOAT                              cycleTime                                 */
/* in     APILONG                               resultDataExtArraySize                    */
/* in     struct ResultDataExtendedStruct*      resultDataExtArray                        */
/* out    APISTRING*                            errorString                               */
/* out    APILONG                            	result	 	                              */
/*                                                                                        */
/* in     int 									store_type								  */

/*  //////////////////////////////////////////////////////////////////////////////
    store_type input setting
	0) Store only a pass/fail flag (use upload result)
	1) Store only fail data
	2) Store all data up to & including first failure
	3) Store all pass data if passed or all fail data if failed
	4) Store all data
*/
/******************************************************************************************/
APILONG __stdcall upResultDataAndRecipe(int totalResult[100],int itacResult[100], int store_type, char* SerialNumber,TestStepInfoStruct  (*TestStepInfo)[10][150],int nestNum, float testTime, int numTests, char * errorString)
{
	APILONG result=0;
	APILONG processLayer = 2;  // position independent
	APILONG serialNumberState;
	APILONG bookDate = -1;  //curent date and current time
	APILONG duplicateSerialNumber = 0;
	APILONG checkActiveWorkOrder = 0;
	char serialNumberRefPos[10]={0};
	char productNo[100]={0};
	char productRev[100]={0};
	char testName[numTests][200];  
	int resultDataExtArraySize=0;
	struct ResultDataExtendedStruct* resultDataExtArray;
	
	memset(testName, 0, 200*numTests*sizeof(char));
	
	if (itacResult[nestNum] == 0)  //unit is valid for this station
	{
		serialNumberState = !totalResult[nestNum]; // serialNumberState = 0 = pass
		sprintf(serialNumberRefPos,"%c",SerialNumber[11]);	

		if(store_type == 0)
		{
			result = uploadState(sessionID, sITACStationId, processLayer, SerialNumber, serialNumberRefPos , serialNumberState, duplicateSerialNumber, checkActiveWorkOrder, &errorString);
		}
		else
		{
			resultDataExtArray = (struct ResultDataExtendedStruct*)malloc(numTests* sizeof(struct ResultDataExtendedStruct));
				
			for (int testIndex = 0, i=0; i<numTests; i++)
			{  // store type: 0-only state, 1- only fail data 2-all data up to and including first fail, 4 - all if pass, fail only if fail, 5 all data 
				if( ((*TestStepInfo)[nestNum][i].testResult[0] == 0) || // Don't store blank results (don't know how this would happen) 
					((*TestStepInfo)[nestNum][i].testSkip[0] == 'Y') ||	// Don't store skipped tests
					((*TestStepInfo)[nestNum][i].testType[0] == 'R') ||	// Dont store "report" type tests
					((*TestStepInfo)[nestNum][i].testResult[0] == 'P' && store_type == 1) || // Dont store passes if store_type == 1 (fail only)
					(serialNumberState && (*TestStepInfo)[nestNum][i].testResult[0] == 'P' && store_type == 3) )// store_type 3 == all if pass, fail only if fail	
						continue;	
			
				resultDataExtArray[testIndex].nr = i+1;
				sprintf(testName[i],"T%d_%s",i+1,(*TestStepInfo)[nestNum][i].testName);
				resultDataExtArray[testIndex].name = testName[i];
				resultDataExtArray[testIndex].value = (*TestStepInfo)[nestNum][i].testResultVal;
				resultDataExtArray[testIndex].min = "";//TestStepInfo[nestNum][i].testLowLimit;
				resultDataExtArray[testIndex].max = "";//TestStepInfo[nestNum][i].testHighLimit;
				resultDataExtArray[testIndex].nom = "";
				resultDataExtArray[testIndex].toleranz = "";
				resultDataExtArray[testIndex].unit = "";//TestStepInfo[nestNum][i].testUnit;
				resultDataExtArray[testIndex].failCode = (strcmp((*TestStepInfo)[nestNum][i].testResult, "Pass") != 0); // 0 PASS, 1 FAIL
				resultDataExtArray[testIndex].messtyp = "0";
				testIndex++;
		
				if(store_type == 2 && (*TestStepInfo)[nestNum][i].testResult[0] != 'P')
					break;
			}
			result = uploadResultDataAndRecipe(sessionID, sITACStationId, processLayer, SerialNumber, serialNumberRefPos, serialNumberState, productNo, productRev, bookDate, testTime, resultDataExtArraySize, resultDataExtArray, &errorString);
			free(resultDataExtArray);
		}
	}
 
	/* free memory, that was allocated by dll  */
	apiFreeBuffers();
	return(result);
}
