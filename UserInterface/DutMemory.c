
//==============================================================================
//
// Title:		DutMemory.c
// Purpose:		A short description of the implementation.
//
// Created on:	19/09/2013 at 2:38:33 PM by test.
// Copyright:	. All Rights Reserved.
//
//==============================================================================
/*!
*    @file    DutMemory.c
*    @brief   Diagnostic utility for reading and writing to EEPROM memory
*    @author  Arxtron Technologies Inc.
*    @date    2013.10.01
*    Functions to read and write to EEPROM memory 
*/ 


//--------------------------------------------------------------
#include "nblib.h"
#include "nb_test.h"
#include "nb_functions.h"

typedef enum{GLB_FALSE, GLB_TRUE}bool;   
#include "teststeps.h"
#include "worker.h"
#include "timeutils.h"

//Alv_NarrowBand_Sensor	NarrowBand_Sensor[];  
extern void returnNarrowBand_SensorHandle(int testUnit, Alv_NarrowBand_Sensor **Sensor);


//-------------------------------------------------------------


#include <utility.h>
#include <ansi_c.h>
#include <formatio.h>
#include <userint.h>
#include "DutMemory.h"
#include "DutMemory_Def.h"
#include "CANDrv.h"
#include "CANCommand.h"
#include "Measurements.h"
#include "app_log.h"
#include "DIO6515UtilsDef.h"



static int SensorAddress = 1;
static int testUnit;
static int numberFormat;

/********************************************//**
*  Test Unit Callback        
***********************************************/
int CVICALLBACK TestUnitCB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			// Diconnect all units and clear listbox
			ResetAllTestUnits();
			break;
	}
	return 0;
} // end TestUnitCB


/********************************************//**
*  Connect Unit Callback      
***********************************************/
int  CVICALLBACK ConnectUnitCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlVal(panel,MEM_PNL_TESTUNIT_RING,&testUnit);  
			if (getDutPresence(testUnit) && getDutPosition(testUnit))
			{
				SetCtrlAttribute(panel,control,ATTR_DIMMED,1);
				setSelectValve(testUnit, 1);
				setDutPower(testUnit,1);

				InitCanInterfaceDbg(testUnit);
				Sensor_Comm_InitDbg(testUnit);
				Get_Test_InstrumentDbg(testUnit);
				Init_Tx_CalDbg(testUnit);
				PingDutDbg(testUnit);

				SetCtrlAttribute(panel,MEM_PNL_DISCONNECTUNITBUTTON,ATTR_DIMMED,0); 
				SetCtrlAttribute(panel,MEM_PNL_SENDCOMMANDBUTTON,ATTR_DIMMED,0);
				SetCtrlAttribute(panel,MEM_PNL_VIEMINFOBUTTON,ATTR_DIMMED,0); 
				//SetCtrlAttribute(panel,MEM_PNL_VIEMMEMORYBUTTON,ATTR_DIMMED,0); 
				//SetCtrlAttribute(panel,MEM_PNL_DUMPEEPROMBUTTON,ATTR_DIMMED,0); 
				SetCtrlAttribute(panel,MEM_PNL_WRITEMEMORYBUTTON,ATTR_DIMMED,0); 
				SetCtrlAttribute(panel,MEM_PNL_READMEMORYBUTTON,ATTR_DIMMED,0);
				
				//SetCtrlAttribute(panel,MEM_PNL_BROWSEBUTTON,ATTR_DIMMED,0); 
				//SetCtrlAttribute(panel,MEM_PNL_LOADEEPROMBUTTON,ATTR_DIMMED,0);
				SetCtrlAttribute(panel,MEM_PNL_TESTUNIT_RING,ATTR_DIMMED,1);
			}
			else
			{
				MessagePopup("Connect Unit Error","Test unit is not presence or in position");
			}
			break;
	}
	return 0;
} // end ConnectUnitCB

/********************************************//**
*  Disconnect Unit Callback        
***********************************************/
int CVICALLBACK DisconnectUnitCB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			SetCtrlAttribute(panel,control,ATTR_DIMMED,1);   
			GetCtrlVal(panel,MEM_PNL_TESTUNIT_RING,&testUnit);  

			
			
			UnlockTestInstrument(testUnit);	// Should be released in sequence, but
			UnlockOtherNest(testUnit);		// Release again in case we aborted

			DisconnectTXCal (testUnit) ;  
			DisconnectCan (testUnit) ;

			setSelectValve(testUnit,0);
			//setDutPower(testUnit,0);


			ClearListCtrl(panel,MEM_PNL_CAL_MEM_LISTBOX); 
			SetCtrlAttribute(panel,MEM_PNL_CONNECTUNITBUTTON,ATTR_DIMMED,0);  
			SetCtrlAttribute(panel,MEM_PNL_SENDCOMMANDBUTTON,ATTR_DIMMED,1);
			SetCtrlAttribute(panel,MEM_PNL_VIEMINFOBUTTON,ATTR_DIMMED,1); 
			//SetCtrlAttribute(panel,MEM_PNL_VIEMMEMORYBUTTON,ATTR_DIMMED,1); 
			//SetCtrlAttribute(panel,MEM_PNL_DUMPEEPROMBUTTON,ATTR_DIMMED,1); 
			SetCtrlAttribute(panel,MEM_PNL_WRITEMEMORYBUTTON,ATTR_DIMMED,1); 
			SetCtrlAttribute(panel,MEM_PNL_READMEMORYBUTTON,ATTR_DIMMED,1);
			//SetCtrlAttribute(panel,MEM_PNL_BROWSEBUTTON,ATTR_DIMMED,1); 
			//SetCtrlAttribute(panel,MEM_PNL_LOADEEPROMBUTTON,ATTR_DIMMED,1);
			SetCtrlAttribute(panel,MEM_PNL_TESTUNIT_RING,ATTR_DIMMED,0); 
			break;
	}
	return 0;
}  // end DisconnectUnitCB


/********************************************//**
*  Read EEPROM memory Callback        
***********************************************/
int CVICALLBACK ReadMemoryCB (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int error = 0;
	char readAddressStr[10];
	char readValueStr[10];
	int readAddressDec;
	int readValueDec;
	Alv_NarrowBand_Sensor Sensor;
	
	char * pvalue;
	int	   ret_val = 0;

	switch (event)
	{
		case EVENT_COMMIT:
			SetCtrlAttribute(panel,control,ATTR_DIMMED,1); 
			ProcessDrawEvents();  
			error |= GetCtrlVal(panel,MEM_PNL_TESTUNIT_RING,&testUnit);
			error |= GetCtrlVal(panel,MEM_PNL_FORMAT_RING,&numberFormat);
			error |= GetCtrlVal(panel,MEM_PNL_READADDRESS_STRING,readAddressStr);

			if (numberFormat == 0)		// input value is decimal format
			{
				readAddressDec = atoi(readAddressStr);    
			}
			else   // input value is hex format
			{
				readAddressDec = ConvertHexStrToInteger(readAddressStr);
			}


			returnNarrowBand_SensorHandle(testUnit, &Sensor);
			Read_Point(Sensor, readAddressDec , &pvalue, &ret_val);
		
			
			// update GUI
			if (error)
			{
				MessagePopup("Error","Unable to read memory address.");
			}
			else
			{
				if (numberFormat == 0)		// input value is decimal format
				{
					sprintf(readValueStr,"%s",pvalue);       
				}
				else   // input value is hex format
				{
					readValueDec = atoi(pvalue);
					ConvertIntegerToHexStr(readValueDec,readValueStr);
				}
				SetCtrlVal(panel,MEM_PNL_READVALUE_STRING,readValueStr);
			}
			SetCtrlAttribute(panel,control,ATTR_DIMMED,0); 
			break;
	}
	return 0;
}  // end ReadMemoryCB 


/********************************************//**
*  Write to EEPROM memory Callback        
***********************************************/
int CVICALLBACK WriteMemoryCB (int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int error = 0;
	char writeAddressStr[10];
	char writeValueStr[10];
	int writeAddressDec;
	int writeValueDec;
	char swriteValueDec[32];

	Alv_NarrowBand_Sensor Sensor;
	char * pvalue;
	int	   ret_val = 0;

	
	switch (event)
	{
		case EVENT_COMMIT:
			SetCtrlAttribute(panel,control,ATTR_DIMMED,1); 
			ProcessDrawEvents();  
			error |= GetCtrlVal(panel,MEM_PNL_TESTUNIT_RING,&testUnit);
			error |= GetCtrlVal(panel,MEM_PNL_FORMAT_RING,&numberFormat);
			error |= GetCtrlVal(panel,MEM_PNL_WRITEADDRESS_STRING,writeAddressStr);
			error |= GetCtrlVal(panel,MEM_PNL_WRITEVALUE_STRING,writeValueStr); 

			if (numberFormat == 0)	// input value is decimal format
			{
				writeAddressDec = atoi(writeAddressStr);   
				writeValueDec = atoi(writeValueStr);
			}
			else   // input value is hex format
			{
				writeAddressDec = ConvertHexStrToInteger(writeAddressStr);
				writeValueDec = ConvertHexStrToInteger(writeValueStr);
				sprintf(writeAddressStr, "%d", writeAddressDec);
				sprintf(writeValueStr, "%d", writeValueDec);
			}

			
			returnNarrowBand_SensorHandle(testUnit, &Sensor);
			write_to_point(Sensor, writeAddressDec, writeValueStr, &ret_val);


			if (error)
			{
				MessagePopup("Error","Unable to write memory address.");
			}
			SetCtrlAttribute(panel,control,ATTR_DIMMED,0); 
			break;
	}
	return 0;
} // end WriteMemoryCB

/********************************************//**
*  Dump EEPROM memory to a file Callback        
***********************************************/
int CVICALLBACK DumpE2PCB (int panel, int control, int event,void *callbackData, int eventData1, int eventData2)
{
	int error = 0;
	int E2P_size = 1024;
	int arrayE2P[E2P_size];
	char fileName[256];
	
	switch (event)
	{
		case EVENT_COMMIT:
			SetCtrlAttribute(panel,control,ATTR_DIMMED,1); 
			ProcessDrawEvents();
			error |= GetCtrlVal(panel,MEM_PNL_TESTUNIT_RING,&testUnit);
			//error |= GetCtrlVal(panel,MEM_PNL_FILENAME_STRING,fileName);
		
			error |= ReadEEPROM_c6(SensorAddress,arrayE2P,testUnit);
			
			if (error)
			{
				MessagePopup("Error","Unable to read memory.");
			}
			else
			{
				FILE *fp;
				fp = fopen(fileName,"w");
				if (fp == NULL)
				{
					MessagePopup("Error","Could not open and write to file.");
					error = 1;
				}
				else
				{   // format based on Lowell etf file format
					fprintf(fp,"Loc;Description;;;Value;\n");
					for (int i=0; i<E2P_size; i++)
					{
						fprintf(fp,"%d;;;%d;\n",i, arrayE2P[i]);   
					} 
					fclose(fp);
				}
			} // end if
			SetCtrlAttribute(panel,control,ATTR_DIMMED,0); 
			break;
	}
	return 0;
} // end DumpE2PCB

/********************************************//**
*  Send a CAN command Callback        
***********************************************/
int  CVICALLBACK SendCommand(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int error = 0;
	int msgSendIx;
	char msgSendLabel[80];
	char msgInputStr[80];
	int msgInputValue;

	char msg[80];
	
	// Send CAN command and read return buffer
	switch (event)
	{
		case EVENT_COMMIT: 
			// Get send command input
			error |= GetCtrlVal(panel,MEM_PNL_TESTUNIT_RING,&testUnit); 
			GetCtrlIndex(panel,MEM_PNL_MESSAGE_LIBRARY,&msgSendIx);
			GetLabelFromIndex(panel,MEM_PNL_MESSAGE_LIBRARY,msgSendIx,msgSendLabel);
			GetCtrlVal(panel,MEM_PNL_CAN_MESSAGE,msgInputStr);  
#if 1
			if(strstr(msgSendLabel,"SendTxBand0HiFreq") != NULL)
			{
				error |= SendTxBand(28000, TX_BAND_0, testUnit);
			}
			else if(strstr(msgSendLabel,"SendTxBand1HiFreq") != NULL)
			{
				error |= SendTxBand(28000, TX_BAND_1, testUnit);
			}
			else if(strstr(msgSendLabel,"SendTxBand0LowFreq") != NULL)
			{
				error |= SendTxBand(20000, TX_BAND_0, testUnit);
			}
			else if(strstr(msgSendLabel,"SendTxBand1LowFreq") != NULL)
			{
				error |= SendTxBand(20000, TX_BAND_1, testUnit);
			}
			if(strstr(msgSendLabel,"SendTxUwbDac") != NULL)
			{
				msgInputValue = atoi(msgInputStr);
				error |= SendTxUwbDac(msgInputValue,testUnit);
			}
			if(strstr(msgSendLabel,"SendTx1OnTx2Off") != NULL)
			{
				msgInputValue = atoi(msgInputStr);
				error |= SendTxAnt(24000, INNER_ANTENNA,testUnit);
			}
			if(strstr(msgSendLabel,"SendTx1OffTx2On") != NULL)
			{
				msgInputValue = atoi(msgInputStr);
				error |= SendTxAnt(24000, OUTER_ANTENNA,testUnit);
			}
			if(strstr(msgSendLabel,"SendTx1OffTx2Off") != NULL)
			{
				msgInputValue = atoi(msgInputStr);
				error |= SendTxAnt(24000, TRANSMITTER_DISABLED,testUnit);
			}
			if(strstr(msgSendLabel,"SendReset") != NULL)
			{
				error |= SendReset(testUnit);
			}
			if(strstr(msgSendLabel,"SendClearFaults") != NULL)
			{
				error |= SendClearFaults(testUnit);
			}
			if(strstr(msgSendLabel,"SendIsmPowerCommand") != NULL)
			{
				msgInputValue = atoi(msgInputStr);
				error |= SendIsmPowerCommand(msgInputValue,testUnit);
			}
			if(strstr(msgSendLabel,"SendIsmPulsingCommand") != NULL)
			{
				error |= SendIsmPulsingCommand(testUnit);
			}
			if(strstr(msgSendLabel,"SendIsmNonPulsingCommand") != NULL)
			{
				error |= SendIsmNonPulsingCommand(testUnit);
			}
			if(strstr(msgSendLabel,"SendDisableIsmFmCommand") != NULL)
			{
				error |= SendDisableIsmFmCommand(testUnit);
			}
			if(strstr(msgSendLabel,"SendTxPulseRestoreCommand") != NULL)
			{
				error |= SendTxPulseRestoreCommand(testUnit);
			}
			else
			{
				// do nothing
			}
#endif			
			break;
	}
	return 0;
} // end SendCommand

/********************************************//**
*  Populate CAN Message Library Callback        
***********************************************/
int  CVICALLBACK Populate_Send_Command(int panel, int control, int event, void *callbackData, int eventData1, int eventData2)
{
	int itemIx;
	char itemLabel[80];
	switch (event)
	{
		case EVENT_COMMIT:
			GetCtrlIndex(panel,control,&itemIx);
			GetLabelFromIndex(panel,control,itemIx,itemLabel);
			//SetCtrlVal(panel,MEM_PNL_CAN_MESSAGE,itemLabel);
			break;
	}
	return 0;
} // end Populate_Send_Command

/********************************************//**
*  View DUT information Callback        
***********************************************/
int CVICALLBACK ViewInfoCB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	char item[80], MIS[23]={0}, swVer[25]={0};
	int error = 0, temperature = 999;  
	int E2P_size = 1024, arrayE2P[E2P_size];
	
	int calMemoryAddress[]={77,80,81,82,83,84,85,86,177,178};
	int calMemorySize = sizeof(calMemoryAddress)/sizeof(calMemoryAddress[0]);
	int addrIx;
	double tval;
	
	
	switch (event)
	{
		case EVENT_COMMIT:
			SetCtrlAttribute(panel,control,ATTR_DIMMED,1);
			ProcessDrawEvents();  
			error |= GetCtrlVal(panel,MEM_PNL_TESTUNIT_RING,&testUnit);
			
			error |= GetMISnumber_c6(SensorAddress,testUnit,MIS); 
			error |= GetFirmwareVersion(testUnit,swVer);
			error |= GetSensorTemperature(testUnit,&temperature);  
				
			ClearListCtrl(panel,MEM_PNL_CAL_MEM_LISTBOX);
			sprintf(item,"MIS=%s",MIS);
			error |= InsertListItem(panel,MEM_PNL_CAL_MEM_LISTBOX,-1,item,0); 
			sprintf(item,"Firmware=%s",swVer);
			error |= InsertListItem(panel,MEM_PNL_CAL_MEM_LISTBOX,-1,item,0);
			sprintf(item,"Temperature[Celsius]=%i",temperature);
			error |= InsertListItem(panel,MEM_PNL_CAL_MEM_LISTBOX,-1,item,0);
			error |= InsertListItem(panel,MEM_PNL_CAL_MEM_LISTBOX,-1," ",0);
			
			tval=Timer();
			error |= ReadEEPROM_c6(SensorAddress,arrayE2P,testUnit); 
			tval = Timer() - tval;

			/*  This just seems like it should be faster, but for some reason it is slower!
			tval=Timer();
			for(int i = 0; i < calMemorySize; i++)
				addrIx = GetEEPROMValue(calMemoryAddress[i],testUnit);
			tval = Timer() - tval;
			*/
			
			if (!error)
			{
				sprintf(item,"\033p60c%s \033p120c%s \033p180c%s","Address","Value(Dec)","Value(Hex)");
				InsertListItem(panel,MEM_PNL_CAL_MEM_LISTBOX,-1,item,0); 
				for (int i=0; i<calMemorySize; i++)
				{
					addrIx = calMemoryAddress[i];
					sprintf(item,"\033p60r%i \033p120r%i \033p180r%04X",addrIx,arrayE2P[addrIx], arrayE2P[addrIx]); 
					InsertListItem(panel,MEM_PNL_CAL_MEM_LISTBOX,-1,item,0); 
				} // end for loop 
			} 
			else
				MessagePopup("Error","Unable to display all test unit information.");
				
			
			SetCtrlAttribute(panel,control,ATTR_DIMMED,0); 
			break;
	}
	return 0;
} // end ViewInfoCB


/********************************************//**
*  Exit DutMemory Callback        
***********************************************/
int CVICALLBACK ExitCB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			MainTestingIsPause = 0;
			ResetAllTestUnits();   
			HidePanel (panel); 
			//NonBlockDelay(2);
			break;
	}
	
	return 0;
} // end ExitCB

/********************************************//**
*  Convert a Hex string to Integer        
***********************************************/
int ConvertHexStrToInteger(char hexStr[10])
{
	int value;
	Scan(hexStr,"%s>%x",&value);
	return(value);
} // end ConvertHexStrToInteger

/********************************************//**
*  Convert an Integer to Hex string      
***********************************************/
void ConvertIntegerToHexStr(int value, char hexStr[10])
{
	sprintf(hexStr,"%04X",value);	
} // end ConvertIntegerToHexStr


/********************************************//**
*  Load CAN message library from a config file        
***********************************************/
int LoadMessageLibrary(char *filename)
{
	int error;
	//char filename[120];
	char line[120];
	char msg[256];
	
	//sprintf(filename,"C:\\temp\\CAN_MessageLibrary.txt");
	
	FILE *fp;
	fp = fopen(filename,"r");
	if (fp == NULL)
	{
		sprintf(msg,"Unable to open file %s.",filename);
		MessagePopup("Error",msg);	
	}
	else
	{
		ClearListCtrl(DutMemoryPanelHandle,MEM_PNL_MESSAGE_LIBRARY);   
		while(fscanf(fp,"%s",line)!=EOF)
		{
			InsertListItem(DutMemoryPanelHandle,MEM_PNL_MESSAGE_LIBRARY,-1,line,0);
		}
		error = 0;
	}
	fclose(fp);
	ResetAllTestUnits();
	MainTestingIsPause = 1;
	DisplayPanel(DutMemoryPanelHandle);
	return(error);
} // end LoadMessageLibrary


/********************************************//**
*  Reset all test units       
***********************************************/
void ResetAllTestUnits(void)
{
	// Disconnect all test units and clear list box
	int numTestUnits=0;
	GetNumListItems(DutMemoryPanelHandle,MEM_PNL_TESTUNIT_RING,&numTestUnits);
	for(int i=0; i<numTestUnits; i++)
	{
		setDutPower(i,0);
		setSelectValve(i,0);
	
	}
	ClearListCtrl(DutMemoryPanelHandle,MEM_PNL_CAL_MEM_LISTBOX);     
	SetCtrlAttribute(DutMemoryPanelHandle,MEM_PNL_CONNECTUNITBUTTON,ATTR_DIMMED,0);   
	SetCtrlAttribute(DutMemoryPanelHandle,MEM_PNL_DISCONNECTUNITBUTTON,ATTR_DIMMED,1);
	SetCtrlAttribute(DutMemoryPanelHandle,MEM_PNL_SENDCOMMANDBUTTON,ATTR_DIMMED,1);
	SetCtrlAttribute(DutMemoryPanelHandle,MEM_PNL_VIEMINFOBUTTON,ATTR_DIMMED,1); 
	//SetCtrlAttribute(DutMemoryPanelHandle,MEM_PNL_VIEMMEMORYBUTTON,ATTR_DIMMED,1); 
	//SetCtrlAttribute(DutMemoryPanelHandle,MEM_PNL_DUMPEEPROMBUTTON,ATTR_DIMMED,1); 
	SetCtrlAttribute(DutMemoryPanelHandle,MEM_PNL_WRITEMEMORYBUTTON,ATTR_DIMMED,1); 
	SetCtrlAttribute(DutMemoryPanelHandle,MEM_PNL_READMEMORYBUTTON,ATTR_DIMMED,1); 
	//SetCtrlAttribute(DutMemoryPanelHandle,MEM_PNL_BROWSEBUTTON,ATTR_DIMMED,1); 
	//SetCtrlAttribute(DutMemoryPanelHandle,MEM_PNL_LOADEEPROMBUTTON,ATTR_DIMMED,1);
} // end ResetAllTestUnits

/********************************************//**
*  Browse for to select a load EEPROM file      
***********************************************/
int CVICALLBACK BrowseCB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	char E2PFileName[MAX_PATHNAME_LEN];
	int iFileStatus;
	switch (event)
	{
		case EVENT_COMMIT:
			// can not use FileSelectPopupEx due to multithreading
			iFileStatus = FileSelectPopup("C:\\tmp\\","*.etf","*.etf;*.*","Select an EEPROM file",VAL_SELECT_BUTTON,0,0,0,0,E2PFileName);  
			if (iFileStatus == 1)
			{
				//SetCtrlVal(panel,MEM_PNL_E2P_FILENAME_STRING,E2PFileName);
			}
			break;
	}
	return 0;
} // end BrowseCB


/********************************************//**
*  Load EEPROM from a selected file      
***********************************************/
int CVICALLBACK LoadE2PCB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	char E2PFileName[MAX_PATHNAME_LEN], msg[120];
	FILE *fp;
	
	if(event != EVENT_COMMIT)
		return(0);
	
	SetCtrlAttribute(panel,control,ATTR_DIMMED,1); 
	ProcessDrawEvents();  
	//GetCtrlVal(panel,MEM_PNL_E2P_FILENAME_STRING,E2PFileName);
			
	fp = fopen(E2PFileName,"r");
	if (fp == NULL)
	{
		sprintf(msg,"Unable to open file %s.",E2PFileName);
		MessagePopup("Error",msg);	
	}
	else
	{
		int E2P_SIZE = 1024, E2P_Location[E2P_SIZE], E2P_Values[E2P_SIZE], E2P_Count;
		int calMemoryAddress[11]={77,80,81,82,83,84,85,86,177,178, -1};
		int calMemoryValues[11] ={-1,-1,-1,-1,-1,-1,-1,-1, -1, -1, -1};
		int resp, error = 0;
		char line[600];
		
		// read EEPROM file:  format as used in Lowell is addr;Desc1;Desc2;value 
		for(E2P_Count=0; fscanf(fp, "%[^\n] ",line)!=EOF; E2P_Count++)
		{
			char *line_ptr, desc[600];

			sscanf(line, "%d", &E2P_Location[E2P_Count]);   // read field 
			line_ptr=1+strchr(line, ';');					// find field 2
			sscanf(line_ptr, "%[^;]", desc);				// read field
			line_ptr=1+strchr(line_ptr, ';');				// find field 3
			sscanf(line_ptr, "%[^;]", desc); 				// read field 
			line_ptr=1+strchr(line_ptr, ';');				// find field 4
			sscanf(line_ptr, "%d", &E2P_Values[E2P_Count]); // read field 
		}
		fclose(fp);
		
		GetCtrlVal(panel,MEM_PNL_TESTUNIT_RING,&testUnit); 
		sprintf(msg, "Found %d address/value pairs.\nUsually memory is %d bytes.\n", E2P_Count, E2P_SIZE);
		resp = GenericMessagePopup ("EEProm Load", msg, "Load all", "Load only Tx Cal values", "Cancel", 0, 0, 0, VAL_GENERIC_POPUP_BTN2, VAL_GENERIC_POPUP_BTN2, VAL_GENERIC_POPUP_BTN3);
			
		if(resp ==  1 && E2P_Count == E2P_SIZE)  	// write whole EEPROM 
		{
			error |= WriteEEPROM_c6(SensorAddress,0,E2P_Count-1,E2P_Values,testUnit);   // This may or may not be better than FastWriteEEPROM_c6...

		}
		if(resp ==  1 && E2P_Count != E2P_SIZE)   // Use a different method if we don't have all the locations & values
		{
			for(int i = 0; i < E2P_Count; i++)
				error |= FastWriteEEPROM_c6(SensorAddress,E2P_Location[i],E2P_Values[i],testUnit);
		}
		
		if(resp == 2) // Only Use Tx Cal Values
		{
			for(int i=0; i < E2P_Count; i++)
				for(int j=0; calMemoryAddress[j] != -1; j++)	  
					if(E2P_Location[i] == calMemoryAddress[j])
						calMemoryValues[j] = E2P_Values[i];
			
			for(int j=0; calMemoryAddress[j] != -1; j++)
				if(calMemoryValues[j] == -1)
					error=1;
				
			if(error)
				MessagePopup("Error", "Didn't find all the Tx Cal values");
			else
				for(int i = 0; i < calMemoryAddress[i] != -1; i++)
					error |= FastWriteEEPROM_c6(SensorAddress,calMemoryAddress[i],calMemoryValues[i],testUnit);
				
		}
		// if(resp == 3) // Don't do anything.
		
		if (error == 0)
			MessagePopup("Load EEPROM","Load EEPROM file successfully.");
		else
			MessagePopup("Error","Unable to load EEPROM file.");
	}
	SetCtrlAttribute(panel,control,ATTR_DIMMED,0); 
	return 0;
} // end LoadE2PCB



int CVICALLBACK FormatCtrlCB (int panel, int control, int event,
							  void *callbackData, int eventData1, int eventData2)
{
	static int curselection = DEC;
 	int selctedformat;
	int error = 0;
	char readAddressStr[10];
	char readValueStr[10];
	char writeAddressStr[10];
	char writeValueStr[10];
	int readAddressDec;
	int readValueDec;
	int writeAddressDec;
	int writeValueDec;

	
	switch (event)
	{
		case EVENT_COMMIT:

			break;
			
		case EVENT_VAL_CHANGED:
			
			GetCtrlVal(panel,control, &selctedformat);
			if(selctedformat == DEC)
			{	// Conver to decimal
				curselection = selctedformat;
				
				//AddressDec = ConvertHexStrToInteger(AddressStr);
				//sprintf(ValueStr,"%s",pvalue);       

				error |= GetCtrlVal(panel,MEM_PNL_READADDRESS_STRING,readAddressStr);
				error |= GetCtrlVal(panel,MEM_PNL_READVALUE_STRING,readValueStr);
				readAddressDec = ConvertHexStrToInteger(readAddressStr);
				readValueDec = ConvertHexStrToInteger(readValueStr);
				sprintf(readAddressStr,"%d",readAddressDec);
				sprintf(readValueStr,"%d",readValueDec);

				error |= GetCtrlVal(panel,MEM_PNL_WRITEADDRESS_STRING,writeAddressStr);
				error |= GetCtrlVal(panel,MEM_PNL_WRITEVALUE_STRING,writeValueStr);
				writeAddressDec = ConvertHexStrToInteger(writeAddressStr);
				writeValueDec = ConvertHexStrToInteger(writeValueStr);
				sprintf(writeAddressStr,"%d",writeAddressDec);
				sprintf(writeValueStr,"%d",writeValueDec);

				
				if(error)
				{
					
					MessagePopup("Error","Unable to read point id or point value.");
					
				}
				else
				{
					
					error |= SetCtrlVal(panel,MEM_PNL_READADDRESS_STRING,readAddressStr);
					error |= SetCtrlVal(panel,MEM_PNL_READVALUE_STRING,readValueStr);
					
					
					error |= SetCtrlVal(panel,MEM_PNL_WRITEADDRESS_STRING,writeAddressStr);
					error |= SetCtrlVal(panel,MEM_PNL_WRITEVALUE_STRING,writeValueStr);

				}

				
			}
			else if(selctedformat == HEX)
			{   // Conver to hex
				curselection = selctedformat;

				error |= GetCtrlVal(panel,MEM_PNL_READADDRESS_STRING,readAddressStr);
				error |= GetCtrlVal(panel,MEM_PNL_READVALUE_STRING,readValueStr);
				readAddressDec = atoi(readAddressStr);    
				readValueDec = atoi(readValueStr);    

				error |= GetCtrlVal(panel,MEM_PNL_WRITEADDRESS_STRING,writeAddressStr);
				error |= GetCtrlVal(panel,MEM_PNL_WRITEVALUE_STRING,writeValueStr);
				writeAddressDec = atoi(writeAddressStr);    
				writeValueDec = atoi(writeValueStr);    

				
				if (error)
				{
					MessagePopup("Error","Unable to read point id or point value.");
				}
				else
				{

					ConvertIntegerToHexStr(readAddressDec,readAddressStr);
					ConvertIntegerToHexStr(readValueDec,readValueStr);
					SetCtrlVal(panel,MEM_PNL_READADDRESS_STRING,readAddressStr);
					SetCtrlVal(panel,MEM_PNL_READVALUE_STRING,readValueStr);

					ConvertIntegerToHexStr(writeAddressDec,writeAddressStr);
					ConvertIntegerToHexStr(writeValueDec,writeValueStr);
					SetCtrlVal(panel,MEM_PNL_WRITEADDRESS_STRING,writeAddressStr);
					SetCtrlVal(panel,MEM_PNL_WRITEVALUE_STRING,writeValueStr);

				}

			}
			
			break;
			
		case EVENT_RIGHT_CLICK:

			break;
	}
	return 0;
}

