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

#define  PS_PNL                           1
#define  PS_PNL_RECIPE__EXIT              2       /* control type: command, callback function: RecipeExitCB */
#define  PS_PNL_RECIPE_TABLE              3       /* control type: table, callback function: RecipeTableCB */
#define  PS_PNL_TEXTMSG_3                 4       /* control type: textMsg, callback function: (none) */
#define  PS_PNL_txtTestFile0              5       /* control type: textMsg, callback function: (none) */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK RecipeExitCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK RecipeTableCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int deleteAllFiles(char * errMsg);


#ifdef __cplusplus
    }
#endif
