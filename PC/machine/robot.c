#include <formatio.h>
#include <userint.h>
#include "robot.h"

//==============================================================================
//
// Title:       robot_panel.c
// Purpose:     A short description of the implementation.
//
// Created on:  2014/7/8 at �U�� 03:19:25 by wang fang.
// Copyright:   hua. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files

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
static TANK_ID firstTid;
static int curRobotId;
static TANK_ID curTid;
static  int on_bitmap_id;
static  int off_bitmap_id;
static int cur_type;
//==============================================================================
// Static functions

//==============================================================================
// Global variables



//==============================================================================
// Global functions
int readRobotStatus(int rid);

void updateTankPos(int panel)
{
	if(curTid == firstTid && curRobotId > RB01){
		SetCtrlVal(panel, PANEL_RB_X_UNLOCK, sys->tkPos[curTid].xUnlock2);
		SetCtrlVal(panel, PANEL_RB_X_LOCK, sys->tkPos[curTid].xLock2);
		SetCtrlVal(panel, PANEL_RB_Z_DOWN, sys->tkPos[curTid].zDown2);
	}
	else{
		SetCtrlVal(panel, PANEL_RB_X_UNLOCK, sys->tkPos[curTid].xUnlock);
		SetCtrlVal(panel, PANEL_RB_X_LOCK, sys->tkPos[curTid].xLock);
		SetCtrlVal(panel, PANEL_RB_Z_DOWN, sys->tkPos[curTid].zDown);
	}
}

void saveTkPosPC()
{
	char FileName[256];
	char Path[MAX_PATHNAME_LEN ];
	
	GetDir(Path);
	Fmt(FileName,"%s<%s\\pos.dat",Path);
	int fSAVE = OpenFile (FileName, VAL_WRITE_ONLY, VAL_TRUNCATE, VAL_BINARY);
	if(fSAVE > 0)
	{
		WriteFile(fSAVE,(char*)sys->tkPos,sizeof(sys->tkPos));
		CloseFile (	fSAVE );
	}	
}

int CVICALLBACK SavePosition (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			
			union DatCnv cnv; 
			int tmpx;
			int state;
			GetCtrlVal (panel, PANEL_RB_CHECKBOX_PERMIT_INPUT, &state);  
			
			if(CheckAuth(OP_ROBOT) == 0) {
				SetCtrlAttribute(panel,PANEL_RB_SET_X_UNLOCK, ATTR_DIMMED, 1); 
				SetCtrlAttribute(panel,PANEL_RB_SET_X_LOCK, ATTR_DIMMED, 1);
				SetCtrlAttribute(panel,PANEL_RB_SET_Z_DOWN, ATTR_DIMMED, 1); 
				
				SetCtrlVal (panel, PANEL_RB_CHECKBOX_PERMIT_SAVE, 0); 
				return 0;
			}
			if (!ConfirmPopup("����ȷ��","�Ƿ�ȷ��ִ����ѡ��Ĺ��ܣ�"))	{
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

					if(curTid == firstTid && curRobotId > 0 )//overlap tank  pos
					{
						Q2h.cmdWrite[0]=CMD_SAVE_TK_POS_PC;
						Q2h.cmdWrite[1]=curRobotId;
						Q2h.cmdWrite[2]=curTid;
						Q2h.cmdWrite[3]=key_save_pc_x_unlock2;
						Q2h.cmdWrite[4]=cnv._I16[0];
						Q2h.cmdWrite[5]=cnv._I16[1]; 
				
						if(writeCommand(6)){
							sys->tkPos[curTid].xUnlock2 = cnv._I32;
							saveTkPosPC();
						}
					}
					else //normal tank pos
					{
						Q2h.cmdWrite[0]=CMD_SAVE_TK_POS_PC;
						Q2h.cmdWrite[1]=curRobotId;
						Q2h.cmdWrite[2]=curTid;
						Q2h.cmdWrite[3]=key_save_pc_x_unlock;
						Q2h.cmdWrite[4]=cnv._I16[0];
						Q2h.cmdWrite[5]=cnv._I16[1]; 
				
						if(writeCommand(6)){
							sys->tkPos[curTid].xUnlock = cnv._I32;
							saveTkPosPC();
						}
					}	
				}
				else//get plc data
				{
					if(curTid == firstTid && curRobotId > 0 )//overlap tank  pos
					{
						Q2h.cmdWrite[0]=CMD_SAVE_TK_POS;
						Q2h.cmdWrite[1]=curRobotId;
						Q2h.cmdWrite[2]=curTid;
						Q2h.cmdWrite[3]=key_save_x_unlock2;
				
						if(writeCommand(4)){
							sys->tkPos[curTid].xUnlock2 = Q2h.rbStatus.axis[0].cur_pos;
							saveTkPosPC();
						}
					}
					else //normal tank pos
					{
						Q2h.cmdWrite[0]=CMD_SAVE_TK_POS;
						Q2h.cmdWrite[1]=curRobotId;
						Q2h.cmdWrite[2]=curTid;
						Q2h.cmdWrite[3]=key_save_x_unlock;
				
						if(writeCommand(4)){
							sys->tkPos[curTid].xUnlock = Q2h.rbStatus.axis[0].cur_pos;
							saveTkPosPC();
						}
					}
				}
				
				ActionLog(RB_POS_SAVE_ACT_EVENT,curRobotId,0,curTid,0,0); 
			}
			else if(control == PANEL_RB_SET_X_LOCK)
			{
				if(state)//maun input
				{
					GetCtrlVal(panel, PANEL_RB_X_LOCK, &tmpx);
					cnv._I32 = tmpx;

					if(curTid == firstTid && curRobotId > 0 )//overlap tank  pos
					{
						Q2h.cmdWrite[0]=CMD_SAVE_TK_POS_PC;
						Q2h.cmdWrite[1]=curRobotId;
						Q2h.cmdWrite[2]=curTid;
						Q2h.cmdWrite[3]=key_save_pc_x_lock2;
						Q2h.cmdWrite[4]=cnv._I16[0];
						Q2h.cmdWrite[5]=cnv._I16[1]; 
				
						if(writeCommand(6)){
							sys->tkPos[curTid].xLock2 = cnv._I32;
							saveTkPosPC();
						}
					}
					else //normal tank pos
					{
						Q2h.cmdWrite[0]=CMD_SAVE_TK_POS_PC;
						Q2h.cmdWrite[1]=curRobotId;
						Q2h.cmdWrite[2]=curTid;
						Q2h.cmdWrite[3]=key_save_pc_x_lock;
						Q2h.cmdWrite[4]=cnv._I16[0];
						Q2h.cmdWrite[5]=cnv._I16[1]; 
				
						if(writeCommand(6)){
							sys->tkPos[curTid].xLock = cnv._I32;
							saveTkPosPC();
						}
					}	
				}
				else//get plc data
				{
					if(curTid == firstTid && curRobotId > 0 )//overlap tank  pos
					{
						Q2h.cmdWrite[0]=CMD_SAVE_TK_POS;
						Q2h.cmdWrite[1]=curRobotId;
						Q2h.cmdWrite[2]=curTid;
						Q2h.cmdWrite[3]=key_save_x_lock2;
				
						if(writeCommand(6)){
							sys->tkPos[curTid].xLock2 = Q2h.rbStatus.axis[0].cur_pos;
							saveTkPosPC();
						}

					}
					else //normal tank pos
					{
						Q2h.cmdWrite[0]=CMD_SAVE_TK_POS;
						Q2h.cmdWrite[1]=curRobotId;
						Q2h.cmdWrite[2]=curTid;
						Q2h.cmdWrite[3]=key_save_x_lock;
				
						if(writeCommand(4)){
							sys->tkPos[curTid].xLock = Q2h.rbStatus.axis[0].cur_pos;
							saveTkPosPC();
						}

					}
				}
				
				
				ActionLog(RB_POS_SAVE_ACT_EVENT,curRobotId,1,curTid,0,0); 
				
			}else if(control == PANEL_RB_SET_Z_DOWN)
			{
				if(state)//maun input
				{
					GetCtrlVal(panel, PANEL_RB_Z_DOWN, &tmpx);
					cnv._I32 = tmpx;

					if(curTid == firstTid && curRobotId > 0 )//overlap tank  pos
					{
						Q2h.cmdWrite[0]=CMD_SAVE_TK_POS_PC;
						Q2h.cmdWrite[1]=curRobotId;
						Q2h.cmdWrite[2]=curTid;
						Q2h.cmdWrite[3]=key_save_pc_z_bottom2;
						Q2h.cmdWrite[4]=cnv._I16[0];
						Q2h.cmdWrite[5]=cnv._I16[1]; 
				
						if(writeCommand(6)){
							sys->tkPos[curTid].zDown2 = cnv._I32;
							saveTkPosPC();
						}
					}
					else //normal tank pos
					{
						Q2h.cmdWrite[0]=CMD_SAVE_TK_POS_PC;
						Q2h.cmdWrite[1]=curRobotId;
						Q2h.cmdWrite[2]=curTid;
						Q2h.cmdWrite[3]=key_save_pc_z_bottom;
						Q2h.cmdWrite[4]=cnv._I16[0];
						Q2h.cmdWrite[5]=cnv._I16[1]; 
				
						if(writeCommand(6)){
							sys->tkPos[curTid].zDown = cnv._I32;
							saveTkPosPC();
						}
					}	
				}
				else//get plc data
				{
					if(curTid == firstTid && curRobotId > 0 )//overlap tank  pos
					{
						Q2h.cmdWrite[0]=CMD_SAVE_TK_POS;
						Q2h.cmdWrite[1]=curRobotId;
						Q2h.cmdWrite[2]=curTid;
						Q2h.cmdWrite[3]=key_save_z_bottom2;
				
						if(writeCommand(4)){
							sys->tkPos[curTid].zDown2 = Q2h.rbStatus.axis[1].cur_pos;
							saveTkPosPC();
						}
					}
					else //normal tank pos
					{
						Q2h.cmdWrite[0]=CMD_SAVE_TK_POS;
						Q2h.cmdWrite[1]=curRobotId;
						Q2h.cmdWrite[2]=curTid;
						Q2h.cmdWrite[3]=key_save_z_bottom;
				
						if(writeCommand(4)){
							sys->tkPos[curTid].zDown = Q2h.rbStatus.axis[1].cur_pos;
							saveTkPosPC();
						}
					}
				}
				
				
				ActionLog(RB_POS_SAVE_ACT_EVENT,curRobotId,1,curTid,0,0); 
				
			}

	
			SetCtrlAttribute(panel,PANEL_RB_SET_X_LOCK, ATTR_DIMMED, 1); 
			SetCtrlAttribute(panel,PANEL_RB_SET_X_UNLOCK, ATTR_DIMMED, 1);
			SetCtrlAttribute(panel,PANEL_RB_SET_Z_DOWN, ATTR_DIMMED, 1); 
			SetCtrlVal (panel, PANEL_RB_CHECKBOX_PERMIT_SAVE, 0);
			
			updateTankPos(panel);

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
			if(CheckAuth(OP_ROBOT) == 0)
				return 0;
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
			}else if(control == PANEL_RB_X_JOG_SPEED ){
				int state;
				GetCtrlVal (panel, control, &state); 	  
				if(state)
				{
					Q2h.cmdWrite[0]=CMD_ROBOT;
					Q2h.cmdWrite[1]=curRobotId;
					Q2h.cmdWrite[2]=key_x_jog_high_speed;
					writeCommand(3);	
				}
				else
				{
				   	Q2h.cmdWrite[0]=CMD_ROBOT;
					Q2h.cmdWrite[1]=curRobotId;
					Q2h.cmdWrite[2]=key_x_jog_low_speed;
					writeCommand(3);	
				}
			}else if(control == PANEL_RB_Z_JOG_SPEED ){
				int state;
				GetCtrlVal (panel, control, &state); 	  
				if(state)
				{
					Q2h.cmdWrite[0]=CMD_ROBOT;
					Q2h.cmdWrite[1]=curRobotId;
					Q2h.cmdWrite[2]=key_z_jog_high_speed;
					writeCommand(3);	
				}
				else
				{
				   	Q2h.cmdWrite[0]=CMD_ROBOT;
					Q2h.cmdWrite[1]=curRobotId;
					Q2h.cmdWrite[2]=key_z_jog_low_speed;
					writeCommand(3);	
				}
			}else if(control == PANEL_RB_TEACH_BOX ){
				int state;
				GetCtrlVal (panel, control, &state); 	  
				if(state)
				{
					Q2h.cmdWrite[0]=CMD_ROBOT;
					Q2h.cmdWrite[1]=curRobotId;
					Q2h.cmdWrite[2]=key_teach_enable;
					writeCommand(3);	
					
					ActionLog(RB_TEACH_ACT_EVENT,curRobotId,1,0,0,0);
				}
				else
				{
				   	Q2h.cmdWrite[0]=CMD_ROBOT;
					Q2h.cmdWrite[1]=curRobotId;
					Q2h.cmdWrite[2]=key_teach_disable;
					writeCommand(3);
					
					ActionLog(RB_TEACH_ACT_EVENT,curRobotId,0,0,0,0);
						
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
				Q2h.cmdWrite[0]=CMD_ROBOT;
				Q2h.cmdWrite[1]=curRobotId;
				Q2h.cmdWrite[2]=key_z_jog_reverse;
				
				writeCommand(3);
				
				ActionLog(RB_UP_ACT_EVENT,curRobotId,0,0,0,0); 
			}
			else if(control == PANEL_RB_JOG_DOWN)
			{
				Q2h.cmdWrite[0]=CMD_ROBOT;
				Q2h.cmdWrite[1]=curRobotId;
				Q2h.cmdWrite[2]=key_z_jog_forward;
				
				writeCommand(3);
				
				ActionLog(RB_DOWN_ACT_EVENT,curRobotId,0,0,0,0);
			}
			////////////////////////////////////////////
			else if(control == PANEL_RB_JOG_LEFT)
			{
				Q2h.cmdWrite[0]=CMD_ROBOT;
				Q2h.cmdWrite[1]=curRobotId;
				Q2h.cmdWrite[2]=key_x_jog_forward;
				
				writeCommand(3);
				
				ActionLog(RB_LEFT_ACT_EVENT,curRobotId,0,0,0,0);
			}
			else if(control == PANEL_RB_JOG_RIGHT)
			{
				Q2h.cmdWrite[0]=CMD_ROBOT;
				Q2h.cmdWrite[1]=curRobotId;
				Q2h.cmdWrite[2]=key_x_jog_reverse;
				
				writeCommand(3);
				
				ActionLog(RB_RIGHT_ACT_EVENT,curRobotId,0,0,0,0);
			}
			break;
		case EVENT_LEFT_CLICK_UP: 
			
			Q2h.cmdWrite[0]=CMD_ROBOT;
			Q2h.cmdWrite[1]=curRobotId;
			Q2h.cmdWrite[2]=key_jog_stop;
				
			writeCommand(3);

			break;
	}
	return 0;
}


int CVICALLBACK tankChange (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_VAL_CHANGED:
			int tid;
			GetCtrlVal(panel, control, &tid);
			curTid = tid;
			updateTankPos(panel);

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
			if (!ConfirmPopup("����ȷ��","�Ƿ�ȷ��ִ����ѡ��Ĺ��ܣ�"))		
				return 0;
			switch(control)
			{
				int stat; 
				case PANEL_RB_CMD_PUT:
					Q2h.cmdWrite[0]=CMD_ROBOT;
					Q2h.cmdWrite[1]=curRobotId;
					Q2h.cmdWrite[2]=key_put;
					Q2h.cmdWrite[3]=curTid; 
					writeCommand(4);
					
					ActionLog(RB_PUT_ACT_EVENT,curRobotId,curTid,0,0,0); 
					break;
				case PANEL_RB_CMD_TAKE:
					Q2h.cmdWrite[0]=CMD_ROBOT;
					Q2h.cmdWrite[1]=curRobotId;
					Q2h.cmdWrite[2]=key_take;
					Q2h.cmdWrite[3]=curTid;
					writeCommand(4);

					ActionLog(RB_GET_ACT_EVENT,curRobotId,curTid,0,0,0);
					break;	
				case PANEL_RB_CMD_HOME:
					Q2h.cmdWrite[0]=CMD_ROBOT;
					Q2h.cmdWrite[1]=curRobotId;
					Q2h.cmdWrite[2]=key_home;
					writeCommand(3);
					
					ActionLog(RB_HOME_ACT_EVENT,curRobotId,0,0,0,0);
					break;
				case PANEL_RB_CMD_MOVE_LOCK:
					Q2h.cmdWrite[0]=CMD_ROBOT;
					Q2h.cmdWrite[1]=curRobotId;
					Q2h.cmdWrite[2]=key_goto_lock;
					Q2h.cmdWrite[3]=curTid;
					writeCommand(4);
					
					ActionLog(RB_MOVE_ACT_EVENT,curRobotId,curTid,0,0,0);
					break;
				case PANEL_RB_CMD_MOVE_UNLOCK:
					Q2h.cmdWrite[0]=CMD_ROBOT;
					Q2h.cmdWrite[1]=curRobotId;
					Q2h.cmdWrite[2]=key_goto_unlock;
					Q2h.cmdWrite[3]=curTid;
					writeCommand(4);

					ActionLog(RB_MOVE_ACT_EVENT,curRobotId,curTid,0,0,0);
					break;
				case PANEL_RB_CMD_CLEAN:
					
					Q2h.cmdWrite[0]=CMD_ROBOT;
					Q2h.cmdWrite[1]=curRobotId;
					Q2h.cmdWrite[2]=key_clean;
					writeCommand(3);

					ActionLog(RB_CLEAN_ACT_EVENT,curRobotId,0,0,0,0);
					break;


				case PANEL_RB_CHUCK_OFF:
					Q2h.cmdWrite[0]=CMD_ROBOT;
					Q2h.cmdWrite[1]=curRobotId;
					Q2h.cmdWrite[2]=key_chuck_on;
					writeCommand(3);
					
					ActionLog(RB_CHUCK_ACT_EVENT,curRobotId,1,0,0,0);
					break;
				case PANEL_RB_CHUCK_ON:
					Q2h.cmdWrite[0]=CMD_ROBOT;
					Q2h.cmdWrite[1]=curRobotId;
					Q2h.cmdWrite[2]=key_chuck_off;
					
					ActionLog(RB_CHUCK_ACT_EVENT,curRobotId,0,0,0,0);
					break;
					
				case PANEL_RB_REMOVE_CAR:
					Q2h.cmdWrite[0]=CMD_ROBOT;
					Q2h.cmdWrite[1]=curRobotId;
					Q2h.cmdWrite[2]=key_add_car;
					
					ActionLog(RB_CAR_ACT_EVENT,curRobotId,1,0,0,0);
					break;
				case PANEL_RB_ADD_CAR:
					Q2h.cmdWrite[0]=CMD_ROBOT;
					Q2h.cmdWrite[1]=curRobotId;
					Q2h.cmdWrite[2]=key_remve_car;
					
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
	int type,id;
	Point cell;  
	unsigned short data[64];
	char str[32];
	union DatCnv cnv;
	switch (event)
	{
		case EVENT_TIMER_TICK:
			if(readRobotStatus(curRobotId) <0 )
				break;
			
			////////////////////////////////////////////////////////////////////
			SetCtrlVal (panel, PANEL_RB_TEACH_BOX, getBit(Q2h.rbStatus.rb_bit,9));
			SetCtrlVal (panel, PANEL_RB_X_JOG_SPEED, getBit(Q2h.rbStatus.axis[0].bit,2)); 
			SetCtrlVal (panel, PANEL_RB_Z_JOG_SPEED, getBit(Q2h.rbStatus.axis[1].bit,2));
			/////////////////////////////////////////////////////////////////////
			
			GetTableCellVal (panel, PANEL_RB_TABLE, MakePoint (2, 1), str);
			GetTableCellRingIndexFromValue (panel, PANEL_RB_TABLE, 0, MakePoint (2, 1), &type, str);
			
			if(cur_type != -1 && cur_type != type)
				DeleteTableRows (panel, PANEL_RB_TABLE, 2, -1);
			
			
			if(type == 0)
				id=0;
			else if(type == 1)
				id=15;
			else
				id=30;
			
			if(type == 0 || type == 1){
				cell.y = 2;
				sprintf(str,"%d",Q2h.rbStatus.axis[type].cur_pos);
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "��ǰλ��");
    			cell.x = 2;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, str);

	
				cell.y = 3;
				sprintf(str,"%d",Q2h.rbStatus.axis[type].cur_speed);  
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "��ǰ�ٶ�");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, str);
				
				cell.y = 4;
				sprintf(str,"%d",Q2h.rbStatus.axis[type].address); 
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "Ŀ��λ��");
    			cell.x = 2;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, str);

	
				cell.y = 5;
				sprintf(str,"%d",Q2h.rbStatus.axis[type].speed);
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "Ŀ���ٶ�");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, str);
				
				cell.y = 6;
				sprintf(str,"%d",Q2h.rbStatus.axis[type].error_code);
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "�������");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, str);
				
				cell.y = 7;
				sprintf(str,"%d",Q2h.rbStatus.axis[type].alarm_code);
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "��������");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, str);
				
				cell.y = 8;
				sprintf(str,"%d",Q2h.rbStatus.axis[type].serve_alarm_code);
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "�ŷ���������");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, str);
				
				cell.y = 9;
				sprintf(str,"%d",Q2h.rbStatus.axis[type].action_status);
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "����״̬����");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, str);
				
				cell.y = 10;
				sprintf(str,"%d",Q2h.rbStatus.axis[type].status);
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "״̬��");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, str);
	
				cell.y = 11;
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "------------------------------");
    			cell.x = 2;
				//SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "------------------------------");
				
				
				cell.y = 12;
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "x0_QD77_ready");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CELL_TYPE, VAL_CELL_PICTURE);
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_FIT_MODE, VAL_PICT_CORNER);
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, getBit(Q2h.rbStatus.axis[type].xy,0)?on_bitmap_id:off_bitmap_id);
					
				
				cell.y = 13;
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "x1_sync");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CELL_TYPE, VAL_CELL_PICTURE);
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_FIT_MODE, VAL_PICT_CORNER);
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, getBit(Q2h.rbStatus.axis[type].xy,1)?on_bitmap_id:off_bitmap_id); 
				
				cell.y = 14;
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "x4_m_code");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CELL_TYPE, VAL_CELL_PICTURE);
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_FIT_MODE, VAL_PICT_CORNER);
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, getBit(Q2h.rbStatus.axis[type].xy,2)?on_bitmap_id:off_bitmap_id); 
				
				cell.y = 15;
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "x8_error");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CELL_TYPE, VAL_CELL_PICTURE);
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_FIT_MODE, VAL_PICT_CORNER);
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, getBit(Q2h.rbStatus.axis[type].xy,3)?on_bitmap_id:off_bitmap_id); 
				
				cell.y = 16;
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "xc_busy");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CELL_TYPE, VAL_CELL_PICTURE);
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_FIT_MODE, VAL_PICT_CORNER);
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, getBit(Q2h.rbStatus.axis[type].xy,4)?on_bitmap_id:off_bitmap_id); 
				
				cell.y = 17;
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "x10_start_complete");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CELL_TYPE, VAL_CELL_PICTURE);
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_FIT_MODE, VAL_PICT_CORNER);
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, getBit(Q2h.rbStatus.axis[type].xy,5)?on_bitmap_id:off_bitmap_id); 
				
				cell.y = 18;
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "x14_position_complete");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CELL_TYPE, VAL_CELL_PICTURE);
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_FIT_MODE, VAL_PICT_CORNER);
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, getBit(Q2h.rbStatus.axis[type].xy,6)?on_bitmap_id:off_bitmap_id); 
				
				
				cell.y = 19;
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "------------------------------");
    			cell.x = 2;
				//SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "------------------------------");
				
				cell.y = 20;
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "y0_plc_ready");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CELL_TYPE, VAL_CELL_PICTURE);
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_FIT_MODE, VAL_PICT_CORNER);
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, getBit(Q2h.rbStatus.axis[type].xy,7)?on_bitmap_id:off_bitmap_id); 
				
				cell.y = 21;
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "y1_server_on");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CELL_TYPE, VAL_CELL_PICTURE);
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_FIT_MODE, VAL_PICT_CORNER);
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, getBit(Q2h.rbStatus.axis[type].xy,8)?on_bitmap_id:off_bitmap_id); 
				
				cell.y = 22;
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "y4_stop");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CELL_TYPE, VAL_CELL_PICTURE);
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_FIT_MODE, VAL_PICT_CORNER);
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, getBit(Q2h.rbStatus.axis[type].xy,9)?on_bitmap_id:off_bitmap_id); 
				
				cell.y = 23;
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "y8_foward_jog");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CELL_TYPE, VAL_CELL_PICTURE);
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_FIT_MODE, VAL_PICT_CORNER);
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, getBit(Q2h.rbStatus.axis[type].xy,10)?on_bitmap_id:off_bitmap_id); 
				
				cell.y = 24;
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "y9_reverse_jog");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CELL_TYPE, VAL_CELL_PICTURE);
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_FIT_MODE, VAL_PICT_CORNER);
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, getBit(Q2h.rbStatus.axis[type].xy,11)?on_bitmap_id:off_bitmap_id); 
				
				cell.y = 25;
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "y10_start");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CELL_TYPE, VAL_CELL_PICTURE);
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_FIT_MODE, VAL_PICT_CORNER);
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, getBit(Q2h.rbStatus.axis[type].xy,12)?on_bitmap_id:off_bitmap_id); 
				
				cell.y = 26;
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "y14_exe_prohibit");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CELL_TYPE, VAL_CELL_PICTURE);
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_FIT_MODE, VAL_PICT_CORNER);
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, getBit(Q2h.rbStatus.axis[type].xy,13)?on_bitmap_id:off_bitmap_id); 
						
				cell.y = 27;
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "------------------------------");
    			cell.x = 2;
				//SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "------------------------------");
				
				cell.y = 28;
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "cmd_home");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CELL_TYPE, VAL_CELL_PICTURE);
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_FIT_MODE, VAL_PICT_CORNER);
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, getBit(Q2h.rbStatus.axis[type].bit,0)?on_bitmap_id:off_bitmap_id);
				
				cell.y = 29;
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "cmd_jog_forward");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CELL_TYPE, VAL_CELL_PICTURE);
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_FIT_MODE, VAL_PICT_CORNER);
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, getBit(Q2h.rbStatus.axis[type].bit,1)?on_bitmap_id:off_bitmap_id);
				
				cell.y = 30;
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "cmd_jog_high_speed");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CELL_TYPE, VAL_CELL_PICTURE);
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_FIT_MODE, VAL_PICT_CORNER);
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, getBit(Q2h.rbStatus.axis[type].bit,2)?on_bitmap_id:off_bitmap_id);
				
				cell.y = 31;
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "cmd_jog_reverse");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CELL_TYPE, VAL_CELL_PICTURE);
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_FIT_MODE, VAL_PICT_CORNER);
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, getBit(Q2h.rbStatus.axis[type].bit,3)?on_bitmap_id:off_bitmap_id);
				
				cell.y = 32;
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "cmd_position");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CELL_TYPE, VAL_CELL_PICTURE);
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_FIT_MODE, VAL_PICT_CORNER);
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, getBit(Q2h.rbStatus.axis[type].bit,4)?on_bitmap_id:off_bitmap_id);
				
				cell.y = 33;
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "is_action_enable");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CELL_TYPE, VAL_CELL_PICTURE);
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_FIT_MODE, VAL_PICT_CORNER);
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, getBit(Q2h.rbStatus.axis[type].bit,5)?on_bitmap_id:off_bitmap_id);
				
				cell.y = 34;
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "is_alarm");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CELL_TYPE, VAL_CELL_PICTURE);
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_FIT_MODE, VAL_PICT_CORNER);
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, getBit(Q2h.rbStatus.axis[type].bit,6)?on_bitmap_id:off_bitmap_id);
				
				cell.y = 35;
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "is_error");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CELL_TYPE, VAL_CELL_PICTURE);
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_FIT_MODE, VAL_PICT_CORNER);
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, getBit(Q2h.rbStatus.axis[type].bit,7)?on_bitmap_id:off_bitmap_id);
				
				cell.y = 36;
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "is_home_complete");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CELL_TYPE, VAL_CELL_PICTURE);
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_FIT_MODE, VAL_PICT_CORNER);
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, getBit(Q2h.rbStatus.axis[type].bit,8)?on_bitmap_id:off_bitmap_id);
				
				cell.y = 37;
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "is_home_start");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CELL_TYPE, VAL_CELL_PICTURE);
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_FIT_MODE, VAL_PICT_CORNER);
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, getBit(Q2h.rbStatus.axis[type].bit,9)?on_bitmap_id:off_bitmap_id);
				
				cell.y = 38;
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "is_position_complete");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CELL_TYPE, VAL_CELL_PICTURE);
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_FIT_MODE, VAL_PICT_CORNER);
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, getBit(Q2h.rbStatus.axis[type].bit,10)?on_bitmap_id:off_bitmap_id);
				
				cell.y = 39;
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "is_position_enable");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CELL_TYPE, VAL_CELL_PICTURE);
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_FIT_MODE, VAL_PICT_CORNER);
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, getBit(Q2h.rbStatus.axis[type].bit,11)?on_bitmap_id:off_bitmap_id);
				
				cell.y = 40;
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "is_position_start");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CELL_TYPE, VAL_CELL_PICTURE);
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_FIT_MODE, VAL_PICT_CORNER);
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, getBit(Q2h.rbStatus.axis[type].bit,12)?on_bitmap_id:off_bitmap_id);
				
				cell.y = 41;
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "status_home_complete");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CELL_TYPE, VAL_CELL_PICTURE);
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_FIT_MODE, VAL_PICT_CORNER);
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, getBit(Q2h.rbStatus.axis[type].bit,13)?on_bitmap_id:off_bitmap_id);
				
				cell.y = 42;
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "status_home_req");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CELL_TYPE, VAL_CELL_PICTURE);
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_FIT_MODE, VAL_PICT_CORNER);
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, getBit(Q2h.rbStatus.axis[type].bit,14)?on_bitmap_id:off_bitmap_id);
				
				
				
				
			}else{
				cell.y = 2;
				sprintf(str,"%d",Q2h.rbStatus.rb_state); 
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "rb_state");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, str);
				
				cell.y = 3;
				sprintf(str,"%d",Q2h.rbStatus.target_tid);
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "target_tid");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, str);
				
				cell.y = 4;
				sprintf(str,"%d",Q2h.rbStatus.cur_tid);
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "cur_tid");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, str);
				
				cell.y = 5;
				sprintf(str,"%d",Q2h.rbStatus.from_tid);
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "from_tid");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, str);
				
				cell.y = 6;
				sprintf(str,"%d",Q2h.rbStatus.to_tid);
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "to_tid");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, str);
				
				cell.y = 7;
				sprintf(str,"%d",Q2h.rbStatus.pc_key);
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "pc_key");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, str);
				
				cell.y = 8;
				sprintf(str,"%d",Q2h.rbStatus.pc_tid);
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "pc_tid");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, str);
				
				cell.y = 9;
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "x_car_sensor1");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CELL_TYPE, VAL_CELL_PICTURE);
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_FIT_MODE, VAL_PICT_CORNER);
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, getBit(Q2h.rbStatus.rb_bit,0)?on_bitmap_id:off_bitmap_id); 
				
				cell.y = 10;
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "x_car_sensor2");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CELL_TYPE, VAL_CELL_PICTURE);
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_FIT_MODE, VAL_PICT_CORNER);
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, getBit(Q2h.rbStatus.rb_bit,1)?on_bitmap_id:off_bitmap_id);
				
				cell.y = 11;
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "x_car_sensor3");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CELL_TYPE, VAL_CELL_PICTURE);
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_FIT_MODE, VAL_PICT_CORNER);
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, getBit(Q2h.rbStatus.rb_bit,2)?on_bitmap_id:off_bitmap_id);
				
				cell.y = 12;
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "x_car_sensor4");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CELL_TYPE, VAL_CELL_PICTURE);
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_FIT_MODE, VAL_PICT_CORNER);
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, getBit(Q2h.rbStatus.rb_bit,3)?on_bitmap_id:off_bitmap_id);
				
				cell.y = 13;
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "x_tech_h_forward");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CELL_TYPE, VAL_CELL_PICTURE);
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_FIT_MODE, VAL_PICT_CORNER);
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, getBit(Q2h.rbStatus.rb_bit,4)?on_bitmap_id:off_bitmap_id);
				
				cell.y = 14;
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "x_tech_h_reverse");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CELL_TYPE, VAL_CELL_PICTURE);
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_FIT_MODE, VAL_PICT_CORNER);
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, getBit(Q2h.rbStatus.rb_bit,5)?on_bitmap_id:off_bitmap_id);
				
				cell.y = 15;
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "x_tech_v_forward");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CELL_TYPE, VAL_CELL_PICTURE);
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_FIT_MODE, VAL_PICT_CORNER);
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, getBit(Q2h.rbStatus.rb_bit,6)?on_bitmap_id:off_bitmap_id);
				
				cell.y = 16;
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "x_tech_v_reverse");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CELL_TYPE, VAL_CELL_PICTURE);
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_FIT_MODE, VAL_PICT_CORNER);
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, getBit(Q2h.rbStatus.rb_bit,7)?on_bitmap_id:off_bitmap_id);
				
				cell.y = 17;
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "wait_rb_inter_lock");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CELL_TYPE, VAL_CELL_PICTURE);
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_FIT_MODE, VAL_PICT_CORNER);
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, getBit(Q2h.rbStatus.rb_bit,8)?on_bitmap_id:off_bitmap_id);
				
				cell.y = 18;
				if(cur_type != type) 
					InsertTableRows (panel, PANEL_RB_TABLE, cell.y, 1, VAL_CELL_STRING); 
				cell.x = 1;
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, "is_tech_box_enable");
    			cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CELL_TYPE, VAL_CELL_PICTURE);
    			SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_FIT_MODE, VAL_PICT_CORNER);
				SetTableCellAttribute(panel, PANEL_RB_TABLE, cell, ATTR_CTRL_VAL, getBit(Q2h.rbStatus.rb_bit,9)?on_bitmap_id:off_bitmap_id);
			}


			cur_type = type; 
			break;
	}
	return 0;
}

void initRobotPanel(int panel, int rid, int tid)
{
	cur_type = -1;
	
	curRobotId = rid;
	curTid = tid;
	firstTid =  tid;
	
//	char* title[] = {"�ֱ�1�Ƴ̲�","�ֱ�2�Ƴ̲�","�ֱ�3�Ƴ̲�"};
//	SetCtrlAttribute(panel,PANEL_RB_TEXTMSG_22, ATTR_CTRL_VAL, title[rid]);
	
	char* tankName[]={"Loader","DIW1","ACID","DIW2","KOH","DIW3","Unloader"};
	
	int len = sizeof(tankName)/sizeof(char*);
	for(int i = 0; i < len; i++)
	{
		InsertListItem(panel, PANEL_RB_RING, i, tankName[i], i+firstTid);
	}
	
	
	//////////////////////////////////////////////////////////////////////////
    GetCtrlDisplayBitmap (panel, PANEL_RB_LEDOFF, 0, &off_bitmap_id);
    GetCtrlDisplayBitmap (panel, PANEL_RB_LEDON, 0, &on_bitmap_id);
	
	updateTankPos(panel);	
    
}

