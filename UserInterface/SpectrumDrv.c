/***********************************************************************
 *
 *
 *  COPYRIGHT: Arxtron Technologies Inc. All Rights Reserved.
 *
 *  PURPOSE: - Rohde & Schwarz FSV-30 Spectrum Analyzer driver functions
 *
 *  DEVELOPMENT HISTORY:
 *
 *  Date        Name           Rev.   Description
 *  ----------  -------------  -----  -----------------------
 *  08-14-2013  Arxtron    		1.0      Initial Release
 *  
 *  
 *********************************************************************/
/*!
*    @file    SpectrumDrv.c
*    @brief   FSV Spectrum Analyzer driver
*    @author  Arxtron Technologies Inc.
*    @date    2013.9.6
*    Functions to open and remote command FSV Spectrum Analyzer 
*    
*/ 

#include <windows.h>
#include <ansi_c.h>
#include "rsspecan.h"
#include "SpectrumDrv.h"
#include "app_log.h"

#define TRUE		1
#define FALSE 		0
#define WINDOW		1    
#define	TIMEOUT		5000

//#define _DEBUG


char msg[256];

//==============================================================================  
/********************************************//**
* Open Spectrum Analyzer instrument
***********************************************/
int openSpectrum(char *saAddress, ViSession *RSSpecAn)
{
	int error = 0;
	char function[] = {"openSpectrum"};
	
	ViSession saSession = VI_NULL; 
	ViInt32 saID = 0;
	ViInt32 saReset = VI_TRUE;
	char msg[256];
	if (saSession == VI_NULL)
	{
		error = rsspecan_init(saAddress,saID,saReset,&saSession);
		if (error != 0)
		{
			decode_error(error,function,saAddress);
			return(-1);
		}
		else
		{	
			*RSSpecAn = saSession;
			sprintf(msg,"%s, %s",function,saAddress);
			add_log(msg);
		}
	}
	else
	{
		// show error
		sprintf(msg,"Spectrum is opened for %s",saAddress);
		add_log(msg);
	}
	return(error);
} // end openSpectrum

//==============================================================================  
/********************************************//**
* Close Spectrum Analyzer instrument
***********************************************/
int closeSpectrum(ViSession saSession)
{
	int error = 0;
	char function[] = {"closeSpectrum"};
	if (saSession != VI_NULL)
	{
		error = rsspecan_close(saSession);
		if (error != 0)
		{
			getErrorMessage(saSession,error,function);
			return(-1);
		}
		else  // close session
		{
			saSession = VI_NULL;
			sprintf(msg,"%s",function);
		}
	}
	else
	{
		sprintf(msg,"%s, spectrum session is not open.",function);  	
	}
	add_log(msg);  
	return(error); 	
} // end closeSpectrum

//==============================================================================  
/********************************************//**
* Set preset
***********************************************/
int setPreset(ViSession saSession)
{
	int error = 0;
	char function[] = {"setPreset"};
	error = rsspecan_Preset(saSession);
	if (error != 0)
	{
		getErrorMessage(saSession,error,function);
	}
#ifdef _DEBUG
	add_log(function);
#endif
	return(error); 
}  // end setPreset

//==============================================================================  
/********************************************//**
* Switches on or off the update of all display elements during remote control
***********************************************/
int setDisplayUpdate(ViSession saSession, int displayState)
{
	int error = 0;
	char function[] = {"setDisplayUpdate"};
	error = rsspecan_ConfigureDisplayUpdate(saSession,displayState);
	if (error != 0)
	{
		getErrorMessage(saSession,error,function);
	}
#ifdef _DEBUG
	sprintf(msg,"%s, %i",function,displayState);   
	add_log(msg);
#endif
	return(error); 
}  // end setDisplayUpdate

//==============================================================================  
/********************************************//**
* Set number of sweep points
***********************************************/
int setSweepNpts(ViSession saSession, int npts)
{
	int error = 0;
	char function[] = {"setSweepNpts"};
	error = rsspecan_ConfigureSweepPoints(saSession,WINDOW,npts);
	if (error != 0)
	{
		getErrorMessage(saSession,error,function); 
	}
#ifdef _DEBUG
	sprintf(msg,"%s, %i",function,npts);   
	add_log(msg);
#endif
	return(error); 
} // end setSweepNpts

//==============================================================================  
/********************************************//**
* Set sweep time in second
***********************************************/
int setSweepTime(ViSession saSession, double sweepTimeSec)
{
	int error = 0;
	char function[] = {"setSweepTime"};
	error = rsspecan_ConfigureSweepCoupling(saSession,WINDOW,RSSPECAN_VAL_COUPLING_SWEEP_TIME,sweepTimeSec);

	if (error != 0)
	{
		getErrorMessage(saSession,error,function); 
	}
	
	
#ifdef _DEBUG
	sprintf(msg,"%s, %10.2f",function,sweepTimeSec);   
	add_log(msg);
#endif
	return(error); 
} // end setSweepTime

//==============================================================================  
/********************************************//**
* Set center frequency
***********************************************/
int setCenterFreq(ViSession saSession, double centerFreqGHz)
{
	int error = 0;
	char function[] = {"setCenterFreq"};
	
	error = rsspecan_ConfigureFrequencyCenter(saSession,WINDOW,centerFreqGHz*1.0e9);
	if (error != 0)
	{
		getErrorMessage(saSession,error,function);  
	}
#ifdef _DEBUG
	sprintf(msg,"%s, %10.2f",function,centerFreqGHz);   
	add_log(msg);
#endif
	return(error); 
} // end setCenterFreq

//==============================================================================  
/********************************************//**
* Set center frequency and span
***********************************************/
int setCenterFreqSpan(ViSession saSession, double centerFreqGHz, double freqSpanGHz)
{
	int error = 0;
	char function[] = {"setFreqSpan"};
	error = rsspecan_ConfigureFrequencyCenterSpan(saSession,WINDOW,centerFreqGHz*1.0e9,freqSpanGHz*1.0e9);
			
	if (error != 0)
	{
		getErrorMessage(saSession,error,function);  
	}
#ifdef _DEBUG
	sprintf(msg,"%s, %10.2f, %10.2f",function,centerFreqGHz,freqSpanGHz);   
	add_log(msg);
#endif
	return(error); 
} // end setCenterFreqSpan

//==============================================================================  
/********************************************//**
* Set video bandwidth
***********************************************/
int setVidBw(ViSession saSession, double vidBwMHz)
{
	int error = 0;
	char function[] = {"setVidBw"};
	error = rsspecan_ConfigureSweepCoupling(saSession,WINDOW,RSSPECAN_VAL_COUPLING_VBW,vidBwMHz*1.0e6);
	if (error != 0)
	{
		getErrorMessage(saSession,error,function);  
	}
#ifdef _DEBUG
	sprintf(msg,"%s, %10.2f",function,vidBwMHz);   
	add_log(msg);
#endif
	return(error);  
} // end setVidBw

//==============================================================================  
/********************************************//**
* Set resolution bandwidth
***********************************************/
int setResBw(ViSession saSession, double resBwMHz)
{
	int error = 0;
	char function[] = {"setResBw"};
	error = rsspecan_ConfigureSweepCoupling(saSession,WINDOW,RSSPECAN_VAL_COUPLING_RBW,resBwMHz*1.0e6);
	
	if (error != 0)
	{
		getErrorMessage(saSession,error,function);  
	}
#ifdef _DEBUG
	sprintf(msg,"%s, %10.2f",function,resBwMHz);   
	add_log(msg);
#endif
	return(error);  
} // end setResBw

//==============================================================================  
/********************************************//**
* Set attenuation level
***********************************************/
int setAttnValue(ViSession saSession, double attn)
{
	int error = 0;
	char function[] = {"setAttnValue"};
	error = rsspecan_ConfigureAttenuation(saSession, WINDOW, VI_FALSE, attn); 
	if (error != 0)
	{
		getErrorMessage(saSession,error,function);  
	}
#ifdef _DEBUG
	sprintf(msg,"%s, %10.2f",function,attn);   
	add_log(msg);
#endif
	return(error); 
} // end setAttnValue


//==============================================================================  
/********************************************//**
* config the trace clear write mode
***********************************************/
int setTraceClearWrite(ViSession saSession, int traceNumber)
{
	int error = 0;
	char function[] = {"setTraceClearWrite"};

	error = rsspecan_ConfigureTrace(saSession, WINDOW, traceNumber, RSSPECAN_TRAC_MOD_WRITE); 
	if (error != 0)
	{
		getErrorMessage(saSession,error,function);  
	}
#ifdef _DEBUG
	add_log(function);
#endif
	return(error); 
} // end setTraceClearWrite


//==============================================================================  
/********************************************//**
* Set acquired trace number
***********************************************/
int setMaxHold(ViSession saSession, int traceNumber)
{
	int error = 0;
	char function[] = {"setMaxHold"};

	error = rsspecan_ConfigureTrace(saSession, WINDOW, traceNumber, RSSPECAN_TRAC_MOD_MAXH); 
	if (error != 0)
	{
		getErrorMessage(saSession,error,function);  
	}
#ifdef _DEBUG
	add_log(function);
#endif
	return(error); 
} // end setMaxHold


//==============================================================================  
/********************************************//**
* config the trace detector   
***********************************************/
int setDetectorMaxPeak(ViSession saSession, int traceNumber)
{
	int error = 0;
	char function[] = {"setDetectorMaxPeak"};
	
	error = rsspecan_ConfigureTraceDetector(saSession, WINDOW, traceNumber,VI_FALSE, RSSPECAN_VAL_DETECTOR_TYPE_MAX_PEAK); 
	if (error != 0)
	{
		getErrorMessage(saSession,error,function);  
	} 
#ifdef _DEBUG
	add_log(function);
#endif
	return(error); 
} // end setDetectorMaxPeak

//==============================================================================  
/********************************************//**
* Set pre-amp on or off
***********************************************/
int setPreAmp(ViSession saSession, int preAmpPow)
{
	int error = 0;
	char function[] = {"setPreAmp"};
	char cCmdToSpecAnalyzer[80];
	
	ViUInt32 retCount;
	if (preAmpPow)
	{ 	
		strcpy(cCmdToSpecAnalyzer, "INP1:GAIN:STAT ON");  
	}
	else
	{
		strcpy(cCmdToSpecAnalyzer, "INP1:GAIN:STAT OFF"); 
	}
		
	error = viBufWrite(saSession,cCmdToSpecAnalyzer,strlen(cCmdToSpecAnalyzer),&retCount);

	if (error != 0)
	{
		getErrorMessage(saSession,error,function);  
	}
#ifdef _DEBUG
	sprintf(msg,"%s, %i",function,preAmpPow);   
	add_log(msg);
#endif
	return(error);  
} // end setPreAmp

//==============================================================================  
/********************************************//**
* Set reference level
***********************************************/
int setRefLevel(ViSession saSession, double refLevel)
{
	int error = 0;
	char function[] = {"setRefLevel"};
	error = rsspecan_ConfigureReferenceLevel(saSession,WINDOW,refLevel);
	if (error != 0)
	{
		getErrorMessage(saSession,error,function);  
	}
#ifdef _DEBUG
	sprintf(msg,"%s, %10.2f",function,refLevel);   
	add_log(msg);
#endif
	return(error);  
} // end setRefLevel

//==============================================================================  
/********************************************//**
* Set reference level offset
***********************************************/
int setRefLevelOffset(ViSession saSession, double refLevelOffset)
{
	int error = 0;
	char function[] = {"setRefLevelOffset"};
	error = rsspecan_ConfigureReferenceLevelOffset(saSession,WINDOW,refLevelOffset);  
	if (error != 0)
	{
		getErrorMessage(saSession,error,function);  
	}
#ifdef _DEBUG
	sprintf(msg,"%s, %10.2f",function,refLevelOffset);   
	add_log(msg);
#endif
	return(error); 
} // end setRefLevelOffset

//==============================================================================  
/********************************************//**
* Set single sweep mode
***********************************************/
int setSingleSweepMode(ViSession saSession)
{
	int error = 0;
	char function[] = {"setSingleSweepMode"};
	error = rsspecan_ConfigureSignalStatisticSweep(saSession, VI_FALSE);  
	if (error != 0)
	{
		getErrorMessage(saSession,error,function);  
	}
#ifdef _DEBUG
	add_log(function);
#endif
	return(error); 
} // end setSingleSweepMode


//============================================================================== 
/********************************************//**
* Acquire trace data without initialize a new signal acquisition
***********************************************/
int fetchTraceData(ViSession saSession, int trace, int arrayLen, double *traceData, int *sz_data)
{
	int error = 0;
	char function[] = {"fetchTraceData"};
	ViInt32	actual_count = 0;
	
	error = rsspecan_FetchYTrace(saSession,WINDOW,trace,arrayLen,&actual_count,traceData);
	
	if (error != 0)
	{
		getErrorMessage(saSession,error,function);  
		return(-1);
	}
	
	*sz_data = actual_count;
	
	// write trace to log 
#ifdef _DEBUG
	for(int i=0;i<actual_count;i++)
	{
		sprintf(msg,"%i, %lf",i,traceData[i]);
		add_log(msg);
	}
#endif
	
	return(error);  
} // end fetchTraceData


//==============================================================================  
/********************************************//**
* Initiates a signal acquisition based on the present instrument configuration 
***********************************************/
int readTraceData(ViSession saSession, int trace, int arrayLen, int timeout, double *traceData, int *sz_data)
{
	int error = 0;
	char function[] = {"readTraceData"};
	ViInt32	actual_count = 0;
	
	// set single sweep mode
	setSingleSweepMode(saSession);
	
	error = rsspecan_ReadYTrace(saSession,WINDOW,trace,timeout,arrayLen,&actual_count,traceData);
	
	//  rsspecan_StoreTraceToFile (ViSession instrumentHandle,ViInt32 window, ViInt32 trace,ViString fileName);
	if (error != 0)
	{
		getErrorMessage(saSession,error,function);  
		return(-1);
	}
	
	*sz_data = actual_count;
	
	// write trace to log 
#ifdef _DEBUG
	for(int i=0;i<actual_count;i++)
	{
		sprintf(msg,"%i, %lf",i,traceData[i]);
		add_log(msg);
	}
#endif
	
	return(error);  
} // end readTraceData


//==============================================================================  
/********************************************//**
* Store Trace To File  
***********************************************/
int saveTraceData(ViSession saSession, int trace, char *saveFilename)
{
	int error = 0;
	char function[] = {"saveTraceData"};

	// set single sweep mode
	setSingleSweepMode(saSession);
	
	while(!getOperationComplete(saSession))
	{
		Sleep(20);
	}
	
	error = rsspecan_StoreTraceToFile (saSession,WINDOW, trace, saveFilename);
	if (error != 0)
	{
		getErrorMessage(saSession,error,function);  
		return(-1);
	}
	
#ifdef _DEBUG
	sprintf(msg,"%s, save trace %i to file %s ",function,trace,saveFilename);   
	add_log(msg);
#endif	

	return(error);  
} // end saveTraceData


//==============================================================================  
/********************************************//**
* check if the operation is completed
***********************************************/
int getOperationComplete(ViSession saSession)
{
	int error;
	char function[] = {"OperationComplete"};
	ViBoolean bOpComplete;
	
	error = rsspecan_QueryViBoolean(saSession,"*OPC?",&bOpComplete);
	if (error != 0)	   
	{
		getErrorMessage(saSession,error,function);  
	}
	return(bOpComplete);
} // end getOperationComplete


//==============================================================================  
/********************************************//**
* Get peak power of set marker 
***********************************************/
int getPeakPower(ViSession saSession, int marker, double *peakPow)
{
	int error = 0;
	char function[] = {"getPeakPower"};
	
	double peakPower;
	double peakFrequency;
	
	error = getPeakPowerFreq(saSession,marker,&peakPower,&peakFrequency);
	
	if (error != 0)	   
	{
		getErrorMessage(saSession,error,function);  
		return(-1);
	}
	*peakPow=(double)peakPower;
#ifdef _DEBUG
	sprintf(msg,"%s, %lf",function,markerAmp);
	add_log(msg);
#endif
	return(error); 
} // end getPeakPower


//==============================================================================  
/********************************************//**
* Get peak power and frequency of marker 
***********************************************/
int getPeakPowerFreq(ViSession saSession, int marker, double *peakPow, double *peakFreq)
{
	int error = 0;
	char function[] = {"getPeakPowerFreq"};
	ViString capability="Win0,M1";
	ViReal64 markerXPos, markerAmp;
	
	// set single sweep mode
	setSingleSweepMode(saSession);

	
	// enable the marker
	error |= rsspecan_SetAttributeViBoolean(saSession,capability,RSSPECAN_ATTR_MARKER_ENABLED,VI_TRUE);
	if (error != 0)	   
	{
		getErrorMessage(saSession,error,function);  
		return(-1);
	}
	// perform the sweep
	error |= rsspecan_Initiate(saSession,WINDOW,TIMEOUT*2);
	if (error != 0)	   
	{
		getErrorMessage(saSession,error,function);  
		return(-1);
	}
	
	
	while(!getOperationComplete(saSession))
	{
		Sleep(100); 		 //Carol changed - was 20. changed to see if related with UWB power check fals fail 
	}
	
	// set marker search type and start searching
	error |= rsspecan_MarkerSearch(saSession,WINDOW,marker,RSSPECAN_VAL_MARKER_SEARCH_HIGHEST);
	if (error != 0)	   
	{
		getErrorMessage(saSession,error,function);  
		return(-1);
	}
	// return the position of the selected marker
	error |= rsspecan_QueryMarker(saSession,WINDOW,marker,&markerXPos,&markerAmp);
	if (error != 0)	   
	{
		getErrorMessage(saSession,error,function);  
		return(-1);
	}
	*peakPow=(double)markerAmp;
	*peakFreq=(double)markerXPos;			// frequency at peak power
#ifdef _DEBUG
	sprintf(msg,"%s, %lf, %lf0",function,markerAmp,markerXPos);
	add_log(msg);
#endif

	return(error); 
} // end getPeakPowerFreq


//==============================================================================  
/********************************************//**
* move marker to a set frequency 
***********************************************/
int moveMarker(ViSession saSession, int marker, double setFreqHz)
{
	int error = 0;
	char function[] = {"moveMarker"};
	error = rsspecan_MoveMarker(saSession,WINDOW,marker,setFreqHz);
	
	if (error != 0)
	{
		getErrorMessage(saSession,error,function);  
	}
#ifdef _DEBUG
	sprintf(msg,"%s, marker=%i, freqHz=%10.2f",function,marker,setFreqHz);   
	add_log(msg);
#endif
	return(error);  
} // end moveMarker


//==============================================================================  
/********************************************//**
* Get power and frequency of marker 
***********************************************/
int getMarkerPowerFreq(ViSession saSession, int marker, double *markerPow, double *markerFreq)
{
	int error = 0;
	char function[] = {"getMarkerPowerFreq"};
	ViReal64 markerXPos, markerAmp;
	

	// return the position of the selected marker
	error = rsspecan_QueryMarker(saSession,WINDOW,marker,&markerXPos,&markerAmp);
	if (error != 0)	   
	{
		getErrorMessage(saSession,error,function);  
		return(-1);
	}
	*markerPow=(double)markerAmp;
	*markerFreq=(double)markerXPos;			// frequency at peak power
#ifdef _DEBUG
	sprintf(msg,"%s, %lf, %lf",function,markerAmp,markerXPos);
	add_log(msg);
#endif
	return(error); 
} // end getMarkerPowerFreq


//==============================================================================  
/********************************************//**
* Get instrument ID          
***********************************************/
int getInstrumentId(ViSession saSession, char *instrId)
{
	int error = 0;
	char function[] = {"getInstrumentId"};
	char cCmdToSpecAnalyzer[80];
	ViChar idStr[256];
	
	strcpy(cCmdToSpecAnalyzer,"*IDN?\n");
	error = viQueryf(saSession,cCmdToSpecAnalyzer,"%[^\r\n]",idStr);

	if (error != 0)
	{
		getErrorMessage(saSession,error,function);  
	}
	else
	{
		strcpy(instrId,idStr);    
	}
#ifdef _DEBUG
	add_log(function);
#endif
	return(error);  
} // end setPreAmp


//==============================================================================  
/********************************************//**
* Get frequency offset of measurement data 
***********************************************/
int getFrequencyOffset(ViSession saSession, double *offsetFrequency)
{
	int error = 0;
	char function[] = {"getFrequencyOffset"};
	char cCmdToSpecAnalyzer[80];
	
	ViUInt32 retCount; 
	ViReal64 qFrequency;
	qFrequency = 0.0;
	
	
	// Switches on analog demodulator
	sprintf(cCmdToSpecAnalyzer,"%s","ADEM ON");
	error |= viBufWrite(saSession,cCmdToSpecAnalyzer,strlen(cCmdToSpecAnalyzer),&retCount);
	
	Sleep(500);
	
	// calculates the FM offset of the currently available measurement data set.
	sprintf(cCmdToSpecAnalyzer,"%s","ADEM:FM:OFFS? IMM");
	error |= viQueryf(saSession,cCmdToSpecAnalyzer,"%lf",&qFrequency); 
	
	// Switches off analog demodulator 
	//sprintf(cCmdToSpecAnalyzer,"%s","ADEM OFF");
	//error |= viBufWrite(saSession,cCmdToSpecAnalyzer,strlen(cCmdToSpecAnalyzer),&retCount);
	
	if (error != 0)
	{
		getErrorMessage(saSession,error,function);  
	}
	else
	{
		*offsetFrequency = qFrequency;    
	}
#ifdef _DEBUG
	add_log(func);
#endif
	return(error);  
} // end setFrequencyOffset

/********************************************//**
* Get average frequency offset of measurement data
***********************************************/
int getFrequencyOffsetAverage(ViSession saSession, double *offsetFrequency, int average)
{
	int error = 0;
	char function[] = {"getFrequencyOffset"};
	char cCmdToSpecAnalyzer[80];
	
	ViUInt32 retCount; 
	ViReal64 qFrequency;
	qFrequency = 0.0;
	double total = 0.0;
	
	
	// Switches on analog demodulator
	sprintf(cCmdToSpecAnalyzer,"%s","ADEM ON");
	error |= viBufWrite(saSession,cCmdToSpecAnalyzer,strlen(cCmdToSpecAnalyzer),&retCount);
	
	Sleep(500);
	for (int i=0; i< average; i++)
	{
		// calculates the FM offset of the currently available measurement data set.
		sprintf(cCmdToSpecAnalyzer,"%s","ADEM:FM:OFFS? IMM");
		error |= viQueryf(saSession,cCmdToSpecAnalyzer,"%lf",&qFrequency); 
		total += fabs(qFrequency);
	}
	
	// Switches off analog demodulator 
	//sprintf(cCmdToSpecAnalyzer,"%s","ADEM OFF");
	//error |= viBufWrite(saSession,cCmdToSpecAnalyzer,strlen(cCmdToSpecAnalyzer),&retCount);
	
	if (error != 0)
	{
		getErrorMessage(saSession,error,function);  
	}
	else
	{
		*offsetFrequency = total/average;    
	}
#ifdef _DEBUG
	add_log(func);
#endif
	return(error);  
} // end setFrequencyOffsetAvarage


//==============================================================================  
/********************************************//**
* Get frequency error for determine frequency deviation   
***********************************************/
int getFrequencyError(ViSession saSession, double *frequencyError)
{
	int error = 0;
	char function[] = {"getFrequencyError"};
	char cCmdToSpecAnalyzer[80];

	ViUInt32 retCount; 
	ViReal64 qFrequency;
	qFrequency = 0.0;
	
	// Switches on analog demodulator
	sprintf(cCmdToSpecAnalyzer,"%s","ADEM ON");
	error |= viBufWrite(saSession,cCmdToSpecAnalyzer,strlen(cCmdToSpecAnalyzer),&retCount);
	
	Sleep(500);
	
	//queries the frequency error with FM and PM demodulation
	sprintf(cCmdToSpecAnalyzer,"%s","CALC:MARK:FUNC:ADEM:FERR?");  
	error |= viQueryf(saSession,cCmdToSpecAnalyzer,"%lf",&qFrequency); 
	
	// Switches off analog demodulator 
	sprintf(cCmdToSpecAnalyzer,"%s","ADEM OFF");
	error |= viBufWrite(saSession,cCmdToSpecAnalyzer,strlen(cCmdToSpecAnalyzer),&retCount);
	
	if (error != 0)
	{
		getErrorMessage(saSession,error,function);  
	}
	else
	{
		*frequencyError = qFrequency;    
	}
#ifdef _DEBUG
	add_log(func);
#endif
	return(error);  
} // end setFrequencyError


//==============================================================================  
/********************************************//**
* Get average frequency error for determine frequency deviation 
***********************************************/
int getFrequencyErrorAverage(ViSession saSession, double *frequencyError, int average)
{
	int error = 0;
	char function[] = {"getFrequencyError"};
	char cCmdToSpecAnalyzer[80];

	ViUInt32 retCount; 
	ViReal64 qFrequency;
	qFrequency = 0.0;
	double total = 0.0;
	
	// Switches on analog demodulator
	sprintf(cCmdToSpecAnalyzer,"%s","ADEM ON");
	error |= viBufWrite(saSession,cCmdToSpecAnalyzer,strlen(cCmdToSpecAnalyzer),&retCount);
	
	Sleep(500);
	for (int i=0; i< average; i++)
	{
		//queries the frequency error with FM and PM demodulation
		sprintf(cCmdToSpecAnalyzer,"%s","CALC:MARK:FUNC:ADEM:FERR?");  
		error |= viQueryf(saSession,cCmdToSpecAnalyzer,"%lf",&qFrequency); 
		total += fabs(qFrequency);
	}
	
	// Switches off analog demodulator 
	sprintf(cCmdToSpecAnalyzer,"%s","ADEM OFF");
	error |= viBufWrite(saSession,cCmdToSpecAnalyzer,strlen(cCmdToSpecAnalyzer),&retCount);
	
	if (error != 0)
	{
		getErrorMessage(saSession,error,function);  
	}
	else
	{
		*frequencyError = total/average;    
	}
#ifdef _DEBUG
	add_log(func);
#endif
	return(error);  
} // end setFrequencyErrorAverage




//==============================================================================  
/********************************************//**
* Initiate an acquisition    
***********************************************/
int initiateMeasurement(ViSession saSession, int timeOut_mSec)
{
	int error = 0;
	char function[] = {"initateMeasurement"};
	error = rsspecan_Initiate(saSession,WINDOW,timeOut_mSec);
	
	if (error != 0)
	{
		getErrorMessage(saSession,error,function);  
	}
#ifdef _DEBUG
	sprintf(msg,"%s, timeOut_mSec=%i",function,timeOut_mSec);   
	add_log(msg);
#endif
	return(error);  
} // end initiateMeasurement


//==============================================================================  
/********************************************//**
* Get instrument error  
***********************************************/
void getErrorMessage(ViSession saSession, int error, char *function)
{
	rsspecan_error_message (saSession, error, msg);
	decode_error(error,function,msg);
} // end getErrorMessage


	   
