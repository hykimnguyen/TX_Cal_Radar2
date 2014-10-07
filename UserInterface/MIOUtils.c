/***********************************************************************
 *
 *
 *  COPYRIGHT: Arxtron Technologies Inc. All Rights Reserved.
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
*    @file    MIOUtils.c
*    @brief   Utilities for MIO 6220
*    @author  Arxtron Technologies Inc.
*    @date    2013.9.6
*    Utility functions for MIO 6220
*    
*/ 

#include "MIO6220.h"
#include <cvirte.h>		
#include <userint.h>
#include "Global.h"
#include "DataLib.h"  
#include "MIOUtils.h"
#include "MIOUtilsDef.h" 
#include "TestConfiguration_Def.h"
#include "TextUtils.h"  
#include "test_output_log.h" 
#include "Measurements.h"
#include "TestSteps.h"


#define	USEDATAACQ  /// Enable / Disable DAQ Functionality
#ifdef USEDATAACQ
#endif
//*******************************************************************************************************************
#define DAQmxErrChk(functionCall) if( DAQmxFailed(error=(functionCall)) ) goto Error; else
//*******************************************************************************************************************

struct		MIOMANUALPNLPARAM6220 { //MANUAL PANEL CONTROLS PARAMETER  
								int 		NumberofDevices;
								int			MIO_DECORATION_INPUT;
								int			MIO_DECORATION_INPUT2;
								int 		MIO_DECORATION_OUTPUT;
								int 		MIO_DECORATION_OUTPUT2;
								int			MIO_DECORATION_INPUT3;
								char		External_Module_Name[100];
								int			MIO_DECORATION_INPUT_LEFT;
								int			MIO_DECORATION_INPUT_TOP;
								int			MIO_DECORATION_OUTPUT_LEFT;
								int			MIO_DECORATION_OUTPUT_TOP;
								char		Device_Title1[100];
								char		Device_Title2[100];
								char		MIO_LED_LABEL_TITLE[TOTAL_INPUT_LINE][100];
								int			MDIO_LEDTextTitle[TOTAL_INPUT_LINE]; 
								int			MDIO_LED[TOTAL_INPUT_LINE];
								int			MDIO_DYN_BUTTON[TOTAL_OUTPUT_LINE];
								int			MDIO_DYN_LED_OUT[TOTAL_OUTPUT_LINE];
								char		MDIO_ButtonTitle[TOTAL_OUTPUT_LINE][100];
								char		CallBackEventHandler[100];
								int			PortLineOfset;
							};
							
struct		MIOMANUALPNLPARAM6220			MIO6220_MN_PNL_ParametersAI, *Ptr_MIO6220_MN_PNL_ParametersAI, MIO6220_MN_PNL_ParametersAI2, *Ptr_MIO6220_MN_PNL_ParametersAI2; 
struct		MIOMANUALPNLPARAM6220			MIO6220_MN_PNL_ParametersAO, *Ptr_MIO6220_MN_PNL_ParametersAO, MIO6220_MN_PNL_ParametersAO2, *Ptr_MIO6220_MN_PNL_ParametersAO2;
struct		MIOMANUALPNLPARAM6220			MIO6220_MN_PNL_ParametersMIO, *Ptr_MIO6220_MN_PNL_ParametersDIO, MIO6220_MN_PNL_ParametersMIO2, *Ptr_MIO6220_MN_PNL_ParametersDIO2;

void Create6220MANUAOConfigurationTable(int PanelHandler, struct	MIOMANUALPNLPARAM6220	*ptrPanelControlParams);
void Create6220MANUAOConfigurationTable2(int PanelHandler, struct	MIOMANUALPNLPARAM6220	*ptrPanelControlParams);
void CreateMANUAIConfigurationTable(int PanelHandler, struct	MIOMANUALPNLPARAM6220	*ptrPanelControlParams);
void CreateMANUAIConfigurationTable2(int PanelHandler, struct	MIOMANUALPNLPARAM6220	*ptrPanelControlParams);
void Create6220MANUMDIOConfigurationTable(int PanelHandler, struct	MIOMANUALPNLPARAM6220	*ptrPanelControlParams);
void Create6220MANUMDIOConfigurationTable2(int PanelHandler, struct	MIOMANUALPNLPARAM6220	*ptrPanelControlParams);
void Init6220MANUALTableAI(int PanelHandler, struct MIOMANUALPNLPARAM6220	*ptrPanelControlParams);
void Init6220MANUALTableAO(int PanelHandler, struct MIOMANUALPNLPARAM6220	*ptrPanelControlParams);
void Init6220MANUALTableMDIO(int PanelHandler, struct MIOMANUALPNLPARAM6220	*ptrPanelControlParams);

void Init6220MANUALTableAI2(int PanelHandler, struct MIOMANUALPNLPARAM6220	*ptrPanelControlParams);
void Init6220MANUALTableAO2(int PanelHandler, struct MIOMANUALPNLPARAM6220	*ptrPanelControlParams);
void Init6220MANUALTableMDIO2(int PanelHandler, struct MIOMANUALPNLPARAM6220	*ptrPanelControlParams);


int InitMDIOInterface(int Device, int totalNumberofPorts, int outputPortStarts)    
{   
	int returnVal;
	///#ifdef USEDATAACQ
	////***
	returnVal = InitMDIOInterface_LIB(Device, totalNumberofPorts, outputPortStarts);
	
	return returnVal;
}
///************************************************************************************************************
int InitializeMIOAnalogInput(int Device, int totalChannels, int differential, int type)
{

	
	InitializeMIOAnalogInput_LIB(Device, totalChannels, differential, type);
		
	return 0;
}

///************************************************************************************************************
int InitializeMIOAnalogOutput(int Device, int totalChannels)
{
	int returnVal;

	
	returnVal = InitializeMIOAnalogOutput_LIB(Device, totalChannels);
		
	return returnVal;
}

///************************************************************************************************************
int CVICALLBACK MIOUtilsExitCB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
						#if USE_EXT_MAIN_PROJ
							CheckError(HidePanel(MIOUtilsPanelHandle)); 
						#else		
							QuitUserInterface (0);
						#endif
			break;
		case EVENT_KEYPRESS:

			break;
	}
	return 0;
}
//********************************************************************************************************************
int CVICALLBACK MIOUtilsWriteButtonCB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{

	switch (event)
	{
		case EVENT_COMMIT:

			break;
		case EVENT_KEYPRESS:

			break;
	}
	return 0;
}
//*******************************************************************************************************************
// Update Manual Input / Output
// Inputs: 
//        Type: 	Input Or Output
//		  Control:	Pointer to the Specific Controls
//        Device:	Which Device (Device Number)
// Output:
//    	  None
//*******************************************************************************************************************
void UpdateManualMIO(int Type, int Control[], int Device)
{
	short 			i, PortValue;
	
	for(i=0;i<TOTAL_NUMBER_OF_INPUT_PORTS;i++)
	{
		if(Type)
		{
			PortValue=Input_Port_Val_MIO[i];  // Current Input Port Value
			UpdateMIOPort(i, PortValue, Control, Type, Device); /// Update the Controls with Current Status
		}

	}
}
//*******************************************************************************************************************
// Update IO Ports Status
// Inputs: 
//        index:    Control Index
//        PortValue	Input Or Output Status
//		  Control:	Pointer to the Specific Controls
//		  Type: 	Input Or Output
//        Device:	Which Device (Device Number)
// Output:
//    	  None
//*******************************************************************************************************************
void UpdateMIOPort(int index, int PortValue, int Control[], int Type, int Device)
{
	int			Set, Reset, BIT_ON, TabPanelHandle;
	
	if(Device==MIO6220DeviceNum1)
	{
		GetPanelHandleFromTabPage (MIOUtilsPanelHandle, MIOUTL_PNL_MIO_TAB, TAB_PAGE_THREE, &TabPanelHandle);
	}
	else if(Device==MIO6220DeviceNum2)
	{
		GetPanelHandleFromTabPage (MIOUtilsPanelHandle2, MIOUTLPNL2_MIO_TAB2, TAB_PAGE_THREE, &TabPanelHandle);
	}
	
	Set=1; Reset=0;		/// Output

	BIT_ON=PortValue & BIT_7;	
	if (BIT_ON == BIT_7)
		{
			SetCtrlVal (TabPanelHandle, Control[(index*PORT_SIZE)+7], Set); 
		}
		else
		{
			SetCtrlVal (TabPanelHandle, Control[(index*PORT_SIZE)+7], Reset); 
		}
	BIT_ON=PortValue & BIT_6;
	if (BIT_ON == BIT_6) 
		{
			SetCtrlVal (TabPanelHandle, Control[(index*PORT_SIZE)+6], Set); 
		}
		else
		{
			SetCtrlVal (TabPanelHandle, Control[(index*PORT_SIZE)+6], Reset); 
		}
	BIT_ON=PortValue & BIT_5;
	if (BIT_ON == BIT_5)
		{
			SetCtrlVal (TabPanelHandle, Control[(index*PORT_SIZE)+5], Set); 
		}
		else
		{
			SetCtrlVal (TabPanelHandle, Control[(index*PORT_SIZE)+5], Reset); 
		}
	BIT_ON=PortValue & BIT_4;
	if (BIT_ON == BIT_4)
		{
			SetCtrlVal (TabPanelHandle, Control[(index*PORT_SIZE)+4], Set); 
		}
		else
		{
			SetCtrlVal (TabPanelHandle, Control[(index*PORT_SIZE)+4], Reset); 
		}
	BIT_ON=PortValue & BIT_3;
	if (BIT_ON == BIT_3)
		{
			SetCtrlVal (TabPanelHandle, Control[(index*PORT_SIZE)+3], Set); 
		}
		else
		{
			SetCtrlVal (TabPanelHandle, Control[(index*PORT_SIZE)+3], Reset); 
		}
	BIT_ON=PortValue & BIT_2;
	if (BIT_ON == BIT_2)
		{
			SetCtrlVal (TabPanelHandle, Control[(index*PORT_SIZE)+2], Set); 
		}
		else
		{
			SetCtrlVal (TabPanelHandle, Control[(index*PORT_SIZE)+2], Reset); 
		}
	BIT_ON=PortValue & BIT_1;
	if (BIT_ON == BIT_1)
		{
			SetCtrlVal (TabPanelHandle, Control[(index*PORT_SIZE)+1], Set); 
		}
		else
		{
			SetCtrlVal (TabPanelHandle, Control[(index*PORT_SIZE)+1], Reset); 
		}
		BIT_ON=PortValue & BIT_0;
	if (BIT_ON == BIT_0)
		{
			SetCtrlVal (TabPanelHandle, Control[(index*PORT_SIZE)+0], Set); 
		}
		else
		{
			SetCtrlVal (TabPanelHandle, Control[(index*PORT_SIZE)+0], Reset); 
		}
}
//*******************************************************************************************************************

int CVICALLBACK EnablDisableReadDIOTimerCB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int ONOFF;
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal(panel, control, &ONOFF );
			if(ONOFF)
			{
				 SetCtrlAttribute (MIOUtilsPanelHandle, MIOUTL_PNL_READIOTIMER, ATTR_ENABLED, 1);
			}
			else
			{
				 SetCtrlAttribute (MIOUtilsPanelHandle, MIOUTL_PNL_READIOTIMER, ATTR_ENABLED, 0);
			}
				

			break;
		case EVENT_VAL_CHANGED:

			break;
		case EVENT_KEYPRESS:

			break;
	}
	return 0;
}
//*******************************************************************************************************************
int CVICALLBACK ReadDIOTimerCB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	
    #ifdef USEDATAACQ

	switch (event)
	{
		case EVENT_TIMER_TICK:
			 ReadDIOTimerCB_LIB(); 
			break;
	}
	#endif 
	return 0;
}
//*******************************************************************************************************************
int CVICALLBACK EnablDisableReadAITimerCB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int ONOFF;
	
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal(panel, control, &ONOFF );
			if(ONOFF)
			{
				 SetCtrlAttribute (MIOUtilsPanelHandle, MIOUTL_PNL_READAITIMER, ATTR_ENABLED, 1);
			}
			else
			{
				 SetCtrlAttribute (MIOUtilsPanelHandle, MIOUTL_PNL_READAITIMER, ATTR_ENABLED, 0);
			}

			break;
		case EVENT_VAL_CHANGED:

			break;
		case EVENT_KEYPRESS:

			break;
	}
	return 0;
}
//*******************************************************************************************************************
int CVICALLBACK ReadDAITimerCB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		int TabPanelHandle;
		case EVENT_TIMER_TICK:
			GetPanelHandleFromTabPage (MIOUtilsPanelHandle, MIOUTL_PNL_MIO_TAB, TAB_PAGE_ONE, &TabPanelHandle);	
			ReadDAITimerCB_LIB(TabPanelHandle);
			break;
	}
	return 0;
}
/********************************************************
*
* FUNCTION NAME: MAIReadInput
* 
* DESCRIPTION: Read a single channel from the DAQ card
*              
*
* ARGUMENT LIST: 
* 
* ARGUMENT        TYPE     I/O    DESCRIPTION       
* --------        ----     ---    ----------- 
* AI_Discription char      I     Label name of the AI channel
*
* RETURNS: measured value
* 
*********************************************************/
double MAIReadInput(char* AI_Discription)
{
	#define TOTAL_AI_CHANNEL 80
	int 				TabPanelHandle;
	float64     		returnVal;
	
	#ifdef USEDATAACQ
	GetPanelHandleFromTabPage (MIOUtilsPanelHandle, MIOUTL_PNL_MIO_TAB, TAB_PAGE_ONE, &TabPanelHandle);
	
	returnVal = MAIReadInput_LIB(AI_Discription);

	#endif
	return returnVal;
}
/********************************************************
*
* FUNCTION NAME: AnalogVoltMeas
* 
* DESCRIPTION: Read a single channel from the DAQ card
*              
*
* ARGUMENT LIST: 
* 
* ARGUMENT        TYPE     I/O    DESCRIPTION       
* --------        ----     ---    ----------- 
* testNumber      int       I     ID for the test sequence config
* nestNum		  int       I     daughterboard number 
*
* RETURNS: bool status
* 
*********************************************************/
/********************************************//**
* Read a single channel from the DAQ card (eg. Current measurement)
***********************************************/ 
bool AnalogVoltMeas(int testNumber, int nestNum)
{	
	CmtGetLock(AnalogVoltMeas_LockHandle);

	bool status = 0;
	bool fctstatus;
	char channelName[100];
	int sample = 1999;

	int repeat = 0;
	int repeatMax = 0;
	char field_tmp[100];  
	int device = 0;

	double low_thresh = 0;
	double high_thresh = 0;
	double aValue = 0;
	double aRead[2000]; 
	
	double StartTime,EndTime; 
	char testTime[100] = {0};
    StartTime = Timer(); 	

	
	device = MIO6220DeviceNum1;
	
	low_thresh = CurrentLowLimit;
	high_thresh = CurrentHighLimit;
	sprintf(channelName,"1,%d:V_OPAMP",nestNum+1);

	repeatMax=4;  // repeat if initial measurement is not stable
	
	do
	{
		memset(aRead,0,sizeof(aRead));
		aValue = 0;
		status = GLB_FALSE;
		fctstatus =  GLB_FALSE;
		fctstatus = MAIReadInputMultiChan_LIB(channelName, 1, sample, 10.0,-10.0, "", 1.0, device, nestNum, aRead);

		if (fctstatus)
		{
			for (int i = 0;i<sample;i++)
			{
				aValue += aRead[i];	
			}
			aValue = aValue/sample;
			
			aValue /= 5;  // Scale because of voltage divider.
			aValue *= 1000; //(in mA)
			if((aValue >= low_thresh) && (aValue <= high_thresh))
			{
				status = GLB_TRUE;
			}
		}
		repeat++;
	}while (!status  && (repeat<repeatMax));
	
		
	EndTime=Timer() - StartTime;   
	sprintf(testTime, "%4.1f", EndTime);	
	
	sprintf(mtgTestStepInfo[nestNum][testNumber-1].testResultVal, "Current[mA] = %.3f", aValue); 
	sprintf(field_tmp,"%.3f", aValue);  
	add_data_to_test_output_log(nestNum,field_tmp); 
	
	addMeasureCurrentToIts(testNumber,nestNum,low_thresh,high_thresh,aValue, !status);
	CmtReleaseLock(AnalogVoltMeas_LockHandle);   
	return !status;
} // end AnalogVoltMeas

/********************************************************
*
* FUNCTION NAME: MAOWriteOutput
* 
* DESCRIPTION: Write a voltage value to the output of a channel on the DAQ card
*              
*
* ARGUMENT LIST: 
* 
* ARGUMENT        TYPE     I/O    DESCRIPTION       
* --------        ----     ---    ----------- 
* AO_Discription  char      I     Label for the output channel
* value		      double    I     Value to be generated
* Device		  int		I	  device number for the DAQ card
*
* RETURNS: measured value
* 
*********************************************************/
double MAOWriteOutput(char* AO_Discription, double value, int Device)
{
	#define TOTAL_AO_CHANNEL 2
	
	float64     		returnVal=0.0;
	#ifdef USEDATAACQ

		returnVal = MAOWriteOutput_LIB(AO_Discription, value, Device);

	#endif
	return returnVal;
}
//*******************************************************************************************************************
void DisplayMANUALMIOConfiguration(void)
{
	First_Manual_Pnl=1;   ///
	if(First_Manual_Pnl)
	{
		Ptr_MIO6220_MN_PNL_ParametersAI=&MIO6220_MN_PNL_ParametersAI;
		Ptr_MIO6220_MN_PNL_ParametersAO=&MIO6220_MN_PNL_ParametersAO;
		Ptr_MIO6220_MN_PNL_ParametersDIO=&MIO6220_MN_PNL_ParametersMIO;

		Ptr_MIO6220_MN_PNL_ParametersAI2=&MIO6220_MN_PNL_ParametersAI2;
		Ptr_MIO6220_MN_PNL_ParametersAO2=&MIO6220_MN_PNL_ParametersAO2;
		Ptr_MIO6220_MN_PNL_ParametersDIO2=&MIO6220_MN_PNL_ParametersMIO2;
		
		Ptr_MIO6220_MN_PNL_ParametersDIO->NumberofDevices=1;                            
		strcpy(Ptr_MIO6220_MN_PNL_ParametersDIO->External_Module_Name,"MIOUtils.C");                  
		strcpy(Ptr_MIO6220_MN_PNL_ParametersDIO->External_Module_Name,"MIOUtils.C");
		strcpy(Ptr_MIO6220_MN_PNL_ParametersAI->External_Module_Name,"MIOUtils.C");
		strcpy(Ptr_MIO6220_MN_PNL_ParametersAO->External_Module_Name,"MIOUtils.C");
		
		strcpy(Ptr_MIO6220_MN_PNL_ParametersDIO->Device_Title1,"Multi Functional Digital Inputs Outputs");
		strcpy(Ptr_MIO6220_MN_PNL_ParametersDIO->Device_Title2,"Multi Functional Digital Inputs Outputs");                         
		strcpy(Ptr_MIO6220_MN_PNL_ParametersDIO->CallBackEventHandler,"MDIOOutputsCommandButtonsCB");                  
	
		Init6220MANUALTableAI(MIOUtilsPanelHandle, Ptr_MIO6220_MN_PNL_ParametersAI);
		Init6220MANUALTableAO(MIOUtilsPanelHandle, Ptr_MIO6220_MN_PNL_ParametersAO);
		Init6220MANUALTableMDIO(MIOUtilsPanelHandle, Ptr_MIO6220_MN_PNL_ParametersDIO);

		DisplayPanel(MIOUtilsPanelHandle);
	}
}
//*******************************************************************************************************************
void DisplayMANUALMIOConfiguration2(void)
{
	First_Manual_Pnl=1;   ///
	if(First_Manual_Pnl)
	{
		Ptr_MIO6220_MN_PNL_ParametersAI=&MIO6220_MN_PNL_ParametersAI;
		Ptr_MIO6220_MN_PNL_ParametersAO=&MIO6220_MN_PNL_ParametersAO;
		Ptr_MIO6220_MN_PNL_ParametersDIO=&MIO6220_MN_PNL_ParametersMIO;

		Ptr_MIO6220_MN_PNL_ParametersAI2=&MIO6220_MN_PNL_ParametersAI2;
		Ptr_MIO6220_MN_PNL_ParametersAO2=&MIO6220_MN_PNL_ParametersAO2;
		Ptr_MIO6220_MN_PNL_ParametersDIO2=&MIO6220_MN_PNL_ParametersMIO2;

		Ptr_MIO6220_MN_PNL_ParametersDIO2->NumberofDevices=1;                            
		strcpy(Ptr_MIO6220_MN_PNL_ParametersDIO2->External_Module_Name,"MIOUtils.C");                  
		strcpy(Ptr_MIO6220_MN_PNL_ParametersDIO2->External_Module_Name,"MIOUtils.C");
		strcpy(Ptr_MIO6220_MN_PNL_ParametersAI2->External_Module_Name,"MIOUtils.C");
		strcpy(Ptr_MIO6220_MN_PNL_ParametersAO2->External_Module_Name,"MIOUtils.C");
		
		strcpy(Ptr_MIO6220_MN_PNL_ParametersDIO2->Device_Title2,"Multi Functional Digital Inputs Outputs");                         
		strcpy(Ptr_MIO6220_MN_PNL_ParametersDIO2->CallBackEventHandler,"MDIOOutputsCommandButtonsCB");

		Init6220MANUALTableAI(MIOUtilsPanelHandle2, Ptr_MIO6220_MN_PNL_ParametersAI2);
		Init6220MANUALTableAO(MIOUtilsPanelHandle2, Ptr_MIO6220_MN_PNL_ParametersAO2);
		Init6220MANUALTableMDIO(MIOUtilsPanelHandle2, Ptr_MIO6220_MN_PNL_ParametersDIO2);
		
		DisplayPanel(MIOUtilsPanelHandle2);
	
	}
}
//*******************************************************************************************************************
void InitMANUALTableAI(int PanelHandler, struct MIOMANUALPNLPARAM6220	*ptrPanelControlParams)
{
	CreateMANUAIConfigurationTable(PanelHandler, ptrPanelControlParams);
}
//*******************************************************************************************************************
void InitMANUALTableAO(int PanelHandler, struct MIOMANUALPNLPARAM6220	*ptrPanelControlParams)
{
	Create6220MANUAOConfigurationTable(PanelHandler, ptrPanelControlParams);
}
//*******************************************************************************************************************
void Init6220MANUALTableMDIO(int PanelHandler, struct MIOMANUALPNLPARAM6220	*ptrPanelControlParams)
{
	Create6220MANUMDIOConfigurationTable(PanelHandler, ptrPanelControlParams);
}
//*******************************************************************************************************************
void Init6220MANUALTableAI(int PanelHandler, struct MIOMANUALPNLPARAM6220	*ptrPanelControlParams)
{
	CreateMANUAIConfigurationTable(PanelHandler, ptrPanelControlParams);
}
//*******************************************************************************************************************
void Init6220MANUALTableAI2(int PanelHandler, struct MIOMANUALPNLPARAM6220	*ptrPanelControlParams)
{
	CreateMANUAIConfigurationTable2(PanelHandler, ptrPanelControlParams);
}
//*******************************************************************************************************************
void Init6220MANUALTableAO(int PanelHandler, struct MIOMANUALPNLPARAM6220	*ptrPanelControlParams)
{
	Create6220MANUAOConfigurationTable(PanelHandler, ptrPanelControlParams);
}
//*******************************************************************************************************************
void Init6220MANUALTableAO2(int PanelHandler, struct MIOMANUALPNLPARAM6220	*ptrPanelControlParams)
{
	Create6220MANUAOConfigurationTable2(PanelHandler, ptrPanelControlParams);
}
//*******************************************************************************************************************
void Init6220MANUALTableMDIO2(int PanelHandler, struct MIOMANUALPNLPARAM6220	*ptrPanelControlParams)
{
	Create6220MANUMDIOConfigurationTable2(PanelHandler, ptrPanelControlParams);
}
//*******************************************************************************************************************
void CreateMANUAIConfigurationTable(int PanelHandler, struct	MIOMANUALPNLPARAM6220	*ptrPanelControlParams)
{
	int			i, TabPanelHandle;
// -----------------------------------------------------------------------------------------------------------------------	
	//CREATE DECORATION FOR THE INPUT AND OUTPUTS
	
	GetPanelHandleFromTabPage (PanelHandler, MIOUTL_PNL_MIO_TAB, TAB_PAGE_ONE, &TabPanelHandle);	
	
	
	ptrPanelControlParams->MIO_DECORATION_INPUT2= 
	                       LIB_CreateDecorationControl(TabPanelHandle, 
	                                                    ptrPanelControlParams->External_Module_Name, 
	                                                    25, 610, 10, 460, "ANALOG INPUTS");
	ptrPanelControlParams->MIO_DECORATION_OUTPUT2= 
	                       LIB_CreateDecorationControl(TabPanelHandle, 
	                                                    ptrPanelControlParams->External_Module_Name, 
	                                                    25, 610, 480, 460, "ANALOG INPUTS");

	GetCtrlAttribute (TabPanelHandle, ptrPanelControlParams->MIO_DECORATION_INPUT2, ATTR_LEFT,
					  &ptrPanelControlParams->MIO_DECORATION_INPUT_LEFT);
	GetCtrlAttribute (TabPanelHandle, ptrPanelControlParams->MIO_DECORATION_INPUT2, ATTR_TOP,
					  &ptrPanelControlParams->MIO_DECORATION_INPUT_TOP);

	for(i=0; i<40; i++)
	{
		strcpy(NUMERIC1_LABEL_TITLE[i],MAIInfo[MIO6220DeviceNum1][i].AIChannelName);
	}
	
	LIB_CreateNumericControls1(TabPanelHandle, ptrPanelControlParams->External_Module_Name, "NumericControl1CB", 
						       DYN_NUMERIC1,NUMERICTextTitle1,ptrPanelControlParams->MIO_DECORATION_INPUT_TOP+25,
							   80,100,70,ptrPanelControlParams->MIO_DECORATION_INPUT_LEFT+20,
	                           40,1,NUMERIC1_LABEL_TITLE, VAL_BLACK, 
							   VAL_LT_GRAY, 14, VAL_CENTER_JUSTIFIED, VAL_BLACK, VAL_INDICATOR, 10,2, 20, 230);

	for(i=40; i<80; i++)
	{
		strcpy(NUMERIC2_LABEL_TITLE[i-40],MAIInfo[MIO6220DeviceNum1][i].AIChannelName);
	}
	
	LIB_CreateNumericControls1(TabPanelHandle, ptrPanelControlParams->External_Module_Name, "NumericControl2CB", 
						       DYN_NUMERIC2,NUMERICTextTitle1,ptrPanelControlParams->MIO_DECORATION_INPUT_TOP+25,
							   80,100,70,ptrPanelControlParams->MIO_DECORATION_INPUT_LEFT+500,
	                           40,1,NUMERIC2_LABEL_TITLE, VAL_BLACK, 
							   VAL_LT_GRAY, 14, VAL_CENTER_JUSTIFIED, VAL_BLACK, VAL_INDICATOR, 10,2, 20, 230);
	
}

//*******************************************************************************************************************
void CreateMANUAIConfigurationTable2(int PanelHandler, struct	MIOMANUALPNLPARAM6220	*ptrPanelControlParams)
{
	int			i, TabPanelHandle;
// -----------------------------------------------------------------------------------------------------------------------	
	//CREATE DECORATION FOR THE INPUT AND OUTPUTS
	
	GetPanelHandleFromTabPage (PanelHandler, MIOUTLPNL2_MIO_TAB2, TAB_PAGE_ONE, &TabPanelHandle);	
	
	
	ptrPanelControlParams->MIO_DECORATION_INPUT2= 
	                       LIB_CreateDecorationControl(TabPanelHandle, 
	                                                    ptrPanelControlParams->External_Module_Name, 
	                                                    25, 610, 10, 460, "ANALOG INPUTS");
	ptrPanelControlParams->MIO_DECORATION_OUTPUT2= 
	                       LIB_CreateDecorationControl(TabPanelHandle, 
	                                                    ptrPanelControlParams->External_Module_Name, 
	                                                    25, 610, 480, 460, "ANALOG INPUTS");

	GetCtrlAttribute (TabPanelHandle, ptrPanelControlParams->MIO_DECORATION_INPUT2, ATTR_LEFT,
					  &ptrPanelControlParams->MIO_DECORATION_INPUT_LEFT);
	GetCtrlAttribute (TabPanelHandle, ptrPanelControlParams->MIO_DECORATION_INPUT2, ATTR_TOP,
					  &ptrPanelControlParams->MIO_DECORATION_INPUT_TOP);

	for(i=0; i<40; i++)
	{
		strcpy(NUMERIC21_LABEL_TITLE[i],MAIInfo[MIO6220DeviceNum2][i].AIChannelName);
	}
	
	LIB_CreateNumericControls1(TabPanelHandle, ptrPanelControlParams->External_Module_Name, "NumericControl1CB", 
						       DYN_NUMERIC21,NUMERICTextTitle21,ptrPanelControlParams->MIO_DECORATION_INPUT_TOP+25,
							   80,100,70,ptrPanelControlParams->MIO_DECORATION_INPUT_LEFT+20,
	                           40,1,NUMERIC21_LABEL_TITLE, VAL_BLACK, 
							   VAL_LT_GRAY, 14, VAL_CENTER_JUSTIFIED, VAL_BLACK, VAL_INDICATOR, 10,2, 20, 230);

	for(i=40; i<80; i++)
	{
		strcpy(NUMERIC22_LABEL_TITLE[i-40],MAIInfo[MIO6220DeviceNum2][i].AIChannelName);
	}
	
	LIB_CreateNumericControls1(TabPanelHandle, ptrPanelControlParams->External_Module_Name, "NumericControl2CB", 
						       DYN_NUMERIC22,NUMERICTextTitle21,ptrPanelControlParams->MIO_DECORATION_INPUT_TOP+25,
							   80,100,70,ptrPanelControlParams->MIO_DECORATION_INPUT_LEFT+500,
	                           40,1,NUMERIC22_LABEL_TITLE, VAL_BLACK, 
							   VAL_LT_GRAY, 14, VAL_CENTER_JUSTIFIED, VAL_BLACK, VAL_INDICATOR, 10,2, 20, 230);
	
}

//*******************************************************************************************************************
void Create6220MANUAOConfigurationTable(int PanelHandler, struct	MIOMANUALPNLPARAM6220	*ptrPanelControlParams)
{
	int			i, TabPanelHandle;
// -----------------------------------------------------------------------------------------------------------------------	
	//CREATE DECORATION FOR THE INPUT AND OUTPUTS
	
	GetPanelHandleFromTabPage (PanelHandler, MIOUTL_PNL_MIO_TAB, TAB_PAGE_TWO, &TabPanelHandle);	
	
	
	ptrPanelControlParams->MIO_DECORATION_INPUT3= 
	                       LIB_CreateDecorationControl(TabPanelHandle, 
	                                                    ptrPanelControlParams->External_Module_Name, 
	                                                    25, 610, 10, 460, "ANALOG OUTPUTS");

	GetCtrlAttribute (TabPanelHandle, ptrPanelControlParams->MIO_DECORATION_INPUT3, ATTR_LEFT,
					  &ptrPanelControlParams->MIO_DECORATION_INPUT_LEFT);
	GetCtrlAttribute (TabPanelHandle, ptrPanelControlParams->MIO_DECORATION_INPUT3, ATTR_TOP,
					  &ptrPanelControlParams->MIO_DECORATION_INPUT_TOP);
	for(i=0; i<2; i++)
	{
		strcpy(NUMERIC3_LABEL_TITLE[i],MAOInfo[MIO6220DeviceNum1][i].AOChannelName);
	}
	
	LIB_CreateNumericControls1(TabPanelHandle, ptrPanelControlParams->External_Module_Name, "NumericControl3CB", 
						       DYN_NUMERIC3,NUMERICTextTitle1,ptrPanelControlParams->MIO_DECORATION_INPUT_TOP+25,
							   80,100,100,ptrPanelControlParams->MIO_DECORATION_INPUT_LEFT+20,
	                           2,1,NUMERIC3_LABEL_TITLE, VAL_BLACK, 
							   VAL_LT_GRAY, 14, VAL_CENTER_JUSTIFIED, VAL_BLACK, VAL_NORMAL, 10,2, 20, 230);
}
//*******************************************************************************************************************
void Create6220MANUAOConfigurationTable2(int PanelHandler, struct	MIOMANUALPNLPARAM6220	*ptrPanelControlParams)
{
	int			i, TabPanelHandle;
// -----------------------------------------------------------------------------------------------------------------------	
	//CREATE DECORATION FOR THE INPUT AND OUTPUTS
	
	GetPanelHandleFromTabPage (PanelHandler, MIOUTLPNL2_MIO_TAB2, TAB_PAGE_TWO, &TabPanelHandle);	
	
	
	ptrPanelControlParams->MIO_DECORATION_INPUT3= 
	                       LIB_CreateDecorationControl(TabPanelHandle, 
	                                                    ptrPanelControlParams->External_Module_Name, 
	                                                    25, 610, 10, 460, "ANALOG OUTPUTS");

	GetCtrlAttribute (TabPanelHandle, ptrPanelControlParams->MIO_DECORATION_INPUT3, ATTR_LEFT,
					  &ptrPanelControlParams->MIO_DECORATION_INPUT_LEFT);
	GetCtrlAttribute (TabPanelHandle, ptrPanelControlParams->MIO_DECORATION_INPUT3, ATTR_TOP,
					  &ptrPanelControlParams->MIO_DECORATION_INPUT_TOP);
	for(i=0; i<2; i++)
	{
		strcpy(NUMERIC32_LABEL_TITLE[i],MAOInfo[MIO6220DeviceNum2][i].AOChannelName);
	}
	
	LIB_CreateNumericControls1(TabPanelHandle, ptrPanelControlParams->External_Module_Name, "NumericControl3CB", 
						       DYN_NUMERIC32,NUMERICTextTitle21,ptrPanelControlParams->MIO_DECORATION_INPUT_TOP+25,
							   80,100,100,ptrPanelControlParams->MIO_DECORATION_INPUT_LEFT+20,
	                           2,1,NUMERIC32_LABEL_TITLE, VAL_BLACK, 
							   VAL_LT_GRAY, 14, VAL_CENTER_JUSTIFIED, VAL_BLACK, VAL_NORMAL, 10,2, 20, 230);
}
//*******************************************************************************************************************
void Create6220MANUMDIOConfigurationTable(int PanelHandler, struct	MIOMANUALPNLPARAM6220	*ptrPanelControlParams)
{
	int			i, TabPanelHandle;
// -----------------------------------------------------------------------------------------------------------------------	
	//CREATE DECORATION FOR THE INPUT AND OUTPUTS

	GetPanelHandleFromTabPage (PanelHandler, MIOUTL_PNL_MIO_TAB, TAB_PAGE_THREE, &TabPanelHandle);	
	
	ptrPanelControlParams->MIO_DECORATION_INPUT= 
	                       LIB_CreateDecorationControl(TabPanelHandle, 
	                                                    ptrPanelControlParams->External_Module_Name, 
	                                                    25, 310, 30, 505, "DIO INPUTS");
	ptrPanelControlParams->MIO_DECORATION_OUTPUT= 
	                       LIB_CreateDecorationControl(TabPanelHandle, 
	                                                    ptrPanelControlParams->External_Module_Name, 
	                                                    350, 270, 30, 505, "DIO OUTPUTS");


	GetCtrlAttribute (TabPanelHandle, ptrPanelControlParams->MIO_DECORATION_INPUT, ATTR_LEFT,
					  &ptrPanelControlParams->MIO_DECORATION_INPUT_LEFT);
	GetCtrlAttribute (TabPanelHandle, ptrPanelControlParams->MIO_DECORATION_INPUT, ATTR_TOP,
					  &ptrPanelControlParams->MIO_DECORATION_INPUT_TOP);

	GetCtrlAttribute (TabPanelHandle, ptrPanelControlParams->MIO_DECORATION_OUTPUT, ATTR_LEFT,
					  &ptrPanelControlParams->MIO_DECORATION_OUTPUT_LEFT);
	GetCtrlAttribute (TabPanelHandle, ptrPanelControlParams->MIO_DECORATION_OUTPUT, ATTR_TOP,
					  &ptrPanelControlParams->MIO_DECORATION_OUTPUT_TOP);

	LIB_CreateTextMesage(TabPanelHandle, ptrPanelControlParams->External_Module_Name,
	                      ptrPanelControlParams->MIO_DECORATION_INPUT_TOP+20,
	                      ptrPanelControlParams->MIO_DECORATION_INPUT_LEFT+5, 
					      ptrPanelControlParams->Device_Title1, 480, 15,0);
	LIB_CreateTextMesage(TabPanelHandle, ptrPanelControlParams->External_Module_Name, 
	                      ptrPanelControlParams->MIO_DECORATION_OUTPUT_TOP+20, 
	                      ptrPanelControlParams->MIO_DECORATION_OUTPUT_LEFT+5, 
					      ptrPanelControlParams->Device_Title1, 480, 15,0);
	for(i=0; i<16; i++)
	{
		strcpy(ptrPanelControlParams->MIO_LED_LABEL_TITLE[i],DIOInfo[MIO6220DeviceNum1][i].DIOChannelName);
	}
	LIB_CreateLEDControls1(TabPanelHandle, ptrPanelControlParams->External_Module_Name,
	            	       ptrPanelControlParams->MDIO_LEDTextTitle, ptrPanelControlParams->MDIO_LED, 
	            	       ptrPanelControlParams->MIO_DECORATION_INPUT_TOP+40, 20, 30, 
	            	       ptrPanelControlParams->MIO_DECORATION_INPUT_LEFT+5, 16, 
	                       8,ptrPanelControlParams->MIO_LED_LABEL_TITLE,50,
	                       120,170,12,20,8); //
	for(i=16; i<24; i++)
	{
		strcpy(ptrPanelControlParams->MDIO_ButtonTitle[i-16],DIOInfo[MIO6220DeviceNum1][i].DIOChannelName);
	}
	
	LIB_CreateUtilButtonControls1(TabPanelHandle, ptrPanelControlParams->External_Module_Name, 
								  ptrPanelControlParams->CallBackEventHandler,
						          ptrPanelControlParams->MDIO_DYN_BUTTON, ptrPanelControlParams->MDIO_DYN_LED_OUT, 
						          ptrPanelControlParams->MIO_DECORATION_OUTPUT_TOP+50, 20, 30, 20, 
						          130, ptrPanelControlParams->MIO_DECORATION_OUTPUT_LEFT+10,8,
						          ptrPanelControlParams->MDIO_ButtonTitle,8,165,1, 
						          CTRL_SQUARE_COMMAND_BUTTON_LS); 
	                  
}
//*******************************************************************************************************************
void Create6220MANUMDIOConfigurationTable2(int PanelHandler, struct	MIOMANUALPNLPARAM6220	*ptrPanelControlParams)
{
	int			i, TabPanelHandle;
// -----------------------------------------------------------------------------------------------------------------------	
	//CREATE DECORATION FOR THE INPUT AND OUTPUTS

	GetPanelHandleFromTabPage (PanelHandler, MIOUTLPNL2_MIO_TAB2, TAB_PAGE_THREE, &TabPanelHandle);	
	
	ptrPanelControlParams->MIO_DECORATION_INPUT= 
	                       LIB_CreateDecorationControl(TabPanelHandle, 
	                                                    ptrPanelControlParams->External_Module_Name, 
	                                                    25, 310, 30, 505, "DIO INPUTS");
	ptrPanelControlParams->MIO_DECORATION_OUTPUT= 
	                       LIB_CreateDecorationControl(TabPanelHandle, 
	                                                    ptrPanelControlParams->External_Module_Name, 
	                                                    350, 270, 30, 505, "DIO OUTPUTS");


	GetCtrlAttribute (TabPanelHandle, ptrPanelControlParams->MIO_DECORATION_INPUT, ATTR_LEFT,
					  &ptrPanelControlParams->MIO_DECORATION_INPUT_LEFT);
	GetCtrlAttribute (TabPanelHandle, ptrPanelControlParams->MIO_DECORATION_INPUT, ATTR_TOP,
					  &ptrPanelControlParams->MIO_DECORATION_INPUT_TOP);

	GetCtrlAttribute (TabPanelHandle, ptrPanelControlParams->MIO_DECORATION_OUTPUT, ATTR_LEFT,
					  &ptrPanelControlParams->MIO_DECORATION_OUTPUT_LEFT);
	GetCtrlAttribute (TabPanelHandle, ptrPanelControlParams->MIO_DECORATION_OUTPUT, ATTR_TOP,
					  &ptrPanelControlParams->MIO_DECORATION_OUTPUT_TOP);

	LIB_CreateTextMesage(TabPanelHandle, ptrPanelControlParams->External_Module_Name,
	                      ptrPanelControlParams->MIO_DECORATION_INPUT_TOP+20,
	                      ptrPanelControlParams->MIO_DECORATION_INPUT_LEFT+5, 
					      ptrPanelControlParams->Device_Title1, 480, 15,0);
	LIB_CreateTextMesage(TabPanelHandle, ptrPanelControlParams->External_Module_Name, 
	                      ptrPanelControlParams->MIO_DECORATION_OUTPUT_TOP+20, 
	                      ptrPanelControlParams->MIO_DECORATION_OUTPUT_LEFT+5, 
					      ptrPanelControlParams->Device_Title1, 480, 15,0);
	for(i=0; i<16; i++)
	{
		strcpy(ptrPanelControlParams->MIO_LED_LABEL_TITLE[i],DIOInfo[MIO6220DeviceNum2][i].DIOChannelName);
	}
	LIB_CreateLEDControls1(TabPanelHandle, ptrPanelControlParams->External_Module_Name,
	            	       ptrPanelControlParams->MDIO_LEDTextTitle, ptrPanelControlParams->MDIO_LED, 
	            	       ptrPanelControlParams->MIO_DECORATION_INPUT_TOP+40, 20, 30, 
	            	       ptrPanelControlParams->MIO_DECORATION_INPUT_LEFT+5, 16, 
	                       8,ptrPanelControlParams->MIO_LED_LABEL_TITLE,50,
	                       120,170,12,20,8); //
	for(i=16; i<24; i++)
	{
		strcpy(ptrPanelControlParams->MDIO_ButtonTitle[i-16],DIOInfo[MIO6220DeviceNum1][i].DIOChannelName);
	}
	
	LIB_CreateUtilButtonControls1(TabPanelHandle, ptrPanelControlParams->External_Module_Name, 
								  ptrPanelControlParams->CallBackEventHandler,
						          ptrPanelControlParams->MDIO_DYN_BUTTON, ptrPanelControlParams->MDIO_DYN_LED_OUT, 
						          ptrPanelControlParams->MIO_DECORATION_OUTPUT_TOP+50, 20, 30, 20, 
						          130, ptrPanelControlParams->MIO_DECORATION_OUTPUT_LEFT+10,8,
						          ptrPanelControlParams->MDIO_ButtonTitle,8,165,1, 
						          CTRL_SQUARE_COMMAND_BUTTON_LS); 
	                  
}
//*******************************************************************************************************************
int CVICALLBACK NumericControl1CB (int panel, int control, int event,
		            void *callbackData, int eventData1, int eventData2)
{
	#define		TOTALNUMBEROFNUMERIC 10
	int			i;
	switch (event)
		{
		case EVENT_COMMIT:
			break;
		case EVENT_VAL_CHANGED:

			for(i=0;i<TOTALNUMBEROFNUMERIC;i++)
			{
				if(control==DYN_NUMERIC1[i]){ Dyn_Numeric1Handle(i); break;}
				if(control==DYN_NUMERIC21[i]){ Dyn_Numeric21Handle(i); break;} 
			}
			
			break;
		}
	return 0;
}//Numeric Events
//*******************************************************************************************************************
int CVICALLBACK NumericControl2CB (int panel, int control, int event,
		            void *callbackData, int eventData1, int eventData2)
{
	#define		TOTALNUMBEROFNUMERIC 10
	int			i;
	switch (event)
		{
		case EVENT_COMMIT:
			break;
		case EVENT_VAL_CHANGED:

			for(i=0;i<TOTALNUMBEROFNUMERIC;i++)
			{
				if(control==DYN_NUMERIC2[i]){ Dyn_Numeric2Handle(i); break;}
				if(control==DYN_NUMERIC22[i]){ Dyn_Numeric22Handle(i); break;}
			}
			
			break;
		}
	return 0;
}//Numeric Events
//*******************************************************************************************************************
int CVICALLBACK NumericControl3CB (int panel, int control, int event,
		            void *callbackData, int eventData1, int eventData2)
{
	#define		TOTALNUMBEROFNUMERIC 10
	int			i;
	switch (event)
		{
		case EVENT_COMMIT:
			break;
		case EVENT_VAL_CHANGED:

			for(i=0;i<TOTALNUMBEROFNUMERIC;i++)
			{
				if(control==DYN_NUMERIC3[i]){ Dyn_Numeric3Handle(i); break;}
				if(control==DYN_NUMERIC32[i]){ Dyn_Numeric32Handle(i); break;}
			}
			
			break;
		}
	return 0;
}//Numeric Events
//*******************************************************************************************************************
void Dyn_Numeric1Handle(int i)
{
	switch (i)
		{
		case 0:
			MessagePopup ("DYN_NUMERIC1, NUMERIC CB", "NUMERIC 1");
			break;
		case 1:
			MessagePopup ("DYN_NUMERIC1, NUMERIC CB", "NUMERIC 2");  
			break;
		case 2:
			MessagePopup ("DYN_NUMERIC1, NUMERIC CB", "NUMERIC 3");  
			break;
		case 3:
			MessagePopup ("DYN_NUMERIC1, NUMERIC CB", "NUMERIC 4");  
			break;
		case 4:
			MessagePopup ("DYN_NUMERIC1, NUMERIC CB", "NUMERIC 5");  
			break;
		case 5:
			MessagePopup ("DYN_NUMERIC1, NUMERIC CB", "NUMERIC 6");  
			break;
		case 6:
			MessagePopup ("DYN_NUMERIC1, NUMERIC CB", "NUMERIC 7");  
			break;
		case 7:
			MessagePopup ("DYN_NUMERIC1, NUMERIC CB", "NUMERIC 8");  
			break;
		case 8:
			MessagePopup ("DYN_NUMERIC1, NUMERIC CB", "NUMERIC 9");  
			break;
		case 9:
			MessagePopup ("DYN_NUMERIC1, NUMERIC CB", "NUMERIC 10");  
			break;
		default:
			
			break;
		}
}
//*******************************************************************************************************************
void Dyn_Numeric21Handle(int i)
{
	switch (i)
		{
		case 0:
			MessagePopup ("DYN_NUMERIC1, NUMERIC CB", "NUMERIC 1");
			break;
		case 1:
			MessagePopup ("DYN_NUMERIC1, NUMERIC CB", "NUMERIC 2");  
			break;
		case 2:
			MessagePopup ("DYN_NUMERIC1, NUMERIC CB", "NUMERIC 3");  
			break;
		case 3:
			MessagePopup ("DYN_NUMERIC1, NUMERIC CB", "NUMERIC 4");  
			break;
		case 4:
			MessagePopup ("DYN_NUMERIC1, NUMERIC CB", "NUMERIC 5");  
			break;
		case 5:
			MessagePopup ("DYN_NUMERIC1, NUMERIC CB", "NUMERIC 6");  
			break;
		case 6:
			MessagePopup ("DYN_NUMERIC1, NUMERIC CB", "NUMERIC 7");  
			break;
		case 7:
			MessagePopup ("DYN_NUMERIC1, NUMERIC CB", "NUMERIC 8");  
			break;
		case 8:
			MessagePopup ("DYN_NUMERIC1, NUMERIC CB", "NUMERIC 9");  
			break;
		case 9:
			MessagePopup ("DYN_NUMERIC1, NUMERIC CB", "NUMERIC 10");  
			break;
		default:
			
			break;
		}
}
//*******************************************************************************************************************
void Dyn_Numeric2Handle(int i)
{
	switch (i)
		{
		case 0:
			MessagePopup ("DYN_NUMERIC2, NUMERIC CB", "NUMERIC 1");
			break;
		case 1:
			MessagePopup ("DYN_NUMERIC2, NUMERIC CB", "NUMERIC 2");  
			break;
		case 2:
			MessagePopup ("DYN_NUMERIC2, NUMERIC CB", "NUMERIC 3");  
			break;
		case 3:
			MessagePopup ("DYN_NUMERIC2, NUMERIC CB", "NUMERIC 4");  
			break;
		case 4:
			MessagePopup ("DYN_NUMERIC2, NUMERIC CB", "NUMERIC 5");  
			break;
		case 5:
			MessagePopup ("DYN_NUMERIC2, NUMERIC CB", "NUMERIC 6");  
			break;
		case 6:
			MessagePopup ("DYN_NUMERIC2, NUMERIC CB", "NUMERIC 7");  
			break;
		case 7:
			MessagePopup ("DYN_NUMERIC2, NUMERIC CB", "NUMERIC 8");  
			break;
		case 8:
			MessagePopup ("DYN_NUMERIC2, NUMERIC CB", "NUMERIC 9");  
			break;
		case 9:
			MessagePopup ("DYN_NUMERIC2, NUMERIC CB", "NUMERIC 10");  
			break;
		default:
			
			break;
		}
}
//*******************************************************************************************************************
void Dyn_Numeric22Handle(int i)
{
	switch (i)
		{
		case 0:
			MessagePopup ("DYN_NUMERIC2, NUMERIC CB", "NUMERIC 1");
			break;
		case 1:
			MessagePopup ("DYN_NUMERIC2, NUMERIC CB", "NUMERIC 2");  
			break;
		case 2:
			MessagePopup ("DYN_NUMERIC2, NUMERIC CB", "NUMERIC 3");  
			break;
		case 3:
			MessagePopup ("DYN_NUMERIC2, NUMERIC CB", "NUMERIC 4");  
			break;
		case 4:
			MessagePopup ("DYN_NUMERIC2, NUMERIC CB", "NUMERIC 5");  
			break;
		case 5:
			MessagePopup ("DYN_NUMERIC2, NUMERIC CB", "NUMERIC 6");  
			break;
		case 6:
			MessagePopup ("DYN_NUMERIC2, NUMERIC CB", "NUMERIC 7");  
			break;
		case 7:
			MessagePopup ("DYN_NUMERIC2, NUMERIC CB", "NUMERIC 8");  
			break;
		case 8:
			MessagePopup ("DYN_NUMERIC2, NUMERIC CB", "NUMERIC 9");  
			break;
		case 9:
			MessagePopup ("DYN_NUMERIC2, NUMERIC CB", "NUMERIC 10");  
			break;
		default:
			
			break;
		}
}
//*******************************************************************************************************************
void Dyn_Numeric3Handle(int i)
{
	int					TabPanelHandle;
	double				value;
// -----------------------------------------------------------------------------------------------------------------------	
	//CREATE DECORATION FOR THE INPUT AND OUTPUTS

	GetPanelHandleFromTabPage (MIOUtilsPanelHandle, MIOUTL_PNL_MIO_TAB, TAB_PAGE_TWO, &TabPanelHandle);	
	GetCtrlVal(TabPanelHandle, DYN_NUMERIC3[i], &value);
	
	switch (i)
		{
		case 0:
			MAOWriteOutput("AOCH0", value, MIO6220DeviceNum1);
			break;
		case 1:
			MAOWriteOutput("AOCH1", value, MIO6220DeviceNum1);
			break;
		case 2:
			MessagePopup ("DYN_NUMERIC3, NUMERIC CB", "NUMERIC 3");  
			break;
		case 3:
			MessagePopup ("DYN_NUMERIC3, NUMERIC CB", "NUMERIC 4");  
			break;
		case 4:
			MessagePopup ("DYN_NUMERIC3, NUMERIC CB", "NUMERIC 5");  
			break;
		case 5:
			MessagePopup ("DYN_NUMERIC3, NUMERIC CB", "NUMERIC 6");  
			break;
		case 6:
			MessagePopup ("DYN_NUMERIC3, NUMERIC CB", "NUMERIC 7");  
			break;
		case 7:
			MessagePopup ("DYN_NUMERIC3, NUMERIC CB", "NUMERIC 8");  
			break;
		case 8:
			MessagePopup ("DYN_NUMERIC3, NUMERIC CB", "NUMERIC 9");  
			break;
		case 9:
			MessagePopup ("DYN_NUMERIC3, NUMERIC CB", "NUMERIC 10");  
			break;
		default:
			
			break;
		}
}
//*******************************************************************************************************************
void Dyn_Numeric32Handle(int i)
{
	int					TabPanelHandle;
	double				value;
// -----------------------------------------------------------------------------------------------------------------------	
	//CREATE DECORATION FOR THE INPUT AND OUTPUTS

	GetPanelHandleFromTabPage (MIOUtilsPanelHandle2, MIOUTLPNL2_MIO_TAB2, TAB_PAGE_TWO, &TabPanelHandle);	
	GetCtrlVal(TabPanelHandle, DYN_NUMERIC32[i], &value);
	
	switch (i)
		{
		case 0:
			MAOWriteOutput("AOCH0", value, MIO6220DeviceNum2);
			break;
		case 1:
			MAOWriteOutput("AOCH1", value, MIO6220DeviceNum2);
			break;
		case 2:
			MessagePopup ("DYN_NUMERIC3, NUMERIC CB", "NUMERIC 3");  
			break;
		case 3:
			MessagePopup ("DYN_NUMERIC3, NUMERIC CB", "NUMERIC 4");  
			break;
		case 4:
			MessagePopup ("DYN_NUMERIC3, NUMERIC CB", "NUMERIC 5");  
			break;
		case 5:
			MessagePopup ("DYN_NUMERIC3, NUMERIC CB", "NUMERIC 6");  
			break;
		case 6:
			MessagePopup ("DYN_NUMERIC3, NUMERIC CB", "NUMERIC 7");  
			break;
		case 7:
			MessagePopup ("DYN_NUMERIC3, NUMERIC CB", "NUMERIC 8");  
			break;
		case 8:
			MessagePopup ("DYN_NUMERIC3, NUMERIC CB", "NUMERIC 9");  
			break;
		case 9:
			MessagePopup ("DYN_NUMERIC3, NUMERIC CB", "NUMERIC 10");  
			break;
		default:
			
			break;
		}
}
//*******************************************************************************************************************
int CVICALLBACK MDIOOutputsCommandButtonsCB (int panel, int control, int event,
		                          void *callbackData, int eventData1, int eventData2)
		
{
	#define		TOTALNUMBEROFBUTTONS 8
	int			i;
	switch (event)
		{
		case EVENT_COMMIT:
			for(i=0;i<TOTALNUMBEROFBUTTONS;i++)
			{
				if(control==Ptr_MIO6220_MN_PNL_ParametersDIO->MDIO_DYN_BUTTON[i])
				{ 
					Ptr_MIO6220_MN_PNL_ParametersDIO->PortLineOfset=0;
					MDIO_Dyn_OutputsButton1Handle(i, MIO6220DeviceNum1); 
					break;
				}
				if(control==Ptr_MIO6220_MN_PNL_ParametersDIO2->MDIO_DYN_BUTTON[i])
				{ 
					Ptr_MIO6220_MN_PNL_ParametersDIO2->PortLineOfset=0;
					MDIO_Dyn_OutputsButton1Handle(i, MIO6220DeviceNum2); 
					break;
				}
			}
		break;
		}
	return 0;
}//Buttons Event 	
//*******************************************************************************************************************
void MDIO_Dyn_OutputsButton1Handle(int i, int Device)
{

	int				TabPanelHandle;

	
	if(Device==MIO6220DeviceNum1)
	{
		GetPanelHandleFromTabPage (MIOUtilsPanelHandle, MIOUTL_PNL_MIO_TAB, TAB_PAGE_THREE, &TabPanelHandle);
	}
	else if(Device==MIO6220DeviceNum2)
	{
		GetPanelHandleFromTabPage (MIOUtilsPanelHandle2, MIOUTLPNL2_MIO_TAB2, TAB_PAGE_THREE, &TabPanelHandle);
	}
	
	#ifdef USEDATAACQ
		MDIO_Dyn_OutputsButton1Handle_LIB(i, Device, TabPanelHandle);
	#endif	
}
/********************************************************
*
* FUNCTION NAME: MDIOReadInput
* 
* DESCRIPTION: Returns the state of the apropriate input
*              
*
* ARGUMENT LIST: 
* 
* ARGUMENT        TYPE     I/O    DESCRIPTION       
* --------        ----     ---    ----------- 
* DIO_Discription char      I     Label for the input channel
* Device		  int		I	  device number for the DAQ card
*
* RETURNS: state (1 or 0)
* 
*********************************************************/
short MDIOReadInput(char* DIO_Discription, int Device)
{
	short state=0;
	#ifdef USEDATAACQ
	state = MDIOReadInput_LIB(DIO_Discription, Device);
	#endif
	return state;
}
/********************************************************
*
* FUNCTION NAME: MDIOWriteOutput
* 
* DESCRIPTION: Writes the state of the apropriate output driver    
*              
*
* ARGUMENT LIST: 
* 
* ARGUMENT        TYPE     I/O    DESCRIPTION       
* --------        ----     ---    ----------- 
* DIO_Discription char      I     Label for the input channel
* state           int       I     state to be written
* Device		  int		I	  device number for the DAQ card
*
* RETURNS: GLB_FALSE for failure
*          GLB_TRUE for success
* 
*********************************************************/
int MDIOWriteOutput(char* DIO_Discription, int state, int Device)
{
	int  returnVal = GLB_FALSE;

	#ifdef USEDATAACQ
	returnVal = MDIOWriteOutput_LIB(DIO_Discription, state, Device);
	
	#endif
	return returnVal;
}
//*******************************************************************************************************************
// Update Manual Input / Output
// Inputs: 
//        Type: 	Input Or Output
//		  Control:	Pointer to the Specific Controls
//        Device:	Which Device (Device Number)
// Output:
//    	  None
//*******************************************************************************************************************
void MIOUpdateManualIO(int Type, int Control[], int Device)
{
	short 			i, PortValue;
	
	for(i=0;i<TOTAL_NUMBER_OF_PORTS_6220;i++)
	{
		if(Type)
		{
			if((i==0) || (i==1))
			{
				PortValue=Input_Port_Val_MIO[i];  // Current Input Port Value
				UpdateMIOPort(i, PortValue, Control, Type, Device); /// Update the Controls with Current Status 
			}
		}
		else 
		{
			PortValue=Output_Port_Val_MIO[i]; // Current Output Port Value 

		}

	}
}
//*******************************************************************************************************************

int CVICALLBACK MDIOInsertRow2CB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			break;
		case EVENT_KEYPRESS:

			break;
	}
	return 0;
}
//*******************************************************************************************************************

int CVICALLBACK MIODeleteRow2CB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			break;
		case EVENT_KEYPRESS:

			break;
	}
	return 0;
}
//*******************************************************************************************************************

int CVICALLBACK MAOInsertRow2CB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			break;
		case EVENT_KEYPRESS:

			break;
	}
	return 0;
}
//*******************************************************************************************************************

int CVICALLBACK MAODeleteRow2CB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			break;
		case EVENT_KEYPRESS:

			break;
	}
	return 0;
}
//*******************************************************************************************************************

int CVICALLBACK MAIInsertRow2CB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			break;
		case EVENT_KEYPRESS:

			break;
	}
	return 0;
}
//*******************************************************************************************************************

int CVICALLBACK MAIDeleteRow2CB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			break;
		case EVENT_KEYPRESS:

			break;
	}
	return 0;
}
//*******************************************************************************************************************

int CVICALLBACK EnablDisableReadDIOTimer2CB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int ONOFF;
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal(panel, control, &ONOFF );
			if(ONOFF)
			{
				 SetCtrlAttribute (MIOUtilsPanelHandle2, MIOUTLPNL2_READIOTIMER2, ATTR_ENABLED, 1);
			}
			else
			{
				 SetCtrlAttribute (MIOUtilsPanelHandle2, MIOUTLPNL2_READIOTIMER2, ATTR_ENABLED, 0);
			}
			
			break;
		case EVENT_VAL_CHANGED:

			break;
		case EVENT_KEYPRESS:

			break;
	}
	return 0;
}
//*******************************************************************************************************************

int CVICALLBACK ReadDIOTimer2CB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
    #ifdef USEDATAACQ

	switch (event)
	{
		case EVENT_TIMER_TICK:
			ReadDIOTimer2CB_LIB();
			break;
	}
	#endif 
	return 0;
}
//*******************************************************************************************************************

int CVICALLBACK EnablDisableReadAITimer2CB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int ONOFF;
	
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal(panel, control, &ONOFF );
			if(ONOFF)
			{
				 SetCtrlAttribute (MIOUtilsPanelHandle2, MIOUTLPNL2_READAITIMER2, ATTR_ENABLED, 1);
			}
			else
			{
				 SetCtrlAttribute (MIOUtilsPanelHandle2, MIOUTLPNL2_READAITIMER2, ATTR_ENABLED, 0);
			}

			break;
		case EVENT_VAL_CHANGED:

			break;
		case EVENT_KEYPRESS:

			break;
	}
	return 0;
}
//*******************************************************************************************************************

int CVICALLBACK ReadDAITimer2CB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int TabPanelHandle;
	
	switch (event)
	{
		case EVENT_TIMER_TICK:
			GetPanelHandleFromTabPage (MIOUtilsPanelHandle2, MIOUTLPNL2_MIO_TAB2, TAB_PAGE_ONE, &TabPanelHandle);	
			ReadDAITimer2CB_LIB(TabPanelHandle);			
			break;
	}
	return 0;
}
//*******************************************************************************************************************

int CVICALLBACK MIOUtilsExit2CB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
						
						#if USE_EXT_MAIN_PROJ
							CheckError(HidePanel(MIOUtilsPanelHandle2)); 
						#else		
							QuitUserInterface (0);
						#endif
						
			break;
	}
	return 0;
}

