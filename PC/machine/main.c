#include "msie.h"
#include "pwctrl.h"
#include <formatio.h>

//==============================================================================
//
// Title:       machine
// Purpose:     A short description of the application.
//
// Created on:  2014/7/3 at と 08:21:48 by wang fang.
// Copyright:   hua. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files

#include <ansi_c.h>
#include <cvirte.h>     
#include <userint.h>
#include "toolbox.h"

#include "type.h"
#include "main.h" 
#include "robot.h"  
#include "recipe.h" 
#include "tank_diw.h" 
#include "set.h" 
#include "user.h"   
//==============================================================================
// Constants
int uiCAR[TANK_NUM] = {PANEL_INPROC_ILD,PANEL_INPROC_01,PANEL_INPROC_02,PANEL_INPROC_03,PANEL_INPROC_04,PANEL_INPROC_05,PANEL_INPROC_ULD};
int uiTM[TANK_NUM] = {PANEL_TM_ILD,PANEL_TM_01,PANEL_TM_02,PANEL_TM_03,PANEL_TM_04,PANEL_TM_05,PANEL_TM_ULD};
int uiPRCTM[TANK_NUM] = {PANEL_PRCTM_ILD,PANEL_PRCTM_01,PANEL_PRCTM_02,PANEL_PRCTM_03,PANEL_PRCTM_04,PANEL_PRCTM_05,PANEL_PRCTM_ULD}; 
int uiHeat[TANK_NUM] = {0,0,PANEL_HEATER_02,0,PANEL_HEATER_04,0,0};
int uiTemp[TANK_NUM] = {0,0,PANEL_TEMP_02,0,PANEL_TEMP_04,0,0};
int uiShut[TANK_NUM] = {0,0,PANEL_SHUT_02,0,PANEL_SHUT_04,0,0};
int uiUpLev[TANK_NUM] = {0,0,PANEL_UP_LEV_02,0,PANEL_UP_LEV_04,0,0};
int uiPump[TANK_NUM] = {0,0,0,0,0,0,0};
int uiTANK[TANK_NUM] = {0,PANEL_TNK_01,PANEL_TNK_02,PANEL_TNK_03,PANEL_TNK_04,PANEL_TNK_05,0};
int uiCARNum[TANK_NUM] = {PANEL_COUNT_ILD,PANEL_COUNT_01,PANEL_COUNT_02,PANEL_COUNT_03,PANEL_COUNT_04,PANEL_COUNT_05,PANEL_COUNT_ULD}; 
//==============================================================================
// Types

//==============================================================================
// Static global variables

static int dialogHandle;
static int msgShowTime = 180; 
//==============================================================================
// Static functions
extern struct Q02hReg Q2h;
//==============================================================================
// Global variables
int			EMOHandle;
int 		panelHandle;

SYSTEM* 	sys;  

//==============================================================================
// Global functions

//void initPlcPanel(int panel);
void initRobotPanel(int panel, int rid, int tid);
//void initTankPanel(int panel,TANK_ID tid,RTANK_ID rid1,RTANK_ID rid2);
void initSetPanel(int panel);
void initRecipePanel(int panel,int rcpId) ;
void initUserPanel (int Panel_Handle, int Control_ID);

int initSystem(void);
void unInitSystem(void);

int readAlarm(void);
int readSysStatus(void);


int main (int argc, char *argv[])
{

    int error = 0;
	int idRKC = 0;
    
    /* initialize and load resources */
    nullChk (InitCVIRTE (0, argv, 0));
    errChk (panelHandle = LoadPanel (0, "main.uir", PANEL));

	errChk(initSystem());
    
    /* display the panel and run the user interface */
    errChk (DisplayPanel (panelHandle));
    errChk (RunUserInterface ());

Error:
	
    /* clean up */
    DiscardPanel (panelHandle);
	unInitSystem();
	
    return 0;
}


//==============================================================================
// UI callback function prototypes

/// HIFN Exit when the user dismisses the panel.
int CVICALLBACK panelCB (int panel, int event, void *callbackData, int eventData1, int eventData2)
{
    if (event == EVENT_CLOSE)
	{
		if (!ConfirmPopup("操作确认","是否确定执行您选择的功能？"))		
			return 0;
		
		ActionLog(USER_EXIT_EVENT,0,0,0,0,0);
        QuitUserInterface (0);
	}

    return 0;
}

int CVICALLBACK ExitDialog (int panel, int event, void *callbackData, int eventData1, int eventData2)
{
    if (event == EVENT_CLOSE)
	{
        RemovePopup(0);
		DiscardPanel (panel);
	}
    return 0;
}

int CVICALLBACK showPanel (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			if(panel == panelHandle && control == PANEL_SHOW_RCP){
				dialogHandle = LoadPanel (0, "recipe.uir", PANEL_RCP);
				InstallPopup(dialogHandle);
				initRecipePanel(dialogHandle,Q2h.sysStatus.rcpid);
			}  
			else if(panel == panelHandle && control == PANEL_SHOW_SET){
				dialogHandle = LoadPanel (0, "set.uir", SET);
				InstallPopup(dialogHandle);
				initSetPanel(dialogHandle); 
			} 
			else if(panel == panelHandle && control == PANEL_SHOW_HIS){
				//LaunchExecutable("C:\\Program Files\\Google\\Chrome\\Application\\chrome.exe");
			}
			else if(panel == panelHandle && control == PANEL_SHOW_USER){
				dialogHandle = LoadPanel (0, "user.uir", PANEL_USER);
				PasswordCtrl_ConvertFromString (dialogHandle, PANEL_USER_OLDPWD); 
				PasswordCtrl_ConvertFromString (dialogHandle, PANEL_USER_NEWPWD);
				PasswordCtrl_ConvertFromString (dialogHandle, PANEL_USER_NEWPWD2);
				InstallPopup(dialogHandle);
				initUserPanel(dialogHandle,PANEL_USER_TABLE);
			}	 
			if(panel == panelHandle && control == PANEL_SHOW_HELP){
				//LaunchExecutable("C:\\Program Files\\Google\\Chrome\\Application\\chrome.exe localhost/wakom/web/help");
				
			}
			else if(panel == panelHandle && control == PANEL_LOGIN){
				dialogHandle = LoadPanel (0, "user.uir", PANE_LOGIN);
				PasswordCtrl_ConvertFromString (dialogHandle, PANE_LOGIN_PWD);
				InstallPopup(dialogHandle);
			} 
			else if(panel == panelHandle && control == PANEL_LOGOUT){
				sys->user.type = UNKNOW_USER_TYPE;
				ActionLog(USER_LOGOUT_EVENT,0,0,0,0,0);
			}
			else if(panel == panelHandle && control == PANEL_EXIT){
				
				if (!ConfirmPopup("操作确认","是否确定执行您选择的功能？"))		
					return 0;
				ActionLog(USER_EXIT_EVENT,0,0,0,0,0);
				QuitUserInterface (0);
			}
			

			break;
	}
	return 0;
}

int CVICALLBACK ShowManuDialog (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	
	switch (event)
	{
		case EVENT_LEFT_CLICK:
			if(control == PANEL_ROBOT1 || control == PANEL_ROBOT11){
				dialogHandle = LoadPanel (0, "robot.uir", PANEL_RB);
				InstallPopup(dialogHandle);
				initRobotPanel(dialogHandle,0,0);
			}
			else if(control == PANEL_TNK_01){
				dialogHandle = LoadPanel (0, "tank_diw.uir", PANEL_DIW);
				InstallPopup(dialogHandle);
			//	initTankPanel(dialogHandle,TANK_02,RTK_02_01,RTK_02_02);
			}/*
			else if(control == PANEL_TNK_02){
				dialogHandle = LoadPanel (0, "robot_panel.uir", PANEL_TANK);
				InstallPopup(dialogHandle);
				initTankPanel(dialogHandle,TANK_02,RTK_02_01,RTK_02_02);
			}
			else if(control == PANEL_TNK_03){
				dialogHandle = LoadPanel (0, "robot_panel.uir", PANEL_TANK);
				InstallPopup(dialogHandle);
				initTankPanel(dialogHandle,TANK_03,RTK_03_01,RTK_03_02);
			}
			else if(control == PANEL_TNK_04){
				dialogHandle = LoadPanel (0, "robot_panel.uir", PANEL_TANK);
				InstallPopup(dialogHandle);
				initTankPanel(dialogHandle,TANK_04,RTK_04_01,RTK_04_02);
			}
			else if(control == PANEL_TNK_05){
				dialogHandle = LoadPanel (0, "robot_panel.uir", PANEL_TANK);
				InstallPopup(dialogHandle);
				initTankPanel(dialogHandle,TANK_05,RTK_05_01,RTK_05_02);
			}
			else if(control == PANEL_TNK_ILD){
				dialogHandle = LoadPanel (0, "robot_panel.uir", PANEL_TANK);
				InstallPopup(dialogHandle);
				initTankPanel(dialogHandle,TANK_02,RTK_02_01,RTK_02_02);
			}
			else if(control == PANEL_ULD){
				dialogHandle = LoadPanel (0, "robot_panel.uir", PANEL_LOAD);
				InstallPopup(dialogHandle);
			}
			   */

			break;
	}
	return 0;
}

void bubble(int panel,unsigned int id,int up,int low,int r)
{
	SetCtrlAttribute(panel, id,ATTR_VISIBLE,1);
					
	int top;
	GetCtrlAttribute (panel, id, ATTR_TOP, &top);
				
	top-= rand()%r;
	if(top<up) top = low; 

	SetCtrlAttribute (panel, id, ATTR_TOP, top); 
}

int CVICALLBACK PriTimer (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	double cTM;
	char buf[128];
	

	switch (event)
	{
		case EVENT_TIMER_TICK:
			GetCurrentDateTime ( &cTM);
			FormatDateTimeString (cTM, "%Y/%m/%d\r%H:%M:%S", buf, 120);
			SetCtrlVal ( panel, PANEL_SYS_DATE, buf);
			
			sprintf(buf,"  用户：%s",sys->user.name);
			SetCtrlVal ( panel, PANEL_USERNAME, buf);
			if(sys->user.type == UNKNOW_USER_TYPE)
			{
				SetCtrlAttribute(panel, PANEL_LOGIN,ATTR_VISIBLE,1);
				SetCtrlAttribute(panel, PANEL_LOGOUT,ATTR_VISIBLE,0); 
			}
			else
			{
				SetCtrlAttribute(panel, PANEL_LOGIN,ATTR_VISIBLE,0);
				SetCtrlAttribute(panel, PANEL_LOGOUT,ATTR_VISIBLE,1);
			}
			
			if(msgShowTime > 0)
			{
				msgShowTime--;
				SetCtrlAttribute(panel, PANEL_TEXTMSG,ATTR_VISIBLE,1);
			}
			else
				SetCtrlAttribute(panel, PANEL_TEXTMSG,ATTR_VISIBLE,0);
			
			
			readAlarm();
			if(readSysStatus() < 0)
				break;
			

			sprintf(buf,"  配方：%d",Q2h.sysStatus.rcpid);
			SetCtrlVal ( panel, PANEL_RECIPEID, buf);
			
			
			///////////////////////////////////////////////////////////
			//sys bit0(auto mode)  bit1(manual mode)
			if(getBit(Q2h.sysStatus.sys_bit,0) && sys->isManual){
				ActionLog(SYS_AUTO,0,0,0,0,0); 
			}
			else if(getBit(Q2h.sysStatus.sys_bit,1) && sys->isAuto){
				ActionLog(SYS_MANUAL,0,0,0,0,0);  
			}
			sys->isAuto = getBit(Q2h.sysStatus.sys_bit,0);
			sys->isManual = getBit(Q2h.sysStatus.sys_bit,1);
			
			if(sys->isAuto)
				SetCtrlVal ( panel, PANEL_MODE, "  模式：自动");
			else
				SetCtrlVal ( panel, PANEL_MODE, "  模式：手动");
			
			///////////////////////////////////////////////////////////
			//sys bit2(rb01 car)  bit3(light)  	  bit4(buzz)  
			SetCtrlIndex(panel, PANEL_ROBOT1, getBit(Q2h.sysStatus.sys_bit,2));
			SetCtrlVal (panel, PANEL_TOGGLEBUTTON_LIGHT, getBit(Q2h.sysStatus.sys_bit,3)); 
			SetCtrlVal (panel, PANEL_TOGGLEBUTTON_BUZZ, getBit(Q2h.sysStatus.sys_bit,4));
			
			/////////////////////////////////////////////////////////////////////////////////////////////////////
			//Loader bit8(xDoorOpen) bit9(xDoorClose) 
			SetCtrlVal (panel, PANEL_DOR_ILD, (getBit(Q2h.sysStatus.tk_bit[TANK_ILD],8) > 0 && getBit(Q2h.sysStatus.tk_bit[TANK_ILD],9) == 0) ?2:1);
			
			SetCtrlAttribute(panel, PANEL_ILD_POS1A, ATTR_TEXT_BGCOLOR, getBit(Q2h.sysStatus.tk_bit[TANK_ILD],10)>0?0x0000FF00:0x00cccccc); 
			SetCtrlAttribute(panel, PANEL_ILD_POS1B, ATTR_TEXT_BGCOLOR, getBit(Q2h.sysStatus.tk_bit[TANK_ILD],11)>0?0x0000FF00:0x00cccccc);
			SetCtrlAttribute(panel, PANEL_ILD_POS2A, ATTR_TEXT_BGCOLOR, getBit(Q2h.sysStatus.tk_bit[TANK_ILD],12)>0?0x0000FF00:0x00cccccc); 
			SetCtrlAttribute(panel, PANEL_ILD_POS2B, ATTR_TEXT_BGCOLOR, getBit(Q2h.sysStatus.tk_bit[TANK_ILD],13)>0?0x0000FF00:0x00cccccc);
			SetCtrlAttribute(panel, PANEL_ILD_POS3A, ATTR_TEXT_BGCOLOR, getBit(Q2h.sysStatus.tk_bit[TANK_ILD],14)>0?0x0000FF00:0x00cccccc); 
			SetCtrlAttribute(panel, PANEL_ILD_POS3B, ATTR_TEXT_BGCOLOR, getBit(Q2h.sysStatus.tk_bit[TANK_ILD],15)>0?0x0000FF00:0x00cccccc);
			SetCtrlAttribute(panel, PANEL_INPROC_ILDA, ATTR_VISIBLE,(getBit(Q2h.sysStatus.tk_bit[TANK_ILD],10)>0&&getBit(Q2h.sysStatus.tk_bit[TANK_ILD],11)>0) ? 1:0);
			SetCtrlAttribute(panel, PANEL_INPROC_ILDB, ATTR_VISIBLE,(getBit(Q2h.sysStatus.tk_bit[TANK_ILD],12)>0&&getBit(Q2h.sysStatus.tk_bit[TANK_ILD],13)>0) ? 1:0); 
			
			
			
			
			for(int i = 0; i < TANK_NUM; i++)
			{
				SetCtrlVal(panel, uiCARNum[i], Q2h.sysStatus.tk_car_count[i]);
				
					
				///////////////////////////////////////////////
				//car  bit0
				if(getBit(Q2h.sysStatus.tk_bit[i],0) > 0)
				{
					SetCtrlAttribute(panel,uiCAR[i], ATTR_VISIBLE, 1);
					SetCtrlIndex(panel,uiCAR[i], Q2h.sysStatus.tk_remain_time[i]<=0?1:0);
					SetCtrlVal(panel, uiTM[i], Q2h.sysStatus.tk_remain_time[i]); 
				}
				else
				{
					SetCtrlAttribute(panel,uiCAR[i], ATTR_VISIBLE, 0);
					SetCtrlVal(panel, uiTM[i], 0);
				}
				SetCtrlVal(panel, uiPRCTM[i], Q2h.sysStatus.tk_recipe_time[i]);
				
				
				//////////////////////////////////////////////////////////////
				//heat bit1
				if(uiHeat[i] > 0 ){  
					SetCtrlAttribute(panel, uiHeat[i], ATTR_VISIBLE ,getBit(Q2h.sysStatus.tk_bit[i],1));
					SetCtrlVal(panel, uiTemp[i], Q2h.sysStatus.tk_temp[i]/10.0); 
				}
				
				
				////////////////////////////////////////////////////////////////
				///shut bit2(xShutOpen) bit3(xShutClose)
				if(uiShut[i] > 0)
				{
					if(getBit(Q2h.sysStatus.tk_bit[i],2) > 0 && getBit(Q2h.sysStatus.tk_bit[i],3) == 0)
						SetCtrlVal(panel, uiShut[i], 2);
					else if(getBit(Q2h.sysStatus.tk_bit[i],2) == 0 && getBit(Q2h.sysStatus.tk_bit[i],3) > 0)
						SetCtrlVal(panel, uiShut[i], 1);
					else
						SetCtrlVal(panel, uiShut[i], 3);
					
				}
				
				
				/////////////////////////////////////////////////////////////
				//pump bit4
				if(uiPump[i] > 0 )  
					SetCtrlVal(panel, uiPump[i], getBit(Q2h.sysStatus.tk_bit[i],4));
				
				
				//////////////////////////////////////////////////////////////////////////
				//tank level bit5(xLevLL) bit6(xLevL) bit7(xLevH) bit8(xLevHH) 
				if(uiTANK[i] > 0 ) 
				{
					int lev = 0;
					lev += getBit(Q2h.sysStatus.tk_bit[i],5);
					lev += getBit(Q2h.sysStatus.tk_bit[i],6);
					lev += getBit(Q2h.sysStatus.tk_bit[i],7);
					lev += getBit(Q2h.sysStatus.tk_bit[i],8);
					lev *= 20;
					SetCtrlVal(panel, uiTANK[i], lev); 
				} 
				
				//////////////////////////////////////////////////////////////////////////
				//tank  bit9(up level) 
				if(uiUpLev[i] > 0 ) 
				{
					SetCtrlVal (panel, uiUpLev[i], getBit(Q2h.sysStatus.tk_bit[i],9)); 
				}
				
				
				////////////////////////////////////////////////////////////////////////////////
				//tank ready bit10
				if(uiTANK[i] > 0) 
				{
					if(Q2h.sysStatus.tk_recipe_time[i] == 0){
						SetCtrlAttribute(panel, uiTANK[i], ATTR_LABEL_COLOR , VAL_WHITE);
						SetCtrlAttribute(panel, uiTANK[i], ATTR_LABEL_BGCOLOR ,VAL_GRAY);
					}else{
						SetCtrlAttribute(panel, uiTANK[i], ATTR_LABEL_COLOR , getBit(Q2h.sysStatus.tk_bit[i],10)==1?VAL_WHITE:VAL_BLACK); 
						SetCtrlAttribute(panel, uiTANK[i], ATTR_LABEL_BGCOLOR , getBit(Q2h.sysStatus.tk_bit[i],10)==1?VAL_BLACK:VAL_YELLOW); 
					}
				}
				
				
				
				///////////////////////////////////////////////
				//bubble
				/*if(sys->tk[i].hsBubble.wid != 0 || sys->tk[i].hsBubble.bid != 0 )
				{
					if(testBit(sys->tk[i].yBubble,RY) > 0)
					{
						SetCtrlAttribute(panel, sys->tk[i].uiBubble01, ATTR_VISIBLE,1);
						SetCtrlAttribute(panel, sys->tk[i].uiBubble02, ATTR_VISIBLE,1);
						SetCtrlAttribute(panel, sys->tk[i].uiBubble03, ATTR_VISIBLE,1);
						bubble(panel, sys->tk[i].uiBubble01,400,440,20);
						bubble(panel, sys->tk[i].uiBubble02,400,440,20);
						bubble(panel, sys->tk[i].uiBubble03,400,440,20);
					}
					else
					{
						SetCtrlAttribute(panel, sys->tk[i].uiBubble01, ATTR_VISIBLE,0);
						SetCtrlAttribute(panel, sys->tk[i].uiBubble02, ATTR_VISIBLE,0);
						SetCtrlAttribute(panel, sys->tk[i].uiBubble03, ATTR_VISIBLE,0);
					}
					
				}*/
				
				  
			}

			
			//////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//Unloader bit8(xDoorOpen) bit9(xDoorClose) 
			SetCtrlVal (panel, PANEL_DOR_ILD, (getBit(Q2h.sysStatus.tk_bit[TANK_ULD],8) > 0 && getBit(Q2h.sysStatus.tk_bit[TANK_ULD],9) == 0) ?2:1);
			SetCtrlAttribute(panel, PANEL_ULD_POS1A, ATTR_TEXT_BGCOLOR, getBit(Q2h.sysStatus.tk_bit[TANK_ULD],10) > 0?0x0000FF00:0x00cccccc); 
			SetCtrlAttribute(panel, PANEL_ULD_POS1B, ATTR_TEXT_BGCOLOR, getBit(Q2h.sysStatus.tk_bit[TANK_ULD],11) > 0?0x0000FF00:0x00cccccc);
			SetCtrlAttribute(panel, PANEL_ULD_POS2A, ATTR_TEXT_BGCOLOR, getBit(Q2h.sysStatus.tk_bit[TANK_ULD],12) > 0?0x0000FF00:0x00cccccc); 
			SetCtrlAttribute(panel, PANEL_ULD_POS2B, ATTR_TEXT_BGCOLOR, getBit(Q2h.sysStatus.tk_bit[TANK_ULD],13) > 0?0x0000FF00:0x00cccccc);
			SetCtrlAttribute(panel, PANEL_ULD_POS3A, ATTR_TEXT_BGCOLOR, getBit(Q2h.sysStatus.tk_bit[TANK_ULD],14) > 0?0x0000FF00:0x00cccccc); 
			SetCtrlAttribute(panel, PANEL_ULD_POS3B, ATTR_TEXT_BGCOLOR, getBit(Q2h.sysStatus.tk_bit[TANK_ULD],15) > 0?0x0000FF00:0x00cccccc);
			
			SetCtrlAttribute(panel, PANEL_INPROC_ULDA, ATTR_VISIBLE,(getBit(Q2h.sysStatus.tk_bit[TANK_ULD],12)>0&&getBit(Q2h.sysStatus.tk_bit[TANK_ULD],13)>0) ? 1:0);
			SetCtrlAttribute(panel, PANEL_INPROC_ULDB, ATTR_VISIBLE,(getBit(Q2h.sysStatus.tk_bit[TANK_ULD],14)>0&&getBit(Q2h.sysStatus.tk_bit[TANK_ULD],15)>0) ? 1:0); 


			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//robot
			int UIPosTop = 310.0;
			int UIPosLow = 350.0;
			int UIPosLeft = 770.0;
			int UIPosRight = UIPosLeft - 6*50.0;
			
			double xUnlock01 = 0.0;
			double xUnlock07 = 1000.0;
			
			double safeHight = 0.0;
			double zDown = 1000.0;
			
			int left = UIPosLeft + (Q2h.sysStatus.rb_h_pos[0] - xUnlock01) * (UIPosRight - UIPosLeft) / (xUnlock07 - xUnlock01);  
			int top = UIPosTop + (Q2h.sysStatus.rb_v_pos[0] - safeHight) * (UIPosTop - UIPosLow)  / (safeHight - zDown);
			if(left > 0 && left < 2000)
			{
				SetCtrlAttribute (panel, PANEL_ROBOT1, ATTR_LEFT,	left);
				SetCtrlAttribute (panel, PANEL_ROBOT11,ATTR_LEFT, 	left-1);
			}
			if(top > 0 && top < 2000)
				SetCtrlAttribute (panel, PANEL_ROBOT1, ATTR_TOP, 	top);


			break;
	}
	return 0;
}

int CVICALLBACK sysCommand (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			if(panel == panelHandle && control == PANEL_RESET_COUNT)
			{
				if(CheckAuth(OP_TANK) == 0)
					return 0;
				
				if (!ConfirmPopup("操作确认","是否确定执行您选择的功能？"))		
					return 0;
				
				Q2h.cmdWrite[0]=CMD_SYS_RESET_COUNT;
				writeCommand(1);
			}
			else if(panel == panelHandle && control == PANEL_TOGGLEBUTTON_LIGHT)
			{
				int tmp;
				Q2h.cmdWrite[0]=CMD_SYS_LIGHT;
				GetCtrlVal(panel,control, &tmp);
				if(tmp)
					Q2h.cmdWrite[1] = 1;
				else
					Q2h.cmdWrite[1] = 0;
				
				writeCommand(2);
				
			}
			else if(panel == panelHandle && control == PANEL_TOGGLEBUTTON_BUZZ)
			{
				int tmp;
				Q2h.cmdWrite[0]=CMD_SYS_BUZZ;
				GetCtrlVal(panel,control, &tmp);
				if(tmp)
					Q2h.cmdWrite[1] = 1;
				else
					Q2h.cmdWrite[1] = 0;

				writeCommand(2);
			}
			break;
	}
	return 0;
}
