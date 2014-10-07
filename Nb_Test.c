// CVI wrapper source file for .NET assembly: NbTest, Version=2.9.0.34, Culture=neutral, PublicKeyToken=null

#include "Nb_Test.h"
#include <stdarg.h>

// Macros
#ifndef __errChk
#define __errChk(f) if (__error = (f), __error < 0) goto __Error; else
#endif
#ifndef __nullChk
#define __nullChk(p) if (!(p)) { __error = CDotNetOutOfMemoryError; goto __Error; } else
#endif

// Constants
static const char * __assemblyName = "NbTest, Version=2.9.0.34, Culture=neutral, PublicKeyToken=null";

// Static Variables
static CDotNetAssemblyHandle __assemblyHandle = 0;

// Forward declarations
static int CVIFUNC Alv_NarrowBand_NBProtocol_Antenna__Create(
	Alv_NarrowBand_NBProtocol_Antenna * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception);
static int CVIFUNC Alv_NarrowBand_NBProtocol_ControlRadarMode__Create(
	Alv_NarrowBand_NBProtocol_ControlRadarMode * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception);
static int CVIFUNC Alv_NarrowBand_NBProtocol_StaticTestMode__Create(
	Alv_NarrowBand_NBProtocol_StaticTestMode * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception);
static int CVIFUNC Alv_NarrowBand_NBProtocol_DCOffset__Create(
	Alv_NarrowBand_NBProtocol_DCOffset * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception);
static int CVIFUNC Alv_NarrowBand_NBProtocol_ConfigurationBlock__Create(
	Alv_NarrowBand_NBProtocol_ConfigurationBlock * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception);
static int CVIFUNC Alv_NarrowBand_NBProtocol_Processor__Create(
	Alv_NarrowBand_NBProtocol_Processor * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception);
static int CVIFUNC Alv_NarrowBand_NBProtocol_TestLED__Create(
	Alv_NarrowBand_NBProtocol_TestLED * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception);
static int CVIFUNC Alv_NarrowBand_NBProtocol_GearPosition__Create(
	Alv_NarrowBand_NBProtocol_GearPosition * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception);
static int CVIFUNC Alv_GPIB_N9010A_Traces__Create(
	Alv_GPIB_N9010A_Traces * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception);
static int CVIFUNC Alv_GPIB_N9010A_Measurments__Create(
	Alv_GPIB_N9010A_Measurments * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception);
static int CVIFUNC Alv_GPIB_N9010A_Markers__Create(
	Alv_GPIB_N9010A_Markers * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception);
static int CVIFUNC Alv_GPIB_RS_FSV_Traces__Create(
	Alv_GPIB_RS_FSV_Traces * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception);
static int CVIFUNC Alv_GPIB_RS_FSV_Detectors__Create(
	Alv_GPIB_RS_FSV_Detectors * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception);
static int CVIFUNC Alv_GPIB_RS_FSV_Measurments__Create(
	Alv_GPIB_RS_FSV_Measurments * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception);
static int CVIFUNC Ivi_Visa_Interop_IEEEASCIIType__Create(
	Ivi_Visa_Interop_IEEEASCIIType * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception);
static int CVIFUNC Ivi_Visa_Interop_AccessMode__Create(
	Ivi_Visa_Interop_AccessMode * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception);
static void _CDotNetGenDisposeScalar(void * scalar, unsigned int typeId);
static void CVIFUNC_C _CDotNetGenDisposeArray(void * array, unsigned int typeId, size_t nDims, ...);

// Global Functions
int CVIFUNC Initialize_NbTest(void)
{
	int __error = 0;


	if (__assemblyHandle == 0)
		__errChk(CDotNetLoadAssembly(
			__assemblyName, 
			&__assemblyHandle));



__Error:
	return __error;
}

int CVIFUNC Close_NbTest(void)
{
	int __error = 0;


	if (__assemblyHandle) {
		__errChk(CDotNetDiscardAssemblyHandle(__assemblyHandle));
		__assemblyHandle = 0;
	}



__Error:
	return __error;
}


// Type: Alv.Test.TxCalSettings
int CVIFUNC Alv_Test_TxCalSettings__Create(
	Alv_Test_TxCalSettings * __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"Alv.Test.TxCalSettings", 
		0, 
		0, 
		__instance, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_TxCalSettings_Load(
	Alv_Test_TxCalSettings __instance,
	char * path,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: path
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &path;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.TxCalSettings", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Load", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_TxCalSettings__Get__Enabled(
	Alv_Test_TxCalSettings __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.TxCalSettings", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"Enabled", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_TxCalSettings__Set__Enabled(
	Alv_Test_TxCalSettings __instance,
	int Enabled,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: Enabled
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &Enabled;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.TxCalSettings", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"Enabled", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_TxCalSettings__Get__GPIBInterface(
	Alv_Test_TxCalSettings __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.TxCalSettings", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"GPIBInterface", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_TxCalSettings__Set__GPIBInterface(
	Alv_Test_TxCalSettings __instance,
	int GPIBInterface,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: GPIBInterface
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &GPIBInterface;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.TxCalSettings", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"GPIBInterface", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_TxCalSettings__Get__PowerSupplyGPIB(
	Alv_Test_TxCalSettings __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.TxCalSettings", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"PowerSupplyGPIB", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_TxCalSettings__Set__PowerSupplyGPIB(
	Alv_Test_TxCalSettings __instance,
	int PowerSupplyGPIB,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: PowerSupplyGPIB
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &PowerSupplyGPIB;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.TxCalSettings", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"PowerSupplyGPIB", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_TxCalSettings__Get__ControlPower(
	Alv_Test_TxCalSettings __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.TxCalSettings", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"ControlPower", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_TxCalSettings__Set__ControlPower(
	Alv_Test_TxCalSettings __instance,
	int ControlPower,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: ControlPower
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &ControlPower;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.TxCalSettings", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"ControlPower", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_TxCalSettings__Get__SensorVoltage(
	Alv_Test_TxCalSettings __instance,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.TxCalSettings", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"SensorVoltage", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_TxCalSettings__Set__SensorVoltage(
	Alv_Test_TxCalSettings __instance,
	double SensorVoltage,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: SensorVoltage
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &SensorVoltage;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.TxCalSettings", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"SensorVoltage", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_TxCalSettings__Get__WarmupDelay(
	Alv_Test_TxCalSettings __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.TxCalSettings", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"WarmupDelay", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_TxCalSettings__Set__WarmupDelay(
	Alv_Test_TxCalSettings __instance,
	int WarmupDelay,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: WarmupDelay
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &WarmupDelay;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.TxCalSettings", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"WarmupDelay", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_TxCalSettings__Get__SwitchGPIB(
	Alv_Test_TxCalSettings __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.TxCalSettings", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"SwitchGPIB", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_TxCalSettings__Set__SwitchGPIB(
	Alv_Test_TxCalSettings __instance,
	int SwitchGPIB,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: SwitchGPIB
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &SwitchGPIB;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.TxCalSettings", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"SwitchGPIB", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_TxCalSettings__Get__AnalyzerGPIB(
	Alv_Test_TxCalSettings __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.TxCalSettings", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"AnalyzerGPIB", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_TxCalSettings__Set__AnalyzerGPIB(
	Alv_Test_TxCalSettings __instance,
	int AnalyzerGPIB,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: AnalyzerGPIB
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &AnalyzerGPIB;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.TxCalSettings", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"AnalyzerGPIB", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_TxCalSettings__Get__NestOffsets(
	Alv_Test_TxCalSettings __instance,
	double ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.TxCalSettings", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"NestOffsets", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_DOUBLE, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_DOUBLE, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC Alv_Test_TxCalSettings__Set__NestOffsets(
	Alv_Test_TxCalSettings __instance,
	double * NestOffsets,
	ssize_t __NestOffsetsLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle NestOffsets__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: NestOffsets
	if (NestOffsets)
		__errChk(CDotNetCreateArray(
			CDOTNET_DOUBLE, 
			1, 
			0, 
			&__NestOffsetsLength, 
			NestOffsets, 
			&NestOffsets__));
	__parameterTypeNames[0] = "System.Double[]";
	__parameterTypes[0] = (CDOTNET_DOUBLE | CDOTNET_ARRAY);
	__parameters[0] = &NestOffsets__;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.TxCalSettings", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"NestOffsets", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (NestOffsets__)
		CDotNetDiscardHandle(NestOffsets__);
	return __error;
}

int CVIFUNC Alv_Test_TxCalSettings__Get__PowerOffset(
	Alv_Test_TxCalSettings __instance,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.TxCalSettings", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"PowerOffset", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_TxCalSettings__Set__PowerOffset(
	Alv_Test_TxCalSettings __instance,
	double PowerOffset,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: PowerOffset
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &PowerOffset;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.TxCalSettings", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"PowerOffset", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_TxCalSettings__Get__Attenuation(
	Alv_Test_TxCalSettings __instance,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.TxCalSettings", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"Attenuation", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_TxCalSettings__Set__Attenuation(
	Alv_Test_TxCalSettings __instance,
	double Attenuation,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: Attenuation
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &Attenuation;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.TxCalSettings", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"Attenuation", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_TxCalSettings__Get__ReferenceLevel(
	Alv_Test_TxCalSettings __instance,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.TxCalSettings", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"ReferenceLevel", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_TxCalSettings__Set__ReferenceLevel(
	Alv_Test_TxCalSettings __instance,
	double ReferenceLevel,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: ReferenceLevel
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &ReferenceLevel;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.TxCalSettings", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"ReferenceLevel", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_TxCalSettings__Get__HornDistance(
	Alv_Test_TxCalSettings __instance,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.TxCalSettings", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"HornDistance", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_TxCalSettings__Set__HornDistance(
	Alv_Test_TxCalSettings __instance,
	double HornDistance,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: HornDistance
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &HornDistance;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.TxCalSettings", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"HornDistance", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_TxCalSettings__Get__UseSwitch(
	Alv_Test_TxCalSettings __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.TxCalSettings", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"UseSwitch", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_TxCalSettings__Set__UseSwitch(
	Alv_Test_TxCalSettings __instance,
	int UseSwitch,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: UseSwitch
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &UseSwitch;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.TxCalSettings", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"UseSwitch", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}


// Type: Alv.Test.TxCal
int CVIFUNC Alv_Test_TxCal__Create(
	Alv_Test_TxCal * __instance,
	char * settings_path,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: settings_path
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &settings_path;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"Alv.Test.TxCal", 
		0, 
		0, 
		__instance, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_TxCal_Get_RfPath(
	Alv_Test_TxCal __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.TxCal", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"RfPath", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_TxCal_Set_RfPath(
	Alv_Test_TxCal __instance,
	int value,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: value
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &value;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.TxCal", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"RfPath", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_TxCal_ConnectSpec(
	Alv_Test_TxCal __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.TxCal", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ConnectSpec", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_TxCal_ConnectSensorPower(
	Alv_Test_TxCal __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.TxCal", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ConnectSensorPower", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_TxCal_ConnectAttenuator(
	Alv_Test_TxCal __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.TxCal", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ConnectAttenuator", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_TxCal_ConnectAll(
	Alv_Test_TxCal __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.TxCal", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ConnectAll", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_TxCal_CloseAll(
	Alv_Test_TxCal __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.TxCal", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"CloseAll", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_TxCal_GetChannelPower(
	Alv_Test_TxCal __instance,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.TxCal", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GetChannelPower", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_TxCal_GetPeakPower(
	Alv_Test_TxCal __instance,
	int force,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: force
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &force;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.TxCal", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GetPeakPower", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_TxCal_GetCenterFrequency(
	Alv_Test_TxCal __instance,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.TxCal", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GetCenterFrequency", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_TxCal_GetOccupiedBW(
	Alv_Test_TxCal __instance,
	int hold_time,
	int span,
	int sweep_time,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: hold_time
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &hold_time;

	// Pre-process parameter: span
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &span;

	// Pre-process parameter: sweep_time
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &sweep_time;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.TxCal", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GetOccupiedBW", 
		0, 
		0, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_TxCal_SetOutput(
	Alv_Test_TxCal __instance,
	double voltage,
	double current,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: voltage
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &voltage;

	// Pre-process parameter: current
	__parameterTypeNames[1] = "System.Double";
	__parameterTypes[1] = (CDOTNET_DOUBLE);
	__parameters[1] = &current;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.TxCal", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"SetOutput", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_TxCal_ControlPower(
	Alv_Test_TxCal __instance,
	int on,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: on
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &on;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.TxCal", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ControlPower", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_TxCal_GetCurrent(
	Alv_Test_TxCal __instance,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.TxCal", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GetCurrent", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_TxCal_GetVoltage(
	Alv_Test_TxCal __instance,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.TxCal", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GetVoltage", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_TxCal__Get__settings(
	Alv_Test_TxCal __instance,
	Alv_Test_TxCalSettings * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.TxCal", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"settings", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Alv_Test_TxCal__Set__settings(
	Alv_Test_TxCal __instance,
	Alv_Test_TxCalSettings settings,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: settings
	__parameterTypeNames[0] = "Alv.Test.TxCalSettings";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &settings;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.TxCal", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"settings", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}


// Type: Alv.Test.Mfg.MfgTests
int CVIFUNC Alv_Test_Mfg_MfgTests_Get_State(
	Alv_Test_Mfg_MfgTests __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTests", 
		0, 
		0, 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"State", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTests_Get_Message(
	Alv_Test_Mfg_MfgTests __instance,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTests", 
		0, 
		0, 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Message", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTests_InitCoffin(
	Alv_Test_Mfg_MfgTests __instance,
	Alv_NarrowBand_Sensor comm,
	char * settings_path,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: comm
	__parameterTypeNames[0] = "Alv.NarrowBand.Sensor,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &comm;

	// Pre-process parameter: settings_path
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &settings_path;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTests", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"InitCoffin", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTests_InitTxCal(
	Alv_Test_Mfg_MfgTests __instance,
	Alv_NarrowBand_Sensor comm,
	char * settings_path,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: comm
	__parameterTypeNames[0] = "Alv.NarrowBand.Sensor,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &comm;

	// Pre-process parameter: settings_path
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &settings_path;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTests", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"InitTxCal", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTests_Connect(
	Alv_Test_Mfg_MfgTests __instance,
	char ** serial,
	char *** part_number,
	ssize_t * __part_numberLength,
	char *** sw_version,
	ssize_t * __sw_versionLength,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];
	CDotNetHandle part_number__ = 0;
	CDotNetHandle sw_version__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	*serial = 0;
	*part_number = 0;
	*__part_numberLength = 0;
	*sw_version = 0;
	*__sw_versionLength = 0;


	// Pre-process parameter: serial
	__parameterTypeNames[0] = "System.String&";
	__parameterTypes[0] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[0] = serial;

	// Pre-process parameter: part_number
	__parameterTypeNames[1] = "System.String[]&";
	__parameterTypes[1] = (CDOTNET_STRING | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[1] = &part_number__;

	// Pre-process parameter: sw_version
	__parameterTypeNames[2] = "System.String[]&";
	__parameterTypes[2] = (CDOTNET_STRING | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[2] = &sw_version__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTests", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Connect", 
		0, 
		0, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));

	// Post-process parameter: part_number
	if (part_number__) {
		__errChk(CDotNetGetArrayElements(
			part_number__, 
			CDOTNET_STRING, 
			0, 
			part_number));
		__errChk(CDotNetGetArrayLength(
			part_number__, 
			0, 
			__part_numberLength));
	}

	// Post-process parameter: sw_version
	if (sw_version__) {
		__errChk(CDotNetGetArrayElements(
			sw_version__, 
			CDOTNET_STRING, 
			0, 
			sw_version));
		__errChk(CDotNetGetArrayLength(
			sw_version__, 
			0, 
			__sw_versionLength));
	}


__Error:
	if (part_number__)
		CDotNetDiscardHandle(part_number__);
	if (sw_version__)
		CDotNetDiscardHandle(sw_version__);
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			serial, 
			CDOTNET_STRING);
		_CDotNetGenDisposeArray(
			part_number, 
			CDOTNET_STRING, 
			1, 
			__part_numberLength);
		_CDotNetGenDisposeArray(
			sw_version, 
			CDOTNET_STRING, 
			1, 
			__sw_versionLength);
	}
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTests_Ping(
	Alv_Test_Mfg_MfgTests __instance,
	char ** serial,
	char *** part_number,
	ssize_t * __part_numberLength,
	char *** sw_version,
	ssize_t * __sw_versionLength,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];
	CDotNetHandle part_number__ = 0;
	CDotNetHandle sw_version__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	*serial = 0;
	*part_number = 0;
	*__part_numberLength = 0;
	*sw_version = 0;
	*__sw_versionLength = 0;


	// Pre-process parameter: serial
	__parameterTypeNames[0] = "System.String&";
	__parameterTypes[0] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[0] = serial;

	// Pre-process parameter: part_number
	__parameterTypeNames[1] = "System.String[]&";
	__parameterTypes[1] = (CDOTNET_STRING | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[1] = &part_number__;

	// Pre-process parameter: sw_version
	__parameterTypeNames[2] = "System.String[]&";
	__parameterTypes[2] = (CDOTNET_STRING | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[2] = &sw_version__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTests", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Ping", 
		0, 
		0, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));

	// Post-process parameter: part_number
	if (part_number__) {
		__errChk(CDotNetGetArrayElements(
			part_number__, 
			CDOTNET_STRING, 
			0, 
			part_number));
		__errChk(CDotNetGetArrayLength(
			part_number__, 
			0, 
			__part_numberLength));
	}

	// Post-process parameter: sw_version
	if (sw_version__) {
		__errChk(CDotNetGetArrayElements(
			sw_version__, 
			CDOTNET_STRING, 
			0, 
			sw_version));
		__errChk(CDotNetGetArrayLength(
			sw_version__, 
			0, 
			__sw_versionLength));
	}


__Error:
	if (part_number__)
		CDotNetDiscardHandle(part_number__);
	if (sw_version__)
		CDotNetDiscardHandle(sw_version__);
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			serial, 
			CDOTNET_STRING);
		_CDotNetGenDisposeArray(
			part_number, 
			CDOTNET_STRING, 
			1, 
			__part_numberLength);
		_CDotNetGenDisposeArray(
			sw_version, 
			CDOTNET_STRING, 
			1, 
			__sw_versionLength);
	}
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTests_MakePath(
	Alv_Test_Mfg_MfgTests __instance,
	char * path,
	char * description,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: path
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &path;

	// Pre-process parameter: description
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &description;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTests", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"MakePath", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTests_SetupData(
	Alv_Test_Mfg_MfgTests __instance,
	char * file_name,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: file_name
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &file_name;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTests", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"SetupData", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTests_Disconnect(
	Alv_Test_Mfg_MfgTests __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTests", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Disconnect", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTests_Supply_on(
	Alv_Test_Mfg_MfgTests __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTests", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Supply_on", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTests_SelectRfRoute(
	Alv_Test_Mfg_MfgTests __instance,
	int route,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: route
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &route;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTests", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"SelectRfRoute", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTests_DcOffsetInit(
	Alv_Test_Mfg_MfgTests __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTests", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"DcOffsetInit", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTests_CenterFrequency(
	Alv_Test_Mfg_MfgTests __instance,
	Alv_NarrowBand_NBProtocol_Antenna antenna,
	double * frequency,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	CDotNetHandle antenna__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: antenna
	__errChk(Alv_NarrowBand_NBProtocol_Antenna__Create(
		&antenna, 
		&antenna__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+Antenna,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &antenna__;

	// Pre-process parameter: frequency
	__parameterTypeNames[1] = "System.Double&";
	__parameterTypes[1] = (CDOTNET_DOUBLE | CDOTNET_OUT);
	__parameters[1] = frequency;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTests", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"CenterFrequency", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (antenna__)
		CDotNetDiscardHandle(antenna__);
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTests_CwLeakage(
	Alv_Test_Mfg_MfgTests __instance,
	Alv_NarrowBand_NBProtocol_Antenna antenna,
	double * leakage,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	CDotNetHandle antenna__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: antenna
	__errChk(Alv_NarrowBand_NBProtocol_Antenna__Create(
		&antenna, 
		&antenna__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+Antenna,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &antenna__;

	// Pre-process parameter: leakage
	__parameterTypeNames[1] = "System.Double&";
	__parameterTypes[1] = (CDOTNET_DOUBLE | CDOTNET_OUT);
	__parameters[1] = leakage;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTests", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"CwLeakage", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (antenna__)
		CDotNetDiscardHandle(antenna__);
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTests_OccupiedBW(
	Alv_Test_Mfg_MfgTests __instance,
	Alv_NarrowBand_NBProtocol_ControlRadarMode mode,
	int time,
	double * bandwidth,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];
	CDotNetHandle mode__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: mode
	__errChk(Alv_NarrowBand_NBProtocol_ControlRadarMode__Create(
		&mode, 
		&mode__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+ControlRadarMode,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &mode__;

	// Pre-process parameter: time
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &time;

	// Pre-process parameter: bandwidth
	__parameterTypeNames[2] = "System.Double&";
	__parameterTypes[2] = (CDOTNET_DOUBLE | CDOTNET_OUT);
	__parameters[2] = bandwidth;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTests", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"OccupiedBW", 
		0, 
		0, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (mode__)
		CDotNetDiscardHandle(mode__);
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTests_PointCheck(
	Alv_Test_Mfg_MfgTests __instance,
	int point,
	char * failval,
	char ** pointval,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	*pointval = 0;


	// Pre-process parameter: point
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &point;

	// Pre-process parameter: failval
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &failval;

	// Pre-process parameter: pointval
	__parameterTypeNames[2] = "System.String&";
	__parameterTypes[2] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[2] = pointval;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTests", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"PointCheck", 
		0, 
		0, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			pointval, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTests_PointCheck_1(
	Alv_Test_Mfg_MfgTests __instance,
	int point,
	double max,
	double min,
	char ** pointval,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	*pointval = 0;


	// Pre-process parameter: point
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &point;

	// Pre-process parameter: max
	__parameterTypeNames[1] = "System.Double";
	__parameterTypes[1] = (CDOTNET_DOUBLE);
	__parameters[1] = &max;

	// Pre-process parameter: min
	__parameterTypeNames[2] = "System.Double";
	__parameterTypes[2] = (CDOTNET_DOUBLE);
	__parameters[2] = &min;

	// Pre-process parameter: pointval
	__parameterTypeNames[3] = "System.String&";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[3] = pointval;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTests", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"PointCheck", 
		0, 
		0, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			pointval, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTests_DspErrorCheck(
	Alv_Test_Mfg_MfgTests __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTests", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"DspErrorCheck", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTests_HpErrorCheck(
	Alv_Test_Mfg_MfgTests __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTests", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"HpErrorCheck", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTests_IQCheckHonda(
	Alv_Test_Mfg_MfgTests __instance,
	double ** points,
	ssize_t * __pointsLength1,
	ssize_t * __pointsLength2,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle points__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	*points = 0;
	*__pointsLength1 = 0;
	*__pointsLength2 = 0;


	// Pre-process parameter: points
	__parameterTypeNames[0] = "System.Double[,]&";
	__parameterTypes[0] = (CDOTNET_DOUBLE | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[0] = &points__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTests", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"IQCheckHonda", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));

	// Post-process parameter: points
	if (points__) {
		__errChk(CDotNetGetArrayElements(
			points__, 
			CDOTNET_DOUBLE, 
			0, 
			points));
		__errChk(CDotNetGetArrayLength(
			points__, 
			0, 
			__pointsLength1));
		__errChk(CDotNetGetArrayLength(
			points__, 
			1, 
			__pointsLength2));
	}


__Error:
	if (points__)
		CDotNetDiscardHandle(points__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			points, 
			CDOTNET_DOUBLE, 
			2, 
			__pointsLength1, 
			__pointsLength2);
	}
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTests_IQCheckGM(
	Alv_Test_Mfg_MfgTests __instance,
	double ** points,
	ssize_t * __pointsLength1,
	ssize_t * __pointsLength2,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle points__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	*points = 0;
	*__pointsLength1 = 0;
	*__pointsLength2 = 0;


	// Pre-process parameter: points
	__parameterTypeNames[0] = "System.Double[,]&";
	__parameterTypes[0] = (CDOTNET_DOUBLE | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[0] = &points__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTests", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"IQCheckGM", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));

	// Post-process parameter: points
	if (points__) {
		__errChk(CDotNetGetArrayElements(
			points__, 
			CDOTNET_DOUBLE, 
			0, 
			points));
		__errChk(CDotNetGetArrayLength(
			points__, 
			0, 
			__pointsLength1));
		__errChk(CDotNetGetArrayLength(
			points__, 
			1, 
			__pointsLength2));
	}


__Error:
	if (points__)
		CDotNetDiscardHandle(points__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			points, 
			CDOTNET_DOUBLE, 
			2, 
			__pointsLength1, 
			__pointsLength2);
	}
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTests_CurrentCheck(
	Alv_Test_Mfg_MfgTests __instance,
	double * current,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: current
	__parameterTypeNames[0] = "System.Double&";
	__parameterTypes[0] = (CDOTNET_DOUBLE | CDOTNET_OUT);
	__parameters[0] = current;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTests", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"CurrentCheck", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTests_SensorTemp(
	Alv_Test_Mfg_MfgTests __instance,
	double * board_temp,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: board_temp
	__parameterTypeNames[0] = "System.Double&";
	__parameterTypes[0] = (CDOTNET_DOUBLE | CDOTNET_OUT);
	__parameters[0] = board_temp;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTests", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"SensorTemp", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTests_LEDTest(
	Alv_Test_Mfg_MfgTests __instance,
	double * led_current,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: led_current
	__parameterTypeNames[0] = "System.Double&";
	__parameterTypes[0] = (CDOTNET_DOUBLE | CDOTNET_OUT);
	__parameters[0] = led_current;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTests", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"LEDTest", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTests_NoiseArtifact(
	Alv_Test_Mfg_MfgTests __instance,
	int sweeps,
	int bin_length,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: sweeps
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &sweeps;

	// Pre-process parameter: bin_length
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &bin_length;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTests", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"NoiseArtifact", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTests_BSDRangeCheck(
	Alv_Test_Mfg_MfgTests __instance,
	int count,
	double angle,
	double threshold,
	double * range,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: count
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &count;

	// Pre-process parameter: angle
	__parameterTypeNames[1] = "System.Double";
	__parameterTypes[1] = (CDOTNET_DOUBLE);
	__parameters[1] = &angle;

	// Pre-process parameter: threshold
	__parameterTypeNames[2] = "System.Double";
	__parameterTypes[2] = (CDOTNET_DOUBLE);
	__parameters[2] = &threshold;

	// Pre-process parameter: range
	__parameterTypeNames[3] = "System.Double&";
	__parameterTypes[3] = (CDOTNET_DOUBLE | CDOTNET_OUT);
	__parameters[3] = range;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTests", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"BSDRangeCheck", 
		0, 
		0, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTests_SweepBSD(
	Alv_Test_Mfg_MfgTests __instance,
	double angle,
	Alv_NarrowBand_NBProtocol_Antenna antenna,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	CDotNetHandle antenna__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: angle
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &angle;

	// Pre-process parameter: antenna
	__errChk(Alv_NarrowBand_NBProtocol_Antenna__Create(
		&antenna, 
		&antenna__, 
		__exception));
	__parameterTypeNames[1] = "Alv.NarrowBand.NBProtocol+Antenna,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[1] = (CDOTNET_ENUM);
	__parameters[1] = &antenna__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTests", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"SweepBSD", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (antenna__)
		CDotNetDiscardHandle(antenna__);
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTests_SweepRCTA(
	Alv_Test_Mfg_MfgTests __instance,
	double angle,
	Alv_NarrowBand_NBProtocol_Antenna antenna,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	CDotNetHandle antenna__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: angle
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &angle;

	// Pre-process parameter: antenna
	__errChk(Alv_NarrowBand_NBProtocol_Antenna__Create(
		&antenna, 
		&antenna__, 
		__exception));
	__parameterTypeNames[1] = "Alv.NarrowBand.NBProtocol+Antenna,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[1] = (CDOTNET_ENUM);
	__parameters[1] = &antenna__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTests", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"SweepRCTA", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (antenna__)
		CDotNetDiscardHandle(antenna__);
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTests_SweepLCA(
	Alv_Test_Mfg_MfgTests __instance,
	double angle,
	Alv_NarrowBand_NBProtocol_Antenna antenna,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	CDotNetHandle antenna__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: angle
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &angle;

	// Pre-process parameter: antenna
	__errChk(Alv_NarrowBand_NBProtocol_Antenna__Create(
		&antenna, 
		&antenna__, 
		__exception));
	__parameterTypeNames[1] = "Alv.NarrowBand.NBProtocol+Antenna,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[1] = (CDOTNET_ENUM);
	__parameters[1] = &antenna__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTests", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"SweepLCA", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (antenna__)
		CDotNetDiscardHandle(antenna__);
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[8] = {0};
	unsigned int __parameterTypes[8];
	void * __parameters[8];
	CDotNetHandle mode__ = 0;
	CDotNetHandle antenna__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: mode
	__errChk(Alv_NarrowBand_NBProtocol_ControlRadarMode__Create(
		&mode, 
		&mode__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+ControlRadarMode,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &mode__;

	// Pre-process parameter: antenna
	__errChk(Alv_NarrowBand_NBProtocol_Antenna__Create(
		&antenna, 
		&antenna__, 
		__exception));
	__parameterTypeNames[1] = "Alv.NarrowBand.NBProtocol+Antenna,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[1] = (CDOTNET_ENUM);
	__parameters[1] = &antenna__;

	// Pre-process parameter: angle
	__parameterTypeNames[2] = "System.Double";
	__parameterTypes[2] = (CDOTNET_DOUBLE);
	__parameters[2] = &angle;

	// Pre-process parameter: count
	__parameterTypeNames[3] = "System.Int32";
	__parameterTypes[3] = (CDOTNET_INT32);
	__parameters[3] = &count;

	// Pre-process parameter: azimuth
	__parameterTypeNames[4] = "System.Double&";
	__parameterTypes[4] = (CDOTNET_DOUBLE | CDOTNET_OUT);
	__parameters[4] = azimuth;

	// Pre-process parameter: distance
	__parameterTypeNames[5] = "System.Double&";
	__parameterTypes[5] = (CDOTNET_DOUBLE | CDOTNET_OUT);
	__parameters[5] = distance;

	// Pre-process parameter: speed
	__parameterTypeNames[6] = "System.Double&";
	__parameterTypes[6] = (CDOTNET_DOUBLE | CDOTNET_OUT);
	__parameters[6] = speed;

	// Pre-process parameter: SNR
	__parameterTypeNames[7] = "System.Double&";
	__parameterTypes[7] = (CDOTNET_DOUBLE | CDOTNET_OUT);
	__parameters[7] = SNR;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTests", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"UntDatSweep", 
		0, 
		0, 
		8, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (mode__)
		CDotNetDiscardHandle(mode__);
	if (antenna__)
		CDotNetDiscardHandle(antenna__);
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTests_UntDatSweep_1(
	Alv_Test_Mfg_MfgTests __instance,
	Alv_NarrowBand_NBProtocol_StaticTestMode mode,
	double angle,
	int count,
	double * azimuth,
	double * distance,
	double * speed,
	double * SNR,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[7] = {0};
	unsigned int __parameterTypes[7];
	void * __parameters[7];
	CDotNetHandle mode__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: mode
	__errChk(Alv_NarrowBand_NBProtocol_StaticTestMode__Create(
		&mode, 
		&mode__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+StaticTestMode,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &mode__;

	// Pre-process parameter: angle
	__parameterTypeNames[1] = "System.Double";
	__parameterTypes[1] = (CDOTNET_DOUBLE);
	__parameters[1] = &angle;

	// Pre-process parameter: count
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &count;

	// Pre-process parameter: azimuth
	__parameterTypeNames[3] = "System.Double&";
	__parameterTypes[3] = (CDOTNET_DOUBLE | CDOTNET_OUT);
	__parameters[3] = azimuth;

	// Pre-process parameter: distance
	__parameterTypeNames[4] = "System.Double&";
	__parameterTypes[4] = (CDOTNET_DOUBLE | CDOTNET_OUT);
	__parameters[4] = distance;

	// Pre-process parameter: speed
	__parameterTypeNames[5] = "System.Double&";
	__parameterTypes[5] = (CDOTNET_DOUBLE | CDOTNET_OUT);
	__parameters[5] = speed;

	// Pre-process parameter: SNR
	__parameterTypeNames[6] = "System.Double&";
	__parameterTypes[6] = (CDOTNET_DOUBLE | CDOTNET_OUT);
	__parameters[6] = SNR;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTests", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"UntDatSweep", 
		0, 
		0, 
		7, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (mode__)
		CDotNetDiscardHandle(mode__);
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTests_TxPower(
	Alv_Test_Mfg_MfgTests __instance,
	double * power,
	Alv_NarrowBand_NBProtocol_Antenna antenna,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	CDotNetHandle antenna__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: power
	__parameterTypeNames[0] = "System.Double&";
	__parameterTypes[0] = (CDOTNET_DOUBLE | CDOTNET_OUT);
	__parameters[0] = power;

	// Pre-process parameter: antenna
	__errChk(Alv_NarrowBand_NBProtocol_Antenna__Create(
		&antenna, 
		&antenna__, 
		__exception));
	__parameterTypeNames[1] = "Alv.NarrowBand.NBProtocol+Antenna,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[1] = (CDOTNET_ENUM);
	__parameters[1] = &antenna__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTests", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"TxPower", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (antenna__)
		CDotNetDiscardHandle(antenna__);
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTests_PowerAtAngle(
	Alv_Test_Mfg_MfgTests __instance,
	double angle,
	double ** power,
	ssize_t * __powerLength,
	double * board_temp,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];
	CDotNetHandle power__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	*power = 0;
	*__powerLength = 0;


	// Pre-process parameter: angle
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &angle;

	// Pre-process parameter: power
	__parameterTypeNames[1] = "System.Double[]&";
	__parameterTypes[1] = (CDOTNET_DOUBLE | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[1] = &power__;

	// Pre-process parameter: board_temp
	__parameterTypeNames[2] = "System.Double&";
	__parameterTypes[2] = (CDOTNET_DOUBLE | CDOTNET_OUT);
	__parameters[2] = board_temp;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTests", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"PowerAtAngle", 
		0, 
		0, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));

	// Post-process parameter: power
	if (power__) {
		__errChk(CDotNetGetArrayElements(
			power__, 
			CDOTNET_DOUBLE, 
			0, 
			power));
		__errChk(CDotNetGetArrayLength(
			power__, 
			0, 
			__powerLength));
	}


__Error:
	if (power__)
		CDotNetDiscardHandle(power__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			power, 
			CDOTNET_DOUBLE, 
			1, 
			__powerLength);
	}
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTests_BlockageTest(
	Alv_Test_Mfg_MfgTests __instance,
	double * blockage,
	double * board_temp,
	double * noise_floor,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: blockage
	__parameterTypeNames[0] = "System.Double&";
	__parameterTypes[0] = (CDOTNET_DOUBLE | CDOTNET_OUT);
	__parameters[0] = blockage;

	// Pre-process parameter: board_temp
	__parameterTypeNames[1] = "System.Double&";
	__parameterTypes[1] = (CDOTNET_DOUBLE | CDOTNET_OUT);
	__parameters[1] = board_temp;

	// Pre-process parameter: noise_floor
	__parameterTypeNames[2] = "System.Double&";
	__parameterTypes[2] = (CDOTNET_DOUBLE | CDOTNET_OUT);
	__parameters[2] = noise_floor;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTests", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"BlockageTest", 
		0, 
		0, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[5] = {0};
	unsigned int __parameterTypes[5];
	void * __parameters[5];
	CDotNetHandle points__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	*points = 0;
	*__pointsLength1 = 0;
	*__pointsLength2 = 0;


	// Pre-process parameter: gain_min
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &gain_min;

	// Pre-process parameter: pow_min
	__parameterTypeNames[1] = "System.Double";
	__parameterTypes[1] = (CDOTNET_DOUBLE);
	__parameters[1] = &pow_min;

	// Pre-process parameter: pow_max
	__parameterTypeNames[2] = "System.Double";
	__parameterTypes[2] = (CDOTNET_DOUBLE);
	__parameters[2] = &pow_max;

	// Pre-process parameter: power
	__parameterTypeNames[3] = "System.Double&";
	__parameterTypes[3] = (CDOTNET_DOUBLE | CDOTNET_OUT);
	__parameters[3] = power;

	// Pre-process parameter: points
	__parameterTypeNames[4] = "System.Double[,]&";
	__parameterTypes[4] = (CDOTNET_DOUBLE | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[4] = &points__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTests", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"TxPowerCalHonda", 
		0, 
		0, 
		5, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));

	// Post-process parameter: points
	if (points__) {
		__errChk(CDotNetGetArrayElements(
			points__, 
			CDOTNET_DOUBLE, 
			0, 
			points));
		__errChk(CDotNetGetArrayLength(
			points__, 
			0, 
			__pointsLength1));
		__errChk(CDotNetGetArrayLength(
			points__, 
			1, 
			__pointsLength2));
	}


__Error:
	if (points__)
		CDotNetDiscardHandle(points__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			points, 
			CDOTNET_DOUBLE, 
			2, 
			__pointsLength1, 
			__pointsLength2);
	}
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTests_IQCalHonda(
	Alv_Test_Mfg_MfgTests __instance,
	double ** points,
	ssize_t * __pointsLength1,
	ssize_t * __pointsLength2,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle points__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	*points = 0;
	*__pointsLength1 = 0;
	*__pointsLength2 = 0;


	// Pre-process parameter: points
	__parameterTypeNames[0] = "System.Double[,]&";
	__parameterTypes[0] = (CDOTNET_DOUBLE | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[0] = &points__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTests", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"IQCalHonda", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));

	// Post-process parameter: points
	if (points__) {
		__errChk(CDotNetGetArrayElements(
			points__, 
			CDOTNET_DOUBLE, 
			0, 
			points));
		__errChk(CDotNetGetArrayLength(
			points__, 
			0, 
			__pointsLength1));
		__errChk(CDotNetGetArrayLength(
			points__, 
			1, 
			__pointsLength2));
	}


__Error:
	if (points__)
		CDotNetDiscardHandle(points__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			points, 
			CDOTNET_DOUBLE, 
			2, 
			__pointsLength1, 
			__pointsLength2);
	}
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTests_AngleCalHonda(
	Alv_Test_Mfg_MfgTests __instance,
	int count,
	double ** points,
	ssize_t * __pointsLength1,
	ssize_t * __pointsLength2,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	CDotNetHandle points__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	*points = 0;
	*__pointsLength1 = 0;
	*__pointsLength2 = 0;


	// Pre-process parameter: count
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &count;

	// Pre-process parameter: points
	__parameterTypeNames[1] = "System.Double[,]&";
	__parameterTypes[1] = (CDOTNET_DOUBLE | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[1] = &points__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTests", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"AngleCalHonda", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));

	// Post-process parameter: points
	if (points__) {
		__errChk(CDotNetGetArrayElements(
			points__, 
			CDOTNET_DOUBLE, 
			0, 
			points));
		__errChk(CDotNetGetArrayLength(
			points__, 
			0, 
			__pointsLength1));
		__errChk(CDotNetGetArrayLength(
			points__, 
			1, 
			__pointsLength2));
	}


__Error:
	if (points__)
		CDotNetDiscardHandle(points__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			points, 
			CDOTNET_DOUBLE, 
			2, 
			__pointsLength1, 
			__pointsLength2);
	}
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTests_BSDCalHonda(
	Alv_Test_Mfg_MfgTests __instance,
	int count,
	double angle,
	double threshold,
	double ** points,
	ssize_t * __pointsLength,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];
	CDotNetHandle points__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	*points = 0;
	*__pointsLength = 0;


	// Pre-process parameter: count
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &count;

	// Pre-process parameter: angle
	__parameterTypeNames[1] = "System.Double";
	__parameterTypes[1] = (CDOTNET_DOUBLE);
	__parameters[1] = &angle;

	// Pre-process parameter: threshold
	__parameterTypeNames[2] = "System.Double";
	__parameterTypes[2] = (CDOTNET_DOUBLE);
	__parameters[2] = &threshold;

	// Pre-process parameter: points
	__parameterTypeNames[3] = "System.Double[]&";
	__parameterTypes[3] = (CDOTNET_DOUBLE | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[3] = &points__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTests", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"BSDCalHonda", 
		0, 
		0, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));

	// Post-process parameter: points
	if (points__) {
		__errChk(CDotNetGetArrayElements(
			points__, 
			CDOTNET_DOUBLE, 
			0, 
			points));
		__errChk(CDotNetGetArrayLength(
			points__, 
			0, 
			__pointsLength));
	}


__Error:
	if (points__)
		CDotNetDiscardHandle(points__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			points, 
			CDOTNET_DOUBLE, 
			1, 
			__pointsLength);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[9] = {0};
	unsigned int __parameterTypes[9];
	void * __parameters[9];
	CDotNetHandle power__ = 0;
	CDotNetHandle amp__ = 0;
	CDotNetHandle sw__ = 0;
	CDotNetHandle pdet__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	*power = 0;
	*__powerLength = 0;
	*amp = 0;
	*__ampLength = 0;
	*sw = 0;
	*__swLength = 0;
	*pdet = 0;
	*__pdetLength = 0;


	// Pre-process parameter: pow_max_bsd
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &pow_max_bsd;

	// Pre-process parameter: pow_max_rcta
	__parameterTypeNames[1] = "System.Double";
	__parameterTypes[1] = (CDOTNET_DOUBLE);
	__parameters[1] = &pow_max_rcta;

	// Pre-process parameter: pow_min_bsd
	__parameterTypeNames[2] = "System.Double";
	__parameterTypes[2] = (CDOTNET_DOUBLE);
	__parameters[2] = &pow_min_bsd;

	// Pre-process parameter: pow_min_rcta
	__parameterTypeNames[3] = "System.Double";
	__parameterTypes[3] = (CDOTNET_DOUBLE);
	__parameters[3] = &pow_min_rcta;

	// Pre-process parameter: power
	__parameterTypeNames[4] = "System.Double[]&";
	__parameterTypes[4] = (CDOTNET_DOUBLE | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[4] = &power__;

	// Pre-process parameter: amp
	__parameterTypeNames[5] = "System.UInt16[]&";
	__parameterTypes[5] = (CDOTNET_UINT16 | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[5] = &amp__;

	// Pre-process parameter: sw
	__parameterTypeNames[6] = "System.UInt16[]&";
	__parameterTypes[6] = (CDOTNET_UINT16 | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[6] = &sw__;

	// Pre-process parameter: pdet
	__parameterTypeNames[7] = "System.UInt16[]&";
	__parameterTypes[7] = (CDOTNET_UINT16 | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[7] = &pdet__;

	// Pre-process parameter: thermistor
	__parameterTypeNames[8] = "System.UInt16&";
	__parameterTypes[8] = (CDOTNET_UINT16 | CDOTNET_OUT);
	__parameters[8] = thermistor;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTests", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"TxPowerCalGM", 
		0, 
		0, 
		9, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));

	// Post-process parameter: power
	if (power__) {
		__errChk(CDotNetGetArrayElements(
			power__, 
			CDOTNET_DOUBLE, 
			0, 
			power));
		__errChk(CDotNetGetArrayLength(
			power__, 
			0, 
			__powerLength));
	}

	// Post-process parameter: amp
	if (amp__) {
		__errChk(CDotNetGetArrayElements(
			amp__, 
			CDOTNET_UINT16, 
			0, 
			amp));
		__errChk(CDotNetGetArrayLength(
			amp__, 
			0, 
			__ampLength));
	}

	// Post-process parameter: sw
	if (sw__) {
		__errChk(CDotNetGetArrayElements(
			sw__, 
			CDOTNET_UINT16, 
			0, 
			sw));
		__errChk(CDotNetGetArrayLength(
			sw__, 
			0, 
			__swLength));
	}

	// Post-process parameter: pdet
	if (pdet__) {
		__errChk(CDotNetGetArrayElements(
			pdet__, 
			CDOTNET_UINT16, 
			0, 
			pdet));
		__errChk(CDotNetGetArrayLength(
			pdet__, 
			0, 
			__pdetLength));
	}


__Error:
	if (power__)
		CDotNetDiscardHandle(power__);
	if (amp__)
		CDotNetDiscardHandle(amp__);
	if (sw__)
		CDotNetDiscardHandle(sw__);
	if (pdet__)
		CDotNetDiscardHandle(pdet__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			power, 
			CDOTNET_DOUBLE, 
			1, 
			__powerLength);
		_CDotNetGenDisposeArray(
			amp, 
			CDOTNET_UINT16, 
			1, 
			__ampLength);
		_CDotNetGenDisposeArray(
			sw, 
			CDOTNET_UINT16, 
			1, 
			__swLength);
		_CDotNetGenDisposeArray(
			pdet, 
			CDOTNET_UINT16, 
			1, 
			__pdetLength);
	}
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTests_IQCalGM(
	Alv_Test_Mfg_MfgTests __instance,
	double ** points,
	ssize_t * __pointsLength1,
	ssize_t * __pointsLength2,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle points__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	*points = 0;
	*__pointsLength1 = 0;
	*__pointsLength2 = 0;


	// Pre-process parameter: points
	__parameterTypeNames[0] = "System.Double[,]&";
	__parameterTypes[0] = (CDOTNET_DOUBLE | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[0] = &points__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTests", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"IQCalGM", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));

	// Post-process parameter: points
	if (points__) {
		__errChk(CDotNetGetArrayElements(
			points__, 
			CDOTNET_DOUBLE, 
			0, 
			points));
		__errChk(CDotNetGetArrayLength(
			points__, 
			0, 
			__pointsLength1));
		__errChk(CDotNetGetArrayLength(
			points__, 
			1, 
			__pointsLength2));
	}


__Error:
	if (points__)
		CDotNetDiscardHandle(points__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			points, 
			CDOTNET_DOUBLE, 
			2, 
			__pointsLength1, 
			__pointsLength2);
	}
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTests_AngleCalGM(
	Alv_Test_Mfg_MfgTests __instance,
	int count,
	double MDA_start,
	double MDA_stop,
	double * TrueAngles,
	ssize_t __TrueAnglesLength,
	double ** measured_theta,
	ssize_t * __measured_thetaLength1,
	ssize_t * __measured_thetaLength2,
	CDotNetHandle * beam_formed_theta,
	CDotNetHandle * TableCalcPoints,
	CDotNetHandle * TableCalcValues,
	CDotNetHandle * TableTruePoints,
	CDotNetHandle * TableTrueValues,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[10] = {0};
	unsigned int __parameterTypes[10];
	void * __parameters[10];
	CDotNetHandle TrueAngles__ = 0;
	CDotNetHandle measured_theta__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	*measured_theta = 0;
	*__measured_thetaLength1 = 0;
	*__measured_thetaLength2 = 0;
	*beam_formed_theta = 0;
	*TableCalcPoints = 0;
	*TableCalcValues = 0;
	*TableTruePoints = 0;
	*TableTrueValues = 0;


	// Pre-process parameter: count
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &count;

	// Pre-process parameter: MDA_start
	__parameterTypeNames[1] = "System.Double";
	__parameterTypes[1] = (CDOTNET_DOUBLE);
	__parameters[1] = &MDA_start;

	// Pre-process parameter: MDA_stop
	__parameterTypeNames[2] = "System.Double";
	__parameterTypes[2] = (CDOTNET_DOUBLE);
	__parameters[2] = &MDA_stop;

	// Pre-process parameter: TrueAngles
	if (TrueAngles)
		__errChk(CDotNetCreateArray(
			CDOTNET_DOUBLE, 
			1, 
			0, 
			&__TrueAnglesLength, 
			TrueAngles, 
			&TrueAngles__));
	__parameterTypeNames[3] = "System.Double[]";
	__parameterTypes[3] = (CDOTNET_DOUBLE | CDOTNET_ARRAY);
	__parameters[3] = &TrueAngles__;

	// Pre-process parameter: measured_theta
	__parameterTypeNames[4] = "System.Double[,]&";
	__parameterTypes[4] = (CDOTNET_DOUBLE | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[4] = &measured_theta__;

	// Pre-process parameter: beam_formed_theta
	__parameterTypeNames[5] = "System.Double[][]&";
	__parameterTypes[5] = (CDOTNET_OBJECT | CDOTNET_OUT);
	__parameters[5] = beam_formed_theta;

	// Pre-process parameter: TableCalcPoints
	__parameterTypeNames[6] = "System.UInt16[][]&";
	__parameterTypes[6] = (CDOTNET_OBJECT | CDOTNET_OUT);
	__parameters[6] = TableCalcPoints;

	// Pre-process parameter: TableCalcValues
	__parameterTypeNames[7] = "System.Double[][]&";
	__parameterTypes[7] = (CDOTNET_OBJECT | CDOTNET_OUT);
	__parameters[7] = TableCalcValues;

	// Pre-process parameter: TableTruePoints
	__parameterTypeNames[8] = "System.UInt16[][]&";
	__parameterTypes[8] = (CDOTNET_OBJECT | CDOTNET_OUT);
	__parameters[8] = TableTruePoints;

	// Pre-process parameter: TableTrueValues
	__parameterTypeNames[9] = "System.Double[][]&";
	__parameterTypes[9] = (CDOTNET_OBJECT | CDOTNET_OUT);
	__parameters[9] = TableTrueValues;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTests", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"AngleCalGM", 
		0, 
		0, 
		10, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));

	// Post-process parameter: measured_theta
	if (measured_theta__) {
		__errChk(CDotNetGetArrayElements(
			measured_theta__, 
			CDOTNET_DOUBLE, 
			0, 
			measured_theta));
		__errChk(CDotNetGetArrayLength(
			measured_theta__, 
			0, 
			__measured_thetaLength1));
		__errChk(CDotNetGetArrayLength(
			measured_theta__, 
			1, 
			__measured_thetaLength2));
	}


__Error:
	if (TrueAngles__)
		CDotNetDiscardHandle(TrueAngles__);
	if (measured_theta__)
		CDotNetDiscardHandle(measured_theta__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			measured_theta, 
			CDOTNET_DOUBLE, 
			2, 
			__measured_thetaLength1, 
			__measured_thetaLength2);
		_CDotNetGenDisposeScalar(
			beam_formed_theta, 
			CDOTNET_OBJECT);
		_CDotNetGenDisposeScalar(
			TableCalcPoints, 
			CDOTNET_OBJECT);
		_CDotNetGenDisposeScalar(
			TableCalcValues, 
			CDOTNET_OBJECT);
		_CDotNetGenDisposeScalar(
			TableTruePoints, 
			CDOTNET_OBJECT);
		_CDotNetGenDisposeScalar(
			TableTrueValues, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTests_TxPowerCalVEVA(
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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[9] = {0};
	unsigned int __parameterTypes[9];
	void * __parameters[9];
	CDotNetHandle power__ = 0;
	CDotNetHandle amp__ = 0;
	CDotNetHandle sw__ = 0;
	CDotNetHandle pdet__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	*power = 0;
	*__powerLength = 0;
	*amp = 0;
	*__ampLength = 0;
	*sw = 0;
	*__swLength = 0;
	*pdet = 0;
	*__pdetLength = 0;


	// Pre-process parameter: pow_max_bsd
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &pow_max_bsd;

	// Pre-process parameter: pow_max_rcta
	__parameterTypeNames[1] = "System.Double";
	__parameterTypes[1] = (CDOTNET_DOUBLE);
	__parameters[1] = &pow_max_rcta;

	// Pre-process parameter: pow_min_bsd
	__parameterTypeNames[2] = "System.Double";
	__parameterTypes[2] = (CDOTNET_DOUBLE);
	__parameters[2] = &pow_min_bsd;

	// Pre-process parameter: pow_min_rcta
	__parameterTypeNames[3] = "System.Double";
	__parameterTypes[3] = (CDOTNET_DOUBLE);
	__parameters[3] = &pow_min_rcta;

	// Pre-process parameter: power
	__parameterTypeNames[4] = "System.Double[]&";
	__parameterTypes[4] = (CDOTNET_DOUBLE | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[4] = &power__;

	// Pre-process parameter: amp
	__parameterTypeNames[5] = "System.UInt16[]&";
	__parameterTypes[5] = (CDOTNET_UINT16 | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[5] = &amp__;

	// Pre-process parameter: sw
	__parameterTypeNames[6] = "System.UInt16[]&";
	__parameterTypes[6] = (CDOTNET_UINT16 | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[6] = &sw__;

	// Pre-process parameter: pdet
	__parameterTypeNames[7] = "System.UInt16[]&";
	__parameterTypes[7] = (CDOTNET_UINT16 | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[7] = &pdet__;

	// Pre-process parameter: thermistor
	__parameterTypeNames[8] = "System.UInt16&";
	__parameterTypes[8] = (CDOTNET_UINT16 | CDOTNET_OUT);
	__parameters[8] = thermistor;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTests", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"TxPowerCalVEVA", 
		0, 
		0, 
		9, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));

	// Post-process parameter: power
	if (power__) {
		__errChk(CDotNetGetArrayElements(
			power__, 
			CDOTNET_DOUBLE, 
			0, 
			power));
		__errChk(CDotNetGetArrayLength(
			power__, 
			0, 
			__powerLength));
	}

	// Post-process parameter: amp
	if (amp__) {
		__errChk(CDotNetGetArrayElements(
			amp__, 
			CDOTNET_UINT16, 
			0, 
			amp));
		__errChk(CDotNetGetArrayLength(
			amp__, 
			0, 
			__ampLength));
	}

	// Post-process parameter: sw
	if (sw__) {
		__errChk(CDotNetGetArrayElements(
			sw__, 
			CDOTNET_UINT16, 
			0, 
			sw));
		__errChk(CDotNetGetArrayLength(
			sw__, 
			0, 
			__swLength));
	}

	// Post-process parameter: pdet
	if (pdet__) {
		__errChk(CDotNetGetArrayElements(
			pdet__, 
			CDOTNET_UINT16, 
			0, 
			pdet));
		__errChk(CDotNetGetArrayLength(
			pdet__, 
			0, 
			__pdetLength));
	}


__Error:
	if (power__)
		CDotNetDiscardHandle(power__);
	if (amp__)
		CDotNetDiscardHandle(amp__);
	if (sw__)
		CDotNetDiscardHandle(sw__);
	if (pdet__)
		CDotNetDiscardHandle(pdet__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			power, 
			CDOTNET_DOUBLE, 
			1, 
			__powerLength);
		_CDotNetGenDisposeArray(
			amp, 
			CDOTNET_UINT16, 
			1, 
			__ampLength);
		_CDotNetGenDisposeArray(
			sw, 
			CDOTNET_UINT16, 
			1, 
			__swLength);
		_CDotNetGenDisposeArray(
			pdet, 
			CDOTNET_UINT16, 
			1, 
			__pdetLength);
	}
	return __error;
}


// Type: Alv.Test.Mfg.MfgCoffinSettings
int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Create(
	Alv_Test_Mfg_MfgCoffinSettings * __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffinSettings", 
		0, 
		0, 
		__instance, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings_Load(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	char * path,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: path
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &path;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffinSettings", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Load", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Get__Enabled(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffinSettings", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"Enabled", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Set__Enabled(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	int Enabled,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: Enabled
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &Enabled;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffinSettings", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"Enabled", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Get__GPIBInterface(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffinSettings", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"GPIBInterface", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Set__GPIBInterface(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	int GPIBInterface,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: GPIBInterface
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &GPIBInterface;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffinSettings", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"GPIBInterface", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Get__PowerSupplyGPIB(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffinSettings", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"PowerSupplyGPIB", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Set__PowerSupplyGPIB(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	int PowerSupplyGPIB,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: PowerSupplyGPIB
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &PowerSupplyGPIB;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffinSettings", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"PowerSupplyGPIB", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Get__ControlPower(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffinSettings", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"ControlPower", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Set__ControlPower(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	int ControlPower,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: ControlPower
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &ControlPower;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffinSettings", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"ControlPower", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Get__SensorVoltage(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffinSettings", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"SensorVoltage", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Set__SensorVoltage(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	double SensorVoltage,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: SensorVoltage
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &SensorVoltage;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffinSettings", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"SensorVoltage", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Get__WarmupDelay(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffinSettings", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"WarmupDelay", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Set__WarmupDelay(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	int WarmupDelay,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: WarmupDelay
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &WarmupDelay;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffinSettings", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"WarmupDelay", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Get__UsePowerMeter(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffinSettings", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"UsePowerMeter", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Set__UsePowerMeter(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	int UsePowerMeter,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: UsePowerMeter
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &UsePowerMeter;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffinSettings", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"UsePowerMeter", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Get__PowerMeterGPIB(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffinSettings", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"PowerMeterGPIB", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Set__PowerMeterGPIB(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	int PowerMeterGPIB,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: PowerMeterGPIB
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &PowerMeterGPIB;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffinSettings", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"PowerMeterGPIB", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Get__PowerMeterOffset(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffinSettings", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"PowerMeterOffset", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Set__PowerMeterOffset(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	double PowerMeterOffset,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: PowerMeterOffset
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &PowerMeterOffset;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffinSettings", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"PowerMeterOffset", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Get__PowerSamples(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffinSettings", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"PowerSamples", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Set__PowerSamples(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	int PowerSamples,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: PowerSamples
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &PowerSamples;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffinSettings", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"PowerSamples", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Get__RfLength(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffinSettings", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"RfLength", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Set__RfLength(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	double RfLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: RfLength
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &RfLength;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffinSettings", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"RfLength", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Get__RangeWindow(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffinSettings", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"RangeWindow", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Set__RangeWindow(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	double RangeWindow,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: RangeWindow
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &RangeWindow;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffinSettings", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"RangeWindow", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Get__RangeBin(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffinSettings", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"RangeBin", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Set__RangeBin(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	int RangeBin,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: RangeBin
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &RangeBin;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffinSettings", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"RangeBin", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Get__LoadAngle(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffinSettings", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"LoadAngle", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Set__LoadAngle(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	double LoadAngle,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: LoadAngle
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &LoadAngle;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffinSettings", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"LoadAngle", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Get__LinearRange(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffinSettings", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"LinearRange", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Set__LinearRange(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	double LinearRange,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: LinearRange
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &LinearRange;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffinSettings", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"LinearRange", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Get__RehomeVelmex(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffinSettings", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"RehomeVelmex", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Set__RehomeVelmex(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	int RehomeVelmex,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: RehomeVelmex
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &RehomeVelmex;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffinSettings", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"RehomeVelmex", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Get__DcOffsetAngle(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffinSettings", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"DcOffsetAngle", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffinSettings__Set__DcOffsetAngle(
	Alv_Test_Mfg_MfgCoffinSettings __instance,
	double DcOffsetAngle,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: DcOffsetAngle
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &DcOffsetAngle;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffinSettings", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"DcOffsetAngle", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}


// Type: Alv.Test.Mfg.MfgCoffin
int CVIFUNC Alv_Test_Mfg_MfgCoffin__Create(
	Alv_Test_Mfg_MfgCoffin * __instance,
	char * settings_path,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: settings_path
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &settings_path;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffin", 
		0, 
		0, 
		__instance, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffin_Get_LinSpeed(
	Alv_Test_Mfg_MfgCoffin __instance,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffin", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"LinSpeed", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffin_Set_LinSpeed(
	Alv_Test_Mfg_MfgCoffin __instance,
	double value,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: value
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &value;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffin", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"LinSpeed", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffin_Get_AngSpeed(
	Alv_Test_Mfg_MfgCoffin __instance,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffin", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"AngSpeed", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffin_Set_AngSpeed(
	Alv_Test_Mfg_MfgCoffin __instance,
	double value,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: value
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &value;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffin", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"AngSpeed", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffin_Get_Distance(
	Alv_Test_Mfg_MfgCoffin __instance,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffin", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Distance", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffin_Set_Distance(
	Alv_Test_Mfg_MfgCoffin __instance,
	double value,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: value
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &value;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffin", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"Distance", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffin_Get_Angle(
	Alv_Test_Mfg_MfgCoffin __instance,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffin", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Angle", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffin_Set_Angle(
	Alv_Test_Mfg_MfgCoffin __instance,
	double value,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: value
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &value;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffin", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"Angle", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffin_ConnectVelmex(
	Alv_Test_Mfg_MfgCoffin __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffin", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ConnectVelmex", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffin_ConnectSensorPower(
	Alv_Test_Mfg_MfgCoffin __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffin", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ConnectSensorPower", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffin_ConnectPowerMeter(
	Alv_Test_Mfg_MfgCoffin __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffin", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ConnectPowerMeter", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffin_ConnectAll(
	Alv_Test_Mfg_MfgCoffin __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffin", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ConnectAll", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffin_CloseAll(
	Alv_Test_Mfg_MfgCoffin __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffin", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"CloseAll", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffin_SetLinMotion(
	Alv_Test_Mfg_MfgCoffin __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffin", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"SetLinMotion", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffin_StopMotion(
	Alv_Test_Mfg_MfgCoffin __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffin", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"StopMotion", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffin_LoadAngle(
	Alv_Test_Mfg_MfgCoffin __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffin", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"LoadAngle", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffin_GetChannelPower(
	Alv_Test_Mfg_MfgCoffin __instance,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffin", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GetChannelPower", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffin_SetOutput(
	Alv_Test_Mfg_MfgCoffin __instance,
	double voltage,
	double current,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: voltage
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &voltage;

	// Pre-process parameter: current
	__parameterTypeNames[1] = "System.Double";
	__parameterTypes[1] = (CDOTNET_DOUBLE);
	__parameters[1] = &current;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffin", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"SetOutput", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffin_ControlPower(
	Alv_Test_Mfg_MfgCoffin __instance,
	int on,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: on
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &on;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffin", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ControlPower", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffin_GetCurrent(
	Alv_Test_Mfg_MfgCoffin __instance,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffin", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GetCurrent", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffin_GetVoltage(
	Alv_Test_Mfg_MfgCoffin __instance,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffin", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GetVoltage", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffin__Get__settings(
	Alv_Test_Mfg_MfgCoffin __instance,
	Alv_Test_Mfg_MfgCoffinSettings * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffin", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"settings", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgCoffin__Set__settings(
	Alv_Test_Mfg_MfgCoffin __instance,
	Alv_Test_Mfg_MfgCoffinSettings settings,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: settings
	__parameterTypeNames[0] = "Alv.Test.Mfg.MfgCoffinSettings";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &settings;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgCoffin", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"settings", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}


// Type: Alv.Test.SensorState
int CVIFUNC Alv_Test_SensorState__Create(
	Alv_Test_SensorState * __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"Alv.Test.SensorState", 
		0, 
		0, 
		__instance, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_SensorState__Get__CwMode(
	Alv_Test_SensorState __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorState", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"CwMode", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_SensorState__Set__CwMode(
	Alv_Test_SensorState __instance,
	int CwMode,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: CwMode
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &CwMode;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorState", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"CwMode", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_SensorState__Get__Antenna(
	Alv_Test_SensorState __instance,
	Alv_NarrowBand_NBProtocol_Antenna * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorState", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"Antenna", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_Test_SensorState__Set__Antenna(
	Alv_Test_SensorState __instance,
	Alv_NarrowBand_NBProtocol_Antenna Antenna,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle Antenna__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: Antenna
	__errChk(Alv_NarrowBand_NBProtocol_Antenna__Create(
		&Antenna, 
		&Antenna__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+Antenna,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &Antenna__;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorState", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"Antenna", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (Antenna__)
		CDotNetDiscardHandle(Antenna__);
	return __error;
}

int CVIFUNC Alv_Test_SensorState__Get__RF(
	Alv_Test_SensorState __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorState", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"RF", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_SensorState__Set__RF(
	Alv_Test_SensorState __instance,
	int RF,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: RF
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &RF;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorState", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"RF", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_SensorState__Get__RadarRx(
	Alv_Test_SensorState __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorState", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"RadarRx", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_SensorState__Set__RadarRx(
	Alv_Test_SensorState __instance,
	int RadarRx,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: RadarRx
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &RadarRx;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorState", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"RadarRx", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_SensorState__Get__DCOffset(
	Alv_Test_SensorState __instance,
	Alv_NarrowBand_NBProtocol_DCOffset * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorState", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"DCOffset", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_Test_SensorState__Set__DCOffset(
	Alv_Test_SensorState __instance,
	Alv_NarrowBand_NBProtocol_DCOffset DCOffset,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle DCOffset__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: DCOffset
	__errChk(Alv_NarrowBand_NBProtocol_DCOffset__Create(
		&DCOffset, 
		&DCOffset__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+DCOffset,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &DCOffset__;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorState", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"DCOffset", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (DCOffset__)
		CDotNetDiscardHandle(DCOffset__);
	return __error;
}

int CVIFUNC Alv_Test_SensorState__Get__StaticTestMode(
	Alv_Test_SensorState __instance,
	Alv_NarrowBand_NBProtocol_StaticTestMode * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorState", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"StaticTestMode", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_Test_SensorState__Set__StaticTestMode(
	Alv_Test_SensorState __instance,
	Alv_NarrowBand_NBProtocol_StaticTestMode StaticTestMode,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle StaticTestMode__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: StaticTestMode
	__errChk(Alv_NarrowBand_NBProtocol_StaticTestMode__Create(
		&StaticTestMode, 
		&StaticTestMode__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+StaticTestMode,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &StaticTestMode__;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorState", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"StaticTestMode", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (StaticTestMode__)
		CDotNetDiscardHandle(StaticTestMode__);
	return __error;
}

int CVIFUNC Alv_Test_SensorState__Get__PulseJitter(
	Alv_Test_SensorState __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorState", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"PulseJitter", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_SensorState__Set__PulseJitter(
	Alv_Test_SensorState __instance,
	int PulseJitter,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: PulseJitter
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &PulseJitter;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorState", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"PulseJitter", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_SensorState__Get__RadarMode(
	Alv_Test_SensorState __instance,
	Alv_NarrowBand_NBProtocol_ControlRadarMode * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorState", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"RadarMode", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_Test_SensorState__Set__RadarMode(
	Alv_Test_SensorState __instance,
	Alv_NarrowBand_NBProtocol_ControlRadarMode RadarMode,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle RadarMode__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: RadarMode
	__errChk(Alv_NarrowBand_NBProtocol_ControlRadarMode__Create(
		&RadarMode, 
		&RadarMode__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+ControlRadarMode,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &RadarMode__;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorState", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"RadarMode", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (RadarMode__)
		CDotNetDiscardHandle(RadarMode__);
	return __error;
}

int CVIFUNC Alv_Test_SensorState__Get__EngineeringMode(
	Alv_Test_SensorState __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorState", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"EngineeringMode", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_SensorState__Set__EngineeringMode(
	Alv_Test_SensorState __instance,
	int EngineeringMode,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: EngineeringMode
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &EngineeringMode;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorState", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"EngineeringMode", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_SensorState__Get__TempComp(
	Alv_Test_SensorState __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorState", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"TempComp", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_SensorState__Set__TempComp(
	Alv_Test_SensorState __instance,
	int TempComp,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: TempComp
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &TempComp;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorState", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"TempComp", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}


// Type: Alv.Test.SensorControl
int CVIFUNC Alv_Test_SensorControl__Create(
	Alv_Test_SensorControl * __instance,
	Alv_NarrowBand_Sensor Communicator,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: Communicator
	__parameterTypeNames[0] = "Alv.NarrowBand.Sensor,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &Communicator;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		0, 
		0, 
		__instance, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_Get_Status(
	Alv_Test_SensorControl __instance,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Status", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_Get_CwMode(
	Alv_Test_SensorControl __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"CwMode", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_Set_CwMode(
	Alv_Test_SensorControl __instance,
	int value,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: value
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &value;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"CwMode", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_Get_Antenna(
	Alv_Test_SensorControl __instance,
	Alv_NarrowBand_NBProtocol_Antenna * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Antenna", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_Set_Antenna(
	Alv_Test_SensorControl __instance,
	Alv_NarrowBand_NBProtocol_Antenna value,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle value__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: value
	__errChk(Alv_NarrowBand_NBProtocol_Antenna__Create(
		&value, 
		&value__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+Antenna,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &value__;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"Antenna", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (value__)
		CDotNetDiscardHandle(value__);
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_Get_RF(
	Alv_Test_SensorControl __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"RF", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_Set_RF(
	Alv_Test_SensorControl __instance,
	int value,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: value
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &value;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"RF", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_Get_RadarRx(
	Alv_Test_SensorControl __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"RadarRx", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_Set_RadarRx(
	Alv_Test_SensorControl __instance,
	int value,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: value
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &value;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"RadarRx", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_Get_HardwareOffset(
	Alv_Test_SensorControl __instance,
	Alv_NarrowBand_NBProtocol_DCOffset * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"HardwareOffset", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_Set_HardwareOffset(
	Alv_Test_SensorControl __instance,
	Alv_NarrowBand_NBProtocol_DCOffset value,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle value__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: value
	__errChk(Alv_NarrowBand_NBProtocol_DCOffset__Create(
		&value, 
		&value__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+DCOffset,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &value__;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"HardwareOffset", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (value__)
		CDotNetDiscardHandle(value__);
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_Get_SoftwareOffset(
	Alv_Test_SensorControl __instance,
	Alv_NarrowBand_NBProtocol_DCOffset * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"SoftwareOffset", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_Set_SoftwareOffset(
	Alv_Test_SensorControl __instance,
	Alv_NarrowBand_NBProtocol_DCOffset value,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle value__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: value
	__errChk(Alv_NarrowBand_NBProtocol_DCOffset__Create(
		&value, 
		&value__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+DCOffset,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &value__;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"SoftwareOffset", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (value__)
		CDotNetDiscardHandle(value__);
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_Get_StaticTestMode(
	Alv_Test_SensorControl __instance,
	Alv_NarrowBand_NBProtocol_StaticTestMode * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"StaticTestMode", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_Set_StaticTestMode(
	Alv_Test_SensorControl __instance,
	Alv_NarrowBand_NBProtocol_StaticTestMode value,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle value__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: value
	__errChk(Alv_NarrowBand_NBProtocol_StaticTestMode__Create(
		&value, 
		&value__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+StaticTestMode,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &value__;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"StaticTestMode", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (value__)
		CDotNetDiscardHandle(value__);
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_Get_PulseJitter(
	Alv_Test_SensorControl __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"PulseJitter", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_Set_PulseJitter(
	Alv_Test_SensorControl __instance,
	int value,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: value
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &value;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"PulseJitter", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_Get_RadarMode(
	Alv_Test_SensorControl __instance,
	Alv_NarrowBand_NBProtocol_ControlRadarMode * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"RadarMode", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_Set_RadarMode(
	Alv_Test_SensorControl __instance,
	Alv_NarrowBand_NBProtocol_ControlRadarMode value,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle value__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: value
	__errChk(Alv_NarrowBand_NBProtocol_ControlRadarMode__Create(
		&value, 
		&value__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+ControlRadarMode,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &value__;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"RadarMode", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (value__)
		CDotNetDiscardHandle(value__);
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_Get_EngineeringMode(
	Alv_Test_SensorControl __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"EngineeringMode", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_Set_EngineeringMode(
	Alv_Test_SensorControl __instance,
	int value,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: value
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &value;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"EngineeringMode", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_Get_TempComp(
	Alv_Test_SensorControl __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"TempComp", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_Set_TempComp(
	Alv_Test_SensorControl __instance,
	int value,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: value
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &value;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"TempComp", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_Get_Serial(
	Alv_Test_SensorControl __instance,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Serial", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_Get_Architecture(
	Alv_Test_SensorControl __instance,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Architecture", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_Get_HardwareType(
	Alv_Test_SensorControl __instance,
	Alv_Test_HardwareTypes * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"HardwareType", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_Get_HpAppVersion(
	Alv_Test_SensorControl __instance,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"HpAppVersion", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_Get_HpBootVersion(
	Alv_Test_SensorControl __instance,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"HpBootVersion", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_Get_DspAppVersion(
	Alv_Test_SensorControl __instance,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"DspAppVersion", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_Get_DspBootVersion(
	Alv_Test_SensorControl __instance,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"DspBootVersion", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_Get_BsdTargetTreshold(
	Alv_Test_SensorControl __instance,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"BsdTargetTreshold", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_Set_BsdTargetTreshold(
	Alv_Test_SensorControl __instance,
	double value,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: value
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &value;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"BsdTargetTreshold", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_Get_Thermistor(
	Alv_Test_SensorControl __instance,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Thermistor", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_Clear(
	Alv_Test_SensorControl __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Clear", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_GetComm(
	Alv_Test_SensorControl __instance,
	Alv_NarrowBand_Sensor * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GetComm", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_GetSerial(
	Alv_Test_SensorControl __instance,
	char ** serial,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;
	*serial = 0;


	// Pre-process parameter: serial
	__parameterTypeNames[0] = "System.String&";
	__parameterTypes[0] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[0] = serial;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GetSerial", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			serial, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_GetArchitecture(
	Alv_Test_SensorControl __instance,
	char ** arch,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;
	*arch = 0;


	// Pre-process parameter: arch
	__parameterTypeNames[0] = "System.String&";
	__parameterTypes[0] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[0] = arch;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GetArchitecture", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			arch, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_GetHwType(
	Alv_Test_SensorControl __instance,
	unsigned short * rev,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: rev
	__parameterTypeNames[0] = "System.UInt16&";
	__parameterTypes[0] = (CDOTNET_UINT16 | CDOTNET_OUT);
	__parameters[0] = rev;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GetHwType", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_GetPartNumber(
	Alv_Test_SensorControl __instance,
	char *** part_number,
	ssize_t * __part_numberLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle part_number__ = 0;

	if (__exception)
		*__exception = 0;
	*part_number = 0;
	*__part_numberLength = 0;


	// Pre-process parameter: part_number
	__parameterTypeNames[0] = "System.String[]&";
	__parameterTypes[0] = (CDOTNET_STRING | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[0] = &part_number__;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GetPartNumber", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));

	// Post-process parameter: part_number
	if (part_number__) {
		__errChk(CDotNetGetArrayElements(
			part_number__, 
			CDOTNET_STRING, 
			0, 
			part_number));
		__errChk(CDotNetGetArrayLength(
			part_number__, 
			0, 
			__part_numberLength));
	}


__Error:
	if (part_number__)
		CDotNetDiscardHandle(part_number__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			part_number, 
			CDOTNET_STRING, 
			1, 
			__part_numberLength);
	}
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_GetSwVersion(
	Alv_Test_SensorControl __instance,
	char *** sw_version,
	ssize_t * __sw_versionLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle sw_version__ = 0;

	if (__exception)
		*__exception = 0;
	*sw_version = 0;
	*__sw_versionLength = 0;


	// Pre-process parameter: sw_version
	__parameterTypeNames[0] = "System.String[]&";
	__parameterTypes[0] = (CDOTNET_STRING | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[0] = &sw_version__;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GetSwVersion", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));

	// Post-process parameter: sw_version
	if (sw_version__) {
		__errChk(CDotNetGetArrayElements(
			sw_version__, 
			CDOTNET_STRING, 
			0, 
			sw_version));
		__errChk(CDotNetGetArrayLength(
			sw_version__, 
			0, 
			__sw_versionLength));
	}


__Error:
	if (sw_version__)
		CDotNetDiscardHandle(sw_version__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			sw_version, 
			CDOTNET_STRING, 
			1, 
			__sw_versionLength);
	}
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_GetSwVersion_1(
	Alv_Test_SensorControl __instance,
	char ** HpApp,
	char ** HpBoot,
	char ** DspApp,
	char ** DspBoot,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];

	if (__exception)
		*__exception = 0;
	*HpApp = 0;
	*HpBoot = 0;
	*DspApp = 0;
	*DspBoot = 0;


	// Pre-process parameter: HpApp
	__parameterTypeNames[0] = "System.String&";
	__parameterTypes[0] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[0] = HpApp;

	// Pre-process parameter: HpBoot
	__parameterTypeNames[1] = "System.String&";
	__parameterTypes[1] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[1] = HpBoot;

	// Pre-process parameter: DspApp
	__parameterTypeNames[2] = "System.String&";
	__parameterTypes[2] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[2] = DspApp;

	// Pre-process parameter: DspBoot
	__parameterTypeNames[3] = "System.String&";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[3] = DspBoot;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GetSwVersion", 
		0, 
		0, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			HpApp, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			HpBoot, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			DspApp, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			DspBoot, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_GetPointsVersion(
	Alv_Test_SensorControl __instance,
	char *** point_version,
	ssize_t * __point_versionLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle point_version__ = 0;

	if (__exception)
		*__exception = 0;
	*point_version = 0;
	*__point_versionLength = 0;


	// Pre-process parameter: point_version
	__parameterTypeNames[0] = "System.String[]&";
	__parameterTypes[0] = (CDOTNET_STRING | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[0] = &point_version__;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GetPointsVersion", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));

	// Post-process parameter: point_version
	if (point_version__) {
		__errChk(CDotNetGetArrayElements(
			point_version__, 
			CDOTNET_STRING, 
			0, 
			point_version));
		__errChk(CDotNetGetArrayLength(
			point_version__, 
			0, 
			__point_versionLength));
	}


__Error:
	if (point_version__)
		CDotNetDiscardHandle(point_version__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			point_version, 
			CDOTNET_STRING, 
			1, 
			__point_versionLength);
	}
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_SaveConfiguration(
	Alv_Test_SensorControl __instance,
	Alv_NarrowBand_NBProtocol_ConfigurationBlock block,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle block__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: block
	__errChk(Alv_NarrowBand_NBProtocol_ConfigurationBlock__Create(
		&block, 
		&block__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+ConfigurationBlock,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &block__;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"SaveConfiguration", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (block__)
		CDotNetDiscardHandle(block__);
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_ReloadConfiguration(
	Alv_Test_SensorControl __instance,
	Alv_NarrowBand_NBProtocol_ConfigurationBlock block,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle block__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: block
	__errChk(Alv_NarrowBand_NBProtocol_ConfigurationBlock__Create(
		&block, 
		&block__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+ConfigurationBlock,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &block__;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ReloadConfiguration", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (block__)
		CDotNetDiscardHandle(block__);
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_ResetConfiguration(
	Alv_Test_SensorControl __instance,
	Alv_NarrowBand_NBProtocol_ConfigurationBlock block,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle block__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: block
	__errChk(Alv_NarrowBand_NBProtocol_ConfigurationBlock__Create(
		&block, 
		&block__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+ConfigurationBlock,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &block__;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ResetConfiguration", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (block__)
		CDotNetDiscardHandle(block__);
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_ResetProcessor(
	Alv_Test_SensorControl __instance,
	Alv_NarrowBand_NBProtocol_Processor processor,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle processor__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: processor
	__errChk(Alv_NarrowBand_NBProtocol_Processor__Create(
		&processor, 
		&processor__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+Processor,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &processor__;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ResetProcessor", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (processor__)
		CDotNetDiscardHandle(processor__);
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_ControlLED(
	Alv_Test_SensorControl __instance,
	Alv_NarrowBand_NBProtocol_Processor processor,
	Alv_NarrowBand_NBProtocol_TestLED control,
	unsigned short interval,
	unsigned short timeOut,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];
	CDotNetHandle processor__ = 0;
	CDotNetHandle control__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: processor
	__errChk(Alv_NarrowBand_NBProtocol_Processor__Create(
		&processor, 
		&processor__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+Processor,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &processor__;

	// Pre-process parameter: control
	__errChk(Alv_NarrowBand_NBProtocol_TestLED__Create(
		&control, 
		&control__, 
		__exception));
	__parameterTypeNames[1] = "Alv.NarrowBand.NBProtocol+TestLED,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[1] = (CDOTNET_ENUM);
	__parameters[1] = &control__;

	// Pre-process parameter: interval
	__parameterTypeNames[2] = "System.UInt16";
	__parameterTypes[2] = (CDOTNET_UINT16);
	__parameters[2] = &interval;

	// Pre-process parameter: timeOut
	__parameterTypeNames[3] = "System.UInt16";
	__parameterTypes[3] = (CDOTNET_UINT16);
	__parameters[3] = &timeOut;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ControlLED", 
		0, 
		0, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (processor__)
		CDotNetDiscardHandle(processor__);
	if (control__)
		CDotNetDiscardHandle(control__);
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_PerformSelfTest(
	Alv_Test_SensorControl __instance,
	Alv_NarrowBand_NBProtocol_Processor processor,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle processor__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: processor
	__errChk(Alv_NarrowBand_NBProtocol_Processor__Create(
		&processor, 
		&processor__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+Processor,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &processor__;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"PerformSelfTest", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (processor__)
		CDotNetDiscardHandle(processor__);
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_RunOffsetInitialization(
	Alv_Test_SensorControl __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RunOffsetInitialization", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_RawSweepBroadcast(
	Alv_Test_SensorControl __instance,
	Alv_NarrowBand_NBProtocol_Processor processor,
	unsigned char control,
	unsigned short count,
	unsigned char type,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];
	CDotNetHandle processor__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: processor
	__errChk(Alv_NarrowBand_NBProtocol_Processor__Create(
		&processor, 
		&processor__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+Processor,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &processor__;

	// Pre-process parameter: control
	__parameterTypeNames[1] = "System.Byte";
	__parameterTypes[1] = (CDOTNET_BYTE);
	__parameters[1] = &control;

	// Pre-process parameter: count
	__parameterTypeNames[2] = "System.UInt16";
	__parameterTypes[2] = (CDOTNET_UINT16);
	__parameters[2] = &count;

	// Pre-process parameter: type
	__parameterTypeNames[3] = "System.Byte";
	__parameterTypes[3] = (CDOTNET_BYTE);
	__parameters[3] = &type;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RawSweepBroadcast", 
		0, 
		0, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (processor__)
		CDotNetDiscardHandle(processor__);
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_ReadManufacturingData(
	Alv_Test_SensorControl __instance,
	unsigned char ** data,
	ssize_t * __dataLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle data__ = 0;

	if (__exception)
		*__exception = 0;
	*data = 0;
	*__dataLength = 0;


	// Pre-process parameter: data
	__parameterTypeNames[0] = "System.Byte[]&";
	__parameterTypes[0] = (CDOTNET_BYTE | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[0] = &data__;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ReadManufacturingData", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));

	// Post-process parameter: data
	if (data__) {
		__errChk(CDotNetGetArrayElements(
			data__, 
			CDOTNET_BYTE, 
			0, 
			data));
		__errChk(CDotNetGetArrayLength(
			data__, 
			0, 
			__dataLength));
	}


__Error:
	if (data__)
		CDotNetDiscardHandle(data__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			data, 
			CDOTNET_BYTE, 
			1, 
			__dataLength);
	}
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_GetPoint(
	Alv_Test_SensorControl __instance,
	unsigned short point,
	unsigned int * value,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: point
	__parameterTypeNames[0] = "System.UInt16";
	__parameterTypes[0] = (CDOTNET_UINT16);
	__parameters[0] = &point;

	// Pre-process parameter: value
	__parameterTypeNames[1] = "System.UInt32&";
	__parameterTypes[1] = (CDOTNET_UINT32 | CDOTNET_OUT);
	__parameters[1] = value;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GetPoint", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_GetPoint_1(
	Alv_Test_SensorControl __instance,
	unsigned short point,
	unsigned short * value,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: point
	__parameterTypeNames[0] = "System.UInt16";
	__parameterTypes[0] = (CDOTNET_UINT16);
	__parameters[0] = &point;

	// Pre-process parameter: value
	__parameterTypeNames[1] = "System.UInt16&";
	__parameterTypes[1] = (CDOTNET_UINT16 | CDOTNET_OUT);
	__parameters[1] = value;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GetPoint", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_GetPoint_2(
	Alv_Test_SensorControl __instance,
	unsigned short point,
	int * value,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: point
	__parameterTypeNames[0] = "System.UInt16";
	__parameterTypes[0] = (CDOTNET_UINT16);
	__parameters[0] = &point;

	// Pre-process parameter: value
	__parameterTypeNames[1] = "System.Int32&";
	__parameterTypes[1] = (CDOTNET_INT32 | CDOTNET_OUT);
	__parameters[1] = value;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GetPoint", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_GetPoint_3(
	Alv_Test_SensorControl __instance,
	unsigned short point,
	double * value,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: point
	__parameterTypeNames[0] = "System.UInt16";
	__parameterTypes[0] = (CDOTNET_UINT16);
	__parameters[0] = &point;

	// Pre-process parameter: value
	__parameterTypeNames[1] = "System.Double&";
	__parameterTypes[1] = (CDOTNET_DOUBLE | CDOTNET_OUT);
	__parameters[1] = value;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GetPoint", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_GetPoint_4(
	Alv_Test_SensorControl __instance,
	unsigned short point,
	char ** value,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;
	*value = 0;


	// Pre-process parameter: point
	__parameterTypeNames[0] = "System.UInt16";
	__parameterTypes[0] = (CDOTNET_UINT16);
	__parameters[0] = &point;

	// Pre-process parameter: value
	__parameterTypeNames[1] = "System.String&";
	__parameterTypes[1] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[1] = value;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GetPoint", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			value, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_SetPoint(
	Alv_Test_SensorControl __instance,
	unsigned short point,
	CDotNetHandle value,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: point
	__parameterTypeNames[0] = "System.UInt16";
	__parameterTypes[0] = (CDOTNET_UINT16);
	__parameters[0] = &point;

	// Pre-process parameter: value
	__parameterTypeNames[1] = "System.Object";
	__parameterTypes[1] = (CDOTNET_OBJECT);
	__parameters[1] = &value;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"SetPoint", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_GetSweep(
	Alv_Test_SensorControl __instance,
	CDotNetHandle * sweep_data,
	unsigned short count,
	Alv_NarrowBand_NBProtocol_ControlRadarMode mode,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];
	CDotNetHandle mode__ = 0;

	if (__exception)
		*__exception = 0;
	*sweep_data = 0;


	// Pre-process parameter: sweep_data
	__parameterTypeNames[0] = "System.Byte[][]&";
	__parameterTypes[0] = (CDOTNET_OBJECT | CDOTNET_OUT);
	__parameters[0] = sweep_data;

	// Pre-process parameter: count
	__parameterTypeNames[1] = "System.UInt16";
	__parameterTypes[1] = (CDOTNET_UINT16);
	__parameters[1] = &count;

	// Pre-process parameter: mode
	__errChk(Alv_NarrowBand_NBProtocol_ControlRadarMode__Create(
		&mode, 
		&mode__, 
		__exception));
	__parameterTypeNames[2] = "Alv.NarrowBand.NBProtocol+ControlRadarMode,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[2] = (CDOTNET_ENUM);
	__parameters[2] = &mode__;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GetSweep", 
		0, 
		0, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (mode__)
		CDotNetDiscardHandle(mode__);
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			sweep_data, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_SetLiveGain(
	Alv_Test_SensorControl __instance,
	unsigned short amp,
	unsigned short sw,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: amp
	__parameterTypeNames[0] = "System.UInt16";
	__parameterTypes[0] = (CDOTNET_UINT16);
	__parameters[0] = &amp;

	// Pre-process parameter: sw
	__parameterTypeNames[1] = "System.UInt16";
	__parameterTypes[1] = (CDOTNET_UINT16);
	__parameters[1] = &sw;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"SetLiveGain", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_RestoreLiveGain(
	Alv_Test_SensorControl __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RestoreLiveGain", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_GetCalGain(
	Alv_Test_SensorControl __instance,
	Alv_NarrowBand_NBProtocol_Antenna antenna,
	Alv_NarrowBand_NBProtocol_ControlRadarMode mode,
	unsigned short * amp,
	unsigned short * sw,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];
	CDotNetHandle antenna__ = 0;
	CDotNetHandle mode__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: antenna
	__errChk(Alv_NarrowBand_NBProtocol_Antenna__Create(
		&antenna, 
		&antenna__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+Antenna,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &antenna__;

	// Pre-process parameter: mode
	__errChk(Alv_NarrowBand_NBProtocol_ControlRadarMode__Create(
		&mode, 
		&mode__, 
		__exception));
	__parameterTypeNames[1] = "Alv.NarrowBand.NBProtocol+ControlRadarMode,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[1] = (CDOTNET_ENUM);
	__parameters[1] = &mode__;

	// Pre-process parameter: amp
	__parameterTypeNames[2] = "System.UInt16&";
	__parameterTypes[2] = (CDOTNET_UINT16 | CDOTNET_OUT);
	__parameters[2] = amp;

	// Pre-process parameter: sw
	__parameterTypeNames[3] = "System.UInt16&";
	__parameterTypes[3] = (CDOTNET_UINT16 | CDOTNET_OUT);
	__parameters[3] = sw;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GetCalGain", 
		0, 
		0, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (antenna__)
		CDotNetDiscardHandle(antenna__);
	if (mode__)
		CDotNetDiscardHandle(mode__);
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_SetCalGain(
	Alv_Test_SensorControl __instance,
	Alv_NarrowBand_NBProtocol_Antenna antenna,
	Alv_NarrowBand_NBProtocol_ControlRadarMode mode,
	unsigned short amp,
	unsigned short sw,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];
	CDotNetHandle antenna__ = 0;
	CDotNetHandle mode__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: antenna
	__errChk(Alv_NarrowBand_NBProtocol_Antenna__Create(
		&antenna, 
		&antenna__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+Antenna,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &antenna__;

	// Pre-process parameter: mode
	__errChk(Alv_NarrowBand_NBProtocol_ControlRadarMode__Create(
		&mode, 
		&mode__, 
		__exception));
	__parameterTypeNames[1] = "Alv.NarrowBand.NBProtocol+ControlRadarMode,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[1] = (CDOTNET_ENUM);
	__parameters[1] = &mode__;

	// Pre-process parameter: amp
	__parameterTypeNames[2] = "System.UInt16";
	__parameterTypes[2] = (CDOTNET_UINT16);
	__parameters[2] = &amp;

	// Pre-process parameter: sw
	__parameterTypeNames[3] = "System.UInt16";
	__parameterTypes[3] = (CDOTNET_UINT16);
	__parameters[3] = &sw;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"SetCalGain", 
		0, 
		0, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (antenna__)
		CDotNetDiscardHandle(antenna__);
	if (mode__)
		CDotNetDiscardHandle(mode__);
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_SetStMmicFrequency(
	Alv_Test_SensorControl __instance,
	double frequency,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: frequency
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &frequency;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"SetStMmicFrequency", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_SetFrequencyComp(
	Alv_Test_SensorControl __instance,
	Alv_NarrowBand_NBProtocol_Antenna antenna,
	unsigned short comp,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	CDotNetHandle antenna__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: antenna
	__errChk(Alv_NarrowBand_NBProtocol_Antenna__Create(
		&antenna, 
		&antenna__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+Antenna,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &antenna__;

	// Pre-process parameter: comp
	__parameterTypeNames[1] = "System.UInt16";
	__parameterTypes[1] = (CDOTNET_UINT16);
	__parameters[1] = &comp;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"SetFrequencyComp", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (antenna__)
		CDotNetDiscardHandle(antenna__);
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_ClearQueue(
	Alv_Test_SensorControl __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ClearQueue", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_ReadDspDiag(
	Alv_Test_SensorControl __instance,
	Alv_NarrowBand_DSP_DIAG * msg,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	*msg = 0;


	// Pre-process parameter: msg
	__parameterTypeNames[0] = "Alv.NarrowBand.DSP_DIAG&,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[0] = (CDOTNET_OBJECT | CDOTNET_OUT);
	__parameters[0] = msg;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ReadDspDiag", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			msg, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_ReadHpDiag(
	Alv_Test_SensorControl __instance,
	Alv_NarrowBand_HP_DIAG * msg,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	*msg = 0;


	// Pre-process parameter: msg
	__parameterTypeNames[0] = "Alv.NarrowBand.HP_DIAG&,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[0] = (CDOTNET_OBJECT | CDOTNET_OUT);
	__parameters[0] = msg;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ReadHpDiag", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			msg, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_ReadUntDat(
	Alv_Test_SensorControl __instance,
	Alv_NarrowBand_UNT_DAT * msg,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	*msg = 0;


	// Pre-process parameter: msg
	__parameterTypeNames[0] = "Alv.NarrowBand.UNT_DAT&,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[0] = (CDOTNET_OBJECT | CDOTNET_OUT);
	__parameters[0] = msg;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ReadUntDat", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			msg, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_SendVehicleSpeed(
	Alv_Test_SensorControl __instance,
	unsigned int speed,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: speed
	__parameterTypeNames[0] = "System.UInt32";
	__parameterTypes[0] = (CDOTNET_UINT32);
	__parameters[0] = &speed;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"SendVehicleSpeed", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_SensorControl_SendGearPosition(
	Alv_Test_SensorControl __instance,
	Alv_NarrowBand_NBProtocol_GearPosition gear,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle gear__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: gear
	__errChk(Alv_NarrowBand_NBProtocol_GearPosition__Create(
		&gear, 
		&gear__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+GearPosition,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &gear__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"SendGearPosition", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (gear__)
		CDotNetDiscardHandle(gear__);
	return __error;
}

int CVIFUNC Alv_Test_SensorControl__Get__StateControl(
	Alv_Test_SensorControl __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"StateControl", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_SensorControl__Set__StateControl(
	Alv_Test_SensorControl __instance,
	int StateControl,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: StateControl
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &StateControl;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"StateControl", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_SensorControl__Get__Attempts(
	Alv_Test_SensorControl __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"Attempts", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_SensorControl__Set__Attempts(
	Alv_Test_SensorControl __instance,
	int Attempts,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: Attempts
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &Attempts;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorControl", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"Attempts", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}


// Type: Alv.Test.Write
int CVIFUNC Alv_Test_Write_Antenna(
	Alv_NarrowBand_NBProtocol_Antenna antenna,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle antenna__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: antenna
	__errChk(Alv_NarrowBand_NBProtocol_Antenna__Create(
		&antenna, 
		&antenna__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+Antenna,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &antenna__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.Test.Write", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"Antenna", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (antenna__)
		CDotNetDiscardHandle(antenna__);
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC Alv_Test_Write_Mode(
	Alv_NarrowBand_NBProtocol_ControlRadarMode mode,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle mode__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: mode
	__errChk(Alv_NarrowBand_NBProtocol_ControlRadarMode__Create(
		&mode, 
		&mode__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+ControlRadarMode,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &mode__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.Test.Write", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"Mode", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (mode__)
		CDotNetDiscardHandle(mode__);
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC Alv_Test_Write_STM(
	Alv_NarrowBand_NBProtocol_StaticTestMode mode,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle mode__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: mode
	__errChk(Alv_NarrowBand_NBProtocol_StaticTestMode__Create(
		&mode, 
		&mode__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+StaticTestMode,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &mode__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.Test.Write", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"STM", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (mode__)
		CDotNetDiscardHandle(mode__);
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC Alv_Test_Write_UntDat(
	Alv_NarrowBand_UNT_DAT msg,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: msg
	__parameterTypeNames[0] = "Alv.NarrowBand.UNT_DAT,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &msg;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.Test.Write", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"UntDat", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC Alv_Test_Write_UntDat_1(
	Alv_NarrowBand_UNT_DAT * msgs,
	ssize_t __msgsLength,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle msgs__ = 0;
	CDotNetAssemblyHandle __msgsAssembly = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: msgs
	if (msgs) {
		__errChk(CDotNetLoadAssembly(
			"NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null", 
			&__msgsAssembly));
		__errChk(CDotNetCreateTypedArray(
			__msgsAssembly, 
			"Alv.NarrowBand.UNT_DAT", 
			1, 
			0, 
			&__msgsLength, 
			msgs, 
			&msgs__));
	}
	__parameterTypeNames[0] = "Alv.NarrowBand.UNT_DAT[],NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[0] = (CDOTNET_OBJECT | CDOTNET_ARRAY);
	__parameters[0] = &msgs__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.Test.Write", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"UntDat", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (msgs__)
		CDotNetDiscardHandle(msgs__);
	if (__msgsAssembly)
		CDotNetDiscardAssemblyHandle(__msgsAssembly);
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC Alv_Test_Write_WaveData(
	Alv_Test_Wave * waves,
	ssize_t __wavesLength,
	double * kaiser_taps,
	ssize_t __kaiser_tapsLength,
	int pad_len,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];
	CDotNetHandle waves__ = 0;
	CDotNetAssemblyHandle __wavesAssembly = 0;
	CDotNetHandle kaiser_taps__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: waves
	if (waves) {
		__errChk(CDotNetLoadAssembly(
			__assemblyName, 
			&__wavesAssembly));
		__errChk(CDotNetCreateTypedArray(
			__wavesAssembly, 
			"Alv.Test.Wave", 
			1, 
			0, 
			&__wavesLength, 
			waves, 
			&waves__));
	}
	__parameterTypeNames[0] = "Alv.Test.Wave[]";
	__parameterTypes[0] = (CDOTNET_OBJECT | CDOTNET_ARRAY);
	__parameters[0] = &waves__;

	// Pre-process parameter: kaiser_taps
	if (kaiser_taps)
		__errChk(CDotNetCreateArray(
			CDOTNET_DOUBLE, 
			1, 
			0, 
			&__kaiser_tapsLength, 
			kaiser_taps, 
			&kaiser_taps__));
	__parameterTypeNames[1] = "System.Double[]";
	__parameterTypes[1] = (CDOTNET_DOUBLE | CDOTNET_ARRAY);
	__parameters[1] = &kaiser_taps__;

	// Pre-process parameter: pad_len
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &pad_len;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.Test.Write", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"WaveData", 
		0, 
		0, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (waves__)
		CDotNetDiscardHandle(waves__);
	if (__wavesAssembly)
		CDotNetDiscardAssemblyHandle(__wavesAssembly);
	if (kaiser_taps__)
		CDotNetDiscardHandle(kaiser_taps__);
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC Alv_Test_Write_WaveData_1(
	Alv_Test_Wave * waves,
	ssize_t __wavesLength,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle waves__ = 0;
	CDotNetAssemblyHandle __wavesAssembly = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: waves
	if (waves) {
		__errChk(CDotNetLoadAssembly(
			__assemblyName, 
			&__wavesAssembly));
		__errChk(CDotNetCreateTypedArray(
			__wavesAssembly, 
			"Alv.Test.Wave", 
			1, 
			0, 
			&__wavesLength, 
			waves, 
			&waves__));
	}
	__parameterTypeNames[0] = "Alv.Test.Wave[]";
	__parameterTypes[0] = (CDOTNET_OBJECT | CDOTNET_ARRAY);
	__parameters[0] = &waves__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.Test.Write", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"WaveData", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (waves__)
		CDotNetDiscardHandle(waves__);
	if (__wavesAssembly)
		CDotNetDiscardAssemblyHandle(__wavesAssembly);
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}


// Type: Alv.Test.DataHeader
int CVIFUNC Alv_Test_DataHeader__Create(
	Alv_Test_DataHeader * __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"Alv.Test.DataHeader", 
		0, 
		0, 
		__instance, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_DataHeader_Get_TimeStamp(
	Alv_Test_DataHeader __instance,
	System_DateTime * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRUCT;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.DataHeader", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"TimeStamp", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRUCT);
	}
	return __error;
}

int CVIFUNC Alv_Test_DataHeader_Get_HostId(
	Alv_Test_DataHeader __instance,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.DataHeader", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"HostId", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC Alv_Test_DataHeader_Get_TestPlan(
	Alv_Test_DataHeader __instance,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.DataHeader", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"TestPlan", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC Alv_Test_DataHeader_Get_DataPath(
	Alv_Test_DataHeader __instance,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.DataHeader", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"DataPath", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC Alv_Test_DataHeader_Get_Serial(
	Alv_Test_DataHeader __instance,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.DataHeader", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Serial", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC Alv_Test_DataHeader_Get_Architecture(
	Alv_Test_DataHeader __instance,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.DataHeader", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Architecture", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC Alv_Test_DataHeader_Get_HardwareType(
	Alv_Test_DataHeader __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_UINT16;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.DataHeader", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"HardwareType", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_DataHeader_Get_HpAppVersion(
	Alv_Test_DataHeader __instance,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.DataHeader", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"HpAppVersion", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC Alv_Test_DataHeader_Get_HpBootVersion(
	Alv_Test_DataHeader __instance,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.DataHeader", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"HpBootVersion", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC Alv_Test_DataHeader_Get_DspAppVersion(
	Alv_Test_DataHeader __instance,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.DataHeader", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"DspAppVersion", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC Alv_Test_DataHeader_Get_DspBootVersion(
	Alv_Test_DataHeader __instance,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.DataHeader", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"DspBootVersion", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC Alv_Test_DataHeader_Clear(
	Alv_Test_DataHeader __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.DataHeader", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Clear", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_DataHeader_Load(
	Alv_Test_DataHeader __instance,
	Alv_NarrowBand_Sensor s,
	char * test_plan,
	char * data_path,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: s
	__parameterTypeNames[0] = "Alv.NarrowBand.Sensor,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &s;

	// Pre-process parameter: test_plan
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &test_plan;

	// Pre-process parameter: data_path
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &data_path;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.DataHeader", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Load", 
		0, 
		0, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_DataHeader_Write(
	Alv_Test_DataHeader __instance,
	char * delim,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: delim
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &delim;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.DataHeader", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Write", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}


// Type: Alv.Test.SensorFolder
int CVIFUNC Alv_Test_SensorFolder__Create(
	Alv_Test_SensorFolder * __instance,
	char * path,
	Alv_Test_DataHeader header,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: path
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &path;

	// Pre-process parameter: header
	__parameterTypeNames[1] = "Alv.Test.DataHeader";
	__parameterTypes[1] = (CDOTNET_OBJECT);
	__parameters[1] = &header;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"Alv.Test.SensorFolder", 
		0, 
		0, 
		__instance, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_SensorFolder_SetupData(
	Alv_Test_SensorFolder __instance,
	char * file_name,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: file_name
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &file_name;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorFolder", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"SetupData", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_SensorFolder_Close(
	Alv_Test_SensorFolder __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorFolder", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Close", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_SensorFolder_MakeFileUnique(
	char * filename,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: filename
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &filename;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.Test.SensorFolder", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"MakeFileUnique", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC Alv_Test_SensorFolder__Get__Stats(
	Alv_Test_SensorFolder __instance,
	Alv_Test_DataFile * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorFolder", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"Stats", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Alv_Test_SensorFolder__Set__Stats(
	Alv_Test_SensorFolder __instance,
	Alv_Test_DataFile Stats,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: Stats
	__parameterTypeNames[0] = "Alv.Test.DataFile";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &Stats;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorFolder", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"Stats", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_SensorFolder__Get__Data(
	Alv_Test_SensorFolder __instance,
	Alv_Test_DataFile * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorFolder", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"Data", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Alv_Test_SensorFolder__Set__Data(
	Alv_Test_SensorFolder __instance,
	Alv_Test_DataFile Data,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: Data
	__parameterTypeNames[0] = "Alv.Test.DataFile";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &Data;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorFolder", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"Data", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_SensorFolder__Get__CalPoints(
	Alv_Test_SensorFolder __instance,
	Alv_Test_PointDump * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorFolder", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"CalPoints", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Alv_Test_SensorFolder__Set__CalPoints(
	Alv_Test_SensorFolder __instance,
	Alv_Test_PointDump CalPoints,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: CalPoints
	__parameterTypeNames[0] = "Alv.Test.PointDump";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &CalPoints;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorFolder", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"CalPoints", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_SensorFolder__Get__root_path(
	Alv_Test_SensorFolder __instance,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.SensorFolder", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"root_path", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}


// Type: Alv.Test.PointDump
int CVIFUNC Alv_Test_PointDump__Create(
	Alv_Test_PointDump * __instance,
	char * path,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: path
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &path;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"Alv.Test.PointDump", 
		0, 
		0, 
		__instance, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_PointDump_Get_FileName(
	Alv_Test_PointDump __instance,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.PointDump", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"FileName", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC Alv_Test_PointDump_PointRead(
	Alv_Test_PointDump __instance,
	unsigned short point,
	char ** value,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	*value = 0;


	// Pre-process parameter: point
	__parameterTypeNames[0] = "System.UInt16";
	__parameterTypes[0] = (CDOTNET_UINT16);
	__parameters[0] = &point;

	// Pre-process parameter: value
	__parameterTypeNames[1] = "System.String&";
	__parameterTypes[1] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[1] = value;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.PointDump", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"PointRead", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			value, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC Alv_Test_PointDump_PointWrite(
	Alv_Test_PointDump __instance,
	unsigned short point,
	char * value,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: point
	__parameterTypeNames[0] = "System.UInt16";
	__parameterTypes[0] = (CDOTNET_UINT16);
	__parameters[0] = &point;

	// Pre-process parameter: value
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &value;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.PointDump", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"PointWrite", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_PointDump_PointWrite_1(
	Alv_Test_PointDump __instance,
	unsigned short point,
	int value,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: point
	__parameterTypeNames[0] = "System.UInt16";
	__parameterTypes[0] = (CDOTNET_UINT16);
	__parameters[0] = &point;

	// Pre-process parameter: value
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &value;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.PointDump", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"PointWrite", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_PointDump_PointWrite_2(
	Alv_Test_PointDump __instance,
	unsigned short point,
	unsigned int value,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: point
	__parameterTypeNames[0] = "System.UInt16";
	__parameterTypes[0] = (CDOTNET_UINT16);
	__parameters[0] = &point;

	// Pre-process parameter: value
	__parameterTypeNames[1] = "System.UInt32";
	__parameterTypes[1] = (CDOTNET_UINT32);
	__parameters[1] = &value;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.PointDump", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"PointWrite", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_PointDump_PointWrite_3(
	Alv_Test_PointDump __instance,
	unsigned short point,
	double value,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: point
	__parameterTypeNames[0] = "System.UInt16";
	__parameterTypes[0] = (CDOTNET_UINT16);
	__parameters[0] = &point;

	// Pre-process parameter: value
	__parameterTypeNames[1] = "System.Double";
	__parameterTypes[1] = (CDOTNET_DOUBLE);
	__parameters[1] = &value;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.PointDump", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"PointWrite", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_PointDump_PointWrite_4(
	Alv_Test_PointDump __instance,
	unsigned short point,
	unsigned short value,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: point
	__parameterTypeNames[0] = "System.UInt16";
	__parameterTypes[0] = (CDOTNET_UINT16);
	__parameters[0] = &point;

	// Pre-process parameter: value
	__parameterTypeNames[1] = "System.UInt16";
	__parameterTypes[1] = (CDOTNET_UINT16);
	__parameters[1] = &value;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.PointDump", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"PointWrite", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_PointDump__Get__ext(
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.Test.PointDump", 
		0, 
		0, 
		CDOTNET_GET_FIELD, 
		"ext", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}


// Type: Alv.Test.DataFile
int CVIFUNC Alv_Test_DataFile__Create(
	Alv_Test_DataFile * __instance,
	char * path,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: path
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &path;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"Alv.Test.DataFile", 
		0, 
		0, 
		__instance, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_DataFile_Get_FileName(
	Alv_Test_DataFile __instance,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.DataFile", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"FileName", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC Alv_Test_DataFile_Close(
	Alv_Test_DataFile __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.DataFile", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Close", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_DataFile_WriteLine(
	Alv_Test_DataFile __instance,
	CDotNetHandle item,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: item
	__parameterTypeNames[0] = "System.Object";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &item;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.DataFile", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"WriteLine", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_DataFile_WriteLine_1(
	Alv_Test_DataFile __instance,
	CDotNetHandle * items,
	ssize_t __itemsLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle items__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: items
	if (items)
		__errChk(CDotNetCreateArray(
			CDOTNET_OBJECT, 
			1, 
			0, 
			&__itemsLength, 
			items, 
			&items__));
	__parameterTypeNames[0] = "System.Object[]";
	__parameterTypes[0] = (CDOTNET_OBJECT | CDOTNET_ARRAY);
	__parameters[0] = &items__;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.DataFile", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"WriteLine", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (items__)
		CDotNetDiscardHandle(items__);
	return __error;
}

int CVIFUNC Alv_Test_DataFile_Write(
	Alv_Test_DataFile __instance,
	CDotNetHandle item,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: item
	__parameterTypeNames[0] = "System.Object";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &item;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.DataFile", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Write", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_DataFile_Write_1(
	Alv_Test_DataFile __instance,
	CDotNetHandle * items,
	ssize_t __itemsLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle items__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: items
	if (items)
		__errChk(CDotNetCreateArray(
			CDOTNET_OBJECT, 
			1, 
			0, 
			&__itemsLength, 
			items, 
			&items__));
	__parameterTypeNames[0] = "System.Object[]";
	__parameterTypes[0] = (CDOTNET_OBJECT | CDOTNET_ARRAY);
	__parameters[0] = &items__;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.DataFile", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Write", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (items__)
		CDotNetDiscardHandle(items__);
	return __error;
}

int CVIFUNC Alv_Test_DataFile__Get__delim(
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.Test.DataFile", 
		0, 
		0, 
		CDOTNET_GET_FIELD, 
		"delim", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC Alv_Test_DataFile__Get__ext(
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.Test.DataFile", 
		0, 
		0, 
		CDOTNET_GET_FIELD, 
		"ext", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}


// Type: Alv.Test.Mfg.MfgTesterSettings
int CVIFUNC Alv_Test_Mfg_MfgTesterSettings__Create(
	Alv_Test_Mfg_MfgTesterSettings * __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTesterSettings", 
		0, 
		0, 
		__instance, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTesterSettings_Load(
	Alv_Test_Mfg_MfgTesterSettings __instance,
	char * path,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: path
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &path;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTesterSettings", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Load", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTesterSettings__Get__Enabled(
	Alv_Test_Mfg_MfgTesterSettings __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTesterSettings", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"Enabled", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTesterSettings__Set__Enabled(
	Alv_Test_Mfg_MfgTesterSettings __instance,
	int Enabled,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: Enabled
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &Enabled;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTesterSettings", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"Enabled", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTesterSettings__Get__LogFile(
	Alv_Test_Mfg_MfgTesterSettings __instance,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTesterSettings", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"LogFile", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTesterSettings__Set__LogFile(
	Alv_Test_Mfg_MfgTesterSettings __instance,
	char * LogFile,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: LogFile
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &LogFile;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTesterSettings", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"LogFile", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTesterSettings__Get__FirPath(
	Alv_Test_Mfg_MfgTesterSettings __instance,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTesterSettings", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"FirPath", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTesterSettings__Set__FirPath(
	Alv_Test_Mfg_MfgTesterSettings __instance,
	char * FirPath,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: FirPath
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &FirPath;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTesterSettings", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"FirPath", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTesterSettings__Get__StateControl(
	Alv_Test_Mfg_MfgTesterSettings __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTesterSettings", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"StateControl", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTesterSettings__Set__StateControl(
	Alv_Test_Mfg_MfgTesterSettings __instance,
	int StateControl,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: StateControl
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &StateControl;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTesterSettings", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"StateControl", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTesterSettings__Get__LogEngData(
	Alv_Test_Mfg_MfgTesterSettings __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTesterSettings", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"LogEngData", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTesterSettings__Set__LogEngData(
	Alv_Test_Mfg_MfgTesterSettings __instance,
	int LogEngData,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: LogEngData
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &LogEngData;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTesterSettings", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"LogEngData", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTesterSettings__Get__CommAttempts(
	Alv_Test_Mfg_MfgTesterSettings __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTesterSettings", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"CommAttempts", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTesterSettings__Set__CommAttempts(
	Alv_Test_Mfg_MfgTesterSettings __instance,
	int CommAttempts,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: CommAttempts
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &CommAttempts;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTesterSettings", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"CommAttempts", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTesterSettings__Get__KaiserAlpha(
	Alv_Test_Mfg_MfgTesterSettings __instance,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTesterSettings", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"KaiserAlpha", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTesterSettings__Set__KaiserAlpha(
	Alv_Test_Mfg_MfgTesterSettings __instance,
	double KaiserAlpha,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: KaiserAlpha
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &KaiserAlpha;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTesterSettings", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"KaiserAlpha", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}


// Type: Alv.Test.Mfg.MfgTester
int CVIFUNC Alv_Test_Mfg_MfgTester__Create(
	Alv_Test_Mfg_MfgTester * __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		0, 
		0, 
		__instance, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTester_Get_Message(
	Alv_Test_Mfg_MfgTester __instance,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Message", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTester_Get_State(
	Alv_Test_Mfg_MfgTester __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"State", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTester_Set_State(
	Alv_Test_Mfg_MfgTester __instance,
	int value,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: value
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &value;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"State", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTester_InitCoffin(
	Alv_Test_Mfg_MfgTester __instance,
	Alv_NarrowBand_Sensor comm,
	char * settings_path,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: comm
	__parameterTypeNames[0] = "Alv.NarrowBand.Sensor,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &comm;

	// Pre-process parameter: settings_path
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &settings_path;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"InitCoffin", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTester_InitCoffin_No_Velmex(
	Alv_Test_Mfg_MfgTester __instance,
	Alv_NarrowBand_Sensor comm,
	char * settings_path,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: comm
	__parameterTypeNames[0] = "Alv.NarrowBand.Sensor,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &comm;

	// Pre-process parameter: settings_path
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &settings_path;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"InitCoffin_No_Velmex", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTester_InitTxCal(
	Alv_Test_Mfg_MfgTester __instance,
	Alv_NarrowBand_Sensor comm,
	char * settings_path,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: comm
	__parameterTypeNames[0] = "Alv.NarrowBand.Sensor,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &comm;

	// Pre-process parameter: settings_path
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &settings_path;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"InitTxCal", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTester_DcOffsetInit(
	Alv_Test_Mfg_MfgTester __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"DcOffsetInit", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTester_RotateVelmex(
	Alv_Test_Mfg_MfgTester __instance,
	double angle,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: angle
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &angle;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RotateVelmex", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTester_ReHomeVelmex(
	Alv_Test_Mfg_MfgTester __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ReHomeVelmex", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTester_Setup(
	Alv_Test_Mfg_MfgTester __instance,
	double angle,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: angle
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &angle;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Setup", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTester_Supply_on(
	Alv_Test_Mfg_MfgTester __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Supply_on", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTester_readCurrent(
	Alv_Test_Mfg_MfgTester __instance,
	double * current,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: current
	__parameterTypeNames[0] = "System.Double&";
	__parameterTypes[0] = (CDOTNET_DOUBLE | CDOTNET_OUT);
	__parameters[0] = current;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"readCurrent", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTester_SelectRfRoute(
	Alv_Test_Mfg_MfgTester __instance,
	int route,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: route
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &route;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"SelectRfRoute", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[9] = {0};
	unsigned int __parameterTypes[9];
	void * __parameters[9];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	*serial = 0;
	*part_number0 = 0;
	*part_number1 = 0;
	*part_number2 = 0;
	*part_number3 = 0;
	*sw_version0 = 0;
	*sw_version1 = 0;
	*sw_version2 = 0;
	*sw_version3 = 0;


	// Pre-process parameter: serial
	__parameterTypeNames[0] = "System.String&";
	__parameterTypes[0] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[0] = serial;

	// Pre-process parameter: part_number0
	__parameterTypeNames[1] = "System.String&";
	__parameterTypes[1] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[1] = part_number0;

	// Pre-process parameter: part_number1
	__parameterTypeNames[2] = "System.String&";
	__parameterTypes[2] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[2] = part_number1;

	// Pre-process parameter: part_number2
	__parameterTypeNames[3] = "System.String&";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[3] = part_number2;

	// Pre-process parameter: part_number3
	__parameterTypeNames[4] = "System.String&";
	__parameterTypes[4] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[4] = part_number3;

	// Pre-process parameter: sw_version0
	__parameterTypeNames[5] = "System.String&";
	__parameterTypes[5] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[5] = sw_version0;

	// Pre-process parameter: sw_version1
	__parameterTypeNames[6] = "System.String&";
	__parameterTypes[6] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[6] = sw_version1;

	// Pre-process parameter: sw_version2
	__parameterTypeNames[7] = "System.String&";
	__parameterTypes[7] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[7] = sw_version2;

	// Pre-process parameter: sw_version3
	__parameterTypeNames[8] = "System.String&";
	__parameterTypes[8] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[8] = sw_version3;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Ping", 
		0, 
		0, 
		9, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			serial, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			part_number0, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			part_number1, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			part_number2, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			part_number3, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			sw_version0, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			sw_version1, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			sw_version2, 
			CDOTNET_STRING);
		_CDotNetGenDisposeScalar(
			sw_version3, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTester_Ping_1(
	Alv_Test_Mfg_MfgTester __instance,
	char ** serial,
	char *** part_number,
	ssize_t * __part_numberLength,
	char *** sw_version,
	ssize_t * __sw_versionLength,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];
	CDotNetHandle part_number__ = 0;
	CDotNetHandle sw_version__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	*serial = 0;
	*part_number = 0;
	*__part_numberLength = 0;
	*sw_version = 0;
	*__sw_versionLength = 0;


	// Pre-process parameter: serial
	__parameterTypeNames[0] = "System.String&";
	__parameterTypes[0] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[0] = serial;

	// Pre-process parameter: part_number
	__parameterTypeNames[1] = "System.String[]&";
	__parameterTypes[1] = (CDOTNET_STRING | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[1] = &part_number__;

	// Pre-process parameter: sw_version
	__parameterTypeNames[2] = "System.String[]&";
	__parameterTypes[2] = (CDOTNET_STRING | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[2] = &sw_version__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Ping", 
		0, 
		0, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));

	// Post-process parameter: part_number
	if (part_number__) {
		__errChk(CDotNetGetArrayElements(
			part_number__, 
			CDOTNET_STRING, 
			0, 
			part_number));
		__errChk(CDotNetGetArrayLength(
			part_number__, 
			0, 
			__part_numberLength));
	}

	// Post-process parameter: sw_version
	if (sw_version__) {
		__errChk(CDotNetGetArrayElements(
			sw_version__, 
			CDOTNET_STRING, 
			0, 
			sw_version));
		__errChk(CDotNetGetArrayLength(
			sw_version__, 
			0, 
			__sw_versionLength));
	}


__Error:
	if (part_number__)
		CDotNetDiscardHandle(part_number__);
	if (sw_version__)
		CDotNetDiscardHandle(sw_version__);
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			serial, 
			CDOTNET_STRING);
		_CDotNetGenDisposeArray(
			part_number, 
			CDOTNET_STRING, 
			1, 
			__part_numberLength);
		_CDotNetGenDisposeArray(
			sw_version, 
			CDOTNET_STRING, 
			1, 
			__sw_versionLength);
	}
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTester_Connect(
	Alv_Test_Mfg_MfgTester __instance,
	char ** serial,
	char *** part_number,
	ssize_t * __part_numberLength,
	char *** sw_version,
	ssize_t * __sw_versionLength,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];
	CDotNetHandle part_number__ = 0;
	CDotNetHandle sw_version__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	*serial = 0;
	*part_number = 0;
	*__part_numberLength = 0;
	*sw_version = 0;
	*__sw_versionLength = 0;


	// Pre-process parameter: serial
	__parameterTypeNames[0] = "System.String&";
	__parameterTypes[0] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[0] = serial;

	// Pre-process parameter: part_number
	__parameterTypeNames[1] = "System.String[]&";
	__parameterTypes[1] = (CDOTNET_STRING | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[1] = &part_number__;

	// Pre-process parameter: sw_version
	__parameterTypeNames[2] = "System.String[]&";
	__parameterTypes[2] = (CDOTNET_STRING | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[2] = &sw_version__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Connect", 
		0, 
		0, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));

	// Post-process parameter: part_number
	if (part_number__) {
		__errChk(CDotNetGetArrayElements(
			part_number__, 
			CDOTNET_STRING, 
			0, 
			part_number));
		__errChk(CDotNetGetArrayLength(
			part_number__, 
			0, 
			__part_numberLength));
	}

	// Post-process parameter: sw_version
	if (sw_version__) {
		__errChk(CDotNetGetArrayElements(
			sw_version__, 
			CDOTNET_STRING, 
			0, 
			sw_version));
		__errChk(CDotNetGetArrayLength(
			sw_version__, 
			0, 
			__sw_versionLength));
	}


__Error:
	if (part_number__)
		CDotNetDiscardHandle(part_number__);
	if (sw_version__)
		CDotNetDiscardHandle(sw_version__);
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			serial, 
			CDOTNET_STRING);
		_CDotNetGenDisposeArray(
			part_number, 
			CDOTNET_STRING, 
			1, 
			__part_numberLength);
		_CDotNetGenDisposeArray(
			sw_version, 
			CDOTNET_STRING, 
			1, 
			__sw_versionLength);
	}
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTester_Disconnect(
	Alv_Test_Mfg_MfgTester __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Disconnect", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTester_MakePath(
	Alv_Test_Mfg_MfgTester __instance,
	char * path,
	char * description,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: path
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &path;

	// Pre-process parameter: description
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &description;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"MakePath", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTester_SetupData(
	Alv_Test_Mfg_MfgTester __instance,
	char * file_name,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: file_name
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &file_name;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"SetupData", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTester_CloseData(
	Alv_Test_Mfg_MfgTester __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"CloseData", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTester_CenterFrequency(
	Alv_Test_Mfg_MfgTester __instance,
	Alv_NarrowBand_NBProtocol_Antenna antenna,
	double * frequency,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	CDotNetHandle antenna__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: antenna
	__errChk(Alv_NarrowBand_NBProtocol_Antenna__Create(
		&antenna, 
		&antenna__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+Antenna,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &antenna__;

	// Pre-process parameter: frequency
	__parameterTypeNames[1] = "System.Double&";
	__parameterTypes[1] = (CDOTNET_DOUBLE | CDOTNET_OUT);
	__parameters[1] = frequency;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"CenterFrequency", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (antenna__)
		CDotNetDiscardHandle(antenna__);
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTester_CwLeakage(
	Alv_Test_Mfg_MfgTester __instance,
	Alv_NarrowBand_NBProtocol_Antenna antenna,
	double * leakage,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	CDotNetHandle antenna__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: antenna
	__errChk(Alv_NarrowBand_NBProtocol_Antenna__Create(
		&antenna, 
		&antenna__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+Antenna,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &antenna__;

	// Pre-process parameter: leakage
	__parameterTypeNames[1] = "System.Double&";
	__parameterTypes[1] = (CDOTNET_DOUBLE | CDOTNET_OUT);
	__parameters[1] = leakage;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"CwLeakage", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (antenna__)
		CDotNetDiscardHandle(antenna__);
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTester_OccupiedBW(
	Alv_Test_Mfg_MfgTester __instance,
	Alv_NarrowBand_NBProtocol_ControlRadarMode mode,
	int time,
	double * bandwidth,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];
	CDotNetHandle mode__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: mode
	__errChk(Alv_NarrowBand_NBProtocol_ControlRadarMode__Create(
		&mode, 
		&mode__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+ControlRadarMode,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &mode__;

	// Pre-process parameter: time
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &time;

	// Pre-process parameter: bandwidth
	__parameterTypeNames[2] = "System.Double&";
	__parameterTypes[2] = (CDOTNET_DOUBLE | CDOTNET_OUT);
	__parameters[2] = bandwidth;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"OccupiedBW", 
		0, 
		0, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (mode__)
		CDotNetDiscardHandle(mode__);
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTester_PointCheck(
	Alv_Test_Mfg_MfgTester __instance,
	int point,
	char * failval,
	char ** pointval,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	*pointval = 0;


	// Pre-process parameter: point
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &point;

	// Pre-process parameter: failval
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &failval;

	// Pre-process parameter: pointval
	__parameterTypeNames[2] = "System.String&";
	__parameterTypes[2] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[2] = pointval;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"PointCheck", 
		0, 
		0, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			pointval, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTester_PointCheck_1(
	Alv_Test_Mfg_MfgTester __instance,
	int point,
	double max,
	double min,
	char ** pointval,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	*pointval = 0;


	// Pre-process parameter: point
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &point;

	// Pre-process parameter: max
	__parameterTypeNames[1] = "System.Double";
	__parameterTypes[1] = (CDOTNET_DOUBLE);
	__parameters[1] = &max;

	// Pre-process parameter: min
	__parameterTypeNames[2] = "System.Double";
	__parameterTypes[2] = (CDOTNET_DOUBLE);
	__parameters[2] = &min;

	// Pre-process parameter: pointval
	__parameterTypeNames[3] = "System.String&";
	__parameterTypes[3] = (CDOTNET_STRING | CDOTNET_OUT);
	__parameters[3] = pointval;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"PointCheck", 
		0, 
		0, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			pointval, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTester_DspErrorCheck(
	Alv_Test_Mfg_MfgTester __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"DspErrorCheck", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTester_HpErrorCheck(
	Alv_Test_Mfg_MfgTester __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"HpErrorCheck", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTester_CurrentCheck(
	Alv_Test_Mfg_MfgTester __instance,
	double * current,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: current
	__parameterTypeNames[0] = "System.Double&";
	__parameterTypes[0] = (CDOTNET_DOUBLE | CDOTNET_OUT);
	__parameters[0] = current;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"CurrentCheck", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTester_SensorTemp(
	Alv_Test_Mfg_MfgTester __instance,
	double * board_temp,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: board_temp
	__parameterTypeNames[0] = "System.Double&";
	__parameterTypes[0] = (CDOTNET_DOUBLE | CDOTNET_OUT);
	__parameters[0] = board_temp;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"SensorTemp", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTester_IQCheckHonda(
	Alv_Test_Mfg_MfgTester __instance,
	double ** points,
	ssize_t * __pointsLength1,
	ssize_t * __pointsLength2,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle points__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	*points = 0;
	*__pointsLength1 = 0;
	*__pointsLength2 = 0;


	// Pre-process parameter: points
	__parameterTypeNames[0] = "System.Double[,]&";
	__parameterTypes[0] = (CDOTNET_DOUBLE | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[0] = &points__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"IQCheckHonda", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));

	// Post-process parameter: points
	if (points__) {
		__errChk(CDotNetGetArrayElements(
			points__, 
			CDOTNET_DOUBLE, 
			0, 
			points));
		__errChk(CDotNetGetArrayLength(
			points__, 
			0, 
			__pointsLength1));
		__errChk(CDotNetGetArrayLength(
			points__, 
			1, 
			__pointsLength2));
	}


__Error:
	if (points__)
		CDotNetDiscardHandle(points__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			points, 
			CDOTNET_DOUBLE, 
			2, 
			__pointsLength1, 
			__pointsLength2);
	}
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTester_IQCheckGM(
	Alv_Test_Mfg_MfgTester __instance,
	double ** points,
	ssize_t * __pointsLength1,
	ssize_t * __pointsLength2,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle points__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	*points = 0;
	*__pointsLength1 = 0;
	*__pointsLength2 = 0;


	// Pre-process parameter: points
	__parameterTypeNames[0] = "System.Double[,]&";
	__parameterTypes[0] = (CDOTNET_DOUBLE | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[0] = &points__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"IQCheckGM", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));

	// Post-process parameter: points
	if (points__) {
		__errChk(CDotNetGetArrayElements(
			points__, 
			CDOTNET_DOUBLE, 
			0, 
			points));
		__errChk(CDotNetGetArrayLength(
			points__, 
			0, 
			__pointsLength1));
		__errChk(CDotNetGetArrayLength(
			points__, 
			1, 
			__pointsLength2));
	}


__Error:
	if (points__)
		CDotNetDiscardHandle(points__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			points, 
			CDOTNET_DOUBLE, 
			2, 
			__pointsLength1, 
			__pointsLength2);
	}
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTester_LEDTest(
	Alv_Test_Mfg_MfgTester __instance,
	double * led_current,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: led_current
	__parameterTypeNames[0] = "System.Double&";
	__parameterTypes[0] = (CDOTNET_DOUBLE | CDOTNET_OUT);
	__parameters[0] = led_current;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"LEDTest", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTester_NoiseArtifact(
	Alv_Test_Mfg_MfgTester __instance,
	int sweeps,
	int bin_length,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: sweeps
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &sweeps;

	// Pre-process parameter: bin_length
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &bin_length;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"NoiseArtifact", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTester_BlockageTest(
	Alv_Test_Mfg_MfgTester __instance,
	double * blockage,
	double * board_temp,
	double * noise_floor,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: blockage
	__parameterTypeNames[0] = "System.Double&";
	__parameterTypes[0] = (CDOTNET_DOUBLE | CDOTNET_OUT);
	__parameters[0] = blockage;

	// Pre-process parameter: board_temp
	__parameterTypeNames[1] = "System.Double&";
	__parameterTypes[1] = (CDOTNET_DOUBLE | CDOTNET_OUT);
	__parameters[1] = board_temp;

	// Pre-process parameter: noise_floor
	__parameterTypeNames[2] = "System.Double&";
	__parameterTypes[2] = (CDOTNET_DOUBLE | CDOTNET_OUT);
	__parameters[2] = noise_floor;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"BlockageTest", 
		0, 
		0, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTester_FalseAlarm(
	Alv_Test_Mfg_MfgTester __instance,
	double ** dac_values,
	ssize_t * __dac_valuesLength,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle dac_values__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	*dac_values = 0;
	*__dac_valuesLength = 0;


	// Pre-process parameter: dac_values
	__parameterTypeNames[0] = "System.Double[]&";
	__parameterTypes[0] = (CDOTNET_DOUBLE | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[0] = &dac_values__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"FalseAlarm", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));

	// Post-process parameter: dac_values
	if (dac_values__) {
		__errChk(CDotNetGetArrayElements(
			dac_values__, 
			CDOTNET_DOUBLE, 
			0, 
			dac_values));
		__errChk(CDotNetGetArrayLength(
			dac_values__, 
			0, 
			__dac_valuesLength));
	}


__Error:
	if (dac_values__)
		CDotNetDiscardHandle(dac_values__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			dac_values, 
			CDOTNET_DOUBLE, 
			1, 
			__dac_valuesLength);
	}
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTester_BSDRangeCheck(
	Alv_Test_Mfg_MfgTester __instance,
	int count,
	double * range,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: count
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &count;

	// Pre-process parameter: range
	__parameterTypeNames[1] = "System.Double&";
	__parameterTypes[1] = (CDOTNET_DOUBLE | CDOTNET_OUT);
	__parameters[1] = range;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"BSDRangeCheck", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTester_BSDRangeCheck_1(
	Alv_Test_Mfg_MfgTester __instance,
	int count,
	double angle,
	double threshold,
	double * range,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: count
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &count;

	// Pre-process parameter: angle
	__parameterTypeNames[1] = "System.Double";
	__parameterTypes[1] = (CDOTNET_DOUBLE);
	__parameters[1] = &angle;

	// Pre-process parameter: threshold
	__parameterTypeNames[2] = "System.Double";
	__parameterTypes[2] = (CDOTNET_DOUBLE);
	__parameters[2] = &threshold;

	// Pre-process parameter: range
	__parameterTypeNames[3] = "System.Double&";
	__parameterTypes[3] = (CDOTNET_DOUBLE | CDOTNET_OUT);
	__parameters[3] = range;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"BSDRangeCheck", 
		0, 
		0, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTester_TxPower(
	Alv_Test_Mfg_MfgTester __instance,
	double * power,
	Alv_NarrowBand_NBProtocol_Antenna antenna,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	CDotNetHandle antenna__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: power
	__parameterTypeNames[0] = "System.Double&";
	__parameterTypes[0] = (CDOTNET_DOUBLE | CDOTNET_OUT);
	__parameters[0] = power;

	// Pre-process parameter: antenna
	__errChk(Alv_NarrowBand_NBProtocol_Antenna__Create(
		&antenna, 
		&antenna__, 
		__exception));
	__parameterTypeNames[1] = "Alv.NarrowBand.NBProtocol+Antenna,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[1] = (CDOTNET_ENUM);
	__parameters[1] = &antenna__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"TxPower", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (antenna__)
		CDotNetDiscardHandle(antenna__);
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTester_SweepBSD(
	Alv_Test_Mfg_MfgTester __instance,
	double angle,
	Alv_NarrowBand_NBProtocol_Antenna antenna,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	CDotNetHandle antenna__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: angle
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &angle;

	// Pre-process parameter: antenna
	__errChk(Alv_NarrowBand_NBProtocol_Antenna__Create(
		&antenna, 
		&antenna__, 
		__exception));
	__parameterTypeNames[1] = "Alv.NarrowBand.NBProtocol+Antenna,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[1] = (CDOTNET_ENUM);
	__parameters[1] = &antenna__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"SweepBSD", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (antenna__)
		CDotNetDiscardHandle(antenna__);
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTester_SweepRCTA(
	Alv_Test_Mfg_MfgTester __instance,
	double angle,
	Alv_NarrowBand_NBProtocol_Antenna antenna,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	CDotNetHandle antenna__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: angle
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &angle;

	// Pre-process parameter: antenna
	__errChk(Alv_NarrowBand_NBProtocol_Antenna__Create(
		&antenna, 
		&antenna__, 
		__exception));
	__parameterTypeNames[1] = "Alv.NarrowBand.NBProtocol+Antenna,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[1] = (CDOTNET_ENUM);
	__parameters[1] = &antenna__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"SweepRCTA", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (antenna__)
		CDotNetDiscardHandle(antenna__);
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTester_SweepLCA(
	Alv_Test_Mfg_MfgTester __instance,
	double angle,
	Alv_NarrowBand_NBProtocol_Antenna antenna,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	CDotNetHandle antenna__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: angle
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &angle;

	// Pre-process parameter: antenna
	__errChk(Alv_NarrowBand_NBProtocol_Antenna__Create(
		&antenna, 
		&antenna__, 
		__exception));
	__parameterTypeNames[1] = "Alv.NarrowBand.NBProtocol+Antenna,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[1] = (CDOTNET_ENUM);
	__parameters[1] = &antenna__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"SweepLCA", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (antenna__)
		CDotNetDiscardHandle(antenna__);
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[8] = {0};
	unsigned int __parameterTypes[8];
	void * __parameters[8];
	CDotNetHandle mode__ = 0;
	CDotNetHandle antenna__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: mode
	__errChk(Alv_NarrowBand_NBProtocol_ControlRadarMode__Create(
		&mode, 
		&mode__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+ControlRadarMode,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &mode__;

	// Pre-process parameter: antenna
	__errChk(Alv_NarrowBand_NBProtocol_Antenna__Create(
		&antenna, 
		&antenna__, 
		__exception));
	__parameterTypeNames[1] = "Alv.NarrowBand.NBProtocol+Antenna,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[1] = (CDOTNET_ENUM);
	__parameters[1] = &antenna__;

	// Pre-process parameter: angle
	__parameterTypeNames[2] = "System.Double";
	__parameterTypes[2] = (CDOTNET_DOUBLE);
	__parameters[2] = &angle;

	// Pre-process parameter: count
	__parameterTypeNames[3] = "System.Int32";
	__parameterTypes[3] = (CDOTNET_INT32);
	__parameters[3] = &count;

	// Pre-process parameter: azimuth
	__parameterTypeNames[4] = "System.Double&";
	__parameterTypes[4] = (CDOTNET_DOUBLE | CDOTNET_OUT);
	__parameters[4] = azimuth;

	// Pre-process parameter: distance
	__parameterTypeNames[5] = "System.Double&";
	__parameterTypes[5] = (CDOTNET_DOUBLE | CDOTNET_OUT);
	__parameters[5] = distance;

	// Pre-process parameter: speed
	__parameterTypeNames[6] = "System.Double&";
	__parameterTypes[6] = (CDOTNET_DOUBLE | CDOTNET_OUT);
	__parameters[6] = speed;

	// Pre-process parameter: SNR
	__parameterTypeNames[7] = "System.Double&";
	__parameterTypes[7] = (CDOTNET_DOUBLE | CDOTNET_OUT);
	__parameters[7] = SNR;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"UntDatSweep", 
		0, 
		0, 
		8, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (mode__)
		CDotNetDiscardHandle(mode__);
	if (antenna__)
		CDotNetDiscardHandle(antenna__);
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTester_UntDatSweep_1(
	Alv_Test_Mfg_MfgTester __instance,
	Alv_NarrowBand_NBProtocol_StaticTestMode mode,
	double angle,
	int count,
	double * azimuth,
	double * distance,
	double * speed,
	double * SNR,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[7] = {0};
	unsigned int __parameterTypes[7];
	void * __parameters[7];
	CDotNetHandle mode__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: mode
	__errChk(Alv_NarrowBand_NBProtocol_StaticTestMode__Create(
		&mode, 
		&mode__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+StaticTestMode,NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &mode__;

	// Pre-process parameter: angle
	__parameterTypeNames[1] = "System.Double";
	__parameterTypes[1] = (CDOTNET_DOUBLE);
	__parameters[1] = &angle;

	// Pre-process parameter: count
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &count;

	// Pre-process parameter: azimuth
	__parameterTypeNames[3] = "System.Double&";
	__parameterTypes[3] = (CDOTNET_DOUBLE | CDOTNET_OUT);
	__parameters[3] = azimuth;

	// Pre-process parameter: distance
	__parameterTypeNames[4] = "System.Double&";
	__parameterTypes[4] = (CDOTNET_DOUBLE | CDOTNET_OUT);
	__parameters[4] = distance;

	// Pre-process parameter: speed
	__parameterTypeNames[5] = "System.Double&";
	__parameterTypes[5] = (CDOTNET_DOUBLE | CDOTNET_OUT);
	__parameters[5] = speed;

	// Pre-process parameter: SNR
	__parameterTypeNames[6] = "System.Double&";
	__parameterTypes[6] = (CDOTNET_DOUBLE | CDOTNET_OUT);
	__parameters[6] = SNR;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"UntDatSweep", 
		0, 
		0, 
		7, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (mode__)
		CDotNetDiscardHandle(mode__);
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTester_PowerAtAngle(
	Alv_Test_Mfg_MfgTester __instance,
	double angle,
	double ** power,
	ssize_t * __powerLength,
	double * board_temp,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];
	CDotNetHandle power__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	*power = 0;
	*__powerLength = 0;


	// Pre-process parameter: angle
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &angle;

	// Pre-process parameter: power
	__parameterTypeNames[1] = "System.Double[]&";
	__parameterTypes[1] = (CDOTNET_DOUBLE | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[1] = &power__;

	// Pre-process parameter: board_temp
	__parameterTypeNames[2] = "System.Double&";
	__parameterTypes[2] = (CDOTNET_DOUBLE | CDOTNET_OUT);
	__parameters[2] = board_temp;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"PowerAtAngle", 
		0, 
		0, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));

	// Post-process parameter: power
	if (power__) {
		__errChk(CDotNetGetArrayElements(
			power__, 
			CDOTNET_DOUBLE, 
			0, 
			power));
		__errChk(CDotNetGetArrayLength(
			power__, 
			0, 
			__powerLength));
	}


__Error:
	if (power__)
		CDotNetDiscardHandle(power__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			power, 
			CDOTNET_DOUBLE, 
			1, 
			__powerLength);
	}
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTester_TxPowerCalHonda(
	Alv_Test_Mfg_MfgTester __instance,
	int gain_min,
	double pow_min,
	double pow_max,
	double ** points,
	ssize_t * __pointsLength1,
	ssize_t * __pointsLength2,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];
	CDotNetHandle points__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	*points = 0;
	*__pointsLength1 = 0;
	*__pointsLength2 = 0;


	// Pre-process parameter: gain_min
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &gain_min;

	// Pre-process parameter: pow_min
	__parameterTypeNames[1] = "System.Double";
	__parameterTypes[1] = (CDOTNET_DOUBLE);
	__parameters[1] = &pow_min;

	// Pre-process parameter: pow_max
	__parameterTypeNames[2] = "System.Double";
	__parameterTypes[2] = (CDOTNET_DOUBLE);
	__parameters[2] = &pow_max;

	// Pre-process parameter: points
	__parameterTypeNames[3] = "System.Double[,]&";
	__parameterTypes[3] = (CDOTNET_DOUBLE | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[3] = &points__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"TxPowerCalHonda", 
		0, 
		0, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));

	// Post-process parameter: points
	if (points__) {
		__errChk(CDotNetGetArrayElements(
			points__, 
			CDOTNET_DOUBLE, 
			0, 
			points));
		__errChk(CDotNetGetArrayLength(
			points__, 
			0, 
			__pointsLength1));
		__errChk(CDotNetGetArrayLength(
			points__, 
			1, 
			__pointsLength2));
	}


__Error:
	if (points__)
		CDotNetDiscardHandle(points__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			points, 
			CDOTNET_DOUBLE, 
			2, 
			__pointsLength1, 
			__pointsLength2);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[5] = {0};
	unsigned int __parameterTypes[5];
	void * __parameters[5];
	CDotNetHandle points__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	*points = 0;
	*__pointsLength1 = 0;
	*__pointsLength2 = 0;


	// Pre-process parameter: gain_min
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &gain_min;

	// Pre-process parameter: pow_min
	__parameterTypeNames[1] = "System.Double";
	__parameterTypes[1] = (CDOTNET_DOUBLE);
	__parameters[1] = &pow_min;

	// Pre-process parameter: pow_max
	__parameterTypeNames[2] = "System.Double";
	__parameterTypes[2] = (CDOTNET_DOUBLE);
	__parameters[2] = &pow_max;

	// Pre-process parameter: power
	__parameterTypeNames[3] = "System.Double&";
	__parameterTypes[3] = (CDOTNET_DOUBLE | CDOTNET_OUT);
	__parameters[3] = power;

	// Pre-process parameter: points
	__parameterTypeNames[4] = "System.Double[,]&";
	__parameterTypes[4] = (CDOTNET_DOUBLE | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[4] = &points__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"TxPowerCalHonda", 
		0, 
		0, 
		5, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));

	// Post-process parameter: points
	if (points__) {
		__errChk(CDotNetGetArrayElements(
			points__, 
			CDOTNET_DOUBLE, 
			0, 
			points));
		__errChk(CDotNetGetArrayLength(
			points__, 
			0, 
			__pointsLength1));
		__errChk(CDotNetGetArrayLength(
			points__, 
			1, 
			__pointsLength2));
	}


__Error:
	if (points__)
		CDotNetDiscardHandle(points__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			points, 
			CDOTNET_DOUBLE, 
			2, 
			__pointsLength1, 
			__pointsLength2);
	}
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTester_IQCalHonda(
	Alv_Test_Mfg_MfgTester __instance,
	double ** points,
	ssize_t * __pointsLength1,
	ssize_t * __pointsLength2,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle points__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	*points = 0;
	*__pointsLength1 = 0;
	*__pointsLength2 = 0;


	// Pre-process parameter: points
	__parameterTypeNames[0] = "System.Double[,]&";
	__parameterTypes[0] = (CDOTNET_DOUBLE | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[0] = &points__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"IQCalHonda", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));

	// Post-process parameter: points
	if (points__) {
		__errChk(CDotNetGetArrayElements(
			points__, 
			CDOTNET_DOUBLE, 
			0, 
			points));
		__errChk(CDotNetGetArrayLength(
			points__, 
			0, 
			__pointsLength1));
		__errChk(CDotNetGetArrayLength(
			points__, 
			1, 
			__pointsLength2));
	}


__Error:
	if (points__)
		CDotNetDiscardHandle(points__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			points, 
			CDOTNET_DOUBLE, 
			2, 
			__pointsLength1, 
			__pointsLength2);
	}
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTester_AngleCalHonda(
	Alv_Test_Mfg_MfgTester __instance,
	int count,
	double ** points,
	ssize_t * __pointsLength1,
	ssize_t * __pointsLength2,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	CDotNetHandle points__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	*points = 0;
	*__pointsLength1 = 0;
	*__pointsLength2 = 0;


	// Pre-process parameter: count
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &count;

	// Pre-process parameter: points
	__parameterTypeNames[1] = "System.Double[,]&";
	__parameterTypes[1] = (CDOTNET_DOUBLE | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[1] = &points__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"AngleCalHonda", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));

	// Post-process parameter: points
	if (points__) {
		__errChk(CDotNetGetArrayElements(
			points__, 
			CDOTNET_DOUBLE, 
			0, 
			points));
		__errChk(CDotNetGetArrayLength(
			points__, 
			0, 
			__pointsLength1));
		__errChk(CDotNetGetArrayLength(
			points__, 
			1, 
			__pointsLength2));
	}


__Error:
	if (points__)
		CDotNetDiscardHandle(points__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			points, 
			CDOTNET_DOUBLE, 
			2, 
			__pointsLength1, 
			__pointsLength2);
	}
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTester_BSDCalHonda(
	Alv_Test_Mfg_MfgTester __instance,
	int count,
	double ** points,
	ssize_t * __pointsLength,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	CDotNetHandle points__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	*points = 0;
	*__pointsLength = 0;


	// Pre-process parameter: count
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &count;

	// Pre-process parameter: points
	__parameterTypeNames[1] = "System.Double[]&";
	__parameterTypes[1] = (CDOTNET_DOUBLE | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[1] = &points__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"BSDCalHonda", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));

	// Post-process parameter: points
	if (points__) {
		__errChk(CDotNetGetArrayElements(
			points__, 
			CDOTNET_DOUBLE, 
			0, 
			points));
		__errChk(CDotNetGetArrayLength(
			points__, 
			0, 
			__pointsLength));
	}


__Error:
	if (points__)
		CDotNetDiscardHandle(points__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			points, 
			CDOTNET_DOUBLE, 
			1, 
			__pointsLength);
	}
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTester_BSDCalHonda_1(
	Alv_Test_Mfg_MfgTester __instance,
	int count,
	double angle,
	double threshold,
	double ** points,
	ssize_t * __pointsLength,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];
	CDotNetHandle points__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	*points = 0;
	*__pointsLength = 0;


	// Pre-process parameter: count
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &count;

	// Pre-process parameter: angle
	__parameterTypeNames[1] = "System.Double";
	__parameterTypes[1] = (CDOTNET_DOUBLE);
	__parameters[1] = &angle;

	// Pre-process parameter: threshold
	__parameterTypeNames[2] = "System.Double";
	__parameterTypes[2] = (CDOTNET_DOUBLE);
	__parameters[2] = &threshold;

	// Pre-process parameter: points
	__parameterTypeNames[3] = "System.Double[]&";
	__parameterTypes[3] = (CDOTNET_DOUBLE | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[3] = &points__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"BSDCalHonda", 
		0, 
		0, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));

	// Post-process parameter: points
	if (points__) {
		__errChk(CDotNetGetArrayElements(
			points__, 
			CDOTNET_DOUBLE, 
			0, 
			points));
		__errChk(CDotNetGetArrayLength(
			points__, 
			0, 
			__pointsLength));
	}


__Error:
	if (points__)
		CDotNetDiscardHandle(points__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			points, 
			CDOTNET_DOUBLE, 
			1, 
			__pointsLength);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[9] = {0};
	unsigned int __parameterTypes[9];
	void * __parameters[9];
	CDotNetHandle power__ = 0;
	CDotNetHandle amp__ = 0;
	CDotNetHandle sw__ = 0;
	CDotNetHandle pdet__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	*power = 0;
	*__powerLength = 0;
	*amp = 0;
	*__ampLength = 0;
	*sw = 0;
	*__swLength = 0;
	*pdet = 0;
	*__pdetLength = 0;


	// Pre-process parameter: pow_max_bsd
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &pow_max_bsd;

	// Pre-process parameter: pow_max_rcta
	__parameterTypeNames[1] = "System.Double";
	__parameterTypes[1] = (CDOTNET_DOUBLE);
	__parameters[1] = &pow_max_rcta;

	// Pre-process parameter: pow_min_bsd
	__parameterTypeNames[2] = "System.Double";
	__parameterTypes[2] = (CDOTNET_DOUBLE);
	__parameters[2] = &pow_min_bsd;

	// Pre-process parameter: pow_min_rcta
	__parameterTypeNames[3] = "System.Double";
	__parameterTypes[3] = (CDOTNET_DOUBLE);
	__parameters[3] = &pow_min_rcta;

	// Pre-process parameter: power
	__parameterTypeNames[4] = "System.Double[]&";
	__parameterTypes[4] = (CDOTNET_DOUBLE | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[4] = &power__;

	// Pre-process parameter: amp
	__parameterTypeNames[5] = "System.UInt16[]&";
	__parameterTypes[5] = (CDOTNET_UINT16 | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[5] = &amp__;

	// Pre-process parameter: sw
	__parameterTypeNames[6] = "System.UInt16[]&";
	__parameterTypes[6] = (CDOTNET_UINT16 | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[6] = &sw__;

	// Pre-process parameter: pdet
	__parameterTypeNames[7] = "System.UInt16[]&";
	__parameterTypes[7] = (CDOTNET_UINT16 | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[7] = &pdet__;

	// Pre-process parameter: thermistor
	__parameterTypeNames[8] = "System.UInt16&";
	__parameterTypes[8] = (CDOTNET_UINT16 | CDOTNET_OUT);
	__parameters[8] = thermistor;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"TxPowerCalGM", 
		0, 
		0, 
		9, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));

	// Post-process parameter: power
	if (power__) {
		__errChk(CDotNetGetArrayElements(
			power__, 
			CDOTNET_DOUBLE, 
			0, 
			power));
		__errChk(CDotNetGetArrayLength(
			power__, 
			0, 
			__powerLength));
	}

	// Post-process parameter: amp
	if (amp__) {
		__errChk(CDotNetGetArrayElements(
			amp__, 
			CDOTNET_UINT16, 
			0, 
			amp));
		__errChk(CDotNetGetArrayLength(
			amp__, 
			0, 
			__ampLength));
	}

	// Post-process parameter: sw
	if (sw__) {
		__errChk(CDotNetGetArrayElements(
			sw__, 
			CDOTNET_UINT16, 
			0, 
			sw));
		__errChk(CDotNetGetArrayLength(
			sw__, 
			0, 
			__swLength));
	}

	// Post-process parameter: pdet
	if (pdet__) {
		__errChk(CDotNetGetArrayElements(
			pdet__, 
			CDOTNET_UINT16, 
			0, 
			pdet));
		__errChk(CDotNetGetArrayLength(
			pdet__, 
			0, 
			__pdetLength));
	}


__Error:
	if (power__)
		CDotNetDiscardHandle(power__);
	if (amp__)
		CDotNetDiscardHandle(amp__);
	if (sw__)
		CDotNetDiscardHandle(sw__);
	if (pdet__)
		CDotNetDiscardHandle(pdet__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			power, 
			CDOTNET_DOUBLE, 
			1, 
			__powerLength);
		_CDotNetGenDisposeArray(
			amp, 
			CDOTNET_UINT16, 
			1, 
			__ampLength);
		_CDotNetGenDisposeArray(
			sw, 
			CDOTNET_UINT16, 
			1, 
			__swLength);
		_CDotNetGenDisposeArray(
			pdet, 
			CDOTNET_UINT16, 
			1, 
			__pdetLength);
	}
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTester_TxPowerCalVEVA(
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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[9] = {0};
	unsigned int __parameterTypes[9];
	void * __parameters[9];
	CDotNetHandle power__ = 0;
	CDotNetHandle amp__ = 0;
	CDotNetHandle sw__ = 0;
	CDotNetHandle pdet__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	*power = 0;
	*__powerLength = 0;
	*amp = 0;
	*__ampLength = 0;
	*sw = 0;
	*__swLength = 0;
	*pdet = 0;
	*__pdetLength = 0;


	// Pre-process parameter: pow_max_bsd
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &pow_max_bsd;

	// Pre-process parameter: pow_max_rcta
	__parameterTypeNames[1] = "System.Double";
	__parameterTypes[1] = (CDOTNET_DOUBLE);
	__parameters[1] = &pow_max_rcta;

	// Pre-process parameter: pow_min_bsd
	__parameterTypeNames[2] = "System.Double";
	__parameterTypes[2] = (CDOTNET_DOUBLE);
	__parameters[2] = &pow_min_bsd;

	// Pre-process parameter: pow_min_rcta
	__parameterTypeNames[3] = "System.Double";
	__parameterTypes[3] = (CDOTNET_DOUBLE);
	__parameters[3] = &pow_min_rcta;

	// Pre-process parameter: power
	__parameterTypeNames[4] = "System.Double[]&";
	__parameterTypes[4] = (CDOTNET_DOUBLE | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[4] = &power__;

	// Pre-process parameter: amp
	__parameterTypeNames[5] = "System.UInt16[]&";
	__parameterTypes[5] = (CDOTNET_UINT16 | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[5] = &amp__;

	// Pre-process parameter: sw
	__parameterTypeNames[6] = "System.UInt16[]&";
	__parameterTypes[6] = (CDOTNET_UINT16 | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[6] = &sw__;

	// Pre-process parameter: pdet
	__parameterTypeNames[7] = "System.UInt16[]&";
	__parameterTypes[7] = (CDOTNET_UINT16 | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[7] = &pdet__;

	// Pre-process parameter: thermistor
	__parameterTypeNames[8] = "System.UInt16&";
	__parameterTypes[8] = (CDOTNET_UINT16 | CDOTNET_OUT);
	__parameters[8] = thermistor;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"TxPowerCalVEVA", 
		0, 
		0, 
		9, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));

	// Post-process parameter: power
	if (power__) {
		__errChk(CDotNetGetArrayElements(
			power__, 
			CDOTNET_DOUBLE, 
			0, 
			power));
		__errChk(CDotNetGetArrayLength(
			power__, 
			0, 
			__powerLength));
	}

	// Post-process parameter: amp
	if (amp__) {
		__errChk(CDotNetGetArrayElements(
			amp__, 
			CDOTNET_UINT16, 
			0, 
			amp));
		__errChk(CDotNetGetArrayLength(
			amp__, 
			0, 
			__ampLength));
	}

	// Post-process parameter: sw
	if (sw__) {
		__errChk(CDotNetGetArrayElements(
			sw__, 
			CDOTNET_UINT16, 
			0, 
			sw));
		__errChk(CDotNetGetArrayLength(
			sw__, 
			0, 
			__swLength));
	}

	// Post-process parameter: pdet
	if (pdet__) {
		__errChk(CDotNetGetArrayElements(
			pdet__, 
			CDOTNET_UINT16, 
			0, 
			pdet));
		__errChk(CDotNetGetArrayLength(
			pdet__, 
			0, 
			__pdetLength));
	}


__Error:
	if (power__)
		CDotNetDiscardHandle(power__);
	if (amp__)
		CDotNetDiscardHandle(amp__);
	if (sw__)
		CDotNetDiscardHandle(sw__);
	if (pdet__)
		CDotNetDiscardHandle(pdet__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			power, 
			CDOTNET_DOUBLE, 
			1, 
			__powerLength);
		_CDotNetGenDisposeArray(
			amp, 
			CDOTNET_UINT16, 
			1, 
			__ampLength);
		_CDotNetGenDisposeArray(
			sw, 
			CDOTNET_UINT16, 
			1, 
			__swLength);
		_CDotNetGenDisposeArray(
			pdet, 
			CDOTNET_UINT16, 
			1, 
			__pdetLength);
	}
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTester_IQCalGM(
	Alv_Test_Mfg_MfgTester __instance,
	double ** points,
	ssize_t * __pointsLength1,
	ssize_t * __pointsLength2,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle points__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	*points = 0;
	*__pointsLength1 = 0;
	*__pointsLength2 = 0;


	// Pre-process parameter: points
	__parameterTypeNames[0] = "System.Double[,]&";
	__parameterTypes[0] = (CDOTNET_DOUBLE | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[0] = &points__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"IQCalGM", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));

	// Post-process parameter: points
	if (points__) {
		__errChk(CDotNetGetArrayElements(
			points__, 
			CDOTNET_DOUBLE, 
			0, 
			points));
		__errChk(CDotNetGetArrayLength(
			points__, 
			0, 
			__pointsLength1));
		__errChk(CDotNetGetArrayLength(
			points__, 
			1, 
			__pointsLength2));
	}


__Error:
	if (points__)
		CDotNetDiscardHandle(points__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			points, 
			CDOTNET_DOUBLE, 
			2, 
			__pointsLength1, 
			__pointsLength2);
	}
	return __error;
}

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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[10] = {0};
	unsigned int __parameterTypes[10];
	void * __parameters[10];
	CDotNetHandle TrueAngles__ = 0;
	CDotNetHandle measured_theta__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	*TrueAngles = 0;
	*__TrueAnglesLength = 0;
	*measured_theta = 0;
	*__measured_thetaLength1 = 0;
	*__measured_thetaLength2 = 0;
	*beam_formed_theta = 0;
	*TableCalcPoints = 0;
	*TableCalcValues = 0;
	*TableTruePoints = 0;
	*TableTrueValues = 0;


	// Pre-process parameter: count
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &count;

	// Pre-process parameter: MDA_start
	__parameterTypeNames[1] = "System.Double";
	__parameterTypes[1] = (CDOTNET_DOUBLE);
	__parameters[1] = &MDA_start;

	// Pre-process parameter: MDA_stop
	__parameterTypeNames[2] = "System.Double";
	__parameterTypes[2] = (CDOTNET_DOUBLE);
	__parameters[2] = &MDA_stop;

	// Pre-process parameter: TrueAngles
	__parameterTypeNames[3] = "System.Double[]&";
	__parameterTypes[3] = (CDOTNET_DOUBLE | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[3] = &TrueAngles__;

	// Pre-process parameter: measured_theta
	__parameterTypeNames[4] = "System.Double[,]&";
	__parameterTypes[4] = (CDOTNET_DOUBLE | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[4] = &measured_theta__;

	// Pre-process parameter: beam_formed_theta
	__parameterTypeNames[5] = "System.Double[][]&";
	__parameterTypes[5] = (CDOTNET_OBJECT | CDOTNET_OUT);
	__parameters[5] = beam_formed_theta;

	// Pre-process parameter: TableCalcPoints
	__parameterTypeNames[6] = "System.UInt16[][]&";
	__parameterTypes[6] = (CDOTNET_OBJECT | CDOTNET_OUT);
	__parameters[6] = TableCalcPoints;

	// Pre-process parameter: TableCalcValues
	__parameterTypeNames[7] = "System.Double[][]&";
	__parameterTypes[7] = (CDOTNET_OBJECT | CDOTNET_OUT);
	__parameters[7] = TableCalcValues;

	// Pre-process parameter: TableTruePoints
	__parameterTypeNames[8] = "System.UInt16[][]&";
	__parameterTypes[8] = (CDOTNET_OBJECT | CDOTNET_OUT);
	__parameters[8] = TableTruePoints;

	// Pre-process parameter: TableTrueValues
	__parameterTypeNames[9] = "System.Double[][]&";
	__parameterTypes[9] = (CDOTNET_OBJECT | CDOTNET_OUT);
	__parameters[9] = TableTrueValues;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"AngleCalGM", 
		0, 
		0, 
		10, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));

	// Post-process parameter: TrueAngles
	if (TrueAngles__) {
		__errChk(CDotNetGetArrayElements(
			TrueAngles__, 
			CDOTNET_DOUBLE, 
			0, 
			TrueAngles));
		__errChk(CDotNetGetArrayLength(
			TrueAngles__, 
			0, 
			__TrueAnglesLength));
	}

	// Post-process parameter: measured_theta
	if (measured_theta__) {
		__errChk(CDotNetGetArrayElements(
			measured_theta__, 
			CDOTNET_DOUBLE, 
			0, 
			measured_theta));
		__errChk(CDotNetGetArrayLength(
			measured_theta__, 
			0, 
			__measured_thetaLength1));
		__errChk(CDotNetGetArrayLength(
			measured_theta__, 
			1, 
			__measured_thetaLength2));
	}


__Error:
	if (TrueAngles__)
		CDotNetDiscardHandle(TrueAngles__);
	if (measured_theta__)
		CDotNetDiscardHandle(measured_theta__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			TrueAngles, 
			CDOTNET_DOUBLE, 
			1, 
			__TrueAnglesLength);
		_CDotNetGenDisposeArray(
			measured_theta, 
			CDOTNET_DOUBLE, 
			2, 
			__measured_thetaLength1, 
			__measured_thetaLength2);
		_CDotNetGenDisposeScalar(
			beam_formed_theta, 
			CDOTNET_OBJECT);
		_CDotNetGenDisposeScalar(
			TableCalcPoints, 
			CDOTNET_OBJECT);
		_CDotNetGenDisposeScalar(
			TableCalcValues, 
			CDOTNET_OBJECT);
		_CDotNetGenDisposeScalar(
			TableTruePoints, 
			CDOTNET_OBJECT);
		_CDotNetGenDisposeScalar(
			TableTrueValues, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Alv_Test_Mfg_MfgTester_AngleCalGM_1(
	Alv_Test_Mfg_MfgTester __instance,
	int count,
	double MDA_start,
	double MDA_stop,
	double * TrueAngles,
	ssize_t __TrueAnglesLength,
	double ** measured_theta,
	ssize_t * __measured_thetaLength1,
	ssize_t * __measured_thetaLength2,
	CDotNetHandle * beam_formed_theta,
	CDotNetHandle * TableCalcPoints,
	CDotNetHandle * TableCalcValues,
	CDotNetHandle * TableTruePoints,
	CDotNetHandle * TableTrueValues,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[10] = {0};
	unsigned int __parameterTypes[10];
	void * __parameters[10];
	CDotNetHandle TrueAngles__ = 0;
	CDotNetHandle measured_theta__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	*measured_theta = 0;
	*__measured_thetaLength1 = 0;
	*__measured_thetaLength2 = 0;
	*beam_formed_theta = 0;
	*TableCalcPoints = 0;
	*TableCalcValues = 0;
	*TableTruePoints = 0;
	*TableTrueValues = 0;


	// Pre-process parameter: count
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &count;

	// Pre-process parameter: MDA_start
	__parameterTypeNames[1] = "System.Double";
	__parameterTypes[1] = (CDOTNET_DOUBLE);
	__parameters[1] = &MDA_start;

	// Pre-process parameter: MDA_stop
	__parameterTypeNames[2] = "System.Double";
	__parameterTypes[2] = (CDOTNET_DOUBLE);
	__parameters[2] = &MDA_stop;

	// Pre-process parameter: TrueAngles
	if (TrueAngles)
		__errChk(CDotNetCreateArray(
			CDOTNET_DOUBLE, 
			1, 
			0, 
			&__TrueAnglesLength, 
			TrueAngles, 
			&TrueAngles__));
	__parameterTypeNames[3] = "System.Double[]";
	__parameterTypes[3] = (CDOTNET_DOUBLE | CDOTNET_ARRAY);
	__parameters[3] = &TrueAngles__;

	// Pre-process parameter: measured_theta
	__parameterTypeNames[4] = "System.Double[,]&";
	__parameterTypes[4] = (CDOTNET_DOUBLE | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[4] = &measured_theta__;

	// Pre-process parameter: beam_formed_theta
	__parameterTypeNames[5] = "System.Double[][]&";
	__parameterTypes[5] = (CDOTNET_OBJECT | CDOTNET_OUT);
	__parameters[5] = beam_formed_theta;

	// Pre-process parameter: TableCalcPoints
	__parameterTypeNames[6] = "System.UInt16[][]&";
	__parameterTypes[6] = (CDOTNET_OBJECT | CDOTNET_OUT);
	__parameters[6] = TableCalcPoints;

	// Pre-process parameter: TableCalcValues
	__parameterTypeNames[7] = "System.Double[][]&";
	__parameterTypes[7] = (CDOTNET_OBJECT | CDOTNET_OUT);
	__parameters[7] = TableCalcValues;

	// Pre-process parameter: TableTruePoints
	__parameterTypeNames[8] = "System.UInt16[][]&";
	__parameterTypes[8] = (CDOTNET_OBJECT | CDOTNET_OUT);
	__parameters[8] = TableTruePoints;

	// Pre-process parameter: TableTrueValues
	__parameterTypeNames[9] = "System.Double[][]&";
	__parameterTypes[9] = (CDOTNET_OBJECT | CDOTNET_OUT);
	__parameters[9] = TableTrueValues;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Mfg.MfgTester", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"AngleCalGM", 
		0, 
		0, 
		10, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));

	// Post-process parameter: measured_theta
	if (measured_theta__) {
		__errChk(CDotNetGetArrayElements(
			measured_theta__, 
			CDOTNET_DOUBLE, 
			0, 
			measured_theta));
		__errChk(CDotNetGetArrayLength(
			measured_theta__, 
			0, 
			__measured_thetaLength1));
		__errChk(CDotNetGetArrayLength(
			measured_theta__, 
			1, 
			__measured_thetaLength2));
	}


__Error:
	if (TrueAngles__)
		CDotNetDiscardHandle(TrueAngles__);
	if (measured_theta__)
		CDotNetDiscardHandle(measured_theta__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			measured_theta, 
			CDOTNET_DOUBLE, 
			2, 
			__measured_thetaLength1, 
			__measured_thetaLength2);
		_CDotNetGenDisposeScalar(
			beam_formed_theta, 
			CDOTNET_OBJECT);
		_CDotNetGenDisposeScalar(
			TableCalcPoints, 
			CDOTNET_OBJECT);
		_CDotNetGenDisposeScalar(
			TableCalcValues, 
			CDOTNET_OBJECT);
		_CDotNetGenDisposeScalar(
			TableTruePoints, 
			CDOTNET_OBJECT);
		_CDotNetGenDisposeScalar(
			TableTrueValues, 
			CDOTNET_OBJECT);
	}
	return __error;
}


// Type: Alv.GPIB.VISA
int CVIFUNC Alv_GPIB_VISA__Create(
	Alv_GPIB_VISA * __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"Alv.GPIB.VISA", 
		0, 
		0, 
		__instance, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_VISA_Connect(
	Alv_GPIB_VISA __instance,
	int GPIB,
	int Device_ID,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: GPIB
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &GPIB;

	// Pre-process parameter: Device_ID
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &Device_ID;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.VISA", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Connect", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_VISA_Close(
	Alv_GPIB_VISA __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.VISA", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Close", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_VISA_ResetState(
	Alv_GPIB_VISA __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.VISA", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ResetState", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_VISA_Calibrate(
	Alv_GPIB_VISA __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.VISA", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Calibrate", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_VISA_Identification(
	Alv_GPIB_VISA __instance,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.VISA", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Identification", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC Alv_GPIB_VISA_Ready(
	Alv_GPIB_VISA __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.VISA", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Ready", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_VISA_Recall(
	Alv_GPIB_VISA __instance,
	int state,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: state
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &state;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.VISA", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Recall", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_VISA_Save(
	Alv_GPIB_VISA __instance,
	int state,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: state
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &state;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.VISA", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Save", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_VISA_Wait(
	Alv_GPIB_VISA __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.VISA", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Wait", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}


// Type: Alv.GPIB.E3632A
int CVIFUNC Alv_GPIB_E3632A__Create(
	Alv_GPIB_E3632A * __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"Alv.GPIB.E3632A", 
		0, 
		0, 
		__instance, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_E3632A_Apply(
	Alv_GPIB_E3632A __instance,
	double voltage,
	double current,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: voltage
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &voltage;

	// Pre-process parameter: current
	__parameterTypeNames[1] = "System.Double";
	__parameterTypes[1] = (CDOTNET_DOUBLE);
	__parameters[1] = &current;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.E3632A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Apply", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_E3632A_VoltageRange(
	Alv_GPIB_E3632A __instance,
	int high,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: high
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &high;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.E3632A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"VoltageRange", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_E3632A_SetOutput(
	Alv_GPIB_E3632A __instance,
	int on,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: on
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &on;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.E3632A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"SetOutput", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_E3632A_Voltage(
	Alv_GPIB_E3632A __instance,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.E3632A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Voltage", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_E3632A_Current(
	Alv_GPIB_E3632A __instance,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.E3632A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Current", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_E3632A_Connect(
	Alv_GPIB_E3632A __instance,
	int GPIB,
	int Device_ID,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: GPIB
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &GPIB;

	// Pre-process parameter: Device_ID
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &Device_ID;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.E3632A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Connect", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_E3632A_Close(
	Alv_GPIB_E3632A __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.E3632A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Close", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_E3632A_ResetState(
	Alv_GPIB_E3632A __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.E3632A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ResetState", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_E3632A_Calibrate(
	Alv_GPIB_E3632A __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.E3632A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Calibrate", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_E3632A_Identification(
	Alv_GPIB_E3632A __instance,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.E3632A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Identification", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC Alv_GPIB_E3632A_Ready(
	Alv_GPIB_E3632A __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.E3632A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Ready", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_E3632A_Recall(
	Alv_GPIB_E3632A __instance,
	int state,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: state
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &state;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.E3632A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Recall", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_E3632A_Save(
	Alv_GPIB_E3632A __instance,
	int state,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: state
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &state;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.E3632A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Save", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_E3632A_Wait(
	Alv_GPIB_E3632A __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.E3632A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Wait", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}


// Type: Alv.GPIB.N9010A
int CVIFUNC Alv_GPIB_N9010A__Create(
	Alv_GPIB_N9010A * __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		0, 
		0, 
		__instance, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_Preset(
	Alv_GPIB_N9010A __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Preset", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_ReferenceLevel(
	Alv_GPIB_N9010A __instance,
	double dBm,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: dBm
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &dBm;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ReferenceLevel", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_ReferenceLevelOffset(
	Alv_GPIB_N9010A __instance,
	double dB,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: dB
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &dB;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ReferenceLevelOffset", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_Attenuation(
	Alv_GPIB_N9010A __instance,
	double dB,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: dB
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &dB;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Attenuation", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_ReferenceLevelOffset_1(
	Alv_GPIB_N9010A __instance,
	int dB,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: dB
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &dB;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ReferenceLevelOffset", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_AutoCouple(
	Alv_GPIB_N9010A __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"AutoCouple", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_Cont(
	Alv_GPIB_N9010A __instance,
	int on,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: on
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &on;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Cont", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_AutoTune(
	Alv_GPIB_N9010A __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"AutoTune", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_CenterFreq(
	Alv_GPIB_N9010A __instance,
	double MHz,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: MHz
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &MHz;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"CenterFreq", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_FreqSpan(
	Alv_GPIB_N9010A __instance,
	double MHz,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: MHz
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &MHz;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"FreqSpan", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_StartFreq(
	Alv_GPIB_N9010A __instance,
	double MHz,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: MHz
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &MHz;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"StartFreq", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_StopFreq(
	Alv_GPIB_N9010A __instance,
	double MHz,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: MHz
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &MHz;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"StopFreq", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_SweepTime(
	Alv_GPIB_N9010A __instance,
	double ms,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: ms
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &ms;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"SweepTime", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_SweepPoints(
	Alv_GPIB_N9010A __instance,
	int points,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: points
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &points;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"SweepPoints", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_ResolutionBand(
	Alv_GPIB_N9010A __instance,
	double MHz,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: MHz
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &MHz;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ResolutionBand", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_VideoBand(
	Alv_GPIB_N9010A __instance,
	double MHz,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: MHz
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &MHz;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"VideoBand", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_Trace(
	Alv_GPIB_N9010A __instance,
	Alv_GPIB_N9010A_Traces trace,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle trace__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: trace
	__errChk(Alv_GPIB_N9010A_Traces__Create(
		&trace, 
		&trace__, 
		__exception));
	__parameterTypeNames[0] = "Alv.GPIB.N9010A+Traces";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &trace__;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Trace", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (trace__)
		CDotNetDiscardHandle(trace__);
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_Measure(
	Alv_GPIB_N9010A __instance,
	Alv_GPIB_N9010A_Measurments measurment,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle measurment__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: measurment
	__errChk(Alv_GPIB_N9010A_Measurments__Create(
		&measurment, 
		&measurment__, 
		__exception));
	__parameterTypeNames[0] = "Alv.GPIB.N9010A+Measurments";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &measurment__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Measure", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (measurment__)
		CDotNetDiscardHandle(measurment__);
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_Configure(
	Alv_GPIB_N9010A __instance,
	Alv_GPIB_N9010A_Measurments measurment,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle measurment__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: measurment
	__errChk(Alv_GPIB_N9010A_Measurments__Create(
		&measurment, 
		&measurment__, 
		__exception));
	__parameterTypeNames[0] = "Alv.GPIB.N9010A+Measurments";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &measurment__;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Configure", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (measurment__)
		CDotNetDiscardHandle(measurment__);
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_ConfigureNdef(
	Alv_GPIB_N9010A __instance,
	Alv_GPIB_N9010A_Measurments measurment,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle measurment__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: measurment
	__errChk(Alv_GPIB_N9010A_Measurments__Create(
		&measurment, 
		&measurment__, 
		__exception));
	__parameterTypeNames[0] = "Alv.GPIB.N9010A+Measurments";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &measurment__;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ConfigureNdef", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (measurment__)
		CDotNetDiscardHandle(measurment__);
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_Fetch(
	Alv_GPIB_N9010A __instance,
	Alv_GPIB_N9010A_Measurments measurment,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle measurment__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: measurment
	__errChk(Alv_GPIB_N9010A_Measurments__Create(
		&measurment, 
		&measurment__, 
		__exception));
	__parameterTypeNames[0] = "Alv.GPIB.N9010A+Measurments";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &measurment__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Fetch", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (measurment__)
		CDotNetDiscardHandle(measurment__);
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_Initiate(
	Alv_GPIB_N9010A __instance,
	Alv_GPIB_N9010A_Measurments measurment,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle measurment__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: measurment
	__errChk(Alv_GPIB_N9010A_Measurments__Create(
		&measurment, 
		&measurment__, 
		__exception));
	__parameterTypeNames[0] = "Alv.GPIB.N9010A+Measurments";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &measurment__;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Initiate", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (measurment__)
		CDotNetDiscardHandle(measurment__);
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_Read(
	Alv_GPIB_N9010A __instance,
	Alv_GPIB_N9010A_Measurments measurment,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle measurment__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: measurment
	__errChk(Alv_GPIB_N9010A_Measurments__Create(
		&measurment, 
		&measurment__, 
		__exception));
	__parameterTypeNames[0] = "Alv.GPIB.N9010A+Measurments";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &measurment__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Read", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (measurment__)
		CDotNetDiscardHandle(measurment__);
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_Reset(
	Alv_GPIB_N9010A __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Reset", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_Marker(
	Alv_GPIB_N9010A __instance,
	int marker,
	Alv_GPIB_N9010A_Markers mode,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	CDotNetHandle mode__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: marker
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &marker;

	// Pre-process parameter: mode
	__errChk(Alv_GPIB_N9010A_Markers__Create(
		&mode, 
		&mode__, 
		__exception));
	__parameterTypeNames[1] = "Alv.GPIB.N9010A+Markers";
	__parameterTypes[1] = (CDOTNET_ENUM);
	__parameters[1] = &mode__;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Marker", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (mode__)
		CDotNetDiscardHandle(mode__);
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_MkrToCf(
	Alv_GPIB_N9010A __instance,
	int marker,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: marker
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &marker;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"MkrToCf", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_MkrToStart(
	Alv_GPIB_N9010A __instance,
	int marker,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: marker
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &marker;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"MkrToStart", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_MkrToStop(
	Alv_GPIB_N9010A __instance,
	int marker,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: marker
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &marker;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"MkrToStop", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_PeakSearch(
	Alv_GPIB_N9010A __instance,
	int marker,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: marker
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &marker;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"PeakSearch", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_MinSearch(
	Alv_GPIB_N9010A __instance,
	int marker,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: marker
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &marker;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"MinSearch", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_MarkerX(
	Alv_GPIB_N9010A __instance,
	int marker,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: marker
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &marker;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"MarkerX", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_MarkerY(
	Alv_GPIB_N9010A __instance,
	int marker,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: marker
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &marker;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"MarkerY", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_ObwReferenceLevel(
	Alv_GPIB_N9010A __instance,
	double dBm,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: dBm
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &dBm;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ObwReferenceLevel", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_ObwResolutionBand(
	Alv_GPIB_N9010A __instance,
	double MHz,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: MHz
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &MHz;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ObwResolutionBand", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_ObwVideoBand(
	Alv_GPIB_N9010A __instance,
	double MHz,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: MHz
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &MHz;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ObwVideoBand", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_ObwPrecentile(
	Alv_GPIB_N9010A __instance,
	int percentile,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: percentile
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &percentile;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ObwPrecentile", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_ObwFreqSpan(
	Alv_GPIB_N9010A __instance,
	double MHz,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: MHz
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &MHz;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ObwFreqSpan", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_ObwTrace(
	Alv_GPIB_N9010A __instance,
	Alv_GPIB_N9010A_Traces trace,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle trace__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: trace
	__errChk(Alv_GPIB_N9010A_Traces__Create(
		&trace, 
		&trace__, 
		__exception));
	__parameterTypeNames[0] = "Alv.GPIB.N9010A+Traces";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &trace__;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ObwTrace", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (trace__)
		CDotNetDiscardHandle(trace__);
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_ObwSweepTime(
	Alv_GPIB_N9010A __instance,
	double ms,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: ms
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &ms;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ObwSweepTime", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_ChpReferenceLevel(
	Alv_GPIB_N9010A __instance,
	double dBm,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: dBm
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &dBm;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ChpReferenceLevel", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_ChpIntegBw(
	Alv_GPIB_N9010A __instance,
	double MHz,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: MHz
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &MHz;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ChpIntegBw", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_ChpFreqSpan(
	Alv_GPIB_N9010A __instance,
	double MHz,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: MHz
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &MHz;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ChpFreqSpan", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_ChpAverageCount(
	Alv_GPIB_N9010A __instance,
	int count,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: count
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &count;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ChpAverageCount", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_PowerConfigure(
	Alv_GPIB_N9010A __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"PowerConfigure", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_PowerAverage(
	Alv_GPIB_N9010A __instance,
	int samples,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: samples
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &samples;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"PowerAverage", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_PowerFrequency(
	Alv_GPIB_N9010A __instance,
	int center,
	int span,
	int points,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: center
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &center;

	// Pre-process parameter: span
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &span;

	// Pre-process parameter: points
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &points;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"PowerFrequency", 
		0, 
		0, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_ReadPower(
	Alv_GPIB_N9010A __instance,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ReadPower", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_Connect(
	Alv_GPIB_N9010A __instance,
	int GPIB,
	int Device_ID,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: GPIB
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &GPIB;

	// Pre-process parameter: Device_ID
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &Device_ID;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Connect", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_Close(
	Alv_GPIB_N9010A __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Close", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_ResetState(
	Alv_GPIB_N9010A __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ResetState", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_Calibrate(
	Alv_GPIB_N9010A __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Calibrate", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_Identification(
	Alv_GPIB_N9010A __instance,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Identification", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_Ready(
	Alv_GPIB_N9010A __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Ready", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_Recall(
	Alv_GPIB_N9010A __instance,
	int state,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: state
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &state;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Recall", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_Save(
	Alv_GPIB_N9010A __instance,
	int state,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: state
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &state;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Save", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_N9010A_Wait(
	Alv_GPIB_N9010A __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.N9010A", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Wait", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}


// Type: Alv.GPIB.A11713
int CVIFUNC Alv_GPIB_A11713__Create(
	Alv_GPIB_A11713 * __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"Alv.GPIB.A11713", 
		0, 
		0, 
		__instance, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_A11713_OpenPath(
	Alv_GPIB_A11713 __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.A11713", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"OpenPath", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_A11713_OpenPath_1(
	Alv_GPIB_A11713 __instance,
	int route,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: route
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &route;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.A11713", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"OpenPath", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_A11713_ClosePath(
	Alv_GPIB_A11713 __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.A11713", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ClosePath", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_A11713_ClosePath_1(
	Alv_GPIB_A11713 __instance,
	int route,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: route
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &route;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.A11713", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ClosePath", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_A11713_Supply(
	Alv_GPIB_A11713 __instance,
	int on,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: on
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &on;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.A11713", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Supply", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_A11713_TTL(
	Alv_GPIB_A11713 __instance,
	int on,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: on
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &on;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.A11713", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"TTL", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_A11713_Connect(
	Alv_GPIB_A11713 __instance,
	int GPIB,
	int Device_ID,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: GPIB
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &GPIB;

	// Pre-process parameter: Device_ID
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &Device_ID;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.A11713", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Connect", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_A11713_Close(
	Alv_GPIB_A11713 __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.A11713", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Close", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_A11713_ResetState(
	Alv_GPIB_A11713 __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.A11713", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ResetState", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_A11713_Calibrate(
	Alv_GPIB_A11713 __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.A11713", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Calibrate", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_A11713_Identification(
	Alv_GPIB_A11713 __instance,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.A11713", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Identification", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC Alv_GPIB_A11713_Ready(
	Alv_GPIB_A11713 __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.A11713", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Ready", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_A11713_Recall(
	Alv_GPIB_A11713 __instance,
	int state,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: state
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &state;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.A11713", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Recall", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_A11713_Save(
	Alv_GPIB_A11713 __instance,
	int state,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: state
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &state;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.A11713", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Save", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_A11713_Wait(
	Alv_GPIB_A11713 __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.A11713", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Wait", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}


// Type: Alv.Velmex.VXM
int CVIFUNC Alv_Velmex_VXM__Create(
	Alv_Velmex_VXM * __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"Alv.Velmex.VXM", 
		0, 
		0, 
		__instance, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Velmex_VXM_Connect(
	Alv_Velmex_VXM __instance,
	char * port_name,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: port_name
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &port_name;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Velmex.VXM", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Connect", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Velmex_VXM_Connect_1(
	Alv_Velmex_VXM __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Velmex.VXM", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Connect", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Velmex_VXM_Disconnect(
	Alv_Velmex_VXM __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Velmex.VXM", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Disconnect", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Velmex_VXM_Transmit(
	Alv_Velmex_VXM __instance,
	char * command,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: command
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &command;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Velmex.VXM", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Transmit", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Velmex_VXM_Recieve(
	Alv_Velmex_VXM __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_CHAR;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Velmex.VXM", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Recieve", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Velmex_VXM_Clear(
	Alv_Velmex_VXM __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Velmex.VXM", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Clear", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Velmex_VXM_V(
	Alv_Velmex_VXM __instance,
	unsigned short * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_CHAR;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Velmex.VXM", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"V", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Velmex_VXM_halt(
	Alv_Velmex_VXM __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Velmex.VXM", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"halt", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Velmex_VXM_Run(
	Alv_Velmex_VXM __instance,
	int wait,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: wait
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &wait;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Velmex.VXM", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Run", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Velmex_VXM_get_ang(
	Alv_Velmex_VXM __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Velmex.VXM", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"get_ang", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Velmex_VXM_get_lin(
	Alv_Velmex_VXM __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Velmex.VXM", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"get_lin", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Velmex_VXM_rehome_ang(
	Alv_Velmex_VXM __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Velmex.VXM", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"rehome_ang", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Velmex_VXM_rehome_lin(
	Alv_Velmex_VXM __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Velmex.VXM", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"rehome_lin", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Velmex_VXM_rehome_ang_1(
	Alv_Velmex_VXM __instance,
	int port,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: port
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &port;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Velmex.VXM", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"rehome_ang", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Velmex_VXM_rehome_lin_1(
	Alv_Velmex_VXM __instance,
	int port,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: port
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &port;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Velmex.VXM", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"rehome_lin", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Velmex_VXM_set_ang(
	Alv_Velmex_VXM __instance,
	int steps,
	int speed,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: steps
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &steps;

	// Pre-process parameter: speed
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &speed;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Velmex.VXM", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"set_ang", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Velmex_VXM_set_lin(
	Alv_Velmex_VXM __instance,
	int steps,
	int speed,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: steps
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &steps;

	// Pre-process parameter: speed
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &speed;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Velmex.VXM", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"set_lin", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Velmex_VXM_set_ang_1(
	Alv_Velmex_VXM __instance,
	int steps,
	int speed,
	int port,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: steps
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &steps;

	// Pre-process parameter: speed
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &speed;

	// Pre-process parameter: port
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &port;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Velmex.VXM", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"set_ang", 
		0, 
		0, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Velmex_VXM_set_lin_1(
	Alv_Velmex_VXM __instance,
	int steps,
	int speed,
	int port,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: steps
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &steps;

	// Pre-process parameter: speed
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &speed;

	// Pre-process parameter: port
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &port;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Velmex.VXM", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"set_lin", 
		0, 
		0, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Velmex_VXM_set_ang_motion(
	Alv_Velmex_VXM __instance,
	int steps,
	int speed,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: steps
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &steps;

	// Pre-process parameter: speed
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &speed;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Velmex.VXM", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"set_ang_motion", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Velmex_VXM_set_lin_motion(
	Alv_Velmex_VXM __instance,
	int steps,
	int speed,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: steps
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &steps;

	// Pre-process parameter: speed
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &speed;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Velmex.VXM", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"set_lin_motion", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Velmex_VXM_set_ang_motion_1(
	Alv_Velmex_VXM __instance,
	int steps,
	int speed,
	int port,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: steps
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &steps;

	// Pre-process parameter: speed
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &speed;

	// Pre-process parameter: port
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &port;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Velmex.VXM", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"set_ang_motion", 
		0, 
		0, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Velmex_VXM_set_lin_motion_1(
	Alv_Velmex_VXM __instance,
	int steps,
	int speed,
	int port,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: steps
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &steps;

	// Pre-process parameter: speed
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &speed;

	// Pre-process parameter: port
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &port;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Velmex.VXM", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"set_lin_motion", 
		0, 
		0, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Velmex_VXM_Cm2Step(
	double cm,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: cm
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &cm;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.Velmex.VXM", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"Cm2Step", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Velmex_VXM_Cm2Step_1(
	int cm,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: cm
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &cm;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.Velmex.VXM", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"Cm2Step", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Velmex_VXM_Step2Cm(
	int step,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: step
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &step;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.Velmex.VXM", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"Step2Cm", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Velmex_VXM_Deg2Step(
	int deg,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: deg
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &deg;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.Velmex.VXM", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"Deg2Step", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Velmex_VXM_Deg2Step_1(
	double deg,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: deg
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &deg;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.Velmex.VXM", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"Deg2Step", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Velmex_VXM_Step2Deg(
	int step,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: step
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &step;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.Velmex.VXM", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"Step2Deg", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Velmex_VXM__Get__MIN_M(
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.Velmex.VXM", 
		0, 
		0, 
		CDOTNET_GET_FIELD, 
		"MIN_M", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Velmex_VXM__Get__MAX_M(
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.Velmex.VXM", 
		0, 
		0, 
		CDOTNET_GET_FIELD, 
		"MAX_M", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}


// Type: Alv.GPIB.RS_FSV
int CVIFUNC Alv_GPIB_RS_FSV__Create(
	Alv_GPIB_RS_FSV * __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"Alv.GPIB.RS_FSV", 
		0, 
		0, 
		__instance, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_RS_FSV_Preamp(
	Alv_GPIB_RS_FSV __instance,
	int on,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: on
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &on;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.RS_FSV", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Preamp", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_RS_FSV_PowerOffset(
	Alv_GPIB_RS_FSV __instance,
	double dB,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: dB
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &dB;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.RS_FSV", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"PowerOffset", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_RS_FSV_InputAttenuation(
	Alv_GPIB_RS_FSV __instance,
	double dB,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: dB
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &dB;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.RS_FSV", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"InputAttenuation", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_RS_FSV_SweepTime(
	Alv_GPIB_RS_FSV __instance,
	int ms,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: ms
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &ms;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.RS_FSV", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"SweepTime", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_RS_FSV_CenterFrequency(
	Alv_GPIB_RS_FSV __instance,
	double MHz,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: MHz
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &MHz;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.RS_FSV", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"CenterFrequency", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_RS_FSV_FrequencySpan(
	Alv_GPIB_RS_FSV __instance,
	double MHz,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: MHz
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &MHz;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.RS_FSV", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"FrequencySpan", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_RS_FSV_Trace(
	Alv_GPIB_RS_FSV __instance,
	Alv_GPIB_RS_FSV_Traces t,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle t__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: t
	__errChk(Alv_GPIB_RS_FSV_Traces__Create(
		&t, 
		&t__, 
		__exception));
	__parameterTypeNames[0] = "Alv.GPIB.RS_FSV+Traces";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &t__;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.RS_FSV", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Trace", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (t__)
		CDotNetDiscardHandle(t__);
	return __error;
}

int CVIFUNC Alv_GPIB_RS_FSV_Detector(
	Alv_GPIB_RS_FSV __instance,
	Alv_GPIB_RS_FSV_Detectors detector,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle detector__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: detector
	__errChk(Alv_GPIB_RS_FSV_Detectors__Create(
		&detector, 
		&detector__, 
		__exception));
	__parameterTypeNames[0] = "Alv.GPIB.RS_FSV+Detectors";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &detector__;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.RS_FSV", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Detector", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (detector__)
		CDotNetDiscardHandle(detector__);
	return __error;
}

int CVIFUNC Alv_GPIB_RS_FSV_ReferenceLevel(
	Alv_GPIB_RS_FSV __instance,
	double dBm,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: dBm
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &dBm;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.RS_FSV", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ReferenceLevel", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_RS_FSV_ReadTrace(
	Alv_GPIB_RS_FSV __instance,
	int trace,
	double ** __returnValue,
	ssize_t * ____returnValueLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;
	if (__returnValue)
		*____returnValueLength = 0;


	// Pre-process parameter: trace
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &trace;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.RS_FSV", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ReadTrace", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_DOUBLE, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_DOUBLE, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC Alv_GPIB_RS_FSV_MarkerOff(
	Alv_GPIB_RS_FSV __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.RS_FSV", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"MarkerOff", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_RS_FSV_MarkerFrequency(
	Alv_GPIB_RS_FSV __instance,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.RS_FSV", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"MarkerFrequency", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_RS_FSV_MarkerPower(
	Alv_GPIB_RS_FSV __instance,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.RS_FSV", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"MarkerPower", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_RS_FSV_PeakSearch(
	Alv_GPIB_RS_FSV __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.RS_FSV", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"PeakSearch", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_RS_FSV_MarkerToCenter(
	Alv_GPIB_RS_FSV __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.RS_FSV", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"MarkerToCenter", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_RS_FSV_PowerSelect(
	Alv_GPIB_RS_FSV __instance,
	Alv_GPIB_RS_FSV_Measurments measurment,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle measurment__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: measurment
	__errChk(Alv_GPIB_RS_FSV_Measurments__Create(
		&measurment, 
		&measurment__, 
		__exception));
	__parameterTypeNames[0] = "Alv.GPIB.RS_FSV+Measurments";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &measurment__;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.RS_FSV", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"PowerSelect", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (measurment__)
		CDotNetDiscardHandle(measurment__);
	return __error;
}

int CVIFUNC Alv_GPIB_RS_FSV_PowerResult(
	Alv_GPIB_RS_FSV __instance,
	Alv_GPIB_RS_FSV_Measurments measurment,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle measurment__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: measurment
	__errChk(Alv_GPIB_RS_FSV_Measurments__Create(
		&measurment, 
		&measurment__, 
		__exception));
	__parameterTypeNames[0] = "Alv.GPIB.RS_FSV+Measurments";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &measurment__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.RS_FSV", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"PowerResult", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (measurment__)
		CDotNetDiscardHandle(measurment__);
	return __error;
}

int CVIFUNC Alv_GPIB_RS_FSV_PowerClear(
	Alv_GPIB_RS_FSV __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.RS_FSV", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"PowerClear", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_RS_FSV_ObwBandwidth(
	Alv_GPIB_RS_FSV __instance,
	int percentile,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: percentile
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &percentile;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.RS_FSV", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ObwBandwidth", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_RS_FSV_ResolutionBandwidth(
	Alv_GPIB_RS_FSV __instance,
	double MHz,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: MHz
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &MHz;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.RS_FSV", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ResolutionBandwidth", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_RS_FSV_VideoBandwidth(
	Alv_GPIB_RS_FSV __instance,
	double MHz,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: MHz
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &MHz;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.RS_FSV", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"VideoBandwidth", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_RS_FSV_Connect(
	Alv_GPIB_RS_FSV __instance,
	int GPIB,
	int Device_ID,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: GPIB
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &GPIB;

	// Pre-process parameter: Device_ID
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &Device_ID;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.RS_FSV", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Connect", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_RS_FSV_Close(
	Alv_GPIB_RS_FSV __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.RS_FSV", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Close", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_RS_FSV_ResetState(
	Alv_GPIB_RS_FSV __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.RS_FSV", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ResetState", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_RS_FSV_Calibrate(
	Alv_GPIB_RS_FSV __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.RS_FSV", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Calibrate", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_RS_FSV_Identification(
	Alv_GPIB_RS_FSV __instance,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.RS_FSV", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Identification", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC Alv_GPIB_RS_FSV_Ready(
	Alv_GPIB_RS_FSV __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.RS_FSV", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Ready", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_RS_FSV_Recall(
	Alv_GPIB_RS_FSV __instance,
	int state,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: state
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &state;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.RS_FSV", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Recall", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_RS_FSV_Save(
	Alv_GPIB_RS_FSV __instance,
	int state,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: state
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &state;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.RS_FSV", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Save", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_GPIB_RS_FSV_Wait(
	Alv_GPIB_RS_FSV __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.GPIB.RS_FSV", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Wait", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}


// Type: Alv.Test.Wave
int CVIFUNC Alv_Test_Wave__Create(
	Alv_Test_Wave * __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"Alv.Test.Wave", 
		0, 
		0, 
		__instance, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Wave__Create_1(
	Alv_Test_Wave * __instance,
	Alv_Test_Wave previous,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: previous
	__parameterTypeNames[0] = "Alv.Test.Wave";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &previous;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"Alv.Test.Wave", 
		0, 
		0, 
		__instance, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Wave__Create_2(
	Alv_Test_Wave * __instance,
	System_Collections_Generic_IEnumerable_T1 source,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: source
	__parameterTypeNames[0] = "System.Collections.Generic.IEnumerable`1[[System.Numerics.Complex, MathNet.Numerics, Version=2.5.0.27, Culture=neutral, PublicKeyToken=null]]";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &source;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"Alv.Test.Wave", 
		0, 
		0, 
		__instance, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Wave_Get_Length(
	Alv_Test_Wave __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Wave", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Length", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Wave_LoadBsdSweep(
	CDotNetHandle data,
	int antenna_pair,
	int rbin,
	Alv_Test_Wave * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: data
	__parameterTypeNames[0] = "System.Byte[][]";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &data;

	// Pre-process parameter: antenna_pair
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &antenna_pair;

	// Pre-process parameter: rbin
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &rbin;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.Test.Wave", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"LoadBsdSweep", 
		0, 
		0, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Alv_Test_Wave_LoadRctaSweep(
	CDotNetHandle data,
	int antenna_pair,
	int doppler,
	Alv_Test_Wave * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: data
	__parameterTypeNames[0] = "System.Byte[][]";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &data;

	// Pre-process parameter: antenna_pair
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &antenna_pair;

	// Pre-process parameter: doppler
	__parameterTypeNames[2] = "System.Boolean";
	__parameterTypes[2] = (CDOTNET_BOOLEAN);
	__parameters[2] = &doppler;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.Test.Wave", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"LoadRctaSweep", 
		0, 
		0, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Alv_Test_Wave_Load(
	double * re,
	ssize_t __reLength,
	double * im,
	ssize_t __imLength,
	Alv_Test_Wave * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	CDotNetHandle re__ = 0;
	CDotNetHandle im__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: re
	if (re)
		__errChk(CDotNetCreateArray(
			CDOTNET_DOUBLE, 
			1, 
			0, 
			&__reLength, 
			re, 
			&re__));
	__parameterTypeNames[0] = "System.Double[]";
	__parameterTypes[0] = (CDOTNET_DOUBLE | CDOTNET_ARRAY);
	__parameters[0] = &re__;

	// Pre-process parameter: im
	if (im)
		__errChk(CDotNetCreateArray(
			CDOTNET_DOUBLE, 
			1, 
			0, 
			&__imLength, 
			im, 
			&im__));
	__parameterTypeNames[1] = "System.Double[]";
	__parameterTypes[1] = (CDOTNET_DOUBLE | CDOTNET_ARRAY);
	__parameters[1] = &im__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.Test.Wave", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"Load", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (re__)
		CDotNetDiscardHandle(re__);
	if (im__)
		CDotNetDiscardHandle(im__);
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Alv_Test_Wave_Load_1(
	double * re,
	ssize_t __reLength,
	Alv_Test_Wave * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle re__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: re
	if (re)
		__errChk(CDotNetCreateArray(
			CDOTNET_DOUBLE, 
			1, 
			0, 
			&__reLength, 
			re, 
			&re__));
	__parameterTypeNames[0] = "System.Double[]";
	__parameterTypes[0] = (CDOTNET_DOUBLE | CDOTNET_ARRAY);
	__parameters[0] = &re__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.Test.Wave", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"Load", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (re__)
		CDotNetDiscardHandle(re__);
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Alv_Test_Wave_Load_2(
	System_Numerics_Complex * c,
	ssize_t __cLength,
	Alv_Test_Wave * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle c__ = 0;
	CDotNetAssemblyHandle __cAssembly = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: c
	if (c) {
		__errChk(CDotNetLoadAssembly(
			"MathNet.Numerics, Version=2.5.0.27, Culture=neutral, PublicKeyToken=null", 
			&__cAssembly));
		__errChk(CDotNetCreateTypedArray(
			__cAssembly, 
			"System.Numerics.Complex", 
			1, 
			0, 
			&__cLength, 
			c, 
			&c__));
	}
	__parameterTypeNames[0] = "System.Numerics.Complex[],MathNet.Numerics, Version=2.5.0.27, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[0] = (CDOTNET_STRUCT | CDOTNET_ARRAY);
	__parameters[0] = &c__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.Test.Wave", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"Load", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (c__)
		CDotNetDiscardHandle(c__);
	if (__cAssembly)
		CDotNetDiscardAssemblyHandle(__cAssembly);
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Alv_Test_Wave_op_Addition(
	Alv_Test_Wave left,
	Alv_Test_Wave right,
	Alv_Test_Wave * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: left
	__parameterTypeNames[0] = "Alv.Test.Wave";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &left;

	// Pre-process parameter: right
	__parameterTypeNames[1] = "Alv.Test.Wave";
	__parameterTypes[1] = (CDOTNET_OBJECT);
	__parameters[1] = &right;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.Test.Wave", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"op_Addition", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Alv_Test_Wave_op_Subtraction(
	Alv_Test_Wave left,
	Alv_Test_Wave right,
	Alv_Test_Wave * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: left
	__parameterTypeNames[0] = "Alv.Test.Wave";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &left;

	// Pre-process parameter: right
	__parameterTypeNames[1] = "Alv.Test.Wave";
	__parameterTypes[1] = (CDOTNET_OBJECT);
	__parameters[1] = &right;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.Test.Wave", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"op_Subtraction", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Alv_Test_Wave_op_UnaryNegation(
	Alv_Test_Wave left,
	Alv_Test_Wave * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: left
	__parameterTypeNames[0] = "Alv.Test.Wave";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &left;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.Test.Wave", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"op_UnaryNegation", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Alv_Test_Wave_op_Multiply(
	Alv_Test_Wave left,
	Alv_Test_Wave right,
	Alv_Test_Wave * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: left
	__parameterTypeNames[0] = "Alv.Test.Wave";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &left;

	// Pre-process parameter: right
	__parameterTypeNames[1] = "Alv.Test.Wave";
	__parameterTypes[1] = (CDOTNET_OBJECT);
	__parameters[1] = &right;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.Test.Wave", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"op_Multiply", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Alv_Test_Wave_op_Multiply_1(
	System_Numerics_Complex left,
	Alv_Test_Wave right,
	Alv_Test_Wave * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: left
	__parameterTypeNames[0] = "System.Numerics.Complex,MathNet.Numerics, Version=2.5.0.27, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[0] = (CDOTNET_STRUCT);
	__parameters[0] = &left;

	// Pre-process parameter: right
	__parameterTypeNames[1] = "Alv.Test.Wave";
	__parameterTypes[1] = (CDOTNET_OBJECT);
	__parameters[1] = &right;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.Test.Wave", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"op_Multiply", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Alv_Test_Wave_op_Multiply_2(
	Alv_Test_Wave left,
	System_Numerics_Complex right,
	Alv_Test_Wave * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: left
	__parameterTypeNames[0] = "Alv.Test.Wave";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &left;

	// Pre-process parameter: right
	__parameterTypeNames[1] = "System.Numerics.Complex,MathNet.Numerics, Version=2.5.0.27, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[1] = (CDOTNET_STRUCT);
	__parameters[1] = &right;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.Test.Wave", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"op_Multiply", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Alv_Test_Wave_op_Division(
	Alv_Test_Wave left,
	System_Numerics_Complex right,
	Alv_Test_Wave * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: left
	__parameterTypeNames[0] = "Alv.Test.Wave";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &left;

	// Pre-process parameter: right
	__parameterTypeNames[1] = "System.Numerics.Complex,MathNet.Numerics, Version=2.5.0.27, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[1] = (CDOTNET_STRUCT);
	__parameters[1] = &right;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.Test.Wave", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"op_Division", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Alv_Test_Wave_FFT(
	Alv_Test_Wave left,
	Alv_Test_Wave * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: left
	__parameterTypeNames[0] = "Alv.Test.Wave";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &left;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.Test.Wave", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"FFT", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Alv_Test_Wave_IFFT(
	Alv_Test_Wave left,
	Alv_Test_Wave * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: left
	__parameterTypeNames[0] = "Alv.Test.Wave";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &left;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.Test.Wave", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"IFFT", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Alv_Test_Wave_FIR(
	Alv_Test_Wave left,
	double * points,
	ssize_t __pointsLength,
	Alv_Test_Wave * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	CDotNetHandle points__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: left
	__parameterTypeNames[0] = "Alv.Test.Wave";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &left;

	// Pre-process parameter: points
	if (points)
		__errChk(CDotNetCreateArray(
			CDOTNET_DOUBLE, 
			1, 
			0, 
			&__pointsLength, 
			points, 
			&points__));
	__parameterTypeNames[1] = "System.Double[]";
	__parameterTypes[1] = (CDOTNET_DOUBLE | CDOTNET_ARRAY);
	__parameters[1] = &points__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.Test.Wave", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"FIR", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (points__)
		CDotNetDiscardHandle(points__);
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Alv_Test_Wave_MovingAvg(
	Alv_Test_Wave left,
	int points,
	Alv_Test_Wave * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: left
	__parameterTypeNames[0] = "Alv.Test.Wave";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &left;

	// Pre-process parameter: points
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &points;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.Test.Wave", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"MovingAvg", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Alv_Test_Wave_BiasAt(
	Alv_Test_Wave left,
	double bias,
	Alv_Test_Wave * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: left
	__parameterTypeNames[0] = "Alv.Test.Wave";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &left;

	// Pre-process parameter: bias
	__parameterTypeNames[1] = "System.Double";
	__parameterTypes[1] = (CDOTNET_DOUBLE);
	__parameters[1] = &bias;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.Test.Wave", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"BiasAt", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Alv_Test_Wave_Decimate(
	Alv_Test_Wave left,
	int every,
	int offset,
	Alv_Test_Wave * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: left
	__parameterTypeNames[0] = "Alv.Test.Wave";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &left;

	// Pre-process parameter: every
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &every;

	// Pre-process parameter: offset
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &offset;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.Test.Wave", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"Decimate", 
		0, 
		0, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Alv_Test_Wave_Trim(
	Alv_Test_Wave left,
	int length,
	Alv_Test_Wave * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: left
	__parameterTypeNames[0] = "Alv.Test.Wave";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &left;

	// Pre-process parameter: length
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &length;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.Test.Wave", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"Trim", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Alv_Test_Wave_QCorrect(
	Alv_Test_Wave left,
	double amplitude,
	double phase,
	Alv_Test_Wave * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: left
	__parameterTypeNames[0] = "Alv.Test.Wave";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &left;

	// Pre-process parameter: amplitude
	__parameterTypeNames[1] = "System.Double";
	__parameterTypes[1] = (CDOTNET_DOUBLE);
	__parameters[1] = &amplitude;

	// Pre-process parameter: phase
	__parameterTypeNames[2] = "System.Double";
	__parameterTypes[2] = (CDOTNET_DOUBLE);
	__parameters[2] = &phase;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.Test.Wave", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"QCorrect", 
		0, 
		0, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Alv_Test_Wave_BalanceCorrect(
	Alv_Test_Wave left,
	double amplitude,
	double phase,
	Alv_Test_Wave * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: left
	__parameterTypeNames[0] = "Alv.Test.Wave";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &left;

	// Pre-process parameter: amplitude
	__parameterTypeNames[1] = "System.Double";
	__parameterTypes[1] = (CDOTNET_DOUBLE);
	__parameters[1] = &amplitude;

	// Pre-process parameter: phase
	__parameterTypeNames[2] = "System.Double";
	__parameterTypes[2] = (CDOTNET_DOUBLE);
	__parameters[2] = &phase;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.Test.Wave", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"BalanceCorrect", 
		0, 
		0, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Alv_Test_Wave_Concat(
	Alv_Test_Wave left,
	Alv_Test_Wave right,
	Alv_Test_Wave * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: left
	__parameterTypeNames[0] = "Alv.Test.Wave";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &left;

	// Pre-process parameter: right
	__parameterTypeNames[1] = "Alv.Test.Wave";
	__parameterTypes[1] = (CDOTNET_OBJECT);
	__parameters[1] = &right;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.Test.Wave", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"Concat", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Alv_Test_Wave_KBDWindow(
	int size,
	double alpha,
	Alv_Test_Wave * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: size
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &size;

	// Pre-process parameter: alpha
	__parameterTypeNames[1] = "System.Double";
	__parameterTypes[1] = (CDOTNET_DOUBLE);
	__parameters[1] = &alpha;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.Test.Wave", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"KBDWindow", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Alv_Test_Wave_Bessel(
	double x,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: x
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &x;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.Test.Wave", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"Bessel", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Wave_dB(
	double value,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: value
	__parameterTypeNames[0] = "System.Double";
	__parameterTypes[0] = (CDOTNET_DOUBLE);
	__parameters[0] = &value;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.Test.Wave", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"dB", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Wave_dB_1(
	System_Numerics_Complex value,
	System_Numerics_Complex * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: value
	__parameterTypeNames[0] = "System.Numerics.Complex,MathNet.Numerics, Version=2.5.0.27, Culture=neutral, PublicKeyToken=null";
	__parameterTypes[0] = (CDOTNET_STRUCT);
	__parameters[0] = &value;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRUCT;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.Test.Wave", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"dB", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRUCT);
	}
	return __error;
}

int CVIFUNC Alv_Test_Wave_GetEnumerator(
	Alv_Test_Wave __instance,
	System_Collections_Generic_IEnumerator_T1 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Wave", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GetEnumerator", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Alv_Test_Wave_Phase(
	Alv_Test_Wave __instance,
	System_Collections_Generic_IEnumerable_T1 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Wave", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Phase", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Alv_Test_Wave_Re(
	Alv_Test_Wave __instance,
	System_Collections_Generic_IEnumerable_T1 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Wave", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Re", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Alv_Test_Wave_Im(
	Alv_Test_Wave __instance,
	System_Collections_Generic_IEnumerable_T1 * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Wave", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Im", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Alv_Test_Wave_SNR(
	Alv_Test_Wave __instance,
	int pad,
	int percentile,
	double * window,
	ssize_t __windowLength,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];
	CDotNetHandle window__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: pad
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &pad;

	// Pre-process parameter: percentile
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &percentile;

	// Pre-process parameter: window
	if (window)
		__errChk(CDotNetCreateArray(
			CDOTNET_DOUBLE, 
			1, 
			0, 
			&__windowLength, 
			window, 
			&window__));
	__parameterTypeNames[2] = "System.Double[]";
	__parameterTypes[2] = (CDOTNET_DOUBLE | CDOTNET_ARRAY);
	__parameters[2] = &window__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Wave", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"SNR", 
		0, 
		0, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (window__)
		CDotNetDiscardHandle(window__);
	return __error;
}

int CVIFUNC Alv_Test_Wave_SNR_1(
	Alv_Test_Wave __instance,
	int pad,
	int percentile,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: pad
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &pad;

	// Pre-process parameter: percentile
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &percentile;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Wave", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"SNR", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Wave_SNR_2(
	Alv_Test_Wave __instance,
	double * window,
	ssize_t __windowLength,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle window__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: window
	if (window)
		__errChk(CDotNetCreateArray(
			CDOTNET_DOUBLE, 
			1, 
			0, 
			&__windowLength, 
			window, 
			&window__));
	__parameterTypeNames[0] = "System.Double[]";
	__parameterTypes[0] = (CDOTNET_DOUBLE | CDOTNET_ARRAY);
	__parameters[0] = &window__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Wave", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"SNR", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (window__)
		CDotNetDiscardHandle(window__);
	return __error;
}

int CVIFUNC Alv_Test_Wave_Signel(
	Alv_Test_Wave __instance,
	int pad,
	double * window,
	ssize_t __windowLength,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	CDotNetHandle window__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: pad
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &pad;

	// Pre-process parameter: window
	if (window)
		__errChk(CDotNetCreateArray(
			CDOTNET_DOUBLE, 
			1, 
			0, 
			&__windowLength, 
			window, 
			&window__));
	__parameterTypeNames[1] = "System.Double[]";
	__parameterTypes[1] = (CDOTNET_DOUBLE | CDOTNET_ARRAY);
	__parameters[1] = &window__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Wave", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Signel", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (window__)
		CDotNetDiscardHandle(window__);
	return __error;
}

int CVIFUNC Alv_Test_Wave_Signel_1(
	Alv_Test_Wave __instance,
	int pad,
	double alpha,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: pad
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &pad;

	// Pre-process parameter: alpha
	__parameterTypeNames[1] = "System.Double";
	__parameterTypes[1] = (CDOTNET_DOUBLE);
	__parameters[1] = &alpha;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Wave", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Signel", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Wave_Noise(
	Alv_Test_Wave __instance,
	int percentile,
	double * window,
	ssize_t __windowLength,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	CDotNetHandle window__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: percentile
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &percentile;

	// Pre-process parameter: window
	if (window)
		__errChk(CDotNetCreateArray(
			CDOTNET_DOUBLE, 
			1, 
			0, 
			&__windowLength, 
			window, 
			&window__));
	__parameterTypeNames[1] = "System.Double[]";
	__parameterTypes[1] = (CDOTNET_DOUBLE | CDOTNET_ARRAY);
	__parameters[1] = &window__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Wave", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Noise", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (window__)
		CDotNetDiscardHandle(window__);
	return __error;
}

int CVIFUNC Alv_Test_Wave_Noise_1(
	Alv_Test_Wave __instance,
	int percentile,
	double alpha,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: percentile
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &percentile;

	// Pre-process parameter: alpha
	__parameterTypeNames[1] = "System.Double";
	__parameterTypes[1] = (CDOTNET_DOUBLE);
	__parameters[1] = &alpha;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Wave", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Noise", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Wave_Percentile(
	Alv_Test_Wave __instance,
	int percent,
	System_Numerics_Complex * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: percent
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &percent;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRUCT;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Wave", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Percentile", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRUCT);
	}
	return __error;
}

int CVIFUNC Alv_Test_Wave_PhaseDelta(
	Alv_Test_Wave __instance,
	int start,
	int stop,
	double * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: start
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &start;

	// Pre-process parameter: stop
	__parameterTypeNames[1] = "System.Int32";
	__parameterTypes[1] = (CDOTNET_INT32);
	__parameters[1] = &stop;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_DOUBLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Wave", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"PhaseDelta", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_Test_Wave_Mean(
	Alv_Test_Wave __instance,
	System_Numerics_Complex * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRUCT;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Wave", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Mean", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRUCT);
	}
	return __error;
}

int CVIFUNC Alv_Test_Wave_Std(
	Alv_Test_Wave __instance,
	System_Numerics_Complex * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRUCT;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Wave", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Std", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRUCT);
	}
	return __error;
}

int CVIFUNC Alv_Test_Wave_Rms(
	Alv_Test_Wave __instance,
	System_Numerics_Complex * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRUCT;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Wave", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Rms", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRUCT);
	}
	return __error;
}

int CVIFUNC Alv_Test_Wave_WriteWave(
	Alv_Test_Wave __instance,
	char * deliminator,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: deliminator
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &deliminator;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Wave", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"WriteWave", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC Alv_Test_Wave_WriteWave_1(
	Alv_Test_Wave __instance,
	char * value_deliminator,
	char * line_deliminator,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: value_deliminator
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &value_deliminator;

	// Pre-process parameter: line_deliminator
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &line_deliminator;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.Test.Wave", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"WriteWave", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}


// Type: Alv.MfgTest
int CVIFUNC Alv_MfgTest_Get_Version(
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.MfgTest", 
		0, 
		0, 
		CDOTNET_GET_PROPERTY, 
		"Version", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}


int CVIFUNC Ivi_Visa_Interop_FormattedIO488_get_IO(
	Ivi_Visa_Interop_FormattedIO488 __instance,
	Ivi_Visa_Interop_IMessage * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Ivi.Visa.Interop.FormattedIO488", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"get_IO", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Ivi_Visa_Interop_FormattedIO488_set_IO(
	Ivi_Visa_Interop_FormattedIO488 __instance,
	Ivi_Visa_Interop_IMessage pVal,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: pVal
	__parameterTypeNames[0] = "Ivi.Visa.Interop.IMessage";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &pVal;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Ivi.Visa.Interop.FormattedIO488", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"set_IO", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Ivi_Visa_Interop_FormattedIO488_WriteString(
	Ivi_Visa_Interop_FormattedIO488 __instance,
	char * data,
	int flushAndEND,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: data
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &data;

	// Pre-process parameter: flushAndEND
	__parameterTypeNames[1] = "System.Boolean";
	__parameterTypes[1] = (CDOTNET_BOOLEAN);
	__parameters[1] = &flushAndEND;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Ivi.Visa.Interop.FormattedIO488", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"WriteString", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Ivi_Visa_Interop_FormattedIO488_ReadString(
	Ivi_Visa_Interop_FormattedIO488 __instance,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Ivi.Visa.Interop.FormattedIO488", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ReadString", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC Ivi_Visa_Interop_FormattedIO488_ReadNumber(
	Ivi_Visa_Interop_FormattedIO488 __instance,
	Ivi_Visa_Interop_IEEEASCIIType type,
	int flushToEND,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	CDotNetHandle type__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: type
	__errChk(Ivi_Visa_Interop_IEEEASCIIType__Create(
		&type, 
		&type__, 
		__exception));
	__parameterTypeNames[0] = "Ivi.Visa.Interop.IEEEASCIIType";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &type__;

	// Pre-process parameter: flushToEND
	__parameterTypeNames[1] = "System.Boolean";
	__parameterTypes[1] = (CDOTNET_BOOLEAN);
	__parameters[1] = &flushToEND;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Ivi.Visa.Interop.FormattedIO488", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ReadNumber", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (type__)
		CDotNetDiscardHandle(type__);
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Ivi_Visa_Interop_FormattedIO488_ReadList(
	Ivi_Visa_Interop_FormattedIO488 __instance,
	Ivi_Visa_Interop_IEEEASCIIType type,
	char * listSeperator,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	CDotNetHandle type__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: type
	__errChk(Ivi_Visa_Interop_IEEEASCIIType__Create(
		&type, 
		&type__, 
		__exception));
	__parameterTypeNames[0] = "Ivi.Visa.Interop.IEEEASCIIType";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &type__;

	// Pre-process parameter: listSeperator
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &listSeperator;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Ivi.Visa.Interop.FormattedIO488", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ReadList", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (type__)
		CDotNetDiscardHandle(type__);
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}


// Type: Ivi.Visa.Interop.IFormattedIO488
int CVIFUNC Ivi_Visa_Interop_IFormattedIO488_Get_IO(
	Ivi_Visa_Interop_IFormattedIO488 __instance,
	Ivi_Visa_Interop_IMessage * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Ivi.Visa.Interop.IFormattedIO488", 
		0, 
		0, 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"IO", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Ivi_Visa_Interop_IFormattedIO488_Set_IO(
	Ivi_Visa_Interop_IFormattedIO488 __instance,
	Ivi_Visa_Interop_IMessage pVal,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: pVal
	__parameterTypeNames[0] = "Ivi.Visa.Interop.IMessage";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &pVal;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Ivi.Visa.Interop.IFormattedIO488", 
		0, 
		0, 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"IO", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Ivi_Visa_Interop_IFormattedIO488_WriteString(
	Ivi_Visa_Interop_IFormattedIO488 __instance,
	char * data,
	int flushAndEND,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: data
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &data;

	// Pre-process parameter: flushAndEND
	__parameterTypeNames[1] = "System.Boolean";
	__parameterTypes[1] = (CDOTNET_BOOLEAN);
	__parameters[1] = &flushAndEND;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Ivi.Visa.Interop.IFormattedIO488", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"WriteString", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Ivi_Visa_Interop_IFormattedIO488_ReadString(
	Ivi_Visa_Interop_IFormattedIO488 __instance,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Ivi.Visa.Interop.IFormattedIO488", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ReadString", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC Ivi_Visa_Interop_IFormattedIO488_ReadNumber(
	Ivi_Visa_Interop_IFormattedIO488 __instance,
	Ivi_Visa_Interop_IEEEASCIIType type,
	int flushToEND,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	CDotNetHandle type__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: type
	__errChk(Ivi_Visa_Interop_IEEEASCIIType__Create(
		&type, 
		&type__, 
		__exception));
	__parameterTypeNames[0] = "Ivi.Visa.Interop.IEEEASCIIType";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &type__;

	// Pre-process parameter: flushToEND
	__parameterTypeNames[1] = "System.Boolean";
	__parameterTypes[1] = (CDOTNET_BOOLEAN);
	__parameters[1] = &flushToEND;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Ivi.Visa.Interop.IFormattedIO488", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ReadNumber", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (type__)
		CDotNetDiscardHandle(type__);
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Ivi_Visa_Interop_IFormattedIO488_ReadList(
	Ivi_Visa_Interop_IFormattedIO488 __instance,
	Ivi_Visa_Interop_IEEEASCIIType type,
	char * listSeperator,
	CDotNetHandle * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	CDotNetHandle type__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: type
	__errChk(Ivi_Visa_Interop_IEEEASCIIType__Create(
		&type, 
		&type__, 
		__exception));
	__parameterTypeNames[0] = "Ivi.Visa.Interop.IEEEASCIIType";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &type__;

	// Pre-process parameter: listSeperator
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &listSeperator;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Ivi.Visa.Interop.IFormattedIO488", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ReadList", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (type__)
		CDotNetDiscardHandle(type__);
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}


// Type: Ivi.Visa.Interop.IMessage
int CVIFUNC Ivi_Visa_Interop_IMessage_Get_ResourceName(
	Ivi_Visa_Interop_IMessage __instance,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Ivi.Visa.Interop.IMessage", 
		0, 
		0, 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"ResourceName", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC Ivi_Visa_Interop_IMessage_Get_Timeout(
	Ivi_Visa_Interop_IMessage __instance,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_INT32;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Ivi.Visa.Interop.IMessage", 
		0, 
		0, 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Timeout", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Ivi_Visa_Interop_IMessage_Set_Timeout(
	Ivi_Visa_Interop_IMessage __instance,
	int pVal,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: pVal
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &pVal;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Ivi.Visa.Interop.IMessage", 
		0, 
		0, 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"Timeout", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Ivi_Visa_Interop_IMessage_Close(
	Ivi_Visa_Interop_IMessage __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Ivi.Visa.Interop.IMessage", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Close", 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		0, 
		__exception));


__Error:
	return __error;
}


int CVIFUNC Ivi_Visa_Interop_ResourceManager_Open(
	Ivi_Visa_Interop_ResourceManager __instance,
	char * ResourceName,
	Ivi_Visa_Interop_AccessMode mode,
	int openTimeout,
	char * OptionString,
	Ivi_Visa_Interop_IVisaSession * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];
	CDotNetHandle mode__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: ResourceName
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &ResourceName;

	// Pre-process parameter: mode
	__errChk(Ivi_Visa_Interop_AccessMode__Create(
		&mode, 
		&mode__, 
		__exception));
	__parameterTypeNames[1] = "Ivi.Visa.Interop.AccessMode";
	__parameterTypes[1] = (CDOTNET_ENUM);
	__parameters[1] = &mode__;

	// Pre-process parameter: openTimeout
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &openTimeout;

	// Pre-process parameter: OptionString
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &OptionString;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Ivi.Visa.Interop.ResourceManager", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Open", 
		0, 
		0, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (mode__)
		CDotNetDiscardHandle(mode__);
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}


int CVIFUNC Ivi_Visa_Interop_IResourceManager3_Open(
	Ivi_Visa_Interop_IResourceManager3 __instance,
	char * ResourceName,
	Ivi_Visa_Interop_AccessMode mode,
	int openTimeout,
	char * OptionString,
	Ivi_Visa_Interop_IVisaSession * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];
	CDotNetHandle mode__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: ResourceName
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &ResourceName;

	// Pre-process parameter: mode
	__errChk(Ivi_Visa_Interop_AccessMode__Create(
		&mode, 
		&mode__, 
		__exception));
	__parameterTypeNames[1] = "Ivi.Visa.Interop.AccessMode";
	__parameterTypes[1] = (CDOTNET_ENUM);
	__parameters[1] = &mode__;

	// Pre-process parameter: openTimeout
	__parameterTypeNames[2] = "System.Int32";
	__parameterTypes[2] = (CDOTNET_INT32);
	__parameters[2] = &openTimeout;

	// Pre-process parameter: OptionString
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &OptionString;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Ivi.Visa.Interop.IResourceManager3", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Open", 
		0, 
		0, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	if (mode__)
		CDotNetDiscardHandle(mode__);
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_OBJECT);
	}
	return __error;
}






// Internal functions
static int CVIFUNC Alv_NarrowBand_NBProtocol_Antenna__Create(
	Alv_NarrowBand_NBProtocol_Antenna * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int enumType = CDOTNET_INT32;
	CDotNetAssemblyHandle assembly = 0;

	if (__exception)
		*__exception = 0;

	*handle = 0;

	__errChk(CDotNetLoadAssembly(
		"NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null", 
		&assembly));

	__errChk(CDotNetCreateInstance(
		assembly, 
		"Alv.NarrowBand.NBProtocol+Antenna", 
		handle, 
		1, 
		&enumType, 
		(void **)&value, 
		__exception));


__Error:
	if (assembly)
		CDotNetDiscardAssemblyHandle(assembly);
	return __error;
}

static int CVIFUNC Alv_NarrowBand_NBProtocol_ControlRadarMode__Create(
	Alv_NarrowBand_NBProtocol_ControlRadarMode * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int enumType = CDOTNET_INT32;
	CDotNetAssemblyHandle assembly = 0;

	if (__exception)
		*__exception = 0;

	*handle = 0;

	__errChk(CDotNetLoadAssembly(
		"NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null", 
		&assembly));

	__errChk(CDotNetCreateInstance(
		assembly, 
		"Alv.NarrowBand.NBProtocol+ControlRadarMode", 
		handle, 
		1, 
		&enumType, 
		(void **)&value, 
		__exception));


__Error:
	if (assembly)
		CDotNetDiscardAssemblyHandle(assembly);
	return __error;
}

static int CVIFUNC Alv_NarrowBand_NBProtocol_StaticTestMode__Create(
	Alv_NarrowBand_NBProtocol_StaticTestMode * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int enumType = CDOTNET_INT32;
	CDotNetAssemblyHandle assembly = 0;

	if (__exception)
		*__exception = 0;

	*handle = 0;

	__errChk(CDotNetLoadAssembly(
		"NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null", 
		&assembly));

	__errChk(CDotNetCreateInstance(
		assembly, 
		"Alv.NarrowBand.NBProtocol+StaticTestMode", 
		handle, 
		1, 
		&enumType, 
		(void **)&value, 
		__exception));


__Error:
	if (assembly)
		CDotNetDiscardAssemblyHandle(assembly);
	return __error;
}

static int CVIFUNC Alv_NarrowBand_NBProtocol_DCOffset__Create(
	Alv_NarrowBand_NBProtocol_DCOffset * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int enumType = CDOTNET_INT32;
	CDotNetAssemblyHandle assembly = 0;

	if (__exception)
		*__exception = 0;

	*handle = 0;

	__errChk(CDotNetLoadAssembly(
		"NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null", 
		&assembly));

	__errChk(CDotNetCreateInstance(
		assembly, 
		"Alv.NarrowBand.NBProtocol+DCOffset", 
		handle, 
		1, 
		&enumType, 
		(void **)&value, 
		__exception));


__Error:
	if (assembly)
		CDotNetDiscardAssemblyHandle(assembly);
	return __error;
}

static int CVIFUNC Alv_NarrowBand_NBProtocol_ConfigurationBlock__Create(
	Alv_NarrowBand_NBProtocol_ConfigurationBlock * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int enumType = CDOTNET_INT32;
	CDotNetAssemblyHandle assembly = 0;

	if (__exception)
		*__exception = 0;

	*handle = 0;

	__errChk(CDotNetLoadAssembly(
		"NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null", 
		&assembly));

	__errChk(CDotNetCreateInstance(
		assembly, 
		"Alv.NarrowBand.NBProtocol+ConfigurationBlock", 
		handle, 
		1, 
		&enumType, 
		(void **)&value, 
		__exception));


__Error:
	if (assembly)
		CDotNetDiscardAssemblyHandle(assembly);
	return __error;
}

static int CVIFUNC Alv_NarrowBand_NBProtocol_Processor__Create(
	Alv_NarrowBand_NBProtocol_Processor * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int enumType = CDOTNET_INT32;
	CDotNetAssemblyHandle assembly = 0;

	if (__exception)
		*__exception = 0;

	*handle = 0;

	__errChk(CDotNetLoadAssembly(
		"NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null", 
		&assembly));

	__errChk(CDotNetCreateInstance(
		assembly, 
		"Alv.NarrowBand.NBProtocol+Processor", 
		handle, 
		1, 
		&enumType, 
		(void **)&value, 
		__exception));


__Error:
	if (assembly)
		CDotNetDiscardAssemblyHandle(assembly);
	return __error;
}

static int CVIFUNC Alv_NarrowBand_NBProtocol_TestLED__Create(
	Alv_NarrowBand_NBProtocol_TestLED * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int enumType = CDOTNET_INT32;
	CDotNetAssemblyHandle assembly = 0;

	if (__exception)
		*__exception = 0;

	*handle = 0;

	__errChk(CDotNetLoadAssembly(
		"NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null", 
		&assembly));

	__errChk(CDotNetCreateInstance(
		assembly, 
		"Alv.NarrowBand.NBProtocol+TestLED", 
		handle, 
		1, 
		&enumType, 
		(void **)&value, 
		__exception));


__Error:
	if (assembly)
		CDotNetDiscardAssemblyHandle(assembly);
	return __error;
}

static int CVIFUNC Alv_NarrowBand_NBProtocol_GearPosition__Create(
	Alv_NarrowBand_NBProtocol_GearPosition * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int enumType = CDOTNET_INT32;
	CDotNetAssemblyHandle assembly = 0;

	if (__exception)
		*__exception = 0;

	*handle = 0;

	__errChk(CDotNetLoadAssembly(
		"NbLib, Version=1.2.0.1, Culture=neutral, PublicKeyToken=null", 
		&assembly));

	__errChk(CDotNetCreateInstance(
		assembly, 
		"Alv.NarrowBand.NBProtocol+GearPosition", 
		handle, 
		1, 
		&enumType, 
		(void **)&value, 
		__exception));


__Error:
	if (assembly)
		CDotNetDiscardAssemblyHandle(assembly);
	return __error;
}

static int CVIFUNC Alv_GPIB_N9010A_Traces__Create(
	Alv_GPIB_N9010A_Traces * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int enumType = CDOTNET_INT32;
	CDotNetAssemblyHandle assembly = 0;

	if (__exception)
		*__exception = 0;

	*handle = 0;

	__errChk(CDotNetLoadAssembly(
		__assemblyName, 
		&assembly));

	__errChk(CDotNetCreateInstance(
		assembly, 
		"Alv.GPIB.N9010A+Traces", 
		handle, 
		1, 
		&enumType, 
		(void **)&value, 
		__exception));


__Error:
	if (assembly)
		CDotNetDiscardAssemblyHandle(assembly);
	return __error;
}

static int CVIFUNC Alv_GPIB_N9010A_Measurments__Create(
	Alv_GPIB_N9010A_Measurments * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int enumType = CDOTNET_INT32;
	CDotNetAssemblyHandle assembly = 0;

	if (__exception)
		*__exception = 0;

	*handle = 0;

	__errChk(CDotNetLoadAssembly(
		__assemblyName, 
		&assembly));

	__errChk(CDotNetCreateInstance(
		assembly, 
		"Alv.GPIB.N9010A+Measurments", 
		handle, 
		1, 
		&enumType, 
		(void **)&value, 
		__exception));


__Error:
	if (assembly)
		CDotNetDiscardAssemblyHandle(assembly);
	return __error;
}

static int CVIFUNC Alv_GPIB_N9010A_Markers__Create(
	Alv_GPIB_N9010A_Markers * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int enumType = CDOTNET_INT32;
	CDotNetAssemblyHandle assembly = 0;

	if (__exception)
		*__exception = 0;

	*handle = 0;

	__errChk(CDotNetLoadAssembly(
		__assemblyName, 
		&assembly));

	__errChk(CDotNetCreateInstance(
		assembly, 
		"Alv.GPIB.N9010A+Markers", 
		handle, 
		1, 
		&enumType, 
		(void **)&value, 
		__exception));


__Error:
	if (assembly)
		CDotNetDiscardAssemblyHandle(assembly);
	return __error;
}

static int CVIFUNC Alv_GPIB_RS_FSV_Traces__Create(
	Alv_GPIB_RS_FSV_Traces * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int enumType = CDOTNET_INT32;
	CDotNetAssemblyHandle assembly = 0;

	if (__exception)
		*__exception = 0;

	*handle = 0;

	__errChk(CDotNetLoadAssembly(
		__assemblyName, 
		&assembly));

	__errChk(CDotNetCreateInstance(
		assembly, 
		"Alv.GPIB.RS_FSV+Traces", 
		handle, 
		1, 
		&enumType, 
		(void **)&value, 
		__exception));


__Error:
	if (assembly)
		CDotNetDiscardAssemblyHandle(assembly);
	return __error;
}

static int CVIFUNC Alv_GPIB_RS_FSV_Detectors__Create(
	Alv_GPIB_RS_FSV_Detectors * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int enumType = CDOTNET_INT32;
	CDotNetAssemblyHandle assembly = 0;

	if (__exception)
		*__exception = 0;

	*handle = 0;

	__errChk(CDotNetLoadAssembly(
		__assemblyName, 
		&assembly));

	__errChk(CDotNetCreateInstance(
		assembly, 
		"Alv.GPIB.RS_FSV+Detectors", 
		handle, 
		1, 
		&enumType, 
		(void **)&value, 
		__exception));


__Error:
	if (assembly)
		CDotNetDiscardAssemblyHandle(assembly);
	return __error;
}

static int CVIFUNC Alv_GPIB_RS_FSV_Measurments__Create(
	Alv_GPIB_RS_FSV_Measurments * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int enumType = CDOTNET_INT32;
	CDotNetAssemblyHandle assembly = 0;

	if (__exception)
		*__exception = 0;

	*handle = 0;

	__errChk(CDotNetLoadAssembly(
		__assemblyName, 
		&assembly));

	__errChk(CDotNetCreateInstance(
		assembly, 
		"Alv.GPIB.RS_FSV+Measurments", 
		handle, 
		1, 
		&enumType, 
		(void **)&value, 
		__exception));


__Error:
	if (assembly)
		CDotNetDiscardAssemblyHandle(assembly);
	return __error;
}

static int CVIFUNC Ivi_Visa_Interop_IEEEASCIIType__Create(
	Ivi_Visa_Interop_IEEEASCIIType * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int enumType = CDOTNET_INT32;
	CDotNetAssemblyHandle assembly = 0;

	if (__exception)
		*__exception = 0;

	*handle = 0;

	__errChk(CDotNetLoadAssembly(
		__assemblyName, 
		&assembly));

	__errChk(CDotNetCreateInstance(
		assembly, 
		"Ivi.Visa.Interop.IEEEASCIIType", 
		handle, 
		1, 
		&enumType, 
		(void **)&value, 
		__exception));


__Error:
	if (assembly)
		CDotNetDiscardAssemblyHandle(assembly);
	return __error;
}

static int CVIFUNC Ivi_Visa_Interop_AccessMode__Create(
	Ivi_Visa_Interop_AccessMode * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int enumType = CDOTNET_INT32;
	CDotNetAssemblyHandle assembly = 0;

	if (__exception)
		*__exception = 0;

	*handle = 0;

	__errChk(CDotNetLoadAssembly(
		__assemblyName, 
		&assembly));

	__errChk(CDotNetCreateInstance(
		assembly, 
		"Ivi.Visa.Interop.AccessMode", 
		handle, 
		1, 
		&enumType, 
		(void **)&value, 
		__exception));


__Error:
	if (assembly)
		CDotNetDiscardAssemblyHandle(assembly);
	return __error;
}

static void _CDotNetGenDisposeScalar(void * scalar, unsigned int typeId)
{
	if (!*(void **)scalar)
		return;

	typeId &= CDOTNET_BASIC_TYPE_MASK;
	if (typeId == CDOTNET_STRING) {
		CDotNetFreeMemory(*(char **)scalar);
		*(char **)scalar = 0;
	}
	else if (typeId == CDOTNET_OBJECT || typeId == CDOTNET_STRUCT) {
		CDotNetDiscardHandle(*(CDotNetHandle *)scalar);
		*(CDotNetHandle *)scalar = 0;
	}
}

static void CVIFUNC_C _CDotNetGenDisposeArray(void * array, unsigned int typeId, size_t nDims, ...)
{
	size_t i;
	ssize_t totalLength = 1;
	va_list list;

	if (!*(void **)array)
		return;

	va_start(list, nDims);
	for (i = 0; i < nDims; ++i) {
		ssize_t * lenPtr = va_arg(list, ssize_t*);

		totalLength *= *lenPtr;
		*lenPtr = 0;
	}
	va_end(list);

	typeId &= CDOTNET_BASIC_TYPE_MASK;
	if (typeId == CDOTNET_STRING)
		while (--totalLength >= 0)
			CDotNetFreeMemory((*(char ***)array)[totalLength]);
	else if (typeId > CDOTNET_ENUM)
		while (--totalLength >= 0)
			CDotNetDiscardHandle((*(CDotNetHandle **)array)[totalLength]);

	CDotNetFreeMemory(*(void**)array);
	*(void**)array = 0;
}

