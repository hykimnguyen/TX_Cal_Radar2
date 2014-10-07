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

#define  DIO6515PNL                       1
#define  DIO6515PNL_WRITE_BUTTON          2       /* control type: command, callback function: DIO6515UtilsWriteButtonCB */
#define  DIO6515PNL_DIO6515_UTILS_EXIT    3       /* control type: command, callback function: DIO6515UtilsExitCB */
#define  DIO6515PNL_READIOTIMER           4       /* control type: timer, callback function: Read6515IOTimerCB */
#define  DIO6515PNL_INPUT_NUMERIC_PORT    5       /* control type: numeric, callback function: (none) */
#define  DIO6515PNL_INPUT_NUMERIC_BIT     6       /* control type: numeric, callback function: (none) */
#define  DIO6515PNL_OUTPUT_NUMERIC_BIT    7       /* control type: numeric, callback function: (none) */
#define  DIO6515PNL_OUTPUT_NUMERIC_PORT   8       /* control type: numeric, callback function: (none) */
#define  DIO6515PNL_OUTPUT_NUMERIC        9       /* control type: numeric, callback function: (none) */
#define  DIO6515PNL_INPUT_STRING          10      /* control type: string, callback function: (none) */
#define  DIO6515PNL_OUTPUT_STRING         11      /* control type: string, callback function: (none) */
#define  DIO6515PNL_ENABL_TIMER           12      /* control type: radioButton, callback function: EnablDisableRead6515IOTimerCB */
#define  DIO6515PNL_DIO6515_TAB           13      /* control type: tab, callback function: (none) */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK DIO6515UtilsExitCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK DIO6515UtilsWriteButtonCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK EnablDisableRead6515IOTimerCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Read6515IOTimerCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int getFixtureId(void);
char * getFixtureName(int Id);

/* Air Pressure Sensor */  
int getVacSensor(void);

#ifdef __cplusplus
    }
#endif
