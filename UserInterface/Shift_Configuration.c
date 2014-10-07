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
*    @file    Shift_Configuration.c
*    @brief   Function related to shift configuration panel
*    @author  Arxtron Technologies Inc.
*    @date    2013.9.6
*    Functions to display, parse and save the shift configuration panel
*    
*/
 
#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>
#include "Global.h" 
#include "DataLib.h"
#include "Shift_Configuration.h"
#include "Shift_Configuration_Def.h"


#if USE_EXT_MAIN_PROJ

#else
//int main (int argc, char *argv[])
//{
//	if (InitCVIRTE (0, argv, 0) == 0)
//		return -1;	//* out of memory /
//	if ((ShiftPanelHandle = LoadPanel (0, "Shift_Configuration.uir", SHIFT_PNL)) < 0)
//		return -1;
//
//	GetShiftCofigDirectory();
//	InitShiftConfiguration(); 
//	DisplayPanel (ShiftPanelHandle);
//	SetDataToShiftTable(SHIFT_PNL_SHIFT_CONFIG_TABLE); 	
//	RunUserInterface ();
//	DiscardPanel (ShiftPanelHandle);
//	return 0;
//}
#endif
//*******************************************************************************************************************
/********************************************//**
*Display current shift configuration
***********************************************/
void DisplayShiftConfiguration(int Edit)
{
	DisplayPanel (ShiftPanelHandle);
	if(Edit)
	{
		SetCtrlAttribute(ShiftPanelHandle, SHIFT_PNL_SAVE, ATTR_VISIBLE, GLB_TRUE);
	}
	else
	{
		SetCtrlAttribute(ShiftPanelHandle, SHIFT_PNL_SAVE, ATTR_VISIBLE, GLB_FALSE);
	}

	SetDataToShiftTable(SHIFT_PNL_SHIFT_CONFIG_TABLE); 
	SetCtrlAttribute (ShiftPanelHandle, SHIFT_PNL_DATE_CODE_TIMER, ATTR_ENABLED, GLB_TRUE);
}
//*******************************************************************************************************************
/********************************************//**
*Get directory where shift configuration is stored
***********************************************/
void GetShiftCofigDirectory(void)
{
	char dir[260], path[260];
	
	GetProjectDir(dir);
	sprintf(path, "%s%s", dir,"\\Configuration\\");
	
	sprintf(SC_int_dir, "\\%s.txt", "SC_File");                             
	sprintf(SC_ext_dir, "%s%s",path, "SC_File.txt"); 
	sprintf(SC_int_xls, "\\%s.csv", "SC_File");                             	
	sprintf(SC_ext_xls, "%s%s", path, "SC_File.csv"); 	
	sprintf(SC_ext_dir, "%s%s", path, "SC_File.txt");
	sprintf(SC_ext_uir, "%s%s", path,"Shift_Configuration.uir");
	sprintf(SC_int_uir, "\\Shift_Configuration.uir");
}
//*******************************************************************************************************************
int CVICALLBACK ShiftTableCB (int panel, int control, int event,
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
/********************************************//**
*Saving shift configuration
***********************************************/
int CVICALLBACK ShiftConfigSaveCB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
		{
		case EVENT_COMMIT:
			 WriteShiftConfiguration();
			break;
		}
	return 0;
}
//*******************************************************************************************************************
/********************************************//**
*exit shift configuration panel
***********************************************/
int CVICALLBACK ShiftConfigExitCB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
		{
		case EVENT_COMMIT:
			SetCtrlAttribute (ShiftPanelHandle, SHIFT_PNL_DATE_CODE_TIMER, ATTR_ENABLED, GLB_FALSE);
			//#if USE_EXT_MAIN_PROJ
				CheckError(HidePanel(ShiftPanelHandle)); 
		//	#else		
		//		QuitUserInterface (0);
		//	#endif
			break;
		}
	return 0;
}
//*******************************************************************************************************************
/********************************************//**
* Initilize shift configuration panel
***********************************************/
void InitShiftConfiguration(void)
{
	int  row;
	char SC_dir[MAX_PATHNAME_LEN];
	FILE *fp;

	MakeProjectDirPath(SC_ext_dir, SC_int_dir, SC_dir);
// -----------------------------------------------------------------------------------------------------------------------	
	if(VerifyOpenFileRead(/***SC_dir***/SC_ext_dir, "rb", &fp))
	{ 	rewind(fp);
		Shift_Config_file_exist=GLB_TRUE;
		
		for(row=0;row<DAYOFTHEWEEK_SIZE;row++) 
		{   
		 	fread( Shift_Configuration.S_Day[row],      	sizeof(char),   100,  	fp);
			fread(&Shift_Configuration.S_1HR[row],      	sizeof(int), 	1,   	fp);
			fread(&Shift_Configuration.S_1MIN[row],     	sizeof(int), 	1,   	fp);
			fread(&Shift_Configuration.S_2HR[row],      	sizeof(int),  	1,   	fp);
			fread(&Shift_Configuration.S_2MIN[row],     	sizeof(int), 	1,   	fp);
			fread(&Shift_Configuration.S_3HR[row],      	sizeof(int), 	1,   	fp);
			fread(&Shift_Configuration.S_3MIN[row],     	sizeof(int), 	1,   	fp);
		}	
		fclose(fp);
	}
	return;	
}
//*******************************************************************************************************************
/********************************************//**
*Get data from shift configuration table
***********************************************/
void GetDataFromShiftTable(int data_table)
{
	int row, col, tbl_ctrl;
	
	if(data_table==SHIFT_PNL_SHIFT_CONFIG_TABLE)
	{	
		tbl_ctrl=SHIFT_PNL_SHIFT_CONFIG_TABLE;
		for(row=1;row<=DAYOFTHEWEEK_SIZE;row++)
		{	col=1;
 
				GetTableCellVal(ShiftPanelHandle, tbl_ctrl, MakePoint(col++,row),  Shift_Configuration.S_Day[row-1]);
				GetTableCellVal(ShiftPanelHandle, tbl_ctrl, MakePoint(col++,row), &Shift_Configuration.S_1HR[row-1]);
				GetTableCellVal(ShiftPanelHandle, tbl_ctrl, MakePoint(col++,row), &Shift_Configuration.S_1MIN[row-1]);
				GetTableCellVal(ShiftPanelHandle, tbl_ctrl, MakePoint(col++,row), &Shift_Configuration.S_2HR[row-1]);
				GetTableCellVal(ShiftPanelHandle, tbl_ctrl, MakePoint(col++,row), &Shift_Configuration.S_2MIN[row-1]);
				GetTableCellVal(ShiftPanelHandle, tbl_ctrl, MakePoint(col++,row), &Shift_Configuration.S_3HR[row-1]);
				GetTableCellVal(ShiftPanelHandle, tbl_ctrl, MakePoint(col++,row), &Shift_Configuration.S_3MIN[row-1]);
		}	
	}	
	return;
}
//*******************************************************************************************************************
/********************************************//**
* Set data on shift configuration table
***********************************************/
void SetDataToShiftTable(int data_table)
{
	int row, col, tbl_ctrl;
	
	if(data_table==SHIFT_PNL_SHIFT_CONFIG_TABLE)
	{	
		tbl_ctrl=SHIFT_PNL_SHIFT_CONFIG_TABLE;
		for(row=1;row<=DAYOFTHEWEEK_SIZE;row++)
		{	col=1;
				SetTableCellVal(ShiftPanelHandle, tbl_ctrl, MakePoint(col++,row),  Shift_Configuration.S_Day[row-1]);
				SetTableCellVal(ShiftPanelHandle, tbl_ctrl, MakePoint(col++,row),  Shift_Configuration.S_1HR[row-1]);
				SetTableCellVal(ShiftPanelHandle, tbl_ctrl, MakePoint(col++,row),  Shift_Configuration.S_1MIN[row-1]);
				SetTableCellVal(ShiftPanelHandle, tbl_ctrl, MakePoint(col++,row),  Shift_Configuration.S_2HR[row-1]);
				SetTableCellVal(ShiftPanelHandle, tbl_ctrl, MakePoint(col++,row),  Shift_Configuration.S_2MIN[row-1]);
				SetTableCellVal(ShiftPanelHandle, tbl_ctrl, MakePoint(col++,row),  Shift_Configuration.S_3HR[row-1]);
				SetTableCellVal(ShiftPanelHandle, tbl_ctrl, MakePoint(col++,row),  Shift_Configuration.S_3MIN[row-1]);
		}	
	}	
	return;
}
// =======================================================================================================================
/********************************************//**
* write shift configuration to file
***********************************************/
void WriteShiftConfiguration(void)
{
	int  row, actv_pnl, WriteReturn;
	char xls_dir[MAX_PATHNAME_LEN], bin_dir[MAX_PATHNAME_LEN];
	FILE *xls_fp, *bin_fp;
	boolean xls_file, bin_file;

	MakeProjectDirPath(SC_int_xls, SC_int_xls, xls_dir);	// make excel directory for configuration data
	MakeProjectDirPath(SC_int_dir, SC_int_dir, bin_dir);	// make binary directory for configuration data
	MakeBackUpCopy(bin_dir);								// make backup copy before overwriting data file
	
	xls_file=VerifyOpenFileWrite(xls_dir, "w",  &xls_fp);
	bin_file=VerifyOpenFileWrite(bin_dir, "wb", &bin_fp);
// -----------------------------------------------------------------------------------------------------------------------				 				
	if(xls_file && bin_file)
	{	actv_pnl=GetActivePanel();
		if(actv_pnl==ShiftPanelHandle) GetDataFromShiftTable(SHIFT_PNL_SHIFT_CONFIG_TABLE);

		// write header for excel data file
		fprintf(xls_fp,"%s EOL Tester: Shift Configuration Data\n", "SC_File");
      	fprintf(xls_fp,"\n");
// -----------------------------------------------------------------------------------------------------------------------				 						
		for(row=0;row<DAYOFTHEWEEK_SIZE;row++)
		{   // write test executive data to data file
		 	WriteReturn=fwrite( Shift_Configuration.S_Day[row],      	sizeof(char),   100,  bin_fp);
			WriteReturn=fwrite(&Shift_Configuration.S_1HR[row],      	sizeof(int), 1,   bin_fp);
			WriteReturn=fwrite(&Shift_Configuration.S_1MIN[row],     	sizeof(int), 1,   bin_fp);
			WriteReturn=fwrite(&Shift_Configuration.S_2HR[row],      	sizeof(int), 1,   bin_fp);
			WriteReturn=fwrite(&Shift_Configuration.S_2MIN[row],     	sizeof(int), 1,   bin_fp);
			WriteReturn=fwrite(&Shift_Configuration.S_3HR[row],      	sizeof(int), 1,   bin_fp);
			WriteReturn=fwrite(&Shift_Configuration.S_3MIN[row],     	sizeof(int), 1,   bin_fp);
			
			// write data to excel data file
			fprintf(xls_fp, "%s,", Shift_Configuration.S_Day[row]);
			fprintf(xls_fp, "%d,", Shift_Configuration.S_1HR[row]);
			fprintf(xls_fp, "%d,", Shift_Configuration.S_1MIN[row]);
			fprintf(xls_fp, "%d,", Shift_Configuration.S_2HR[row]);
			fprintf(xls_fp, "%d,", Shift_Configuration.S_2MIN[row]);
			fprintf(xls_fp, "%d,", Shift_Configuration.S_3HR[row]);
			fprintf(xls_fp, "%d,", Shift_Configuration.S_3MIN[row]);
			fprintf(xls_fp,"\n");
		}
		fclose(bin_fp);
		fclose(xls_fp);
	}	
}

/********************************************//**
* Shift string callback
***********************************************/
//*******************************************************************************************************************
int CVICALLBACK ShiftStringCB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
		{
		case EVENT_COMMIT:
			 GetTextBoxLine (ShiftPanelHandle,SHIFT_PNL_SHIFT_STRING,0, Shift_Str);
			break;
		}
	return 0;
}
//*******************************************************************************************************************
/********************************************//**
* Date code timer
***********************************************/
int CVICALLBACK DateCodeTimer (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
    char       TempStr[100], RowData[256]="";
	const time_t*	ConstCurrentTime;
	time_t			GetCurrentTime, CurrentTime;
    
	switch (event)
		{
		case EVENT_TIMER_TICK:
			 GetDateCode(ShiftPanelHandle, SHIFT_PNL_SHIFT_STRING);
			 Fmt (TempStr, "%d", shift);
			 SetCtrlVal (ShiftPanelHandle,SHIFT_PNL_SHIFT_STRING,TempStr);
			 CurrentTime=time (&GetCurrentTime);
			 ConstCurrentTime=&CurrentTime;
			 strcpy(RowData,asctime(localtime (ConstCurrentTime))); 
			 SetCtrlVal(ShiftPanelHandle, SHIFT_PNL_CURRENT_TIME, RowData); 
			break;
		}
	return 0;
}
//*******************************************************************************************************************
