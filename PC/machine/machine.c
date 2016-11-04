#include "main.h"
#include "msie.h"
#include "pwctrl.h"
#include <formatio.h>
#include "robot_panel.h"

//==============================================================================
//
// Title:       machine
// Purpose:     A short description of the application.
//
// Created on:  2014/7/3 at 上午 08:21:48 by wang fang.
// Copyright:   hua. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files

#include <ansi_c.h>
#include <cvirte.h>     
#include <userint.h>
#include "machine.h"
#include "toolbox.h"

#include "type.h"

#include "robot.h"  

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
extern int g_setupMake;
extern BIT g_makeBit;
//==============================================================================
// Global variables
int			EMOHandle;
int 		panelHandle;
int 		g_exitThread = 0;
SYSTEM* 	sys;  

SYS_STATUS  sysStatus = UNKNOW_SYS_STATUS;
//==============================================================================
// Global functions
int CVICALLBACK simThread (void *Data);
int CVICALLBACK plcThread (void *Data);
int CVICALLBACK rkcThread (void *Data);
int CVICALLBACK robotThread (void *pData);

//void initPlcPanel(int panel);
void initRobotPanel(int panel, int rid);
void initTankPanel(int panel,TANK_ID tid,RTANK_ID rid1,RTANK_ID rid2);
void initSetPanel(int panel);
void initRecipePanel(int panel);
void initUserPanel (int Panel_Handle, int Control_ID);

int initSystem(void);
void unInitSystem(void);

void closePlc(void);
int openPlc(void);


int main (int argc, char *argv[])
{

	
    int error = 0;
	int idPLC = 0;  
	int idRKC = 0;
    
    /* initialize and load resources */
    nullChk (InitCVIRTE (0, argv, 0));
    errChk (panelHandle = LoadPanel (0, "machine.uir", PANEL));


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
		if (!ButtonConfirm (panel,PANEL_TNK_11))		
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
				dialogHandle = LoadPanel (0, "robot_panel.uir", PANEL_RCP);
				InstallPopup(dialogHandle);
				initRecipePanel(dialogHandle);
			}
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
			else if(panel == panelHandle && control == PANEL_SHOW_HELP){
				LaunchExecutable("C:\\Program Files\\Google\\Chrome\\Application\\chrome.exe localhost/wakom/web/help");
				
			}
			else if(panel == panelHandle && control == PANEL_LOGIN){
				dialogHandle = LoadPanel (0, "robot_panel.uir", PANELOGIN);
				PasswordCtrl_ConvertFromString (dialogHandle, PANELOGIN_PWD);
				InstallPopup(dialogHandle);
			}
			else if(panel == panelHandle && control == PANEL_LOGOUT){
				sys->user.type = UNKNOW_USER_TYPE;
				ActionLog(USER_LOGOUT_EVENT,0,0,0,0,0);
			}
			else if(panel == panelHandle && control == PANEL_EXIT){
				
				if (!ButtonConfirm (panel,PANEL_TNK_11))		
					return 0;
				ActionLog(USER_EXIT_EVENT,0,0,0,0,0);
				QuitUserInterface (0);
			}
			else if(panel == panelHandle && control == PANEL_RESET_COUNT)
			{
				if(CheckAuth(OP_TANK) == 0)
					return 0;
				
				if (!ButtonConfirm (panel,PANEL_TNK_11))		
					return 0;
			
				for(int i = 0; i <= TANK_17; i++)
				{
					sys->tk[i].carNumber = 0;
					sys->tk[i].runAC1Dos = 0;
					sys->tk[i].runAC2Dos = 0;
					sys->tk[i].runAC3Dos = 0;
					sys->tk[i].runAC4Dos = 0;
					
					sys->tk[i].PdRun = 0;
				}
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
				initRobotPanel(dialogHandle,0);
			}
			else if(control == PANEL_TNK_ILD){
				dialogHandle = LoadPanel (0, "robot_panel.uir", PANEL_TANK);
				InstallPopup(dialogHandle);
				initTankPanel(dialogHandle,TANK_02,RTK_02_01,RTK_02_02);
			}
			else if(control == PANEL_TNK_01){
				dialogHandle = LoadPanel (0, "robot_panel.uir", PANEL_TANK);
				InstallPopup(dialogHandle);
				initTankPanel(dialogHandle,TANK_02,RTK_02_01,RTK_02_02);
			}
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
			else if(control == PANEL_ULD){
				dialogHandle = LoadPanel (0, "robot_panel.uir", PANEL_LOAD);
				InstallPopup(dialogHandle);
			}


			break;
	}
	return 0;
}


int ButtonConfirm (int _pnl, int _ctrl)
{
	return ConfirmPopup("紱釬�溜�","岆瘁�毓併棣陑�恁寁腔髡夔ˋ");
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

void DosingByRun(TANK_ID tid)
{
	if(testBit(sys->hsAuto,RB) == 0)
		return;
	if(sys->rcp.isReady == 0)
		return;
	
	int carNumber = sys->tk[tid].carNumber;
	
	if(tid == TANK_04)
	{
		carNumber += sys->tk[TANK_05].carNumber; 
	}
	else if(tid == TANK_05)
	{
		tid = TANK_04;
		carNumber += sys->tk[TANK_04].carNumber; 
	}
	else if(tid == TANK_07)
	{
		carNumber += sys->tk[TANK_08].carNumber; 
	}
	else if(tid == TANK_08)
	{
		tid = TANK_07;
		carNumber += sys->tk[TANK_07].carNumber; 
	}
	
	if(sys->tk[tid].rcp.DosCH1Run > 0 && testBit(sys->tk[tid].hsAC1Dos,WB) == 0)
	{
		if(carNumber - sys->tk[tid].runAC1Dos >= sys->tk[tid].rcp.DosCH1Run)
		{
			sys->tk[tid].runAC1Dos = carNumber;
			setBit(sys->tk[tid].hsAC1Dos);
			DosingLog(DOSING_BY_RUN,tid,1,carNumber);
		}
	}
	
	if(sys->tk[tid].rcp.DosCH2Run > 0 && testBit(sys->tk[tid].hsAC2Dos,WB) == 0)
	{
		if(carNumber - sys->tk[tid].runAC2Dos >= sys->tk[tid].rcp.DosCH2Run)
		{
			sys->tk[tid].runAC2Dos = carNumber;
			setBit(sys->tk[tid].hsAC2Dos);
			DosingLog(DOSING_BY_RUN,tid,2,carNumber);
		}
	}
	
	if(sys->tk[tid].rcp.DosCH3Run > 0 && testBit(sys->tk[tid].hsAC3Dos,WB) == 0)
	{
		if(carNumber - sys->tk[tid].runAC3Dos >= sys->tk[tid].rcp.DosCH3Run)
		{
			sys->tk[tid].runAC3Dos = carNumber;
			setBit(sys->tk[tid].hsAC3Dos);
			DosingLog(DOSING_BY_RUN,tid,3,carNumber);
		}
	}
	
	if(sys->tk[tid].rcp.DosCH4Run > 0 && testBit(sys->tk[tid].hsAC4Dos,WB) == 0)
	{
		if(carNumber - sys->tk[tid].runAC4Dos >= sys->tk[tid].rcp.DosCH4Run)
		{
			sys->tk[tid].runAC4Dos = carNumber;
			setBit(sys->tk[tid].hsAC4Dos);
			DosingLog(DOSING_BY_RUN,tid,4,carNumber);
		}
	}

	
}

void DosingByTime(TANK_ID tid, double cTM)
{
	if(testBit(sys->hsAuto,RB) == 0)
		return;
	if(sys->rcp.isReady == 0)
		return;	
	
	if(sys->tk[tid].autoMakeStep > 1)
		return;
//	if(tid != TANK_11 && sys->tk[tid].curTemp < sys->tk[tid].rcp.DosTmp)
//		return;
	
	if(sys->tk[tid].rcp.DosCH1Time > 0 && testBit(sys->tk[tid].hsAC1Dos,WB) == 0)
	{
		if(sys->tk[tid].tmAC1Dos == 0 || (cTM - sys->tk[tid].tmAC1Dos) > sys->tk[tid].rcp.DosCH1Time)
		{
			sys->tk[tid].tmAC1Dos = cTM;
			setBit(sys->tk[tid].hsAC1Dos);
			DosingLog(DOSING_BY_TIME,tid,1,sys->tk[tid].carNumber);
		}
	}
	if(sys->tk[tid].rcp.DosCH2Time > 0  && testBit(sys->tk[tid].hsAC2Dos,WB) == 0)
	{
		if(sys->tk[tid].tmAC2Dos == 0 || (cTM - sys->tk[tid].tmAC2Dos) > sys->tk[tid].rcp.DosCH2Time)
		{
			sys->tk[tid].tmAC2Dos = cTM;
			setBit(sys->tk[tid].hsAC2Dos);
			DosingLog(DOSING_BY_TIME,tid,2,sys->tk[tid].carNumber);
		}
	}
	if(sys->tk[tid].rcp.DosCH3Time > 0  && testBit(sys->tk[tid].hsAC3Dos,WB) == 0)
	{
		if(sys->tk[tid].tmAC3Dos == 0 || (cTM - sys->tk[tid].tmAC3Dos) > sys->tk[tid].rcp.DosCH3Time)
		{
			sys->tk[tid].tmAC3Dos = cTM;
			setBit(sys->tk[tid].hsAC3Dos);
			DosingLog(DOSING_BY_TIME,tid,3,sys->tk[tid].carNumber);
		}
	}
	if(sys->tk[tid].rcp.DosCH4Time > 0  && testBit(sys->tk[tid].hsAC4Dos,WB) == 0)
	{
		if(sys->tk[tid].tmAC4Dos == 0 || (cTM - sys->tk[tid].tmAC4Dos) > sys->tk[tid].rcp.DosCH4Time)
		{
			sys->tk[tid].tmAC4Dos = cTM;
			setBit(sys->tk[tid].hsAC4Dos);
			DosingLog(DOSING_BY_TIME,tid,4,sys->tk[tid].carNumber);
		}
	}
}

int CVICALLBACK HandleEMO (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			if(control == PANEL_EMO_RESET)
			{
				resetBit(sys->hsEMOContine);
				
				for(int i = 0; i < ROBOT_NUM; i++)
				{
					setBit(sys->rb[i].hsAbortCommand);
					sys->rb[i].resetCommand = 1;
				}
			
				sys->EMOStatus = 0;	
				RemovePopup (0);
				DiscardPanel (EMOHandle);
				EMOHandle = 0;
			}
			else if(control == PANEL_EMO_CONTINUE)
			{
				setBit(sys->hsEMOContine);
				for(int i = 0; i < ROBOT_NUM; i++)
				{
					resetBit(sys->rb[i].hsAbortCommand);
					sys->rb[i].resetCommand = 0;
				}
			
				sys->EMOStatus = 0;	
				RemovePopup (0);
				DiscardPanel (EMOHandle);
				EMOHandle = 0;
			}

			break;
	}
	return 0;
}

void CheckEMO(void)
{
	
	if(testBit(sys->hsEMGALL,RB) > 0 || testBit(sys->hsEMGROBOT,RB) > 0)
		sys->EMOStatus = 1;
	else
	{
		if(sys->EMOStatus == 1 && EMOHandle == 0)
		{
			EMOHandle = LoadPanel (0, "robot_panel.uir", PANEL_EMO);
			InstallPopup(EMOHandle);
		}
	}
}

void Loader(void)
{
	if(testBit(sys->rtk[RTK_01].hsPermitGet,RB)>0 )
	{
		if(testBit(sys->tk[TANK_01].xPosA3,RX) > 0 && testBit(sys->tk[TANK_01].xPosB3,RX) > 0 && testBit(sys->rtk[RTK_01].hsFill,WB) == 0)
		{
			/*if(strlen(sys->rtk[RTK_01].car.tag1) == 0)
				ReadTag(0,4);
			if(strlen(sys->rtk[RTK_01].car.tag2) == 0)
				ReadTag(1,4);  */
			strcpy(sys->rtk[RTK_01].car.tag1,"tag1");
			strcpy(sys->rtk[RTK_01].car.tag2,"tag2");
			
			if(strlen(sys->rtk[RTK_01].car.tag1) > 0 && strlen(sys->rtk[RTK_01].car.tag2) > 0)
			{
				sys->rtk[RTK_01].car.sn = ++sys->tk[TANK_01].carNumber;
				GetCurrentDateTime(&sys->rtk[RTK_01].car.iPrcTM[TANK_01]);
				if(sys->tk[TANK_01].carNumber == 1)
					sys->rtk[RTK_01].car.iPrcTM[TANK_01] -= sys->tk[TANK_01].rcp.ProcTM;
					
				setBit(sys->rtk[RTK_01].hsFill);
				resetBit(sys->rtk[RTK_01].hsPermitGet);
			}
		}
	}
	else
	{
		int feed;
		GetCtrlVal ( panelHandle, PANEL_FEED, &feed);
		if(feed)
			setBit(sys->rtk[RTK_01].hsPermitGet);
		else
			resetBit(sys->rtk[RTK_01].hsPermitGet);
	}	
}

void AutoMake(TANK_ID tid)
{
	//double cTM;
	if(sys->tk[tid].rcp.DrainRun <= 0 || sys->tk[tid].rcp.ProcTM <= 0)
		return;
	
	if(sys->tk[tid].autoMakeStep == 0)
	{
//		GetCurrentDateTime ( &cTM);
//		if((sys->tk[tid].rcp.DrainRun > 0 && sys->tk[tid].lifeRun <= 0))// || (sys->tk[tid].rcp.DrainTime > 0 && sys->tk[tid].lifeTime <= cTM))

		if(tid == TANK_04)
		{
			if(sys->tk[tid].lifeRun <= 0)
			{
				SetCtrlAttribute(panelHandle,PANEL_AUTOMAKE_04, ATTR_VISIBLE,1);
				SetCtrlVal (panelHandle, PANEL_AUTOMAKE_04, "自動換酸準備中");
				
				sys->tk[tid].autoMakeStep = 1;
				PDrainLog(PDRAIN_ALL,tid,sys->tk[tid].autoMakeStep);
				SaveSystem();
			}
			else if(sys->tk[TANK_07].rcp.ProcTM <= 0)
			{
				int life = sys->tk[tid].lifeRun;
				for(int i = RTK_02_01;i<=RTK_03_02;i++)
				{
					if(testBit(sys->rtk[i].hsFill,WB) > 0)
						life--;
				}
				if(life <= 0)
				{
					SetCtrlAttribute(panelHandle,PANEL_AUTOMAKE_04, ATTR_VISIBLE,1);
					SetCtrlVal (panelHandle, PANEL_AUTOMAKE_04, "自動換酸準備中");
				
					sys->tk[tid].autoMakeStep = 1;
					PDrainLog(PDRAIN_ALL,tid,sys->tk[tid].autoMakeStep);
					SaveSystem();
				}
			}
		}
		else if(tid == TANK_07)
		{
			if(sys->tk[tid].lifeRun <= 0)
			{
				SetCtrlAttribute(panelHandle,PANEL_AUTOMAKE_07, ATTR_VISIBLE,1);
				SetCtrlVal (panelHandle, PANEL_AUTOMAKE_07, "自動換酸準備中");
				
				sys->tk[tid].autoMakeStep = 1;
				PDrainLog(PDRAIN_ALL,tid,sys->tk[tid].autoMakeStep);
				SaveSystem();
			}
			else if(sys->tk[TANK_04].rcp.ProcTM <= 0)
			{
				int life = sys->tk[tid].lifeRun;
				for(int i = RTK_02_01;i<=RTK_03_02;i++)
				{
					if(testBit(sys->rtk[i].hsFill,WB) > 0)
						life--;
				}
				if(testBit(sys->rtk[RTK_06].hsFill,WB) > 0)
					life--;
				if(life <= 0)
				{
					SetCtrlAttribute(panelHandle,PANEL_AUTOMAKE_07, ATTR_VISIBLE,1);
					SetCtrlVal (panelHandle, PANEL_AUTOMAKE_07, "自動換酸準備中");
				
					sys->tk[tid].autoMakeStep = 1;
					PDrainLog(PDRAIN_ALL,tid,sys->tk[tid].autoMakeStep);
					SaveSystem();
				}
			}
		}
		else if(tid == TANK_02)
		{
			if(sys->tk[tid].lifeRun <= 0)
			{
				SetCtrlAttribute(panelHandle,PANEL_AUTOMAKE_02, ATTR_VISIBLE,1);
				SetCtrlVal (panelHandle, PANEL_AUTOMAKE_02, "自動換酸準備中");
				
				sys->tk[tid].autoMakeStep = 1;
				PDrainLog(PDRAIN_ALL,tid,sys->tk[tid].autoMakeStep);
				SaveSystem();
			}
		}
		else if(tid == TANK_11)
		{
			if(sys->tk[tid].lifeRun <= 0)
			{
				SetCtrlAttribute(panelHandle,PANEL_AUTOMAKE_11, ATTR_VISIBLE,1);
				SetCtrlVal (panelHandle, PANEL_AUTOMAKE_11, "自動換酸準備中");
				
				sys->tk[tid].autoMakeStep = 1;
				PDrainLog(PDRAIN_ALL,tid,sys->tk[tid].autoMakeStep);
				SaveSystem();
			}
			else
			{
				int life = sys->tk[tid].lifeRun;
				for(int i = RTK_02_01;i<=RTK_10_02;i++)
				{
					if(testBit(sys->rtk[i].hsFill,WB) > 0)
						life--;
				}
				if(life <= 0)
				{
					SetCtrlAttribute(panelHandle,PANEL_AUTOMAKE_11, ATTR_VISIBLE,1);
					SetCtrlVal (panelHandle, PANEL_AUTOMAKE_11, "自動換酸準備中");
				
					sys->tk[tid].autoMakeStep = 1;
					PDrainLog(PDRAIN_ALL,tid,sys->tk[tid].autoMakeStep);
					SaveSystem();
				}
			}
		}
				
		
	}
	else if(sys->tk[tid].autoMakeStep == 1)
	{
		if(sys->tk[tid].lifeRun > 0)
			return;
		
		if(tid == TANK_04) 
		{
			if(testBit(sys->rtk[RTK_04_01].hsFill,WB) == 0 && testBit(sys->rtk[RTK_04_02].hsFill,WB) == 0  &&
				testBit(sys->rtk[RTK_05_01].hsFill,WB) == 0  && testBit(sys->rtk[RTK_05_02].hsFill,WB) == 0)
			{
				sys->tk[tid].autoMakeStep = 2;
				SaveSystem();
				SetCtrlVal (panelHandle, PANEL_AUTOMAKE_04, "自動換酸當槽中");
				setBit(sys->tk[tid].hsDown);
				PDrainLog(PDRAIN_ALL,tid,sys->tk[tid].autoMakeStep);
			}
		}
		else if(tid == TANK_07)
		{
			if(testBit(sys->rtk[RTK_07_01].hsFill,WB) == 0 && testBit(sys->rtk[RTK_07_02].hsFill,WB) == 0  &&
				testBit(sys->rtk[RTK_08_01].hsFill,WB) == 0  && testBit(sys->rtk[RTK_08_02].hsFill,WB) == 0)
			{
				sys->tk[tid].autoMakeStep = 2;
				SaveSystem();
				SetCtrlVal (panelHandle, PANEL_AUTOMAKE_07, "自動換酸當槽中");
				setBit(sys->tk[tid].hsDown);
				PDrainLog(PDRAIN_ALL,tid,sys->tk[tid].autoMakeStep);
			}
		}
		else if(tid == TANK_02)
		{
			if(testBit(sys->rtk[RTK_02_01].hsFill,WB) == 0  && testBit(sys->rtk[RTK_02_02].hsFill,WB) == 0)
			{
				sys->tk[tid].autoMakeStep = 2;
				SaveSystem();
				SetCtrlVal (panelHandle, PANEL_AUTOMAKE_02, "自動換酸當槽中");
				setBit(sys->tk[tid].hsDown);
				PDrainLog(PDRAIN_ALL,tid,sys->tk[tid].autoMakeStep);
				
			}
		}
		else if(tid == TANK_11)
		{
			if(testBit(sys->rtk[RTK_11_01].hsFill,WB) == 0  && testBit(sys->rtk[RTK_11_02].hsFill,WB) == 0)
			{
				sys->tk[tid].autoMakeStep = 2;
				SaveSystem();
				SetCtrlVal (panelHandle, PANEL_AUTOMAKE_11, "自動換酸當槽中");
				setBit(sys->tk[tid].hsDown);
				PDrainLog(PDRAIN_ALL,tid,sys->tk[tid].autoMakeStep);
				
			}
		}
	}
	else if(sys->tk[tid].autoMakeStep == 2)
	{
		if(testBit(sys->tk[tid].hsDown,WB) == 0 && testBit(sys->tk[tid].hsDown,RB) == 0)
		{
			sys->tk[tid].autoMakeStep = 3;
			SaveSystem();
			if(tid == TANK_04)
				SetCtrlVal (panelHandle, PANEL_AUTOMAKE_04, "自動換酸配槽中");
			else if(tid == TANK_07)
				SetCtrlVal (panelHandle, PANEL_AUTOMAKE_07, "自動換酸配槽中");
			else if(tid == TANK_02)
				SetCtrlVal (panelHandle, PANEL_AUTOMAKE_02, "自動換酸配槽中");
			else if(tid == TANK_11)
				SetCtrlVal (panelHandle, PANEL_AUTOMAKE_11, "自動換酸配槽中");
			
			sys->tk[tid].MakeCH1 = sys->tk[tid].rcp.DrainCH1;
			sys->tk[tid].MakeCH2 = sys->tk[tid].rcp.DrainCH2; 
			sys->tk[tid].MakeCH3 = sys->tk[tid].rcp.DrainCH3;
			sys->tk[tid].MakeCH4 = sys->tk[tid].rcp.DrainCH4;
			g_makeBit = sys->tk[tid].hsMake;
			g_setupMake = 1;
			
			PDrainLog(PDRAIN_ALL,tid,sys->tk[tid].autoMakeStep); 
		}
		
	}
	else if(sys->tk[tid].autoMakeStep == 3)
	{
		if(g_setupMake == 0 &&  testBit(sys->tk[tid].hsMake,WB) == 0 && testBit(sys->tk[tid].hsMakeEnd,RB) > 0)
		{
			sys->tk[tid].autoMakeStep = 0;
			SaveSystem();
			if(tid == TANK_04)
			{
				SetCtrlAttribute(panelHandle,PANEL_AUTOMAKE_04, ATTR_VISIBLE,0); 
				SetCtrlVal (panelHandle, PANEL_LIFE_04, "自動換酸完成");
			}
			else if(tid == TANK_07)
			{
				SetCtrlAttribute(panelHandle,PANEL_AUTOMAKE_07, ATTR_VISIBLE,0); 
				SetCtrlVal (panelHandle, PANEL_LIFE_07, "自動換酸完成");
			}
			else if(tid == TANK_02)
			{
				SetCtrlAttribute(panelHandle,PANEL_AUTOMAKE_02, ATTR_VISIBLE,0); 
				SetCtrlVal (panelHandle, PANEL_LIFE_02, "自動換酸完成");
			}
			else if(tid == TANK_11)
			{
				SetCtrlAttribute(panelHandle,PANEL_AUTOMAKE_11, ATTR_VISIBLE,0); 
				SetCtrlVal (panelHandle, PANEL_LIFE_11, "自動換酸完成");
			}
			PDrainLog(PDRAIN_ALL,tid,sys->tk[tid].autoMakeStep);
		}
		
	}
	
}

int CVICALLBACK PriTimer (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	double cTM;
	char buf[128];
	

	switch (event)
	{
		case EVENT_TIMER_TICK:
			
			if(msgShowTime > 0)
			{
				msgShowTime--;
				SetCtrlAttribute(panel, PANEL_TEXTMSG,ATTR_VISIBLE,1);
			}
			else
				SetCtrlAttribute(panel, PANEL_TEXTMSG,ATTR_VISIBLE,0);
			
			SetCtrlVal ( panel, PANEL_USERNAME, sys->user.name);
			
			if(testBit(sys->hsAuto,RB) > 0 && sysStatus == MANUAL_STATUS){
				ActionLog(SYS_AUTO,0,0,0,0,0); 
			}
			else if(testBit(sys->hsAuto,RB) == 0 && sysStatus == AUTO_STATUS){
				ActionLog(SYS_MANUAL,0,0,0,0,0);  
			}
			
			if(testBit(sys->hsAuto,RB) > 0){
				SetCtrlVal ( panel, PANEL_USERTYPE, "自動狀態"); 
				sysStatus = AUTO_STATUS;
			}
			else{
				sysStatus = MANUAL_STATUS;  
				SetCtrlVal ( panel, PANEL_USERTYPE, "手動狀態"); 
			}
			
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
			
			GetCurrentDateTime ( &cTM);
			FormatDateTimeString (cTM, "%Y/%m/%d\r%H:%M:%S", buf, 120);
			SetCtrlVal ( panel, PANEL_SYS_DATE, buf);
			
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
				if(sys->tk[i].hsHeat.wid != 0 || sys->tk[i].hsHeat.bid != 0 )  
					SetCtrlAttribute(panel, sys->tk[i].uiHeat, ATTR_VISIBLE ,(testBit(sys->tk[i].yHeat,RY) > 0)?1:0);
/*				
				//pump
				if(sys->tk[i].hsPump.wid != 0 || sys->tk[i].hsPump.bid != 0 )  
					SetCtrlVal(panel, sys->tk[i].uiPump, (testBit(sys->tk[i].yPump,RY) > 0)?1:0);
*/				
				//tank
				if(sys->tk[i].xLevH.wid != 0 || sys->tk[i].xLevH.bid != 0 ) 
				{
					int lev = 0;
					lev += (testBit(sys->tk[i].xLevLL,RX) > 0)?1:0;
					lev += (testBit(sys->tk[i].xLevL,RX) > 0)?1:0;
					lev += (testBit(sys->tk[i].xLevH,RX) > 0)?1:0;
					lev += (testBit(sys->tk[i].xLevHH,RX) > 0)?1:0;
					lev *= 20;
					SetCtrlVal(panel, sys->tk[i].uiTANK, lev); 
				}

				///shut
				if(sys->tk[i].uiShut > 0)
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
					Fmt(Strcount, "%s<%i", sys->tk[i].carNumber);
					SetCtrlVal(panel, sys->tk[i].uiCARNum, Strcount);
					
					if(sys->tk[i].rcp.ProcTM == 0)
					{
						SetCtrlAttribute(panel, sys->tk[i].uiTANK, ATTR_LABEL_COLOR , VAL_WHITE);
						SetCtrlAttribute(panel, sys->tk[i].uiTANK, ATTR_LABEL_BGCOLOR ,VAL_GRAY);
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
				}
			}
			
			///////////////////////////////////////////////
			//car
			for(int i = 0; i < RTANK_NUM; i++)
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
			SetCtrlVal(panel,  PANEL_TM_17, 0);

			SetCtrlIndex(panel, PANEL_INPROC_ULDA2, (testBit(sys->tk[TANK_17].xPosA2,RX) > 0 || testBit(sys->tk[TANK_17].xPosB2,RX) > 0) ? 1:0);
			SetCtrlIndex(panel, PANEL_INPROC_ULDA3, (testBit(sys->tk[TANK_17].xPosA3,RX) > 0 || testBit(sys->tk[TANK_17].xPosB3,RX) > 0) ? 1:0); 
			SetCtrlIndex(panel, PANEL_INPROC_ULDA4, (testBit(sys->tk[TANK_17].xPosA4,RX) > 0 || testBit(sys->tk[TANK_17].xPosB4,RX) > 0) ? 1:0);
			SetCtrlIndex(panel, PANEL_INPROC_ULDA5, (testBit(sys->tk[TANK_17].xPosA5,RX) > 0 || testBit(sys->tk[TANK_17].xPosB5,RX) > 0) ? 1:0);
			SetCtrlIndex(panel, PANEL_INPROC_ULDA6, (testBit(sys->tk[TANK_17].xPosA6,RX) > 0 || testBit(sys->tk[TANK_17].xPosB6,RX) > 0) ? 1:0);

			if(testBit(sys->tk[TANK_17].xPosA1,RX) > 0 || testBit(sys->tk[TANK_17].xPosB1,RX) > 0)
				setBit(sys->rtk[RTK_17].hsFill);
			else
				resetBit(sys->rtk[RTK_17].hsFill);
			
			SetCtrlAttribute(panel, PANEL_ULD_POS1A, ATTR_TEXT_BGCOLOR, testBit(sys->tk[TANK_17].xPosA1,RX) > 0?0x0000FF00:0x00cccccc); 
			SetCtrlAttribute(panel, PANEL_ULD_POS1B, ATTR_TEXT_BGCOLOR, testBit(sys->tk[TANK_17].xPosB1,RX) > 0?0x0000FF00:0x00cccccc);
			SetCtrlAttribute(panel, PANEL_ULD_POS2A, ATTR_TEXT_BGCOLOR, testBit(sys->tk[TANK_17].xPosA2,RX) > 0?0x0000FF00:0x00cccccc); 
			SetCtrlAttribute(panel, PANEL_ULD_POS2B, ATTR_TEXT_BGCOLOR, testBit(sys->tk[TANK_17].xPosB2,RX) > 0?0x0000FF00:0x00cccccc);
			SetCtrlAttribute(panel, PANEL_ULD_POS3A, ATTR_TEXT_BGCOLOR, testBit(sys->tk[TANK_17].xPosA3,RX) > 0?0x0000FF00:0x00cccccc); 
			SetCtrlAttribute(panel, PANEL_ULD_POS3B, ATTR_TEXT_BGCOLOR, testBit(sys->tk[TANK_17].xPosB3,RX) > 0?0x0000FF00:0x00cccccc);
			SetCtrlAttribute(panel, PANEL_ULD_POS4A, ATTR_TEXT_BGCOLOR, testBit(sys->tk[TANK_17].xPosA4,RX) > 0?0x0000FF00:0x00cccccc); 
			SetCtrlAttribute(panel, PANEL_ULD_POS4B, ATTR_TEXT_BGCOLOR, testBit(sys->tk[TANK_17].xPosB4,RX) > 0?0x0000FF00:0x00cccccc);
			SetCtrlAttribute(panel, PANEL_ULD_POS5A, ATTR_TEXT_BGCOLOR, testBit(sys->tk[TANK_17].xPosA5,RX) > 0?0x0000FF00:0x00cccccc); 
			SetCtrlAttribute(panel, PANEL_ULD_POS5B, ATTR_TEXT_BGCOLOR, testBit(sys->tk[TANK_17].xPosB5,RX) > 0?0x0000FF00:0x00cccccc);
			SetCtrlAttribute(panel, PANEL_ULD_POS6A, ATTR_TEXT_BGCOLOR, testBit(sys->tk[TANK_17].xPosA6,RX) > 0?0x0000FF00:0x00cccccc); 
			SetCtrlAttribute(panel, PANEL_ULD_POS6B, ATTR_TEXT_BGCOLOR, testBit(sys->tk[TANK_17].xPosB6,RX) > 0?0x0000FF00:0x00cccccc);
			 
			SetCtrlIndex(panel, PANEL_ROBOT1, testBit(sys->rb[0].hsFill,WB) > 0 ? 1:0);
			SetCtrlIndex(panel, PANEL_ROBOT2, testBit(sys->rb[1].hsFill,WB) > 0 ? 1:0);
			SetCtrlIndex(panel, PANEL_ROBOT3, testBit(sys->rb[2].hsFill,WB) >0 ? 1:0);
			
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//robot
			int left = sys->rb[0].UIPosLeft + (sys->rb[0].curPosX - sys->rtk[RTK_01].xUnlock) * (sys->rb[0].UIPosRight - sys->rb[0].UIPosLeft) / (sys->rtk[RTK_06].xUnlock - sys->rtk[RTK_01].xUnlock);  
			int top = sys->rb[0].UIPosTop + (sys->rb[0].curPosY - sys->rb[0].safeHight) * (sys->rb[0].UIPosTop - sys->rb[0].UIPosLow)  / (sys->rb[0].safeHight - sys->rtk[RTK_01].zDown);
			if(left > 0 && left < 2000)
			{
				SetCtrlAttribute (panel, PANEL_ROBOT1, ATTR_LEFT,	left);
				SetCtrlAttribute (panel, PANEL_ROBOT11,ATTR_LEFT, 	left-1);
			}
			if(top > 0 && top < 2000)
				SetCtrlAttribute (panel, PANEL_ROBOT1, ATTR_TOP, 	top); 
			
			left = sys->rb[1].UIPosLeft + (sys->rb[1].curPosX - sys->rtk[RTK_06].xUnlock2) * (sys->rb[1].UIPosRight - sys->rb[1].UIPosLeft) / (sys->rtk[RTK_12].xUnlock - sys->rtk[RTK_06].xUnlock2);  
			top = sys->rb[1].UIPosTop + (sys->rb[1].curPosY - sys->rb[1].safeHight) * (sys->rb[1].UIPosTop - sys->rb[1].UIPosLow)  / (sys->rb[1].safeHight - sys->rtk[RTK_06].zDown2);
			if(left > 0 && left < 2000)
			{
				SetCtrlAttribute (panel, PANEL_ROBOT2, ATTR_LEFT,	left);
				SetCtrlAttribute (panel, PANEL_ROBOT21,ATTR_LEFT, 	left-1);
			}
			if(top > 0 && top < 2000)
				SetCtrlAttribute (panel, PANEL_ROBOT2, ATTR_TOP, 	top);
			
			left = sys->rb[2].UIPosLeft + (sys->rb[2].curPosX - sys->rtk[RTK_12].xUnlock2) * (sys->rb[2].UIPosRight - sys->rb[2].UIPosLeft) / (sys->rtk[RTK_17].xUnlock - sys->rtk[RTK_12].xUnlock2);  
			top = sys->rb[2].UIPosTop + (sys->rb[2].curPosY - sys->rb[2].safeHight) * (sys->rb[2].UIPosTop - sys->rb[2].UIPosLow)  / (sys->rb[2].safeHight - sys->rtk[RTK_12].zDown2);
			if(left > 0 && left < 2000)
			{
				SetCtrlAttribute (panel, PANEL_ROBOT3, ATTR_LEFT,	left);
				SetCtrlAttribute (panel, PANEL_ROBOT31,ATTR_LEFT, 	left-1);
			}
			if(top > 0 && top < 2000)
				SetCtrlAttribute (panel, PANEL_ROBOT3, ATTR_TOP, 	top);
			
			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//
			SetCtrlVal (panel, PANEL_PLC_LED, test00Bit(RB)?1:0);
			SetCtrlVal (panel, PANEL_DOR_ILD, (testBit(sys->tk[TANK_01].xDoorOpen,RX) > 0 && testBit(sys->tk[TANK_01].xDoorClose,RX) == 0) ?2:1);
			SetCtrlVal (panel, PANEL_DOR_ULD, (testBit(sys->tk[TANK_17].xDoorOpen,RX) > 0 && testBit(sys->tk[TANK_17].xDoorClose,RX) == 0) ?2:1); 

			//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//
			int buzz;
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
			}
			
			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//temp
			SetCtrlVal (panel, PANEL_TEMP02, sys->tk[TANK_02].curTemp);
			SetCtrlVal (panel, PANEL_TEMP03, sys->tk[TANK_03].curTemp);
			SetCtrlVal (panel, PANEL_TEMP04, sys->tk[TANK_04].curTemp);
			SetCtrlVal (panel, PANEL_TEMP06, sys->tk[TANK_06].curTemp);
			SetCtrlVal (panel, PANEL_TEMP07, sys->tk[TANK_07].curTemp);
			SetCtrlVal (panel, PANEL_TEMP09, sys->tk[TANK_09].curTemp);
			SetCtrlVal (panel, PANEL_TEMP10, sys->tk[TANK_10].curTemp);
			SetCtrlVal (panel, PANEL_TEMP12, sys->tk[TANK_12].curTemp);
			SetCtrlVal (panel, PANEL_TEMP13, sys->tk[TANK_13].curTemp);
			SetCtrlVal (panel, PANEL_TEMP14, sys->tk[TANK_14].curTemp);
			SetCtrlVal (panel, PANEL_TEMP15, sys->tk[TANK_15].curTemp);
			SetCtrlVal (panel, PANEL_TEMP16, sys->tk[TANK_16].curTemp);
			SetCtrlVal (panel, PANEL_TEMP17, sys->tk[TANK_17].curTemp);
			SetCtrlVal (panel, PANEL_TEMP_PH1, sys->tk[TANK_AUX_PH1].curTemp);
			SetCtrlVal (panel, PANEL_TEMP_PH2, sys->tk[TANK_AUX_PH2].curTemp);
			SetCtrlVal (panel, PANEL_TEMP_IN, sys->tk[TANK_AUX_IN].curTemp);
			
			SetCtrlVal (panel, PANEL_UP_LEV_02, testBit(sys->tk[TANK_02].xLevUP,RX)>0?1:0);
			SetCtrlVal (panel, PANEL_UP_LEV_04, testBit(sys->tk[TANK_04].xLevUP,RX)>0?1:0);
			SetCtrlVal (panel, PANEL_UP_LEV_05, testBit(sys->tk[TANK_05].xLevUP,RX)>0?1:0);
			SetCtrlVal (panel, PANEL_UP_LEV_07, testBit(sys->tk[TANK_07].xLevUP,RX)>0?1:0);
			SetCtrlVal (panel, PANEL_UP_LEV_08, testBit(sys->tk[TANK_08].xLevUP,RX)>0?1:0);
			SetCtrlVal (panel, PANEL_UP_LEV_14, testBit(sys->tk[TANK_14].xLevUP,RX)>0?1:0);
			SetCtrlVal (panel, PANEL_UP_LEV_15, testBit(sys->tk[TANK_15].xLevUP,RX)>0?1:0);
			
			if(sys->tk[TANK_02].lifeTime>cTM)
				Fmt(buf,"%d Run\r%d:%d:%d", sys->tk[TANK_02].lifeRun,(int)(sys->tk[TANK_02].lifeTime-cTM)/3600,((int)(sys->tk[TANK_02].lifeTime-cTM)%3600)/60,((int)(sys->tk[TANK_02].lifeTime-cTM)%3600)%60);
			else
				Fmt(buf,"%d Run\r-%d:%d:%d", sys->tk[TANK_02].lifeRun,(int)(cTM - sys->tk[TANK_02].lifeTime)/3600,((int)(cTM - sys->tk[TANK_02].lifeTime)%3600)/60,((int)(cTM - sys->tk[TANK_02].lifeTime)%3600)%60);
			SetCtrlVal (panel, PANEL_LIFE_02, buf);
			
			if(sys->tk[TANK_04].lifeTime>cTM)
				Fmt(buf,"%d Run\r%d:%d:%d", sys->tk[TANK_04].lifeRun,(int)(sys->tk[TANK_04].lifeTime-cTM)/3600,((int)(sys->tk[TANK_04].lifeTime-cTM)%3600)/60,((int)(sys->tk[TANK_04].lifeTime-cTM)%3600)%60);
			else
				Fmt(buf,"%d Run\r-%d:%d:%d", sys->tk[TANK_04].lifeRun,(int)(cTM - sys->tk[TANK_04].lifeTime)/3600,((int)(cTM - sys->tk[TANK_04].lifeTime)%3600)/60,((int)(cTM - sys->tk[TANK_04].lifeTime)%3600)%60);
			SetCtrlVal (panel, PANEL_LIFE_04, buf);
			
			if(sys->tk[TANK_07].lifeTime>cTM)
				Fmt(buf,"%d Run\r%d:%d:%d", sys->tk[TANK_07].lifeRun,(int)(sys->tk[TANK_07].lifeTime-cTM)/3600,((int)(sys->tk[TANK_07].lifeTime-cTM)%3600)/60,((int)(sys->tk[TANK_07].lifeTime-cTM)%3600)%60);
			 else
				Fmt(buf,"%d Run\r-%d:%d:%d", sys->tk[TANK_07].lifeRun,(int)(cTM - sys->tk[TANK_07].lifeTime)/3600,((int)(cTM - sys->tk[TANK_07].lifeTime)%3600)/60,((int)(cTM - sys->tk[TANK_07].lifeTime)%3600)%60);
			SetCtrlVal (panel, PANEL_LIFE_07, buf);
			
			if(sys->tk[TANK_11].lifeTime>cTM)
				Fmt(buf,"%d Run\r%d:%d:%d", sys->tk[TANK_11].lifeRun,(int)(sys->tk[TANK_11].lifeTime-cTM)/3600,((int)(sys->tk[TANK_11].lifeTime-cTM)%3600)/60,((int)(sys->tk[TANK_11].lifeTime-cTM)%3600)%60);
			else
				Fmt(buf,"%d Run\r-%d:%d:%d", sys->tk[TANK_11].lifeRun,(int)(cTM - sys->tk[TANK_11].lifeTime)/3600,((int)(cTM - sys->tk[TANK_11].lifeTime)%3600)/60,((int)(cTM - sys->tk[TANK_11].lifeTime)%3600)%60);
			SetCtrlVal (panel, PANEL_LIFE_11, buf);
			

			break;
	}
	return 0;
}

