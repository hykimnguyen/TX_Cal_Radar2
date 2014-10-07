/***********************************************************************
 *
 *
 *  COPYRIGHT: Arxtron Technologies Inc. All Rights Reserved.
 *
 *  PURPOSE: - Driver configuration for Digital IO 6515.    
 *
 *  DEVELOPMENT HISTORY:
 *
 *  Date        Name           Rev.   Description
 *  ----------  -------------  -----  -----------------------
 *  07-29-2013  Arxtron        1      Initial Release
 *  
 *  
 *********************************************************************/ 
/*!
*    @file    DIO6515.c
*    @brief   Driver configuration for Digital IO 6515.
*    @author  Arxtron Technologies Inc.
*    @date    2013.9.6
*    Driver configuration for Digital IO 6515. 
*/ 

#include <cvirte.h>		
#include <userint.h>
#include "Global.h"
///#include "Password.h" 
#include "DIO6515.h"
#include "DIO6515Def.h"
#include "DataLib.h"


//*******************************************************************************************************************
#if USE_EXT_MAIN_PROJ 

#else  

/********************************************//**
*  DIO 6515 main         
***********************************************/
//int main (int argc, char *argv[])
//{
//	char					dir[MAX_PATHNAME_LEN], uirPath[MAX_PATHNAME_LEN];/*dbPath[MAX_PATHNAME_LEN],SQLString[1000],strSeparator[10] = ", ";*/
//	CVIXMLElement rootElement;
//	char DIO6515DeviceNum1Str[100];
//	
//	if (InitCVIRTE (0, argv, 0) == 0)
//		return -1;	/* out of memory */
//	if ((DIO6515ConfigPanelHandle = LoadPanel (0, "DIO6515.uir", DIO_PNL)) < 0)
//		return -1;
//	DisplayPanel (DIO6515ConfigPanelHandle);
//	
//	GetProjectDir(dir);
//	sprintf(uirPath, "%s%s", dir,"\\Configuration\\gMiscellaneous.xml");
//	rootElement = LoadConfigurationDocument(uirPath);
//	ParseXMLDocument(rootElement, 0);
//
//	strcpy(DIO6515DeviceNum1Str, GetCfgMiscValue("DIO6515DeviceNum1",80));
//	Scan (DIO6515DeviceNum1Str, "%s>%d", &DIO6515DeviceNum1);
//	
//	sprintf(uirPath, "%s%s", dir,"\\Configuration\\DIO6515Definition.xml");
//	rootElement = LoadConfigurationDocument(uirPath);
//	ParseXMLDocument(rootElement, 1);
	
	
//	CreateDigitalIO6515ConfigurationTable();
//	CreateDigitalIO6515ConfigurationTable2();
//	DisplayDIO6515Control(1, 1);
	
//	RunUserInterface ();
//	DiscardPanel (DIO6515ConfigPanelHandle);
//	return 0;
//}
#endif

/********************************************//**
*  DIO 6515 Exit Callback         
***********************************************/
int CVICALLBACK DIO6515CFGExitCB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
						
						//#if USE_EXT_MAIN_PROJ
							DIOViewMenu=0;
							///EnableDIO6515ControlSaving();
							CheckError(HidePanel(DIO6515ConfigPanelHandle)); 
						//#else		
						//	QuitUserInterface (0);
						//#endif
						
			//QuitUserInterface (0);  
			break;
		case EVENT_KEYPRESS:

			break;
	}
	return 0;
}


/********************************************//**
*  DIO 6515 Configuration Tab Callback          
***********************************************/
int CVICALLBACK DIO6515CfgTabCB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_KEYPRESS:

			break;
		case EVENT_ACTIVE_TAB_CHANGE:
			 //ctrlID = GetActiveCtrl(SystemPanelHandle);   
			 //GetActiveTabPage   (SystemPanelHandle, control, &activeIndex);
			 if((eventData2 == 1) && (!DIOViewMenu))  // eventData2 => Currently Selected TabPage  eventData1 => Previously Selected TabPage
			 {
				 PWD_KeyPress_Loc=0;
				 //MessagePopup("Password", "Password Required");
/***				 
				 if(!PasswordProtectedMenu)				 
				 {
					 if(VerifyPassword(PD_PNL, PD_PNL_PW_MESSAGE, PD_PNL_PW_ENTER, VERIFY) == GLB_PASS) 
					 {
						 strcpy(password,""); 
					 }
					 else
					 {
						 SetActiveTabPage (DIO6515ConfigPanelHandle, control, 0);
						 strcpy(password,""); 
					 }
				 }
***/				 
			 }
			break;
			
	}
	return 0;
}

/********************************************//**
*  DIO 6515 Save Callback         
***********************************************/
int CVICALLBACK DIO6515CFGSaveCB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
    int						numRows, numColumns;
    int 					TabPanelHandle; 
	int                 	error = 0;	
	char					dir[MAX_PATHNAME_LEN], filePath[MAX_PATHNAME_LEN]; 

	switch (event)
	{
		case EVENT_COMMIT:
			GetPanelHandleFromTabPage (DIO6515ConfigPanelHandle, DIO_PNL_DIO6515_CFG_TAB, TAB_PAGE_TWO, &TabPanelHandle);
		    //Fill ring control options
		    errChk(GetNumTableRows(TabPanelHandle, DYN_6515_TABLE_DIO_CONFIG, &numRows));
			errChk(GetNumTableColumns(TabPanelHandle, DYN_6515_TABLE_DIO_CONFIG, &numColumns));
			
			GetSysCfgDIOTable(DIO6515ConfigPanelHandle, DIO_PNL_DIO6515_CFG_TAB , TAB_PAGE_TWO, DYN_6515_TABLE_DIO_CONFIG, DIO6515DeviceNum1);
			
		    GetProjectDir(dir);
		    ///LoadSystemConfiguration(SYSCFG_PNL);
			sprintf(filePath, "%s%s", dir,"\\Configuration\\DIO6515Definition.xml");
			CreateBackUpCopy(filePath);
			SaveDIOCfgDIOTableValue(numRows, DIO6515DeviceNum1);
			WriteDIOCfgTableValue(numRows, filePath, DIO6515DeviceNum1);
			
			DisplayDIO6515Control(0, 1);
			break;
		case EVENT_KEYPRESS:

			break;
	}
Error:
	
	return error;
}


/********************************************//**
*  DIO 6515 panel 2 Save Callback          
***********************************************/
int CVICALLBACK DIO6515CFGSaveCB_2 (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
    int						numRows, numColumns;
    int 					TabPanelHandle1; 
	int                 	error = 0;	
	char					dir[MAX_PATHNAME_LEN], filePath[MAX_PATHNAME_LEN]; 

	
	switch (event)
	{
		case EVENT_COMMIT:
			GetPanelHandleFromTabPage (DIO6515ConfigPanelHandle, DIO_PNL_DIO6515_CFG_TAB, TAB_PAGE_FOUR, &TabPanelHandle1);
		    //Fill ring control options

			errChk(GetNumTableRows(TabPanelHandle1, DYN_6515_TABLE_DIO2_CONFIG, &numRows));
			errChk(GetNumTableColumns(TabPanelHandle1, DYN_6515_TABLE_DIO2_CONFIG, &numColumns));
			
			GetSysCfgDIOTable(DIO6515ConfigPanelHandle, DIO_PNL_DIO6515_CFG_TAB , TAB_PAGE_FOUR, DYN_6515_TABLE_DIO2_CONFIG, DIO6515DeviceNum2);
			
		    GetProjectDir(dir);
			
			sprintf(filePath, "%s%s", dir,"\\Configuration\\DIO6515Definition2.xml");
			CreateBackUpCopy(filePath);
			SaveDIOCfgDIOTableValue(numRows, DIO6515DeviceNum2);
			WriteDIOCfgTableValue(numRows, filePath, DIO6515DeviceNum2);
			
			DisplayDIO6515Control(1, 1);
			break;
	}
Error:
	
	return error;
}

/********************************************//**
*  DIO 6515 display control          
***********************************************/
void DisplayDIO6515Control(int firstTab, int editConfig)
{
	int 					TabPanelHandle, TabPanelHandle1;
	
	if(editConfig)
	{
		if(firstTab) SetActiveTabPage (DIO6515ConfigPanelHandle, DIO_PNL_DIO6515_CFG_TAB, 0);
		DisplayDIOCfg(DIO6515ConfigPanelHandle, DIO_PNL_DIO6515_CFG_TAB, TAB_PAGE_ONE, TREE_TAB_DIO_TREE, DIO6515DeviceNum1, 63);
		DisplayDIOCfg(DIO6515ConfigPanelHandle, DIO_PNL_DIO6515_CFG_TAB, TAB_PAGE_THREE, TREE_TAB2_DIO_TREE2, DIO6515DeviceNum2, 63);
	
		DisplaySysCfgDIOTable(DIO6515ConfigPanelHandle, DIO_PNL_DIO6515_CFG_TAB, TAB_PAGE_TWO,DYN_6515_TABLE_DIO_CONFIG, DIO6515DeviceNum1); 
		DisplaySysCfgDIOTable(DIO6515ConfigPanelHandle, DIO_PNL_DIO6515_CFG_TAB, TAB_PAGE_FOUR,DYN_6515_TABLE_DIO2_CONFIG, DIO6515DeviceNum2);
		
		SetTabPageAttribute(DIO6515ConfigPanelHandle, DIO_PNL_DIO6515_CFG_TAB, TAB_PAGE_TWO, ATTR_VISIBLE, 1);
		SetTabPageAttribute(DIO6515ConfigPanelHandle, DIO_PNL_DIO6515_CFG_TAB, TAB_PAGE_FOUR, ATTR_VISIBLE, 1);
		
		GetPanelHandleFromTabPage (DIO6515ConfigPanelHandle, DIO_PNL_DIO6515_CFG_TAB, TAB_PAGE_TWO, &TabPanelHandle);
		GetPanelHandleFromTabPage (DIO6515ConfigPanelHandle, DIO_PNL_DIO6515_CFG_TAB, TAB_PAGE_FOUR, &TabPanelHandle1);
		SetCtrlAttribute (TabPanelHandle, TABLE_TAB_DIO6515_CFG_SAVE, ATTR_DIMMED , 0);
		SetCtrlAttribute (TabPanelHandle1, TABLE_TAB2_DIO6515_CFG_SAVE_2, ATTR_DIMMED , 0);
	}
	else
	{
		if(firstTab) SetActiveTabPage (DIO6515ConfigPanelHandle, DIO_PNL_DIO6515_CFG_TAB, 0);
		DisplayDIOCfg(DIO6515ConfigPanelHandle, DIO_PNL_DIO6515_CFG_TAB, TAB_PAGE_ONE, TREE_TAB_DIO_TREE, DIO6515DeviceNum1, 31);
		DisplayDIOCfg(DIO6515ConfigPanelHandle, DIO_PNL_DIO6515_CFG_TAB, TAB_PAGE_THREE, TREE_TAB2_DIO_TREE2, DIO6515DeviceNum2, 31);
	
		DisplaySysCfgDIOTable(DIO6515ConfigPanelHandle, DIO_PNL_DIO6515_CFG_TAB, TAB_PAGE_TWO,DYN_6515_TABLE_DIO_CONFIG, DIO6515DeviceNum1); 
		DisplaySysCfgDIOTable(DIO6515ConfigPanelHandle, DIO_PNL_DIO6515_CFG_TAB, TAB_PAGE_FOUR,DYN_6515_TABLE_DIO2_CONFIG, DIO6515DeviceNum2);
		
		///SetTabPageAttribute(DIO6515ConfigPanelHandle, DIO_PNL_DIO6515_CFG_TAB, TAB_PAGE_TWO, ATTR_VISIBLE, 0);
		///SetTabPageAttribute(DIO6515ConfigPanelHandle, DIO_PNL_DIO6515_CFG_TAB, TAB_PAGE_FOUR, ATTR_VISIBLE, 0);
		GetPanelHandleFromTabPage (DIO6515ConfigPanelHandle, DIO_PNL_DIO6515_CFG_TAB, TAB_PAGE_TWO, &TabPanelHandle);
		GetPanelHandleFromTabPage (DIO6515ConfigPanelHandle, DIO_PNL_DIO6515_CFG_TAB, TAB_PAGE_FOUR, &TabPanelHandle1);
		SetCtrlAttribute (TabPanelHandle, TABLE_TAB_DIO6515_CFG_SAVE, ATTR_DIMMED , 1);
		SetCtrlAttribute (TabPanelHandle1, TABLE_TAB2_DIO6515_CFG_SAVE_2, ATTR_DIMMED , 1);
	}
}

/********************************************//**
*  DIO 6515 create table to be displayed on the panel       
***********************************************/
void CreateDigitalIO6515ConfigurationTable()
{
	int 		TabPanelHandle;
// -----------------------------------------------------------------------------------------------------------------------	
	Ptr_DIO_CONFIG_TableParameters=&DIO_CONFIG_TableParameters;
	Ptr_DIO_CONFIG_ColumnParameters=DIO_CONFIG_ColumnParameters; 

	GetPanelHandleFromTabPage (DIO6515ConfigPanelHandle, DIO_PNL_DIO6515_CFG_TAB, TAB_PAGE_TWO, &TabPanelHandle);

	DIO_CONFIG_TableRowsandColumns.Num_of_Rows = DIO6515_NUMBER_OF_ROWS;
		
	DIO_CONFIG_TableRowsandColumns.Num_of_Columns = DIO6515_NUMBER_OF_COLUMNS; 
	
	SetCtrlVal (TabPanelHandle, DIO_PNL_DIO6515_CFG_TAB, DIO_CONFIG_TableRowsandColumns.Num_of_Rows);
	
	if(DIO_CONFIG_TableRowsandColumns.Num_of_Rows>0)
	{
		LIB_CreateTableParam(Ptr_DIO_CONFIG_TableParameters,10,500,1255,30,10,
							  DIO_CONFIG_TableRowsandColumns.Num_of_Rows,0);
    	DYN_6515_TABLE_DIO_CONFIG=LIB_CreatTableControl(Ptr_DIO_CONFIG_TableParameters, TabPanelHandle, 
    												 "SystemConfiguration.c", DYN_6515_TABLE_DIO_CONFIG);
    
    }
    else
    {
		LIB_CreateTableParam(Ptr_DIO_CONFIG_TableParameters,50,500,1000,30,10,DIO_CONFIG_ROW_INDEX_CONSTANT,0);
	   	DYN_6515_TABLE_DIO_CONFIG=LIB_CreatTableControl(Ptr_DIO_CONFIG_TableParameters,TabPanelHandle, 
	   												 "SystemConfiguration.c", DYN_6515_TABLE_DIO_CONFIG);
    }

//  CREATE TABLE COLUMN	
//===================================================================================================================
	LIB_CreateTableColumnParam(Ptr_DIO_CONFIG_ColumnParameters,0,-1,1,1,80,"DIO Channel Index",1);
	LIB_DYNInsertTableColumns(Ptr_DIO_CONFIG_ColumnParameters, Ptr_DIO_CONFIG_TableParameters,
							   TabPanelHandle, "SystemConfiguration.c", DYN_6515_TABLE_DIO_CONFIG,1);//char  where Number Type int/Double = 0, char = 1
//===================================================================================================================	
	LIB_CreateTableColumnParam(Ptr_DIO_CONFIG_ColumnParameters,1,-1,2,1,200,"DIO Name",0);
	LIB_DYNInsertTableColumns(Ptr_DIO_CONFIG_ColumnParameters, Ptr_DIO_CONFIG_TableParameters,
							   TabPanelHandle, "SystemConfiguration.c", DYN_6515_TABLE_DIO_CONFIG,2); //char
//===================================================================================================================	
	LIB_CreateTableColumnParam(Ptr_DIO_CONFIG_ColumnParameters,2,-1,3,1,200,"DIO Channel Name",0);
	LIB_DYNInsertTableColumns(Ptr_DIO_CONFIG_ColumnParameters, Ptr_DIO_CONFIG_TableParameters,
							   TabPanelHandle, "SystemConfiguration.c", DYN_6515_TABLE_DIO_CONFIG,3);//char
//===================================================================================================================	
	LIB_CreateTableColumnParam(Ptr_DIO_CONFIG_ColumnParameters,3,-1,4,1,100,"DIO Input Configuration",0);
	LIB_DYNInsertTableColumns(Ptr_DIO_CONFIG_ColumnParameters, Ptr_DIO_CONFIG_TableParameters,
							   TabPanelHandle, "SystemConfiguration.c", DYN_6515_TABLE_DIO_CONFIG,4);//char
//===================================================================================================================	
	LIB_CreateTableColumnParam(Ptr_DIO_CONFIG_ColumnParameters,4,-1,5,1,100,"DIO Port",0);
	LIB_DYNInsertTableColumns(Ptr_DIO_CONFIG_ColumnParameters, Ptr_DIO_CONFIG_TableParameters,
							   TabPanelHandle, "SystemConfiguration.c", DYN_6515_TABLE_DIO_CONFIG,5);//char
//===================================================================================================================
	LIB_CreateTableColumnParam(Ptr_DIO_CONFIG_ColumnParameters,5,-1,6,1,100,"DIO Bit",0);
	LIB_DYNInsertTableColumns(Ptr_DIO_CONFIG_ColumnParameters, Ptr_DIO_CONFIG_TableParameters,
							   TabPanelHandle, "SystemConfiguration.c", DYN_6515_TABLE_DIO_CONFIG,6);//char
//===================================================================================================================
	LIB_CreateTableColumnParam(Ptr_DIO_CONFIG_ColumnParameters,6,-1,7,1,80,"DIO Test Status",0);
	LIB_DYNInsertTableColumns(Ptr_DIO_CONFIG_ColumnParameters, Ptr_DIO_CONFIG_TableParameters,
							   TabPanelHandle, "SystemConfiguration.c", DYN_6515_TABLE_DIO_CONFIG,7);//char					  
//===================================================================================================================
	LIB_CreateTableColumnParam(Ptr_DIO_CONFIG_ColumnParameters,7,-1,8,1,130,"DIO Timeout",0);
	LIB_DYNInsertTableColumns(Ptr_DIO_CONFIG_ColumnParameters, Ptr_DIO_CONFIG_TableParameters,
							   TabPanelHandle, "SystemConfiguration.c", DYN_6515_TABLE_DIO_CONFIG,8);//char
//===================================================================================================================	
	LIB_CreateTableColumnParam(Ptr_DIO_CONFIG_ColumnParameters,8,-1,9,1,100,"DIO Repeat",1);
	LIB_DYNInsertTableColumns(Ptr_DIO_CONFIG_ColumnParameters, Ptr_DIO_CONFIG_TableParameters,
							   TabPanelHandle, "SystemConfiguration.c", DYN_6515_TABLE_DIO_CONFIG,9);//char
//===================================================================================================================
	LIB_CreateTableColumnParam(Ptr_DIO_CONFIG_ColumnParameters,9,-1,10,1,100,"DIO Wire Tag",0);
	LIB_DYNInsertTableColumns(Ptr_DIO_CONFIG_ColumnParameters, Ptr_DIO_CONFIG_TableParameters,
							   TabPanelHandle, "SystemConfiguration.c", DYN_6515_TABLE_DIO_CONFIG,10);//char
//===================================================================================================================	
	SetCtrlAttribute(TabPanelHandle, TABLE_TAB_NUM_COLUMNS,ATTR_NO_EDIT_TEXT,0);
	SetCtrlVal (TabPanelHandle, TABLE_TAB_NUM_COLUMNS, ((Ptr_DIO_CONFIG_ColumnParameters+9))->NumberofColumns);
	SetCtrlAttribute(TabPanelHandle, TABLE_TAB_NUM_COLUMNS,ATTR_NO_EDIT_TEXT,1);
	SetCtrlAttribute(TabPanelHandle, TABLE_TAB_NUM_COLUMNS,ATTR_SHOW_INCDEC_ARROWS,0);
}

/********************************************//**
*  DIO 6515 Create table to display on the panel (tab2)        
***********************************************/
void CreateDigitalIO6515ConfigurationTable2()
{
	int 		TabPanelHandle1;
// -----------------------------------------------------------------------------------------------------------------------	
	Ptr_DIO2_CONFIG_TableParameters=&DIO2_CONFIG_TableParameters;
	Ptr_DIO2_CONFIG_ColumnParameters=DIO2_CONFIG_ColumnParameters; 

	GetPanelHandleFromTabPage (DIO6515ConfigPanelHandle, DIO_PNL_DIO6515_CFG_TAB, TAB_PAGE_FOUR, &TabPanelHandle1);

	DIO2_CONFIG_TableRowsandColumns.Num_of_Rows = DIO6515_NUMBER_OF_ROWS;
		
	DIO2_CONFIG_TableRowsandColumns.Num_of_Columns = DIO6515_NUMBER_OF_COLUMNS;   
	
	
	SetCtrlVal (TabPanelHandle1, DIO_PNL_DIO6515_CFG_TAB, DIO2_CONFIG_TableRowsandColumns.Num_of_Rows);
	
	if(DIO2_CONFIG_TableRowsandColumns.Num_of_Rows>0)
	{
		LIB_CreateTableParam(Ptr_DIO2_CONFIG_TableParameters,10,500,1255,30,10,
							  DIO2_CONFIG_TableRowsandColumns.Num_of_Rows,0);
    	DYN_6515_TABLE_DIO2_CONFIG=LIB_CreatTableControl(Ptr_DIO2_CONFIG_TableParameters, TabPanelHandle1, 
    												 "SystemConfiguration.c", DYN_6515_TABLE_DIO2_CONFIG);
    
    }
    else
    {
		LIB_CreateTableParam(Ptr_DIO2_CONFIG_TableParameters,50,500,1000,30,10,DIO_CONFIG_ROW_INDEX_CONSTANT,0);
	   	DYN_6515_TABLE_DIO2_CONFIG=LIB_CreatTableControl(Ptr_DIO2_CONFIG_TableParameters,TabPanelHandle1, 
	   												 "SystemConfiguration.c", DYN_6515_TABLE_DIO2_CONFIG);
    	
    }

//  CREATE TABLE COLUMN	
//===================================================================================================================
	LIB_CreateTableColumnParam(Ptr_DIO2_CONFIG_ColumnParameters,0,-1,1,1,80,"DIO Channel Index",1);
	LIB_DYNInsertTableColumns(Ptr_DIO2_CONFIG_ColumnParameters, Ptr_DIO2_CONFIG_TableParameters,
							   TabPanelHandle1, "SystemConfiguration.c", DYN_6515_TABLE_DIO2_CONFIG,1);//char  where Number Type int/Double = 0, char = 1
//===================================================================================================================	
	LIB_CreateTableColumnParam(Ptr_DIO2_CONFIG_ColumnParameters,1,-1,2,1,200,"DIO Name",0);
	LIB_DYNInsertTableColumns(Ptr_DIO2_CONFIG_ColumnParameters, Ptr_DIO2_CONFIG_TableParameters,
							   TabPanelHandle1, "SystemConfiguration.c", DYN_6515_TABLE_DIO2_CONFIG,2); //char
//===================================================================================================================	
	LIB_CreateTableColumnParam(Ptr_DIO2_CONFIG_ColumnParameters,2,-1,3,1,200,"DIO Channel Name",0);
	LIB_DYNInsertTableColumns(Ptr_DIO2_CONFIG_ColumnParameters, Ptr_DIO2_CONFIG_TableParameters,
							   TabPanelHandle1, "SystemConfiguration.c", DYN_6515_TABLE_DIO2_CONFIG,3);//char
//===================================================================================================================	
	LIB_CreateTableColumnParam(Ptr_DIO2_CONFIG_ColumnParameters,3,-1,4,1,100,"DIO Input Configuration",0);
	LIB_DYNInsertTableColumns(Ptr_DIO2_CONFIG_ColumnParameters, Ptr_DIO2_CONFIG_TableParameters,
							   TabPanelHandle1, "SystemConfiguration.c", DYN_6515_TABLE_DIO2_CONFIG,4);//char
//===================================================================================================================	
	LIB_CreateTableColumnParam(Ptr_DIO2_CONFIG_ColumnParameters,4,-1,5,1,100,"DIO Port",0);
	LIB_DYNInsertTableColumns(Ptr_DIO2_CONFIG_ColumnParameters, Ptr_DIO2_CONFIG_TableParameters,
							   TabPanelHandle1, "SystemConfiguration.c", DYN_6515_TABLE_DIO2_CONFIG,5);//char
//===================================================================================================================
	LIB_CreateTableColumnParam(Ptr_DIO2_CONFIG_ColumnParameters,5,-1,6,1,100,"DIO Bit",0);
	LIB_DYNInsertTableColumns(Ptr_DIO2_CONFIG_ColumnParameters, Ptr_DIO2_CONFIG_TableParameters,
							   TabPanelHandle1, "SystemConfiguration.c", DYN_6515_TABLE_DIO2_CONFIG,6);//char
//===================================================================================================================
	LIB_CreateTableColumnParam(Ptr_DIO2_CONFIG_ColumnParameters,6,-1,7,1,80,"DIO Test Status",0);
	LIB_DYNInsertTableColumns(Ptr_DIO2_CONFIG_ColumnParameters, Ptr_DIO2_CONFIG_TableParameters,
							   TabPanelHandle1, "SystemConfiguration.c", DYN_6515_TABLE_DIO2_CONFIG,7);//char					  
//===================================================================================================================
	LIB_CreateTableColumnParam(Ptr_DIO2_CONFIG_ColumnParameters,7,-1,8,1,130,"DIO Timeout",0);
	LIB_DYNInsertTableColumns(Ptr_DIO2_CONFIG_ColumnParameters, Ptr_DIO2_CONFIG_TableParameters,
							   TabPanelHandle1, "SystemConfiguration.c", DYN_6515_TABLE_DIO2_CONFIG,8);//char
//===================================================================================================================	
	LIB_CreateTableColumnParam(Ptr_DIO2_CONFIG_ColumnParameters,8,-1,9,1,100,"DIO Repeat",1);
	LIB_DYNInsertTableColumns(Ptr_DIO2_CONFIG_ColumnParameters, Ptr_DIO2_CONFIG_TableParameters,
							   TabPanelHandle1, "SystemConfiguration.c", DYN_6515_TABLE_DIO2_CONFIG,9);//char
//===================================================================================================================
	LIB_CreateTableColumnParam(Ptr_DIO2_CONFIG_ColumnParameters,9,-1,10,1,100,"DIO Wire Tag",0);
	LIB_DYNInsertTableColumns(Ptr_DIO2_CONFIG_ColumnParameters, Ptr_DIO2_CONFIG_TableParameters,
							   TabPanelHandle1, "SystemConfiguration.c", DYN_6515_TABLE_DIO2_CONFIG,10);//char
//===================================================================================================================	
	SetCtrlAttribute(TabPanelHandle1, TABLE_TAB2_NUM_COLUMNS,ATTR_NO_EDIT_TEXT,0);
	SetCtrlVal (TabPanelHandle1, TABLE_TAB2_NUM_COLUMNS, ((Ptr_DIO2_CONFIG_ColumnParameters+9))->NumberofColumns);
	SetCtrlAttribute(TabPanelHandle1, TABLE_TAB2_NUM_COLUMNS,ATTR_NO_EDIT_TEXT,1);
	SetCtrlAttribute(TabPanelHandle1, TABLE_TAB2_NUM_COLUMNS,ATTR_SHOW_INCDEC_ARROWS,0);
}

/********************************************//**
*  DIO 6515 Insert new row Callback          
***********************************************/
int CVICALLBACK DIOInsertRowCB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			break;
		case EVENT_KEYPRESS:

			break;
	}
	return 0;
}

/********************************************//**
*  DIO 6515 Delete row Callback          
***********************************************/
int CVICALLBACK DIODeleteRowCB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			break;
		case EVENT_KEYPRESS:

			break;
	}
	return 0;
}

