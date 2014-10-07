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

#define  CAP_PNL                          1
#define  CAP_PNL_INTERVAL_NUM             2       /* control type: numeric, callback function: (none) */
#define  CAP_PNL_CYCLE_NUM                3       /* control type: numeric, callback function: (none) */
#define  CAP_PNL_FILENAME_STRING          4       /* control type: string, callback function: (none) */
#define  CAP_PNL_UNLIMITED_CHCKBOX        5       /* control type: radioButton, callback function: (none) */
#define  CAP_PNL_CANCLECAPABILITYMODE     6       /* control type: command, callback function: CancleCapabilityMode */
#define  CAP_PNL_EXITCAPABILITYMODE       7       /* control type: command, callback function: UpdateCapabilityMode */
#define  CAP_PNL_DECORATION               8       /* control type: deco, callback function: (none) */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK CancleCapabilityMode(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK UpdateCapabilityMode(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
