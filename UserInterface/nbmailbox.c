//==============================================================================
//
// Title:		nbmailbox.c
// Purpose:		A short description of the implementation.
//
// Created on:	05/06/2014 at 10:16:05 AM by Arxtron1.
// Copyright:	. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files

#include "nbmailbox.h"
#include "timeutils.h"

//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// Static global variables

short					NBMailboxFileExists = 0;
static unsigned int 	nNumberOfPoints = 0;
static	nbpoint			NBpoints[MAX_NUM_OF_POINTS];
static	nbpoint			ReadPoints[MAX_NUM_OF_POINTS];
static  int				WriteStatus[MAX_NUM_OF_POINTS];
static  int				ReadStatus[MAX_NUM_OF_POINTS];


//==============================================================================
// Static functions

//==============================================================================
// Global variables

//==============================================================================
// Global functions
/*==============================================================================
FUNCTION:
	1)	Check if mailbox file exist
	2)  If it does, read all the points and store in memory
 		for later use by the test





//=============================================================================*/
int ReadMailBoxPointsDataXML()
{
	int nAttributes = 0;;
    CVIXMLDocument   doc;
	CVIXMLElement    curElem = 0;
	CVIXMLElement 	 parentElem = 0;
	CVIXMLElement 	 childElem = 0;
	CVIXMLAttribute  Attribute = 0;
	char AttribName[128];
	char dir[MAX_PATHNAME_LEN] = "C:\\Main\\MailBoxFile\\623473419A.nbpdxml";
	char filePathName[MAX_PATHNAME_LEN];
	int numChildren = 0;
	char tag[120];
	char value[120];
	
	memset(AttribName,0,128);
	memset(filePathName,0,MAX_PATHNAME_LEN);

	// Check if NBMailbox file exists
//	GetProjectDir(filePathName);
//	strcat(filePathName,"\\MailBoxFile\\");
	strcpy(filePathName,selRecipe.localMailBox);
//	strcat(filePathName,".nbpdxml");

		
	WIN32_FIND_DATA FindFileData;
   	HANDLE handle = FindFirstFile(filePathName, &FindFileData);
   	int found = handle != INVALID_HANDLE_VALUE;
	if(found) 
	{
	   // File found close handle and continue.
	   FindClose(handle);
	   NBMailboxFileExists = 1;
	   
	}
	else
	{
		// Handle case when file not found. TBD
		NBMailboxFileExists = 0;
		return(0);
	}
	

	memset(AttribName,0,128);
	
	//---------------------------------------------------	
	//strcpy(filePathName,dir);	// just for testing
	//---------------------------------------------------	
	

	// load document
	CVIXMLLoadDocument(filePathName,&doc);
	CVIXMLGetRootElement(doc,&curElem);
	
	parentElem = curElem;
	
	CVIXMLGetChildElementByTag(parentElem,"Points", &curElem); 
	CVIXMLGetNumChildElements(curElem,&numChildren);
	nNumberOfPoints = numChildren;
	
	for (int i=0;i<numChildren;i++)
	{
		CVIXMLGetChildElementByIndex(curElem,i,&childElem);
		
		
		CVIXMLGetElementTag(childElem,tag);
		CVIXMLGetNumAttributes(childElem, &nAttributes);
		
		for(int j=0; j<nAttributes; j++)
		{
			CVIXMLGetAttributeByIndex(childElem, j, &Attribute);
			CVIXMLGetAttributeName(Attribute,AttribName);
			
			if(!strcmp(AttribName, "ID"))
			{
				CVIXMLGetAttributeValue(Attribute,NBpoints[i].ID);
			
			}
			else if(!strcmp(AttribName, "Value"))
			{
				CVIXMLGetAttributeValue(Attribute,NBpoints[i].Value);
			}
		}

	}

	return(0);			
		

}

/*=======================================================================================
	Test NB Write mailbox file data


========================================================================================*/
int WriteMailboxPoints(int testNumber, int nestNum, Alv_NarrowBand_SensorComm *nbsensor)   
{
	int nRet, stat, status;
 	unsigned short nID;
	
	nRet = 0;
	stat = 0;
	status = 0;

	for(int i=0; i<nNumberOfPoints; i++)
	{
		
		nID = atoi(NBpoints[i].ID);
		stat = write_to_point(nbsensor, nID, NBpoints[i].Value ,&status);
		WriteStatus[i] = status;
		strcpy(ReadPoints[i].ID,NBpoints[i].ID);
		strcpy(ReadPoints[i].Value,NBpoints[i].Value);
			
		//NonBlockDelay(0.3);
		
		if(status != 0)
			nRet += 1;
	}
	

	return nRet;
	
}


int CreateReportWriteMailbox(char *buf, char *ITACbuf)
{
	char str[64];
	char ITACstr[64];
	char code[32];
	

	for(int i=0; i<nNumberOfPoints; i++)
	{
		Get_ErrorCodeNBProtocolStatus(WriteStatus[i], code);
		sprintf(str,"P%s Value=%s        Status Code=%s,", NBpoints[i].ID, NBpoints[i].Value, code);
		strcat(buf,str);
		
		sprintf(ITACstr,"%s,%s,%s,", NBpoints[i].ID, NBpoints[i].Value, code);
		strcat(ITACbuf,ITACstr);
		
	}

	return 0;
}


/*=======================================================================================
	Test


========================================================================================*/
int VerifyMailboxPoints(int testNumber, int nestNum, Alv_NarrowBand_SensorComm* nbsensor)   
{
	int nRet, stat,status;
	unsigned short nID;
	char *Value;
	
	nRet = 0;
	stat = 0;
	status = 0;

	for(int i=0; i<nNumberOfPoints; i++)
	{

		nID = atoi(NBpoints[i].ID);
		stat = Read_Point(nbsensor, nID, &Value ,&status);
		ReadStatus[i] = status;
		strcpy(ReadPoints[i].ID,NBpoints[i].ID);
		strcpy(ReadPoints[i].Value,Value);

		if(status != 0)
			nRet += 1;
		
		if(strcmp(NBpoints[i].Value, Value) != 0)
			nRet += 1;
	}

	return nRet;
	
}


int CreateReportVerifyMailbox(char *buf, char *ITACbuf)
{

	char str[128];
	char ITACstr[64];
	char code[32];

	for(int i=0; i<nNumberOfPoints; i++)
	{
		
		Get_ErrorCodeNBProtocolStatus(WriteStatus[i], code);
		sprintf(str,"P%s Value=%s Exp. Value=%s    Status Code=%s,", NBpoints[i].ID, ReadPoints[i].Value, NBpoints[i].Value, code);
		strcat(buf,str);
		sprintf(ITACstr,"%s,%s,%s,", NBpoints[i].ID, NBpoints[i].Value, code);
		strcat(ITACbuf,ITACstr);
		
	}

	return 0;
	
}













