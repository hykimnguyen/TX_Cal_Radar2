/***********************************************************************
 *
 *
 *  COPYRIGHT: Arxtron Technologies Inc. All Rights Reserved.
 *
 *  PURPOSE:  
 *            
 *            
 *            
 *
 *
 *  DEVELOPMENT HISTORY:
 *
 *  Date        Name           Rev.   Description
 *  ----------  -------------  -----  -----------------------
 *  05-15-2013  Arxtron        1      Initial Release
 *  
 *  
 *********************************************************************/ 
 /*!
*    @file    Password.c
*    @brief   Function related password management
*    @author  Arxtron Technologies Inc.
*    @date    2013.9.6
*    Password management functions
*    
*/
 
#include <cvirte.h>		
#include <userint.h>
#include "Password.h"
#include "Global.h" 
#include "DataLib.h" 
#include <formatio.h>
//********************************************************************************************************************
#if USE_EXT_MAIN_PROJ 

#else  
//********************************************************************************************************************
//int main (int argc, char *argv[])
//{
//	if (InitCVIRTE (0, argv, 0) == 0)
//		return -1;	/* out of memory */
//	if ((PasswordPanelHandle = LoadPanel (0, "Password.uir", PD_PNL)) < 0)
//		return -1;
//	DisplayPanel (PasswordPanelHandle);
//	RunUserInterface ();
//	DiscardPanel (PasswordPanelHandle);
//	return 0;
//}
#endif 
//********************************************************************************************************************
/********************************************//**
* Handeling different even in the password panel
***********************************************/
int CVICALLBACK PasswordCallback (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (control)
	{
		// entering stuff into password field
		case PD_PNL_PW_ENTER:
	
			switch (event)
			{
				case EVENT_COMMIT:
					break;
				case EVENT_VAL_CHANGED:

					break;
				case EVENT_KEYPRESS:
		           			if (eventData1 == VAL_ESC_VKEY)
		           			{ 
		           				pwd_status = GLB_FAIL; return 0;
		           			}
		          			if ((eventData1 & VAL_VKEY_MASK) == VAL_BACKSPACE_VKEY)
		          			{
		           				if (PWD_KeyPress_Loc == 0)
		           				{ 
		           					return 0;							 
		           				}
		            			else
		            			{
		            				PWD_KeyPress_Loc--;                 // Decrement password index by one 
		            				password[PWD_KeyPress_Loc] = '\0';  // Remove one character from password 
		               				return 0;
		             			}
		                    }
		           			if ((eventData1 & VAL_ASCII_KEY_MASK) != 0) // Check for an ASCII printable key 
		             			if (PWD_KeyPress_Loc < 10)
		             			{
		               			Fmt(password,"%s[a]<%c", eventData1);   // Store the entered keystroke  
					            PWD_KeyPress_Loc++;                     // Increment index 
		            			return 0;
		             			}
		             		else                                        // If index >= 10, length limit reached 
		             		{
		               			return 0;                                   // Return a non-zero to "swallow" KEYPRESS 
		             		}
            
		           			if (((eventData1 & VAL_VKEY_MASK) == VAL_LEFT_ARROW_VKEY)  || 
		               			((eventData1 & VAL_VKEY_MASK) == VAL_RIGHT_ARROW_VKEY) ||
		               			((eventData1 & VAL_VKEY_MASK) == VAL_HOME_VKEY)		  || 
		               			((eventData1 & VAL_VKEY_MASK) == VAL_END_VKEY)) 
		               			return 1;

					break;
			}
		case PD_PNL_OK_PASSWORD:
    		if (event == EVENT_COMMIT)				
    		{										
      			switch (pwd_status)
      			{
        			case VERIFY:
             			switch (pwd_location)
			            {
            				case VER_MODE:
               				case CONFIG_MODE:
               				case VERIFY_SYSTEM:
								StringUpperCase(password);
                    			if (!strcmp ((password), access_level1) || 
									!strcmp ((password), access_level2) || 
                        			!strcmp (password, (const char*)"»"))
                    			{
                      				pwd_status = GLB_PASS;
                      				return 0;
                    			}
               				break;
               				case MANUAL_MODE:
               					if (!strcmp ((password), access_level1) || 
									!strcmp ((password), (const char*)"»"))
               					{
			               			pwd_status = GLB_PASS;
               		  				return 0;
			               		}  
               				break;
               				case DEVIATION_MODE:
               					if (!strcmp((password), access_level1)) 
               					{
               						pwd_status = GLB_PASS;
									return 0;
               					}
               						
             				break;
             				}
             				//default:
			            		PWD_KeyPress_Loc     = 0;
            					password[0] = '\0';
		             	    	SetCtrlVal (panel, PD_PNL_PW_MESSAGE, "Password INCORRECT - Re-enter Password");
             					SetCtrlVal (panel, PD_PNL_PW_ENTER, "");
             				//break;
             			//}
        			break;
            
        			case CHANGE:
             			strcpy (new_pwd, (password));
             			PWD_KeyPress_Loc     = 0;
             			password[0] = '\0';
             			pwd_status  = REENTER;
             			SetCtrlVal (panel, PD_PNL_PW_MESSAGE, "Please Re-Enter New Password");
             			SetCtrlVal (panel, PD_PNL_PW_ENTER, NULL);
        			break;
            
        			case REENTER:
             			if (!strcmp (new_pwd, (password)))
             			{
               				if (!strcmp (temp_pwd, access_level1))
               				{
                 				strcpy (access_level1, password);

                 				return 0;
               			 	}  
               				else if (!strcmp ((temp_pwd), access_level2))
               			 	{
                 				strcpy (access_level2, (password));

                				return 0;
               			 	}  
             			}
             			else
             			{
               				PWD_KeyPress_Loc     = 0;
               				password[0] = '\0';
               				pwd_status  = CHANGE;
               				SetCtrlVal (panel, PD_PNL_PW_MESSAGE, "Passwords INCONSISTENT - Try Again");
               				SetCtrlVal (panel, PD_PNL_PW_ENTER, NULL);
             			}
        			break;
        			}
        	}
			break;
		case PD_PNL_PW_CANCEL:
             if (panel==PasswordPanelHandle)
			 {     
	    		if (event == EVENT_COMMIT)				
	    		{										
			 		pwd_status = GLB_FAIL;
		        	break;
				}
		     }
			return 0;
		}
	return 0;
}
//********************************************************************************************************************
/********************************************//**
*Saving of new password
***********************************************/
int CVICALLBACK EPasswordCallback (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	char					newPassword[100];
	char					dir[MAX_PATHNAME_LEN], filePath[MAX_PATHNAME_LEN]; 
	int						error=999;
	CVIXMLElement 			rootElement;
	
	switch (event)
	{
		case EVENT_COMMIT:
             if (control==EP_PNL_EPW_CANCEL)
			 { 
				 CheckError(HidePanel(EditPasswordPanelHandle));
			 }
             if (control==EP_PNL_OK_EPASSWORD)
			 { 
				 GetCtrlVal (EditPasswordPanelHandle, EP_PNL_EPW_ENTER, newPassword);
				 GetProjectDir(dir);
				 sprintf(filePath, "%s%s%s", dir,"\\Configuration\\", "ALevel.xml");
				 error = WritePasswordValue(newPassword, filePath);

				 rootElement = LoadConfigurationDocument(filePath);
				 ParseXMLDocument(rootElement, 0);
	
				 pwd_status=VERIFY;
				 StringUpperCase(Password.Level1);
				 StringUpperCase(Password.Level2);
				 strcpy (access_level1, Password.Level1);	
				 strcpy (access_level2, Password.Level2);	
				 pwd_location = CONFIG_MODE;								
				 if(!error)
				 {
				 	MessagePopup("Password Changed", "Password Change Succesful");	 
				 }
				 CheckError(HidePanel(EditPasswordPanelHandle));
			 }
			 
			break;
		case EVENT_KEYPRESS:

			break;
	}
	return 0;
}
//********************************************************************************************************************
