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
#define  key_dialog_open			1
#define  key_dialog_close			2

#define  key_add_car				20
#define  key_remve_car				30
#define  key_qdr					40
#define  key_fill_up				50
#define  key_fill_down				60
#define  key_bubble					70
#define  key_drain					80



//==============================================================================
// Types

//==============================================================================
// Static global variables
int curTid;
//==============================================================================
// Static functions

//==============================================================================
// Global variables

//==============================================================================
// Global functions

void initDiwTankPanel(int panel,TANK_ID tid)
{
	curTid = tid;
	DIW_RCP rcp;
	
	if(tid == TANK_DIW1)
		rcp = sys->rcp.rcpDIW1;
	else if(tid == TANK_DIW2)
		rcp = sys->rcp.rcpDIW2;
	else if(tid == TANK_DIW3)
		rcp = sys->rcp.rcpDIW3;
	else
		rcp = sys->rcp.rcpDIW1;
	
	SetCtrlVal(panel, PANEL_DIW_TIMES, rcp.LoopCount);
	
	int id1[6]={PANEL_DIW_TIME_1,PANEL_DIW_TIME_2,PANEL_DIW_TIME_3,PANEL_DIW_TIME_4,PANEL_DIW_TIME_5,PANEL_DIW_TIME_6};
	int id2[6]={PANEL_DIW_UP_1,PANEL_DIW_UP_2,PANEL_DIW_UP_3,PANEL_DIW_UP_4,PANEL_DIW_UP_5,PANEL_DIW_UP_6}; 
	int id3[6]={PANEL_DIW_DOWN_1,PANEL_DIW_DOWN_2,PANEL_DIW_DOWN_3,PANEL_DIW_DOWN_4,PANEL_DIW_DOWN_5,PANEL_DIW_DOWN_6};
	int id4[6]={PANEL_DIW_BUBBLE_1,PANEL_DIW_BUBBLE_2,PANEL_DIW_BUBBLE_3,PANEL_DIW_BUBBLE_4,PANEL_DIW_BUBBLE_5,PANEL_DIW_BUBBLE_6};
	int id5[6]={PANEL_DIW_DRAIN_1,PANEL_DIW_DRAIN_2,PANEL_DIW_DRAIN_3,PANEL_DIW_DRAIN_4,PANEL_DIW_DRAIN_5,PANEL_DIW_DRAIN_6};
	for(int i=0;i<6;i++)
	{
		SetCtrlVal(panel, id1[i], rcp.uiRemain[i]);
		SetCtrlVal(panel, id2[i], getBit(rcp.uiCmd[i],0));  
		SetCtrlVal(panel, id3[i], getBit(rcp.uiCmd[i],1));  
		SetCtrlVal(panel, id4[i], getBit(rcp.uiCmd[i],2));  
		SetCtrlVal(panel, id5[i], getBit(rcp.uiCmd[i],3));  
	}
	
	Q2h.cmdWrite[0]=CMD_TANK;
	Q2h.cmdWrite[1]=curTid;
	Q2h.cmdWrite[2]=key_dialog_open;
	writeCommand(3);
}

int CVICALLBACK DiwCommand (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:

			break;
	}
	return 0;
}

int CVICALLBACK DiwTimer (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_TIMER_TICK:

			break;
	}
	return 0;
}

int CVICALLBACK ExitDiwDialog (int panel, int event, void *callbackData, int eventData1, int eventData2)
{
    if (event == EVENT_CLOSE)
	{
		Q2h.cmdWrite[0]=CMD_TANK;
		Q2h.cmdWrite[1]=curTid;
		Q2h.cmdWrite[2]=key_dialog_close;
		writeCommand(3);
		
        RemovePopup(0);
		DiscardPanel (panel);
	}
    return 0;
}
