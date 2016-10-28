#include <formatio.h>
#include <userint.h>
#include "robot_panel.h"

//==============================================================================
//
// Title:       robot_panel.c
// Purpose:     A short description of the implementation.
//
// Created on:  2014/7/8 at と 03:19:25 by wang fang.
// Copyright:   hua. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files

//#include "robot_panel.h"
#include "type.h"

//==============================================================================
// Constants
#define  key_x_jog_forward 			10
#define  key_x_jog_reverse			11
#define  key_x_jog_high_speed		12
#define  key_x_jog_low_speed		13
#define  key_z_jog_forward			14
#define  key_z_jog_reverse			15
#define  key_z_jog_high_speed		16
#define  key_z_jog_low_speed		17
#define  key_jog_stop				18

#define  key_home					20
#define  key_goto_lock				21
#define  key_goto_unlock			22
#define  key_take					23
#define  key_put					24
#define  key_clean					25

#define  key_teach_enable			30
#define  key_teach_disable			31
#define  key_add_car				32
#define  key_remve_car				33
#define  key_chuck_on				34
#define  key_chuck_off				35

#define  key_save_x_lock			40
#define  key_save_x_unlock			41
#define  key_save_z_bottom			42
#define  key_save_x_lock2			43
#define  key_save_x_unlock2			44
#define  key_save_z_bottom2			45

#define  key_save_pc_x_lock			50
#define  key_save_pc_x_unlock		51
#define  key_save_pc_z_bottom		52
#define  key_save_pc_x_lock2		53
#define  key_save_pc_x_unlock2		54
#define  key_save_pc_z_bottom2		55
//==============================================================================
// Types

//==============================================================================
// Static global variables
static int curRobotId;
static RTANK_ID curRid;
//==============================================================================
// Static functions

//==============================================================================
// Global variables
extern struct Q02hReg Q2h;
//==============================================================================
// Global functions
int readTankPos(int tid);
void writeHandshake(int len);
int readRobotPos(int rid);

int CVICALLBACK SavePosition (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			union DatCnv cnv; 
			double tmpx;
			int state;
			GetCtrlVal (panel, PANEL_RB_CHECKBOX_PERMIT_INPUT, &state);  
			
			if(CheckAuth(OP_ROBOT) == 0) {
				SetCtrlAttribute(panel,PANEL_RB_SET_X_UNLOCK, ATTR_DIMMED, 1); 
				SetCtrlAttribute(panel,PANEL_RB_SET_X_LOCK, ATTR_DIMMED, 1);
				SetCtrlAttribute(panel,PANEL_RB_SET_Z_DOWN, ATTR_DIMMED, 1); 
				
				SetCtrlVal (panel, PANEL_RB_CHECKBOX_PERMIT_SAVE, 0); 
				return 0;
			}
			if (!ButtonConfirm (panel,control))	{
				SetCtrlAttribute(panel,PANEL_RB_SET_X_UNLOCK, ATTR_DIMMED, 1); 
				SetCtrlAttribute(panel,PANEL_RB_SET_X_LOCK, ATTR_DIMMED, 1);
				SetCtrlAttribute(panel,PANEL_RB_SET_Z_DOWN, ATTR_DIMMED, 1); 

				SetCtrlVal (panel, PANEL_RB_CHECKBOX_PERMIT_SAVE, 0);
				return 0;
			}
			
			if(control == PANEL_RB_SET_X_UNLOCK)
			{
				if(state)//maun input
				{
					GetCtrlVal(panel, PANEL_RB_X_UNLOCK, &tmpx);
					cnv._I32 = tmpx;
					if(curRid <= sys->rb[curRobotId].lastRid)//tank pos
					{
						if(curRid == sys->rb[curRobotId].firstRid && curRobotId > 0 )//overlap tank  pos
						{
							//sys->rtk[curRid].xUnlock2 = tmpx * 10000;
							Q2h.wB[0]=50;
							Q2h.wB[1]=curRobotId;
							Q2h.wB[2]=curRid;
							Q2h.wB[3]=key_save_pc_x_unlock2;
							Q2h.wB[4]=cnv._I16[0];
							Q2h.wB[5]=cnv._I16[1]; 
				
							writeHandshake(6);
						}
						else //normal tank pos
						{
							//sys->rtk[curRid].xUnlock = tmpx * 10000;
							Q2h.wB[0]=50;
							Q2h.wB[1]=curRobotId;
							Q2h.wB[2]=curRid;
							Q2h.wB[3]=key_save_pc_x_unlock;
							Q2h.wB[4]=cnv._I16[0];
							Q2h.wB[5]=cnv._I16[1]; 
				
							writeHandshake(6);
						}	
					}
					else //clean pos
					{
						//sys->rb[curRobotId].cleanPosH = tmpx * 10000;
						//sys->rb[curRobotId].cleanPosV = tmpy * 10000;
					}	
				}
				else//get plc data
				{
					if(curRid <= sys->rb[curRobotId].lastRid)//tank pos
					{
						if(curRid == sys->rb[curRobotId].firstRid && curRobotId > 0 )//overlap tank  pos
						{
							//sys->rtk[curRid].xUnlock2 = tmpx * 10000; 
							Q2h.wB[0]=40;
							Q2h.wB[1]=curRobotId;
							Q2h.wB[2]=curRid;
							Q2h.wB[3]=key_save_x_unlock2;
				
							writeHandshake(4);
						}
						else //normal tank pos
						{
							//sys->rtk[curRid].xUnlock = tmpx * 10000; 
							Q2h.wB[0]=40;
							Q2h.wB[1]=curRobotId;
							Q2h.wB[2]=curRid;
							Q2h.wB[3]=key_save_x_unlock;
				
							writeHandshake(4);
						}
					}
					else//clean pos
					{
						//sys->rb[curRobotId].cleanPosH = tmpx * 10000; 
						//sys->rb[curRobotId].cleanPosV = tmpy * 10000;	
					}
				}
				
				ActionLog(RB_POS_SAVE_ACT_EVENT,curRobotId,0,curRid,0,0); 
			}
			else if(control == PANEL_RB_SET_X_LOCK)
			{
				if(state)//maun input
				{
					GetCtrlVal(panel, PANEL_RB_X_LOCK, &tmpx);
					cnv._I32 = tmpx;
					if(curRid <= sys->rb[curRobotId].lastRid)//tank pos
					{
						if(curRid == sys->rb[curRobotId].firstRid && curRobotId > 0 )//overlap tank  pos
						{
							//sys->rtk[curRid].xLock2 = tmpx * 10000;
							Q2h.wB[0]=50;
							Q2h.wB[1]=curRobotId;
							Q2h.wB[2]=curRid;
							Q2h.wB[3]=key_save_pc_x_lock;
							Q2h.wB[4]=cnv._I16[0];
							Q2h.wB[5]=cnv._I16[1]; 
				
							writeHandshake(6);

							
						}
						else //normal tank pos
						{
							//sys->rtk[curRid].xLock = tmpx * 10000;
							Q2h.wB[0]=50;
							Q2h.wB[1]=curRobotId;
							Q2h.wB[2]=curRid;
							Q2h.wB[3]=key_save_x_lock;
							Q2h.wB[4]=cnv._I16[0];
							Q2h.wB[5]=cnv._I16[1]; 
				
							writeHandshake(6);

						}	
					}
					else //clean pos
					{
						//sys->rb[curRobotId].cleanLock = tmpx * 10000;
						//sys->rb[curRobotId].cleanPosV = tmpy * 10000;
					}	
				}
				else//get plc data
				{

					if(curRid <= sys->rb[curRobotId].lastRid)//tank pos
					{
						if(curRid == sys->rb[curRobotId].firstRid && curRobotId > 0 )//overlap tank  pos
						{
							//sys->rtk[curRid].xLock2 = tmpx * 10000; 
							Q2h.wB[0]=40;
							Q2h.wB[1]=curRobotId;
							Q2h.wB[2]=curRid;
							Q2h.wB[3]=key_save_x_lock2;
				
							writeHandshake(4);

						}
						else //normal tank pos
						{
							//sys->rtk[curRid].xLock = tmpx * 10000;
							Q2h.wB[0]=40;
							Q2h.wB[1]=curRobotId;
							Q2h.wB[2]=curRid;
							Q2h.wB[3]=key_save_x_lock;
				
							writeHandshake(4);

						}
					}
					else//clean pos
					{
						//sys->rb[curRobotId].cleanLock = tmpx * 10000; 
						//sys->rb[curRobotId].cleanPosV = tmpy * 10000;
					}
				}
				
				
				ActionLog(RB_POS_SAVE_ACT_EVENT,curRobotId,1,curRid,0,0); 
				
			}else if(control == PANEL_RB_SET_Z_DOWN)
			{
				if(state)//maun input
				{
					GetCtrlVal(panel, PANEL_RB_Z_DOWN, &tmpx);
					cnv._I32 = tmpx;
					if(curRid <= sys->rb[curRobotId].lastRid)//tank pos
					{
						if(curRid == sys->rb[curRobotId].firstRid && curRobotId > 0 )//overlap tank  pos
						{
							Q2h.wB[0]=50;
							Q2h.wB[1]=curRobotId;
							Q2h.wB[2]=curRid;
							Q2h.wB[3]=key_save_pc_z_bottom2;
							Q2h.wB[4]=cnv._I16[0];
							Q2h.wB[5]=cnv._I16[1]; 
				
							writeHandshake(6);

							
						}
						else //normal tank pos
						{
							Q2h.wB[0]=50;
							Q2h.wB[1]=curRobotId;
							Q2h.wB[2]=curRid;
							Q2h.wB[3]=key_save_pc_z_bottom;
							Q2h.wB[4]=cnv._I16[0];
							Q2h.wB[5]=cnv._I16[1]; 
				
							writeHandshake(6);

						}	
					}
					else //clean pos
					{
						//sys->rb[curRobotId].cleanLock = tmpx * 10000;
						//sys->rb[curRobotId].cleanPosV = tmpy * 10000;
					}	
				}
				else//get plc data
				{

					if(curRid <= sys->rb[curRobotId].lastRid)//tank pos
					{
						if(curRid == sys->rb[curRobotId].firstRid && curRobotId > 0 )//overlap tank  pos
						{
							Q2h.wB[0]=40;
							Q2h.wB[1]=curRobotId;
							Q2h.wB[2]=curRid;
							Q2h.wB[3]=key_save_z_bottom2;
				
							writeHandshake(4);

						}
						else //normal tank pos
						{
							Q2h.wB[0]=40;
							Q2h.wB[1]=curRobotId;
							Q2h.wB[2]=curRid;
							Q2h.wB[3]=key_save_z_bottom;
				
							writeHandshake(4);

						}
					}
					else//clean pos
					{
						//sys->rb[curRobotId].cleanLock = tmpx * 10000; 
						//sys->rb[curRobotId].cleanPosV = tmpy * 10000;
					}
				}
				
				
				ActionLog(RB_POS_SAVE_ACT_EVENT,curRobotId,1,curRid,0,0); 
				
			}

	
			SetCtrlAttribute(panel,PANEL_RB_SET_X_LOCK, ATTR_DIMMED, 1); 
			SetCtrlAttribute(panel,PANEL_RB_SET_X_UNLOCK, ATTR_DIMMED, 1);
			SetCtrlAttribute(panel,PANEL_RB_SET_Z_DOWN, ATTR_DIMMED, 1); 
			SetCtrlVal (panel, PANEL_RB_CHECKBOX_PERMIT_SAVE, 0);

			break;
	}
	
	return 0;
}

int CVICALLBACK ManualInput (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			if(control == PANEL_RB_CHECKBOX_PERMIT_INPUT ){
				int state;
				GetCtrlVal (panel, control, &state); 
				if(state)
				{
					SetCtrlAttribute (panel, PANEL_RB_X_UNLOCK, ATTR_CTRL_MODE,  VAL_NORMAL);
					SetCtrlAttribute (panel, PANEL_RB_X_LOCK, ATTR_CTRL_MODE,  VAL_NORMAL); 
					SetCtrlAttribute (panel, PANEL_RB_Z_DOWN, ATTR_CTRL_MODE,  VAL_NORMAL);

				}
				else
				{
					SetCtrlAttribute (panel, PANEL_RB_X_UNLOCK, ATTR_CTRL_MODE,  VAL_INDICATOR);
					SetCtrlAttribute (panel, PANEL_RB_X_LOCK, ATTR_CTRL_MODE,  VAL_INDICATOR); 
					SetCtrlAttribute (panel, PANEL_RB_Z_DOWN, ATTR_CTRL_MODE,  VAL_INDICATOR);

				}
			}else if(control == PANEL_RB_CHECKBOX_PERMIT_SAVE ){
				int state;
				GetCtrlVal (panel, control, &state); 
				if(state)
				{
					SetCtrlAttribute(panel,PANEL_RB_SET_X_UNLOCK, ATTR_DIMMED, 0); 
					SetCtrlAttribute(panel,PANEL_RB_SET_X_LOCK, ATTR_DIMMED, 0);
					SetCtrlAttribute(panel,PANEL_RB_SET_Z_DOWN, ATTR_DIMMED, 0);
				}
				else
				{
					SetCtrlAttribute(panel,PANEL_RB_SET_X_UNLOCK, ATTR_DIMMED, 1); 
					SetCtrlAttribute(panel,PANEL_RB_SET_X_LOCK, ATTR_DIMMED, 1);
					SetCtrlAttribute(panel,PANEL_RB_SET_Z_DOWN, ATTR_DIMMED, 1);
				}
			}else if(control == PANEL_RB_CHECKBOX_X_JOG_SPEED ){
				int state;
				GetCtrlVal (panel, control, &state); 	  
				if(state)
				{
					Q2h.wB[0]=10;
					Q2h.wB[1]=curRobotId;
					Q2h.wB[2]=key_x_jog_high_speed;
					writeHandshake(3);	
				}
				else
				{
				   	Q2h.wB[0]=10;
					Q2h.wB[1]=curRobotId;
					Q2h.wB[2]=key_x_jog_low_speed;
					writeHandshake(3);	
				}
			}else if(control == PANEL_RB_CHECKBOX_Z_JOG_SPEED ){
				int state;
				GetCtrlVal (panel, control, &state); 	  
				if(state)
				{
					Q2h.wB[0]=10;
					Q2h.wB[1]=curRobotId;
					Q2h.wB[2]=key_z_jog_high_speed;
					writeHandshake(3);	
				}
				else
				{
				   	Q2h.wB[0]=10;
					Q2h.wB[1]=curRobotId;
					Q2h.wB[2]=key_z_jog_low_speed;
					writeHandshake(3);	
				}
			}
			
			break;
	}
	return 0;
}


int CVICALLBACK RobotManuAdj (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_LEFT_CLICK:
			if(CheckAuth(OP_ROBOT) == 0)
				return 0;
			
			if(control == PANEL_RB_JOG_UP)
			{
				Q2h.wB[0]=10;
				Q2h.wB[1]=curRobotId;
				Q2h.wB[2]=key_z_jog_reverse;
				
				writeHandshake(3);
				
				ActionLog(RB_UP_ACT_EVENT,curRobotId,0,0,0,0); 
			}
			else if(control == PANEL_RB_JOG_DOWN)
			{
				Q2h.wB[0]=10;
				Q2h.wB[1]=curRobotId;
				Q2h.wB[2]=key_z_jog_forward;
				
				writeHandshake(3);
				
				ActionLog(RB_DOWN_ACT_EVENT,curRobotId,0,0,0,0);
			}
			////////////////////////////////////////////
			else if(control == PANEL_RB_JOG_LEFT)
			{
				Q2h.wB[0]=10;
				Q2h.wB[1]=curRobotId;
				Q2h.wB[2]=key_x_jog_forward;
				
				writeHandshake(3);
				
				ActionLog(RB_LEFT_ACT_EVENT,curRobotId,0,0,0,0);
			}
			else if(control == PANEL_RB_JOG_RIGHT)
			{
				Q2h.wB[0]=10;
				Q2h.wB[1]=curRobotId;
				Q2h.wB[2]=key_x_jog_reverse;
				
				writeHandshake(3);
				
				ActionLog(RB_RIGHT_ACT_EVENT,curRobotId,0,0,0,0);
			}
			break;
		case EVENT_LEFT_CLICK_UP: 
			
			Q2h.wB[0]=10;
			Q2h.wB[1]=curRobotId;
			Q2h.wB[2]=key_jog_stop;
				
			writeHandshake(3);

			break;
	}
	return 0;
}

void initRobotPanel(int panel, int rid)
{
	ROBOT* rb = &sys->rb[rid];
	
	curRobotId = rid;
	curRid = rb->firstRid;
	
	char* title[] = {"RB1选择制程槽","RB2选择制程槽","RB3选择制程槽"};
	SetCtrlAttribute(panel,PANEL_RB_TEXTMSG_22, ATTR_CTRL_VAL, title[rid]);
	
	for(int i = rb->firstRid; i <= rb->lastRid; i++)
	{
		char tmp[32];
		if(i <= rb->lastRid-1 && sys->rtk[i].tid == sys->rtk[i+1].tid)
		{
			sprintf(tmp,"%s-1", sys->tk[sys->rtk[i].tid].name);
			InsertListItem(panel, PANEL_RB_RING, i - rb->firstRid, tmp, i); 
			i++;
			sprintf(tmp,"%s-2", sys->tk[sys->rtk[i].tid].name);
			InsertListItem(panel, PANEL_RB_RING, i - rb->firstRid, tmp, i);
		}
		else
			InsertListItem(panel, PANEL_RB_RING, i - rb->firstRid, sys->tk[sys->rtk[i].tid].name, i);
	}
	
	readTankPos(curRid);
	if(curRobotId == RB01)
	{
		SetCtrlAttribute(panel,PANEL_RB_CMD_CLEAN, ATTR_VISIBLE, 1);
		InsertListItem(panel, PANEL_RB_RING, rb->lastRid - rb->firstRid + 1, "Clean", rb->lastRid + 1); 
		
		SetCtrlVal(panel, PANEL_RB_X_UNLOCK, sys->rtk[rb->firstRid].xUnlock / 10000);
		SetCtrlVal(panel, PANEL_RB_X_LOCK, sys->rtk[rb->firstRid].xLock / 10000);
		SetCtrlVal(panel, PANEL_RB_Z_DOWN, sys->rtk[rb->firstRid].zDown / 10000);
	}
	else
	{
		SetCtrlVal(panel, PANEL_RB_X_UNLOCK, sys->rtk[rb->firstRid].xUnlock2 / 10000);
		SetCtrlVal(panel, PANEL_RB_X_LOCK, sys->rtk[rb->firstRid].xLock2 / 10000);
		SetCtrlVal(panel, PANEL_RB_Z_DOWN, sys->rtk[rb->firstRid].zDown2 / 10000);

	}
	
	//SetCtrlAttribute(panel,PANEL_RB_CMD_PUT, ATTR_VISIBLE, 0);
	
	//jog low speed
	Q2h.wB[0]=10;
	Q2h.wB[1]=curRobotId;
	Q2h.wB[2]=key_z_jog_low_speed; 
	writeHandshake(3);
	
	Q2h.wB[0]=10;
	Q2h.wB[1]=curRobotId;
	Q2h.wB[2]=key_x_jog_low_speed; 
	writeHandshake(3);
	SetCtrlVal (panel, PANEL_RB_CHECKBOX_X_JOG_SPEED, 0); 
	SetCtrlVal (panel, PANEL_RB_CHECKBOX_Z_JOG_SPEED, 0);
}

int CVICALLBACK tankChange (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_VAL_CHANGED:
			int tid;
			GetCtrlVal(panel, control, &tid);
			curRid = tid;
			readTankPos(curRid); 
			if(tid == sys->rb[curRobotId].firstRid && curRobotId > RB01){
				SetCtrlVal(panel, PANEL_RB_X_UNLOCK, sys->rtk[tid].xUnlock2 / 10000);
				SetCtrlVal(panel, PANEL_RB_X_LOCK, sys->rtk[tid].xLock2 / 10000);
				SetCtrlVal(panel, PANEL_RB_Z_DOWN, sys->rtk[tid].zDown2 / 10000);
			}
			else if(tid > sys->rb[curRobotId].lastRid){
				//SetCtrlVal(panel, PANEL_RB_X_UNLOCK, sys->rb[curRobotId].cleanPosH / 10000);
				//SetCtrlVal(panel, PANEL_RB_X_LOCK, sys->rb[curRobotId].cleanLock / 10000);
				//SetCtrlVal(panel, PANEL_RB_LOCKY, sys->rb[curRobotId].cleanPosV / 10000);
				
			}
			else{
				SetCtrlVal(panel, PANEL_RB_X_UNLOCK, sys->rtk[tid].xUnlock / 10000);
				SetCtrlVal(panel, PANEL_RB_X_LOCK, sys->rtk[tid].xLock / 10000);
				SetCtrlVal(panel, PANEL_RB_Z_DOWN, sys->rtk[tid].zDown / 10000);
			}
			
			SetCtrlAttribute(panel,PANEL_RB_CMD_PUT, ATTR_VISIBLE, 1);
			SetCtrlAttribute(panel,PANEL_RB_CMD_TAKE, ATTR_VISIBLE, 1);
			SetCtrlAttribute(panel,PANEL_RB_CMD_MOVE_LOCK, ATTR_VISIBLE, 1);
			SetCtrlAttribute(panel,PANEL_RB_CMD_MOVE_UNLOCK, ATTR_VISIBLE, 1);
				
			if(tid == sys->rb[curRobotId].firstRid)
				SetCtrlAttribute(panel,PANEL_RB_CMD_PUT, ATTR_VISIBLE, 0);
			else if(tid == sys->rb[curRobotId].lastRid)
				SetCtrlAttribute(panel,PANEL_RB_CMD_TAKE, ATTR_VISIBLE, 0);
			else if(tid > sys->rb[curRobotId].lastRid){
				SetCtrlAttribute(panel,PANEL_RB_CMD_PUT, ATTR_VISIBLE, 0);
				SetCtrlAttribute(panel,PANEL_RB_CMD_TAKE, ATTR_VISIBLE, 0);
				SetCtrlAttribute(panel,PANEL_RB_CMD_MOVE_LOCK, ATTR_VISIBLE, 0);
				SetCtrlAttribute(panel,PANEL_RB_CMD_MOVE_UNLOCK, ATTR_VISIBLE, 0);
			}
			
			break;
	}
	return 0;
}


int CVICALLBACK RobotCommand (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_LEFT_CLICK:
			if(CheckAuth(OP_ROBOT) == 0)
				return 0;
			if (!ButtonConfirm (panel,control))		
				return 0;
			switch(control)
			{
				int stat; 
				case PANEL_RB_CMD_PUT:
					Q2h.wB[0]=10;
					Q2h.wB[1]=curRobotId;
					Q2h.wB[2]=key_put;
					Q2h.wB[3]=curRid; 
					writeHandshake(4);
					
					ActionLog(RB_PUT_ACT_EVENT,curRobotId,curRid,0,0,0); 
					break;
				case PANEL_RB_CMD_TAKE:
					Q2h.wB[0]=10;
					Q2h.wB[1]=curRobotId;
					Q2h.wB[2]=key_take;
					Q2h.wB[3]=curRid;
					writeHandshake(4);

					ActionLog(RB_GET_ACT_EVENT,curRobotId,curRid,0,0,0);
					break;	
				case PANEL_RB_CMD_HOME:
					Q2h.wB[0]=10;
					Q2h.wB[1]=curRobotId;
					Q2h.wB[2]=key_home;
					writeHandshake(3);
					
					ActionLog(RB_HOME_ACT_EVENT,curRobotId,0,0,0,0);
					break;
				case PANEL_RB_CMD_MOVE_LOCK:
					Q2h.wB[0]=10;
					Q2h.wB[1]=curRobotId;
					Q2h.wB[2]=key_goto_lock;
					Q2h.wB[3]=curRid;
					writeHandshake(4);
					
					ActionLog(RB_MOVE_ACT_EVENT,curRobotId,curRid,0,0,0);
					break;
				case PANEL_RB_CMD_MOVE_UNLOCK:
					Q2h.wB[0]=10;
					Q2h.wB[1]=curRobotId;
					Q2h.wB[2]=key_goto_unlock;
					Q2h.wB[3]=curRid;
					writeHandshake(4);

					ActionLog(RB_MOVE_ACT_EVENT,curRobotId,curRid,0,0,0);
					break;
				case PANEL_RB_CMD_CLEAN:
					
					Q2h.wB[0]=10;
					Q2h.wB[1]=curRobotId;
					Q2h.wB[2]=key_clean;
					writeHandshake(3);

					ActionLog(RB_CLEAN_ACT_EVENT,curRobotId,0,0,0,0);
					break;


				case PANEL_RB_CHUCK_OFF:
					Q2h.wB[0]=10;
					Q2h.wB[1]=curRobotId;
					Q2h.wB[2]=key_chuck_on;
					writeHandshake(3);
					
					ActionLog(RB_CHUCK_ACT_EVENT,curRobotId,1,0,0,0);
					break;
				case PANEL_RB_CHUCK_ON:
					Q2h.wB[0]=10;
					Q2h.wB[1]=curRobotId;
					Q2h.wB[2]=key_chuck_off;
					
					ActionLog(RB_CHUCK_ACT_EVENT,curRobotId,0,0,0,0);
					break;
					
				case PANEL_RB_TEACH_OFF:
					Q2h.wB[0]=10;
					Q2h.wB[1]=curRobotId;
					Q2h.wB[2]=key_teach_enable;
					
					ActionLog(RB_TEACH_ACT_EVENT,curRobotId,1,0,0,0);
					break;
				case PANEL_RB_TEACH_ON:
					Q2h.wB[0]=10;
					Q2h.wB[1]=curRobotId;
					Q2h.wB[2]=key_teach_disable;
					
					ActionLog(RB_TEACH_ACT_EVENT,curRobotId,0,0,0,0);
					break;
					
				case PANEL_RB_FILL_OFF:
					Q2h.wB[0]=10;
					Q2h.wB[1]=curRobotId;
					Q2h.wB[2]=key_add_car;
					
					ActionLog(RB_CAR_ACT_EVENT,curRobotId,1,0,0,0);
					break;
				case PANEL_RB_FILL_ON:
					Q2h.wB[0]=10;
					Q2h.wB[1]=curRobotId;
					Q2h.wB[2]=key_remve_car;
					
					ActionLog(RB_CAR_ACT_EVENT,curRobotId,0,0,0,0);
					break;
			}
			break;
	}
	return 0;
}

int CVICALLBACK RobotTimer (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_TIMER_TICK:
			readRobotPos(curRobotId);
			SetCtrlVal(panel, PANEL_RB_CURR_POS_X, sys->rb[curRobotId].curPosX/10000.0);
			SetCtrlVal(panel, PANEL_RB_CURR_POS_Z, sys->rb[curRobotId].curPosY/10000.0);
			
			SetCtrlAttribute(panel,PANEL_RB_CHUCK_OFF, ATTR_VISIBLE, testBit(sys->rb[curRobotId].hsChuck,WB) > 0 ? 0 : 1);
			SetCtrlAttribute(panel,PANEL_RB_CHUCK_ON, ATTR_VISIBLE, testBit(sys->rb[curRobotId].hsChuck,WB) > 0 ? 1 : 0);
			
			SetCtrlAttribute(panel,PANEL_RB_TEACH_OFF, ATTR_VISIBLE, testBit(sys->rb[curRobotId].hsTeach,WB) > 0 ? 0 : 1);
			SetCtrlAttribute(panel,PANEL_RB_TEACH_ON, ATTR_VISIBLE, testBit(sys->rb[curRobotId].hsTeach,WB) > 0 ? 1 : 0);
			
			SetCtrlAttribute(panel,PANEL_RB_FILL_OFF, ATTR_VISIBLE, testBit(sys->rb[curRobotId].hsFill,WB) > 0 ? 0 : 1);
			SetCtrlAttribute(panel,PANEL_RB_FILL_ON, ATTR_VISIBLE, testBit(sys->rb[curRobotId].hsFill,WB) > 0 ? 1 : 0);
			break;
	}
	return 0;
}

