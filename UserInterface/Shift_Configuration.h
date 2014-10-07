/**************************************************************************/
/* LabWindows/CVI User Interface Resource (UIR) Include File              */
/* Copyright (c) National Instruments 2013. All Rights Reserved.          */
/*                                                                        */
/* WARNING: Do not add to, delete from, or otherwise modify the contents  */
/*          of this include file.                                         */
/**************************************************************************/

#include <userint.h>

#ifdef __cplusplus
    extern "C" {
#endif

     /* Panels and Controls: */

#define  SHIFT_PNL                        1
#define  SHIFT_PNL_SHIFT_CONFIG_TABLE     2       /* control type: table, callback function: ShiftTableCB */
#define  SHIFT_PNL_CURRENT_TIME           3       /* control type: string, callback function: (none) */
#define  SHIFT_PNL_SHIFT_STRING           4       /* control type: string, callback function: ShiftStringCB */
#define  SHIFT_PNL_DATE_CODE_TIMER        5       /* control type: timer, callback function: DateCodeTimer */
#define  SHIFT_PNL_EXIT                   6       /* control type: command, callback function: ShiftConfigExitCB */
#define  SHIFT_PNL_SAVE                   7       /* control type: command, callback function: ShiftConfigSaveCB */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK DateCodeTimer(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK ShiftConfigExitCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK ShiftConfigSaveCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK ShiftStringCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK ShiftTableCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
