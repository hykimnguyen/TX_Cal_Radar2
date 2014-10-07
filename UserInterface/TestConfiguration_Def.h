int			DYN_TABLE_TST_CONFIG; 
int			numberOfAttempt;

CmtThreadLockHandle WriteToFile_LockHandle, FailChute_LockHandle;   
	
void CreateMiscConfigurationTable(void);
void CreategTestConfigurationTable(void);
void DisplayTstControl(int firstTab, int editTSTCfg);


void  TempFuncPtr(void);
void DisplayPassFailResult(int TestResult, int testNumber, char timeStamp[], bool runTestScript, int scriptTestNumber, int threadNum, int testAttempt);
 void WriteTestResultsToFile (int result, int nest, bool checkNewFile, double totalTestTime);  
void TestPassFailResult(int NestNum, int totalNumbrofTests);  
void InitTestStepParamHeader(void);
void InitTestStepParam(void);

void  ValidateTestSequenceInputs(void);
void ShowValidateTestSequenceInputsError(int i, int j, char *funcName, char *testParam);
int getTestCount(void);

void DisplayTestReport(int dutNumber, char testStr[1000]);
void InsertItemInTestReport(int dutNumber, char *testStr);
void GetMisNumber(int nest, char MIS[23]);
void InsertItemInReportList(int threadNum, int testNumber, char textColor[100]);
