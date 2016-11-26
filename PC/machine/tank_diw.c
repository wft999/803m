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
#include "type.h" 
//==============================================================================
// Constants

#define  key_add_car				20
#define  key_remve_car				30
#define  key_run					40
#define  key_fill_up				50
#define  key_fill_down				60
#define  key_bubble					70
#define  key_drain					80



//==============================================================================
// Types
typedef struct _PLC_DIW_STATUS{
	short proc_step;
	short remain_time;
	short remain_times;
	short bit;
	
}PLC_DIW_STATUS;
//==============================================================================
// Static global variables
int tid;
//==============================================================================
// Static functions

//==============================================================================
// Global variables

//==============================================================================
// Global functions
int readTankStatus(void);

void initDiwTankPanel(int panel,TANK_ID id)
{
	tid = id;
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
	
}

int CVICALLBACK DiwCommand (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_LEFT_CLICK:
			if(CheckAuth(OP_ROBOT) == 0)
				return 0;
			if (!ConfirmPopup("操作确认","是否确定执行您选择的功能？"))		
				return 0;
			switch(control)
			{
				int stat; 
				case PANEL_DIW_ADD_CAR:
					Q2h.cmdWrite[0]=CMD_TANK;
					Q2h.cmdWrite[1]=tid;
					Q2h.cmdWrite[2]=key_add_car;
					writeCommand(3);
					
					//ActionLog(RB_PUT_ACT_EVENT,curRobotId,curTid,0,0,0); 
					break;
				case PANEL_DIW_REMOVE_CAR:
					Q2h.cmdWrite[0]=CMD_TANK;
					Q2h.cmdWrite[1]=tid;
					Q2h.cmdWrite[2]=key_remve_car;
					writeCommand(3);
					
					//ActionLog(RB_PUT_ACT_EVENT,curRobotId,curTid,0,0,0); 
					break;
					
				case PANEL_DIW_TOGGLEBUTTON_RUN:
					Q2h.cmdWrite[0]=CMD_TANK;
					Q2h.cmdWrite[1]=tid;
					Q2h.cmdWrite[2]=key_run;
					writeCommand(3);
					
					//ActionLog(RB_PUT_ACT_EVENT,curRobotId,curTid,0,0,0); 
					break;
					
				case PANEL_DIW_VALVE_UP:
					Q2h.cmdWrite[0]=CMD_TANK;
					Q2h.cmdWrite[1]=tid;
					Q2h.cmdWrite[2]=key_fill_up;
					writeCommand(3);
					
					//ActionLog(RB_PUT_ACT_EVENT,curRobotId,curTid,0,0,0); 
					break;
					
				case PANEL_DIW_VALVE_BOBBLE:
					Q2h.cmdWrite[0]=CMD_TANK;
					Q2h.cmdWrite[1]=tid;
					Q2h.cmdWrite[2]=key_bubble;
					writeCommand(3);
					
					//ActionLog(RB_PUT_ACT_EVENT,curRobotId,curTid,0,0,0); 
					break;
					
				case PANEL_DIW_VALVE_DOWN:
					Q2h.cmdWrite[0]=CMD_TANK;
					Q2h.cmdWrite[1]=tid;
					Q2h.cmdWrite[2]=key_fill_down;
					writeCommand(3);
					
					//ActionLog(RB_PUT_ACT_EVENT,curRobotId,curTid,0,0,0); 
					break;
					
				case PANEL_DIW_VALVE_DRAIN:
					Q2h.cmdWrite[0]=CMD_TANK;
					Q2h.cmdWrite[1]=tid;
					Q2h.cmdWrite[2]=key_drain;
					writeCommand(3);
					
					//ActionLog(RB_PUT_ACT_EVENT,curRobotId,curTid,0,0,0); 
					break;
			}

			break;
	}
	return 0;
}

int CVICALLBACK DiwTimer (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int id1[6]={PANEL_DIW_REMAIN_1,PANEL_DIW_REMAIN_2,PANEL_DIW_REMAIN_3,PANEL_DIW_REMAIN_4,PANEL_DIW_REMAIN_5,PANEL_DIW_REMAIN_6}; 
	switch (event)
	{
		case EVENT_TIMER_TICK:
			
			readTankStatus();
			PLC_DIW_STATUS* stat = (PLC_DIW_STATUS*)Q2h.tkStatus;
			SetCtrlVal(panel, PANEL_DIW_REMAIN_TIMES, stat->remain_times);
			
			
			for(int i=0;i<6;i++)
			{
				if( i == stat->proc_step-1)
					SetCtrlVal(panel, id1[i], stat->remain_time);
				else
					SetCtrlVal(panel, id1[i], 0);
				
			}
			
			//SetCtrlVal(panel, PANEL_DIW_CAR, getBit(stat->bit,0));
			SetCtrlAttribute(panel,PANEL_DIW_CAR, ATTR_VISIBLE, getBit(stat->bit,0));
			//SetCtrlIndex(panel,PANEL_DIW_CAR, Q2h.sysStatus.tk_remain_time[i]<=0?1:0);
			
			if(getBit(stat->bit,6))
				SetCtrlVal(panel, PANEL_DIW_TANK, 2);
			else if(getBit(stat->bit,7))
				SetCtrlVal(panel, PANEL_DIW_TANK, 1);
			else
				SetCtrlVal(panel, PANEL_DIW_TANK, 0);
			
			SetCtrlVal(panel, PANEL_DIW_VALVE_BOBBLE, getBit(stat->bit,11));
			SetCtrlVal(panel, PANEL_DIW_VALVE_DRAIN, getBit(stat->bit,12)); 
			SetCtrlVal(panel, PANEL_DIW_VALVE_DOWN, getBit(stat->bit,13));
			SetCtrlVal(panel, PANEL_DIW_VALVE_UP, getBit(stat->bit,14));


			break;
	}
	return 0;
}

