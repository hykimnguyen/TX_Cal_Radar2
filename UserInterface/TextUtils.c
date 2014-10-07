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
*    @file    TextUtils.c
*    @brief   Functions related to parse, formating text
*    @author  Arxtron Technologies Inc.
*    @date    2013.9.6
*    Functions related to parse, formating text   
*    
*/ 
#include <utility.h>
#include <userint.h>
#include "TextUtils.h"
#include <ansi_c.h>
#include <stdio.h>
#include <string.h>

/********************************************//**
*Convert from int to hex   
***********************************************/
void int_to_hex(int input_int, char * output_hex)
{
	/* convert int to hex in char */
	sprintf(output_hex,"%x",input_int);
}
/********************************************//**
* convert hex to int  
***********************************************/
void hex_to_int(char * input_hex,int output_int)
{
	/* convert char to hex to int */
	sscanf(input_hex,"%x",&output_int);
}
/********************************************//**
* Parse text  in the form label=value; find the value when given label.
***********************************************/
int parse (char * str, char * param, char * returnField)
{
  char temp[255]={0};
  char * pch;
  char * returnField_tmp;

  strcpy(temp,str);
  memset(returnField,0,strlen(returnField));
  
  pch = strtok (temp,",");
  
  while (pch != NULL)
  {
	//deleteSpaces(pch);
	if (returnField_tmp = strstr(pch,param))
	{
		pch = strtok (returnField_tmp,"="); 
		pch = strtok (NULL, "=");
		if (pch != NULL)
		{
			strcpy(returnField,pch);
			return 1;
		}
	}
    pch = strtok (NULL, ",");
  }
  return 0;
}
/********************************************//**
* remove spaces from string   
***********************************************/
void deleteSpaces(char* source)
{
  char * i = source;
  char * j = source;
  while( * j != 0)
  {
    * i = * j++;
    if(* i != ' ')
      i++;
  }
  * i = 0;
}
/********************************************//**
* Remove cariage return at the end
***********************************************/
void deleteTermination(char* source)
{
  char * i = source;
  char * j = source;
  while( * j != 0)
  {
    * i = * j++;
    if(* i != '\n')
      i++;
  }
  * i = 0;
}

/********************************************//**
* Replace a character  
***********************************************/
char *replaceChar(char *str1,char old, char new)
{
	char *str2 = str1;
	
	while(*str2)
	{
		if (*str2==old)
		{
			*str2 = new;
		}
		++str2;
	}
	return(str1);
}

/********************************************//**
*parse string and keep string const      
***********************************************/
int parse2 (const char * str, const char * param, char * returnField)
{
  char * pch;
  char * returnField_tmp;
  int paramFound = 0;
  char parseStr[256];
  strcpy(parseStr,str);							 
  deleteSpaces(parseStr); 
  
  memset(returnField,0,strlen(returnField));
  
  pch = strtok (parseStr,",");
  
  while (pch != NULL)
  {
	deleteSpaces(pch);
	if (returnField_tmp = strstr(pch,param))
	{
		pch = strtok (returnField_tmp,"="); 
		pch = strtok (NULL, "=");
		if (pch != NULL)
		{
			strcpy(returnField,pch);
			paramFound = 1;
			return 1;
		}
	}
    pch = strtok (NULL, ",");
  }
  if (paramFound==0)
  {
	  char msg[256];
	  sprintf(msg,"Can not parse %s using %s.",param,str);
	  MessagePopup("Input Error",msg); 
  }
  
  return 0;
}


/********************************************//**
* validate if the test sequence has all the proper input parameters         
***********************************************/
int validateTestSequenceInputs(const char *str, const char * params, int paramsSize)
{
	int retval;
	char myReturn[100];
	int error =0;
	char parseParams[80];
	strcpy(parseParams,params);
	
	// get list of parameters
	char myParams[paramsSize][100];
	
	char * pch;
  
  	pch = strtok (parseParams,",");
	int count = 0;
  	while (pch != NULL)
  	{
		deleteSpaces(pch); 
		strcpy(myParams[count],pch);
		count++;
    	pch = strtok (NULL, ",");
  	}
	
	// validate parameters list and display message if parameters is not in input list
	for (int i=0; i<paramsSize; i++)
	{
		retval = parse2(str,myParams[i],myReturn);
		if (retval == 0)
		{
			error=1;
		}
	}
	
	return(error);
}
/********************************************//**
* Find the Start and End index of each section in c6 EOL config file.    
***********************************************/
int findStartEndOfSection(char section[50],char fileArray[1000][500], int *start, int *end)
{
	char sectionsName[7][50]={"[eeprom_check]","[product]","[software_revisions]","[Extended_APP]","[software_load_enable]","[presoftware_load_E2P]","[softwareloadfile]"}; 
	*start=-1;
	*end=-1;
	for(int i=0;i<1000;i++)
	{
		if(*start==-1)
		{
			if(strstr(fileArray[i],section)!=NULL)
			{
				*start = i;
			}
		}
		else
		{
			for(int j=0; j<7;j++)
			{
				if(strstr(fileArray[i],sectionsName[j])!=NULL || strlen(fileArray[i])<2)
				{
					*end = i;
					break;
				}
			}	
		}
		if(*end!=-1) 
			break;
	}
	return 0;	
}  // end findStartEndOfSection

/********************************************//**
*  return min and max for value range separated by '-' or 'to'
***********************************************/
int ParseRange(char * field, char * separator, char * first, char * last)
{
	char temp[255]={0};
	char * pch;
	char * returnField_tmp;

	strcpy(temp,field);
	deleteSpaces(temp);
	
	if (returnField_tmp = strstr(temp,separator))
	{
		pch = strtok (temp,separator); 
		strcpy(first,pch);
		pch = strtok (NULL,separator); 
		strcpy(last,pch);
		return 1;
	}
	
	return  0;
	
}
