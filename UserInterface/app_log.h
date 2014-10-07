int ApplicationExecutionIsLog;

int add_log(char *msg);
int add_error(char *msg);  
int add_log_error(char *msg);
int add_to_file(char *pFilename, char *msg);
char* get_time(void);
void decode_error(int error, char *func, char *desc);
void check_error(int error, char *func, char *desc); 

