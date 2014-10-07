/***********************************************************************
 *
 *
 *  COPYRIGHT: Arxtron Technologies Inc. All Rights Reserved.
 *
 *  PURPOSE:  
 *            
 *            
 *            
 *
 *
 *  DEVELOPMENT HISTORY:
 *
 *  Date        Name           Rev.   Description
 *  ----------  -------------  -----  -----------------------
 *  05-15-2013  Arxtron        1      Initial Release
 *  
 *  
 *********************************************************************/ 
/*!
*    @file    SystemConfiguration.c
*    @brief   Function related to System configuration panel
*    @author  Arxtron Technologies Inc.
*    @date    2013.9.6
*    Function to save, parse and display the system configuration info in the panel 
*    
*/


/*---------------------------------------------------------------------------*/   
/* Include files                                                             */   
/*---------------------------------------------------------------------------*/   
#include <cvirte.h>		
#include <userint.h>
#include "Global.h"

#include "DataLib.h" 
#include "SystemConfiguration.h"
#include "SystemConfiguration_Def.h"

//********************************************************************************************************************
#if USE_EXT_MAIN_PROJ 

#else  
//********************************************************************************************************************

//int main (int argc, char *argv[])
//{
//	char					dir[MAX_PATHNAME_LEN], uirPath[MAX_PATHNAME_LEN]; 
//	CVIXMLElement rootElement;
//	
//	if (InitCVIRTE (0, argv, 0) == 0)
//		return -1;	/* out of memory */
//	if ((SystemPanelHandle = LoadPanel (0, "SystemConfiguration.uir", SYSCFG_PNL)) < 0)
//		return -1;
//	
//	GetProjectDir(dir);
//	sprintf(uirPath, "%s%s", dir,"\\Configuration\\gMiscellaneous.xml");
//	rootElement = LoadConfigurationDocument(uirPath);
//	ParseXMLDocument(rootElement, 0);
//	CreateMiscConfigurationTable();
//	DisplaySysControl(1);
//	
//	DisplayPanel (SystemPanelHandle);
//	RunUserInterface ();
//	DiscardPanel (SystemPanelHandle);
//	return 0;
//}
#endif
//********************************************************************************************************************

int CVICALLBACK SysMiscCfgTabCB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	return 0;
}
//********************************************************************************************************************
int CVICALLBACK SYSCFGExitCB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
				//#if USE_EXT_MAIN_PROJ
					CheckError(HidePanel(SystemPanelHandle)); 
				//#else		
				//	QuitUserInterface (0);
				//#endif
			break;
	}
	return 0;
}
//********************************************************************************************************************
int CVICALLBACK SYSDeleteRowCB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			QuitUserInterface (0);
			break;
	}
	return 0;
}
//********************************************************************************************************************
int CVICALLBACK SYSInsertRowCB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			QuitUserInterface (0);
			break;
	}
	return 0;
}
//********************************************************************************************************************
int CVICALLBACK MISCCFGSaveCB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
    int						numRows, numColumns;
    int 					TabPanelHandle; 
	int                 	error = 0;	
	char					dir[MAX_PATHNAME_LEN], filePath[MAX_PATHNAME_LEN]; 

	switch (event)
	{
		case EVENT_COMMIT:
			GetPanelHandleFromTabPage (SystemPanelHandle, SYSCFG_PNL_SYS_CFG_TAB, TAB_PAGE_TWO, &TabPanelHandle);
		    //Fill ring control options

			errChk(GetNumTableRows(TabPanelHandle, DYN_TABLE_MISC_CONFIG, &numRows));
			errChk(GetNumTableColumns(TabPanelHandle, DYN_TABLE_MISC_CONFIG, &numColumns));
			
			GetSysCfgMiscTable(SystemPanelHandle, SYSCFG_PNL_SYS_CFG_TAB , TAB_PAGE_TWO, DYN_TABLE_MISC_CONFIG);
			
		    GetProjectDir(dir);
			
			sprintf(filePath, "%s%s", dir,"\\Configuration\\gMiscellaneous.xml");
			CreateBackUpCopy(filePath);
			SaveSysCfgMiscTableValue(numRows);
			WriteSysCfgMiscTableValue(numRows, filePath);
			
			DisplaySysControl(1);

			break;
	}
Error:
	
	return error;
}
/********************************************//**
* display system configuration control
***********************************************/
//********************************************************************************************************************
void DisplaySysControl(int firstTab) 
{
	//char strTemp[100];
	
	if(firstTab) SetActiveTabPage (SystemPanelHandle, SYSCFG_PNL_SYS_CFG_TAB, 0);
	DisplaygMisc(SystemPanelHandle, SYSCFG_PNL_SYS_CFG_TAB, TAB_PAGE_ONE, TREE_TAB_MISC_TREE, 79);
	DisplaySysCfgMiscTable(SystemPanelHandle, SYSCFG_PNL_SYS_CFG_TAB, TAB_PAGE_TWO,DYN_TABLE_MISC_CONFIG);
}
//********************************************************************************************************************
/********************************************//**
* Create system configuration table
***********************************************/
void CreateMiscConfigurationTable()
{
	char tmpStr[100];

	int 		TabPanelHandle;
// -----------------------------------------------------------------------------------------------------------------------	
	Ptr_MISC_CONFIG_TableParameters=&MSCI_CONFIG_TableParameters;
	Ptr_MISC_CONFIG_ColumnParameters=MSCI_CONFIG_ColumnParameters; 

	GetPanelHandleFromTabPage (SystemPanelHandle, SYSCFG_PNL_SYS_CFG_TAB, TAB_PAGE_TWO, &TabPanelHandle);

	strcpy(tmpStr, GetCfgMiscValue("MiscTableRow",80));
	Scan(tmpStr,"%d",&MISC_CONFIG_TableRowsandColumns.Num_of_Rows);
	
	strcpy(tmpStr, GetCfgMiscValue("MiscTableColumn",80));
	Scan(tmpStr,"%d",&MISC_CONFIG_TableRowsandColumns.Num_of_Columns);
	
	SetCtrlVal (TabPanelHandle, SYSCFG_PNL_SYS_CFG_TAB, MISC_CONFIG_TableRowsandColumns.Num_of_Rows);
	
	
	if(MISC_CONFIG_TableRowsandColumns.Num_of_Rows>0)
	{
		LIB_CreateTableParam(Ptr_MISC_CONFIG_TableParameters,10,500,670,30,10,
							 MISC_CONFIG_TableRowsandColumns.Num_of_Rows,0);
    	DYN_TABLE_MISC_CONFIG=LIB_CreatTableControl(Ptr_MISC_CONFIG_TableParameters, TabPanelHandle, 
    												 "SystemConfiguration.c", DYN_TABLE_MISC_CONFIG);
    }
    else
    {
		LIB_CreateTableParam(Ptr_MISC_CONFIG_TableParameters,50,500,670,30,10,AI_CONFIG_ROW_INDEX_CONSTANT,0);
	   	DYN_TABLE_MISC_CONFIG=LIB_CreatTableControl(Ptr_MISC_CONFIG_TableParameters,TabPanelHandle, 
	   												 "SystemConfiguration.c", DYN_TABLE_MISC_CONFIG);
    }

//  CREATE TABLE COLUMN	
//===================================================================================================================
	LIB_CreateTableColumnParam(Ptr_MISC_CONFIG_ColumnParameters,0,-1,1,1,300,"Misc. Name",1);
	LIB_DYNInsertTableColumns(Ptr_MISC_CONFIG_ColumnParameters, Ptr_MISC_CONFIG_TableParameters,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_MISC_CONFIG,1);//char  where Number Type int/Double = 0, char = 1
//===================================================================================================================	
	LIB_CreateTableColumnParam(Ptr_MISC_CONFIG_ColumnParameters,1,-1,2,1,300,"Misc. Value",0);
	LIB_DYNInsertTableColumns(Ptr_MISC_CONFIG_ColumnParameters, Ptr_MISC_CONFIG_TableParameters,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_MISC_CONFIG,2); //char
//===================================================================================================================	
	SetCtrlAttribute(TabPanelHandle, MIS_TB_TAB_NUM_COLUMNS,ATTR_NO_EDIT_TEXT,0);
	SetCtrlVal (TabPanelHandle, MIS_TB_TAB_NUM_COLUMNS, ((Ptr_MISC_CONFIG_ColumnParameters+9))->NumberofColumns);
	SetCtrlAttribute(TabPanelHandle, MIS_TB_TAB_NUM_COLUMNS,ATTR_NO_EDIT_TEXT,1);
	SetCtrlAttribute(TabPanelHandle, MIS_TB_TAB_NUM_COLUMNS,ATTR_SHOW_INCDEC_ARROWS,0);
}
//*******************************************************************************************************************
