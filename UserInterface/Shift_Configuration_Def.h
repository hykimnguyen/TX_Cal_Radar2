//********************************************************************************************************************
char Shift_Str[10];
int  Shift_Config_file_exist;

char SC_int_dir[MAX_PATHNAME_LEN];
char SC_ext_dir[MAX_PATHNAME_LEN];
char SC_int_uir[MAX_PATHNAME_LEN];
char SC_ext_uir[MAX_PATHNAME_LEN];
char SC_int_xls[MAX_PATHNAME_LEN];
char SC_ext_xls[MAX_PATHNAME_LEN];

void GetShiftCofigDirectory(void);
void InitShiftConfiguration(void);
void GetDataFromShiftTable(int data_table);
void SetDataToShiftTable(int data_table);
void WriteShiftConfiguration(void);
void DisplayShiftConfiguration(int Edit);
//********************************************************************************************************************
