#define NUMBER_OF_FILES	6		   // one file or each test unit

CmtThreadLockHandle WriteTestOutput_LockHandle; 
int TestOutputIsLog;

char testOutputFilename[NUMBER_OF_FILES][MAX_PATHNAME_LEN];
char testOutputHeaderStr[1000];  
  
void get_test_output_log_filename(void);
int add_header_to_test_output_log(int dutNumber); 
int add_data_to_test_output_log(int dutNumber, char *result); 
void add_datetime_to_test_output_log(int dutNumber); 



