#include <NIDAQmx.h>
#include <DAQmxIOctrl.h>

// the maximum number of samples to store
#define SAMPLE_LIMIT 63
#define DFL_SAMPLE_WIDTH 10


//----------------------------------------------------------------------------
// File global variables
//----------------------------------------------------------------------------
static int           gPanelHandle;
static int           gRunning; // "boolean" to indicate whether we are sampling
static int           gDGraphSampleWidth; // number of visible (graphed) samples
static unsigned char gOffset = 0; // X-axis offset for the graph plot
static int           gArrIndex = 0; // keep track of how much data we have
static unsigned int  gOldData; // cached value to see if new value is different
static TaskHandle    gTaskHandle[8]; // handle to the DAQmx task we will create
static unsigned int  gPlotData[SAMPLE_LIMIT] = { 0 }; // array to hold samples
int				     CounterTimerPanelHandle;


static int32		gSamplesToRead=0;
static float64		*gData=NULL;

/***
struct		// CT Variable Declaration
{	
	int         Error;
	char        Chan[256];
	uInt32      Idle;
	float64     Freq,duty;
	char        ErrBuff[2048];
}	CT_Data;
***/
int32 CVICALLBACK DoneCallback(TaskHandle taskHandle, int32 status, void *callbackData);

int __stdcall CounterTimer_Start(char Chan[], float64 Freq, float64 Duty, uInt32 Idel, int Error, char ErrBuff[]);

int __stdcall CounterTimer_Stop(TaskHandle gTaskHandle);

int __stdcall CounterTimer_Stop_Done(TaskHandle gTaskHandle);

int32 __stdcall CounterTimerDone(TaskHandle taskHandle, int32 status);

//void __stdcall Init_CounterTimer(void);
void __stdcall Display_CounterTimer(void);
static void __stdcall UpdateSliderPos(int panel);
static void __stdcall BoundsCheckSlider(int panel);
static void __stdcall UpdateDGraphLimits(int panel, int sample_width);
static void __stdcall UpdateSlider(int panel);
void __stdcall HandleDAQmxError(int panel);
void __stdcall SetRunningState(int panel, int state);
void __stdcall StopRunning(int panel);
static void __stdcall SetupUI(int panel);
void __stdcall PopulateMeasurementListBox(float64 data[], int32 read);
int __stdcall CounterTimer_StartMeas(char Chan[], float64 MinFreq, float64 MaxFreq, uInt32 Edge, int32 Divisor, int32 Samples, float64 freqHz[], int Error, char ErrBuff[]); 
