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
//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// Static global variables

static int dialogHandle;
static int msgShowTime = 180; 
//==============================================================================
// Static functions

//==============================================================================
// Global variables
int			EMOHandle;
int 		panelHandle;

SYSTEM* 	sys;  

SYS_STATUS  sysStatus = UNKNOW_SYS_STATUS;
//==============================================================================
// Global functions

//void initPlcPanel(int panel);
void initRobotPanel(int panel, int rid, int tid);
void initTankPanel(int panel,TANK_ID tid,RTANK_ID rid1,RTANK_ID rid2);
void initSetPanel(int panel);
void initRecipePanel(int panel,int rcpId) ;
void initUserPanel (int Panel_Handle, int Control_ID);

int initSystem(void);
void unInitSystem(void);

void closePlc(void);
int openPlc(void);
int readAlarm(void);


int main (int argc, char *argv[])
{

    int error = 0;
	int idRKC = 0;
    
    /* initialize and load resources */
    nullChk (InitCVIRTE (0, argv, 0));
    errChk (panelHandle = LoadPanel (0, "main.uir", PANEL));


	errChk(initSystem());
	errChk(openPlc());
	ActionLog(SYS_START,0,0,0,0,0); 
    
    /* display the panel and run the user interface */
    errChk (DisplayPanel (panelHandle));
    errChk (RunUserInterface ());

Error:
	
    /* clean up */
	closePlc();
	
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
		if (!ButtonConfirm (panel,PANEL_TNK_02))		
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
				initRecipePanel(dialogHandle,0);
			}  /*
			else if(panel == panelHandle && control == PANEL_SHOW_SET){
				dialogHandle = LoadPanel (0, "robot_panel.uir", PANEL_SET);
				InstallPopup(dialogHandle);
				initSetPanel(dialogHandle); 
			}
			else if(panel == panelHandle && control == PANEL_SHOW_HIS){
				LaunchExecutable("C:\\Program Files\\Google\\Chrome\\Application\\chrome.exe");
			}
			else if(panel == panelHandle && control == PANEL_SHOW_USER){
				dialogHandle = LoadPanel (0, "robot_panel.uir", PANEL_USER);
				PasswordCtrl_ConvertFromString (dialogHandle, PANEL_USER_OLDPWD); 
				PasswordCtrl_ConvertFromString (dialogHandle, PANEL_USER_NEWPWD);
				PasswordCtrl_ConvertFromString (dialogHandle, PANEL_USER_NEWPWD2);
				InstallPopup(dialogHandle);
				initUserPanel(dialogHandle,PANEL_USER_TABLE);
			}	 
			if(panel == panelHandle && control == PANEL_SHOW_HELP){
				LaunchExecutable("C:\\Program Files\\Google\\Chrome\\Application\\chrome.exe localhost/wakom/web/help");
				
			}
			else if(panel == panelHandle && control == PANEL_LOGIN){
				dialogHandle = LoadPanel (0, "robot_panel.uir", PANELOGIN);
				PasswordCtrl_ConvertFromString (dialogHandle, PANELOGIN_PWD);
				InstallPopup(dialogHandle);
			} */
			else if(panel == panelHandle && control == PANEL_LOGOUT){
				sys->user.type = UNKNOW_USER_TYPE;
				ActionLog(USER_LOGOUT_EVENT,0,0,0,0,0);
			}
			else if(panel == panelHandle && control == PANEL_EXIT){
				
				if (!ButtonConfirm (panel,PANEL_TNK_02))		
					return 0;
				ActionLog(USER_EXIT_EVENT,0,0,0,0,0);
				QuitUserInterface (0);
			}
			else if(panel == panelHandle && control == PANEL_RESET_COUNT)
			{
				if(CheckAuth(OP_TANK) == 0)
					return 0;
				
				if (!ButtonConfirm (panel,PANEL_TNK_02))		
					return 0;
			

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
			if(control == PANEL_ROBOT1){
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


int ButtonConfirm (int _pnl, int _ctrl)
{
	return ConfirmPopup("操作确认","是否确定执行您选择的功能？");
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
			
			readAlarm();
			
			if(msgShowTime > 0)
			{
				msgShowTime--;
				SetCtrlAttribute(panel, PANEL_TEXTMSG,ATTR_VISIBLE,1);
			}
			else
				SetCtrlAttribute(panel, PANEL_TEXTMSG,ATTR_VISIBLE,0);
			
			SetCtrlVal ( panel, PANEL_USERNAME, sys->user.name);
			
/*			if(testBit(sys->hsAuto,RB) > 0 && sysStatus == MANUAL_STATUS){
				ActionLog(SYS_AUTO,0,0,0,0,0); 
			}
			else if(testBit(sys->hsAuto,RB) == 0 && sysStatus == AUTO_STATUS){
				ActionLog(SYS_MANUAL,0,0,0,0,0);  
			}
			
			if(testBit(sys->hsAuto,RB) > 0){
				SetCtrlVal ( panel, PANEL_USERTYPE, "笆篈"); 
				sysStatus = AUTO_STATUS;
			}
			else{
				sysStatus = MANUAL_STATUS;  
				SetCtrlVal ( panel, PANEL_USERTYPE, "も笆篈"); 
			}  */
			
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
			
/*			GetCurrentDateTime ( &cTM);
			FormatDateTimeString (cTM, "%Y/%m/%d\r%H:%M:%S", buf, 120);
			//SetCtrlVal ( panel, PANEL_SYS_DATE, buf);
			
			/////////////////////////////////////////////////////////////////////////////////////////////////////
			//hs fill
			SetCtrlAttribute(panel, PANEL_ILD_POS1A, ATTR_TEXT_BGCOLOR, testBit(sys->tk[TANK_01].xPosA1,RX)>0?0x0000FF00:0x00cccccc); 
			SetCtrlAttribute(panel, PANEL_ILD_POS1B, ATTR_TEXT_BGCOLOR, testBit(sys->tk[TANK_01].xPosB1,RX)>0?0x0000FF00:0x00cccccc);
			SetCtrlAttribute(panel, PANEL_ILD_POS2A, ATTR_TEXT_BGCOLOR, testBit(sys->tk[TANK_01].xPosA2,RX)>0?0x0000FF00:0x00cccccc); 
			SetCtrlAttribute(panel, PANEL_ILD_POS2B, ATTR_TEXT_BGCOLOR, testBit(sys->tk[TANK_01].xPosB2,RX)>0?0x0000FF00:0x00cccccc);
			SetCtrlAttribute(panel, PANEL_ILD_POS3A, ATTR_TEXT_BGCOLOR, testBit(sys->tk[TANK_01].xPosA3,RX)>0?0x0000FF00:0x00cccccc); 
			SetCtrlAttribute(panel, PANEL_ILD_POS3B, ATTR_TEXT_BGCOLOR, testBit(sys->tk[TANK_01].xPosB3,RX)>0?0x0000FF00:0x00cccccc);
			
	
			SetCtrlIndex(panel, PANEL_INPROC_ILDA, (testBit(sys->tk[TANK_01].xPosA1,RX)>0&&testBit(sys->tk[TANK_01].xPosB1,RX)>0) ? 1:0);
			SetCtrlIndex(panel, PANEL_INPROC_ILDB, (testBit(sys->tk[TANK_01].xPosA2,RX)>0&&testBit(sys->tk[TANK_01].xPosB2,RX)>0) ? 1:0); 
		*/	
			for(int i = 0; i < PRO_TANK_NUM+AUX_TANK_NUM; i++)
			{
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
				
				//heat
//				if(sys->tk[i].hsHeat.wid != 0 || sys->tk[i].hsHeat.bid != 0 )  
//					SetCtrlAttribute(panel, sys->tk[i].uiHeat, ATTR_VISIBLE ,(testBit(sys->tk[i].yHeat,RY) > 0)?1:0);
/*				
				//pump
				if(sys->tk[i].hsPump.wid != 0 || sys->tk[i].hsPump.bid != 0 )  
					SetCtrlVal(panel, sys->tk[i].uiPump, (testBit(sys->tk[i].yPump,RY) > 0)?1:0);
				
				//tank
				if(sys->tk[i].xLevH.wid != 0 || sys->tk[i].xLevH.bid != 0 ) 
				{
					int lev = 0;
					lev += (testBit(sys->tk[i].xLevLL,RX) > 0)?1:0;
					lev += (testBit(sys->tk[i].xLevL,RX) > 0)?1:0;
					lev += (testBit(sys->tk[i].xLevH,RX) > 0)?1:0;
					lev += (testBit(sys->tk[i].xLevHH,RX) > 0)?1:0;
					lev *= 20;
				//	SetCtrlVal(panel, sys->tk[i].uiTANK, lev); 
				} */

				///shut
				/*if(sys->tk[i].uiShut > 0)
				{
					if(testBit(sys->tk[i].xShutOpen,RX) > 0 && testBit(sys->tk[i].xShutClose,RX) == 0)
						SetCtrlVal(panel, sys->tk[i].uiShut, 2);
					else if(testBit(sys->tk[i].xShutOpen,RX) == 0 && testBit(sys->tk[i].xShutClose,RX) > 0)
						SetCtrlVal(panel, sys->tk[i].uiShut, 1);
					else
						SetCtrlVal(panel, sys->tk[i].uiShut, 3);
					
				}  
				
				///bypass and car number
				if(i < PRO_TANK_NUM)
				{
					unsigned char Strcount[16];
					//Fmt(Strcount, "%s<%i", sys->tk[i].carNumber);
					//SetCtrlVal(panel, sys->tk[i].uiCARNum, Strcount);
					
					if(sys->tk[i].rcp.ProcTM == 0)
					{
						//SetCtrlAttribute(panel, sys->tk[i].uiTANK, ATTR_LABEL_COLOR , VAL_WHITE);
						//SetCtrlAttribute(panel, sys->tk[i].uiTANK, ATTR_LABEL_BGCOLOR ,VAL_GRAY);
					}
					else
					{
						//SetCtrlAttribute(panel, sys->tk[i].uiTANK, ATTR_LABEL_COLOR , isTankReady(i)==1?VAL_WHITE:VAL_BLACK); 
						//SetCtrlAttribute(panel, sys->tk[i].uiTANK, ATTR_LABEL_BGCOLOR , isTankReady(i)==1?VAL_BLACK:VAL_YELLOW); 
					}
					
					if(i == TANK_02 || i == TANK_04 || i == TANK_07 || i == TANK_11 )
					{
						//DosingByTime(i,cTM);
						//DosingByRun(i);
					}
				} */
			}
			
			///////////////////////////////////////////////
			//car
/*			for(int i = 0; i < RTANK_NUM; i++)
			{
				if(testBit(sys->rtk[i].hsFill,WB) > 0)
				{
					SetCtrlAttribute(panel,sys->rtk[i].uiCAR, ATTR_VISIBLE, 1);
					if(sys->rtk[i].car.iPrcTM[sys->rtk[i].tid] >0 && cTM > (sys->rtk[i].car.iPrcTM[sys->rtk[i].tid] + sys->tk[sys->rtk[i].tid].rcp.ProcTM))
					{
						SetCtrlIndex(panel,sys->rtk[i].uiCAR, 2);
					}
					else
					{
						SetCtrlIndex(panel,sys->rtk[i].uiCAR, 1); 
					}
					
					if(sys->rtk[i].car.iPrcTM[sys->rtk[i].tid] >0 )
						SetCtrlVal(panel, sys->rtk[i].uiTM, (int)(sys->rtk[i].car.iPrcTM[sys->rtk[i].tid] + sys->tk[sys->rtk[i].tid].rcp.ProcTM - cTM));
					else
					{
						sys->rtk[i].car.iPrcTM[sys->rtk[i].tid] = cTM;
						SetCtrlVal(panel, sys->rtk[i].uiTM, 0);
					}
				}
				else
				{
					SetCtrlAttribute(panel,sys->rtk[i].uiCAR, ATTR_VISIBLE, 0);
					SetCtrlVal(panel, sys->rtk[i].uiTM, 0);
				}
			}



			
			SetCtrlAttribute(panel, PANEL_ULD_POS1A, ATTR_TEXT_BGCOLOR, testBit(sys->tk[TANK_17].xPosA1,RX) > 0?0x0000FF00:0x00cccccc); 
			SetCtrlAttribute(panel, PANEL_ULD_POS1B, ATTR_TEXT_BGCOLOR, testBit(sys->tk[TANK_17].xPosB1,RX) > 0?0x0000FF00:0x00cccccc);
			SetCtrlAttribute(panel, PANEL_ULD_POS2A, ATTR_TEXT_BGCOLOR, testBit(sys->tk[TANK_17].xPosA2,RX) > 0?0x0000FF00:0x00cccccc); 
			SetCtrlAttribute(panel, PANEL_ULD_POS2B, ATTR_TEXT_BGCOLOR, testBit(sys->tk[TANK_17].xPosB2,RX) > 0?0x0000FF00:0x00cccccc);
			SetCtrlAttribute(panel, PANEL_ULD_POS3A, ATTR_TEXT_BGCOLOR, testBit(sys->tk[TANK_17].xPosA3,RX) > 0?0x0000FF00:0x00cccccc); 
			SetCtrlAttribute(panel, PANEL_ULD_POS3B, ATTR_TEXT_BGCOLOR, testBit(sys->tk[TANK_17].xPosB3,RX) > 0?0x0000FF00:0x00cccccc);

			 
			SetCtrlIndex(panel, PANEL_ROBOT1, testBit(sys->rb[0].hsFill,WB) > 0 ? 1:0);		*/

			
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//robot
/*			int left = sys->rb[0].UIPosLeft + (sys->rb[0].curPosX - sys->rtk[RTK_01].xUnlock) * (sys->rb[0].UIPosRight - sys->rb[0].UIPosLeft) / (sys->rtk[RTK_06].xUnlock - sys->rtk[RTK_01].xUnlock);  
			int top = sys->rb[0].UIPosTop + (sys->rb[0].curPosY - sys->rb[0].safeHight) * (sys->rb[0].UIPosTop - sys->rb[0].UIPosLow)  / (sys->rb[0].safeHight - sys->rtk[RTK_01].zDown);
			if(left > 0 && left < 2000)
			{
				SetCtrlAttribute (panel, PANEL_ROBOT1, ATTR_LEFT,	left);
				SetCtrlAttribute (panel, PANEL_ROBOT11,ATTR_LEFT, 	left-1);
			}
			if(top > 0 && top < 2000)
				SetCtrlAttribute (panel, PANEL_ROBOT1, ATTR_TOP, 	top); 	   */
			

			
			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//

//			SetCtrlVal (panel, PANEL_DOR_ILD, (testBit(sys->tk[TANK_01].xDoorOpen,RX) > 0 && testBit(sys->tk[TANK_01].xDoorClose,RX) == 0) ?2:1);
//			SetCtrlVal (panel, PANEL_DOR_ULD, (testBit(sys->tk[TANK_17].xDoorOpen,RX) > 0 && testBit(sys->tk[TANK_17].xDoorClose,RX) == 0) ?2:1); 

			//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//
/*			int buzz;
			GetCtrlVal ( panelHandle, PANEL_BUZZ, &buzz);
			if(buzz)
				setBit(sys->hsAlarmBuzzOff);
			else
				resetBit(sys->hsAlarmBuzzOff);
			
			GetCtrlVal ( panelHandle, PANEL_LIGHT, &buzz);
			if(buzz)
			{
				setBit(sys->hsLight1);
				setBit(sys->hsLight2); 
				setBit(sys->hsLight3); 
				setBit(sys->hsLight4); 
			}
			else
			{
				resetBit(sys->hsLight1);
				resetBit(sys->hsLight2);
				resetBit(sys->hsLight3);
				resetBit(sys->hsLight4);
			} */
			
			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//temp
		/*	SetCtrlVal (panel, PANEL_TEMP02, sys->tk[TANK_02].curTemp);
			SetCtrlVal (panel, PANEL_TEMP03, sys->tk[TANK_03].curTemp);
			SetCtrlVal (panel, PANEL_TEMP04, sys->tk[TANK_04].curTemp);

			
			SetCtrlVal (panel, PANEL_UP_LEV_02, testBit(sys->tk[TANK_02].xLevUP,RX)>0?1:0);
			SetCtrlVal (panel, PANEL_UP_LEV_04, testBit(sys->tk[TANK_04].xLevUP,RX)>0?1:0);
			SetCtrlVal (panel, PANEL_UP_LEV_05, testBit(sys->tk[TANK_05].xLevUP,RX)>0?1:0);
			SetCtrlVal (panel, PANEL_UP_LEV_07, testBit(sys->tk[TANK_07].xLevUP,RX)>0?1:0);
			SetCtrlVal (panel, PANEL_UP_LEV_08, testBit(sys->tk[TANK_08].xLevUP,RX)>0?1:0);
			SetCtrlVal (panel, PANEL_UP_LEV_14, testBit(sys->tk[TANK_14].xLevUP,RX)>0?1:0);
			SetCtrlVal (panel, PANEL_UP_LEV_15, testBit(sys->tk[TANK_15].xLevUP,RX)>0?1:0);
			
			 */

			break;
	}
	return 0;
}

