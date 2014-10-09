/***********************************************************************
 *
 *
 *  COPYRIGHT: Arxtron Technologies Inc. All Rights Reserved.
 *
 *  PURPOSE: - Digital IO 6515 library   
 *
 *  DEVELOPMENT HISTORY:
 *
 *  Date        Name           Rev.   Description
 *  ----------  -------------  -----  -----------------------
 *  07-29-2013  Arxtron        1      Initial Release
 *  
 *  
 *********************************************************************/ 

/*---------------------------------------------------------------------------*/   
/* Include files                                                             */   
/*---------------------------------------------------------------------------*/   
#include <cvirte.h>    
#include <userint.h>   
#include <ansi_c.h>    

#include <userint.h>
#include "Global.h"
#include "cvi_db.h"
#include "DataLib.h" 
#include <rs232.h>
#include <formatio.h>
#include "DIO6515UtilsLIBDef.h"

#define	USEDATAACQ  /// Enable / Disable DAQ Functionality
#ifdef USEDATAACQ
#endif
//*******************************************************************************************************************
#define DAQmxErrChk(functionCall) if( DAQmxFailed(error=(functionCall)) ) goto Error; else
//*******************************************************************************************************************

/********************************************************************************/
/* DIODLL Functions Implemantation                                              */
/********************************************************************************/
//*******************************************************************************************************************
int __stdcall ReadIO6515TimerCB_LIB (int TabPanelHandle, int Device)
{
	int					i, Port, Line, Temp, Multiplier=0;
	int32       		error=0;
	///uInt32      		numChannels;
	///uInt32      		Ch;
	char        		errBuff[2048]={'\0'};
	uInt8       		data_0[100];
	int32				read_0, bytesPerSamp;
    #ifdef USEDATAACQ

	 for(i=0;i<TOTAL_NUMBER_OF_PORTS;i++)
	 {
	 	Input_Port_Val_DIO6515[i]=0;
	 	Output_Port_Val_DIO6515[i]=0;
	 }
	 for(i=0;i<TOTAL_NUMBER_OF_INPUT_PORTS_6515;i++)
	 {
	 	///#ifdef USEDATAACQ
	 	///#if !DEBUG
	  		if(i<4) 
	  		{
	  			//Device=DIO6515DeviceNum1; 
				Port=i;
				for(Line=0;Line<8;Line++)
				{
					DAQmxErrChk (DAQmxReadDigitalLines(DIOInfo[Device][Line+(Port*8)].taskHandle,
						         1,10.0,DAQmx_Val_GroupByChannel,data_0,100,&read_0,&bytesPerSamp,NULL));
					Multiplier=(1<<Line);
					Input_Port_Val_DIO6515[i]=Input_Port_Val_DIO6515[i]+(data_0[0]*(Multiplier));
				}
	  		}									  
	  		else
	  		{
	  			//Device=DIO6515DeviceNum2;
				Port=i-4;
				for(Line=0;Line<8;Line++)
				{
					///***
					DAQmxErrChk (DAQmxReadDigitalLines(DIOInfo[Device][Line+(Port*8)].taskHandle,
						         1,10.0,DAQmx_Val_GroupByChannel,data_0,100,&read_0,&bytesPerSamp,NULL));
					Multiplier=(1<<Line);
					Input_Port_Val_DIO6515[i]=Input_Port_Val_DIO6515[i]+(data_0[0]*(Multiplier));
					///***/
				}
	  		}
	  		///DIG_In_Port(Device, Port, &Input_Port_Val_DIO6515[i]);
	  	///#endif
	  	///#endif
	 }
  	 UpdateManualIO6515_LIB(1, Ptr_DIO6515_MN_PNL_Parameters->DIO6515_LED, Device,TabPanelHandle);
	 
	 for(i=0;i<TOTAL_NUMBER_OF_OUTPUT_PORTS_6515;i++)
	 {
	 	///#ifdef USEDATAACQ
	 	///if !DEBUG
	  		if(i<4)
	  		{
	  			//Device=DIO6515DeviceNum1; 
				Port=i+4;
				for(Line=0;Line<8;Line++)
				{
					DAQmxErrChk (DAQmxReadDigitalLines(DIOInfo[Device][Line+(Port*8)].taskHandle,
						         1,10.0,DAQmx_Val_GroupByChannel,data_0,100,&read_0,&bytesPerSamp,NULL));
					Multiplier=(1<<Line);
					Output_Port_Val_DIO6515[i]=Output_Port_Val_DIO6515[i]+(data_0[0]*(Multiplier));
				}
	  		}
	  		else
	  		{
	  			//Device=DIO6515DeviceNum1;
				Port=i;
				for(Line=0;Line<8;Line++)
				{
					////***
					DAQmxErrChk (DAQmxReadDigitalLines(DIOInfo[Device][Line+(Port*8)].taskHandle,
						         1,10.0,DAQmx_Val_GroupByChannel,data_0,100,&read_0,&bytesPerSamp,NULL));
					Multiplier=(1<<Line);
					Output_Port_Val_DIO6515[i]=Output_Port_Val_DIO6515[i]+(data_0[0]*(Multiplier));
					///***/
				}
	  		}
	  		///DIG_In_Port(Device, Port, &Output_Port_Val_DIO6515[i]);
	  		if((Device==1) && (Port==4))
	  		{
	  			Temp=Output_Port_Val_DIO6515[i];	
//    		  			if(Temp!=255)  JUST TESTING IF IT WORKED
//    		  				Temp1=1;
	  		}
	  	///#endif
	  }
  	 UpdateManualIO6515_LIB(0, Ptr_DIO6515_MN_PNL_Parameters->DIO6515_DYN_LED_OUT, Device,TabPanelHandle);
	Error:
		if( DAQmxFailed(error) )
			DAQmxGetExtendedErrorInfo(errBuff,2048);
	#endif 
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
void __stdcall UpdateManualIO6515_LIB(int Type, int Control[], int Device, int TabPanelHandle)
{
	short 			i, PortValue;
	
	for(i=0;i<TOTAL_NUMBER_OF_INPUT_PORTS_6515;i++)
	{
		if(Type)
		{
			PortValue=Input_Port_Val_DIO6515[i];  // Current Input Port Value
		}
		else 
		{
			PortValue=Output_Port_Val_DIO6515[i]; // Current Output Port Value 
		}

//		if(i==3) PortValue=0x01;
//		PortValue=0xFF;
		UpdateIO6515Port_LIB(i, PortValue, Control, Type, Device,TabPanelHandle); /// Update the Controls with Current Status
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
void __stdcall UpdateIO6515Port_LIB(int index, int PortValue, int Control[], int Type, int Device, int TabPanelHandle)
{
	int			Set, Reset, BIT_ON, DeviceOffset=0;
	
	///GetPanelHandleFromTabPage (DIOUtilsPanelHandle, DIOUTL_PNL_DIO_TAB, TAB_PAGE_ONE, &TabPanelHandle);
	
	if (Type)
	{
		Set=1; Reset=0;		/// Input
	}
	else
	{
		Set=1; Reset=0;		/// Output
	}
	if(Device==DIO6515DeviceNum2) DeviceOffset=NUM_DIO_LINE_6515;
	else DeviceOffset=0;
	
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
void __stdcall DIO6515_Dyn_OutputsButton1Handle_LIB(int i, int Device)
{
	int 			Port, Line;
	///short			State;
	char			errBuff[2048]={'\0'};             
	int 			error;
	static uInt8       	data[8];
	static int  	Flag1=0;/// Flag2=0, Flag3=0,Flag4=0, Flag5=0,Flag6=0, Flag7=0,Flag8=0;
	int32			read_0, bytesPerSamp;
	uInt8       	data_0[100]; /// data_1[100];
//		J=i%8; //JUST TESTING
//		K=i/8;
	#ifdef USEDATAACQ		
		if((i>=0) && (i<32))
		{
			//Device=DIO6515DeviceNum1;
			Port= DIO_OUTPUT_PORT_BASE_6515+(i/PORT_SIZE);
			Line= i%PORT_SIZE; 
			
			DAQmxErrChk (DAQmxReadDigitalLines(DIOInfo[Device][Line+(Port*8)].taskHandle,
				         1,10.0,DAQmx_Val_GroupByChannel,data_0,100,&read_0,&bytesPerSamp,NULL));
		}
		
		if(data_0[0]==0) Flag1=0;
		else if (data_0[0]==1) Flag1=1;

		if(!Flag1)
		{
			data[0]=1;
			if(Device==DIO6515DeviceNum1)
			{
				DAQmxErrChk (DAQmxWriteDigitalLines(DIOInfo[Device][Line+(Port*8)].taskHandle ,
					         1,1,10.0, DAQmx_Val_GroupByChannel,&data[0],NULL,NULL));
			}
		}
		else
		{
			data[0]=0;
			if(Device==DIO6515DeviceNum1)
			{
				DAQmxErrChk (DAQmxWriteDigitalLines(DIOInfo[Device][Line+(Port*8)].taskHandle ,
					         1,1,10.0, DAQmx_Val_GroupByChannel,&data[0],NULL,NULL));
			}
		}
		Error:
			if( DAQmxFailed(error) )
				DAQmxGetExtendedErrorInfo(errBuff,2048);
	#endif	
}
//*******************************************************************************************************************
void __stdcall DIO6515_Dyn_OutputsButton2Handle_LIB(int i, int Device)
{
	int 			Port, Line;
	///short			State;
	char			errBuff[2048]={'\0'};             
	int 			error;
	uInt8       	data[8];
	static int  	Flag1=0;/// Flag2=0, Flag3=0,Flag4=0, Flag5=0,Flag6=0, Flag7=0,Flag8=0;
	int32			read_0, bytesPerSamp;
	uInt8       	data_0[100]; /// data_1[100];
//		J=i%8; //JUST TESTING
//		K=i/8;
	#ifdef USEDATAACQ		
		if((i>=0) && (i<32))
		{
			//Device=DIO6515DeviceNum2;									
			Port= DIO_OUTPUT_PORT_BASE_6515+(i/PORT_SIZE);
			Line= i%PORT_SIZE; 
			
			DAQmxErrChk (DAQmxReadDigitalLines(DIOInfo[Device][Line+(Port*8)].taskHandle,
				         1,10.0,DAQmx_Val_GroupByChannel,data_0,100,&read_0,&bytesPerSamp,NULL));
		}
		
		if(data_0[0]==0) Flag1=0;
		else if (data_0[0]==1) Flag1=1;

		if(!Flag1)
		{
			data[0]=1;
			if(Device==DIO6515DeviceNum2)
			{
				DAQmxErrChk (DAQmxWriteDigitalLines(DIOInfo[Device][Line+(Port*8)].taskHandle ,
					         1,1,10.0, DAQmx_Val_GroupByChannel,&data[0],NULL,NULL));
			}
		}
		else
		{
			data[0]=0;
			if(Device==DIO6515DeviceNum2)
			{
				DAQmxErrChk (DAQmxWriteDigitalLines(DIOInfo[Device][Line+(Port*8)].taskHandle ,
					         1,1,10.0, DAQmx_Val_GroupByChannel,&data[0],NULL,NULL));
			}
		}
		Error:
			if( DAQmxFailed(error) )
				DAQmxGetExtendedErrorInfo(errBuff,2048);
	#endif	
}
// Returns the state of the apropriate input
short __stdcall ReadInput6515_LIB(char* DIO_Discription, int Device)
{
	int   Port, Line, Temp_Line;
	char  buf[100];
	short state=0;
	int32       		error=0;
	///uInt32      		numChannels;
	///uInt32      		Ch;
	char        		errBuff[2048]={'\0'};
	uInt8       		data_0[100]="";
	int32				read_0, bytesPerSamp;
	#ifdef USEDATAACQ
	/////CmtGetLock(Thread_6515_LockHandle);
	for(Line=0;Line<TOTAL_INPUT_DIO6515_LINE;Line++)
	{	
		DIOInfo[Device][Line].Device = Device;
		if(!strcmp(DIO_Discription, DIOInfo[Device][Line].DIOChannelName))
		{	
			//if(dio6515.disable[Line]==GLB_TRUE)
			//{	
		//		sprintf(buf, "< %s > is marked as disabled", DIO_Discription);
		//		MessagePopup("DIO Input Error!!", buf);
		//		/////CmtReleaseLock(Thread_6515_LockHandle);
		//		return DISABLE;
		//	}
			
			//Device = DIO6515DeviceNum1;
			Scan (DIOInfo[Device][Line].DIOPort, "%s>%d", &Port);
			Scan (DIOInfo[Device][Line].DIOBit, "%s>%d", &Temp_Line);
			
			if(Device==DIO6515DeviceNum1)
			{
				DAQmxErrChk (DAQmxReadDigitalLines(DIOInfo[Device][Line].taskHandle,
					         1,10.0,DAQmx_Val_GroupByChannel,data_0,100,&read_0,&bytesPerSamp,NULL));
			}
			state=data_0[0];
			/////CmtReleaseLock(Thread_6515_LockHandle);
			return state;
		}
		Error:
			if( DAQmxFailed(error) )
				DAQmxGetExtendedErrorInfo(errBuff,2048);
	}
	/////CmtReleaseLock(Thread_6515_LockHandle);
	sprintf(buf, "Unable to Locate <%s> Input. %d, %d, %d", DIO_Discription, Device, Port, Temp_Line);
	MessagePopup("Input Error!!", buf);
	state=NOT_FOUND;

	#endif
	return state;
}
//*******************************************************************************************************************
// Writes the state of the apropriate output driver
int __stdcall WriteOutput6515_LIB(char* DIO_Discription, int state, int Device)
{
	int  Port, Line, Temp_Line;
	char buf[100];
	int32       		error=0;
	///uInt32      		numChannels;
	///uInt32      		Ch;
	char        		errBuff[2048]={'\0'};
	uInt8       		data[100];
	/////int32				read_0, read_1,bytesPerSamp;
	#ifdef USEDATAACQ
	if(state!=GLB_TRUE && state!=GLB_FALSE)
	{	
		MessagePopup("Boolean Error", "Invalid boolean value, past to the WriteOutput() function.");
		return GLB_FALSE;
	}	
	// starting output line is offset by the total number of inputs
	for(Line=TOTAL_INPUT_DIO6515_LINE;Line<(TOTAL_OUTPUT_DIO6515_LINE + TOTAL_INPUT_DIO6515_LINE);Line++)
	{	
		if(!strcmp(DIO_Discription, DIOInfo[Device][Line].DIOChannelName))
		{	
			if(!strcmp(DIOInfo[Device][Line].DIOTestStatus,"N"))
			{	
				sprintf(buf, "< %s > is marked as disabled", DIO_Discription);
				MessagePopup("DIO Output Error!!", buf);
				return DISABLE;
			}
			if((Line>=TOTAL_INPUT_DIO6515_LINE) && (Line<TOTAL_INPUT_DIO6515_LINE+32))
			{
				//Device=DIO6515DeviceNum1;
				Port= (Line/PORT_SIZE)-4;
				Temp_Line= Line%PORT_SIZE;  
			}
			
			data[0]= state;
			if(Device==DIO6515DeviceNum1)
			{
				DAQmxErrChk (DAQmxWriteDigitalLines(DIOInfo[Device][Line].taskHandle ,
					         1,1,10.0, DAQmx_Val_GroupByChannel,&data[0],NULL,NULL));  
			}
			if(Device==DIO6515DeviceNum2)
			{
				DAQmxErrChk (DAQmxWriteDigitalLines(DIOInfo[Device][Line+(Port*8)].taskHandle ,
					         1,1,10.0, DAQmx_Val_GroupByChannel,&data[0],NULL,NULL));
			}
			
			
			Error:
				if( DAQmxFailed(error) )
				{
					DAQmxGetExtendedErrorInfo(errBuff,2048);
					return GLB_FALSE;
				}
			return GLB_TRUE;
		}	
	}
	sprintf(buf, "Unable to Locate <%s> Output.", DIO_Discription);
	MessagePopup("DIO Output Error!!", buf);
	#endif
	return GLB_FALSE;
}
//*******************************************************************************************************************
// Initialize device interface
int __stdcall InitDIOInterface6515(int Device)    
{   
	int			i, Port=0, Line=0, state=0;
	char		errBuff[2048]={'\0'}, str[100];             
	int 		error;
	///#ifdef USEDATAACQ
	////***
	for(i=0;i<TOTAL_NUMBER_DEVICE_6515;i++)
	{
		while (Port<TOTAL_NUMBER_OF_PORTS_6515)		
		{	
			if(Port>=4) state=1;						// set port direction to output (ports 3,4,5) 
			for(Line=0;Line<8;Line++)
			{
				if(state==0)
				{
					DAQmxErrChk (DAQmxCreateTask("",&DIOInfo[Device][Line+(Port*8)].taskHandle));
					DAQmxErrChk (DAQmxCreateDIChan (DIOInfo[Device][Line+(Port*8)].taskHandle,
													DIOInfo[Device][Line+(Port*8)].DIOName, DIOInfo[Device][Line+(Port*8)].DIOChannelName,
													DAQmx_Val_ChanPerLine));
					/*********************************************/
					// DAQmx Start Code
					/*********************************************/
					DAQmxErrChk (DAQmxStartTask(DIOInfo[Device][Line+(Port*8)].taskHandle));
				}
				if(state==1)
				{
					DAQmxErrChk (DAQmxCreateTask("",&DIOInfo[Device][Line+(Port*8)].taskHandle));
					DAQmxErrChk (DAQmxCreateDOChan (DIOInfo[Device][Line+(Port*8)].taskHandle,
													DIOInfo[Device][Line+(Port*8)].DIOName, DIOInfo[Device][Line+(Port*8)].DIOChannelName,
													DAQmx_Val_ChanPerLine));
					/*********************************************/
					// DAQmx Start Code
					/*********************************************/
					DAQmxErrChk (DAQmxStartTask(DIOInfo[Device][Line+(Port*8)].taskHandle));
				}
			Error:
				if( DAQmxFailed(error) )
				{
					DAQmxGetExtendedErrorInfo(errBuff,2048);
					sprintf(str, "Error Configuring Device #%d, Port %d, Line %d", Device+1, Port, Line);
					MessagePopup ("PCI-6515 Error", str);
					return GLB_FALSE;
				}
			}
			Port++;
		}
	}
	return GLB_TRUE;
}
///************************************************************************************************************


