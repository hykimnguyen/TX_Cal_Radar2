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

#define  DIO_PNL                          1
#define  DIO_PNL_DIO6515_CFG__EXIT        2       /* control type: command, callback function: DIO6515CFGExitCB */
#define  DIO_PNL_DIO6515_CFG_TAB          3       /* control type: tab, callback function: DIO6515CfgTabCB */

     /* tab page panel controls */
#define  TABLE_TAB_DELETE_ROW             2       /* control type: command, callback function: DIODeleteRowCB */
#define  TABLE_TAB_DIOINSERT_ROW          3       /* control type: command, callback function: DIOInsertRowCB */
#define  TABLE_TAB_NUM_DIO                4       /* control type: numeric, callback function: (none) */
#define  TABLE_TAB_NUM_COLUMNS            5       /* control type: numeric, callback function: (none) */
#define  TABLE_TAB_DIO6515_CFG_SAVE       6       /* control type: command, callback function: DIO6515CFGSaveCB */

     /* tab page panel controls */
#define  TABLE_TAB2_DIO2DELETE_ROW        2       /* control type: command, callback function: DIODeleteRowCB */
#define  TABLE_TAB2_DIO2INSERT_ROW        3       /* control type: command, callback function: DIOInsertRowCB */
#define  TABLE_TAB2_NUM_DIO               4       /* control type: numeric, callback function: (none) */
#define  TABLE_TAB2_NUM_COLUMNS           5       /* control type: numeric, callback function: (none) */
#define  TABLE_TAB2_DIO6515_CFG_SAVE_2    6       /* control type: command, callback function: DIO6515CFGSaveCB_2 */

     /* tab page panel controls */
#define  TREE_TAB_DIO_TREE                2       /* control type: tree, callback function: (none) */

     /* tab page panel controls */
#define  TREE_TAB2_DIO_TREE2              2       /* control type: tree, callback function: (none) */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK DIO6515CFGExitCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK DIO6515CFGSaveCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK DIO6515CFGSaveCB_2(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK DIO6515CfgTabCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK DIODeleteRowCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK DIOInsertRowCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
