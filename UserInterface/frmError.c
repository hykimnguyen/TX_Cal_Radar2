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
*    @file    frmError.c
*    @brief    Error message panel.
*    @author  Arxtron Technologies Inc.
*    @date    2013.9.6
*    Contains code for handeling the frmError.uir panel. 
*/


#include <cvirte.h>		
#include <userint.h>
#include "Global.h"
#include "DataLib.h"
#include "TestSteps.h"
#include "frmMain.h"

#if USE_EXT_MAIN_PROJ 

#else  

//int main (int argc, char *argv[])
//{
//	if (InitCVIRTE (0, argv, 0) == 0)
//		return -1;	/* out of memory */
//	if ((ErrorPanelHandle = LoadPanel (0, "frmError.uir", ERR_PNL)) < 0)
//		return -1;
//	DisplayPanel (ErrorPanelHandle);
//	RunUserInterface ();
//	DiscardPanel (ErrorPanelHandle);
//	return 0;
//}
#endif 

/********************************************//**
 *  Form Errot Exit callback 
 ***********************************************/
int CVICALLBACK ErrorExitCB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			#if USE_EXT_MAIN_PROJ
				estopFlag=0;
				
				/* Air Pressure Sensor */    
				SetCtrlAttribute (MainPanelHandle, Main_CLOCK_TIMER, ATTR_ENABLED, 1);
				
				CheckError(HidePanel(ErrorPanelHandle)); 
			#else		
				QuitUserInterface (0);
			#endif
			break;
	}
	return 0;
}
