#include <userint.h>
#include "ild.h"
#include "type.h"  

//==============================================================================
// Constants

#define  key_up				10
#define  key_down			20
#define  key_backward		30
#define  key_forward		40
#define  key_run			50

//==============================================================================
// Types
typedef struct _PLC_ILD_STATUS{
	short x_bit;
	short y_bit;
	
}PLC_ILD_STATUS;
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


void initIldTankPanel(int panel,TANK_ID id)
{
	tid = id;
	
}

int CVICALLBACK LoadCommand (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int val;
	switch (event)
	{
		case EVENT_COMMIT:
			if(CheckAuth(OP_ROBOT) == 0)
				return 0;
			if (!ConfirmPopup("操作确认","是否确定执行您选择的功能？"))		
				return 0;
			GetCtrlVal(panel, control, &val);  
			if(val == 0)
				return 0;
			
			switch(control)
			{
				int stat; 
				case PANEL_ILD_RUN:
					Q2h.cmdWrite[0]=CMD_TANK;
					Q2h.cmdWrite[1]=tid;
					Q2h.cmdWrite[2]=key_run;
					writeCommand(3);
					
					//ActionLog(RB_PUT_ACT_EVENT,curRobotId,curTid,0,0,0); 
					break;
				case PANEL_ILD_UP:
					Q2h.cmdWrite[0]=CMD_TANK;
					Q2h.cmdWrite[1]=tid;
					Q2h.cmdWrite[2]=key_up;
					writeCommand(3);
					
					//ActionLog(RB_PUT_ACT_EVENT,curRobotId,curTid,0,0,0); 
					break;
				case PANEL_ILD_DOWN:
					Q2h.cmdWrite[0]=CMD_TANK;
					Q2h.cmdWrite[1]=tid;
					Q2h.cmdWrite[2]=key_down;
					writeCommand(3);
					
					//ActionLog(RB_PUT_ACT_EVENT,curRobotId,curTid,0,0,0); 
					break;
				case PANEL_ILD_FORWARD:
					Q2h.cmdWrite[0]=CMD_TANK;
					Q2h.cmdWrite[1]=tid;
					Q2h.cmdWrite[2]=key_forward;
					writeCommand(3);
					
					//ActionLog(RB_PUT_ACT_EVENT,curRobotId,curTid,0,0,0); 
					break;
				case PANEL_ILD_BACKWARD:
					Q2h.cmdWrite[0]=CMD_TANK;
					Q2h.cmdWrite[1]=tid;
					Q2h.cmdWrite[2]=key_backward;
					writeCommand(3);
					
					//ActionLog(RB_PUT_ACT_EVENT,curRobotId,curTid,0,0,0); 
					break;	
			}

			break;
	}
	return 0;
}

int CVICALLBACK LoadTimer (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_TIMER_TICK:
			readTankStatus();
			PLC_ILD_STATUS* stat = (PLC_ILD_STATUS*)Q2h.tkStatus;
			

			if(getBit(stat->x_bit,1) == 1 && getBit(stat->x_bit,2) == 0) {
				SetCtrlAttribute(panel,PANEL_ILD_T1A, ATTR_TOP, 70);  
			}else{
				SetCtrlAttribute(panel,PANEL_ILD_T1A, ATTR_TOP, 80);  
			}
			
			if(getBit(stat->x_bit,3) == 1 && getBit(stat->x_bit,4) == 0) {
				SetCtrlAttribute(panel,PANEL_ILD_T2A, ATTR_TOP, 70);  
			}else{
				SetCtrlAttribute(panel,PANEL_ILD_T2A, ATTR_TOP, 80);  
			}
			
			if(getBit(stat->x_bit,5) == 1 && getBit(stat->x_bit,6) == 0) {
				SetCtrlAttribute(panel,PANEL_ILD_T1A, ATTR_LEFT, 205);  
				SetCtrlAttribute(panel,PANEL_ILD_T2A, ATTR_LEFT, 275);
				SetCtrlAttribute(panel,PANEL_ILD_T1B, ATTR_LEFT, 235);
				SetCtrlAttribute(panel,PANEL_ILD_T2B, ATTR_LEFT, 305);
			}else{
				SetCtrlAttribute(panel,PANEL_ILD_T1A, ATTR_LEFT, 135);  
				SetCtrlAttribute(panel,PANEL_ILD_T2A, ATTR_LEFT, 205);
				SetCtrlAttribute(panel,PANEL_ILD_T1B, ATTR_LEFT, 165);
				SetCtrlAttribute(panel,PANEL_ILD_T2B, ATTR_LEFT, 235);
			}
			
			SetCtrlAttribute(panel, PANEL_ILD_A1, ATTR_TEXT_BGCOLOR, getBit(stat->x_bit,7)>0?0x0000FF00:0x00cccccc);
			SetCtrlAttribute(panel, PANEL_ILD_B1, ATTR_TEXT_BGCOLOR, getBit(stat->x_bit,8)>0?0x0000FF00:0x00cccccc); 
			SetCtrlAttribute(panel, PANEL_ILD_A2, ATTR_TEXT_BGCOLOR, getBit(stat->x_bit,9)>0?0x0000FF00:0x00cccccc); 
			SetCtrlAttribute(panel, PANEL_ILD_B2, ATTR_TEXT_BGCOLOR, getBit(stat->x_bit,10)>0?0x0000FF00:0x00cccccc); 
			SetCtrlAttribute(panel, PANEL_ILD_A3, ATTR_TEXT_BGCOLOR, getBit(stat->x_bit,11)>0?0x0000FF00:0x00cccccc); 
			SetCtrlAttribute(panel, PANEL_ILD_B3, ATTR_TEXT_BGCOLOR, getBit(stat->x_bit,12)>0?0x0000FF00:0x00cccccc); 
			
			SetCtrlAttribute(panel,PANEL_ILD_CAR1, ATTR_VISIBLE, getBit(stat->x_bit,7)&&getBit(stat->x_bit,8));
			SetCtrlAttribute(panel,PANEL_ILD_CAR2, ATTR_VISIBLE, getBit(stat->x_bit,9)&&getBit(stat->x_bit,10));
			SetCtrlAttribute(panel,PANEL_ILD_CAR3, ATTR_VISIBLE, getBit(stat->x_bit,11)&&getBit(stat->x_bit,12));
			
			
			SetCtrlVal(panel, PANEL_ILD_UP, getBit(stat->y_bit,0));
			SetCtrlVal(panel, PANEL_ILD_DOWN, getBit(stat->y_bit,1));
			SetCtrlVal(panel, PANEL_ILD_FORWARD, getBit(stat->y_bit,2));
			SetCtrlVal(panel, PANEL_ILD_BACKWARD, getBit(stat->y_bit,3));
			SetCtrlVal(panel, PANEL_ILD_RUN, getBit(stat->y_bit,4));
			
			break;
	}
	return 0;
}
