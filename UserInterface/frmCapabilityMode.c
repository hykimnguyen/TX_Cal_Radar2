/***********************************************************************
 *
 *
 *  COPYRIGHT: Arxtron Technologies Inc. All Rights Reserved.
 *
 *  PURPOSE:  
 *            
 *            
 *            
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
*    @file    frmCapabilityMode.c
*    @brief    Contains functions related to capability mode  .
*    @author  Arxtron Technologies Inc.
*    @date    2013.9.6
*    Function to run capability test. Capability mode is used to run
*    multiple iteration on the same DUT.
*    Please Note: Capability mode is for internal use during development.
*/
 
#include <cvirte.h>		
#include <userint.h>
#include "Global.h"
#include "DataLib.h" 
#include "frmCapabilityMode.h"

#if USE_EXT_MAIN_PROJ 

#else  
//int main (int argc, char *argv[])
//{
//	if (InitCVIRTE (0, argv, 0) == 0)
//		return -1;	/* out of memory */
//	if ((CapabilityPanelHandle = LoadPanel (0, "frmCapabilityMode.uir", CAP_PNL)) < 0)
//		return -1;
//	DisplayPanel (CapabilityPanelHandle);
//	RunUserInterface ();
//	DiscardPanel (CapabilityPanelHandle);
//	return 0;
//}
#endif


/********************************************//**
*  Manage different event for the capability panel
***********************************************/
int CVICALLBACK UpdateCapabilityMode (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	long size;
	char dir[MAX_PATHNAME_LEN], temp_file[MAX_PATHNAME_LEN];
	
	switch (event)
	{
		case EVENT_COMMIT:
			 GetCtrlVal(CapabilityPanelHandle, CAP_PNL_FILENAME_STRING, val_filename);
			 if(!strcmp(val_filename, ""))
			 {	
				MessagePopup("Filename", "Please enter filename");
			 	break;
			 }	
					 
			 GetProjectDir(dir); 
			 strcat(val_filename,".csv");
			 sprintf(temp_file, "\\Log\\%s", val_filename);  // path for re-validate test results
    		 strcat(dir, temp_file);
					 
			 if(GetFileInfo(dir, &size))
			 {	
				if(!ConfirmPopup("Duplicate Filename", "File already exist, delete???"))
			  	{	
					SetCtrlVal(CapabilityPanelHandle, CAP_PNL_FILENAME_STRING, " ");
			  		break;
			  	}	
			  	DeleteFile(dir);
			 }	
					 
			 GetCtrlVal (CapabilityPanelHandle, CAP_PNL_CYCLE_NUM,         &num_capability_cycle);
			 GetCtrlVal (CapabilityPanelHandle, CAP_PNL_INTERVAL_NUM,      &capability_time_interval);
			 GetCtrlVal (CapabilityPanelHandle, CAP_PNL_UNLIMITED_CHCKBOX, &unlimited_capability_test);
					 
			 CheckError(HidePanel(CapabilityPanelHandle));
			 RunCapabilityMode();
			break;
		case EVENT_KEYPRESS:

			break;
	}
	return 0;
}


/********************************************//**
*  Cancel capability run
***********************************************/
int CVICALLBACK CancleCapabilityMode (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
					//	#if USE_EXT_MAIN_PROJ
							CheckError(HidePanel(CapabilityPanelHandle)); 
					//	#else		
					//		QuitUserInterface (0);
					//	#endif
			break;
		case EVENT_KEYPRESS:

			break;
	}
	return 0;
}
