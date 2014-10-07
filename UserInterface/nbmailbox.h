//==============================================================================
//
// Title:		nbmailbox.h
// Purpose:		A short description of the interface.
//
// Created on:	05/06/2014 at 10:16:05 AM by Arxtron1.
// Copyright:	. All Rights Reserved.
//
//==============================================================================

#ifndef __nbmailbox_H__
#define __nbmailbox_H__

#ifdef __cplusplus
    extern "C" {
#endif

//==============================================================================
// Include files

#include <ansi_c.h>
#include "cvixml.h"
#include "cvidef.h"
#include <utility.h>
//#include "Global.h"
#include "measurements.h"


//==============================================================================
// Constants
#define POINT_NAME_LENGTH	36
#define POINT_VLUE_LENGTH	36
#define MAX_NUM_OF_POINTS	280		
#define MAX_PATHNAME_LEN	280		

		
//==============================================================================
// Types

//typedef enum{GLB_FALSE, GLB_TRUE}bool; 

typedef struct _nbpoint
{
	char ID[POINT_NAME_LENGTH];
	char Value[POINT_VLUE_LENGTH];

} nbpoint;

//==============================================================================
// External variables

//==============================================================================
// Global functions

		
//==============================================================================
// Include files

#include <ansi_c.h>
#include "cvixml.h"
#include "cvidef.h"
#include <utility.h>
#include "Nb_Test.h"
#include "NbLib.h"
#include "NB_Functions.h" 

//==============================================================================
// Constants

#define POINT_NAME_LENGTH	36
#define POINT_VLUE_LENGTH	36
#define MAX_NUM_OF_POINTS	280		
#define MAX_PATHNAME_LEN	280		


//==============================================================================
// Types

//==============================================================================
// External variables
extern short NBMailboxFileExists;
//extern nbpoint NBpoints[MAX_NUM_OF_POINTS];
		
		
//==============================================================================
// Global functions

int ReadMailBoxPointsDataXML();
int WriteMailboxPoints(int testNumber, int nestNum, Alv_NarrowBand_SensorComm *nbsensor);   
int VerifyMailboxPoints(int testNumber, int nestNum, Alv_NarrowBand_SensorComm *nbsensor);
int CreateReportWriteMailbox(char *buf, char *ITACbuf);
int CreateReportVerifyMailbox(char *buf, char *ITACbuf);


#ifdef __cplusplus
    }
#endif

#endif  /* ndef __nbmailbox_H__ */
