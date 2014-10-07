
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
*    @file    frmMain.c
*    @brief    MAIN file.
*    @author  Arxtron Technologies Inc.
*    @date    2013.9.6
*    Contains all the callback for the main frmMain.uir panel.
*    Initialization of the Main GUI and t
*/

#include <userint.h>
#include "Global.h"
#include "DataLib.h"
#include "frmMain.h"
#include "excel2000.h"
#include "excelreport.h"
#include "Nb_Test.h"
#include "NiCanWrp.h"
#include "nblib.h"
#include "Password.h"
#include <string.h>
#include "Shift_Configuration.h"
#include "Shift_Configuration_Def.h"
#include "MainDef.h"
#include "frmError.h"
#include "TextUtils.h"
#include "TestSteps.h"
#include "parallel_LIB.h"
#include "YieldData.h"
#include "timeUtils.h"
#include "CANCommand.h"
#include "Measurements.h"
#include "MIO6220.h"
#include "MIO6220Def.h"
#include "MIOUtils.h"
#include "MIOUtilsDef.h"
#include "app_log.h"
#include "test_output_log.h"
#include "PartSelect_DEF.h"

#include "frmINIT.h"
#include "itacLayer_LIB.h"
#include "ParseCSV.h"
#include "AirPressurePanel.h"

#define	USEDATAACQ
#ifdef USEDATAACQ
#endif


#define	USESERIALPORT
#ifdef USESERIALPORT
#endif

#define	USETIMER
#ifdef USETIMER
#endif


#define	USEDUTMEMORY
#ifdef USEDUTMEMORY
	#include "DutMemory.h"
	#include "DutMemory_Def.h"
#endif

#define	USESSYSCONFIG
#ifdef USESSYSCONFIG
	#include "SystemConfiguration.h"
	#include "SystemConfiguration_Def.h"
#endif

#define	USESPSMODULE
#ifdef USESPSMODULE
	#include "PartSelect.h"
#endif

#define	USESTSTCONFIG
#ifdef USESTSTCONFIG
	#include "TestConfiguration.h"
	#include "TestConfiguration_Def.h"
#endif
#define	USESCAPMODULE
#ifdef USESCAPMODULE
	#include "frmCapabilityMode.h"
#endif

#define	USESDIO6515CCONFIG
#ifdef USESDIO6515CCONFIG
	#include "DIO6515Def.h"
	#include "DIO6515.h"
#endif

#define	USESDIO6515UUTILS
#ifdef USESDIO6515UUTILS
#include "DIO6515UtilsDef.h"
#include "DIO6515Utils.h"
#endif


#define	USESMIO6220CCONFIG
#ifdef USESMIO6220CCONFIG
	#include "MIO6220Def.h"
	#include "MIO6220.h"
#endif

#define	USESMIO6220UUTILS
#ifdef USESMIO6220UUTILS
#include "MIOUtilsDef.h"
#include "MIOUtils.h"
#endif

int failChuteCnt=0;
static int toggleBit=0;
char DLLrev[20];

void RejectBinFullErrorMessage(void);
void FxtLockErrorMessage(void);


//********************************************************************************************************************
int main (int argc, char *argv[])
{
	char dir[MAX_PATHNAME_LEN], uirPath[MAX_PATHNAME_LEN];

	if (InitCVIRTE (0, argv, 0) == 0)
		return -1;	/* out of memory */
	GetProjectDir(dir);
	sprintf(uirPath, "%s%s", dir,"\\UserInterface\\frmMain.uir");

	if ((MainPanelHandle = LoadPanel (0, uirPath, Main)) < 0)

		return -1;
	MAIN_menuHandle = LoadMenuBar (MainPanelHandle, uirPath, Main);

	DisplayPanel (MainPanelHandle);

	InitMain();
	
	RunUserInterface ();
	DiscardPanel (MainPanelHandle);

	
	
	return 0;
}

/********************************************//**
 *  Initialize Main GUI
 ***********************************************/
//********************************************************************************************************************
int InitMain(void)
{
	char dir[MAX_PATHNAME_LEN], uirPath[MAX_PATHNAME_LEN], strTemp[100], strTempTimeOut[10], totalNestStr[100], tempNestNum[100];
	char MIO6220DeviceNum1Str[100], DIO6515DeviceNum1Str[100], DIO6515DeviceNum2Str[100];
	int passwordTimeoutNum=0, i, j;
	CVIXMLElement rootElement;

    Initialize_NbLib ();
	Initialize_NiCanWrp ();
	Initialize_NbTest ();
				//	Flag_Password_Protect=1;
	InitInterfaces (); 
    strcpy(DLLrev,Get_Dll_Version ());
	
	
	////////////////////////////////////////////////////////////////
	// Load MAIN gui configuration
	////////////////////////////////////////////////////////////////
	GetProjectDir(dir);

	LoadEditPasswordPanel(EP_PNL);

	#ifdef USEDUTMEMORY
		sprintf(uirPath, "%s%s", dir,"\\UserInterface\\DutMemory.uir");
		DutMemoryPanelHandle = LoadPanel(0,uirPath,MEM_PNL);
	#endif

	#ifdef USESSYSCONFIG
		LoadSystemConfiguration(SYSCFG_PNL);
	#endif

	LoadShiftConfig(SHIFT_PNL);

	#ifdef	USESPSMODULE
		LoadPartSelectModule(PS_PNL);
	#endif

	GetShiftCofigDirectory();
	InitShiftConfiguration();

	#ifdef USESSPCFG
		   LoadSPConfig(SPCFG_PNL);
	#endif

	#ifdef USESSPUTIL
		   LoadSPUtils(SPUTL_PNL);
	#endif

//============================================================================================================
	sprintf(uirPath, "%s%s", dir,"\\Configuration\\gMiscellaneous.xml");
	rootElement = LoadConfigurationDocument(uirPath);
	ParseXMLDocument(rootElement, 0);

	////////////////////////////////////////////////////////////////
	// Load test step parameter from csv base on partnumber
	////////////////////////////////////////////////////////////////
	//sprintf(uirPath, "%s%s", dir,"\\Configuration\\NB_Test_Prameters_updating.csv");  


	sprintf(uirPath, "%s%s", dir,"\\Configuration\\ALevel.xml");
	rootElement = LoadConfigurationDocument(uirPath);
	ParseXMLDocument(rootElement,0);
	
	pwd_status=VERIFY;
	StringUpperCase(Password.Level1);
	StringUpperCase(Password.Level2);
	
	strcpy (access_level1, Password.Level1);	
	strcpy (access_level2, Password.Level2);	
	pwd_location = CONFIG_MODE;		

	// load Recipe data from database & display part select window.
	PartSelectPanelHandle=0;
	LoadPartSelectModule(PS_PNL);
	if(loadTableFromDatabase(GetCfgMiscValue("DatabaseDSN",80),GetCfgMiscValue("DatabaseUserID",80),GetCfgMiscValue("DatabasePassword",80)))
	{
		sprintf(strTemp, "Unable to access database \"%s\".\n"
						 "Check Data Sources in Adminstrative tools in the control panel", GetCfgMiscValue("DatabaseDSN",80));
		MessagePopup("Database Error", strTemp);
		//DisplayPanel(ApplicationPanelHandle);
		//UpdateAppConfigurationTable(ApplicationPanelHandle);
		PartSelectPanelHandle=0;  
	}
	else
	{
		DisplayPanel (PartSelectPanelHandle);
		while (PartSelectPanelHandle != 0)  // This is bad becuase we don't know when PartSelectPanelHandle is initialized
			NonBlockDelay(0.05);			// Clearly this is a global.  PS
	}

	// load initialize system configuration values
	InitializeCfgMiscValue();
	
	
	


	
	
//============================================================================================================

	#ifdef USESTSTCONFIG
		LoadTestConfig(TSTCFG_PNL);
	#endif

	#ifdef USESCAPMODULE
		LoadCapabilityInterface(CAP_PNL);
	#endif
	LoadErrorInterface(ERR_PNL);
	LoadINITInterface(INIT_PNL);


	////////////////////////////////////////////////////////////////
	// Load test step parameter
	////////////////////////////////////////////////////////////////
	InitTestStepParamHeader();
	InitTestStepParam();
	if(totalNest > 0)
	{
		for(i=0; i<totalNest; i++)		  // AA (i=0; i<totalNest; i++) 
		{
			totalResult[i] = GLB_TRUE;
			for(j=0;j<testARRAY_SIZE;j++)  // Why do we need anoter copy of this info?  PS
			{
				strcpy(mtgTestStepInfo[i][j].testNum          	 	 , gTestStepInfo[j].testNum);
				strcpy(mtgTestStepInfo[i][j].testName       		 , gTestStepInfo[j].testName);
				strcpy(mtgTestStepInfo[i][j].testFuncName	 	 	 , gTestStepInfo[j].testFuncName);
				strcpy(mtgTestStepInfo[i][j].testSkip       		 , gTestStepInfo[j].testSkip);
				strcpy(mtgTestStepInfo[i][j].testAbort       		 , gTestStepInfo[j].testAbort);
				strcpy(mtgTestStepInfo[i][j].testParam      		 , gTestStepInfo[j].testParam);
				strcpy(mtgTestStepInfo[i][j].testType       		 , gTestStepInfo[j].testType);
				strcpy(mtgTestStepInfo[i][j].testRepeat     		 , gTestStepInfo[j].testRepeat);
				sprintf(tempNestNum, "%d", i+1);
				strcpy(mtgTestStepInfo[i][j].testNest       		 , tempNestNum);
				strcpy(mtgTestStepInfo[i][j].testResult     		 , "");
				strcpy(mtgTestStepInfo[i][j].testResultVal		     , "");
			}
		}
	}

		
	strcpy(DIO6515DeviceNum1Str, GetCfgMiscValue("DIO6515DeviceNum1",80));
	Scan (DIO6515DeviceNum1Str, "%s>%d", &DIO6515DeviceNum1);

	strcpy(DIO6515DeviceNum2Str, GetCfgMiscValue("DIO6515DeviceNum2",80));
	Scan (DIO6515DeviceNum2Str, "%s>%d", &DIO6515DeviceNum2);

	#ifdef USESDIO6515CCONFIG
		sprintf(uirPath, "%s%s", dir,"\\UserInterface\\DIO6515.uir");
		if ((DIO6515ConfigPanelHandle = LoadPanel (0, uirPath, DIO_PNL)) < 0)
			return -1;
		
		sprintf(uirPath, "%s%s", dir,"\\Configuration\\DIO6515Definition.xml");
		rootElement = LoadConfigurationDocument(uirPath);
		ParseXMLDocument(rootElement, DIO6515DeviceNum1);

		sprintf(uirPath, "%s%s", dir,"\\Configuration\\DIO6515Definition2.xml");
		rootElement = LoadConfigurationDocument(uirPath);
		ParseXMLDocument(rootElement, DIO6515DeviceNum2);
	#endif

	#ifdef USESDIO6515UUTILS
		sprintf(uirPath, "%s%s", dir,"\\UserInterface\\DIO6515Utils.uir");
		if ((DIO6515UtilsPanelHandle = LoadPanel (0, uirPath, DIO6515PNL)) < 0)
			return -1;

		InitDIOInterface6515(DIO6515DeviceNum1);
		InitDIOInterface6515(DIO6515DeviceNum2);
		
     WriteOutput6515("CTRL_POWER_24V", 1, DIO6515DeviceNum1); 
	resetTestStation();
	for (int i=0;i<6;i++)
	{
		setDutIndicators (i, 0, 0, 0);  
	}	

	#endif

	////////////////////////////////////////////////////////////////
	// Fixture ID
	////////////////////////////////////////////////////////////////
    char tempErrStr[512];
	char customerType[100]={0};
	NonBlockDelay(4);
	strcpy(customerType,getProductType(selRecipe.Variant));
	while (strcmp(getFixtureName(getFixtureId()),customerType))
	{
		sprintf(tempErrStr, "Product is %s, Fixture is for %s \n",customerType,getFixtureName(getFixtureId())); //
		ProcessSystemEvents();
		MessagePopup("Fixture ID error",tempErrStr);
		NonBlockDelay(2);

	}
 

	 
	#ifdef USESSPCFG
		sprintf(uirPath, "%s%s", dir,"\\Configuration\\SerialPorts.xml");
		rootElement = LoadConfigurationDocument(uirPath);
		ParseXMLDocument(rootElement, 0);
	#endif

	pwd_status=VERIFY;
	StringUpperCase(Password.Level1);
	StringUpperCase(Password.Level2);

	strcpy (access_level1, Password.Level1);
	strcpy (access_level2, Password.Level2);
	pwd_location = CONFIG_MODE;

	#ifdef USEDATAACQ
	#endif

	sprintf(uirPath, "%s%s", dir,"\\UserInterface\\MIO6220.uir");
	if ((MIOPanelHandle = LoadPanel (0, uirPath, MIO_PNL)) < 0)
		return -1;
		
	sprintf(uirPath, "%s%s", dir,"\\UserInterface\\MIOUtils.uir");
	if ((MIOUtilsPanelHandle = LoadPanel (0, uirPath, MIOUTL_PNL)) < 0)
		return -1;
		
	strcpy(MIO6220DeviceNum1Str, GetCfgMiscValue("MIO6220DeviceNum1",80));
	Scan (MIO6220DeviceNum1Str, "%s>%d", &MIO6220DeviceNum1);
	
	sprintf(uirPath, "%s%s", dir,"\\Configuration\\MIODIODefinition.xml");
	rootElement = LoadConfigurationDocument(uirPath);
	ParseXMLDocument(rootElement, MIO6220DeviceNum1);

	sprintf(uirPath, "%s%s", dir,"\\Configuration\\MIOAIDefinition.xml");
	rootElement = LoadConfigurationDocument(uirPath);
	ParseXMLDocument(rootElement, MIO6220DeviceNum1);

	sprintf(uirPath, "%s%s", dir,"\\Configuration\\MIOAODefinition.xml");
	rootElement = LoadConfigurationDocument(uirPath);
	ParseXMLDocument(rootElement, MIO6220DeviceNum1);

	InitMDIOInterface(MIO6220DeviceNum1, 3, 2);		// MIO Interface Initialization 0 for First Device 1, 2, 3... for more DIO Devices
	InitializeMIOAnalogInput(MIO6220DeviceNum1, 16, MIO6220DeviceNum1, DAQmx_Val_Diff);
	InitializeMIOAnalogOutput(MIO6220DeviceNum1, 0);

	SystemFileHandler = CreatFile("SystemLog",	"log", 1, 0);

	////////////////////////////////////////////////////////////////
	// Initialize test configuration create GUI dynamic controls
	////////////////////////////////////////////////////////////////
	CreateAllDynamicControls();
	TestInitialization(); //AA  

	CreateMainConfigurationTable();
	InitMainTable();

	BuildTestSequence();
	NumOfTests = getTestCount();

	SetCtrlAttribute (MainPanelHandle, Main_CLOCK_TIMER, ATTR_ENABLED, 1);

    strcpy(strTempTimeOut, GetCfgMiscValue("PasswordTimeout",80));
	Scan (strTempTimeOut, "%s>%d", &passwordTimeoutNum);
	PasswordTimeInterval = passwordTimeoutNum;

	CreateTestResultDynamicControls();  
	InitializeCycleCount();

	resetTestStation();
	NonBlockDelay(5);
	SetCtrlAttribute (MainPanelHandle, Main_CLOCK_TIMER, ATTR_ENABLED, 1);
	SetCtrlAttribute (MainPanelHandle, Main_ESTOP_TIMER, ATTR_ENABLED, 1);
	SetCtrlAttribute (MainPanelHandle, Main_PASSWORDTIMER, ATTR_ENABLED, 1);
	SetCtrlAttribute (MainPanelHandle, Main_START_TIMER, ATTR_ENABLED, 1); 
	
	

	WriteTestResultsToFile(totalResult[0],0,GLB_TRUE,0.0);  

	return 0;
}


//********************************************************************************************************************
/********************************************//**
*  create dynamic panel GUI objects
***********************************************/
void CreateAllDynamicControls(void)
{
	// Create Test Yield GUI controls
	int backgroundColor = 0x00e8e4d9;//0x00E8E4D9;//0x00E0E0E0;

	// MAIN_DECO_CONTROL1=LIB_CreateDecorationControl(MainPanelHandle, APP_MAIN_NAME,
	// 									       30, 130, /***Decoration_2_Left+Decoration_2_Width+10***/500+5, 150,"Short Term");
	/***Decoration_2_Left+Decoration_2_Width+10***/
	MAIN_DECO_CONTROL1=LIB_CreateDecorationControl(MainPanelHandle, APP_MAIN_NAME, 30, 130, 505, 150,"Short Term");
 	SetCtrlAttribute (MainPanelHandle, MAIN_DECO_CONTROL1, ATTR_FRAME_COLOR , backgroundColor);
	GetCtrlAttribute (MainPanelHandle, MAIN_DECO_CONTROL1, ATTR_LEFT, &Decoration_1_Left);
	GetCtrlAttribute (MainPanelHandle, MAIN_DECO_CONTROL1, ATTR_TOP, &Decoration_1_Top);
	GetCtrlAttribute (MainPanelHandle, MAIN_DECO_CONTROL1, ATTR_WIDTH, &Decoration_1_Width);
	GetCtrlAttribute (MainPanelHandle, MAIN_DECO_CONTROL1, ATTR_HEIGHT, &Decoration_1_Height);


	MAIN_DECO_CONTROL2=LIB_CreateDecorationControl(MainPanelHandle, APP_MAIN_NAME, 30, 130, 5, 500, "TEST PROGRAM INFO");
 	SetCtrlAttribute (MainPanelHandle, MAIN_DECO_CONTROL2, ATTR_FRAME_COLOR , backgroundColor);
	GetCtrlAttribute (MainPanelHandle, MAIN_DECO_CONTROL2, ATTR_LEFT,  &Decoration_2_Left);
	GetCtrlAttribute (MainPanelHandle, MAIN_DECO_CONTROL2, ATTR_TOP,  &Decoration_2_Top);
	GetCtrlAttribute (MainPanelHandle, MAIN_DECO_CONTROL2, ATTR_WIDTH, &Decoration_2_Width);
	GetCtrlAttribute (MainPanelHandle, MAIN_DECO_CONTROL2, ATTR_HEIGHT, &Decoration_2_Height);

    /***Decoration_2_Left+Decoration_2_Width+10***/
	MAIN_DECO_CONTROL3=LIB_CreateDecorationControl(MainPanelHandle, APP_MAIN_NAME, 30, 130, 655, 150,"Long Term");
  	SetCtrlAttribute (MainPanelHandle, MAIN_DECO_CONTROL3, ATTR_FRAME_COLOR , backgroundColor);
	GetCtrlAttribute (MainPanelHandle, MAIN_DECO_CONTROL3, ATTR_LEFT, &Decoration_3_Left);
	GetCtrlAttribute (MainPanelHandle, MAIN_DECO_CONTROL3, ATTR_TOP,  &Decoration_3_Top);
	GetCtrlAttribute (MainPanelHandle, MAIN_DECO_CONTROL3, ATTR_WIDTH, &Decoration_3_Width);
	GetCtrlAttribute (MainPanelHandle, MAIN_DECO_CONTROL3, ATTR_HEIGHT, &Decoration_3_Height);

/* 																		*/
/* Create object on fmrMain.uir											*/
/*                                                                      */
	MAIN_TEST_PASS=LIB_CreateNumericalControl(MainPanelHandle, APP_MAIN_NAME, "",
									   	   	   Decoration_1_Top+20, Decoration_1_Left+20, 50,0, "Pass",60,0,0,100000, VAL_BLACK,
									   	   	   VAL_GREEN, 14, VAL_CENTER_JUSTIFIED, VAL_BLACK,VAL_INDICATOR, 14,2,1);
	MAIN_TEST_FAIL=LIB_CreateNumericalControl(MainPanelHandle, APP_MAIN_NAME, "",
									   	   	   Decoration_1_Top+48, Decoration_1_Left+20, 50,0, "Fail",60,0,0,100000, VAL_BLACK,
									   	   	   VAL_RED, 14, VAL_CENTER_JUSTIFIED, VAL_BLACK,VAL_INDICATOR, 14,2,1);
	MAIN_TEST_YIELD=LIB_CreateNumericalControl(MainPanelHandle, APP_MAIN_NAME, "",
									   	   	   Decoration_1_Top+76, Decoration_1_Left+20, 50,1, "Yield(%)",60,0,0,100000, VAL_BLACK,
									   	   	   VAL_OFFWHITE, 14, VAL_CENTER_JUSTIFIED, VAL_BLACK,VAL_INDICATOR, 14,2,1);

	HISTO_TEST_PASS=LIB_CreateNumericalControl(MainPanelHandle, APP_MAIN_NAME, "",
									   	   	   Decoration_3_Top+20, Decoration_3_Left+20, 50,0, "Pass",60,0,0,100000, VAL_BLACK,
									   	   	   VAL_GREEN, 14, VAL_CENTER_JUSTIFIED, VAL_BLACK,VAL_INDICATOR, 14,2,1);
	HISTO_TEST_FAIL=LIB_CreateNumericalControl(MainPanelHandle, APP_MAIN_NAME, "",
									   	   	   Decoration_3_Top+48, Decoration_3_Left+20, 50,0, "Fail",60,0,0,100000, VAL_BLACK,
									   	   	   VAL_RED, 14, VAL_CENTER_JUSTIFIED, VAL_BLACK,VAL_INDICATOR, 14,2,1);
	HISTO_TEST_YIELD=LIB_CreateNumericalControl(MainPanelHandle, APP_MAIN_NAME, "",
									   	   	   Decoration_3_Top+76, Decoration_3_Left+20, 50,1, "Yield(%)",60,0,0,100000, VAL_BLACK,
									   	   	   VAL_OFFWHITE, 14, VAL_CENTER_JUSTIFIED, VAL_BLACK,VAL_INDICATOR, 14,2,1);

    HISTO_CLEAR_DATE=LIB_CreateTextMesage(MainPanelHandle, APP_MAIN_NAME, Decoration_1_Top+104, Decoration_3_Left+5, "", 140, 15, 0);


	// Create ITAC and Reject Bin GUI status
	MAIN_IDLE_TIME= LIB_CreateEditControl(MainPanelHandle, APP_MAIN_NAME, 1, Decoration_1_Top+70, 20, 70, 70, Decoration_1_Left+350, 
											"IDLE TIME", "00:00:00", VAL_BLUE, VAL_WHITE, 14,VAL_CENTER_JUSTIFIED, VAL_BLACK);

	itacStatusLed = NewCtrl (MainPanelHandle, CTRL_ROUND_LED_LS, "ITAC Status", 70, 1053);
	SetCtrlAttribute (MainPanelHandle, itacStatusLed, ATTR_LABEL_LEFT, 1045);
	SetCtrlAttribute (MainPanelHandle, itacStatusLed, ATTR_LABEL_BOLD, 1);
	SetCtrlAttribute (MainPanelHandle, itacStatusLed, ATTR_HEIGHT , 50);
	SetCtrlAttribute (MainPanelHandle, itacStatusLed, ATTR_WIDTH  , 50);
	SetCtrlAttribute (MainPanelHandle, itacStatusLed, ATTR_ON_COLOR, VAL_GREEN);

	rejectBinLed = NewCtrl (MainPanelHandle, CTRL_ROUND_LED_LS, "Reject Bin Full", 70, 1153);
	SetCtrlAttribute (MainPanelHandle, rejectBinLed, ATTR_LABEL_LEFT, 1140);
	SetCtrlAttribute (MainPanelHandle, rejectBinLed, ATTR_LABEL_BOLD, 1);
	SetCtrlAttribute (MainPanelHandle, rejectBinLed, ATTR_HEIGHT , 50);
	SetCtrlAttribute (MainPanelHandle, rejectBinLed, ATTR_WIDTH  , 50);
	SetCtrlAttribute (MainPanelHandle, rejectBinLed, ATTR_ON_COLOR, VAL_RED);
}

//**********************************************************************************************************************************************
//Function:		CreateTestResultDynamicControls
//
//Description:	Create Test Result Dynamic controls
//
//
//Parameters:
//Inputs:     	None
//
//Outputs     	None
//**********************************************************************************************************************************************
/********************************************//**
*  Create the list box for each daughterboards to display the test status
***********************************************/
void CreateTestResultDynamicControls(void)
{
	int base=565, height=325,  size=1800/totalNest, inc= size+15,  fontSize=35, x_offset=10;
	int backgroundColor = 0x00e8e4d9;//0x00E0E0E0;;
	char tmpMsg[100];

	for (int i = 0; i< totalNest; i++)
	{
		//box frame for each unit
		sprintf(tmpMsg,"#%d",i+1);
		gBoxDeco[i]=LIB_CreateDecorationControl(MainPanelHandle, APP_MAIN_NAME, base-400, base+height-50, x_offset-5, size+15,"");
		SetCtrlAttribute (MainPanelHandle, gBoxDeco[i], ATTR_FRAME_COLOR , backgroundColor);

		// Device ID
    	gBoxId[i]=LIB_CreateTextMesage(MainPanelHandle, APP_MAIN_NAME, base-400, x_offset, tmpMsg, size/6, 30, 1);
		SetCtrlAttribute (MainPanelHandle, gBoxId[i], ATTR_TEXT_POINT_SIZE , 25);

		//list box for test step status display
		gStepList[i]=LIB_CreateListCtrl(MainPanelHandle, APP_MAIN_NAME, "CreateListCtrlCB",
						   						       base-285, x_offset, size, "TEST STATUS",1, 225, 0, VAL_INDICATOR, 1);
    	gStepLabel[i]=LIB_CreateTextMesage(MainPanelHandle, APP_MAIN_NAME, base-310, x_offset, "T#      Description                         Time(s)", size, 20, 0);
		SetCtrlAttribute (MainPanelHandle, gStepLabel[i], ATTR_TEXT_JUSTIFY, VAL_LEFT_JUSTIFIED);
		SetCtrlAttribute (MainPanelHandle, gStepLabel[i], ATTR_TEXT_BGCOLOR , backgroundColor);
		SetCtrlAttribute (MainPanelHandle, gStepLabel[i], ATTR_TEXT_POINT_SIZE , 15);
		SetCtrlAttribute (MainPanelHandle, gStepLabel[i], ATTR_TEXT_COLOR , VAL_BLACK);

		//list box for test result display
		gReportList[i]=LIB_CreateListCtrl(MainPanelHandle, APP_MAIN_NAME, "CreateListCtrlCB",
						   						       base+10, x_offset, size, "TEST RESULT",1, 190, 0, VAL_INDICATOR, 1);
    	gReportLabel[i]=LIB_CreateTextMesage(MainPanelHandle, APP_MAIN_NAME, base-20, x_offset, "Test Measurements                                             Low Limit    High Limit", size, 20, 0);
		SetCtrlAttribute (MainPanelHandle, gReportLabel[i], ATTR_TEXT_JUSTIFY, VAL_LEFT_JUSTIFIED);
		SetCtrlAttribute (MainPanelHandle, gReportLabel[i], ATTR_TEXT_BGCOLOR , backgroundColor);
		SetCtrlAttribute (MainPanelHandle, gReportLabel[i], ATTR_TEXT_POINT_SIZE , 15);
		SetCtrlAttribute (MainPanelHandle, gReportLabel[i], ATTR_TEXT_COLOR , VAL_BLACK);

		//test status result box message
    	gBoxMsg[i]=LIB_CreateTextMesage(MainPanelHandle, APP_MAIN_NAME, base+200+30, x_offset, "WAITING...", size, 45, 1);
		SetCtrlAttribute (MainPanelHandle, gBoxMsg[i], ATTR_TEXT_BGCOLOR , VAL_BLUE);
		SetCtrlAttribute (MainPanelHandle, gBoxMsg[i], ATTR_TEXT_POINT_SIZE , fontSize);

		//test status result box message
    	gBoxTxt[i]=LIB_CreateTextMesage(MainPanelHandle, APP_MAIN_NAME, base+200+75, x_offset, "Place Unit\n to start testing", size, 90, 0);
		SetCtrlAttribute (MainPanelHandle, gBoxTxt[i], ATTR_TEXT_BGCOLOR , backgroundColor);
		SetCtrlAttribute (MainPanelHandle, gBoxTxt[i], ATTR_TEXT_COLOR , VAL_BLACK);
		SetCtrlAttribute (MainPanelHandle, gBoxTxt[i], ATTR_TEXT_POINT_SIZE , fontSize);

		//Presence LED
    	gPresenceLed[i] = NewCtrl (MainPanelHandle, CTRL_SQUARE_LED_LS, "Presence", base-375, x_offset+100);
		SetCtrlAttribute (MainPanelHandle, gPresenceLed[i], ATTR_LABEL_BOLD, 1);
		SetCtrlAttribute (MainPanelHandle, gPresenceLed[i], ATTR_ON_COLOR, VAL_GREEN);

		//Position LED
		gPositionLed[i] = NewCtrl (MainPanelHandle, CTRL_SQUARE_LED_LS, "In Position", base-375, x_offset+200);
		SetCtrlAttribute (MainPanelHandle, gPositionLed[i], ATTR_LABEL_BOLD, 1);
		SetCtrlAttribute (MainPanelHandle, gPositionLed[i], ATTR_ON_COLOR, VAL_GREEN);

		//test time of a measurement cycle
		gTestTime[i] = NewCtrl(MainPanelHandle,CTRL_NUMERIC,"Time(s)",base-330,x_offset+40);
		SetCtrlAttribute(MainPanelHandle,gTestTime[i],ATTR_SHOW_INCDEC_ARROWS,0);
		SetCtrlAttribute(MainPanelHandle,gTestTime[i],ATTR_LABEL_LEFT,x_offset+40);
		SetCtrlAttribute(MainPanelHandle,gTestTime[i],ATTR_LABEL_TOP,base-350); 
		SetCtrlAttribute(MainPanelHandle,gTestTime[i],ATTR_LABEL_BOLD,1);  
		SetCtrlAttribute(MainPanelHandle,gTestTime[i],ATTR_WIDTH,60);
		SetCtrlAttribute(MainPanelHandle,gTestTime[i],ATTR_CTRL_MODE,VAL_INDICATOR); 
		SetCtrlAttribute(MainPanelHandle,gTestTime[i],ATTR_DFLT_VALUE,0.0); 
		SetCtrlAttribute(MainPanelHandle,gTestTime[i],ATTR_PRECISION,1);
		SetCtrlAttribute(MainPanelHandle,gTestTime[i],ATTR_TEXT_BOLD,1); 
		SetCtrlAttribute(MainPanelHandle,gTestTime[i],ATTR_TEXT_JUSTIFY,VAL_CENTER_JUSTIFIED); 
		SetCtrlAttribute(MainPanelHandle,gTestTime[i],ATTR_TEXT_BGCOLOR,VAL_WHITE); 
		
		// ITAC CNT of number of ITAC connection attempts
		gItacCount[i] = NewCtrl (MainPanelHandle, CTRL_TEXT_BOX_LS, "ITAC CNT", base-330, x_offset+120);
		SetCtrlAttribute (MainPanelHandle, gItacCount[i], ATTR_LABEL_BOLD, 1); 
		SetCtrlAttribute (MainPanelHandle, gItacCount[i], ATTR_LABEL_LEFT  , x_offset+120);   
		SetCtrlAttribute (MainPanelHandle, gItacCount[i], ATTR_LEFT   , x_offset+120);   
		SetCtrlAttribute (MainPanelHandle, gItacCount[i], ATTR_HEIGHT  , 25);
		SetCtrlAttribute (MainPanelHandle, gItacCount[i], ATTR_WIDTH   , 60);  
		SetCtrlAttribute (MainPanelHandle, gItacCount[i], ATTR_TEXT_BGCOLOR  , VAL_WHITE);
		SetCtrlAttribute (MainPanelHandle, gItacCount[i], ATTR_TEXT_COLOR  , VAL_BLACK);   
		SetCtrlAttribute (MainPanelHandle, gItacCount[i], ATTR_TEXT_JUSTIFY  , VAL_CENTER_JUSTIFIED);
		SetCtrlVal		 (MainPanelHandle, gItacCount[i], "0"); 
		
		//cycle CNT of number of measurements performed using the test unit
		gCycleCount[i] = NewCtrl (MainPanelHandle, CTRL_TEXT_BOX_LS, "Cycle CNT", base-330, x_offset+200);
		SetCtrlAttribute (MainPanelHandle, gCycleCount[i], ATTR_LABEL_BOLD, 1); 
		SetCtrlAttribute (MainPanelHandle, gCycleCount[i], ATTR_LABEL_LEFT  , x_offset+200);   
		SetCtrlAttribute (MainPanelHandle, gCycleCount[i], ATTR_LEFT   , x_offset+200);   
		SetCtrlAttribute (MainPanelHandle, gCycleCount[i], ATTR_HEIGHT  , 25);
		SetCtrlAttribute (MainPanelHandle, gCycleCount[i], ATTR_WIDTH   , 60);  
		SetCtrlAttribute (MainPanelHandle, gCycleCount[i], ATTR_TEXT_BGCOLOR  , VAL_WHITE);
		SetCtrlAttribute (MainPanelHandle, gCycleCount[i], ATTR_TEXT_COLOR  , VAL_BLACK);   
		SetCtrlAttribute (MainPanelHandle, gCycleCount[i], ATTR_TEXT_JUSTIFY  , VAL_CENTER_JUSTIFIED);
		SetCtrlVal	     (MainPanelHandle, gCycleCount[i], "0"); 

		x_offset = x_offset + inc;
	}
	// Set panel position on top left coner.
	SetPanelPos(MainPanelHandle,40,20);
}

//*******************************************************************************************************************
/********************************************//**
* expanding the test measurement results list  What a horrible name!
***********************************************/
int CVICALLBACK CreateListCtrlCB (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	static int gStepFlag[NUMOFNESTS]={TRUE, TRUE, TRUE, TRUE, TRUE, TRUE};
	static int gReportFlag[NUMOFNESTS]={TRUE, TRUE, TRUE, TRUE, TRUE, TRUE};
	static char gReportOrgLabel[NUMOFNESTS][120]={	{"Test Measurements"},{"Test Measurements"},{"Test Measurements"},{"Test Measurements"},{"Test Measurements"},
													{"Test Measurements"},{"Test Measurements"},{"Test Measurements"},{"Test Measurements"},{"Test Measurements"}};
	
	
	static gCtrlSize OrgSize[NUMOFNESTS], OrgSizeRpt[NUMOFNESTS];
	int base=565, size=1800/totalNest, inc=size+15, x_offset=10;

	char reportLabelVal[120];
	char reportLabelVal2[120] = {"  Low Limit    High Limit"};   // use second value because it can't overlap the previous text value

//	if (gReportLabel[0] > 0)
//	{
//		GetCtrlVal(MainPanelHandle,gReportLabel[0],reportLabelVal);
//	}

	switch (event)
	{
		case EVENT_LEFT_DOUBLE_CLICK:

			for (int i =0;i<totalNest;i++)
			{
				 if(control == gReportList[i])
				 {
					 if(gReportFlag[i])
					  {
						 OrgSizeRpt[i] = LibGetControlSize(MainPanelHandle, control);
						 LibSetControlSize(MainPanelHandle, control, OrgSizeRpt[i].top, x_offset, size*2+20, OrgSizeRpt[i].height, 0, 1);
						 if (i < (totalNest-1))
						 {

							GetCtrlVal(MainPanelHandle,gReportLabel[i+1],gReportOrgLabel[i+1]);
						 	SetCtrlVal(MainPanelHandle,gReportLabel[i+1],reportLabelVal2);
						 	SetCtrlAttribute(MainPanelHandle,gReportLabel[i],ATTR_WIDTH,size*2);

						 }
						 else
						 {
							GetCtrlVal(MainPanelHandle,gReportLabel[i],gReportOrgLabel[i]); 
							SetCtrlVal(MainPanelHandle,gReportLabel[i],reportLabelVal2);
							GetCtrlVal(MainPanelHandle,gReportLabel[i-1],gReportOrgLabel[i-1]);
							SetCtrlVal(MainPanelHandle,gReportLabel[i-1],gReportOrgLabel[i]);
							SetCtrlAttribute(MainPanelHandle,gReportLabel[i],ATTR_WIDTH,size*2);
						 }
					 	 gReportFlag[i]=FALSE;
					  }
					  else								   
					  {
						 LibSetControlSize(MainPanelHandle, control, OrgSizeRpt[i].top, OrgSizeRpt[i].left, OrgSizeRpt[i].width, OrgSizeRpt[i].height, 0, 0);
						 if (i < (totalNest-1))
						 {
						 	SetCtrlAttribute(MainPanelHandle,gReportLabel[i],ATTR_WIDTH,size);
							SetCtrlVal(MainPanelHandle,gReportLabel[i+1],gReportOrgLabel[i+1]); 

						 }
						 else
						 {
						 	SetCtrlVal(MainPanelHandle,gReportLabel[i],gReportOrgLabel[i]);
						 	SetCtrlVal(MainPanelHandle,gReportLabel[i-1],gReportOrgLabel[i-1]);
						 	SetCtrlAttribute(MainPanelHandle,gReportLabel[i],ATTR_WIDTH,size);
						 }
					     gReportFlag[i]=TRUE;
					  }
				 }

				// move back if x_offset move near the end last two nest
				if (i < (totalNest-2))
				{
		 			x_offset = x_offset + inc;
				}
			}  // end for loop
			break;
	}
	return 0;
}


//*******************************************************************************************************************
/********************************************//**
* Create the table which display the current configuration (recipe selected)
***********************************************/
void CreateMainConfigurationTable(void)
{
// -----------------------------------------------------------------------------------------------------------------------
	Ptr_MAIN_TableParameters=&MAIN_TableParameters;
	Ptr_MAIN_ColumnParameters=MAIN_ColumnParameters;

	MAIN_config_File_Exist=DATA_FALSE;
	if(MAIN_TableRowsandColumns.Num_of_Rows>0)
	{
		LIB_CreateTableParam(Ptr_MAIN_TableParameters,Decoration_2_Top+20,207,Decoration_2_Width-30,Decoration_2_Left+15,
							  10, MAIN_TableRowsandColumns.Num_of_Rows,0);

    	DYN_TABLE_MAIN=LIB_CreatTableControl(Ptr_MAIN_TableParameters, MainPanelHandle, "frmMain.c", DYN_TABLE_MAIN);
		SetCtrlAttribute (MainPanelHandle, DYN_TABLE_MAIN, ATTR_ROW_LABELS_VISIBLE,0);
		SetCtrlAttribute (MainPanelHandle, DYN_TABLE_MAIN, ATTR_COLUMN_LABELS_VISIBLE,0);
    	SetCtrlAttribute (MainPanelHandle, DYN_TABLE_MAIN,ATTR_SCROLL_BARS,VAL_NO_SCROLL_BARS);
    	NumberofTableRows=Ptr_MAIN_TableParameters->RowIndex;
    }
    else
    {
		LIB_CreateTableParam(Ptr_MAIN_TableParameters,Decoration_2_Top+20,105,Decoration_2_Width-30,Decoration_2_Left+15,
		                      10,MAIN_ROW_INDEX_CONSTANT,0);


    	DYN_TABLE_MAIN=LIB_CreatTableControl(Ptr_MAIN_TableParameters, MainPanelHandle,"frmMain.c", DYN_TABLE_MAIN);
		SetCtrlAttribute (MainPanelHandle, DYN_TABLE_MAIN, ATTR_ROW_LABELS_VISIBLE,0);
		SetCtrlAttribute (MainPanelHandle, DYN_TABLE_MAIN, ATTR_COLUMN_LABELS_VISIBLE,0);
    	SetCtrlAttribute (MainPanelHandle, DYN_TABLE_MAIN,ATTR_SCROLL_BARS,VAL_NO_SCROLL_BARS);
    	NumberofTableRows=Ptr_MAIN_TableParameters->RowIndex;
    }

//  CREATE TABLE COLUMN
	LIB_CreateTableColumnParam(Ptr_MAIN_ColumnParameters,0,-1,1,1,116,"",0);
	LIB_DYNInsertTableColumns(Ptr_MAIN_ColumnParameters, Ptr_MAIN_TableParameters, MainPanelHandle, APP_MAIN_NAME, DYN_TABLE_MAIN,1);//char
	LIB_CreateTableColumnParam(Ptr_MAIN_ColumnParameters,1,-1,2,1,116,"",0);
	LIB_DYNInsertTableColumns(Ptr_MAIN_ColumnParameters, Ptr_MAIN_TableParameters, MainPanelHandle, APP_MAIN_NAME, DYN_TABLE_MAIN,2); //char
	LIB_CreateTableColumnParam(Ptr_MAIN_ColumnParameters,2,-1,3,1,116,"",0);
	LIB_DYNInsertTableColumns(Ptr_MAIN_ColumnParameters, Ptr_MAIN_TableParameters, MainPanelHandle, APP_MAIN_NAME, DYN_TABLE_MAIN,3); //char
	LIB_CreateTableColumnParam(Ptr_MAIN_ColumnParameters,3,-1,4,1,116,"",0);
	LIB_DYNInsertTableColumns(Ptr_MAIN_ColumnParameters, Ptr_MAIN_TableParameters, MainPanelHandle, APP_MAIN_NAME, DYN_TABLE_MAIN,4);//char
}

//*******************************************************************************************************************
/********************************************//**
* Initialze the configuration table (top left of main panel)
***********************************************/
void InitMainTable(void)
{
	CreateMainConfigurationTable();
	SetTableCellVal(MainPanelHandle, DYN_TABLE_MAIN, MakePoint(1,1), " Date");
	SetTableCellVal(MainPanelHandle, DYN_TABLE_MAIN, MakePoint(1,2), " Time");
	SetTableCellVal(MainPanelHandle, DYN_TABLE_MAIN, MakePoint(1,3), " Product Type");
	SetTableCellVal(MainPanelHandle, DYN_TABLE_MAIN, MakePoint(1,4), " DLL rev");


	SetTableCellVal(MainPanelHandle, DYN_TABLE_MAIN, MakePoint(3,1), " Cal Recipe No.");
	SetTableCellVal(MainPanelHandle, DYN_TABLE_MAIN, MakePoint(3,2), " Variant");  
	SetTableCellVal(MainPanelHandle, DYN_TABLE_MAIN, MakePoint(3,3), " Flavor Id");
	SetTableCellVal(MainPanelHandle, DYN_TABLE_MAIN, MakePoint(3,4), " Program");
}

//********************************************************************************************************************
/********************************************//**
* handeling of file->exit
***********************************************/
void CVICALLBACK MAINMenuFileCB (int menuBar, int menuItem, void *callbackData,	int panel)
{
	switch (menuItem)
	{
		case MAIN_FILE_EXIT:
			if(ConfirmPopup("Close Application", "You have selected to Exit Application\n Press YES to Exit"))
			{
				estopFlag = 0; 
				CheckError(HidePanel(ErrorPanelHandle));
				ResetAndExit();
						
			}
			break;
		case 999:
			break;
		default:
			break;
	}
}

//********************************************************************************************************************
/********************************************//**
* Event from the edit menu
***********************************************/
void CVICALLBACK MAINEditMenuCB (int menuBar, int menuItem, void *callbackData, int panel)
{
//	if(Flag_Password_Protect && VerifyPassword(PD_PNL, PD_PNL_PW_MESSAGE, PD_PNL_PW_ENTER, VERIFY) == GLB_FAIL)
//		return;

	switch (menuItem)
	{
		case MAIN_EDIT_PW_VERIFY:
			if(!Flag_Password_Protect)
			{
				if(VerifyPassword(PD_PNL, PD_PNL_PW_MESSAGE, PD_PNL_PW_ENTER, VERIFY) == GLB_PASS)
				{
					strcpy(password,"");
					SetMenuBarAttribute (MAIN_menuHandle, MAIN_EDIT_PW_VERIFY, ATTR_ITEM_NAME,
									 "Enable Pass__word Request");
					PasswordTimerExpired=1;
					Flag_Password_Protect=1;
					PasswordProtectedMenu = GLB_TRUE;
				}
				else
				{
					SetMenuBarAttribute (MAIN_menuHandle, MAIN_EDIT_PW_VERIFY, ATTR_ITEM_NAME,
										 "Disable Pass__word Request");
					PasswordProtectedMenu = GLB_FALSE;
					PasswordTimerExpired=0;
					Flag_Password_Protect=0;
				}
			}
			else
			{
					SetMenuBarAttribute (MAIN_menuHandle, MAIN_EDIT_PW_VERIFY, ATTR_ITEM_NAME,
										 "Enable Pass__word Protected Menus");
					PasswordProtectedMenu = GLB_FALSE;
					PasswordTimerExpired=0;
					Flag_Password_Protect=0;
			}
		break;
		case MAIN_EDIT_EPW_VERIFY:
			 if(VerifyPassword(PD_PNL, PD_PNL_PW_MESSAGE, PD_PNL_PW_ENTER, VERIFY) == GLB_PASS)
			 {			
				SetCtrlVal (EditPasswordPanelHandle, EP_PNL_EPW_ENTER, "");
				DisplayPanel(EditPasswordPanelHandle);
			 }
			break;
			
		case MAIN_EDIT_SYSTEM_CONFIG:
			SysViewMenu =0;
            //PWD_KeyPress_Loc     = 0;
			
			#ifdef USESSYSCONFIG
				 if(!PasswordProtectedMenu)
				 {
				 	if(VerifyPassword(PD_PNL, PD_PNL_PW_MESSAGE, PD_PNL_PW_ENTER, VERIFY) == GLB_PASS) 
					 {			
						strcpy(password,"");
						EnableSystemControlSaving(1);
						DisplayPanel (SystemPanelHandle);
						CreateMiscConfigurationTable();
						DisplaySysControl(1);
					 }
					 else
					 {
						 strcpy(password,""); 
					 }
				 }
				 else
				 {
						strcpy(password,""); 
					 	EnableSystemControlSaving(1);
					 	DisplayPanel (SystemPanelHandle);
						CreateMiscConfigurationTable();
					 	DisplaySysControl(1);
				 }						
			#endif
			break;
		case MAIN_EDIT_TEST_CONFIG:
			SysViewMenu =0;
            PWD_KeyPress_Loc     = 0;
			
			#ifdef USESTSTCONFIG
				 if(!PasswordProtectedMenu)
				 {
				 	if(VerifyPassword(PD_PNL, PD_PNL_PW_MESSAGE, PD_PNL_PW_ENTER, VERIFY) == GLB_PASS) 
					 {			
						strcpy(password,"");
						CreategTestConfigurationTable();
						DisplayTstControl(1, 1);
						DisplayPanel (TestCfgPanelHandle);
					 }
					 else
					 {
						 strcpy(password,""); 
					 }
				 }
				 else
				 {
						strcpy(password,""); 
						CreategTestConfigurationTable();
						DisplayTstControl(1, 1);
					 	DisplayPanel (TestCfgPanelHandle);
				 }						
			#endif
			break;
		case MAIN_EDIT_DIO6515:
			DIOViewMenu =0;
			#ifdef USESDIO6515CCONFIG
				 if(!PasswordProtectedMenu)
				 {
					 if(VerifyPassword(PD_PNL, PD_PNL_PW_MESSAGE, PD_PNL_PW_ENTER, VERIFY) == GLB_PASS) 
					 {			
						CreateDigitalIO6515ConfigurationTable();
						CreateDigitalIO6515ConfigurationTable2();
						DisplayDIO6515Control(1, 1);
						DisplayPanel (DIO6515ConfigPanelHandle);
					 }
					 else
					 {
						 strcpy(password,""); 
					 }
				 }
				 else
				 {
						CreateDigitalIO6515ConfigurationTable();
						CreateDigitalIO6515ConfigurationTable2();
						DisplayDIO6515Control(1, 1);
						DisplayPanel (DIO6515ConfigPanelHandle);
				 }						
			#endif
			break;
		case MAIN_EDIT_MIO6220:
			DIOViewMenu =0;
			#ifdef USESMIO6220CCONFIG
				 if(!PasswordProtectedMenu)
				 {
					 if(VerifyPassword(PD_PNL, PD_PNL_PW_MESSAGE, PD_PNL_PW_ENTER, VERIFY) == GLB_PASS) 
					 {			
						CreateAnalogInputConfigurationTable();
						CreateAnalogOutputConfigurationTable();
						CreateMDigitalIOConfigurationTable();
						DisplayMIOControl(1, 1);
						DisplayPanel (MIOPanelHandle);
					 }
					 else
					 {
						 strcpy(password,""); 
					 }
				 }
				 else
				 {
						CreateAnalogInputConfigurationTable();
						CreateAnalogOutputConfigurationTable();
						CreateMDigitalIOConfigurationTable();
						DisplayMIOControl(1, 1);
						DisplayPanel (MIOPanelHandle);
				 }						
			#endif
			break;
		case MAIN_EDIT_SHIFT:
			GetShiftCofigDirectory();
			InitShiftConfiguration();
			 if(!PasswordProtectedMenu)
			 {
			 	if(VerifyPassword(PD_PNL, PD_PNL_PW_MESSAGE, PD_PNL_PW_ENTER, VERIFY) == GLB_PASS) 
			 	{
					strcpy(password,""); 			
					DisplayShiftConfiguration(1);
			 	}
			 	else
			 	{
				 strcpy(password,""); 
			 	}
			 }
			 else
			 {
				DisplayShiftConfiguration(1);
			 }					
			break;
		case MAIN_EDIT_CAPABILITY:
			capabilitySerialNumber = 5000001;
			#ifdef USESCAPMODULE
				 if(!PasswordProtectedMenu)
				 {
				 	if(VerifyPassword(PD_PNL, PD_PNL_PW_MESSAGE, PD_PNL_PW_ENTER, VERIFY) == GLB_PASS) 
				 	{
						strcpy(password,""); 			
						DisplayPanel (CapabilityPanelHandle);
				 	}
				 	else
				 	{
					 	strcpy(password,""); 
					}
				 }
				 else
				 {
						strcpy(password,""); 
				 		DisplayPanel (CapabilityPanelHandle);
				 }						
			#endif
			break;
		case MAIN_EDIT_HISTOYIELD:
			 if(!PasswordProtectedMenu)
			 {
			 	if(VerifyPassword(PD_PNL, PD_PNL_PW_MESSAGE, PD_PNL_PW_ENTER, VERIFY) == GLB_PASS) 
			 	{
					strcpy(password,"");			
					ClearLongTerm();

			 	}
			 	else
			 	{
				 strcpy(password,""); 
			 	}
			 }
			 else
			 {
				ClearLongTerm();
			 }					
			break;


		default:

			break;
	}   // end switch
} // end MAINEditMenuCB

//********************************************************************************************************************
/********************************************//**
* Event from the View menu
***********************************************/
void CVICALLBACK MAINViewMenuCB (int menuBar, int menuItem, void *callbackData, int panel)
{
	menuItem = CheckTestingInProcess(menuItem);

	switch (menuItem)
	{
		#ifdef USESSYSCONFIG
		case MAIN_VIEW_SYSTEM_CONFIG:
			SysViewMenu =1;
			EnableSystemControlSaving(0);
			DisplayPanel (SystemPanelHandle);
			CreateMiscConfigurationTable();
			DisplaySysControl(1);
			break;
		#endif
		
		#ifdef USESTSTCONFIG
		case MAIN_VIEW_TEST_CONFIG:
			SysViewMenu =0;
			CreategTestConfigurationTable();
			DisplayTstControl(1, 0);
			DisplayPanel (TestCfgPanelHandle);
			break;
		#endif
		
		case MAIN_VIEW_SHIFT:
			GetShiftCofigDirectory();
			InitShiftConfiguration();
			DisplayShiftConfiguration(0);
			break;
		
		case MAIN_VIEW_CLEAR_TEST_COUNT:
			ClearShortTerm();
			break;
		
		case MAIN_VIEW_DIO6515:
			DIOViewMenu =0;
			CreateDigitalIO6515ConfigurationTable();
			CreateDigitalIO6515ConfigurationTable2();
			DisplayDIO6515Control(1, 0);
			DisplayPanel (DIO6515ConfigPanelHandle);
			break;
		
		case MAIN_VIEW_MIO6220:
			DIOViewMenu =0;
			CreateAnalogInputConfigurationTable();
			CreateAnalogOutputConfigurationTable();
			CreateMDigitalIOConfigurationTable();
			DisplayMIOControl(1, 0);
			DisplayPanel (MIOPanelHandle);
			break;
		
		default:
			break;
	} // end switch
} // end MAINViewMenuCB

//********************************************************************************************************************
 /********************************************//**
* Event from the hardware control menu
***********************************************/
void CVICALLBACK MAINHardwareCtrlCB (int menuBar, int menuItem, void *callbackData, int panel)
{
	menuItem = CheckTestingInProcess(menuItem);
	char dir[MAX_PATHNAME_LEN];
	char canMsgFilename[MAX_PATHNAME_LEN];

	if(Flag_Password_Protect && VerifyPassword(PD_PNL, PD_PNL_PW_MESSAGE, PD_PNL_PW_ENTER, VERIFY) == GLB_FAIL)
		return;
		
	switch (menuItem)
	{
		#ifdef USESDIO6515UUTILS
		case MAIN_HARDWARE_CONTROL_DIO6515U:
				DIOViewMenu =0;
				SetCtrlAttribute (MainPanelHandle, Main_START_TIMER, ATTR_ENABLED, 0);
				DisplayMANUAL6515Utils();
				break;
		#endif
		#ifdef USEDUTMEMORY
		case MAIN_HARDWARE_CONTROL_DUTMEMORY:
			SysViewMenu =0;
			DisplayPanel (DutMemoryPanelHandle);
			GetProjectDir(dir);
			sprintf(canMsgFilename,"%s\\Configuration\\CAN_MessageLibrary.txt",dir);
			LoadMessageLibrary(canMsgFilename);   // TODO add libary file 
			break;
		#endif

		default:
			break;
	} // end switch
}

//********************************************************************************************************************
 /********************************************//**
* Event from the help menu
***********************************************/
void CVICALLBACK MainHelpCB (int menuBar, int menuItem, void *callbackData,
		int panel)
{
		char dir[MAX_PATHNAME_LEN];
		char cmd[512];
		GetProjectDir(dir);   
		
		switch (menuItem)
		{
			case MAIN_HELP_USER_GUIDE:
				sprintf(cmd, "%s%s",dir,"\\Help\\C6_Calibration_Guide.pdf");
				OpenDocumentInDefaultViewer(cmd,VAL_NO_ZOOM);
				break;
			case MAIN_HELP_EE_SCHEMATICS:
				sprintf(cmd, "%s%s",dir,"\\Help\\C6_Calibration_Electrical_Schematic.pdf");
				OpenDocumentInDefaultViewer(cmd,VAL_NO_ZOOM);
				break;
			case MAIN_HELP_MECH_SCHEMATICS:
				sprintf(cmd, "%s%s",dir,"\\Help\\C6_Calibration_Mechanical_Schematic.pdf");
				OpenDocumentInDefaultViewer(cmd,VAL_NO_ZOOM);
				break;
			case MAIN_HELP_SW_FUNCTIONS:
				sprintf(cmd, "%s%s",dir,"\\Help\\html\\index.html");
				OpenDocumentInDefaultViewer(cmd,VAL_NO_ZOOM);
				break;
			case MAIN_HELP_ABOUT:
			 	DisplayPanel (InitPanelHandle);
				break;
			default:
				break;
		} // end switch
}  // end MainHelpCB

//********************************************************************************************************************
/********************************************//**
* Enable saving of System configuration panel
***********************************************/
void EnableSystemControlSaving(int enableSaveButton)
{
	int 					TabPanelHandle;

	if(enableSaveButton)
	{
		GetPanelHandleFromTabPage (SystemPanelHandle, SYSCFG_PNL_SYS_CFG_TAB, TAB_PAGE_TWO, &TabPanelHandle);
		SetTabPageAttribute(SystemPanelHandle, SYSCFG_PNL_SYS_CFG_TAB, TAB_PAGE_TWO, ATTR_VISIBLE, 1);
		SetCtrlAttribute (TabPanelHandle, MIS_TB_TAB_MISC_CFG_SAVE, ATTR_DIMMED , 0);
	}
	else
	{
		GetPanelHandleFromTabPage (SystemPanelHandle, SYSCFG_PNL_SYS_CFG_TAB, TAB_PAGE_TWO, &TabPanelHandle);
		SetCtrlAttribute (TabPanelHandle, MIS_TB_TAB_MISC_CFG_SAVE, ATTR_DIMMED , 1);
	}
} // end EnableSystemControlSaving

//********************************************************************************************************************
/********************************************//**
* idle time and Configuration table update every second.
***********************************************/
int CVICALLBACK UpdateClock (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	char       idle_time[12], shift_str[10];
	static int idle_sec=0, idle_min=0, idle_hrs=0;
	char calRecipeNoStr[12], flavorIdStr[12];


	switch (event)
	{
		case EVENT_TIMER_TICK:
			
			
			//Air Pressure Sensor
			if (getVacSensor() == 0)
			{
				//Stop Clock
				SetCtrlAttribute (MainPanelHandle, Main_CLOCK_TIMER, ATTR_ENABLED, 0);    
				SetCtrlAttribute (MainPanelHandle, Main_ESTOP_TIMER, ATTR_ENABLED, 0);  

				setCtrlDumpValve(GLB_FALSE);
				resetTestStation();
			
				
				
				for(int i=0;i<6;i++)
				{   
					if(BoardRunning[i]==1)
					{	
						CmtGetLock(VacSensor_LockHandle);	
						VacFault[i] = GLB_TRUE;
						CmtReleaseLock(VacSensor_LockHandle);
					}
				}
				
		
				//Write to Log File
				//CmtGetLock(VacSensor_LockHandle);	 
				//AirPressureErrorLogging();
				//CmtReleaseLock(VacSensor_LockHandle);
				
				////////////////////////////////////////////////////////
				// Air Pressure Panel
				////////////////////////////////////////////////////////				
				char					dirP[MAX_PATHNAME_LEN], uirPathP[MAX_PATHNAME_LEN]; 
	
				GetProjectDir(dirP);
				sprintf(uirPathP, "%s%s", dirP,"\\UserInterface\\AirPressurePanel.uir");
	 
				AirPressurePanelHandle = LoadPanel (0, uirPathP, AIRPNL);
				
				InstallPopup (AirPressurePanelHandle);
				
				//Flag set to 1
				AirPressureFlag = 1;
				//setDebugBit(1);
				
				
			}
			else 
			{
			//	if (installFlag == 1)
			//	{
			//		setDebugBit(0);	
			//	}
			}
			
			//end
			
			while (getFxtLock() != 15)
			{
				resetTestStation();
				FxtFlag=GLB_TRUE;
				FxtLockErrorMessage();
				ProcessSystemEvents();
				NonBlockDelay(2);
	
				for(int i=0;i<totalNest;i++)
				{   
					if(BoardRunning[i]==1)
						AirIsDisabled[i] = GLB_TRUE;
				}

			}
			FxtFlag = GLB_FALSE;  
			
			
			if (GetNumberOfRunningBoard() == 0)	   // TODO ID 33
			{
			   	if (idle_sec < 59) idle_sec++;
			   	else {idle_sec = 0; idle_min++;}
			   	if (idle_min > 59) {idle_min = 0; idle_hrs++;}
			   	sprintf(idle_time, "%02d:%02d:%02d", idle_hrs, idle_min, idle_sec);
			   	SetCtrlVal(MainPanelHandle, MAIN_IDLE_TIME, idle_time);
			}

    	   	sprintf(shift_str, "%d", shift);
			GetDateCode(ShiftPanelHandle, SHIFT_PNL_SHIFT_STRING);
			sprintf(calRecipeNoStr,"%i",selRecipe.CalNum);
			sprintf(flavorIdStr,"%i",selRecipe.FlavorId);
			
		
			SetTableCellVal(MainPanelHandle, DYN_TABLE_MAIN, MakePoint(2,1), DateStr());
    	   	SetTableCellVal(MainPanelHandle, DYN_TABLE_MAIN, MakePoint(2,2), TimeStr());
    	   	SetTableCellVal(MainPanelHandle, DYN_TABLE_MAIN, MakePoint(2,3), ProductType);
    	   	SetTableCellVal(MainPanelHandle, DYN_TABLE_MAIN, MakePoint(2,4), DLLrev);
			SetTableCellVal(MainPanelHandle, DYN_TABLE_MAIN, MakePoint(4,1), selRecipe.Recipe);
    	   	SetTableCellVal(MainPanelHandle, DYN_TABLE_MAIN, MakePoint(4,2), selRecipe.Variant);
    	   	SetTableCellVal(MainPanelHandle, DYN_TABLE_MAIN, MakePoint(4,3), flavorIdStr);
    	   	SetTableCellVal(MainPanelHandle, DYN_TABLE_MAIN, MakePoint(4,4), selRecipe.PartNum);
			
//			UpdateStartUpTestNest();	// TODO ID 25 (load nest 1,3,5 indicator)
			updateFailChuteIsFullStatus();
			
			break;
	}
	return 0;
} // end UpdateClock 

//********************************************************************************************************************
/********************************************//**
* Estop time event handeling
***********************************************/
int CVICALLBACK EstopTimerCB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	SetCtrlAttribute (MainPanelHandle, Main_ESTOP_TIMER, ATTR_ENABLED, 0);
 	int FailChuteLastUnit = getFailChute2();

	switch (event)
	{
		case EVENT_TIMER_TICK:
			//return 0; ////AA
			if(!getE_Stop())
			 {
				
				//Air Pressure Sensor
				SetCtrlAttribute (MainPanelHandle, Main_CLOCK_TIMER, ATTR_ENABLED, 0);
				 
				resetTestStation();
				estopFlag=GLB_TRUE;
			
				CmtGetLock(ESTOP_LockHandle);   
				for(int i=0;i<totalNest;i++)
				{   
					if(BoardRunning[i]==1)
						EStopIsEnable[i] = GLB_TRUE;
				}
				CmtReleaseLock(ESTOP_LockHandle); 
				EStopErrorMessage();
			 }
			 else
			 {
				estopFlag = GLB_FALSE;  
			 }
			 
			 failChuteCnt=0;
			 for(int i=0;i<5;i++)
			 {
				if(getFailChute())
				{
					NonBlockDelay(0.05);
					failChuteCnt++;
				}
			 }
			 if(failChuteCnt > 4)
			 {
				 failChuteCnt=0;
				 SetCtrlAttribute (MainPanelHandle, Main_ESTOP_TIMER, ATTR_INTERVAL, 0.5);  
				 SetCtrlVal(MainPanelHandle, rejectBinLed, toggleBit);
				 FailChuteLastUnit = getFailChute2();
				 while (FailChuteLastUnit == 1)
				 {
				 	RejectBinFullErrorMessage();
					FailChuteLastUnit = getFailChute2();
					NonBlockDelay(2);
					FailChuteLastUnit = getFailChute2();
				 }
				 toggleBit = !toggleBit;
			 
			 }
			 if(!getFailChute())
			 {
				 SetCtrlAttribute (MainPanelHandle, Main_ESTOP_TIMER, ATTR_INTERVAL, 1.0); 
				 SetCtrlVal(MainPanelHandle, rejectBinLed, 0);
			 }

			break;
	}
	SetCtrlAttribute (MainPanelHandle, Main_ESTOP_TIMER, ATTR_ENABLED, 1);

	return 0;
}  // end EstopTimerCB

//********************************************************************************************************************
/********************************************//**
* Estop error message
***********************************************/
void EStopErrorMessage(void)
{
	FILE *fp;
	char* timeStamp;

	if(estopFlag && (ExitStatus==FALSE))
	{
		ResetTextBox(ErrorPanelHandle, ERR_PNL_ERROR_TEXTBOX, "");
		SetCtrlVal(ErrorPanelHandle, ERR_PNL_ERROR_TEXTBOX, "E-STOP IS PRESSED\n\n");
		SetCtrlVal(ErrorPanelHandle, ERR_PNL_ERROR_TEXTBOX, "PLEASE CALL TEST TECHNICIAN\n\n");
		SetCtrlVal(ErrorPanelHandle, ERR_PNL_ERROR_TEXTBOX, "ONCE PROBLEM IS FIXED\n\n PRESS EXIT BUTTON TO CLOSE.\n");

		if(VerifyOpenFileWrite(SystemFileName, "a", &fp))
		{
			timeStamp = TimeStr();
			fprintf(fp,"%s: %s \n", timeStamp, "E-STOP Pressed");
	    	if (fclose(fp) != 0)
	    	{
				MessagePopup ("FILE ERROR: Unable to close file \n", SystemFileName);
	    	}
		}

		InstallPopup (ErrorPanelHandle);
		estopFlag=1;
	}
}  // end EStopErrorMessage
/********************************************//**
* Fixture lock error message
***********************************************/
void FxtLockErrorMessage(void)
{
	FILE *fp;
	char* timeStamp;

	if(FxtFlag && (ExitStatus==FALSE))
	{
		ResetTextBox(ErrorPanelHandle, ERR_PNL_ERROR_TEXTBOX, "");
		SetCtrlVal(ErrorPanelHandle, ERR_PNL_ERROR_TEXTBOX, "Fixture is not seated properly\n\n");

		if(VerifyOpenFileWrite(SystemFileName, "a", &fp))
		{
			timeStamp = TimeStr();
			fprintf(fp,"%s: %s \n", timeStamp, "Fixture is not seated properly");
	    	if (fclose(fp) != 0)
	    	{
				MessagePopup ("FILE ERROR: Unable to close file \n", SystemFileName);
	    	}
		}

		InstallPopup (ErrorPanelHandle);
		FxtFlag=1;
	}
}  // end EStopErrorMessage
/********************************************//**
* Fixture ID error message
***********************************************/
void FxtIDErrorMessage(char * type)
{
	FILE *fp;
	char* timeStamp;
	char message[256]={0};
	sprintf(message,"Wrong Fixture, expecting %s fixture",type);
	if(FxtFlag && (ExitStatus==FALSE))
	{
		ResetTextBox(ErrorPanelHandle, ERR_PNL_ERROR_TEXTBOX, "");
		SetCtrlVal(ErrorPanelHandle, ERR_PNL_ERROR_TEXTBOX, message);

		InstallPopup (ErrorPanelHandle);
		FxtFlag=1;
		
	}
}  // end EStopErrorMessage
//********************************************************************************************************************

/********************************************//**
* Logging of system error messages
***********************************************/
//********************************************************************************************************************
void logSystemErrorMessage(char * systemMsg)
{
	FILE *fp;
	char* timeStamp;
	char msg[120];

	if(VerifyOpenFileWrite(SystemFileName, "a", &fp))
	{
		timeStamp = TimeStr();
		fprintf(fp,"%s: %s \n", timeStamp, systemMsg);
    	if (fclose(fp) != 0)
    	{
			sprintf(msg,"Unable to close file %s.",SystemFileName);
			MessagePopup ("FILE ERROR",msg);
		}
	}

} // end logSystemErrorMessage

//********************************************************************************************************************

/********************************************//**
* Log Test results in log file
***********************************************/
void logTestResult(int nestNum, int testNumber)
{
	FILE *fp;
	char* timeStamp;
	char msg[120];

	if(VerifyOpenFileWrite(SystemFileName, "a", &fp))
	{
		timeStamp = TimeStr();
        deleteTermination(mtgTestStepInfo[nestNum][testNumber].testName);
		deleteTermination(mtgTestStepInfo[nestNum][testNumber].testResultVal);
		fprintf(fp,"%s: %s  %s \n", timeStamp, mtgTestStepInfo[nestNum][testNumber].testName, mtgTestStepInfo[nestNum][testNumber].testResultVal);

    	if (fclose(fp) != 0)
    	{
			sprintf(msg,"Unable to close file %s.",SystemFileName);
			MessagePopup ("FILE ERROR",msg);
		}
	}

} // end logTestResult

//********************************************************************************************************************
/********************************************//**
* Log Test results file initialization
***********************************************/
void logTestResultInit(void)
{
	FILE *fp;
	char* timeStamp;
	char msg[120];

	if(VerifyOpenFileWrite(SystemFileName, "a", &fp))
	{
		timeStamp = TimeStr();
		fprintf(fp,"\n%s: Serial Number: %s\n", timeStamp, "");

    		if (fclose(fp) != 0)
    	{
			sprintf(msg,"Unable to close file %s.",SystemFileName);
			MessagePopup ("FILE ERROR",msg);
		}
	}

}  // end logTestResultInit

//********************************************************************************************************************
/********************************************//**
* Perform initialization of CAN ports, instruments and configuration
***********************************************/
void TestInitialization(void)
{
	long status=0;
	char tempMsg[200], errorString[1000];

	// Attempt to connect to ITAC database
	if(ITACIsEnable == TRUE)
	{
		LogOutSession();
		//ewMII_close ();
		if((status=ewMII_init(errorString))<0)
		{
			sprintf(tempMsg,"Failed to connect to ITAC\n ewMII_init status:%d",status);
			MessagePopup("Error",tempMsg);
			ResetAndExit();
		}
		checkSession();
		if((status = LogInSession(GetCfgMiscValue("ITACSystemID",80),GetCfgMiscValue("ITACStationID",80),errorString))<0)
		{
			sprintf(tempMsg,"Failed to connect to ITAC\n LogInSession status:%d",status);
			MessagePopup("Error",tempMsg);
			ResetAndExit();
		}
		SetCtrlVal(MainPanelHandle, itacStatusLed, 1);
	}


	/////////////////////////////////////////////////////////////////////////
	// Turn on 24VDC power and Control Dump Valve
	// reset test station to a preset state
	// Load cable loss compensation file
	// initialize CAN port and Spectrum Analyzers
	// Initialize test result and output file
	// Initialize parallel thread workers and locks
	/////////////////////////////////////////////////////////////////////////
	MainTestingIsPause=0;
	failChuteLastStatus=0;

	powerTestStation(GLB_TRUE);
	setCtrlDumpValve(GLB_TRUE);
	resetTestStation();

	// read cable loss from xml config file
	LoadCableLossCompensationFile();
	GetTestStepLimits();

	// Initialize CANport and totalResult
	for(int i=0; i<totalNest; i++)
	{
		//char error_str[400];
		//sprintf(error_str, "Can't initialize CAN card %d, restart PC", i);
		
		//if(Open_CAN(i) != 0)
		//	MessagePopup("Error", error_str);	
		
		BoardRunning[i]=0;
		EStopIsEnable[i]=0;
		AirIsDisabled[i]=0;

	}

	// Initialize Spectrum Analyzers
//	for(int i=0; i<NUMBER_OF_TEST_INSTRUMENTS; i++)
//	{
//		char error_str[400];
//		sprintf(error_str, "Can not initialize Spectrum Analyzer %i, check power & connections", i+1);
		
//		if(InitSpecAn(i) != 0)
//			MessagePopup("Error", error_str);
//	}

	get_test_output_log_filename();   // create file to log test output for debugging

	// intialize all worker and thread locks
	if (!InitializeParallelWorkers())
	{
		NonBlockDelay(5);
		exit(0);
	}
		
	InitializeAllLock();
	InitializeLongTermCount();
	UnitsAreTestingCount = 0;
}

//********************************************************************************************************************
/********************************************//**
* Main Sequence to call the test sequence in parallel
***********************************************/
void MainSequence(void)
{
	SetCtrlAttribute (MainPanelHandle, Main_START_TIMER, ATTR_ENABLED, 0);

/**	while (getFxtLock() != 15)
	{
		resetTestStation();
		FxtFlag=GLB_TRUE;
		FxtLockErrorMessage();
		ProcessSystemEvents();
		NonBlockDelay(2);
		
		for(int i=0;i<totalNest;i++)
		{   
			if(BoardRunning[i]==1)
				AirIsDisabled[i] = GLB_TRUE;
		}

	}
	FxtFlag = GLB_FALSE;  **/

	if ((!estopFlag) && (!AirPressureFlag) && (!FxtFlag))
	{
		TestSequenceParallel();
	}
	SetCtrlAttribute (MainPanelHandle, Main_START_TIMER, ATTR_ENABLED, 1);

} // end MainSequence
//********************************************************************************************************************


 /********************************************//**
* Start test timer
***********************************************/
//********************************************************************************************************************
int CVICALLBACK StartTest (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_TIMER_TICK:
			// return 0; /// //AA
			 if(ExitStatus != GLB_TRUE || test_mode == CAPABILITY ) 		//if and else statements were add to support exiting the software if we are unable to upload results to itac
				MainSequence();
			else
			{
			// Display software is testing
			ResetAndExit();
		}
			break;
	}
	return 0;
} // end StartTest

//********************************************************************************************************************
/********************************************//**
* Run capability mode
***********************************************/
void RunCapabilityMode(void)
{
	int		 counter=0;
	double   wait_time = 0.0;

	SetCtrlAttribute (MainPanelHandle, Main_STOP_CAPABILITY_TEST, ATTR_VISIBLE, GLB_TRUE);
	SetCtrlAttribute (MainPanelHandle, Main_CAP_COUNTER,          ATTR_VISIBLE, GLB_TRUE);
	SetCtrlAttribute (MainPanelHandle, Main_START_TIMER, ATTR_ENABLED, 0);

	stop_capability=GLB_FALSE;
	test_mode = CAPABILITY;
	ExitStatus = 1;
	while( ((stop_capability==GLB_FALSE) && (counter < num_capability_cycle)) || (unlimited_capability_test))
	{
		ProcessSystemEvents();
		MainSequence();
		counter++;
		SetCtrlVal(MainPanelHandle, Main_CAP_COUNTER, counter);
		if(capability_time_interval>0)
		{
			wait_time=Timer();
			while(Timer()-wait_time<capability_time_interval)
			{
				ProcessSystemEvents();
				if(stop_capability==GLB_TRUE) break;
			}
		}
		else Delay(1);

	}
	SetCtrlAttribute (MainPanelHandle, Main_STOP_CAPABILITY_TEST, ATTR_VISIBLE, GLB_FALSE);
	SetCtrlAttribute (MainPanelHandle, Main_CAP_COUNTER,          ATTR_VISIBLE, GLB_FALSE);
	SetCtrlAttribute (MainPanelHandle, Main_START_TIMER, ATTR_ENABLED, 1);
} // end RunCapabilityMode

//********************************************************************************************************************
/********************************************//**
* Stop capability mode
***********************************************/
int CVICALLBACK StopCapabilityModeCB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			 if(ConfirmPopup("Stop Capability Test", "You have selected to stop the capability test,\ncontinue"))
			 {
			 	 stop_capability=GLB_TRUE;
				 test_mode = FINAL;
                 ExitStatus = 0;

				 Capability_Count=0;
				 SetCtrlAttribute (MainPanelHandle, Main_CAP_TIMER, ATTR_ENABLED, 0);

				 Start_Capability_Test=0;
				 SetCtrlAttribute (MainPanelHandle, Main_STOP_CAPABILITY_TEST, ATTR_VISIBLE, 0);
				 SetCtrlAttribute (MainPanelHandle, Main_CAP_COUNTER, ATTR_VISIBLE, 0);
				 FirstTimeCapMode=1;
				 DisplayCapabilityControls=0;

			 }

			 SetCtrlAttribute (MainPanelHandle, Main_STOP_CAPABILITY_TEST, ATTR_VISIBLE, 0);
			break;
	}
	return 0;
} // end StopCapabilityModeCB

//********************************************************************************************************************
/********************************************//**
* Update capability timer
***********************************************/
int CVICALLBACK UpdateCapabilityTimerCB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_TIMER_TICK:
			 SetCtrlAttribute (MainPanelHandle, Main_CAP_TIMER, ATTR_ENABLED, 0);
			 capCounter++;
			 if(capCounter==Capability_Time_Interva)
			 {
			 	Start_Capability_Test=1;
			 }
			 else
			 {
			 	Start_Capability_Test=0;
			 }

			break;
	}
	ProcessSystemEvents();
	return 0;
}  // end UpdateCapabilityTimerCB

//********************************************************************************************************************
/********************************************//**
* Password time event handeling
***********************************************/
int CVICALLBACK PasswordTimerCB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	static int PasswordCount=0;

	switch (event)
	{
		case EVENT_TIMER_TICK:
 			 if(PasswordTimerExpired)
			 {
			 	PasswordCount++;
			 }
			 if(PasswordCount>PasswordTimeInterval)
			 {
				SetMenuBarAttribute (MAIN_menuHandle, MAIN_EDIT_PW_VERIFY, ATTR_ITEM_NAME,
				                   	 "Enable Pass__word Protected Menus");
				PasswordCount=0;
				PasswordTimerExpired=0;
				Flag_Password_Protect=0;
				PasswordProtectedMenu = GLB_FALSE;
			 }

			break;
	}
	return 0;
}  // end  PasswordTimerCB

//********************************************************************************************************************
/********************************************//**
* status box attribute handling
***********************************************/
void StatusBoxAttribute(int dutNumber, char * Msg, int backgroundColor, int fontColor, int fontSize)
{
	SetCtrlAttribute (MainPanelHandle, gBoxMsg[dutNumber], ATTR_TEXT_BGCOLOR , backgroundColor);
	SetCtrlAttribute (MainPanelHandle, gBoxMsg[dutNumber], ATTR_TEXT_COLOR , fontColor);
	SetCtrlAttribute (MainPanelHandle, gBoxMsg[dutNumber], ATTR_TEXT_POINT_SIZE , fontSize);
	SetCtrlVal(MainPanelHandle, gBoxMsg[dutNumber], Msg);
}
//********************************************************************************************************************
/********************************************//**
* Message box attribute handling
***********************************************/
void MsgBoxAttribute(int dutNumber, char * Msg, int backgroundColor, int fontColor, int fontSize)
{
	SetCtrlAttribute (MainPanelHandle, gBoxTxt[dutNumber], ATTR_TEXT_BGCOLOR , backgroundColor);
	SetCtrlAttribute (MainPanelHandle, gBoxTxt[dutNumber], ATTR_TEXT_COLOR , fontColor);
	SetCtrlAttribute (MainPanelHandle, gBoxTxt[dutNumber], ATTR_TEXT_POINT_SIZE , fontSize);
	SetCtrlVal(MainPanelHandle, gBoxTxt[dutNumber], Msg);
}

//********************************************************************************************************************
/********************************************//**
* Initialize all locks threads
***********************************************/
void InitializeAllLock(void)
{
	CmtNewLock (NULL, OPT_TL_PROCESS_EVENTS_WHILE_WAITING, &WriteToFile_LockHandle);
	CmtNewLock (NULL, OPT_TL_PROCESS_EVENTS_WHILE_WAITING, &FailChute_LockHandle);
	CmtNewLock (NULL, OPT_TL_PROCESS_EVENTS_WHILE_WAITING, &ITAC_LockHandle);
	CmtNewLock (NULL, OPT_TL_PROCESS_EVENTS_WHILE_WAITING, &YieldData_LockHandle);
	CmtNewLock (NULL, OPT_TL_PROCESS_EVENTS_WHILE_WAITING, &AnalogVoltMeas_LockHandle);
	CmtNewLock (NULL, OPT_TL_PROCESS_EVENTS_WHILE_WAITING, &WriteTestOutput_LockHandle);
	CmtNewLock (NULL, OPT_TL_PROCESS_EVENTS_WHILE_WAITING, &ESTOP_LockHandle); 
	CmtNewLock (NULL, OPT_TL_PROCESS_EVENTS_WHILE_WAITING, &Thread_6220_LockHandle); 
	CmtNewLock (NULL, OPT_TL_PROCESS_EVENTS_WHILE_WAITING, &InitCalLock); 
	CmtNewLock (NULL, OPT_TL_PROCESS_EVENTS_WHILE_WAITING, &AirPressurePanelHandle);
	CmtNewLock (NULL, OPT_TL_PROCESS_EVENTS_WHILE_WAITING, &VacSensor_LockHandle);   	
	
}

//********************************************************************************************************************
/********************************************//**
* Release all locks thread
***********************************************/
void ReleaseAllLock(void)
{
	ReleaseLock(WriteToFile_LockHandle);
	ReleaseLock(FailChute_LockHandle);
	ReleaseLock(YieldData_LockHandle);
	ReleaseLock(AnalogVoltMeas_LockHandle);
	ReleaseLock(WriteTestOutput_LockHandle);
	ReleaseLock(ESTOP_LockHandle);
	ReleaseLock(Thread_6220_LockHandle);
	ReleaseLock(InitCalLock);  
	ReleaseLock(AirPressurePanelHandle);
	ReleaseLock(VacSensor_LockHandle);   	
	
	
}

/********************************************//**
* Release a lock thread
***********************************************/
void ReleaseLock(CmtThreadLockHandle threadLock)
{
	int obtainedLock = 0;
	CmtTryToGetLock(threadLock,&obtainedLock);
	if (obtainedLock)
	{
		CmtReleaseLock(threadLock);
	}
} // end ReleaseLock

//********************************************************************************************************************
/********************************************//**
* Discard all locks thread
***********************************************/
void DiscardAllLock(void)
{
	//DiscardLock(WriteToFile_LockHandle);
	DiscardLock(FailChute_LockHandle);
	DiscardLock(ITAC_LockHandle);
	DiscardLock(YieldData_LockHandle);
	DiscardLock(AnalogVoltMeas_LockHandle);
	DiscardLock(WriteTestOutput_LockHandle);
	DiscardLock(ESTOP_LockHandle);
	DiscardLock(Thread_6220_LockHandle);
}

/********************************************//**
* Discard a lock thread
***********************************************/
void DiscardLock(CmtThreadLockHandle threadLock)
{
	int obtainedLock = 0;
	CmtTryToGetLock(threadLock,&obtainedLock);
	if (obtainedLock)
	{
		CmtDiscardLock(threadLock);
	}
} // end DiscardLock


/********************************************//**
* Initialize Configuration Misc Value
***********************************************/
void InitializeCfgMiscValue(void)
{
	char tmpStr[120];

	// Get ITAC enable status (Y=1, No=0)
	strcpy(tmpStr, GetCfgMiscValue("ITACEnable",80));
	Scan (tmpStr, "%s>%d", &ITACIsEnable);
	
	strcpy(tmpStr, GetCfgMiscValue("NumberofNests",80));
	Scan (tmpStr, "%s>%d", &totalNest);
	
	strcpy(tmpStr,GetCfgMiscValue("ApplicationExecutionIsLog",80));
	Scan(tmpStr,"%s>%i",&ApplicationExecutionIsLog);
	
	strcpy(tmpStr,GetCfgMiscValue("TestOutputIsLog",80));
	Scan(tmpStr,"%s>%i",&TestOutputIsLog);
	
	MaxItacProceedRequestCount = atoi(GetCfgMiscValue("MaxCount",80));  
	
} // end InitializeCfgMiscValue

//********************************************************************************************************************
/********************************************//**
* Reset test station and exit
***********************************************/
 void ResetAndExit(void)
 {
	PowerDownTestStation();
	DiscardAllHandles();
	Close_NbLib();
	Close_NiCanWrp ();
	Close_NbTest ();
	ExitStatus = GLB_TRUE;
	if(ITACIsEnable)
	{
		LogOutSession();
		ewMII_close ();
	}
	ReleaseAllLock();
	DiscardAllLock();
 	QuitUserInterface (0);

 }  // end ResetAndExit


/********************************************//**
* Power down test station
***********************************************/
 void PowerDownTestStation(void)
 {
	resetTestStation();
	
	//Air Pressure Sensor
	for (int i=0;i<6;i++)
	{
		setDutIndicators (i, 0, 0, 0);  
	}
	
	setCtrlPower24VDC(FALSE);  // and power down dump valve before power.
 } // end PowerDownTestStation


/********************************************//**
* Check if any testing is in progress
***********************************************/
int CheckTestingInProcess(int menuItem)
{
	int value;
	// check if any units are being tested
	if (UnitsAreTestingCount > 0)
	{
		MessagePopup("Invalid Command","Testing is in process.");
		value = -1;
	}
	else
	{
		value = menuItem;
	}
	return(value);
}  // end CheckTestingInProcess


/********************************************//**
* Update start up test nest indicator
***********************************************/
void UpdateStartUpTestNest(void)
{
	int startUpTestNest[3] = {1,3,5}; // set operator to start at the following nest

	if (GetNumberOfRunningBoard() == 0)
	{
		for (int i=0; i<3; i++)
		{
			StatusBoxAttribute(startUpTestNest[i], "", VAL_BLUE, VAL_WHITE, 35);
			MsgBoxAttribute(startUpTestNest[i], "", 0x00E0E0E0, VAL_BLACK, 35);
		}
	}
	else
	{
		for(int i=0; i<totalNest; i++)
		{
			if (BoardRunning[i]==0)
			{
				StatusBoxAttribute(i, "WAITING...", VAL_BLUE, VAL_WHITE, 35);
				MsgBoxAttribute(i, "Place Unit\n to start testing", 0x00E0E0E0, VAL_BLACK, 35);
			}
		}
	} // end if
	ProcessDrawEvents();
}  // end UpdateStartUpTestNest
//Air Pressure Sensor
void AirPressureErrorLogging(void)
{
	FILE *fp;
	char* timeStamp;

	if(VerifyOpenFileWrite(SystemFileName, "a", &fp))
	{
		timeStamp = TimeStr();
		fprintf(fp,"%s: %s \n", timeStamp, "Air Pressure Fault Occured");
	    if (fclose(fp) != 0)
	    {	
			///MessagePopup ("FILE ERROR: Unable to close file \n", res_file);
	      	///return;
	    }
	}
	
}

/********************************************//**
* Estop error message
***********************************************/
void RejectBinFullErrorMessage(void)
{
	FILE *fp;
	char* timeStamp;
	
	if(!estopFlag)
	{
		ResetTextBox(ErrorPanelHandle, ERR_PNL_ERROR_TEXTBOX, "");
		SetCtrlVal(ErrorPanelHandle, ERR_PNL_ERROR_TEXTBOX, "Reject Bin Full\n\n");
		SetCtrlVal(ErrorPanelHandle, ERR_PNL_ERROR_TEXTBOX, "Please empty reject bin.\n\n");
		SetCtrlVal(ErrorPanelHandle, ERR_PNL_ERROR_TEXTBOX, "Once the bin is empty\n\n Press the exit button\n");
		
		if(VerifyOpenFileWrite(SystemFileName, "a", &fp))
		{
			timeStamp = TimeStr();
			fprintf(fp,"%s: %s \n", timeStamp, "Reject Bin Full");
	    	if (fclose(fp) != 0)
	    	{	

	    	}
		}
	

		InstallPopup (ErrorPanelHandle);
	}
}


