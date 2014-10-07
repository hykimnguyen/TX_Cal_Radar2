/**************************************************************************/
/* LabWindows/CVI User Interface Resource (UIR) Include File              */
/* Copyright (c) National Instruments 2014. All Rights Reserved.          */
/*                                                                        */
/* WARNING: Do not add to, delete from, or otherwise modify the contents  */
/*          of this include file.                                         */
/**************************************************************************/

#include <userint.h>


#define DEC 		0
#define HEX			1



#ifdef __cplusplus
    extern "C" {
#endif

     /* Panels and Controls: */

#define  MEM_PNL                          1
#define  MEM_PNL_TEXTMSG                  2       /* control type: textMsg, callback function: (none) */
#define  MEM_PNL_CONNECTUNITBUTTON        3       /* control type: command, callback function: ConnectUnitCB */
#define  MEM_PNL_DISCONNECTUNITBUTTON     4       /* control type: command, callback function: DisconnectUnitCB */
#define  MEM_PNL_EXITBUTTON               5       /* control type: command, callback function: ExitCB */
#define  MEM_PNL_SENDCOMMANDBUTTON        6       /* control type: command, callback function: SendCommand */
#define  MEM_PNL_VIEMINFOBUTTON           7       /* control type: command, callback function: ViewInfoCB */
#define  MEM_PNL_WRITEMEMORYBUTTON        8       /* control type: command, callback function: WriteMemoryCB */
#define  MEM_PNL_READMEMORYBUTTON         9       /* control type: command, callback function: ReadMemoryCB */
#define  MEM_PNL_TESTUNIT_RING            10      /* control type: ring, callback function: TestUnitCB */
#define  MEM_PNL_MESSAGE_LIBRARY          11      /* control type: ring, callback function: Populate_Send_Command */
#define  MEM_PNL_FORMAT_RING              12      /* control type: ring, callback function: FormatCtrlCB */
#define  MEM_PNL_WRITEVALUE_STRING        13      /* control type: string, callback function: (none) */
#define  MEM_PNL_READVALUE_STRING         14      /* control type: string, callback function: (none) */
#define  MEM_PNL_WRITEADDRESS_STRING      15      /* control type: string, callback function: (none) */
#define  MEM_PNL_READADDRESS_STRING       16      /* control type: string, callback function: (none) */
#define  MEM_PNL_PICTURE                  17      /* control type: picture, callback function: (none) */
#define  MEM_PNL_CAL_MEM_LISTBOX          18      /* control type: listBox, callback function: (none) */
#define  MEM_PNL_CAN_MESSAGE              19      /* control type: string, callback function: (none) */
#define  MEM_PNL_DECORATION               20      /* control type: deco, callback function: (none) */
#define  MEM_PNL_DECORATION_2             21      /* control type: deco, callback function: (none) */


     /* Control Arrays: */

          /* (no control arrays in the resource file) */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK ConnectUnitCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK DisconnectUnitCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK ExitCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK FormatCtrlCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Populate_Send_Command(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK ReadMemoryCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SendCommand(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK TestUnitCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK ViewInfoCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK WriteMemoryCB(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
