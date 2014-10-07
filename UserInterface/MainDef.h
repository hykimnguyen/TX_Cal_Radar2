//*******************************************************************************************************************
int res[4][100000];
int InitMain(void);
//*******************************************************************************************************************
int ret, i, tempRet;	
int HDL_POOL; ///, HDL_LOCK;
int THREAD_FUNCTION_ID [4];
unsigned char THREAD_ID;				// runs 0..3 - value that thread pool will pass to the Device session
										// thread function, local variable does not work
										// as this pass is done through pointer
int HDL_LOCK;
int testIndex, testNumber;
int testNest;
bool TestSequenceSingle(void);
bool ExitStatus;
static bool ESTOPpressed = GLB_FALSE;

//Air Pressure Sensor
bool VacFault[6];  

//*******************************************************************************************************************
void CreateAllDynamicControls(void);
void CreateMainConfigurationTable(void);
void CreateAllDynamicControls(void);
void InitMainTable(void);

int CVICALLBACK TransferFlashRunnerBinaryFile(void * index);
bool ParseManufacturingData(char scannedBarCode[]);
int CVICALLBACK Hello1(void * index);
bool ValidateScannedBarcode(char scannedBarcode[]);
void MainSequence(void);
bool ActivatFlashRunnerPower(char outputDescription[], short outputState);
bool IsLIDClosed(char InputDescription[]);
bool LoadandEngage(char outputDescription[], short outputState, bool selectValve);
bool IsBoardLoaded(char InputDescription[]);
void EnableSystemControlSaving(int enableSaveButton);
int CVICALLBACK CreateListCtrlCB (int panel, int control, int event,
void *callbackData, int eventData1, int eventData2);

bool EStopIsEnable[6]; 
bool AirIsDisabled[6];  

void CreateTestResultDynamicControls(void);
void DisplayInitializationError(char msg[]);
void EstopPressed(void);
void EstopReleased(void);
//void SafetyRelayBroken(void);
void SafetyRelayRestored(void);
void InterLockReleased(void);
void InterLockRestored(void);
void PrinterUnLocked(void);
void FailChuteFull(void);
void FailchuteCleared(void);
void logSystemErrorMessage(char * systemMsg);
void logTestResult(int nestNum, int testNumber);
void logTestResultInit(void);
void PrinterErrorMessage(char *Msg);
void StatusBoxAttribute(int dutNumber, char * Msg, int backgroundColor, int fontColor, int fontSize);
void MsgBoxAttribute(int dutNumber, char * Msg, int backgroundColor, int fontColor, int fontSize);
void InitializeAllLock(void);
void DiscardAllLock(void);
void ReleaseAllLock(void);
void InitializeCfgMiscValue(void);
void ResetAndExit(void);
int CheckTestingInProcess(int menuItem);
void PowerDownTestStation(void);
void DiscardLock(CmtThreadLockHandle threadLock);
void ReleaseLock(CmtThreadLockHandle threadLock);
void UpdateStartUpTestNest(void);
void AirPressureErrorLogging(void);
void FxtIDErrorMessage(char * type);
//*******************************************************************************************************************


