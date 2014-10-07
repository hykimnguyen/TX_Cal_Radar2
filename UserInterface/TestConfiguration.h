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

#define  TSTCFG_PNL                       1
#define  TSTCFG_PNL_TST_CFG_TAB           2       /* control type: tab, callback function: TestCfgTabCB */
#define  TSTCFG_PNL_TST_CFG__EXIT         3       /* control type: command, callback function: TSTCFGExitCB */

     /* tab page panel controls */
#define  TREE_TAB_TST_TREE                2       /* control type: tree, callback function: (none) */

     /* tab page panel controls */
#define  TST_TB_TAB_TSTDELETE_ROW         2       /* control type: command, callback function: TSTDeleteRowCB */
#define  TST_TB_TAB_TSTINSERT_ROW         3       /* control type: command, callback function: TSTInsertRowCB */
#define  TST_TB_TAB_TST_CFG_SAVE          4       /* control type: command, callback function: TSTCFGSaveCB */
#define  TST_TB_TAB_NUM_MSCI              5       /* control type: numeric, callback function: (none) */
#define  TST_TB_TAB_NUM_COLUMNS           6       /* control type: numeric, callback function: (none) */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK TestCfgTabCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK TSTCFGExitCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK TSTCFGSaveCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK TSTDeleteRowCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK TSTInsertRowCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
