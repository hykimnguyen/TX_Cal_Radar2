/***********************************************************************
 *
 *
 *  COPYRIGHT: Arxtron Technologies Inc. All Rights Reserved.
 *
 *  PURPOSE: - C6 Calibration spectrum analyzer driver functions
 *
 *  DEVELOPMENT HISTORY:
 *
 *  Date        Name           Rev.   Description
 *  ----------  -------------  -----  -----------------------
 *  08-14-2013  Arxtron    		1.0      Initial Release
 *  
 *  
 *********************************************************************/

#ifndef __SpectrumDrv_H__
#define __SpectrumDrv_H__

#ifdef __cplusplus
    extern "C" {
#endif


#include "cvidef.h"
#include "rsspecan.h" 


int openSpectrum(char *saAddress, ViSession *RSSpecAn); 
int closeSpectrum(ViSession saSession);
int setPreset(ViSession saSession);
int setDisplayUpdate(ViSession saSession, int displayState); 
int setSweepNpts(ViSession saSession, int npts);
int setSweepTime(ViSession saSession, double sweepTimeSec);
int setCenterFreq(ViSession saSession, double centerFreqGHz); 
int setCenterFreqSpan(ViSession saSession, double centerFreqGHz, double freqSpanGHz); 
int setVidBw(ViSession saSession, double vidBwMHz);
int setResBw(ViSession saSession, double resBwMHz);
int setAttnValue(ViSession saSession, double attn);
int setTraceClearWrite(ViSession saSession, int traceNumber);
int setMaxHold(ViSession saSession, int traceNumber);
int setDetectorMaxPeak(ViSession saSession,int traceNumber); 
int setPreAmp(ViSession saSession, int preAmpPow); 
int setRefLevel(ViSession saSession, double refLevel);
int setRefLevelOffset(ViSession saSession, double refLevelOffset); 
int setSingleSweepMode(ViSession saSession);
int fetchTraceData(ViSession saSession, int trace, int arrayLen, double *traceData, int *sz_data);
int readTraceData(ViSession saSession, int trace, int arrayLen, int timeout, double *traceData, int *sz_data); 
int saveTraceData(ViSession saSession, int trace, char *saveFilename);
int getOperationComplete(ViSession saSession); 
int getPeakPower(ViSession saSession, int marker, double *peakPow);
int getPeakPowerFreq(ViSession saSession, int marker, double *peakPow, double *peakFreq); 
int getMarkerPowerFreq(ViSession saSession, int marker, double *markerPow, double *markerFreq);
int moveMarker(ViSession saSession, int marker, double setFreqHz); 
int initiateMeasurement(ViSession saSession, int timeOut_mSec); 
void getErrorMessage(ViSession saSession, int error, char *function); 
int getInstrumentId(ViSession saSession, char *instrId);
int getFrequencyOffset(ViSession saSession, double *offsetFreq);
int getFrequencyOffsetAverage(ViSession saSession, double *offsetFreq, int average);
int getFrequencyError(ViSession saSession, double *frequencyError);
int getFrequencyErrorAvg(ViSession saSession, double *frequencyError, int average);



#ifdef __cplusplus
    }
#endif

#endif  /* ndef __SpectrumDrv_H__ */
