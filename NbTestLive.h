// CVI wrapper header file for .NET assembly: NbTest, Version=0.0.0.0, Culture=neutral, PublicKeyToken=null
//
// This is specified by the '__assemblyName' constant in the generated source file.
// If there are multiple versions of this assembly, and you want .NET to determine 
// the appropriate one to load, then you can remove the version, culture, and public 
// key token information from the constant and just specify the name of the assembly.
//
// Other assemblies referenced by the target assembly:
// Name: NbLib, Location: c:\NB_Alex - Copy\NbLib.dll
// Name: mscorlib, Location: C:\Windows\Microsoft.NET\Framework\v4.0.30319\mscorlib.dll
// Name: MathNet.Numerics, Location: c:\NB_Alex - Copy\MathNet.Numerics.dll
//
// If any assembly, including the target assembly, is not installed in the
// Global Assembly Cache (GAC) or in the application directory, and the wrapper
// code needs to load the assembly to convert types like arrays and enums, then
// you must register the path of the assembly with the CVI .NET library by
// calling CDotNetRegisterAssemblyPath before calling the wrapper code.
//
// Types exposed by the target assembly but defined in other assemblies:
// CVI name: Alv_NarrowBand_NBProtocol_StaticTestMode, .NET name: Alv.NarrowBand.NBProtocol+StaticTestMode, Assembly: NbLib, Module: c:\NB_Alex - Copy\NbLib.dll
// CVI name: System_Collections_Generic_IEnumerator_T1, .NET name: System.Collections.Generic.IEnumerator`1[[System.Numerics.Complex, MathNet.Numerics, Version=2.5.0.27, Culture=neutral, PublicKeyToken=null]], Assembly: mscorlib, Module: Global Assembly Cache
// CVI name: Alv_NarrowBand_UNT_DAT, .NET name: Alv.NarrowBand.UNT_DAT, Assembly: NbLib, Module: c:\NB_Alex - Copy\NbLib.dll
// CVI name: Alv_NarrowBand_NBProtocol_Status, .NET name: Alv.NarrowBand.NBProtocol+Status, Assembly: NbLib, Module: c:\NB_Alex - Copy\NbLib.dll
// CVI name: Alv_NarrowBand_NBProtocol_GearPosition, .NET name: Alv.NarrowBand.NBProtocol+GearPosition, Assembly: NbLib, Module: c:\NB_Alex - Copy\NbLib.dll
// CVI name: Alv_NarrowBand_DSP_DIAG, .NET name: Alv.NarrowBand.DSP_DIAG, Assembly: NbLib, Module: c:\NB_Alex - Copy\NbLib.dll
// CVI name: Alv_NarrowBand_NBProtocol_ConfigurationBlock, .NET name: Alv.NarrowBand.NBProtocol+ConfigurationBlock, Assembly: NbLib, Module: c:\NB_Alex - Copy\NbLib.dll
// CVI name: Alv_NarrowBand_NBProtocol_DCOffset, .NET name: Alv.NarrowBand.NBProtocol+DCOffset, Assembly: NbLib, Module: c:\NB_Alex - Copy\NbLib.dll
// CVI name: Alv_NarrowBand_NBProtocol_TestLED, .NET name: Alv.NarrowBand.NBProtocol+TestLED, Assembly: NbLib, Module: c:\NB_Alex - Copy\NbLib.dll
// CVI name: System_Collections_Generic_IEnumerable_T1, .NET name: System.Collections.Generic.IEnumerable`1[[System.Numerics.Complex, MathNet.Numerics, Version=2.5.0.27, Culture=neutral, PublicKeyToken=null]], Assembly: mscorlib, Module: Global Assembly Cache
// CVI name: Alv_NarrowBand_NBProtocol_Processor, .NET name: Alv.NarrowBand.NBProtocol+Processor, Assembly: NbLib, Module: c:\NB_Alex - Copy\NbLib.dll
// CVI name: Alv_NarrowBand_NBProtocol_Antenna, .NET name: Alv.NarrowBand.NBProtocol+Antenna, Assembly: NbLib, Module: c:\NB_Alex - Copy\NbLib.dll
// CVI name: Alv_NarrowBand_Sensor, .NET name: Alv.NarrowBand.Sensor, Assembly: NbLib, Module: c:\NB_Alex - Copy\NbLib.dll
// CVI name: System_Collections_Generic_IEnumerable_T1, .NET name: System.Collections.Generic.IEnumerable`1[[System.Double, mscorlib, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089]], Assembly: mscorlib, Module: Global Assembly Cache
// CVI name: System_DateTime, .NET name: System.DateTime, Assembly: mscorlib, Module: Global Assembly Cache
// CVI name: Alv_NarrowBand_NBProtocol_ControlRadarMode, .NET name: Alv.NarrowBand.NBProtocol+ControlRadarMode, Assembly: NbLib, Module: c:\NB_Alex - Copy\NbLib.dll
// CVI name: System_Numerics_Complex, .NET name: System.Numerics.Complex, Assembly: MathNet.Numerics, Module: c:\NB_Alex - Copy\MathNet.Numerics.dll
// CVI name: Alv_NarrowBand_HP_DIAG, .NET name: Alv.NarrowBand.HP_DIAG, Assembly: NbLib, Module: c:\NB_Alex - Copy\NbLib.dll

#include <cvidotnet.h>

#ifdef __cplusplus
extern "C" {
#endif

// Type definitions
typedef struct __Alv_Test_TxCalSettings * Alv_Test_TxCalSettings;
typedef struct __Alv_Test_TxCal * Alv_Test_TxCal;
typedef struct __Alv_Test_Mfg_MfgTests * Alv_Test_Mfg_MfgTests;
typedef struct __Alv_NarrowBand_Sensor * Alv_NarrowBand_Sensor;
typedef struct __Alv_Test_Mfg_MfgCoffinSettings * Alv_Test_Mfg_MfgCoffinSettings;
typedef struct __Alv_Test_Mfg_MfgCoffin * Alv_Test_Mfg_MfgCoffin;
typedef struct __Alv_Test_SensorState * Alv_Test_SensorState;
typedef struct __Alv_Test_SensorControl * Alv_Test_SensorControl;
typedef struct __Alv_NarrowBand_DSP_DIAG * Alv_NarrowBand_DSP_DIAG;
typedef struct __Alv_NarrowBand_HP_DIAG * Alv_NarrowBand_HP_DIAG;
typedef struct __Alv_NarrowBand_UNT_DAT * Alv_NarrowBand_UNT_DAT;
typedef struct __Alv_Test_Write * Alv_Test_Write;
typedef struct __Alv_Test_DataHeader * Alv_Test_DataHeader;
typedef struct __System_DateTime * System_DateTime;
typedef struct __Alv_Test_SensorFolder * Alv_Test_SensorFolder;
typedef struct __Alv_Test_PointDump * Alv_Test_PointDump;
typedef struct __Alv_Test_DataFile * Alv_Test_DataFile;
typedef struct __Alv_Test_Mfg_MfgTesterSettings * Alv_Test_Mfg_MfgTesterSettings;
typedef struct __Alv_Test_Mfg_MfgTester * Alv_Test_Mfg_MfgTester;
typedef struct __Alv_GPIB_VISA * Alv_GPIB_VISA;
typedef struct __Alv_GPIB_E3632A * Alv_GPIB_E3632A;
typedef struct __Alv_GPIB_N9010A * Alv_GPIB_N9010A;
typedef struct __Alv_GPIB_A11713 * Alv_GPIB_A11713;
typedef struct __Alv_Velmex_VXM * Alv_Velmex_VXM;
typedef struct __Alv_GPIB_RS_FSV * Alv_GPIB_RS_FSV;
typedef struct __Alv_Test_Wave * Alv_Test_Wave;
typedef struct __System_Collections_Generic_IEnumerable_T1 * System_Collections_Generic_IEnumerable_T1;
typedef struct __System_Numerics_Complex * System_Numerics_Complex;
typedef struct __System_Collections_Generic_IEnumerator_T1 * System_Collections_Generic_IEnumerator_T1;
typedef struct __System_Collections_Generic_IEnumerable_T1 * System_Collections_Generic_IEnumerable_T1;
typedef struct __Alv_MfgTest * Alv_MfgTest;
typedef struct __Ivi_Visa_Interop_FormattedIO488 * Ivi_Visa_Interop_FormattedIO488;
typedef struct __Ivi_Visa_Interop_IFormattedIO488 * Ivi_Visa_Interop_IFormattedIO488;
typedef struct __Ivi_Visa_Interop_IMessage * Ivi_Visa_Interop_IMessage;
typedef struct __Ivi_Visa_Interop_ResourceManager * Ivi_Visa_Interop_ResourceManager;
typedef struct __Ivi_Visa_Interop_IResourceManager3 * Ivi_Visa_Interop_IResourceManager3;
typedef struct __Ivi_Visa_Interop_IVisaSession * Ivi_Visa_Interop_IVisaSession;
typedef struct __Ivi_Visa_Interop_IBaseMessage * Ivi_Visa_Interop_IBaseMessage;
typedef struct __Ivi_Visa_Interop_IResourceManager * Ivi_Visa_Interop_IResourceManager;

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

// C wrapper for enumeration type Alv.Test.HardwareTypes
#ifndef Alv_Test_HardwareTypes_DEFINED
#define Alv_Test_HardwareTypes_DEFINED
typedef enum Alv_Test_HardwareTypes
{
	Alv_Test_HardwareTypes_Invalid = 0x0,
	Alv_Test_HardwareTypes_NB_7D00 = 0x1,
	Alv_Test_HardwareTypes_NB_7D01 = 0x2,
	Alv_Test_HardwareTypes_NB_7E00 = 0x3,
	Alv_Test_HardwareTypes_NB_1B00 = 0x4,
	Alv_Test_HardwareTypes_NB_2A00 = 0x5,
	Alv_Test_HardwareTypes_NB_1B01 = 0x6,
	Alv_Test_HardwareTypes_NB_1C00 = 0x7,
	Alv_Test_HardwareTypes_NB_2B00 = 0x8,
	Alv_Test_HardwareTypes_NB_1D00 = 0x9,
	Alv_Test_HardwareTypes_NB_1E00 = 0xa,
	Alv_Test_HardwareTypes_NB_2C00 = 0xb,
	Alv_Test_HardwareTypes_NB_2D00 = 0xc,
	Alv_Test_HardwareTypes_NB_9B00 = 0xd,
} Alv_Test_HardwareTypes;
#endif // Alv_Test_HardwareTypes_DEFINED

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

// C wrapper for enumeration type Alv.GPIB.N9010A+Traces
#ifndef Alv_GPIB_N9010A_Traces_DEFINED
#define Alv_GPIB_N9010A_Traces_DEFINED
typedef enum Alv_GPIB_N9010A_Traces
{
	Alv_GPIB_N9010A_Traces_Write = 0x0,
	Alv_GPIB_N9010A_Traces_Average = 0x1,
	Alv_GPIB_N9010A_Traces_Maxhold = 0x2,
	Alv_GPIB_N9010A_Traces_Minhold = 0x3,
} Alv_GPIB_N9010A_Traces;
#endif // Alv_GPIB_N9010A_Traces_DEFINED

// C wrapper for enumeration type Alv.GPIB.N9010A+Measurments
#ifndef Alv_GPIB_N9010A_Measurments_DEFINED
#define Alv_GPIB_N9010A_Measurments_DEFINED
typedef enum Alv_GPIB_N9010A_Measurments
{
	Alv_GPIB_N9010A_Measurments_SweptSA = 0x0,
	Alv_GPIB_N9010A_Measurments_ChannelPower = 0x1,
	Alv_GPIB_N9010A_Measurments_OccupiedBandwidth = 0x2,
	Alv_GPIB_N9010A_Measurments_ACP = 0x3,
	Alv_GPIB_N9010A_Measurments_PowerStatCCDF = 0x4,
	Alv_GPIB_N9010A_Measurments_BurstPower = 0x5,
	Alv_GPIB_N9010A_Measurments_SpuriousEmissions = 0x6,
	Alv_GPIB_N9010A_Measurments_SpectrumEmissionMask = 0x7,
	Alv_GPIB_N9010A_Measurments_TOI = 0x8,
	Alv_GPIB_N9010A_Measurments_Harmonic = 0x9,
	Alv_GPIB_N9010A_Measurments_ListSweep = 0xa,
} Alv_GPIB_N9010A_Measurments;
#endif // Alv_GPIB_N9010A_Measurments_DEFINED

// C wrapper for enumeration type Alv.GPIB.N9010A+Markers
#ifndef Alv_GPIB_N9010A_Markers_DEFINED
#define Alv_GPIB_N9010A_Markers_DEFINED
typedef enum Alv_GPIB_N9010A_Markers
{
	Alv_GPIB_N9010A_Markers_Normal = 0x0,
	Alv_GPIB_N9010A_Markers_Delta = 0x1,
	Alv_GPIB_N9010A_Markers_Fixed = 0x2,
	Alv_GPIB_N9010A_Markers_Off = 0x3,
} Alv_GPIB_N9010A_Markers;
#endif // Alv_GPIB_N9010A_Markers_DEFINED

// C wrapper for enumeration type Alv.GPIB.Insturments
#ifndef Alv_GPIB_Insturments_DEFINED
#define Alv_GPIB_Insturments_DEFINED
typedef enum Alv_GPIB_Insturments
{
	Alv_GPIB_Insturments_A1171s = 0x0,
	Alv_GPIB_Insturments_E3632A = 0x1,
	Alv_GPIB_Insturments_N5224A = 0x2,
	Alv_GPIB_Insturments_N9010A = 0x3,
	Alv_GPIB_Insturments_RS_FSV = 0x4,
	Alv_GPIB_Insturments_THJ80 = 0x5,
} Alv_GPIB_Insturments;
#endif // Alv_GPIB_Insturments_DEFINED

// C wrapper for enumeration type Alv.GPIB.RS_FSV+Traces
#ifndef Alv_GPIB_RS_FSV_Traces_DEFINED
#define Alv_GPIB_RS_FSV_Traces_DEFINED
typedef enum Alv_GPIB_RS_FSV_Traces
{
	Alv_GPIB_RS_FSV_Traces_WRITe = 0x0,
	Alv_GPIB_RS_FSV_Traces_MAXHold = 0x1,
} Alv_GPIB_RS_FSV_Traces;
#endif // Alv_GPIB_RS_FSV_Traces_DEFINED

// C wrapper for enumeration type Alv.GPIB.RS_FSV+Detectors
#ifndef Alv_GPIB_RS_FSV_Detectors_DEFINED
#define Alv_GPIB_RS_FSV_Detectors_DEFINED
typedef enum Alv_GPIB_RS_FSV_Detectors
{
	Alv_GPIB_RS_FSV_Detectors_PPEak = 0x0,
	Alv_GPIB_RS_FSV_Detectors_RMS = 0x1,
	Alv_GPIB_RS_FSV_Detectors_MEAN = 0x2,
	Alv_GPIB_RS_FSV_Detectors_SDEViation = 0x3,
} Alv_GPIB_RS_FSV_Detectors;
#endif // Alv_GPIB_RS_FSV_Detectors_DEFINED

// C wrapper for enumeration type Alv.GPIB.RS_FSV+Measurments
#ifndef Alv_GPIB_RS_FSV_Measurments_DEFINED
#define Alv_GPIB_RS_FSV_Measurments_DEFINED
typedef enum Alv_GPIB_RS_FSV_Measurments
{
	Alv_GPIB_RS_FSV_Measurments_ACPower = 0x0,
	Alv_GPIB_RS_FSV_Measurments_CPOwer = 0x1,
	Alv_GPIB_RS_FSV_Measurments_MCACpower = 0x2,
	Alv_GPIB_RS_FSV_Measurments_OBWidth = 0x3,
	Alv_GPIB_RS_FSV_Measurments_CN = 0x4,
	Alv_GPIB_RS_FSV_Measurments_CN0 = 0x5,
} Alv_GPIB_RS_FSV_Measurments;
#endif // Alv_GPIB_RS_FSV_Measurments_DEFINED

// C wrapper for enumeration type Ivi.Visa.Interop.IEEEASCIIType
#ifndef Ivi_Visa_Interop_IEEEASCIIType_DEFINED
#define Ivi_Visa_Interop_IEEEASCIIType_DEFINED
typedef enum Ivi_Visa_Interop_IEEEASCIIType
{
	Ivi_Visa_Interop_IEEEASCIIType_ASCIIType_I2 = 0x2,
	Ivi_Visa_Interop_IEEEASCIIType_ASCIIType_I4 = 0x3,
	Ivi_Visa_Interop_IEEEASCIIType_ASCIIType_R4 = 0x4,
	Ivi_Visa_Interop_IEEEASCIIType_ASCIIType_R8 = 0x5,
	Ivi_Visa_Interop_IEEEASCIIType_ASCIIType_BSTR = 0x8,
	Ivi_Visa_Interop_IEEEASCIIType_ASCIIType_Any = 0xc,
	Ivi_Visa_Interop_IEEEASCIIType_ASCIIType_UI1 = 0x11,
} Ivi_Visa_Interop_IEEEASCIIType;
#endif // Ivi_Visa_Interop_IEEEASCIIType_DEFINED

// C wrapper for enumeration type Ivi.Visa.Interop.AccessMode
#ifndef Ivi_Visa_Interop_AccessMode_DEFINED
#define Ivi_Visa_Interop_AccessMode_DEFINED
typedef enum Ivi_Visa_Interop_AccessMode
{
	Ivi_Visa_Interop_AccessMode_NO_LOCK = 0x0,
	Ivi_Visa_Interop_AccessMode_EXCLUSIVE_LOCK = 0x1,
	Ivi_Visa_Interop_AccessMode_SHARED_LOCK = 0x2,
	Ivi_Visa_Interop_AccessMode_LOAD_CONFIG = 0x4,
} Ivi_Visa_Interop_AccessMode;
#endif // Ivi_Visa_Interop_AccessMode_DEFINED




// Global Functions
int CVIFUNC Initialize_NbTest(void);
int CVIFUNC Close_NbTest(void);

// Type: Alv.Test.TxCalSettings
int CVIFUNC Alv_Test_TxCalSettings__Create(
	Alv_Test_TxCalSettings * __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_TxCalSettings_Load(
	Alv_Test_TxCalSettings __instance,
	char * path,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_TxCalSettings__Get__Enabled(
	Alv_Test_TxCalSettings __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_TxCalSettings__Set__Enabled(
	Alv_Test_TxCalSettings __instance,
	int Enabled,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_TxCalSettings__Get__GPIBInterface(
	Alv_Test_TxCalSettings __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_TxCalSettings__Set__GPIBInterface(
	Alv_Test_TxCalSettings __instance,
	int GPIBInterface,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_TxCalSettings__Get__PowerSupplyGPIB(
	Alv_Test_TxCalSettings __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_TxCalSettings__Set__PowerSupplyGPIB(
	Alv_Test_TxCalSettings __instance,
	int PowerSupplyGPIB,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_TxCalSettings__Get__ControlPower(
	Alv_Test_TxCalSettings __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_TxCalSettings__Set__ControlPower(
	Alv_Test_TxCalSettings __instance,
	int ControlPower,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_TxCalSettings__Get__SensorVoltage(
	Alv_Test_TxCalSettings __instance,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_TxCalSettings__Set__SensorVoltage(
	Alv_Test_TxCalSettings __instance,
	double SensorVoltage,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_TxCalSettings__Get__WarmupDelay(
	Alv_Test_TxCalSettings __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_TxCalSettings__Set__WarmupDelay(
	Alv_Test_TxCalSettings __instance,
	int WarmupDelay,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_TxCalSettings__Get__SwitchGPIB(
	Alv_Test_TxCalSettings __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_TxCalSettings__Set__SwitchGPIB(
	Alv_Test_TxCalSettings __instance,
	int SwitchGPIB,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_TxCalSettings__Get__AnalyzerGPIB(
	Alv_Test_TxCalSettings __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_TxCalSettings__Set__AnalyzerGPIB(
	Alv_Test_TxCalSettings __instance,
	int AnalyzerGPIB,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_TxCalSettings__Get__NestOffsets(
	Alv_Test_TxCalSettings __instance,
	double ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_TxCalSettings__Set__NestOffsets(
	Alv_Test_TxCalSettings __instance,
	double * NestOffsets,
	ssize_t __NestOffsetsLength,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_TxCalSettings__Get__PowerOffset(
	Alv_Test_TxCalSettings __instance,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_TxCalSettings__Set__PowerOffset(
	Alv_Test_TxCalSettings __instance,
	double PowerOffset,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_TxCalSettings__Get__Attenuation(
	Alv_Test_TxCalSettings __instance,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_TxCalSettings__Set__Attenuation(
	Alv_Test_TxCalSettings __instance,
	double Attenuation,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_TxCalSettings__Get__ReferenceLevel(
	Alv_Test_TxCalSettings __instance,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_TxCalSettings__Set__ReferenceLevel(
	Alv_Test_TxCalSettings __instance,
	double ReferenceLevel,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_TxCalSettings__Get__HornDistance(
	Alv_Test_TxCalSettings __instance,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_TxCalSettings__Set__HornDistance(
	Alv_Test_TxCalSettings __instance,
	double HornDistance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_TxCalSettings__Get__UseSwitch(
	Alv_Test_TxCalSettings __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_TxCalSettings__Set__UseSwitch(
	Alv_Test_TxCalSettings __instance,
	int UseSwitch,
	CDotNetHandle * __exception);

// Type: Alv.Test.TxCal
int CVIFUNC Alv_Test_TxCal__Create(
	Alv_Test_TxCal * __instance,
	char * settings_path,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_TxCal_Get_RfPath(
	Alv_Test_TxCal __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_TxCal_Set_RfPath(
	Alv_Test_TxCal __instance,
	int value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_TxCal_ConnectSpec(
	Alv_Test_TxCal __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_TxCal_ConnectSensorPower(
	Alv_Test_TxCal __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_TxCal_ConnectAttenuator(
	Alv_Test_TxCal __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_TxCal_ConnectAll(
	Alv_Test_TxCal __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_TxCal_CloseAll(
	Alv_Test_TxCal __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_TxCal_GetChannelPower(
	Alv_Test_TxCal __instance,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_TxCal_GetPeakPower(
	Alv_Test_TxCal __instance,
	int force,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_TxCal_GetCenterFrequency(
	Alv_Test_TxCal __instance,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_TxCal_GetOccupiedBW(
	Alv_Test_TxCal __instance,
	int hold_time,
	int span,
	int sweep_time,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_TxCal_SetOutput(
	Alv_Test_TxCal __instance,
	double voltage,
	double current,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_TxCal_ControlPower(
	Alv_Test_TxCal __instance,
	int on,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_TxCal_GetCurrent(
	Alv_Test_TxCal __instance,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_TxCal_GetVoltage(
	Alv_Test_TxCal __instance,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_TxCal__Get__settings(
	Alv_Test_TxCal __instance,
	Alv_Test_TxCalSettings * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_TxCal__Set__settings(
	Alv_Test_TxCal __instance,
	Alv_Test_TxCalSettings settings,
	CDotNetHandle * __exception);

// Type: Alv.Test.Mfg.MfgTests
int CVIFUNC Alv_Test_Mfg_MfgTests_Get_State(
	Alv_Test_Mfg_MfgTests __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTests_Get_Message(
	Alv_Test_Mfg_MfgTests __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTests_InitCoffin(
	Alv_Test_Mfg_MfgTests __instance,
	Alv_NarrowBand_Sensor comm,
	char * settings_path,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTests_InitTxCal(
	Alv_Test_Mfg_MfgTests __instance,
	Alv_NarrowBand_Sensor comm,
	char * settings_path,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTests_Connect(
	Alv_Test_Mfg_MfgTests __instance,
	char ** serial,
	char *** part_number,
	ssize_t * __part_numberLength,
	char *** sw_version,
	ssize_t * __sw_versionLength,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTests_Ping(
	Alv_Test_Mfg_MfgTests __instance,
	char ** serial,
	char *** part_number,
	ssize_t * __part_numberLength,
	char *** sw_version,
	ssize_t * __sw_versionLength,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTests_MakePath(
	Alv_Test_Mfg_MfgTests __instance,
	char * path,
	char * description,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTests_SetupData(
	Alv_Test_Mfg_MfgTests __instance,
	char * file_name,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTests_Disconnect(
	Alv_Test_Mfg_MfgTests __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTests_Supply_on(
	Alv_Test_Mfg_MfgTests __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTests_SelectRfRoute(
	Alv_Test_Mfg_MfgTests __instance,
	int route,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTests_DcOffsetInit(
	Alv_Test_Mfg_MfgTests __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTests_CenterFrequency(
	Alv_Test_Mfg_MfgTests __instance,
	Alv_NarrowBand_NBProtocol_Antenna antenna,
	double * frequency,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTests_CwLeakage(
	Alv_Test_Mfg_MfgTests __instance,
	Alv_NarrowBand_NBProtocol_Antenna antenna,
	double * leakage,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTests_OccupiedBW(
	Alv_Test_Mfg_MfgTests __instance,
	Alv_NarrowBand_NBProtocol_ControlRadarMode mode,
	int time,
	double * bandwidth,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTests_PointCheck(
	Alv_Test_Mfg_MfgTests __instance,
	int point,
	char * failval,
	char ** pointval,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTests_PointCheck_1(
	Alv_Test_Mfg_MfgTests __instance,
	int point,
	double max,
	double min,
	char ** pointval,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTests_DspErrorCheck(
	Alv_Test_Mfg_MfgTests __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTests_HpErrorCheck(
	Alv_Test_Mfg_MfgTests __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTests_IQCheckHonda(
	Alv_Test_Mfg_MfgTests __instance,
	double ** points,
	ssize_t * __pointsLength1,
	ssize_t * __pointsLength2,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTests_IQCheckGM(
	Alv_Test_Mfg_MfgTests __instance,
	double ** points,
	ssize_t * __pointsLength1,
	ssize_t * __pointsLength2,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTests_CurrentCheck(
	Alv_Test_Mfg_MfgTests __instance,
	double * current,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTests_SensorTemp(
	Alv_Test_Mfg_MfgTests __instance,
	double * board_temp,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTests_LEDTest(
	Alv_Test_Mfg_MfgTests __instance,
	double * led_current,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTests_NoiseArtifact(
	Alv_Test_Mfg_MfgTests __instance,
	int sweeps,
	int bin_length,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTests_BSDRangeCheck(
	Alv_Test_Mfg_MfgTests __instance,
	int count,
	double angle,
	double threshold,
	double * range,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTests_BlockageTest(
	Alv_Test_Mfg_MfgTests __instance,
	double * blockage,
	double * board_temp,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTests_SweepBSD(
	Alv_Test_Mfg_MfgTests __instance,
	double angle,
	Alv_NarrowBand_NBProtocol_Antenna antenna,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTests_SweepRCTA(
	Alv_Test_Mfg_MfgTests __instance,
	double angle,
	Alv_NarrowBand_NBProtocol_Antenna antenna,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTests_SweepLCA(
	Alv_Test_Mfg_MfgTests __instance,
	double angle,
	Alv_NarrowBand_NBProtocol_Antenna antenna,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTests_UntDatSweep(
	Alv_Test_Mfg_MfgTests __instance,
	Alv_NarrowBand_NBProtocol_ControlRadarMode mode,
	Alv_NarrowBand_NBProtocol_Antenna antenna,
	double angle,
	int count,
	double * azimuth,
	double * distance,
	double * speed,
	double * SNR,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTests_TxPower(
	Alv_Test_Mfg_MfgTests __instance,
	double * power,
	Alv_NarrowBand_NBProtocol_Antenna antenna,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTests_PowerAtAngle(
	Alv_Test_Mfg_MfgTests __instance,
	double angle,
	double ** power,
	ssize_t * __powerLength,
	double * board_temp,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTests_TxPowerCalHonda(
	Alv_Test_Mfg_MfgTests __instance,
	int gain_min,
	double pow_min,
	double pow_max,
	double * power,
	double ** points,
	ssize_t * __pointsLength1,
	ssize_t * __pointsLength2,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTests_IQCalHonda(
	Alv_Test_Mfg_MfgTests __instance,
	double ** points,
	ssize_t * __pointsLength1,
	ssize_t * __pointsLength2,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTests_AngleCalHonda(
	Alv_Test_Mfg_MfgTests __instance,
	int count,
	double ** points,
	ssize_t * __pointsLength1,
	ssize_t * __pointsLength2,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTests_BSDCalHonda(
	Alv_Test_Mfg_MfgTests __instance,
	int count,
	double angle,
	double threshold,
	double ** points,
	ssize_t * __pointsLength,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTests_TxPowerCalGM(
	Alv_Test_Mfg_MfgTests __instance,
	double pow_max_bsd,
	double pow_max_rcta,
	double pow_min_bsd,
	double pow_min_rcta,
	double ** power,
	ssize_t * __powerLength,
	unsigned short ** amp,
	ssize_t * __ampLength,
	unsigned short ** sw,
	ssize_t * __swLength,
	unsigned short ** pdet,
	ssize_t * __pdetLength,
	unsigned short * thermistor,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTests_IQCalGM(
	Alv_Test_Mfg_MfgTests __instance,
	double ** points,
	ssize_t * __pointsLength1,
	ssize_t * __pointsLength2,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTests_AngleCalGM(
	Alv_Test_Mfg_MfgTests __instance,
	int count,
	double MDA_start,
	double MDA_stop,
	double ** TrueAngles,
	ssize_t * __TrueAnglesLength,
	double ** measured_theta,
	ssize_t * __measured_thetaLength1,
	ssize_t * __measured_thetaLength2,
	CDotNetHandle * beam_formed_theta,
	CDotNetHandle * TableCalcPoints,
	CDotNetHandle * TableCalcValues,
	CDotNetHandle * TableTruePoints,
	CDotNetHandle * TableTrueValues,
	int * __returnValue,
	CDotNetHandle * __exception);

// Type: Alv.Test.Mfg.MfgCoffinSettings
int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Create(
	Alv_Test_Mfg_MfgCoffinSettings * __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings_Load(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	char * path,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Get__Enabled(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Set__Enabled(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	int Enabled,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Get__GPIBInterface(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Set__GPIBInterface(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	int GPIBInterface,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Get__PowerSupplyGPIB(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Set__PowerSupplyGPIB(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	int PowerSupplyGPIB,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Get__ControlPower(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Set__ControlPower(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	int ControlPower,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Get__SensorVoltage(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Set__SensorVoltage(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	double SensorVoltage,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Get__WarmupDelay(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Set__WarmupDelay(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	int WarmupDelay,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Get__UsePowerMeter(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Set__UsePowerMeter(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	int UsePowerMeter,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Get__PowerMeterGPIB(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Set__PowerMeterGPIB(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	int PowerMeterGPIB,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Get__PowerMeterOffset(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Set__PowerMeterOffset(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	double PowerMeterOffset,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Get__PowerSamples(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Set__PowerSamples(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	int PowerSamples,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Get__RfLength(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Set__RfLength(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	double RfLength,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Get__RangeWindow(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Set__RangeWindow(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	double RangeWindow,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Get__RangeBin(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Set__RangeBin(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	int RangeBin,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Get__LoadAngle(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Set__LoadAngle(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	double LoadAngle,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Get__LinearRange(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Set__LinearRange(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	double LinearRange,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Get__RehomeVelmex(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Set__RehomeVelmex(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	int RehomeVelmex,
	CDotNetHandle * __exception);

// Type: Alv.Test.Mfg.MfgCoffin
int CVIFUNC Alv_Test_Mfg_MfgCoffin__Create(
	Alv_Test_Mfg_MfgCoffin * __instance,
	char * settings_path,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffin_Get_LinSpeed(
	Alv_Test_Mfg_MfgCoffin __instance,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffin_Set_LinSpeed(
	Alv_Test_Mfg_MfgCoffin __instance,
	double value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffin_Get_AngSpeed(
	Alv_Test_Mfg_MfgCoffin __instance,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffin_Set_AngSpeed(
	Alv_Test_Mfg_MfgCoffin __instance,
	double value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffin_Get_Distance(
	Alv_Test_Mfg_MfgCoffin __instance,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffin_Set_Distance(
	Alv_Test_Mfg_MfgCoffin __instance,
	double value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffin_Get_Angle(
	Alv_Test_Mfg_MfgCoffin __instance,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffin_Set_Angle(
	Alv_Test_Mfg_MfgCoffin __instance,
	double value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffin_ConnectVelmex(
	Alv_Test_Mfg_MfgCoffin __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffin_ConnectSensorPower(
	Alv_Test_Mfg_MfgCoffin __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffin_ConnectPowerMeter(
	Alv_Test_Mfg_MfgCoffin __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffin_ConnectAll(
	Alv_Test_Mfg_MfgCoffin __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffin_CloseAll(
	Alv_Test_Mfg_MfgCoffin __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffin_SetLinMotion(
	Alv_Test_Mfg_MfgCoffin __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffin_StopMotion(
	Alv_Test_Mfg_MfgCoffin __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffin_LoadAngle(
	Alv_Test_Mfg_MfgCoffin __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffin_GetChannelPower(
	Alv_Test_Mfg_MfgCoffin __instance,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffin_SetOutput(
	Alv_Test_Mfg_MfgCoffin __instance,
	double voltage,
	double current,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffin_ControlPower(
	Alv_Test_Mfg_MfgCoffin __instance,
	int on,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffin_GetCurrent(
	Alv_Test_Mfg_MfgCoffin __instance,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffin_GetVoltage(
	Alv_Test_Mfg_MfgCoffin __instance,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffin__Get__settings(
	Alv_Test_Mfg_MfgCoffin __instance,
	Alv_Test_Mfg_MfgCoffinSettings * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgCoffin__Set__settings(
	Alv_Test_Mfg_MfgCoffin __instance,
	Alv_Test_Mfg_MfgCoffinSettings settings,
	CDotNetHandle * __exception);

// Type: Alv.Test.SensorState
int CVIFUNC Alv_Test_SensorState__Create(
	Alv_Test_SensorState * __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorState__Get__CwMode(
	Alv_Test_SensorState __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorState__Set__CwMode(
	Alv_Test_SensorState __instance,
	int CwMode,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorState__Get__Antenna(
	Alv_Test_SensorState __instance,
	Alv_NarrowBand_NBProtocol_Antenna * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorState__Set__Antenna(
	Alv_Test_SensorState __instance,
	Alv_NarrowBand_NBProtocol_Antenna Antenna,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorState__Get__RF(
	Alv_Test_SensorState __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorState__Set__RF(
	Alv_Test_SensorState __instance,
	int RF,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorState__Get__RadarRx(
	Alv_Test_SensorState __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorState__Set__RadarRx(
	Alv_Test_SensorState __instance,
	int RadarRx,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorState__Get__DCOffset(
	Alv_Test_SensorState __instance,
	Alv_NarrowBand_NBProtocol_DCOffset * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorState__Set__DCOffset(
	Alv_Test_SensorState __instance,
	Alv_NarrowBand_NBProtocol_DCOffset DCOffset,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorState__Get__StaticTestMode(
	Alv_Test_SensorState __instance,
	Alv_NarrowBand_NBProtocol_StaticTestMode * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorState__Set__StaticTestMode(
	Alv_Test_SensorState __instance,
	Alv_NarrowBand_NBProtocol_StaticTestMode StaticTestMode,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorState__Get__PulseJitter(
	Alv_Test_SensorState __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorState__Set__PulseJitter(
	Alv_Test_SensorState __instance,
	int PulseJitter,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorState__Get__RadarMode(
	Alv_Test_SensorState __instance,
	Alv_NarrowBand_NBProtocol_ControlRadarMode * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorState__Set__RadarMode(
	Alv_Test_SensorState __instance,
	Alv_NarrowBand_NBProtocol_ControlRadarMode RadarMode,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorState__Get__EngineeringMode(
	Alv_Test_SensorState __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorState__Set__EngineeringMode(
	Alv_Test_SensorState __instance,
	int EngineeringMode,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorState__Get__TempComp(
	Alv_Test_SensorState __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorState__Set__TempComp(
	Alv_Test_SensorState __instance,
	int TempComp,
	CDotNetHandle * __exception);

// Type: Alv.Test.SensorControl
int CVIFUNC Alv_Test_SensorControl__Create(
	Alv_Test_SensorControl * __instance,
	Alv_NarrowBand_Sensor Communicator,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_Get_Status(
	Alv_Test_SensorControl __instance,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_Get_CwMode(
	Alv_Test_SensorControl __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_Set_CwMode(
	Alv_Test_SensorControl __instance,
	int value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_Get_Antenna(
	Alv_Test_SensorControl __instance,
	Alv_NarrowBand_NBProtocol_Antenna * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_Set_Antenna(
	Alv_Test_SensorControl __instance,
	Alv_NarrowBand_NBProtocol_Antenna value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_Get_RF(
	Alv_Test_SensorControl __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_Set_RF(
	Alv_Test_SensorControl __instance,
	int value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_Get_RadarRx(
	Alv_Test_SensorControl __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_Set_RadarRx(
	Alv_Test_SensorControl __instance,
	int value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_Get_HardwareOffset(
	Alv_Test_SensorControl __instance,
	Alv_NarrowBand_NBProtocol_DCOffset * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_Set_HardwareOffset(
	Alv_Test_SensorControl __instance,
	Alv_NarrowBand_NBProtocol_DCOffset value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_Get_SoftwareOffset(
	Alv_Test_SensorControl __instance,
	Alv_NarrowBand_NBProtocol_DCOffset * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_Set_SoftwareOffset(
	Alv_Test_SensorControl __instance,
	Alv_NarrowBand_NBProtocol_DCOffset value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_Get_StaticTestMode(
	Alv_Test_SensorControl __instance,
	Alv_NarrowBand_NBProtocol_StaticTestMode * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_Set_StaticTestMode(
	Alv_Test_SensorControl __instance,
	Alv_NarrowBand_NBProtocol_StaticTestMode value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_Get_PulseJitter(
	Alv_Test_SensorControl __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_Set_PulseJitter(
	Alv_Test_SensorControl __instance,
	int value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_Get_RadarMode(
	Alv_Test_SensorControl __instance,
	Alv_NarrowBand_NBProtocol_ControlRadarMode * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_Set_RadarMode(
	Alv_Test_SensorControl __instance,
	Alv_NarrowBand_NBProtocol_ControlRadarMode value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_Get_EngineeringMode(
	Alv_Test_SensorControl __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_Set_EngineeringMode(
	Alv_Test_SensorControl __instance,
	int value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_Get_TempComp(
	Alv_Test_SensorControl __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_Set_TempComp(
	Alv_Test_SensorControl __instance,
	int value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_Get_Serial(
	Alv_Test_SensorControl __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_Get_Architecture(
	Alv_Test_SensorControl __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_Get_HardwareType(
	Alv_Test_SensorControl __instance,
	Alv_Test_HardwareTypes * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_Get_HpAppVersion(
	Alv_Test_SensorControl __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_Get_HpBootVersion(
	Alv_Test_SensorControl __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_Get_DspAppVersion(
	Alv_Test_SensorControl __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_Get_DspBootVersion(
	Alv_Test_SensorControl __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_Clear(
	Alv_Test_SensorControl __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_GetComm(
	Alv_Test_SensorControl __instance,
	Alv_NarrowBand_Sensor * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_GetSerial(
	Alv_Test_SensorControl __instance,
	char ** serial,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_GetArchitecture(
	Alv_Test_SensorControl __instance,
	char ** arch,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_GetHwType(
	Alv_Test_SensorControl __instance,
	unsigned short * rev,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_GetPartNumber(
	Alv_Test_SensorControl __instance,
	char *** part_number,
	ssize_t * __part_numberLength,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_GetSwVersion(
	Alv_Test_SensorControl __instance,
	char *** sw_version,
	ssize_t * __sw_versionLength,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_GetSwVersion_1(
	Alv_Test_SensorControl __instance,
	char ** HpApp,
	char ** HpBoot,
	char ** DspApp,
	char ** DspBoot,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_GetPointsVersion(
	Alv_Test_SensorControl __instance,
	char *** point_version,
	ssize_t * __point_versionLength,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_SaveConfiguration(
	Alv_Test_SensorControl __instance,
	Alv_NarrowBand_NBProtocol_ConfigurationBlock block,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_ReloadConfiguration(
	Alv_Test_SensorControl __instance,
	Alv_NarrowBand_NBProtocol_ConfigurationBlock block,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_ResetConfiguration(
	Alv_Test_SensorControl __instance,
	Alv_NarrowBand_NBProtocol_ConfigurationBlock block,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_ResetProcessor(
	Alv_Test_SensorControl __instance,
	Alv_NarrowBand_NBProtocol_Processor processor,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_ControlLED(
	Alv_Test_SensorControl __instance,
	Alv_NarrowBand_NBProtocol_Processor processor,
	Alv_NarrowBand_NBProtocol_TestLED control,
	unsigned short interval,
	unsigned short timeOut,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_PerformSelfTest(
	Alv_Test_SensorControl __instance,
	Alv_NarrowBand_NBProtocol_Processor processor,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_RunOffsetInitialization(
	Alv_Test_SensorControl __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_RawSweepBroadcast(
	Alv_Test_SensorControl __instance,
	Alv_NarrowBand_NBProtocol_Processor processor,
	unsigned char control,
	unsigned short count,
	unsigned char type,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_ReadManufacturingData(
	Alv_Test_SensorControl __instance,
	unsigned char ** data,
	ssize_t * __dataLength,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_GetPoint(
	Alv_Test_SensorControl __instance,
	unsigned short point,
	unsigned int * value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_GetPoint_1(
	Alv_Test_SensorControl __instance,
	unsigned short point,
	unsigned short * value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_GetPoint_2(
	Alv_Test_SensorControl __instance,
	unsigned short point,
	int * value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_GetPoint_3(
	Alv_Test_SensorControl __instance,
	unsigned short point,
	double * value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_GetPoint_4(
	Alv_Test_SensorControl __instance,
	unsigned short point,
	char ** value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_SetPoint(
	Alv_Test_SensorControl __instance,
	unsigned short point,
	CDotNetHandle value,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_GetSweep(
	Alv_Test_SensorControl __instance,
	CDotNetHandle * sweep_data,
	unsigned short count,
	Alv_NarrowBand_NBProtocol_ControlRadarMode mode,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_SetLiveGain(
	Alv_Test_SensorControl __instance,
	unsigned short amp,
	unsigned short sw,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_RestoreLiveGain(
	Alv_Test_SensorControl __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_GetCalGain(
	Alv_Test_SensorControl __instance,
	Alv_NarrowBand_NBProtocol_Antenna antenna,
	Alv_NarrowBand_NBProtocol_ControlRadarMode mode,
	unsigned short * amp,
	unsigned short * sw,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_SetCalGain(
	Alv_Test_SensorControl __instance,
	Alv_NarrowBand_NBProtocol_Antenna antenna,
	Alv_NarrowBand_NBProtocol_ControlRadarMode mode,
	unsigned short amp,
	unsigned short sw,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_ClearQueue(
	Alv_Test_SensorControl __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_ReadDspDiag(
	Alv_Test_SensorControl __instance,
	Alv_NarrowBand_DSP_DIAG * msg,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_ReadHpDiag(
	Alv_Test_SensorControl __instance,
	Alv_NarrowBand_HP_DIAG * msg,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_ReadUntDat(
	Alv_Test_SensorControl __instance,
	Alv_NarrowBand_UNT_DAT * msg,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_SendVehicleSpeed(
	Alv_Test_SensorControl __instance,
	unsigned int speed,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl_SendGearPosition(
	Alv_Test_SensorControl __instance,
	Alv_NarrowBand_NBProtocol_GearPosition gear,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl__Get__StateControl(
	Alv_Test_SensorControl __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl__Set__StateControl(
	Alv_Test_SensorControl __instance,
	int StateControl,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl__Get__Attempts(
	Alv_Test_SensorControl __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorControl__Set__Attempts(
	Alv_Test_SensorControl __instance,
	int Attempts,
	CDotNetHandle * __exception);

// Type: Alv.Test.Write
int CVIFUNC Alv_Test_Write_Antenna(
	Alv_NarrowBand_NBProtocol_Antenna antenna,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Write_Mode(
	Alv_NarrowBand_NBProtocol_ControlRadarMode mode,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Write_STM(
	Alv_NarrowBand_NBProtocol_StaticTestMode mode,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Write_UntDat(
	Alv_NarrowBand_UNT_DAT msg,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Write_UntDat_1(
	Alv_NarrowBand_UNT_DAT * msgs,
	ssize_t __msgsLength,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Write_WaveData(
	Alv_Test_Wave * waves,
	ssize_t __wavesLength,
	double * kaiser_taps,
	ssize_t __kaiser_tapsLength,
	int pad_len,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Write_WaveData_1(
	Alv_Test_Wave * waves,
	ssize_t __wavesLength,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: Alv.Test.DataHeader
int CVIFUNC Alv_Test_DataHeader__Create(
	Alv_Test_DataHeader * __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_DataHeader_Get_TimeStamp(
	Alv_Test_DataHeader __instance,
	System_DateTime * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_DataHeader_Get_HostId(
	Alv_Test_DataHeader __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_DataHeader_Get_TestPlan(
	Alv_Test_DataHeader __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_DataHeader_Get_DataPath(
	Alv_Test_DataHeader __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_DataHeader_Get_Serial(
	Alv_Test_DataHeader __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_DataHeader_Get_Architecture(
	Alv_Test_DataHeader __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_DataHeader_Get_HardwareType(
	Alv_Test_DataHeader __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_DataHeader_Get_HpAppVersion(
	Alv_Test_DataHeader __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_DataHeader_Get_HpBootVersion(
	Alv_Test_DataHeader __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_DataHeader_Get_DspAppVersion(
	Alv_Test_DataHeader __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_DataHeader_Get_DspBootVersion(
	Alv_Test_DataHeader __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_DataHeader_Clear(
	Alv_Test_DataHeader __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_DataHeader_Load(
	Alv_Test_DataHeader __instance,
	Alv_NarrowBand_Sensor s,
	char * test_plan,
	char * data_path,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_DataHeader_Write(
	Alv_Test_DataHeader __instance,
	char * delim,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: Alv.Test.SensorFolder
int CVIFUNC Alv_Test_SensorFolder__Create(
	Alv_Test_SensorFolder * __instance,
	char * path,
	Alv_Test_DataHeader header,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorFolder_SetupData(
	Alv_Test_SensorFolder __instance,
	char * file_name,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorFolder_Close(
	Alv_Test_SensorFolder __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorFolder_MakeFileUnique(
	char * filename,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorFolder__Get__Stats(
	Alv_Test_SensorFolder __instance,
	Alv_Test_DataFile * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorFolder__Set__Stats(
	Alv_Test_SensorFolder __instance,
	Alv_Test_DataFile Stats,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorFolder__Get__Data(
	Alv_Test_SensorFolder __instance,
	Alv_Test_DataFile * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorFolder__Set__Data(
	Alv_Test_SensorFolder __instance,
	Alv_Test_DataFile Data,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorFolder__Get__CalPoints(
	Alv_Test_SensorFolder __instance,
	Alv_Test_PointDump * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorFolder__Set__CalPoints(
	Alv_Test_SensorFolder __instance,
	Alv_Test_PointDump CalPoints,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_SensorFolder__Get__root_path(
	Alv_Test_SensorFolder __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: Alv.Test.PointDump
int CVIFUNC Alv_Test_PointDump__Create(
	Alv_Test_PointDump * __instance,
	char * path,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_PointDump_Get_FileName(
	Alv_Test_PointDump __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_PointDump_PointRead(
	Alv_Test_PointDump __instance,
	unsigned short point,
	char ** value,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_PointDump_PointWrite(
	Alv_Test_PointDump __instance,
	unsigned short point,
	char * value,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_PointDump_PointWrite_1(
	Alv_Test_PointDump __instance,
	unsigned short point,
	int value,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_PointDump_PointWrite_2(
	Alv_Test_PointDump __instance,
	unsigned short point,
	unsigned int value,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_PointDump_PointWrite_3(
	Alv_Test_PointDump __instance,
	unsigned short point,
	double value,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_PointDump_PointWrite_4(
	Alv_Test_PointDump __instance,
	unsigned short point,
	unsigned short value,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_PointDump__Get__ext(
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: Alv.Test.DataFile
int CVIFUNC Alv_Test_DataFile__Create(
	Alv_Test_DataFile * __instance,
	char * path,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_DataFile_Get_FileName(
	Alv_Test_DataFile __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_DataFile_Close(
	Alv_Test_DataFile __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_DataFile_WriteLine(
	Alv_Test_DataFile __instance,
	CDotNetHandle item,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_DataFile_WriteLine_1(
	Alv_Test_DataFile __instance,
	CDotNetHandle * items,
	ssize_t __itemsLength,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_DataFile_Write(
	Alv_Test_DataFile __instance,
	CDotNetHandle item,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_DataFile_Write_1(
	Alv_Test_DataFile __instance,
	CDotNetHandle * items,
	ssize_t __itemsLength,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_DataFile__Get__delim(
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_DataFile__Get__ext(
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: Alv.Test.Mfg.MfgTesterSettings
int CVIFUNC Alv_Test_Mfg_MfgTesterSettings__Create(
	Alv_Test_Mfg_MfgTesterSettings * __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTesterSettings_Load(
	Alv_Test_Mfg_MfgTesterSettings __instance,
	char * path,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTesterSettings__Get__Enabled(
	Alv_Test_Mfg_MfgTesterSettings __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTesterSettings__Set__Enabled(
	Alv_Test_Mfg_MfgTesterSettings __instance,
	int Enabled,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTesterSettings__Get__LogFile(
	Alv_Test_Mfg_MfgTesterSettings __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTesterSettings__Set__LogFile(
	Alv_Test_Mfg_MfgTesterSettings __instance,
	char * LogFile,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTesterSettings__Get__FirPath(
	Alv_Test_Mfg_MfgTesterSettings __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTesterSettings__Set__FirPath(
	Alv_Test_Mfg_MfgTesterSettings __instance,
	char * FirPath,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTesterSettings__Get__StateControl(
	Alv_Test_Mfg_MfgTesterSettings __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTesterSettings__Set__StateControl(
	Alv_Test_Mfg_MfgTesterSettings __instance,
	int StateControl,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTesterSettings__Get__LogEngData(
	Alv_Test_Mfg_MfgTesterSettings __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTesterSettings__Set__LogEngData(
	Alv_Test_Mfg_MfgTesterSettings __instance,
	int LogEngData,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTesterSettings__Get__CommAttempts(
	Alv_Test_Mfg_MfgTesterSettings __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTesterSettings__Set__CommAttempts(
	Alv_Test_Mfg_MfgTesterSettings __instance,
	int CommAttempts,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTesterSettings__Get__KaiserAlpha(
	Alv_Test_Mfg_MfgTesterSettings __instance,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTesterSettings__Set__KaiserAlpha(
	Alv_Test_Mfg_MfgTesterSettings __instance,
	double KaiserAlpha,
	CDotNetHandle * __exception);

// Type: Alv.Test.Mfg.MfgTester
int CVIFUNC Alv_Test_Mfg_MfgTester__Create(
	Alv_Test_Mfg_MfgTester * __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTester_Get_State(
	Alv_Test_Mfg_MfgTester __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTester_Get_Message(
	Alv_Test_Mfg_MfgTester __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTester_InitCoffin(
	Alv_Test_Mfg_MfgTester __instance,
	Alv_NarrowBand_Sensor comm,
	char * settings_path,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTester_InitCoffin_No_Velmex(
	Alv_Test_Mfg_MfgTester __instance,
	Alv_NarrowBand_Sensor comm,
	char * settings_path,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTester_InitTxCal(
	Alv_Test_Mfg_MfgTester __instance,
	Alv_NarrowBand_Sensor comm,
	char * settings_path,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTester_DcOffsetInit(
	Alv_Test_Mfg_MfgTester __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTester_RotateVelmex(
	Alv_Test_Mfg_MfgTester __instance,
	double angle,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTester_ReHomeVelmex(
	Alv_Test_Mfg_MfgTester __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTester_Setup(
	Alv_Test_Mfg_MfgTester __instance,
	double angle,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTester_Supply_on(
	Alv_Test_Mfg_MfgTester __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTester_readCurrent(
	Alv_Test_Mfg_MfgTester __instance,
	double * current,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTester_SelectRfRoute(
	Alv_Test_Mfg_MfgTester __instance,
	int route,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTester_Ping(
	Alv_Test_Mfg_MfgTester __instance,
	char ** serial,
	char ** part_number0,
	char ** part_number1,
	char ** part_number2,
	char ** part_number3,
	char ** sw_version0,
	char ** sw_version1,
	char ** sw_version2,
	char ** sw_version3,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTester_Ping_1(
	Alv_Test_Mfg_MfgTester __instance,
	char ** serial,
	char *** part_number,
	ssize_t * __part_numberLength,
	char *** sw_version,
	ssize_t * __sw_versionLength,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTester_Connect(
	Alv_Test_Mfg_MfgTester __instance,
	char ** serial,
	char *** part_number,
	ssize_t * __part_numberLength,
	char *** sw_version,
	ssize_t * __sw_versionLength,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTester_Disconnect(
	Alv_Test_Mfg_MfgTester __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTester_Disconnect_TxCal(
	Alv_Test_Mfg_MfgTester __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTester_MakePath(
	Alv_Test_Mfg_MfgTester __instance,
	char * path,
	char * description,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTester_SetupData(
	Alv_Test_Mfg_MfgTester __instance,
	char * file_name,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTester_CloseData(
	Alv_Test_Mfg_MfgTester __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTester_CenterFrequency(
	Alv_Test_Mfg_MfgTester __instance,
	Alv_NarrowBand_NBProtocol_Antenna antenna,
	double * frequency,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTester_CwLeakage(
	Alv_Test_Mfg_MfgTester __instance,
	Alv_NarrowBand_NBProtocol_Antenna antenna,
	double * leakage,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTester_OccupiedBW(
	Alv_Test_Mfg_MfgTester __instance,
	Alv_NarrowBand_NBProtocol_ControlRadarMode mode,
	int time,
	double * bandwidth,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTester_PointCheck(
	Alv_Test_Mfg_MfgTester __instance,
	int point,
	char * failval,
	char ** pointval,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTester_PointCheck_1(
	Alv_Test_Mfg_MfgTester __instance,
	int point,
	double max,
	double min,
	char ** pointval,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTester_DspErrorCheck(
	Alv_Test_Mfg_MfgTester __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTester_HpErrorCheck(
	Alv_Test_Mfg_MfgTester __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTester_CurrentCheck(
	Alv_Test_Mfg_MfgTester __instance,
	double * current,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTester_SensorTemp(
	Alv_Test_Mfg_MfgTester __instance,
	double * board_temp,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTester_IQCheckHonda(
	Alv_Test_Mfg_MfgTester __instance,
	double ** points,
	ssize_t * __pointsLength1,
	ssize_t * __pointsLength2,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTester_IQCheckGM(
	Alv_Test_Mfg_MfgTester __instance,
	double ** points,
	ssize_t * __pointsLength1,
	ssize_t * __pointsLength2,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTester_LEDTest(
	Alv_Test_Mfg_MfgTester __instance,
	double * led_current,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTester_NoiseArtifact(
	Alv_Test_Mfg_MfgTester __instance,
	int sweeps,
	int bin_length,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTester_BlockageTest(
	Alv_Test_Mfg_MfgTester __instance,
	double * blockage,
	double * board_temp,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTester_FalseAlarm(
	Alv_Test_Mfg_MfgTester __instance,
	double ** dac_values,
	ssize_t * __dac_valuesLength,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTester_BSDRangeCheck(
	Alv_Test_Mfg_MfgTester __instance,
	int count,
	double * range,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTester_BSDRangeCheck_1(
	Alv_Test_Mfg_MfgTester __instance,
	int count,
	double angle,
	double threshold,
	double * range,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTester_TxPower(
	Alv_Test_Mfg_MfgTester __instance,
	double * power,
	Alv_NarrowBand_NBProtocol_Antenna antenna,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTester_SweepBSD(
	Alv_Test_Mfg_MfgTester __instance,
	double angle,
	Alv_NarrowBand_NBProtocol_Antenna antenna,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTester_SweepRCTA(
	Alv_Test_Mfg_MfgTester __instance,
	double angle,
	Alv_NarrowBand_NBProtocol_Antenna antenna,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTester_SweepLCA(
	Alv_Test_Mfg_MfgTester __instance,
	double angle,
	Alv_NarrowBand_NBProtocol_Antenna antenna,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTester_UntDatSweep(
	Alv_Test_Mfg_MfgTester __instance,
	Alv_NarrowBand_NBProtocol_ControlRadarMode mode,
	Alv_NarrowBand_NBProtocol_Antenna antenna,
	double angle,
	int count,
	double * azimuth,
	double * distance,
	double * speed,
	double * SNR,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTester_PowerAtAngle(
	Alv_Test_Mfg_MfgTester __instance,
	double angle,
	double ** power,
	ssize_t * __powerLength,
	double * board_temp,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTester_TxPowerCalHonda(
	Alv_Test_Mfg_MfgTester __instance,
	int gain_min,
	double pow_min,
	double pow_max,
	double ** points,
	ssize_t * __pointsLength1,
	ssize_t * __pointsLength2,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTester_TxPowerCalHonda_1(
	Alv_Test_Mfg_MfgTester __instance,
	int gain_min,
	double pow_min,
	double pow_max,
	double * power,
	double ** points,
	ssize_t * __pointsLength1,
	ssize_t * __pointsLength2,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTester_IQCalHonda(
	Alv_Test_Mfg_MfgTester __instance,
	double ** points,
	ssize_t * __pointsLength1,
	ssize_t * __pointsLength2,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTester_AngleCalHonda(
	Alv_Test_Mfg_MfgTester __instance,
	int count,
	double ** points,
	ssize_t * __pointsLength1,
	ssize_t * __pointsLength2,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTester_BSDCalHonda(
	Alv_Test_Mfg_MfgTester __instance,
	int count,
	double ** points,
	ssize_t * __pointsLength,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTester_BSDCalHonda_1(
	Alv_Test_Mfg_MfgTester __instance,
	int count,
	double angle,
	double threshold,
	double ** points,
	ssize_t * __pointsLength,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTester_TxPowerCalGM(
	Alv_Test_Mfg_MfgTester __instance,
	double pow_max_bsd,
	double pow_max_rcta,
	double pow_min_bsd,
	double pow_min_rcta,
	double ** power,
	ssize_t * __powerLength,
	unsigned short ** amp,
	ssize_t * __ampLength,
	unsigned short ** sw,
	ssize_t * __swLength,
	unsigned short ** pdet,
	ssize_t * __pdetLength,
	unsigned short * thermistor,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTester_IQCalGM(
	Alv_Test_Mfg_MfgTester __instance,
	double ** points,
	ssize_t * __pointsLength1,
	ssize_t * __pointsLength2,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Mfg_MfgTester_AngleCalGM(
	Alv_Test_Mfg_MfgTester __instance,
	int count,
	double MDA_start,
	double MDA_stop,
	double ** TrueAngles,
	ssize_t * __TrueAnglesLength,
	double ** measured_theta,
	ssize_t * __measured_thetaLength1,
	ssize_t * __measured_thetaLength2,
	CDotNetHandle * beam_formed_theta,
	CDotNetHandle * TableCalcPoints,
	CDotNetHandle * TableCalcValues,
	CDotNetHandle * TableTruePoints,
	CDotNetHandle * TableTrueValues,
	int * __returnValue,
	CDotNetHandle * __exception);

// Type: Alv.GPIB.VISA
int CVIFUNC Alv_GPIB_VISA__Create(
	Alv_GPIB_VISA * __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_VISA_Connect(
	Alv_GPIB_VISA __instance,
	int GPIB,
	int Device_ID,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_VISA_Close(
	Alv_GPIB_VISA __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_VISA_ResetState(
	Alv_GPIB_VISA __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_VISA_Calibrate(
	Alv_GPIB_VISA __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_VISA_Identification(
	Alv_GPIB_VISA __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_VISA_Ready(
	Alv_GPIB_VISA __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_VISA_Recall(
	Alv_GPIB_VISA __instance,
	int state,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_VISA_Save(
	Alv_GPIB_VISA __instance,
	int state,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_VISA_Wait(
	Alv_GPIB_VISA __instance,
	CDotNetHandle * __exception);

// Type: Alv.GPIB.E3632A
int CVIFUNC Alv_GPIB_E3632A__Create(
	Alv_GPIB_E3632A * __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_E3632A_Apply(
	Alv_GPIB_E3632A __instance,
	double voltage,
	double current,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_E3632A_VoltageRange(
	Alv_GPIB_E3632A __instance,
	int high,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_E3632A_SetOutput(
	Alv_GPIB_E3632A __instance,
	int on,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_E3632A_Voltage(
	Alv_GPIB_E3632A __instance,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_E3632A_Current(
	Alv_GPIB_E3632A __instance,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_E3632A_Connect(
	Alv_GPIB_E3632A __instance,
	int GPIB,
	int Device_ID,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_E3632A_Close(
	Alv_GPIB_E3632A __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_E3632A_ResetState(
	Alv_GPIB_E3632A __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_E3632A_Calibrate(
	Alv_GPIB_E3632A __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_E3632A_Identification(
	Alv_GPIB_E3632A __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_E3632A_Ready(
	Alv_GPIB_E3632A __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_E3632A_Recall(
	Alv_GPIB_E3632A __instance,
	int state,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_E3632A_Save(
	Alv_GPIB_E3632A __instance,
	int state,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_E3632A_Wait(
	Alv_GPIB_E3632A __instance,
	CDotNetHandle * __exception);

// Type: Alv.GPIB.N9010A
int CVIFUNC Alv_GPIB_N9010A__Create(
	Alv_GPIB_N9010A * __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_Preset(
	Alv_GPIB_N9010A __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_ReferenceLevel(
	Alv_GPIB_N9010A __instance,
	double dBm,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_ReferenceLevelOffset(
	Alv_GPIB_N9010A __instance,
	double dB,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_Attenuation(
	Alv_GPIB_N9010A __instance,
	double dB,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_ReferenceLevelOffset_1(
	Alv_GPIB_N9010A __instance,
	int dB,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_AutoCouple(
	Alv_GPIB_N9010A __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_Cont(
	Alv_GPIB_N9010A __instance,
	int on,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_AutoTune(
	Alv_GPIB_N9010A __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_CenterFreq(
	Alv_GPIB_N9010A __instance,
	double MHz,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_FreqSpan(
	Alv_GPIB_N9010A __instance,
	double MHz,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_StartFreq(
	Alv_GPIB_N9010A __instance,
	double MHz,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_StopFreq(
	Alv_GPIB_N9010A __instance,
	double MHz,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_SweepTime(
	Alv_GPIB_N9010A __instance,
	double ms,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_SweepPoints(
	Alv_GPIB_N9010A __instance,
	int points,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_ResolutionBand(
	Alv_GPIB_N9010A __instance,
	double MHz,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_VideoBand(
	Alv_GPIB_N9010A __instance,
	double MHz,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_Trace(
	Alv_GPIB_N9010A __instance,
	Alv_GPIB_N9010A_Traces trace,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_Measure(
	Alv_GPIB_N9010A __instance,
	Alv_GPIB_N9010A_Measurments measurment,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_Configure(
	Alv_GPIB_N9010A __instance,
	Alv_GPIB_N9010A_Measurments measurment,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_ConfigureNdef(
	Alv_GPIB_N9010A __instance,
	Alv_GPIB_N9010A_Measurments measurment,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_Fetch(
	Alv_GPIB_N9010A __instance,
	Alv_GPIB_N9010A_Measurments measurment,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_Initiate(
	Alv_GPIB_N9010A __instance,
	Alv_GPIB_N9010A_Measurments measurment,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_Read(
	Alv_GPIB_N9010A __instance,
	Alv_GPIB_N9010A_Measurments measurment,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_Reset(
	Alv_GPIB_N9010A __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_Marker(
	Alv_GPIB_N9010A __instance,
	int marker,
	Alv_GPIB_N9010A_Markers mode,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_MkrToCf(
	Alv_GPIB_N9010A __instance,
	int marker,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_MkrToStart(
	Alv_GPIB_N9010A __instance,
	int marker,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_MkrToStop(
	Alv_GPIB_N9010A __instance,
	int marker,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_PeakSearch(
	Alv_GPIB_N9010A __instance,
	int marker,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_MinSearch(
	Alv_GPIB_N9010A __instance,
	int marker,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_MarkerX(
	Alv_GPIB_N9010A __instance,
	int marker,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_MarkerY(
	Alv_GPIB_N9010A __instance,
	int marker,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_ObwReferenceLevel(
	Alv_GPIB_N9010A __instance,
	double dBm,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_ObwResolutionBand(
	Alv_GPIB_N9010A __instance,
	double MHz,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_ObwVideoBand(
	Alv_GPIB_N9010A __instance,
	double MHz,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_ObwPrecentile(
	Alv_GPIB_N9010A __instance,
	int percentile,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_ObwFreqSpan(
	Alv_GPIB_N9010A __instance,
	double MHz,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_ObwTrace(
	Alv_GPIB_N9010A __instance,
	Alv_GPIB_N9010A_Traces trace,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_ObwSweepTime(
	Alv_GPIB_N9010A __instance,
	double ms,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_ChpReferenceLevel(
	Alv_GPIB_N9010A __instance,
	double dBm,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_ChpIntegBw(
	Alv_GPIB_N9010A __instance,
	double MHz,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_ChpFreqSpan(
	Alv_GPIB_N9010A __instance,
	double MHz,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_ChpAverageCount(
	Alv_GPIB_N9010A __instance,
	int count,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_PowerConfigure(
	Alv_GPIB_N9010A __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_PowerAverage(
	Alv_GPIB_N9010A __instance,
	int samples,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_PowerFrequency(
	Alv_GPIB_N9010A __instance,
	int center,
	int span,
	int points,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_ReadPower(
	Alv_GPIB_N9010A __instance,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_Connect(
	Alv_GPIB_N9010A __instance,
	int GPIB,
	int Device_ID,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_Close(
	Alv_GPIB_N9010A __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_ResetState(
	Alv_GPIB_N9010A __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_Calibrate(
	Alv_GPIB_N9010A __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_Identification(
	Alv_GPIB_N9010A __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_Ready(
	Alv_GPIB_N9010A __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_Recall(
	Alv_GPIB_N9010A __instance,
	int state,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_Save(
	Alv_GPIB_N9010A __instance,
	int state,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_N9010A_Wait(
	Alv_GPIB_N9010A __instance,
	CDotNetHandle * __exception);

// Type: Alv.GPIB.A11713
int CVIFUNC Alv_GPIB_A11713__Create(
	Alv_GPIB_A11713 * __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_A11713_OpenPath(
	Alv_GPIB_A11713 __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_A11713_OpenPath_1(
	Alv_GPIB_A11713 __instance,
	int route,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_A11713_ClosePath(
	Alv_GPIB_A11713 __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_A11713_ClosePath_1(
	Alv_GPIB_A11713 __instance,
	int route,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_A11713_Supply(
	Alv_GPIB_A11713 __instance,
	int on,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_A11713_TTL(
	Alv_GPIB_A11713 __instance,
	int on,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_A11713_Connect(
	Alv_GPIB_A11713 __instance,
	int GPIB,
	int Device_ID,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_A11713_Close(
	Alv_GPIB_A11713 __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_A11713_ResetState(
	Alv_GPIB_A11713 __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_A11713_Calibrate(
	Alv_GPIB_A11713 __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_A11713_Identification(
	Alv_GPIB_A11713 __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_A11713_Ready(
	Alv_GPIB_A11713 __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_A11713_Recall(
	Alv_GPIB_A11713 __instance,
	int state,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_A11713_Save(
	Alv_GPIB_A11713 __instance,
	int state,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_A11713_Wait(
	Alv_GPIB_A11713 __instance,
	CDotNetHandle * __exception);

// Type: Alv.Velmex.VXM
int CVIFUNC Alv_Velmex_VXM__Create(
	Alv_Velmex_VXM * __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Velmex_VXM_Connect(
	Alv_Velmex_VXM __instance,
	char * port_name,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Velmex_VXM_Connect_1(
	Alv_Velmex_VXM __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Velmex_VXM_Disconnect(
	Alv_Velmex_VXM __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Velmex_VXM_Transmit(
	Alv_Velmex_VXM __instance,
	char * command,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Velmex_VXM_Recieve(
	Alv_Velmex_VXM __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Velmex_VXM_Clear(
	Alv_Velmex_VXM __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Velmex_VXM_V(
	Alv_Velmex_VXM __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Velmex_VXM_halt(
	Alv_Velmex_VXM __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Velmex_VXM_Run(
	Alv_Velmex_VXM __instance,
	int wait,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Velmex_VXM_get_ang(
	Alv_Velmex_VXM __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Velmex_VXM_get_lin(
	Alv_Velmex_VXM __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Velmex_VXM_rehome_ang(
	Alv_Velmex_VXM __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Velmex_VXM_rehome_lin(
	Alv_Velmex_VXM __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Velmex_VXM_rehome_ang_1(
	Alv_Velmex_VXM __instance,
	int port,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Velmex_VXM_rehome_lin_1(
	Alv_Velmex_VXM __instance,
	int port,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Velmex_VXM_set_ang(
	Alv_Velmex_VXM __instance,
	int steps,
	int speed,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Velmex_VXM_set_lin(
	Alv_Velmex_VXM __instance,
	int steps,
	int speed,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Velmex_VXM_set_ang_1(
	Alv_Velmex_VXM __instance,
	int steps,
	int speed,
	int port,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Velmex_VXM_set_lin_1(
	Alv_Velmex_VXM __instance,
	int steps,
	int speed,
	int port,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Velmex_VXM_set_ang_motion(
	Alv_Velmex_VXM __instance,
	int steps,
	int speed,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Velmex_VXM_set_lin_motion(
	Alv_Velmex_VXM __instance,
	int steps,
	int speed,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Velmex_VXM_set_ang_motion_1(
	Alv_Velmex_VXM __instance,
	int steps,
	int speed,
	int port,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Velmex_VXM_set_lin_motion_1(
	Alv_Velmex_VXM __instance,
	int steps,
	int speed,
	int port,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Velmex_VXM_Cm2Step(
	double cm,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Velmex_VXM_Cm2Step_1(
	int cm,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Velmex_VXM_Step2Cm(
	int step,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Velmex_VXM_Deg2Step(
	int deg,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Velmex_VXM_Deg2Step_1(
	double deg,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Velmex_VXM_Step2Deg(
	int step,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Velmex_VXM__Get__MIN_M(
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Velmex_VXM__Get__MAX_M(
	int * __returnValue,
	CDotNetHandle * __exception);

// Type: Alv.GPIB.RS_FSV
int CVIFUNC Alv_GPIB_RS_FSV__Create(
	Alv_GPIB_RS_FSV * __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_RS_FSV_Preamp(
	Alv_GPIB_RS_FSV __instance,
	int on,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_RS_FSV_PowerOffset(
	Alv_GPIB_RS_FSV __instance,
	double dB,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_RS_FSV_InputAttenuation(
	Alv_GPIB_RS_FSV __instance,
	double dB,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_RS_FSV_SweepTime(
	Alv_GPIB_RS_FSV __instance,
	int ms,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_RS_FSV_CenterFrequency(
	Alv_GPIB_RS_FSV __instance,
	double MHz,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_RS_FSV_FrequencySpan(
	Alv_GPIB_RS_FSV __instance,
	double MHz,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_RS_FSV_Trace(
	Alv_GPIB_RS_FSV __instance,
	Alv_GPIB_RS_FSV_Traces t,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_RS_FSV_Detector(
	Alv_GPIB_RS_FSV __instance,
	Alv_GPIB_RS_FSV_Detectors detector,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_RS_FSV_ReferenceLevel(
	Alv_GPIB_RS_FSV __instance,
	double dBm,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_RS_FSV_MarkerOff(
	Alv_GPIB_RS_FSV __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_RS_FSV_MarkerFrequency(
	Alv_GPIB_RS_FSV __instance,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_RS_FSV_MarkerPower(
	Alv_GPIB_RS_FSV __instance,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_RS_FSV_PeakSearch(
	Alv_GPIB_RS_FSV __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_RS_FSV_MarkerToCenter(
	Alv_GPIB_RS_FSV __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_RS_FSV_PowerSelect(
	Alv_GPIB_RS_FSV __instance,
	Alv_GPIB_RS_FSV_Measurments measurment,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_RS_FSV_PowerResult(
	Alv_GPIB_RS_FSV __instance,
	Alv_GPIB_RS_FSV_Measurments measurment,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_RS_FSV_PowerClear(
	Alv_GPIB_RS_FSV __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_RS_FSV_ObwBandwidth(
	Alv_GPIB_RS_FSV __instance,
	int percentile,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_RS_FSV_ResolutionBandwidth(
	Alv_GPIB_RS_FSV __instance,
	double MHz,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_RS_FSV_VideoBandwidth(
	Alv_GPIB_RS_FSV __instance,
	double MHz,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_RS_FSV_Connect(
	Alv_GPIB_RS_FSV __instance,
	int GPIB,
	int Device_ID,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_RS_FSV_Close(
	Alv_GPIB_RS_FSV __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_RS_FSV_ResetState(
	Alv_GPIB_RS_FSV __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_RS_FSV_Calibrate(
	Alv_GPIB_RS_FSV __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_RS_FSV_Identification(
	Alv_GPIB_RS_FSV __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_RS_FSV_Ready(
	Alv_GPIB_RS_FSV __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_RS_FSV_Recall(
	Alv_GPIB_RS_FSV __instance,
	int state,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_RS_FSV_Save(
	Alv_GPIB_RS_FSV __instance,
	int state,
	CDotNetHandle * __exception);
int CVIFUNC Alv_GPIB_RS_FSV_Wait(
	Alv_GPIB_RS_FSV __instance,
	CDotNetHandle * __exception);

// Type: Alv.Test.Wave
int CVIFUNC Alv_Test_Wave__Create(
	Alv_Test_Wave * __instance,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Wave__Create_1(
	Alv_Test_Wave * __instance,
	Alv_Test_Wave previous,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Wave__Create_2(
	Alv_Test_Wave * __instance,
	System_Collections_Generic_IEnumerable_T1 source,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Wave_Get_Length(
	Alv_Test_Wave __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Wave_LoadBsdSweep(
	CDotNetHandle data,
	int antenna_pair,
	int rbin,
	Alv_Test_Wave * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Wave_LoadRctaSweep(
	CDotNetHandle data,
	int antenna_pair,
	int doppler,
	Alv_Test_Wave * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Wave_Load(
	double * re,
	ssize_t __reLength,
	double * im,
	ssize_t __imLength,
	Alv_Test_Wave * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Wave_Load_1(
	double * re,
	ssize_t __reLength,
	Alv_Test_Wave * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Wave_Load_2(
	System_Numerics_Complex * c,
	ssize_t __cLength,
	Alv_Test_Wave * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Wave_op_Addition(
	Alv_Test_Wave left,
	Alv_Test_Wave right,
	Alv_Test_Wave * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Wave_op_Subtraction(
	Alv_Test_Wave left,
	Alv_Test_Wave right,
	Alv_Test_Wave * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Wave_op_UnaryNegation(
	Alv_Test_Wave left,
	Alv_Test_Wave * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Wave_op_Multiply(
	Alv_Test_Wave left,
	Alv_Test_Wave right,
	Alv_Test_Wave * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Wave_op_Multiply_1(
	System_Numerics_Complex left,
	Alv_Test_Wave right,
	Alv_Test_Wave * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Wave_op_Multiply_2(
	Alv_Test_Wave left,
	System_Numerics_Complex right,
	Alv_Test_Wave * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Wave_op_Division(
	Alv_Test_Wave left,
	System_Numerics_Complex right,
	Alv_Test_Wave * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Wave_FFT(
	Alv_Test_Wave left,
	Alv_Test_Wave * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Wave_IFFT(
	Alv_Test_Wave left,
	Alv_Test_Wave * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Wave_FIR(
	Alv_Test_Wave left,
	double * points,
	ssize_t __pointsLength,
	Alv_Test_Wave * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Wave_MovingAvg(
	Alv_Test_Wave left,
	int points,
	Alv_Test_Wave * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Wave_BiasAt(
	Alv_Test_Wave left,
	double bias,
	Alv_Test_Wave * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Wave_Decimate(
	Alv_Test_Wave left,
	int every,
	int offset,
	Alv_Test_Wave * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Wave_Trim(
	Alv_Test_Wave left,
	int length,
	Alv_Test_Wave * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Wave_QCorrect(
	Alv_Test_Wave left,
	double amplitude,
	double phase,
	Alv_Test_Wave * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Wave_BalanceCorrect(
	Alv_Test_Wave left,
	double amplitude,
	double phase,
	Alv_Test_Wave * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Wave_Concat(
	Alv_Test_Wave left,
	Alv_Test_Wave right,
	Alv_Test_Wave * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Wave_KBDWindow(
	int size,
	double alpha,
	Alv_Test_Wave * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Wave_Bessel(
	double x,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Wave_dB(
	double value,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Wave_dB_1(
	System_Numerics_Complex value,
	System_Numerics_Complex * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Wave_GetEnumerator(
	Alv_Test_Wave __instance,
	System_Collections_Generic_IEnumerator_T1 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Wave_Phase(
	Alv_Test_Wave __instance,
	System_Collections_Generic_IEnumerable_T1 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Wave_Re(
	Alv_Test_Wave __instance,
	System_Collections_Generic_IEnumerable_T1 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Wave_Im(
	Alv_Test_Wave __instance,
	System_Collections_Generic_IEnumerable_T1 * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Wave_SNR(
	Alv_Test_Wave __instance,
	int pad,
	int percentile,
	double * window,
	ssize_t __windowLength,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Wave_SNR_1(
	Alv_Test_Wave __instance,
	int pad,
	int percentile,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Wave_SNR_2(
	Alv_Test_Wave __instance,
	double * window,
	ssize_t __windowLength,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Wave_Signel(
	Alv_Test_Wave __instance,
	int pad,
	double * window,
	ssize_t __windowLength,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Wave_Signel_1(
	Alv_Test_Wave __instance,
	int pad,
	double alpha,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Wave_Noise(
	Alv_Test_Wave __instance,
	int percentile,
	double * window,
	ssize_t __windowLength,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Wave_Noise_1(
	Alv_Test_Wave __instance,
	int percentile,
	double alpha,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Wave_Percentile(
	Alv_Test_Wave __instance,
	int percent,
	System_Numerics_Complex * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Wave_PhaseDelta(
	Alv_Test_Wave __instance,
	int start,
	int stop,
	double * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Wave_Mean(
	Alv_Test_Wave __instance,
	System_Numerics_Complex * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Wave_Std(
	Alv_Test_Wave __instance,
	System_Numerics_Complex * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Wave_Rms(
	Alv_Test_Wave __instance,
	System_Numerics_Complex * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Wave_WriteWave(
	Alv_Test_Wave __instance,
	char * deliminator,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Alv_Test_Wave_WriteWave_1(
	Alv_Test_Wave __instance,
	char * value_deliminator,
	char * line_deliminator,
	char ** __returnValue,
	CDotNetHandle * __exception);

// Type: Alv.MfgTest
int CVIFUNC Alv_MfgTest_Get_Version(
	char ** __returnValue,
	CDotNetHandle * __exception);

int CVIFUNC Ivi_Visa_Interop_FormattedIO488_get_IO(
	Ivi_Visa_Interop_FormattedIO488 __instance,
	Ivi_Visa_Interop_IMessage * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Ivi_Visa_Interop_FormattedIO488_set_IO(
	Ivi_Visa_Interop_FormattedIO488 __instance,
	Ivi_Visa_Interop_IMessage pVal,
	CDotNetHandle * __exception);
int CVIFUNC Ivi_Visa_Interop_FormattedIO488_WriteString(
	Ivi_Visa_Interop_FormattedIO488 __instance,
	char * data,
	int flushAndEND,
	CDotNetHandle * __exception);
int CVIFUNC Ivi_Visa_Interop_FormattedIO488_ReadString(
	Ivi_Visa_Interop_FormattedIO488 __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Ivi_Visa_Interop_FormattedIO488_ReadNumber(
	Ivi_Visa_Interop_FormattedIO488 __instance,
	Ivi_Visa_Interop_IEEEASCIIType type,
	int flushToEND,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Ivi_Visa_Interop_FormattedIO488_ReadList(
	Ivi_Visa_Interop_FormattedIO488 __instance,
	Ivi_Visa_Interop_IEEEASCIIType type,
	char * listSeperator,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);

// Type: Ivi.Visa.Interop.IFormattedIO488
int CVIFUNC Ivi_Visa_Interop_IFormattedIO488_Get_IO(
	Ivi_Visa_Interop_IFormattedIO488 __instance,
	Ivi_Visa_Interop_IMessage * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Ivi_Visa_Interop_IFormattedIO488_Set_IO(
	Ivi_Visa_Interop_IFormattedIO488 __instance,
	Ivi_Visa_Interop_IMessage pVal,
	CDotNetHandle * __exception);
int CVIFUNC Ivi_Visa_Interop_IFormattedIO488_WriteString(
	Ivi_Visa_Interop_IFormattedIO488 __instance,
	char * data,
	int flushAndEND,
	CDotNetHandle * __exception);
int CVIFUNC Ivi_Visa_Interop_IFormattedIO488_ReadString(
	Ivi_Visa_Interop_IFormattedIO488 __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Ivi_Visa_Interop_IFormattedIO488_ReadNumber(
	Ivi_Visa_Interop_IFormattedIO488 __instance,
	Ivi_Visa_Interop_IEEEASCIIType type,
	int flushToEND,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Ivi_Visa_Interop_IFormattedIO488_ReadList(
	Ivi_Visa_Interop_IFormattedIO488 __instance,
	Ivi_Visa_Interop_IEEEASCIIType type,
	char * listSeperator,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception);

// Type: Ivi.Visa.Interop.IMessage
int CVIFUNC Ivi_Visa_Interop_IMessage_Get_ResourceName(
	Ivi_Visa_Interop_IMessage __instance,
	char ** __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Ivi_Visa_Interop_IMessage_Get_Timeout(
	Ivi_Visa_Interop_IMessage __instance,
	int * __returnValue,
	CDotNetHandle * __exception);
int CVIFUNC Ivi_Visa_Interop_IMessage_Set_Timeout(
	Ivi_Visa_Interop_IMessage __instance,
	int pVal,
	CDotNetHandle * __exception);
int CVIFUNC Ivi_Visa_Interop_IMessage_Close(
	Ivi_Visa_Interop_IMessage __instance,
	CDotNetHandle * __exception);

int CVIFUNC Ivi_Visa_Interop_ResourceManager_Open(
	Ivi_Visa_Interop_ResourceManager __instance,
	char * ResourceName,
	Ivi_Visa_Interop_AccessMode mode,
	int openTimeout,
	char * OptionString,
	Ivi_Visa_Interop_IVisaSession * __returnValue,
	CDotNetHandle * __exception);

int CVIFUNC Ivi_Visa_Interop_IResourceManager3_Open(
	Ivi_Visa_Interop_IResourceManager3 __instance,
	char * ResourceName,
	Ivi_Visa_Interop_AccessMode mode,
	int openTimeout,
	char * OptionString,
	Ivi_Visa_Interop_IVisaSession * __returnValue,
	CDotNetHandle * __exception);





#ifdef __cplusplus
}
#endif
