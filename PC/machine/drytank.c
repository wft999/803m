//==============================================================================
//
// Title:       drytank.c
// Purpose:     A short description of the implementation.
//
// Created on:  2014/9/11 at と 08:49:59 by wang fang.
// Copyright:   hua. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files

//#include "drytank.h"
#include "robot_panel.h"
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

int CVICALLBACK DryTankTimer (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_TIMER_TICK:
			SetCtrlAttribute(panel,PANEL_DRY_PUMP_ON, ATTR_VISIBLE, testBit(sys->tk[TANK_17].hsPump,WB) > 0 ? 0 : 1);
			SetCtrlAttribute(panel,PANEL_DRY_PUMP_OFF, ATTR_VISIBLE, testBit(sys->tk[TANK_17].hsPump,WB) > 0 ? 1 : 0);
			
			SetCtrlAttribute(panel,PANEL_DRY_HEAT_ON, ATTR_VISIBLE, testBit(sys->tk[TANK_17].hsHeat,WB) > 0 ? 0 : 1);
			SetCtrlAttribute(panel,PANEL_DRY_HEAT_OFF, ATTR_VISIBLE, testBit(sys->tk[TANK_17].hsHeat,WB) > 0 ? 1 : 0);
			
			SetCtrlAttribute(panel,PANEL_DRY_SHUT_OFF, ATTR_VISIBLE, testBit(sys->tk[TANK_17].hsShutOpen,WB) > 0 ? 0 : 1);
			SetCtrlAttribute(panel,PANEL_DRY_SHUT_ON, ATTR_VISIBLE, testBit(sys->tk[TANK_17].hsShutOpen,WB) > 0 ? 1 : 0);
			
			SetCtrlAttribute(panel,PANEL_DRY_CV_OFF, ATTR_VISIBLE, testBit(sys->tk[TANK_17].hsCVOn,RB) > 0 ? 0 : 1);
			SetCtrlAttribute(panel,PANEL_DRY_CV_ON, ATTR_VISIBLE, testBit(sys->tk[TANK_17].hsCVOn,RB) > 0 ? 1 : 0);
			
			SetCtrlAttribute(panel,PANEL_DRY_AUTO_OFF, ATTR_VISIBLE, testBit(sys->tk[TANK_17].hsCVAuto,RB) > 0 ? 0 : 1);
			SetCtrlAttribute(panel,PANEL_DRY_AUTO_ON, ATTR_VISIBLE, testBit(sys->tk[TANK_17].hsCVAuto,RB) > 0 ? 1 : 0);
			
			SetCtrlAttribute(panel,PANEL_DRY_DOOR_OFF, ATTR_VISIBLE, testBit(sys->tk[TANK_17].hsCVDoor,WB) > 0 ? 0 : 1);
			SetCtrlAttribute(panel,PANEL_DRY_DOOR_ON, ATTR_VISIBLE, testBit(sys->tk[TANK_17].hsCVDoor,WB) > 0 ? 1 : 0);

			break;
	}
	return 0;
}


int CVICALLBACK DryCommand (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	if(event != EVENT_LEFT_CLICK)
		return 0;
	
	if(CheckAuth(OP_TANK) == 0)
		return 0;
	if (!ConfirmPopup("操作确认","是否确定执行您选择的功能？"))		
		return 0; 
	
	switch (control) {
		case PANEL_DRY_PUMP_OFF:
			resetBit(sys->tk[TANK_17].hsPump);
			ActionLog(TANK_PUMP_ACT_EVENT,TANK_17,1,0,0,0);
			break;
		case PANEL_DRY_PUMP_ON:
			ActionLog(TANK_PUMP_ACT_EVENT,TANK_17,0,0,0,0);
			setBit(sys->tk[TANK_17].hsPump);
			break;
		case PANEL_DRY_HEAT_OFF:
			resetBit(sys->tk[TANK_17].hsHeat);
			ActionLog(TANK_HEAT_ACT_EVENT,TANK_17,1,0,0,0);
			break;
		case PANEL_DRY_HEAT_ON:
			setBit(sys->tk[TANK_17].hsHeat);
			ActionLog(TANK_HEAT_ACT_EVENT,TANK_17,0,0,0,0);
			break;
		case PANEL_DRY_SHUT_OFF:
			setBit(sys->tk[TANK_17].hsShutOpen);
			resetBit(sys->tk[TANK_17].hsShutClose);
			ActionLog(TANK_SHUT_ACT_EVENT,TANK_17,1,0,0,0);
			break;
		case PANEL_DRY_SHUT_ON:
			setBit(sys->tk[TANK_17].hsShutClose);
			resetBit(sys->tk[TANK_17].hsShutOpen);
			ActionLog(TANK_SHUT_ACT_EVENT,TANK_17,0,0,0,0);
			break;
		case PANEL_DRY_DOOR_OFF:
			setBit(sys->tk[TANK_17].hsCVDoor);
			ActionLog(ULD_DOOR_ACT_EVENT,TANK_17,1,0,0,0); 
			break;
		case PANEL_DRY_DOOR_ON:
			resetBit(sys->tk[TANK_17].hsCVDoor);
			ActionLog(ULD_DOOR_ACT_EVENT,TANK_17,0,0,0,0); 
			break;
			
		case PANEL_DRY_AUTO_OFF:
			setBit(sys->tk[TANK_17].hsCVAuto);
			ActionLog(CV_AUTO_ACT_EVENT,TANK_17,1,0,0,0);
			break;
		case PANEL_DRY_AUTO_ON:
			resetBit(sys->tk[TANK_17].hsCVAuto);
			ActionLog(CV_AUTO_ACT_EVENT,TANK_17,0,0,0,0);
			break;
			
		case PANEL_DRY_CV_OFF:
			setBit(sys->tk[TANK_17].hsCVOn);
			ActionLog(CV_ON_ACT_EVENT,TANK_17,1,0,0,0);
			break;
		case PANEL_DRY_CV_ON:
			resetBit(sys->tk[TANK_17].hsCVOn);
			ActionLog(CV_ON_ACT_EVENT,TANK_17,0,0,0,0);
			break;	
			
	}
	
	return 0;
}

int CVICALLBACK AKFTankTimer (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_TIMER_TICK:
			SetCtrlAttribute(panel,PANEL_AKF_PUMP_ON, ATTR_VISIBLE, testBit(sys->tk[TANK_16].hsPump,WB) > 0 ? 0 : 1);
			SetCtrlAttribute(panel,PANEL_AKF_PUMP_OFF, ATTR_VISIBLE, testBit(sys->tk[TANK_16].hsPump,WB) > 0 ? 1 : 0);
			
			SetCtrlAttribute(panel,PANEL_AKF_HEAT_ON, ATTR_VISIBLE, testBit(sys->tk[TANK_16].hsHeat,WB) > 0 ? 0 : 1);
			SetCtrlAttribute(panel,PANEL_AKF_HEAT_OFF, ATTR_VISIBLE, testBit(sys->tk[TANK_16].hsHeat,WB) > 0 ? 1 : 0);
			
			
			SetCtrlAttribute(panel,PANEL_AKF_FILL_OFF, ATTR_VISIBLE, testBit(sys->rtk[RTK_16].hsFill,WB) > 0 ? 0 : 1);
			SetCtrlAttribute(panel,PANEL_AKF_FILL_ON, ATTR_VISIBLE, testBit(sys->rtk[RTK_16].hsFill,WB) > 0 ? 1 : 0);
			
			SetCtrlAttribute(panel,PANEL_AKF_AUTO_OFF, ATTR_VISIBLE, testBit(sys->tk[TANK_16].hsAKFAuto,WB) > 0 ? 0 : 1);
			SetCtrlAttribute(panel,PANEL_AKF_AUTO_ON, ATTR_VISIBLE, testBit(sys->tk[TANK_16].hsAKFAuto,WB) > 0 ? 1 : 0);
			
			SetCtrlAttribute(panel,PANEL_AKF_HOME_OFF, ATTR_VISIBLE, testBit(sys->tk[TANK_16].hsAKFHome,WB) > 0 ? 0 : 1);
			SetCtrlAttribute(panel,PANEL_AKF_HOME_ON, ATTR_VISIBLE, testBit(sys->tk[TANK_16].hsAKFHome,WB) > 0 ? 1 : 0);

			break;
	}
	return 0;
}

int CVICALLBACK AKFAdj (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	BIT bt;
	switch (event)
	{
		case EVENT_LEFT_CLICK:
			if(CheckAuth(OP_TANK) == 0)
				return 0;
			if(control == PANEL_AKF_UP) 
			{
				setBit(sys->tk[TANK_16].hsAKFUp);  	
				ActionLog(AKF_UP_ACT_EVENT,TANK_16,0,0,0,0);
			}
			else if(control == PANEL_AKF_DOWN) 
			{
				setBit(sys->tk[TANK_16].hsAKFBottom);	
				ActionLog(AKF_DOWN_ACT_EVENT,TANK_16,0,0,0,0);
			}

			break;
		case EVENT_LEFT_CLICK_UP:
			if(control == PANEL_AKF_UP) 
				resetBit(sys->tk[TANK_16].hsAKFUp);	
			else if(control == PANEL_AKF_DOWN) 
				resetBit(sys->tk[TANK_16].hsAKFBottom);

			break;
	}
	return 0;
}

int CVICALLBACK AkfCommand (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	if(event != EVENT_LEFT_CLICK)
		return 0;
	
	if(CheckAuth(OP_TANK) == 0)
		return 0;
	if (!ConfirmPopup("操作确认","是否确定执行您选择的功能？"))		
		return 0; 
	
	switch (control) {
		case PANEL_AKF_PUMP_OFF:
			resetBit(sys->tk[TANK_16].hsPump);
			ActionLog(TANK_PUMP_ACT_EVENT,TANK_16,1,0,0,0);
			break;
		case PANEL_AKF_PUMP_ON:
			ActionLog(TANK_PUMP_ACT_EVENT,TANK_16,0,0,0,0);
			setBit(sys->tk[TANK_16].hsPump);
			break;
		case PANEL_AKF_HEAT_OFF:
			resetBit(sys->tk[TANK_16].hsHeat);
			ActionLog(TANK_HEAT_ACT_EVENT,TANK_16,1,0,0,0);
			break;
		case PANEL_AKF_HEAT_ON:
			setBit(sys->tk[TANK_16].hsHeat);
			ActionLog(TANK_HEAT_ACT_EVENT,TANK_16,0,0,0,0);
			break;
		case PANEL_AKF_AUTO_OFF:
			setBit(sys->tk[TANK_16].hsAKFAuto);
			ActionLog(AKF_AUTO_ACT_EVENT,TANK_16,1,0,0,0);
			break;
		case PANEL_AKF_AUTO_ON:
			resetBit(sys->tk[TANK_16].hsAKFAuto);
			ActionLog(AKF_AUTO_ACT_EVENT,TANK_16,0,0,0,0);
			break;
			
		case PANEL_AKF_HOME_OFF:
			setBit(sys->tk[TANK_16].hsAKFHome);
			ActionLog(AKF_HOME_ACT_EVENT,TANK_16,1,0,0,0);
			break;
		case PANEL_AKF_HOME_ON:
			resetBit(sys->tk[TANK_16].hsAKFHome);
			ActionLog(AKF_HOME_ACT_EVENT,TANK_16,0,0,0,0);
			break;	
			
		case PANEL_AKF_FILL_OFF:
			setBit(sys->rtk[RTK_16].hsFill);
			ActionLog(TANK_CAR_ACT_EVENT,TANK_16,1,0,0,0);
			break;
		case PANEL_AKF_FILL_ON:
			resetBit(sys->rtk[RTK_16].hsFill);
			ActionLog(TANK_CAR_ACT_EVENT,TANK_16,0,0,0,0);
			break;	
	}
	
	return 0;
}


int CVICALLBACK LoadCommand (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	BIT bit;
	if(event != EVENT_LEFT_CLICK)
		return 0;
	
	if(CheckAuth(OP_TANK) == 0)
		return 0;
	if (!ConfirmPopup("操作确认","是否确定执行您选择的功能？"))		
		return 0; 
	
	switch (control) {
		case PANEL_LOAD_MLD_OFF:
			bit.wid = 0;bit.bid=7;
			setBit(bit);
			//ActionLog(TANK_SHUT_ACT_EVENT,TANK_01,1,0,0,0);
			break;
		case PANEL_LOAD_MLD_ON:
			bit.wid = 0;bit.bid=7;
			resetBit(bit);
			//ActionLog(TANK_SHUT_ACT_EVENT,TANK_01,0,0,0,0);
			break;
			
		case PANEL_LOAD_SHUT_OFF:
			resetBit(sys->tk[TANK_01].hsShutClose);
			setBit(sys->tk[TANK_01].hsShutOpen);
			ActionLog(TANK_SHUT_ACT_EVENT,TANK_01,1,0,0,0);
			break;
		case PANEL_LOAD_SHUT_ON:
			setBit(sys->tk[TANK_01].hsShutClose);
			resetBit(sys->tk[TANK_01].hsShutOpen);
			ActionLog(TANK_SHUT_ACT_EVENT,TANK_01,0,0,0,0);
			break;
			
		case PANEL_LOAD_DOOR_OFF:
			setBit(sys->tk[TANK_01].hsLDDoor);
			ActionLog(ULD_DOOR_ACT_EVENT,TANK_01,1,0,0,0); 
			break;
		case PANEL_LOAD_DOOR_ON:
			resetBit(sys->tk[TANK_01].hsLDDoor);
			ActionLog(ULD_DOOR_ACT_EVENT,TANK_01,0,0,0,0); 
			break;
			
		case PANEL_LOAD_AUTO_OFF:
			setBit(sys->tk[TANK_01].hsLDAuto);
			ActionLog(ULD_INIT_ACT_EVENT,TANK_01,1,0,0,0);
			break;
		case PANEL_LOAD_AUTO_ON:
			resetBit(sys->tk[TANK_01].hsLDAuto);
			ActionLog(ULD_INIT_ACT_EVENT,TANK_01,0,0,0,0);
			break;
			
		case PANEL_LOAD_FILL_OFF:
			setBit(sys->rtk[TANK_01].hsFill);
			ActionLog(TANK_CAR_ACT_EVENT,TANK_01,1,0,0,0);
			break;
		case PANEL_LOAD_FILL_ON:
			resetBit(sys->rtk[TANK_01].hsFill);
			ActionLog(TANK_CAR_ACT_EVENT,TANK_01,0,0,0,0);
			break;	
			
		case PANEL_LOAD_ONLINE_OFF:
			setBit(sys->tk[TANK_01].hsLDOnline);
			ActionLog(ULD_INIT_ACT_EVENT,TANK_01,1,0,0,0);
			break;
		case PANEL_LOAD_ONLINE_ON:
			resetBit(sys->tk[TANK_01].hsLDOnline);
			ActionLog(ULD_INIT_ACT_EVENT,TANK_01,0,0,0,0);
			break;
	}
	
	return 0;
}

		
int CVICALLBACK LoadAdj (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	char name[32];
	GetPanelAttribute(panel,ATTR_TITLE, name);
	switch (event)
	{
		case EVENT_LEFT_CLICK:
			if(CheckAuth(OP_TANK) == 0)
				return 0;
			
			if (control == PANEL_LOAD_AC_UP)
			{
				setBit(sys->tk[TANK_01].hsLDTop);
				ActionLog(ULD_UP_ACT_EVENT,TANK_01,0,0,0,0);
			}
			else if (control == PANEL_LOAD_AC_UP_2)
			{
				setBit(sys->tk[TANK_01].hsLDTop2);
				ActionLog(ULD_UP_ACT_EVENT,TANK_01,0,0,0,0);
			}
			else if (control == PANEL_LOAD_AC_DOWN)
			{
				setBit(sys->tk[TANK_01].hsLDBottom);
				ActionLog(ULD_DOWN_ACT_EVENT,TANK_01,0,0,0,0);
			}
			else if (control == PANEL_LOAD_AC_DOWN_2)
			{
				setBit(sys->tk[TANK_01].hsLDBottom2);
				ActionLog(ULD_DOWN_ACT_EVENT,TANK_01,0,0,0,0);
			}
			else if (control == PANEL_LOAD_AC_LEFT)
			{
				setBit(sys->tk[TANK_01].hsLDLeft);
				ActionLog(ULD_LEFT_ACT_EVENT,TANK_01,0,0,0,0);
			}
			else if (control == PANEL_LOAD_AC_RIGHT)
			{
				setBit(sys->tk[TANK_01].hsLDRight);
				ActionLog(ULD_RIGHT_ACT_EVENT,TANK_01,0,0,0,0);
			}
			break;
		case EVENT_LEFT_CLICK_UP:
			if (control == PANEL_LOAD_AC_UP)
			{
				resetBit(sys->tk[TANK_01].hsLDTop);
			}
			else if (control == PANEL_LOAD_AC_UP_2)
			{
				resetBit(sys->tk[TANK_01].hsLDTop2);
			}
			else if (control == PANEL_LOAD_AC_DOWN)
			{
				resetBit(sys->tk[TANK_01].hsLDBottom);
			}
			else if (control == PANEL_LOAD_AC_DOWN_2)
			{
				resetBit(sys->tk[TANK_01].hsLDBottom2);
			}
			else if (control == PANEL_LOAD_AC_LEFT)
			{
				resetBit(sys->tk[TANK_01].hsLDLeft);
			}
			else if (control == PANEL_LOAD_AC_RIGHT)
			{
				resetBit(sys->tk[TANK_01].hsLDRight);
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
			BIT bit;bit.wid = 0;bit.bid=7;
			SetCtrlAttribute(panel,PANEL_LOAD_MLD_OFF, ATTR_VISIBLE, testBit(bit,RB) > 0 ? 0 : 1);
			SetCtrlAttribute(panel,PANEL_LOAD_MLD_ON, ATTR_VISIBLE, testBit(bit,RB) > 0 ? 1 : 0);
				
			if(sys->tk[TANK_01].hsShutOpen.wid != 0 || sys->tk[TANK_01].hsShutOpen.bid != 0 )
			{
				SetCtrlAttribute(panel,PANEL_LOAD_SHUT_OFF, ATTR_VISIBLE, testBit(sys->tk[TANK_01].hsShutOpen,WB) > 0 ? 0 : 1);
				SetCtrlAttribute(panel,PANEL_LOAD_SHUT_ON, ATTR_VISIBLE, testBit(sys->tk[TANK_01].hsShutOpen,WB) > 0 ? 1 : 0);
			}
			
			if(sys->tk[TANK_01].hsLDDoor.wid != 0 || sys->tk[TANK_01].hsLDDoor.bid != 0)
			{
				SetCtrlAttribute(panel,PANEL_LOAD_DOOR_OFF, ATTR_VISIBLE, testBit(sys->tk[TANK_01].hsLDDoor,WB) > 0 ? 0 : 1);
				SetCtrlAttribute(panel,PANEL_LOAD_DOOR_ON, ATTR_VISIBLE, testBit(sys->tk[TANK_01].hsLDDoor,WB) > 0 ? 1 : 0);
			}
			
			if(sys->tk[TANK_01].hsLDAuto.wid != 0 || sys->tk[TANK_01].hsLDAuto.bid != 0)
			{
				SetCtrlAttribute(panel,PANEL_LOAD_AUTO_OFF, ATTR_VISIBLE, testBit(sys->tk[TANK_01].hsLDAuto,RB) > 0 ? 0 : 1);
				SetCtrlAttribute(panel,PANEL_LOAD_AUTO_ON, ATTR_VISIBLE, testBit(sys->tk[TANK_01].hsLDAuto,RB) > 0 ? 1 : 0);
			}
			
			if(sys->rtk[TANK_01].hsFill.wid != 0 || sys->rtk[TANK_01].hsFill.bid != 0)
			{
				SetCtrlAttribute(panel,PANEL_LOAD_FILL_OFF, ATTR_VISIBLE, testBit(sys->rtk[TANK_01].hsFill,WB) > 0 ? 0 : 1);
				SetCtrlAttribute(panel,PANEL_LOAD_FILL_ON, ATTR_VISIBLE, testBit(sys->rtk[TANK_01].hsFill,WB) > 0 ? 1 : 0);
			}
			
			if(sys->tk[TANK_01].hsLDOnline.wid != 0 || sys->tk[TANK_01].hsLDOnline.bid != 0)
			{
				SetCtrlAttribute(panel,PANEL_LOAD_ONLINE_OFF, ATTR_VISIBLE, testBit(sys->tk[TANK_01].hsLDOnline,RB) > 0 ? 0 : 1);
				SetCtrlAttribute(panel,PANEL_LOAD_ONLINE_ON, ATTR_VISIBLE, testBit(sys->tk[TANK_01].hsLDOnline,RB) > 0 ? 1 : 0);
			}
			
/*			if(sys->tk[TANK_01].hsLDInit.wid != 0 || sys->tk[TANK_01].hsLDInit.bid != 0)
			{
				SetCtrlAttribute(panel,PANEL_LOAD_INIT_OFF, ATTR_VISIBLE, testBit(sys->tk[TANK_01].hsLDInit,WB) > 0 ? 0 : 1);
				SetCtrlAttribute(panel,PANEL_LOAD_INIT_ON, ATTR_VISIBLE, testBit(sys->tk[TANK_01].hsLDInit,WB) > 0 ? 1 : 0);
			} */

			break;
	}
	return 0;
}
