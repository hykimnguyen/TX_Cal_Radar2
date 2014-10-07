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
*    @file    frmINIT.c
*    @brief   Help->bout panel code.
*    @author  Arxtron Technologies Inc.
*    @date    2013.9.6
*    Contains code to handle the frmINIT.uir panel which contains the about tab. 
*/


#include <cvirte.h>		
#include <userint.h>
#include "Global.h"
#include "DataLib.h" 
#include "frmINIT.h"


#if USE_EXT_MAIN_PROJ

#else

//int main (int argc, char *argv[])
//{
//	if (InitCVIRTE (0, argv, 0) == 0)
//		return -1;	/* out of memory */
//	if ((InitPanelHandle = LoadPanel (0, "frmINIT.uir", INIT_PNL)) < 0)
//		return -1;
//	DisplayPanel (InitPanelHandle);
//	RunUserInterface ();
//	DiscardPanel (InitPanelHandle);
//	return 0;
//}
#endif 

/********************************************//**
 *  Form Exit callback  
 ***********************************************/
int CVICALLBACK INITExitCB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			#if USE_EXT_MAIN_PROJ
				CheckError(HidePanel(InitPanelHandle)); 
			#else		
				QuitUserInterface (0);
			#endif
			break;
	}
	return 0;
}
