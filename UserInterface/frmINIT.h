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

#define  INIT_PNL                         1
#define  INIT_PNL_MAIN_EXIT               2       /* control type: command, callback function: INITExitCB */
#define  INIT_PNL_DATE_2                  3       /* control type: textMsg, callback function: (none) */
#define  INIT_PNL_REVISION_2              4       /* control type: textMsg, callback function: (none) */
#define  INIT_PNL_COPY_RIGHT_2            5       /* control type: textMsg, callback function: (none) */
#define  INIT_PNL_TESTER_INTERFACE_2      6       /* control type: textMsg, callback function: (none) */
#define  INIT_PNL_FIXTURE_VENDOR_2        7       /* control type: textMsg, callback function: (none) */
#define  INIT_PNL_TESTER_NAME_2           8       /* control type: textMsg, callback function: (none) */
#define  INIT_PNL_DATE                    9       /* control type: textMsg, callback function: (none) */
#define  INIT_PNL_REVISION                10      /* control type: textMsg, callback function: (none) */
#define  INIT_PNL_COPY_RIGHT              11      /* control type: textMsg, callback function: (none) */
#define  INIT_PNL_TESTER_INTERFACE        12      /* control type: textMsg, callback function: (none) */
#define  INIT_PNL_FIXTURE_VENDOR          13      /* control type: textMsg, callback function: (none) */
#define  INIT_PNL_TESTER_NAME             14      /* control type: textMsg, callback function: (none) */
#define  INIT_PNL_PROJECT_NAME            15      /* control type: textMsg, callback function: (none) */
#define  INIT_PNL_DECORATION              16      /* control type: deco, callback function: (none) */
#define  INIT_PNL_PROJECT_NAME_2          17      /* control type: textMsg, callback function: (none) */
#define  INIT_PNL_DECORATION_2            18      /* control type: deco, callback function: (none) */
#define  INIT_PNL_PICTURE                 19      /* control type: picture, callback function: (none) */
#define  INIT_PNL_PROJECT_NAME_4          20      /* control type: textMsg, callback function: (none) */
#define  INIT_PNL_PROJECT_NAME_3          21      /* control type: textMsg, callback function: (none) */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK INITExitCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
