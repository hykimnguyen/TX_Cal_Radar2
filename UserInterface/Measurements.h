/***********************************************************************
 *
 *
 *  COPYRIGHT: Arxtron Technologies Inc. All Rights Reserved.
 *
 *  PURPOSE: - C6 Calibration measurement functions
 *
 *  DEVELOPMENT HISTORY:
 *
 *  Date        Name           Rev.   Description
 *  ----------  -------------  -----  -----------------------
 *  08-14-2013  Arxtron    		1.0      Initial Release
 *  
 *  
 *********************************************************************/

#ifndef __Measurements_H__
#define __Measurements_H__

#ifdef __cplusplus
    extern "C" {
#endif


#include "cvidef.h"
#include "rsspecan.h"


typedef struct 
{
	int idNumber;
	char address[120];
	ViSession session;
	int isOpen;
	int npts;
	double sweepTime;
	double centerFreq;			  // GHz
	double freqSpan;			  // GHz
	double vidBw;				  // MHz
	double resBw;				  // MHz
	double attn;				  // dB
	int preAmpPow;
	double refLevel;
	double refLevelOffset;
} RSSpecAn;


typedef struct
{
	int CalNum;
	int FlavorId;
	char PartNum[256];  //was 11
	char Recipe[11]; 
	char Customer[80];
	char Variant[20];
	char TestStepsFile[256];
//	char Extra[512];
	char Description[256];
	char remoteFolder[256];
	char remoteMailBox[256];
	char remoteVariantCSV[256];	
	char localFolder[256];
	char localMailBox[256];
	char localVariantCSV[256];	
} CalRecipe;			// C6 Calibration recipe
	
CalRecipe selRecipe;	

char testFirmwareVersion[20];


#define  NUMBER_OF_TEST_INSTRUMENTS  	3			
#define  NUMBER_OF_TEST_UNITS			6


#define MAX_LENGHT_MEDIAN_ARRAY 	50
#define INITIAL_DAC_AMP_HONDA		22
#define INITIAL_DAC_SW_HONDA		4  		


RSSpecAn specAn[NUMBER_OF_TEST_INSTRUMENTS];

//static double PathLossdB[NUMBER_OF_TEST_UNITS];
static double UwbPathLossdB[NUMBER_OF_TEST_UNITS]; 
static double IsmPathLossdB[NUMBER_OF_TEST_UNITS]; 

double initialDAC_amp[MAX_LENGHT_MEDIAN_ARRAY];
double initialDAC_sw[MAX_LENGHT_MEDIAN_ARRAY];


double CurrentLowLimit;
double CurrentHighLimit;
int TemperatureLowLimit;
int TemperatureHighLimit;
int Band0LowLimit;
int Band1HighLimit;
int UwbDacLowLimit;
int UwbDacHighLimit;
double UwbPowerLowLimit;
double UwbPowerHighLimit;
double UwbCalMarginLowLimit;
double IsmFreqDevHighLimit;
double IsmInitalDAC;
int IsmDacLowLimit;
int IsmDacHighLimit;
double IsmPowerLowLimit;
double UwbPowerCheckLowLimit;
double UwbPowerCheckHighLimit;
double TxDiffLowLimit;
double TxDiffHighLimit;
double TxIsolLowLimit;
double TxIsolCalLowLimit;
double TxIsolCalHighLimit;

unsigned int UnitsAreTestingCount;




int ITAC_LockHandle; 
int ITACIsEnable;
int BoardRunning[6];
int ESTOP_LockHandle;

int CalUwbDac[NUMBER_OF_TEST_UNITS];
//int CalIsmDac[NUMBER_OF_TEST_UNITS];  
int MainTestingIsPause;					// set this to TRUE to pause main testing and allow for diagnostic 
int MaxItacProceedRequestCount;

int SetSpectrum(RSSpecAn sa);
void SetSpectrumNominalCondition(RSSpecAn sa);
int CloseSpectrum(RSSpecAn sa);
int SetSpectrumPreset(RSSpecAn sa);
int CalTxBandCrossOverFrequency(RSSpecAn sa, int testUnit, int *Band0_Low_FrequencyMHz, int *Band0_High_FrequencyMHz, int *Band1_Low_FrequencyMHz, int *Band1_High_FrequencyMHz, int *TransitionFrequencyMHz, int only_measure);
int CalTxUwbPower(RSSpecAn sa,int testUnit,double *TxCalibratedUwbPeakPwr,double *TxCalibratedUwbPeakFrequency, double *TxAdjustmentMargin, int *CalibratedDacValue, int CalibratedDACValues100MHzBins[14], double *deltaPowerOverUwbBand);
int ValidateUwbDacValue(int calUwbDac, int testUnit, int *ReadBackUwbDacValue);  
int MeasureIsmPullingAndPowerCal(RSSpecAn sa,int testUnit,double *IsmPeakPower,double *IsmDeltaFrequency,int *IsmDac,
						double *DeltaIsmPowerAtMinus2_5MHz,double *DeltaIsmPowerAtPlus2_5MHz);
int MeasureIsmPullingAndPower(RSSpecAn sa,int testUnit,double *IsmPeakPower,double *IsmDeltaFrequency,
						double *DeltaIsmPowerAtMinus2_5MHz,double *DeltaIsmPowerAtPlus2_5MHz);			 // Without Cal
int MeasureUwbPeakPower(RSSpecAn sa,int testUnit,int calUwbDac,double *PeakPowerUWB,double *PeakFrequencyUWB);
int MeasureTxDiffPower(RSSpecAn sa,int testUnit, double TxDiffRes[6]);
int MeasureTxIsolation(RSSpecAn sa, int testUnit, int calUwbDac, double TxSwitchIsolationRes[6]); 
int MeasureTxIsolationAtHighestPower(RSSpecAn sa, int testUnit, double TxSwitchIsolationRes[6]);  
int MeasureTxIsolationAtCalibratedUwbDac(RSSpecAn sa, int testUnit, int calUwbDac, double TxSwitchIsolationResAtCalUwbDac[6]);
int ResetTestUnit(int testUnit);
int MeasureUnitCurrent(int testUnit, double *current_mAmp);
int GetSensorTemperature(int testUnit, int *temperature);
int ProceedRequest(int testUnit, char *MIS, char ErrorMsg[256]);
int itac_proceed_request(int testUnit, char *MIS_SerialNumber, char ErrorMsg[1000]);
int GetFirmwareVersion(int testUnit, char *swVer);

double getRefLevel(double expectedPower, double pathLoss);
int CalculateTxCrossOverFreq(double TxBand1HiFreq, double TxBand0LoFreq);
int VerifyTxUwbPowerIsInLimit(double power);
int VerifyTxUwbDacCalIsInLimit(int value);
int VerifyIsmDacCalIsInLimit(int value);
int adjustedDac(int currentDac,double targetPower,double currentPower,double slope);
//void CalculateEnergyCenter(double dInputArray[], int NumberOfPoints, double ArrayFreqResolution, double *dEnergyCenterFrequency);
void CalculateEnergyCenter(double dInputArray[], int NumberOfPoints, double cf, double span, double *dEnergyCenterFrequency);
void NormalizeData(double dArrayToBeNormalized[], int NumberOfPoints, double dNormalizedArray[]);
void AverageSamples(double dArray[], int nNumOfArraySamples, int nOddNumOfSamplesToAverage, double dAveragedArray[]);
int InitSpecAn(int testInstrument);
int LoadCableLossCompensationFile(void);
int GetCalibratedTxUwbPower(int phase, ViSession session, int testUnit, int uwbDac, double *power, double *frequency, int *calIsSuccessful, int *calIsCompleted);

int init_eeprom_and_cpld(char *MIS, char *E2P_file, double cpld_timeout_s, int CANport);
int ArrMedian(double arr[],int NumElements,double *Median);

#ifdef __cplusplus
    }
#endif

#endif  /* ndef __Measurements_H__ */
