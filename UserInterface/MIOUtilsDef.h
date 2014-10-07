#include <DAQmxIOctrl.h>
#include <NIDAQmx.h>
#include "MIOUtilsLIBDef.h"  
//*******************************************************************************************************************

/*
struct			{ 
					int  MIO_Num;
					char descrp[TOT_MIO_LINE1][MAX_CHAR_LEN1];	  	
					int  port[TOT_MIO_LINE1];					
					int  bit[TOT_MIO_LINE1];
					int  device[TOT_MIO_LINE1];					
					int  disable[TOT_MIO_LINE1];
					char wire_tag[TOT_MIO_LINE1][20];
					int  num_MIO_card;
					struct DIOConfiguration MIOConfig_Port1[6];
					struct DIOConfiguration MIOConfig_Port2[6];
	  			}	MIO6220;
 */



//*******************************************************************************************************************
void MIOPrtLineName(int Dev, int Port);
void Dyn_Numeric1Handle(int i);
void Dyn_Numeric2Handle(int i);
void Dyn_Numeric3Handle(int i);

void Dyn_Numeric21Handle(int i);
void Dyn_Numeric22Handle(int i);
void Dyn_Numeric32Handle(int i);




int InitMDIOInterface(int Device, int totalNumberofPorts, int outputPortStarts);
int InitializeMIOAnalogInput(int Device, int totalChannels, int differential, int type);
int InitializeMIOAnalogOutput(int Device, int totalChannels);
void DisplayMANUALMIOConfiguration(void);
void DisplayMANUALMIOConfiguration2(void);

///int MDIOWriteOutput(char* DIO_Discription, int state, int Device);
void MIOUpdateManualIO(int Type, int Control[], int Device);
double MAIReadInputMultiChan(char* AI_Discription, int totalChannelNumber, int AISamplePerChannel,
	                         double maxVal, double minVal, char InputTermCfg[], double timeOut, int deviceNum);
bool DetermineMAIReadInputChan(int tIndex, double aValue, int tNest, char * timeTest);
double MAIReadInput(char* AI_Discription);
double MAOWriteOutput(char* AO_Discription, double value, int Device);

void MDIO_Dyn_OutputsButton1Handle(int i, int Device);
short MDIOReadInput(char* DIO_Discription, int Device);
int MDIOWriteOutput(char* DIO_Discription, int state, int Device);
bool AnalogVoltMeas(int testNumber, int nestNum);

bool CounterTimerFreq(int testNumber, int nestNum);

CmtThreadLockHandle AnalogVoltMeas_LockHandle; 
//*******************************************************************************************************************
