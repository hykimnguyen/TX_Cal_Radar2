/***********************************************************************
 *
 *
 *  COPYRIGHT: Arxtron Technologies Inc. All Rights Reserved.
 *
 *  PURPOSE: - CAN driver wrapper for C6 project.  The driver implements CAN
 *				functions defined in SIC_MRR.lib library.
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
*    @file    CANDrv.c
*    @brief   CAN driver wrapper for C6 project.
*    @author  Arxtron Technologies Inc.
*    @date    2013.9.6
*    CAN driver wrapper for C6 project.  The driver implements CAN
*	 functions defined in SIC_MRR.lib library. 
*/ 

#include <windows.h>
#include <utility.h>
#include <ansi_c.h>
#include <time.h>
#include "cvidef.h"
#include "CANDrv.h"
#include "SIC_MRR.h"    
#include "app_log.h"


//#include <nixnet.h> 
#include "Nb_Test.h"
#include "NiCanWrp.h"
#include "NbLib.h"


#define SIC10_SYNC_PERIOD		40		// sleep for 40ms after SendCommand_mt

//char CANport[] = "CAN0";
//strcpy(CANport, "CAN1");
//strcpy(CANport, "CAN2");
//strcpy(CANport, "CAN3");
//strcpy(CANport, "CAN4");
//strcpy(CANport, CAN5);
//strcpy(CANport, "CAN6");
/********************************************//**
 *  Close can port   
 ***********************************************/
int CloseCAN_c6(int CANport)
{
	int error;

//	error = CloseCAN_mt(CANport); CODE_CLEAN
	check_error(error,__FUNCTION__,"Command failed.");
	 
	return(error);
} // end CloseCAN


/********************************************//**
 *  Close CAN controller   
 ***********************************************/
int CloseController_c6(int CANport)
{
	int error;

//	error = CloseController_mt(CANport);  CODE_CLEAN 
#ifdef _DEBUG
	check_error(error,__FUNCTION__,"Command failed.");   
#endif
	return(error);
} // end CloseController_c6



/********************************************//**
*  Engineer command to disable cyclic CAN messages (Meas,  
*				Data,targets, Status msgs).  Should be used after power up
*				and after getting measurement data.  
***********************************************/
void DisableSICMsgs(int CANport)
{
	//Disable status, meas. data, and target reports
	int DoNotSendData[6]={2,55,1,0,0,0};	
	for (int SensorID=1;SensorID<=4;SensorID++)
	{
		//SendCommand_mt(SensorID,sizeof(DoNotSendData),DoNotSendData,CANport); CODE_CLEAN 
	}
	Sleep(SIC10_SYNC_PERIOD);	// SIC10_SYNC_PERIOD = 40 ms
} // end DisableSICMsgs


/********************************************//**
*  Engineer command to enable cyclic CAN messages (Meas,  
* Data,targets, Status msgs).  Should be used before 
* reading measurement data.  Disable it afterward. 
***********************************************/
void EnableSICMsgs(int CANport)
{
	//Enable status, meas. data, and target reports
	int DoSendData[6]={2,55,1,0,0,7};	

	for (int SensorID=1;SensorID<=4;SensorID++)
	{
		//SendCommand_mt(SensorID,sizeof(DoSendData),DoSendData,CANport); CODE_CLEAN
	}
	Sleep(SIC10_SYNC_PERIOD);	// SIC10_SYNC_PERIOD = 40 ms
}  // end EnableSICMsgs


/********************************************//**
*   Write a value to an EEPROM address 
***********************************************/
int FastWriteEEPROM_c6(int SensorID, int Adrs, int Value, int CANport)
{
	int error;

	EnableSICMsgs(CANport);
	//error = FastWriteEEPROM_mt(SensorID,Adrs,Value,CANport);  CODE_CLEAN
	DisableSICMsgs(CANport);
	
	Sleep(SIC10_SYNC_PERIOD); 
#ifdef _DEBUG	
	check_error(error,__FUNCTION__,"Command failed.");   
#endif 
	return(error); 
} // end FastWriteEEPROM_c6


/********************************************//**
*   Get measurement data
***********************************************/
int Get_MeasData_Array_c6(int SensorID, unsigned char MeasData[128], int CANport)
{
	int error;
	
	EnableSICMsgs(CANport);
//	error = Get_MeasData_Array_mt(SensorID,MeasData,CANport);  CLEAN_CODE
	DisableSICMsgs(CANport);

	switch(error)
	{
		case 0:
			add_log(__FUNCTION__);
			break;
		case 1:
			decode_error(error,__FUNCTION__,"Invalid pointer to sensor controller.");
			break;
		case 11:
			decode_error(error,__FUNCTION__,"Data invalid.");
			break;
		case 98:
			decode_error(error,__FUNCTION__,"Invalid port number.");
			break;
		default:
			decode_error(error,__FUNCTION__,"Command failed");
			break;
	}
	return(error); 
} // end Get_MeasData_Array_c6


// Example: CSN = 16  2982U03486221569
/********************************************//**
*   Get CSN number
***********************************************/
int GetCSNnumber_c6(int SensorID, int CANport, char CSN[21])
{
	int error;
	
	EnableSICMsgs(CANport);
//	error = GetCSNnumber_mt(SensorID,CANport,CSN);  CIODE_CLEAN
	DisableSICMsgs(CANport);
#ifdef _DEBUG
	switch(error)
	{
		case 0:
			add_log(func);
			break;
		case 1:
			decode_error(error,__FUNCTION__,"Invalid sensor controller or bad E2P read.");
			break;
		case 20:
			decode_error(error,__FUNCTION__,"Both ports of a 2-port CAN card are selectec.");
			break;
		case 98:
			decode_error(error,__FUNCTION__,"Invalid port number.");
			break;
		default:
			decode_error(error,__FUNCTION__,"Command failed.");  
			break;
	}
#endif 
	return(error); 
} // end GetCSNumber



/********************************************//**
*   Get MIS number
* 		example: MIS = 6221569160205020044241
*		12 number digits, 4 SMD flavour ID, 1 SMD line code, 4 serial number, 1 daughterboard number 
***********************************************/
int GetMISnumber_c6(int SensorID, int CANport, char MIS[23])
{
	int error = -1;
	int maxAttempts = 2;
	int numAttempts	= 0;
	int MISnumber_length = 22;

	memset(MIS,0,23); 
	
	while (error != 0 && numAttempts < maxAttempts)
	{
		EnableSICMsgs(CANport);
	//	error = GetMISnumber_mt(SensorID,CANport,MIS);     CLEAN_CODE
		DisableSICMsgs(CANport);
		numAttempts++;
		Sleep(40);
	}
	
	for(int i=0; i<12; i++)
	{
		if((int)MIS[i]==(-1))
			MIS[i]=' ';
	}
		
	// set error if length of MIS[] is not equal to 22 
	if (strlen(MIS) != MISnumber_length)
	{
		error = 22;
	}
#ifdef _DEBUG	
	switch(error)
	{
		case 0:
			add_log(func);
			break;
		case 1:
			decode_error(error,__FUNCTION__,"Invalid sensor controller or bad E2P read.");
			break;
		case 20:
			decode_error(error,__FUNCTION__,"Both port of a 2-port CAN card are selected.");
			break;
		case 22:
			decode_error(error,__FUNCTION__,"Length of MIS[] is not equal to 22.");
			break;
		case 98:
			decode_error(error,__FUNCTION__,"Invalid port number.");
			break;
		default:
			decode_error(error,__FUNCTION__,"Command failed.");  
			break;
	}
#endif 
	return(error); 
} // end GetMISnumber


/********************************************//**
*   Initialize CAN port 
***********************************************/
int InitCAN_c6(int CANport)
{
	int error;

	//error = InitCAN_mt(CANport);    CLEAN_CODE
	switch(error)
	{
		case 0:
			add_log(__FUNCTION__);
			break;
		case 2:
			decode_error(error,__FUNCTION__,"Invalid port number");
			break;
		case 16:
			decode_error(error,__FUNCTION__,"Some error occured");  
			break;
		default:
			decode_error(error,__FUNCTION__,"Command failed.");  
			break;
	}
	return(error);
	
} // end InitCAN

/********************************************//**
*   Initialize CAN controller  
***********************************************/
int InitController_c6(int CANport)
{
	int error;

	//error = InitController_mt(CANport); CLEAN_CODE
#ifdef _DEBUG
	check_error(error,__FUNCTION__,"Command failed.");   
#endif 
	return(error);
} // end InitController_c6



/********************************************//**
*   Load sensor software from a file to device     
***********************************************/
int LoadSensorSoftware_c6(int SensorID, char *pDLFilename, int EnableReadStatus, int StatusAry[5][18][5], int CANport)
{
	int error;
	error = 1;
	int maxAttempts = 4;
	int numAttempts	= 0;

	while (error != 0 && numAttempts < maxAttempts)
	{
	//	error = LoadSensorSoftware_mt(SensorID,pDLFilename,EnableReadStatus,StatusAry,CANport);	   CLEAN_CODE
		numAttempts++;
		Sleep(1000);
	}
	
#ifdef _DEBUG
	switch(error)
	{
		case 0:
			add_log(func);
			break;
		case 2:
			decode_error(error,__FUNCTION__,"Open file error.");
			break;
		case 3:
			decode_error(error,__FUNCTION__,"SENSOR_NO_RESPONSE_IN_ENTER_BOOT.");
			break;
		case 4:
			decode_error(error,__FUNCTION__,"SENSOR_UNNORMAL.");
			break;
		case 5:
			decode_error(error,__FUNCTION__,"SENSOR_NO_RESPONSE_IN_ENTER_FLASH.");
			break;
		case 6:
			decode_error(error,__FUNCTION__,"SENSOR_NOT_READY.");
			break;
		case 9:
			decode_error(error,__FUNCTION__,"Key send error.");
			break;
		case 10:
			decode_error(error,__FUNCTION__,"PSA send error.");
			break;
		case 11:
			decode_error(error,__FUNCTION__,"Key not match.");
			break;
		case 12:
			decode_error(error,__FUNCTION__,"Send data error.");
			break;
		case 13:
			decode_error(error,__FUNCTION__,"Download fail.");
			break;
		case 98:
			decode_error(error,__FUNCTION__,"Invalid port number.");
			break;
		case 99:
			decode_error(error,__FUNCTION__,"CAN object not found.");
			break;
		default:
			decode_error(error,__FUNCTION__,"Command failed.");  
			break;
	}
#endif 
	return(error); 
} // end LoadSensorUDSSoftware


/********************************************//**
*   Ping device to retrieve the boot and app      
***********************************************/
int Ping_c6(int SensorIDArray[5][4], int CANport)
{
	//////////////////////////////////////////////
	// SensorIDArray[0][] or first index is not used
	// SensorIDArray[][0] = boot major version
	// SensorIDArray[][1] = boot minor version 
	// SensorIDArray[][2] = app major version 
	// SensorIDArray[][3] = app minor version 
	//////////////////////////////////////////////  
	int error;

	int numOfFoundSensors = 0;
	char tmpStr[50];

	// Get SensorID array
	//numOfFoundSensors = Ping_mt(SensorIDArray,CANport);  CLEAN_CODE
	error = numOfFoundSensors; 			 
	
#ifdef _DEBUG
	switch(numOfFoundSensors)
	{
		case 0:
			decode_error(error,__FUNCTION__,"Unable to ping or find any sensor."); 
			error = -1;
			break;
		case 1:
			sprintf(tmpStr,"%s found %i sensors.",__FUNCTION__, numOfFoundSensors);
			add_log(tmpStr);	   
			break;
		case 2:
			sprintf(tmpStr,"%s found %i sensors.",__FUNCTION__, numOfFoundSensors); 
			add_log(tmpStr);
			break;
		case 3:
			sprintf(tmpStr,"%s found %i sensors.",__FUNCTION__, numOfFoundSensors); 
			add_log(tmpStr);
			break;
		case 4:
			sprintf(tmpStr,"%s found %i sensors.",__FUNCTION__, numOfFoundSensors); 
			add_log(tmpStr);
			break;	
		case 98:
			decode_error(error,__FUNCTION__,"Invalid port number.");
			break;
		case 99:
			decode_error(error,__FUNCTION__,"CAN object not found.");
			break;
		default:
			decode_error(error,__FUNCTION__,"Command failed."); 
			break;
	}
#endif 
	return(error); 
} // end Ping_c6



/********************************************//**
*   New Ping command to device to retrieve the boot and app 
*	versions.   
***********************************************/
int Ping_new_c6(int SensorIDArray[5][8], int CANport)
{
	//////////////////////////////////////////////
	// SensorIDArray[0][] or first index is not used
	// SensorIDArray[][6] = boot major version
	// SensorIDArray[][7] = boot minor version 
	// SensorIDArray[][2] = app major version 
	// SensorIDArray[][3] = app minor version 
	// SensorIDArray[][4] = a fifth field
	// SensorIDArray[][0-7] = -1 // for sensor address without an UUT 
	//////////////////////////////////////////////  
	int error;
	int numOfFoundSensors = 0;
	char tmpStr[50];

	// Get SensorID array
//	numOfFoundSensors = Ping_new_mt(SensorIDArray,CANport); CLEAN_CODE 
	error = numOfFoundSensors; 	
	
#ifdef _DEBUG
	switch(numOfFoundSensors)
	{
		case 0:
			decode_error(error,__FUNCTION__,"Unable to ping or find any sensor."); 
			error = -1;
			break;
		case 1:
			sprintf(tmpStr,"%s found %i sensors.",__FUNCTION__, numOfFoundSensors);
			add_log(tmpStr);	   
			break;
		case 2:
			sprintf(tmpStr,"%s found %i sensors.",__FUNCTION__, numOfFoundSensors);  
			add_log(tmpStr);
			break;
		case 3:
			sprintf(tmpStr,"%s found %i sensors.",__FUNCTION__, numOfFoundSensors);  
			add_log(tmpStr);
			break;
		case 4:
			sprintf(tmpStr,"%s found %i sensors.",__FUNCTION__, numOfFoundSensors);  
			add_log(tmpStr);
			break;	
		case 98:
			decode_error(error,__FUNCTION__,"Invalid port number.");
			break;
		case 99:
			decode_error(error,__FUNCTION__,"CAN object not found.");
			break;
		default:
			decode_error(error,__FUNCTION__,"Command failed."); 
			break;
	}
#endif 
	return(error); 
} // end Ping_new_c6


/********************************************//**
*   Read values from EEPROM    
***********************************************/
int ReadEEPROM_c6(int sensorID,int *arrayE2P, int CANport)
{
	int error;
	
	//int arrayE2P[1024];
	int maxAttempts = 4;
	int numAttempts	= 0;
	error = -1;
	while ((error != 0) && (numAttempts < maxAttempts))
	{
		EnableSICMsgs(CANport);
		//error = ReadEEPROM_mt(sensorID,arrayE2P,CANport); CLEAN_CODE
		DisableSICMsgs(CANport);
		numAttempts++;
		Sleep(1000);
	}
	
#ifdef _DEBUG
	switch(error)
	{
		case 0:
			add_log(func);
			break;
		case 1:
			decode_error(error,__FUNCTION__,"Bad E2P read.");
			break;
		case 2:
			decode_error(error,__FUNCTION__,"Invalid sensor controller.");
			break;
		case 98:
			decode_error(error,__FUNCTION__,"Invalid port number.");
			break;
		default:
			decode_error(error,__FUNCTION__,"Command failed.");  
			break;
	}
#endif 
	return(error); 
} // end ReadEEPROM


/********************************************//**
*   Read a part of EEPROM      
***********************************************/
int ReadEEPROMPart_c6(int sensorID, int startAdr, int endAdr, int *arrayE2P, int CANport)
{
	int error=-1;
	int maxAttempts = 4;
	int numAttempts	= 0;

	while ((error != 0) && (numAttempts++ < maxAttempts))
	{
		EnableSICMsgs(CANport);
		//error = ReadEEPROMPart_mt(sensorID,startAdr,endAdr,arrayE2P,CANport);  CLEAN_CODE
		DisableSICMsgs(CANport);
		if(error)
			Sleep(200);
	}
	
#ifdef _DEBUG
	switch(error)
	{
		case 0:
			add_log(func);
			break;
		case 1:
			decode_error(error,__FUNCTION__,"Invalid sensor controller or Bad E2P read.");
			break;
		case 3:
			decode_error(error,__FUNCTION__,"Address error (address range < 0 or > EEPROM\'s size.");
			break;
		case 98:
			decode_error(error,__FUNCTION__,"Invalid port number.");
			break;
		default:
			decode_error(error,__FUNCTION__,"Command failed.");  
			break;
	}
#endif 
	return(error); 
} // end ReadEEPROMPart_c6


/********************************************//**
*  Send a command to device       
***********************************************/
int SendCommand_c6(int sAddress, int NoBytes, int* CmdMess, int CANport)
{
	int error;
	
	//error = SendCommand_mt(sAddress,NoBytes,CmdMess,CANport);  CODE_CLEAN
	Sleep(SIC10_SYNC_PERIOD*2);		// sleep and await for command to finish
	
#ifdef _DEBUG
	switch(error)
	{
		case 0:
			add_log(func);
			break;
		case 1:
			decode_error(error,__FUNCTION__,"Unable to send eng command.");  
			break;
		case 2:
			decode_error(error,__FUNCTION__,"Invalid pointer to sensor controller.");  
			break;
		case 51:
			decode_error(error,__FUNCTION__,"CAN message of the specified ID not found.");  
			break;
		case 98:
			decode_error(error,__FUNCTION__,"Invalid port number.");  
			break;
		default:
			decode_error(error,__FUNCTION__,"Command failed.");  
			break;
	}
#endif 
	return(error);
} // end SendCommand


/********************************************//**
*   Read CAN Buffer
***********************************************/
//int ReadCAN_Buffer_mt(int sAddress, int cmdIdent, int CanBuffer[8], int port_num); 
int ReadCAN_Buffer_c6(int sAddress, int cmdIdent, int CanBuffer[8], int CANport)
{
	int error;
	
	EnableSICMsgs(CANport);
	//error = ReadCAN_Buffer_mt(sAddress,cmdIdent,CanBuffer,CANport);	  CLEAN_CODE
	DisableSICMsgs(CANport);
#ifdef _DEBUG
	switch(error)
	{
		case 0:
			add_log(func);
			break;
		case 51:
			decode_error(error,__FUNCTION__,"CAN message of the specified ID not found.");
			break;
		case 98:
			decode_error(error,__FUNCTION__,"Invalid port number.");
			break;
		default:
			decode_error(error,__FUNCTION__,"Command failed.");  
			break;
	}
#endif 
	return(error); 
} // end ReadCAN_Buffer_c6

/********************************************//**
*  Set CAN parameters       
***********************************************/
int SetCANparameters_c6(int CAN_Hardware, int BaudRate)
{
	int error;

//	error = SetCANparameters(CAN_Hardware,BaudRate); CLEAN_CODE
#ifdef _DEBUG
	check_error(error,__FUNCTION__,"Command failed.");   
#endif 
	return(error); 
} // end SetCANparameters


/********************************************//**
*  Set CAN controller mode         
***********************************************/
int SetControllerMode_c6(int CntrlMode)
{
	int error;


	//error = SetControllerMode(CntrlMode);   CLEAN_CODE
#ifdef _DEBUG 
	check_error(error,__FUNCTION__,"Command failed.");   
#endif 
	return(error);
} // end SetControllerMode_c6


/********************************************//**
*  Set CSN number of device using CAN         
***********************************************/
int SetCSNnumber_c6(int SensorID, int CANport, char CSN[21])
{
	int error;
	
	EnableSICMsgs(CANport);
//	error = SetCSNnumber_mt(SensorID,CANport,CSN);   CLEAN_CODE
	DisableSICMsgs(CANport);
	
#ifdef _DEBUG
	switch(error)
	{
		case 0:
			add_log(func);
			break;
		case 1:
			decode_error(error,__FUNCTION__,"Invalid sensor controller.");
			break;
		case 98:
			decode_error(error,__FUNCTION__,"Invalid port number.");
			break;
		default:
			decode_error(error,__FUNCTION__,"Command failed.");  
			break;
	}
#endif 
	return(error); 
} // end SetCSNumber


/********************************************//**
*  Do a single ping command        
***********************************************/
int SinglePing_c6(int SensorAddress, int SensorIDArray[4], int CANport)
{
	//////////////////////////////////////////////
	// SensorIDArray[0][] or first index is not used
	// SensorIDArray[0] = boot major version
	// SensorIDArray[1] = boot minor version 
	// SensorIDArray[2] = app major version 
	// SensorIDArray[3] = app minor version 
	//////////////////////////////////////////////  
	int error;
	char tmpStr[50];   
	
	// Get SensorID array
	//error = SinglePing_mt(SensorAddress,SensorIDArray,CANport);  CLEAN_CODE
	
	// check SensorIDArray return value for error
	if (error == 0)
	{
		for(int i=0; i<4; i++)
		{
			if (SensorIDArray[i] == -1)
			{
				error = -1;
				sprintf(tmpStr,"%s found SensorIDArray[%i] = -1",__FUNCTION__,i);
				add_log_error(tmpStr);
			}
		}
	} // end if
	

#ifdef _DEBUG
	switch(error)
	{
		case -1:
			decode_error(error,__FUNCTION__,"Invalid SensorIDArray value."); 
			break;
		case 0:
			add_log(func);  		   
			break;
		case 20:
			decode_error(error,__FUNCTION__,"Invalid return value.");
			break;
		case 98:
			decode_error(error,__FUNCTION__,"Invalid port number.");
			break;
		case 99:
			decode_error(error,__FUNCTION__,"CAN object not found.");
			break;
		default:
			decode_error(error,__FUNCTION__,"Command failed."); 
			break;
	}
#endif 
	return(error); 
} // end SinglePing_c6



/********************************************//**
*  Set device to wait for EEPROM to finish        
***********************************************/
int WaitUntilNoEepromWritesRemains(int SensorAddress, int timeout_s, int CANport)
{
	unsigned char  readE2PArray[128];
	int i, error=0;
	double stime = Timer();
		
	for (i = 0; i < 128; i++)
		readE2PArray[i] = 255;
		
	while(readE2PArray[7] != 0 && (Timer() - stime) < timeout_s)
	{
		EnableSICMsgs(CANport);
		//error = Get_MeasData_Array_mt(SensorAddress, readE2PArray, CANport);  CLEAN_CODE
		DisableSICMsgs(CANport);
		Sleep(200);
	}
	
	return error;
} // end WaitUntilNoEepromWritesRemains


/********************************************//**
*  Set device to wait for EEPROM to finish           
***********************************************/
int WaitUntilNoEepromWritesRemains_c6(int SensorAddress, int timeout_s, int CANport)
{
	unsigned char  readE2PArray[128];
	int error;
	int ix;
	int maxAttempts = 4;
	int numAttempts = 0;

	for (ix = 0; ix < 128; ix++)
		readE2PArray[ix] = 255;
	
	while (numAttempts < maxAttempts)
	{	
		// error = Get_MeasData_Array_mt(SensorAddress, readE2PArray, CANport);   CLEAN_CODE
		if ((error==0) && (readE2PArray[7]==0))
		{
			break;
		}
		else
		{
			numAttempts++;
			Sleep(200);
		}
	}
	add_log(__FUNCTION__);   
	return error;
} // end WaitUntilNoEepromWritesRemains



/********************************************//**
*  Write to EEPROM device              
***********************************************/
int WriteEEPROM_c6(int SensorID, int StartAdrs, int EndAdrs, int *ArrayWr, int CANport)
{
	int error;
	
	EnableSICMsgs(CANport);
	//error = WriteEEPROM_mt(SensorID,StartAdrs,EndAdrs,ArrayWr,CANport);  CLEAN_CODE
	DisableSICMsgs(CANport);
	
#ifdef _DEBUG
	switch(error)
	{
		case 0:
			add_log(func);
			break;
		case 2:
			decode_error(error,__FUNCTION__,"Invalid pointer to sensor controller.");  
			break;
		case 98:
			decode_error(error,__FUNCTION__,"Invalid port number.");  
			break;
		case 99:
			decode_error(error,__FUNCTION__,"CAN object not found.");  
			break;
		default:
			decode_error(error,__FUNCTION__,"Command failed.");  
			break;
	}
#endif 
	return(error); 
} // end WriteEEPROM_c6

