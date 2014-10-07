/***********************************************************************
 *
 *
 *  COPYRIGHT: Arxtron Technologies Inc. All Rights Reserved.
 *
 *  PURPOSE: - Digital IO 6515 driver utitility   
 *
 *  DEVELOPMENT HISTORY:
 *
 *  Date        Name           Rev.   Description
 *  ----------  -------------  -----  -----------------------
 *  07-29-2013  Arxtron        1      Initial Release
 *  
 *  
 *********************************************************************/ 
/*!
*    @file    DIO6515Utils.c
*    @brief    Digital IO 6515 driver utitility  .
*    @author  Arxtron Technologies Inc.
*    @date    2013.9.6
*    Driver utility for Digital IO 6515. 
*/
#include <cvirte.h>		
#include <userint.h>
#include "Global.h"
#include "DataLib.h"  
#include "DIO6515Utils.h"
#include "DIO6515UtilsDef.h"
#include "frmMain.h"

#include "timeUtils.h"

#define	USEDATAACQ  /// Enable / Disable DAQ Functionality
#ifdef USEDATAACQ
#endif
//*******************************************************************************************************************
#define DAQmxErrChk(functionCall) if( DAQmxFailed(error=(functionCall)) ) goto Error; else
//*******************************************************************************************************************
#if USE_EXT_MAIN_PROJ 		/// Should be Set 1 if Module is Part of the Main Project and Set 0 if Stand Alone

#else 

extern int rejectBinLed;

/********************************************//**
*  DIO 6515 main utility      
***********************************************/
//int main (int argc, char *argv[])
//{
//	char					dir[MAX_PATHNAME_LEN], uirPath[MAX_PATHNAME_LEN]; //dbPath[MAX_PATHNAME_LEN], SQLString[1000], strSeparator[10] = ", ";
//	CVIXMLElement rootElement;
//	char DIO6515DeviceNum1Str[100];
//	
//	if (InitCVIRTE (0, argv, 0) == 0)
//		return -1;	/* out of memory */
//	if ((DIO6515UtilsPanelHandle = LoadPanel (0, "DIO6515Utils.uir", DIO6515PNL)) < 0)
//		return -1;
//	DisplayPanel (DIO6515UtilsPanelHandle);
//
//	GetProjectDir(dir);
//	
//	sprintf(uirPath, "%s%s", dir,"\\Configuration\\gMiscellaneous.xml");
//	rootElement = LoadConfigurationDocument(uirPath);
//	ParseXMLDocument(rootElement, 0);
//
//	strcpy(DIO6515DeviceNum1Str, GetCfgMiscValue("DIO6515DeviceNum1",80));
//	Scan (DIO6515DeviceNum1Str, "%s>%d", &DIO6515DeviceNum1);
//	
//	sprintf(uirPath, "%s%s", dir,"\\Configuration\\DIO6515Definition.xml");		 ///Retrieve the DIO Definition Configuration from an XML File
//	rootElement = LoadConfigurationDocument(uirPath);
//	ParseXMLDocument(rootElement, 7);
//	
//	#ifdef USEDATAACQ 
//		InitDIOInterface6515(DIO6515DeviceNum1);		// DIO Interface Initialization 0 for First Device 1, 2, 3... for more DIO Devices
//	#endif
//	
//	
//		
//	DisplayMANUALConfiguration6515();
//	RunUserInterface ();
//	DiscardPanel (DIO6515UtilsPanelHandle);
//	return 0;
//}
#endif


/********************************************//**
*  DIO 6515 main utility exit Callback   
***********************************************/
int CVICALLBACK DIO6515UtilsExitCB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
						
						//#if USE_EXT_MAIN_PROJ
							CheckError(HidePanel(DIO6515UtilsPanelHandle)); 
					//	#else		
						//	QuitUserInterface (0);
						//#endif
						SetCtrlAttribute (MainPanelHandle, Main_START_TIMER, ATTR_ENABLED, 1); 
			//QuitUserInterface (0);
			break;
		case EVENT_KEYPRESS:

			break;
	}
	return 0;
}


/********************************************//**
*  DIO 6515 write utitlity    
***********************************************/
int CVICALLBACK DIO6515UtilsWriteButtonCB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
/*	short readReturnVal, tempWriteReturnVal;
	bool writeReturnVal;
	int Multiplier;
	char temprReadReturnStr[100];
	
	switch (event)
	{
		case EVENT_COMMIT:
			
			 GetCtrlVal(panel, DIO6515_OUTPUT_STRING, outputDescription);
			 GetCtrlVal(panel, DIO6515_OUTPUT_NUMERIC, &outputState);
			 GetCtrlVal(panel, DIO6515_OUTPUT_NUMERIC_PORT, &outputPort);
			 GetCtrlVal(panel, DIO6515_INPUT_NUMERIC_PORT, &inputPort);
			 GetCtrlVal(panel, DIO6515_INPUT_STRING, InputDescription);
			 writeReturnVal = WriteOutput(outputDescription, outputState);
			 GetCtrlVal(panel, DIO6515_INPUT_NUMERIC_BIT, &inputBit);
			 GetCtrlVal(panel, DIO6515_OUTPUT_NUMERIC_BIT, &outputBit);
			 readReturnVal = ReadInput(InputDescription);
			 sprintf(temprReadReturnStr, "%d",readReturnVal);
			 ///MessagePopup("Value Read",temprReadReturnStr); 
			 Multiplier=(1<<inputBit);
			 ///readReturnVal = 1;
			 ///writeReturnVal = GLB_TRUE;
			 readReturnVal *= Multiplier;
			 if(writeReturnVal && outputState == 1)
			 {
				 tempWriteReturnVal = 0;
			 }
			 else if(writeReturnVal && outputState == 0)
			 {
				 tempWriteReturnVal = 1;
			 }
			 else
			 {
				tempWriteReturnVal = 0;	 
			 }
			 Multiplier=(1<<outputBit);
			 tempWriteReturnVal *= Multiplier;
			 
			 if(strcmp(InputDescription, ""))
			 {
			 	 /// Port, Read Value, Control, Type, Device
				 UpdateIOPort(inputPort, readReturnVal, Ptr_DIO_MN_PNL_Parameters->DIO_LED, 1, 1);
			 }
			 if(strcmp(outputDescription, ""))
			 {
			 	 /// Port, Write Value, Control, Type, Device
				 UpdateIOPort(outputPort, tempWriteReturnVal, Ptr_DIO_MN_PNL_Parameters->DIO_DYN_LED_OUT, 0, 1);
			 }


			break;
		case EVENT_KEYPRESS:

			break;
	}
*/
	return 0;
}

/********************************************//**
*  DIO 6515 Read IO Timer utility   
***********************************************/
int CVICALLBACK Read6515IOTimerCB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int					TabPanelHandle, TabPanelHandle1;
	
    #ifdef USEDATAACQ

	switch (event)
	{
		case EVENT_TIMER_TICK:
			// TODO troubleshoot io flashing
			 GetPanelHandleFromTabPage (DIO6515UtilsPanelHandle, DIO6515PNL_DIO6515_TAB, TAB_PAGE_ONE, &TabPanelHandle);
			 ReadIO6515TimerCB_LIB(TabPanelHandle, DIO6515DeviceNum1);
			 GetPanelHandleFromTabPage (DIO6515UtilsPanelHandle, DIO6515PNL_DIO6515_TAB, TAB_PAGE_TWO, &TabPanelHandle1);
			 ReadIO6515TimerCB_LIB(TabPanelHandle1, DIO6515DeviceNum2);
			break;
	}
	#endif 
	return 0;
}
/********************************************//**
*  DIO 6515 Display the hardware control panel       
***********************************************/
void DisplayMANUAL6515Utils(void)
{

	First_Manual_Pnl=1;   ///
	if(First_Manual_Pnl)
	{
		Ptr_DIO6515_MN_PNL_Parameters=&DIO6515_MN_PNL_Parameters;
		Ptr_DIO6515_MN_PNL_Parameters2=&DIO6515_MN_PNL_Parameters2;

		Ptr_DIO6515_MN_PNL_Parameters->NumberofDevices=2;                            
		strcpy(Ptr_DIO6515_MN_PNL_Parameters->External_Module_Name,"DIO6515Utils.C");                  
		strcpy(Ptr_DIO6515_MN_PNL_Parameters2->External_Module_Name,"DIO6515Utils.C");
		strcpy(Ptr_DIO6515_MN_PNL_Parameters->Device_Title1,"DEVICE 1");
		strcpy(Ptr_DIO6515_MN_PNL_Parameters2->Device_Title2,"DEVICE 2");                         
		strcpy(Ptr_DIO6515_MN_PNL_Parameters->CallBackEventHandler,"DIO6515OutputsCommandButtonsCB");                  
		strcpy(Ptr_DIO6515_MN_PNL_Parameters2->CallBackEventHandler,"DIO6515OutputsCommandButtons2CB");
	
		InitMANUALTable6515(DIO6515UtilsPanelHandle, Ptr_DIO6515_MN_PNL_Parameters);
		InitMANUALTable26515(DIO6515UtilsPanelHandle, Ptr_DIO6515_MN_PNL_Parameters2);
	
		DisplayPanel(DIO6515UtilsPanelHandle);
	
	}
}
//*******************************************************************************************************************
void InitMANUALTable6515(int PanelHandler, struct MANUALPNLPARAM6515	*ptrPanelControlParams)
{
	CreateMANUALConfigurationTable6515(PanelHandler, ptrPanelControlParams);
}
//*******************************************************************************************************************
void InitMANUALTable26515(int PanelHandler, struct MANUALPNLPARAM6515	*ptrPanelControlParams)
{
	CreateMANUALConfigurationTable26515(PanelHandler, ptrPanelControlParams);
}


/********************************************//**
*  DIO 6515 create table to be displayed on hardware control panel       
***********************************************/
void CreateMANUALConfigurationTable26515(int PanelHandler, struct	MANUALPNLPARAM6515	*ptrPanelControlParams)
{
	int			i, TabPanelHandle;
// -----------------------------------------------------------------------------------------------------------------------	
	//CREATE DECORATION FOR THE INPUT AND OUTPUTS
	
	GetPanelHandleFromTabPage (PanelHandler, DIO6515PNL_DIO6515_TAB, TAB_PAGE_TWO, &TabPanelHandle);	
	
	ptrPanelControlParams->DIO6515_DECORATION_INPUT2= 
	                       LIB_CreateDecorationControl(TabPanelHandle, 
	                                                    ptrPanelControlParams->External_Module_Name, 
	                                                    25, 310, 30, 681, "DIO INPUTS");
	ptrPanelControlParams->DIO6515_DECORATION_OUTPUT2= 
	                       LIB_CreateDecorationControl(TabPanelHandle, 
	                                                    ptrPanelControlParams->External_Module_Name, 
	                                                    350, 270, 30, 681, "DIO OUTPUTS");
									   
	GetCtrlAttribute (TabPanelHandle, ptrPanelControlParams->DIO6515_DECORATION_INPUT2, ATTR_LEFT,
					  &ptrPanelControlParams->DIO6515_DECORATION_INPUT_LEFT);
	GetCtrlAttribute (TabPanelHandle, ptrPanelControlParams->DIO6515_DECORATION_INPUT2, ATTR_TOP,
					  &ptrPanelControlParams->DIO6515_DECORATION_INPUT_TOP);

	GetCtrlAttribute (TabPanelHandle, ptrPanelControlParams->DIO6515_DECORATION_OUTPUT2, ATTR_LEFT,
					  &ptrPanelControlParams->DIO6515_DECORATION_OUTPUT_LEFT);
	GetCtrlAttribute (TabPanelHandle, ptrPanelControlParams->DIO6515_DECORATION_OUTPUT2, ATTR_TOP,
					  &ptrPanelControlParams->DIO6515_DECORATION_OUTPUT_TOP);

	LIB_CreateTextMesage(TabPanelHandle, ptrPanelControlParams->External_Module_Name,
	                      ptrPanelControlParams->DIO6515_DECORATION_INPUT_TOP+20,
	                      ptrPanelControlParams->DIO6515_DECORATION_INPUT_LEFT+5, 
					      ptrPanelControlParams->Device_Title1, 675, 15,0);
	LIB_CreateTextMesage(TabPanelHandle, ptrPanelControlParams->External_Module_Name, 
	                      ptrPanelControlParams->DIO6515_DECORATION_OUTPUT_TOP+20, 
	                      ptrPanelControlParams->DIO6515_DECORATION_OUTPUT_LEFT+5, 
					      ptrPanelControlParams->Device_Title1, 675, 15,0);
	for(i=0; i<TOTAL_INPUT_DIO6515_LINE; i++)
	{
		strcpy(ptrPanelControlParams->DIO6515_LED_LABEL_TITLE[i],DIOInfo[DIO6515DeviceNum2][i].DIOChannelName);
	}
	LIB_CreateLEDControls1(TabPanelHandle, ptrPanelControlParams->External_Module_Name,
	            	       ptrPanelControlParams->DIO6515_LEDTextTitle, ptrPanelControlParams->DIO6515_LED, 
	            	       ptrPanelControlParams->DIO6515_DECORATION_INPUT_TOP+40, 20, 30, 
	            	       ptrPanelControlParams->DIO6515_DECORATION_INPUT_LEFT+5, 32, 
	                       8,ptrPanelControlParams->DIO6515_LED_LABEL_TITLE,50,
	                       120,170,12,20,8); //
	for(i=TOTAL_INPUT_DIO6515_LINE; i<TOTAL_IO_DIO6515_ROWS; i++)
	{
		strcpy(ptrPanelControlParams->DIO6515_ButtonTitle[i-TOTAL_INPUT_DIO6515_LINE],DIOInfo[DIO6515DeviceNum2][i].DIOChannelName);
	}
	
	LIB_CreateUtilButtonControls1(TabPanelHandle, ptrPanelControlParams->External_Module_Name, 
								  ptrPanelControlParams->CallBackEventHandler,
						          ptrPanelControlParams->DIO6515_DYN_BUTTON, ptrPanelControlParams->DIO6515_DYN_LED_OUT, 
						          ptrPanelControlParams->DIO6515_DECORATION_OUTPUT_TOP+50, 20, 30, 20, 
						          130, ptrPanelControlParams->DIO6515_DECORATION_OUTPUT_LEFT+10,32,
						          ptrPanelControlParams->DIO6515_ButtonTitle,8,165,1, 
						          CTRL_SQUARE_COMMAND_BUTTON_LS); 
	for(i=TOTAL_INPUT_DIO6515_LINE; i<TOTAL_IO_DIO6515_ROWS; i++)
	{		
		SetCtrlAttribute(TabPanelHandle,ptrPanelControlParams->DIO6515_DYN_BUTTON[i-TOTAL_INPUT_DIO6515_LINE],ATTR_CALLBACK_FUNCTION_POINTER,DIO6515OutputsCommandButtons2CB);
	}
	                  
}


/********************************************//**
*  DIO 6515 create table to be displayed on hardware control panel       
***********************************************/
void CreateMANUALConfigurationTable6515(int PanelHandler, struct	MANUALPNLPARAM6515	*ptrPanelControlParams)
{
	int			i, TabPanelHandle;
// -----------------------------------------------------------------------------------------------------------------------	
	//CREATE DECORATION FOR THE INPUT AND OUTPUTS

	GetPanelHandleFromTabPage (PanelHandler, DIO6515PNL_DIO6515_TAB, TAB_PAGE_ONE, &TabPanelHandle);	
	
	ptrPanelControlParams->DIO6515_DECORATION_INPUT= 
	                       LIB_CreateDecorationControl(TabPanelHandle, 
	                                                    ptrPanelControlParams->External_Module_Name, 
	                                                    25, 310, 30, 681, "DIO INPUTS");
	ptrPanelControlParams->DIO6515_DECORATION_OUTPUT= 
	                       LIB_CreateDecorationControl(TabPanelHandle, 
	                                                    ptrPanelControlParams->External_Module_Name, 
	                                                    350, 270, 30, 681, "DIO OUTPUTS");


	GetCtrlAttribute (TabPanelHandle, ptrPanelControlParams->DIO6515_DECORATION_INPUT, ATTR_LEFT,
					  &ptrPanelControlParams->DIO6515_DECORATION_INPUT_LEFT);
	GetCtrlAttribute (TabPanelHandle, ptrPanelControlParams->DIO6515_DECORATION_INPUT, ATTR_TOP,
					  &ptrPanelControlParams->DIO6515_DECORATION_INPUT_TOP);

	GetCtrlAttribute (TabPanelHandle, ptrPanelControlParams->DIO6515_DECORATION_OUTPUT, ATTR_LEFT,
					  &ptrPanelControlParams->DIO6515_DECORATION_OUTPUT_LEFT);
	GetCtrlAttribute (TabPanelHandle, ptrPanelControlParams->DIO6515_DECORATION_OUTPUT, ATTR_TOP,
					  &ptrPanelControlParams->DIO6515_DECORATION_OUTPUT_TOP);

	LIB_CreateTextMesage(TabPanelHandle, ptrPanelControlParams->External_Module_Name,
	                      ptrPanelControlParams->DIO6515_DECORATION_INPUT_TOP+20,
	                      ptrPanelControlParams->DIO6515_DECORATION_INPUT_LEFT+5, 
					      ptrPanelControlParams->Device_Title1, 675, 15,0);
	LIB_CreateTextMesage(TabPanelHandle, ptrPanelControlParams->External_Module_Name, 
	                      ptrPanelControlParams->DIO6515_DECORATION_OUTPUT_TOP+20, 
	                      ptrPanelControlParams->DIO6515_DECORATION_OUTPUT_LEFT+5, 
					      ptrPanelControlParams->Device_Title1, 675, 15,0);
	for(i=0; i<TOTAL_INPUT_DIO6515_LINE; i++)
	{
		strcpy(ptrPanelControlParams->DIO6515_LED_LABEL_TITLE[i],DIOInfo[DIO6515DeviceNum1][i].DIOChannelName);
	}
	LIB_CreateLEDControls1(TabPanelHandle, ptrPanelControlParams->External_Module_Name,
	            	       ptrPanelControlParams->DIO6515_LEDTextTitle, ptrPanelControlParams->DIO6515_LED, 
	            	       ptrPanelControlParams->DIO6515_DECORATION_INPUT_TOP+40, 20, 30, 
	            	       ptrPanelControlParams->DIO6515_DECORATION_INPUT_LEFT+5, 32, 
	                       8,ptrPanelControlParams->DIO6515_LED_LABEL_TITLE,50,
	                       120,170,12,20,8); //
	for(i=TOTAL_INPUT_DIO6515_LINE; i<TOTAL_IO_DIO6515_ROWS; i++)
	{
		strcpy(ptrPanelControlParams->DIO6515_ButtonTitle[i-TOTAL_INPUT_DIO6515_LINE],DIOInfo[DIO6515DeviceNum1][i].DIOChannelName);
	}
	
	LIB_CreateUtilButtonControls1(TabPanelHandle, ptrPanelControlParams->External_Module_Name, 
								  ptrPanelControlParams->CallBackEventHandler,
						          ptrPanelControlParams->DIO6515_DYN_BUTTON, ptrPanelControlParams->DIO6515_DYN_LED_OUT, 
						          ptrPanelControlParams->DIO6515_DECORATION_OUTPUT_TOP+50, 20, 30, 20, 
						          130, ptrPanelControlParams->DIO6515_DECORATION_OUTPUT_LEFT+10,32,
						          ptrPanelControlParams->DIO6515_ButtonTitle,8,165,1, 
						          CTRL_SQUARE_COMMAND_BUTTON_LS); 
	                  
	for(i=TOTAL_INPUT_DIO6515_LINE; i<TOTAL_IO_DIO6515_ROWS; i++)
	{		
		SetCtrlAttribute(TabPanelHandle,ptrPanelControlParams->DIO6515_DYN_BUTTON[i-TOTAL_INPUT_DIO6515_LINE],ATTR_CALLBACK_FUNCTION_POINTER,DIO6515OutputsCommandButtonsCB);
	}
}

/********************************************//**
*  DIO 6515 output command callback     
***********************************************/
int CVICALLBACK DIO6515OutputsCommandButtonsCB (int panel, int control, int event,
		                          void *callbackData, int eventData1, int eventData2)
		
{
	#define		TOTALNUMBEROFBUTTONS 32
	int			i;
	switch (event)
		{
		case EVENT_COMMIT:
			for(i=0;i<TOTALNUMBEROFBUTTONS;i++)
			{
				if(control==Ptr_DIO6515_MN_PNL_Parameters->DIO6515_DYN_BUTTON[i])
				{ 
					Ptr_DIO6515_MN_PNL_Parameters->PortLineOfset=0;
					DIO6515_Dyn_OutputsButton1Handle(i, DIO6515DeviceNum1); 
					break;
				}
			}
		break;
		}
	return 0;
}//Buttons Event 	


/********************************************//**
*  DIO 6515 output command callback 2   
***********************************************/
int CVICALLBACK DIO6515OutputsCommandButtons2CB (int panel, int control, int event,
		                          void *callbackData, int eventData1, int eventData2)
		
{
	#define		TOTALNUMBEROFBUTTONS 32
	int			i;
	switch (event)
		{
		case EVENT_COMMIT:
			for(i=0;i<TOTALNUMBEROFBUTTONS;i++)
			{
				if(control==Ptr_DIO6515_MN_PNL_Parameters2->DIO6515_DYN_BUTTON[i])
				{ 
					Ptr_DIO6515_MN_PNL_Parameters2->PortLineOfset=0;
					DIO6515_Dyn_OutputsButton2Handle(i, DIO6515DeviceNum2); 
					break;
				}
			}
		break;
		}
	return 0;
}//Buttons Event 	

/********************************************//**
*  DIO 6515 output button handle      
***********************************************/
void DIO6515_Dyn_OutputsButton1Handle(int i, int Device)
{

	#ifdef USEDATAACQ		
		DIO6515_Dyn_OutputsButton1Handle_LIB(i, Device);
	#endif	
}

/********************************************//**
*  DIO 6515 output button handle 2     
***********************************************/
void DIO6515_Dyn_OutputsButton2Handle(int i, int Device)
{

	#ifdef USEDATAACQ		
		DIO6515_Dyn_OutputsButton2Handle_LIB(i, Device);
	#endif	
}


/********************************************//**
*  Returns the state of the apropriate input      
***********************************************/
short ReadInput6515(char* DIO_Discription, int Device)
{
	short state=0;
	#ifdef USEDATAACQ
		state = ReadInput6515_LIB(DIO_Discription, Device);
	#endif
	return state;
}

/********************************************//**
*  Writes the state of the apropriate output driver          
***********************************************/
int WriteOutput6515(char* DIO_Discription, int state, int Device)
{
	int returnValue=0;
	#ifdef USEDATAACQ
		returnValue = WriteOutput6515_LIB(DIO_Discription, state, Device);
	#endif
	return returnValue;
}


/********************************************//**
*  DIO 6515 Enable Disable Read Timer          
***********************************************/
int CVICALLBACK EnablDisableRead6515IOTimerCB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int ONOFF;
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal(panel, control, &ONOFF );
			if(ONOFF)
			{
				 SetCtrlAttribute (DIO6515UtilsPanelHandle, DIO6515PNL_READIOTIMER, ATTR_ENABLED, 1);
			}
			else
			{
				 SetCtrlAttribute (DIO6515UtilsPanelHandle, DIO6515PNL_READIOTIMER, ATTR_ENABLED, 0);
			}
				

			break;
		case EVENT_VAL_CHANGED:

			break;
		case EVENT_KEYPRESS:

			break;
	}
	return 0;
}
///************************************************************************************************************

/********************************************//**
*  get the status of the dut presence sensor         
***********************************************/
int getDutPresence(int dutNumber)
{
	int status;
	char tmpStr[80];
	sprintf(tmpStr,"DUT%i_PRESENCE",dutNumber+1);
	status = ReadInput6515(tmpStr,DIO6515DeviceNum1);
	SetCtrlVal(MainPanelHandle, gPresenceLed[dutNumber],status); 
	if (status)
	{
		SetCtrlVal(MainPanelHandle,gPositionLed[dutNumber],getDutPosition(dutNumber));
	}
	else
	{
		SetCtrlVal(MainPanelHandle,gPositionLed[dutNumber],0); 
	}
	return(status);
} // end getDutPresence

/********************************************//**
*  get the status of the dut position sensor         
***********************************************/
int getDutPosition(int dutNumber)
{
	int status;
	char tmpStr[80];
	sprintf(tmpStr,"DUT%i_POSITION",dutNumber+1);
	status = ReadInput6515(tmpStr,DIO6515DeviceNum1);
	return(status);
} // end getDutPosition

/********************************************//**
*  get the status of the reject button        
***********************************************/
int getDutRejectButton(int dutNumber)
{
	int status;
	char tmpStr[80];
	sprintf(tmpStr,"DUT%i_REJECT",dutNumber+1);
	status = ReadInput6515(tmpStr,DIO6515DeviceNum1);
	return(status);
}

/********************************************//**
*  get the status of the fail chute sensor       
***********************************************/
int getFailChute(void)
{
	int status;
	status = ReadInput6515("FAIL_CHUTE",DIO6515DeviceNum1); 
	return(status);
}  // end getFailChute

/********************************************//**
*  get the status of the estop button      
***********************************************/
int getE_Stop(void)
{
	int status;
	status = ReadInput6515("E-STOP",DIO6515DeviceNum1); 
	return(status);
} // end getE_Stop

/********************************************//**
*  Turn on or off dut power    
***********************************************/
void setDutPower(int dutNumber,int bState)
{
	char tmpStr[80];
	sprintf(tmpStr,"DUT%i_BATT",dutNumber+1);
	WriteOutput6515(tmpStr, bState, DIO6515DeviceNum1);
	if(bState)
	{
		NonBlockDelay(2.5);
	}
} // end setPower


/********************************************//**
*  set RF switch to perform measure of select dutNumber   
***********************************************/
int setTestInstrumentPath(int dutNumber)
{
	int error = 0;
	switch(dutNumber)
	{
		case 0:
			WriteOutput6515("DUT1_2_RF_SWITCH", 0, DIO6515DeviceNum1);  
			break;
		case 1:
			WriteOutput6515("DUT1_2_RF_SWITCH", 1, DIO6515DeviceNum1); 
			break;
		case 2:
			WriteOutput6515("DUT3_4_RF_SWITCH", 0, DIO6515DeviceNum1);   
			break;
		case 3:
			WriteOutput6515("DUT3_4_RF_SWITCH", 1, DIO6515DeviceNum1);   
			break;
		case 4:
			WriteOutput6515("DUT5_6_RF_SWITCH", 0, DIO6515DeviceNum1);   
			break;
		case 5:
			WriteOutput6515("DUT5_6_RF_SWITCH", 1, DIO6515DeviceNum1);   
			break;
		default:
			error = -1;
			break;

	} // end switch
	return(error);
} // end setTestInstrumentPath 

/********************************************//**
*  set Fail LED Fail indicator 
***********************************************/
void setLedFail(int dutNumber,int bState)
{
	char tmpStr[80];
	sprintf(tmpStr,"LED%i_FAIL",dutNumber+1);
	WriteOutput6515(tmpStr, bState, DIO6515DeviceNum1); 
} // end setLedFail

/********************************************//**
*  set Busy LED indicator
***********************************************/
void setLedBusy(int dutNumber,int bState)
{
	char tmpStr[80];
	sprintf(tmpStr,"LED%i_BUSY",dutNumber+1);
	WriteOutput6515(tmpStr, bState, DIO6515DeviceNum1); 
} // end setLedBusy

/********************************************//**
*  set Good LED indicator   
***********************************************/
void setLedGood(int dutNumber,int bState)
{
	char tmpStr[80];
	sprintf(tmpStr,"LED%i_GOOD",dutNumber+1);
	WriteOutput6515(tmpStr, bState, DIO6515DeviceNum1); 
} // end setLedGood


/********************************************//**
*  Set test station control power
*  Need to power this control at startup   
***********************************************/
void setCtrlPower24VDC(int bState)
{
	// Turn Dump Valve off before turn off power
	if (bState == 0)
	{
		setCtrlDumpValve(0);
	}
	WriteOutput6515("CTRL_POWER_24V", bState, DIO6515DeviceNum1); 
} // end setCtrlPower24VDC



/********************************************//**
*  set valve to secure DUT   
***********************************************/
void setSelectValve(int dutNumber,int bState)
{   
	char tmpStr[80];
	sprintf(tmpStr,"DUT%i_VALVE",dutNumber+1);  

	WriteOutput6515(tmpStr, bState, DIO6515DeviceNum2);
	
	if (bState)
		NonBlockDelay(1);
} // end setSelectValve          


/********************************************//**
*  set control dump valve   
***********************************************/
void setCtrlDumpValve(int bState)
{
	WriteOutput6515("CTRL_DUMP_VALVE", bState, DIO6515DeviceNum2); 
} // end setCtrlDumpValve

/********************************************//**
* Clear all LED of a selected nest number
***********************************************/
int getFailChuteIsFull(void)
{
	int failChuteIsFull;
	GetCtrlVal(MainPanelHandle,rejectBinLed,&failChuteIsFull);
	return(failChuteIsFull);
} // end getFailChuteIsFull

/********************************************//**
*  get the status of the fail chute sensor       
***********************************************/
int getFailChute2(void)
{
	int status;
	status = ReadInput6515("FAIL_CHUTE2",DIO6515DeviceNum1);
	return(status);
}  // end getFailChute2


/********************************************//**
* Update Fail Chute LED when fail chute is full
***********************************************/
void updateFailChuteIsFullStatus(void)
{
	int status;
	status = getFailChute();
	NonBlockDelay(0.01); 
	if ((status==TRUE) && (failChuteLastStatus==TRUE))
	{
		// set Fail Chute LED if two consecutive check is true
		SetCtrlVal(MainPanelHandle,rejectBinLed,status);
	}
	else
	{
		SetCtrlVal(MainPanelHandle,rejectBinLed,FALSE);
	}
	failChuteLastStatus = status;
} // end updateFailChuteIsFullStatus

/********************************************//**
*  determine fixture id
***********************************************/
int getFixtureId(void)
{
	int autofile = 0;
	char FxtId[100];
	for (int i=0; i<2; i++)
	{
		sprintf(FxtId,"%s%d","FixID_",i);
		autofile |= ReadInput6515(FxtId, DIO6515DeviceNum1) << i;	
	}
	return autofile;	

}  

/********************************************//**
*  determine fixture id
***********************************************/
int getFxtLock(void)
{
	int data = 0;
	char FxtId[100];
	for (int i=1; i<5; i++)
	{
		sprintf(FxtId,"%s%d","Fxt_Lock_",i);
		data |= ReadInput6515(FxtId, DIO6515DeviceNum1) << i-1;	
	}
	return data;	

}  

/********************************************//**
*  return product type associated with fixture
***********************************************/

char * getFixtureName(int Id)//, char * Name)
{
	switch(Id)
	{
		case 1:
			return "nonGM"; 
			break;
		case 2:
			return "GM"; 
			break;
		default:
			return "Unknown";
			break;
	} // end switch	
	return "Unknown Fixture";
}

/********************************************//**
*  get the status of vaccum sensor         
***********************************************/
/* Air Pressure Sensor */  
int getVacSensor(void)
{
	int status;
	status = ReadInput6515("PSI_Sense",DIO6515DeviceNum1); 
	return(status);
} // end getVacSensor
