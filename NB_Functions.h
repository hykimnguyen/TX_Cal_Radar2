/**************************************************************************/
/* LabWindows/CVI User Interface Resource (UIR) Include File              */
/* Copyright (c) National Instruments 2014. All Rights Reserved.          */
/*                                                                        */
/* WARNING: Do not add to, delete from, or otherwise modify the contents  */
/*          of this include file.                                         */
/**************************************************************************/

#ifndef __nb_functions_H__
#define __nb_functions_H__

//nclude <userint.h>
//nclude "nblib.h"
//nclude "NbTestLive.h" 
//nclude "NiCanWrp.h"
//nclude <stdarg.h> 
//nclude <utility.h> 
#include <time.h>  
#define NUMUNITS  6
typedef struct	 
{

	char AEC_Backend;
	char Filler;
	char FlavorId;
	char AEC_SMT;
	char Daughter_Board;
	char Panel_Number[NUMUNITS];
	char Date[10];
	char Data_String[20];

} Create_Serial_Number;	

Create_Serial_Number getSerial[6];

typedef struct	 
{

	char Point_Value[6][NUMUNITS];

} Verify_Serial_Values;	

Verify_Serial_Values VerifySerial[6];		


int Get_CanComm_Err(Alv_CAN_CanComm Handle,char **CanComm_Get_Error_str);

int Can_Disconnect(Alv_CAN_CanComm Handle, int *CanComm_Disconnect_ret) ;

int getVersion (char **VersionNum);  

int Get_Center_Frequency (Alv_Test_Mfg_MfgTester Handle,Alv_NarrowBand_NBProtocol_Antenna antenna,
						  double * frequency,int * CenterFrequency_return);

int Get_TxPower(Alv_Test_Mfg_MfgTester Handle,double * power, 
				Alv_NarrowBand_NBProtocol_Antenna antenna, int *TxPower_ret);

int Get_CwLeakage(Alv_Test_Mfg_MfgTester Handle,Alv_NarrowBand_NBProtocol_Antenna antenna,
				  double * leakage,int * cwleakage_return);
 
int write_to_point(Alv_NarrowBand_SensorComm Handle,unsigned short point,char * value,
					Alv_NarrowBand_NBProtocol_Status *NBProtocol_Status);              

int TxPowerCalHonda(Alv_Test_Mfg_MfgTester Handle,int gain_min,double pow_min,double pow_max,double * power,double ** points,               
					ssize_t * __pointsLength1,ssize_t * __pointsLength2,int *TxPowerCalHonda_return);          

int SelectTxAntenna(Alv_NarrowBand_SensorComm Handle,Alv_NarrowBand_NBProtocol_Antenna antenna,
					Alv_NarrowBand_NBProtocol_Status *NBProtocol_Status);

int OccupiedBW(Alv_Test_Mfg_MfgTester Handle, Alv_NarrowBand_NBProtocol_ControlRadarMode mode,int mode_time
			   ,double * bandwidth,int *OccupiedBW_ret);

int	ForceRadarMode(Alv_NarrowBand_SensorComm Handle,Alv_NarrowBand_NBProtocol_ControlRadarMode mode, 
				   Alv_NarrowBand_NBProtocol_Status *NBProtocol_Status );                             

int SET_CW_Mode(Alv_Test_SensorControl Handle,int value);

int Read_Point(	Alv_NarrowBand_Sensor Handle,unsigned short point,char ** value,Alv_NarrowBand_NBProtocol_Status *NBProtocol_Status);

int MakePath(Alv_Test_Mfg_MfgTester Handle, char *path,char *description,int *MakePath_return);

int Ping(Alv_Test_Mfg_MfgTester  Handle,char ** ping_serial,char ** ping_part_number0,char ** ping_part_number1,char ** ping_part_number2,char ** ping_part_number3
	 ,	char ** ping_sw_version0,char ** ping_sw_version1,char ** ping_sw_version2,char ** ping_sw_version3, int * Ping_returnValue);

int InitTxCal(Alv_Test_Mfg_MfgTester Handle,Alv_NarrowBand_Sensor comm, char * pathset, int * InitTxCal_return);

int Get_SW_Version(Alv_Test_SensorControl Handle,char ** HpApp,char ** HpBoot,char ** DspApp,char ** DspBoot) ;

int Get_Serial_Number(Alv_Test_SensorControl Handle,char ** serial);

int CAN_Connect(Alv_CAN_CanComm Handle,int *Connection_Status);

int Can_Set_DriverID(Alv_CAN_NiCan Handle,char * value);

int SensorComm_Init(Alv_NarrowBand_SensorComm Handle,char * pathsettings,Alv_NarrowBand_NBProtocol_Position SensorPosition,
					Alv_CAN_CanComm CanInterface,int *SensorComm_Init_ret);

int Save_config_points(Alv_NarrowBand_SensorComm Handle,Alv_NarrowBand_NBProtocol_ConfigurationBlock block,Alv_NarrowBand_NBProtocol_Status *NBProtocol_Status);

int Disconnect_TxCal(Alv_Test_Mfg_MfgTester Handle);

int WriteManufacturingData(Alv_NarrowBand_Sensor Handle, int boardNum); //aa

int Serial_points_Check(Alv_NarrowBand_Sensor Handle,int boardNum,char * datastring); //aa

int Get_Point(Alv_Test_SensorControl Handle,unsigned short point,unsigned int * value);

int Get_ErrorCodeNBProtocolStatus(short code, char *buf);

int TxPowerCalGM(Alv_Test_Mfg_MfgTester Handle,double max_bsd_pow, double max_rcta_pow, 
				 double min_bsd_pow, double min_rcta_pow, double **power_GM, ssize_t *powLength,
				unsigned short **amp_GM, ssize_t *ampLength,unsigned short **sw_GM, ssize_t *swLength,
				unsigned short **pdet_GM, ssize_t *pdetLength,unsigned short *thermistor_GM, int *returnValue_GM);
#endif  /* ndef __nb_functions_H__ */
