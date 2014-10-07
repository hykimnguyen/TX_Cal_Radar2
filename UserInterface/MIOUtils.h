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

#define  MIOUTL_PNL                       1
#define  MIOUTL_PNL_MIOWRITE_BUTTON       2       /* control type: command, callback function: MIOUtilsWriteButtonCB */
#define  MIOUTL_PNL_MIO_UTILS_EXIT        3       /* control type: command, callback function: MIOUtilsExitCB */
#define  MIOUTL_PNL_READAITIMER           4       /* control type: timer, callback function: ReadDAITimerCB */
#define  MIOUTL_PNL_READIOTIMER           5       /* control type: timer, callback function: ReadDIOTimerCB */
#define  MIOUTL_PNL_INPUT_NUMERIC_PORT    6       /* control type: numeric, callback function: (none) */
#define  MIOUTL_PNL_INPUT_NUMERIC_BIT     7       /* control type: numeric, callback function: (none) */
#define  MIOUTL_PNL_OUTPUT_NUMERIC_BIT    8       /* control type: numeric, callback function: (none) */
#define  MIOUTL_PNL_OUTPUT_NUMERIC_PORT   9       /* control type: numeric, callback function: (none) */
#define  MIOUTL_PNL_OUTPUT_NUMERIC        10      /* control type: numeric, callback function: (none) */
#define  MIOUTL_PNL_INPUT_STRING          11      /* control type: string, callback function: (none) */
#define  MIOUTL_PNL_ENABL_AI_TIMER        12      /* control type: radioButton, callback function: EnablDisableReadAITimerCB */
#define  MIOUTL_PNL_OUTPUT_STRING         13      /* control type: string, callback function: (none) */
#define  MIOUTL_PNL_ENABL_TIMER           14      /* control type: radioButton, callback function: EnablDisableReadDIOTimerCB */
#define  MIOUTL_PNL_MIO_TAB               15      /* control type: tab, callback function: (none) */

#define  MIOUTLPNL2                       2
#define  MIOUTLPNL2_MIOWRITE_BUTTON       2       /* control type: command, callback function: MIOUtilsWriteButtonCB */
#define  MIOUTLPNL2_MIO_UTILS_EXIT2       3       /* control type: command, callback function: MIOUtilsExit2CB */
#define  MIOUTLPNL2_READAITIMER2          4       /* control type: timer, callback function: ReadDAITimer2CB */
#define  MIOUTLPNL2_READIOTIMER2          5       /* control type: timer, callback function: ReadDIOTimer2CB */
#define  MIOUTLPNL2_INPUT_NUMERIC_PORT    6       /* control type: numeric, callback function: (none) */
#define  MIOUTLPNL2_INPUT_NUMERIC_BIT     7       /* control type: numeric, callback function: (none) */
#define  MIOUTLPNL2_OUTPUT_NUMERIC_BIT    8       /* control type: numeric, callback function: (none) */
#define  MIOUTLPNL2_OUTPUT_NUMERIC_PORT   9       /* control type: numeric, callback function: (none) */
#define  MIOUTLPNL2_OUTPUT_NUMERIC        10      /* control type: numeric, callback function: (none) */
#define  MIOUTLPNL2_INPUT_STRING          11      /* control type: string, callback function: (none) */
#define  MIOUTLPNL2_ENABL_AI_TIMER        12      /* control type: radioButton, callback function: EnablDisableReadAITimer2CB */
#define  MIOUTLPNL2_OUTPUT_STRING         13      /* control type: string, callback function: (none) */
#define  MIOUTLPNL2_ENABL_TIMER           14      /* control type: radioButton, callback function: EnablDisableReadDIOTimer2CB */
#define  MIOUTLPNL2_MIO_TAB2              15      /* control type: tab, callback function: (none) */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK EnablDisableReadAITimer2CB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK EnablDisableReadAITimerCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK EnablDisableReadDIOTimer2CB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK EnablDisableReadDIOTimerCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK MIOUtilsExit2CB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK MIOUtilsExitCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK MIOUtilsWriteButtonCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK ReadDAITimer2CB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK ReadDAITimerCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK ReadDIOTimer2CB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK ReadDIOTimerCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
