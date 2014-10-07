/***********************************************************************
 *
 *
 *  COPYRIGHT: Arxtron Technologies Inc. All Rights Reserved.
 *
 *
 *  PURPOSE: - uir callback for the DAQ 6220 interface   
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
*    @file    MIO6220.c
*    @brief   Configuration for MIO 6220 card
*    @author  Arxtron Technologies Inc.
*    @date    2013.9.6
*    Functions to configure MIO 6220   
*    
*/ 

#include <cvirte.h>		
#include <userint.h>
#include "Global.h"
#include "MIO6220.h"
#include "MIO6220Def.h"
#include "DataLib.h"
//*******************************************************************************************************************
int CVICALLBACK MIOCFGExitCB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
						
						//#if USE_EXT_MAIN_PROJ
							DIOViewMenu=0;
							///EnableDIOControlSaving();
							CheckError(HidePanel(MIOPanelHandle)); 
						//#else		
						//	QuitUserInterface (0);
					//	#endif
						
			break;
		case EVENT_KEYPRESS:

			break;
	}
	return 0;
}
//*******************************************************************************************************************
int CVICALLBACK AICfgTabCB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_KEYPRESS:

			break;
		case EVENT_ACTIVE_TAB_CHANGE:

			 if((eventData2 == 1) && (!DIOViewMenu))  // eventData2 => Currently Selected TabPage  eventData1 => Previously Selected TabPage
			 {
				 PWD_KeyPress_Loc=0;
				 
			 }
			break;
			
	}
	return 0;
}
//*******************************************************************************************************************
int CVICALLBACK AICfgTab2CB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_KEYPRESS:

			break;
		case EVENT_ACTIVE_TAB_CHANGE:

			 if((eventData2 == 1) && (!DIOViewMenu))  // eventData2 => Currently Selected TabPage  eventData1 => Previously Selected TabPage
			 {
				 PWD_KeyPress_Loc=0;
				 
			 }
			break;
			
	}
	return 0;
}

//*******************************************************************************************************************
int CVICALLBACK AICFGSaveCB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
    int						numRows, numColumns;
    int 					TabPanelHandle; 
	int                 	error = 0;	
	char					dir[MAX_PATHNAME_LEN], filePath[MAX_PATHNAME_LEN]; 

	switch (event)
	{
		case EVENT_COMMIT:
			GetPanelHandleFromTabPage (MIOPanelHandle, MIO_PNL_MIO_CFG_TAB, TAB_PAGE_TWO, &TabPanelHandle);
		    //Fill ring control options
		    errChk(GetNumTableRows(TabPanelHandle, DYN_TABLE_AI_CONFIG, &numRows));
			errChk(GetNumTableColumns(TabPanelHandle, DYN_TABLE_AI_CONFIG, &numColumns));
			
			GetSysCfgAITable(MIOPanelHandle, MIO_PNL_MIO_CFG_TAB , TAB_PAGE_TWO, DYN_TABLE_AI_CONFIG, MIO6220DeviceNum1);
			
		    GetProjectDir(dir);
		    ///LoadSystemConfiguration(SYSCFG_PNL);
			sprintf(filePath, "%s%s", dir,"\\Configuration\\MIOAIDefinition.xml");
			CreateBackUpCopy(filePath);
			SaveAICfgDIOTableValue(numRows, MIO6220DeviceNum1);
			WriteAICfgTableValue(numRows, filePath, MIO6220DeviceNum1);
			
			DisplayMIOControl(1, 1);
			break;
		case EVENT_KEYPRESS:

			break;
	}
Error:
	
	return error;
}
//********************************************************************************************************************
int CVICALLBACK AICFGSave2CB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
    int						numRows, numColumns;
    int 					TabPanelHandle; 
	int                 	error = 0;	
	char					dir[MAX_PATHNAME_LEN], filePath[MAX_PATHNAME_LEN]; 

	switch (event)
	{
		case EVENT_COMMIT:
			GetPanelHandleFromTabPage (MIOPanelHandle2, MIO_PNL_2_MIO_CFG_TAB_2, TAB_PAGE_TWO, &TabPanelHandle);
		    //Fill ring control options
		    errChk(GetNumTableRows(TabPanelHandle, DYN_TABLE_AI_CONFIG_2, &numRows));
			errChk(GetNumTableColumns(TabPanelHandle, DYN_TABLE_AI_CONFIG_2, &numColumns));
			
			GetSysCfgAITable(MIOPanelHandle2, MIO_PNL_2_MIO_CFG_TAB_2 , TAB_PAGE_TWO, DYN_TABLE_AI_CONFIG_2, MIO6220DeviceNum2);
			
		    GetProjectDir(dir);
		    ///LoadSystemConfiguration(SYSCFG_PNL);
			sprintf(filePath, "%s%s", dir,"\\Configuration\\MIOAIDefinition2.xml");
			CreateBackUpCopy(filePath);
			SaveAICfgDIOTableValue(numRows, MIO6220DeviceNum2);
			WriteAICfgTableValue(numRows, filePath, MIO6220DeviceNum2);
			
			DisplayMIOControl2(1, 1);
			break;
		case EVENT_KEYPRESS:

			break;
	}
Error:
	
	return error;
}
//********************************************************************************************************************
int CVICALLBACK AOCFGSaveCB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
    int						numRows, numColumns;
    int 					TabPanelHandle; 
	int                 	error = 0;	
	char					dir[MAX_PATHNAME_LEN], filePath[MAX_PATHNAME_LEN]; 

	
	switch (event)
	{
		case EVENT_COMMIT:
			GetPanelHandleFromTabPage (MIOPanelHandle, MIO_PNL_MIO_CFG_TAB, TAB_PAGE_FOUR, &TabPanelHandle);
		    //Fill ring control options

			errChk(GetNumTableRows(TabPanelHandle, DYN_TABLE_AO_CONFIG, &numRows));
			errChk(GetNumTableColumns(TabPanelHandle, DYN_TABLE_AO_CONFIG, &numColumns));
			
			GetSysCfgAOTable(MIOPanelHandle, MIO_PNL_MIO_CFG_TAB , TAB_PAGE_FOUR, DYN_TABLE_AO_CONFIG, MIO6220DeviceNum1);
			
		    GetProjectDir(dir);
			
			sprintf(filePath, "%s%s", dir,"\\Configuration\\MIOAODefinition.xml");
			CreateBackUpCopy(filePath);
			SaveAOCfgDIOTableValue(numRows, MIO6220DeviceNum1);
			WriteAOCfgTableValue(numRows, filePath, MIO6220DeviceNum1);
			
			DisplayMIOControl(1, 1);
			break;
	}
Error:
	
	return error;
}
//********************************************************************************************************************
int CVICALLBACK AOCFGSave2CB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
    int						numRows, numColumns;
    int 					TabPanelHandle; 
	int                 	error = 0;	
	char					dir[MAX_PATHNAME_LEN], filePath[MAX_PATHNAME_LEN]; 

	
	switch (event)
	{
		case EVENT_COMMIT:
			GetPanelHandleFromTabPage (MIOPanelHandle2, MIO_PNL_2_MIO_CFG_TAB_2, TAB_PAGE_FOUR, &TabPanelHandle);
		    //Fill ring control options

			errChk(GetNumTableRows(TabPanelHandle, DYN_TABLE_AO_CONFIG_2, &numRows));
			errChk(GetNumTableColumns(TabPanelHandle, DYN_TABLE_AO_CONFIG_2, &numColumns));
			
			GetSysCfgAOTable(MIOPanelHandle, MIO_PNL_MIO_CFG_TAB , TAB_PAGE_FOUR, DYN_TABLE_AO_CONFIG_2, MIO6220DeviceNum2);
			
		    GetProjectDir(dir);
			
			sprintf(filePath, "%s%s", dir,"\\Configuration\\MIOAODefinition2.xml");
			CreateBackUpCopy(filePath);
			SaveAOCfgDIOTableValue(numRows, MIO6220DeviceNum2);
			WriteAOCfgTableValue(numRows, filePath, MIO6220DeviceNum2);
			
			DisplayMIOControl2(1, 1);
			break;
	}
Error:
	
	return error;
}
//********************************************************************************************************************
int CVICALLBACK MDIOCFGSaveCB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
    int						numRows, numColumns;
    int 					TabPanelHandle; 
	int                 	error = 0;	
	char					dir[MAX_PATHNAME_LEN], filePath[MAX_PATHNAME_LEN]; 

	switch (event)
	{
		case EVENT_COMMIT:
			GetPanelHandleFromTabPage (MIOPanelHandle, MIO_PNL_MIO_CFG_TAB, TAB_PAGE_SIX, &TabPanelHandle);
		    //Fill ring control options

			errChk(GetNumTableRows(TabPanelHandle, DYN_TABLE_MDIO_CONFIG, &numRows));
			errChk(GetNumTableColumns(TabPanelHandle, DYN_TABLE_MDIO_CONFIG, &numColumns));
			
			GetSysCfgDIOTable(MIOPanelHandle, MIO_PNL_MIO_CFG_TAB , TAB_PAGE_SIX, DYN_TABLE_MDIO_CONFIG, MIO6220DeviceNum1);
			
		    GetProjectDir(dir);
			
			sprintf(filePath, "%s%s", dir,"\\Configuration\\MIODIODefinition.xml");
			CreateBackUpCopy(filePath);
			SaveDIOCfgDIOTableValue(numRows, MIO6220DeviceNum1);
			WriteDIOCfgTableValue(numRows, filePath, MIO6220DeviceNum1);
			
			DisplayMIOControl(1, 1);
			break;
	}
Error:
	
	return error;
}
//********************************************************************************************************************
int CVICALLBACK MDIOCFGSave2CB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
    int						numRows, numColumns;
    int 					TabPanelHandle; 
	int                 	error = 0;	
	char					dir[MAX_PATHNAME_LEN], filePath[MAX_PATHNAME_LEN]; 

	switch (event)
	{
		case EVENT_COMMIT:
			GetPanelHandleFromTabPage (MIOPanelHandle, MIO_PNL_2_MIO_CFG_TAB_2, TAB_PAGE_SIX, &TabPanelHandle);
		    //Fill ring control options

			errChk(GetNumTableRows(TabPanelHandle, DYN_TABLE_MDIO_CONFIG_2, &numRows));
			errChk(GetNumTableColumns(TabPanelHandle, DYN_TABLE_MDIO_CONFIG_2, &numColumns));
			
			GetSysCfgDIOTable(MIOPanelHandle, MIO_PNL_MIO_CFG_TAB , TAB_PAGE_SIX, DYN_TABLE_MDIO_CONFIG_2, MIO6220DeviceNum2);
			
		    GetProjectDir(dir);
			
			sprintf(filePath, "%s%s", dir,"\\Configuration\\MIODIODefinition2.xml");
			CreateBackUpCopy(filePath);
			SaveDIOCfgDIOTableValue(numRows, MIO6220DeviceNum2);
			WriteDIOCfgTableValue(numRows, filePath, MIO6220DeviceNum2);
			
			DisplayMIOControl(1, 1);
			break;
	}
Error:
	
	return error;
}
//*******************************************************************************************************************
void __stdcall DisplayMIOControl(int firstTab, int editConfig) 
{

	int 					TabPanelHandle, TabPanelHandle1, TabPanelHandle2;
	
	if(editConfig)
	{
		if(firstTab) SetActiveTabPage (MIOPanelHandle, MIO_PNL_MIO_CFG_TAB, 0);
		DisplayAICfg(MIOPanelHandle, MIO_PNL_MIO_CFG_TAB, TAB_PAGE_ONE, TREE_TAB_AI_TREE, MIO6220DeviceNum1, 79);
		DisplayAOCfg(MIOPanelHandle, MIO_PNL_MIO_CFG_TAB, TAB_PAGE_THREE, TREE_TAB_AI_TREE, MIO6220DeviceNum1, MIO6220DeviceNum1);
		DisplaySysCfgAITable(MIOPanelHandle, MIO_PNL_MIO_CFG_TAB, TAB_PAGE_TWO,DYN_TABLE_AI_CONFIG, MIO6220DeviceNum1); 
		DisplaySysCfgAOTable(MIOPanelHandle, MIO_PNL_MIO_CFG_TAB, TAB_PAGE_FOUR,DYN_TABLE_AO_CONFIG, MIO6220DeviceNum1);
	
		DisplayDIOCfg(MIOPanelHandle, MIO_PNL_MIO_CFG_TAB, TAB_PAGE_FIVE, TREE_TAB3_DIO_TREE, MIO6220DeviceNum1, 23);
		DisplaySysCfgDIOTable(MIOPanelHandle, MIO_PNL_MIO_CFG_TAB, TAB_PAGE_SIX,DYN_TABLE_MDIO_CONFIG, MIO6220DeviceNum1);
		
		SetTabPageAttribute(MIOPanelHandle, MIO_PNL_MIO_CFG_TAB, TAB_PAGE_TWO, ATTR_VISIBLE, 1);
		SetTabPageAttribute(MIOPanelHandle, MIO_PNL_MIO_CFG_TAB, TAB_PAGE_FOUR, ATTR_VISIBLE, 1);
		SetTabPageAttribute(MIOPanelHandle, MIO_PNL_MIO_CFG_TAB, TAB_PAGE_SIX, ATTR_VISIBLE, 1);
		
		GetPanelHandleFromTabPage (MIOPanelHandle, MIO_PNL_MIO_CFG_TAB, TAB_PAGE_TWO, &TabPanelHandle);
		GetPanelHandleFromTabPage (MIOPanelHandle, MIO_PNL_MIO_CFG_TAB, TAB_PAGE_FOUR, &TabPanelHandle1);
		GetPanelHandleFromTabPage (MIOPanelHandle, MIO_PNL_MIO_CFG_TAB, TAB_PAGE_SIX, &TabPanelHandle2);
		
		SetCtrlAttribute (TabPanelHandle, AI_TB_TAB_AI_CFG_SAVE, ATTR_DIMMED , 0);
		SetCtrlAttribute (TabPanelHandle1, AO_TB_TAB_AO_CFG_SAVE, ATTR_DIMMED , 0);
		SetCtrlAttribute (TabPanelHandle2, MIO_TB_TAB_MDIO_CFG_SAVE, ATTR_DIMMED , 0);
	}
	else
	{
		if(firstTab) SetActiveTabPage (MIOPanelHandle, MIO_PNL_MIO_CFG_TAB, 0);
		DisplayAICfg(MIOPanelHandle, MIO_PNL_MIO_CFG_TAB, TAB_PAGE_ONE, TREE_TAB_AI_TREE, MIO6220DeviceNum1, 79);
		DisplayAOCfg(MIOPanelHandle, MIO_PNL_MIO_CFG_TAB, TAB_PAGE_THREE, TREE_TAB_AI_TREE, MIO6220DeviceNum1, MIO6220DeviceNum1);
		DisplaySysCfgAITable(MIOPanelHandle, MIO_PNL_MIO_CFG_TAB, TAB_PAGE_TWO,DYN_TABLE_AI_CONFIG, MIO6220DeviceNum1); 
		DisplaySysCfgAOTable(MIOPanelHandle, MIO_PNL_MIO_CFG_TAB, TAB_PAGE_FOUR,DYN_TABLE_AO_CONFIG, MIO6220DeviceNum1);
	
		DisplayDIOCfg(MIOPanelHandle, MIO_PNL_MIO_CFG_TAB, TAB_PAGE_FIVE, TREE_TAB3_DIO_TREE, MIO6220DeviceNum1, 23);
		DisplaySysCfgDIOTable(MIOPanelHandle, MIO_PNL_MIO_CFG_TAB, TAB_PAGE_SIX,DYN_TABLE_MDIO_CONFIG, MIO6220DeviceNum1);

		GetPanelHandleFromTabPage (MIOPanelHandle, MIO_PNL_MIO_CFG_TAB, TAB_PAGE_TWO, &TabPanelHandle);
		GetPanelHandleFromTabPage (MIOPanelHandle, MIO_PNL_MIO_CFG_TAB, TAB_PAGE_FOUR, &TabPanelHandle1);
		GetPanelHandleFromTabPage (MIOPanelHandle, MIO_PNL_MIO_CFG_TAB, TAB_PAGE_SIX, &TabPanelHandle2);
		
		SetCtrlAttribute (TabPanelHandle, AI_TB_TAB_AI_CFG_SAVE, ATTR_DIMMED , 1);
		SetCtrlAttribute (TabPanelHandle1, AO_TB_TAB_AO_CFG_SAVE, ATTR_DIMMED , 1);
		SetCtrlAttribute (TabPanelHandle2, MIO_TB_TAB_MDIO_CFG_SAVE, ATTR_DIMMED , 1);
		
	}
}
//********************************************************************************************************************
void __stdcall DisplayMIOControl2(int firstTab, int editConfig) 
{

	int 					TabPanelHandle, TabPanelHandle1, TabPanelHandle2;
	
	if(editConfig)
	{
		if(firstTab) SetActiveTabPage (MIOPanelHandle2, MIO_PNL_2_MIO_CFG_TAB_2, 0);
		DisplayAICfg(MIOPanelHandle2, MIO_PNL_2_MIO_CFG_TAB_2, TAB_PAGE_ONE, TREE_TAB_2_AI_TREE_2, MIO6220DeviceNum2, 79);
		DisplayAOCfg(MIOPanelHandle2, MIO_PNL_2_MIO_CFG_TAB_2, TAB_PAGE_THREE, TREE_TAB_2_AI_TREE_2, MIO6220DeviceNum2, MIO6220DeviceNum2);
		DisplaySysCfgAITable(MIOPanelHandle2, MIO_PNL_2_MIO_CFG_TAB_2, TAB_PAGE_TWO,DYN_TABLE_AI_CONFIG_2, MIO6220DeviceNum2); 
		DisplaySysCfgAOTable(MIOPanelHandle2, MIO_PNL_2_MIO_CFG_TAB_2, TAB_PAGE_FOUR,DYN_TABLE_AO_CONFIG_2, MIO6220DeviceNum2);
	
		DisplayDIOCfg(MIOPanelHandle2, MIO_PNL_2_MIO_CFG_TAB_2, TAB_PAGE_FIVE, TREE_TAB3_DIO_TREE, MIO6220DeviceNum2, 23);
		DisplaySysCfgDIOTable(MIOPanelHandle2, MIO_PNL_2_MIO_CFG_TAB_2, TAB_PAGE_SIX,DYN_TABLE_MDIO_CONFIG_2, MIO6220DeviceNum2);
		
		SetTabPageAttribute(MIOPanelHandle2, MIO_PNL_2_MIO_CFG_TAB_2, TAB_PAGE_TWO, ATTR_VISIBLE, 1);
		SetTabPageAttribute(MIOPanelHandle2, MIO_PNL_2_MIO_CFG_TAB_2, TAB_PAGE_FOUR, ATTR_VISIBLE, 1);
		SetTabPageAttribute(MIOPanelHandle2, MIO_PNL_2_MIO_CFG_TAB_2, TAB_PAGE_SIX, ATTR_VISIBLE, 1);
		
		GetPanelHandleFromTabPage (MIOPanelHandle2, MIO_PNL_2_MIO_CFG_TAB_2, TAB_PAGE_TWO, &TabPanelHandle);
		GetPanelHandleFromTabPage (MIOPanelHandle2, MIO_PNL_2_MIO_CFG_TAB_2, TAB_PAGE_FOUR, &TabPanelHandle1);
		GetPanelHandleFromTabPage (MIOPanelHandle2, MIO_PNL_2_MIO_CFG_TAB_2, TAB_PAGE_SIX, &TabPanelHandle2);
		
		SetCtrlAttribute (TabPanelHandle, AI_TB_TA_2_AI_CFG_SAVE_2, ATTR_DIMMED , 0);
		SetCtrlAttribute (TabPanelHandle1, AO_TB_TA_2_AO_CFG_SAVE_2, ATTR_DIMMED , 0);
		SetCtrlAttribute (TabPanelHandle2, MIO_TB_T_2_MDIO_CFG_SAVE_2, ATTR_DIMMED , 0);
	}
	else
	{
		if(firstTab) SetActiveTabPage (MIOPanelHandle2, MIO_PNL_2_MIO_CFG_TAB_2, 0);
		DisplayAICfg(MIOPanelHandle2, MIO_PNL_MIO_CFG_TAB, TAB_PAGE_ONE, TREE_TAB_2_AI_TREE_2, MIO6220DeviceNum2, 79);
		DisplayAOCfg(MIOPanelHandle2, MIO_PNL_MIO_CFG_TAB, TAB_PAGE_THREE, TREE_TAB_2_AI_TREE_2, MIO6220DeviceNum2, MIO6220DeviceNum2);
		DisplaySysCfgAITable(MIOPanelHandle2, MIO_PNL_MIO_CFG_TAB, TAB_PAGE_TWO,DYN_TABLE_AI_CONFIG_2, MIO6220DeviceNum2); 
		DisplaySysCfgAOTable(MIOPanelHandle2, MIO_PNL_MIO_CFG_TAB, TAB_PAGE_FOUR,DYN_TABLE_AO_CONFIG_2, MIO6220DeviceNum2);
	
		DisplayDIOCfg(MIOPanelHandle2, MIO_PNL_MIO_CFG_TAB, TAB_PAGE_FIVE, TREE_TAB_4_DIO_TREE_2, MIO6220DeviceNum2, 23);
		DisplaySysCfgDIOTable(MIOPanelHandle2, MIO_PNL_MIO_CFG_TAB, TAB_PAGE_SIX,DYN_TABLE_MDIO_CONFIG_2, MIO6220DeviceNum2);

		GetPanelHandleFromTabPage (MIOPanelHandle2, MIO_PNL_2_MIO_CFG_TAB_2, TAB_PAGE_TWO, &TabPanelHandle);
		GetPanelHandleFromTabPage (MIOPanelHandle2, MIO_PNL_2_MIO_CFG_TAB_2, TAB_PAGE_FOUR, &TabPanelHandle1);
		GetPanelHandleFromTabPage (MIOPanelHandle2, MIO_PNL_2_MIO_CFG_TAB_2, TAB_PAGE_SIX, &TabPanelHandle2);
		
		SetCtrlAttribute (TabPanelHandle, AI_TB_TA_2_AI_CFG_SAVE_2, ATTR_DIMMED , 1);
		SetCtrlAttribute (TabPanelHandle1, AO_TB_TA_2_AO_CFG_SAVE_2, ATTR_DIMMED , 1);
		SetCtrlAttribute (TabPanelHandle2, MIO_TB_T_2_MDIO_CFG_SAVE_2, ATTR_DIMMED , 1);
		
	}
}
//********************************************************************************************************************
void CreateAnalogInputConfigurationTable()
{
	int 		TabPanelHandle;
// -----------------------------------------------------------------------------------------------------------------------	
	Ptr_AI_CONFIG_TableParameters=&AI_CONFIG_TableParameters;
	Ptr_AI_CONFIG_ColumnParameters=AI_CONFIG_ColumnParameters; 

	GetPanelHandleFromTabPage (MIOPanelHandle, MIO_PNL_MIO_CFG_TAB, TAB_PAGE_TWO, &TabPanelHandle);
	
	AI_CONFIG_TableRowsandColumns.Num_of_Rows = ANALOG_INPUT_TABLE_ROW;
	AI_CONFIG_TableRowsandColumns.Num_of_Columns = ANALOG_INPUT_TABLE_COLUMN;
	
	SetCtrlVal (TabPanelHandle, MIO_PNL_MIO_CFG_TAB, AI_CONFIG_TableRowsandColumns.Num_of_Rows);
	
	if(AI_CONFIG_TableRowsandColumns.Num_of_Rows>0)
	{
		LIB_CreateTableParam(Ptr_AI_CONFIG_TableParameters,10,500,1255,30,10,
							  AI_CONFIG_TableRowsandColumns.Num_of_Rows,0);
    	DYN_TABLE_AI_CONFIG=LIB_CreatTableControl(Ptr_AI_CONFIG_TableParameters, TabPanelHandle, 
    												 "SystemConfiguration.c", DYN_TABLE_AI_CONFIG);
    }
    else
    {
		LIB_CreateTableParam(Ptr_AI_CONFIG_TableParameters,50,500,700,30,10,AI_CONFIG_ROW_INDEX_CONSTANT,0);
	   	DYN_TABLE_AI_CONFIG=LIB_CreatTableControl(Ptr_AI_CONFIG_TableParameters,TabPanelHandle, 
	   												 "SystemConfiguration.c", DYN_TABLE_AI_CONFIG);
    }

//  CREATE TABLE COLUMN	
//===================================================================================================================
	LIB_CreateTableColumnParam(Ptr_AI_CONFIG_ColumnParameters,0,-1,1,1,80,"Analog Channel Index",1);
	LIB_DYNInsertTableColumns(Ptr_AI_CONFIG_ColumnParameters, Ptr_AI_CONFIG_TableParameters,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_AI_CONFIG,1);//char  where Number Type int/Double = 0, char = 1
//===================================================================================================================	
	LIB_CreateTableColumnParam(Ptr_AI_CONFIG_ColumnParameters,1,-1,2,1,200,"AI Name",0);
	LIB_DYNInsertTableColumns(Ptr_AI_CONFIG_ColumnParameters, Ptr_AI_CONFIG_TableParameters,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_AI_CONFIG,2); //char
//===================================================================================================================	
	LIB_CreateTableColumnParam(Ptr_AI_CONFIG_ColumnParameters,2,-1,3,1,200,"AI Channel Name",0);
	LIB_DYNInsertTableColumns(Ptr_AI_CONFIG_ColumnParameters, Ptr_AI_CONFIG_TableParameters,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_AI_CONFIG,3);//char
//===================================================================================================================	
	LIB_CreateTableColumnParam(Ptr_AI_CONFIG_ColumnParameters,3,-1,4,1,100,"AI Input Configuration",0);
	LIB_DYNInsertTableColumns(Ptr_AI_CONFIG_ColumnParameters, Ptr_AI_CONFIG_TableParameters,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_AI_CONFIG,4);//char
//===================================================================================================================	
	LIB_CreateTableColumnParam(Ptr_AI_CONFIG_ColumnParameters,4,-1,5,1,100,"AI Minimum Limit",0);
	LIB_DYNInsertTableColumns(Ptr_AI_CONFIG_ColumnParameters, Ptr_AI_CONFIG_TableParameters,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_AI_CONFIG,5);//char
//===================================================================================================================
	LIB_CreateTableColumnParam(Ptr_AI_CONFIG_ColumnParameters,5,-1,6,1,100,"AI Maximum Limit",0);
	LIB_DYNInsertTableColumns(Ptr_AI_CONFIG_ColumnParameters, Ptr_AI_CONFIG_TableParameters,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_AI_CONFIG,6);//char
//===================================================================================================================
	LIB_CreateTableColumnParam(Ptr_AI_CONFIG_ColumnParameters,6,-1,7,1,80,"AI Sample Mode",0);
	LIB_DYNInsertTableColumns(Ptr_AI_CONFIG_ColumnParameters, Ptr_AI_CONFIG_TableParameters,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_AI_CONFIG,7);//char					  
//===================================================================================================================
	LIB_CreateTableColumnParam(Ptr_AI_CONFIG_ColumnParameters,7,-1,8,1,130,"AI Timeout",0);
	LIB_DYNInsertTableColumns(Ptr_AI_CONFIG_ColumnParameters, Ptr_AI_CONFIG_TableParameters,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_AI_CONFIG,8);//char
//===================================================================================================================	
	LIB_CreateTableColumnParam(Ptr_AI_CONFIG_ColumnParameters,8,-1,9,1,100,"AI Sampling Rate",1);
	LIB_DYNInsertTableColumns(Ptr_AI_CONFIG_ColumnParameters, Ptr_AI_CONFIG_TableParameters,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_AI_CONFIG,9);//char
//===================================================================================================================
	LIB_CreateTableColumnParam(Ptr_AI_CONFIG_ColumnParameters,9,-1,10,1,100,"AI Sample Per Channel",0);
	LIB_DYNInsertTableColumns(Ptr_AI_CONFIG_ColumnParameters, Ptr_AI_CONFIG_TableParameters,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_AI_CONFIG,10);//char
//===================================================================================================================	
	SetCtrlAttribute(TabPanelHandle, AI_TB_TAB_NUM_COLUMNS,ATTR_NO_EDIT_TEXT,0);
	SetCtrlVal (TabPanelHandle, AI_TB_TAB_NUM_COLUMNS, ((Ptr_AI_CONFIG_ColumnParameters+9))->NumberofColumns);
	SetCtrlAttribute(TabPanelHandle, AI_TB_TAB_NUM_COLUMNS,ATTR_NO_EDIT_TEXT,1);
	SetCtrlAttribute(TabPanelHandle, AI_TB_TAB_NUM_COLUMNS,ATTR_SHOW_INCDEC_ARROWS,0);
}
//********************************************************************************************************************
void CreateAnalogInputConfigurationTable2()
{
	int 		TabPanelHandle;
// -----------------------------------------------------------------------------------------------------------------------	
	Ptr_AI_CONFIG_TableParameters2=&AI_CONFIG_TableParameters2;
	Ptr_AI_CONFIG_ColumnParameters2=AI_CONFIG_ColumnParameters2; 

	GetPanelHandleFromTabPage (MIOPanelHandle2, MIO_PNL_2_MIO_CFG_TAB_2, TAB_PAGE_TWO, &TabPanelHandle);
	
	AI_CONFIG_TableRowsandColumns2.Num_of_Rows = ANALOG_INPUT_TABLE_ROW;
	AI_CONFIG_TableRowsandColumns2.Num_of_Columns = ANALOG_INPUT_TABLE_COLUMN;
	
	SetCtrlVal (TabPanelHandle, MIO_PNL_2_MIO_CFG_TAB_2, AI_CONFIG_TableRowsandColumns2.Num_of_Rows);
	
	if(AI_CONFIG_TableRowsandColumns2.Num_of_Rows>0)
	{
		LIB_CreateTableParam(Ptr_AI_CONFIG_TableParameters2,10,500,1255,30,10,
							  AI_CONFIG_TableRowsandColumns2.Num_of_Rows,0);
    	DYN_TABLE_AI_CONFIG_2=LIB_CreatTableControl(Ptr_AI_CONFIG_TableParameters2, TabPanelHandle, 
    												 "SystemConfiguration.c", DYN_TABLE_AI_CONFIG_2);
    }
    else
    {
		LIB_CreateTableParam(Ptr_AI_CONFIG_TableParameters2,50,500,700,30,10,AI_CONFIG_ROW_INDEX_CONSTANT,0);
	   	DYN_TABLE_AI_CONFIG_2=LIB_CreatTableControl(Ptr_AI_CONFIG_TableParameters2,TabPanelHandle, 
	   												 "SystemConfiguration.c", DYN_TABLE_AI_CONFIG_2);
    }

//  CREATE TABLE COLUMN	
//===================================================================================================================
	LIB_CreateTableColumnParam(Ptr_AI_CONFIG_ColumnParameters2,0,-1,1,1,80,"Analog Channel Index",1);
	LIB_DYNInsertTableColumns(Ptr_AI_CONFIG_ColumnParameters2, Ptr_AI_CONFIG_TableParameters2,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_AI_CONFIG_2,1);//char  where Number Type int/Double = 0, char = 1
//===================================================================================================================	
	LIB_CreateTableColumnParam(Ptr_AI_CONFIG_ColumnParameters2,1,-1,2,1,200,"AI Name",0);
	LIB_DYNInsertTableColumns(Ptr_AI_CONFIG_ColumnParameters2, Ptr_AI_CONFIG_TableParameters2,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_AI_CONFIG_2,2); //char
//===================================================================================================================	
	LIB_CreateTableColumnParam(Ptr_AI_CONFIG_ColumnParameters2,2,-1,3,1,200,"AI Channel Name",0);
	LIB_DYNInsertTableColumns(Ptr_AI_CONFIG_ColumnParameters2, Ptr_AI_CONFIG_TableParameters2,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_AI_CONFIG_2,3);//char
//===================================================================================================================	
	LIB_CreateTableColumnParam(Ptr_AI_CONFIG_ColumnParameters2,3,-1,4,1,100,"AI Input Configuration",0);
	LIB_DYNInsertTableColumns(Ptr_AI_CONFIG_ColumnParameters2, Ptr_AI_CONFIG_TableParameters2,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_AI_CONFIG_2,4);//char
//===================================================================================================================	
	LIB_CreateTableColumnParam(Ptr_AI_CONFIG_ColumnParameters2,4,-1,5,1,100,"AI Minimum Limit",0);
	LIB_DYNInsertTableColumns(Ptr_AI_CONFIG_ColumnParameters2, Ptr_AI_CONFIG_TableParameters2,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_AI_CONFIG_2,5);//char
//===================================================================================================================
	LIB_CreateTableColumnParam(Ptr_AI_CONFIG_ColumnParameters2,5,-1,6,1,100,"AI Maximum Limit",0);
	LIB_DYNInsertTableColumns(Ptr_AI_CONFIG_ColumnParameters2, Ptr_AI_CONFIG_TableParameters2,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_AI_CONFIG_2,6);//char
//===================================================================================================================
	LIB_CreateTableColumnParam(Ptr_AI_CONFIG_ColumnParameters2,6,-1,7,1,80,"AI Sample Mode",0);
	LIB_DYNInsertTableColumns(Ptr_AI_CONFIG_ColumnParameters2, Ptr_AI_CONFIG_TableParameters2,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_AI_CONFIG_2,7);//char					  
//===================================================================================================================
	LIB_CreateTableColumnParam(Ptr_AI_CONFIG_ColumnParameters2,7,-1,8,1,130,"AI Timeout",0);
	LIB_DYNInsertTableColumns(Ptr_AI_CONFIG_ColumnParameters2, Ptr_AI_CONFIG_TableParameters2,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_AI_CONFIG_2,8);//char
//===================================================================================================================	
	LIB_CreateTableColumnParam(Ptr_AI_CONFIG_ColumnParameters2,8,-1,9,1,100,"AI Sampling Rate",1);
	LIB_DYNInsertTableColumns(Ptr_AI_CONFIG_ColumnParameters2, Ptr_AI_CONFIG_TableParameters2,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_AI_CONFIG_2,9);//char
//===================================================================================================================
	LIB_CreateTableColumnParam(Ptr_AI_CONFIG_ColumnParameters2,9,-1,10,1,100,"AI Sample Per Channel",0);
	LIB_DYNInsertTableColumns(Ptr_AI_CONFIG_ColumnParameters2, Ptr_AI_CONFIG_TableParameters2,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_AI_CONFIG_2,10);//char
//===================================================================================================================	
	SetCtrlAttribute(TabPanelHandle, AI_TB_TA_2_NUM_COLUMNS,ATTR_NO_EDIT_TEXT,0);
	SetCtrlVal (TabPanelHandle, AI_TB_TAB_NUM_COLUMNS, ((Ptr_AI_CONFIG_ColumnParameters2+9))->NumberofColumns);
	SetCtrlAttribute(TabPanelHandle, AI_TB_TA_2_NUM_COLUMNS,ATTR_NO_EDIT_TEXT,1);
	SetCtrlAttribute(TabPanelHandle, AI_TB_TA_2_NUM_COLUMNS,ATTR_SHOW_INCDEC_ARROWS,0);
}
//*******************************************************************************************************************
void CreateAnalogOutputConfigurationTable()
{
	int 		TabPanelHandle;
// -----------------------------------------------------------------------------------------------------------------------	
	Ptr_AO_CONFIG_TableParameters=&AO_CONFIG_TableParameters;
	Ptr_AO_CONFIG_ColumnParameters=AO_CONFIG_ColumnParameters; 

	GetPanelHandleFromTabPage (MIOPanelHandle, MIO_PNL_MIO_CFG_TAB, TAB_PAGE_FOUR, &TabPanelHandle);

	AO_CONFIG_TableRowsandColumns.Num_of_Rows = ANALOG_OUTPUT_TABLE_ROW;
	AO_CONFIG_TableRowsandColumns.Num_of_Columns = ANALOG_OUTPUT_TABLE_COLUMN;
	
	SetCtrlVal (TabPanelHandle, MIO_PNL_MIO_CFG_TAB, AO_CONFIG_TableRowsandColumns.Num_of_Rows);
	
	
	if(AO_CONFIG_TableRowsandColumns.Num_of_Rows>0)
	{
		LIB_CreateTableParam(Ptr_AO_CONFIG_TableParameters,10,500,1255,30,10,
							  AO_CONFIG_TableRowsandColumns.Num_of_Rows,0);
    	DYN_TABLE_AO_CONFIG=LIB_CreatTableControl(Ptr_AO_CONFIG_TableParameters, TabPanelHandle, 
    												 "SystemConfiguration.c", DYN_TABLE_AO_CONFIG);
    }
    else
    {
		LIB_CreateTableParam(Ptr_AO_CONFIG_TableParameters,50,500,1000,30,10,AO_CONFIG_ROW_INDEX_CONSTANT,0);
	   	DYN_TABLE_AO_CONFIG=LIB_CreatTableControl(Ptr_AO_CONFIG_TableParameters,TabPanelHandle, 
	   												 "SystemConfiguration.c", DYN_TABLE_AO_CONFIG);
    }

//  CREATE TABLE COLUMN	
//===================================================================================================================
	LIB_CreateTableColumnParam(Ptr_AO_CONFIG_ColumnParameters,0,-1,1,1,80,"Analog Channel Index",1);
	LIB_DYNInsertTableColumns(Ptr_AO_CONFIG_ColumnParameters, Ptr_AO_CONFIG_TableParameters,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_AO_CONFIG,1);//char  where Number Type int/Double = 0, char = 1
//===================================================================================================================	
	LIB_CreateTableColumnParam(Ptr_AO_CONFIG_ColumnParameters,1,-1,2,1,200,"AO Name",0);
	LIB_DYNInsertTableColumns(Ptr_AO_CONFIG_ColumnParameters, Ptr_AO_CONFIG_TableParameters,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_AO_CONFIG,2); //char
//===================================================================================================================	
	LIB_CreateTableColumnParam(Ptr_AO_CONFIG_ColumnParameters,2,-1,3,1,200,"AO Channel Name",0);
	LIB_DYNInsertTableColumns(Ptr_AO_CONFIG_ColumnParameters, Ptr_AO_CONFIG_TableParameters,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_AO_CONFIG,3);//char
//===================================================================================================================	
	LIB_CreateTableColumnParam(Ptr_AO_CONFIG_ColumnParameters,3,-1,4,1,100,"AO Input Configuration",0);
	LIB_DYNInsertTableColumns(Ptr_AO_CONFIG_ColumnParameters, Ptr_AO_CONFIG_TableParameters,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_AO_CONFIG,4);//char
//===================================================================================================================	
	LIB_CreateTableColumnParam(Ptr_AO_CONFIG_ColumnParameters,4,-1,5,1,100,"AO Minimum Limit",0);
	LIB_DYNInsertTableColumns(Ptr_AO_CONFIG_ColumnParameters, Ptr_AO_CONFIG_TableParameters,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_AO_CONFIG,5);//char
//===================================================================================================================
	LIB_CreateTableColumnParam(Ptr_AO_CONFIG_ColumnParameters,5,-1,6,1,100,"AO Maximum Limit",0);
	LIB_DYNInsertTableColumns(Ptr_AO_CONFIG_ColumnParameters, Ptr_AO_CONFIG_TableParameters,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_AO_CONFIG,6);//char
//===================================================================================================================
	LIB_CreateTableColumnParam(Ptr_AO_CONFIG_ColumnParameters,6,-1,7,1,80,"AO Sample Mode",0);
	LIB_DYNInsertTableColumns(Ptr_AO_CONFIG_ColumnParameters, Ptr_AO_CONFIG_TableParameters,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_AO_CONFIG,7);//char					  
//===================================================================================================================
	LIB_CreateTableColumnParam(Ptr_AO_CONFIG_ColumnParameters,7,-1,8,1,130,"AO Timeout",0);
	LIB_DYNInsertTableColumns(Ptr_AO_CONFIG_ColumnParameters, Ptr_AO_CONFIG_TableParameters,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_AO_CONFIG,8);//char
//===================================================================================================================	
	LIB_CreateTableColumnParam(Ptr_AO_CONFIG_ColumnParameters,8,-1,9,1,100,"AO Sampling Rate",1);
	LIB_DYNInsertTableColumns(Ptr_AO_CONFIG_ColumnParameters, Ptr_AO_CONFIG_TableParameters,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_AO_CONFIG,9);//char
//===================================================================================================================
	LIB_CreateTableColumnParam(Ptr_AO_CONFIG_ColumnParameters,9,-1,10,1,100,"AO Sample Per Channel",0);
	LIB_DYNInsertTableColumns(Ptr_AO_CONFIG_ColumnParameters, Ptr_AO_CONFIG_TableParameters,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_AO_CONFIG,10);//char
//===================================================================================================================	
	SetCtrlAttribute(TabPanelHandle, AO_TB_TAB_NUM_COLUMNS,ATTR_NO_EDIT_TEXT,0);
	SetCtrlVal (TabPanelHandle, AO_TB_TAB_NUM_COLUMNS, ((Ptr_AO_CONFIG_ColumnParameters+9))->NumberofColumns);
	SetCtrlAttribute(TabPanelHandle, AO_TB_TAB_NUM_COLUMNS,ATTR_NO_EDIT_TEXT,1);
	SetCtrlAttribute(TabPanelHandle, AO_TB_TAB_NUM_COLUMNS,ATTR_SHOW_INCDEC_ARROWS,0);
}
//*******************************************************************************************************************
void CreateAnalogOutputConfigurationTable2()
{
	int 		TabPanelHandle;
// -----------------------------------------------------------------------------------------------------------------------	
	Ptr_AO_CONFIG_TableParameters2=&AO_CONFIG_TableParameters2;
	Ptr_AO_CONFIG_ColumnParameters2=AO_CONFIG_ColumnParameters2; 

	GetPanelHandleFromTabPage (MIOPanelHandle2, MIO_PNL_2_MIO_CFG_TAB_2, TAB_PAGE_FOUR, &TabPanelHandle);

	AO_CONFIG_TableRowsandColumns2.Num_of_Rows = ANALOG_OUTPUT_TABLE_ROW;
	AO_CONFIG_TableRowsandColumns2.Num_of_Columns = ANALOG_OUTPUT_TABLE_COLUMN;
	
	SetCtrlVal (TabPanelHandle, MIO_PNL_2_MIO_CFG_TAB_2, AO_CONFIG_TableRowsandColumns2.Num_of_Rows);
	
	if(AO_CONFIG_TableRowsandColumns2.Num_of_Rows>0)
	{
		LIB_CreateTableParam(Ptr_AO_CONFIG_TableParameters2,10,500,1255,30,10,
							  AO_CONFIG_TableRowsandColumns2.Num_of_Rows,0);
    	DYN_TABLE_AO_CONFIG_2=LIB_CreatTableControl(Ptr_AO_CONFIG_TableParameters2, TabPanelHandle, 
    												 "SystemConfiguration.c", DYN_TABLE_AO_CONFIG);
    }
    else
    {
		LIB_CreateTableParam(Ptr_AO_CONFIG_TableParameters2,50,500,1000,30,10,AO_CONFIG_ROW_INDEX_CONSTANT,0);
	   	DYN_TABLE_AO_CONFIG_2=LIB_CreatTableControl(Ptr_AO_CONFIG_TableParameters2,TabPanelHandle, 
	   												 "SystemConfiguration.c", DYN_TABLE_AO_CONFIG_2);
    }

//  CREATE TABLE COLUMN	
//===================================================================================================================
	LIB_CreateTableColumnParam(Ptr_AO_CONFIG_ColumnParameters2,0,-1,1,1,80,"Analog Channel Index",1);
	LIB_DYNInsertTableColumns(Ptr_AO_CONFIG_ColumnParameters2, Ptr_AO_CONFIG_TableParameters2,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_AO_CONFIG_2,1);//char  where Number Type int/Double = 0, char = 1
//===================================================================================================================	
	LIB_CreateTableColumnParam(Ptr_AO_CONFIG_ColumnParameters2,1,-1,2,1,200,"AO Name",0);
	LIB_DYNInsertTableColumns(Ptr_AO_CONFIG_ColumnParameters2, Ptr_AO_CONFIG_TableParameters2,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_AO_CONFIG_2,2); //char
//===================================================================================================================	
	LIB_CreateTableColumnParam(Ptr_AO_CONFIG_ColumnParameters2,2,-1,3,1,200,"AO Channel Name",0);
	LIB_DYNInsertTableColumns(Ptr_AO_CONFIG_ColumnParameters2, Ptr_AO_CONFIG_TableParameters2,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_AO_CONFIG_2,3);//char
//===================================================================================================================	
	LIB_CreateTableColumnParam(Ptr_AO_CONFIG_ColumnParameters2,3,-1,4,1,100,"AO Input Configuration",0);
	LIB_DYNInsertTableColumns(Ptr_AO_CONFIG_ColumnParameters2, Ptr_AO_CONFIG_TableParameters2,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_AO_CONFIG_2,4);//char
//===================================================================================================================	
	LIB_CreateTableColumnParam(Ptr_AO_CONFIG_ColumnParameters2,4,-1,5,1,100,"AO Minimum Limit",0);
	LIB_DYNInsertTableColumns(Ptr_AO_CONFIG_ColumnParameters2, Ptr_AO_CONFIG_TableParameters2,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_AO_CONFIG_2,5);//char
//===================================================================================================================
	LIB_CreateTableColumnParam(Ptr_AO_CONFIG_ColumnParameters2,5,-1,6,1,100,"AO Maximum Limit",0);
	LIB_DYNInsertTableColumns(Ptr_AO_CONFIG_ColumnParameters2, Ptr_AO_CONFIG_TableParameters2,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_AO_CONFIG_2,6);//char
//===================================================================================================================
	LIB_CreateTableColumnParam(Ptr_AO_CONFIG_ColumnParameters2,6,-1,7,1,80,"AO Sample Mode",0);
	LIB_DYNInsertTableColumns(Ptr_AO_CONFIG_ColumnParameters2, Ptr_AO_CONFIG_TableParameters2,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_AO_CONFIG_2,7);//char					  
//===================================================================================================================
	LIB_CreateTableColumnParam(Ptr_AO_CONFIG_ColumnParameters2,7,-1,8,1,130,"AO Timeout",0);
	LIB_DYNInsertTableColumns(Ptr_AO_CONFIG_ColumnParameters2, Ptr_AO_CONFIG_TableParameters2,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_AO_CONFIG_2,8);//char
//===================================================================================================================	
	LIB_CreateTableColumnParam(Ptr_AO_CONFIG_ColumnParameters2,8,-1,9,1,100,"AO Sampling Rate",1);
	LIB_DYNInsertTableColumns(Ptr_AO_CONFIG_ColumnParameters2, Ptr_AO_CONFIG_TableParameters2,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_AO_CONFIG_2,9);//char
//===================================================================================================================
	LIB_CreateTableColumnParam(Ptr_AO_CONFIG_ColumnParameters2,9,-1,10,1,100,"AO Sample Per Channel",0);
	LIB_DYNInsertTableColumns(Ptr_AO_CONFIG_ColumnParameters2, Ptr_AO_CONFIG_TableParameters2,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_AO_CONFIG_2,10);//char
//===================================================================================================================	
	SetCtrlAttribute(TabPanelHandle, AO_TB_TAB_NUM_COLUMNS,ATTR_NO_EDIT_TEXT,0);
	SetCtrlVal (TabPanelHandle, AO_TB_TAB_NUM_COLUMNS, ((Ptr_AO_CONFIG_ColumnParameters2+9))->NumberofColumns);
	SetCtrlAttribute(TabPanelHandle, AO_TB_TAB_NUM_COLUMNS,ATTR_NO_EDIT_TEXT,1);
	SetCtrlAttribute(TabPanelHandle, AO_TB_TAB_NUM_COLUMNS,ATTR_SHOW_INCDEC_ARROWS,0);
}
//*******************************************************************************************************************
void CreateMDigitalIOConfigurationTable()
{
	int 		TabPanelHandle;
// -----------------------------------------------------------------------------------------------------------------------	
	Ptr_MDIO_CONFIG_TableParameters=&MDIO_CONFIG_TableParameters;
	Ptr_MDIO_CONFIG_ColumnParameters=MDIO_CONFIG_ColumnParameters; 

	GetPanelHandleFromTabPage (MIOPanelHandle, MIO_PNL_MIO_CFG_TAB, TAB_PAGE_SIX, &TabPanelHandle);

	MDIO_CONFIG_TableRowsandColumns.Num_of_Rows = MDIO_TABLE_ROW;
	MDIO_CONFIG_TableRowsandColumns.Num_of_Columns = MDIO_TABLE_COLUMN;
	
	SetCtrlVal (TabPanelHandle, MIO_PNL_MIO_CFG_TAB, MDIO_CONFIG_TableRowsandColumns.Num_of_Rows);
	
	
	if(MDIO_CONFIG_TableRowsandColumns.Num_of_Rows>0)
	{
		LIB_CreateTableParam(Ptr_MDIO_CONFIG_TableParameters,10,500,1255,30,10,
							  MDIO_CONFIG_TableRowsandColumns.Num_of_Rows,0);
    	DYN_TABLE_MDIO_CONFIG=LIB_CreatTableControl(Ptr_MDIO_CONFIG_TableParameters, TabPanelHandle, 
    												 "SystemConfiguration.c", DYN_TABLE_MDIO_CONFIG);
    }
    else
    {
		LIB_CreateTableParam(Ptr_MDIO_CONFIG_TableParameters,50,500,1000,30,10,MDIO_CONFIG_ROW_INDEX_CONSTANT,0);
	   	DYN_TABLE_MDIO_CONFIG=LIB_CreatTableControl(Ptr_MDIO_CONFIG_TableParameters,TabPanelHandle, 
	   												 "SystemConfiguration.c", DYN_TABLE_MDIO_CONFIG);
    }

//  CREATE TABLE COLUMN	
//===================================================================================================================
	LIB_CreateTableColumnParam(Ptr_MDIO_CONFIG_ColumnParameters,0,-1,1,1,80,"MDIO Channel Index",1);
	LIB_DYNInsertTableColumns(Ptr_MDIO_CONFIG_ColumnParameters, Ptr_MDIO_CONFIG_TableParameters,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_MDIO_CONFIG,1);//char  where Number Type int/Double = 0, char = 1
//===================================================================================================================	
	LIB_CreateTableColumnParam(Ptr_MDIO_CONFIG_ColumnParameters,1,-1,2,1,200,"MDIO Name",0);
	LIB_DYNInsertTableColumns(Ptr_MDIO_CONFIG_ColumnParameters, Ptr_MDIO_CONFIG_TableParameters,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_MDIO_CONFIG,2); //char
//===================================================================================================================	
	LIB_CreateTableColumnParam(Ptr_MDIO_CONFIG_ColumnParameters,2,-1,3,1,200,"MDIO Channel Name",0);
	LIB_DYNInsertTableColumns(Ptr_MDIO_CONFIG_ColumnParameters, Ptr_MDIO_CONFIG_TableParameters,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_MDIO_CONFIG,3);//char
//===================================================================================================================	
	LIB_CreateTableColumnParam(Ptr_MDIO_CONFIG_ColumnParameters,3,-1,4,1,100,"MDIO Input Configuration",0);
	LIB_DYNInsertTableColumns(Ptr_MDIO_CONFIG_ColumnParameters, Ptr_MDIO_CONFIG_TableParameters,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_MDIO_CONFIG,4);//char
//===================================================================================================================	
	LIB_CreateTableColumnParam(Ptr_MDIO_CONFIG_ColumnParameters,4,-1,5,1,100,"MDIO Port",0);
	LIB_DYNInsertTableColumns(Ptr_MDIO_CONFIG_ColumnParameters, Ptr_MDIO_CONFIG_TableParameters,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_MDIO_CONFIG,5);//char
//===================================================================================================================
	LIB_CreateTableColumnParam(Ptr_MDIO_CONFIG_ColumnParameters,5,-1,6,1,100,"MDIO Bit",0);
	LIB_DYNInsertTableColumns(Ptr_MDIO_CONFIG_ColumnParameters, Ptr_MDIO_CONFIG_TableParameters,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_MDIO_CONFIG,6);//char
//===================================================================================================================
	LIB_CreateTableColumnParam(Ptr_MDIO_CONFIG_ColumnParameters,6,-1,7,1,80,"MDIO Test Status",0);
	LIB_DYNInsertTableColumns(Ptr_MDIO_CONFIG_ColumnParameters, Ptr_MDIO_CONFIG_TableParameters,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_MDIO_CONFIG,7);//char					  
//===================================================================================================================
	LIB_CreateTableColumnParam(Ptr_MDIO_CONFIG_ColumnParameters,7,-1,8,1,130,"MDIO Timeout",0);
	LIB_DYNInsertTableColumns(Ptr_MDIO_CONFIG_ColumnParameters, Ptr_MDIO_CONFIG_TableParameters,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_MDIO_CONFIG,8);//char
//===================================================================================================================	
	LIB_CreateTableColumnParam(Ptr_MDIO_CONFIG_ColumnParameters,8,-1,9,1,100,"MDIO Repeat",1);
	LIB_DYNInsertTableColumns(Ptr_MDIO_CONFIG_ColumnParameters, Ptr_MDIO_CONFIG_TableParameters,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_MDIO_CONFIG,9);//char
//===================================================================================================================
	LIB_CreateTableColumnParam(Ptr_MDIO_CONFIG_ColumnParameters,9,-1,10,1,100,"MDIO Wire Tag",0);
	LIB_DYNInsertTableColumns(Ptr_MDIO_CONFIG_ColumnParameters, Ptr_MDIO_CONFIG_TableParameters,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_MDIO_CONFIG,10);//char
//===================================================================================================================	
	SetCtrlAttribute(TabPanelHandle, MIO_TB_TAB_NUM_COLUMNS,ATTR_NO_EDIT_TEXT,0);
	SetCtrlVal (TabPanelHandle, MIO_TB_TAB_NUM_COLUMNS, ((Ptr_MDIO_CONFIG_ColumnParameters+9))->NumberofColumns);
	SetCtrlAttribute(TabPanelHandle, MIO_TB_TAB_NUM_COLUMNS,ATTR_NO_EDIT_TEXT,1);
	SetCtrlAttribute(TabPanelHandle, MIO_TB_TAB_NUM_COLUMNS,ATTR_SHOW_INCDEC_ARROWS,0);
}
//********************************************************************************************************************
void CreateMDigitalIOConfigurationTable2()
{
	int 		TabPanelHandle;
// -----------------------------------------------------------------------------------------------------------------------	
	Ptr_MDIO_CONFIG_TableParameters2=&MDIO_CONFIG_TableParameters2;
	Ptr_MDIO_CONFIG_ColumnParameters2=MDIO_CONFIG_ColumnParameters2; 

	GetPanelHandleFromTabPage (MIOPanelHandle2, MIO_PNL_2_MIO_CFG_TAB_2, TAB_PAGE_SIX, &TabPanelHandle);

	MDIO_CONFIG_TableRowsandColumns2.Num_of_Rows = MDIO_TABLE_ROW;
	MDIO_CONFIG_TableRowsandColumns2.Num_of_Columns = MDIO_TABLE_COLUMN;
	
	SetCtrlVal (TabPanelHandle, MIO_PNL_2_MIO_CFG_TAB_2, MDIO_CONFIG_TableRowsandColumns2.Num_of_Rows);
	
	if(MDIO_CONFIG_TableRowsandColumns2.Num_of_Rows>0)
	{
		LIB_CreateTableParam(Ptr_MDIO_CONFIG_TableParameters2,10,500,1255,30,10,
							  MDIO_CONFIG_TableRowsandColumns2.Num_of_Rows,0);
    	DYN_TABLE_MDIO_CONFIG_2=LIB_CreatTableControl(Ptr_MDIO_CONFIG_TableParameters2, TabPanelHandle, 
    												 "SystemConfiguration.c", DYN_TABLE_MDIO_CONFIG_2);
    }
    else
    {
		LIB_CreateTableParam(Ptr_MDIO_CONFIG_TableParameters2,50,500,1000,30,10,MDIO_CONFIG_ROW_INDEX_CONSTANT,0);
	   	DYN_TABLE_MDIO_CONFIG_2=LIB_CreatTableControl(Ptr_MDIO_CONFIG_TableParameters2,TabPanelHandle, 
	   												 "SystemConfiguration.c", DYN_TABLE_MDIO_CONFIG_2);
    }

//  CREATE TABLE COLUMN	
//===================================================================================================================
	LIB_CreateTableColumnParam(Ptr_MDIO_CONFIG_ColumnParameters2,0,-1,1,1,80,"MDIO Channel Index",1);
	LIB_DYNInsertTableColumns(Ptr_MDIO_CONFIG_ColumnParameters2, Ptr_MDIO_CONFIG_TableParameters2,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_MDIO_CONFIG_2,1);//char  where Number Type int/Double = 0, char = 1
//===================================================================================================================	
	LIB_CreateTableColumnParam(Ptr_MDIO_CONFIG_ColumnParameters2,1,-1,2,1,200,"MDIO Name",0);
	LIB_DYNInsertTableColumns(Ptr_MDIO_CONFIG_ColumnParameters2, Ptr_MDIO_CONFIG_TableParameters2,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_MDIO_CONFIG_2,2); //char
//===================================================================================================================	
	LIB_CreateTableColumnParam(Ptr_MDIO_CONFIG_ColumnParameters2,2,-1,3,1,200,"MDIO Channel Name",0);
	LIB_DYNInsertTableColumns(Ptr_MDIO_CONFIG_ColumnParameters2, Ptr_MDIO_CONFIG_TableParameters2,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_MDIO_CONFIG_2,3);//char
//===================================================================================================================	
	LIB_CreateTableColumnParam(Ptr_MDIO_CONFIG_ColumnParameters2,3,-1,4,1,100,"MDIO Input Configuration",0);
	LIB_DYNInsertTableColumns(Ptr_MDIO_CONFIG_ColumnParameters2, Ptr_MDIO_CONFIG_TableParameters2,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_MDIO_CONFIG_2,4);//char
//===================================================================================================================	
	LIB_CreateTableColumnParam(Ptr_MDIO_CONFIG_ColumnParameters2,4,-1,5,1,100,"MDIO Port",0);
	LIB_DYNInsertTableColumns(Ptr_MDIO_CONFIG_ColumnParameters2, Ptr_MDIO_CONFIG_TableParameters2,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_MDIO_CONFIG_2,5);//char
//===================================================================================================================
	LIB_CreateTableColumnParam(Ptr_MDIO_CONFIG_ColumnParameters2,5,-1,6,1,100,"MDIO Bit",0);
	LIB_DYNInsertTableColumns(Ptr_MDIO_CONFIG_ColumnParameters2, Ptr_MDIO_CONFIG_TableParameters2,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_MDIO_CONFIG_2,6);//char
//===================================================================================================================
	LIB_CreateTableColumnParam(Ptr_MDIO_CONFIG_ColumnParameters2,6,-1,7,1,80,"MDIO Test Status",0);
	LIB_DYNInsertTableColumns(Ptr_MDIO_CONFIG_ColumnParameters2, Ptr_MDIO_CONFIG_TableParameters2,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_MDIO_CONFIG_2,7);//char					  
//===================================================================================================================
	LIB_CreateTableColumnParam(Ptr_MDIO_CONFIG_ColumnParameters2,7,-1,8,1,130,"MDIO Timeout",0);
	LIB_DYNInsertTableColumns(Ptr_MDIO_CONFIG_ColumnParameters2, Ptr_MDIO_CONFIG_TableParameters2,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_MDIO_CONFIG_2,8);//char
//===================================================================================================================	
	LIB_CreateTableColumnParam(Ptr_MDIO_CONFIG_ColumnParameters2,8,-1,9,1,100,"MDIO Repeat",1);
	LIB_DYNInsertTableColumns(Ptr_MDIO_CONFIG_ColumnParameters2, Ptr_MDIO_CONFIG_TableParameters2,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_MDIO_CONFIG_2,9);//char
//===================================================================================================================
	LIB_CreateTableColumnParam(Ptr_MDIO_CONFIG_ColumnParameters2,9,-1,10,1,100,"MDIO Wire Tag",0);
	LIB_DYNInsertTableColumns(Ptr_MDIO_CONFIG_ColumnParameters2, Ptr_MDIO_CONFIG_TableParameters2,
							   TabPanelHandle, "SystemConfiguration.c", DYN_TABLE_MDIO_CONFIG_2,10);//char
//===================================================================================================================	
	SetCtrlAttribute(TabPanelHandle, MIO_TB_T_2_NUM_COLUMNS_2,ATTR_NO_EDIT_TEXT,0);
	SetCtrlVal (TabPanelHandle, MIO_TB_T_2_NUM_COLUMNS_2, ((Ptr_MDIO_CONFIG_ColumnParameters2+9))->NumberofColumns);
	SetCtrlAttribute(TabPanelHandle, MIO_TB_T_2_NUM_COLUMNS_2,ATTR_NO_EDIT_TEXT,1);
	SetCtrlAttribute(TabPanelHandle, MIO_TB_T_2_NUM_COLUMNS_2,ATTR_SHOW_INCDEC_ARROWS,0);
}
//********************************************************************************************************************

int CVICALLBACK DeleteRowCB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			break;
	}
	return 0;
}
//*******************************************************************************************************************
int CVICALLBACK InsertRowCB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			break;
	}
	return 0;
}
//*******************************************************************************************************************
int CVICALLBACK MAIInsertRowCB (int panel, int control, int event,
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
//*******************************************************************************************************************
int CVICALLBACK MAIDeleteRowCB (int panel, int control, int event,
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
//*******************************************************************************************************************
int CVICALLBACK MAOInsertRowCB (int panel, int control, int event,
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
//*******************************************************************************************************************
int CVICALLBACK MAODeleteRowCB (int panel, int control, int event,
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
//*******************************************************************************************************************
int CVICALLBACK MDIOInsertRowCB (int panel, int control, int event,
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
//*******************************************************************************************************************
int CVICALLBACK MIODeleteRowCB (int panel, int control, int event,
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
//*******************************************************************************************************************
int CVICALLBACK MIOCFGExit2CB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
						#if USE_EXT_MAIN_PROJ
							DIOViewMenu=0;
							///EnableDIOControlSaving();
							CheckError(HidePanel(MIOPanelHandle2)); 
						#else		
							QuitUserInterface (0);
						#endif
			break;
		case EVENT_KEYPRESS:

			break;
	}
	return 0;
}
