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

#define  MIO_PNL                          1
#define  MIO_PNL_NUM_COLUMNS              2       /* control type: numeric, callback function: (none) */
#define  MIO_PNL_MIO_CFG__EXIT            3       /* control type: command, callback function: MIOCFGExitCB */
#define  MIO_PNL_MIO_CFG_TAB              4       /* control type: tab, callback function: AICfgTabCB */

#define  MIO_PNL_2                        2
#define  MIO_PNL_2_MIO_CFG_TAB_2          2       /* control type: tab, callback function: AICfgTab2CB */
#define  MIO_PNL_2_MIO_CFG__EXIT          3       /* control type: command, callback function: MIOCFGExit2CB */

     /* tab page panel controls */
#define  AI_TB_TA_2_MAIDELETE_ROW_2       2       /* control type: command, callback function: MAIDeleteRow2CB */
#define  AI_TB_TA_2_MAIINSERT_ROW_2       3       /* control type: command, callback function: MAIInsertRow2CB */
#define  AI_TB_TA_2_AI_CFG_SAVE_2         4       /* control type: command, callback function: AICFGSave2CB */
#define  AI_TB_TA_2_NUM_COLUMNS           5       /* control type: numeric, callback function: (none) */
#define  AI_TB_TA_2_NUM_AI                6       /* control type: numeric, callback function: (none) */

     /* tab page panel controls */
#define  AI_TB_TAB_MAIDELETE_ROW          2       /* control type: command, callback function: MAIDeleteRowCB */
#define  AI_TB_TAB_MAIINSERT_ROW          3       /* control type: command, callback function: MAIInsertRowCB */
#define  AI_TB_TAB_AI_CFG_SAVE            4       /* control type: command, callback function: AICFGSaveCB */
#define  AI_TB_TAB_NUM_COLUMNS            5       /* control type: numeric, callback function: (none) */
#define  AI_TB_TAB_NUM_AI                 6       /* control type: numeric, callback function: (none) */

     /* tab page panel controls */
#define  AO_TB_TA_2_MAODELETE_ROW_2       2       /* control type: command, callback function: MAODeleteRow2CB */
#define  AO_TB_TA_2_MAOINSERT_ROW_2       3       /* control type: command, callback function: MAOInsertRow2CB */
#define  AO_TB_TA_2_AO_CFG_SAVE_2         4       /* control type: command, callback function: AOCFGSave2CB */
#define  AO_TB_TA_2_NUM_COLUMNS_2         5       /* control type: numeric, callback function: (none) */
#define  AO_TB_TA_2_NUM_AO_2              6       /* control type: numeric, callback function: (none) */

     /* tab page panel controls */
#define  AO_TB_TAB_MAODELETE_ROW          2       /* control type: command, callback function: MAODeleteRowCB */
#define  AO_TB_TAB_MAOINSERT_ROW          3       /* control type: command, callback function: MAOInsertRowCB */
#define  AO_TB_TAB_AO_CFG_SAVE            4       /* control type: command, callback function: AOCFGSaveCB */
#define  AO_TB_TAB_NUM_COLUMNS            5       /* control type: numeric, callback function: (none) */
#define  AO_TB_TAB_NUM_AO                 6       /* control type: numeric, callback function: (none) */

     /* tab page panel controls */
#define  MIO_TB_T_2_MIODELETE_ROW_2       2       /* control type: command, callback function: MIODeleteRow2CB */
#define  MIO_TB_T_2_MDIOINSERT_ROW_2      3       /* control type: command, callback function: MDIOInsertRow2CB */
#define  MIO_TB_T_2_MDIO_CFG_SAVE_2       4       /* control type: command, callback function: MDIOCFGSave2CB */
#define  MIO_TB_T_2_NUM_MDIO_2            5       /* control type: numeric, callback function: (none) */
#define  MIO_TB_T_2_NUM_COLUMNS_2         6       /* control type: numeric, callback function: (none) */

     /* tab page panel controls */
#define  MIO_TB_TAB_MIODELETE_ROW         2       /* control type: command, callback function: MIODeleteRowCB */
#define  MIO_TB_TAB_MDIOINSERT_ROW        3       /* control type: command, callback function: MDIOInsertRowCB */
#define  MIO_TB_TAB_MDIO_CFG_SAVE         4       /* control type: command, callback function: MDIOCFGSaveCB */
#define  MIO_TB_TAB_NUM_MDIO              5       /* control type: numeric, callback function: (none) */
#define  MIO_TB_TAB_NUM_COLUMNS           6       /* control type: numeric, callback function: (none) */

     /* tab page panel controls */
#define  TREE_TAB_AI_TREE                 2       /* control type: tree, callback function: (none) */

     /* tab page panel controls */
#define  TREE_TAB2_AO_TREE                2       /* control type: tree, callback function: (none) */

     /* tab page panel controls */
#define  TREE_TAB3_DIO_TREE               2       /* control type: tree, callback function: (none) */

     /* tab page panel controls */
#define  TREE_TAB_2_AI_TREE_2             2       /* control type: tree, callback function: (none) */

     /* tab page panel controls */
#define  TREE_TAB_3_AO_TREE_2             2       /* control type: tree, callback function: (none) */

     /* tab page panel controls */
#define  TREE_TAB_4_DIO_TREE_2            2       /* control type: tree, callback function: (none) */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK AICFGSave2CB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK AICFGSaveCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK AICfgTab2CB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK AICfgTabCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK AOCFGSave2CB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK AOCFGSaveCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK MAIDeleteRow2CB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK MAIDeleteRowCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK MAIInsertRow2CB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK MAIInsertRowCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK MAODeleteRow2CB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK MAODeleteRowCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK MAOInsertRow2CB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK MAOInsertRowCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK MDIOCFGSave2CB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK MDIOCFGSaveCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK MDIOInsertRow2CB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK MDIOInsertRowCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK MIOCFGExit2CB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK MIOCFGExitCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK MIODeleteRow2CB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK MIODeleteRowCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
