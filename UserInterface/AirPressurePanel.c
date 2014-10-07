#include <userint.h>
#include "AirPressurePanel.h"
#include "DIO6515Utils.h"
#include "DIO6515UtilsDef.h"
#include "Global.h"
#include "frmMain.h"


/* Air Pressure Sensor */

int CVICALLBACK OK_CB (int panel, int control, int event,
					   void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			//Toggle DumpVale Power
			setCtrlDumpValve(GLB_FALSE);
			setCtrlDumpValve(GLB_TRUE);
			
			AirPressurePanelHandle = 0;
			HidePanel(panel);
			DiscardPanel (AirPressurePanelHandle);
			
			//Flag set to 0
			AirPressureFlag = 0;
			//setDebugBit(0);	
			
			//Resume Clock
			SetCtrlAttribute (MainPanelHandle, Main_CLOCK_TIMER, ATTR_ENABLED, 1);
			SetCtrlAttribute (MainPanelHandle, Main_ESTOP_TIMER, ATTR_ENABLED, 1);  

			break;
	}
	return 0;
}
