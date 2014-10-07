// CVI wrapper source file for .NET assembly: NbLib, Version=0.0.0.0, Culture=neutral, PublicKeyToken=null

#include "nblib.h"
#include <stdarg.h>

// Macros
#ifndef __errChk
#define __errChk(f) if (__error = (f), __error < 0) goto __Error; else
#endif
#ifndef __nullChk
#define __nullChk(p) if (!(p)) { __error = CDotNetOutOfMemoryError; goto __Error; } else
#endif

// Constants
static const char * __assemblyName = "NbLib, Version=0.0.0.0, Culture=neutral, PublicKeyToken=null";

// Static Variables
static CDotNetAssemblyHandle __assemblyHandle = 0;

// Forward declarations
static int CVIFUNC Alv_NarrowBand_NBProtocol_Status__Create(
	Alv_NarrowBand_NBProtocol_Status * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception);
static int CVIFUNC Alv_CAN_CanBusModes__Create(
	Alv_CAN_CanBusModes * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception);
static int CVIFUNC Alv_CAN_CanWakeupModes__Create(
	Alv_CAN_CanWakeupModes * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception);
static int CVIFUNC Alv_NarrowBand_NBProtocol_Position__Create(
	Alv_NarrowBand_NBProtocol_Position * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception);
static int CVIFUNC Alv_NarrowBand_NBProtocol_ConfigurationBlock__Create(
	Alv_NarrowBand_NBProtocol_ConfigurationBlock * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception);
static int CVIFUNC Alv_NarrowBand_NBProtocol_Antenna__Create(
	Alv_NarrowBand_NBProtocol_Antenna * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception);
static int CVIFUNC Alv_NarrowBand_NBProtocol_DCOffset__Create(
	Alv_NarrowBand_NBProtocol_DCOffset * value,
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
static int CVIFUNC Alv_NarrowBand_NBProtocol_StaticTestMode__Create(
	Alv_NarrowBand_NBProtocol_StaticTestMode * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception);
static int CVIFUNC Alv_NarrowBand_NBProtocol_ControlRadarMode__Create(
	Alv_NarrowBand_NBProtocol_ControlRadarMode * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception);
static int CVIFUNC Alv_NarrowBand_NBProtocol_ControlError__Create(
	Alv_NarrowBand_NBProtocol_ControlError * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception);
static int CVIFUNC Alv_NarrowBand_NBProtocol_LoggerID__Create(
	Alv_NarrowBand_NBProtocol_LoggerID * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception);
static int CVIFUNC Alv_NarrowBand_NBProtocol_ControlLogger__Create(
	Alv_NarrowBand_NBProtocol_ControlLogger * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception);
static int CVIFUNC Alv_NarrowBand_NBProtocol_GearPosition__Create(
	Alv_NarrowBand_NBProtocol_GearPosition * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception);
static int CVIFUNC Alv_NarrowBand_NBProtocol_ExecuteFunctions__Create(
	Alv_NarrowBand_NBProtocol_ExecuteFunctions * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception);
static int CVIFUNC Alv_NarrowBand_PointTypes__Create(
	Alv_NarrowBand_PointTypes * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception);
static int CVIFUNC Alv_NarrowBand_PointFormats__Create(
	Alv_NarrowBand_PointFormats * value,
	CDotNetHandle * handle,
	CDotNetHandle * __exception);
static void _CDotNetGenDisposeScalar(void * scalar, unsigned int typeId);
static void CVIFUNC_C _CDotNetGenDisposeArray(void * array, unsigned int typeId, size_t nDims, ...);

// Global Functions
int CVIFUNC Initialize_NbLib(void)
{
	int __error = 0;


	if (__assemblyHandle == 0)
		__errChk(CDotNetLoadAssembly(
			__assemblyName, 
			&__assemblyHandle));



__Error:
	return __error;
}

int CVIFUNC Close_NbLib(void)
{
	int __error = 0;


	if (__assemblyHandle) {
		__errChk(CDotNetDiscardAssemblyHandle(__assemblyHandle));
		__assemblyHandle = 0;
	}



__Error:
	return __error;
}


// Type: Alv.NarrowBand.Message
int CVIFUNC Alv_NarrowBand_Message__Create(
	Alv_NarrowBand_Message * __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"Alv.NarrowBand.Message", 
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


// Type: Alv.NarrowBand.DataPoints
int CVIFUNC Alv_NarrowBand_DataPoints__Create(
	Alv_NarrowBand_DataPoints * __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"Alv.NarrowBand.DataPoints", 
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

int CVIFUNC Alv_NarrowBand_DataPoints_Get_Version(
	Alv_NarrowBand_DataPoints __instance,
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
		"Alv.NarrowBand.DataPoints", 
		__instance, 
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

int CVIFUNC Alv_NarrowBand_DataPoints_Get_Points(
	Alv_NarrowBand_DataPoints __instance,
	System_Collections_Generic_List_T1 * __returnValue,
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
		"Alv.NarrowBand.DataPoints", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Points", 
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

int CVIFUNC Alv_NarrowBand_DataPoints_Get_Count(
	Alv_NarrowBand_DataPoints __instance,
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
		"Alv.NarrowBand.DataPoints", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Count", 
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

int CVIFUNC Alv_NarrowBand_DataPoints_Get_SecurityGroups(
	Alv_NarrowBand_DataPoints __instance,
	System_Collections_Generic_List_T1 * __returnValue,
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
		"Alv.NarrowBand.DataPoints", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"SecurityGroups", 
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

int CVIFUNC Alv_NarrowBand_DataPoints_Get_Secure(
	Alv_NarrowBand_DataPoints __instance,
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
		"Alv.NarrowBand.DataPoints", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Secure", 
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

int CVIFUNC Alv_NarrowBand_DataPoints_Set_Secure(
	Alv_NarrowBand_DataPoints __instance,
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
		"Alv.NarrowBand.DataPoints", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"Secure", 
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

int CVIFUNC Alv_NarrowBand_DataPoints_Initialize(
	Alv_NarrowBand_DataPoints __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.DataPoints", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Initialize", 
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

int CVIFUNC Alv_NarrowBand_DataPoints_GetVersion(
	Alv_NarrowBand_DataPoints __instance,
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

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.DataPoints", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"GetVersion", 
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

int CVIFUNC Alv_NarrowBand_DataPoints_Load(
	Alv_NarrowBand_DataPoints __instance,
	char * filename,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: filename
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &filename;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.DataPoints", 
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

int CVIFUNC Alv_NarrowBand_DataPoints_AddEnums(
	Alv_NarrowBand_DataPoints __instance,
	System_Xml_XmlNodeList * nodeList,
	char * nameEnum,
	char * nameChild,
	char * attrValue,
	char * attrName,
	char * attrDisplay,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[6] = {0};
	unsigned int __parameterTypes[6];
	void * __parameters[6];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: nodeList
	__parameterTypeNames[0] = "System.Xml.XmlNodeList&,System.Xml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089";
	__parameterTypes[0] = (CDOTNET_OBJECT | CDOTNET_REF);
	__parameters[0] = nodeList;

	// Pre-process parameter: nameEnum
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &nameEnum;

	// Pre-process parameter: nameChild
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &nameChild;

	// Pre-process parameter: attrValue
	__parameterTypeNames[3] = "System.String";
	__parameterTypes[3] = (CDOTNET_STRING);
	__parameters[3] = &attrValue;

	// Pre-process parameter: attrName
	__parameterTypeNames[4] = "System.String";
	__parameterTypes[4] = (CDOTNET_STRING);
	__parameters[4] = &attrName;

	// Pre-process parameter: attrDisplay
	__parameterTypeNames[5] = "System.String";
	__parameterTypes[5] = (CDOTNET_STRING);
	__parameters[5] = &attrDisplay;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.DataPoints", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"AddEnums", 
		0, 
		0, 
		6, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		0, 
		0, 
		__exception));


__Error:
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			nodeList, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Alv_NarrowBand_DataPoints_AllValid(
	Alv_NarrowBand_DataPoints __instance,
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
		"Alv.NarrowBand.DataPoints", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"AllValid", 
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

int CVIFUNC Alv_NarrowBand_DataPoints_SavePointData(
	Alv_NarrowBand_DataPoints __instance,
	char * filename,
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


	// Pre-process parameter: filename
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &filename;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.DataPoints", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"SavePointData", 
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

int CVIFUNC Alv_NarrowBand_DataPoints_LoadPointData(
	Alv_NarrowBand_DataPoints __instance,
	char * filename,
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


	// Pre-process parameter: filename
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &filename;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.DataPoints", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"LoadPointData", 
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

int CVIFUNC Alv_NarrowBand_DataPoints_Find(
	Alv_NarrowBand_DataPoints __instance,
	unsigned short point,
	Alv_NarrowBand_DataPoint * __returnValue,
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


	// Pre-process parameter: point
	__parameterTypeNames[0] = "System.UInt16";
	__parameterTypes[0] = (CDOTNET_UINT16);
	__parameters[0] = &point;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_OBJECT;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.DataPoints", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Find", 
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

int CVIFUNC Alv_NarrowBand_DataPoints_Data(
	Alv_NarrowBand_DataPoints __instance,
	unsigned short point,
	char * data,
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

	// Pre-process parameter: data
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &data;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.DataPoints", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Data", 
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

int CVIFUNC Alv_NarrowBand_DataPoints_Status(
	Alv_NarrowBand_NBProtocol_Status status,
	char ** __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle status__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	if (__returnValue)
		*__returnValue = 0;


	// Pre-process parameter: status
	__errChk(Alv_NarrowBand_NBProtocol_Status__Create(
		&status, 
		&status__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+Status";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &status__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.NarrowBand.DataPoints", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"Status", 
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
	if (status__)
		CDotNetDiscardHandle(status__);
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			__returnValue, 
			CDOTNET_STRING);
	}
	return __error;
}


// Type: Alv.CAN.CanComm
int CVIFUNC Alv_CAN_CanComm_Get_DeviceType(
	Alv_CAN_CanComm __instance,
	Alv_CAN_CanDevices * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.CAN.CanComm", 
		0, 
		0, 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"DeviceType", 
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

int CVIFUNC Alv_CAN_CanComm_Get_BusMode(
	Alv_CAN_CanComm __instance,
	Alv_CAN_CanBusModes * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.CAN.CanComm", 
		0, 
		0, 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"BusMode", 
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

int CVIFUNC Alv_CAN_CanComm_Set_BusMode(
	Alv_CAN_CanComm __instance,
	Alv_CAN_CanBusModes value,
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
	__errChk(Alv_CAN_CanBusModes__Create(
		&value, 
		&value__, 
		__exception));
	__parameterTypeNames[0] = "Alv.CAN.CanBusModes";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &value__;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.CAN.CanComm", 
		0, 
		0, 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"BusMode", 
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

int CVIFUNC Alv_CAN_CanComm_Get_WakeupMode(
	Alv_CAN_CanComm __instance,
	Alv_CAN_CanWakeupModes * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.CAN.CanComm", 
		0, 
		0, 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"WakeupMode", 
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

int CVIFUNC Alv_CAN_CanComm_Set_WakeupMode(
	Alv_CAN_CanComm __instance,
	Alv_CAN_CanWakeupModes value,
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
	__errChk(Alv_CAN_CanWakeupModes__Create(
		&value, 
		&value__, 
		__exception));
	__parameterTypeNames[0] = "Alv.CAN.CanWakeupModes";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &value__;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.CAN.CanComm", 
		0, 
		0, 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"WakeupMode", 
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

int CVIFUNC Alv_CAN_CanComm_Get_BaudRate(
	Alv_CAN_CanComm __instance,
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
		"Alv.CAN.CanComm", 
		0, 
		0, 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"BaudRate", 
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

int CVIFUNC Alv_CAN_CanComm_Set_BaudRate(
	Alv_CAN_CanComm __instance,
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

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.CAN.CanComm", 
		0, 
		0, 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"BaudRate", 
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

int CVIFUNC Alv_CAN_CanComm_Get_DriverID(
	Alv_CAN_CanComm __instance,
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
		"Alv.CAN.CanComm", 
		0, 
		0, 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"DriverID", 
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

int CVIFUNC Alv_CAN_CanComm_Set_DriverID(
	Alv_CAN_CanComm __instance,
	char * value,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: value
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &value;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.CAN.CanComm", 
		0, 
		0, 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"DriverID", 
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

int CVIFUNC Alv_CAN_CanComm_Get_ClientID(
	Alv_CAN_CanComm __instance,
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
		"Alv.CAN.CanComm", 
		0, 
		0, 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"ClientID", 
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

int CVIFUNC Alv_CAN_CanComm_Set_ClientID(
	Alv_CAN_CanComm __instance,
	char * value,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: value
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &value;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.CAN.CanComm", 
		0, 
		0, 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"ClientID", 
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

int CVIFUNC Alv_CAN_CanComm_Get_ReadTimeout(
	Alv_CAN_CanComm __instance,
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
		"Alv.CAN.CanComm", 
		0, 
		0, 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"ReadTimeout", 
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

int CVIFUNC Alv_CAN_CanComm_Set_ReadTimeout(
	Alv_CAN_CanComm __instance,
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

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.CAN.CanComm", 
		0, 
		0, 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"ReadTimeout", 
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

int CVIFUNC Alv_CAN_CanComm_Get_WriteTimeout(
	Alv_CAN_CanComm __instance,
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
		"Alv.CAN.CanComm", 
		0, 
		0, 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"WriteTimeout", 
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

int CVIFUNC Alv_CAN_CanComm_Set_WriteTimeout(
	Alv_CAN_CanComm __instance,
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

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.CAN.CanComm", 
		0, 
		0, 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"WriteTimeout", 
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

int CVIFUNC Alv_CAN_CanComm_Get_Error(
	Alv_CAN_CanComm __instance,
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
		"Alv.CAN.CanComm", 
		0, 
		0, 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Error", 
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

int CVIFUNC Alv_CAN_CanComm_Connect(
	Alv_CAN_CanComm __instance,
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
		"Alv.CAN.CanComm", 
		0, 
		0, 
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

int CVIFUNC Alv_CAN_CanComm_Disconnect(
	Alv_CAN_CanComm __instance,
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
		"Alv.CAN.CanComm", 
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
		&__returnValueTypeId, 
		__returnValue, 
		__exception));


__Error:
	return __error;
}

int CVIFUNC Alv_CAN_CanComm_Read(
	Alv_CAN_CanComm __instance,
	Alv_CAN_CanMsg * msg,
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


	// Pre-process parameter: msg
	__parameterTypeNames[0] = "Alv.CAN.CanMsg&";
	__parameterTypes[0] = (CDOTNET_STRUCT | CDOTNET_REF);
	__parameters[0] = msg;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.CAN.CanComm", 
		0, 
		0, 
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
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			msg, 
			CDOTNET_STRUCT);
	}
	return __error;
}

int CVIFUNC Alv_CAN_CanComm_Write(
	Alv_CAN_CanComm __instance,
	Alv_CAN_CanMsg * msg,
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


	// Pre-process parameter: msg
	__parameterTypeNames[0] = "Alv.CAN.CanMsg&";
	__parameterTypes[0] = (CDOTNET_STRUCT | CDOTNET_REF);
	__parameters[0] = msg;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.CAN.CanComm", 
		0, 
		0, 
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
			msg, 
			CDOTNET_STRUCT);
	}
	return __error;
}

int CVIFUNC Alv_CAN_CanComm_Clear(
	Alv_CAN_CanComm __instance,
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
		"Alv.CAN.CanComm", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Clear", 
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


// Type: Alv.CAN.PeakCan
int CVIFUNC Alv_CAN_PeakCan__Create(
	Alv_CAN_PeakCan * __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"Alv.CAN.PeakCan", 
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

int CVIFUNC Alv_CAN_PeakCan_Get_DeviceType(
	Alv_CAN_PeakCan __instance,
	Alv_CAN_CanDevices * __returnValue,
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
		"Alv.CAN.PeakCan", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"DeviceType", 
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

int CVIFUNC Alv_CAN_PeakCan_Get_BusMode(
	Alv_CAN_PeakCan __instance,
	Alv_CAN_CanBusModes * __returnValue,
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
		"Alv.CAN.PeakCan", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"BusMode", 
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

int CVIFUNC Alv_CAN_PeakCan_Set_BusMode(
	Alv_CAN_PeakCan __instance,
	Alv_CAN_CanBusModes value,
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
	__errChk(Alv_CAN_CanBusModes__Create(
		&value, 
		&value__, 
		__exception));
	__parameterTypeNames[0] = "Alv.CAN.CanBusModes";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &value__;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.CAN.PeakCan", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"BusMode", 
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

int CVIFUNC Alv_CAN_PeakCan_Get_WakeupMode(
	Alv_CAN_PeakCan __instance,
	Alv_CAN_CanWakeupModes * __returnValue,
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
		"Alv.CAN.PeakCan", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"WakeupMode", 
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

int CVIFUNC Alv_CAN_PeakCan_Set_WakeupMode(
	Alv_CAN_PeakCan __instance,
	Alv_CAN_CanWakeupModes value,
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
	__errChk(Alv_CAN_CanWakeupModes__Create(
		&value, 
		&value__, 
		__exception));
	__parameterTypeNames[0] = "Alv.CAN.CanWakeupModes";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &value__;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.CAN.PeakCan", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"WakeupMode", 
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

int CVIFUNC Alv_CAN_PeakCan_Get_BaudRate(
	Alv_CAN_PeakCan __instance,
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
		"Alv.CAN.PeakCan", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"BaudRate", 
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

int CVIFUNC Alv_CAN_PeakCan_Set_BaudRate(
	Alv_CAN_PeakCan __instance,
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
		"Alv.CAN.PeakCan", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"BaudRate", 
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

int CVIFUNC Alv_CAN_PeakCan_Get_DriverID(
	Alv_CAN_PeakCan __instance,
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
		"Alv.CAN.PeakCan", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"DriverID", 
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

int CVIFUNC Alv_CAN_PeakCan_Set_DriverID(
	Alv_CAN_PeakCan __instance,
	char * value,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: value
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &value;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.CAN.PeakCan", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"DriverID", 
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

int CVIFUNC Alv_CAN_PeakCan_Get_ClientID(
	Alv_CAN_PeakCan __instance,
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
		"Alv.CAN.PeakCan", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"ClientID", 
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

int CVIFUNC Alv_CAN_PeakCan_Set_ClientID(
	Alv_CAN_PeakCan __instance,
	char * value,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: value
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &value;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.CAN.PeakCan", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"ClientID", 
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

int CVIFUNC Alv_CAN_PeakCan_Get_ReadTimeout(
	Alv_CAN_PeakCan __instance,
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
		"Alv.CAN.PeakCan", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"ReadTimeout", 
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

int CVIFUNC Alv_CAN_PeakCan_Set_ReadTimeout(
	Alv_CAN_PeakCan __instance,
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
		"Alv.CAN.PeakCan", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"ReadTimeout", 
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

int CVIFUNC Alv_CAN_PeakCan_Get_WriteTimeout(
	Alv_CAN_PeakCan __instance,
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
		"Alv.CAN.PeakCan", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"WriteTimeout", 
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

int CVIFUNC Alv_CAN_PeakCan_Set_WriteTimeout(
	Alv_CAN_PeakCan __instance,
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
		"Alv.CAN.PeakCan", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"WriteTimeout", 
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

int CVIFUNC Alv_CAN_PeakCan_Get_Error(
	Alv_CAN_PeakCan __instance,
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
		"Alv.CAN.PeakCan", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Error", 
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

int CVIFUNC Alv_CAN_PeakCan_Connect(
	Alv_CAN_PeakCan __instance,
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
		"Alv.CAN.PeakCan", 
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

int CVIFUNC Alv_CAN_PeakCan_Disconnect(
	Alv_CAN_PeakCan __instance,
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
		"Alv.CAN.PeakCan", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Disconnect", 
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

int CVIFUNC Alv_CAN_PeakCan_Clear(
	Alv_CAN_PeakCan __instance,
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
		"Alv.CAN.PeakCan", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Clear", 
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

int CVIFUNC Alv_CAN_PeakCan_Read(
	Alv_CAN_PeakCan __instance,
	Alv_CAN_CanMsg * msg,
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


	// Pre-process parameter: msg
	__parameterTypeNames[0] = "Alv.CAN.CanMsg&";
	__parameterTypes[0] = (CDOTNET_STRUCT | CDOTNET_REF);
	__parameters[0] = msg;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.CAN.PeakCan", 
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
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			msg, 
			CDOTNET_STRUCT);
	}
	return __error;
}

int CVIFUNC Alv_CAN_PeakCan_Write(
	Alv_CAN_PeakCan __instance,
	Alv_CAN_CanMsg * msg,
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


	// Pre-process parameter: msg
	__parameterTypeNames[0] = "Alv.CAN.CanMsg&";
	__parameterTypes[0] = (CDOTNET_STRUCT | CDOTNET_REF);
	__parameters[0] = msg;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.CAN.PeakCan", 
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
			msg, 
			CDOTNET_STRUCT);
	}
	return __error;
}


// Type: Alv.NarrowBand.Sensor
int CVIFUNC Alv_NarrowBand_Sensor_Get_Position(
	Alv_NarrowBand_Sensor __instance,
	Alv_NarrowBand_NBProtocol_Position * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.NarrowBand.Sensor", 
		0, 
		0, 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Position", 
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

int CVIFUNC Alv_NarrowBand_Sensor_Init(
	Alv_NarrowBand_Sensor __instance,
	char * PointsList,
	Alv_NarrowBand_NBProtocol_Position SensorPosition,
	Alv_CAN_CanComm CanInterface,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];
	CDotNetHandle SensorPosition__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: PointsList
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &PointsList;

	// Pre-process parameter: SensorPosition
	__errChk(Alv_NarrowBand_NBProtocol_Position__Create(
		&SensorPosition, 
		&SensorPosition__, 
		__exception));
	__parameterTypeNames[1] = "Alv.NarrowBand.NBProtocol+Position";
	__parameterTypes[1] = (CDOTNET_ENUM);
	__parameters[1] = &SensorPosition__;

	// Pre-process parameter: CanInterface
	__parameterTypeNames[2] = "Alv.CAN.CanComm";
	__parameterTypes[2] = (CDOTNET_OBJECT);
	__parameters[2] = &CanInterface;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.NarrowBand.Sensor", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Init", 
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
	if (SensorPosition__)
		CDotNetDiscardHandle(SensorPosition__);
	return __error;
}

int CVIFUNC Alv_NarrowBand_Sensor_PointRead(
	Alv_NarrowBand_Sensor __instance,
	unsigned short point,
	char ** value,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	CDotNetHandle __returnValue__ = 0;
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
	__returnValueTypeId = CDOTNET_ENUM;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.NarrowBand.Sensor", 
		0, 
		0, 
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
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			value, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC Alv_NarrowBand_Sensor_PointWrite(
	Alv_NarrowBand_Sensor __instance,
	unsigned short point,
	char * value,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	CDotNetHandle __returnValue__ = 0;
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
	__returnValueTypeId = CDOTNET_ENUM;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.NarrowBand.Sensor", 
		0, 
		0, 
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

int CVIFUNC Alv_NarrowBand_Sensor_EnterEngineeringMode(
	Alv_NarrowBand_Sensor __instance,
	int selection,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
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


	// Pre-process parameter: selection
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &selection;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.NarrowBand.Sensor", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"EnterEngineeringMode", 
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
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_NarrowBand_Sensor_SaveConfiguration(
	Alv_NarrowBand_Sensor __instance,
	Alv_NarrowBand_NBProtocol_ConfigurationBlock block,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle block__ = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: block
	__errChk(Alv_NarrowBand_NBProtocol_ConfigurationBlock__Create(
		&block, 
		&block__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+ConfigurationBlock";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &block__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.NarrowBand.Sensor", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"SaveConfiguration", 
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
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (block__)
		CDotNetDiscardHandle(block__);
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_NarrowBand_Sensor_ReloadConfiguration(
	Alv_NarrowBand_Sensor __instance,
	Alv_NarrowBand_NBProtocol_ConfigurationBlock block,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle block__ = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: block
	__errChk(Alv_NarrowBand_NBProtocol_ConfigurationBlock__Create(
		&block, 
		&block__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+ConfigurationBlock";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &block__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.NarrowBand.Sensor", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ReloadConfiguration", 
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
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (block__)
		CDotNetDiscardHandle(block__);
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_NarrowBand_Sensor_ResetConfiguration(
	Alv_NarrowBand_Sensor __instance,
	Alv_NarrowBand_NBProtocol_ConfigurationBlock block,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle block__ = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: block
	__errChk(Alv_NarrowBand_NBProtocol_ConfigurationBlock__Create(
		&block, 
		&block__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+ConfigurationBlock";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &block__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.NarrowBand.Sensor", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ResetConfiguration", 
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
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (block__)
		CDotNetDiscardHandle(block__);
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_NarrowBand_Sensor_ControlCWMode(
	Alv_NarrowBand_Sensor __instance,
	int selection,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
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


	// Pre-process parameter: selection
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &selection;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.NarrowBand.Sensor", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ControlCWMode", 
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
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_NarrowBand_Sensor_SelectTxAntenna(
	Alv_NarrowBand_Sensor __instance,
	Alv_NarrowBand_NBProtocol_Antenna antenna,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle antenna__ = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: antenna
	__errChk(Alv_NarrowBand_NBProtocol_Antenna__Create(
		&antenna, 
		&antenna__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+Antenna";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &antenna__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.NarrowBand.Sensor", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"SelectTxAntenna", 
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
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (antenna__)
		CDotNetDiscardHandle(antenna__);
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_NarrowBand_Sensor_ControlRF(
	Alv_NarrowBand_Sensor __instance,
	int selection,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
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


	// Pre-process parameter: selection
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &selection;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.NarrowBand.Sensor", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ControlRF", 
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
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_NarrowBand_Sensor_ControlRadarRx(
	Alv_NarrowBand_Sensor __instance,
	int selection,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
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


	// Pre-process parameter: selection
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &selection;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.NarrowBand.Sensor", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ControlRadarRx", 
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
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_NarrowBand_Sensor_ControlDCOffset(
	Alv_NarrowBand_Sensor __instance,
	Alv_NarrowBand_NBProtocol_DCOffset softwareoffset,
	Alv_NarrowBand_NBProtocol_DCOffset hardwareoffset,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	CDotNetHandle softwareoffset__ = 0;
	CDotNetHandle hardwareoffset__ = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: softwareoffset
	__errChk(Alv_NarrowBand_NBProtocol_DCOffset__Create(
		&softwareoffset, 
		&softwareoffset__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+DCOffset";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &softwareoffset__;

	// Pre-process parameter: hardwareoffset
	__errChk(Alv_NarrowBand_NBProtocol_DCOffset__Create(
		&hardwareoffset, 
		&hardwareoffset__, 
		__exception));
	__parameterTypeNames[1] = "Alv.NarrowBand.NBProtocol+DCOffset";
	__parameterTypes[1] = (CDOTNET_ENUM);
	__parameters[1] = &hardwareoffset__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.NarrowBand.Sensor", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ControlDCOffset", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (softwareoffset__)
		CDotNetDiscardHandle(softwareoffset__);
	if (hardwareoffset__)
		CDotNetDiscardHandle(hardwareoffset__);
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_NarrowBand_Sensor_ResetProcessor(
	Alv_NarrowBand_Sensor __instance,
	Alv_NarrowBand_NBProtocol_Processor processor,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle processor__ = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: processor
	__errChk(Alv_NarrowBand_NBProtocol_Processor__Create(
		&processor, 
		&processor__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+Processor";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &processor__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.NarrowBand.Sensor", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ResetProcessor", 
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
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (processor__)
		CDotNetDiscardHandle(processor__);
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_NarrowBand_Sensor_ControlLED(
	Alv_NarrowBand_Sensor __instance,
	Alv_NarrowBand_NBProtocol_Processor processor,
	Alv_NarrowBand_NBProtocol_TestLED control,
	unsigned int interval,
	unsigned int timeout,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];
	CDotNetHandle processor__ = 0;
	CDotNetHandle control__ = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: processor
	__errChk(Alv_NarrowBand_NBProtocol_Processor__Create(
		&processor, 
		&processor__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+Processor";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &processor__;

	// Pre-process parameter: control
	__errChk(Alv_NarrowBand_NBProtocol_TestLED__Create(
		&control, 
		&control__, 
		__exception));
	__parameterTypeNames[1] = "Alv.NarrowBand.NBProtocol+TestLED";
	__parameterTypes[1] = (CDOTNET_ENUM);
	__parameters[1] = &control__;

	// Pre-process parameter: interval
	__parameterTypeNames[2] = "System.UInt32";
	__parameterTypes[2] = (CDOTNET_UINT32);
	__parameters[2] = &interval;

	// Pre-process parameter: timeout
	__parameterTypeNames[3] = "System.UInt32";
	__parameterTypes[3] = (CDOTNET_UINT32);
	__parameters[3] = &timeout;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.NarrowBand.Sensor", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ControlLED", 
		0, 
		0, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (processor__)
		CDotNetDiscardHandle(processor__);
	if (control__)
		CDotNetDiscardHandle(control__);
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_NarrowBand_Sensor_ControlRawSweepBroadcast(
	Alv_NarrowBand_Sensor __instance,
	Alv_NarrowBand_NBProtocol_Processor processor,
	unsigned char control,
	unsigned int count,
	unsigned char type,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];
	CDotNetHandle processor__ = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: processor
	__errChk(Alv_NarrowBand_NBProtocol_Processor__Create(
		&processor, 
		&processor__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+Processor";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &processor__;

	// Pre-process parameter: control
	__parameterTypeNames[1] = "System.Byte";
	__parameterTypes[1] = (CDOTNET_BYTE);
	__parameters[1] = &control;

	// Pre-process parameter: count
	__parameterTypeNames[2] = "System.UInt32";
	__parameterTypes[2] = (CDOTNET_UINT32);
	__parameters[2] = &count;

	// Pre-process parameter: type
	__parameterTypeNames[3] = "System.Byte";
	__parameterTypes[3] = (CDOTNET_BYTE);
	__parameters[3] = &type;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.NarrowBand.Sensor", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ControlRawSweepBroadcast", 
		0, 
		0, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (processor__)
		CDotNetDiscardHandle(processor__);
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_NarrowBand_Sensor_PerformSelfTest(
	Alv_NarrowBand_Sensor __instance,
	Alv_NarrowBand_NBProtocol_Processor processor,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle processor__ = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: processor
	__errChk(Alv_NarrowBand_NBProtocol_Processor__Create(
		&processor, 
		&processor__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+Processor";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &processor__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.NarrowBand.Sensor", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"PerformSelfTest", 
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
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (processor__)
		CDotNetDiscardHandle(processor__);
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_NarrowBand_Sensor_ControlStaticTestMode(
	Alv_NarrowBand_Sensor __instance,
	Alv_NarrowBand_NBProtocol_StaticTestMode selection,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle selection__ = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: selection
	__errChk(Alv_NarrowBand_NBProtocol_StaticTestMode__Create(
		&selection, 
		&selection__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+StaticTestMode";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &selection__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.NarrowBand.Sensor", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ControlStaticTestMode", 
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
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (selection__)
		CDotNetDiscardHandle(selection__);
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_NarrowBand_Sensor_ControlPulseJitter(
	Alv_NarrowBand_Sensor __instance,
	int selection,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
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


	// Pre-process parameter: selection
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &selection;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.NarrowBand.Sensor", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ControlPulseJitter", 
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
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_NarrowBand_Sensor_ForceRadarMode(
	Alv_NarrowBand_Sensor __instance,
	Alv_NarrowBand_NBProtocol_ControlRadarMode mode,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle mode__ = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: mode
	__errChk(Alv_NarrowBand_NBProtocol_ControlRadarMode__Create(
		&mode, 
		&mode__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+ControlRadarMode";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &mode__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.NarrowBand.Sensor", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ForceRadarMode", 
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
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (mode__)
		CDotNetDiscardHandle(mode__);
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_NarrowBand_Sensor_RunOffsetInitialization(
	Alv_NarrowBand_Sensor __instance,
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

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.NarrowBand.Sensor", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RunOffsetInitialization", 
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

int CVIFUNC Alv_NarrowBand_Sensor_ReadManufacturingData(
	Alv_NarrowBand_Sensor __instance,
	unsigned char ** data,
	ssize_t * __dataLength,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle data__ = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	*data = 0;
	*__dataLength = 0;


	// Pre-process parameter: data
	__parameterTypeNames[0] = "System.Byte[]&";
	__parameterTypes[0] = (CDOTNET_BYTE | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[0] = &data__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.NarrowBand.Sensor", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ReadManufacturingData", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		&__returnValue__, 
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

	// Post-process return value
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (data__)
		CDotNetDiscardHandle(data__);
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			data, 
			CDOTNET_BYTE, 
			1, 
			__dataLength);
	}
	return __error;
}

int CVIFUNC Alv_NarrowBand_Sensor_ErrorManager(
	Alv_NarrowBand_Sensor __instance,
	Alv_NarrowBand_NBProtocol_ControlError selection,
	unsigned int code,
	unsigned int timeout,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];
	CDotNetHandle selection__ = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: selection
	__errChk(Alv_NarrowBand_NBProtocol_ControlError__Create(
		&selection, 
		&selection__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+ControlError";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &selection__;

	// Pre-process parameter: code
	__parameterTypeNames[1] = "System.UInt32";
	__parameterTypes[1] = (CDOTNET_UINT32);
	__parameters[1] = &code;

	// Pre-process parameter: timeout
	__parameterTypeNames[2] = "System.UInt32";
	__parameterTypes[2] = (CDOTNET_UINT32);
	__parameters[2] = &timeout;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.NarrowBand.Sensor", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ErrorManager", 
		0, 
		0, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (selection__)
		CDotNetDiscardHandle(selection__);
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_NarrowBand_Sensor_LoggerControl(
	Alv_NarrowBand_Sensor __instance,
	Alv_NarrowBand_NBProtocol_LoggerID logger,
	Alv_NarrowBand_NBProtocol_ControlLogger selection,
	unsigned int control,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];
	CDotNetHandle logger__ = 0;
	CDotNetHandle selection__ = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: logger
	__errChk(Alv_NarrowBand_NBProtocol_LoggerID__Create(
		&logger, 
		&logger__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+LoggerID";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &logger__;

	// Pre-process parameter: selection
	__errChk(Alv_NarrowBand_NBProtocol_ControlLogger__Create(
		&selection, 
		&selection__, 
		__exception));
	__parameterTypeNames[1] = "Alv.NarrowBand.NBProtocol+ControlLogger";
	__parameterTypes[1] = (CDOTNET_ENUM);
	__parameters[1] = &selection__;

	// Pre-process parameter: control
	__parameterTypeNames[2] = "System.UInt32";
	__parameterTypes[2] = (CDOTNET_UINT32);
	__parameters[2] = &control;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.NarrowBand.Sensor", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"LoggerControl", 
		0, 
		0, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (logger__)
		CDotNetDiscardHandle(logger__);
	if (selection__)
		CDotNetDiscardHandle(selection__);
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_NarrowBand_Sensor_Program(
	Alv_NarrowBand_Sensor __instance,
	char * filepath,
	Alv_NarrowBand_NBProtocol_Processor processor,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	CDotNetHandle processor__ = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: filepath
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &filepath;

	// Pre-process parameter: processor
	__errChk(Alv_NarrowBand_NBProtocol_Processor__Create(
		&processor, 
		&processor__, 
		__exception));
	__parameterTypeNames[1] = "Alv.NarrowBand.NBProtocol+Processor";
	__parameterTypes[1] = (CDOTNET_ENUM);
	__parameters[1] = &processor__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.NarrowBand.Sensor", 
		0, 
		0, 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Program", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (processor__)
		CDotNetDiscardHandle(processor__);
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_NarrowBand_Sensor_ReadDspDiag(
	Alv_NarrowBand_Sensor __instance,
	Alv_NarrowBand_DSP_DIAG * Msg,
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
	*Msg = 0;


	// Pre-process parameter: Msg
	__parameterTypeNames[0] = "Alv.NarrowBand.DSP_DIAG&";
	__parameterTypes[0] = (CDOTNET_OBJECT | CDOTNET_OUT);
	__parameters[0] = Msg;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.NarrowBand.Sensor", 
		0, 
		0, 
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
			Msg, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Alv_NarrowBand_Sensor_ReadHpDiag(
	Alv_NarrowBand_Sensor __instance,
	Alv_NarrowBand_HP_DIAG * Msg,
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
	*Msg = 0;


	// Pre-process parameter: Msg
	__parameterTypeNames[0] = "Alv.NarrowBand.HP_DIAG&";
	__parameterTypes[0] = (CDOTNET_OBJECT | CDOTNET_OUT);
	__parameters[0] = Msg;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.NarrowBand.Sensor", 
		0, 
		0, 
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
			Msg, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Alv_NarrowBand_Sensor_ReadUntDat(
	Alv_NarrowBand_Sensor __instance,
	Alv_NarrowBand_UNT_DAT * Msg,
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
	*Msg = 0;


	// Pre-process parameter: Msg
	__parameterTypeNames[0] = "Alv.NarrowBand.UNT_DAT&";
	__parameterTypes[0] = (CDOTNET_OBJECT | CDOTNET_OUT);
	__parameters[0] = Msg;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.NarrowBand.Sensor", 
		0, 
		0, 
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
			Msg, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Alv_NarrowBand_Sensor_ClearQueue(
	Alv_NarrowBand_Sensor __instance,
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
		"Alv.NarrowBand.Sensor", 
		0, 
		0, 
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

int CVIFUNC Alv_NarrowBand_Sensor_SendVehicleSpeed(
	Alv_NarrowBand_Sensor __instance,
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

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.NarrowBand.Sensor", 
		0, 
		0, 
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

int CVIFUNC Alv_NarrowBand_Sensor_SendGearPosition(
	Alv_NarrowBand_Sensor __instance,
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
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+GearPosition";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &gear__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call interface member
	__errChk(CDotNetInvokeGenericInterfaceMember(
		__assemblyHandle, 
		"Alv.NarrowBand.Sensor", 
		0, 
		0, 
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


// Type: Alv.NarrowBand.SensorComm
int CVIFUNC Alv_NarrowBand_SensorComm__Create(
	Alv_NarrowBand_SensorComm * __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"Alv.NarrowBand.SensorComm", 
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

int CVIFUNC Alv_NarrowBand_SensorComm_Get_Position(
	Alv_NarrowBand_SensorComm __instance,
	Alv_NarrowBand_NBProtocol_Position * __returnValue,
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
		"Alv.NarrowBand.SensorComm", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Position", 
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

int CVIFUNC Alv_NarrowBand_SensorComm_Init(
	Alv_NarrowBand_SensorComm __instance,
	char * PointsList,
	Alv_NarrowBand_NBProtocol_Position SensorPosition,
	Alv_CAN_CanComm CanInterface,
	int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];
	CDotNetHandle SensorPosition__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: PointsList
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &PointsList;

	// Pre-process parameter: SensorPosition
	__errChk(Alv_NarrowBand_NBProtocol_Position__Create(
		&SensorPosition, 
		&SensorPosition__, 
		__exception));
	__parameterTypeNames[1] = "Alv.NarrowBand.NBProtocol+Position";
	__parameterTypes[1] = (CDOTNET_ENUM);
	__parameters[1] = &SensorPosition__;

	// Pre-process parameter: CanInterface
	__parameterTypeNames[2] = "Alv.CAN.CanComm";
	__parameterTypes[2] = (CDOTNET_OBJECT);
	__parameters[2] = &CanInterface;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.SensorComm", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Init", 
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
	if (SensorPosition__)
		CDotNetDiscardHandle(SensorPosition__);
	return __error;
}

int CVIFUNC Alv_NarrowBand_SensorComm_PointRead(
	Alv_NarrowBand_SensorComm __instance,
	unsigned short point,
	char ** value,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	CDotNetHandle __returnValue__ = 0;
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
	__returnValueTypeId = CDOTNET_ENUM;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.SensorComm", 
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
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			value, 
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC Alv_NarrowBand_SensorComm_PointWrite(
	Alv_NarrowBand_SensorComm __instance,
	unsigned short point,
	char * value,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	CDotNetHandle __returnValue__ = 0;
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
	__returnValueTypeId = CDOTNET_ENUM;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.SensorComm", 
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

int CVIFUNC Alv_NarrowBand_SensorComm_SendExecute(
	Alv_NarrowBand_SensorComm __instance,
	Alv_NarrowBand_NBProtocol_ExecuteFunctions function,
	unsigned int functionData32,
	unsigned short functionData16,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];
	CDotNetHandle function__ = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: function
	__errChk(Alv_NarrowBand_NBProtocol_ExecuteFunctions__Create(
		&function, 
		&function__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+ExecuteFunctions";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &function__;

	// Pre-process parameter: functionData32
	__parameterTypeNames[1] = "System.UInt32";
	__parameterTypes[1] = (CDOTNET_UINT32);
	__parameters[1] = &functionData32;

	// Pre-process parameter: functionData16
	__parameterTypeNames[2] = "System.UInt16";
	__parameterTypes[2] = (CDOTNET_UINT16);
	__parameters[2] = &functionData16;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.SensorComm", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"SendExecute", 
		0, 
		0, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (function__)
		CDotNetDiscardHandle(function__);
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_NarrowBand_SensorComm_EnterEngineeringMode(
	Alv_NarrowBand_SensorComm __instance,
	int enterMode,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
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


	// Pre-process parameter: enterMode
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &enterMode;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.SensorComm", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"EnterEngineeringMode", 
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
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_NarrowBand_SensorComm_EnterEngineeringModeGMVCAN(
	Alv_NarrowBand_SensorComm __instance,
	int enterMode,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
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


	// Pre-process parameter: enterMode
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &enterMode;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.SensorComm", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"EnterEngineeringModeGMVCAN", 
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
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_NarrowBand_SensorComm_ReadManufacturingData(
	Alv_NarrowBand_SensorComm __instance,
	unsigned char ** response,
	ssize_t * __responseLength,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle response__ = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;
	*response = 0;
	*__responseLength = 0;


	// Pre-process parameter: response
	__parameterTypeNames[0] = "System.Byte[]&";
	__parameterTypes[0] = (CDOTNET_BYTE | CDOTNET_ARRAY | CDOTNET_OUT);
	__parameters[0] = &response__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.SensorComm", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ReadManufacturingData", 
		0, 
		0, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process parameter: response
	if (response__) {
		__errChk(CDotNetGetArrayElements(
			response__, 
			CDOTNET_BYTE, 
			0, 
			response));
		__errChk(CDotNetGetArrayLength(
			response__, 
			0, 
			__responseLength));
	}

	// Post-process return value
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (response__)
		CDotNetDiscardHandle(response__);
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			response, 
			CDOTNET_BYTE, 
			1, 
			__responseLength);
	}
	return __error;
}

int CVIFUNC Alv_NarrowBand_SensorComm_SaveConfiguration(
	Alv_NarrowBand_SensorComm __instance,
	Alv_NarrowBand_NBProtocol_ConfigurationBlock block,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle block__ = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: block
	__errChk(Alv_NarrowBand_NBProtocol_ConfigurationBlock__Create(
		&block, 
		&block__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+ConfigurationBlock";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &block__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.SensorComm", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"SaveConfiguration", 
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
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (block__)
		CDotNetDiscardHandle(block__);
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_NarrowBand_SensorComm_ReloadConfiguration(
	Alv_NarrowBand_SensorComm __instance,
	Alv_NarrowBand_NBProtocol_ConfigurationBlock block,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle block__ = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: block
	__errChk(Alv_NarrowBand_NBProtocol_ConfigurationBlock__Create(
		&block, 
		&block__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+ConfigurationBlock";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &block__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.SensorComm", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ReloadConfiguration", 
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
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (block__)
		CDotNetDiscardHandle(block__);
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_NarrowBand_SensorComm_ResetConfiguration(
	Alv_NarrowBand_SensorComm __instance,
	Alv_NarrowBand_NBProtocol_ConfigurationBlock block,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle block__ = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: block
	__errChk(Alv_NarrowBand_NBProtocol_ConfigurationBlock__Create(
		&block, 
		&block__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+ConfigurationBlock";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &block__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.SensorComm", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ResetConfiguration", 
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
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (block__)
		CDotNetDiscardHandle(block__);
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_NarrowBand_SensorComm_ResetProcessor(
	Alv_NarrowBand_SensorComm __instance,
	Alv_NarrowBand_NBProtocol_Processor processor,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle processor__ = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: processor
	__errChk(Alv_NarrowBand_NBProtocol_Processor__Create(
		&processor, 
		&processor__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+Processor";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &processor__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.SensorComm", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ResetProcessor", 
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
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (processor__)
		CDotNetDiscardHandle(processor__);
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_NarrowBand_SensorComm_ControlCWMode(
	Alv_NarrowBand_SensorComm __instance,
	int selection,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
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


	// Pre-process parameter: selection
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &selection;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.SensorComm", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ControlCWMode", 
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
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_NarrowBand_SensorComm_SelectTxAntenna(
	Alv_NarrowBand_SensorComm __instance,
	Alv_NarrowBand_NBProtocol_Antenna antenna,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle antenna__ = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: antenna
	__errChk(Alv_NarrowBand_NBProtocol_Antenna__Create(
		&antenna, 
		&antenna__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+Antenna";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &antenna__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.SensorComm", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"SelectTxAntenna", 
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
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (antenna__)
		CDotNetDiscardHandle(antenna__);
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_NarrowBand_SensorComm_ControlRF(
	Alv_NarrowBand_SensorComm __instance,
	int selection,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
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


	// Pre-process parameter: selection
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &selection;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.SensorComm", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ControlRF", 
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
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_NarrowBand_SensorComm_ControlRadarRx(
	Alv_NarrowBand_SensorComm __instance,
	int selection,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
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


	// Pre-process parameter: selection
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &selection;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.SensorComm", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ControlRadarRx", 
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
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_NarrowBand_SensorComm_ControlDCOffset(
	Alv_NarrowBand_SensorComm __instance,
	Alv_NarrowBand_NBProtocol_DCOffset softwareoffset,
	Alv_NarrowBand_NBProtocol_DCOffset hardwareoffset,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	CDotNetHandle softwareoffset__ = 0;
	CDotNetHandle hardwareoffset__ = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: softwareoffset
	__errChk(Alv_NarrowBand_NBProtocol_DCOffset__Create(
		&softwareoffset, 
		&softwareoffset__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+DCOffset";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &softwareoffset__;

	// Pre-process parameter: hardwareoffset
	__errChk(Alv_NarrowBand_NBProtocol_DCOffset__Create(
		&hardwareoffset, 
		&hardwareoffset__, 
		__exception));
	__parameterTypeNames[1] = "Alv.NarrowBand.NBProtocol+DCOffset";
	__parameterTypes[1] = (CDOTNET_ENUM);
	__parameters[1] = &hardwareoffset__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.SensorComm", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ControlDCOffset", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (softwareoffset__)
		CDotNetDiscardHandle(softwareoffset__);
	if (hardwareoffset__)
		CDotNetDiscardHandle(hardwareoffset__);
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_NarrowBand_SensorComm_PerformSelfTest(
	Alv_NarrowBand_SensorComm __instance,
	Alv_NarrowBand_NBProtocol_Processor processor,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle processor__ = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: processor
	__errChk(Alv_NarrowBand_NBProtocol_Processor__Create(
		&processor, 
		&processor__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+Processor";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &processor__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.SensorComm", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"PerformSelfTest", 
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
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (processor__)
		CDotNetDiscardHandle(processor__);
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_NarrowBand_SensorComm_ControlLED(
	Alv_NarrowBand_SensorComm __instance,
	Alv_NarrowBand_NBProtocol_Processor processor,
	Alv_NarrowBand_NBProtocol_TestLED control,
	unsigned int interval,
	unsigned int timeout,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];
	CDotNetHandle processor__ = 0;
	CDotNetHandle control__ = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: processor
	__errChk(Alv_NarrowBand_NBProtocol_Processor__Create(
		&processor, 
		&processor__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+Processor";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &processor__;

	// Pre-process parameter: control
	__errChk(Alv_NarrowBand_NBProtocol_TestLED__Create(
		&control, 
		&control__, 
		__exception));
	__parameterTypeNames[1] = "Alv.NarrowBand.NBProtocol+TestLED";
	__parameterTypes[1] = (CDOTNET_ENUM);
	__parameters[1] = &control__;

	// Pre-process parameter: interval
	__parameterTypeNames[2] = "System.UInt32";
	__parameterTypes[2] = (CDOTNET_UINT32);
	__parameters[2] = &interval;

	// Pre-process parameter: timeout
	__parameterTypeNames[3] = "System.UInt32";
	__parameterTypes[3] = (CDOTNET_UINT32);
	__parameters[3] = &timeout;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.SensorComm", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ControlLED", 
		0, 
		0, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (processor__)
		CDotNetDiscardHandle(processor__);
	if (control__)
		CDotNetDiscardHandle(control__);
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_NarrowBand_SensorComm_ControlRawSweepBroadcast(
	Alv_NarrowBand_SensorComm __instance,
	Alv_NarrowBand_NBProtocol_Processor processor,
	unsigned char control,
	unsigned int count,
	unsigned char type,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];
	CDotNetHandle processor__ = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: processor
	__errChk(Alv_NarrowBand_NBProtocol_Processor__Create(
		&processor, 
		&processor__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+Processor";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &processor__;

	// Pre-process parameter: control
	__parameterTypeNames[1] = "System.Byte";
	__parameterTypes[1] = (CDOTNET_BYTE);
	__parameters[1] = &control;

	// Pre-process parameter: count
	__parameterTypeNames[2] = "System.UInt32";
	__parameterTypes[2] = (CDOTNET_UINT32);
	__parameters[2] = &count;

	// Pre-process parameter: type
	__parameterTypeNames[3] = "System.Byte";
	__parameterTypes[3] = (CDOTNET_BYTE);
	__parameters[3] = &type;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.SensorComm", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ControlRawSweepBroadcast", 
		0, 
		0, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (processor__)
		CDotNetDiscardHandle(processor__);
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_NarrowBand_SensorComm_ControlStaticTestMode(
	Alv_NarrowBand_SensorComm __instance,
	Alv_NarrowBand_NBProtocol_StaticTestMode selection,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle selection__ = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: selection
	__errChk(Alv_NarrowBand_NBProtocol_StaticTestMode__Create(
		&selection, 
		&selection__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+StaticTestMode";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &selection__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.SensorComm", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ControlStaticTestMode", 
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
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (selection__)
		CDotNetDiscardHandle(selection__);
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_NarrowBand_SensorComm_ControlPulseJitter(
	Alv_NarrowBand_SensorComm __instance,
	int selection,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
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


	// Pre-process parameter: selection
	__parameterTypeNames[0] = "System.Boolean";
	__parameterTypes[0] = (CDOTNET_BOOLEAN);
	__parameters[0] = &selection;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.SensorComm", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ControlPulseJitter", 
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
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_NarrowBand_SensorComm_ForceRadarMode(
	Alv_NarrowBand_SensorComm __instance,
	Alv_NarrowBand_NBProtocol_ControlRadarMode mode,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle mode__ = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: mode
	__errChk(Alv_NarrowBand_NBProtocol_ControlRadarMode__Create(
		&mode, 
		&mode__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+ControlRadarMode";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &mode__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.SensorComm", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ForceRadarMode", 
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
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (mode__)
		CDotNetDiscardHandle(mode__);
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_NarrowBand_SensorComm_RunOffsetInitialization(
	Alv_NarrowBand_SensorComm __instance,
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
		"Alv.NarrowBand.SensorComm", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"RunOffsetInitialization", 
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

int CVIFUNC Alv_NarrowBand_SensorComm_EnterProgramMode(
	Alv_NarrowBand_SensorComm __instance,
	Alv_NarrowBand_NBProtocol_Processor processor,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle processor__ = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: processor
	__errChk(Alv_NarrowBand_NBProtocol_Processor__Create(
		&processor, 
		&processor__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+Processor";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &processor__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.SensorComm", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"EnterProgramMode", 
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
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (processor__)
		CDotNetDiscardHandle(processor__);
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_NarrowBand_SensorComm_SendProgram(
	Alv_NarrowBand_SensorComm __instance,
	Alv_NarrowBand_NBProtocol_Processor processor,
	unsigned char * data,
	ssize_t __dataLength,
	unsigned int address,
	unsigned char checksum,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[4] = {0};
	unsigned int __parameterTypes[4];
	void * __parameters[4];
	CDotNetHandle processor__ = 0;
	CDotNetHandle data__ = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: processor
	__errChk(Alv_NarrowBand_NBProtocol_Processor__Create(
		&processor, 
		&processor__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+Processor";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &processor__;

	// Pre-process parameter: data
	if (data)
		__errChk(CDotNetCreateArray(
			CDOTNET_BYTE, 
			1, 
			0, 
			&__dataLength, 
			data, 
			&data__));
	__parameterTypeNames[1] = "System.Byte[]";
	__parameterTypes[1] = (CDOTNET_BYTE | CDOTNET_ARRAY);
	__parameters[1] = &data__;

	// Pre-process parameter: address
	__parameterTypeNames[2] = "System.UInt32";
	__parameterTypes[2] = (CDOTNET_UINT32);
	__parameters[2] = &address;

	// Pre-process parameter: checksum
	__parameterTypeNames[3] = "System.Byte";
	__parameterTypes[3] = (CDOTNET_BYTE);
	__parameters[3] = &checksum;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.SensorComm", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"SendProgram", 
		0, 
		0, 
		4, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (processor__)
		CDotNetDiscardHandle(processor__);
	if (data__)
		CDotNetDiscardHandle(data__);
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_NarrowBand_SensorComm_SendEnd(
	Alv_NarrowBand_SensorComm __instance,
	Alv_NarrowBand_NBProtocol_Processor processor,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle processor__ = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: processor
	__errChk(Alv_NarrowBand_NBProtocol_Processor__Create(
		&processor, 
		&processor__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+Processor";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &processor__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.SensorComm", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"SendEnd", 
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
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (processor__)
		CDotNetDiscardHandle(processor__);
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_NarrowBand_SensorComm_Program(
	Alv_NarrowBand_SensorComm __instance,
	char * filepath,
	Alv_NarrowBand_NBProtocol_Processor processor,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[2] = {0};
	unsigned int __parameterTypes[2];
	void * __parameters[2];
	CDotNetHandle processor__ = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: filepath
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &filepath;

	// Pre-process parameter: processor
	__errChk(Alv_NarrowBand_NBProtocol_Processor__Create(
		&processor, 
		&processor__, 
		__exception));
	__parameterTypeNames[1] = "Alv.NarrowBand.NBProtocol+Processor";
	__parameterTypes[1] = (CDOTNET_ENUM);
	__parameters[1] = &processor__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.SensorComm", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Program", 
		0, 
		0, 
		2, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (processor__)
		CDotNetDiscardHandle(processor__);
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_NarrowBand_SensorComm_ErrorManager(
	Alv_NarrowBand_SensorComm __instance,
	Alv_NarrowBand_NBProtocol_ControlError selection,
	unsigned int code,
	unsigned int timeout,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];
	CDotNetHandle selection__ = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: selection
	__errChk(Alv_NarrowBand_NBProtocol_ControlError__Create(
		&selection, 
		&selection__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+ControlError";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &selection__;

	// Pre-process parameter: code
	__parameterTypeNames[1] = "System.UInt32";
	__parameterTypes[1] = (CDOTNET_UINT32);
	__parameters[1] = &code;

	// Pre-process parameter: timeout
	__parameterTypeNames[2] = "System.UInt32";
	__parameterTypes[2] = (CDOTNET_UINT32);
	__parameters[2] = &timeout;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.SensorComm", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ErrorManager", 
		0, 
		0, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (selection__)
		CDotNetDiscardHandle(selection__);
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_NarrowBand_SensorComm_LoggerControl(
	Alv_NarrowBand_SensorComm __instance,
	Alv_NarrowBand_NBProtocol_LoggerID logger,
	Alv_NarrowBand_NBProtocol_ControlLogger selection,
	unsigned int control,
	Alv_NarrowBand_NBProtocol_Status * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[3] = {0};
	unsigned int __parameterTypes[3];
	void * __parameters[3];
	CDotNetHandle logger__ = 0;
	CDotNetHandle selection__ = 0;
	CDotNetHandle __returnValue__ = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: logger
	__errChk(Alv_NarrowBand_NBProtocol_LoggerID__Create(
		&logger, 
		&logger__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+LoggerID";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &logger__;

	// Pre-process parameter: selection
	__errChk(Alv_NarrowBand_NBProtocol_ControlLogger__Create(
		&selection, 
		&selection__, 
		__exception));
	__parameterTypeNames[1] = "Alv.NarrowBand.NBProtocol+ControlLogger";
	__parameterTypes[1] = (CDOTNET_ENUM);
	__parameters[1] = &selection__;

	// Pre-process parameter: control
	__parameterTypeNames[2] = "System.UInt32";
	__parameterTypes[2] = (CDOTNET_UINT32);
	__parameters[2] = &control;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_ENUM;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.SensorComm", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"LoggerControl", 
		0, 
		0, 
		3, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		&__returnValueTypeId, 
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue)
		__errChk(CDotNetGetEnumValue(
			__returnValue__, 
			__returnValue));


__Error:
	if (logger__)
		CDotNetDiscardHandle(logger__);
	if (selection__)
		CDotNetDiscardHandle(selection__);
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	return __error;
}

int CVIFUNC Alv_NarrowBand_SensorComm_ReadDspDiag(
	Alv_NarrowBand_SensorComm __instance,
	Alv_NarrowBand_DSP_DIAG * Msg,
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
	*Msg = 0;


	// Pre-process parameter: Msg
	__parameterTypeNames[0] = "Alv.NarrowBand.DSP_DIAG&";
	__parameterTypes[0] = (CDOTNET_OBJECT | CDOTNET_OUT);
	__parameters[0] = Msg;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.SensorComm", 
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
			Msg, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Alv_NarrowBand_SensorComm_ReadHpDiag(
	Alv_NarrowBand_SensorComm __instance,
	Alv_NarrowBand_HP_DIAG * Msg,
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
	*Msg = 0;


	// Pre-process parameter: Msg
	__parameterTypeNames[0] = "Alv.NarrowBand.HP_DIAG&";
	__parameterTypes[0] = (CDOTNET_OBJECT | CDOTNET_OUT);
	__parameters[0] = Msg;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.SensorComm", 
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
			Msg, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Alv_NarrowBand_SensorComm_ReadUntDat(
	Alv_NarrowBand_SensorComm __instance,
	Alv_NarrowBand_UNT_DAT * Msg,
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
	*Msg = 0;


	// Pre-process parameter: Msg
	__parameterTypeNames[0] = "Alv.NarrowBand.UNT_DAT&";
	__parameterTypes[0] = (CDOTNET_OBJECT | CDOTNET_OUT);
	__parameters[0] = Msg;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.SensorComm", 
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
			Msg, 
			CDOTNET_OBJECT);
	}
	return __error;
}

int CVIFUNC Alv_NarrowBand_SensorComm_ClearQueue(
	Alv_NarrowBand_SensorComm __instance,
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
		"Alv.NarrowBand.SensorComm", 
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

int CVIFUNC Alv_NarrowBand_SensorComm_SendVehicleSpeed(
	Alv_NarrowBand_SensorComm __instance,
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
		"Alv.NarrowBand.SensorComm", 
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

int CVIFUNC Alv_NarrowBand_SensorComm_SendGearPosition(
	Alv_NarrowBand_SensorComm __instance,
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
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+GearPosition";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &gear__;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.SensorComm", 
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


// Type: Alv.CAN.CanMsg
int CVIFUNC Alv_CAN_CanMsg__Create(
	Alv_CAN_CanMsg * __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"Alv.CAN.CanMsg", 
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

int CVIFUNC Alv_CAN_CanMsg__Get__ID(
	Alv_CAN_CanMsg __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_UINT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.CAN.CanMsg", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"ID", 
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

int CVIFUNC Alv_CAN_CanMsg__Set__ID(
	Alv_CAN_CanMsg __instance,
	unsigned int ID,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: ID
	__parameterTypeNames[0] = "System.UInt32";
	__parameterTypes[0] = (CDOTNET_UINT32);
	__parameters[0] = &ID;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.CAN.CanMsg", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"ID", 
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

int CVIFUNC Alv_CAN_CanMsg__Get__Len(
	Alv_CAN_CanMsg __instance,
	unsigned char * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BYTE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.CAN.CanMsg", 
		__instance, 
		CDOTNET_GET_FIELD, 
		"Len", 
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

int CVIFUNC Alv_CAN_CanMsg__Set__Len(
	Alv_CAN_CanMsg __instance,
	unsigned char Len,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: Len
	__parameterTypeNames[0] = "System.Byte";
	__parameterTypes[0] = (CDOTNET_BYTE);
	__parameters[0] = &Len;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.CAN.CanMsg", 
		__instance, 
		CDOTNET_SET_FIELD, 
		"Len", 
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

int CVIFUNC Alv_CAN_CanMsg__Get__Data(
	Alv_CAN_CanMsg __instance,
	unsigned char ** __returnValue,
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
	__returnValueTypeId = CDOTNET_BYTE | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.CAN.CanMsg", 
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
		&__returnValue__, 
		__exception));

	// Post-process return value
	if (__returnValue__) {
		if (__returnValue)
			__errChk(CDotNetGetArrayElements(
				__returnValue__, 
				CDOTNET_BYTE, 
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
			CDOTNET_BYTE, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC Alv_CAN_CanMsg__Set__Data(
	Alv_CAN_CanMsg __instance,
	unsigned char * Data,
	ssize_t __DataLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle Data__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: Data
	if (Data)
		__errChk(CDotNetCreateArray(
			CDOTNET_BYTE, 
			1, 
			0, 
			&__DataLength, 
			Data, 
			&Data__));
	__parameterTypeNames[0] = "System.Byte[]";
	__parameterTypes[0] = (CDOTNET_BYTE | CDOTNET_ARRAY);
	__parameters[0] = &Data__;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.CAN.CanMsg", 
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
	if (Data__)
		CDotNetDiscardHandle(Data__);
	return __error;
}


// Type: Alv.CAN.NiCan
int CVIFUNC Alv_CAN_NiCan__Create(
	Alv_CAN_NiCan * __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"Alv.CAN.NiCan", 
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

int CVIFUNC Alv_CAN_NiCan_Get_DeviceType(
	Alv_CAN_NiCan __instance,
	Alv_CAN_CanDevices * __returnValue,
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
		"Alv.CAN.NiCan", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"DeviceType", 
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

int CVIFUNC Alv_CAN_NiCan_Get_BusMode(
	Alv_CAN_NiCan __instance,
	Alv_CAN_CanBusModes * __returnValue,
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
		"Alv.CAN.NiCan", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"BusMode", 
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

int CVIFUNC Alv_CAN_NiCan_Set_BusMode(
	Alv_CAN_NiCan __instance,
	Alv_CAN_CanBusModes value,
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
	__errChk(Alv_CAN_CanBusModes__Create(
		&value, 
		&value__, 
		__exception));
	__parameterTypeNames[0] = "Alv.CAN.CanBusModes";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &value__;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.CAN.NiCan", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"BusMode", 
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

int CVIFUNC Alv_CAN_NiCan_Get_WakeupMode(
	Alv_CAN_NiCan __instance,
	Alv_CAN_CanWakeupModes * __returnValue,
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
		"Alv.CAN.NiCan", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"WakeupMode", 
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

int CVIFUNC Alv_CAN_NiCan_Set_WakeupMode(
	Alv_CAN_NiCan __instance,
	Alv_CAN_CanWakeupModes value,
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
	__errChk(Alv_CAN_CanWakeupModes__Create(
		&value, 
		&value__, 
		__exception));
	__parameterTypeNames[0] = "Alv.CAN.CanWakeupModes";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &value__;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.CAN.NiCan", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"WakeupMode", 
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

int CVIFUNC Alv_CAN_NiCan_Get_BaudRate(
	Alv_CAN_NiCan __instance,
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
		"Alv.CAN.NiCan", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"BaudRate", 
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

int CVIFUNC Alv_CAN_NiCan_Set_BaudRate(
	Alv_CAN_NiCan __instance,
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
		"Alv.CAN.NiCan", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"BaudRate", 
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

int CVIFUNC Alv_CAN_NiCan_Get_DriverID(
	Alv_CAN_NiCan __instance,
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
		"Alv.CAN.NiCan", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"DriverID", 
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

int CVIFUNC Alv_CAN_NiCan_Set_DriverID(
	Alv_CAN_NiCan __instance,
	char * value,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: value
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &value;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.CAN.NiCan", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"DriverID", 
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

int CVIFUNC Alv_CAN_NiCan_Get_ClientID(
	Alv_CAN_NiCan __instance,
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
		"Alv.CAN.NiCan", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"ClientID", 
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

int CVIFUNC Alv_CAN_NiCan_Set_ClientID(
	Alv_CAN_NiCan __instance,
	char * value,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: value
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &value;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.CAN.NiCan", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"ClientID", 
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

int CVIFUNC Alv_CAN_NiCan_Get_ReadTimeout(
	Alv_CAN_NiCan __instance,
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
		"Alv.CAN.NiCan", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"ReadTimeout", 
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

int CVIFUNC Alv_CAN_NiCan_Set_ReadTimeout(
	Alv_CAN_NiCan __instance,
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
		"Alv.CAN.NiCan", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"ReadTimeout", 
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

int CVIFUNC Alv_CAN_NiCan_Get_WriteTimeout(
	Alv_CAN_NiCan __instance,
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
		"Alv.CAN.NiCan", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"WriteTimeout", 
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

int CVIFUNC Alv_CAN_NiCan_Set_WriteTimeout(
	Alv_CAN_NiCan __instance,
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
		"Alv.CAN.NiCan", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"WriteTimeout", 
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

int CVIFUNC Alv_CAN_NiCan_Get_Error(
	Alv_CAN_NiCan __instance,
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
		"Alv.CAN.NiCan", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Error", 
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

int CVIFUNC Alv_CAN_NiCan_Connect(
	Alv_CAN_NiCan __instance,
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
		"Alv.CAN.NiCan", 
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

int CVIFUNC Alv_CAN_NiCan_Disconnect(
	Alv_CAN_NiCan __instance,
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
		"Alv.CAN.NiCan", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Disconnect", 
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

int CVIFUNC Alv_CAN_NiCan_Clear(
	Alv_CAN_NiCan __instance,
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
		"Alv.CAN.NiCan", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Clear", 
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

int CVIFUNC Alv_CAN_NiCan_Read(
	Alv_CAN_NiCan __instance,
	Alv_CAN_CanMsg * msg,
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


	// Pre-process parameter: msg
	__parameterTypeNames[0] = "Alv.CAN.CanMsg&";
	__parameterTypes[0] = (CDOTNET_STRUCT | CDOTNET_REF);
	__parameters[0] = msg;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.CAN.NiCan", 
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
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			msg, 
			CDOTNET_STRUCT);
	}
	return __error;
}

int CVIFUNC Alv_CAN_NiCan_Write(
	Alv_CAN_NiCan __instance,
	Alv_CAN_CanMsg * msg,
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


	// Pre-process parameter: msg
	__parameterTypeNames[0] = "Alv.CAN.CanMsg&";
	__parameterTypes[0] = (CDOTNET_STRUCT | CDOTNET_REF);
	__parameters[0] = msg;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.CAN.NiCan", 
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
			msg, 
			CDOTNET_STRUCT);
	}
	return __error;
}


// Type: Alv.NarrowBand.HP_DIAG
int CVIFUNC Alv_NarrowBand_HP_DIAG__Create(
	Alv_NarrowBand_HP_DIAG * __instance,
	unsigned char * Data,
	ssize_t __DataLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle Data__ = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: Data
	if (Data)
		__errChk(CDotNetCreateArray(
			CDOTNET_BYTE, 
			1, 
			0, 
			&__DataLength, 
			Data, 
			&Data__));
	__parameterTypeNames[0] = "System.Byte[]";
	__parameterTypes[0] = (CDOTNET_BYTE | CDOTNET_ARRAY);
	__parameters[0] = &Data__;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"Alv.NarrowBand.HP_DIAG", 
		0, 
		0, 
		__instance, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	if (Data__)
		CDotNetDiscardHandle(Data__);
	return __error;
}

int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_HP_State(
	Alv_NarrowBand_HP_DIAG __instance,
	Alv_NarrowBand_HP_DIAG_HP_States * __returnValue,
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
		"Alv.NarrowBand.HP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"HP_State", 
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

int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_Toggle_Flag(
	Alv_NarrowBand_HP_DIAG __instance,
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
		"Alv.NarrowBand.HP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Toggle_Flag", 
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

int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_Processor_Run_Mode(
	Alv_NarrowBand_HP_DIAG __instance,
	Alv_NarrowBand_HP_DIAG_HP_Run_Modes * __returnValue,
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
		"Alv.NarrowBand.HP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Processor_Run_Mode", 
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

int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_Expected_DSP_State(
	Alv_NarrowBand_HP_DIAG __instance,
	Alv_NarrowBand_HP_DIAG_DSP_States * __returnValue,
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
		"Alv.NarrowBand.HP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Expected_DSP_State", 
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

int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_OEM_INCOMPATIBLE(
	Alv_NarrowBand_HP_DIAG __instance,
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
		"Alv.NarrowBand.HP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"ERR_U8_OEM_INCOMPATIBLE", 
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

int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_LOST_DSP_INFO_MESSAGE(
	Alv_NarrowBand_HP_DIAG __instance,
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
		"Alv.NarrowBand.HP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"ERR_U8_LOST_DSP_INFO_MESSAGE", 
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

int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_LOST_DSP_BSD_MESSAGE(
	Alv_NarrowBand_HP_DIAG __instance,
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
		"Alv.NarrowBand.HP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"ERR_U8_LOST_DSP_BSD_MESSAGE", 
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

int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_LOST_DSP_RCTA_MESSAGE(
	Alv_NarrowBand_HP_DIAG __instance,
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
		"Alv.NarrowBand.HP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"ERR_U8_LOST_DSP_RCTA_MESSAGE", 
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

int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_HIGH_33_VOLT(
	Alv_NarrowBand_HP_DIAG __instance,
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
		"Alv.NarrowBand.HP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"ERR_U8_HIGH_33_VOLT", 
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

int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_LOW_33_VOLT(
	Alv_NarrowBand_HP_DIAG __instance,
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
		"Alv.NarrowBand.HP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"ERR_U8_LOW_33_VOLT", 
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

int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_HIGH_19_VOLT(
	Alv_NarrowBand_HP_DIAG __instance,
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
		"Alv.NarrowBand.HP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"ERR_U8_HIGH_19_VOLT", 
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

int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_LOW_19_VOLT(
	Alv_NarrowBand_HP_DIAG __instance,
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
		"Alv.NarrowBand.HP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"ERR_U8_LOW_19_VOLT", 
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

int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_DIAG_VIN_MISMATCH(
	Alv_NarrowBand_HP_DIAG __instance,
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
		"Alv.NarrowBand.HP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"ERR_U8_DIAG_VIN_MISMATCH", 
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

int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_TEST_ROM_INIT_FAULT(
	Alv_NarrowBand_HP_DIAG __instance,
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
		"Alv.NarrowBand.HP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"ERR_U8_TEST_ROM_INIT_FAULT", 
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

int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_TEST_ROM_FAULT(
	Alv_NarrowBand_HP_DIAG __instance,
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
		"Alv.NarrowBand.HP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"ERR_U8_TEST_ROM_FAULT", 
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

int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_TEST_SENSOR_ADDRESS_UNSTABLE(
	Alv_NarrowBand_HP_DIAG __instance,
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
		"Alv.NarrowBand.HP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"ERR_U8_TEST_SENSOR_ADDRESS_UNSTABLE", 
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

int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_RESET_INTERNAL_WATCHDOG_TIMEOUT(
	Alv_NarrowBand_HP_DIAG __instance,
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
		"Alv.NarrowBand.HP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"ERR_U8_RESET_INTERNAL_WATCHDOG_TIMEOUT", 
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

int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_RESET_TASK_WATCHDOG_TIMEOUT(
	Alv_NarrowBand_HP_DIAG __instance,
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
		"Alv.NarrowBand.HP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"ERR_U8_RESET_TASK_WATCHDOG_TIMEOUT", 
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

int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_RESET_OS_ERROR(
	Alv_NarrowBand_HP_DIAG __instance,
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
		"Alv.NarrowBand.HP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"ERR_U8_RESET_OS_ERROR", 
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

int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_RESET_UNEXPECTED_EXCEPTION(
	Alv_NarrowBand_HP_DIAG __instance,
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
		"Alv.NarrowBand.HP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"ERR_U8_RESET_UNEXPECTED_EXCEPTION", 
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

int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_NCA_LOST_COMM_SBZA_L(
	Alv_NarrowBand_HP_DIAG __instance,
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
		"Alv.NarrowBand.HP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"ERR_U8_NCA_LOST_COMM_SBZA_L", 
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

int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_NCA_LOST_COMM_SBZA_R(
	Alv_NarrowBand_HP_DIAG __instance,
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
		"Alv.NarrowBand.HP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"ERR_U8_NCA_LOST_COMM_SBZA_R", 
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

int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_NCA_LOST_COMM_EOCM(
	Alv_NarrowBand_HP_DIAG __instance,
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
		"Alv.NarrowBand.HP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"ERR_U8_NCA_LOST_COMM_EOCM", 
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

int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_EEP_CAL_NOT_PROGRAMMED(
	Alv_NarrowBand_HP_DIAG __instance,
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
		"Alv.NarrowBand.HP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"ERR_U8_EEP_CAL_NOT_PROGRAMMED", 
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

int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_EEP_OUT_OF_ORDER(
	Alv_NarrowBand_HP_DIAG __instance,
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
		"Alv.NarrowBand.HP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"ERR_U8_EEP_OUT_OF_ORDER", 
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

int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_EEP_CORRUPTED(
	Alv_NarrowBand_HP_DIAG __instance,
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
		"Alv.NarrowBand.HP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"ERR_U8_EEP_CORRUPTED", 
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

int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_EEP_INCOMPATIBLE(
	Alv_NarrowBand_HP_DIAG __instance,
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
		"Alv.NarrowBand.HP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"ERR_U8_EEP_INCOMPATIBLE", 
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

int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_EEP_NOT_PROGRAMMED(
	Alv_NarrowBand_HP_DIAG __instance,
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
		"Alv.NarrowBand.HP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"ERR_U8_EEP_NOT_PROGRAMMED", 
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

int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_NCA_BUS_OFF(
	Alv_NarrowBand_HP_DIAG __instance,
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
		"Alv.NarrowBand.HP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"ERR_U8_NCA_BUS_OFF", 
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

int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_NCA_LOST_COMM_BCM(
	Alv_NarrowBand_HP_DIAG __instance,
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
		"Alv.NarrowBand.HP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"ERR_U8_NCA_LOST_COMM_BCM", 
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

int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_NCA_LOST_COMM_IPC(
	Alv_NarrowBand_HP_DIAG __instance,
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
		"Alv.NarrowBand.HP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"ERR_U8_NCA_LOST_COMM_IPC", 
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

int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_NCA_LOST_COMM_HUD(
	Alv_NarrowBand_HP_DIAG __instance,
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
		"Alv.NarrowBand.HP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"ERR_U8_NCA_LOST_COMM_HUD", 
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

int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_NCA_LOST_COMM_APA(
	Alv_NarrowBand_HP_DIAG __instance,
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
		"Alv.NarrowBand.HP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"ERR_U8_NCA_LOST_COMM_APA", 
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

int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_NCA_LOST_COMM_RADIO(
	Alv_NarrowBand_HP_DIAG __instance,
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
		"Alv.NarrowBand.HP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"ERR_U8_NCA_LOST_COMM_RADIO", 
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

int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_NCA_LOST_COMM_ONSTAR(
	Alv_NarrowBand_HP_DIAG __instance,
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
		"Alv.NarrowBand.HP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"ERR_U8_NCA_LOST_COMM_ONSTAR", 
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

int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_NCA_LOST_COMM_MSM(
	Alv_NarrowBand_HP_DIAG __instance,
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
		"Alv.NarrowBand.HP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"ERR_U8_NCA_LOST_COMM_MSM", 
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

int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_IPC_BUS_OFF(
	Alv_NarrowBand_HP_DIAG __instance,
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
		"Alv.NarrowBand.HP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"ERR_U8_IPC_BUS_OFF", 
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

int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_LOST_DSP_MESSAGE(
	Alv_NarrowBand_HP_DIAG __instance,
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
		"Alv.NarrowBand.HP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"ERR_U8_LOST_DSP_MESSAGE", 
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

int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_TEST_VOLT_BELOW_THRESHOLD(
	Alv_NarrowBand_HP_DIAG __instance,
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
		"Alv.NarrowBand.HP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"ERR_U8_TEST_VOLT_BELOW_THRESHOLD", 
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

int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_TEST_VOLT_ABOVE_THRESHOLD(
	Alv_NarrowBand_HP_DIAG __instance,
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
		"Alv.NarrowBand.HP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"ERR_U8_TEST_VOLT_ABOVE_THRESHOLD", 
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

int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_LED_SHORT_TO_BATT(
	Alv_NarrowBand_HP_DIAG __instance,
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
		"Alv.NarrowBand.HP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"ERR_U8_LED_SHORT_TO_BATT", 
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

int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_LED_SHORT_TO_GROUND(
	Alv_NarrowBand_HP_DIAG __instance,
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
		"Alv.NarrowBand.HP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"ERR_U8_LED_SHORT_TO_GROUND", 
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

int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_LED_OPEN_CIRCUIT(
	Alv_NarrowBand_HP_DIAG __instance,
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
		"Alv.NarrowBand.HP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"ERR_U8_LED_OPEN_CIRCUIT", 
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

int CVIFUNC Alv_NarrowBand_HP_DIAG_Get_ERR_U8_NCA_INACTIVE_NODE(
	Alv_NarrowBand_HP_DIAG __instance,
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
		"Alv.NarrowBand.HP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"ERR_U8_NCA_INACTIVE_NODE", 
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


// Type: Alv.NarrowBand.UNT_DAT
int CVIFUNC Alv_NarrowBand_UNT_DAT__Create(
	Alv_NarrowBand_UNT_DAT * __instance,
	unsigned char * Data,
	ssize_t __DataLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle Data__ = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: Data
	if (Data)
		__errChk(CDotNetCreateArray(
			CDOTNET_BYTE, 
			1, 
			0, 
			&__DataLength, 
			Data, 
			&Data__));
	__parameterTypeNames[0] = "System.Byte[]";
	__parameterTypes[0] = (CDOTNET_BYTE | CDOTNET_ARRAY);
	__parameters[0] = &Data__;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"Alv.NarrowBand.UNT_DAT", 
		0, 
		0, 
		__instance, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	if (Data__)
		CDotNetDiscardHandle(Data__);
	return __error;
}

int CVIFUNC Alv_NarrowBand_UNT_DAT_Get_Object_ID(
	Alv_NarrowBand_UNT_DAT __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_UINT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.UNT_DAT", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Object_ID", 
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

int CVIFUNC Alv_NarrowBand_UNT_DAT_Get_Squinted_Beam_Antenna_Detection(
	Alv_NarrowBand_UNT_DAT __instance,
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
		"Alv.NarrowBand.UNT_DAT", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Squinted_Beam_Antenna_Detection", 
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

int CVIFUNC Alv_NarrowBand_UNT_DAT_Get_Normal_Beam_Antenna_Detection(
	Alv_NarrowBand_UNT_DAT __instance,
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
		"Alv.NarrowBand.UNT_DAT", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Normal_Beam_Antenna_Detection", 
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

int CVIFUNC Alv_NarrowBand_UNT_DAT_Get_Relative_Distance(
	Alv_NarrowBand_UNT_DAT __instance,
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
		"Alv.NarrowBand.UNT_DAT", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Relative_Distance", 
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

int CVIFUNC Alv_NarrowBand_UNT_DAT_Get_Relative_Speed(
	Alv_NarrowBand_UNT_DAT __instance,
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
		"Alv.NarrowBand.UNT_DAT", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Relative_Speed", 
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

int CVIFUNC Alv_NarrowBand_UNT_DAT_Get_Azimuth(
	Alv_NarrowBand_UNT_DAT __instance,
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
		"Alv.NarrowBand.UNT_DAT", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Azimuth", 
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

int CVIFUNC Alv_NarrowBand_UNT_DAT_Get_Doppler_Data_SNR(
	Alv_NarrowBand_UNT_DAT __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_UINT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.UNT_DAT", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Doppler_Data_SNR", 
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

int CVIFUNC Alv_NarrowBand_UNT_DAT_Get_Sensor_Mode(
	Alv_NarrowBand_UNT_DAT __instance,
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
		"Alv.NarrowBand.UNT_DAT", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Sensor_Mode", 
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

int CVIFUNC Alv_NarrowBand_UNT_DAT_Get_Range_Data_SNR(
	Alv_NarrowBand_UNT_DAT __instance,
	unsigned int * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_UINT32;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.UNT_DAT", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Range_Data_SNR", 
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

int CVIFUNC Alv_NarrowBand_UNT_DAT_ToString(
	Alv_NarrowBand_UNT_DAT __instance,
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
		"Alv.NarrowBand.UNT_DAT", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ToString", 
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

int CVIFUNC Alv_NarrowBand_UNT_DAT_Header(
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

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.NarrowBand.UNT_DAT", 
		0, 
		0, 
		CDOTNET_CALL_METHOD, 
		"Header", 
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


// Type: Alv.NarrowBand.NBProtocol
int CVIFUNC Alv_NarrowBand_NBProtocol__Get__UNDEF(
	unsigned short * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_UINT16;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.NarrowBand.NBProtocol", 
		0, 
		0, 
		CDOTNET_GET_FIELD, 
		"UNDEF", 
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

int CVIFUNC Alv_NarrowBand_NBProtocol__Set__UNDEF(
	unsigned short UNDEF,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: UNDEF
	__parameterTypeNames[0] = "System.UInt16";
	__parameterTypes[0] = (CDOTNET_UINT16);
	__parameters[0] = &UNDEF;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.NarrowBand.NBProtocol", 
		0, 
		0, 
		CDOTNET_SET_FIELD, 
		"UNDEF", 
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

int CVIFUNC Alv_NarrowBand_NBProtocol__Get__RX_CAN_ID(
	unsigned short ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
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
		*____returnValueLength1 = 0;
	if (__returnValue)
		*____returnValueLength2 = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_UINT16 | CDOTNET_ARRAY;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.NarrowBand.NBProtocol", 
		0, 
		0, 
		CDOTNET_GET_FIELD, 
		"RX_CAN_ID", 
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
				CDOTNET_UINT16, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength1));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				1, 
				____returnValueLength2));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_UINT16, 
			2, 
			____returnValueLength1, 
			____returnValueLength2);
	}
	return __error;
}

int CVIFUNC Alv_NarrowBand_NBProtocol__Set__RX_CAN_ID(
	unsigned short * RX_CAN_ID,
	ssize_t __RX_CAN_IDLength1,
	ssize_t __RX_CAN_IDLength2,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle RX_CAN_ID__ = 0;
	ssize_t __RX_CAN_IDLengths[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: RX_CAN_ID
	__RX_CAN_IDLengths[0] = __RX_CAN_IDLength1;
	__RX_CAN_IDLengths[1] = __RX_CAN_IDLength2;
	if (RX_CAN_ID)
		__errChk(CDotNetCreateArray(
			CDOTNET_UINT16, 
			2, 
			0, 
			__RX_CAN_IDLengths, 
			RX_CAN_ID, 
			&RX_CAN_ID__));
	__parameterTypeNames[0] = "System.UInt16[,]";
	__parameterTypes[0] = (CDOTNET_UINT16 | CDOTNET_ARRAY);
	__parameters[0] = &RX_CAN_ID__;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.NarrowBand.NBProtocol", 
		0, 
		0, 
		CDOTNET_SET_FIELD, 
		"RX_CAN_ID", 
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
	if (RX_CAN_ID__)
		CDotNetDiscardHandle(RX_CAN_ID__);
	return __error;
}

int CVIFUNC Alv_NarrowBand_NBProtocol__Get__TX_CAN_ID(
	unsigned short ** __returnValue,
	ssize_t * ____returnValueLength1,
	ssize_t * ____returnValueLength2,
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
		*____returnValueLength1 = 0;
	if (__returnValue)
		*____returnValueLength2 = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_UINT16 | CDOTNET_ARRAY;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.NarrowBand.NBProtocol", 
		0, 
		0, 
		CDOTNET_GET_FIELD, 
		"TX_CAN_ID", 
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
				CDOTNET_UINT16, 
				0, 
				__returnValue));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				0, 
				____returnValueLength1));
		if (__returnValue)
			__errChk(CDotNetGetArrayLength(
				__returnValue__, 
				1, 
				____returnValueLength2));
	}


__Error:
	if (__returnValue__)
		CDotNetDiscardHandle(__returnValue__);
	if (__error < 0) {
		_CDotNetGenDisposeArray(
			__returnValue, 
			CDOTNET_UINT16, 
			2, 
			____returnValueLength1, 
			____returnValueLength2);
	}
	return __error;
}

int CVIFUNC Alv_NarrowBand_NBProtocol__Set__TX_CAN_ID(
	unsigned short * TX_CAN_ID,
	ssize_t __TX_CAN_IDLength1,
	ssize_t __TX_CAN_IDLength2,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle TX_CAN_ID__ = 0;
	ssize_t __TX_CAN_IDLengths[2];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: TX_CAN_ID
	__TX_CAN_IDLengths[0] = __TX_CAN_IDLength1;
	__TX_CAN_IDLengths[1] = __TX_CAN_IDLength2;
	if (TX_CAN_ID)
		__errChk(CDotNetCreateArray(
			CDOTNET_UINT16, 
			2, 
			0, 
			__TX_CAN_IDLengths, 
			TX_CAN_ID, 
			&TX_CAN_ID__));
	__parameterTypeNames[0] = "System.UInt16[,]";
	__parameterTypes[0] = (CDOTNET_UINT16 | CDOTNET_ARRAY);
	__parameters[0] = &TX_CAN_ID__;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.NarrowBand.NBProtocol", 
		0, 
		0, 
		CDOTNET_SET_FIELD, 
		"TX_CAN_ID", 
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
	if (TX_CAN_ID__)
		CDotNetDiscardHandle(TX_CAN_ID__);
	return __error;
}

int CVIFUNC Alv_NarrowBand_NBProtocol__Get__U(
	unsigned char * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_BYTE;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.NarrowBand.NBProtocol", 
		0, 
		0, 
		CDOTNET_GET_FIELD, 
		"U", 
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

int CVIFUNC Alv_NarrowBand_NBProtocol__Set__U(
	unsigned char U,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: U
	__parameterTypeNames[0] = "System.Byte";
	__parameterTypes[0] = (CDOTNET_BYTE);
	__parameters[0] = &U;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.NarrowBand.NBProtocol", 
		0, 
		0, 
		CDOTNET_SET_FIELD, 
		"U", 
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

int CVIFUNC Alv_NarrowBand_NBProtocol__Get__RX_CAN_LEN(
	unsigned char ** __returnValue,
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
	__returnValueTypeId = CDOTNET_BYTE | CDOTNET_ARRAY;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.NarrowBand.NBProtocol", 
		0, 
		0, 
		CDOTNET_GET_FIELD, 
		"RX_CAN_LEN", 
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
				CDOTNET_BYTE, 
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
			CDOTNET_BYTE, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC Alv_NarrowBand_NBProtocol__Set__RX_CAN_LEN(
	unsigned char * RX_CAN_LEN,
	ssize_t __RX_CAN_LENLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle RX_CAN_LEN__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: RX_CAN_LEN
	if (RX_CAN_LEN)
		__errChk(CDotNetCreateArray(
			CDOTNET_BYTE, 
			1, 
			0, 
			&__RX_CAN_LENLength, 
			RX_CAN_LEN, 
			&RX_CAN_LEN__));
	__parameterTypeNames[0] = "System.Byte[]";
	__parameterTypes[0] = (CDOTNET_BYTE | CDOTNET_ARRAY);
	__parameters[0] = &RX_CAN_LEN__;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.NarrowBand.NBProtocol", 
		0, 
		0, 
		CDOTNET_SET_FIELD, 
		"RX_CAN_LEN", 
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
	if (RX_CAN_LEN__)
		CDotNetDiscardHandle(RX_CAN_LEN__);
	return __error;
}

int CVIFUNC Alv_NarrowBand_NBProtocol__Get__TX_CAN_LEN(
	unsigned char ** __returnValue,
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
	__returnValueTypeId = CDOTNET_BYTE | CDOTNET_ARRAY;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.NarrowBand.NBProtocol", 
		0, 
		0, 
		CDOTNET_GET_FIELD, 
		"TX_CAN_LEN", 
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
				CDOTNET_BYTE, 
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
			CDOTNET_BYTE, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC Alv_NarrowBand_NBProtocol__Set__TX_CAN_LEN(
	unsigned char * TX_CAN_LEN,
	ssize_t __TX_CAN_LENLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle TX_CAN_LEN__ = 0;

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: TX_CAN_LEN
	if (TX_CAN_LEN)
		__errChk(CDotNetCreateArray(
			CDOTNET_BYTE, 
			1, 
			0, 
			&__TX_CAN_LENLength, 
			TX_CAN_LEN, 
			&TX_CAN_LEN__));
	__parameterTypeNames[0] = "System.Byte[]";
	__parameterTypes[0] = (CDOTNET_BYTE | CDOTNET_ARRAY);
	__parameters[0] = &TX_CAN_LEN__;

	// Call static member
	__errChk(CDotNetInvokeGenericStaticMember(
		__assemblyHandle, 
		"Alv.NarrowBand.NBProtocol", 
		0, 
		0, 
		CDOTNET_SET_FIELD, 
		"TX_CAN_LEN", 
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
	if (TX_CAN_LEN__)
		CDotNetDiscardHandle(TX_CAN_LEN__);
	return __error;
}


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
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[17] = {0};
	unsigned int __parameterTypes[17];
	void * __parameters[17];
	CDotNetHandle type__ = 0;
	CDotNetHandle format__ = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: name
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &name;

	// Pre-process parameter: point
	__parameterTypeNames[1] = "System.UInt16";
	__parameterTypes[1] = (CDOTNET_UINT16);
	__parameters[1] = &point;

	// Pre-process parameter: type
	__errChk(Alv_NarrowBand_PointTypes__Create(
		&type, 
		&type__, 
		__exception));
	__parameterTypeNames[2] = "Alv.NarrowBand.PointTypes";
	__parameterTypes[2] = (CDOTNET_ENUM);
	__parameters[2] = &type__;

	// Pre-process parameter: associated
	__parameterTypeNames[3] = "System.UInt16";
	__parameterTypes[3] = (CDOTNET_UINT16);
	__parameters[3] = &associated;

	// Pre-process parameter: scaling
	__parameterTypeNames[4] = "System.Single";
	__parameterTypes[4] = (CDOTNET_SINGLE);
	__parameters[4] = &scaling;

	// Pre-process parameter: category
	__parameterTypeNames[5] = "System.String";
	__parameterTypes[5] = (CDOTNET_STRING);
	__parameters[5] = &category;

	// Pre-process parameter: readOnly
	__parameterTypeNames[6] = "System.Boolean";
	__parameterTypes[6] = (CDOTNET_BOOLEAN);
	__parameters[6] = &readOnly;

	// Pre-process parameter: secure
	__parameterTypeNames[7] = "System.Boolean";
	__parameterTypes[7] = (CDOTNET_BOOLEAN);
	__parameters[7] = &secure;

	// Pre-process parameter: lower
	__parameterTypeNames[8] = "System.Single";
	__parameterTypes[8] = (CDOTNET_SINGLE);
	__parameters[8] = &lower;

	// Pre-process parameter: upper
	__parameterTypeNames[9] = "System.Single";
	__parameterTypes[9] = (CDOTNET_SINGLE);
	__parameters[9] = &upper;

	// Pre-process parameter: dynamic
	__parameterTypeNames[10] = "System.Boolean";
	__parameterTypes[10] = (CDOTNET_BOOLEAN);
	__parameters[10] = &dynamic;

	// Pre-process parameter: units
	__parameterTypeNames[11] = "System.String";
	__parameterTypes[11] = (CDOTNET_STRING);
	__parameters[11] = &units;

	// Pre-process parameter: enumtype
	__parameterTypeNames[12] = "System.String";
	__parameterTypes[12] = (CDOTNET_STRING);
	__parameters[12] = &enumtype;

	// Pre-process parameter: format
	__errChk(Alv_NarrowBand_PointFormats__Create(
		&format, 
		&format__, 
		__exception));
	__parameterTypeNames[13] = "Alv.NarrowBand.PointFormats";
	__parameterTypes[13] = (CDOTNET_ENUM);
	__parameters[13] = &format__;

	// Pre-process parameter: description
	__parameterTypeNames[14] = "System.String";
	__parameterTypes[14] = (CDOTNET_STRING);
	__parameters[14] = &description;

	// Pre-process parameter: calibration
	__parameterTypeNames[15] = "System.String";
	__parameterTypes[15] = (CDOTNET_STRING);
	__parameters[15] = &calibration;

	// Pre-process parameter: securitygroup
	__parameterTypeNames[16] = "System.UInt16";
	__parameterTypes[16] = (CDOTNET_UINT16);
	__parameters[16] = &securitygroup;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"Alv.NarrowBand.DataPoint", 
		0, 
		0, 
		__instance, 
		17, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	if (type__)
		CDotNetDiscardHandle(type__);
	if (format__)
		CDotNetDiscardHandle(format__);
	return __error;
}

int CVIFUNC Alv_NarrowBand_DataPoint_Get_Length(
	Alv_NarrowBand_DataPoint __instance,
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
		"Alv.NarrowBand.DataPoint", 
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

int CVIFUNC Alv_NarrowBand_DataPoint_Get_Name(
	Alv_NarrowBand_DataPoint __instance,
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
		"Alv.NarrowBand.DataPoint", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Name", 
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

int CVIFUNC Alv_NarrowBand_DataPoint_Get_Point(
	Alv_NarrowBand_DataPoint __instance,
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
		"Alv.NarrowBand.DataPoint", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Point", 
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

int CVIFUNC Alv_NarrowBand_DataPoint_Get_Type(
	Alv_NarrowBand_DataPoint __instance,
	Alv_NarrowBand_PointTypes * __returnValue,
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
		"Alv.NarrowBand.DataPoint", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Type", 
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

int CVIFUNC Alv_NarrowBand_DataPoint_Get_Associated(
	Alv_NarrowBand_DataPoint __instance,
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
		"Alv.NarrowBand.DataPoint", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Associated", 
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

int CVIFUNC Alv_NarrowBand_DataPoint_Get_Scaling(
	Alv_NarrowBand_DataPoint __instance,
	float * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_SINGLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.DataPoint", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Scaling", 
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

int CVIFUNC Alv_NarrowBand_DataPoint_Get_Category(
	Alv_NarrowBand_DataPoint __instance,
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
		"Alv.NarrowBand.DataPoint", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Category", 
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

int CVIFUNC Alv_NarrowBand_DataPoint_Get_ReadOnly(
	Alv_NarrowBand_DataPoint __instance,
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
		"Alv.NarrowBand.DataPoint", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"ReadOnly", 
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

int CVIFUNC Alv_NarrowBand_DataPoint_Get_Secure(
	Alv_NarrowBand_DataPoint __instance,
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
		"Alv.NarrowBand.DataPoint", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Secure", 
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

int CVIFUNC Alv_NarrowBand_DataPoint_Get_StillSecure(
	Alv_NarrowBand_DataPoint __instance,
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
		"Alv.NarrowBand.DataPoint", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"StillSecure", 
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

int CVIFUNC Alv_NarrowBand_DataPoint_Set_StillSecure(
	Alv_NarrowBand_DataPoint __instance,
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
		"Alv.NarrowBand.DataPoint", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"StillSecure", 
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

int CVIFUNC Alv_NarrowBand_DataPoint_Get_Lower(
	Alv_NarrowBand_DataPoint __instance,
	float * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_SINGLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.DataPoint", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Lower", 
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

int CVIFUNC Alv_NarrowBand_DataPoint_Get_Upper(
	Alv_NarrowBand_DataPoint __instance,
	float * __returnValue,
	CDotNetHandle * __exception)
{
	int __error = 0;
	unsigned int __returnValueTypeId;

	if (__exception)
		*__exception = 0;


	// Pre-process return value
	__returnValueTypeId = CDOTNET_SINGLE;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.DataPoint", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Upper", 
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

int CVIFUNC Alv_NarrowBand_DataPoint_Get_Dynamic(
	Alv_NarrowBand_DataPoint __instance,
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
		"Alv.NarrowBand.DataPoint", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Dynamic", 
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

int CVIFUNC Alv_NarrowBand_DataPoint_Set_Dynamic(
	Alv_NarrowBand_DataPoint __instance,
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
		"Alv.NarrowBand.DataPoint", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"Dynamic", 
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

int CVIFUNC Alv_NarrowBand_DataPoint_Get_Units(
	Alv_NarrowBand_DataPoint __instance,
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
		"Alv.NarrowBand.DataPoint", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Units", 
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

int CVIFUNC Alv_NarrowBand_DataPoint_Get_Format(
	Alv_NarrowBand_DataPoint __instance,
	Alv_NarrowBand_PointFormats * __returnValue,
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
		"Alv.NarrowBand.DataPoint", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Format", 
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

int CVIFUNC Alv_NarrowBand_DataPoint_Set_Format(
	Alv_NarrowBand_DataPoint __instance,
	Alv_NarrowBand_PointFormats value,
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
	__errChk(Alv_NarrowBand_PointFormats__Create(
		&value, 
		&value__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.PointFormats";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &value__;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.DataPoint", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"Format", 
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

int CVIFUNC Alv_NarrowBand_DataPoint_Get_FormatOriginal(
	Alv_NarrowBand_DataPoint __instance,
	Alv_NarrowBand_PointFormats * __returnValue,
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
		"Alv.NarrowBand.DataPoint", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"FormatOriginal", 
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

int CVIFUNC Alv_NarrowBand_DataPoint_Get_Description(
	Alv_NarrowBand_DataPoint __instance,
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
		"Alv.NarrowBand.DataPoint", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Description", 
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

int CVIFUNC Alv_NarrowBand_DataPoint_Get_Calibration(
	Alv_NarrowBand_DataPoint __instance,
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
		"Alv.NarrowBand.DataPoint", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Calibration", 
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

int CVIFUNC Alv_NarrowBand_DataPoint_Get_SecurityGroup(
	Alv_NarrowBand_DataPoint __instance,
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
		"Alv.NarrowBand.DataPoint", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"SecurityGroup", 
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

int CVIFUNC Alv_NarrowBand_DataPoint_Get_Enum(
	Alv_NarrowBand_DataPoint __instance,
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
		"Alv.NarrowBand.DataPoint", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Enum", 
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

int CVIFUNC Alv_NarrowBand_DataPoint_Get_Bytes(
	Alv_NarrowBand_DataPoint __instance,
	unsigned char ** __returnValue,
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
	__returnValueTypeId = CDOTNET_BYTE | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.DataPoint", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Bytes", 
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
				CDOTNET_BYTE, 
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
			CDOTNET_BYTE, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC Alv_NarrowBand_DataPoint_Set_Bytes(
	Alv_NarrowBand_DataPoint __instance,
	unsigned char * value,
	ssize_t __valueLength,
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
	if (value)
		__errChk(CDotNetCreateArray(
			CDOTNET_BYTE, 
			1, 
			0, 
			&__valueLength, 
			value, 
			&value__));
	__parameterTypeNames[0] = "System.Byte[]";
	__parameterTypes[0] = (CDOTNET_BYTE | CDOTNET_ARRAY);
	__parameters[0] = &value__;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.DataPoint", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"Bytes", 
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

int CVIFUNC Alv_NarrowBand_DataPoint_Get_DataDisplayStandard(
	Alv_NarrowBand_DataPoint __instance,
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
		"Alv.NarrowBand.DataPoint", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"DataDisplayStandard", 
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

int CVIFUNC Alv_NarrowBand_DataPoint_Get_Data(
	Alv_NarrowBand_DataPoint __instance,
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
		"Alv.NarrowBand.DataPoint", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
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
			CDOTNET_STRING);
	}
	return __error;
}

int CVIFUNC Alv_NarrowBand_DataPoint_Set_Data(
	Alv_NarrowBand_DataPoint __instance,
	char * value,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: value
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &value;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.DataPoint", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
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

int CVIFUNC Alv_NarrowBand_DataPoint_Get_Changed(
	Alv_NarrowBand_DataPoint __instance,
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
		"Alv.NarrowBand.DataPoint", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Changed", 
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

int CVIFUNC Alv_NarrowBand_DataPoint_Set_Changed(
	Alv_NarrowBand_DataPoint __instance,
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
		"Alv.NarrowBand.DataPoint", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"Changed", 
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

int CVIFUNC Alv_NarrowBand_DataPoint_Get_Status(
	Alv_NarrowBand_DataPoint __instance,
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
		"Alv.NarrowBand.DataPoint", 
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

int CVIFUNC Alv_NarrowBand_DataPoint_Set_Status(
	Alv_NarrowBand_DataPoint __instance,
	Alv_NarrowBand_NBProtocol_Status value,
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
	__errChk(Alv_NarrowBand_NBProtocol_Status__Create(
		&value, 
		&value__, 
		__exception));
	__parameterTypeNames[0] = "Alv.NarrowBand.NBProtocol+Status";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &value__;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.DataPoint", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"Status", 
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

int CVIFUNC Alv_NarrowBand_DataPoint_Get_EnumList(
	Alv_NarrowBand_DataPoint __instance,
	Alv_NarrowBand_Enumeration * __returnValue,
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
		"Alv.NarrowBand.DataPoint", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"EnumList", 
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

int CVIFUNC Alv_NarrowBand_DataPoint_Set_EnumList(
	Alv_NarrowBand_DataPoint __instance,
	Alv_NarrowBand_Enumeration value,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: value
	__parameterTypeNames[0] = "Alv.NarrowBand.Enumeration";
	__parameterTypes[0] = (CDOTNET_OBJECT);
	__parameters[0] = &value;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.DataPoint", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"EnumList", 
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

int CVIFUNC Alv_NarrowBand_DataPoint_Get_Row(
	Alv_NarrowBand_DataPoint __instance,
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
		"Alv.NarrowBand.DataPoint", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Row", 
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

int CVIFUNC Alv_NarrowBand_DataPoint_Set_Row(
	Alv_NarrowBand_DataPoint __instance,
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
		"Alv.NarrowBand.DataPoint", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"Row", 
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

int CVIFUNC Alv_NarrowBand_DataPoint_Get_Valid(
	Alv_NarrowBand_DataPoint __instance,
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
		"Alv.NarrowBand.DataPoint", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Valid", 
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

int CVIFUNC Alv_NarrowBand_DataPoint_Set_Valid(
	Alv_NarrowBand_DataPoint __instance,
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
		"Alv.NarrowBand.DataPoint", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"Valid", 
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

int CVIFUNC Alv_NarrowBand_DataPoint_DataBytes(
	Alv_NarrowBand_DataPoint __instance,
	char * newdata,
	unsigned char ** __returnValue,
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


	// Pre-process parameter: newdata
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &newdata;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BYTE | CDOTNET_ARRAY;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.DataPoint", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"DataBytes", 
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
				CDOTNET_BYTE, 
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
			CDOTNET_BYTE, 
			1, 
			____returnValueLength);
	}
	return __error;
}

int CVIFUNC Alv_NarrowBand_DataPoint_ToString(
	Alv_NarrowBand_DataPoint __instance,
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
		"Alv.NarrowBand.DataPoint", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"ToString", 
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


// Type: Alv.CAN.SoftingCan
int CVIFUNC Alv_CAN_SoftingCan__Create(
	Alv_CAN_SoftingCan * __instance,
	CDotNetHandle * __exception)
{
	int __error = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"Alv.CAN.SoftingCan", 
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

int CVIFUNC Alv_CAN_SoftingCan_Get_DeviceType(
	Alv_CAN_SoftingCan __instance,
	Alv_CAN_CanDevices * __returnValue,
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
		"Alv.CAN.SoftingCan", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"DeviceType", 
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

int CVIFUNC Alv_CAN_SoftingCan_Get_BusMode(
	Alv_CAN_SoftingCan __instance,
	Alv_CAN_CanBusModes * __returnValue,
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
		"Alv.CAN.SoftingCan", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"BusMode", 
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

int CVIFUNC Alv_CAN_SoftingCan_Set_BusMode(
	Alv_CAN_SoftingCan __instance,
	Alv_CAN_CanBusModes value,
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
	__errChk(Alv_CAN_CanBusModes__Create(
		&value, 
		&value__, 
		__exception));
	__parameterTypeNames[0] = "Alv.CAN.CanBusModes";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &value__;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.CAN.SoftingCan", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"BusMode", 
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

int CVIFUNC Alv_CAN_SoftingCan_Get_WakeupMode(
	Alv_CAN_SoftingCan __instance,
	Alv_CAN_CanWakeupModes * __returnValue,
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
		"Alv.CAN.SoftingCan", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"WakeupMode", 
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

int CVIFUNC Alv_CAN_SoftingCan_Set_WakeupMode(
	Alv_CAN_SoftingCan __instance,
	Alv_CAN_CanWakeupModes value,
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
	__errChk(Alv_CAN_CanWakeupModes__Create(
		&value, 
		&value__, 
		__exception));
	__parameterTypeNames[0] = "Alv.CAN.CanWakeupModes";
	__parameterTypes[0] = (CDOTNET_ENUM);
	__parameters[0] = &value__;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.CAN.SoftingCan", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"WakeupMode", 
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

int CVIFUNC Alv_CAN_SoftingCan_Get_BaudRate(
	Alv_CAN_SoftingCan __instance,
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
		"Alv.CAN.SoftingCan", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"BaudRate", 
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

int CVIFUNC Alv_CAN_SoftingCan_Set_BaudRate(
	Alv_CAN_SoftingCan __instance,
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
		"Alv.CAN.SoftingCan", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"BaudRate", 
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

int CVIFUNC Alv_CAN_SoftingCan_Get_DriverID(
	Alv_CAN_SoftingCan __instance,
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
		"Alv.CAN.SoftingCan", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"DriverID", 
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

int CVIFUNC Alv_CAN_SoftingCan_Set_DriverID(
	Alv_CAN_SoftingCan __instance,
	char * value,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: value
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &value;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.CAN.SoftingCan", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"DriverID", 
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

int CVIFUNC Alv_CAN_SoftingCan_Get_ClientID(
	Alv_CAN_SoftingCan __instance,
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
		"Alv.CAN.SoftingCan", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"ClientID", 
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

int CVIFUNC Alv_CAN_SoftingCan_Set_ClientID(
	Alv_CAN_SoftingCan __instance,
	char * value,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	// Pre-process parameter: value
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &value;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.CAN.SoftingCan", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"ClientID", 
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

int CVIFUNC Alv_CAN_SoftingCan_Get_ReadTimeout(
	Alv_CAN_SoftingCan __instance,
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
		"Alv.CAN.SoftingCan", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"ReadTimeout", 
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

int CVIFUNC Alv_CAN_SoftingCan_Set_ReadTimeout(
	Alv_CAN_SoftingCan __instance,
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
		"Alv.CAN.SoftingCan", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"ReadTimeout", 
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

int CVIFUNC Alv_CAN_SoftingCan_Get_WriteTimeout(
	Alv_CAN_SoftingCan __instance,
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
		"Alv.CAN.SoftingCan", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"WriteTimeout", 
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

int CVIFUNC Alv_CAN_SoftingCan_Set_WriteTimeout(
	Alv_CAN_SoftingCan __instance,
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
		"Alv.CAN.SoftingCan", 
		__instance, 
		CDOTNET_SET_PROPERTY, 
		"WriteTimeout", 
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

int CVIFUNC Alv_CAN_SoftingCan_Get_Error(
	Alv_CAN_SoftingCan __instance,
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
		"Alv.CAN.SoftingCan", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Error", 
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

int CVIFUNC Alv_CAN_SoftingCan_Connect(
	Alv_CAN_SoftingCan __instance,
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
		"Alv.CAN.SoftingCan", 
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

int CVIFUNC Alv_CAN_SoftingCan_Disconnect(
	Alv_CAN_SoftingCan __instance,
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
		"Alv.CAN.SoftingCan", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Disconnect", 
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

int CVIFUNC Alv_CAN_SoftingCan_Clear(
	Alv_CAN_SoftingCan __instance,
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
		"Alv.CAN.SoftingCan", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Clear", 
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

int CVIFUNC Alv_CAN_SoftingCan_Read(
	Alv_CAN_SoftingCan __instance,
	Alv_CAN_CanMsg * msg,
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


	// Pre-process parameter: msg
	__parameterTypeNames[0] = "Alv.CAN.CanMsg&";
	__parameterTypes[0] = (CDOTNET_STRUCT | CDOTNET_REF);
	__parameters[0] = msg;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.CAN.SoftingCan", 
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
	if (__error < 0) {
		_CDotNetGenDisposeScalar(
			msg, 
			CDOTNET_STRUCT);
	}
	return __error;
}

int CVIFUNC Alv_CAN_SoftingCan_Write(
	Alv_CAN_SoftingCan __instance,
	Alv_CAN_CanMsg * msg,
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


	// Pre-process parameter: msg
	__parameterTypeNames[0] = "Alv.CAN.CanMsg&";
	__parameterTypes[0] = (CDOTNET_STRUCT | CDOTNET_REF);
	__parameters[0] = msg;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.CAN.SoftingCan", 
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
			msg, 
			CDOTNET_STRUCT);
	}
	return __error;
}


// Type: Alv.NarrowBand.Enumeration
int CVIFUNC Alv_NarrowBand_Enumeration__Create(
	Alv_NarrowBand_Enumeration * __instance,
	char * type,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: type
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &type;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"Alv.NarrowBand.Enumeration", 
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

int CVIFUNC Alv_NarrowBand_Enumeration_Get_Type(
	Alv_NarrowBand_Enumeration __instance,
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
		"Alv.NarrowBand.Enumeration", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Type", 
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

int CVIFUNC Alv_NarrowBand_Enumeration_Add(
	Alv_NarrowBand_Enumeration __instance,
	char * value,
	char * name,
	char * display,
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


	// Pre-process parameter: value
	__parameterTypeNames[0] = "System.String";
	__parameterTypes[0] = (CDOTNET_STRING);
	__parameters[0] = &value;

	// Pre-process parameter: name
	__parameterTypeNames[1] = "System.String";
	__parameterTypes[1] = (CDOTNET_STRING);
	__parameters[1] = &name;

	// Pre-process parameter: display
	__parameterTypeNames[2] = "System.String";
	__parameterTypes[2] = (CDOTNET_STRING);
	__parameters[2] = &display;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_BOOLEAN;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.Enumeration", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"Add", 
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

int CVIFUNC Alv_NarrowBand_Enumeration_FindDisplay(
	Alv_NarrowBand_Enumeration __instance,
	int value,
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


	// Pre-process parameter: value
	__parameterTypeNames[0] = "System.Int32";
	__parameterTypes[0] = (CDOTNET_INT32);
	__parameters[0] = &value;

	// Pre-process return value
	__returnValueTypeId = CDOTNET_STRING;

	// Call instance member
	__errChk(CDotNetInvokeGenericMember(
		__assemblyHandle, 
		"Alv.NarrowBand.Enumeration", 
		__instance, 
		CDOTNET_CALL_METHOD, 
		"FindDisplay", 
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


// Type: Alv.NarrowBand.DSP_DIAG
int CVIFUNC Alv_NarrowBand_DSP_DIAG__Create(
	Alv_NarrowBand_DSP_DIAG * __instance,
	unsigned char * Data,
	ssize_t __DataLength,
	CDotNetHandle * __exception)
{
	int __error = 0;
	char * __parameterTypeNames[1] = {0};
	unsigned int __parameterTypes[1];
	void * __parameters[1];
	CDotNetHandle Data__ = 0;

	if (__exception)
		*__exception = 0;


	*__instance = 0;

	// Pre-process parameter: Data
	if (Data)
		__errChk(CDotNetCreateArray(
			CDOTNET_BYTE, 
			1, 
			0, 
			&__DataLength, 
			Data, 
			&Data__));
	__parameterTypeNames[0] = "System.Byte[]";
	__parameterTypes[0] = (CDOTNET_BYTE | CDOTNET_ARRAY);
	__parameters[0] = &Data__;

	// Call constructor
	__errChk(CDotNetCreateGenericInstance(
		__assemblyHandle, 
		"Alv.NarrowBand.DSP_DIAG", 
		0, 
		0, 
		__instance, 
		1, 
		(const char **)__parameterTypeNames, 
		__parameterTypes, 
		__parameters, 
		__exception));


__Error:
	if (Data__)
		CDotNetDiscardHandle(Data__);
	return __error;
}

int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Sensor_Position(
	Alv_NarrowBand_DSP_DIAG __instance,
	Alv_NarrowBand_NBProtocol_Position * __returnValue,
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
		"Alv.NarrowBand.DSP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Sensor_Position", 
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

int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Sensor_Fault(
	Alv_NarrowBand_DSP_DIAG __instance,
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
		"Alv.NarrowBand.DSP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Sensor_Fault", 
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

int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Diagnostics_Summary(
	Alv_NarrowBand_DSP_DIAG __instance,
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
		"Alv.NarrowBand.DSP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Diagnostics_Summary", 
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

int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_RAM_Fault(
	Alv_NarrowBand_DSP_DIAG __instance,
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
		"Alv.NarrowBand.DSP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"RAM_Fault", 
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

int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Flash_Fault(
	Alv_NarrowBand_DSP_DIAG __instance,
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
		"Alv.NarrowBand.DSP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Flash_Fault", 
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

int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_EEPROM_Fault(
	Alv_NarrowBand_DSP_DIAG __instance,
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
		"Alv.NarrowBand.DSP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"EEPROM_Fault", 
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

int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Power_Fault(
	Alv_NarrowBand_DSP_DIAG __instance,
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
		"Alv.NarrowBand.DSP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Power_Fault", 
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

int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Watchdog_Tripped_Warning(
	Alv_NarrowBand_DSP_DIAG __instance,
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
		"Alv.NarrowBand.DSP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Watchdog_Tripped_Warning", 
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

int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_A_D_Trigger_Fault(
	Alv_NarrowBand_DSP_DIAG __instance,
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
		"Alv.NarrowBand.DSP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"A_D_Trigger_Fault", 
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

int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_PLL_Unable_To_Lock_Fault(
	Alv_NarrowBand_DSP_DIAG __instance,
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
		"Alv.NarrowBand.DSP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"PLL_Unable_To_Lock_Fault", 
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

int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Initialization_Fault(
	Alv_NarrowBand_DSP_DIAG __instance,
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
		"Alv.NarrowBand.DSP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Initialization_Fault", 
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

int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Radar_Start_Fault(
	Alv_NarrowBand_DSP_DIAG __instance,
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
		"Alv.NarrowBand.DSP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Radar_Start_Fault", 
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

int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Stack_Overflow_Warning(
	Alv_NarrowBand_DSP_DIAG __instance,
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
		"Alv.NarrowBand.DSP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Stack_Overflow_Warning", 
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

int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Sensor_Over_Temperature_Warning(
	Alv_NarrowBand_DSP_DIAG __instance,
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
		"Alv.NarrowBand.DSP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Sensor_Over_Temperature_Warning", 
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

int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_RX_MMIC_Fault(
	Alv_NarrowBand_DSP_DIAG __instance,
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
		"Alv.NarrowBand.DSP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"RX_MMIC_Fault", 
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

int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_TX_MMIC_Fault(
	Alv_NarrowBand_DSP_DIAG __instance,
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
		"Alv.NarrowBand.DSP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"TX_MMIC_Fault", 
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

int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Busy_Sending_DAQ_Data_Warning(
	Alv_NarrowBand_DSP_DIAG __instance,
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
		"Alv.NarrowBand.DSP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Busy_Sending_DAQ_Data_Warning", 
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

int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Bias_Check_Warning(
	Alv_NarrowBand_DSP_DIAG __instance,
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
		"Alv.NarrowBand.DSP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Bias_Check_Warning", 
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

int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_A_D_Out_Of_Range_Warning(
	Alv_NarrowBand_DSP_DIAG __instance,
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
		"Alv.NarrowBand.DSP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"A_D_Out_Of_Range_Warning", 
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

int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_HP_Not_Responding_Fault(
	Alv_NarrowBand_DSP_DIAG __instance,
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
		"Alv.NarrowBand.DSP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"HP_Not_Responding_Fault", 
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

int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_High_Rx_Noise_Warning(
	Alv_NarrowBand_DSP_DIAG __instance,
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
		"Alv.NarrowBand.DSP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"High_Rx_Noise_Warning", 
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

int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Phase_Shifter_Warning(
	Alv_NarrowBand_DSP_DIAG __instance,
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
		"Alv.NarrowBand.DSP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Phase_Shifter_Warning", 
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

int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_DC_Offset_Out_Of_Range_Warning(
	Alv_NarrowBand_DSP_DIAG __instance,
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
		"Alv.NarrowBand.DSP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"DC_Offset_Out_Of_Range_Warning", 
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

int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Slow_Signal_Processing_Warning(
	Alv_NarrowBand_DSP_DIAG __instance,
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
		"Alv.NarrowBand.DSP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Slow_Signal_Processing_Warning", 
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

int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Parameters_Warning(
	Alv_NarrowBand_DSP_DIAG __instance,
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
		"Alv.NarrowBand.DSP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Parameters_Warning", 
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

int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_I_CAN_Tx_Queue_Full_Warning(
	Alv_NarrowBand_DSP_DIAG __instance,
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
		"Alv.NarrowBand.DSP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"I_CAN_Tx_Queue_Full_Warning", 
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

int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Sweep_Discarded_Warning(
	Alv_NarrowBand_DSP_DIAG __instance,
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
		"Alv.NarrowBand.DSP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Sweep_Discarded_Warning", 
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

int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Sensor_Blockage_Fault(
	Alv_NarrowBand_DSP_DIAG __instance,
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
		"Alv.NarrowBand.DSP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Sensor_Blockage_Fault", 
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

int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Sensor_Interference_Fault(
	Alv_NarrowBand_DSP_DIAG __instance,
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
		"Alv.NarrowBand.DSP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Sensor_Interference_Fault", 
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

int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Sensor_Misalignment_Fault(
	Alv_NarrowBand_DSP_DIAG __instance,
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
		"Alv.NarrowBand.DSP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Sensor_Misalignment_Fault", 
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

int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Vehicle_Data_Stagnant_Warning(
	Alv_NarrowBand_DSP_DIAG __instance,
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
		"Alv.NarrowBand.DSP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Vehicle_Data_Stagnant_Warning", 
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

int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_E_CAN_Tx_Queue_Full_Warning(
	Alv_NarrowBand_DSP_DIAG __instance,
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
		"Alv.NarrowBand.DSP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"E_CAN_Tx_Queue_Full_Warning", 
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

int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Config_Block_8_Invalid_Warning(
	Alv_NarrowBand_DSP_DIAG __instance,
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
		"Alv.NarrowBand.DSP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Config_Block_8_Invalid_Warning", 
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

int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Config_Block_7_Invalid_Warning(
	Alv_NarrowBand_DSP_DIAG __instance,
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
		"Alv.NarrowBand.DSP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Config_Block_7_Invalid_Warning", 
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

int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Config_Block_6_Invalid_Warning(
	Alv_NarrowBand_DSP_DIAG __instance,
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
		"Alv.NarrowBand.DSP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Config_Block_6_Invalid_Warning", 
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

int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Config_Block_5_Invalid_Warning(
	Alv_NarrowBand_DSP_DIAG __instance,
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
		"Alv.NarrowBand.DSP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Config_Block_5_Invalid_Warning", 
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

int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Config_Block_4_Invalid_Warning(
	Alv_NarrowBand_DSP_DIAG __instance,
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
		"Alv.NarrowBand.DSP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Config_Block_4_Invalid_Warning", 
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

int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Config_Block_3_Invalid_Warning(
	Alv_NarrowBand_DSP_DIAG __instance,
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
		"Alv.NarrowBand.DSP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Config_Block_3_Invalid_Warning", 
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

int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Config_Block_2_Invalid_Warning(
	Alv_NarrowBand_DSP_DIAG __instance,
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
		"Alv.NarrowBand.DSP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Config_Block_2_Invalid_Warning", 
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

int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Config_Block_1_Invalid_Warning(
	Alv_NarrowBand_DSP_DIAG __instance,
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
		"Alv.NarrowBand.DSP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Config_Block_1_Invalid_Warning", 
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

int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Blockage_Warning(
	Alv_NarrowBand_DSP_DIAG __instance,
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
		"Alv.NarrowBand.DSP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Blockage_Warning", 
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

int CVIFUNC Alv_NarrowBand_DSP_DIAG_Get_Incompatible_Hardware_Fault(
	Alv_NarrowBand_DSP_DIAG __instance,
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
		"Alv.NarrowBand.DSP_DIAG", 
		__instance, 
		CDOTNET_GET_PROPERTY, 
		"Incompatible_Hardware_Fault", 
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


// Type: Alv.NbLib
int CVIFUNC Alv_NbLib_Get_Version(
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
		"Alv.NbLib", 
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



// Internal functions
static int CVIFUNC Alv_NarrowBand_NBProtocol_Status__Create(
	Alv_NarrowBand_NBProtocol_Status * value,
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
		"Alv.NarrowBand.NBProtocol+Status", 
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

static int CVIFUNC Alv_CAN_CanBusModes__Create(
	Alv_CAN_CanBusModes * value,
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
		"Alv.CAN.CanBusModes", 
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

static int CVIFUNC Alv_CAN_CanWakeupModes__Create(
	Alv_CAN_CanWakeupModes * value,
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
		"Alv.CAN.CanWakeupModes", 
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

static int CVIFUNC Alv_NarrowBand_NBProtocol_Position__Create(
	Alv_NarrowBand_NBProtocol_Position * value,
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
		"Alv.NarrowBand.NBProtocol+Position", 
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
		__assemblyName, 
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
		__assemblyName, 
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
		__assemblyName, 
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
		__assemblyName, 
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
		__assemblyName, 
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
		__assemblyName, 
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
		__assemblyName, 
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

static int CVIFUNC Alv_NarrowBand_NBProtocol_ControlError__Create(
	Alv_NarrowBand_NBProtocol_ControlError * value,
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
		"Alv.NarrowBand.NBProtocol+ControlError", 
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

static int CVIFUNC Alv_NarrowBand_NBProtocol_LoggerID__Create(
	Alv_NarrowBand_NBProtocol_LoggerID * value,
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
		"Alv.NarrowBand.NBProtocol+LoggerID", 
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

static int CVIFUNC Alv_NarrowBand_NBProtocol_ControlLogger__Create(
	Alv_NarrowBand_NBProtocol_ControlLogger * value,
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
		"Alv.NarrowBand.NBProtocol+ControlLogger", 
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
		__assemblyName, 
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

static int CVIFUNC Alv_NarrowBand_NBProtocol_ExecuteFunctions__Create(
	Alv_NarrowBand_NBProtocol_ExecuteFunctions * value,
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
		"Alv.NarrowBand.NBProtocol+ExecuteFunctions", 
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

static int CVIFUNC Alv_NarrowBand_PointTypes__Create(
	Alv_NarrowBand_PointTypes * value,
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
		"Alv.NarrowBand.PointTypes", 
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

static int CVIFUNC Alv_NarrowBand_PointFormats__Create(
	Alv_NarrowBand_PointFormats * value,
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
		"Alv.NarrowBand.PointFormats", 
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

