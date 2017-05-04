/*!
*    @file    PartSelect.c
*    @brief   Communicate with SQL server on Recipe station and load recipe Table 
*    @author  Arxtron Technologies Inc.
*    @date    2013.9.6
*    Communicate with SQL server on Recipe station and load recipe Table with information 
*    about the C6 board.
*    
*/
#include "cvi_db.h"
#include <ansi_c.h>
#include <cvirte.h>		
#include <userint.h>
#include "cvixml.h"
#include "PartSelect.h"
#include "PartSelect_DEF.h"
#include "Global.h"
#include "DataLib.h"
#include "frmError.h"
#include "TestSteps.h"
#include "Measurements.h"
#include "frmMain.h"
#include <utility.h>  
#include "ParseCSV.h"
#include "nbmailbox.h"
#include "TextUtils.h" 


void ShowDBError(void) ;
int GetUnitFields(void);
int currentlySelectedFlag=0;
int CVICALLBACK RecipeExitCB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			if(currentlySelectedFlag==0)
			{
				MessagePopup("Error","Please select one of the table row before clicking Ok");
			}
			else
			{
				//SaveToAppConfig();
				//LoadSelectedRecipe();
				GetUnitFields();
				ReadMailBoxPointsDataXML(); 
				
				
				DiscardPanel(PartSelectPanelHandle);
				SetCtrlAttribute (MainPanelHandle, Main_START_TIMER, ATTR_ENABLED, 1);
				PartSelectPanelHandle =0;
			}

			break;
	}
	return 0;
}

int CVICALLBACK RecipeTableCB (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			break;
	//	case EVENT_LEFT_DOUBLE_CLICK:
	//		RecipeExitCB (panel, PS_PNL_RECIPE__EXIT, EVENT_COMMIT, 0, 0, 0);
			
		case EVENT_LEFT_CLICK_UP:
			 currentlySelectedFlag=1; 
			 Point ptA;
			 char value[255]={0};
			 char valueToSet[1000]={0};
			 int numCol=0;
			 
			 GetActiveTableCell(PartSelectPanelHandle,PS_PNL_RECIPE_TABLE,&ptA);
			 GetNumTableColumns(PartSelectPanelHandle,PS_PNL_RECIPE_TABLE,&numCol);
			 SetTableSelection (panel, control, MakeRect (ptA.y, 1, 1, numCol));

			 sprintf(valueToSet,"Row #%d: ",ptA.y); 
			 for(int i=1;i<=numCol;i++)
			 {
				GetTableCellVal(PartSelectPanelHandle,PS_PNL_RECIPE_TABLE,MakePoint(i,ptA.y),value);
				sprintf(valueToSet,"%s%s, ",valueToSet,value);
			 }
			 SetCtrlVal (PartSelectPanelHandle, PS_PNL_txtTestFile0, valueToSet);
			break;
	}
	return 0;
}

/********************************************//**
 *  This fucntion reads the SQL database and Loads the table in the database
 *  into the recipe table which is used by the operator to select the correct version.
 ***********************************************/
int loadTableFromDatabase(char DSN[100],char UserID[100],char Password[100])
{
	int gHDBC=0;
	int hStmt;
	char connectString[300] ={0} ;
	char databaseName[] = {"Recipe"} ;
	//char SQLCommand[] = {"Select Recipe.ID,RecipeNumber,PartNumber1,AutolivPN1,TesterFile1.TesterFile, TesterFile2.TesterFile, TesterFile3.TesterFile, dbo.Recipe.Description from dbo.Recipe,TesterProfileData,TesterFile1, TesterFile2, TesterFile3 where Recipe.ID = TesterProfileData.ID AND TesterFile1.TesterFileID = TesterProfileData.TesterFile1 AND TesterFile2.TesterFileID = TesterProfileData.TesterFile2 AND TesterFile3.TesterFileID = TesterProfileData.TesterFile3"};
	
	char AEC_Backend[10];
	strcpy(AEC_Backend,GetCfgMiscValue("BackendLineID",80));
//TesterDataView.TesterFile1,TesterDataView.TesterFile4,TesterDataView.TesterFile5	
//	char SQLCommand[] = {"Select Recipe.ID,RecipeNumber,PartNumber1,AutolivPN1,AutolivPN2,ProductParamProfileData.ProductParam1,ProductParamProfileData.ProductParam11,ProductParamProfileData.ProductParam17,ModuleProfileData.ModuleParam1,ModuleProfileData.ModuleParam2,ModuleProfileData.ModuleParam3,dbo.Recipe.Description from dbo.Recipe,ProductParamProfileData,ModuleProfileData where Recipe.ID = ProductParamProfileData.ID AND Recipe.ID = ModuleProfileData.ID"};	
//	char SQLCommand[] = {"Select Recipe.ID,Recipe.RecipeNumber,PartNumber1,AutolivPN1,AutolivPN2,TesterDataView.TesterFile1, TesterDataView.TesterFile2,TesterDataView.TesterFile6,ProductParamProfileData.ProductParam1,ProductParamProfileData.ProductParam11,ProductParamProfileData.ProductParam17,ModuleProfileData.ModuleParam1,ModuleProfileData.ModuleParam2,ModuleProfileData.ModuleParam3,dbo.Recipe.Description from dbo.Recipe,ProductParamProfileData,ModuleProfileData, TesterDataView where Recipe.ID = ProductParamProfileData.ID AND Recipe.ID = ModuleProfileData.ID AND Recipe.ID = TesterDataView.ID"};	
//	char SQLCommand[] = {"Select Recipe.ID,Recipe.RecipeNumber,ProductParamProfileData.ProductParam1,ProductParamProfileData.ProductParam11,ProductParamProfileData.ProductParam17,TesterDataView.TesterFile1, TesterDataView.TesterFile4,TesterDataView.TesterFile5,ModuleProfileData.ModuleParam1,ModuleProfileData.ModuleParam2,ModuleProfileData.ModuleParam3,dbo.Recipe.Description from dbo.Recipe,ProductParamProfileData,ModuleProfileData, TesterDataView where Recipe.ID = ProductParamProfileData.ID AND Recipe.ID = ModuleProfileData.ID AND Recipe.ID = TesterDataView.ID"};	
//	char SQLCommand[] = {"Select Recipe.RecipeNumber,dbo.Recipe.Description, ProductParamProfileData.ProductParam1,ProductParamProfileData.ProductParam11,TesterDataView.TesterData1,TesterDataView.TesterData2,TesterDataView.TesterFile1, TesterDataView.TesterFile4,TesterDataView.TesterFile5,TesterDataView.TesterFile15,TesterDataView.TesterFile12,TesterDataView.TesterFile10 from dbo.Recipe,ProductParamProfileData,TesterDataView where Recipe.ID = ProductParamProfileData.ID AND Recipe.ID = TesterDataView.ID"};	
//	char SQLCommand[] = {"Select * from TesterDataView"};	
	char SQLCommand[10000] = "";
	sprintf(SQLCommand,"%s%s%s","Select Recipe.RecipeNumber,dbo.Recipe.Description, ProductParamProfileData.ProductParam1,ProductParamProfileData.ProductParam11,TesterDataView.TesterData1,TesterDataView.TesterData2,TesterDataView.TesterFile1, TesterDataView.TesterFile4,TesterDataView.TesterFile5,TesterDataView.TesterFile15,TesterDataView.TesterFile12,TesterDataView.TesterFile10, TesterDataView.Enabled from dbo.Recipe,ProductParamProfileData,TesterDataView where Recipe.ID = ProductParamProfileData.ID AND Recipe.ID = TesterDataView.ID AND TesterDataView.Enabled = 'true'", "AND TesterDataView.LineID = ", AEC_Backend);
	char tempChar[200]={0};
	char *colName;
	int numCols;
	int numRows;
	int status;
	int colWidth=0; 
	char cellChar[257];
	int columnWidthsize,maxColumnWidthSize;
	int resCode;
	
	sprintf(connectString,"DSN=%s;UID=%s;PWD=%s; MODIFYSQL=1",DSN,UserID,Password);
	gHDBC = DBConnect(connectString);
	if( gHDBC <= 0)
	{
		ShowDBError();
		return 1;
	}
	resCode = DBSetDatabase(gHDBC,databaseName);
	if (resCode < 0)
	{ 
		ShowDBError();
		return 2;
	}
	hStmt = DBActivateSQL (gHDBC, SQLCommand);
	if (hStmt <= 0)
	{
		MessagePopup("Failed to activate SQL CMD", SQLCommand);
		return 3;
	}
	numCols = DBNumberOfColumns (hStmt);
	numRows = DBNumberOfRecords(  hStmt);
	if(numRows <0 || numCols<0)
	{
		MessagePopup("SQL ERROR","Empty table found in database"); 
		return 4;
	}
	//generate rows and columns
	InsertTableRows(PartSelectPanelHandle,PS_PNL_RECIPE_TABLE,1,numRows,VAL_CELL_STRING);
	InsertTableColumns( PartSelectPanelHandle,PS_PNL_RECIPE_TABLE,1,numCols,VAL_CELL_STRING);

	resCode = DBDeactivateSQL (hStmt);

	//Load the recipe table with data from sql server.
	for(int j=1;j<= numCols;j++)
	{
		hStmt = DBActivateSQL (gHDBC, SQLCommand);   
		colWidth = DBColumnWidth(hStmt, j);
		resCode = DBBindColChar(hStmt, j, colWidth + 1,cellChar , &status, "");
		colName = DBColumnName (hStmt, j);
		//Set column name
		
//		ProductParam1: Board Flavour ID
//ProductParam11: Product ID (can be used to determine
//Honda vs. GM vs. FIAT). Product ID Values: Honda, GM, Fiat
//ProductParam17: Label ID
		
		if (stricmp(colName,"ProductParam1") == 0)
			strcpy(colName,"FlavourID");
		if (stricmp(colName,"ProductParam11") == 0)
			strcpy(colName,"ProductID");
		if (stricmp(colName,"TesterData1") == 0)
			strcpy(colName,"VariantPN");
		if (stricmp(colName,"TesterData2") == 0)
			strcpy(colName,"ProgramName");	
		if (stricmp(colName,"TesterFile1") == 0)
			strcpy(colName,"Folder");
		if (stricmp(colName,"TesterFile4") == 0)
			strcpy(colName,"MailBox");
		if (stricmp(colName,"TesterFile5") == 0)
			strcpy(colName,"VariantCSV");		
		
		
		SetTableColumnAttribute(PartSelectPanelHandle, PS_PNL_RECIPE_TABLE,j,ATTR_LABEL_TEXT ,colName);
		//SetTableColumnAttribute(PartSelectPanelHandle, PS_PNL_RECIPE_TABLE,j,ATTR_LABEL_COLOR  ,VAL_WHITE);
		SetTableColumnAttribute(PartSelectPanelHandle, PS_PNL_RECIPE_TABLE,j,ATTR_USE_LABEL_TEXT ,1);
		maxColumnWidthSize=0;
		
		for(int i=1;i<=numRows;i++)
		{
			 resCode = DBFetchNext(hStmt);
			 sprintf(cellChar,"%s", replaceChar(cellChar,'\n', '\0'));
			  sprintf(cellChar,"%s", replaceChar(cellChar,'\r', '\0')); 
			 SetTableCellVal(PartSelectPanelHandle,PS_PNL_RECIPE_TABLE, MakePoint(j,i),cellChar);
			 
			 columnWidthsize = strlen(cellChar)*8;
			 if(columnWidthsize<60)
				 columnWidthsize =80;
			 if(columnWidthsize > maxColumnWidthSize)
				 maxColumnWidthSize = columnWidthsize;
			 if(maxColumnWidthSize < 60)
				 maxColumnWidthSize = 80;
			 SetTableCellAttribute(PartSelectPanelHandle,PS_PNL_RECIPE_TABLE,MakePoint(j,i),ATTR_NO_EDIT_TEXT ,1);
		}
		SetTableColumnAttribute(PartSelectPanelHandle, PS_PNL_RECIPE_TABLE,j,ATTR_COLUMN_WIDTH, maxColumnWidthSize); 
		SetTableColumnAttribute(PartSelectPanelHandle, PS_PNL_RECIPE_TABLE,j,ATTR_NO_EDIT_TEXT,1);    
		resCode = DBDeactivateSQL (hStmt); 
	}
	SetActiveTableCell(PartSelectPanelHandle,PS_PNL_RECIPE_TABLE,MakePoint(2,numRows));
	return 0;
} // end loadTableFromDatabase


/********************************************//**
 *  This functions gets the DBErrorMessage and puts in a MessagePopup.
 ***********************************************/
void ShowDBError(void)
{
    int status;
    status = MessagePopup ("Database Error", DBErrorMessage());

    if (status<0) 
		QuitUserInterface(0);
    else return;
}
/********************************************//**
 *  This functions saves the selected row from the recipe table into teh app_config xml file.
 ***********************************************/
int SaveToAppConfig(void)
{
	int error;
	CVIXMLDocument   doc=0;   
	CVIXMLElement    curElem = 0;
    CVIXMLElement 	 childElem = 0;
	char rootTag[]={"Configuration"};
	int numChildren;
	char tag[120];
	char value[120];
	char msg[100];
	char dir[MAX_PATHNAME_LEN];
	char filePath[MAX_PATHNAME_LEN];
	Point ptA;
	char cellValue[255]={0};
	int numCol=0;
	char columnLabel[100]={0};
	int tagFoundFlag=0;
	GetActiveTableCell(PartSelectPanelHandle,PS_PNL_RECIPE_TABLE,&ptA);
	GetNumTableColumns(PartSelectPanelHandle,PS_PNL_RECIPE_TABLE,&numCol);
		 
	GetProjectDir(dir);
	sprintf(filePath,"%s%s",dir,"\\Configuration\\app_config.xml");

	CVIXMLLoadDocument(filePath,&doc);
	CVIXMLNewDocument(rootTag,&doc);
	CVIXMLGetRootElement(doc,&curElem);
	
	
	for(int i=1;i<=numCol;i++)
	{
		tagFoundFlag=0;
		CVIXMLGetNumChildElements(curElem,&numChildren); 
		GetTableColumnAttribute(PartSelectPanelHandle, PS_PNL_RECIPE_TABLE, i, ATTR_LABEL_TEXT , columnLabel);
		if(i==5)
			sprintf(columnLabel,"%s1",columnLabel);
		if(i==6)
			sprintf(columnLabel,"%s2",columnLabel);
		if(i==7)
			sprintf(columnLabel,"%s3",columnLabel);
		GetTableCellVal(PartSelectPanelHandle,PS_PNL_RECIPE_TABLE,MakePoint(i,ptA.y),cellValue);
		for (int j=0;j<numChildren;j++) 
		{
			CVIXMLGetChildElementByIndex(curElem,j,&childElem);
			CVIXMLGetElementTag(childElem,tag);
			if (strcmp(tag,columnLabel)==0)
			{
				CVIXMLSetElementValue(childElem,cellValue);
				tagFoundFlag =1;
				break;
			}
			if (childElem)
			{
				CVIXMLDiscardElement(childElem);
			}
		}
		if(tagFoundFlag==0)
		{
			CVIXMLNewElement(curElem,0,columnLabel,&childElem);
			CVIXMLSetElementValue(childElem,cellValue);
			CVIXMLDiscardElement(childElem);
		}
	}
	
	error = CVIXMLSaveDocument(doc,1,NULL);
	if (error != 0)
	{
		sprintf(msg,"Unable to save xml file %s",filePath);
		MessagePopup("Error",msg);
		return(-1);
	}

	// release and free xml memory
	if (childElem)
	{
		CVIXMLDiscardElement(childElem);
	}
	if (curElem)
	{
		CVIXMLDiscardElement(curElem);
	}
	if (doc)
	{
		CVIXMLDiscardDocument(doc);
	}
	return 0;	
}

int copyFileLocallyTestpoint(char * filePath, char * filePathStr) 
{
	//char filePathStr[MAX_PATHNAME_LEN];
	char projDir[MAX_PATHNAME_LEN];
	char tmpMsg[500]; 
	
	GetProjectDir(projDir);
	sprintf(filePathStr,"%s\\%s",projDir,GetFileName(filePath));
	if(CopyFile(filePath,filePathStr))
	{
		sprintf(tmpMsg,"Unable to copy %s file locally from the path specified in configuration",GetFileName(filePath));
		MessagePopup("Copy Error", tmpMsg);
		return 1;
	}
	
	return(0);			
}
/********************************************//**
 *  This functions copy's file from specified path to a local path
 ***********************************************/
int copyFileLocally(char * filePath, char * filePathStr) 
{
	//char filePathStr[MAX_PATHNAME_LEN];
	char projDir[MAX_PATHNAME_LEN];
	char tmpMsg[500]; 
	
	GetProjectDir(projDir);
	sprintf(filePathStr,"%s\\Data\\%s",projDir,GetFileName(filePath));
	if(CopyFile(filePath,filePathStr))
	{
		sprintf(tmpMsg,"Unable to copy %s file locally from the path specified in configuration",GetFileName(filePath));
		//MessagePopup("Copy Error", tmpMsg);
		return 1;
	}
	
	return(0);			
}
/********************************************//**
 *  This functions seperates the file name from the file path
 ***********************************************/
char *GetFileName( char *path)
{
    char *filename = strrchr(path, '\\');
    if (filename == NULL)
        filename = path;
    else
        filename++;
    return filename;
}
/********************************************//**
 *  This functions saves the selected row from the recipe table into teh app_config xml file.
 ***********************************************/
int GetUnitFields(void)
{
	int error;
	Point ptA;
	int numChildren;
	char value[120];
	char msg[100];
	char cellValue[255]={0};
	char remoteDrive[256] = {0};
	char tempFolder[256] = {0};
	char tempMailBox[256] = {0};
	char tempVariantCSV[256] = {0};
 	char dir[MAX_PATHNAME_LEN];
	char targetTestStepFileName[MAX_PATHNAME_LEN];
	int numCol=0;
	char columnLabel[100]={0};
	CVIXMLElement rootElement;
	char TestStepsHonda[100]={0};
	char TestStepsFiat[100]={0};
	char TestStepsGM[100]={0};


	
	char errorMsg[512]={0};
	
   	int code = deleteAllFiles (errorMsg);
	
	if (code<-1)
		MessagePopup("SQL files Download",errorMsg);	
	
	GetActiveTableCell(PartSelectPanelHandle,PS_PNL_RECIPE_TABLE,&ptA);
	GetNumTableColumns(PartSelectPanelHandle,PS_PNL_RECIPE_TABLE,&numCol);
	
	strcpy(remoteDrive,GetCfgMiscValue("RemoteDrive",80));
//	initnbsqlField();	 
	for(int i=1;i<=numCol;i++)
	{
		GetTableColumnAttribute(PartSelectPanelHandle, PS_PNL_RECIPE_TABLE, i, ATTR_LABEL_TEXT , columnLabel);

		GetTableCellVal(PartSelectPanelHandle,PS_PNL_RECIPE_TABLE,MakePoint(i,ptA.y),cellValue);

		if (stricmp(columnLabel,"FlavourID") == 0)
			selRecipe.FlavorId = atoi(cellValue);
		else if (stricmp(columnLabel,"ProductID") == 0)
			strcpy(selRecipe.Customer,cellValue);
		else if (stricmp(columnLabel,"RecipeNumber") == 0)
			strcpy(selRecipe.Recipe,cellValue);
		else if (stricmp(columnLabel,"VariantPN") == 0)
			strcpy(selRecipe.Variant,cellValue);
		else if (stricmp(columnLabel,"ProgramName") == 0)
			strcpy(selRecipe.PartNum,cellValue);
		else if (stricmp(columnLabel,"TesterFile15") == 0)
			strcpy(TestStepsHonda,cellValue);		
		else if (stricmp(columnLabel,"TesterFile12") == 0)
			strcpy(TestStepsGM,cellValue);		
		else if (stricmp(columnLabel,"TesterFile10") == 0)
			strcpy(TestStepsFiat,cellValue);		
		else if (stricmp(columnLabel,"Folder") == 0)
		{
			CopyString(tempFolder,0,cellValue,2,strlen(cellValue)-2);
		    sprintf(selRecipe.remoteFolder,"%s%s\\%s",remoteDrive,tempFolder,"TestPointList.nbpxml");
		}
		else if (stricmp(columnLabel,"MailBox") == 0)
		{
			CopyString(tempMailBox,0,cellValue,2,strlen(cellValue)-2);
			sprintf(selRecipe.remoteMailBox,"%s%s",remoteDrive,tempMailBox); 
		}
		else if (stricmp(columnLabel,"VariantCSV") == 0)
		{
			CopyString(tempVariantCSV,0,cellValue,2,strlen(cellValue)-2);
			sprintf(selRecipe.remoteVariantCSV,"%s%s",remoteDrive,tempVariantCSV); 
		}
			
	}
	if ( copyFileLocally(selRecipe.remoteFolder,selRecipe.localFolder) )
	{
		MessagePopup("Cannot copy TestPointList.nbpxml", "Cannot copy TestPointList.nbpxml");
		exit (0);
	}
	if (copyFileLocally(selRecipe.remoteMailBox,selRecipe.localMailBox) && (strstr(selRecipe.remoteMailBox,"nbpdxml") != NULL))
	{
		MessagePopup("Cannot copy variant limit file", "Cannot copy the mailboxfile file"); 
		exit (0); 
	}
	if ( copyFileLocally(selRecipe.remoteVariantCSV,selRecipe.localVariantCSV) )
	{
		MessagePopup("Cannot copy variant limit file", "Cannot copy variant limit file"); 
		exit (0); 
	}	
	
	ParseCSV(selRecipe.localVariantCSV);  	
	GetProjectDir(dir);
	setPartNumber (selRecipe.Variant); 
	
	if (stricmp(getProductType(selRecipe.Variant),"Unknown Type") == 0)
	{
		MessagePopup("Variant does not exist in csv", "Variant does not exist in csv"); 
		exit (0); 
	}
	
	if (stricmp(selRecipe.Customer,"GM") == 0)
		sprintf(selRecipe.TestStepsFile,"%s.xml",TestStepsGM);
	else if ((stricmp(selRecipe.Customer,"Fiat") == 0) || (stricmp(selRecipe.Customer,"Chrysler") == 0) || (stricmp(selRecipe.Customer,"Alfa Romeo") == 0) ) // alex 20150317 added for Chrysler PV build
		sprintf(selRecipe.TestStepsFile,"%s.xml",TestStepsFiat);
	else if (stricmp(selRecipe.Customer,"Honda") == 0)
		sprintf(selRecipe.TestStepsFile,"%s.xml",TestStepsHonda);
	else 
	{		
		MessagePopup("Customer error", "Customer not defined in SQL"); 
		exit (0); 
	}

	strcpy (ProductType,getProductType(selRecipe.Variant)); 	
	sprintf(targetTestStepFileName,"%s\\Configuration\\%s",dir, selRecipe.TestStepsFile);
	rootElement = LoadConfigurationDocument(targetTestStepFileName);
	if (rootElement == 0)
	{		
		MessagePopup("Test Steps error", "Test Steps not defined in SQL"); 
		exit (0); 
	}		
	
	ParseXMLDocument(rootElement, 0);	
	//selRecipe.PartNum;
	//selRecipe.Recipe;
	return 0;	
}

/********************************************//**
 *  Load data from selected recipe 
 ***********************************************/
int LoadSelectedRecipe(void)
{
	CVIXMLElement rootElement;
	int error = 0;
	Point ptA;
	char cellValue[255]={0};
	int numCol=0;
	char columnLabel[100]={0};
	char dir[MAX_PATHNAME_LEN];
	char targetTestStepFileName[MAX_PATHNAME_LEN];
	
	// Get Selected Recipe table
	GetActiveTableCell(PartSelectPanelHandle,PS_PNL_RECIPE_TABLE,&ptA);
	GetNumTableColumns(PartSelectPanelHandle,PS_PNL_RECIPE_TABLE,&numCol);
	
	if (numCol > 0)
	{
		for(int i=1;i<=numCol;i++)
		{
			GetTableColumnAttribute(PartSelectPanelHandle, PS_PNL_RECIPE_TABLE, i, ATTR_LABEL_TEXT , columnLabel);
			GetTableCellVal(PartSelectPanelHandle,PS_PNL_RECIPE_TABLE,MakePoint(i,ptA.y),cellValue);
		
			if (strstr(columnLabel,"CalNum") != NULL)
			{
				selRecipe.CalNum = atoi(cellValue); 
			}
			else if (strstr(columnLabel,"FlavorId") != NULL)
			{
				selRecipe.FlavorId = atoi(cellValue); 
			}
			else if (strstr(columnLabel,"PartNum") != NULL)
			{
				strcpy(selRecipe.PartNum,cellValue);  
			}
			else if (strstr(columnLabel,"Customer") != NULL)
			{
				strcpy(selRecipe.Customer,cellValue);
			}
			else if (strstr(columnLabel,"Variant") != NULL)
			{
				strcpy(selRecipe.Variant,cellValue);
			}
			else if (strstr(columnLabel,"TestStepsFile") != NULL)
			{
				strcpy(selRecipe.TestStepsFile,cellValue); 
			}
			else if (strstr(columnLabel,"Descriptions") != NULL)
			{
				strcpy(selRecipe.Description,cellValue); 
			}
			else
			{
				// do nothing
			}
		
		} // end for loop
	}
	else
	{
		MessagePopup("Error","Select Recipe number of field column is empty");	
	} // end if
	
	GetProjectDir(dir);
	setPartNumber (selRecipe.Variant); 
	sprintf(selRecipe.TestStepsFile,"TestSteps%s.xml",getProductType(selRecipe.Variant));
	strcpy (ProductType,getProductType(selRecipe.Variant)); 	
	sprintf(targetTestStepFileName,"%s\\Configuration\\%s",dir, selRecipe.TestStepsFile);
	rootElement = LoadConfigurationDocument(targetTestStepFileName);
	ParseXMLDocument(rootElement, 0);
	
	if (error != 0)
	{
		MessagePopup("Error","Unable to copy TestStep file.");
	}
	return(error);
} // end LoadSelectedRecipe

/********************************************//**
 *  Load a local recipe configuration
 ***********************************************/
void LoadLocalRecipe(void)
{
	char dir[MAX_PATHNAME_LEN]={0};
	CVIXMLElement rootElement;
	char targetTestStepFileName[MAX_PATHNAME_LEN];
	selRecipe.CalNum = 1;
	selRecipe.FlavorId = 1516;
	strcpy(selRecipe.PartNum,"629554600A");
	strcpy(selRecipe.Customer,"Daimler");
	strcpy(selRecipe.Variant,"02");
	strcpy(selRecipe.TestStepsFile,"TestStepsnonGM.xml");
	GetProjectDir(dir);
	sprintf(targetTestStepFileName,"%s\\Configuration\\%s",dir, selRecipe.TestStepsFile);
	rootElement = LoadConfigurationDocument(targetTestStepFileName);
	ParseXMLDocument(rootElement, 0);
	strcpy(selRecipe.Description,"SRR ISBM");
} // end LoadLocalRecipe

/********************************************//**
 *  Delete all files in Data folder
 ***********************************************/
int deleteAllFiles(char * errMsg)
{
	
    char curDir[512]={0};
	char targetFiles[512]={0};
	int errorCode = -1;

	GetProjectDir(curDir);
	sprintf(targetFiles,"%s\\Data\\*.*",curDir);
	
	//for test only
	//int fileHdl = OpenFile ("Data\\kim.kim", VAL_WRITE_ONLY, VAL_OPEN_AS_IS, VAL_BINARY);

	errorCode = DeleteFile(targetFiles);
	
	switch (errorCode)
	{
		case 0:
			strcpy(errMsg,"Success.");
			break;
		case -1:
			strcpy(errMsg,"File not found or directory in path not found.");
			break;
		case -3:
			strcpy(errMsg,"General I/O error occurred.");
			break;
		case -4:
			strcpy(errMsg,"Insufficient memory to complete operation.");
			break;
		case -5:
			strcpy(errMsg,"Invalid path; for example, c:filename.");
			break;
		case -6:
			strcpy(errMsg,"Access denied. Check Data folder for locked files.");
			break;
		case -7:
			strcpy(errMsg,"Specified path is a directory, not a file.");
			break;
		default:
			strcpy(errMsg,"Error unknown.");
			break;
	}
	return errorCode;
	
	
}

