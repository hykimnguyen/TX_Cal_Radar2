#include <DAQmxIOctrl.h>
#include <NIDAQmx.h> 
#include "DIO6515UtilsLIBDef.h" 

void 			UpdateManualMIO(int Type, int Control[], int Device);
void 			UpdateManualIO(int Type, int Control[], int Device);
void 			UpdateIOPort(int index, int PortValue, int Control[], int Type, int Device);
int 			InitDABoard(int Device);
void 			CreatManualPnl2Dynamically(void);
void			DIO6515_Dyn_OutputsButton1Handle(int i, int device);
void			DIO6515_Dyn_OutputsButton2Handle(int i, int device);
short			ReadInput6515(char* DIO_Discription, int Device);

int 			WriteOutput6515(char* DIO_Discription, int state, int Device);
void DisplayMANUALConfiguration6515(void); 
void DisplayMANUAL6515Utils(void); 

void InitMANUALTable6515(int PanelHandler, struct MANUALPNLPARAM6515	*ptrPanelControlParams);
void InitMANUALTable26515(int PanelHandler, struct MANUALPNLPARAM6515	*ptrPanelControlParams);
void CreateMANUALConfigurationTable6515(int PanelHandler, struct	MANUALPNLPARAM6515	*ptrPanelControlParams);
void CreateMANUALConfigurationTable26515(int PanelHandler, struct	MANUALPNLPARAM6515	*ptrPanelControlParams);

int getDutPresence(int dutNumber);
int getDutPosition(int dutNumber);
int getDutRejectButton(int dutNumber);
int getFailChute(void);
int getE_Stop(void);
void setDutPower(int dutNumber,int bState);

int setTestInstrumentPath(int dutNumber);
void setSelectValve(int dutNumber,int bState);
void setLedFail(int dutNumber,int bState);
void setLedBusy(int dutNumber,int bState);
void setLedGood(int dutNumber,int bState);
void setCtrlPower24VDC(int bState);

void setCtrlDumpValve(int bState);
int getFailChuteIsFull(void);
int failChuteLastStatus;
void updateFailChuteIsFullStatus(void);
int getFxtLock(void);
int getFailChute2(void); 



