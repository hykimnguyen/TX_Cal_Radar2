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

#define  EP_PNL                           1
#define  EP_PNL_EPW_ENTER                 2       /* control type: string, callback function: (none) */
#define  EP_PNL_EPW_CANCEL                3       /* control type: command, callback function: EPasswordCallback */
#define  EP_PNL_OK_EPASSWORD              4       /* control type: command, callback function: EPasswordCallback */
#define  EP_PNL_DECORATION                5       /* control type: deco, callback function: (none) */
#define  EP_PNL_PW_MESSAGE                6       /* control type: textMsg, callback function: (none) */

#define  PD_PNL                           2
#define  PD_PNL_PW_ENTER                  2       /* control type: string, callback function: PasswordCallback */
#define  PD_PNL_PW_CANCEL                 3       /* control type: command, callback function: PasswordCallback */
#define  PD_PNL_OK_PASSWORD               4       /* control type: command, callback function: PasswordCallback */
#define  PD_PNL_DECORATION                5       /* control type: deco, callback function: (none) */
#define  PD_PNL_PW_MESSAGE                6       /* control type: textMsg, callback function: (none) */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK EPasswordCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK PasswordCallback(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
