/***********************************************************************
 *
 *
 *  COPYRIGHT: Arxtron Technologies Inc. All Rights Reserved.
 *
 *  PURPOSE: - NB driver wrapper for NB project.  The driver implements NB
 *				functions defined in NBlib.dll, NBTest.dll and MathNumerics.dll
 *
 *  DEVELOPMENT HISTORY:
 *
 *  Date        Name           Rev.   Description
 *  ----------  -------------  -----  -----------------------
 *  07-04-2014  Arxtron    		1.0      Initial Release
 *  
 *  
 *********************************************************************/ 
/*!
*    @file    NB_Functions.c
*    @brief   NB_Functions driver wrapper for NB project.
*    @author  Arxtron Technologies Inc.
*    @date    2014.4.7
*    NB driver wrapper for NB project.  The driver implements NB     
*	 functions defined in NBlib.dll, NBTest.dll and MathNumerics.dll 
**********************************************************************/

// Include files//
#include "Global.h"
#include <Windows.h>
#include "Nb_Test.h" //AA CHANGE
#include "NiCanWrp.h"
#include "NbLib.h"
#include <formatio.h>
#include "NB_Functions.h" 
#include <ansi_c.h>
#include <userint.h>
#include <cvirte.h>
#include <toolbox.h> 
#include <string.h>
#include <stdarg.h> 
#include <utility.h> 
#include "DateTimeUtils.h"
#include "Measurements.h"
//#include <TestSteps.h>  

//==============================================================================
// Global variables
//==============================================================================

//Alv_CAN_CanComm		        		CanComm;                  
//Alv_CAN_NiCan						NiCan_Handle;
//Alv_Test_Mfg_MfgTester				Test_Mfg_MfgTester_Handle;
//Alv_NarrowBand_SensorComm  			NarrowBand_SensorComm_Handle;
//Alv_NarrowBand_Sensor				NarrowBand_Sensor; 
//Alv_Test_SensorControl				Test_SensorControl_Handle;
//Alv_NarrowBand_NBProtocol_Status    NBProtocol_Status; 

/********************************************************
* Command to Get NB Test dll Version Number 
*********************************************************/

int getVersion (char **VersionNum)
{
	int status = -1; //true = 0
	
	status = Alv_MfgTest_Get_Version (VersionNum,0);
	
	return status;
}

/**********************************************************************
*Command to Discionnect CAN Communications 
***********************************************************************/
int Can_Disconnect(Alv_CAN_CanComm Handle, int *CanComm_Disconnect_ret)
 
 {     

	 int status = -1; //true = 0
	
	status = Alv_CAN_CanComm_Disconnect (Handle, CanComm_Disconnect_ret, 0);

	return status;

}

/************************************************************************
*Command to Get CAN Error Msg
*************************************************************************/

int Get_CanComm_Err(Alv_CAN_CanComm Handle, char **CanComm_Get_Error_str)
{
  
	int status = -1; //true = 0

	status =Alv_CAN_CanComm_Get_Error (Handle, CanComm_Get_Error_str, 0);

	return status;

}

/***************************************************************************************************   
*Command to Get CenterFrequency                             
****************************************************************************************************/ 

int Get_Center_Frequency (Alv_Test_Mfg_MfgTester Handle,Alv_NarrowBand_NBProtocol_Antenna antenna,
						  double * frequency,int * CenterFrequency_return)
{
	
	Alv_Test_Mfg_MfgTester_CenterFrequency(Handle,antenna,frequency, CenterFrequency_return,0);  
	
	return CenterFrequency_return;
}	

/******************************************************************************************    
*Command to Get TxPower                              
*******************************************************************************************/  

int Get_TxPower(Alv_Test_Mfg_MfgTester Handle,double * power, 
				Alv_NarrowBand_NBProtocol_Antenna antenna, int *TxPower_ret)
{
	
	Alv_Test_Mfg_MfgTester_TxPower(Handle, power,
				 antenna,TxPower_ret, 0);
	
	return TxPower_ret;
}

/********************************************************************************************   
*Command to Get CwLeakage                                     
**********************************************************************************************/ 
int Get_CwLeakage(Alv_Test_Mfg_MfgTester Handle,Alv_NarrowBand_NBProtocol_Antenna antenna,
				  double * leakage,int * cwleakage_return)
{

	int status=-1;  //true = 0  
	
	status =Alv_Test_Mfg_MfgTester_CwLeakage(Handle,antenna, leakage, cwleakage_return,0); 
	
	return cwleakage_return;
}	

/********************************************************   
* write to a point Command                         
*********************************************************/  

int write_to_point(Alv_NarrowBand_SensorComm Handle,unsigned short point,char * value,
					Alv_NarrowBand_NBProtocol_Status *NBProtocol_Status)
{

	int status=-1;  //true = 0  
	int statusReturn=1;
	
	status = Alv_NarrowBand_SensorComm_PointWrite(Handle,point, value ,NBProtocol_Status,0);
	
	if (*NBProtocol_Status == 0)
	{
		statusReturn = 0;	
	}
	
	return statusReturn;
}	                          
                                           

/********************************************************  
* Command to Set TxPowerCalHonda                                                         
*********************************************************/ 
int TxPowerCalHonda(Alv_Test_Mfg_MfgTester Handle,int gain_min,
					double pow_min,double pow_max,double ** points, 
					ssize_t *pointsLength1,ssize_t *pointsLength2
					,int *TxPowerCalHonda_return)
{
	int status=-1;  //true = 0  
	                                                                                                                                                
	status =Alv_Test_Mfg_MfgTester_TxPowerCalHonda(Handle, gain_min,pow_min, pow_max,points
									,pointsLength1,pointsLength2,TxPowerCalHonda_return, 0);

	return TxPowerCalHonda_return;
}	              

 /******************************************************** 
* Set TxPowerCalGM                                     
*********************************************************/
int TxPowerCalGM(Alv_Test_Mfg_MfgTester Handle,double max_bsd_pow, double max_rcta_pow, 
				 double min_bsd_pow, double min_rcta_pow, double **power_GM, ssize_t *powLength,
				unsigned short **amp_GM, ssize_t *ampLength,unsigned short **sw_GM, ssize_t *swLength,
				unsigned short **pdet_GM, ssize_t *pdetLength,unsigned short *thermistor_GM, int *returnValue_GM)
 
{ 
	
	int Status = -1;
	
	Status = Alv_Test_Mfg_MfgTester_TxPowerCalGM(Handle,max_bsd_pow, max_rcta_pow,min_bsd_pow, 
			 										min_rcta_pow,power_GM, powLength,amp_GM, ampLength,sw_GM, swLength,
													pdet_GM, pdetLength,thermistor_GM, returnValue_GM,0);
	
	
   	return returnValue_GM;
}	 
/********************************************************  
* Command to SelectTxAntenna                                                          
*********************************************************/ 
int SelectTxAntenna(Alv_NarrowBand_SensorComm Handle,Alv_NarrowBand_NBProtocol_Antenna antenna,
					Alv_NarrowBand_NBProtocol_Status *NBProtocol_Status)
{
	int status=-1;  //true = 0  
	
	status = Alv_NarrowBand_SensorComm_SelectTxAntenna(Handle,antenna,NBProtocol_Status,0);
	
	return NBProtocol_Status;
	
}	         

/********************************************************   
* Command to read OccupiedBW                                                          
*********************************************************/  
int OccupiedBW(Alv_Test_Mfg_MfgTester Handle, Alv_NarrowBand_NBProtocol_ControlRadarMode mode
			   ,int mode_time,double * bandwidth,int *OccupiedBW_ret)
 {
	
	int status=-1;  //true = 0 
	
 	status =Alv_Test_Mfg_MfgTester_OccupiedBW(Handle,mode,mode_time, bandwidth, OccupiedBW_ret,0);
	
	return OccupiedBW_ret;  	
	                	
}	                																	    
                    																	    
																						  	
/********************************************************   							  	                     
* Command to ForceRadarMode                                                          
*********************************************************/  
int	ForceRadarMode(Alv_NarrowBand_SensorComm Handle,Alv_NarrowBand_NBProtocol_ControlRadarMode mode,
				   Alv_NarrowBand_NBProtocol_Status *NBProtocol_Status)
{

	
	int status=-1;  //true = 0  
	
	status = Alv_NarrowBand_SensorComm_ForceRadarMode(Handle,mode,NBProtocol_Status,0);                                                           

	return NBProtocol_Status;  	   	
	                	   	
}	                	   	
                    	   	
/********************************************************   
* Command to Set_ControlCWMode (1 = enable, 0=disable)                                                          
*********************************************************/  
int SET_CW_Mode(Alv_Test_SensorControl Handle,int value)
{
	int status=-1;  //true = 0

	status= Alv_Test_SensorControl_Set_CwMode(Handle, value,0); 			   
			   
	return status;
                                                            
}

/********************************************************   
* Command to Read point                                                          
*********************************************************/  
int Read_Point(	Alv_NarrowBand_Sensor Handle,unsigned short point,
				char ** value,Alv_NarrowBand_NBProtocol_Status *NBProtocol_Status)
{
	
	int status=-1;  //true = 0  
	
	status= Alv_NarrowBand_Sensor_PointRead(Handle,point, value, NBProtocol_Status,0);
		
	return NBProtocol_Status;
}	
                                                            
                                                            
/********************************************************   
* Command to Make_Path                                                          
*********************************************************/  
int MakePath(Alv_Test_Mfg_MfgTester Handle, char * path,char * description,int *MakePath_return)                                                            
{

	
	int status=-1;  //true = 0  
	
	status= Alv_Test_Mfg_MfgTester_MakePath(Handle,path,description,MakePath_return,0);
		
	return MakePath_return;
}			   
                                                            
/**************************************************************************************************************************************************************   
* Ping Command                                                          
***************************************************************************************************************************************************************/  
                                                                                           
Ping(Alv_Test_Mfg_MfgTester Handle,char ** ping_serial,char ** ping_part_number0,char ** ping_part_number1,char ** ping_part_number2,char ** ping_part_number3
	 ,	char ** ping_sw_version0,char ** ping_sw_version1,char ** ping_sw_version2,char ** ping_sw_version3, int * Ping_returnValue)
{
	
	int status=-1;  //true = 0  
	status=  Alv_Test_Mfg_MfgTester_Ping(Handle, ping_serial,ping_part_number0, 
										 ping_part_number1,ping_part_number2, ping_part_number3,  
			 							 ping_sw_version0, ping_sw_version1,ping_sw_version2,     
										 ping_sw_version3,Ping_returnValue, 0);                    
			                                                                                         
		
	return Ping_returnValue;
	
}	

                                                            
                                                            
/********************************************************   
* InitTxCal                                                          
*********************************************************/  
int InitTxCal(Alv_Test_Mfg_MfgTester Handle,Alv_NarrowBand_Sensor comm, char * pathset, int * InitTxCal_return)
{

	int status=-1;  //true = 0  
	status= Alv_Test_Mfg_MfgTester_InitTxCal(Handle,comm, pathset,InitTxCal_return, 0);
	
	return InitTxCal_return;
}	

                                                            
/********************************************************   
* GetSwVersion                                                          
*********************************************************/  
int Get_SW_Version(Alv_Test_SensorControl Handle,char ** HpApp,char ** HpBoot,char ** DspApp,char ** DspBoot)
{
	int status = -1;  //true = 0
	
	status= Alv_Test_SensorControl_GetSwVersion_1(Handle,HpApp,HpBoot,DspApp,DspBoot,0);
		
	return status;
}

/********************************************************   
* GetPoint from NbTest.dll                                                      
*********************************************************/  
int Get_Point(Alv_Test_SensorControl Handle,unsigned short point,unsigned int * value)
{
	int status = -1;  //true = 0
	
	status=Alv_Test_SensorControl_GetPoint(Handle,point, value,0);

	return status;
}


/********************************************************   
* GetSerialNumber                                                          
*********************************************************/  
int Get_Serial_Number(Alv_Test_SensorControl Handle,char ** serial)
{
	int status = -1;  //true = 0
	
	status=  Alv_Test_SensorControl_GetSerial(Handle,serial,0);
	
	return status;
}

/******************************************************** 
* CAN Connect                                     
*********************************************************/
int CAN_Connect(Alv_CAN_CanComm Handle,int *Connection_Status)
{
	int status = -1;  //true = 0

	//status=Alv_CAN_NiCan_Connect (Handle,Connection_Status, 0);  
	status=Alv_CAN_CanComm_Connect (Handle,Connection_Status, 0);

	return Connection_Status;
	
}

/******************************************************** 
*Can_Set_DriverID                                                         
*********************************************************/
int Can_Set_DriverID(Alv_CAN_NiCan Handle,char * value)
{
	int status = -1;  //true = 0
	
	status= Alv_CAN_NiCan_Set_DriverID (Handle, value,0);
	
	return status;
	
}
                                                          
                                                          
/******************************************************** 
* init sensor Interface                                                        
*********************************************************/
int SensorComm_Init(Alv_NarrowBand_SensorComm Handle,char * pathsettings,Alv_NarrowBand_NBProtocol_Position SensorPosition,
					Alv_CAN_CanComm CanInterface,int *SensorComm_Init_ret)
{
	
	int status=-1;  //true = 0  
	status=Alv_NarrowBand_SensorComm_Init(Handle,pathsettings,SensorPosition,CanInterface, SensorComm_Init_ret,0);
   
	return SensorComm_Init_ret;
}


/********************************************************  
* Save Configuration                                         
*********************************************************/ 
int Save_config_points(Alv_NarrowBand_SensorComm Handle,Alv_NarrowBand_NBProtocol_ConfigurationBlock block,Alv_NarrowBand_NBProtocol_Status *NBProtocol_Status)
{
	
	int status=-1;  //true = 0  
	status = Alv_NarrowBand_SensorComm_SaveConfiguration(Handle,block,&NBProtocol_Status,0);

	return NBProtocol_Status;
}	

/**************************************************************** 
*Command to Discionnect TxCal     
*****************************************************************/		
int Disconnect_TxCal(Alv_Test_Mfg_MfgTester Handle)
{
	int status =-1;//true = 0 
	
	status =Alv_Test_Mfg_MfgTester_Disconnect(Handle,0);

	return status;
}



int Get_ErrorCodeNBProtocolStatus(short code, char *buf)
{
	switch(code)
	{
		case 0x0:
			sprintf(buf,"OK");
			break;
			
		case 0x1:
			sprintf(buf,"NOTVALID");
			break;
			
		case 0x2:
			sprintf(buf,"NOT_SUPPORTED");
			break;
			
		case 0x3:
			sprintf(buf,"NOT_WRITEABLE");
			break;
			
		case 0x4:
			sprintf(buf,"OUT_OF_RANGE");
			break;

		case 0x5:
			sprintf(buf,"NOT_IMPLEMENTED");
			break;
			
		case 0x6:
			sprintf(buf,"EXECUTION_TIMEOUT");
			break;
			
		case 0x7:
			sprintf(buf,"STATUS_BUSY");
			break;
			
		case 0x8:
			sprintf(buf,"UNEXPECTED_REQUEST");
			break;
			
		case 0x9:
			sprintf(buf,"UNEXPECTED_RESPONSE");
			break;
			
		case 0xA:
			sprintf(buf,"EXTENDED_START");	// or UNKNOWN_ERROR
			break;
			
		case 0xB:
			sprintf(buf,"EEPROM_HW_ERROR");
			break;
			
		case 0xC:
			sprintf(buf,"FAILDED_TO_START_STOP_SEQUENCER");
			break;
			
		case 0xD:
			sprintf(buf,"CONFIG_IO_BUSY");
			break;
			
		case 0xE:
			sprintf(buf,"CONFIG_IO_TIMED_OUT");
			break;
			
		case 0xF:
			sprintf(buf,"STATUS_RESERVED");
			break;
			
		case 0x10:
			sprintf(buf,"CONFIG_RADAR_INVALID");
			break;
			
		case 0x11:
			sprintf(buf,"STATUS_NO_ACCESSOR");
			break;
			
		case 0x75:
			sprintf(buf,"CAN_READ_ERROR");
			break;
			
		case 0x76:
			sprintf(buf,"CAN_WRITE_ERROR");
			break;
			
		case 0x77:
			sprintf(buf,"NOT_ALLOWED");
			break;
			
		case 0x78:
			sprintf(buf,"KEY_NOT_VALID");
			break;
			
		case 0x79:
			sprintf(buf,"INVALID_ENTRY");
			break;
			
		case 0x7A:
			sprintf(buf,"DATA_CHANGED ");
			break;
			
		case 0x7B:
			sprintf(buf,"POINT_NOT_FOUND");
			break;
			
		case 0xFE:
			sprintf(buf,"EXTENDED_STATUS");
			break;
			
			
	}
	
	
	return code;
	
}
