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


int CloseCAN_c6(int CANport);
int CloseController_c6(int CANport);
void DisableSICMsgs(int CANport);
void EnableSICMsgs(int CANport);
int FastWriteEEPROM_c6(int SensorID, int Adrs, int Value, int CANport);
int Get_MeasData_Array_c6(int SensorID, unsigned char MeasData[128], int CANport); 
int GetCSNnumber_c6(int SensorID, int CANport, char CSN[21]);
int GetMISnumber_c6(int SensorID, int CANport, char MIS[23]);
int InitCAN_c6(int CANport);
int InitController_c6(int CANport); 
int LoadSensorSoftware_c6(int SensorID, char *pDLFilename, int EnableReadStatus, int StatusAry[5][18][5], int CANport); 
int Ping_c6(int SensorIDArray[5][4], int CANport);
int Ping_new_c6(int SensorIDArray[5][8], int CANport); 
int ReadEEPROM_c6(int sensorID, int *arrayE2P, int CANport);
int ReadEEPROMPart_c6(int sensorID, int startAdr, int endAdr, int *arrayE2P, int CANport);
int SendCommand_c6(int sAddress, int NoBytes, int* CmdMess, int CANport);
int ReadCAN_Buffer_c6(int sAddress, int cmdIdent, int CanBuffer[8], int CANport);
int SetCANparameters_c6(int CAN_Hardware, int BaudRate); 
int SetControllerMode_c6(int CntrlMode); // Valid input, 0 for SRS100, 1 for CNX, 2 for SIC10  
int SetCSNnumber_c6(int SensorID, int CANport, char CSN[21]);
int SinglePing_c6(int SensorAddress, int SensorIDArray[4], int CANport); 
int WaitUntilNoEepromWritesRemains(int SensorAddress, int timeout_s, int CANport);
int WaitUntilNoEepromWritesRemains_c6(int SensorAddress, int timeout_s, int CANport);
int WriteEEPROM_c6(int SensorID, int StartAdrs, int EndAdrs, int *ArrayWr, int CANport);

