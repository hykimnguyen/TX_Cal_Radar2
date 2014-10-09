#include <ansi_c.h>
#include <formatio.h>
#include <utility.h>
//*******************************************************************************************************************
// ===== START OF CORE.H FILE ===== 

#ifndef __INVO_DATA_H_
#define __INVO_DATA_H_

// if set to 1, compile module using external main 
#define 		USE_EXT_MAIN_PROJ					1		

#define			TEST_REPORTS_TEXT_BOX				30 

#define			DYN_NUMERIC1_CONST   			   	100
#define			DYN_NUMERIC2_CONST   				100
#define			DYN_NUMERIC3_CONST   				100

#define			DYN_EDIT1_CONST   					10
#define			DYN_EDIT2_CONST   					10
#define			DYN_EDIT3_CONST   					10

#define			CT_DYN_EDIT1_CONST 					10
#define			CT_DYN_NUMERIC1_CONST  			   	10
#define			CT_DYN_NUMERIC2_CONST  				10
#define			CT_DYN_RADIO_INT1_CONST				6  

#define			ARRAY_SIZE							100
#define			NUMBEROFCOLUMNSCONST				30
#define			SYS_ROW_INDEX_CONSTANT				30
#define			NUMBEROFTABLESCONST					100
#define			NUMBEROFTABLECOLUMNSCONST 			10
#define			PART_CONFIG_ROW_INDEX_CONSTANT		10
#define			AI_CONFIG_ROW_INDEX_CONSTANT		10
#define			AO_CONFIG_ROW_INDEX_CONSTANT		10
#define			MDIO_CONFIG_ROW_INDEX_CONSTANT		10
#define			FRC_CONFIG_ROW_INDEX_CONSTANT		3
													   
#define			NUM_TOT_TESTS						50
#define			TOT_UNITS_PER_BANK					15
#define			TOT_NUM_BANKS						5

#define			DMM_EDIT_RING_ITEMLABEL_CONST		50
#define			DMM_MODE_TYPE_DESCRIPTION_CONST		50
#define			DMM_TEXT_TITLE_DES_CONST   		   	50
//*******************************************************************************************************************
#define			DYN_RADIO_INT1_CONST				12
#define			DYN_RADIO_INT2_CONST     			10
#define			DYN_RADIO_INT3_CONST     		   	10
#define			DYN_RADIO_INT4_CONST     		   	10

#define			DYN_RADIO_1_CONST					10
#define			DYN_RADIO_2_CONST					10
#define			DYN_RADIO_3_CONST					10
#define			DYN_RADIO_4_CONST					10

#define			DYN_EDIT1_CONST   					10
#define			DYN_EDIT2_CONST   					10
#define			DYN_EDIT3_CONST   					10

#define			ARRAY_SIZE							100
#define			NUMBEROFCOLUMNSCONST				30
#define			SYS_ROW_INDEX_CONSTANT				30
#define			NUMBEROFTABLESCONST					100
#define			NUMBEROFTABLECOLUMNSCONST 			10
#define			PART_CONFIG_ROW_INDEX_CONSTANT		10
#define			PART_SEL_CONFIG_ROW_INDEX_CONSTANT	10
#define			MDIO_CONFIG_ROW_INDEX_CONSTANT		10
#define			DIO_CONFIG_ROW_INDEX_CONSTANT		10
#define			SW_CONFIG_ROW_INDEX_CONSTANT		5
#define			CAN_CONFIG_ROW_INDEX_CONSTANT		6
#define			CT_CONFIG_ROW_INDEX_CONSTANT		6

//*******************************************************************************************************************
#define 		DAYOFTHEWEEK_SIZE 					7
//*******************************************************************************************************************
//*******************************************************************************************************************
#define 		BIT0  0x1
#define 		BIT1  0x2
#define 		BIT2  0x4
#define 		BIT3  0x8
#define 		BIT4  0x10
#define 		BIT5  0x20
#define 		BIT6  0x40
#define 		BIT7  0x80

enum 	{	PORT0, PORT1, PORT2, 	// ports configured as input
	  		PORT3, PORT4, PORT5, 	// ports configured as output
	 	}	dio_port;

typedef enum {DIO_FALSE, DIO_TRUE} DIO_boolean;
enum {DIO_READ, DIO_WRITE};
int	   	First_Manual_Pnl, Second_Manual_Pnl; 
//*******************************************************************************************************************
// MAIN Module Data
//*******************************************************************************************************************
 typedef 		enum{DATA_FALSE, DATA_TRUE}TF;   

//*******************************************************************************************************************
// GRYPH_DRV Module Data
//*******************************************************************************************************************
#define 		BUFF_SIZE 256
#define 		GRYPH_LIB_TRUE 1
#define 		GRYPH_LIB_FALSE 0

enum 			{VOLTS=1,mVOLTS=2,AMPS=3,mAMPS=4,OHMS=5,MOHMS=6};  



char 			LIB_ERROR_CODE_DESCRIPTION[100][100];
char 			TogleButtonTitle1[10][100];
char 			GRYPH_EDIT_RING_ITEMLABEL[10][100];
char 			GRYPH_EDIT_RING_ITEMLABEL1[30][100];
char 			GRYPH_EDIT_RING_ITEMLABEL2[30][100];
char 			EDIT1_LABEL_TITLE[100];
							  							
char 			EDIT1_DEFAULT_TEXT1[DYN_EDIT1_CONST][100];

char 			GRYPH_CHLED_LABEL_TITLE[20][100];
							   			
char 			GRYPH_CHKBOX_LABEL_TITLE[10][100];


int						OnEventChannelNumber;

/* frame attributes: */
unsigned char 			hdrlen, extralen, mode;
unsigned short 			datalen;

unsigned char 			*headerbytes;
unsigned char 			*databytes;
unsigned char 			*extrabytes;

unsigned char			Actual_msg[256];
int						Disp_All_Diag_Data, Disp_Rec_Data;
int						Lib_Error_Code;
int						LogUtility;
int 					DOMERCEDES, DOACURATL, DOGMT900;
int 					scanMode,scanEnabled[43],units[43];

unsigned char* ActualMsg_ConvertHex2Dec(char* Buffer, int msg_len);
/******************************************************************************************************************
Data for Serial Communication
*******************************************************************************************************************/
unsigned char Tx[512];
unsigned char Rx[512];
unsigned char RowData[512];
unsigned char ExpectedRx[512]; 
unsigned char 	SendBuffer[512];
#define NR_OF_EXPECTED_RX_CHAR	22		
//*******************************************************************************************************************
// PART_SELECT Module Data
//*******************************************************************************************************************
char 			*modes[4];  
//*******************************************************************************************************************
// FUNCTIONAL_TEST Module Data
//*******************************************************************************************************************
//*******************************************************************************************************************
// COUNTER_TIMER_CONFIG Module Data
//*******************************************************************************************************************
char			CT_NUMERIC1_LABEL_TITLE[CT_DYN_NUMERIC1_CONST][100];
char			CT_NUMERIC2_LABEL_TITLE[CT_DYN_NUMERIC2_CONST][100];
char			CT_EDIT1_LABEL_TITLE[CT_DYN_EDIT1_CONST][100];
char			CT_EDIT1_DEFAULT_TEXT1[CT_DYN_EDIT1_CONST][100];
char			CT_RADIO1_LABEL_TITLE[CT_DYN_RADIO_INT1_CONST][100];
//*******************************************************************************************************************
// DIO_CONFIG Module Data
//*******************************************************************************************************************

char 			EDIT_RING_ITEMLABEL[30][100];
//*******************************************************************************************************************
// GPIB
//*******************************************************************************************************************
void SetGPIBUnits(int line); 
//*******************************************************************************************************************

//*******************************************************************************************************************
struct		TBP	{ //TABLE PARAMETER
					int ControlTop;
					int Height;
					int Width;
					int ControlLeft;
   					int ColumnIndex;
   					int RowIndex;
   					int CelDataType;
   	  			};	//TableParameters[NUMBEROFTABLESCONST];

struct 		TCP	{ //TABLE COLUMN PARAMETER
					int ColumnIndex;
					int NumberofColumns;
					int CelDataType;
					int Width;
					char DYN_TABLE_COLUMN_LABEL_TEXT[NUMBEROFCOLUMNSCONST][100];
					int NumericInt;
  	  			};	// TableColumnParameters[NUMBEROFTABLECOLUMNSCONST][NUMBEROFCOLUMNSCONST];
  	  			
struct		TRC	{  //TABLE ROW COLUMN
					int		Num_of_Rows;
					int		Num_of_Columns;
	 			};	// TableRowsandColumns;					 
//*******************************************************************************************************************
struct	TBP			DIO_MN_TableParameters, *Ptr_DIO_MN_TableParameters;
struct 	TCP 		DIO_MN_ColumnParameters[NUMBEROFTABLESCONST], *Ptr_DIO_MN_ColumnParameters;

struct	TBP			DIO_TableParameters, *Ptr_DIO_TableParameters;
struct 	TCP 		DIO_ColumnParameters[NUMBEROFTABLESCONST], *Ptr_DIO_ColumnParameters;

struct	TBP			SYS_CONFIG_TableParameters, *Ptr_SYS_CONFIG_TableParameters;
struct 	TCP 		SYS_CONFIG_ColumnParameters[NUMBEROFTABLESCONST], *Ptr_SYS_CONFIG_ColumnParameters;

struct	TBP			PART_CONFIG_TableParameters, *Ptr_PART_CONFIG_TableParameters, AI_CONFIG_TableParameters, *Ptr_AI_CONFIG_TableParameters,
					AI_CONFIG_TableParameters2, *Ptr_AI_CONFIG_TableParameters2,
					AO_CONFIG_TableParameters, *Ptr_AO_CONFIG_TableParameters, DIO_CONFIG_TableParameters, DIO2_CONFIG_TableParameters, 
					AO_CONFIG_TableParameters2, *Ptr_AO_CONFIG_TableParameters2, DIO_CONFIG_TableParameters2, DIO2_CONFIG_TableParameters2, 
					SW_CONFIG_TableParameters, CAN_CONFIG_TableParameters, CT_CONFIG_TableParameters,
					
					MDIO_CONFIG_TableParameters, *Ptr_MDIO_CONFIG_TableParameters, MDIO_CONFIG_TableParameters2, *Ptr_MDIO_CONFIG_TableParameters2,
					FRC_CONFIG_TableParameters, *Ptr_FRC_CONFIG_TableParameters, *Ptr_SP_CONFIG_TableParameters, MSCI_CONFIG_TableParameters, *Ptr_MISC_CONFIG_TableParameters, 
					
					TST_CONFIG_TableParameters,TST_CONFIG_TableParameters, *Ptr_TST_CONFIG_TableParameters, *Ptr_DIO_CONFIG_TableParameters, 
					*Ptr_SW_CONFIG_TableParameters, *Ptr_CAN_CONFIG_TableParameters, *Ptr_CT_CONFIG_TableParameters, 
					*Ptr_DIO2_CONFIG_TableParameters,MSCI_CONFIG_TableParameters, *Ptr_MISC_CONFIG_TableParameter, 	PART_CONFIG_TableParameters, *Ptr_PART_CONFIG_TableParameters,
					FRC_CONFIG_TableParameters, SP_CONFIG_TableParameters, *Ptr_FRC_CONFIG_TableParameter;

struct 	TCP 		PART_CONFIG_ColumnParameters[NUMBEROFTABLESCONST], *Ptr_PART_CONFIG_ColumnParameters,
					AI_CONFIG_ColumnParameters[NUMBEROFTABLESCONST], *Ptr_AI_CONFIG_ColumnParameters,
					AO_CONFIG_ColumnParameters[NUMBEROFTABLESCONST], *Ptr_AO_CONFIG_ColumnParameters,
					MDIO_CONFIG_ColumnParameters[NUMBEROFTABLESCONST], *Ptr_MDIO_CONFIG_ColumnParameters,
					
					AI_CONFIG_ColumnParameters2[NUMBEROFTABLESCONST], *Ptr_AI_CONFIG_ColumnParameters2,
					AO_CONFIG_ColumnParameters2[NUMBEROFTABLESCONST], *Ptr_AO_CONFIG_ColumnParameters2,
					MDIO_CONFIG_ColumnParameters2[NUMBEROFTABLESCONST], *Ptr_MDIO_CONFIG_ColumnParameters2,
					
					DIO_CONFIG_ColumnParameters[NUMBEROFTABLESCONST], DIO2_CONFIG_ColumnParameters[NUMBEROFTABLESCONST], 
					SW_CONFIG_ColumnParameters[NUMBEROFTABLESCONST], CAN_CONFIG_ColumnParameters[NUMBEROFTABLESCONST],
					CT_CONFIG_ColumnParameters[NUMBEROFTABLESCONST],
					*Ptr_DIO_CONFIG_ColumnParameters,*Ptr_DIO2_CONFIG_ColumnParameters, *Ptr_SW_CONFIG_ColumnParameters, 
					*Ptr_CAN_CONFIG_ColumnParameters, *Ptr_CT_CONFIG_ColumnParameters,
					MSCI_CONFIG_ColumnParameters[NUMBEROFTABLESCONST], *Ptr_MISC_CONFIG_ColumnParameters, 
					*Ptr_FRC_CONFIG_ColumnParameters, *Ptr_SP_CONFIG_ColumnParameters, FRC_CONFIG_ColumnParameters[NUMBEROFTABLESCONST],
					SP_CONFIG_ColumnParameters[NUMBEROFTABLESCONST],
					TST_CONFIG_ColumnParameters[NUMBEROFTABLESCONST], *Ptr_TST_CONFIG_ColumnParameters;

struct	TRC			DIO_MN_TableRowsandColumns, DIO_TableRowsandColumns, 
					SYS_CONFIG_TableRowsandColumns, PART_CONFIG_TableRowsandColumns,
					AI_CONFIG_TableRowsandColumns, MISC_CONFIG_TableRowsandColumns, FRC_CONFIG_TableRowsandColumns,
					SP_CONFIG_TableRowsandColumns,
					AO_CONFIG_TableRowsandColumns, MDIO_CONFIG_TableRowsandColumns, 

					AI_CONFIG_TableRowsandColumns2,AO_CONFIG_TableRowsandColumns2, MDIO_CONFIG_TableRowsandColumns2, 
					
					PART_SEL_CONFIG_TableRowsandColumns, MODE_SEL_CONFIG_TableRowsandColumns,
					TST_CONFIG_TableRowsandColumns, DIO_CONFIG_TableRowsandColumns, DIO2_CONFIG_TableRowsandColumns,
					SW_CONFIG_TableRowsandColumns, CAN_CONFIG_TableRowsandColumns, CT_CONFIG_TableRowsandColumns;

struct	TBP			PART_SEL_CONFIG_TableParameters, *Ptr_PART_SEL_CONFIG_TableParameters;
struct 	TCP 		PART_SEL_CONFIG_ColumnParameters[NUMBEROFTABLESCONST], *Ptr_PART_SEL_CONFIG_ColumnParameters;

struct	TBP			MODE_SEL_CONFIG_TableParameters, *Ptr_MODE_SEL_CONFIG_TableParameters;
struct 	TCP 		MODE_SEL_CONFIG_ColumnParameters[NUMBEROFTABLESCONST], *Ptr_MODE_SEL_CONFIG_ColumnParameters;
//*******************************************************************************************************************	 			
int				MAIN_config_File_Exist;
int				NumberofTableRows;
int 			NUM_ROWS, NUM_COLUMNS;
//*******************************************************************************************************************
struct	TRC			MAIN_TableRowsandColumns;

struct	TBP			MAIN_TableParameters, *Ptr_MAIN_TableParameters;
struct 	TCP 		MAIN_ColumnParameters[100], *Ptr_MAIN_ColumnParameters;
//*******************************************************************************************************************
int 			NumericalControl1, NumericalControl2,
    			DYN_RADIO_INT1[DYN_RADIO_INT1_CONST],   DYN_RADIO_INT2[DYN_RADIO_INT2_CONST],    
    			DYN_RADIO_INT3[DYN_RADIO_INT3_CONST],   DYN_RADIO_INT4[DYN_RADIO_INT4_CONST],

    		
    			DYN_NUMERIC1[DYN_NUMERIC1_CONST], DYN_NUMERIC2[DYN_NUMERIC2_CONST],  
    			DYN_NUMERIC3[DYN_NUMERIC2_CONST],

    			DYN_NUMERIC21[DYN_NUMERIC1_CONST], DYN_NUMERIC22[DYN_NUMERIC2_CONST],  
    			DYN_NUMERIC32[DYN_NUMERIC2_CONST],
				
    			DECO_CONTROL1, DECO_CONTROL2, DECO_CONTROL3, DECO_CONTROL4, DECO_CONTROL5,

    			DYN_EDIT1[DYN_EDIT1_CONST], DYN_EDIT2[DYN_EDIT2_CONST],
    			DYN_EDIT3[DYN_EDIT3_CONST],
    		
    			DECO_CONTROL1, DECO_CONTROL2, DECO_CONTROL3, DECO_CONTROL4,
    		
    			NUMERICTextTitle1[DYN_NUMERIC1_CONST], EditTextTitle1[DYN_EDIT1_CONST],   
    			EDIT_TEXT_TITLE1[DYN_EDIT1_CONST],
				
    			NUMERICTextTitle21[DYN_NUMERIC1_CONST], EditTextTitle21[DYN_EDIT1_CONST],   
    			EDIT_TEXT_TITLE21[DYN_EDIT1_CONST],
				
				
    			DECO_TEXT_MSG1,        DECO_TEXT_MSG2,       DECO_TEXT_MSG3,
    		
    			DYN_TABLE1,
    			TextTitle1, TextTitle2;

int				DYN_RADIO_INT1_ARRAY[50], DYN_RADIO_INT2_ARRAY[50],
				DYN_RADIO_INT3_ARRAY[50], DYN_RADIO_INT4_ARRAY[50];

int				Decoration_1_Left, Decoration_2_Left, Decoration_3_Left, Decoration_4_Left, Decoration_5_Left,
				Decoration_1_Top, Decoration_2_Top, Decoration_3_Top, Decoration_4_Top, Decoration_5_Top,
				Decoration_1_Width, Decoration_2_Width, Decoration_3_Width, Decoration_4_Width, Decoration_5_Width,
				Decoration_1_Height,Decoration_2_Height, Decoration_3_Height, Decoration_4_Height,Decoration_5_Height;

double			DYN_NUMERIC1_ARRAY[DYN_NUMERIC1_CONST];
char 			DYN_EDIT1_ARRAY[DYN_EDIT1_CONST][100];
int				DYN_NUMERIC2_ARRAY[DYN_NUMERIC2_CONST];

char 			Edit_Msg[11][100];

int				Decoration_1_Left, Decoration_2_Left, Decoration_3_Left, Decoration_4_Left, 
				Decoration_1_Top, Decoration_2_Top, Decoration_3_Top, Decoration_4_Top,
				Decoration_1_Width, Decoration_2_Width, Decoration_3_Width, Decoration_4_Width,
				Decoration_1_Height,Decoration_2_Height, Decoration_3_Height, Decoration_4_Height;

int  			red, blue, black;
char 			item_label[100], buf[200]; 
int  			item_val;
long 			file_size;

struct			{ 
					char	S_Day[DAYOFTHEWEEK_SIZE][100];
					int 	S_1HR[DAYOFTHEWEEK_SIZE];
					int	 	S_1MIN[DAYOFTHEWEEK_SIZE];
					int 	S_2HR[DAYOFTHEWEEK_SIZE];
					int 	S_2MIN[DAYOFTHEWEEK_SIZE];
					int 	S_3HR[DAYOFTHEWEEK_SIZE];
					int 	S_3MIN[DAYOFTHEWEEK_SIZE];
	  			}	Shift_Configuration;

int   			shift;
char  			date_code[20];
char 			TimeStamp[20];
//*******************************************************************************************************************
//*******************************************************************************************************************
int				FaultCodeNum[100];
char			FaultCodeDDescription[100][200];
int				TNFaultCodeLines;
//*******************************************************************************************************************
// SYSTEM_CONFIG Module Data
//*******************************************************************************************************************
char			NUMERIC1_LABEL_TITLE[DYN_NUMERIC1_CONST][100];
char			NUMERIC2_LABEL_TITLE[DYN_NUMERIC2_CONST][100];
char			NUMERIC3_LABEL_TITLE[DYN_NUMERIC2_CONST][100];

char			NUMERIC21_LABEL_TITLE[DYN_NUMERIC1_CONST][100];
char			NUMERIC22_LABEL_TITLE[DYN_NUMERIC2_CONST][100];
char			NUMERIC32_LABEL_TITLE[DYN_NUMERIC2_CONST][100];

char			SYS_EDIT1_LABEL_TITLE[DYN_EDIT1_CONST][100];
char			SYS_EDIT1_DEFAULT_TEXT1[DYN_EDIT1_CONST][100];
char			RADIO1_LABEL_TITLE[50][100];
char			RADIO2_LABEL_TITLE[50][100];
char			RADIO3_LABEL_TITLE[50][100];
char			RADIO4_LABEL_TITLE[50][100];
//*******************************************************************************************************************
struct STestStep
	 {
    	char testNumber[100];
    	char testName[100];
    	char TestFRCommands[100];
    	char TestHighLimit[100];
    	char TestLowLimit[100];
    	char testStatus[100];
    	char TestTimeout[100];
    	char TestRepeat[100];
    	char TestCommandDelay[100];
    	char TestResult[100];
    	char TestNest[100];
		char SerialNumber[100];
	 }	TestStepInfo[50], temp_TestStepInfo[50]; 

//*******************************************************************************************************************
int  	CVICALLBACK (*funcptrCreateNumericalControl)  (int panel, int control, int event,
                                                               void *callbackData, int eventData1, 
                                                               int eventData2); 
int     CVICALLBACK (*funcptrCreateNumericalControls) (int panel, int control, int event,
															   void *callbackData, int eventData1, 
															   int eventData2);
int  	CVICALLBACK (*funcptrCreateButtonControl)	  (int panel, int control, int event,
		                          							   void *callbackData, int eventData1, 
		                          							   int eventData2);
int  	CVICALLBACK (*funcptrRadioCheckButtonControls)(int panel, int control, int event,
															   void *callbackData, int eventData1, 
															   int eventData2);   
int  	CVICALLBACK (*funcptrCreateUtilButtonControls) 	  (int panel, int control, int event,
														  	   void *callbackData, int eventData1, 
														  	   int eventData2); 
int  	CVICALLBACK (*funcptrCreateButtonControls) 	  (int panel, int control, int event,
														  	   void *callbackData, int eventData1, 
														  	   int eventData2);	
int  	CVICALLBACK (*funcptrCreateTextBoxControl) 	  (int panel, int control, int event,
															   void *callbackData, int eventData1, 
															   int eventData2);
int  	CVICALLBACK (*funcptrCreateEditRingControl)   (int  panel, int  control, int  event,
									 						   void *callbackData,int  eventData1, 
									 						   int  eventData2);
int  	CVICALLBACK (*funcptrCreateCLosePanel)        (int panel, int event, void *callbackData,
															   int eventData1, int eventData2);
//*******************************************************************************************************************
//*******************************************************************************************************************
/////char*  __stdcall  IO_Error(void);
char*  __stdcall  GetItemLabel(int ControlID);
void  __stdcall GetDateCode(int Panel, int Ctrl);

//*******************************************************************************************************************
int			NumberofTableRows;

int __stdcall  LIB_CreateNumericalControl(int ControlPanelHandle, char ExternalModuleNames[], char CallBackEventHandler[],
						        int ControlTop, int ControlLeft, int CtrlWidth, int DataType, char NUMERIC_LABEL_TITLE[100],
						        int LabelWidth, double DefaultValue, int MaxValue, int MinValue, int FontColor, 
						        int BackGroundColor, int Font_Size, int Font_Justification, int Title_Color,
						        int ControlMode, int Txt_Font_Size, int Precision, int Txt_Bold);

int __stdcall  LIB_CreateNumericControls(int ControlPanelHandle, char ExternalModuleNames[], char CallBackEventHandler[],
						       int DYN_NUMERIC_INT[], int NUMERIC_TEXT_TITLE[], int ControlTop, int Height, 
						       int TextCtrlWidth, int CtrlWidth, int ControlLeft,int NumberofNumericControls, 
						       int DataType, char NUMERIC_LABEL_TITLE[][100], int FontColor, 
						       int BackGroundColor, int Font_Size, int Font_Justification, int Title_Color,
						       int ControlMode, int Txt_Font_Size, int Precision);
int __stdcall LIB_CreateNumericControls1(int ControlPanelHandle, char ExternalModuleNames[], char CallBackEventHandler[],
						       			int DYN_NUMERIC_INT[], int NUMERIC_TEXT_TITLE[], int ControlTop, int Height, 
						       			int TextCtrlWidth, int CtrlWidth, int ControlLeft,int NumberofNumericControls, 
						       			int DataType, char NUMERIC_LABEL_TITLE[][100], int FontColor, 
						       			int BackGroundColor, int Font_Size, int Font_Justification, int Title_Color,
						       			int ControlMode, int Txt_Font_Size, int Precision, int StartSecondRow, int Second_Row_Control_Left);

						 
int __stdcall  LIB_CreateTextMesage(int ControlPanelHandle, char ExternalModuleNames[],
					      			 int Contrl_Top, int Contrl_Left, char Edit_Msg[], 
                          			 int TextWidth, int TextHeight, int Raised);

int __stdcall  LIB_CreateEditControl(int ControlPanelHandle, char ExternalModuleNames[],
					       			  int EDIT_TEXT_TITLE, int ControlTop, int Height, int TextCtrlWidth, 
					       			  int CtrlWidth, int ControlLeft, char EDIT_LABEL_TITLE[100],
					       		      char EDIT_DEFAULT_TEXT[100], int FontColor, int BackGroundColor, int Text_Size,
					       			  int Font_Justification, int Title_Color);

int __stdcall  LIB_CreateEditControls(int ControlPanelHandle, char ExternalModuleNames[], 
					        		   int EDIT_TEXT_TITLE[], int EDIT_CONTROL[], int ControlTop, int Height, int TextCtrlWidth, 
					        		   int CtrlWidth, int ControlLeft, int NumberofEDITCONTROL, char EDIT_LABEL_TITLE[][100], 
					        		   char EDIT_DEFAULT_TEXT[][100], int FontColor, int BackGroundColor, int Text_Size,
					        		   int Font_Justification, int Title_Color);

int __stdcall  LIB_CreatRadioCheckButtonControls(int ControlPanelHandle, char ExternalModuleNames[], char CallBackEventHandler[],
								       			  int DYN_RADIO_INT[], int ControlTop, int Height, int ControlWidth, int LabelWidth, 
								       			  int ControlLeft, int NumberofRadioControls, int SetControlStyle, 
								       			  char RADIO_LABEL_TITLE[][100], int ControlSeparation, int Index);

int __stdcall  LIB_CreateDecorationControl(int ControlPanelHandle, char ExternalModuleNames[], 
							     			int ControlTop, int Height, int ControlLeft, int ControlWidth, char Text_Message[]);

int __stdcall  LIB_CreateButtonControls(int ControlPanelHandle, char ExternalModuleNames[100],char CallBackEventHandler[],
						      			 int DYN_BUTTON[], int ControlTop, int Height, int ControlWidth, int ControlLeft, 
					            		 int NumberofButtons, char BUTTON_LABEL_TITLE[10][100], int ButtonType);

int __stdcall  LIB_CreateButtonControl(int ControlPanelHandle, char ExternalModuleNames[], char CallBackEventHandler[],
						     			int DYN_BUTTON, int ControlTop, int Height, int ControlWidth, int ControlLeft, 
					         			char BUTTON_LABEL_TITLE[100], int ButtonType);
					    
int __stdcall  LIB_CreateUtilButtonControls(int ControlPanelHandle, char ExternalModuleNames[100],char CallBackEventHandler[],
						          			 int DYN_BUTTON[], int DYN_LED_OUT[], int ControlTop, int Height, int LEDCtrlWidth,
						          			 int LEDCtrlHeight, int CtrlWidth, int ControlLeft, int NumberofButtons, 
						          			 char BUTTON_LABEL_TITLE[10][100], int StartSecondRow, int Second_Row_Control_Left, 
						          			 int ControlSeparation, int ButtonType, int LEDType);

int __stdcall  LIB_CreateToggleButtonControls(int ControlPanelHandle, char ExternalModuleNames[100],char CallBackEventHandler[],
						      				   int DYN_BUTTON[], int ControlTop, int Height, int Width, int ControlLeft, 
					             			   int NumberofButtons, char BUTTON_LABEL_TITLE[10][100], int ButtonType);

int __stdcall  LIB_CreateLEDControls(int ControlPanelHandle, char ExternalModuleNames[100],
					       			  int LED_TEXT_TITLE[], int LED[], int ControlTop, int Height, int LEDCtrlWidth, 
                           			  int ControlLeft, int NumberofLED, int StartSecondRow, char LED_LABEL_TITLE[10][100], 
                           			  int TextCtrlWidth, int LED_Text_Title_Width, int Second_Row_Control_Left, 
                           			  int Text_Msg_Font_Size, int LED_Text_Height, int ControlSeparation, int LEDType);

int __stdcall  LIB_CreateRingControl(int ControlPanelHandle, char ExternalModuleNames[], char CallBackEventHandler[],
					       			  int DYN_RING, int ControlTop, int ControlHeight, int ControlWidth, int ControlLeft, 
					       			  char BUTTON_LABEL_TITLE[100]);
int __stdcall  LIB_CreateTextBox(int ControlPanelHandle, char ExternalModuleNames[], char CallBackEventHandler[],
				       			  int ControlTop, int ControlLeft, int CtrlWidth, char NUMERIC_LABEL_TITLE[100],
				       			  int LabelCtrlWidth, int TextBoxCtrlHeight, int TextBoxLabelCtrlHeight, int CtrlMode);
int __stdcall  LIB_CreateNumericSlide(int ControlPanelHandle, char ExternalModuleNames[],
				  	        		   int ControlTop, int ControlLeft, int CtrlWidth, char NUMERIC_LABEL_TITLE[100],
				  	                   int LabelCtrlWidth, int NumericSlideCtrlHeight, int NumericSlideLabelCtrlHeight,
				  	                   double DefaultValue, int DataType, double IncrementValue, double MaxValue, double MinValue,
				  	                   int CtrlMode, int FillColor, int HousingColor);
int __stdcall  LIB_CreateEditRing(int ControlPanelHandle, char ExternalModuleNames[], char CallBackEventHandler[],
				                   int ControlTop, int ControlLeft, int CtrlWidth, char EDIT_RING_LABEL_TITLE[100],
				                   int LabelCtrlWidth, int EditRingCtrlHeight, int EditRingLabelCtrlHeight, int CtrlMode,
				                   int DataType, char EDIT_RING_ITEMLABEL[][100], int RingValues);
int __stdcall  LIB_CreateListCtrl(int ControlPanelHandle, char ExternalModuleNames[], char CallBackEventHandler[],
				                   int ControlTop, int ControlLeft, int CtrlWidth, char LIST_BOX_LABEL_TITLE[100],
				                   int LabelCtrlWidth, int ListBoxCtrlHeight, int ListBoxLabelCtrlHeight, int CtrlMode, 
				                   int DataType);
//*******************************************************************************************************************
void __stdcall  LIB_CreateTableColumnParam_OLD(int TableIndex, int Index, int ColumnIndex, int NumberofColumns, int CelDataType, 
							         			int Width, char LABEL_TEXT[], int NumericInt);

void __stdcall  LIB_CreateTableColumnParam(struct TCP *Ptr_CreateTableColumnParam_Test, int Index, int ColumnIndex, 
								 			int NumberofColumns, int CelDataType, 
								 			int Width, char LABEL_TEXT[], int NumericInt);

void __stdcall  LIB_CreateTableParam_OLD(	int TableIndex, int ControlTop, int Height, int Width, int ControlLeft, int ColumnIndex, 
						        			int RowIndex, int CelDataType);

void __stdcall  LIB_CreateTableParam(	struct TBP *Ptr_TableParameters, int ControlTop, int Height, int Width, int ControlLeft, 
                            			int ColumnIndex, int RowIndex, int CelDataType);
						
int __stdcall  LIB_CreatTableControl_OLD(int TableIndex, int ControlPanelHandle, char ExternalModuleNames[], int DYN_TABLE);

int __stdcall  LIB_CreatTableControl(	struct TBP *Ptr_TableParameters, int ControlPanelHandle, char ExternalModuleNames[], 
						   				int DYN_TABLE);

int __stdcall  LIB_DYNInsertTableColumns_OLD(	int TableIndex, int ControlPanelHandle, char ExternalModuleNames[], int DYN_TABLE, 
						           				int ColumnNumber); 
						  
int __stdcall  LIB_DYNInsertTableColumns(struct TCP *Ptr_CreateTableColumnParam_Test, struct TBP *Ptr_TableParameters,
							   			  int ControlPanelHandle, char ExternalModuleNames[], int DYN_TABLE, int ColumnNumber);
							   
void __stdcall  LIB_DynamicInsertTableRow(	int ControlPanelHandle, int DYN_TABLE, int Num_of_Rows, int Num_of_Columns,
                                			struct TCP *Ptr_ColumnParameters);
                                
void __stdcall  LIB_DynamicDeleteTableRow(int ControlPanelHandle, int DYN_TABLE, int RowIndex, int Num_Rows_to_Delete);

int __stdcall  LIB_CreateDecorationControl(int ControlPanelHandle, char ExternalModuleNames[], 
						    	 int ControlTop, int Height, int ControlLeft, int ControlWidth, char Text_Message[]);

int __stdcall LIB_CreateTextMesage(int ControlPanelHandle, char ExternalModuleNames[],
					      int Contrl_Top, int Contrl_Left, char Edit_Msg[], 
                          int TextWidth, int TextHeight, int Raised);

int __stdcall LIB_CreateLEDControls1(int ControlPanelHandle, char ExternalModuleNames[100],
					       int LED_TEXT_TITLE[], int LED[], int ControlTop, int Height, int LEDCtrlWidth, 
                           int ControlLeft, int NumberofLED, int StartSecondRow, char LED_LABEL_TITLE[10][100], 
                           int TextCtrlWidth, int LED_Text_Title_Width, int Second_Row_Control_Left, 
                           int Text_Msg_Font_Size, int LED_Text_Height, int ControlSeparation);

int __stdcall LIB_CreateUtilButtonControls1(int ControlPanelHandle, char ExternalModuleNames[100],char CallBackEventHandler[],
						          int DYN_BUTTON[], int DYN_LED_OUT[], int ControlTop, int Height, int LEDCtrlWidth,
						          int LEDCtrlHeight, int CtrlWidth, int ControlLeft, int NumberofButtons, 
						          char BUTTON_LABEL_TITLE[][100], int StartSecondRow, int Second_Row_Control_Left, 
						          int ControlSeparation, int ButtonType);

int __stdcall VerifyOpenFileRead(char dir[MAX_PATHNAME_LEN], char *type, FILE *(*fp));

int __stdcall MakeBackUpCopy(char dir[MAX_PATHNAME_LEN]);

int __stdcall VerifyOpenFileWrite(char dir[MAX_PATHNAME_LEN], char *type, FILE *(*fp));

void  BuildTestSequence(void);
void  TempFuncPtr(void);
void  TempFuncPtr(void);

#endif                              
                                    
// ===== END OF DATA.H FILE =====   
