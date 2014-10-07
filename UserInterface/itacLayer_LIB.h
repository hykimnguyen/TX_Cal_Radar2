#include "ewMII.h" 
#include "TestSteps.h"

APILONG __stdcall ewMII_init (char * errorString);
APILONG __stdcall ewMII_close (void);
APILONG __stdcall LogInSession(char ITACSystemID[100], char ITACStationID[100],char * errorString)  ;
APILONG __stdcall verifySerial(char* serialNumber, char * errorString)  ;
void __stdcall LogOutSession(void);
void __stdcall checkSession(void);
void __stdcall storeSession(void);
void __stdcall messageLog(char * msgIn);
APILONG __stdcall uploadResult(int startNest, int totalNest,int totalResult[100],int itacResult[100],char* SerialNumber, APISTRING errorString) ;
void __stdcall LogITCError(char errorString[]);
//APILONG __stdcall upResultDataAndRecipe(int totalResult[100],int itacResult[100],char * LogOnlyFailTests, char* SerialNumber,TestStepInfoStruct  (*TestStepInfo)[10][150],int nestNum, float testTime, int numTests, char * errorString);
APILONG __stdcall upResultDataAndRecipe(int totalResult[100],int itacResult[100], int store_type, char* SerialNumber,TestStepInfoStruct  (*TestStepInfo)[10][150],int nestNum, float testTime, int numTests, char * errorString);
APILONG __stdcall upItacDataAndRecipe(int totalResult[100],int itacResult[100], int store_type, char* SerialNumber,ItacTestStepStruct  (*ItacTestStep)[10][150],int nestNum, float testTime, int numTests, char * errorString);

int getProcessCount(void);
