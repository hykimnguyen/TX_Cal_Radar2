// CVI wrapper header file for .NET assembly: NbLib, Version=0.0.0.0, Culture=neutral, PublicKeyToken=null
//
// This is specified by the '__assemblyName' constant in the generated source file.
// If there are multiple versions of this assembly, and you want .NET to determine 
// the appropriate one to load, then you can remove the version, culture, and public 
// key token information from the constant and just specify the name of the assembly.
//
// Other assemblies referenced by the target assembly:
// Name: mscorlib, Location: C:\Windows\Microsoft.NET\Framework\v4.0.30319\mscorlib.dll
// Name: System.Xml, Location: C:\Windows\Microsoft.Net\assembly\GAC_MSIL\System.Xml\v4.0_4.0.0.0__b77a5c561934e089\System.Xml.dll
//
// If any assembly, including the target assembly, is not installed in the
// Global Assembly Cache (GAC) or in the application directory, and the wrapper
// code needs to load the assembly to convert types like arrays and enums, then
// you must register the path of the assembly with the CVI .NET library by
// calling CDotNetRegisterAssemblyPath before calling the wrapper code.
//
// Types exposed by the target assembly but defined in other assemblies:
// CVI name: System_Xml_XmlNodeList, .NET name: System.Xml.XmlNodeList, Assembly: System.Xml, Module: Global Assembly Cache
// CVI name: System_Collections_Generic_List_T1, .NET name: System.Collections.Generic.List`1[[System.UInt16, mscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089]], Assembly: mscorlib, Module: Global Assembly Cache
// CVI name: System_Collections_Generic_List_T1, .NET name: System.Collections.Generic.List`1[[Alv.NarrowBand.DataPoint, NbLib, Version=0.0.0.0, Culture=neutral, PublicKeyToken=null]], Assembly: mscorlib, Module: Global Assembly Cache

#include <cvidotnet.h>

#ifdef __cplusplus
extern "C" {
#endif

// Type definitions
typedef struct __Alv_NarrowBand_Message * Alv_NarrowBand_Message;
typedef struct __Alv_NarrowBand_DataPoints * Alv_NarrowBand_DataPoints;
typedef struct __System_Collections_Generic_List_T1 * System_Collections_Generic_List_T1;
typedef struct __System_Collections_Generic_List_T1 * System_Collections_Generic_List_T1;
typedef struct __System_Xml_XmlNodeList * System_Xml_XmlNodeList;
typedef struct __Alv_CAN_CanComm * Alv_CAN_CanComm;
typedef struct __Alv_CAN_PeakCan * Alv_CAN_PeakCan;
typedef struct __Alv_NarrowBand_Sensor * Alv_NarrowBand_Sensor;
typedef struct __Alv_NarrowBand_SensorComm * Alv_NarrowBand_SensorComm;
typedef struct __Alv_CAN_CanMsg * Alv_CAN_CanMsg;
typedef struct __Alv_CAN_NiCan * Alv_CAN_NiCan;
typedef struct __Alv_NarrowBand_HP_DIAG * Alv_NarrowBand_HP_DIAG;
typedef struct __Alv_NarrowBand_UNT_DAT * Alv_NarrowBand_UNT_DAT;
typedef struct __Alv_NarrowBand_NBProtocol * Alv_NarrowBand_NBProtocol;
typedef struct __Alv_NarrowBand_DataPoint * Alv_NarrowBand_DataPoint;
typedef struct __Alv_CAN_SoftingCan * Alv_CAN_SoftingCan;
typedef struct __Alv_NarrowBand_Enumeration * Alv_NarrowBand_Enumeration;
typedef struct __Alv_NarrowBand_DSP_DIAG * Alv_NarrowBand_DSP_DIAG;
typedef struct __Alv_NbLib * Alv_NbLib;

// C wrapper for enumeration type Alv.NarrowBand.PointTypes
#ifndef Alv_NarrowBand_PointTypes_DEFINED
#define Alv_NarrowBand_PointTypes_DEFINED
typedef enum Alv_NarrowBand_PointTypes
{
	Alv_NarrowBand_PointTypes_PAF_TYPE_BOOL = 0x0,
	Alv_NarrowBand_PointTypes_PAF_TYPE_U8 = 0x1,
	Alv_NarrowBand_PointTypes_PAF_TYPE_U16 = 0x2,
	Alv_NarrowBand_PointTypes_PAF_TYPE_U32 = 0x3,
	Alv_NarrowBand_PointTypes_PAF_TYPE_S16 = 0x4,
	Alv_NarrowBand_PointTypes_PAF_TYPE_S32 = 0x5,
	Alv_NarrowBand_PointTypes_PAF_TYPE_F32 = 0x6,
	Alv_NarrowBand_PointTypes_PAF_TYPE_DATE = 0x7,
	Alv_NarrowBand_PointTypes_PAF_TYPE_VERSION = 0x8,
	Alv_NarrowBand_PointTypes_PAF_TYPE_STRING = 0x9,
	Alv_NarrowBand_PointTypes_PAF_TYPE_STRING1 = 0xa,
	Alv_NarrowBand_PointTypes_PAF_TYPE_STRING2 = 0xb,
	Alv_NarrowBand_PointTypes_PAF_TYPE_STRING3 = 0xc,
	Alv_NarrowBand_PointTypes_PAF_TYPE_STRING4 = 0xd,
	Alv_NarrowBand_PointTypes_PAF_TYPE_STRING5 = 0xe,
} Alv_NarrowBand_PointTypes;
#endif // Alv_NarrowBand_PointTypes_DEFINED

// C wrapper for enumeration type Alv.NarrowBand.PointFormats
#ifndef Alv_NarrowBand_PointFormats_DEFINED
#define Alv_NarrowBand_PointFormats_DEFINED
typedef enum Alv_NarrowBand_PointFormats
{
	Alv_NarrowBand_PointFormats_PAF_FORMAT_RAW = 0x0,
	Alv_NarrowBand_PointFormats_PAF_FORMAT_DECIMAL = 0x1,
	Alv_NarrowBand_PointFormats_PAF_FORMAT_STANDARD = 0x2,
	Alv_NarrowBand_PointFormats_PAF_FORMAT_HEX = 0x3,
	Alv_NarrowBand_PointFormats_PAF_FORMAT_BIN = 0x4,
} Alv_NarrowBand_PointFormats;
#endif // Alv_NarrowBand_PointFormats_DEFINED

// C wrapper for enumeration type Alv.NarrowBand.NBProtocol+Status
#ifndef Alv_NarrowBand_NBProtocol_Status_DEFINED
#define Alv_NarrowBand_NBProtocol_Status_DEFINED
typedef enum Alv_NarrowBand_NBProtocol_Status
{
	Alv_NarrowBand_NBProtocol_Status_STATUS_OK = 0x0,
	Alv_NarrowBand_NBProtocol_Status_STATUS_NOTVALID = 0x1,
	Alv_NarrowBand_NBProtocol_Status_STATUS_NOTSUPPORTED = 0x2,
	Alv_NarrowBand_NBProtocol_Status_STATUS_NOTWRITEABLE = 0x3,
	Alv_NarrowBand_NBProtocol_Status_STATUS_OUTOFRANGE = 0x4,
	Alv_NarrowBand_NBProtocol_Status_STATUS_NOTIMPLEMENTED = 0x5,
	Alv_NarrowBand_NBProtocol_Status_STATUS_EXECUTIONTIMEOUT = 0x6,
	Alv_NarrowBand_NBProtocol_Status_STATUS_BUSY = 0x7,
	Alv_NarrowBand_NBProtocol_Status_STATUS_UNEXPECTED_REQUEST = 0x8,
	Alv_NarrowBand_NBProtocol_Status_STATUS_UNEXPECTED_RESPONSE = 0x9,
	Alv_NarrowBand_NBProtocol_Status_STATUS_EXTENDED_START = 0xa,
	Alv_NarrowBand_NBProtocol_Status_STATUS_UNKNOWN_ERROR = 0xa,
	Alv_NarrowBand_NBProtocol_Status_STATUS_EEPROM_HW_ERROR = 0xb,
	Alv_NarrowBand_NBProtocol_Status_STATUS_FAILDED_TO_START_STOP_SEQUENCER = 0xc,
	Alv_NarrowBand_NBProtocol_Status_STATUS_CONFIG_IO_BUSY = 0xd,
	Alv_NarrowBand_NBProtocol_Status_STATUS_CONFIG_IO_TIMED_OUT = 0xe,
	Alv_NarrowBand_NBProtocol_Status_STATUS_RESERVED = 0xf,
	Alv_NarrowBand_NBProtocol_Status_STATUS_CONFIG_RADAR_INVALID = 0x10,
	Alv_NarrowBand_NBProtocol_Status_STATUS_NO_ACCESSOR = 0x11,
	Alv_NarrowBand_NBProtocol_Status_STATUS_CAN_READ_ERROR = 0x75,
	Alv_NarrowBand_NBProtocol_Status_STATUS_CAN_WRITE_ERROR = 0x76,
	Alv_NarrowBand_NBProtocol_Status_STATUS_NOTALLOWED = 0x77,
	Alv_NarrowBand_NBProtocol_Status_STATUS_KEYNOTVALID = 0x78,
	Alv_NarrowBand_NBProtocol_Status_STATUS_INVALIDENTRY = 0x79,
	Alv_NarrowBand_NBProtocol_Status_STATUS_DATACHANGED = 0x7a,
	Alv_NarrowBand_NBProtocol_Status_STATUS_POINTNOTFOUND = 0x7b,
	Alv_NarrowBand_NBProtocol_Status_STATUS_EXTENDEDSTATUS = 0xfe,
} Alv_NarrowBand_NBProtocol_Status;
#endif // Alv_NarrowBand_NBProtocol_Status_DEFINED

// C wrapper for enumeration type Alv.CAN.CanBusModes
#ifndef Alv_CAN_CanBusModes_DEFINED
#define Alv_CAN_CanBusModes_DEFINED
typedef enum Alv_CAN_CanBusModes
{
	Alv_CAN_CanBusModes_HighSpeed = 0x0,
	Alv_CAN_CanBusModes_LowSpeed = 0x1,
	Alv_CAN_CanBusModes_SingleWire = 0x2,
} Alv_CAN_CanBusModes;
#endif // Alv_CAN_CanBusModes_DEFINED

// C wrapper for enumeration type Alv.CAN.CanWakeupModes
#ifndef Alv_CAN_CanWakeupModes_DEFINED
#define Alv_CAN_CanWakeupModes_DEFINED
typedef enum Alv_CAN_CanWakeupModes
{
	Alv_CAN_CanWakeupModes_Normal = 0x0,
	Alv_CAN_CanWakeupModes_Sleep = 0x1,
	Alv_CAN_CanWakeupModes_Wakeup = 0x2,
	Alv_CAN_CanWakeupModes_Highspeed = 0x3,
} Alv_CAN_CanWakeupModes;
#endif // Alv_CAN_CanWakeupModes_DEFINED

// C wrapper for enumeration type Alv.NarrowBand.NBProtocol+GearPosition
#ifndef Alv_NarrowBand_NBProtocol_GearPosition_DEFINED
#define Alv_NarrowBand_NBProtocol_GearPosition_DEFINED
typedef enum Alv_NarrowBand_NBProtocol_GearPosition
{
	Alv_NarrowBand_NBProtocol_GearPosition_Park = 0x0,
	Alv_NarrowBand_NBProtocol_GearPosition_Drive = 0x5,
	Alv_NarrowBand_NBProtocol_GearPosition_Neutral = 0x6,
	Alv_NarrowBand_NBProtocol_GearPosition_Reverse = 0x7,
	Alv_NarrowBand_NBProtocol_GearPosition_Manual = 0x8,
	Alv_NarrowBand_NBProtocol_GearPosition_Error = 0xf,
} Alv_NarrowBand_NBProtocol_GearPosition;
#endif // Alv_NarrowBand_NBProtocol_GearPosition_DEFINED

// C wrapper for enumeration type Alv.NarrowBand.NBProtocol+Position
#ifndef Alv_NarrowBand_NBProtocol_Position_DEFINED
#define Alv_NarrowBand_NBProtocol_Position_DEFINED
typedef enum Alv_NarrowBand_NBProtocol_Position
{
	Alv_NarrowBand_NBProtocol_Position_FRONT_LEFT = 0x0,
	Alv_NarrowBand_NBProtocol_Position_FRONT_RIGHT = 0x1,
	Alv_NarrowBand_NBProtocol_Position_FRONT_CENTER = 0x2,
	Alv_NarrowBand_NBProtocol_Position_REAR_CENTER = 0x3,
	Alv_NarrowBand_NBProtocol_Position_REAR_LEFT = 0x4,
	Alv_NarrowBand_NBProtocol_Position_REAR_RIGHT = 0x5,
	Alv_NarrowBand_NBProtocol_Position_SIDE_LEFT = 0x6,
	Alv_NarrowBand_NBProtocol_Position_SIDE_RIGHT = 0x7,
} Alv_NarrowBand_NBProtocol_Position;
#endif // Alv_NarrowBand_NBProtocol_Position_DEFINED

// C wrapper for enumeration type Alv.NarrowBand.NBProtocol+ConfigurationBlock
#ifndef Alv_NarrowBand_NBProtocol_ConfigurationBlock_DEFINED
#define Alv_NarrowBand_NBProtocol_ConfigurationBlock_DEFINED
typedef enum Alv_NarrowBand_NBProtocol_ConfigurationBlock
{
	Alv_NarrowBand_NBProtocol_ConfigurationBlock_DSP_Factory_Fixed = 0x1,
	Alv_NarrowBand_NBProtocol_ConfigurationBlock_DSP_Factory_Calibration = 0x2,
	Alv_NarrowBand_NBProtocol_ConfigurationBlock_DSP_Platform = 0x3,
	Alv_NarrowBand_NBProtocol_ConfigurationBlock_DSP_SP = 0x4,
	Alv_NarrowBand_NBProtocol_ConfigurationBlock_DSP_RCTA = 0x5,
	Alv_NarrowBand_NBProtocol_ConfigurationBlock_DSP_BSD = 0x6,
	Alv_NarrowBand_NBProtocol_ConfigurationBlock_DSP_LCA = 0x7,
	Alv_NarrowBand_NBProtocol_ConfigurationBlock_DSP_Dirty = 0x80,
	Alv_NarrowBand_NBProtocol_ConfigurationBlock_DSP_AllExceptFactory = 0x81,
	Alv_NarrowBand_NBProtocol_ConfigurationBlock_DSP_AllFactory = 0x82,
} Alv_NarrowBand_NBProtocol_ConfigurationBlock;
#endif // Alv_NarrowBand_NBProtocol_ConfigurationBlock_DEFINED

// C wrapper for enumeration type Alv.NarrowBand.NBProtocol+Antenna
#ifndef Alv_NarrowBand_NBProtocol_Antenna_DEFINED
#define Alv_NarrowBand_NBProtocol_Antenna_DEFINED
typedef enum Alv_NarrowBand_NBProtocol_Antenna
{
	Alv_NarrowBand_NBProtocol_Antenna_Automatic = 0x0,
	Alv_NarrowBand_NBProtocol_Antenna_Antenna1 = 0x1,
	Alv_NarrowBand_NBProtocol_Antenna_Antenna2 = 0x2,
} Alv_NarrowBand_NBProtocol_Antenna;
#endif // Alv_NarrowBand_NBProtocol_Antenna_DEFINED

// C wrapper for enumeration type Alv.NarrowBand.NBProtocol+DCOffset
#ifndef Alv_NarrowBand_NBProtocol_DCOffset_DEFINED
#define Alv_NarrowBand_NBProtocol_DCOffset_DEFINED
typedef enum Alv_NarrowBand_NBProtocol_DCOffset
{
	Alv_NarrowBand_NBProtocol_DCOffset_Automatic = 0x0,
	Alv_NarrowBand_NBProtocol_DCOffset_On = 0x1,
	Alv_NarrowBand_NBProtocol_DCOffset_Off = 0x2,
} Alv_NarrowBand_NBProtocol_DCOffset;
#endif // Alv_NarrowBand_NBProtocol_DCOffset_DEFINED

// C wrapper for enumeration type Alv.NarrowBand.NBProtocol+Processor
#ifndef Alv_NarrowBand_NBProtocol_Processor_DEFINED
#define Alv_NarrowBand_NBProtocol_Processor_DEFINED
typedef enum Alv_NarrowBand_NBProtocol_Processor
{
	Alv_NarrowBand_NBProtocol_Processor_Default = 0x0,
	Alv_NarrowBand_NBProtocol_Processor_HP = 0x1,
	Alv_NarrowBand_NBProtocol_Processor_DSP = 0x2,
} Alv_NarrowBand_NBProtocol_Processor;
#endif // Alv_NarrowBand_NBProtocol_Processor_DEFINED

// C wrapper for enumeration type Alv.NarrowBand.NBProtocol+TestLED
#ifndef Alv_NarrowBand_NBProtocol_TestLED_DEFINED
#define Alv_NarrowBand_NBProtocol_TestLED_DEFINED
typedef enum Alv_NarrowBand_NBProtocol_TestLED
{
	Alv_NarrowBand_NBProtocol_TestLED_Off = 0x0,
	Alv_NarrowBand_NBProtocol_TestLED_TimedOn = 0x1,
	Alv_NarrowBand_NBProtocol_TestLED_TimedBlink = 0x2,
	Alv_NarrowBand_NBProtocol_TestLED_ConstantOn = 0x3,
	Alv_NarrowBand_NBProtocol_TestLED_ConstantBlink = 0x4,
} Alv_NarrowBand_NBProtocol_TestLED;
#endif // Alv_NarrowBand_NBProtocol_TestLED_DEFINED

// C wrapper for enumeration type Alv.NarrowBand.NBProtocol+StaticTestMode
#ifndef Alv_NarrowBand_NBProtocol_StaticTestMode_DEFINED
#define Alv_NarrowBand_NBProtocol_StaticTestMode_DEFINED
typedef enum Alv_NarrowBand_NBProtocol_StaticTestMode
{
	Alv_NarrowBand_NBProtocol_StaticTestMode_Automatic = 0x0,
	Alv_NarrowBand_NBProtocol_StaticTestMode_EndOfLine = 0x1,
	Alv_NarrowBand_NBProtocol_StaticTestMode_Coffin = 0x2,
	Alv_NarrowBand_NBProtocol_StaticTestMode_LCA = 0x3,
	Alv_NarrowBand_NBProtocol_StaticTestMode_RCTA_Main = 0x4,
	Alv_NarrowBand_NBProtocol_StaticTestMode_RCTA_Squint = 0x5,
	Alv_NarrowBand_NBProtocol_StaticTestMode_BSD = 0x6,
	Alv_NarrowBand_NBProtocol_StaticTestMode_OEM_EMI = 0x7,
	Alv_NarrowBand_NBProtocol_StaticTestMode_ALV_EMI = 0x8,
} Alv_NarrowBand_NBProtocol_StaticTestMode;
#endif // Alv_NarrowBand_NBProtocol_StaticTestMode_DEFINED

// C wrapper for enumeration type Alv.NarrowBand.NBProtocol+ControlRadarMode
#ifndef Alv_NarrowBand_NBProtocol_ControlRadarMode_DEFINED
#define Alv_NarrowBand_NBProtocol_ControlRadarMode_DEFINED
typedef enum Alv_NarrowBand_NBProtocol_ControlRadarMode
{
	Alv_NarrowBand_NBProtocol_ControlRadarMode_Automatic = 0x0,
	Alv_NarrowBand_NBProtocol_ControlRadarMode_BSD = 0x1,
	Alv_NarrowBand_NBProtocol_ControlRadarMode_RCTA = 0x2,
	Alv_NarrowBand_NBProtocol_ControlRadarMode_LCA = 0x3,
} Alv_NarrowBand_NBProtocol_ControlRadarMode;
#endif // Alv_NarrowBand_NBProtocol_ControlRadarMode_DEFINED

// C wrapper for enumeration type Alv.NarrowBand.NBProtocol+ControlError
#ifndef Alv_NarrowBand_NBProtocol_ControlError_DEFINED
#define Alv_NarrowBand_NBProtocol_ControlError_DEFINED
typedef enum Alv_NarrowBand_NBProtocol_ControlError
{
	Alv_NarrowBand_NBProtocol_ControlError_ClearIndividual = 0x0,
	Alv_NarrowBand_NBProtocol_ControlError_SetIndividual = 0x1,
	Alv_NarrowBand_NBProtocol_ControlError_ClearAll = 0x2,
} Alv_NarrowBand_NBProtocol_ControlError;
#endif // Alv_NarrowBand_NBProtocol_ControlError_DEFINED

// C wrapper for enumeration type Alv.NarrowBand.NBProtocol+LoggerID
#ifndef Alv_NarrowBand_NBProtocol_LoggerID_DEFINED
#define Alv_NarrowBand_NBProtocol_LoggerID_DEFINED
typedef enum Alv_NarrowBand_NBProtocol_LoggerID
{
	Alv_NarrowBand_NBProtocol_LoggerID_SimpleErrorLogger = 0x0,
	Alv_NarrowBand_NBProtocol_LoggerID_EventDataRecorder = 0x1,
} Alv_NarrowBand_NBProtocol_LoggerID;
#endif // Alv_NarrowBand_NBProtocol_LoggerID_DEFINED

// C wrapper for enumeration type Alv.NarrowBand.NBProtocol+ControlLogger
#ifndef Alv_NarrowBand_NBProtocol_ControlLogger_DEFINED
#define Alv_NarrowBand_NBProtocol_ControlLogger_DEFINED
typedef enum Alv_NarrowBand_NBProtocol_ControlLogger
{
	Alv_NarrowBand_NBProtocol_ControlLogger_ClearAllRecords = 0x0,
	Alv_NarrowBand_NBProtocol_ControlLogger_StartRecording = 0x1,
	Alv_NarrowBand_NBProtocol_ControlLogger_StopRecording = 0x2,
	Alv_NarrowBand_NBProtocol_ControlLogger_SetPreTriggerDepth = 0x3,
	Alv_NarrowBand_NBProtocol_ControlLogger_SetTriggerType = 0x4,
	Alv_NarrowBand_NBProtocol_ControlLogger_SetTriggerSource = 0x5,
} Alv_NarrowBand_NBProtocol_ControlLogger;
#endif // Alv_NarrowBand_NBProtocol_ControlLogger_DEFINED

// C wrapper for enumeration type Alv.NarrowBand.NBProtocol+ExecuteFunctions
#ifndef Alv_NarrowBand_NBProtocol_ExecuteFunctions_DEFINED
#define Alv_NarrowBand_NBProtocol_ExecuteFunctions_DEFINED
typedef enum Alv_NarrowBand_NBProtocol_ExecuteFunctions
{
	Alv_NarrowBand_NBProtocol_ExecuteFunctions_ResetProcessor = 0x1,
	Alv_NarrowBand_NBProtocol_ExecuteFunctions_LoadConfiguration = 0x2,
	Alv_NarrowBand_NBProtocol_ExecuteFunctions_SaveConfiguration = 0x3,
	Alv_NarrowBand_NBProtocol_ExecuteFunctions_ResetConfiguration = 0x4,
	Alv_NarrowBand_NBProtocol_ExecuteFunctions_RunCalibration = 0x5,
	Alv_NarrowBand_NBProtocol_ExecuteFunctions_ExitEngineeringMode = 0x6,
	Alv_NarrowBand_NBProtocol_ExecuteFunctions_PerformSelfTest = 0x7,
	Alv_NarrowBand_NBProtocol_ExecuteFunctions_ControlLED = 0x8,
	Alv_NarrowBand_NBProtocol_ExecuteFunctions_EnableRF = 0x9,
	Alv_NarrowBand_NBProtocol_ExecuteFunctions_SelectTxAntenna = 0xa,
	Alv_NarrowBand_NBProtocol_ExecuteFunctions_EnableCWMode = 0xb,
	Alv_NarrowBand_NBProtocol_ExecuteFunctions_EnableRadarRx = 0xc,
	Alv_NarrowBand_NBProtocol_ExecuteFunctions_ControlDCOffset = 0xd,
	Alv_NarrowBand_NBProtocol_ExecuteFunctions_RawSweepBroadcast = 0xe,
	Alv_NarrowBand_NBProtocol_ExecuteFunctions_ControlStaticTestMode = 0xf,
	Alv_NarrowBand_NBProtocol_ExecuteFunctions_ControlPulseJitter = 0x10,
	Alv_NarrowBand_NBProtocol_ExecuteFunctions_ForceRadarMode = 0x11,
	Alv_NarrowBand_NBProtocol_ExecuteFunctions_RunOffsetInitialization = 0x12,
	Alv_NarrowBand_NBProtocol_ExecuteFunctions_ErrorManager = 0x13,
	Alv_NarrowBand_NBProtocol_ExecuteFunctions_ErrorLoggerControl = 0x14,
} Alv_NarrowBand_NBProtocol_ExecuteFunctions;
#endif // Alv_NarrowBand_NBProtocol_ExecuteFunctions_DEFINED

// C wrapper for enumeration type Alv.CAN.CanDevices
#ifndef Alv_CAN_CanDevices_DEFINED
#define Alv_CAN_CanDevices_DEFINED
typedef enum Alv_CAN_CanDevices
{
	Alv_CAN_CanDevices_PeakCan = 0x0,
	Alv_CAN_CanDevices_NiCan = 0x1,
	Alv_CAN_CanDevices_SoftingCan = 0x2,
} Alv_CAN_CanDevices;
#endif // Alv_CAN_CanDevices_DEFINED

// C wrapper for enumeration type Alv.NarrowBand.HP_DIAG+HP_States
#ifndef Alv_NarrowBand_HP_DIAG_HP_States_DEFINED
#define Alv_NarrowBand_HP_DIAG_HP_States_DEFINED
typedef enum Alv_NarrowBand_HP_DIAG_HP_States
{
	Alv_NarrowBand_HP_DIAG_HP_States_INITIALIZATION_STATE = 0x0,
	Alv_NarrowBand_HP_DIAG_HP_States_DISABLED_STATE = 0x1,
	Alv_NarrowBand_HP_DIAG_HP_States_STANDBY_STATE = 0x2,
	Alv_NarrowBand_HP_DIAG_HP_States_TEMP_DISABLE = 0x3,
	Alv_NarrowBand_HP_DIAG_HP_States_BSD_DISABLED = 0x4,
	Alv_NarrowBand_HP_DIAG_HP_States_BSD_AND_LCA_ACTIVE = 0x5,
	Alv_NarrowBand_HP_DIAG_HP_States_BSD_AND_LCA_ALERT_ENABLED = 0x6,
	Alv_NarrowBand_HP_DIAG_HP_States_RCTA_ACTIVE = 0x7,
	Alv_NarrowBand_HP_DIAG_HP_States_RCTA_ALERT_ENABLED = 0x8,
} Alv_NarrowBand_HP_DIAG_HP_States;
#endif // Alv_NarrowBand_HP_DIAG_HP_States_DEFINED

// C wrapper for enumeration type Alv.NarrowBand.HP_DIAG+HP_Run_Modes
#ifndef Alv_NarrowBand_HP_DIAG_HP_Run_Modes_DEFINED
#define Alv_NarrowBand_HP_DIAG_HP_Run_Modes_DEFINED
typedef enum Alv_NarrowBand_HP_DIAG_HP_Run_Modes
{
	Alv_NarrowBand_HP_DIAG_HP_Run_Modes_Bootloader = 0x1,
	Alv_NarrowBand_HP_DIAG_HP_Run_Modes_BootReloader = 0x2,
	Alv_NarrowBand_HP_DIAG_HP_Run_Modes_Application = 0x3,
} Alv_NarrowBand_HP_DIAG_HP_Run_Modes;
#endif // Alv_NarrowBand_HP_DIAG_HP_Run_Modes_DEFINED

// C wrapper for enumeration type Alv.NarrowBand.HP_DIAG+DSP_States
#ifndef Alv_NarrowBand_HP_DIAG_DSP_States_DEFINED
#define Alv_NarrowBand_HP_DIAG_DSP_States_DEFINED
typedef enum Alv_NarrowBand_HP_DIAG_DSP_States
{
	Alv_NarrowBand_HP_DIAG_DSP_States_eSSM_NONE = 0x0,
	Alv_NarrowBand_HP_DIAG_DSP_States_eSSM_IDLE = 0x1,
	Alv_NarrowBand_HP_DIAG_DSP_States_eSSM_BSM = 0x2,
	Alv_NarrowBand_HP_DIAG_DSP_States_eSSM_RCP = 0x3,
	Alv_NarrowBand_HP_DIAG_DSP_States_eSSM_LCA_LCA = 0x4,
} Alv_NarrowBand_HP_DIAG_DSP_States;
#endif // Alv_NarrowBand_HP_DIAG_DSP_States_DEFINED

// C wrapper for enumeration type Alv.NarrowBand.NBProtocol+SensorRx
#ifndef Alv_NarrowBand_NBProtocol_SensorRx_DEFINED
#define Alv_NarrowBand_NBProtocol_SensorRx_DEFINED
typedef enum Alv_NarrowBand_NBProtocol_SensorRx
{
	Alv_NarrowBand_NBProtocol_SensorRx_READ_DATA_REQ = 0x0,
	Alv_NarrowBand_NBProtocol_SensorRx_WRITE_DATA_REQ = 0x1,
	Alv_NarrowBand_NBProtocol_SensorRx_EXECUTE_FUNCTION_REQ = 0x2,
	Alv_NarrowBand_NBProtocol_SensorRx_READ_CONFIG_COMMAND_REQ = 0x3,
	Alv_NarrowBand_NBProtocol_SensorRx_RESERVED_3_REQ = 0x4,
	Alv_NarrowBand_NBProtocol_SensorRx_WRITE_CONFIG_COMMAND_REQ = 0x5,
	Alv_NarrowBand_NBProtocol_SensorRx_WRITE_CONFIG_DATA_REQ = 0x6,
	Alv_NarrowBand_NBProtocol_SensorRx_ENGINEERING_MODE_REQ = 0x7,
	Alv_NarrowBand_NBProtocol_SensorRx_RESERVED_1_REQ = 0x8,
	Alv_NarrowBand_NBProtocol_SensorRx_RESERVED_2_REQ = 0x9,
	Alv_NarrowBand_NBProtocol_SensorRx_RESERVED_4_REQ = 0xa,
	Alv_NarrowBand_NBProtocol_SensorRx_RESERVED_5_REQ = 0xb,
	Alv_NarrowBand_NBProtocol_SensorRx_RESERVED_6_REQ = 0xc,
	Alv_NarrowBand_NBProtocol_SensorRx_DEVELOPER_2_REQ = 0xd,
	Alv_NarrowBand_NBProtocol_SensorRx_DEVELOPER_1_REQ = 0xe,
	Alv_NarrowBand_NBProtocol_SensorRx_ESP_DAT1 = 0xf,
	Alv_NarrowBand_NBProtocol_SensorRx_ESP_DAT2 = 0x10,
	Alv_NarrowBand_NBProtocol_SensorRx_REPROGRAM_START_REQ = 0x11,
	Alv_NarrowBand_NBProtocol_SensorRx_REPROGRAM_RECORD_REQ = 0x12,
	Alv_NarrowBand_NBProtocol_SensorRx_REPROGRAM_DATA_REQ = 0x13,
	Alv_NarrowBand_NBProtocol_SensorRx_REPROGRAM_RESET_REQ = 0x14,
	Alv_NarrowBand_NBProtocol_SensorRx_AQU_CS_REQ = 0x15,
} Alv_NarrowBand_NBProtocol_SensorRx;
#endif // Alv_NarrowBand_NBProtocol_SensorRx_DEFINED

// C wrapper for enumeration type Alv.NarrowBand.NBProtocol+SensorTx
#ifndef Alv_NarrowBand_NBProtocol_SensorTx_DEFINED
#define Alv_NarrowBand_NBProtocol_SensorTx_DEFINED
typedef enum Alv_NarrowBand_NBProtocol_SensorTx
{
	Alv_NarrowBand_NBProtocol_SensorTx_INFO = 0x0,
	Alv_NarrowBand_NBProtocol_SensorTx_BSD_CMD = 0x1,
	Alv_NarrowBand_NBProtocol_SensorTx_RCTA_CMD = 0x2,
	Alv_NarrowBand_NBProtocol_SensorTx_LCA_CMD1 = 0x3,
	Alv_NarrowBand_NBProtocol_SensorTx_DAT1 = 0x4,
	Alv_NarrowBand_NBProtocol_SensorTx_SYNC = 0x5,
	Alv_NarrowBand_NBProtocol_SensorTx_CRTSN_DAT = 0x6,
	Alv_NarrowBand_NBProtocol_SensorTx_UNT_DAT = 0x7,
	Alv_NarrowBand_NBProtocol_SensorTx_RCTA_DEBUG = 0x8,
	Alv_NarrowBand_NBProtocol_SensorTx_CLASS_DEBUG = 0x9,
	Alv_NarrowBand_NBProtocol_SensorTx_MTI_DEBUG = 0xa,
	Alv_NarrowBand_NBProtocol_SensorTx_READ_DATA_RSP = 0xb,
	Alv_NarrowBand_NBProtocol_SensorTx_WRITE_DATA_RSP = 0xc,
	Alv_NarrowBand_NBProtocol_SensorTx_EXECUTE_FUNCTION_RSP = 0xd,
	Alv_NarrowBand_NBProtocol_SensorTx_READ_CONFIG_DATA_RSP = 0xe,
	Alv_NarrowBand_NBProtocol_SensorTx_READ_CONFIG_STATUS_RSP = 0xf,
	Alv_NarrowBand_NBProtocol_SensorTx_WRITE_CONFIG_STATUS_RSP = 0x10,
	Alv_NarrowBand_NBProtocol_SensorTx_HP_DIAG = 0x11,
	Alv_NarrowBand_NBProtocol_SensorTx_ENGINEERING_MODE_RSP = 0x12,
	Alv_NarrowBand_NBProtocol_SensorTx_MANUFACTURING_DATA = 0x13,
	Alv_NarrowBand_NBProtocol_SensorTx_DAT2 = 0x14,
	Alv_NarrowBand_NBProtocol_SensorTx_LCA_CMD2 = 0x15,
	Alv_NarrowBand_NBProtocol_SensorTx_RESERVED_3_RSP = 0x16,
	Alv_NarrowBand_NBProtocol_SensorTx_RESERVED_4_RSP = 0x17,
	Alv_NarrowBand_NBProtocol_SensorTx_DEVELOPER_2_RSP = 0x18,
	Alv_NarrowBand_NBProtocol_SensorTx_DEVELOPER_1_RSP = 0x19,
	Alv_NarrowBand_NBProtocol_SensorTx_DBG = 0x1a,
	Alv_NarrowBand_NBProtocol_SensorTx_CS = 0x1b,
	Alv_NarrowBand_NBProtocol_SensorTx_DSP_DIAG = 0x1c,
	Alv_NarrowBand_NBProtocol_SensorTx_REPROGRAM_STATUS_RSP = 0x1d,
} Alv_NarrowBand_NBProtocol_SensorTx;
#endif // Alv_NarrowBand_NBProtocol_SensorTx_DEFINED

// C wrapper for enumeration type Alv.NarrowBand.NBProtocol+Key
#ifndef Alv_NarrowBand_NBProtocol_Key_DEFINED
#define Alv_NarrowBand_NBProtocol_Key_DEFINED
typedef enum Alv_NarrowBand_NBProtocol_Key
{
	Alv_NarrowBand_NBProtocol_Key_Reprogram = 0xb78c1a45,
} Alv_NarrowBand_NBProtocol_Key;
#endif // Alv_NarrowBand_NBProtocol_Key_DEFINED

// C wrapper for enumeration type Alv.NarrowBand.NBProtocol+EngineeringMode
#ifndef Alv_NarrowBand_NBProtocol_EngineeringMode_DEFINED
#define Alv_NarrowBand_NBProtocol_EngineeringMode_DEFINED
typedef enum Alv_NarrowBand_NBProtocol_EngineeringMode
{
	Alv_NarrowBand_NBProtocol_EngineeringMode_REQ_MODE = 0x1,
	Alv_NarrowBand_NBProtocol_EngineeringMode_REQ_SEED = 0x2,
	Alv_NarrowBand_NBProtocol_EngineeringMode_SEND_KEY = 0x3,
	Alv_NarrowBand_NBProtocol_EngineeringMode_EXIT = 0x4,
} Alv_NarrowBand_NBProtocol_EngineeringMode;
#endif // Alv_NarrowBand_NBProtocol_EngineeringMode_DEFINED




// Global Functions
int CVIFUNC Initialize_NbLib(void);
int CVIFUNC Close_NbLib(void);

// Type: Alv.NarrowBand.Message
int CVIFUNC Alv_NarrowBand_Message__Create(
	Alv_NarrowBand_Message * __instance,
	CDotNetHandle * __exception);

// Type: Alv.NarrowBand.DataPoints
int CVIFUNC Alv_NarrowBand_DataPoints__Create(
	Alv_NarrowBand_DataPoints * __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoints_Get_Version(
	Alv_NarrowBand_DataPoints __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoints_Get_Points(
	Alv_NarrowBand_DataPoints __instance,
	System_Collections_Generic_List_T1 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoints_Get_Count(
	Alv_NarrowBand_DataPoints __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoints_Get_SecurityGroups(
	Alv_NarrowBand_DataPoints __instance,
	System_Collections_Generic_List_T1 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoints_Get_Secure(
	Alv_NarrowBand_DataPoints __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoints_Set_Secure(
	Alv_NarrowBand_DataPoints __instance,
	int value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoints_Initialize(
	Alv_NarrowBand_DataPoints __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoints_GetVersion(
	Alv_NarrowBand_DataPoints __instance,
	char * filename,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoints_Load(
	Alv_NarrowBand_DataPoints __instance,
	char * filename,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoints_AddEnums(
	Alv_NarrowBand_DataPoints __instance,
	System_Xml_XmlNodeList * nodeList,
	char * nameEnum,
	char * nameChild,
	char * attrValue,
	char * attrName,
	char * attrDisplay,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoints_AllValid(
	Alv_NarrowBand_DataPoints __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoints_SavePointData(
	Alv_NarrowBand_DataPoints __instance,
	char * filename,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoints_LoadPointData(
	Alv_NarrowBand_DataPoints __instance,
	char * filename,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoints_Find(
	Alv_NarrowBand_DataPoints __instance,
	unsigned short point,
	Alv_NarrowBand_DataPoint * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoints_Data(
	Alv_NarrowBand_DataPoints __instance,
	unsigned short point,
	char * data,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoints_Status(
	Alv_NarrowBand_NBProtocol_Status status,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: Alv.CAN.CanComm
int CVIFUNC Alv_CAN_CanComm_Get_DeviceType(
	Alv_CAN_CanComm __instance,
	Alv_CAN_CanDevices * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_CanComm_Get_BusMode(
	Alv_CAN_CanComm __instance,
	Alv_CAN_CanBusModes * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_CanComm_Set_BusMode(
	Alv_CAN_CanComm __instance,
	Alv_CAN_CanBusModes value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_CanComm_Get_WakeupMode(
	Alv_CAN_CanComm __instance,
	Alv_CAN_CanWakeupModes * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_CanComm_Set_WakeupMode(
	Alv_CAN_CanComm __instance,
	Alv_CAN_CanWakeupModes value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_CanComm_Get_BaudRate(
	Alv_CAN_CanComm __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_CanComm_Set_BaudRate(
	Alv_CAN_CanComm __instance,
	int value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_CanComm_Get_DriverID(
	Alv_CAN_CanComm __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_CanComm_Set_DriverID(
	Alv_CAN_CanComm __instance,
	char * value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_CanComm_Get_ClientID(
	Alv_CAN_CanComm __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_CanComm_Set_ClientID(
	Alv_CAN_CanComm __instance,
	char * value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_CanComm_Get_ReadTimeout(
	Alv_CAN_CanComm __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_CanComm_Set_ReadTimeout(
	Alv_CAN_CanComm __instance,
	int value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_CanComm_Get_WriteTimeout(
	Alv_CAN_CanComm __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_CanComm_Set_WriteTimeout(
	Alv_CAN_CanComm __instance,
	int value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_CanComm_Get_Error(
	Alv_CAN_CanComm __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_CanComm_Connect(
	Alv_CAN_CanComm __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_CanComm_Disconnect(
	Alv_CAN_CanComm __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_CanComm_Read(
	Alv_CAN_CanComm __instance,
	Alv_CAN_CanMsg * msg,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_CanComm_Write(
	Alv_CAN_CanComm __instance,
	Alv_CAN_CanMsg * msg,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_CanComm_Clear(
	Alv_CAN_CanComm __instance,
	int * __returnValue,
	CDotNetHandle * __exception);

// Type: Alv.CAN.PeakCan
int CVIFUNC Alv_CAN_PeakCan__Create(
	Alv_CAN_PeakCan * __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_PeakCan_Get_DeviceType(
	Alv_CAN_PeakCan __instance,
	Alv_CAN_CanDevices * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_PeakCan_Get_BusMode(
	Alv_CAN_PeakCan __instance,
	Alv_CAN_CanBusModes * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_PeakCan_Set_BusMode(
	Alv_CAN_PeakCan __instance,
	Alv_CAN_CanBusModes value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_PeakCan_Get_WakeupMode(
	Alv_CAN_PeakCan __instance,
	Alv_CAN_CanWakeupModes * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_PeakCan_Set_WakeupMode(
	Alv_CAN_PeakCan __instance,
	Alv_CAN_CanWakeupModes value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_PeakCan_Get_BaudRate(
	Alv_CAN_PeakCan __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_PeakCan_Set_BaudRate(
	Alv_CAN_PeakCan __instance,
	int value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_PeakCan_Get_DriverID(
	Alv_CAN_PeakCan __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_PeakCan_Set_DriverID(
	Alv_CAN_PeakCan __instance,
	char * value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_PeakCan_Get_ClientID(
	Alv_CAN_PeakCan __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_PeakCan_Set_ClientID(
	Alv_CAN_PeakCan __instance,
	char * value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_PeakCan_Get_ReadTimeout(
	Alv_CAN_PeakCan __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_PeakCan_Set_ReadTimeout(
	Alv_CAN_PeakCan __instance,
	int value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_PeakCan_Get_WriteTimeout(
	Alv_CAN_PeakCan __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_PeakCan_Set_WriteTimeout(
	Alv_CAN_PeakCan __instance,
	int value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_PeakCan_Get_Error(
	Alv_CAN_PeakCan __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_PeakCan_Connect(
	Alv_CAN_PeakCan __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_PeakCan_Disconnect(
	Alv_CAN_PeakCan __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_PeakCan_Clear(
	Alv_CAN_PeakCan __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_PeakCan_Read(
	Alv_CAN_PeakCan __instance,
	Alv_CAN_CanMsg * msg,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_PeakCan_Write(
	Alv_CAN_PeakCan __instance,
	Alv_CAN_CanMsg * msg,
	int * __returnValue,
	CDotNetHandle * __exception);

// Type: Alv.NarrowBand.Sensor
int CVIFUNC Alv_NarrowBand_Sensor_Get_Position(
	Alv_NarrowBand_Sensor __instance,
	Alv_NarrowBand_NBProtocol_Position * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_Sensor_ClearQueue(
	Alv_NarrowBand_Sensor __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_Sensor_SendVehicleSpeed(
	Alv_NarrowBand_Sensor __instance,
	unsigned int speed,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_Sensor_SendGearPosition(
	Alv_NarrowBand_Sensor __instance,
	Alv_NarrowBand_NBProtocol_GearPosition gear,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_Sensor_Init(
	Alv_NarrowBand_Sensor __instance,
	char * PointsList,
	Alv_NarrowBand_NBProtocol_Position SensorPosition,
	Alv_CAN_CanComm CanInterface,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_Sensor_PointRead(
	Alv_NarrowBand_Sensor __instance,
	unsigned short point,
	char ** value,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_Sensor_PointWrite(
	Alv_NarrowBand_Sensor __instance,
	unsigned short point,
	char * value,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_Sensor_EnterEngineeringMode(
	Alv_NarrowBand_Sensor __instance,
	int selection,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_Sensor_SaveConfiguration(
	Alv_NarrowBand_Sensor __instance,
	Alv_NarrowBand_NBProtocol_ConfigurationBlock block,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_Sensor_ReloadConfiguration(
	Alv_NarrowBand_Sensor __instance,
	Alv_NarrowBand_NBProtocol_ConfigurationBlock block,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_Sensor_ResetConfiguration(
	Alv_NarrowBand_Sensor __instance,
	Alv_NarrowBand_NBProtocol_ConfigurationBlock block,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_Sensor_ControlCWMode(
	Alv_NarrowBand_Sensor __instance,
	int selection,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_Sensor_SelectTxAntenna(
	Alv_NarrowBand_Sensor __instance,
	Alv_NarrowBand_NBProtocol_Antenna antenna,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_Sensor_ControlRF(
	Alv_NarrowBand_Sensor __instance,
	int selection,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_Sensor_ControlRadarRx(
	Alv_NarrowBand_Sensor __instance,
	int selection,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_Sensor_ControlDCOffset(
	Alv_NarrowBand_Sensor __instance,
	Alv_NarrowBand_NBProtocol_DCOffset softwareoffset,
	Alv_NarrowBand_NBProtocol_DCOffset hardwareoffset,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_Sensor_ResetProcessor(
	Alv_NarrowBand_Sensor __instance,
	Alv_NarrowBand_NBProtocol_Processor processor,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_Sensor_ControlLED(
	Alv_NarrowBand_Sensor __instance,
	Alv_NarrowBand_NBProtocol_Processor processor,
	Alv_NarrowBand_NBProtocol_TestLED control,
	unsigned int interval,
	unsigned int timeout,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_Sensor_ControlRawSweepBroadcast(
	Alv_NarrowBand_Sensor __instance,
	Alv_NarrowBand_NBProtocol_Processor processor,
	unsigned char control,
	unsigned int count,
	unsigned char type,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_Sensor_PerformSelfTest(
	Alv_NarrowBand_Sensor __instance,
	Alv_NarrowBand_NBProtocol_Processor processor,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_Sensor_ControlStaticTestMode(
	Alv_NarrowBand_Sensor __instance,
	Alv_NarrowBand_NBProtocol_StaticTestMode selection,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_Sensor_ControlPulseJitter(
	Alv_NarrowBand_Sensor __instance,
	int selection,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_Sensor_ForceRadarMode(
	Alv_NarrowBand_Sensor __instance,
	Alv_NarrowBand_NBProtocol_ControlRadarMode mode,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_Sensor_RunOffsetInitialization(
	Alv_NarrowBand_Sensor __instance,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_Sensor_ReadManufacturingData(
	Alv_NarrowBand_Sensor __instance,
	unsigned char ** data,
	ssize_t * __dataLength,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_Sensor_ErrorManager(
	Alv_NarrowBand_Sensor __instance,
	Alv_NarrowBand_NBProtocol_ControlError selection,
	unsigned int code,
	unsigned int timeout,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_Sensor_LoggerControl(
	Alv_NarrowBand_Sensor __instance,
	Alv_NarrowBand_NBProtocol_LoggerID logger,
	Alv_NarrowBand_NBProtocol_ControlLogger selection,
	unsigned int control,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_Sensor_Program(
	Alv_NarrowBand_Sensor __instance,
	char * filepath,
	Alv_NarrowBand_NBProtocol_Processor processor,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_Sensor_ReadDspDiag(
	Alv_NarrowBand_Sensor __instance,
	Alv_NarrowBand_DSP_DIAG * Msg,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_Sensor_ReadHpDiag(
	Alv_NarrowBand_Sensor __instance,
	Alv_NarrowBand_HP_DIAG * Msg,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_Sensor_ReadUntDat(
	Alv_NarrowBand_Sensor __instance,
	Alv_NarrowBand_UNT_DAT * Msg,
	int * __returnValue,
	CDotNetHandle * __exception);

// Type: Alv.NarrowBand.SensorComm
int CVIFUNC Alv_NarrowBand_SensorComm__Create(
	Alv_NarrowBand_SensorComm * __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_SensorComm_Get_Position(
	Alv_NarrowBand_SensorComm __instance,
	Alv_NarrowBand_NBProtocol_Position * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_SensorComm_Init(
	Alv_NarrowBand_SensorComm __instance,
	char * PointsList,
	Alv_NarrowBand_NBProtocol_Position SensorPosition,
	Alv_CAN_CanComm CanInterface,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_SensorComm_PointRead(
	Alv_NarrowBand_SensorComm __instance,
	unsigned short point,
	char ** value,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_SensorComm_PointWrite(
	Alv_NarrowBand_SensorComm __instance,
	unsigned short point,
	char * value,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_SensorComm_SendExecute(
	Alv_NarrowBand_SensorComm __instance,
	Alv_NarrowBand_NBProtocol_ExecuteFunctions function,
	unsigned int functionData32,
	unsigned short functionData16,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_SensorComm_EnterEngineeringMode(
	Alv_NarrowBand_SensorComm __instance,
	int enterMode,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_SensorComm_EnterEngineeringModeGMVCAN(
	Alv_NarrowBand_SensorComm __instance,
	int enterMode,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_SensorComm_ReadManufacturingData(
	Alv_NarrowBand_SensorComm __instance,
	unsigned char ** response,
	ssize_t * __responseLength,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_SensorComm_SaveConfiguration(
	Alv_NarrowBand_SensorComm __instance,
	Alv_NarrowBand_NBProtocol_ConfigurationBlock block,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_SensorComm_ReloadConfiguration(
	Alv_NarrowBand_SensorComm __instance,
	Alv_NarrowBand_NBProtocol_ConfigurationBlock block,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_SensorComm_ResetConfiguration(
	Alv_NarrowBand_SensorComm __instance,
	Alv_NarrowBand_NBProtocol_ConfigurationBlock block,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_SensorComm_ResetProcessor(
	Alv_NarrowBand_SensorComm __instance,
	Alv_NarrowBand_NBProtocol_Processor processor,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_SensorComm_ControlCWMode(
	Alv_NarrowBand_SensorComm __instance,
	int selection,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_SensorComm_SelectTxAntenna(
	Alv_NarrowBand_SensorComm __instance,
	Alv_NarrowBand_NBProtocol_Antenna antenna,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_SensorComm_ControlRF(
	Alv_NarrowBand_SensorComm __instance,
	int selection,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_SensorComm_ControlRadarRx(
	Alv_NarrowBand_SensorComm __instance,
	int selection,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_SensorComm_ControlDCOffset(
	Alv_NarrowBand_SensorComm __instance,
	Alv_NarrowBand_NBProtocol_DCOffset softwareoffset,
	Alv_NarrowBand_NBProtocol_DCOffset hardwareoffset,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_SensorComm_PerformSelfTest(
	Alv_NarrowBand_SensorComm __instance,
	Alv_NarrowBand_NBProtocol_Processor processor,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_SensorComm_ControlLED(
	Alv_NarrowBand_SensorComm __instance,
	Alv_NarrowBand_NBProtocol_Processor processor,
	Alv_NarrowBand_NBProtocol_TestLED control,
	unsigned int interval,
	unsigned int timeout,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_SensorComm_ControlRawSweepBroadcast(
	Alv_NarrowBand_SensorComm __instance,
	Alv_NarrowBand_NBProtocol_Processor processor,
	unsigned char control,
	unsigned int count,
	unsigned char type,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_SensorComm_ControlStaticTestMode(
	Alv_NarrowBand_SensorComm __instance,
	Alv_NarrowBand_NBProtocol_StaticTestMode selection,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_SensorComm_ControlPulseJitter(
	Alv_NarrowBand_SensorComm __instance,
	int selection,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_SensorComm_ForceRadarMode(
	Alv_NarrowBand_SensorComm __instance,
	Alv_NarrowBand_NBProtocol_ControlRadarMode mode,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_SensorComm_RunOffsetInitialization(
	Alv_NarrowBand_SensorComm __instance,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_SensorComm_EnterProgramMode(
	Alv_NarrowBand_SensorComm __instance,
	Alv_NarrowBand_NBProtocol_Processor processor,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_SensorComm_SendProgram(
	Alv_NarrowBand_SensorComm __instance,
	Alv_NarrowBand_NBProtocol_Processor processor,
	unsigned char * data,
	ssize_t __dataLength,
	unsigned int address,
	unsigned char checksum,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_SensorComm_SendEnd(
	Alv_NarrowBand_SensorComm __instance,
	Alv_NarrowBand_NBProtocol_Processor processor,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_SensorComm_Program(
	Alv_NarrowBand_SensorComm __instance,
	char * filepath,
	Alv_NarrowBand_NBProtocol_Processor processor,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_SensorComm_ErrorManager(
	Alv_NarrowBand_SensorComm __instance,
	Alv_NarrowBand_NBProtocol_ControlError selection,
	unsigned int code,
	unsigned int timeout,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_SensorComm_LoggerControl(
	Alv_NarrowBand_SensorComm __instance,
	Alv_NarrowBand_NBProtocol_LoggerID logger,
	Alv_NarrowBand_NBProtocol_ControlLogger selection,
	unsigned int control,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_SensorComm_ReadDspDiag(
	Alv_NarrowBand_SensorComm __instance,
	Alv_NarrowBand_DSP_DIAG * Msg,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_SensorComm_ReadHpDiag(
	Alv_NarrowBand_SensorComm __instance,
	Alv_NarrowBand_HP_DIAG * Msg,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_SensorComm_ReadUntDat(
	Alv_NarrowBand_SensorComm __instance,
	Alv_NarrowBand_UNT_DAT * Msg,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_SensorComm_ClearQueue(
	Alv_NarrowBand_SensorComm __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_SensorComm_SendVehicleSpeed(
	Alv_NarrowBand_SensorComm __instance,
	unsigned int speed,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_SensorComm_SendGearPosition(
	Alv_NarrowBand_SensorComm __instance,
	Alv_NarrowBand_NBProtocol_GearPosition gear,
	int * __returnValue,
	CDotNetHandle * __exception);

// Type: Alv.CAN.CanMsg
int CVIFUNC Alv_CAN_CanMsg__Create(
	Alv_CAN_CanMsg * __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_CanMsg__Get__ID(
	Alv_CAN_CanMsg __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_CanMsg__Set__ID(
	Alv_CAN_CanMsg __instance,
	unsigned int ID,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_CanMsg__Get__Len(
	Alv_CAN_CanMsg __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_CanMsg__Set__Len(
	Alv_CAN_CanMsg __instance,
	unsigned char Len,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_CanMsg__Get__Data(
	Alv_CAN_CanMsg __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_CanMsg__Set__Data(
	Alv_CAN_CanMsg __instance,
	unsigned char * Data,
	ssize_t __DataLength,
	CDotNetHandle * __exception);

// Type: Alv.CAN.NiCan
int CVIFUNC Alv_CAN_NiCan__Create(
	Alv_CAN_NiCan * __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_NiCan_Get_DeviceType(
	Alv_CAN_NiCan __instance,
	Alv_CAN_CanDevices * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_NiCan_Get_BusMode(
	Alv_CAN_NiCan __instance,
	Alv_CAN_CanBusModes * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_NiCan_Set_BusMode(
	Alv_CAN_NiCan __instance,
	Alv_CAN_CanBusModes value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_NiCan_Get_WakeupMode(
	Alv_CAN_NiCan __instance,
	Alv_CAN_CanWakeupModes * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_NiCan_Set_WakeupMode(
	Alv_CAN_NiCan __instance,
	Alv_CAN_CanWakeupModes value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_NiCan_Get_BaudRate(
	Alv_CAN_NiCan __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_NiCan_Set_BaudRate(
	Alv_CAN_NiCan __instance,
	int value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_NiCan_Get_DriverID(
	Alv_CAN_NiCan __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_NiCan_Set_DriverID(
	Alv_CAN_NiCan __instance,
	char * value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_NiCan_Get_ClientID(
	Alv_CAN_NiCan __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_NiCan_Set_ClientID(
	Alv_CAN_NiCan __instance,
	char * value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_NiCan_Get_ReadTimeout(
	Alv_CAN_NiCan __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_NiCan_Set_ReadTimeout(
	Alv_CAN_NiCan __instance,
	int value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_NiCan_Get_WriteTimeout(
	Alv_CAN_NiCan __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_NiCan_Set_WriteTimeout(
	Alv_CAN_NiCan __instance,
	int value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_NiCan_Get_Error(
	Alv_CAN_NiCan __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_NiCan_Connect(
	Alv_CAN_NiCan __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_NiCan_Disconnect(
	Alv_CAN_NiCan __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_NiCan_Clear(
	Alv_CAN_NiCan __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_NiCan_Read(
	Alv_CAN_NiCan __instance,
	Alv_CAN_CanMsg * msg,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_NiCan_Write(
	Alv_CAN_NiCan __instance,
	Alv_CAN_CanMsg * msg,
	int * __returnValue,
	CDotNetHandle * __exception);

// Type: Alv.NarrowBand.HP_DIAG
int CVIFUNC Alv_NarrowBand_HP_DIAG__Create(
	Alv_NarrowBand_HP_DIAG * __instance,
	unsigned char * Data,
	ssize_t __DataLength,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_HP_State(
	Alv_NarrowBand_HP_DIAG __instance,
	Alv_NarrowBand_HP_DIAG_HP_States * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_Toggle_Flag(
	Alv_NarrowBand_HP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_Processor_Run_Mode(
	Alv_NarrowBand_HP_DIAG __instance,
	Alv_NarrowBand_HP_DIAG_HP_Run_Modes * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_Expected_DSP_State(
	Alv_NarrowBand_HP_DIAG __instance,
	Alv_NarrowBand_HP_DIAG_DSP_States * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_OEM_INCOMPATIBLE(
	Alv_NarrowBand_HP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_LOST_DSP_INFO_MESSAGE(
	Alv_NarrowBand_HP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_LOST_DSP_BSD_MESSAGE(
	Alv_NarrowBand_HP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_LOST_DSP_RCTA_MESSAGE(
	Alv_NarrowBand_HP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_HIGH_33_VOLT(
	Alv_NarrowBand_HP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_LOW_33_VOLT(
	Alv_NarrowBand_HP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_HIGH_19_VOLT(
	Alv_NarrowBand_HP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_LOW_19_VOLT(
	Alv_NarrowBand_HP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_DIAG_VIN_MISMATCH(
	Alv_NarrowBand_HP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_TEST_ROM_INIT_FAULT(
	Alv_NarrowBand_HP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_TEST_ROM_FAULT(
	Alv_NarrowBand_HP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_TEST_SENSOR_ADDRESS_UNSTABLE(
	Alv_NarrowBand_HP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_RESET_INTERNAL_WATCHDOG_TIMEOUT(
	Alv_NarrowBand_HP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_RESET_TASK_WATCHDOG_TIMEOUT(
	Alv_NarrowBand_HP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_RESET_OS_ERROR(
	Alv_NarrowBand_HP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_RESET_UNEXPECTED_EXCEPTION(
	Alv_NarrowBand_HP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_NCA_LOST_COMM_SBZA_L(
	Alv_NarrowBand_HP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_NCA_LOST_COMM_SBZA_R(
	Alv_NarrowBand_HP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_NCA_LOST_COMM_EOCM(
	Alv_NarrowBand_HP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_EEP_CAL_NOT_PROGRAMMED(
	Alv_NarrowBand_HP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_EEP_OUT_OF_ORDER(
	Alv_NarrowBand_HP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_EEP_CORRUPTED(
	Alv_NarrowBand_HP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_EEP_INCOMPATIBLE(
	Alv_NarrowBand_HP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_EEP_NOT_PROGRAMMED(
	Alv_NarrowBand_HP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_NCA_BUS_OFF(
	Alv_NarrowBand_HP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_NCA_LOST_COMM_BCM(
	Alv_NarrowBand_HP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_NCA_LOST_COMM_IPC(
	Alv_NarrowBand_HP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_NCA_LOST_COMM_HUD(
	Alv_NarrowBand_HP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_NCA_LOST_COMM_APA(
	Alv_NarrowBand_HP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_NCA_LOST_COMM_RADIO(
	Alv_NarrowBand_HP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_NCA_LOST_COMM_ONSTAR(
	Alv_NarrowBand_HP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_NCA_LOST_COMM_MSM(
	Alv_NarrowBand_HP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_IPC_BUS_OFF(
	Alv_NarrowBand_HP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_LOST_DSP_MESSAGE(
	Alv_NarrowBand_HP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_TEST_VOLT_BELOW_THRESHOLD(
	Alv_NarrowBand_HP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_TEST_VOLT_ABOVE_THRESHOLD(
	Alv_NarrowBand_HP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_LED_SHORT_TO_BATT(
	Alv_NarrowBand_HP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_LED_SHORT_TO_GROUND(
	Alv_NarrowBand_HP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_LED_OPEN_CIRCUIT(
	Alv_NarrowBand_HP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_NCA_INACTIVE_NODE(
	Alv_NarrowBand_HP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);

// Type: Alv.NarrowBand.UNT_DAT
int CVIFUNC Alv_NarrowBand_UNT_DAT__Create(
	Alv_NarrowBand_UNT_DAT * __instance,
	unsigned char * Data,
	ssize_t __DataLength,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_UNT_DAT_Get_Object_ID(
	Alv_NarrowBand_UNT_DAT __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_UNT_DAT_Get_Squinted_Beam_Antenna_Detection(
	Alv_NarrowBand_UNT_DAT __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_UNT_DAT_Get_Normal_Beam_Antenna_Detection(
	Alv_NarrowBand_UNT_DAT __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_UNT_DAT_Get_Relative_Distance(
	Alv_NarrowBand_UNT_DAT __instance,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_UNT_DAT_Get_Relative_Speed(
	Alv_NarrowBand_UNT_DAT __instance,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_UNT_DAT_Get_Azimuth(
	Alv_NarrowBand_UNT_DAT __instance,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_UNT_DAT_Get_Doppler_Data_SNR(
	Alv_NarrowBand_UNT_DAT __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_UNT_DAT_Get_Sensor_Mode(
	Alv_NarrowBand_UNT_DAT __instance,
	Alv_NarrowBand_NBProtocol_ControlRadarMode * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_UNT_DAT_Get_Range_Data_SNR(
	Alv_NarrowBand_UNT_DAT __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_UNT_DAT_ToString(
	Alv_NarrowBand_UNT_DAT __instance,
	char * delim,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_UNT_DAT_Header(
	char * delim,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: Alv.NarrowBand.NBProtocol
int CVIFUNC Alv_NarrowBand_NBProtocol__Get__UNDEF(
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_NBProtocol__Set__UNDEF(
	unsigned short UNDEF,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_NBProtocol__Get__RX_CAN_ID(
	unsigned short ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_NBProtocol__Set__RX_CAN_ID(
	unsigned short * RX_CAN_ID,
	ssize_t __RX_CAN_IDLength1,
	ssize_t __RX_CAN_IDLength2,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_NBProtocol__Get__TX_CAN_ID(
	unsigned short ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_NBProtocol__Set__TX_CAN_ID(
	unsigned short * TX_CAN_ID,
	ssize_t __TX_CAN_IDLength1,
	ssize_t __TX_CAN_IDLength2,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_NBProtocol__Get__U(
	unsigned char * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_NBProtocol__Set__U(
	unsigned char U,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_NBProtocol__Get__RX_CAN_LEN(
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_NBProtocol__Set__RX_CAN_LEN(
	unsigned char * RX_CAN_LEN,
	ssize_t __RX_CAN_LENLength,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_NBProtocol__Get__TX_CAN_LEN(
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_NBProtocol__Set__TX_CAN_LEN(
	unsigned char * TX_CAN_LEN,
	ssize_t __TX_CAN_LENLength,
	CDotNetHandle * __exception);

// Type: Alv.NarrowBand.DataPoint
int CVIFUNC Alv_NarrowBand_DataPoint__Create(
	Alv_NarrowBand_DataPoint * __instance,
	char * name,
	unsigned short point,
	Alv_NarrowBand_PointTypes type,
	unsigned short associated,
	float scaling,
	char * category,
	int readOnly,
	int secure,
	float lower,
	float upper,
	int dynamic,
	char * units,
	char * enumtype,
	Alv_NarrowBand_PointFormats format,
	char * description,
	char * calibration,
	unsigned short securitygroup,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoint_Get_Length(
	Alv_NarrowBand_DataPoint __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoint_Get_Name(
	Alv_NarrowBand_DataPoint __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoint_Get_Point(
	Alv_NarrowBand_DataPoint __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoint_Get_Type(
	Alv_NarrowBand_DataPoint __instance,
	Alv_NarrowBand_PointTypes * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoint_Get_Associated(
	Alv_NarrowBand_DataPoint __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoint_Get_Scaling(
	Alv_NarrowBand_DataPoint __instance,
	float * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoint_Get_Category(
	Alv_NarrowBand_DataPoint __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoint_Get_ReadOnly(
	Alv_NarrowBand_DataPoint __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoint_Get_Secure(
	Alv_NarrowBand_DataPoint __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoint_Get_StillSecure(
	Alv_NarrowBand_DataPoint __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoint_Set_StillSecure(
	Alv_NarrowBand_DataPoint __instance,
	int value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoint_Get_Lower(
	Alv_NarrowBand_DataPoint __instance,
	float * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoint_Get_Upper(
	Alv_NarrowBand_DataPoint __instance,
	float * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoint_Get_Dynamic(
	Alv_NarrowBand_DataPoint __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoint_Set_Dynamic(
	Alv_NarrowBand_DataPoint __instance,
	int value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoint_Get_Units(
	Alv_NarrowBand_DataPoint __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoint_Get_Format(
	Alv_NarrowBand_DataPoint __instance,
	Alv_NarrowBand_PointFormats * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoint_Set_Format(
	Alv_NarrowBand_DataPoint __instance,
	Alv_NarrowBand_PointFormats value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoint_Get_FormatOriginal(
	Alv_NarrowBand_DataPoint __instance,
	Alv_NarrowBand_PointFormats * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoint_Get_Description(
	Alv_NarrowBand_DataPoint __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoint_Get_Calibration(
	Alv_NarrowBand_DataPoint __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoint_Get_SecurityGroup(
	Alv_NarrowBand_DataPoint __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoint_Get_Enum(
	Alv_NarrowBand_DataPoint __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoint_Get_Bytes(
	Alv_NarrowBand_DataPoint __instance,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoint_Set_Bytes(
	Alv_NarrowBand_DataPoint __instance,
	unsigned char * value,
	ssize_t __valueLength,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoint_Get_DataDisplayStandard(
	Alv_NarrowBand_DataPoint __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoint_Get_Data(
	Alv_NarrowBand_DataPoint __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoint_Set_Data(
	Alv_NarrowBand_DataPoint __instance,
	char * value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoint_Get_Changed(
	Alv_NarrowBand_DataPoint __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoint_Set_Changed(
	Alv_NarrowBand_DataPoint __instance,
	int value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoint_Get_Status(
	Alv_NarrowBand_DataPoint __instance,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoint_Set_Status(
	Alv_NarrowBand_DataPoint __instance,
	Alv_NarrowBand_NBProtocol_Status value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoint_Get_EnumList(
	Alv_NarrowBand_DataPoint __instance,
	Alv_NarrowBand_Enumeration * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoint_Set_EnumList(
	Alv_NarrowBand_DataPoint __instance,
	Alv_NarrowBand_Enumeration value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoint_Get_Row(
	Alv_NarrowBand_DataPoint __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoint_Set_Row(
	Alv_NarrowBand_DataPoint __instance,
	int value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoint_Get_Valid(
	Alv_NarrowBand_DataPoint __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoint_Set_Valid(
	Alv_NarrowBand_DataPoint __instance,
	int value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoint_DataBytes(
	Alv_NarrowBand_DataPoint __instance,
	char * newdata,
	unsigned char ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DataPoint_ToString(
	Alv_NarrowBand_DataPoint __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: Alv.CAN.SoftingCan
int CVIFUNC Alv_CAN_SoftingCan__Create(
	Alv_CAN_SoftingCan * __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_SoftingCan_Get_DeviceType(
	Alv_CAN_SoftingCan __instance,
	Alv_CAN_CanDevices * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_SoftingCan_Get_BusMode(
	Alv_CAN_SoftingCan __instance,
	Alv_CAN_CanBusModes * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_SoftingCan_Set_BusMode(
	Alv_CAN_SoftingCan __instance,
	Alv_CAN_CanBusModes value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_SoftingCan_Get_WakeupMode(
	Alv_CAN_SoftingCan __instance,
	Alv_CAN_CanWakeupModes * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_SoftingCan_Set_WakeupMode(
	Alv_CAN_SoftingCan __instance,
	Alv_CAN_CanWakeupModes value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_SoftingCan_Get_BaudRate(
	Alv_CAN_SoftingCan __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_SoftingCan_Set_BaudRate(
	Alv_CAN_SoftingCan __instance,
	int value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_SoftingCan_Get_DriverID(
	Alv_CAN_SoftingCan __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_SoftingCan_Set_DriverID(
	Alv_CAN_SoftingCan __instance,
	char * value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_SoftingCan_Get_ClientID(
	Alv_CAN_SoftingCan __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_SoftingCan_Set_ClientID(
	Alv_CAN_SoftingCan __instance,
	char * value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_SoftingCan_Get_ReadTimeout(
	Alv_CAN_SoftingCan __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_SoftingCan_Set_ReadTimeout(
	Alv_CAN_SoftingCan __instance,
	int value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_SoftingCan_Get_WriteTimeout(
	Alv_CAN_SoftingCan __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_SoftingCan_Set_WriteTimeout(
	Alv_CAN_SoftingCan __instance,
	int value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_SoftingCan_Get_Error(
	Alv_CAN_SoftingCan __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_SoftingCan_Connect(
	Alv_CAN_SoftingCan __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_SoftingCan_Disconnect(
	Alv_CAN_SoftingCan __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_SoftingCan_Clear(
	Alv_CAN_SoftingCan __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_SoftingCan_Read(
	Alv_CAN_SoftingCan __instance,
	Alv_CAN_CanMsg * msg,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_CAN_SoftingCan_Write(
	Alv_CAN_SoftingCan __instance,
	Alv_CAN_CanMsg * msg,
	int * __returnValue,
	CDotNetHandle * __exception);

// Type: Alv.NarrowBand.Enumeration
int CVIFUNC Alv_NarrowBand_Enumeration__Create(
	Alv_NarrowBand_Enumeration * __instance,
	char * type,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_Enumeration_Get_Type(
	Alv_NarrowBand_Enumeration __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_Enumeration_Add(
	Alv_NarrowBand_Enumeration __instance,
	char * value,
	char * name,
	char * display,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_Enumeration_FindDisplay(
	Alv_NarrowBand_Enumeration __instance,
	int value,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: Alv.NarrowBand.DSP_DIAG
int CVIFUNC Alv_NarrowBand_DSP_DIAG__Create(
	Alv_NarrowBand_DSP_DIAG * __instance,
	unsigned char * Data,
	ssize_t __DataLength,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Sensor_Position(
	Alv_NarrowBand_DSP_DIAG __instance,
	Alv_NarrowBand_NBProtocol_Position * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Sensor_Fault(
	Alv_NarrowBand_DSP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Diagnostics_Summary(
	Alv_NarrowBand_DSP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_RAM_Fault(
	Alv_NarrowBand_DSP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Flash_Fault(
	Alv_NarrowBand_DSP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_EEPROM_Fault(
	Alv_NarrowBand_DSP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Power_Fault(
	Alv_NarrowBand_DSP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Watchdog_Tripped_Warning(
	Alv_NarrowBand_DSP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_A_D_Trigger_Fault(
	Alv_NarrowBand_DSP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_PLL_Unable_To_Lock_Fault(
	Alv_NarrowBand_DSP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Initialization_Fault(
	Alv_NarrowBand_DSP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Radar_Start_Fault(
	Alv_NarrowBand_DSP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Stack_Overflow_Warning(
	Alv_NarrowBand_DSP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Sensor_Over_Temperature_Warning(
	Alv_NarrowBand_DSP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_RX_MMIC_Fault(
	Alv_NarrowBand_DSP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_TX_MMIC_Fault(
	Alv_NarrowBand_DSP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Busy_Sending_DAQ_Data_Warning(
	Alv_NarrowBand_DSP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Bias_Check_Warning(
	Alv_NarrowBand_DSP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_A_D_Out_Of_Range_Warning(
	Alv_NarrowBand_DSP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_HP_Not_Responding_Fault(
	Alv_NarrowBand_DSP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_High_Rx_Noise_Warning(
	Alv_NarrowBand_DSP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Phase_Shifter_Warning(
	Alv_NarrowBand_DSP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_DC_Offset_Out_Of_Range_Warning(
	Alv_NarrowBand_DSP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Slow_Signal_Processing_Warning(
	Alv_NarrowBand_DSP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Parameters_Warning(
	Alv_NarrowBand_DSP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_I_CAN_Tx_Queue_Full_Warning(
	Alv_NarrowBand_DSP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Sweep_Discarded_Warning(
	Alv_NarrowBand_DSP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Sensor_Blockage_Fault(
	Alv_NarrowBand_DSP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Sensor_Interference_Fault(
	Alv_NarrowBand_DSP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Sensor_Misalignment_Fault(
	Alv_NarrowBand_DSP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Vehicle_Data_Stagnant_Warning(
	Alv_NarrowBand_DSP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_E_CAN_Tx_Queue_Full_Warning(
	Alv_NarrowBand_DSP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Config_Block_8_Invalid_Warning(
	Alv_NarrowBand_DSP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Config_Block_7_Invalid_Warning(
	Alv_NarrowBand_DSP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Config_Block_6_Invalid_Warning(
	Alv_NarrowBand_DSP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Config_Block_5_Invalid_Warning(
	Alv_NarrowBand_DSP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Config_Block_4_Invalid_Warning(
	Alv_NarrowBand_DSP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Config_Block_3_Invalid_Warning(
	Alv_NarrowBand_DSP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Config_Block_2_Invalid_Warning(
	Alv_NarrowBand_DSP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Config_Block_1_Invalid_Warning(
	Alv_NarrowBand_DSP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Blockage_Warning(
	Alv_NarrowBand_DSP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Incompatible_Hardware_Fault(
	Alv_NarrowBand_DSP_DIAG __instance,
	int * __returnValue,
	CDotNetHandle * __exception);

// Type: Alv.NbLib
int CVIFUNC Alv_NbLib_Get_Version(
	char ** __returnValue,
	CDotNetHandle * __exception);


#ifdef __cplusplus
}
#endif
