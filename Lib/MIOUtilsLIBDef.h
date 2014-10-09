#include <DAQmxIOctrl.h>
#include <NIDAQmx.h> 
//*******************************************************************************************************************
#define			MIO_ROW_INDEX_CONSTANT		24
#define			MIO_DYN_RAMIO_INT1_CONST	24
#define			TOTAL_IO_MIO_ROWS			48
#define			TOTAL_INPUT_MIO_LINE		24
#define			TOTAL_OUTPUT_MIO_LINE		24 
#define			TOTAL_NUMBER_OF_MIO_PORTS	3	  
#define			BIT_7						0x80
#define			BIT_6						0x40
#define			BIT_5						0x20
#define			BIT_4						0x10
#define			BIT_3						0x08
#define			BIT_2						0x04
#define			BIT_1						0x02
#define			BIT_0						0x01

#define			TOT_MIO_LINE1				96
#define			MAX_CHAR_LEN1				50
//*******************************************************************************************************************




//*******************************************************************************************************************
int 			MANUAL_GUI_Handle;
int				DYN_TABLE_MIO_CONFIG, DYN_TABLE_MIO_MN_CONFIG;
int 			MIOconfigpanelHandle;
int 			MIO_EDIT_CTRL1, DYN_MIO_BUTTON_SAVE; 
int 			MIO_LED1[TOTAL_INPUT_LINE],MIO_DECORATION_INPUT1, MIO_DECORATION_OUTPUT1, 
				MIO_DYN_BUTTON1[TOTAL_OUTPUT_LINE], MIO_DYN_LED_OUT1[TOTAL_OUTPUT_LINE];
int				MIO_Decoration_IN1_Left,MIO_Decoration_IN1_Top, MIO_Decoration_OUT1_Left,MIO_Decoration_OUT1_Top;
int				MIO_LEDTextTitle1[TOTAL_INPUT_LINE];
char			MIO_LED1_LABEL_TITLE[TOTAL_INPUT_LINE][100];
char 			MIO_ButtonTitle1[TOTAL_OUTPUT_LINE][100];

int				MIO_NUM_ROWS, MIO_NUM_COLUMNS, MIO_CONFIG_NUM_DEV;
char 			MIO_config_int_dir[MAX_PATHNAME_LEN];
char 			MIO_config_ext_dir[MAX_PATHNAME_LEN];
char 			MIO_config_int_uir[MAX_PATHNAME_LEN];
char 			MIO_config_ext_uir[MAX_PATHNAME_LEN];
char 			MIO_config_int_xls[MAX_PATHNAME_LEN];
char 			MIO_config_ext_xls[MAX_PATHNAME_LEN];
int				MIO_config_file_exist;
char 			MIO_config_int_table_dir[MAX_PATHNAME_LEN];
char 			MIO_config_int_table_xls[MAX_PATHNAME_LEN];
char 			MIO_config_ext_table_xls[MAX_PATHNAME_LEN];
char			MIO_config_ext_table_dir[MAX_PATHNAME_LEN];
int				MIO_DYN_RAMIO_INT1[TOTAL_IO_ROWS];
char			MIO_RAMIO1_LABEL_TITLE[MIO_DYN_RAMIO_INT1_CONST][100];
int 			MIO_RING_Index;
short			Input_Port_Val_MIO[TOTAL_NUMBER_OF_PORTS], Input_Port_Val_Chan_MIO[TOTAL_NUMBER_OF_PORTS][8];
short			Output_Port_Val_MIO[TOTAL_NUMBER_OF_PORTS];
//*******************************************************************************************************************
void			CreateMIOConfigurationTable(void);
void 			GetMIOCofigFileDirectory(void);
void 			InitMIOTable(void);
void 			WriteMIOConfigToFile(int io_sel);
void 			ShowMIOConfigData(int io_sel);
void 			MIO_Dyn_RaMIO1Handle(int i);
void 			DisplayMIOPanel(int Edit);
void 			DisplayMIOConfiguration(int Edit);
void 			LoadMIOPanel(void);
//void 			CreateMANUAIConfigurationTable(int PanelHandler, struct	MIOMANUALPNLPARAM	*ptrPanelControlParams);
//void 			CreateMANUAIConfigurationTable2(int PanelHandler, struct	MIOMANUALPNLPARAM	*ptrPanelControlParams);	
//void 			CreateMANUALConfigurationTable5(int PanelHandler, struct	MIOMANUALPNLPARAM	*ptrPanelControlParams); 
void 			DisplayMANUALConfiguration(void);
//void 			InitMANUALTable(int PanelHandler, struct MANUALPNLPARAM	*ptrPanelControlParams);
//void 			InitMANUALTable2(int PanelHandler, struct MANUALPNLPARAM	*ptrPanelControlParams);

void 			__stdcall MDIO_Dyn_OutputsButton1Handle_LIB(int i, int Device, int TabPanelHandle);
void 			MIO_Dyn_OutputsButton2Handle(int i);
void 			UpdateManualIO(int Type, int Control[], int Device);
void 			UpdateMIOPort(int index, int PortValue, int Control[], int Type, int Device);
int 			InitDABoard(int Device);
void 			CreatManualPnl2Dynamically(void);
//*******************************************************************************************************************
int CVICALLBACK MIO_EditRingCallback (int  panel, int  control, int  event, void *callbackData, 
									  int  eventData1, int  eventData2);

int CVICALLBACK MIO_CommandButtonsCB (int panel, int control, int event,
		                              void *callbackData, int eventData1, int eventData2);
int CVICALLBACK MIO_IndividualNumericControlCB (int panel, int control, int event,
		            							void *callbackData, int eventData1, int eventData2);
int CVICALLBACK MIO_RaMIOControlCB (int panel, int control, int event,
									void *callbackData, int eventData1, int eventData2);
int CVICALLBACK MIOOutputsCommandButtonsCB (int panel, int control, int event,
		                          void *callbackData, int eventData1, int eventData2);									
int CVICALLBACK MIOOutputsCommandButtons2CB (int panel, int control, int event,
		                          void *callbackData, int eventData1, int eventData2);
int CVICALLBACK NumericControl1CB (int panel, int control, int event,
		            void *callbackData, int eventData1, int eventData2);
int CVICALLBACK NumericControl2CB (int panel, int control, int event,
		            void *callbackData, int eventData1, int eventData2);
int CVICALLBACK NumericControl3CB (int panel, int control, int event,
		            void *callbackData, int eventData1, int eventData2);
//*******************************************************************************************************************
void MIOPrtLineName(int Dev, int Port);
void Dyn_Numeric1Handle(int i);
void Dyn_Numeric2Handle(int i);
void Dyn_Numeric3Handle(int i);

void Dyn_Numeric21Handle(int i);
void Dyn_Numeric22Handle(int i);
void Dyn_Numeric32Handle(int i);


int __stdcall InitMDIOInterface_LIB(int Device, int totalNumberofPorts, int outputPortStarts);
int __stdcall InitializeMIOAnalogInput_LIB(int Device, int totalChannels, int differential, int type);
int __stdcall InitializeMIOAnalogOutput_LIB(int Device, int totalChannels);
void __stdcall ReadDIOTimerCB_LIB(void);
void __stdcall ReadDAITimerCB_LIB(int TabPanelHandle);

void DisplayMANUALMIOConfiguration(void);
void DisplayMANUALMIOConfiguration2(void);

short __stdcall MDIOReadInput_LIB(char* DIO_Discription, int Device);

int __stdcall MDIOWriteOutput_LIB(char* DIO_Discription, int state, int Device);

void MIOUpdateManualIO(int Type, int Control[], int Device);
double __stdcall MAIReadInputMultiChan_LIB(char* AI_Discription, int totalChannelNumber, int AISamplePerChannel,
	                                       double maxVal, double minVal, char InputTermCfg[], double timeOut, int deviceNum, int nestNum, double aread[100]);
bool __stdcall DetermineMAIReadInputChan_LIB(int tIndex, double aValue, int tNest, double highLimit, double lowLimit);
double __stdcall MAIReadInput_LIB(char* AI_Discription);
double __stdcall MAOWriteOutput_LIB(char* AO_Discription, double value, int Device);
void __stdcall ReadDIOTimer2CB_LIB(void);
void __stdcall ReadDAITimer2CB_LIB(int TabPanelHandle);
///int MDIOWriteOutput(char* DIO_Discription, int state);
//*******************************************************************************************************************
