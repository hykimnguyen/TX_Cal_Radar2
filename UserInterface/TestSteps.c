/***********************************************************************
/***********************************************************************
 *
 *
 *  COPYRIGHT: Arxtron Technologies Inc. All Rights Reserved.
 *
 *  PURPOSE: - Test sequence steps
 *
 *  DEVELOPMENT HISTORY:
 *
 *  Date        Name           Rev.   Description
 *  ----------  -------------  -----  -----------------------
 *  04-10-2014  Arxtron        	0.0      Initial Release
 *  
 *  
 *********************************************************************/ 
/*!
*    @file    TestSteps.c
*    @brief   All the C6 programmer test functions
*    @author  Arxtron Technologies Inc.
*    @date    2013.9.6
*    All the C6 programmer high level test functions and some 
*    low level function to control power, set leds and get the state of sensors. 
*    
*/ 
#include <ansi_c.h>
#include "Global.h"
#include "DIO6515UtilsDef.h"
#include "TestConfiguration_Def.h"
#include "frmMain.h"
#include "TextUtils.h"
#include "MainDef.h"
#include "TestSteps.h"
#include "Measurements.h"
#include "Parallel_LIB.h"
#include "test_output_log.h"
#include "timeUtils.h"
#include "worker.h"
#include "CanCommand.h"
#include <Windows.h>
#include "Nb_Test.h"
#include "NiCanWrp.h"
#include "NbLib.h"
#include "ParseCSV.h"

#include "NB_Functions.h" 
#include <ansi_c.h>
#include <userint.h>
#include <cvirte.h>
#include <toolbox.h> 
#include <string.h>
#include <stdarg.h>
#include "DateTimeUtils.h"


#include "nbmailbox.h"


#define VAL_REQUIRED 1
#define VAL_NOT_REQUIRED 0
#define MAX_POINTS 50


static Alv_CAN_NiCan 				NiCan_Handle[NUMOFNESTS]; 
static Alv_CAN_CanComm 			CanComm[NUMOFNESTS];
static Alv_NarrowBand_SensorComm	NarrowBand_SensorComm_Handle[NUMOFNESTS]; 

static Alv_NarrowBand_Sensor 		NarrowBand_Sensor[NUMOFNESTS];
//Alv_NarrowBand_Sensor 		NarrowBand_Sensor[NUMOFNESTS];

static Alv_Test_SensorControl 		Test_SensorControl_Handle[NUMOFNESTS];
static Alv_Test_Mfg_MfgTester 		Test_Mfg_MfgTester_Handle[NUMOFNESTS];
static Alv_Test_Mfg_MfgTests 		Test_Mfg_MfgTests[NUMOFNESTS]; 
static Alv_Test_SensorState		Test_SensorState_Handle[NUMOFNESTS];
static Alv_NarrowBand_UNT_DAT		NarrowBand_UNT_DAT_Handle[NUMOFNESTS];
Alv_NarrowBand_NBProtocol_Status    NBProtocol_Status[NUMOFNESTS]; 

static unsigned char       *Data[NUMOFNESTS];

static double TemperatureAtStart[NUMOFNESTS];

	
int get_param(int testNumber, char * param, void *val, int type, int required);

void returnNarrowBand_SensorHandle(int testUnit, Alv_NarrowBand_Sensor *Sensor)
{
	*Sensor = NarrowBand_Sensor[testUnit];

}
/********************************************//**
* Initialize Can, Sensor, control, test and  test_mfg_mfgtest interface 
* Set inital states and initalize variables
***********************************************/
bool InitInterfaces (void)  

{
	//KIM TRY ONCE ONLY
	ssize_t 			DataLength=20;
	Data[i]=CDotNetAllocateMemory(20);  
		for (int i=0;i<NUMOFNESTS;i++)
		{
			Alv_CAN_NiCan__Create (&NiCan_Handle[i], 0); 													//Set Can Interface   
			CanComm[i] = (Alv_CAN_CanComm)NiCan_Handle[i]; 											// cast CanComm
			Alv_NarrowBand_SensorComm__Create(&NarrowBand_SensorComm_Handle[i],0); 						//set sensor interface  
			NarrowBand_Sensor[i] = (Alv_NarrowBand_Sensor)NarrowBand_SensorComm_Handle[i]; 			//cast NarrowBand_Sensor 
			Alv_Test_SensorControl__Create(&Test_SensorControl_Handle[i],NarrowBand_Sensor[i],0); 	//set control interface 
			Alv_Test_Mfg_MfgTester__Create(&Test_Mfg_MfgTester_Handle[i],0); 								//set test interface 
			Test_Mfg_MfgTests[i]= (Alv_Test_Mfg_MfgTests)Test_Mfg_MfgTester_Handle[i];				//cast Test_Mfg_MfgTests 
			Alv_Test_SensorState__Create(&Test_SensorState_Handle[i],0); 									//set test sensor state 
			Alv_NarrowBand_UNT_DAT__Create(&NarrowBand_UNT_DAT_Handle[i],Data[i], DataLength,0);  	//set UNT_Data 
		}
	return 0;
}
/********************************************//**
* Initialize DUT CAN communication
***********************************************/
bool InitCanInterface(int testNumber, int nestNum)
{	  
	char buf[6];
	char T_Out [6];
	char *errStr; 
	int  Connection_Status=-1; 
	char LogMsg[256]={0};

		sprintf(buf, "CAN%d", nestNum+1);  // nestNum should be 0 based and xnet starts at 1 please confirm with NI MAX	
		Can_Set_DriverID(NiCan_Handle[nestNum], buf);
		
	
		CanComm[nestNum] = (Alv_CAN_CanComm)NiCan_Handle[nestNum]; 
		 	//Can_Set_ReadTimeout(4000, T_Out);// AA Can Read Timeout 
		Alv_CAN_CanComm_Set_ReadTimeout(CanComm[nestNum], 5000,0);
		CAN_Connect(CanComm[nestNum], &Connection_Status); 	
		
		sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "Connection_Status=%d", !Connection_Status);   //FOR mtgTestStepInfo.testResultVal, 1 = FAIL, 0 = PASS

	return !Connection_Status;
}


bool InitCanInterfaceDbg(int nestNum)
{	  
	char buf[6];
	char *errStr; 
	int  Connection_Status=-1; 
	char LogMsg[256]={0};

		sprintf(buf, "CAN%d", nestNum+1);  // nestNum should be 0 based and xnet starts at 1 please confirm with NI MAX	
		Can_Set_DriverID(NiCan_Handle[nestNum], buf);
		CanComm[nestNum] = (Alv_CAN_CanComm)NiCan_Handle[nestNum]; 
		CAN_Connect(CanComm[nestNum], &Connection_Status);  //1 = pass
		//sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "Connection_Status=%d", !Connection_Status);   //FOR mtgTestStepInfo.testResultVal, 1 = FAIL, 0 = PASS

	return !Connection_Status;
}


/******************************************************** 
* init sensor Interface                                                        
*********************************************************/
bool Sensor_Comm_Init (int testNumber, int nestNum)   
{
 
 	int  Sensor_Comm_Init_ret=-1;
 	char TestPointsListFilePath[256]; 
 	char LogMsg[256]={0};
 	char Mode[256];	
 
		get_param(testNumber, "Position", Mode, VAL_STRING, VAL_REQUIRED);
		strcpy(TestPointsListFilePath, selRecipe.localFolder);
		if(stricmp(Mode,"FRONT_LEFT")==0)
			SensorComm_Init(NarrowBand_SensorComm_Handle[nestNum],TestPointsListFilePath,
						Alv_NarrowBand_NBProtocol_Position_FRONT_LEFT,CanComm[nestNum],&Sensor_Comm_Init_ret);
		if(stricmp(Mode,"FRONT_RIGHT")==0)
			SensorComm_Init(NarrowBand_SensorComm_Handle[nestNum],TestPointsListFilePath,
						Alv_NarrowBand_NBProtocol_Position_FRONT_RIGHT,CanComm[nestNum],&Sensor_Comm_Init_ret);
		if(stricmp(Mode,"FRONT_CENTER")==0)
			SensorComm_Init(NarrowBand_SensorComm_Handle[nestNum],TestPointsListFilePath,
						Alv_NarrowBand_NBProtocol_Position_FRONT_CENTER,CanComm[nestNum],&Sensor_Comm_Init_ret);
		if(stricmp(Mode,"REAR_CENTER")==0)
 			SensorComm_Init(NarrowBand_SensorComm_Handle[nestNum],TestPointsListFilePath,
						Alv_NarrowBand_NBProtocol_Position_REAR_CENTER,CanComm[nestNum],&Sensor_Comm_Init_ret);
		if(stricmp(Mode,"REAR_LEFT")==0)
 			SensorComm_Init(NarrowBand_SensorComm_Handle[nestNum],TestPointsListFilePath,
						Alv_NarrowBand_NBProtocol_Position_REAR_LEFT,CanComm[nestNum],&Sensor_Comm_Init_ret);
		if(stricmp(Mode,"REAR_RIGHT")==0)
 			SensorComm_Init(NarrowBand_SensorComm_Handle[nestNum],TestPointsListFilePath,
						Alv_NarrowBand_NBProtocol_Position_REAR_RIGHT,CanComm[nestNum],&Sensor_Comm_Init_ret);
		if(stricmp(Mode,"SIDE_LEFT")==0)
 			SensorComm_Init(NarrowBand_SensorComm_Handle[nestNum],TestPointsListFilePath,
						Alv_NarrowBand_NBProtocol_Position_SIDE_LEFT,CanComm[nestNum],&Sensor_Comm_Init_ret);
		if(stricmp(Mode,"SIDE_RIGHT")==0)
			SensorComm_Init(NarrowBand_SensorComm_Handle[nestNum],TestPointsListFilePath,
						Alv_NarrowBand_NBProtocol_Position_SIDE_RIGHT,CanComm[nestNum],&Sensor_Comm_Init_ret);
 
 
		sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "Sensor_Comm_Init=%d",!Sensor_Comm_Init_ret); //AA 

 return  !Sensor_Comm_Init_ret;  //check if Sensor_Comm_Init_ret is 0 when everything pass		//AA	   
 //return 0; 
}  



bool Sensor_Comm_InitDbg (int nestNum)   
{
 
 	int  Sensor_Comm_Init_ret=-1;
 	char TestPointsListFilePath[256]; 
 	char LogMsg[256]={0};
 	char Mode[256];	
 
		get_param(3, "Position", Mode, VAL_STRING, VAL_REQUIRED);
		//get_param(3, "SettingsFile", TestPointsListFilePath, VAL_STRING, VAL_REQUIRED);
		strcpy(TestPointsListFilePath,selRecipe.localFolder);
		if(stricmp(Mode,"FRONT_LEFT")==0)
			SensorComm_Init(NarrowBand_SensorComm_Handle[nestNum],TestPointsListFilePath,
						Alv_NarrowBand_NBProtocol_Position_FRONT_LEFT,CanComm[nestNum],&Sensor_Comm_Init_ret);
		if(stricmp(Mode,"FRONT_RIGHT")==0)
			SensorComm_Init(NarrowBand_SensorComm_Handle[nestNum],TestPointsListFilePath,
						Alv_NarrowBand_NBProtocol_Position_FRONT_RIGHT,CanComm[nestNum],&Sensor_Comm_Init_ret);
		if(stricmp(Mode,"FRONT_CENTER")==0)
			SensorComm_Init(NarrowBand_SensorComm_Handle[nestNum],TestPointsListFilePath,
						Alv_NarrowBand_NBProtocol_Position_FRONT_CENTER,CanComm[nestNum],&Sensor_Comm_Init_ret);
		if(stricmp(Mode,"REAR_CENTER")==0)
 			SensorComm_Init(NarrowBand_SensorComm_Handle[nestNum],TestPointsListFilePath,
						Alv_NarrowBand_NBProtocol_Position_REAR_CENTER,CanComm[nestNum],&Sensor_Comm_Init_ret);
		if(stricmp(Mode,"REAR_LEFT")==0)
 			SensorComm_Init(NarrowBand_SensorComm_Handle[nestNum],TestPointsListFilePath,
						Alv_NarrowBand_NBProtocol_Position_REAR_LEFT,CanComm[nestNum],&Sensor_Comm_Init_ret);
		if(stricmp(Mode,"REAR_RIGHT")==0)
 			SensorComm_Init(NarrowBand_SensorComm_Handle[nestNum],TestPointsListFilePath,
						Alv_NarrowBand_NBProtocol_Position_REAR_RIGHT,CanComm[nestNum],&Sensor_Comm_Init_ret);
		if(stricmp(Mode,"SIDE_LEFT")==0)
 			SensorComm_Init(NarrowBand_SensorComm_Handle[nestNum],TestPointsListFilePath,
						Alv_NarrowBand_NBProtocol_Position_SIDE_LEFT,CanComm[nestNum],&Sensor_Comm_Init_ret);
		if(stricmp(Mode,"SIDE_RIGHT")==0)
			SensorComm_Init(NarrowBand_SensorComm_Handle[nestNum],TestPointsListFilePath,
						Alv_NarrowBand_NBProtocol_Position_SIDE_RIGHT,CanComm[nestNum],&Sensor_Comm_Init_ret);
 
 
		//sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "Sensor_Comm_Init=%d",!Sensor_Comm_Init_ret); //AA 

 return  !Sensor_Comm_Init_ret;  //check if Sensor_Comm_Init_ret is 0 when everything pass		//AA	   
 //return 0; 
}  

/********************************************//**
* Get DUT serial number
***********************************************/
bool GetSerialNumber (int testNumber, int nestNum)   
{
	int error=0;
	char *serial; 
	char requiredSW[25] = {0};
	char LogMsg[256]={0};
	
		get_param(testNumber, "VERSION", requiredSW, VAL_STRING, VAL_REQUIRED);	
		Get_Serial_Number(Test_SensorControl_Handle[nestNum], &serial);
	 
		if (serial != NULL)
		{
			//	printf("serial= %s\n", serial); 
			// check if Serial match Expected serial Number
			error |= (strstr(serial,requiredSW) == NULL);
			sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "Serial_Number=%s", serial);
			sprintf(LogMsg,"Serial Number=%s\n", serial); //AA
		}
//addSerialNumToIts(testNumber,nestNum);//TODO     
	
	return error;
	//return 0;
}
/********************************************//**
* Get DUT serial number
***********************************************/
int GetSerialNumberDUT (int nestNum, char * returnSerial)   
{
	int error=0;
	char *serial;
	
	error = Get_Serial_Number(Test_SensorControl_Handle[nestNum], &serial);
	if (!error)
		strcpy(returnSerial,serial);
	 
	return error;
	//return 0;
}

/********************************************//**
* Get DUT Sw Version
***********************************************/
bool GetSWVersion (int testNumber, int nestNum)   
{
	int error=0; //fail = 0;
	char *HpApp;
	char *HpBoot; 
	char *DspApp; 
	char *DspBoot;
	char requiredHPApp[25], requiredHPBoot[25], requiredDSPApp[25], requiredDSPBoot[25] = {0};
	char LogMsg[256]={0};
	char LogMsg1[256]={0}; 
	
	char max[100]={0};
	char parameter[100]={0};
	char point[100]={0};
	char unit[100]={0};
	
	if (getUnitInfoByRequirement("HP_APP", requiredHPApp, max, parameter, point,unit) != 0)
		return 1;
	if (getUnitInfoByRequirement("HP_BOOT", requiredHPBoot, max, parameter, point,unit)!= 0)
		return 1;
	if (getUnitInfoByRequirement("DSP_APP", requiredDSPApp, max, parameter, point,unit) != 0)
		return 1;
	if (getUnitInfoByRequirement("DSP_BOOT", requiredDSPBoot, max, parameter, point,unit) !=0)
		return 1;
	
	deleteSpaces(requiredHPApp);
	deleteSpaces(requiredHPBoot);
	deleteSpaces(requiredDSPApp);
	deleteSpaces(requiredDSPBoot);
	
	Get_SW_Version(Test_SensorControl_Handle[nestNum], &HpApp,&HpBoot, &DspApp, &DspBoot);

	if (HpApp||HpBoot||DspApp||DspBoot!= NULL)
	{

	 //check if SwVersion match expected Sw version
		error |= (strstr(HpApp,requiredHPApp) == NULL);
		error |= (strstr(HpBoot,requiredHPBoot) == NULL); 
		error |= (strstr(DspApp,requiredDSPApp) == NULL); 
		error |= (strstr(DspBoot,requiredDSPBoot) == NULL); 

		sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "HPApp=%s,Req=%s,HPBoot=%s,Req=%s,DSPApp=%s,Req=%s,DSPBoot=%s,Req=%s", HpApp,requiredHPApp,
																		HpBoot, requiredHPBoot, DspApp, requiredDSPApp, DspBoot, requiredDSPBoot);  
		sprintf(LogMsg1,"HpApp=%s\n,HpBoot=%s\n,DspApp=%s\n,DspBoot=%s\n",HpApp,HpBoot, DspApp, DspBoot);
		
	addSWVersionToIts(	testNumber,nestNum,
					  	HpApp, requiredHPApp,
					 	HpBoot, requiredHPBoot,
					 	DspApp, requiredDSPApp,
					 	DspBoot, requiredDSPBoot, error);    
	}
	return error;
}
/********************************************//**
* Init Tx Cal
***********************************************/
bool Init_Tx_Cal (int testNumber, int nestNum)   
{
	int InitTxCal_ret=-1; 
	char NBSettingFilePath[512]={0}; 
	char NBSettingFileFile[512]={0}; 
	char LogMsg[512]={0};
	char dir[512]={0};
	char buf[512]={0};
	char path[512]={0};

		GetProjectDir(dir);
		sprintf(buf, "\\Nest%d\\", nestNum);
		sprintf(path, "%s%s", dir,buf);
		sprintf(NBSettingFilePath, "%s",path );

		get_param(testNumber, "SettingsFile", NBSettingFileFile, VAL_STRING, VAL_REQUIRED);
		strcat(NBSettingFilePath,NBSettingFileFile);
	
		InitTxCal(Test_Mfg_MfgTester_Handle[nestNum],NarrowBand_Sensor[nestNum], NBSettingFilePath,&InitTxCal_ret);

		sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "InitTxCal=%d",!InitTxCal_ret);  //AA
	//addTXCalStatusToIts(testNumber,nestNum);//TODO     
	
	return !InitTxCal_ret;  //check if InitTxCal_ret is 0 when everything pass	  //AA
	//return 0;
}




bool Init_Tx_CalDbg(int nestNum)   
{
	int InitTxCal_ret=-1; 
	char NBSettingFilePath[256]={0}; 
	char NBSettingFileFile[256]={0}; 
	char LogMsg[256]={0};
	char dir[256]={0};
	char buf[256]={0};
	char path[256]={0};

		GetProjectDir(dir);
		sprintf(buf, "\\Nest%d\\", nestNum);
		sprintf(path, "%s%s", dir,buf);
		sprintf(NBSettingFilePath, "%s",path );

		get_param(5, "SettingsFile", NBSettingFileFile, VAL_STRING, VAL_REQUIRED);
		strcat(NBSettingFilePath,NBSettingFileFile);
	
		InitTxCal(Test_Mfg_MfgTester_Handle[nestNum],NarrowBand_Sensor[nestNum], NBSettingFilePath,&InitTxCal_ret);

		//sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "InitTxCal=%d",!InitTxCal_ret);  //AA
	//addTXCalStatusToIts(testNumber,nestNum);//TODO     
	
	return !InitTxCal_ret;  //check if InitTxCal_ret is 0 when everything pass	  //AA
	//return 0;
}


/********************************************//**
* Ping DUT Part # and Sw Version
***********************************************/
bool PingDut (int testNumber, int nestNum)   
{
	int error=0;
	char *ping_serial;
	char *ping_part_number0;
	char *ping_part_number1;
	char *ping_part_number2;
	char *ping_part_number3;
	char *ping_sw_version0;
	char *ping_sw_version1;
	char *ping_sw_version2;
	char *ping_sw_version3;
	int   Ping_returnValue;
	char requiredParNum0[25], requiredParNum1[25], requiredParNum2[25], requiredParNum3[25] = {0}; 
	char requiredSwVersion0[25], requiredSwVersion1[25], requiredSwVersion2[25], requiredSwVersion3[25] = {0}; 
	char LogMsg[256]={0}; 
	
	
		Ping(Test_Mfg_MfgTester_Handle[nestNum], &ping_serial,&ping_part_number0, 
							 &ping_part_number1,&ping_part_number2, &ping_part_number3,
 							 &ping_sw_version0, &ping_sw_version1,&ping_sw_version2, 
							 &ping_sw_version3,&Ping_returnValue);


	
		sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, 
		"ping_part_number0=%s ping_part_number1=%s ping_part_number2=%s ping_part_number3=%s ping_sw_version0=%s ping_sw_version1=%s ping_sw_version2=%s ping_sw_version3=%s", 
		ping_part_number0,ping_part_number1, ping_part_number2, ping_part_number3, ping_sw_version0,ping_sw_version1, ping_sw_version2, ping_sw_version3);  
		
		sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "PING=%d",Ping_returnValue);
	//addPingResultsToIts(testNumber,nestNum);     
	return !Ping_returnValue;
}



bool PingDutDbg(int nestNum)   
{
	int error=0;
	char *ping_serial;
	char *ping_part_number0;
	char *ping_part_number1;
	char *ping_part_number2;
	char *ping_part_number3;
	char *ping_sw_version0;
	char *ping_sw_version1;
	char *ping_sw_version2;
	char *ping_sw_version3;
	int   Ping_returnValue;
	char requiredParNum0[25], requiredParNum1[25], requiredParNum2[25], requiredParNum3[25] = {0}; 
	char requiredSwVersion0[25], requiredSwVersion1[25], requiredSwVersion2[25], requiredSwVersion3[25] = {0}; 
	char LogMsg[256]={0}; 
	
	
		Ping(Test_Mfg_MfgTester_Handle[nestNum], &ping_serial,&ping_part_number0, 
							 &ping_part_number1,&ping_part_number2, &ping_part_number3,
 							 &ping_sw_version0, &ping_sw_version1,&ping_sw_version2, 
							 &ping_sw_version3,&Ping_returnValue);


	
//		sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, 
//		"ping_part_number0=%s ping_part_number1=%s ping_part_number2=%s ping_part_number3=%s ping_sw_version0=%s ping_sw_version1=%s ping_sw_version2=%s ping_sw_version3=%s", 
//		ping_part_number0,ping_part_number1, ping_part_number2, ping_part_number3, ping_sw_version0,ping_sw_version1, ping_sw_version2, ping_sw_version3);  
		
//		sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "PING=%d",Ping_returnValue);
	//addPingResultsToIts(testNumber,nestNum);     
	return !Ping_returnValue;
}



/********************************************//**
* Read the specified point 
***********************************************/
bool ReadPoint (int testNumber, int nestNum)   
{
	
	
	char *value; 
	char Point[25] = {0};
	unsigned short point=0;
	char LogMsg[256]={0};
	int ret_val=0;
	
		get_param(testNumber, "Point", Point, VAL_STRING, VAL_REQUIRED);
		point =atoi(Point);
		Read_Point(NarrowBand_Sensor[nestNum],point, &value,&ret_val); 

	
		sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "Read_Point=%d", ret_val);  
	//addReadPointResultsToIts(testNumber,nestNum);//TODO     
	
	return ret_val;//Need to make sure ret_val is 0 when read_point function succesfull
}

/********************************************//**
* Read the specified point2 
***********************************************/
bool ReadPointCSV (int testNumber, int nestNum)   
{
	
	
	char *value; 
	char Point[25] = {0};
	char Low_Limit[25] = {0};
	char High_Limit[25] = {0};
	
	unsigned short point=0;
	char LogMsg[BUFFER_SIZE]={0};
	char DisplayMsg[BUFFER_SIZE]={0};
	
	int ret_val=0;
	
	char parameter[100]={0};
	char requirement[100]={0};
	char min[100]={0};
	char max[100]={0};
	char firstPoint[100]={0};
	char lastPoint[100]={0};	
	char unit[100]={0};
	char pointCSV[100]={0};

	get_param(testNumber, "requirement", requirement, VAL_STRING, VAL_REQUIRED);

	if (getUnitInfoByRequirement(requirement, min, max, parameter, pointCSV,unit) != 0)
		return 1;
	//kim na
	if ( (strstr(min,"N")!=NULL) && (strstr(max,"N")!=NULL) )
	{
		sprintf(DisplayMsg,"P%s=%s %s,Min=%s,Max=%s", pointCSV, "NA",unit, Low_Limit, High_Limit);
		strcpy(mtgTestStepInfo[nestNum][testNumber-1].testResultVal,DisplayMsg);
		
		return 0;	
	}
	
		
	if (ParseRange(pointCSV, "-", firstPoint, lastPoint))
	{
		for (int i=atoi(firstPoint);i<=atoi(lastPoint);i++)
		{
			Read_Point(NarrowBand_Sensor[nestNum],i, &value,&ret_val);
			ret_val |= CompareValueWithLimits (requirement, value, Low_Limit, High_Limit );
			NonBlockDelay(0.2);
			if (i!=atoi(firstPoint))
			{
				strcat(mtgTestStepInfo[nestNum][testNumber-1].testResultVal,",");	
			}
			sprintf(LogMsg,"P%d=%s,Min=%s,Max=%s", i, value, Low_Limit, High_Limit);
			strcat(mtgTestStepInfo[nestNum][testNumber-1].testResultVal,LogMsg);
			addReadPointResultsToIts(testNumber,nestNum,i,value, Low_Limit, High_Limit,ret_val);
		}
	}
	else
	{
		point =atoi(pointCSV);
		Read_Point(NarrowBand_Sensor[nestNum],point, &value,&ret_val); 
    	ret_val |= CompareValueWithLimits (requirement, value, Low_Limit, High_Limit );  
		sprintf(LogMsg,"P%s=%s,Min=%s,Max=%s", pointCSV, value, Low_Limit, High_Limit);			
		sprintf(DisplayMsg,"P%s=%s %s,Min=%s,Max=%s", pointCSV, value,unit, Low_Limit, High_Limit);
		strcat(mtgTestStepInfo[nestNum][testNumber-1].testResultVal,DisplayMsg);
		addReadPointResultsToIts(testNumber,nestNum,point, value, Low_Limit, High_Limit,ret_val);           
	
	}
	
	return ret_val;//Need to make sure ret_val is 0 when read_point function succesfull
}

/********************************************//**
* Write the specified point 
***********************************************/
bool WritePoint(int testNumber, int nestNum)   
{
	char Point[25],ValueToWrite[25] = {0};
	char LogMsg[256]={0};
	unsigned short point=0;
	
		get_param(testNumber, "Value", ValueToWrite, VAL_STRING, VAL_REQUIRED);
		get_param(testNumber, "Point", Point, VAL_STRING, VAL_REQUIRED);
		point =atoi(Point);
		write_to_point(NarrowBand_SensorComm_Handle[nestNum],point, ValueToWrite ,&NBProtocol_Status[nestNum]); 

		sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "RetValue=%d", NBProtocol_Status[nestNum]);  
		addWriteToPointResultsToIts(testNumber,nestNum,point, ValueToWrite, ValueToWrite, "NA", NBProtocol_Status[nestNum]);
     
	
	return NBProtocol_Status[nestNum];//Need to make sure NBProtocol_Status[nestNum] is 0 when read_point function succesfull
}

/********************************************//**
* Write points from mailbox file 
***********************************************/
bool WriteNBMailboxPoints(int testNumber, int nestNum)
{
	bool bRet;
	int	status;
	char DisplayMsg[2000]={0};  //was 512  
	char ITACMsg[2000]={0};		//was 512 
	
	char LogMsg[256]={0};
	
	status = 0;

	if(NBMailboxFileExists)
	{
	

		status = WriteMailboxPoints(testNumber, nestNum, NarrowBand_SensorComm_Handle[nestNum]);
		
		if(status)
		{
			CreateReportWriteMailbox(DisplayMsg,ITACMsg);
			strcat(DisplayMsg,"FAIL,");
			strcat(mtgTestStepInfo[nestNum][testNumber-1].testResultVal,DisplayMsg);
			bRet = TRUE;
			
			
			
		}
		else
		{
			CreateReportWriteMailbox(DisplayMsg,ITACMsg);
			strcat(DisplayMsg,"PASS,");
			strcat(mtgTestStepInfo[nestNum][testNumber-1].testResultVal,DisplayMsg);
			bRet = FALSE;

		}
			
			addWriteNBMailboxPointsToIts(testNumber,nestNum,ITACMsg,bRet);

		
	}
	else
	{
		sprintf(LogMsg,"No mailbox file,");
		strcat(mtgTestStepInfo[nestNum][testNumber-1].testResultVal,LogMsg);
		bRet = FALSE;
	}

	return bRet;
}


/********************************************//**
* Verify mailbox file data points
***********************************************/
bool VerifyNBMailboxPoints(int testNumber, int nestNum)
{
	bool bRet;
	int status;
	char DisplayMsg[512]={0};
	char LogMsg[256]={0};
	char ITACMsg[512]={0};
	
	
	if(NBMailboxFileExists)
	{
	
		status = VerifyMailboxPoints(testNumber, nestNum, NarrowBand_Sensor[nestNum]);
		
		if(status)
		{
			CreateReportVerifyMailbox(DisplayMsg,ITACMsg);
			strcat(DisplayMsg,"FAIL,");
			strcat(mtgTestStepInfo[nestNum][testNumber-1].testResultVal,DisplayMsg);
			bRet = TRUE;
			
		}
		else
		{
			CreateReportVerifyMailbox(DisplayMsg,ITACMsg);
			strcat(DisplayMsg,"PASS,");
			strcat(mtgTestStepInfo[nestNum][testNumber-1].testResultVal,DisplayMsg);
			bRet = FALSE;
		}

		addVerifyNBMailboxPointsToIts(testNumber,nestNum,ITACMsg,bRet);
		
	}
	else
	{
		sprintf(LogMsg,"No mailbox file,");
		strcat(mtgTestStepInfo[nestNum][testNumber-1].testResultVal,LogMsg);
		bRet = FALSE;

	}
	
	return bRet;
}

 


/********************************************//**
* Write the specified point 
***********************************************/
bool WritePointCsvValue (int testNumber, int nestNum)   
{
	char Point[25] = {0};
	char LogMsg[256]={0};
	char DisplayMsg[256]={0};
	unsigned short point=0;

	char ValueToWrite[100] = {0};
	char max[100];
	char parameter[100];
	char pointCSV[100];
	char requirement[100];
	char firstPoint[100];
	char lastPoint[100];
	char unit[100]={0};
	get_param(testNumber, "requirement", requirement, VAL_STRING, VAL_REQUIRED);
	//kim NA
	
	
	if (getUnitInfoByRequirement(requirement, ValueToWrite, max, parameter, pointCSV, unit) !=0)
		return 1;
	deleteSpaces(ValueToWrite);

	if ( (strstr(ValueToWrite,"N")!=NULL) )
	{
		sprintf(DisplayMsg,"P%s=%s %s,Min=%s,Max=%s", pointCSV, ValueToWrite,unit, ValueToWrite, max);
		sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal,DisplayMsg);  
		
		return 0;	
	}
	
	
	if (ParseRange(pointCSV, "-", firstPoint, lastPoint))
	{
		for (int i=atoi(firstPoint);i<=atoi(lastPoint);i++)
		{
			 write_to_point(NarrowBand_SensorComm_Handle[nestNum],i, ValueToWrite ,&NBProtocol_Status[nestNum]); 
			 NonBlockDelay(0.2);
			if (i!=atoi(firstPoint))
			{
				strcat(mtgTestStepInfo[nestNum][testNumber-1].testResultVal,",");	
			}
			sprintf(LogMsg,"P%d=%s,Min=%s,Max=%s", i, ValueToWrite, ValueToWrite, max);
			strcat(mtgTestStepInfo[nestNum][testNumber-1].testResultVal,LogMsg);
			addWriteToPointResultsToIts(testNumber,nestNum,i, ValueToWrite, ValueToWrite, max, NBProtocol_Status[nestNum]);
			
			 
		}
	}
	
	else	
	{
		point =atoi(Point);
		write_to_point(NarrowBand_SensorComm_Handle[nestNum],point, ValueToWrite ,&NBProtocol_Status[nestNum]); 
		NonBlockDelay(0.2);
		sprintf(LogMsg,"P%s=%s,Min=%s,Max=%s", pointCSV, ValueToWrite, ValueToWrite, max);			
		sprintf(DisplayMsg,"P%s=%s %s,Min=%s,Max=%s", pointCSV, ValueToWrite,unit, ValueToWrite, max);
		strcat(mtgTestStepInfo[nestNum][testNumber-1].testResultVal,DisplayMsg);
		addWriteToPointResultsToIts(testNumber,nestNum,point, ValueToWrite, ValueToWrite, max, NBProtocol_Status[nestNum]);
		
	}
	
	
	return NBProtocol_Status[nestNum];//Need to make sure NBProtocol_Status[nestNum] is 0 when read_point function succesfull
}

/********************************************//**
* Save Configuration Points
***********************************************/
bool SaveConfigPoints (int testNumber, int nestNum)   
{
	int errorStatus;
	char LogMsg[256]={0};
	
	errorStatus = 0;
	NBProtocol_Status[nestNum] = 1;
	//Alv_NarrowBand_NBProtocol_Status    NBProtocol_StatusSave;
	
	
	int status_Save= Save_config_points(NarrowBand_SensorComm_Handle[nestNum], Alv_NarrowBand_NBProtocol_ConfigurationBlock_DSP_Dirty,&NBProtocol_Status[nestNum]);
	if (status_Save)
	{
		LogMsg;	
	}
	
	sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "Status=%d", status_Save);
	
	if(NBProtocol_Status[nestNum])
		errorStatus |= 1;
	
	
//	addSaveConfigPointsToIts(testNumber,nestNum, errorStatus);
	
	
	return status_Save;//Need to make sure status_Save is 0 when read_point function succesfull
}
/********************************************//**
* Make Debug path
***********************************************/
bool Make_Path (int testNumber, int nestNum)   
{
	int MakePath_ret=-1; 
	char Path[512]= "C:\\NB_Project\\Main\\Log";
	char LogMsg[512]={0};
	char TxCal[512]={0};
	
		get_param(testNumber, "Path", Path, VAL_STRING, VAL_REQUIRED);
		get_param(testNumber, "description", TxCal, VAL_STRING, VAL_REQUIRED);
		MakePath(Test_Mfg_MfgTester_Handle[nestNum], Path,TxCal, &MakePath_ret); 
	
	
		sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "Status=%d",!MakePath_ret);
		
	//addMakePathStatusToIts(testNumber,nestNum,!MakePath_ret);//TODO

	//return MakePath_ret;  //check if InitTxCal_ret is 0 when everything pass
	return !MakePath_ret;   
}
/********************************************//**
* Force Radar Mode  to specified mode
***********************************************/
bool Force_Radar_Mode (int testNumber, int nestNum)   
{
	int errorStatus;
	char LogMsg[256]={0};
	char Mode[256]= {0};
	
	errorStatus = 0;
				  

	get_param(testNumber, "Mode", Mode, VAL_STRING, VAL_REQUIRED);

	if(stricmp(Mode,"RCTA")==0)
		ForceRadarMode (NarrowBand_SensorComm_Handle[nestNum],Alv_NarrowBand_NBProtocol_ControlRadarMode_RCTA,&NBProtocol_Status[nestNum]); 
	if(stricmp(Mode,"BSD")==0)
		ForceRadarMode (NarrowBand_SensorComm_Handle[nestNum],Alv_NarrowBand_NBProtocol_ControlRadarMode_BSD,&NBProtocol_Status[nestNum]);
	if(stricmp(Mode,"LCA")==0)
		ForceRadarMode (NarrowBand_SensorComm_Handle[nestNum],Alv_NarrowBand_NBProtocol_ControlRadarMode_LCA,&NBProtocol_Status[nestNum]);
	if(stricmp(Mode,"Automatic")==0)
		ForceRadarMode (NarrowBand_SensorComm_Handle[nestNum],Alv_NarrowBand_NBProtocol_ControlRadarMode_Automatic,&NBProtocol_Status[nestNum]);

	sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "Status=%d",NBProtocol_Status[nestNum]);

	if(NBProtocol_Status[nestNum])
		errorStatus;
		
	//addForce_Radar_ModeToIts(testNumber,nestNum, Mode, errorStatus); 

	
	return NBProtocol_Status[nestNum];  //check if InitTxCal_ret is 0 when everything pass
	NonBlockDelay(0.200); 
	//return 0;
}

/********************************************//**
* Get Occupied Bw for Specified Mode
***********************************************/   //aa checking BW Limits
bool GetOccupiedBw (int testNumber, int nestNum)   
{
	
	char LogMsg[256]={0};
	char Mode[256]= {0};
	double modetime=0;
	double banndwidth_ref=0;
	double Bandwidth=999*1000000;
	double RCTA_Bandwidth=0;
	double BSD_Bandwidth=0;
	double LCA_Bandwidth=0;
	double Automatic_Bandwidth=0;
	
	char requirement[100] = {0};
	char High_Limit[100] = {0};
	char Low_Limit[100] = {0};
	char parameter[100] = {0};
	char pointCSV[100] = {0};
	char unit[100]={0};
	
	int returnVal =1;
	
		get_param(testNumber, "Mode", Mode, VAL_STRING, VAL_REQUIRED);
		get_param(testNumber, "Mode_time", &modetime, VAL_DOUBLE, VAL_REQUIRED);
		get_param(testNumber, "requirement", &requirement, VAL_STRING, VAL_REQUIRED);//csv 

		//kim NA
		if (getUnitInfoByRequirement(requirement, Low_Limit, High_Limit, parameter, pointCSV,unit) != 0)
			return 1;
		if ( (strstr(High_Limit,"N")!=NULL) )
		{
			sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "Bandwidth=%s %s,Min=%s,Max=%s","NA",unit, Low_Limit,High_Limit); 		
			return 0;	
		}
		
		sscanf(High_Limit,"%lf",&banndwidth_ref);
		
		if(stricmp(Mode,"RCTA")==0)
			{
				OccupiedBW(Test_Mfg_MfgTester_Handle[nestNum],Alv_NarrowBand_NBProtocol_ControlRadarMode_RCTA,modetime, &Bandwidth, &returnVal);
				Bandwidth = Bandwidth/1000000;
				
				
				if ((Bandwidth<banndwidth_ref) && returnVal)
					{
					 returnVal =0; 
			
					}
					
			}
			
		if(stricmp(Mode,"BSD")==0)
			{
			
				OccupiedBW(Test_Mfg_MfgTester_Handle[nestNum],Alv_NarrowBand_NBProtocol_ControlRadarMode_BSD,modetime, &Bandwidth, &returnVal); 
			Bandwidth = Bandwidth/1000000; 
			if ((Bandwidth<banndwidth_ref) && returnVal)
					{
					 returnVal =0; 		   
					}
			
			}
			
		if(stricmp(Mode,"LCA")==0)
			{
				OccupiedBW(Test_Mfg_MfgTester_Handle[nestNum],Alv_NarrowBand_NBProtocol_ControlRadarMode_LCA,modetime, &Bandwidth, &returnVal);
				Bandwidth = Bandwidth/1000000;  
				if ((Bandwidth<banndwidth_ref) && returnVal)
					{
					 returnVal =0;
					}
			 		
			} 
		if(stricmp(Mode,"Automatic")==0)
			{
				OccupiedBW(Test_Mfg_MfgTester_Handle[nestNum],Alv_NarrowBand_NBProtocol_ControlRadarMode_Automatic,modetime, &Bandwidth, &returnVal);
				Bandwidth = Bandwidth/1000000;  
				if ((Bandwidth<banndwidth_ref) && returnVal)
					{
					 returnVal =0;
					}
			 		
			}
			sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "Bandwidth=%f %s,Min=%s,Max=%s",Bandwidth,unit, Low_Limit,High_Limit);  
			sprintf(LogMsg,"%.3f", Bandwidth);
			add_data_to_test_output_log(nestNum,LogMsg);
			
	addGetOccupiedBwToIts(testNumber,nestNum, Mode, Bandwidth,unit, Low_Limit,High_Limit, returnVal);
	
	return returnVal;  //check if InitTxCal_ret is 0 when everything pass 
	 //return 0;
}
/********************************************//**
* Select Tx Antenna
***********************************************/
bool Select_TX_Antenna (int testNumber, int nestNum)   
{
	int errorStatus;
	char LogMsg[256]={0};
	char Mode[256]= {0};

		get_param(testNumber, "Antenna", Mode, VAL_STRING, VAL_REQUIRED);
	
		if(stricmp(Mode,"Antenna1")==0)
			SelectTxAntenna(NarrowBand_SensorComm_Handle[nestNum],Alv_NarrowBand_NBProtocol_Antenna_Antenna1,&NBProtocol_Status[nestNum]); 
		if(stricmp(Mode,"Antenna2")==0)
			SelectTxAntenna(NarrowBand_SensorComm_Handle[nestNum],Alv_NarrowBand_NBProtocol_Antenna_Antenna2,&NBProtocol_Status[nestNum]);
		if(stricmp(Mode,"Automatic")==0)
			SelectTxAntenna(NarrowBand_SensorComm_Handle[nestNum],Alv_NarrowBand_NBProtocol_Antenna_Automatic,&NBProtocol_Status[nestNum]);
	
		sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "Status=%d",NBProtocol_Status[nestNum]);
	
		if(NBProtocol_Status[nestNum])
			errorStatus |= 1;

		addSelect_TX_AntennaToIts(testNumber,nestNum, Mode, errorStatus);
		
		
		
	return NBProtocol_Status[nestNum];  //check if InitTxCal_ret is 0 when everything pass
}


/********************************************//**
* Set CW Mode
***********************************************/
bool SetCWMode (int testNumber, int nestNum)   
{
	char LogMsg[256]={0};
	int mode=0;
	int error=1;

		get_param(testNumber, "Mode", &mode, VAL_INTEGER, VAL_REQUIRED);
		error = SET_CW_Mode(Test_SensorControl_Handle[nestNum],mode);  
	
		sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "Mode=%d",mode);
		
		//addSetCWModeToIts(testNumber,nestNum, mode, error);
		
	return error;  //check if InitTxCal_ret is 0 when everything pass
}
/********************************************//**
* Set Tx Power cal Honda
***********************************************/
bool SetHondaTxPowerCal (int testNumber, int nestNum)   
{
	char LogMsg[512]={0};
	char LogMsgTmp[512]={0};
	
	int gain_min=0;
	int returnVal = 0;
	double pow_min=0;
	double pow_max=0;
	double * Power_Honda_points;
	ssize_t pLength1;
	ssize_t pLength2;
	char temp[256];
	char *value; 
	char Low_Limit[25] = {0};
	char High_Limit[25] = {0};
	unsigned short point=0;
//	char DisplayMsg[BUFFER_SIZE]={0};
	
	char DisplayMsg[512]={0};
	
	
	char parameter[100]={0};
	char min[100]={0};
	char max[100]={0};
	char charVal[100]={0};
	char unit[100]={0};
	char pointCSV[100]={0};
	
	char *pch;

	char Requirements[] = {"Tx_H_CAL_05,Tx_H_CAL_07,Tx_H_CAL_08,Tx_H_CAL_09,Tx_H_CAL_10"};

	get_param(testNumber, "MinPower", &pow_min, VAL_DOUBLE, VAL_REQUIRED);
	get_param(testNumber, "MaxPower", &pow_max, VAL_DOUBLE, VAL_REQUIRED);
	get_param(testNumber, "MinGain", &gain_min, VAL_INTEGER, VAL_REQUIRED);

	TxPowerCalHonda(Test_Mfg_MfgTester_Handle[nestNum], gain_min,pow_min, pow_max,&Power_Honda_points,&pLength1, &pLength2,&returnVal);
	sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "Power=%lf Min=%lf Max=%lf Return Val= %d",*Power_Honda_points, pow_min, pow_max, returnVal); 

	
	if (returnVal!=1)
	{
		addFailFctResultsToIts(testNumber,nestNum,"TxPowerCalHonda", "Fail", "", "", !returnVal);		
		return 1;
	}
	
	if ((*Power_Honda_points > pow_max) || (*Power_Honda_points < pow_min))
		 returnVal = 0;
	
	sprintf(charVal,"%lf",*Power_Honda_points);
	sprintf(min,"%lf",pow_min);
	sprintf(max,"%lf",pow_max);
	
	addFailFctResultsToIts(testNumber,nestNum,"TxPowerCalHonda", charVal, min, max, !returnVal);		
//	addFailFctResultsToIts(testNumber,nestNum,"TxPowerCalHonda", "Pass", !returnVal);	
//	addSetHondaTxPowerCalToIts(testNumber,nestNum, value, Low_Limit, High_Limit , returnVal);
	add_data_to_test_output_log(nestNum,charVal);  //add value to log
	
	if (returnVal!=1)
		return 1;	
	
/////////////////////////////
	
	pch = strtok(Requirements,",");	
	while (pch != NULL)
	{
		
		if (getUnitInfoByRequirement(pch, Low_Limit, High_Limit, parameter, pointCSV,unit) != 0)
			return 1;
		if ( (strstr(Low_Limit,"N")!=NULL) && (strstr(High_Limit,"N")!=NULL) )
		{
			sprintf(DisplayMsg,",P%s=%s %s,Min=%s,Max=%s", pointCSV, "NA",unit, Low_Limit, High_Limit);
			strcat(mtgTestStepInfo[nestNum][testNumber-1].testResultVal,DisplayMsg);
			strcat(LogMsgTmp,"NA");
			strcat(LogMsgTmp,","); 
			pch=strtok(NULL,",");
			
			continue;
		}
		
		point =atoi(pointCSV);
		
		Read_Point(NarrowBand_Sensor[nestNum],point, &value,&returnVal); 
		
    	returnVal |= CompareValueWithLimits (pch, value, Low_Limit, High_Limit );  
		
		
		sprintf(DisplayMsg,",P%d=%s,Min=%s,Max=%s", point, value, Low_Limit, High_Limit);
		addReadPointResultsToIts(testNumber,nestNum,point, value, Low_Limit, High_Limit, returnVal);     		
		strcat(mtgTestStepInfo[nestNum][testNumber-1].testResultVal,DisplayMsg);
		strcat(LogMsgTmp,value);
		strcat(LogMsgTmp,",");
		
		pch=strtok(NULL,",");
	
	}
	CopyString(LogMsg,0,LogMsgTmp,0,strlen(LogMsgTmp)-1);
	add_data_to_test_output_log(nestNum,LogMsg);
 
//	sprintf(LogMsg,"Power_Honda=%f\n", Power_Honda_points);

	return returnVal;  //check if status is 0 when everything pass
}

/********************************************//**
* Set Tx Power cal GM
***********************************************/
bool SetGMTxPowerCal (int testNumber, int nestNum)   
{
	char LogMsg[512]={0};
	char LogMsgTmp[512]={0};
	
	double TX1powmax_bsd,TX1powmin_bsd,TX1powmax_rcta,TX1powmin_rcta;
	double TX2powmax_bsd,TX2powmin_bsd,TX2powmax_rcta,TX2powmin_rcta;
	double *power1;

	ssize_t powerLengt;
	ssize_t ampLengt;
	ssize_t swLength;
	ssize_t pdetLengt;

	unsigned short *amp; 
	unsigned short *sw; 
	unsigned short *pdet;

	unsigned short thermistor; 
	int returnVal;	
	
	char *value; 
	char Low_Limit[25] = {0};
	char High_Limit[25] = {0};
	unsigned short point=0;
	
	char DisplayMsg[512]={0};
	char parameter[100]={0};
	char unit[100]={0}; 
	char min[100]={0};
	char max[100]={0};
	char pointCSV[100]={0};
	char *pch;

	char Requirements[512] = {0};
	

	//Tx1 BSD Mode Peak CW EIRP
	if (getUnitInfoByRequirement("Tx_H_CAL_01", min, max, parameter, pointCSV,unit) != 0)
		return 1;
	sscanf(min,"%lf",&TX1powmin_bsd);
	sscanf(max,"%lf",&TX1powmax_bsd);

	//Tx2 BSD Mode Peak CW EIRP
 	if (getUnitInfoByRequirement("Tx_H_CAL_02", min, max, parameter, pointCSV,unit) != 0)
		return 1;
	sscanf(min,"%lf",&TX2powmin_bsd);
	sscanf(max,"%lf",&TX2powmax_bsd);

	//Tx1 RCTA Mode Peak CW EIRP
	if (getUnitInfoByRequirement("Tx_H_CAL_03", min, max, parameter, pointCSV,unit) != 0)
		return 1;	
	sscanf(min,"%lf",&TX1powmin_rcta);
	sscanf(max,"%lf",&TX1powmax_rcta);
	
	//Tx2 RCTA Mode Peak CW EIRP 	
	if (getUnitInfoByRequirement("Tx_H_CAL_04", min, max, parameter, pointCSV,unit) != 0)
		return 1;
	sscanf(min,"%lf",&TX2powmin_rcta);
	sscanf(max,"%lf",&TX2powmax_rcta);	


	TxPowerCalGM(Test_Mfg_MfgTester_Handle[nestNum],TX1powmax_bsd, TX1powmax_rcta,TX1powmin_bsd, TX1powmin_rcta, &power1, 
				 &powerLengt,&amp, &ampLengt,&sw, &swLength,&pdet, &pdetLengt,&thermistor, &returnVal);
	
	
	sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "GM PW Power=%lf Return Val= %d",*power1, returnVal); 
	
	
	if (returnVal!=1)
	{
		addFailFctResultsToIts(testNumber,nestNum,"TxPowerCalGM", "Fail", !returnVal);		
		return 1;
	}
	addFailFctResultsToIts(testNumber,nestNum,"TxPowerCalGM", "Pass", !returnVal);	
/////////////////////////////
	//create Tx_H_CAL_05,Tx_H_CAL_06,...,Tx_H_CAL_17 
	for (int i =5; i<18; i++)
	{
		if (i==5)
			sprintf(Requirements + strlen(Requirements),"Tx_H_CAL_%02d",i);
		else
			sprintf(Requirements + strlen(Requirements),",Tx_H_CAL_%02d",i);  
		
	}	
	pch = strtok(Requirements,",");	
	while (pch != NULL)
	{
		
		if (getUnitInfoByRequirement(pch, Low_Limit, High_Limit, parameter, pointCSV,unit) != 0)
			return 1;
		if ( (strstr(Low_Limit,"N")!=NULL) && (strstr(High_Limit,"N")!=NULL) )
		{
			sprintf(DisplayMsg,",P%s=%s %s,Min=%s,Max=%s", pointCSV, "NA",unit, Low_Limit, High_Limit);
			strcat(mtgTestStepInfo[nestNum][testNumber-1].testResultVal,DisplayMsg);
			strcat(LogMsgTmp,"NA");
			strcat(LogMsgTmp,","); 
			pch=strtok(NULL,",");
			
			continue;
		}
		
		point =atoi(pointCSV);
		
		Read_Point(NarrowBand_Sensor[nestNum],point, &value,&returnVal); 
		
    	returnVal |= CompareValueWithLimits (pch, value, Low_Limit, High_Limit );  
		
		
		sprintf(DisplayMsg,",P%d=%s,Min=%s,Max=%s", point, value, Low_Limit, High_Limit);
		addReadPointResultsToIts(testNumber,nestNum,point, value, Low_Limit, High_Limit, returnVal);     		
		strcat(mtgTestStepInfo[nestNum][testNumber-1].testResultVal,DisplayMsg);
		strcat(LogMsgTmp,value);
		strcat(LogMsgTmp,",");
		
		pch=strtok(NULL,",");
	
	}
	CopyString(LogMsg,0,LogMsgTmp,0,strlen(LogMsgTmp)-1);
	add_data_to_test_output_log(nestNum,LogMsg);
	
	return returnVal;  //check if status is 0 when everything pass
}


/********************************************//**
* Get Tx Power
***********************************************/
bool GetTxPower (int testNumber, int nestNum)   
{
	
	char LogMsg[256],Mode[256]={0};
	int returnVal =-1;
	double main_power=9999;
	double high_power=0;
	
	char High_Limit[100] = {0};
	char Low_Limit[100] = {0};
	char parameter[100] = {0};
	char pointCSV[100] = {0};
	char requirement[100] = {0};
	char unit[100]={0};
	get_param(testNumber, "requirement", &requirement, VAL_STRING, VAL_REQUIRED);//csv 
	//Kim NA
	if (getUnitInfoByRequirement(requirement, Low_Limit, High_Limit, parameter, pointCSV,unit) != 0)
		return 1;
	
	if ( (strstr(High_Limit,"N")!=NULL) )
	{
		sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "Power=%s %s,Min=%s,Max=%s","NA",unit, Low_Limit,High_Limit); 		
		return 0;	
	}
	
	sscanf(High_Limit,"%lf",&high_power);

	get_param(testNumber, "Antenna", Mode, VAL_STRING, VAL_REQUIRED);  
		
		if(stricmp(Mode,"Antenna1")==0) 
			Get_TxPower(Test_Mfg_MfgTester_Handle[nestNum], &main_power,Alv_NarrowBand_NBProtocol_Antenna_Antenna1,&returnVal);
		if(stricmp(Mode,"Antenna2")==0) 
			Get_TxPower(Test_Mfg_MfgTester_Handle[nestNum], &main_power,Alv_NarrowBand_NBProtocol_Antenna_Antenna2,&returnVal);
		if(stricmp(Mode,"Automatic")==0) 
			Get_TxPower(Test_Mfg_MfgTester_Handle[nestNum], &main_power,Alv_NarrowBand_NBProtocol_Antenna_Automatic,&returnVal);
	 
		if (main_power > high_power)	   // check AA
			returnVal = 0;
		
		sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "Power=%f %s,Min=%s,Max=%s",main_power,unit, Low_Limit,High_Limit);  
		sprintf(LogMsg,"%f", main_power);
		add_data_to_test_output_log(nestNum,LogMsg);
		
	
	addGetTxPowerToIts(testNumber,nestNum, main_power, Low_Limit, High_Limit, returnVal );
	
	
	return !returnVal;  //check if returnVal is 0 when everything pass		//AA Check
}
/********************************************//**
* Get Center Frequency
***********************************************/
bool GetCenterFrequency (int testNumber, int nestNum)   
{
	char LogMsg[256],Mode[256]={0};
	int returnVal =-1;
	double main_frequency=0;
	double lowLimit=0; 
	double highLimit=0; 
	char High_Limit[100] = {0};
	char Low_Limit[100] = {0};
	char parameter[100] = {0};
	char pointCSV[100] = {0};
	char requirement[100] = {0};
	char unit[100]={0};
	get_param(testNumber, "requirement", &requirement, VAL_STRING, VAL_REQUIRED);//csv 
		// KIM NA

		
	if (getUnitInfoByRequirement(requirement, Low_Limit, High_Limit, parameter, pointCSV,unit) != 0)
		return 1;
	
	if (  (strstr(Low_Limit,"N")!=NULL) || (strstr(High_Limit,"N")!=NULL) )
	{
		sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "CenterFreq=%s %s,Min=%s,Max=%s","NA", unit,Low_Limit, High_Limit);  
		return 0;	
	}
	
	sscanf(Low_Limit,"%lf",&lowLimit);
	sscanf(High_Limit,"%lf",&highLimit);

	get_param(testNumber, "Antenna", Mode, VAL_STRING, VAL_REQUIRED); 
	if(stricmp(Mode,"Antenna1")==0) 
		Get_Center_Frequency (Test_Mfg_MfgTester_Handle[nestNum],Alv_NarrowBand_NBProtocol_Antenna_Antenna1,&main_frequency, &returnVal); 
		 
	if(stricmp(Mode,"Antenna2")==0) 
		Get_Center_Frequency (Test_Mfg_MfgTester_Handle[nestNum],Alv_NarrowBand_NBProtocol_Antenna_Antenna2,&main_frequency, &returnVal);
		
	if(stricmp(Mode,"Automatic")==0) 
		Get_Center_Frequency (Test_Mfg_MfgTester_Handle[nestNum],Alv_NarrowBand_NBProtocol_Antenna_Automatic,&main_frequency, &returnVal);
	

	main_frequency /= 1000000000;
	if ( (main_frequency<lowLimit) || (main_frequency>highLimit) || !returnVal)
		returnVal |= 1;
	else
		returnVal = 0;
	sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "CenterFreq=%.3f %s,Min=%s,Max=%s",main_frequency, unit,Low_Limit, High_Limit);  
	sprintf(LogMsg,"%f", main_frequency);						   
	add_data_to_test_output_log(nestNum,LogMsg);
		

		
	addGetCenterFrequencyToIts(testNumber,nestNum, main_frequency, Low_Limit, High_Limit, returnVal);
	
	
	return returnVal;  //check if returnVal is 0 when everything pass

}
/********************************************//**
* Get CW Leakage
***********************************************/
bool GetCwLeakage (int testNumber, int nestNum)   
{
	char LogMsg[256],Mode[256]={0};
	int returnVal =-1;
	double main_Leakage=-1;
	
	
	char High_Limit[100] = {0};
	char Low_Limit[100] = {0};
	char parameter[100] = {0};
	char pointCSV[100] = {0};
	double lowLimit = 0;
	char requirement[100] = {0};
	char unit[100]={0};
	get_param(testNumber, "requirement", &requirement, VAL_STRING, VAL_REQUIRED);//csv 
	
	//KIM NA
	if (getUnitInfoByRequirement(requirement, Low_Limit, High_Limit, parameter, pointCSV,unit) != 0)
		return 1;
	if (  (strstr(Low_Limit,"N")!=NULL)  )
	{
		sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "Leakage=%f %s,Min=%s,Max=%s","NA", unit,Low_Limit, High_Limit); 
		return 0;	
	}
	
	sscanf(Low_Limit,"%lf",&lowLimit);


	get_param(testNumber, "Antenna", Mode, VAL_STRING, VAL_REQUIRED); 
	if(stricmp(Mode,"Antenna1")==0) 
		Get_CwLeakage(Test_Mfg_MfgTester_Handle[nestNum],Alv_NarrowBand_NBProtocol_Antenna_Antenna1, &main_Leakage, &returnVal);
	if(stricmp(Mode,"Antenna2")==0) 
		Get_CwLeakage(Test_Mfg_MfgTester_Handle[nestNum],Alv_NarrowBand_NBProtocol_Antenna_Antenna2, &main_Leakage, &returnVal);  
	if(stricmp(Mode,"Automatic")==0) 
		Get_CwLeakage(Test_Mfg_MfgTester_Handle[nestNum],Alv_NarrowBand_NBProtocol_Antenna_Automatic, &main_Leakage, &returnVal); 

	if (returnVal == 0)
		return 1;
	
	if (main_Leakage < lowLimit )   //Check AA
		returnVal=0;
				  
	sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "Leakage=%f ,Min=%s,Max=%s",main_Leakage,Low_Limit, High_Limit);  
	sprintf(LogMsg,"%f", main_Leakage);
	add_data_to_test_output_log(nestNum,LogMsg);
		
	
	addGetCwLeakageToIts(testNumber, nestNum, main_Leakage, unit, Low_Limit, High_Limit, returnVal);
	
	return !returnVal;  //check if returnVal is 1 when everything pass		   //aa Check
}

/********************************//**
* Get NB Test dll Version Number 
************************************/
char * Get_Dll_Version (void)
{
	int error=0;
	char *VNum;
	error = getVersion(&VNum);


	return VNum;
}

/********************************************//**
* Disconnect TXCal
***********************************************/
bool DisconnectTXCal (int nestNum)   
{
	char LogMsg[256]={0};
	int returnVal=Disconnect_TxCal(Test_Mfg_MfgTester_Handle[nestNum]); 
	
	
	//	sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "ReturnVal=%d",returnVal);  
	//	add_data_to_test_output_log(nestNum,LogMsg);
	//addSetHondaTxPWCalStatusToIts(testNumber,nestNum);//TODO     
	return returnVal;  //check if returnVal is 0 when everything pass
}


/********************************************//**
* Disconnect CAN
***********************************************/
bool DisconnectCan (int nestNum)   
{
	char LogMsg[256]={0};
	int returnVal =-1;
	
		Can_Disconnect (CanComm[nestNum], &returnVal); 
	
	//	sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "ReturnVal=%d",returnVal);  
	//	add_data_to_test_output_log(nestNum,LogMsg);
	//addSetHondaTxPWCalStatusToIts(testNumber,nestNum);//TODO     
	//return returnVal;  //check if returnVal is 0 when everything pass
	return !returnVal;
}
/********************************************//**
* Discard all handles
***********************************************/
bool DiscardHanles (int nestNum)   
{
		CDotNetFreeMemory(Data[nestNum]);
		//discard handles   // NOTE - object handles must be discarded after use by calling CDotNetDiscardHandle
		CDotNetDiscardHandle(NiCan_Handle[nestNum]);
		CDotNetDiscardHandle(CanComm[nestNum]);
		CDotNetDiscardHandle(NarrowBand_SensorComm_Handle[nestNum]);
		CDotNetDiscardHandle(NarrowBand_Sensor[nestNum]); 
		CDotNetDiscardHandle(Test_SensorControl_Handle[nestNum]); 
		CDotNetDiscardHandle(Test_Mfg_MfgTester_Handle[nestNum]); 
		CDotNetDiscardHandle(Test_SensorState_Handle[nestNum]);
		CDotNetDiscardHandle(NarrowBand_UNT_DAT_Handle[nestNum]);
		//kim move outside function
		//close the dll wrappers
	//	Close_NbLib();
	//	Close_NiCanWrp ();
	//	Close_NbTest ();
	//	sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "Pass");  

	return 0;  //check if returnVal is 0 when everything pass
}
/********************************************//**
* Discard all handles
***********************************************/
bool DiscardAllHandles (void)   
{
	for (int i=0;i<NUMOFNESTS;i++)
	{
		CDotNetFreeMemory(Data[i]);
		//discard handles   // NOTE - object handles must be discarded after use by calling CDotNetDiscardHandle
		CDotNetDiscardHandle(NiCan_Handle[i]);
		CDotNetDiscardHandle(CanComm[i]);
		CDotNetDiscardHandle(NarrowBand_SensorComm_Handle[i]);
		CDotNetDiscardHandle(NarrowBand_Sensor[i]); 
		CDotNetDiscardHandle(Test_SensorControl_Handle[i]); 
		CDotNetDiscardHandle(Test_Mfg_MfgTester_Handle[i]); 
		CDotNetDiscardHandle(Test_SensorState_Handle[i]);
		CDotNetDiscardHandle(NarrowBand_UNT_DAT_Handle[i]);
	}
		//kim move outside function
		//close the dll wrappers
	//	Close_NbLib();
	//	Close_NiCanWrp ();
	//	Close_NbTest ();
	//	sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "Pass");  

	return 0;  //check if returnVal is 0 when everything pass
}

/********************************************//**
* DUT Power control
***********************************************/
bool Bat_Ctrl(int testNumber, int nestNum)
{	  
	bool state = 0;
	
 	get_param(testNumber, "STATE", &state, VAL_INTEGER, VAL_REQUIRED);
		
	setDutPower(nestNum,state);
	
	sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "%d", state); 
	
	if (state == 1)	   //Carol added - This is the proper place to add this at power on.
	{
		add_datetime_to_test_output_log(nestNum);
	}									 

	addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
	ITS_Idx[nestNum]++;
	return 0;
}
/********************************************//**
* Reset dut
***********************************************/
bool Reset_Bat(int testNumber, int nestNum)
{	  
	double delay = 0;
	
 	get_param(testNumber, "DELAY", &delay, VAL_DOUBLE, VAL_REQUIRED);
		
	setDutPower(nestNum,0);
	NonBlockDelay(delay);
	setDutPower(nestNum,1);  	
	
	sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "%lf", delay); 
	
	addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
	ITS_Idx[nestNum]++;
	return 0;
}
/********************************************//**
* Restart unit by toggle power supply OFF and ON.  
***********************************************/
bool Restart_Unit (int testNumber, int nestNum)   
{
	RestartTestUnit(nestNum);
	
	sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "%s", "Pass");

	addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
	ITS_Idx[nestNum]++;
	return 0;
} // end Restart_Unit
/********************************************//**
* Release test instrument for new RF measurement   
***********************************************/
bool Release_Test_Instrument (int testNumber, int nestNum)   
{
	UnlockTestInstrument(nestNum);
	
	sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "%i", (int)ceil((nestNum+1)/2.0));  

	addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
	ITS_Idx[nestNum]++;
	return 0;
} // end Release_Test_Instrument

/********************************************//**
* Wait for a set duration and then release dut lock 
***********************************************/
void CVICALLBACK wait_and_release_lock(void *int_time_and_dutNumber)
{
	int time = (*(int *)int_time_and_dutNumber)/10;  // Only use integer values for time.
	int dutNumber = (*(int *)int_time_and_dutNumber)%10;
	int maxDelayTimeSec = 100;
	
	if(time < maxDelayTimeSec)
	{
		NonBlockDelay(time);
	}
	UnlockOtherNest(dutNumber);
} // end wait_and_release_lock


/********************************************//**
* Release other test nest  
***********************************************/
bool Release_Other_Nest (int testNumber, int nestNum)   
{
	int error=0;
	int delay, delay_and_nestNum=0;
	char field_tmp[100];

 	if (parse(mtgTestStepInfo[0][testNumber-1].testParam, "DELAY", field_tmp))
		delay = atoi(field_tmp);
	
	delay_and_nestNum = delay * 10 + nestNum;
	if(delay > 0)
		error = PostDeferredCall(wait_and_release_lock, &delay_and_nestNum);
	else
		UnlockOtherNest(nestNum);
	
	sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "%i", nestNum+1);  
	addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
	ITS_Idx[nestNum]++;
	
	return error;
} // end Release_Other_Nest
/********************************************//**
* Initialize spectrum analyzer session   
***********************************************/
bool Init_Spec_An (int testNumber, int nestNum)   
{
	int error;
	int saIx = GetTestInstrumentNumber(nestNum);
	
	error = InitSpecAn(saIx);
	
	if(error)
		sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "%s", "Fail");  
	else
		sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "%s", "Pass");

	addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
	ITS_Idx[nestNum]++;
	return error;
} // end Init_Spec_An


/********************************************//**
* Close spectrum analyzer session   
***********************************************/
bool Close_Spec_An (int testNumber, int nestNum)   
{
	int error;
	int saIx = GetTestInstrumentNumber(nestNum);

	error = CloseSpectrum(specAn[saIx]);
	
	if(error)
		sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "%s", "Fail");  
	else
		sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "%s", "Pass");

	addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
	ITS_Idx[nestNum]++;
	return error;
} // end Close_Spec_An

/********************************************//**
* Get test instrument to perform RF measurements    
***********************************************/
static TestInstrumentLock[3]={-1,-1,-1};	// Set TestInstrumentLock state to NoLock
int LockTestInstrument(int dutNumber, int maxTimeoutSec)
{
	int error=-1, waitTimeSec = 0;
    int testInstrument = GetTestInstrumentNumber(dutNumber); 

	while(waitTimeSec++ < maxTimeoutSec)
	{
		// Continue attempt to lock test instrument if it is unlock
		if (TestInstrumentLock[testInstrument] == -1)
		{
			TestInstrumentLock[testInstrument]=dutNumber;
			setTestInstrumentPath(dutNumber);
			error = 0;
			break;
		}
		else
			NonBlockDelay(1);
	}
	return(error);
} // end GetTestInstrument

/********************************************//**
* Get available test instrument for RF measurement    
***********************************************/
bool Get_Test_Instrument (int testNumber, int nestNum)   
{
	int error;
	
   	error = LockTestInstrument(nestNum, 200); // Wait for upto 200 seconds.
		
	if(error)
		sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "%i", -1); 
	else
		sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "%i", (int)ceil((nestNum+1)/2.0));

	addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
	ITS_Idx[nestNum]++;
	return error;
} // end Get_Test_Instrument




bool Get_Test_InstrumentDbg(int nestNum)   
{
	int error;
	
   	error = LockTestInstrument(nestNum, 200); // Wait for upto 200 seconds.
		
	//if(error)
	//	sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "%i", -1); 
	//else
	//	sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "%i", (int)ceil((nestNum+1)/2.0));

	//addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
	//ITS_Idx[nestNum]++;
	return error;
} // end Get_Test_Instrument


/********************************************//**
* Release test instrument to perform a new RF measurements    
***********************************************/
int UnlockTestInstrument(int dutNumber)
{
	int testInstrument = GetTestInstrumentNumber(dutNumber); 
	
	// Release the lock only if this dut holds it
	if (TestInstrumentLock[testInstrument]==dutNumber)
	{
		TestInstrumentLock[testInstrument]=-1;  // unlock test instrument
	}
	return(0);
} // end ReleaseTestInstrument


/********************************************//**
* Get test instrument number from dutNumber     
***********************************************/
int GetTestInstrumentNumber(int nestNum)
{
	/////////////////////////////////////////////
	// TestInstrument		NestNumber
	// 	0				[0,1]				
	//  1				[2,3]				
	//  2				[4,5]				
	///////////////////////////////////////////// 
	return(nestNum/2);
} // end GetTestInstrumentNumber


/********************************************//**
* Restart test unit by toggle power supply OFF and ON.  Allow 3.5sec for unit to reboot        
***********************************************/
void RestartTestUnit(int testUnit)
{
	setDutPower(testUnit,0);
	NonBlockDelay(0.05);
	setDutPower(testUnit,1);
} // end RestartTestUnit


/********************************************//**
* Get test limits  
***********************************************/
void GetTestStepLimits(void)
{
//	char field_tmp[100]; 
//	for (int i=0; i<testARRAY_SIZE; i++)
//	{
//		if (strstr(mtgTestStepInfo[0][i].testFuncName,"AnalogVoltMeas") != NULL)
//		{
	char min[100];
	char max[100];
	char parameter[100];
	char requirement[100] = "Tx_H_MEAS_01";
	char point[100];
	char unit[100]={0};
	if (getUnitInfoByRequirement(requirement, min, max, parameter, point,unit) != 0)
		return 1;
	
	sscanf(min,"%lf",&CurrentLowLimit);
	sscanf(max,"%lf",&CurrentHighLimit);
	CurrentLowLimit = CurrentLowLimit;
	CurrentHighLimit = CurrentHighLimit;

	//		get_param(i+1, "LOW", &CurrentLowLimit, VAL_DOUBLE, VAL_REQUIRED);
	//		get_param(i+1, "HIGH", &CurrentHighLimit, VAL_DOUBLE, VAL_REQUIRED);
//		}
//	} // end for loop
	
} // end GetTestStepLimits


// test condition
/********************************************//**
* Set DUT LED indicators 
***********************************************/
void setDutIndicators (int dutNumber, int setPass, int setBusy, int setFail) 
{
	
	setLedGood(dutNumber,setPass);
	if(setPass)
	{
		StatusBoxAttribute(dutNumber, "PASS", VAL_GREEN, VAL_BLACK, 35);
		UnitsAreTestingCount--;
	}
	
	setLedBusy(dutNumber,setBusy);
	if(setBusy)
	{
		StatusBoxAttribute(dutNumber, "TESTING", VAL_YELLOW, VAL_BLACK, 35);
		UnitsAreTestingCount++;
	}
	
	setLedFail(dutNumber,setFail);
	if(setFail)
	{
		StatusBoxAttribute(dutNumber, "FAIL", VAL_RED, VAL_BLACK, 35);
		UnitsAreTestingCount--;
	}
	
} // end setDutIndicators


/*********************************************************************/ 
/********************************************//**
* Reset test station valve, power, LED and instrument
***********************************************/
void resetTestStation(void)
{
	// disconnect unit, turn off power, reset instrument
	for(int i=0; i<totalNest; i++)
	{
		setSelectValve(i,0);
		setDutPower(i,0);  
		//setDutIndicators (i, 0, 0, 0);   
		
	}
//	for(int i=0; i<NUMBER_OF_TEST_INSTRUMENTS; i++)
//	{
//		//SetSpectrumPreset(specAn[i]);
//	}
	UnitsAreTestingCount = 0;
} // end resetTestStation

/*********************************************************************/ 
/********************************************//**
* Reset test nest valve, power and LED 
***********************************************/
void resetNest(int nestNum)
{

	setDutIndicators (nestNum, 0, 0, 0); 

	setSelectValve(nestNum,0);
	setDutPower(nestNum,0);
	
	StatusBoxAttribute(nestNum, "WAITING...", VAL_BLUE, VAL_WHITE, 35);
	MsgBoxAttribute(nestNum, "Place Unit\n to start testing", 0x00E0E0E0, VAL_BLACK, 35);


} // end resetNest

/*********************************************************************/ 
/********************************************//**
* Recycle the test station power 
***********************************************/
void powerTestStation(int state)
{
	setCtrlPower24VDC(state);
}  // end powerTestStation


/********************************************//**
* Clear all LED of a selected nest number
***********************************************/
void clearNestLed(int nestNum)
{
	// TODO: ID 24 (clear all LEDs in test initialization)
	setDutIndicators (nestNum, 0, 0, 0);    	
}  // end clearNestLed

/********************************************//**
* Get number of running board
***********************************************/
int GetNumberOfRunningBoard(void)
{
	int numberOfRunningBoard = 0;
	for(int i=0; i<totalNest; i++)
	{
		if (BoardRunning[i]==1)
		{
			numberOfRunningBoard++;
		}
	}
	return(numberOfRunningBoard);
} // end GetNumberOfRunningBoard

/********************************************//**
* Reset ITAC Test Step for a nest  
***********************************************/
void resetItacTestStep(int nestNum)
{
	for(int j=0; j<testARRAY_SIZE; j++)
	{
		//clearItacTestStep(nestNum,j);
	}
	ITS_Idx[nestNum]=0;
} // end resetItacTestStep

/********************************************//**
* Add a test data to ITAC Test Step using mtgTestStepInfo
***********************************************/
void addItacTestStep(int testNumber,int nestNum, int itsTestNumber)
{
	sprintf(mtgItacTestStep[nestNum][itsTestNumber].testNum,"%i",itsTestNumber);
	//strcpy(mtgItacTestStep[nestNum][itsTestNumber].testName,mtgTestStepInfo[nestNum][testNumber-1].testName);  
	sprintf(mtgItacTestStep[nestNum][itsTestNumber].testName,"T%i_%s",testNumber,mtgTestStepInfo[nestNum][testNumber-1].testName);
	strcpy(mtgItacTestStep[nestNum][itsTestNumber].testFuncName,mtgTestStepInfo[nestNum][testNumber-1].testFuncName);  
	strcpy(mtgItacTestStep[nestNum][itsTestNumber].testSkip,mtgTestStepInfo[nestNum][testNumber-1].testSkip);  
	strcpy(mtgItacTestStep[nestNum][itsTestNumber].testType,mtgTestStepInfo[nestNum][testNumber-1].testType);  
	strcpy(mtgItacTestStep[nestNum][itsTestNumber].testAbort,mtgTestStepInfo[nestNum][testNumber-1].testAbort);  
	strcpy(mtgItacTestStep[nestNum][itsTestNumber].testLowLimit,"");  
	strcpy(mtgItacTestStep[nestNum][itsTestNumber].testHighLimit,"");  
	strcpy(mtgItacTestStep[nestNum][itsTestNumber].testUnit,""); 
	strcpy(mtgItacTestStep[nestNum][itsTestNumber].testResult,mtgTestStepInfo[nestNum][testNumber-1].testResult);  
	strcpy(mtgItacTestStep[nestNum][itsTestNumber].testNest,mtgTestStepInfo[nestNum][testNumber-1].testNest);  
	strcpy(mtgItacTestStep[nestNum][itsTestNumber].testResultVal,mtgTestStepInfo[nestNum][testNumber-1].testResultVal);  
}// end add_Bat_Ctrl_to_Itac_Upload

/********************************************//**
* Add Sensor Temperature to ITAC Test Step
***********************************************/
void addSensorTemperatureToIts(int testNumber,int nestNum,int low_thresh,int high_thresh,int temperature)
{
	addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testLowLimit,"%i",low_thresh);  
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testHighLimit,"%i",high_thresh);  
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testUnit,"C"); 
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal,"%i",temperature);  
	ITS_Idx[nestNum]++;
} // end addSensorTemperatureToIts

/********************************************//**
* Add Current Measurement data to ITAC test step
***********************************************/
void addMeasureCurrentToIts(int testNumber,int nestNum,double low_thresh,double high_thresh,double aValue, int status)
{
	addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testName,"T%i_currentMeas",testNumber);
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testLowLimit,"%.3f",low_thresh);  
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testHighLimit,"%.3f",high_thresh); 
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testUnit,"%s","mA");  
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal,"%.3f",aValue);  
	if (status == 0)	
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Pass");   
	}
	else
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Fail"); 
	}
	
	ITS_Idx[nestNum]++;
	
} // end addMeasureCurrentToIts

/********************************************//**
* Add Proceed Request data to ITAC test step 
***********************************************/
void addProceedRequestToIts(int testNumber,int nestNum, int status)
{
	char MIS_tmp[100];
	addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testName,"T%i_MIS",testNumber);
	parse(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "MIS", MIS_tmp);	    
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal,"%s",MIS_tmp);  
	
	if (status == 0)	
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Pass");   
	}
	else
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Fail"); 
	}
		ITS_Idx[nestNum]++;
	
} // end addProceedRequestToIts

/********************************************//**
* Add firmware version to ITAC test step
***********************************************/
void addFirmwareVersionToIts(int testNumber,int nestNum)
{
	char swVer_tmp[100];
	addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
	parse(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "Version", swVer_tmp);	    
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal,"%s",swVer_tmp);  
	ITS_Idx[nestNum]++;
} // end addFirmwareVersionToIts

/********************************************//**
* Add CrossOver Frequency calibration to ITAC test step 
***********************************************/
void addCrossOverFrequencyToIts(int testNumber,int nestNum,int Band0_Low_FrequencyMHz,int Band0_High_FrequencyMHz,int Band1_Low_FrequencyMHz,int Band1_High_FrequencyMHz,int TransitionFrequencyMHz)
{
	// add CrossOverFrequency
	addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testName,"T%i_%s",testNumber,"TransFreq");
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal,"%i",TransitionFrequencyMHz);  
	ITS_Idx[nestNum]++;
	// add Band0 Low Frequency
	addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testName,"T%i_%s",testNumber,"Band0LowFreq");
	strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testUnit,"MHz"); 
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testLowLimit,"%i",Band0LowLimit);  
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testHighLimit,"%i",Band1HighLimit);  
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal,"%i",Band0_Low_FrequencyMHz);  
	if((Band0_Low_FrequencyMHz>=Band0LowLimit) && (Band0_Low_FrequencyMHz<=Band1HighLimit))
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Pass");   
	}
	else
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Fail"); 
	}
	ITS_Idx[nestNum]++;
	// add Band0 High Frequency
	addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testName,"T%i_%s",testNumber,"Band0HighFreq");    
	strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testUnit,"MHz"); 
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testLowLimit,"%i",Band0LowLimit);  
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testHighLimit,"%i",Band1HighLimit);  
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal,"%i",Band0_High_FrequencyMHz);  
	if((Band0_High_FrequencyMHz>=Band0LowLimit) && (Band0_High_FrequencyMHz<=Band1HighLimit))
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Pass");   
	}
	else
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Fail"); 
	}
	ITS_Idx[nestNum]++;
	// add Band1 Low Frequency
	addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testName,"T%i_%s",testNumber,"Band1LowFreq");
	strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testUnit,"MHz"); 
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testLowLimit,"%i",Band0LowLimit);  
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testHighLimit,"%i",Band1HighLimit);  
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal,"%i",Band1_Low_FrequencyMHz);  
	if((Band1_Low_FrequencyMHz>=Band0LowLimit) && (Band1_Low_FrequencyMHz<=Band1HighLimit))
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Pass");   
	}
	else
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Fail"); 
	}
	ITS_Idx[nestNum]++;
	// add Band1 High Frequency
	addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testName,"T%i_%s",testNumber,"Band1HighFreq");
	strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testUnit,"MHz"); 
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testLowLimit,"%i",Band0LowLimit);  
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testHighLimit,"%i",Band1HighLimit);  
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal,"%i",Band1_High_FrequencyMHz);  
	if((Band1_High_FrequencyMHz>=Band0LowLimit) && (Band1_High_FrequencyMHz<=Band1HighLimit))
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Pass");   
	}
	else
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Fail"); 
	}
	ITS_Idx[nestNum]++;
} // end addCrossOverFrequencyToIts

/********************************************//**
* At Tx UWB power calibration to ITAC test step
***********************************************/
void addCalTxUwbPowerToIts(int testNumber,int nestNum,double TxCalibratedUwbPeakPwr,double TxCalibratedUwbPeakFrequency,double TxAdjustmentMargin,int CalibratedDacValue,int CalibratedDACValues100MHzBins[14],double uwbDeltaPower)
{
	// add Calibrated DAC value
	addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testName,"T%i_%s",testNumber,"UWBDAC");
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testLowLimit,"%i",UwbDacLowLimit);  
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testHighLimit,"%i",UwbDacHighLimit);  
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal,"%i",CalibratedDacValue);  
	if((CalibratedDacValue>=UwbDacLowLimit) && (CalibratedDacValue<=UwbDacHighLimit))
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Pass");   
	}
	else
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Fail"); 
	}
	ITS_Idx[nestNum]++;
	// add Tx Calibrated UWB Power
	addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testName,"T%i_%s",testNumber,"UWBPeakPower");
	strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testUnit,"dB"); 
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testLowLimit,"%f",UwbPowerLowLimit);  
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testHighLimit,"%f",UwbPowerHighLimit);  
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal,"%f",TxCalibratedUwbPeakPwr); 
	if((TxCalibratedUwbPeakPwr>=UwbPowerLowLimit) && (TxCalibratedUwbPeakPwr<=UwbPowerHighLimit))
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Pass");   
	}
	else
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Fail"); 
	}
	ITS_Idx[nestNum]++;
	// add Tx Calibrated UWB Frequency
	addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testName,"T%i_%s",testNumber,"UWBPeakFreq");
	strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testUnit,"Hz"); 
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal,"%f",TxCalibratedUwbPeakFrequency);  
	ITS_Idx[nestNum]++;
	// add Calibrated DAC Values in 100 MHz bins
	for(int i=0; i<14; i++)
	{
		addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
		sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testName,"T%i_Bins_%i",testNumber,i);
		sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal,"%i",CalibratedDACValues100MHzBins[i]);  
		ITS_Idx[nestNum]++;
	}
	// add Tx Adjustment Margin 
	addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testName,"T%i_%s",testNumber,"UWBCalMargin");
	strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testUnit,"dB"); 
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testLowLimit,"%f",UwbCalMarginLowLimit);  
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal,"%f",TxAdjustmentMargin); 
	if(TxAdjustmentMargin>=UwbCalMarginLowLimit)
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Pass");   
	}
	else
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Fail"); 
	}
	ITS_Idx[nestNum]++;
	
	// add UWB Delta Power
	addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testName,"T%i_%s",testNumber,"UWBDeltaPower");
	strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testUnit,"dB"); 
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal,"%f",uwbDeltaPower);  
	ITS_Idx[nestNum]++;
} // end addCalTxUwbPowerToIts

/********************************************//**
* Add verify calibrated UWB DAC to ITAC test step 
***********************************************/
void addVerifyCalUwbDacToIts(int testNumber,int nestNum,int ReadBackUwbDacValue)
{
	addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testName,"T%i_%s",testNumber,"ReadUwbDac");
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal,"%i",ReadBackUwbDacValue);  
	ITS_Idx[nestNum]++; 
} // end addVerifyCalUwbDacToIts

/********************************************//**
* Add ISM Pulling and Power Cal to ITAC test step 
***********************************************/
void addMeasureIsmPullingAndPowerCalToIts(int testNumber,int nestNum,double IsmPeakPower,double IsmDeltaFrequency,int calIsmDac,double DeltaIsmPowerAtMinus2_5MHz,double DeltaIsmPowerAtPlus2_5MHz)
{
	// add ISM Delta Frequency
	addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testName,"T%i_%s",testNumber,"IsmFreqDev");
	strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testUnit,"Hz"); 
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testLowLimit,"-%f",IsmFreqDevHighLimit);  
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testHighLimit,"%f",IsmFreqDevHighLimit);  
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal,"%f",IsmDeltaFrequency);  
	if(fabs(IsmDeltaFrequency)<=IsmFreqDevHighLimit) 
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Pass");   
	}
	else
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Fail"); 
	}
	ITS_Idx[nestNum]++;
	// add cal ISM DAC
	addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testName,"T%i_%s",testNumber,"IsmDac");
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testLowLimit,"%i",IsmDacLowLimit);  
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testHighLimit,"%i",IsmDacHighLimit);  
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal,"%i",calIsmDac);  
	if((calIsmDac>=IsmDacLowLimit) && (calIsmDac<=IsmDacHighLimit))
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Pass");   
	}
	else
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Fail"); 
	}
	ITS_Idx[nestNum]++;
	// add ISM Peak Power
	addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testName,"T%i_%s",testNumber,"IsmPower");
	strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testUnit,"dB"); 
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testLowLimit,"%f",IsmPowerLowLimit);  
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal,"%f",IsmPeakPower); 
	if(IsmPeakPower>=IsmPowerLowLimit)
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Pass");   
	}
	else
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Fail"); 
	}
	ITS_Idx[nestNum]++;
	// add delta ISM power at minus 2.5MHz
	addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testName,"T%i_%s",testNumber,"DeltaIsmPm2_5MHz");
	strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testUnit,"dB"); 
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal,"%f",DeltaIsmPowerAtMinus2_5MHz);  
	ITS_Idx[nestNum]++;
	// add delta ISM power at plus 2.5MHz
	addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testName,"T%i_%s",testNumber,"DeltaIsmPp2_5MHz");
	strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testUnit,"dB"); 
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal,"%f",DeltaIsmPowerAtPlus2_5MHz);  
	ITS_Idx[nestNum]++;
} // end addMeasureIsmPullingAndPowerCalToIts

/********************************************//**
* Add ISM Pulling and Power measurement to ITAC test step 
***********************************************/
void addMeasureIsmPullingAndPowerToIts(int testNumber,int nestNum,double IsmPeakPower,double IsmDeltaFrequency,double DeltaIsmPowerAtMinus2_5MHz,double DeltaIsmPowerAtPlus2_5MHz)
{
	// add ISM Delta Frequency
	addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testName,"T%i_%s",testNumber,"IsmFreqDev");
	strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testUnit,"Hz"); 
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testLowLimit,"-%f",IsmFreqDevHighLimit);  
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testHighLimit,"%f",IsmFreqDevHighLimit);  
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal,"%f",IsmDeltaFrequency); 
	if(fabs(IsmDeltaFrequency)<=IsmFreqDevHighLimit)
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Pass");   
	}
	else
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Fail"); 
	}
	ITS_Idx[nestNum]++;
	// add ISM Peak Power
	addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testName,"T%i_%s",testNumber,"IsmPower");
	strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testUnit,"dB"); 
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testLowLimit,"%f",IsmPowerLowLimit);  
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal,"%f",IsmPeakPower); 
	
	if(IsmPeakPower>=IsmPowerLowLimit)
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Pass");   
	}
	else
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Fail"); 
	}
	ITS_Idx[nestNum]++;
	// add delta ISM power at minus 2.5MHz
	addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testName,"T%i_%s",testNumber,"DeltaIsmPm2_5MHz");
	strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testUnit,"dB"); 
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal,"%f",DeltaIsmPowerAtMinus2_5MHz);  
	ITS_Idx[nestNum]++;
	// add delta ISM power at plus 2.5MHz
	addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testName,"T%i_%s",testNumber,"DeltaIsmPp2_5MHz");
	strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testUnit,"dB"); 
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal,"%f",DeltaIsmPowerAtPlus2_5MHz);  
	ITS_Idx[nestNum]++;
}  // end addMeasureIsmPullingAndPowerToIts

/********************************************//**
* Add measure UWB power check to ITAC test step 
***********************************************/
void addMeasureUwbPeakPowerToIts(int testNumber,int nestNum,double PeakPowerUWB,double PeakFrequencyUWB)
{
	// add UWB Power Check
	addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testName,"T%i_%s",testNumber,"UWBPowerCheck");
	strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testUnit,"dB"); 
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testLowLimit,"%f",UwbPowerCheckLowLimit);  
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testHighLimit,"%f",UwbPowerCheckHighLimit);  
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal,"%f",PeakPowerUWB); 
	
	if((PeakPowerUWB>=UwbPowerCheckLowLimit) && (PeakPowerUWB<=UwbPowerCheckHighLimit))
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Pass");   
	}
	else
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Fail"); 
	}
	ITS_Idx[nestNum]++;
	// add UWB Frequency Check
	addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testName,"T%i_%s",testNumber,"UWBFreqCheck");
	strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testUnit,"Hz"); 
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal,"%f",PeakFrequencyUWB);  
	ITS_Idx[nestNum]++;
} // end addMeasureUwbPeakPowerToIt

/********************************************//**
* Add Measure Tx Difference power to ITAC test step 
***********************************************/
void addMeasureTxDiffPowerToIts(int testNumber,int nestNum,double TxDiffRes[6])
{
	// add Tx Difference Power
	for(int i=0; i<6; i++)
	{
		addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
		sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testName,"T%i_TxDiff_%i",testNumber,24600+i*200);
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testUnit,"dB"); 
		sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testLowLimit,"-%f",TxDiffLowLimit);  
		sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testHighLimit,"%f",TxDiffHighLimit);  
		sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal,"%f",TxDiffRes[i]);  
	
		if((TxDiffRes[i]>=TxDiffLowLimit) && (TxDiffRes[i]<=TxDiffHighLimit))
		{
			strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Pass");   
		}
		else
		{
			strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Fail"); 
		}
		ITS_Idx[nestNum]++;
	}
}  // end addMeasureTxDiffPowerToIts

/********************************************//**
* Add Measure Tx Isolation power to ITAC test step 
***********************************************/
void addMeasureTxIsolationPowerToIts(int testNumber,int nestNum,double TxIsolationDiffRes[6])
{
	// add Tx Isolation Power
	for(int i=0; i<6; i++)
	{
		addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
		sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testName,"T%i_TxIsol_%i",testNumber,24600+i*200);
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testUnit,"dB"); 
		sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testLowLimit,"-%f",TxIsolLowLimit);  
		sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal,"%f",TxIsolationDiffRes[i]);  
		
		if(TxIsolationDiffRes[i]>=TxIsolLowLimit)
		{
			strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Pass");   
		}
		else
		{
			strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Fail"); 
		}
		ITS_Idx[nestNum]++;
	}
} // end addMeasureTxIsolationPowerToIts

/********************************************//**
* Add measure Tx Isolation power at Cal UWB DAC to ITAC test step 
***********************************************/
void addMeasureTxIsolationAtCalUwbToIts(int testNumber,int nestNum,double TxIsolationResAtCalUwbDac[6])
{
	// add Tx Isolation Power at Cal UWB 
	for(int i=0; i<6; i++)
	{
		addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
		sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testName,"T%i_TxIsolCal_%i",testNumber,24600+i*200);
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testUnit,"dB"); 
		sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testLowLimit,"-%f",TxIsolCalLowLimit);  
		sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testHighLimit,"%f",TxIsolCalHighLimit);  
		sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal,"%f",TxIsolationResAtCalUwbDac[i]); 
		
		if((TxIsolationResAtCalUwbDac[i]>=TxIsolCalLowLimit) && (TxIsolationResAtCalUwbDac[i]<=TxIsolCalHighLimit))
		{
			strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Pass");   
		}
		else
		{
			strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Fail"); 
		}
		ITS_Idx[nestNum]++;
	}
} // end addMeasureTxIsolationAtCalUwbToIts

void addWriteDUTDataToIts(int testNumber,int nestNum,char * value, int status)
{
	
	//sprintf(LogMsg,"P%d=%s", point, VerifySerial[nestNum].Point_Value[i]);
	char *pch;
	char PointID[BUFFER_SIZE]={0};
	char PointValue[BUFFER_SIZE]={0};
	char buffer[256]={0};
	strcpy(buffer,value);
	pch = strtok(buffer,",="); 
	
	while (pch != NULL)
	{
		strcpy(PointID,pch);
		pch = strtok(NULL,",=");
		strcpy(PointValue,pch);
		pch = strtok(NULL,",="); 		
	
		addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
		
		sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testName,"T%i_WriteDutValue%s",testNumber,PointID);
		sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal,"%s",PointValue);  
		if (status == 0)	
		{
			strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Pass");   
		}
		else
		{
			strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Fail"); 
		}
		ITS_Idx[nestNum]++;
	}
} // end addVerifyCalUwbDacToIts
void addVerifyDUTDataToIts(int testNumber,int nestNum,char * value, int status)
{
	
	//sprintf(LogMsg,"P%d=%s", point, VerifySerial[nestNum].Point_Value[i]);
	char *pch;
	char PointID[BUFFER_SIZE]={0};
	char PointValue[BUFFER_SIZE]={0};
	
	pch = strtok(value,",="); 
	
	while (pch != NULL)
	{
		strcpy(PointID,pch);
		pch = strtok(NULL,",=");
		strcpy(PointValue,pch);
		pch = strtok(NULL,",="); 		
	
		addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
		
		sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testName,"T%i_VerifyDutValue%s",testNumber,PointID);
		sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal,"%s",PointValue);  
		if (status == 0)	
		{
			strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Pass");   
		}
		else
		{
			strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Fail"); 
		}
		ITS_Idx[nestNum]++;
	}
} // end addVerifyCalUwbDacToIts  /addWriteToPointResultsToIts
void addReadPointResultsToIts(int testNumber,int nestNum,int point, char * value, char *min, char *max, int status)
{
	addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testName,"T%i_ReadPoint%i",testNumber,point);
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal,"%s",value);  
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testLowLimit,"%s",min);  
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testHighLimit,"%s",max);  
	
	if (status == 0)	
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Pass");   
	}
	else
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Fail"); 
	}
		ITS_Idx[nestNum]++;
} // end 
void addFailFctResultsToIts(int testNumber,int nestNum,char * name, char * value, char *min, char *max, int status)
{
	addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testName,"T%i_%s",testNumber,name);
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal,"%s",value);  
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testLowLimit,"%s",min);  
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testHighLimit,"%s",max);  
	
	if (status == 0)	
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Pass");   
	}
	else
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Fail"); 
	}
		ITS_Idx[nestNum]++;
} // end 
void addWriteToPointResultsToIts(int testNumber,int nestNum,int point, char * value, char *min, char *max, int status)
{
	addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testName,"T%i_WritePoint%i",testNumber,point);
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal,"%s",value);  
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testLowLimit,"%s",min);  
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testHighLimit,"%s",max);  
	
	if (status == 0)	
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Pass");   
	}
	else
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Fail"); 
	}
		ITS_Idx[nestNum]++;
} // end addVerifyCalUwbDacToIts

/********************************************//**
* Add mailbox points ITACx Isolation power at Cal UWB DAC to ITAC test step 
***********************************************/

void addWriteNBMailboxPointsToIts(int testNumber,int nestNum, char *points, bool testResult)
{

	char *pch;
	char PointsBuff[]={0};
	char PointID[BUFFER_SIZE]={0};
	char PointValue[BUFFER_SIZE]={0};
	char PointStatus[BUFFER_SIZE]={0};
	
	


	//strcpy(PointsBuff,points);
	
	pch = strtok(points,","); 
	
	while (pch != NULL)
	{
		addItacTestStep(testNumber, nestNum, ITS_Idx[nestNum]);
		strcpy(PointID,pch);
		pch = strtok(NULL,",");
		strcpy(PointValue,pch);
		pch = strtok(NULL,","); 		
		strcpy(PointStatus,pch); 
		pch = strtok(NULL,","); 
		sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testName,"T%d_WriteMailboxPoint%s",testNumber,PointID);
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testUnit,"TBD"); 
	//	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testLowLimit,"-%f",TxIsolCalLowLimit);  
	//	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testHighLimit,"%f",TxIsolCalHighLimit);  
		sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal,"%s",PointValue); 
	
		if(!stricmp(PointStatus,"ok"))
		{
			strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Pass");   
		}
		else
		{
			strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Fail"); 
		}
		ITS_Idx[nestNum]++;
		
	}	


	return;
}


void addVerifyNBMailboxPointsToIts(int testNumber,int nestNum, char *points, bool testResult)
{
 
	char *pch;
	char PointsBuff[]={0};
	char PointID[BUFFER_SIZE]={0};
	char PointValue[BUFFER_SIZE]={0};
	char PointStatus[BUFFER_SIZE]={0};
	
	


	//strcpy(PointsBuff,points);
	
	pch = strtok(points,","); 
	
	while (pch != NULL)
	{
		addItacTestStep(testNumber, nestNum, ITS_Idx[nestNum]);
		
		strcpy(PointID,pch);
		pch = strtok(NULL,",");
		strcpy(PointValue,pch);
		pch = strtok(NULL,","); 		
		strcpy(PointStatus,pch); 
		pch = strtok(NULL,","); 
		sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testName,"T%d_VerifyMailboxPoint%s",testNumber,PointID);
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testUnit,"TBD"); 
	//	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testLowLimit,"-%f",TxIsolCalLowLimit);  
	//	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testHighLimit,"%f",TxIsolCalHighLimit);  
		sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal,"%s",PointValue); 
	
		if(!stricmp(PointStatus,"ok"))
		{
			strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Pass");   
		}
		else
		{
			strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Fail"); 
		}
		ITS_Idx[nestNum]++;
		
	}	

	
	

	return;
}


/********************************************//**
* Add software version to ITAC test step 
***********************************************/

 void addSWVersionToIts(int testNumber, int nestNum,
					  	char *HpApp, char *requiredHPApp,
					 	char *HpBoot, char *requiredHPBoot,
					 	char *DspApp, char *requiredDSPApp,
					 	char *DspBoot, char* requiredDSPBoot, int error)
 {
	 
	//HpApp
	addItacTestStep(testNumber, nestNum, ITS_Idx[nestNum]);
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testName,"T%d_HPApp",testNumber);
	strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testUnit,"TBD"); 
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal,"%s",HpApp); 

	if( (strstr(HpApp,requiredHPApp) != NULL) )
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Pass");   
	}
	else
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Fail"); 
	}
	ITS_Idx[nestNum]++;

	
	//HpBoot
	addItacTestStep(testNumber, nestNum, ITS_Idx[nestNum]);
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testName,"T%d_HpBoot",testNumber);
	strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testUnit,"TBD"); 
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal,"%s",HpBoot); 

	if( (strstr(HpBoot,requiredHPBoot) != NULL) )
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Pass");   
	}
	else
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Fail"); 
	}
	ITS_Idx[nestNum]++;
	
	
	
	// DspApp
	addItacTestStep(testNumber, nestNum, ITS_Idx[nestNum]);
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testName,"T%d_DspApp",testNumber);
	strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testUnit,"TBD"); 
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal,"%s",DspApp); 

	if( (strstr(DspApp,requiredDSPApp) != NULL) )
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Pass");   
	}
	else
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Fail"); 
	}
	ITS_Idx[nestNum]++;

	
	//DspBoot
	addItacTestStep(testNumber, nestNum, ITS_Idx[nestNum]);
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testName,"T%d_DspBoot",testNumber);
	strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testUnit,"TBD"); 
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal,"%s",DspBoot); 

	if( (strstr(DspBoot,requiredDSPBoot) != NULL) )
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Pass");   
	}
	else
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Fail"); 
	}
	ITS_Idx[nestNum]++;
	
	 return;
 }



/********************************************//**
* Add Path to ITAC test step 
***********************************************/
void addMakePathStatusToIts(int testNumber, int nestNum, int status)
{
	
	addItacTestStep(testNumber, nestNum, ITS_Idx[nestNum]);
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testName,"T%d_MakePath",testNumber);
	strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testUnit,"TBD"); 
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal,"%d",status); 

	if( status == 0 )
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Pass");   
	}
	else
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Fail"); 
	}
	ITS_Idx[nestNum]++;

	return;
}



/********************************************//**
* Add Set temperature compenstion  to ITAC test step 
***********************************************/

void addSetTemperatureCompensationToIts(int testNumber, int nestNum, char *Point1, char *Point1Val,char *Point2, char *Point2Val, int errorStatus)
{
	

	addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testName,"T%d_DisableTCompPoint%s",testNumber,Point1);
	strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testUnit,"TBD"); 
//	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testLowLimit,"-%f",TxIsolCalLowLimit);  
//	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testHighLimit,"%f",TxIsolCalHighLimit);  
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal,"%s",Point1Val); 
	
	if(errorStatus == 0)
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Pass");   
	}
	else
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Fail"); 
	}
	ITS_Idx[nestNum]++;
	
	
	addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testName,"T%d_DisableTCompPoint%s",testNumber,Point2);
	strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testUnit,"TBD"); 
//	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testLowLimit,"-%f",TxIsolCalLowLimit);  
//	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testHighLimit,"%f",TxIsolCalHighLimit);  
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal,"%s",Point2Val); 
	
	if(errorStatus == 0)
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Pass");   
	}
	else
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Fail"); 
	}
	ITS_Idx[nestNum]++;


	return;
}



void addSetMaxPowerForOccupiedBWToIts(int testNumber,int nestNum,int point, char * value, char *min, char *max, int status)
{
	
	addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testName,"T%i_SetMaxPowerForOccBW%i",testNumber,point);
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal,"%s",value);  
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testLowLimit,"%s",min);  
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testHighLimit,"%s",max);  
	
	if (status == 0)	
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Pass");   
	}
	else
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Fail"); 
	}
		ITS_Idx[nestNum]++;

	return;
}




void addSaveConfigPointsToIts(int testNumber,int nestNum, int errorStatus)
{
	addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
	
	if(errorStatus == 0)
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Pass");   
	}
	else
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Fail"); 
	}
	
	
	ITS_Idx[nestNum]++;

	return;
}


void addForce_Radar_ModeToIts(int testNumber, int nestNum, char *pmode,  int errorStatus)
{


	

	if(!strcmp(pmode, "RCTA"))
	{
		addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);

		if(errorStatus == 0)
		{
			strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Pass");   
		}
		else
		{
			strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Fail"); 
		}
	
		
	}
	else if(!strcmp(pmode, "MBA"))
	{
		addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
		
		if(errorStatus == 0)
		{
			strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Pass");   
		}
		else
		{
			strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Fail"); 
		}
		
		
	}

	
	ITS_Idx[nestNum]++;
	
	return;
	
}

void addGetOccupiedBwToIts(int testNumber, int nestNum, char *pmode, double Bandwidth, char *unit, char *Low_Limit,char *High_Limit,int errorStatus)
{

	addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
		
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testName,"T%d_GetOccBw%s",testNumber,pmode);
	strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testUnit,unit); 
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testLowLimit,"-%s",Low_Limit);  
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testHighLimit,"%s",High_Limit);  
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal,"%f",Bandwidth); 
		
	if(errorStatus == 0)
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Pass");   
	}
	else
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Fail"); 
	}
 
 	ITS_Idx[nestNum]++;

	return;
}



void addSelect_TX_AntennaToIts(int testNumber, int nestNum, char *pmode, int errorStatus)
{

	
	if(!strcmp(pmode, "Antenna1"))
	{

		addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
		
		
		if(errorStatus == 0)
		{
			strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Pass");   
		}
		else
		{
			strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Fail"); 
		}
	}
	else if(!strcmp(pmode, "Antenna2"))
	{
		addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
		

		if(errorStatus == 0)
		{
			strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Pass");   
		}
		else
		{
			strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Fail"); 
		}
	
	}
	

	return;
	
}


void addSetCWModeToIts(int testNumber, int nestNum, int mode, int errorStatus)
{
	char sValue[BUFFER_SIZE];
	
	
	addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
	
	sprintf(sValue, "%d", mode);
	strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal, sValue);

 	mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal;
	
	if(errorStatus == 0)
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Pass");   
	}
	else
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Fail"); 
	}

	
	ITS_Idx[nestNum]++;
	
	
	return;
	
	
}



void addSetHondaTxPowerCalToIts(int testNumber, int nestNum, char *value, char *Low_Limit, char *High_Limit, int returnVal)
{
	
 	addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
	
	strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testUnit,"dB"); 
	strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testLowLimit, Low_Limit);  
	strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testHighLimit, High_Limit);  
	strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal, value); 
	
	if(returnVal)
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Fail");   
	}
	else
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Pass"); 
	}

	ITS_Idx[nestNum]++;

	return;
	
}



void addGetTxPowerToIts(int testNumber, int nestNum, double main_power, char *Low_Limit, char *High_Limit, int returnVal )
{
	
 	addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
	
	strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testUnit,"dB"); 
	strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testLowLimit, Low_Limit);  
	strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testHighLimit, High_Limit);  
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal, "%f",main_power); 
	
	if(returnVal)
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Fail");   
	}
	else
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Pass"); 
	}

	ITS_Idx[nestNum]++;
	

	return;
}


void addGetCenterFrequencyToIts(int testNumber, int nestNum, double main_frequency, char *Low_Limit, char *High_Limit, int returnVal)
{
	
 	addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
	
	strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testUnit,"GHz"); 
	strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testLowLimit, Low_Limit);  
	strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testHighLimit, High_Limit);  
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal, "%f",main_frequency); 
	
	if(returnVal)
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Fail");   
	}
	else
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Pass"); 
	}

	ITS_Idx[nestNum]++;
	
	

	return;
}


void addGetCwLeakageToIts(int testNumber, int nestNum, double main_Leakage, char *unit, char *Low_Limit, char *High_Limit, int returnVal)
{
	
 	addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
	
	strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testUnit,unit); 
	strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testLowLimit, Low_Limit);  
	strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testHighLimit, High_Limit);  
	sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal, "%f",main_Leakage); 
	
	if(returnVal)
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Fail");   
	}
	else
	{
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Pass"); 
	}

	ITS_Idx[nestNum]++;
	
	
	
	

	return;
	
}


void addReadTemperatureToIts(int testNumber, int nestNum, int TempMeasurement, double TCelsius, double minCelsius, double maxCelsius, double Delta_T, double Delta_L, int returnVal)
{


	if(TempMeasurement == 1)
	{
		// Temperature measurement at the begining of test sequence
		
	 	addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
	
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testUnit,"C"); 
		sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testLowLimit, "%f", minCelsius);  
		sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testHighLimit, "%f", maxCelsius);  
		sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal, "%f",TCelsius); 
	
		if(returnVal)
		{
			strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Fail");   
		}
		else
		{
			strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Pass"); 
		}

		ITS_Idx[nestNum]++;
	
	}
	else if(TempMeasurement == 2)
	{
		// Temperature measurement at the end of test sequence
		
	 	addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
	
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testUnit,"C"); 
		sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testLowLimit, "%f", minCelsius);  
		sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testHighLimit, "%f", maxCelsius);  
		sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal, "%f",TCelsius); 
	
		if(returnVal)
		{
			strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Fail");   
		}
		else
		{
			strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Pass"); 
		}

		ITS_Idx[nestNum]++;
		
		//delta
	 	addItacTestStep(testNumber,nestNum,ITS_Idx[nestNum]);
	
		sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testName,"T%d_DeltaTemperature",testNumber);
		strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testUnit,"C"); 
		sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testLowLimit, "%f", Delta_L);  
		sprintf(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResultVal, "%f",Delta_T); 
	
		if(returnVal)
		{
			strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Fail");   
		}
		else
		{
			strcpy(mtgItacTestStep[nestNum][ITS_Idx[nestNum]].testResult,"Pass"); 
		}

		ITS_Idx[nestNum]++;
		
		
		
	}
	

	return;
}



/********************************************//**
* Parse text  in the form label=value; find the value when given label.
***********************************************/
int get_param(int testNum, char *param, void *val, int type, int required)
{
	char temp[250];

	if(parse(mtgTestStepInfo[0][testNum-1].testParam, param, temp))   // The -1 drives me nuts!
	{
		if(type == VAL_INTEGER)
			sscanf(temp, "%d",  val);
		else if(type == VAL_DOUBLE)
			sscanf(temp, "%lf", val);
		else if(type == VAL_STRING)
			sprintf(val, "%s", temp);
	}
	else if(required)
	{
		sprintf(temp, "Param \"%s\" not found in param string \"%s\" for test %d", param, mtgTestStepInfo[0][testNum-1].testParam, testNum);
		MessagePopup("Error Required Test Config Field Not Found", temp); 
  	}
  	return 0;
}

/********************************************//**
*Read MIS number and send proceed request to iTAC
***********************************************/
bool Proceed_Request (int testNumber, int nestNum)   
{
	int error;
	char MIS[23] = {0}, ErrorMsg[256] = {0};
		
	error = ProceedRequest(nestNum,MIS,ErrorMsg);
	strcpy (dutMIS[nestNum].SerialNumber,"");
	strcpy (dutMIS[nestNum].ITACvalid,""); 
	if(error == -1)
		sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "MIS=Unknown");
	else if (error == -2)
		sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "MIS=%s, Wrong FID", MIS);
	else if (error == -3)
		sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "MIS=%s, ITAC Fail. %s", MIS,ErrorMsg);
	else
	{
		sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "MIS=%s", MIS);
		sprintf(dutMIS[nestNum].SerialNumber, "%s", &MIS); 
		sprintf(dutMIS[nestNum].ITACvalid, "%s", &MIS); 
	}
	
	//add_datetime_to_test_output_log(nestNum);  // This seems like the wrong place to add this.
	add_data_to_test_output_log(nestNum,MIS);	
	addProceedRequestToIts(testNumber,nestNum, error);     
	return error;
} // end ProceedRequest


/********************************************//**
*compare measurements with csv limits
***********************************************/ 
int CompareValueWithLimits (char *TestName, char *value, char *Low_Limit, char *High_Limit )   
{
	
	int min, max, meas;
	
	int ret_val=0;
	
	char parameter[100];
	char pointCSV[100];
	char unit[100]={0};

	if (getUnitInfoByRequirement(TestName, Low_Limit, High_Limit, parameter, pointCSV,unit) != 0)
		return 1;
	deleteSpaces(Low_Limit);
	deleteSpaces(High_Limit);
	
	sscanf(value,"%d",&meas);

	if (!strcmp(High_Limit,Low_Limit))
	{
		sscanf(Low_Limit,"%d",&min);
		if (meas != min)
			ret_val |= 1;	
	}
	else if ( (strstr(Low_Limit,"N") == NULL) && (strstr(High_Limit,"N") == NULL) )
	{
		sscanf(Low_Limit,"%d",&min);
		sscanf(High_Limit,"%d",&max);
		if ((meas > max) ||  (meas < min))
			ret_val |= 1;	
	}
	else if (strstr(Low_Limit,"N") == NULL)
	{
		sscanf(High_Limit,"%d",&max);
		if (meas > max)
			ret_val |= 1;	
	}
	else if (strstr(High_Limit,"N") == NULL)
	{
		sscanf(Low_Limit,"%d",&min);
		if (meas < min)
			ret_val |= 1;	
	}
	
	
return ret_val;
}
/********************************************//**
* Writing Points 1571-1576
***********************************************/	 //aa writing Points

bool WriteDUTData(int testNumber, int nestNum)
{
  	int 		Read_1483_ret=-1;
	int 		Read_1484_ret=-1; 
	int 		Read_1485_ret=-1;
	int 		Read_1486_ret=-1;     
	char 		*value_1483;
	char 		*value_1484;
	char 		*value_1485;
	char 		*value_1486;		
	int			errorValue=0;
	int value_int_1485;
	char fillerNumPanel[10]={0};
	int point;
	char Variant_Points[100];
	char LogMsg[256]={0};
	

	Alv_NarrowBand_NBProtocol_Status *NBProtocol_Status_Points;


	Read_Point(NarrowBand_Sensor[nestNum],1483, &value_1483,&Read_1483_ret);   // Flav_Id , Example 1516
	Read_Point(NarrowBand_Sensor[nestNum],1484, &value_1484,&Read_1484_ret);   // AEC_SMT , Example 8
	Read_Point(NarrowBand_Sensor[nestNum],1485, &value_1485,&Read_1485_ret);   // Panel#  , Example 22985
	Read_Point(NarrowBand_Sensor[nestNum],1486, &value_1486,&Read_1486_ret);   // Daughter Board #  5
	
	
	if ((Read_1483_ret||Read_1484_ret||Read_1485_ret||Read_1486_ret) == 0) 
	{	
		
			strcpy(getSerial[nestNum].Date,"");
			strcpy(getSerial[nestNum].Data_String,"");
			for (int k=0;k<6;k++)
			{
				strcpy(VerifySerial[nestNum].Point_Value[k],"");
	
			}
			
			value_int_1485 = atoi(value_1485);
			if (value_int_1485<10)
				strcpy(fillerNumPanel,"00000");
			else if (value_int_1485<100)
				strcpy(fillerNumPanel,"0000");
			else if (value_int_1485<1000)
				strcpy(fillerNumPanel,"000");
			else if (value_int_1485<10000)
				strcpy(fillerNumPanel,"00");
			else if (value_int_1485<100000)
				strcpy(fillerNumPanel,"0");

			sprintf(value_1485,"%s%i",fillerNumPanel,value_int_1485);
			sscanf(value_1485,"%i",&value_int_1485);
		
			/********************************************************  
			*Get date                                       
			*********************************************************/ 

			LocalDateTime dt;
			dt = GetLocalDateTime();
			
			//	unsigned  int D;			// day of week
			//	unsigned int DDD;			// day of year
			//	unsigned int WW;			// week of year
			//YYWWWD

			
			sprintf(getSerial[nestNum].Date,"%s%s%i",dt.YY,dt.WXX,dt.D);
			
			
			char AEC_Backend[]="1";

			/********************************************************  
			*Create Data String                                      
			*********************************************************/
			sprintf(getSerial[nestNum].Data_String, "%s%s%s%s%s%s", getSerial[nestNum].Date,AEC_Backend,value_1483,value_1484,value_1485,value_1486);


			strcpy(Variant_Points,selRecipe.Variant);

			CopyString (VerifySerial[nestNum].Point_Value[0], 0, Variant_Points,0,5);
			CopyString (VerifySerial[nestNum].Point_Value[1], 0, Variant_Points,5,5); 
			CopyString (VerifySerial[nestNum].Point_Value[2], 0, getSerial[nestNum].Data_String,0,5);
			CopyString (VerifySerial[nestNum].Point_Value[3], 0, getSerial[nestNum].Data_String,5,5);
			CopyString (VerifySerial[nestNum].Point_Value[4], 0, getSerial[nestNum].Data_String,10,5); 
			CopyString (VerifySerial[nestNum].Point_Value[5], 0, getSerial[nestNum].Data_String,15,5);
				
			/********************************************************  
			*Write to  Points 1571-1576                                        
			*********************************************************/ 
			for (int i=0;i<6;i++)
			{
				point = 1571+i;
				write_to_point(NarrowBand_Sensor[nestNum],point, VerifySerial[nestNum].Point_Value[i] ,&NBProtocol_Status_Points);
			
				if ( NBProtocol_Status_Points)
				{
					  errorValue |=1;
				}
				if (i>0)
				{
					strcat(mtgTestStepInfo[nestNum][testNumber-1].testResultVal,",");
				}
				sprintf(LogMsg,"P%d=%s", point, VerifySerial[nestNum].Point_Value[i]);
				strcat(mtgTestStepInfo[nestNum][testNumber-1].testResultVal,LogMsg);
				add_data_to_test_output_log(nestNum,VerifySerial[nestNum].Point_Value[i]);
	
			}
		
	}
	else
	{
		errorValue |=1;  	
	}
	
	addWriteDUTDataToIts(testNumber,nestNum,mtgTestStepInfo[nestNum][testNumber-1].testResultVal, errorValue);
	return errorValue;
}


/********************************************//**
* Checking Points 1571-1576
***********************************************/	 //aa Checking Points
bool SerialpointsCheck(int testNumber, int nestNum)
{
	int errorValue=0;
	int fct_return = 0;
	char * returnValue;
	int point;
	char LogMsg[256]={0};
	char ITACLogMsg[256]={0};
	char ITACLogBuf[256]={0};
	

	for (int i=0;i<6;i++)
	{
		point = 1571+i;
		//write_to_point(Handle,point, VerifySerial[boardNum].Point_Value[i] ,&NBProtocol_Status_Points);
		Read_Point(NarrowBand_Sensor[nestNum],point,&returnValue, &fct_return);   
		if((strcmp(VerifySerial[nestNum].Point_Value[i],returnValue) != 0) || fct_return)
		{
			errorValue |=1;
	    }
		if (i>0)
		{
			strcat(mtgTestStepInfo[nestNum][testNumber-1].testResultVal,",");
			strcat(ITACLogMsg,",");
			
		}
		sprintf(LogMsg,"P%d=%s   expected=%s", point, returnValue,VerifySerial[nestNum].Point_Value[i]);
		sprintf(ITACLogBuf,"P%d=%s", point, returnValue);
		strcat(mtgTestStepInfo[nestNum][testNumber-1].testResultVal,LogMsg);
		strcat(ITACLogMsg,ITACLogBuf);
		
	}
	addVerifyDUTDataToIts(testNumber,nestNum,ITACLogMsg, errorValue);   
	return errorValue;
}
		
/********************************************//**
* Read temperature using test requirement "Tx_H_MEAS_02" 
***********************************************/
bool ReadTemperature (int testNumber, int nestNum)   
{
	
	
	char *value; 
	double TCelsius;
	char Low_Limit[25] = {0};
	char High_Limit[25] = {0};
	
	unsigned short point=0;
	char LogMsg[256]={0};
	int ret_val=0;
	double minTick;
	double maxTick;
	double minCelsius;
	double maxCelsius;
	double DeltaTemperature;
	char deltaString[100]={0};
	double deltaLimit;
	int measurement;
	int  TempMeasurement;
	
	char parameter[100];
	char pointCSV[100];
	char requirement[100];// = "Tx_H_MEAS_02";
	char unit[100]={0};

	ret_val = 0;
	
	get_param(testNumber, "requirement", requirement, VAL_STRING, VAL_REQUIRED);
	get_param(testNumber, "measurement", &TempMeasurement, VAL_INTEGER, VAL_REQUIRED);
	//KIM NA
	if (getUnitInfoByRequirement(requirement, Low_Limit, High_Limit, parameter, pointCSV,unit) != 0)
		return 1;
	if (  (strstr(Low_Limit,"N")!=NULL) || (strstr(High_Limit,"N")!=NULL)  )
	{
		sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "RetValue=%s C,Min=%s,Max=%s", "NA", Low_Limit, High_Limit);  
		return 0;	
	}
	
	sscanf (Low_Limit,"%lf",&minTick); 
	sscanf (High_Limit,"%lf",&maxTick); 
	
	maxCelsius = -0.000000005454*minTick*minTick*minTick+0.000035493384*minTick*minTick+-0.100343907372*minTick+147.811855422076;      
	minCelsius = -0.000000005454*maxTick*maxTick*maxTick+0.000035493384*maxTick*maxTick+-0.100343907372*maxTick+147.811855422076;      
	
	sscanf(pointCSV,"Point %i", &point);
	//point =atoi(pointCSV);
	
	Read_Point(NarrowBand_Sensor[nestNum],point, &value, &ret_val); 
	//Get_Point(Test_SensorControl_Handle[nestNum],point,&measurement);

	sscanf (value,"%lf",&TCelsius);
	

	if ((TCelsius<minCelsius) || (TCelsius > maxCelsius) || ret_val)
		ret_val |= 1;
	else
		ret_val |= 0;
	

	
	
	if(TempMeasurement == 1)
	{
		TemperatureAtStart[nestNum] = TCelsius;

		sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "RetValue=%f C,Delta=%s,Min=%f,Max=%f", TCelsius, "N/A", minCelsius, maxCelsius);  
		add_data_to_test_output_log(nestNum,value);
		
		//addSensorTemperatureToIts(testNumber,nestNum,minCelsius,maxCelsius,TCelsius);// Not needed 

	}
	else if(TempMeasurement == 2)
	{
		get_param(testNumber, "delta", &deltaLimit, VAL_DOUBLE, VAL_REQUIRED);  	
		
		DeltaTemperature = TCelsius - TemperatureAtStart[nestNum];
		
		if(DeltaTemperature < deltaLimit)
			ret_val |= 1;
			

		sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "RetValue=%f C,Delta=%f,Min=%f,Max=%f", TCelsius, DeltaTemperature, minCelsius, maxCelsius);
		sprintf(deltaString,"%f",DeltaTemperature);
		add_data_to_test_output_log(nestNum,value);
		add_data_to_test_output_log(nestNum,deltaString);
		

		//addSensorTemperatureToIts(testNumber,nestNum,minCelsius,maxCelsius,TCelsius);

	}

	//sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "RetValue=%f C,Min=%f,Max=%f", TCelsius, minCelsius, maxCelsius);  
	//add_data_to_test_output_log(nestNum,value);
	
	
	addReadTemperatureToIts(testNumber,nestNum, TempMeasurement, TCelsius, minCelsius, maxCelsius, DeltaTemperature , deltaLimit, ret_val);
	
	return ret_val;//Need to make sure ret_val is 0 when read_point function succesfull
}

/********************************************//**
* Set temperature compensation on (1) or off (0)
***********************************************/
bool SetTemperatureCompensation (int testNumber, int nestNum)   
{
	char Point1[25],ValueToWrite1[25] = {0};
	unsigned short point1=0;
	char Point2[25],ValueToWrite2[25] = {0};
	unsigned short point2=0;
	
	int errorStatus = 0;
	
	char LogMsg[512]={0};
	
	get_param(testNumber, "Value1", ValueToWrite1, VAL_STRING, VAL_REQUIRED);
	get_param(testNumber, "Point1", Point1, VAL_STRING, VAL_REQUIRED);
	get_param(testNumber, "Value2", ValueToWrite2, VAL_STRING, VAL_REQUIRED);
	get_param(testNumber, "Point2", Point2, VAL_STRING, VAL_REQUIRED);
	
	
	point1 =atoi(Point1);
	point2 =atoi(Point2);
	
	write_to_point(NarrowBand_SensorComm_Handle[nestNum],point1, ValueToWrite1 ,&NBProtocol_Status[nestNum]); 
	if(NBProtocol_Status[nestNum])
	{
		errorStatus |= 1;
	}
	write_to_point(NarrowBand_SensorComm_Handle[nestNum],point2, ValueToWrite2 ,&NBProtocol_Status[nestNum]); 
	if(NBProtocol_Status[nestNum])
	{
		errorStatus |= 1;
	}

	sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "RetValue=%d", NBProtocol_Status[nestNum]);
	
	//addSetTemperatureCompensationToIts(testNumber,nestNum, Point1, ValueToWrite1, Point2, ValueToWrite2, errorStatus);     
	
	return errorStatus;//Need to make sure NBProtocol_Status[nestNum] is 0 when read_point function succesfull
}

/********************************************//**
* Set Max Power
***********************************************/
bool SetMaxPowerForOccupiedBW (int testNumber, int nestNum)   
{
	char ValueToWrite[25] = {0};

	
	int errorStatus = 0;
	
	char LogMsg[256]={0};
	Alv_NarrowBand_NBProtocol_Status NBProtocol_StatusWrite;

	int PoinValue [16][2] = {  {652,15}, {653,15}, {654,15}, {655,15},
							   {668,6},  {669,6},  {670,6},  {671,6},
						       {850,15}, {851,15}, {852,15}, {853,15}, 
							   {866,6},  {867,6},  {868,6},  {869,6}  };
							
	for (int i=0; i<16; i++)
	{
		sprintf(ValueToWrite,"%d",PoinValue[i][1]);
		write_to_point(NarrowBand_SensorComm_Handle[nestNum],PoinValue[i][0], ValueToWrite,&NBProtocol_StatusWrite);//NBProtocol_Status[nestNum]); 
		if (NBProtocol_StatusWrite)
		{
	  		errorStatus |= 1;
		}
		addSetMaxPowerForOccupiedBWToIts(testNumber,nestNum,PoinValue[i][0], ValueToWrite, "", "", NBProtocol_StatusWrite);
		
	}

	sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "RetValue=%d", NBProtocol_StatusWrite);
	
	return errorStatus;//Need to make sure NBProtocol_Status[nestNum] is 0 when read_point function succesfull
}


