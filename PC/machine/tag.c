#include <userint.h>

//==============================================================================
//
// Title:       tag.c
// Purpose:     A short description of the implementation.
//
// Created on:  2014/9/12 at ¤U¤È 02:16:28 by wang fang.
// Copyright:   hua. All Rights Reserved.
//
//==============================================================================
#include <windows.h> 
//==============================================================================
// Include files

//#include "tag.h"
#include <formatio.h>
#include <rs232.h>
#include "type.h"

#include "robot_panel.h"
//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// Static global variables
static int waitUser;
static int curTagId;; 
//==============================================================================
// Static functions

//==============================================================================
// Global variables

//==============================================================================
// Global functions
int ReadTag(int id,int com)
{
	char Buff[128]={0}; 
	char Response[128];
	
	if(waitUser == 1)
		return 0;
	
	curTagId = id;
#ifndef SIMULATE
	if(OpenComConfig(com, "", 19200, 0, 8, 1, 512, 512)< 0)
	{
		SendPcAlarm(PCA_TAG1_BID+id,1); 
		return 0;
	}
    SetComTime(com,1);

	FlushOutQ(com);
    Sleep(25);
	
    Fmt(Buff, "%s%c", "GT",0xD);
    ComWrt(com, Buff, 3); 
	FlushInQ (com);
    Sleep(25);
	
	ComRd(com, Response, 10); 
	CloseCom (com);
#else
	strcpy(Response,"123456");
#endif

    if(strstr(Response,"NAK") != NULL || strstr(Response,"XXXXXXXX") != NULL)
    {
		SendPcAlarm(PCA_TAG1_BID+id,1); 
		
		int dialogHandle = LoadPanel (0, "robot_panel.uir", PANEL_TAG);
		InstallPopup(dialogHandle);
		
		char msg[64];
		sprintf(msg,"ID%d read fail, Please select handle type:",id+1); 
		SetCtrlVal(dialogHandle,PANEL_TAG_TEXTMSG,msg); 
		
		waitUser = 1;
	}
	else
	{
		if(id == 0)
			Fmt (sys->rtk[RTK_01].car.tag1, "%s<%s[w10]",Response);
		else
			Fmt (sys->rtk[RTK_01].car.tag2, "%s<%s[w10]",Response);
		
	}

	return 1;
}

int CVICALLBACK ReadTagSelect (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			int val;
			GetCtrlVal(panel,PANEL_TAG_ID_RADIOGROUP,&val); 
			if(control == PANEL_TAG_ID_RADIOGROUP)
			{
				if(val == 2)
                	SetCtrlAttribute(panel,PANEL_TAG_ID,ATTR_VISIBLE ,1);
			}
			else if(control == PANEL_TAG_OK)
			{
				
				char* dest;
				char Response[128];
				if(curTagId == 0)
					dest = sys->rtk[RTK_01].car.tag1;
				else
					dest = sys->rtk[RTK_01].car.tag2;
			
				if(val == 1)
				{
					strcpy(dest,"id unknow");
				}
            	else if(val == 2)
				{
                	GetCtrlVal(panel,PANEL_TAG_ID,Response);
					Fmt (dest, "%s<%s[w10]",Response);
				}
				
				SendPcAlarm(PCA_TAG1_BID+curTagId,0);
				waitUser = 0;
			
            	RemovePopup (0);
			}
			
			break;
	}
	return 0;
}
