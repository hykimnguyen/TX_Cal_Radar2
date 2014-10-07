/***********************************************************************
 *
 *
 *  COPYRIGHT: Arxtron Technologies Inc. All Rights Reserved.
 *
 *  PURPOSE:  
 *            
 *            
 *            
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
*    @file    TestConfiguration.c
*    @brief   Functions for test result and test configuration.
*    @author  Arxtron Technologies Inc.
*    @date    2013.9.6
*    Functions for test results and configuration of the test function with sequencer.
*/ 


#include <cvirte.h>		
#include <userint.h>
#include "Global.h"   
#include "DataLib.h" 
#include "Measurements.h"
#include "TestConfiguration.h"
#include "TestConfiguration_Def.h"
#include "frmMain.h"  
#include "MainDef.h"
#include "TextUtils.h"
#include "TestSteps.h"
#include "DIO6515UtilsDef.h"
#include "MIOUtils.h"
#include "MIOUtilsDef.h" 
#include "CANCommand.h"



int testIndex, testNumber;
int testNest;
static char			logTestResults[NUMOFNESTS][2000];

//********************************************************************************************************************

int CVICALLBACK TestCfgTabCB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	return 0;
}
//********************************************************************************************************************
int CVICALLBACK TSTCFGExitCB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			//	#if USE_EXT_MAIN_PROJ
					CheckError(HidePanel(TestCfgPanelHandle)); 
			//	#else		
			//	QuitUserInterface (0);
			//	#endif
			break;
	}
	return 0;
}
//********************************************************************************************************************
int CVICALLBACK TSTDeleteRowCB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			QuitUserInterface (0);
			break;
	}
	return 0;
}
//********************************************************************************************************************
int CVICALLBACK TSTInsertRowCB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			QuitUserInterface (0);
			break;
	}
	return 0;
}
//********************************************************************************************************************
int CVICALLBACK TSTCFGSaveCB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
    int						numRows, numColumns;
    int 					TabPanelHandle; 
	int                 	error = 0;	
	char					dir[MAX_PATHNAME_LEN], filePath[MAX_PATHNAME_LEN]; 

	switch (event)
	{
		case EVENT_COMMIT:
			GetPanelHandleFromTabPage (TestCfgPanelHandle, TSTCFG_PNL_TST_CFG_TAB, TAB_PAGE_TWO, &TabPanelHandle);
		    //Fill ring control options

			errChk(GetNumTableRows(TabPanelHandle, DYN_TABLE_TST_CONFIG, &numRows));
			errChk(GetNumTableColumns(TabPanelHandle, DYN_TABLE_TST_CONFIG, &numColumns));
			
			UniversalGetSysCfgTestgStepsTable(TestCfgPanelHandle, TSTCFG_PNL_TST_CFG_TAB , TAB_PAGE_TWO, DYN_TABLE_TST_CONFIG);
			
		    GetProjectDir(dir);
			sprintf(filePath, "%s\\Configuration\\%s", dir, selRecipe.TestStepsFile);
			CreateBackUpCopy(filePath);
			
			UniversalSaveSysCfgGTestStepsTableValue(numRows);
			UniversalWriteSysCfgTestStepsTableValue(numRows, filePath,8);
			
			CVIXMLElement rootElement;
			rootElement = LoadConfigurationDocument(filePath);
			ParseXMLDocument(rootElement, 0);
			InitTestStepParam();
			if(totalNest > 0)
			{
				for(int i=0; i<totalNest; i++)
				{
					for(int j=0;j<testARRAY_SIZE;j++)
					{
						char tempNestNum[100];   
						strcpy(mtgTestStepInfo[i][j].testNum          	 	 , gTestStepInfo[j].testNum);        	
						strcpy(mtgTestStepInfo[i][j].testName       		 , gTestStepInfo[j].testName);       	
						strcpy(mtgTestStepInfo[i][j].testFuncName	 	 	 , gTestStepInfo[j].testFuncName);	 	
						strcpy(mtgTestStepInfo[i][j].testSkip       		 , gTestStepInfo[j].testSkip); 
						strcpy(mtgTestStepInfo[i][j].testType       		 , gTestStepInfo[j].testType);  				
						strcpy(mtgTestStepInfo[i][j].testAbort       		 , gTestStepInfo[j].testAbort); 
						strcpy(mtgTestStepInfo[i][j].testRepeat     		 , gTestStepInfo[j].testRepeat);     	
						strcpy(mtgTestStepInfo[i][j].testParam      		 , gTestStepInfo[j].testParam);      	
						strcpy(mtgTestStepInfo[i][j].testResult     		 , gTestStepInfo[j].testResult);
						sprintf(tempNestNum, "%d", i+1);
						strcpy(mtgTestStepInfo[i][j].testNest       		 , tempNestNum);       	
						strcpy(mtgTestStepInfo[i][j].testResultVal		     , gTestStepInfo[j].testResultVal);		
					}
				}		      
			}	
			
			BuildTestSequence();
			NumOfTests = getTestCount();
			DisplayTstControl(1,1);
			
			break;
	}
Error:
	
	return error;
}
//*******************************************************************************************************************
#if 0
int CVICALLBACK TstCFGTSSelectCB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int 		TabPanelHandle;
	char					dir[MAX_PATHNAME_LEN], uirPath[MAX_PATHNAME_LEN]; //dbPath[MAX_PATHNAME_LEN], SQLString[1000], strSeparator[10] = ", ";
	CVIXMLElement rootElement;
	
	int rowsIndex;
	char selectedTest[100]="";
	
	switch (event)
	{
		case EVENT_COMMIT:
			GetPanelHandleFromTabPage (TestCfgPanelHandle, TSTCFG_PNL_TST_CFG_TAB, TAB_PAGE_TWO, &TabPanelHandle); 
			GetCtrlVal(TabPanelHandle, TST_TB_TAB_SELECT_TEST, selectedTest);
		for(rowsIndex=0; rowsIndex<NumOfTests;rowsIndex++)
		{
			strcpy(gTestStepInfo[rowsIndex].testNum,               	"");               
			strcpy(gTestStepInfo[rowsIndex].testName,              	"");              
			strcpy(gTestStepInfo[rowsIndex].testFuncName,          	"");          
			strcpy(gTestStepInfo[rowsIndex].testSkip,  	          	""); 
			strcpy(gTestStepInfo[rowsIndex].testType, 	          	"");			
			strcpy(gTestStepInfo[rowsIndex].testAbort, 	          	""); 			
			strcpy(gTestStepInfo[rowsIndex].testRepeat,	          	"");
			strcpy(gTestStepInfo[rowsIndex].testParam,             	"");             
		}

			GetProjectDir(dir);
			sprintf(uirPath, "%s%s%s%s", dir,"\\Configuration\\", selectedTest, ".xml");
			rootElement = LoadConfigurationDocument(uirPath);
			ParseXMLDocument(rootElement, 0);
			SetActiveTabPage (TestCfgPanelHandle, TSTCFG_PNL_TST_CFG_TAB, 0);
			UniversalDisplaySysCfgGTestSteps(TestCfgPanelHandle, TSTCFG_PNL_TST_CFG_TAB, TAB_PAGE_ONE, TREE_TAB_TST_TREE, 149);
			UniversalDisplaySysCfgGTestStepsTable(TestCfgPanelHandle, TSTCFG_PNL_TST_CFG_TAB, TAB_PAGE_TWO,DYN_TABLE_TST_CONFIG);
			
			InitTestStepParam();
			
			gTestStepInfo[0].testName;
			break;
		case EVENT_KEYPRESS:

			break;
	}
	return 0;
}
#endif
//********************************************************************************************************************
/********************************************//**
* Display test configuration control
***********************************************/
void DisplayTstControl(int firstTab, int editTSTCfg) 
{

	int 					TabPanelHandle; 

	if(firstTab) SetActiveTabPage (TestCfgPanelHandle, TSTCFG_PNL_TST_CFG_TAB, 0);
	UniversalDisplaySysCfgGTestSteps(TestCfgPanelHandle, TSTCFG_PNL_TST_CFG_TAB, TAB_PAGE_ONE, TREE_TAB_TST_TREE, 149);

	UniversalDisplaySysCfgGTestStepsTable(TestCfgPanelHandle, TSTCFG_PNL_TST_CFG_TAB, TAB_PAGE_TWO,DYN_TABLE_TST_CONFIG);
	InitTestStepParam();
	if(editTSTCfg)
	{
		GetPanelHandleFromTabPage (TestCfgPanelHandle, TSTCFG_PNL_TST_CFG_TAB, TAB_PAGE_TWO, &TabPanelHandle);
		SetTabPageAttribute(TestCfgPanelHandle, TSTCFG_PNL_TST_CFG_TAB, TAB_PAGE_TWO, ATTR_VISIBLE, 1);
		SetCtrlAttribute (TabPanelHandle, TST_TB_TAB_TST_CFG_SAVE, ATTR_DIMMED , 0);
	}
	else
	{
		GetPanelHandleFromTabPage (TestCfgPanelHandle, TSTCFG_PNL_TST_CFG_TAB, TAB_PAGE_TWO, &TabPanelHandle);
		SetCtrlAttribute (TabPanelHandle, TST_TB_TAB_TST_CFG_SAVE, ATTR_DIMMED , 1);
	}
	

}
//********************************************************************************************************************
/********************************************//**
 Load test parameter header
***********************************************/
void InitTestStepParamHeader(void)
{
	int					index;
	
	for(index=0; index < 8; index++)
	{
		switch (index)
			{
			case 0:
				strcpy(gTesStepParamName[index], "testNum");
				break;
			case 1:
				strcpy(gTesStepParamName[index], "testName");
				break;
			case 2:
				strcpy(gTesStepParamName[index], "testFuncName");
				break;
			case 3:
				strcpy(gTesStepParamName[index], "testSkip");
				break;
			case 4:
				strcpy(gTesStepParamName[index], "testType");
				break;				
			case 5:
				strcpy(gTesStepParamName[index], "testAbort");
				break;
			case 6:
				strcpy(gTesStepParamName[index], "testRepeat");
				break;				
			case 7:
				strcpy(gTesStepParamName[index], "testParam");
				break;							
			default:
			
				break;
			}
	}

}
//********************************************************************************************************************
/********************************************//**
* init test parametre
***********************************************/
void InitTestStepParam(void)
{
	int					index;
	
	for(index=0; index < testARRAY_SIZE; index++)
	{
		if(!strcmp("testNum", gTesStepParamName[0]))
		{
			strcpy(gTestStepInfo[index].testNum, gTestStepInfoParam[index].Param0);
		}
		if(!strcmp("testName", gTesStepParamName[1]))
		{
			strcpy(gTestStepInfo[index].testName, gTestStepInfoParam[index].Param1);
		}
		if(!strcmp("testFuncName", gTesStepParamName[2]))
		{
			strcpy(gTestStepInfo[index].testFuncName, gTestStepInfoParam[index].Param2);
		}
		if(!strcmp("testSkip", gTesStepParamName[3]))
		{
			strcpy(gTestStepInfo[index].testSkip, gTestStepInfoParam[index].Param3);
		}
		if(!strcmp("testType", gTesStepParamName[4]))
		{
			strcpy(gTestStepInfo[index].testType, gTestStepInfoParam[index].Param4);
		}
		if(!strcmp("testAbort", gTesStepParamName[5]))
		{
			strcpy(gTestStepInfo[index].testAbort, gTestStepInfoParam[index].Param5);
		}
		if(!strcmp("testRepeat", gTesStepParamName[6]))
		{
			strcpy(gTestStepInfo[index].testRepeat, gTestStepInfoParam[index].Param6);
		}		
		if(!strcmp("testParam", gTesStepParamName[7]))
		{
			strcpy(gTestStepInfo[index].testParam, gTestStepInfoParam[index].Param7);
		}
		
		
	}


}
//*******************************************************************************************************************
/********************************************//**
* Create test configuration table  
***********************************************/
void CreategTestConfigurationTable()
{

	char tmpStr[100];

	int 		TabPanelHandle;
// -----------------------------------------------------------------------------------------------------------------------	
	Ptr_TST_CONFIG_TableParameters=&TST_CONFIG_TableParameters;
	Ptr_TST_CONFIG_ColumnParameters=TST_CONFIG_ColumnParameters; 

	GetPanelHandleFromTabPage (TestCfgPanelHandle, TSTCFG_PNL_TST_CFG_TAB, TAB_PAGE_TWO, &TabPanelHandle);

	strcpy(tmpStr, GetCfgMiscValue("MiscTableRow",150));
	Scan(tmpStr,"%d",&TST_CONFIG_TableRowsandColumns.Num_of_Rows);
	
	strcpy(tmpStr, GetCfgMiscValue("MiscTableColumn",150));
	Scan(tmpStr,"%d",&TST_CONFIG_TableRowsandColumns.Num_of_Columns);
	
	SetCtrlVal (TabPanelHandle, TSTCFG_PNL_TST_CFG_TAB, TST_CONFIG_TableRowsandColumns.Num_of_Rows);
	
	if(TST_CONFIG_TableRowsandColumns.Num_of_Rows>0)
	{
		LIB_CreateTableParam(Ptr_TST_CONFIG_TableParameters,10,500,950,30,10,
							  TST_CONFIG_TableRowsandColumns.Num_of_Rows,0);
    	DYN_TABLE_TST_CONFIG=LIB_CreatTableControl(Ptr_TST_CONFIG_TableParameters, TabPanelHandle, 
    												 "TestConfiguration.c", DYN_TABLE_TST_CONFIG);
    }
    else
    {
		LIB_CreateTableParam(Ptr_TST_CONFIG_TableParameters,10,500,950,30,10,PART_CONFIG_ROW_INDEX_CONSTANT,0);
	   	DYN_TABLE_TST_CONFIG=LIB_CreatTableControl(Ptr_TST_CONFIG_TableParameters,TabPanelHandle, 
	   												 "TestConfiguration.c", DYN_TABLE_TST_CONFIG);
    }

//  CREATE TABLE COLUMN	
//===================================================================================================================
	LIB_CreateTableColumnParam(Ptr_TST_CONFIG_ColumnParameters,0,-1,1,1,80,"Test Number",1);
	LIB_DYNInsertTableColumns(Ptr_TST_CONFIG_ColumnParameters, Ptr_TST_CONFIG_TableParameters,
							   TabPanelHandle, "TestConfiguration.c", DYN_TABLE_TST_CONFIG,1);//char  where Number Type int/Double = 0, char = 1
//===================================================================================================================	
	LIB_CreateTableColumnParam(Ptr_TST_CONFIG_ColumnParameters,1,-1,2,1,125,"Test Name",0);
	LIB_DYNInsertTableColumns(Ptr_TST_CONFIG_ColumnParameters, Ptr_TST_CONFIG_TableParameters,
							   TabPanelHandle, "TestConfiguration.c", DYN_TABLE_TST_CONFIG,2); //char
//===================================================================================================================	
	LIB_CreateTableColumnParam(Ptr_TST_CONFIG_ColumnParameters,2,-1,3,1,125,"Test Function Name",0);
	LIB_DYNInsertTableColumns(Ptr_TST_CONFIG_ColumnParameters, Ptr_TST_CONFIG_TableParameters,
							   TabPanelHandle, "TestConfiguration.c", DYN_TABLE_TST_CONFIG,3);//char
//===================================================================================================================	
	LIB_CreateTableColumnParam(Ptr_TST_CONFIG_ColumnParameters,3,-1,4,1,60,"Skip",0);
	LIB_DYNInsertTableColumns(Ptr_TST_CONFIG_ColumnParameters, Ptr_TST_CONFIG_TableParameters,
							   TabPanelHandle, "TestConfiguration.c", DYN_TABLE_TST_CONFIG,4);//char
//===================================================================================================================	
	LIB_CreateTableColumnParam(Ptr_TST_CONFIG_ColumnParameters,4,-1,5,1,60,"Type",0);
	LIB_DYNInsertTableColumns(Ptr_TST_CONFIG_ColumnParameters, Ptr_TST_CONFIG_TableParameters,
							   TabPanelHandle, "TestConfiguration.c", DYN_TABLE_TST_CONFIG,5);//char	
//===================================================================================================================	
	LIB_CreateTableColumnParam(Ptr_TST_CONFIG_ColumnParameters,5,-1,6,1,60,"Abort",0);
	LIB_DYNInsertTableColumns(Ptr_TST_CONFIG_ColumnParameters, Ptr_TST_CONFIG_TableParameters,
							   TabPanelHandle, "TestConfiguration.c", DYN_TABLE_TST_CONFIG,6);//char
//===================================================================================================================	
	LIB_CreateTableColumnParam(Ptr_TST_CONFIG_ColumnParameters,6,-1,7,1,60,"Repeat",0);
	LIB_DYNInsertTableColumns(Ptr_TST_CONFIG_ColumnParameters, Ptr_TST_CONFIG_TableParameters,
							   TabPanelHandle, "TestConfiguration.c", DYN_TABLE_TST_CONFIG,7);//char	
//===================================================================================================================	
	LIB_CreateTableColumnParam(Ptr_TST_CONFIG_ColumnParameters,7,-1,8,1,500,"Parameters",0);
	LIB_DYNInsertTableColumns(Ptr_TST_CONFIG_ColumnParameters, Ptr_TST_CONFIG_TableParameters,
							   TabPanelHandle, "TestConfiguration.c", DYN_TABLE_TST_CONFIG,8);//char

	SetCtrlAttribute(TabPanelHandle, TST_TB_TAB_NUM_COLUMNS,ATTR_NO_EDIT_TEXT,0);
	SetCtrlVal (TabPanelHandle, TST_TB_TAB_NUM_COLUMNS, ((Ptr_TST_CONFIG_ColumnParameters+9))->NumberofColumns);
	SetCtrlAttribute(TabPanelHandle, TST_TB_TAB_NUM_COLUMNS,ATTR_NO_EDIT_TEXT,1);
	SetCtrlAttribute(TabPanelHandle, TST_TB_TAB_NUM_COLUMNS,ATTR_SHOW_INCDEC_ARROWS,0);
}
//*******************************************************************************************************************
/********************************************//**
* Get test count 
***********************************************/
int getTestCount(void)
{	  
	
	int count = 0;
	for(int i=0;i<testARRAY_SIZE;i++)
	{

		     if (strcmp(mtgTestStepInfo[0][i].testFuncName,"") )
			 {
				 count++;
			 }
	}
	return count;   		
}
//*******************************************************************************************************************
/********************************************//**
* Build test sequence
***********************************************/
void  BuildTestSequence(void)
{
	int i;
	int j;
	char *funcName;
	char errMsg[256]={0};

		for(i=0;i<testARRAY_SIZE;i++)
		{
			for(j=0; j<totalNest; j++)
			{
				funcName = mtgTestStepInfo[j][i].testFuncName;
				if(!strcmp(funcName,"Bat_Ctrl")) 
				{
					funcptr10[j][i]= Bat_Ctrl;
				}
				else if(!strcmp(funcName,"AnalogVoltMeas")) 	// Measure operating current
				{
					funcptr10[j][i]= AnalogVoltMeas;
				}
				else if(!strcmp(funcName,"Restart_Unit")) 
				{
					funcptr10[j][i]= Restart_Unit;
				}
				else if(!strcmp(funcName,"Release_Test_Instrument")) 
				{
					funcptr10[j][i]= Release_Test_Instrument;
				}
				else if(!strcmp(funcName,"Release_Other_Nest")) 
				{
					funcptr10[j][i]= Release_Other_Nest;
				}
				else if(!strcmp(funcName,"InitInterfaces")) 
				{
					funcptr10[j][i]= InitInterfaces;
				}
				else if(!strcmp(funcName,"InitCanInterface")) 
				{
					funcptr10[j][i]= InitCanInterface;
				}
				else if(!strcmp(funcName,"Sensor_Comm_Init")) //AA
    			{											 //AA
      				funcptr10[j][i]= Sensor_Comm_Init;		 //AA
     			}											 //AA
				else if(!strcmp(funcName,"GetSerialNumber")) 
				{
					funcptr10[j][i]= GetSerialNumber;
				}
				else if(!strcmp(funcName,"GetSWVersion")) 
				{
					funcptr10[j][i]= GetSWVersion;
				}
				else if(!strcmp(funcName,"Init_Tx_Cal")) 
				{
					funcptr10[j][i]= Init_Tx_Cal;
				}
				else if(!strcmp(funcName,"PingDut")) 
				{
					funcptr10[j][i]= PingDut;
				} 
				
				else if(!strcmp(funcName,"WritePointCsvValue")) 
				{
					funcptr10[j][i]= WritePointCsvValue;
				}
				
				else if(!strcmp(funcName,"ReadPointCSV")) 
				{
					funcptr10[j][i]= ReadPointCSV;
				}
				else if(!strcmp(funcName,"ReadPoint")) 
				{
					funcptr10[j][i]= ReadPoint;
				}
				else if(!strcmp(funcName,"WritePoint")) 
				{
					funcptr10[j][i]= WritePoint;
				}
				else if(!strcmp(funcName,"SaveConfigPoints")) 
				{
					funcptr10[j][i]= SaveConfigPoints;
				}
				else if(!strcmp(funcName,"Make_Path")) 
				{
					funcptr10[j][i]= Make_Path;
				}
				else if(!strcmp(funcName,"Force_Radar_Mode")) 
				{
					funcptr10[j][i]= Force_Radar_Mode;
				}
				else if(!strcmp(funcName,"GetOccupiedBw")) 
				{
					funcptr10[j][i]= GetOccupiedBw;
				}
				else if(!strcmp(funcName,"Select_TX_Antenna")) 
				{
					funcptr10[j][i]= Select_TX_Antenna;
				}
				else if(!strcmp(funcName,"SetCWMode")) 
				{
					funcptr10[j][i]= SetCWMode;
				}
				else if(!strcmp(funcName,"SetHondaTxPowerCal")) 
				{
					funcptr10[j][i]= SetHondaTxPowerCal;
				}
				else if(!strcmp(funcName,"GetTxPower")) 
				{
					funcptr10[j][i]= GetTxPower;
				}
				else if(!strcmp(funcName,"GetCenterFrequency")) 
				{
					funcptr10[j][i]= GetCenterFrequency;
				}
				else if(!strcmp(funcName,"GetCwLeakage")) 
				{
					funcptr10[j][i]= GetCwLeakage;
				}
		//		else if(!strcmp(funcName,"Get_Dll_Version")) 
		//		{
		//			funcptr10[j][i]= Get_Dll_Version;
		//		}
				else if(!strcmp(funcName,"Get_Test_Instrument")) 
				{
					funcptr10[j][i]= Get_Test_Instrument;
				}
				else if(!strcmp(funcName,"WriteDUTData"))  //aa writing points 1571-1576
				{
					funcptr10[j][i]= WriteDUTData;
				}
				else if(!strcmp(funcName,"SerialpointsCheck"))  //aa Checking points 1571-1576
				{
					funcptr10[j][i]= SerialpointsCheck;
				}
				else if(!strcmp(funcName,"DisconnectTXCal")) 
				{
					funcptr10[j][i]= DisconnectTXCal;
				}
				else if(!strcmp(funcName,"Proceed_Request")) 
				{
					funcptr10[j][i]= Proceed_Request;
				}
				else if(!strcmp(funcName,"DisconnectCan")) 
				{
					funcptr10[j][i]= DisconnectCan;
				}
				else if(!strcmp(funcName,"ReadTemperature")) 
				{
					funcptr10[j][i]= ReadTemperature;
				}
				else if(!strcmp(funcName,"SetTemperatureCompensation")) 
				{
					funcptr10[j][i]= SetTemperatureCompensation;
				}
				else if(!strcmp(funcName,"SetMaxPowerForOccupiedBW")) 
				{
					funcptr10[j][i]= SetMaxPowerForOccupiedBW;
				}
				else if(!strcmp(funcName,"WriteNBMailboxPoints")) 
				{
					funcptr10[j][i]= WriteNBMailboxPoints;
				}
				else if(!strcmp(funcName,"VerifyNBMailboxPoints")) 
				{
					funcptr10[j][i]= VerifyNBMailboxPoints;
				} 
				else if(!strcmp(funcName,"SetGMTxPowerCal")) 
				{
					funcptr10[j][i]= SetGMTxPowerCal;
				}
				else if(!strcmp(funcName,"Reset_Bat")) 
				{
					funcptr10[j][i]= Reset_Bat;
				}				
				else
				{
					if (stricmp(funcName,"") !=0)
					{
						sprintf(errMsg,"%s does not exist",funcName);
						MessagePopup("Error",errMsg);
						exit(0);
					}
				}

				
			}   // end j nest for loop
			
		}  // end i test `for loop
		
	return;
}
//*******************************************************************************************************************
/********************************************//**
* Display test report 
***********************************************/
void DisplayTestReport(int dutNumber, char testStr[1000])
{

	
	char * itemString = strtok(testStr,"\n");
    while (itemString != NULL)
    {
		InsertItemInTestReport(dutNumber,itemString);
     	itemString = strtok (NULL, ",");
    }
}

/********************************************//**
* Insert item in test report  
***********************************************/
void InsertItemInTestReport(int dutNumber, char *testStr)
{
	int size;
	
	InsertListItem(MainPanelHandle, gReportList[dutNumber], /***testNumber***/ -1, testStr,0);
	GetNumListItems (MainPanelHandle, gReportList[dutNumber], &size);
	SetCtrlAttribute (MainPanelHandle, gReportList[dutNumber], ATTR_CTRL_INDEX, size-1);

	 
}

/********************************************//**
* Display test pass fail in result file
***********************************************/
void DisplayPassFailResult(int TestResult, int testNumber, char timeStamp[], bool runTestScript, int scriptTestNumber, int threadNum, int testAttempt)
{
    char testStr[1000], textColor[100], testName[100]={"OK"}, textColorPass[100], textColorHighLimit[100], 
		 testNumberStr[100], tempTestResult[100],testResult[100], testTimeStamp[100];

	int size;
	
	if(TestResult == 1)
	{
		sprintf(textColor, "\033fg000000");
		sprintf(textColorPass, "\033fg00FF00");
		sprintf(textColorHighLimit, "\033fg000000");
		sprintf(tempTestResult, "\033p200l%s",mtgTestStepInfo[threadNum - 1][testNumber-1].testResult);//"PASS");
		sprintf(testResult,"%s%s", textColor, tempTestResult);
		sprintf(textColor, "\033fg000000");
	}
	else if(TestResult == 2)
	{
		sprintf(textColor, "\033fg808000");
		sprintf(testResult, "\033p200l%s","SKIPPED");
	}
	else
	{
		sprintf(textColor, "\033fgFF0000");
		sprintf(testResult, "\033p200l%s",mtgTestStepInfo[threadNum - 1][testNumber-1].testResult);//"FAIL");
	}

	sprintf(testNumberStr, "T%d", testNumber);
	sprintf(testName, "\033p30l%s",mtgTestStepInfo[threadNum - 1][testNumber-1].testName);
	//sprintf(testRepeat, "\033p890l%d",numberOfAttempt); 
	sprintf(testTimeStamp, "\033p240l%s",timeStamp);

	
	sprintf(testStr, "%s %s %s %s", textColor, 
			    testNumberStr, testName, testTimeStamp);
	

	InsertListItem(MainPanelHandle, gStepList[threadNum - 1], /***testNumber***/ -1, testStr,0);
	GetNumListItems (MainPanelHandle, gStepList[threadNum - 1], &size);
	SetCtrlAttribute (MainPanelHandle, gStepList[threadNum - 1], ATTR_CTRL_INDEX, size-1);


	InsertItemInReportList(threadNum,testNumber,textColor);
	GetNumListItems (MainPanelHandle, gReportList[threadNum - 1], &size);  
	SetCtrlAttribute (MainPanelHandle, gReportList[threadNum - 1], ATTR_CTRL_INDEX, size-1); 
		
	
    strcpy(parsedFRMsg, "");
}


/********************************************//**
* Insert test result in report list  
***********************************************/
void InsertItemInReportList(int threadNum, int testNumber, char textColor[100])
{
	char measTab[20]={"\033p20l"}; 
	char lowTab[20]={"\033p320l"};
	char highTab[20]={"\033p420l"};
	char read[25];
	char min[25];
	char max[25];
	char expected[25];
	
	
	char itemStr[1024];	//512
	char *pch;
	
	
	// Insert test measurement status and measurement values
	sprintf(itemStr,"%s M%i \033p40l %s",textColor,testNumber,mtgTestStepInfo[threadNum-1][testNumber-1].testName);
	InsertListItem(MainPanelHandle, gReportList[threadNum - 1],-1,itemStr,0); 
	pch = strtok(mtgTestStepInfo[threadNum-1][testNumber-1].testResultVal,","); 
	if (strstr(mtgTestStepInfo[threadNum-1][testNumber-1].testFuncName,"Bat_Ctrl") != NULL)
	{
		while (pch != NULL)
		{
			sprintf(itemStr,"%s %s %s",textColor,measTab,pch);
			InsertListItem(MainPanelHandle, gReportList[threadNum - 1],-1,itemStr,0); 
			pch = strtok(NULL,",");
		}
	}
	else if (strstr(mtgTestStepInfo[threadNum-1][testNumber-1].testFuncName,"Proceed_Request") != NULL)  
	{
		while (pch != NULL)
		{
			sprintf(itemStr,"%s %s %s",textColor,measTab,pch);
			InsertListItem(MainPanelHandle, gReportList[threadNum - 1],-1,itemStr,0); 
			pch = strtok(NULL,",");
		}
	}
	else if (strstr(mtgTestStepInfo[threadNum-1][testNumber-1].testFuncName,"AnalogVoltMeas") != NULL)  
	{
		sprintf(itemStr,"%s %s %s %s %.3f %s %.3f",textColor,measTab,pch,lowTab,CurrentLowLimit,highTab,CurrentHighLimit);
		InsertListItem(MainPanelHandle, gReportList[threadNum - 1],-1,itemStr,0); 
	}
	else if (strstr(mtgTestStepInfo[threadNum-1][testNumber-1].testFuncName,"Get_Sensor_Temperature") != NULL)  
	{
		sprintf(itemStr,"%s %s %s %s %2i %s %2i",textColor,measTab,pch,lowTab,TemperatureLowLimit,highTab,TemperatureHighLimit);
		InsertListItem(MainPanelHandle, gReportList[threadNum - 1],-1,itemStr,0); 
	}
	else if (strstr(mtgTestStepInfo[threadNum-1][testNumber-1].testFuncName,"Get_Firmware_Version") != NULL)  
	{
		while (pch != NULL)
		{
			sprintf(itemStr,"%s %s %s",textColor,measTab,pch);
			InsertListItem(MainPanelHandle, gReportList[threadNum - 1],-1,itemStr,0); 
			pch = strtok(NULL,",");
		}
	}
	else if (strstr(mtgTestStepInfo[threadNum-1][testNumber-1].testFuncName,"Get_Test_Instrument") != NULL)  
	{
		while (pch != NULL)
		{
			sprintf(itemStr,"%s %s %s",textColor,measTab,pch);
			InsertListItem(MainPanelHandle, gReportList[threadNum - 1],-1,itemStr,0); 
			pch = strtok(NULL,",");
		}
	}
	else if (strstr(mtgTestStepInfo[threadNum-1][testNumber-1].testFuncName,"Cal_Tx_Band_CrossOver_Frequency") != NULL)  
	{
		sprintf(itemStr,"%s %s %s",textColor,measTab,pch);
		InsertListItem(MainPanelHandle, gReportList[threadNum - 1],-1,itemStr,0); 
		pch = strtok(NULL,",");
		sprintf(itemStr,"%s %s %s %s %i %s %s",textColor,measTab,pch,lowTab,Band0LowLimit,highTab,"NULL");
		InsertListItem(MainPanelHandle, gReportList[threadNum - 1],-1,itemStr,0); 
		pch = strtok(NULL,",");
		sprintf(itemStr,"%s %s %s %s %s %s %i",textColor,measTab,pch,lowTab,"NULL",highTab,Band1HighLimit);
		InsertListItem(MainPanelHandle, gReportList[threadNum - 1],-1,itemStr,0); 
		pch = strtok(NULL,",");
		sprintf(itemStr,"%s %s %s %s %i %s %s",textColor,measTab,pch,lowTab,Band0LowLimit,highTab,"NULL");
		InsertListItem(MainPanelHandle, gReportList[threadNum - 1],-1,itemStr,0); 
		pch = strtok(NULL,",");
		sprintf(itemStr,"%s %s %s %s %s %s %i",textColor,measTab,pch,lowTab,"NULL",highTab,Band1HighLimit);
		InsertListItem(MainPanelHandle, gReportList[threadNum - 1],-1,itemStr,0); 
		pch = strtok(NULL,",");
	}
	else if (strstr(mtgTestStepInfo[threadNum-1][testNumber-1].testFuncName,"Restart_Unit") != NULL)  
	{
		while (pch != NULL)
		{
			sprintf(itemStr,"%s %s %s",textColor,measTab,pch);
			InsertListItem(MainPanelHandle, gReportList[threadNum - 1],-1,itemStr,0); 
			pch = strtok(NULL,",");
		}
	}
	else if (strstr(mtgTestStepInfo[threadNum-1][testNumber-1].testFuncName,"Cal_Tx_Uwb_Power") != NULL)  
	{
		sprintf(itemStr,"%s %s %s %s %i %s %i",textColor,measTab,pch,lowTab,UwbDacLowLimit,highTab,UwbDacHighLimit);
		InsertListItem(MainPanelHandle, gReportList[threadNum - 1],-1,itemStr,0); 
		pch = strtok(NULL,",");   
		sprintf(itemStr,"%s %s %s %s %.1f %s %.1f",textColor,measTab,pch,lowTab,UwbPowerLowLimit,highTab,UwbPowerHighLimit);
		InsertListItem(MainPanelHandle, gReportList[threadNum - 1],-1,itemStr,0); 
		pch = strtok(NULL,",");   
		sprintf(itemStr,"%s %s %s %s %s %s %s",textColor,measTab,pch,lowTab,"NULL",highTab,"NULL");
		InsertListItem(MainPanelHandle, gReportList[threadNum - 1],-1,itemStr,0); 
		pch = strtok(NULL,",");   
		sprintf(itemStr,"%s %s %s %s %.1f %s %s",textColor,measTab,pch,lowTab,UwbCalMarginLowLimit,highTab,"NULL");
		InsertListItem(MainPanelHandle, gReportList[threadNum - 1],-1,itemStr,0); 
	}
	else if (strstr(mtgTestStepInfo[threadNum-1][testNumber-1].testFuncName,"Verify_Calibrated_Uwb_Dac") != NULL)  
	{
		while (pch != NULL)
		{
			sprintf(itemStr,"%s %s %s",textColor,measTab,pch);
			InsertListItem(MainPanelHandle, gReportList[threadNum - 1],-1,itemStr,0); 
			pch = strtok(NULL,",");
		}
	}
	else if (strstr(mtgTestStepInfo[threadNum-1][testNumber-1].testFuncName,"Measure_Ism_Pulling_And_Power_Cal") != NULL)  
	{
		sprintf(itemStr,"%s %s %s %s -%.1f %s %.1f",textColor,measTab,pch,lowTab,IsmInitalDAC,highTab,IsmInitalDAC);
		InsertListItem(MainPanelHandle, gReportList[threadNum - 1],-1,itemStr,0); 
		pch = strtok(NULL,",");  
		sprintf(itemStr,"%s %s %s %s -%.1f %s %.1f",textColor,measTab,pch,lowTab,IsmFreqDevHighLimit,highTab,IsmFreqDevHighLimit);
		InsertListItem(MainPanelHandle, gReportList[threadNum - 1],-1,itemStr,0); 
		pch = strtok(NULL,",");   
		sprintf(itemStr,"%s %s %s %s %i %s %i",textColor,measTab,pch,lowTab,IsmDacLowLimit,highTab,IsmDacHighLimit);
		InsertListItem(MainPanelHandle, gReportList[threadNum - 1],-1,itemStr,0); 
		pch = strtok(NULL,",");   
		sprintf(itemStr,"%s %s %s %s %.1f %s %s",textColor,measTab,pch,lowTab,IsmPowerLowLimit,highTab,"NULL");
		InsertListItem(MainPanelHandle, gReportList[threadNum - 1],-1,itemStr,0); 
		pch = strtok(NULL,",");
		sprintf(itemStr,"%s %s %s",textColor,measTab,pch);
		InsertListItem(MainPanelHandle, gReportList[threadNum - 1],-1,itemStr,0); 
		pch = strtok(NULL,",");
		sprintf(itemStr,"%s %s %s",textColor,measTab,pch);
		InsertListItem(MainPanelHandle, gReportList[threadNum - 1],-1,itemStr,0); 
	}
	else if (strstr(mtgTestStepInfo[threadNum-1][testNumber-1].testFuncName,"Measure_Ism_Pulling_And_Power") != NULL)  
	{
		sprintf(itemStr,"%s %s %s %s -%.1f %s %.1f",textColor,measTab,pch,lowTab,IsmFreqDevHighLimit,highTab,IsmFreqDevHighLimit);
		InsertListItem(MainPanelHandle, gReportList[threadNum - 1],-1,itemStr,0); 
		pch = strtok(NULL,",");   
		sprintf(itemStr,"%s %s %s %s %.1f %s %s",textColor,measTab,pch,lowTab,IsmPowerLowLimit,highTab,"NULL");
		InsertListItem(MainPanelHandle, gReportList[threadNum - 1],-1,itemStr,0); 
		pch = strtok(NULL,",");
		sprintf(itemStr,"%s %s %s",textColor,measTab,pch);
		InsertListItem(MainPanelHandle, gReportList[threadNum - 1],-1,itemStr,0); 
		pch = strtok(NULL,",");
		sprintf(itemStr,"%s %s %s",textColor,measTab,pch);
		InsertListItem(MainPanelHandle, gReportList[threadNum - 1],-1,itemStr,0); 
	}
	else if (strstr(mtgTestStepInfo[threadNum-1][testNumber-1].testFuncName,"Measure_Uwb_Peak_Power") != NULL)  
	{
		sprintf(itemStr,"%s %s %s %s %.1f %s %.1f",textColor,measTab,pch,lowTab,UwbPowerCheckLowLimit,highTab,UwbPowerCheckHighLimit);
		InsertListItem(MainPanelHandle, gReportList[threadNum - 1],-1,itemStr,0); 
		pch = strtok(NULL,",");
		sprintf(itemStr,"%s %s %s",textColor,measTab,pch);
		InsertListItem(MainPanelHandle, gReportList[threadNum - 1],-1,itemStr,0); 
	}
	else if (strstr(mtgTestStepInfo[threadNum-1][testNumber-1].testFuncName,"Measure_Tx_Diff_Power") != NULL)  
	{
		while (pch != NULL)
		{
			sprintf(itemStr,"%s %s %s %s %.1f %s %.1f",textColor,measTab,pch,lowTab,TxDiffLowLimit,highTab,TxDiffHighLimit);
			InsertListItem(MainPanelHandle, gReportList[threadNum - 1],-1,itemStr,0); 
			pch = strtok(NULL,",");
		}
	}
	else if (strstr(mtgTestStepInfo[threadNum-1][testNumber-1].testFuncName,"Measure_Tx_Isolation_Power") != NULL)  
	{
		while (pch != NULL)
		{
			sprintf(itemStr,"%s %s %s %s %.1f %s %s",textColor,measTab,pch,lowTab,TxIsolLowLimit,highTab,"NULL");
			InsertListItem(MainPanelHandle, gReportList[threadNum - 1],-1,itemStr,0); 
			pch = strtok(NULL,",");
		}
	}
	else if (strstr(mtgTestStepInfo[threadNum-1][testNumber-1].testFuncName,"Measure_Tx_Isolation_At_Cal_Uwb") != NULL)  
	{
		while (pch != NULL)
		{
			sprintf(itemStr,"%s %s %s %s %.1f %s %.1f",textColor,measTab,pch,lowTab,TxIsolCalLowLimit,highTab,TxIsolCalHighLimit);
			InsertListItem(MainPanelHandle, gReportList[threadNum - 1],-1,itemStr,0); 
			pch = strtok(NULL,",");
		}
	}
	else if (strstr(mtgTestStepInfo[threadNum-1][testNumber-1].testFuncName,"Release_Test_Instrument") != NULL)  
	{
		while (pch != NULL)
		{
			sprintf(itemStr,"%s %s %s",textColor,measTab,pch);
			InsertListItem(MainPanelHandle, gReportList[threadNum - 1],-1,itemStr,0); 
			pch = strtok(NULL,",");
		}
	} //ReadPointCSV
	else if (strstr(mtgTestStepInfo[threadNum-1][testNumber-1].testFuncName,"ReadPointCSV") != NULL)  
	{
		while (pch != NULL)
		{
			strcpy(read,pch);
			pch = strtok(NULL,",");	
			strcpy(min,pch);
			pch = strtok(NULL,",");	
			strcpy(max,pch);	   
			sprintf(itemStr,"%s %s %s %s %s %s %s",textColor,measTab,read,lowTab,min,highTab,max);
			InsertListItem(MainPanelHandle, gReportList[threadNum - 1],-1,itemStr,0); 
			pch = strtok(NULL,",");
		}
	} //WritePointCsvValue
	else if (strstr(mtgTestStepInfo[threadNum-1][testNumber-1].testFuncName,"WritePointCsvValue") != NULL)  
	{
		while (pch != NULL)
		{
			strcpy(read,pch);
			pch = strtok(NULL,",");	
			strcpy(min,pch);
			pch = strtok(NULL,",");	
			strcpy(max,pch);	   
			sprintf(itemStr,"%s %s %s %s %s %s %s",textColor,measTab,read,lowTab,min,highTab,max);
			InsertListItem(MainPanelHandle, gReportList[threadNum - 1],-1,itemStr,0); 
			pch = strtok(NULL,",");
		}
	} //WritePointCsvValue
	
	else if (strstr(mtgTestStepInfo[threadNum-1][testNumber-1].testFuncName,"SetHondaTxPowerCal") != NULL)  
	{
		int i = 0;
		
		
		while (pch != NULL)
		{
			if (i==0)
			{
				sprintf(itemStr,"%s %s %s",textColor,measTab,pch);
			}
			else
			{
			strcpy(read,pch);
			pch = strtok(NULL,",");	
			strcpy(min,pch);
			pch = strtok(NULL,",");	
			strcpy(max,pch);	   
			sprintf(itemStr,"%s %s %s %s %s %s %s",textColor,measTab,read,lowTab,min,highTab,max);
			}
			InsertListItem(MainPanelHandle, gReportList[threadNum - 1],-1,itemStr,0); 
			pch = strtok(NULL,",");
			i++;
		}
		
	} 
	else if (strstr(mtgTestStepInfo[threadNum-1][testNumber-1].testFuncName,"SetGMTxPowerCal") != NULL)  
	{
		int i = 0;
		
		
		while (pch != NULL)
		{
			if (i==0)
			{
				sprintf(itemStr,"%s %s %s",textColor,measTab,pch);
			}
			else
			{
			strcpy(read,pch);
			pch = strtok(NULL,",");	
			strcpy(min,pch);
			pch = strtok(NULL,",");	
			strcpy(max,pch);	   
			sprintf(itemStr,"%s %s %s %s %s %s %s",textColor,measTab,read,lowTab,min,highTab,max);
			}
			InsertListItem(MainPanelHandle, gReportList[threadNum - 1],-1,itemStr,0); 
			pch = strtok(NULL,",");
			i++;
		}
		
	} 	
	else if (strstr(mtgTestStepInfo[threadNum-1][testNumber-1].testFuncName,"GetSWVersion") != NULL)  
	{
		while (pch != NULL)
		{
			strcpy(read,pch);
			pch = strtok(NULL,",");	
			strcpy(expected,pch);
			sprintf(itemStr,"%s %s %s %s %s",textColor,measTab,read,lowTab,expected);
			InsertListItem(MainPanelHandle, gReportList[threadNum - 1],-1,itemStr,0); 
			pch = strtok(NULL,",");
		}
	} //GetSWVersion
	else if (strstr(mtgTestStepInfo[threadNum-1][testNumber-1].testFuncName,"GetOccupiedBw") != NULL)  
	{
		while (pch != NULL)
		{
			strcpy(read,pch);
			pch = strtok(NULL,",");	
			strcpy(min,pch);
			pch = strtok(NULL,",");	
			strcpy(max,pch);	   
			sprintf(itemStr,"%s %s %s %s %s %s %s",textColor,measTab,read,lowTab,min,highTab,max);
			InsertListItem(MainPanelHandle, gReportList[threadNum - 1],-1,itemStr,0); 
			pch = strtok(NULL,",");
		}
	} //GetOccupiedBw
	else if (strstr(mtgTestStepInfo[threadNum-1][testNumber-1].testFuncName,"GetCenterFrequency") != NULL)  
	{
		while (pch != NULL)
		{
			strcpy(read,pch);
			pch = strtok(NULL,",");	
			strcpy(min,pch);
			pch = strtok(NULL,",");	
			strcpy(max,pch);	   
			sprintf(itemStr,"%s %s %s %s %s %s %s",textColor,measTab,read,lowTab,min,highTab,max);
			InsertListItem(MainPanelHandle, gReportList[threadNum - 1],-1,itemStr,0); 
			pch = strtok(NULL,",");
		}
	} //GetCenterFrequency
	else if ( strstr(mtgTestStepInfo[threadNum-1][testNumber-1].testFuncName,"GetCwLeakage") != NULL)  
	{
		while (pch != NULL)
		{
			strcpy(read,pch);
			pch = strtok(NULL,",");	
			strcpy(min,pch);
			pch = strtok(NULL,",");	
			strcpy(max,pch);	   
			sprintf(itemStr,"%s %s %s %s %s %s %s",textColor,measTab,read,lowTab,min,highTab,max);
			InsertListItem(MainPanelHandle, gReportList[threadNum - 1],-1,itemStr,0); 
			pch = strtok(NULL,",");
		}
	} //GetCWLeakage
	else if (strstr(mtgTestStepInfo[threadNum-1][testNumber-1].testFuncName,"GetTxPower") != NULL)  
	{
		while (pch != NULL)
		{
			strcpy(read,pch);
			pch = strtok(NULL,",");	
			strcpy(min,pch);
			pch = strtok(NULL,",");	
			strcpy(max,pch);	   
			sprintf(itemStr,"%s %s %s %s %s %s %s",textColor,measTab,read,lowTab,min,highTab,max);
			InsertListItem(MainPanelHandle, gReportList[threadNum - 1],-1,itemStr,0); 
			pch = strtok(NULL,",");
		}
	} //GetCenterFrequency
	
	
	else if (strstr(mtgTestStepInfo[threadNum-1][testNumber-1].testFuncName,"SetPoints") != NULL)  
	{
		while (pch != NULL)
		{
			sprintf(itemStr,"%s %s %s",textColor,measTab,pch);
			InsertListItem(MainPanelHandle, gReportList[threadNum - 1],-1,itemStr,0); 
			pch = strtok(NULL,",");
		}
	} //SerialpointsCheck
	else if (strstr(mtgTestStepInfo[threadNum-1][testNumber-1].testFuncName,"SerialpointsCheck") != NULL)  
	{
		while (pch != NULL)
		{
			sprintf(itemStr,"%s %s %s",textColor,measTab,pch);
			InsertListItem(MainPanelHandle, gReportList[threadNum - 1],-1,itemStr,0); 
			pch = strtok(NULL,",");
		}
	}
	else if (strstr(mtgTestStepInfo[threadNum-1][testNumber-1].testFuncName,"SetMaxPowerForOccupiedBW") != NULL)  
	{
		while (pch != NULL)
		{
			sprintf(itemStr,"%s %s %s",textColor,measTab,pch);
			InsertListItem(MainPanelHandle, gReportList[threadNum - 1],-1,itemStr,0); 
			pch = strtok(NULL,",");
		}
	} 
	else if (strstr(mtgTestStepInfo[threadNum-1][testNumber-1].testFuncName,"WriteDUTData") != NULL)  
	{
		while (pch != NULL)
		{
			sprintf(itemStr,"%s %s %s",textColor,measTab,pch);
			InsertListItem(MainPanelHandle, gReportList[threadNum - 1],-1,itemStr,0); 
			pch = strtok(NULL,",");
		}
	} 
	else if (strstr(mtgTestStepInfo[threadNum-1][testNumber-1].testFuncName,"ReadTemperature") != NULL)  
	{
/*		
		char read[25];
		char min[25];
		char max[25];
		
		while (pch != NULL)
		{
			strcpy(read,pch);
			pch = strtok(NULL,",");	
			strcpy(min,pch);
			pch = strtok(NULL,",");	
			strcpy(max,pch);	   
			sprintf(itemStr,"%s %s %s %s %s %s %s",textColor,measTab,read,lowTab,min,highTab,max);
			InsertListItem(MainPanelHandle, gReportList[threadNum - 1],-1,itemStr,0); 
			pch = strtok(NULL,",");
		}

*/
///*		
		char read[25];
		char delta[25];
		char min[25];
		char max[25];
		
		while (pch != NULL)
		{
			strcpy(read,pch);
			pch = strtok(NULL,",");
			strcpy(delta,pch);
			pch = strtok(NULL,",");
			strcpy(min,pch);
			pch = strtok(NULL,",");	
			strcpy(max,pch);
			
			sprintf(itemStr,"%s %s %s    %s %s %s %s %s",textColor,measTab,read,delta,lowTab,min,highTab,max);
			InsertListItem(MainPanelHandle, gReportList[threadNum - 1],-1,itemStr,0); 
			pch = strtok(NULL,",");
		}
//*/	
	
	
	
	
	
	
	
	
	} 
	else if (strstr(mtgTestStepInfo[threadNum-1][testNumber-1].testFuncName,"WriteNBMailboxPoints") != NULL)  
	{
		while (pch != NULL)
		{
			strcpy(read,pch);
			//pch = strtok(NULL,",");	
			sprintf(itemStr,"%s%s%s",textColor,measTab,read);
			InsertListItem(MainPanelHandle, gReportList[threadNum - 1],-1,itemStr,0); 
			pch = strtok(NULL,",");
		}
		
	}
	else if (strstr(mtgTestStepInfo[threadNum-1][testNumber-1].testFuncName,"VerifyNBMailboxPoints") != NULL)  
	{
		while (pch != NULL)
		{
			strcpy(read,pch);
			//pch = strtok(NULL,",");	
			sprintf(itemStr,"%s%s%s",textColor,measTab,read);
			InsertListItem(MainPanelHandle, gReportList[threadNum - 1],-1,itemStr,0); 
			pch = strtok(NULL,",");
		}
	} //WritePointCsvValue
	else
	{ 
		// do nothing
	}
	
} // end InsertItemInReportList		

/********************************************************
*
* FUNCTION NAME: TestPassFailResult
* 
* DESCRIPTION:  display test data on the frmMain interface
*
*
* ARGUMENT LIST: 
* 
* ARGUMENT           TYPE     I/O    DESCRIPTION       
* --------           ----     ---    -----------
* totalNumbrofNests  int 	   I     total number of daughterboards per panel 
* totalNumbrofTests  int       I 	 total number of test in the test config
* 
* RETURNS: void
* 
* 
*********************************************************/
/********************************************//**
* display test data on the frmMain interface     
***********************************************/

void TestPassFailResult(int NestNum, int totalNumbrofTests)
{
	int i, testNumber;
	char tempTestResult[512];
	char tempError[1024];
	bool failFlag;

	failFlag= GLB_TRUE;	
	totalResult[NestNum] = GLB_FALSE;
	strcpy(logTestResults[NestNum],"");
	
	memset(tempTestResult,0,256);
	
	
	if (itacResult[NestNum] == 0)
	{
		for(i=0; i<totalNumbrofTests ; i++)
		{

			Scan (mtgTestStepInfo[NestNum][i].testNum, "%s>%d", &testNumber);
			sprintf(tempTestResult, "%s,", mtgTestStepInfo[NestNum][testNumber-1].testResult);
			strcat(logTestResults[NestNum], tempTestResult);

			if((!strcmp(mtgTestStepInfo[NestNum][i].testSkip, "N") || !strcmp(mtgTestStepInfo[NestNum][i].testSkip, "Y")) && failFlag)
			{

				if(!strcmp(mtgTestStepInfo[NestNum][testNumber - 1].testResult, "Fail"))
				{
					totalResult[NestNum] = GLB_FALSE;
					failFlag = GLB_FALSE;
					sprintf(tempError, "%s :%s :%s", mtgTestStepInfo[NestNum][i].testName, mtgTestStepInfo[NestNum][i].testNum, mtgTestStepInfo[NestNum][i].testNest);
				}
				else if(!strcmp(mtgTestStepInfo[NestNum][testNumber - 1].testResult, "Pass"))
				{
					totalResult[NestNum] = GLB_TRUE;
				}
				else if(!strcmp(mtgTestStepInfo[NestNum][testNumber - 1].testResult, "Skip"))
				{
					totalResult[NestNum] = 2;												    
				}
		
			}

		}
	}
	else
	{
		sprintf(tempTestResult, "ITAC fail code = %d,", itacResult[NestNum]);
		strcat(logTestResults[NestNum], tempTestResult);
		totalResult[NestNum] = 2;	
	}


}
//********************************************************************************************************************

// ============================================ Data File I/O Functions =================================================
// This function write the result of the tested module to the appropriate output file. if the file 
// is larger than 1/2Meg or the file date is different from the current date, the file will be archived. 
// This file is logged as a .csv (comma separated version), which can be viewed using an Excel worksheet. 
// the test legend and the date and time that this file was created will be displayed.
//void WriteTestResultsToFile (int result, double t_result[2][100], int nest)
//************************************************************************************************************************
/********************************************//**
* Write test result to file   
***********************************************/
 void WriteTestResultsToFile (int result, int nest, bool checkNewFile, double totalTestTime)
{
    int  i, i__ret, copy_status;
	long file_size;
	char tmpStr[2000];
	char str[100], file_date[100];
    char tempstr1[3], tempstr2[3], tempstr3[3], tempStr[1000];
    char res_path[MAX_PATHNAME_LEN], res_file[MAX_PATHNAME_LEN], file[MAX_PATHNAME_LEN];
    FILE *fp;
	char MIS[23];
    //GetMisNumber(nest,MIS);  
	strcpy (MIS,dutMIS[nest].SerialNumber);
    // create test result path and filename
    GetProjectDir(proj_dir);

	sprintf(res_file, "%s%s", proj_dir, "\\Log\\test results.csv"); 
	sprintf(res_path, "%s%s", proj_dir, "\\Log\\test results");
    strcpy(file, (test_mode == CAPABILITY) ? val_filename : res_file);
	
	if(checkNewFile)
	{
		i__ret = GetFileInfo (file, &file_size); // check for output file, file size and file date
		//-------------------------------------------------------------------------------------------------------------------------          
		if (i__ret)	 // proceed to archived existing data file
		{
			// get file_date
			int mm,dd,yy;
			GetFileDate (file, &mm, &dd, &yy);
			sprintf(file_date, "%02d-%02d-%02d", mm, dd, yy);
		
		  	if (strcmp(file_date, DateStr()) || file_size > DATA_SIZE)
		  	{	
				CopyString (tempstr1, 0, file_date, 0, 2);
	        	CopyString (tempstr2, 0, file_date, 3, 2);
	        	CopyString (tempstr3, 0, file_date, 8, 2);
        
	        	sprintf (str, "%s%s%s%s.csv", res_path, tempstr3, tempstr1, tempstr2);
	        	copy_status = CopyFile (file, str);
				sprintf(tempStr, "%d: %s: %s", copy_status, res_path, str);
        
	        	// if file copy was successful, delete existing file and ceate new file
	        	if (!copy_status)
	        	{	
					DeleteFile(file);
	          		new_file = GLB_TRUE;
	        	}  
	   	    	else
	   	    	{	MessagePopup ("FILE ERROR: Unable to archive file \n", file);
	          		return;
		    	}
		  	}
		  	else new_file=GLB_FALSE;
	    } 																		    
		else new_file = GLB_TRUE;
	}
	//-------------------------------------------------------------------------------------------------------------------------          
    if(VerifyOpenFileWrite(file, "a", &fp))
	{	// write header of new file which holds test results 
    	if (new_file)  // write file heading
    	{	
			fprintf(fp,",,,,,Name,");
			for (i=1; i<=testARRAY_SIZE; i++) 
			{
				strcpy(tmpStr,mtgTestStepInfo[0][i-1].testName);
				fprintf(fp,"%s,",replaceChar(tmpStr,',',' '));
			}
			fprintf(fp,"\n");
			fprintf(fp,",,,,,Procedure,");
			for (i=1; i<=testARRAY_SIZE; i++) 
			{
				fprintf(fp,"%s,",mtgTestStepInfo[0][i-1].testFuncName);   
			}
			fprintf(fp,"\n");
			/*
			fprintf(fp,",,,,,Prm1,");
			for (i=1; i<=testARRAY_SIZE; i++) 
			{
				strcpy(tmpStr,mtgTestStepInfo[0][i-1].testParam);
				fprintf(fp,"%s,",replaceChar(tmpStr,',',';'));
			}
			fprintf(fp,"\n");
			
			fprintf(fp,",,,,,Prm2,");
			for (i=1; i<=testARRAY_SIZE; i++) 
			{
				fprintf(fp,"%s,","");   
			}
			fprintf(fp,"\n");
			*/
			fprintf(fp,"Date,Time,Test Time,Nest,MIS#,Pass/Fail\n");
      		new_file = GLB_FALSE;
      	}   // end if
		
		// Write test data
		if (strlen(logTestResults[nest])>0)
		{
			fprintf(fp,"%s,",DateStr());
			fprintf(fp,"%s,",TimeStr());	// write current time stamp to file
			fprintf(fp,"%.1f,",totalTestTime);
			fprintf(fp,"%d,", nest+1);
			
			fprintf(fp,"%s,",MIS);    
    		fprintf(fp, (result==GLB_TRUE) ? "PASS," : "FAIL,");
    		strcpy(tmpStr,logTestResults[nest]);
    		fprintf(fp,replaceChar(tmpStr,'\n',' '));
    		fprintf(fp, "\n");    
		}
		
		// close file
    	if (fclose(fp) != 0)
    	{	
			MessagePopup ("FILE ERROR: Unable to close file \n", file);
      		return;
    	}
    } // end if	
    return;
}
//*******************************************************************************************************************

/********************************************//**
* Get MIS number 
***********************************************/
void GetMisNumber(int nest, char MIS[23])
{
	memset(MIS,0,23);
	int offset = 6;   // MIS = ;
	for (int i=0; i<NumOfTests; i++)   
	{
		if (stricmp(mtgTestStepInfo[nest][i].testFuncName,"Proceed_Request")==0)
		{
			for (int j=0; j<23; j++)
			{
				MIS[j]=mtgTestStepInfo[nest][i].testResultVal[j+offset];
			}
		}
	}
} // end GetMisNumber
