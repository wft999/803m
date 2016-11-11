#include <userint.h>
#include "tank_diw.h"

//==============================================================================
//
// Title:       tank_diw.c
// Purpose:     A short description of the implementation.
//
// Created on:  2016/10/30 at 19:11:53 by wuyan.
// Copyright:   . All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files

#include "tank_diw.h"
#include "type.h" 
//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// Static global variables

//==============================================================================
// Static functions

//==============================================================================
// Global variables

//==============================================================================
// Global functions

void initDiwTankPanel(int panel,TANK_ID tid)
{
	SetCtrlVal(panel, PANEL_DIW_TIMES, sys->rcp.rcpDIW1.LoopCount);
	
	int id1[6]={PANEL_DIW_TIME_1,PANEL_DIW_TIME_2,PANEL_DIW_TIME_3,PANEL_DIW_TIME_4,PANEL_DIW_TIME_5,PANEL_DIW_TIME_6};
	int id2[6]={PANEL_DIW_UP_1,PANEL_DIW_UP_2,PANEL_DIW_UP_3,PANEL_DIW_UP_4,PANEL_DIW_UP_5,PANEL_DIW_UP_6}; 
	int id3[6]={PANEL_DIW_DOWN_1,PANEL_DIW_DOWN_2,PANEL_DIW_DOWN_3,PANEL_DIW_DOWN_4,PANEL_DIW_DOWN_5,PANEL_DIW_DOWN_6};
	int id4[6]={PANEL_DIW_BUBBLE_1,PANEL_DIW_BUBBLE_2,PANEL_DIW_BUBBLE_3,PANEL_DIW_BUBBLE_4,PANEL_DIW_BUBBLE_5,PANEL_DIW_BUBBLE_6};
	int id5[6]={PANEL_DIW_DRAIN_1,PANEL_DIW_DRAIN_2,PANEL_DIW_DRAIN_3,PANEL_DIW_DRAIN_4,PANEL_DIW_DRAIN_5,PANEL_DIW_DRAIN_6};
	for(int i=0;i<6;i++)
	{
		SetCtrlVal(panel, id1[i], sys->rcp.rcpDIW1.uiRemain[i]);
		SetCtrlVal(panel, id2[i], getBit(sys->rcp.rcpDIW1.uiCmd[i],0));  
		SetCtrlVal(panel, id3[i], getBit(sys->rcp.rcpDIW1.uiCmd[i],1));  
		SetCtrlVal(panel, id4[i], getBit(sys->rcp.rcpDIW1.uiCmd[i],2));  
		SetCtrlVal(panel, id5[i], getBit(sys->rcp.rcpDIW1.uiCmd[i],3));  
	}
}

int CVICALLBACK TankTimer (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_TIMER_TICK:

			break;
	}
	return 0;
}
