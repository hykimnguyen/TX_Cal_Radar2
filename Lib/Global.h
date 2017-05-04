/*---------------------------------------------------------------------------*/
/*                                                                           */
/* FILE:    Global.h                                                         */
/*                                                                           */
/* PURPOSE: This is the header file for cGlobal.dll. This file is used in    */
/*          two ways -- it is added to the cvidl.dll project to tell         */
/*          LabWindows/CVI to export the symbols contained in it.  It is     */
/*          used by the calling project to gain access to the library        */
/*          function prototypes.                                             */
/*                                                                           */
/*          Note that we explicitly specify a calling convention for our     */
/*          functions.  This is necessary to ensure that caller and callee   */
/*          agree on stack responsibilities.  You should always sepcify a    */
/*          calling convention explicitly when prototyping DLL functions.    */
/*---------------------------------------------------------------------------*/

 /********************************************************************************/
/* Include files                                                                */
/********************************************************************************/
#include <windows.h> 
#include <ansi_c.h> 
#include <formatio.h>

#include <cvixml.h>
#include <cvirte.h>
#include <userint.h>
#include <pathctrl.h>
#include <utility.h>

#include "cvixml.h"
#include "toolbox.h"
#include "toolbar.h"  //toolbar header 
#include <DAQmxIOctrl.h>
#include <NIDAQmx.h> 
#include "nican.h"      // Include file for NI-CAN functions and constants       

//#define	USESFRMODULE
#ifdef USESFRMODULE 
	#include "FR_COMM.h"
#endif
/********************************************************************************/
/* Global Defines                                                               */
/********************************************************************************/
#define TAB_PAGE_ONE			0
#define TAB_PAGE_TWO 			1
#define TAB_PAGE_THREE 			2  
#define TAB_PAGE_FOUR 			3  
#define TAB_PAGE_FIVE 			4  
#define TAB_PAGE_SIX 			5  
#define TAB_PAGE_SEVEN 			6
//*******************************************************************************************************************
#define USE_LABEL_DATA			1
#define 	DATA_SIZE           5000000  // Data storage allowed before archive 
//*******************************************************************************************************************
#define			DIO_ROW_INDEX_CONSTANT			24
#define			DIO_DYN_RADIO_INT1_CONST		24
#define			TOTAL_IO_ROWS					96
#define			TOTAL_INPUT_LINE				24
#define			TOTAL_DIO_OUTPUT_LINE			24
#define			TOTAL_OUTPUT_LINE_DIO			24
#define			TOTAL_OUTPUT_LINE				100 

#define			TOTAL_NUMBER_OF_PORTS			6
#define			TOTAL_NUMBER_OF_INPUT_PORTS		3
#define			TOTAL_NUMBER_OF_OUTPUT_PORTS	3
#define			TOTAL_NUMBER_OF_PORTS_6518			4
#define			TOTAL_NUMBER_OF_PORTS_6514			8 
#define			TOTAL_NUMBER_OF_PORTS_6515			8
#define			TOTAL_NUMBER_OF_INPUT_PORTS_6518	2
#define			TOTAL_NUMBER_OF_OUTPUT_PORTS_6518	4
#define			TOTAL_NUMBER_OF_INPUT_PORTS_6514	4
#define			TOTAL_NUMBER_OF_OUTPUT_PORTS_6514	4
#define			TOTAL_NUMBER_OF_INPUT_PORTS_6515	4
#define			TOTAL_NUMBER_OF_OUTPUT_PORTS_6515	4

#define			TOTAL_NUMBER_OF_PORTS_6509			12
#define			TOTAL_NUMBER_OF_INPUT_PORTS_6509	6
#define			TOTAL_NUMBER_OF_OUTPUT_PORTS_6509	6

#define			TOTAL_SW_ROWS						100
#define			TOTAL_NUMBER_OF_INPUT_PORTS_6220	2
#define			TOTAL_NUMBER_OF_PORTS_6220			3
#define			TOTAL_NUMBER_OF_OUTPUT_PORTS_6220	1
#define			TOTAL_INPUT_LINE_6220				16
#define			TOTAL_OUTPUT_LINE_6220				8 
#define			TOTAL_INPUT_LINE_6514				32
#define			TOTAL_OUTPUT_LINE_6514				32

#define			TOTAL_NUMBER_DEVICE					1
#define			TOTAL_NUMBER_DEVICE_6514			1
#define			TOTAL_NUMBER_DEVICE_6515			1  
#define			TOTAL_NUMBER_DEVICE_6518			1
#define			TOTAL_NUMBER_DEVICE_6509			1
#define			TOTAL_INPUT_LINE_6509				48
#define			TOTAL_OUTPUT_LINE_6509				48    
#define			TOTAL_INPUT_LINE_6514				32
#define			TOTAL_OUTPUT_LINE_6514				32    

#define			TOTAL_NUMBER_DEVICE			1
#define			BIT_7						0x80
#define			BIT_6						0x40
#define			BIT_5						0x20
#define			BIT_4						0x10
#define			BIT_3						0x08
#define			BIT_2						0x04
#define			BIT_1						0x02
#define			BIT_0						0x01

#define			TOT_DIO_LINE1				96
#define			MAX_CHAR_LEN1				50
#define			TOTAL_FLASHRUNNER			8

#define			testARRAY_SIZE 				150
#define 		BUFFER_SIZE 				256
#define			canARRAY_SIZE 				100
#define			ctARRAY_SIZE 				100


// PCI-6528 interface card device number
#define 		DIO_1       				1 
// PCI-6528 interface card device number
#define 		DIO_2       				2 
// PCI-6528 interface card device number
#define 		DIO_3       				3 
// PCI-6528 interface card device number
#define 		DIO_4       				4 	 
#define 		DIO_5       				5
#define 		PORT_SIZE					8
// PCI-6528 INTERFACE CARD OUTPUT PORT BASE
#define			DIO_OUTPUT_PORT_BASE		3
#define			DIO_OUTPUT_PORT_BASE_6509	6
#define			DIO_OUTPUT_PORT_BASE_6514	4
#define			DIO_OUTPUT_PORT_BASE_6515	4 

#define			MIO_OUTPUT_PORT_BASE		2
// num of DIO lines: 24 per IO ctrl
#define 		NUM_DIO_LINE				24 	
#define 		NUM_DIO_LINE_6514			32
#define 		NUM_DIO_LINE_6515			32 

// num of DIO lines: 24 per IO ctrl
#define 		NUM_DIO_LINE_6509			48

#define 		DISABLE						-1
#define 		NOT_FOUND					-2
#define         MAXPROCESSCOUNT             5
#define         NUMOFTESTS                  150
#define         NUMOFNESTS                  6  
//*******************************************************************************************************************
typedef enum{GLB_FAIL, GLB_PASS}booleanResult; 
typedef enum{GLB_FALSE, GLB_TRUE}bool;
enum 			{CHANGE = 4, VERIFY, REENTER, CONFIG_MODE, MANUAL_MODE, VERIFY_SYSTEM, VER_MODE, DEVIATION_MODE}; 
//*******************************************************************************************************************
// Flash Testing Module Data
//*******************************************************************************************************************
#ifdef USESFRMODULE 
bool (*flashTestptr[50]) (int num, FR_COMM_HANDLE FRHandle);
#endif
///int (*funcptr5[100]) (int);

//int (*funcptr10[10][100]) (int, int);
bool (*funcptr10[10][100]) (int, int);

int funcptrid, funcptrstatus; 

void (*funcPtr) (char buf[], double dval, int *ival);
int module_id;
//int status;
char buffuncptr[100];
//double dval;
//int ival;
char *pathname;
char *funcname;
char ProductType[20];


typedef int (*AddFunc)(int,int);
typedef void (*FunctionFunc)();


/********************************************************************************/
/* Global Variables                                                             */
/********************************************************************************/
int 			MainPanelHandle;
int				MAIN_menuHandle;
ToolbarType  	ToolbarHandle;  
int 			SystemPanelHandle;
int 			TestCfgPanelHandle;
int 			PasswordPanelHandle;
int				DIOPanelHandle;
int				MIOPanelHandle;
int				MIOPanelHandle2;
int				MIOUtilsPanelHandle;
int				MIOUtilsPanelHandle2;
int 			SysViewMenu;
int 			DIOViewMenu;
int				SWViewMenu;
int				CANViewMenu;
int				CTViewMenu;
int				RecipePanelHandle;
int				PartSelectPanelHandle;
int 			recipeRowIndex; 
int				recipeColumnIndex;
int 			ShiftPanelHandle;
int 			ExtRecipePanelHandle;
int 			DIOUtilsPanelHandle;
int				Password_PASS;
int				Password_CANCLE;
int 			FRUtilsPanelHandle;
int 			TestResultPanelHandle;
int 			CapabilityPanelHandle;
int				ErrorPanelHandle;
int 			FRBFileTransferPanelHandle;
int 			InitPanelHandle;
int 			GPIBPanelHandle;
int				EditPasswordPanelHandle;
int				SWPanelHandle;
int				CANPanelHandle;
int				CTPanelHandle;
int 			CTUtilsPanelHandle;
int				SWUtilsPanelHandle;
int				DIO6509ConfigPanelHandle;
int				DIO6509UtilsPanelHandle;
int				DIO6514ConfigPanelHandle;
int				DIO6514UtilsPanelHandle;
int				DIO6515ConfigPanelHandle;
int				DIO6515UtilsPanelHandle;
int				MIOPanelHandle;
int				MIOUtilsPanelHandle;
int				FRCUBEPanelHandle;
int				CANTxRxPanelHandle;
int				SPConfigPanelHandle;
int				SPUtilsPanelHandle; 
int				totalNest;
int             NumOfTests;
unsigned long	currentFilePosition;
char			ConfiurationPathName[300];

char 			SysCfg_Int_UIR[MAX_PATHNAME_LEN];
char 			SysCfg_Ext_UIR[MAX_PATHNAME_LEN];

char 			PASSWORD_INT_UIR[MAX_PATHNAME_LEN];
char 			PASSWORD_EXT_UIR[MAX_PATHNAME_LEN];

int  			PWD_KeyPress_Loc, pwd_status, passwordPanel, pwd_location;
char 			test_pwd[15], prod_pwd[15], password[15], new_pwd[15], temp_pwd[15],
				access_level1[15], access_level2[15];
char 			proj_dir[MAX_PATHNAME_LEN];
long 			file_size;
int				RS232Error;
char			ErrorCodeMessage[1000];
char 			FRerror_string[1000];
char			FRstrErrorCode[500];
char			parsedFRMsg[1000];
char			mparsedFRMsg[100][5000]; 
char			FRrecievedStrBuffer[1000][500];
#ifdef USESFRMODULE 
	FR_COMM_HANDLE 	FRcomHandle;
#endif
int				binaryFilePanelHandle, binaryFilePanelControlConstantNumber;
bool 			binarryConversionInProgress;
double			binaryTransferTime;
char			testTimeStamp[100];



struct  SRecipeInfo
	{
    	char TESTERNAME[100];
    	char SequenceFileName[100];
    	char Field[100][100];
    	char DBFileName[100]; 
		char RemotrDBPath[100];
    	char LocalDBPath[100];
    	char UpdateRecipe[100];
    	char CopyFlashFilefromRecipe[100];
    	char LocalTestFileLocation[100];
    	char RemotTestFileLocation [100];
    	char RecipeLocalTesterFileLocation[100];
	}	RecipeInformation;

struct SFlashRunners
	{
    	char COMNUMBER[100];
    	char BAUDERATE[100];
    	char SerialNumber[100];
		#ifdef USESFRMODULE 
			FR_COMM_HANDLE FRHandle;
	    #endif
	}	FlashRunnerInfo[8], temp_FlashRunnerInfo[8]; 



struct SScanner
	{
    	char COMMNUMBER[100];
    	char portSettings[100];
	}	Scanner[5], temp_Scanner[5];

struct SSerialCommunication
	{
    	char COMMNUMBER[10];
    	char DeviceName[10];
		char BaudRate[10];
		char Parity[10];
		char DataBits[10];
		char StopBits[10];
		char StartBits[10];
		char InputQ[10];
		char OutputQ[10];
		int  portOpenStatus;
		int  SerialPortErrorCode;
	}	SerialComm[8], temp_SerialComm[8];

struct SMiscellaneous
{
	char SequenceFileName[100];
	char TesterName[100];
	char DBFileName[100]; 
	char RemoteDBPathName[100];  
	char LocaDBPathName[100]; 
	char UpdateRecipe[100];
	char CopyFlashFilefromRecipe[100];
	char LocalTestFileLocation[100];
	char RemotTestFileLocation[100];
	char RecipeLocalTesterFileLocation[100];
	char MFDataStartMemoryLocation[100];
	char NumberofNests[100];
	char PWTimeout[100];
	char ITACSystemID[100];
	char ITACStationID[100]; 
	char ITACEnable[100];
	char CalInitDacHonda[100];
	char TableRow[100];
	char TableColumn[100];
}	Miscellaneous, tempMiscellaneous;

char gTesStepParamName[25][100];

typedef struct
{ 
	char		testNum[BUFFER_SIZE];
	char   		testName[BUFFER_SIZE];
	char   		testFuncName[BUFFER_SIZE];	
	char   		testSkip[BUFFER_SIZE];
	char   		testType[BUFFER_SIZE]; 
	char   		testAbort[BUFFER_SIZE];  	
	char   		testParam[BUFFER_SIZE];
	char   		testRepeat[BUFFER_SIZE];
	char 		testResult[BUFFER_SIZE];
	char 		testNest[BUFFER_SIZE];
	char 		testResultVal[BUFFER_SIZE];

  }TestStepInfoStruct;	
TestStepInfoStruct gTestStepInfo[testARRAY_SIZE], temp_gTestStepInfo[testARRAY_SIZE], mtgTestStepInfo[10][testARRAY_SIZE];		

struct gTestStepInfoParam			
{ 
	char		Param0[BUFFER_SIZE];
	char   		Param1[BUFFER_SIZE];
	char   		Param2[BUFFER_SIZE];	
	char   		Param3[BUFFER_SIZE];
	char   		Param4[BUFFER_SIZE];
	char 		Param5[BUFFER_SIZE];
	char 		Param6[BUFFER_SIZE];
	char   		Param7[BUFFER_SIZE];
	char   		Param8[BUFFER_SIZE];
	char   		Param9[BUFFER_SIZE];
	char   		Param10[BUFFER_SIZE];
	char   		Param11[BUFFER_SIZE];
	char   		Param12[BUFFER_SIZE];
	char   		Param13[BUFFER_SIZE];
	char   		Param14[BUFFER_SIZE];
	char		Param15[BUFFER_SIZE];
	char		Param16[BUFFER_SIZE];
	char 		Param17[BUFFER_SIZE];
	char 		Param18[BUFFER_SIZE];
	char 		Param19[BUFFER_SIZE];
	char 		Param20[BUFFER_SIZE];
	char 		Param21[BUFFER_SIZE];
	char		Param22[BUFFER_SIZE];
	char 		Param23[BUFFER_SIZE];
	char		Param24[BUFFER_SIZE];
	char 		Param25[BUFFER_SIZE];

  }	gTestStepInfoParam[testARRAY_SIZE], temp_gTestStepInfoParam[testARRAY_SIZE];	

struct gMiscInfo			
	{ 
		char		SystemName[BUFFER_SIZE];
		char   		SystemValue[BUFFER_SIZE];
	}	gMiscInfo[testARRAY_SIZE], temp_gMiscInfo[testARRAY_SIZE];
															  
struct  CANInfo			
		{ 
			char 				CANNum[100];
			/* NI-CAN Status    */
			NCTYPE_STATUS 		Status; ///NCTYPE_STATUS type Long 
			/* NI-CAN handles */
			NCTYPE_OBJH 		TXRXHandle;  /// NCTYPE_OBJH type Unsigned Long
			NCTYPE_CAN_FRAME 	Transmit;  ///type Structure Unsigned Long
			/* NI-CAN Frame Type for Network Interface Write */ 
			char				TxArbitrationId[10];///NCTYPE_CAN_FRAME 	Transmit;  type Structure Unsigned Long
			char				IsRemote[10];///NCTYPE_CAN_FRAME 	Transmit;  type Structure   Unsigned Char
			char				DataLength[10];///NCTYPE_CAN_FRAME 	Transmit;  type Structure   Unsigned Char
			char				Data[10];	   ///NCTYPE_CAN_FRAME 	Transmit;  type Structure   Unsigned Char
			/* CAN interface for input.  
			   Interface names are assigned to NI CAN hardware ports using MAX.
			   The default is CAN0, but you can change this on the panel. */
			char 				CANName[100];
			char				Baudrate[100];	   ///NCTYPE_UINT32 type Unsigned Long
			char 				S2Comparator[100];	   /// type int
			char 				S2Mask[100];			   /// type int 
			char 				S2FilterMode[100];	   /// type int
			char				RxMsg[100];
			char				securityUnlockError[100];
		}	gCANInfo[10][canARRAY_SIZE], temp_gCANInfo[10][canARRAY_SIZE];															  

struct canMessagesData
{
	char testName[100];
	int TxID;
	int RxID; 
	int maskfilter;
	int sizeData;
	char sendMSG[100];
	int inExpect; 
	int location;
	char receiveMSG[100];
	char expectedMSG[100];
	char status[100];
						
}gCanMsg[6][100],gCanSer[6][100];

NCTYPE_OBJH			TXRXHandle;
/***
char temp_SequenceFileName[100];             
char temp_TesterName[100];                   
char temp_DBFileName[100];                   
char temp_RemoteDBPathName[100]; 		    
char temp_LocaDBPathName[100];               
char temp_UpdateRecipe[100];                 
char temp_CopyFlashFilefromRecipe[100];      
char temp_LocalTestFileLocation[100];        
char temp_RemotTestFileLocation[100];        
char temp_RecipeLocalTesterFileLocation[100];
char temp_MFDataStartMemoryLocation[100];    
char temp_NumberofNests[100]; 
***/
struct SRecipeFields
	{
		char Recipe_Number[100]; 
		char Recipe_TestSequence[100]; 
		char Recipe_TesterFile0[100];
		char Recipe_TesterFile1[100];
		char Recipe_TesterFile2[100];
		char Recipe_TesterFile3[100];
		char Recipe_TesterFile4[100];
		char Recipe_TesterFile5[100];
		char Recipe_PartNumber[100]; 
		char Recipe_BoardID[100]; 
	}RecipeFields, temp_RecipeFields;

struct SPassword
	{
		char Level1[100]; 
		char Level2[100]; 
	}Password;

int hdbc;       /// Handle to database connection  
int hmap;       /// Handle to map definition       
int hstmt;      /// Handle to SQL statement         
char recipeConnectString[500];
int totalRecipeRecords;

struct SRecipeRecords
	{
	    char recipeNumber[100];    
	    int  recipeNumberStat;        
	    char testSequence[100];    
	    int  testSequenceStat;        
	    char testerFile0[100];    
	    int  testerFile0Stat;        
	    char testerFile1[100];    
	    int  testerFile1Stat;        
	    char testerFile2[100];    
	    int  testerFile2Stat;        
	    char testerFile3[100];    
	    int  testerFile3Stat;        
	    char testerFile4[100];    
	    int  testerFile4Stat;        
	    char testerFile5[100];    
	    int  testerFile5Stat;        
	    char partNumber[100];    
	    int  partNumberStat;        
	    char boardID[100];    
	    int  boardIDStat;        
	}RecipeRecordsInfo[1000], RecipeRecordInfo;

    char TablerecipeNumber[100];    
    char TabletestSequence[100];    
    char TabletesterFile0[100];    
    char TabletesterFile1[100];    
    char TabletesterFile2[100];    
    char TabletesterFile3[100];    
    char TabletesterFile4[100];    
    char TabletesterFile5[100];    
    char TablepartNumber[100];    
    char TableboardID[100];    

struct	DIOConfiguration
	 {
		int32		error;
		TaskHandle  taskHandle[8];
		int			Device;
		int			Port;
		int			Line;
		char		LineName[192][100];
		int			PortDirection[8];
	 };	

struct SDIO
	 	{
	    	TaskHandle  taskHandle; 
			char 		DIOChannelIndex[100];
	    	char 		DIOName[100];
	    	char 		DIOChannelName[100];
	    	char 		DIOConfiguration[100];  ///PortDirection
	    	char 		DIOPort[100];
	    	char 		DIOBit[100];		  //Bit
	    	char 		DIOTestStatus[100]; //Enable/Disable
	    	char 		DIOTimeout[100];
	    	char 		DIORepeat[100];
	    	char 		DIOWireTag[100];
			int	 		error;
			int	 		Device;
	 	}	DIOInfo[10][TOTAL_IO_ROWS], temp_DIOInfo[10][TOTAL_IO_ROWS]; 

struct SSW
	 	{
	    	TaskHandle  taskHandle; 
			char 		SWChannelIndex[100];
	    	char 		SWName[100];
	    	char 		SWChannelName[100];
	    	char 		SWTopology[100];  ///Topology
	    	char 		SWTestStatus[100]; //Enable/Disable
	    	char 		SWTimeout[100];
			int	 		error;
			int	 		Device;
	 	}	SWInfo[10][TOTAL_SW_ROWS], temp_SWInfo[10][TOTAL_SW_ROWS]; 

struct SMAI
	 	{
	    	TaskHandle  taskHandle; 
			char 		AIChannelIndex[100];
	    	char 		AIName[100];
	    	char 		AIChannelName[100];
	    	char 		AIInputConfiguration[100];  ///PortDirection
	    	char 		AIMinValue[100];
	    	char 		AIMaxValue[100];		  //Bit
	    	char 		AISampleMode[100]; //Enable/Disable
	    	char 		AITimeout[100];
	    	char 		AISamplingRate[100];
	    	char 		AISamplePerChannel[100];
			int	 		error;
			int	 		Device;
	 	}	MAIInfo[10][TOTAL_IO_ROWS], temp_MAIInfo[10][TOTAL_IO_ROWS]; 

struct SMAO
	 	{
	    	TaskHandle  taskHandle; 
			char 		AOChannelIndex[100];
	    	char 		AOName[100];
	    	char 		AOChannelName[100];
	    	char 		AOInputConfiguration[100];  ///PortDirection
	    	char 		AOMinValue[100];
	    	char 		AOMaxValue[100];		  //Bit
	    	char 		AOSampleMode[100]; //Enable/Disable
	    	char 		AOTimeout[100];
	    	char 		AOSamplingRate[100];
	    	char 		AOSamplePerChannel[100];
			int	 		error;
			int	 		Device;
	 	}	MAOInfo[10][TOTAL_IO_ROWS], temp_MAOInfo[10][TOTAL_IO_ROWS]; 
struct  CTInfo			
		{ 
			char 				CTNum[100];
			char 				CTName[100]; 
			char 				CTChanel[100];  
			char				CTMax[10];
			char				CTMin[10];
			char				CTEdge[10];
			char				CTDivisor[10];	   
			char 				CTSampleToRead[100];
	    	TaskHandle  		taskHandle;
			int					Device;
		}	gCTInfo[10][ctARRAY_SIZE], temp_gCTInfo[10][ctARRAY_SIZE];															  

struct  SelectedRecipe
		{
			char selectedNumber[100];
			char selectedName[100];
			char selectedFile0[100];
			char selectedFile1[100];
			char selectedBoardID[100];
			char selectedPartNumber[100];
		}recipeInformation;

#define MAX_THRDS 					 4

struct	TransferBinaryFile
	   	{
			char fileName[100];
			#ifdef USESFRMODULE 
				FR_COMM_HANDLE FRcomHandle;
				FR_COMM_ERR transferSucces;
			#endif
			int	result;
	  	}TransferedBinaryFileInfo[4];

struct SManufacturingData
{
    char Month[100];
    char Year[100];
    char Flavor_BoardID[100];
    char ModuleImageID[100];
    char SerialNumber[100];
    char FlavorID[100];
    char Filler1[100];
    char Filler2[100];
    char Filler3[100];
    char MFData[6][1000];
	char tempMFData[6][1000];
} ManufacturingData ;

typedef struct 
{
	int top; 
	int left; 
	int width; 
	int height;	
} gCtrlSize;


struct SCanResponseData
{
    char HpApp[100];
	char HpBoot[100];
	char DspApp[100];
	char DspBoot[100];
} CanResponseData[6];

//==============================================================================
// Constants

//==============================================================================
// Types
typedef struct 
{
	char name[50];					// COM1, COM2
	int com_port;					// 0,1,2 
	int baudrate;					// 300, 600, 1200, 2400, 4800, 9600, 
	int parity;						// 0=none, 1=odd, 2=even, 3=mark, 4=space
	int databits;					// 0 to 8 
	int stopbits;					// 1 or 2
	int input_queue_size;			// input queue size 512
	int output_queue_size;      	// output queue size 512  
} RS232_t;

//==============================================================================
// External variables

//==============================================================================
// Global functions
int OpenRS232(void);
int CloseRS232(void);
int ConfigRS232(RS232_t device);
int SendDataFile(const char *pFilename);
int SendData(char * send_data);
int SendByte(int byte);
int ReadBytes(char *read_data, int read_cnt, int termination_byte);
int ReadData(char *read_data, size_t bytes);
int FlushBufferIn(void);
int FlushBufferOut(void);
int GetInputQueueByte(void);
int GetOutputQueueByte(void);
//int GetComPortStatus(void);
void remove_char(char c, char *str);
int GetPrinterStatusDescription(int com, char * statusMsg );
int GetPrinterExtendedStatusDescription(void);
void ConfigDevice(void);
void DisplayPrinterExtendedStatus(char *status);
int SendDataFileWithStatusQuery(const char *pFilename);


typedef struct 
{
	char online[10];
	char error[256];
	char state[256];
} PrinterStatus;
PrinterStatus prtStatus;


typedef struct 
{
	int pause;
	int hasJob;
	int printerNotReady;
	int paperIsMoving;
	int ribbonPreWarning;
	int paperPreWarning;
	int labelInDemandPos;
	int labelOnVacPlate;
	int applicatorNotReady;
	int extPauseSignalActive;
	int extPrintSignalActive;
} PrinterExtendedStatus;

char testTimeStamp[100];
bool testPassed;

#define     HEX_DEC(a,b) 		16*a+b
int new_file;
int totalTestResult[10];
bool testInProgress;
char barcodeScanned[10000];
int  SystemFileHandler;
char FlashProgrammingFileName[100];
char SystemFileName[100]; 
char displaySerialNumber[100];
char daughterBoard[100];
int  intTestPassed, intTestFailed, intTested;
double failedPercentage;
bool testingWell1, testingWell2;
int  readESTOPReturnVal;
char ScriptReturnVal[5000];
long nscriptReturnVal;
#ifdef USESFRMODULE
	FR_ANSWER_TYPE frcubeResponseType;
#endif
char gparsedFRMsg[1000];
char gerrorFRMsg[1000];
// capability mode global variable declaration
int  capability_time_interval, unlimited_capability_test, num_capability_cycle;
bool stop_capability;

int	Capability_Time_Interva, Capability_Cycle_Number, Capability_Test, FirstTimeCapMode,
	Start_Capability_Test, Unlimited_Cap_Test, UpdateCapCounterLabel, Capability_Count,
	DisplayCapabilityControls,Temp_Capability_CycleNumber;	
bool stop_capability;
int capCounter;
char val_filename[MAX_PATHNAME_LEN]; 
int  test_mode;            		// pointer offset for the selected mode
enum modes {FINAL, PRETEST, RETEST, CAPABILITY};
int				Flag_Password_Protect, PasswordTimerExpired; 
bool PasswordProtectedMenu;
int PasswordTimeInterval;
unsigned int capabilitySerialNumber;

bool frResult[6]; //assign status from binary transfert to FR
int estopFlag;
int FxtFlag;

char stationID[100]; //ITAC
char systemID[100];  //ITAC
//long sessionID;  //ITAC  
long itacResult[6]; //ITAC  
//long ProcessCount;
//long itacUploadResult[6]; //ITAC   
int ITAC_REJECT; //ITAC  
int ITACSTATE; //ITAC  
//long itacPanelState[6];
static bool LID1ClosedTestInprogress = GLB_FALSE,  LID2ClosedTestInprogress = GLB_FALSE, flagLIDOpen = GLB_FALSE;
int Thread1_LockHandle, Thread2_LockHandle, Thread3_LockHandle, Thread4_LockHandle,Thread5_LockHandle,Thread6_LockHandle;
int Thread_6528_LockHandle, Thread_6220_LockHandle, Thread_Prog_LockHandle,InitCalLock,AirPressurePanelHandle,VacSensor_LockHandle;
int SW2569DeviceNum1, DIO6528DeviceNum1, DIO6528DeviceNum2, MIO6220DeviceNum1, MIO6220DeviceNum2, 
	DIO6509DeviceNum1, CT6602DeviceNum1,CANDeviceNum, DIO6514DeviceNum1, DIO6514DeviceNum2,DIO6515DeviceNum1, DIO6515DeviceNum2,
	MIO6220DeviceNum1, scannerSerialPort, printerSerialPort;
static bool UnitTestInprogress = GLB_FALSE;
short rRead[100];
double aRead[100];
double aReadTime[100];
bool frCUBESystemError;   
int totalResult[6]; 
char logMFData[6][100];      
char CANstr[1000];
char fidhexString[16];
char linehexString[15]; 
char serialhexString[15];
time_t StartTimeBirth;
int itacStatusLed;
int rejectBinLed;
int AirPressureFlag;


//*******************************************************************************************************************
// MAIN Interface
//*******************************************************************************************************************
#define			MAIN_ROW_INDEX_CONSTANT			4
#define			APP_MAIN_NAME					"frmMain.c"
#define			MAIN_CONFIG_FILE				"212240_MAIN_CONFIG_File"
#define			MAIN_CONFIG_FILE_EXT			"212240_MAIN_CONFIG_File.txt"
#define			MAIN_CONFIG_FILE_CSV			"212240_MAIN_CONFIG_File.csv"
#define			MAIN_CONFIG_UIR					"212214_Main_CONFIG.uir"
#define			MAIN_UIR						"\\212240_MAIN.uir"
//*******************************************************************************************************************
int				MAIN_DECO_CONTROL1, MAIN_DECO_CONTROL2, MAIN_DECO_CONTROL3;
int				Decoration_1_Left, Decoration_1_Top, Decoration_1_Width, Decoration_1_Height,
				Decoration_2_Left, Decoration_2_Top, Decoration_2_Width, Decoration_2_Height,
				Decoration_3_Left, Decoration_3_Top, Decoration_3_Width, Decoration_3_Height; 				
int				MAIN_DYN_NUMERIC1[10], MAIN_DYN_NUMERIC2[10];
int 			MAIN_NUMERICTextTitle1[10], MAIN_NUMERICTextTitle2[10];
char			MAIN_NUMERIC1_LABEL_TITLE[10][100], MAIN_NUMERIC2_LABEL_TITLE[10][100];
int				MAIN_TEST_PASS, MAIN_TEST_PASS1, MAIN_TEST_PASS2, MAIN_TEST, MAIN_TEST1, MAIN_TEST2, MAIN_TEST_FAIL, MAIN_TEST_YIELD,
				MAIN_TEST_FAIL1, MAIN_TEST_FAIL2, MAIN_PERCENT_FAILED, MAIN_PERCENT_FAILED1, MAIN_PERCENT_FAILED2,
				MAIN_TEST_TIME, MAIN_IDLE_TIME, MAIN_BIN_COUNT, MAIN_BIN_FAILURE,HISTO_CLEAR_DATE,
				MAIN_LIST_BOX_CONTROL1, MAIN_LIST_BOX_CONTROL2, MAIN_LIST_BOX_CONTROL3, MAIN_LIST_BOX_CONTROL4, 
				MAIN_LIST_BOX_CONTROL5, MAIN_LIST_BOX_CONTROL6, DIO6514_LIST_BOX_CONTROL1;
//*******************************************************************************************************************				
int				MAIN_BUTTON_RESET_STAT, MAIN_BUTTON_RUN_VERIF, MAIN_BUTTON_SHOW_SPC, MAIN_BUTTON_RESET_BIN,
				MAIN_BUTTON_PART_SELECT, MAIN_BUTTON_VIEW_OPTION, MAIN_BUTTON_STOP_CAPABILITY_TEST, 
				MAIN_CAPABILITY_COUNTER;
//*******************************************************************************************************************
int				DYN_TABLE_MAIN;
int             gStepList[NUMOFNESTS], gBoxMsg[NUMOFNESTS], gBoxDeco[NUMOFNESTS],gBoxId[NUMOFNESTS], gBoxTxt[NUMOFNESTS], gReportList[NUMOFNESTS], 
	            gReportLabel[NUMOFNESTS], gStepLabel[NUMOFNESTS], gPresenceLed[NUMOFNESTS], gPositionLed[NUMOFNESTS], gTestTime[NUMOFNESTS], gItacCount[NUMOFNESTS],gCycleCount[NUMOFNESTS];
int             gLongTermPass[NUMOFNESTS],gLongTermFail[NUMOFNESTS],gLongTermYield[NUMOFNESTS];
int             gShortTermPass[NUMOFNESTS],gShortTermFail[NUMOFNESTS],gShortTermYield[NUMOFNESTS];
int             HISTO_CLEAR_DATE, HISTO_TEST_YIELD, HISTO_TEST_PASS, HISTO_TEST_FAIL;

/********************************************************************************/
/* Global Functions Declaration                                                 */
/********************************************************************************/
CVIXMLElement __stdcall LoadConfigurationDocument(char FileName[]);
int __stdcall  ParseDocument(CVIXMLElement currElem);
void __stdcall ParseTestStep(char ParentName[], char ElementName[], char ElementValue[],  int indexElement, int indexChild);
void  __stdcall ParsegTestStep(char ParentName[], char ElementName[], char ElementValue[],  int indexElement, int indexChild);
void  __stdcall UniversalParsegTestStep(char ParentName[], char ElementName[], char ElementValue[],  int indexElement, int indexChild);
void __stdcall ParseFlashRunners(char ParentName[], char ElementName[], char ElementValue[],  int indexElement, int indexChild);
void __stdcall ParseSequenceFileName(char ParentName[], char ElementName[], char ElementValue[],  int indexElement, int indexChild);
void __stdcall ParseTesterName(char ParentName[], char ElementName[], char ElementValue[],  int indexElement, int indexChild);
void __stdcall ParseDBFileName(char ParentName[], char ElementName[], char ElementValue[],  int indexElement, int indexChild);       
void __stdcall ParseRemoteDBPathName(char ParentName[], char ElementName[], char ElementValue[],  int indexElement, int indexChild); 
void __stdcall ParseLocaDBPathName(char ParentName[], char ElementName[], char ElementValue[],  int indexElement, int indexChild);
void __stdcall ParseUpdateRecipe(char ParentName[], char ElementName[], char ElementValue[],  int indexElement, int indexChild);
void __stdcall ParseCopyFlashFilefromRecipe(char ParentName[], char ElementName[], char ElementValue[],  int indexElement, int indexChild);
void __stdcall ParseLocalTestFileLocation(char ParentName[], char ElementName[], char ElementValue[],  int indexElement, int indexChild);
void __stdcall ParseRemotTestFileLocation(char ParentName[], char ElementName[], char ElementValue[],  int indexElement, int indexChild);
void __stdcall ParseRecipeLocalTesterFileLocation(char ParentName[], char ElementName[], char ElementValue[],  int indexElement, int indexChild);
void __stdcall ParseMFDataStartMemoryLocation(char ParentName[], char ElementName[], char ElementValue[],  int indexElement, int indexChild);
void __stdcall ParseNumberofNests(char ParentName[], char ElementName[], char ElementValue[],  int indexElement, int indexChild);
void __stdcall ParseScanner(char ParentName[], char ElementName[], char ElementValue[],  int indexElement, int indexChild);
void __stdcall ParseRecipeFields(char ParentName[], char ElementName[], char ElementValue[],  int indexElement, int indexChild);
void  __stdcall ParseMiscellaneous(char ParentName[], char ElementName[], char ElementValue[], int indexElement, int indexChild);
int __stdcall  ParseXMLDocument(CVIXMLElement currElem, int Device);   //Parse TEst Steps, FlashRunners, Scan and Recipe Fields
int __stdcall  ParseSingleElementDocument(CVIXMLElement currElem);
int __stdcall  DisplaySysCfgMiscellaneous(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTREE);
int __stdcall  DisplaySysCfgSerialPortTable(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTABLE);
int __stdcall  DisplaySysCfgFlashRunnerTable(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTABLE);
int __stdcall  GetSysCfgSerialPortTable(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTABLE);
int __stdcall  GetSysCfgFlashRunnerTable(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTABLE);
int __stdcall  SaveSysCfgSerialPortTableValue(int numRows);
int __stdcall  SaveSysCfgFlashRunnerTableValue(int numRows);
int __stdcall  WriteSysCfgSeriaPortValue(int numRows, char FilePath[]);
int __stdcall  WriteSysCfgFlashRunnerValue(int numRows, char FilePath[]);
int __stdcall  DisplaySysCfgMiscellaneousTable(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTABLE);

int  __stdcall DisplaygMisc(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTREE, int totalMiscNumber);
int  __stdcall DisplaySysCfgMiscTable(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTABLE);
void  __stdcall ParsegMisc(char ParentName[], char ElementName[], char ElementValue[],  int indexElement, int indexChild);
int  __stdcall GetSysCfgMiscTable(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTABLE);
int  __stdcall SaveSysCfgMiscTableValue(int numRows);
int  __stdcall WriteSysCfgMiscTableValue(int numRows, char FilePath[]);
int  __stdcall WriteSysCfgMiscTableValue(int numRows, char FilePath[]);
int  __stdcall GetSysCfgMiscTable(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTABLE);
char*  __stdcall GetCfgMiscValue(char miscName[], int totalRowIndex);

int __stdcall  GetSysCfgMiscellaneousTable(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTABLE);
int __stdcall  SaveSysCfgMiscellaneousTableValue(int numRows);
int __stdcall  WriteSysCfgMiscellaneousValue(int numRows, char FilePath[]); 
int __stdcall  RemoveElement(CVIXMLElement curElement, char elementTag[]);
int __stdcall  DisplaySysCfgRecipeTable(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTABLE);
int __stdcall  GetSysCfgRecipeTable(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTABLE);
int __stdcall  SaveSysCfgReciperTableValue(int numRows);
int __stdcall  WriteSysCfgRecipeValue(int numRows, char FilePath[]);
int  __stdcall DisplayDIOCfg(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTREE, int Device, int totalChannelNumber);
int  __stdcall DisplayMDIOCfg(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTREE, int Device, int totalChannelNumber);
int  __stdcall DisplayAICfg(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTREE, int Device, int totalChannelNumber);
int  __stdcall DisplayAOCfg(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTREE, int Device, int totalChannelNumber);
int  __stdcall DisplaySWCfg(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTREE, int Device, int totalChannelNumber);


int  __stdcall DisplayAICfg(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTREE, int Device, int totalChannelNumber);

int  __stdcall WriteAICfgTableValue(int numRows, char FilePath[], int Device);
int  __stdcall WriteAOCfgTableValue(int numRows, char FilePath[], int Device);

int  __stdcall SaveAICfgDIOTableValue(int numRows, int Device);
int  __stdcall SaveAOCfgDIOTableValue(int numRows, int Device);

int  __stdcall GetSysCfgAITable(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTABLE, int Device);
int  __stdcall GetSysCfgAOTable(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTABLE, int Device);
int  __stdcall DisplaySysCfgAITable(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTABLE, int Device);
int  __stdcall DisplaySysCfgAOTable(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTABLE, int Device);

int  __stdcall DisplayAICfg(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTREE, int Device, int totalChannelNumber);

int  __stdcall DisplaySysCfgDIOTable(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTABLE, int Device);
int  __stdcall GetSysCfgDIOTable(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTABLE, int Device); 
int  __stdcall SaveDIOCfgDIOTableValue(int numRows, int Device);
int  __stdcall WritedioCfgTableValue1(int numRows, char FilePath[], int Device);
int  __stdcall WriteDIOCfgTableValue(int numRows, char FilePath[], int Device);

int  __stdcall DisplaySysCfgSWTable(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTABLE, int Device);
int  __stdcall GetSysCfgSWTable(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTABLE, int Device);

int  __stdcall SaveSWCfgSWTableValue(int numRows, int Device);
int  __stdcall WriteSWCfgTableValue(int numRows, char FilePath[], int Device);

void  __stdcall ParseCAN(char ParentName[], char ElementName[], char ElementValue[],  int indexElement, int indexChild, int Device);
int  __stdcall DisplaySysCfgCANTable(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTABLE, int Device);
int  __stdcall DisplayCANCfg(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTREE, int Device, int totalChannelNumber);
int  __stdcall GetSysCfgCANTable(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTABLE, int Device);
int  __stdcall SaveCANCfgCANTableValue(int numRows, int Device);
int  __stdcall WriteCANCfgTableValue(int numRows, char FilePath[], int Device);

void  __stdcall ParseCT(char ParentName[], char ElementName[], char ElementValue[],  int indexElement, int indexChild, int Device);
int  __stdcall DisplaySysCfgCTTable(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTABLE, int Device);
int  __stdcall DisplayCTCfg(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTREE, int Device, int totalChannelNumber);
int  __stdcall GetSysCfgCTTable(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTABLE, int Device);
int  __stdcall SaveCTCfgCTTableValue(int numRows, int Device);
int  __stdcall WriteCTCfgTableValue(int numRows, char FilePath[], int Device);

void __stdcall GetSysConfigFileDirectory(void);
void __stdcall MakeProjectDirPath(	char ext_dir[MAX_PATHNAME_LEN],
									char int_dir[MAX_PATHNAME_LEN],
									char dir[MAX_PATHNAME_LEN]
					   			 );
void  __stdcall ParseSerialCommunication(char ParentName[], char ElementName[], char ElementValue[],  
	                         int indexElement, int indexChild);
int  __stdcall DisplaySysCfgSerialCommunication(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTREE);
int  __stdcall DisplaySysCfgSerialCommunicationTable(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTABLE);
int  __stdcall GetSysCfgSerialCommunicationTable(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTABLE);
int  __stdcall SaveSysCfgSerialCommunicationTableValue(int numRows);
int  __stdcall WriteSysCfgSerialCommunicationValue(int numRows, char FilePath[]); 

void  __stdcall ParseSerialPorts(char ParentName[], char ElementName[], char ElementValue[],  
	                         int indexElement, int indexChild);
int  __stdcall DisplaySysCfgSerialPorts(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTREE, int totalChannelNumber);
int  __stdcall DisplaySysCfgSerialPortsTable(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTABLE);
int  __stdcall GetSysCfgSerialPortsTable(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTABLE);
int  __stdcall SaveSysCfgSerialPortsTableValue(int numRows);
int  __stdcall WriteSysCfgSerialPortsValue(int numRows, char FilePath[]); 

int __stdcall CheckError(int err_num);

void __stdcall LoadSystemConfiguration(int SysCfgPNLConst);	
void  __stdcall LoadTestConfig(int TSTPNLConst);
void  __stdcall LoadGPIBInterface(int GPIPPNLConst);
void  __stdcall LoadPasswordPanel(int PasswordPNLConst);
void  __stdcall LoadEditPasswordPanel(int EditPasswordPNLConst);
void  __stdcall LoadDIOConfig(int DIOPNLConst);
void  __stdcall LoadMIOConfig(int MIOPNLConst);
void  __stdcall LoadMIOConfig2(int MIOPNLConst);
void  __stdcall LoadGPIBUtil(int GPIBPNLConst);
void  __stdcall LoadMIOUtils(int MIOPNLConst);
void  __stdcall LoadMIOUtils2(int MIOPNL2Const);
void  __stdcall ParseDIO(char ParentName[], char ElementName[], char ElementValue[],  int indexElement, int indexChild, int Device);
void  __stdcall ParseMAI(char ParentName[], char ElementName[], char ElementValue[],  int indexElement, int indexChild, int Device);
void  __stdcall ParseMAO(char ParentName[], char ElementName[], char ElementValue[],  int indexElement, int indexChild, int Device);
void  __stdcall ParseSW(char ParentName[], char ElementName[], char ElementValue[],  int indexElement, int indexChild, int Device);

void  __stdcall LoadRecipeConfig(int RECIPEPNLConst);
void  __stdcall LoadPartSelectModule(int PSPNLConst);
int  __stdcall DisplayRecipeTable(int panelHandle, int controlHandleTABLE);
void  __stdcall LoadFRUtills(int FRUTILPNLConst);
void  __stdcall LoadFRConfig(int FRCFGPNLConst);

void __stdcall DisableDIOControlSaving(void);
void __stdcall DisplayMAIControl(int firstTab);

void __stdcall GetSysConfigFileDirectory(void);
int  __stdcall DisplaySysCfgTestSteps(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTREE, int totalTestNumber); 
int __stdcall DisplayTestStep(int panelHandle, int controlHandle);
int  __stdcall DisplaySysCfgGTestSteps(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTREE, int totalTestNumber);
int  __stdcall UniversalDisplaySysCfgGTestSteps(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTREE, int totalTestNumber);
int  __stdcall DisplaySysCfgGTestStepsTable(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTABLE);
int  __stdcall UniversalDisplaySysCfgGTestStepsTable(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTABLE);
int __stdcall DisplaySysCfgScanner(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTREE);
int __stdcall DisplaySysCfgFlashRunner(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTREE, int totalChannelNumber);
int __stdcall DisplaySysCfgRecipe(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTREE);
int __stdcall DisplaySysCfgTestStepsTable(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTABLE);
int  __stdcall UniversalGetSysCfgTestgStepsTable(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTABLE);
int  __stdcall GetSysCfgTestgStepsTable(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTABLE);
int __stdcall GetSysCfgTestStepsTable(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTABLE);
int  __stdcall DisplaySysCfgGTestStepsTable(int panelHandle, int controlHandleTAB, int tabPage, int controlHandleTABLE);
int __stdcall SaveSysCfgTestStepsTableValue(int numRows);
int  __stdcall SaveSysCfgGTestStepsTableValue(int numRows);
int  __stdcall UniversalSaveSysCfgGTestStepsTableValue(int numRows);
int __stdcall WriteSysCfgTestStepsTableValue(int numRows, char FilePath[]);
int  __stdcall UniversalWriteSysCfgTestStepsTableValue(int numRows, char FilePath[], int NumofParam);

CVIXMLStatus __stdcall CVIXMLInsertElementComment(CVIXMLDocument document, 
        CVIXMLElement element, const char *comment, int insertBelow);
int  __stdcall VerifyPassword(int panelConstant, int infoControlConstant, int passwordEntryControlConstant,int status);

int __stdcall IsWriteFileOpened(char dir[MAX_PATHNAME_LEN], char *type, FILE *(*fp));
int __stdcall IsReadFileOpened(char dir[MAX_PATHNAME_LEN], char *type, FILE *(*fp));
int __stdcall CreateBackUpCopy(char dir[MAX_PATHNAME_LEN]);


void __stdcall DisableSystemControlSaving(void);
void __stdcall DisplaySystemControlSaving(int firstTab);



int __stdcall InitDIOInterface(int Device);
int __stdcall InitDIOInterface6518(int Device);
int __stdcall InitDIOInterface6509(int Device);    
int __stdcall InitDIOInterface6514(int Device);
int __stdcall InitDIOInterface6515(int Device); 

int __stdcall InitRecipeDB(char SQLString[]);
void __stdcall SetRecipeDBConnectString(char connectionString[]);
void ShowError(void);


int   __stdcall  OpenSerialCommunication(int PortNumber); 
int   __stdcall  LocatePortSetting(int PortNumber); 
void  __stdcall DisplayRS232Error (void);
int   __stdcall  SendSerialCOMData (int comPort, char sendData[], int sendTermIndex);
void  __stdcall ReceiveSerialCOMData (int comPort, char recData[], int RecTermIndex);
int   __stdcall  CloseCOMMPort (int comPort);


void  __stdcall InitSingleFlashRunner(char comPort[]);
void  __stdcall ParseErrorMessage(void);
void  __stdcall SendScriptFile(void);

void  __stdcall GetFile(char logFileName[]);
int   __stdcall CreatFile(char fileName[], char extension[], bool dateRequired, bool timeStampRequired);
char* __stdcall CreateTimeStampedFileName(char* FileName);
char* __stdcall GetCurrentTimeFunctionalTest(void);
char* __stdcall GetCurrentDate(void);
void  __stdcall CreatSCDIAGFile(char fileName[], char extension[]); 

void  __stdcall LoadShiftConfig(int SHIFTPNLConst);
void  __stdcall LoadExtRecipe(int EXTRecipePNLConst);
void  __stdcall LoadDIOUtils(int DIOUtilsPNLConst);
void  __stdcall InitializeFlashRunnerCommPort(void);
void  __stdcall ParsePassword(char ParentName[], char ElementName[], char ElementValue[], int indexElement, int indexChild);
void __stdcall FormatAIMultipleParameter(char AIChannelsInfo[], char delimiters[], char AIChannels_MultipleParam[100][100]);
void __stdcall FormatCANMultipleParameter(char gCANInfo[], char delimiters[], char gCANInfo_MultipleParam[100][100]);
void __stdcall FormatMultipleParameter(char Info[], char delimiters[], char MultipleParam[100][100]);
#ifdef USESFRMODULE
	bool  __stdcall CommSerialRx(int testNumber, FR_COMM_HANDLE serialComHandle);
#endif
void  __stdcall LoadTestResultInterface(int TRPNLConst);
void  __stdcall CloseFlashRunnerCommPort(void);
void  __stdcall LoadCapabilityInterface(int CAPPNLConst);
void RunCapabilityMode(void);
char*  SrecordtoBinaryConversion(char fileName[], int index);
void StartFRFileConversion(void);
void TransferFRBFiletoSDCard(void);
void TestInitialization(void);
void  __stdcall LoadErrorInterface(int ERRPNLConst);
short ReadInput(char* DIO_Discription);
short Read6509Input(char* DIO_Discription, int Device);
int   WriteOutput(char* DIO_Discription, int state);
int Write6509Output(char* DIO_Discription, int state, int Device);
void EStopErrorMessage(void);
void  __stdcall LoadFRBFTInterface(int FRBFTPNLConst);
void  __stdcall LoadINITInterface(int INITPNLConst);
void  __stdcall LoadSWConfig(int SWCfgPNLConst);
void  __stdcall LoadSWUtils(int SWUtilsPNLConst);
void  __stdcall LoadDIO6509Config(int DIO6509CfgPNLConst);
void  __stdcall LoadDIO6509Utils(int DIO6509UtilsPNLConst);
void  __stdcall LoadDIO6514Config(int DIO6514CfgPNLConst);

void  __stdcall LoadDIO6515Config(int DIO6515CfgPNLConst); 
void  __stdcall LoadDIO6514Utils(int DIO6514UtilsPNLConst);
void  __stdcall LoadSPConfig(int SPConfigPNLConst);
void  __stdcall LoadSPUtils(int SPUtilsPNLConst);
void  __stdcall LoadCANConfig(int CANCfgPNLConst);
void  __stdcall LoadCANUtil(int CANUtilPNLConst);
void  __stdcall LoadCTConfig(int CTCfgPNLConst);
void  __stdcall LoadCTUtils(int CTUtilsPNLConst);

void __stdcall LoadfromFile(char* FileName, int List_Box, int EditRing, int PanelHandle, int TAB, int TABHandle);
int  __stdcall WritePasswordValue(char newPassword[], char FilePath[]);
gCtrlSize __stdcall LibGetControlSize(int panelHandle, int control);
void __stdcall LibSetControlSize(int panelHandle, int control, int top, int left, int width, int height, int onTop, int flag);
void __stdcall FormatTestMultipleParameter(char testStepInfo[], char delimiters[], char test_MultipleParam[100][100]);
void __stdcall OpenFileNotePad(char notePadAppLocation[]);
char* __stdcall IO_Error(void);

void  BuildTestSequence(void);
