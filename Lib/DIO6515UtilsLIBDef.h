#include <DAQmxIOctrl.h>
#include <NIDAQmx.h> 
//*******************************************************************************************************************
#define			DIO6515_ROW_INDEX_CONSTANT		32
#define			DIO6515_DYN_RADIO_INT1_CONST	32
#define			TOTAL_IO_DIO6515_ROWS			64
#define			TOTAL_INPUT_DIO6515_LINE		32
#define			TOTAL_OUTPUT_DIO6515_LINE		32 
#define			TOTAL_NUMBER_OF_DIO6515_PORTS	8 // 3	  
#define			BIT_7							0x80
#define			BIT_6							0x40
#define			BIT_5							0x20
#define			BIT_4							0x10
#define			BIT_3							0x08
#define			BIT_2							0x04
#define			BIT_1							0x02
#define			BIT_0							0x01

#define			TOT_DIO6515_LINE1				96
#define			MAX_CHAR_LEN1					50
//*******************************************************************************************************************
struct		MANUALPNLPARAM6515	{ //MANUAL PANEL CONTROLS PARAMETER  
								int 		NumberofDevices;
								int			DIO6515_DECORATION_INPUT;
								int			DIO6515_DECORATION_INPUT2;
								int 		DIO6515_DECORATION_OUTPUT;
								int 		DIO6515_DECORATION_OUTPUT2;
								char		External_Module_Name[100];
								int			DIO6515_DECORATION_INPUT_LEFT;
								int			DIO6515_DECORATION_INPUT_TOP;
								int			DIO6515_DECORATION_OUTPUT_LEFT;
								int			DIO6515_DECORATION_OUTPUT_TOP;
								char		Device_Title1[100];
								char		Device_Title2[100];
								char		DIO6515_LED_LABEL_TITLE[TOTAL_INPUT_DIO6515_LINE][100];
								int			DIO6515_LEDTextTitle[TOTAL_INPUT_DIO6515_LINE]; 
								int			DIO6515_LED[TOTAL_INPUT_DIO6515_LINE];
								int			DIO6515_DYN_BUTTON[TOTAL_OUTPUT_DIO6515_LINE];
								int			DIO6515_DYN_LED_OUT[TOTAL_OUTPUT_DIO6515_LINE];
								char		DIO6515_ButtonTitle[TOTAL_OUTPUT_DIO6515_LINE][100];
								char		CallBackEventHandler[100];
								int			PortLineOfset;
							};
							
struct		MANUALPNLPARAM6515			DIO6515_MN_PNL_Parameters, *Ptr_DIO6515_MN_PNL_Parameters; 
struct		MANUALPNLPARAM6515			DIO6515_MN_PNL_Parameters2, *Ptr_DIO6515_MN_PNL_Parameters2;
//*******************************************************************************************************************
/*
struct			{ 
					int  DIO_Num;
					char descrp[96][50];	  				 		// 50 MAX_CHAR_LEN1
					int  port[96];									// 96  TOT_DIO6515_LINE1
					int  bit[96];
					int  device[96];					
					int  disable[96];
					char wire_tag[96][20];
					int  num_dio_card;
					struct DIOConfiguration DIO6515Config_Port1[6];
					struct DIOConfiguration DIO6515Config_Port2[6];
	  			}	dio6515;
*/
//*******************************************************************************************************************
int 			MANUAL_GUI_Handle;
int				DYN_TABLE_DIO6515_CONFIG, DYN_TABLE_DIO6515_MN_CONFIG;
int 			DIOconfigpanelHandle;
int 			DIO6515_EDIT_CTRL1, DYN_DIO6515_BUTTON_SAVE; 
int 			DIO6515_LED1[TOTAL_INPUT_DIO6515_LINE],DIO6515_DECORATION_INPUT1, DIO6515_DECORATION_OUTPUT1, 
				DIO6515_DYN_BUTTON1[TOTAL_OUTPUT_DIO6515_LINE], DIO6515_DYN_LED_OUT1[TOTAL_OUTPUT_DIO6515_LINE];
int				DIO6515_Decoration_IN1_Left,DIO6515_Decoration_IN1_Top, DIO6515_Decoration_OUT1_Left,DIO6515_Decoration_OUT1_Top;
int				DIO6515_LEDTextTitle1[TOTAL_INPUT_DIO6515_LINE];
char			DIO6515_LED1_LABEL_TITLE[TOTAL_INPUT_DIO6515_LINE][100];
char 			DIO6515_ButtonTitle1[TOTAL_OUTPUT_DIO6515_LINE][100];

int				DIO6515_NUM_ROWS, DIO6515_NUM_COLUMNS, DIO6515_CONFIG_NUM_DEV;
char 			DIO6515_config_int_dir[MAX_PATHNAME_LEN];
char 			DIO6515_config_ext_dir[MAX_PATHNAME_LEN];
char 			DIO6515_config_int_uir[MAX_PATHNAME_LEN];
char 			DIO6515_config_ext_uir[MAX_PATHNAME_LEN];
char 			DIO6515_config_int_xls[MAX_PATHNAME_LEN];
char 			DIO6515_config_ext_xls[MAX_PATHNAME_LEN];
int				DIO6515_config_file_exist;
char 			DIO6515_config_int_table_dir[MAX_PATHNAME_LEN];
char 			DIO6515_config_int_table_xls[MAX_PATHNAME_LEN];
char 			DIO6515_config_ext_table_xls[MAX_PATHNAME_LEN];
char			DIO6515_config_ext_table_dir[MAX_PATHNAME_LEN];
int				DIO6515_DYN_RADIO6515_INT1[TOTAL_IO_DIO6515_ROWS];
char			DIO6515_RADIO1_LABEL_TITLE[DIO6515_DYN_RADIO_INT1_CONST][100];
int 			DIO6515_RING_Index;
short			Input_Port_Val_DIO6515[TOTAL_NUMBER_OF_DIO6515_PORTS], Input_Port_Val_Chan_DIO6515[TOTAL_NUMBER_OF_DIO6515_PORTS][8];
short			Output_Port_Val_DIO6515[TOTAL_NUMBER_OF_DIO6515_PORTS];
//*******************************************************************************************************************
void			CreateDIOConfigurationTable(void);
void 			GetDIOCofigFileDirectory(void);
void 			InitDIOTable(void);
void 			WriteDIOConfigToFile(int io_sel);
void 			ShowDIOConfigData(int io_sel);
void 			DIO_Dyn_Radio1Handle(int i);
void 			DisplayDIOPanel(int Edit);
void 			DisplayDIOConfiguration(int Edit);
void 			LoadDIOPanel(void);
void 			CreateMANUALConfigurationTable(int PanelHandler, struct	MANUALPNLPARAM6515	*ptrPanelControlParams);
void 			CreateMANUALConfigurationTable2(int PanelHandler, struct	MANUALPNLPARAM6515	*ptrPanelControlParams); 
void 			DisplayMANUAL6515Utils(void);
void 			InitMANUALTable6515(int PanelHandler, struct MANUALPNLPARAM6515	*ptrPanelControlParams);
void 			InitMANUALTable26515(int PanelHandler, struct MANUALPNLPARAM6515	*ptrPanelControlParams);

void 			DIO_Dyn_OutputsButton1Handle(int i, int device);
void 			DIO_Dyn_OutputsButton2Handle(int i, int device);


int __stdcall ReadIO6515TimerCB_LIB (int TabPanelHandle, int Device);
void __stdcall	DIO6515_Dyn_OutputsButton1Handle_LIB(int i, int Device);
void __stdcall DIO6515_Dyn_OutputsButton2Handle_LIB(int i, int Device);
short __stdcall ReadInput6515_LIB(char* DIO_Discription, int Device);
int __stdcall WriteOutput6515_LIB(char* DIO_Discription, int state, int Device);
void __stdcall UpdateManualIO6515_LIB(int Type, int Control[], int Device, int TabPanelHandle);
void __stdcall UpdateIO6515Port_LIB(int index, int PortValue, int Control[], int Type, int Device, int TabPanelHandle);



void 			UpdateManualMIO(int Type, int Control[], int Device);
void 			UpdateIOPort(int index, int PortValue, int Control[], int Type, int Device);

int 			InitDABoard(int Device);
void 			CreatManualPnl2Dynamically(void);
//*******************************************************************************************************************
int CVICALLBACK DIO6515_EditRingCallback (int  panel, int  control, int  event, void *callbackData, 
									  int  eventData1, int  eventData2);

int CVICALLBACK DIO6515_CommandButtonsCB (int panel, int control, int event,
		                              void *callbackData, int eventData1, int eventData2);
int CVICALLBACK DIO6515_IndividualNumericControlCB (int panel, int control, int event,
		            							void *callbackData, int eventData1, int eventData2);
int CVICALLBACK DIO6515_RadioControlCB (int panel, int control, int event,
									void *callbackData, int eventData1, int eventData2);
int CVICALLBACK DIO6515OutputsCommandButtonsCB (int panel, int control, int event,
		                          void *callbackData, int eventData1, int eventData2);									
int CVICALLBACK DIO6515OutputsCommandButtons2CB (int panel, int control, int event,
		                          void *callbackData, int eventData1, int eventData2);
int CVICALLBACK MaualPnl2ClosePanelCB (int panel, int event, void *callbackData,
		                               int eventData1, int eventData2);	
//*******************************************************************************************************************
void DIOPrtLineName(int Dev, int Port);
//*******************************************************************************************************************
