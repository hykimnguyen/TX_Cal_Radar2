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

#define  SYSCFG_PNL                       1
#define  SYSCFG_PNL_SYS_CFG_TAB           2       /* control type: tab, callback function: SysMiscCfgTabCB */
#define  SYSCFG_PNL_SYS_CFG__EXIT         3       /* control type: command, callback function: SYSCFGExitCB */

     /* tab page panel controls */
#define  MIS_TB_TAB_SYSDELETE_ROW         2       /* control type: command, callback function: SYSDeleteRowCB */
#define  MIS_TB_TAB_SYSINSERT_ROW         3       /* control type: command, callback function: SYSInsertRowCB */
#define  MIS_TB_TAB_MISC_CFG_SAVE         4       /* control type: command, callback function: MISCCFGSaveCB */
#define  MIS_TB_TAB_NUM_MSCI              5       /* control type: numeric, callback function: (none) */
#define  MIS_TB_TAB_NUM_COLUMNS           6       /* control type: numeric, callback function: (none) */

     /* tab page panel controls */
#define  TREE_TAB_MISC_TREE               2       /* control type: tree, callback function: (none) */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK MISCCFGSaveCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SYSCFGExitCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SYSDeleteRowCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SYSInsertRowCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SysMiscCfgTabCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
