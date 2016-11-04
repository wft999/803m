#include <utility.h>
#include <formatio.h>
#include <ansi_c.h>
#include <userint.h>
#include "robot_panel.h"

//==============================================================================
//
// Title:       set_panel.c
// Purpose:     A short description of the implementation.
//
// Created on:  2014/8/7 at ¤U¤È 01:44:01 by wang fang.
// Copyright:   hua. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files

//#include "set_panel.h"
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
void CheckValueRange(int *Value,int MaxNum,int MinNum)
{
	if(*Value >= MaxNum)
		*Value=MaxNum;
	if(*Value <= MinNum)
		*Value=MinNum;
}

void Save_FunctionSet(int panel)
{
 	char FileName[256];
 	char Path[300];
 	FILE *Fp;
	
 	GetDir(Path);
 
 	Fmt(FileName,"%s<%s\\%s.PAR",Path,"FuncSet");
 	Fp=fopen (FileName, "w");

 	GetCtrlVal ( panel, PANEL_SET_CHECKBOX_CHUCK,&sys->set.ChuckLock_Check_Enabled);
 	CheckValueRange(&sys->set.ChuckLock_Check_Enabled,1,0);  
 
 
 	GetCtrlVal ( panel, PANEL_SET_CHECKBOX_DOOR,&sys->set.Door_Interlock_Check_Enabled);
 	CheckValueRange(&sys->set.Door_Interlock_Check_Enabled,1,0);  
 
 	GetCtrlVal ( panel, PANEL_SET_CHECKBOX_EXHAUST,&sys->set.Exhaust_Check_Enabled);
 	CheckValueRange(&sys->set.Exhaust_Check_Enabled,1,0);  
 
 															   
 	GetCtrlVal ( panel, PANEL_SET_CHECKBOX_SAFE,&sys->set.SaveHeightMode_Enabled);
 	CheckValueRange(&sys->set.SaveHeightMode_Enabled,1,0);
	
	GetCtrlVal ( panel, PANEL_SET_CHECKBOX_IPA,&sys->set.IPABufferMode_Enabled);
 	CheckValueRange(&sys->set.IPABufferMode_Enabled,1,0);
	
	GetCtrlVal ( panel, PANEL_SET_DOWN_DELAY_2,&sys->set.down_delay_02);
	GetCtrlVal ( panel, PANEL_SET_DOWN_DELAY_3,&sys->set.down_delay_03);
	GetCtrlVal ( panel, PANEL_SET_DOWN_DELAY_4,&sys->set.down_delay_04);
	GetCtrlVal ( panel, PANEL_SET_DOWN_DELAY_5,&sys->set.down_delay_05);
	GetCtrlVal ( panel, PANEL_SET_DOWN_DELAY_6,&sys->set.down_delay_06);
	GetCtrlVal ( panel, PANEL_SET_DOWN_DELAY_7,&sys->set.down_delay_07);
	GetCtrlVal ( panel, PANEL_SET_DOWN_DELAY_8,&sys->set.down_delay_08);
	GetCtrlVal ( panel, PANEL_SET_DOWN_DELAY_9,&sys->set.down_delay_09);
	GetCtrlVal ( panel, PANEL_SET_DOWN_DELAY_10,&sys->set.down_delay_10);
	GetCtrlVal ( panel, PANEL_SET_DOWN_DELAY_11,&sys->set.down_delay_11);
	GetCtrlVal ( panel, PANEL_SET_DOWN_DELAY_12,&sys->set.down_delay_12);
	GetCtrlVal ( panel, PANEL_SET_DOWN_DELAY_13,&sys->set.down_delay_13);
	GetCtrlVal ( panel, PANEL_SET_DOWN_DELAY_14,&sys->set.down_delay_14);
	GetCtrlVal ( panel, PANEL_SET_DOWN_DELAY_15,&sys->set.down_delay_15);
	
	////////////////////////////////////////////////////////////
	int tmp;
	GetCtrlVal ( panel, PANEL_SET_AUTH_RECIPE1,&tmp);
	if(tmp)
		sys->set.auth[1][0] = OP_RCP;
	else
		sys->set.auth[1][0] = OP_UNKONW;
	
	GetCtrlVal ( panel, PANEL_SET_AUTH_RECIPE2,&tmp);
	if(tmp)
		sys->set.auth[2][0] = OP_RCP;
	else
		sys->set.auth[2][0] = OP_UNKONW;
	
	GetCtrlVal ( panel, PANEL_SET_AUTH_RECIPE3,&tmp);
	if(tmp)
		sys->set.auth[3][0] = OP_RCP;
	else
		sys->set.auth[3][0] = OP_UNKONW;
	
	//////////////////////////////////////////////////////////////////////
	GetCtrlVal ( panel, PANEL_SET_AUTH_TANK1,&tmp);
	if(tmp)
		sys->set.auth[1][1] = OP_TANK;
	else
		sys->set.auth[1][1] = OP_UNKONW;
	
	GetCtrlVal ( panel, PANEL_SET_AUTH_TANK2,&tmp);
	if(tmp)
		sys->set.auth[2][1] = OP_TANK;
	else
		sys->set.auth[2][1] = OP_UNKONW;
	
	GetCtrlVal ( panel, PANEL_SET_AUTH_TANK3,&tmp);
	if(tmp)
		sys->set.auth[3][1] = OP_TANK;
	else
		sys->set.auth[3][1] = OP_UNKONW;
	///////////////////////////////////////////////////////////////////
	GetCtrlVal ( panel, PANEL_SET_AUTH_ROBOT1,&tmp);
	if(tmp)
		sys->set.auth[1][2] = OP_ROBOT;
	else
		sys->set.auth[1][2] = OP_UNKONW;
	
	GetCtrlVal ( panel, PANEL_SET_AUTH_ROBOT2,&tmp);
	if(tmp)
		sys->set.auth[2][2] = OP_ROBOT;
	else
		sys->set.auth[2][2] = OP_UNKONW;
	
	GetCtrlVal ( panel, PANEL_SET_AUTH_ROBOT3,&tmp);
	if(tmp)
		sys->set.auth[3][2] = OP_ROBOT;
	else
		sys->set.auth[3][2] = OP_UNKONW;
	
	//////////////////////////////////////////////////////////////////////
	GetCtrlVal ( panel, PANEL_SET_AUTH_SET1,&tmp);
	if(tmp)
		sys->set.auth[1][3] = OP_SET;
	else
		sys->set.auth[1][3] = OP_UNKONW;
	
	GetCtrlVal ( panel, PANEL_SET_AUTH_SET2,&tmp);
	if(tmp)
		sys->set.auth[2][3] = OP_SET;
	else
		sys->set.auth[2][3] = OP_UNKONW;
	
	GetCtrlVal ( panel, PANEL_SET_AUTH_SET3,&tmp);
	if(tmp)
		sys->set.auth[3][3] = OP_SET;
	else
		sys->set.auth[3][3] = OP_UNKONW;
	
	//////////////////////////////////////////////////////////////////////
	GetCtrlVal ( panel, PANEL_SET_AUTH_EXIT1,&tmp);
	if(tmp)
		sys->set.auth[1][4] = OP_EXIT;
	else
		sys->set.auth[1][4] = OP_UNKONW;
	
	GetCtrlVal ( panel, PANEL_SET_AUTH_EXIT2,&tmp);
	if(tmp)
		sys->set.auth[2][4] = OP_EXIT;
	else
		sys->set.auth[2][4] = OP_UNKONW;
	
	GetCtrlVal ( panel, PANEL_SET_AUTH_EXIT3,&tmp);
	if(tmp)
		sys->set.auth[3][4] = OP_EXIT;
	else
		sys->set.auth[3][4] = OP_UNKONW;
	
	//////////////////////////////////////////////////////////////////////
	GetCtrlVal ( panel, PANEL_SET_AUTH_USER1,&tmp);
	if(tmp)
		sys->set.auth[1][5] = OP_USER;
	else
		sys->set.auth[1][5] = OP_UNKONW;
	
	GetCtrlVal ( panel, PANEL_SET_AUTH_USER2,&tmp);
	if(tmp)
		sys->set.auth[2][5] = OP_USER;
	else
		sys->set.auth[2][5] = OP_UNKONW;
	
	GetCtrlVal ( panel, PANEL_SET_AUTH_USER3,&tmp);
	if(tmp)
		sys->set.auth[3][5] = OP_USER;
	else
		sys->set.auth[3][5] = OP_UNKONW;
	
	fwrite (( char *)&sys->set,sizeof(SETTING),1,Fp); 
	fclose (Fp); 
	
}

void Load_FunctionSet(int panel)
{
	FILE *Fp;
	char FileName[256];
	char Path[300];
	int i;
	int j;
	int Size=0;

	GetDir(Path);
	Fmt(FileName,"%s<%s\\%s.PAR",Path,"FuncSet");

	Fp=fopen (FileName, "r");
	if(Fp == NULL)
		return;
	
	Size=fread (( char *)&sys->set,sizeof(SETTING),1,Fp); 
	sys->set.auth[4][0] = OP_RCP;
	sys->set.auth[4][1] = OP_TANK;
	sys->set.auth[4][2] = OP_ROBOT;
	sys->set.auth[4][3] = OP_SET;
	sys->set.auth[4][4] = OP_EXIT;
	sys->set.auth[4][5] = OP_USER;
	if(Size >= 1)
	{
		CheckValueRange(&sys->set.ChuckLock_Check_Enabled,1,0);
		SetCtrlVal ( panel, PANEL_SET_CHECKBOX_CHUCK,sys->set.ChuckLock_Check_Enabled);

 		CheckValueRange(&sys->set.Door_Interlock_Check_Enabled,1,0);
		SetCtrlVal ( panel, PANEL_SET_CHECKBOX_DOOR,sys->set.Door_Interlock_Check_Enabled);

		CheckValueRange(&sys->set.Exhaust_Check_Enabled,1,0);
		SetCtrlVal ( panel, PANEL_SET_CHECKBOX_EXHAUST,sys->set.Exhaust_Check_Enabled);
		
		SetCtrlVal ( panel, PANEL_SET_DOWN_DELAY_2,sys->set.down_delay_02);
		SetCtrlVal ( panel, PANEL_SET_DOWN_DELAY_3,sys->set.down_delay_03);
		SetCtrlVal ( panel, PANEL_SET_DOWN_DELAY_4,sys->set.down_delay_04);
		SetCtrlVal ( panel, PANEL_SET_DOWN_DELAY_5,sys->set.down_delay_05);
		SetCtrlVal ( panel, PANEL_SET_DOWN_DELAY_6,sys->set.down_delay_06);
		SetCtrlVal ( panel, PANEL_SET_DOWN_DELAY_7,sys->set.down_delay_07);
		SetCtrlVal ( panel, PANEL_SET_DOWN_DELAY_8,sys->set.down_delay_08);
		SetCtrlVal ( panel, PANEL_SET_DOWN_DELAY_9,sys->set.down_delay_09);
		SetCtrlVal ( panel, PANEL_SET_DOWN_DELAY_10,sys->set.down_delay_10);
		SetCtrlVal ( panel, PANEL_SET_DOWN_DELAY_11,sys->set.down_delay_11);
		SetCtrlVal ( panel, PANEL_SET_DOWN_DELAY_12,sys->set.down_delay_12);
		SetCtrlVal ( panel, PANEL_SET_DOWN_DELAY_13,sys->set.down_delay_13);
		SetCtrlVal ( panel, PANEL_SET_DOWN_DELAY_14,sys->set.down_delay_14);
		SetCtrlVal ( panel, PANEL_SET_DOWN_DELAY_15,sys->set.down_delay_15);

		CheckValueRange(&sys->set.SaveHeightMode_Enabled,1,0);
		SetCtrlVal ( panel, PANEL_SET_CHECKBOX_SAFE,sys->set.SaveHeightMode_Enabled);
		
		CheckValueRange(&sys->set.IPABufferMode_Enabled,1,0);
		SetCtrlVal ( panel, PANEL_SET_CHECKBOX_IPA,sys->set.IPABufferMode_Enabled);
		
		SetCtrlVal ( panel, PANEL_SET_AUTH_RECIPE1,sys->set.auth[1][0]==OP_RCP?1:0);
		SetCtrlVal ( panel, PANEL_SET_AUTH_RECIPE2,sys->set.auth[2][0]==OP_RCP?1:0);
		SetCtrlVal ( panel, PANEL_SET_AUTH_RECIPE3,sys->set.auth[3][0]==OP_RCP?1:0);
		
		SetCtrlVal ( panel, PANEL_SET_AUTH_TANK1,sys->set.auth[1][1] == OP_TANK?1:0);
		SetCtrlVal ( panel, PANEL_SET_AUTH_TANK2,sys->set.auth[2][1] == OP_TANK?1:0);
		SetCtrlVal ( panel, PANEL_SET_AUTH_TANK3,sys->set.auth[3][1] == OP_TANK?1:0);
		
		SetCtrlVal ( panel, PANEL_SET_AUTH_ROBOT1,sys->set.auth[1][2] == OP_ROBOT?1:0);
		SetCtrlVal ( panel, PANEL_SET_AUTH_ROBOT2,sys->set.auth[2][2] == OP_ROBOT?1:0);
		SetCtrlVal ( panel, PANEL_SET_AUTH_ROBOT3,sys->set.auth[3][2] == OP_ROBOT?1:0);
		
		SetCtrlVal ( panel, PANEL_SET_AUTH_SET1,sys->set.auth[1][3] == OP_SET?1:0);
		SetCtrlVal ( panel, PANEL_SET_AUTH_SET2,sys->set.auth[2][3] == OP_SET?1:0);
		SetCtrlVal ( panel, PANEL_SET_AUTH_SET3,sys->set.auth[3][3] == OP_SET?1:0);
		
		SetCtrlVal ( panel, PANEL_SET_AUTH_EXIT1,sys->set.auth[1][4] == OP_EXIT?1:0);
		SetCtrlVal ( panel, PANEL_SET_AUTH_EXIT2,sys->set.auth[2][4] == OP_EXIT?1:0);
		SetCtrlVal ( panel, PANEL_SET_AUTH_EXIT3,sys->set.auth[3][4] == OP_EXIT?1:0);
		
		SetCtrlVal ( panel, PANEL_SET_AUTH_USER1,sys->set.auth[1][5] == OP_USER?1:0);
		SetCtrlVal ( panel, PANEL_SET_AUTH_USER2,sys->set.auth[2][5] == OP_USER?1:0);
		SetCtrlVal ( panel, PANEL_SET_AUTH_USER3,sys->set.auth[3][5] == OP_USER?1:0);
	}

	fclose (Fp);


	
/*	if(sys->set.ChuckLock_Check_Enabled)
		setBit(sys->hsChuckCheck);
	else
		resetBit(sys->hsChuckCheck); 

	if (sys->set.Door_Interlock_Check_Enabled)
		setBit(sys->hsDoorCheck); 
	else
		resetBit(sys->hsDoorCheck);

	if (sys->set.Exhaust_Check_Enabled)
		setBit(sys->hsExhaustCheck);
	else
		resetBit(sys->hsExhaustCheck);

	if (sys->set.SaveHeightMode_Enabled)
		setBit(sys->hsSaveHeightMode);
	else
		resetBit(sys->hsSaveHeightMode);   
	
	if (sys->set.IPABufferMode_Enabled)
		setBit(sys->hsIPABufferMode);
	else
		resetBit(sys->hsIPABufferMode);   */
 
}

void initSetPanel(int panel)
{
	Load_FunctionSet(panel);	
}

int CVICALLBACK Save (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			if(CheckAuth(OP_SET) == 0)
				return 0;
			
			Save_FunctionSet(panel);
			Load_FunctionSet(panel);
			
			ActionLog(SET_SAVE_ACT_EVENT,0,0,0,0,0);  
			
			RemovePopup(0);
			DiscardPanel (panel); 
			break;
	}
	return 0;
}
