/**************************************************************************/
/* LabWindows/CVI User Interface Resource (UIR) Include File              */
/* Copyright (c) National Instruments 2014. All Rights Reserved.          */
/*                                                                        */
/* WARNING: Do not add to, delete from, or otherwise modify the contents  */
/*          of this include file.                                         */
/**************************************************************************/

#include <userint.h>

#ifdef __cplusplus
    extern "C" {
#endif

     /* Panels and Controls: */

#define  Main                             1
#define  Main_STOP_CAPABILITY_TEST        2       /* control type: command, callback function: StopCapabilityModeCB */
#define  Main_CLOCK_TIMER                 3       /* control type: timer, callback function: UpdateClock */
#define  Main_START_TIMER                 4       /* control type: timer, callback function: StartTest */
#define  Main_CAP_COUNTER                 5       /* control type: numeric, callback function: (none) */
#define  Main_PASSWORDTIMER               6       /* control type: timer, callback function: PasswordTimerCB */
#define  Main_CAP_TIMER                   7       /* control type: timer, callback function: UpdateCapabilityTimerCB */
#define  Main_ESTOP_TIMER                 8       /* control type: timer, callback function: EstopTimerCB */
#define  Main_IMG_AUTOLIV                 9       /* control type: picture, callback function: (none) */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

#define  MAIN                             1
#define  MAIN_FILE                        2
#define  MAIN_FILE_EXIT                   3       /* callback function: MAINMenuFileCB */
#define  MAIN_EDIT                        4
#define  MAIN_EDIT_PW_VERIFY              5       /* callback function: MAINEditMenuCB */
#define  MAIN_EDIT_EPW_VERIFY             6       /* callback function: MAINEditMenuCB */
#define  MAIN_EDIT_SYSTEM_CONFIG          7       /* callback function: MAINEditMenuCB */
#define  MAIN_EDIT_TEST_CONFIG            8       /* callback function: MAINEditMenuCB */
#define  MAIN_EDIT_DIO6515                9       /* callback function: MAINEditMenuCB */
#define  MAIN_EDIT_MIO6220                10      /* callback function: MAINEditMenuCB */
#define  MAIN_EDIT_SHIFT                  11      /* callback function: MAINEditMenuCB */
#define  MAIN_EDIT_CAPABILITY             12      /* callback function: MAINEditMenuCB */
#define  MAIN_EDIT_HISTOYIELD             13      /* callback function: MAINEditMenuCB */
#define  MAIN_VIEW                        14
#define  MAIN_VIEW_SYSTEM_CONFIG          15      /* callback function: MAINViewMenuCB */
#define  MAIN_VIEW_TEST_CONFIG            16      /* callback function: MAINViewMenuCB */
#define  MAIN_VIEW_DIO6515                17      /* callback function: MAINViewMenuCB */
#define  MAIN_VIEW_MIO6220                18      /* callback function: MAINViewMenuCB */
#define  MAIN_VIEW_SHIFT                  19      /* callback function: MAINViewMenuCB */
#define  MAIN_VIEW_CLEAR_TEST_COUNT       20      /* callback function: MAINViewMenuCB */
#define  MAIN_HARDWARE_CONTROL            21
#define  MAIN_HARDWARE_CONTROL_DIO6515U   22      /* callback function: MAINHardwareCtrlCB */
#define  MAIN_HARDWARE_CONTROL_DUTMEMORY  23      /* callback function: MAINHardwareCtrlCB */
#define  MAIN_HELP                        24
#define  MAIN_HELP_USER_GUIDE             25      /* callback function: MainHelpCB */
#define  MAIN_HELP_EE_SCHEMATICS          26      /* callback function: MainHelpCB */
#define  MAIN_HELP_MECH_SCHEMATICS        27      /* callback function: MainHelpCB */
#define  MAIN_HELP_SW_FUNCTIONS           28      /* callback function: MainHelpCB */
#define  MAIN_HELP_ABOUT                  29      /* callback function: MainHelpCB */


     /* Callback Prototypes: */

int  CVICALLBACK EstopTimerCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
void CVICALLBACK MAINEditMenuCB(int menubar, int menuItem, void *callbackData, int panel);
void CVICALLBACK MAINHardwareCtrlCB(int menubar, int menuItem, void *callbackData, int panel);
void CVICALLBACK MainHelpCB(int menubar, int menuItem, void *callbackData, int panel);
void CVICALLBACK MAINMenuFileCB(int menubar, int menuItem, void *callbackData, int panel);
void CVICALLBACK MAINViewMenuCB(int menubar, int menuItem, void *callbackData, int panel);
int  CVICALLBACK PasswordTimerCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK StartTest(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK StopCapabilityModeCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK UpdateCapabilityTimerCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK UpdateClock(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
