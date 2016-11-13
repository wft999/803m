#include <formatio.h>
#include "inifile.h"
#include <userint.h>
//==============================================================================
//
// Title:       recipe.c
// Purpose:     A short description of the implementation.
//
// Created on:  2016/10/30 at 19:16:26 by wuyan.
// Copyright:   . All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files

#include "recipe.h"
#include "type.h" 
//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// Static global variables
 
//==============================================================================
// Static functions
void writeRecipe(void);
//==============================================================================
// Global variables
int copyRcipID=-1;
int panelSys;
int panelDiw1;
int panelAcid;
int panelDiw2;
int panelKoh;
int panelDiw3;
//==============================================================================
// Global functions
void LoadRecipeData(int panel, int rcpId)
{
	char FileName[256];
	char Path[MAX_PATHNAME_LEN ];
	
	if(rcpId <= 0)
		rcpId = 1;
	
	GetDir(Path);
	Fmt(FileName,"%s<%s\\recipe\\%d.rcp",Path,rcpId);
	int fSAVE = OpenFile (FileName, VAL_READ_ONLY, VAL_OPEN_AS_IS, VAL_BINARY);
	if(fSAVE > 0)
	{
		ReadFile(fSAVE,(char*)&sys->rcp,sizeof(RECIPE));
		CloseFile (	fSAVE );
	}else{
		memset(&sys->rcp,0,sizeof(sys->rcp));
		sys->rcp.date=0;
		strcpy(sys->rcp.comment,"配方没有设定");
	}
	
	
	/////////////////////////////////////////////////////////////////////////////
	char cDateSTR[32];  
	FormatDateTimeString (sys->rcp.date, "%Y/%m/%d %H:%M:%S", cDateSTR, 20);
	SetCtrlVal (panelSys, RCP_SYS_DATE, cDateSTR);
	
	ResetTextBox(panelSys, RCP_SYS_COMMENT, sys->rcp.comment);  
	
	int id0Sys[6]={RCP_SYS_NEXT1,RCP_SYS_NEXT2,RCP_SYS_NEXT3,RCP_SYS_NEXT4,RCP_SYS_NEXT5,RCP_SYS_NEXT6};
	for(int i=0;i<6;i++)
		SetCtrlVal(panelSys, id0Sys[i],getBit(sys->rcp.rcpSYS.next_tank,i));
	
	
	
	/////////////////////////////////////////////////////////////////////////////
	SetCtrlVal(panelDiw1, RCP_DIW1_TAKE_WEIGHT, sys->rcp.rcpDIW1.take_weight);
	int id0Diw1[6]={RCP_DIW1_NEXT1,RCP_DIW1_NEXT2,RCP_DIW1_NEXT3,RCP_DIW1_NEXT4,RCP_DIW1_NEXT5};
	for(int i=0;i<5;i++)
		SetCtrlVal(panelDiw1, id0Diw1[i],  getBit(sys->rcp.rcpDIW1.next_tank,i));

		
	SetCtrlVal(panelDiw1, RCP_DIW1_TIMES, sys->rcp.rcpDIW1.LoopCount);
	
	int id1Diw1[6]={RCP_DIW1_TIME_1,RCP_DIW1_TIME_2,RCP_DIW1_TIME_3,RCP_DIW1_TIME_4,RCP_DIW1_TIME_5,RCP_DIW1_TIME_6};
	int id2Diw1[6]={RCP_DIW1_UP_1,RCP_DIW1_UP_2,RCP_DIW1_UP_3,RCP_DIW1_UP_4,RCP_DIW1_UP_5,RCP_DIW1_UP_6}; 
	int id3Diw1[6]={RCP_DIW1_DOWN_1,RCP_DIW1_DOWN_2,RCP_DIW1_DOWN_3,RCP_DIW1_DOWN_4,RCP_DIW1_DOWN_5,RCP_DIW1_DOWN_6};
	int id4Diw1[6]={RCP_DIW1_BUBBLE_1,RCP_DIW1_BUBBLE_2,RCP_DIW1_BUBBLE_3,RCP_DIW1_BUBBLE_4,RCP_DIW1_BUBBLE_5,RCP_DIW1_BUBBLE_6};
	int id5Diw1[6]={RCP_DIW1_DRAIN_1,RCP_DIW1_DRAIN_2,RCP_DIW1_DRAIN_3,RCP_DIW1_DRAIN_4,RCP_DIW1_DRAIN_5,RCP_DIW1_DRAIN_6};
	for(int i=0;i<6;i++)
	{
		SetCtrlVal(panelDiw1, id1Diw1[i], sys->rcp.rcpDIW1.uiRemain[i]);
		SetCtrlVal(panelDiw1, id2Diw1[i], getBit(sys->rcp.rcpDIW1.uiCmd[i],0));  
		SetCtrlVal(panelDiw1, id3Diw1[i], getBit(sys->rcp.rcpDIW1.uiCmd[i],1));  
		SetCtrlVal(panelDiw1, id4Diw1[i], getBit(sys->rcp.rcpDIW1.uiCmd[i],2));  
		SetCtrlVal(panelDiw1, id5Diw1[i], getBit(sys->rcp.rcpDIW1.uiCmd[i],3));  
	}
	
	///////////////////////////////////////////////////////////////////////////////
	SetCtrlVal(panelAcid, RCP_ACID_TIME, sys->rcp.rcpACID.proc_time);
	SetCtrlVal(panelAcid, RCP_ACID_TAKE_WEIGHT, sys->rcp.rcpACID.take_weight);
	int id0Acid[6]={RCP_ACID_NEXT1,RCP_ACID_NEXT2,RCP_ACID_NEXT3,RCP_ACID_NEXT4};
	for(int i=0;i<4;i++)
		SetCtrlVal(panelAcid, id0Acid[i],getBit(sys->rcp.rcpACID.next_tank,i));
	
	
	/////////////////////////////////////////////////////////////////////////////
	SetCtrlVal(panelDiw2, RCP_DIW2_TAKE_WEIGHT, sys->rcp.rcpDIW2.take_weight);
	int id0Diw2[6]={RCP_DIW2_NEXT1,RCP_DIW2_NEXT2,RCP_DIW2_NEXT3};
	for(int i=0;i<3;i++)
		SetCtrlVal(panelDiw2, id0Diw2[i], getBit(sys->rcp.rcpDIW2.next_tank,i));

		
	SetCtrlVal(panelDiw2, RCP_DIW2_TIMES, sys->rcp.rcpDIW2.LoopCount);
	
	int id1Diw2[6]={RCP_DIW2_TIME_1,RCP_DIW2_TIME_2,RCP_DIW2_TIME_3,RCP_DIW2_TIME_4,RCP_DIW2_TIME_5,RCP_DIW2_TIME_6};
	int id2Diw2[6]={RCP_DIW2_UP_1,RCP_DIW2_UP_2,RCP_DIW2_UP_3,RCP_DIW2_UP_4,RCP_DIW2_UP_5,RCP_DIW2_UP_6}; 
	int id3Diw2[6]={RCP_DIW2_DOWN_1,RCP_DIW2_DOWN_2,RCP_DIW2_DOWN_3,RCP_DIW2_DOWN_4,RCP_DIW2_DOWN_5,RCP_DIW2_DOWN_6};
	int id4Diw2[6]={RCP_DIW2_BUBBLE_1,RCP_DIW2_BUBBLE_2,RCP_DIW2_BUBBLE_3,RCP_DIW2_BUBBLE_4,RCP_DIW2_BUBBLE_5,RCP_DIW2_BUBBLE_6};
	int id5Diw2[6]={RCP_DIW2_DRAIN_1,RCP_DIW2_DRAIN_2,RCP_DIW2_DRAIN_3,RCP_DIW2_DRAIN_4,RCP_DIW2_DRAIN_5,RCP_DIW2_DRAIN_6};
	for(int i=0;i<6;i++)
	{
		SetCtrlVal(panelDiw2, id1Diw2[i], sys->rcp.rcpDIW2.uiRemain[i]);
		SetCtrlVal(panelDiw2, id2Diw2[i], getBit(sys->rcp.rcpDIW2.uiCmd[i],0));  
		SetCtrlVal(panelDiw2, id3Diw2[i], getBit(sys->rcp.rcpDIW2.uiCmd[i],1));  
		SetCtrlVal(panelDiw2, id4Diw2[i], getBit(sys->rcp.rcpDIW2.uiCmd[i],2));  
		SetCtrlVal(panelDiw2, id5Diw2[i], getBit(sys->rcp.rcpDIW2.uiCmd[i],3));  
	}
	
	
	///////////////////////////////////////////////////////////////////////////////
	SetCtrlVal(panelKoh, RCP_KOH_TAKE_WEIGHT, sys->rcp.rcpKOH.take_weight);
	SetCtrlVal(panelKoh, RCP_KOH_TIME, sys->rcp.rcpKOH.proc_time);
	int id0Koh[6]={RCP_KOH_NEXT1,RCP_KOH_NEXT2};
	for(int i=0;i<2;i++)
		SetCtrlVal(panelKoh, id0Koh[i],getBit(sys->rcp.rcpKOH.next_tank,i));
	
	
	
	/////////////////////////////////////////////////////////////////////////////
	SetCtrlVal(panelDiw3, RCP_DIW3_TAKE_WEIGHT, sys->rcp.rcpDIW3.take_weight);
	SetCtrlVal(panelDiw3, RCP_DIW3_TIMES, sys->rcp.rcpDIW3.LoopCount);
	
	int id1Diw3[6]={RCP_DIW3_TIME_1,RCP_DIW3_TIME_2,RCP_DIW3_TIME_3,RCP_DIW3_TIME_4,RCP_DIW3_TIME_5,RCP_DIW3_TIME_6};
	int id2Diw3[6]={RCP_DIW3_UP_1,RCP_DIW3_UP_2,RCP_DIW3_UP_3,RCP_DIW3_UP_4,RCP_DIW3_UP_5,RCP_DIW3_UP_6}; 
	int id3Diw3[6]={RCP_DIW3_DOWN_1,RCP_DIW3_DOWN_2,RCP_DIW3_DOWN_3,RCP_DIW3_DOWN_4,RCP_DIW3_DOWN_5,RCP_DIW3_DOWN_6};
	int id4Diw3[6]={RCP_DIW3_BUBBLE_1,RCP_DIW3_BUBBLE_2,RCP_DIW3_BUBBLE_3,RCP_DIW3_BUBBLE_4,RCP_DIW3_BUBBLE_5,RCP_DIW3_BUBBLE_6};
	int id5Diw3[6]={RCP_DIW3_DRAIN_1,RCP_DIW3_DRAIN_2,RCP_DIW3_DRAIN_3,RCP_DIW3_DRAIN_4,RCP_DIW3_DRAIN_5,RCP_DIW3_DRAIN_6};
	for(int i=0;i<6;i++)
	{
		SetCtrlVal(panelDiw3, id1Diw3[i], sys->rcp.rcpDIW3.uiRemain[i]);
		SetCtrlVal(panelDiw3, id2Diw3[i], getBit(sys->rcp.rcpDIW3.uiCmd[i],0));  
		SetCtrlVal(panelDiw3, id3Diw3[i], getBit(sys->rcp.rcpDIW3.uiCmd[i],1));  
		SetCtrlVal(panelDiw3, id4Diw3[i], getBit(sys->rcp.rcpDIW3.uiCmd[i],2));  
		SetCtrlVal(panelDiw3, id5Diw3[i], getBit(sys->rcp.rcpDIW3.uiCmd[i],3));  
	}
	
	
}

void saveRecipeData(int panel, int rcpId)
{
	char FileName[256];
	char Path[MAX_PATHNAME_LEN ];
	
	GetDir(Path);
	Fmt(FileName,"%s<%s\\recipe\\%d.rcp",Path,rcpId);
	int fSAVE = OpenFile (FileName, VAL_READ_WRITE, VAL_TRUNCATE, VAL_BINARY);
	if(fSAVE > 0)
	{
		int tmp;
		////////////////////////////////////////////////////////////////////
		GetCurrentDateTime (&sys->rcp.date);
		GetCtrlVal(panelSys,RCP_SYS_COMMENT,sys->rcp.comment);
		
		//////////////////////////////////////////////////////////////////
		sys->rcp.rcpSYS.id = rcpId;
		
		int id0Sys[6]={RCP_SYS_NEXT1,RCP_SYS_NEXT2,RCP_SYS_NEXT3,RCP_SYS_NEXT4,RCP_SYS_NEXT5,RCP_SYS_NEXT6};
		sys->rcp.rcpSYS.next_tank=0; 
		for(int i=0;i<6;i++)
		{
			GetCtrlVal(panelSys, id0Sys[i], &tmp);if(tmp) setBit(&sys->rcp.rcpSYS.next_tank,i);
		}
		
		
		/////////////////////////////////////////////////////////////////////
		GetCtrlVal(panelDiw1, RCP_DIW1_TAKE_WEIGHT, &sys->rcp.rcpDIW1.take_weight);
		int id0Diw1[6]={RCP_DIW1_NEXT1,RCP_DIW1_NEXT2,RCP_DIW1_NEXT3,RCP_DIW1_NEXT4,RCP_DIW1_NEXT5};
		sys->rcp.rcpDIW1.next_tank=0; 
		for(int i=0;i<5;i++)
		{
			GetCtrlVal(panelDiw1, id0Diw1[i], &tmp);if(tmp) setBit(&sys->rcp.rcpDIW1.next_tank,i);
		}
		
		
		GetCtrlVal(panelDiw1, RCP_DIW1_TIMES, &sys->rcp.rcpDIW1.LoopCount);
		
		
		int id1Diw1[6]={RCP_DIW1_TIME_1,RCP_DIW1_TIME_2,RCP_DIW1_TIME_3,RCP_DIW1_TIME_4,RCP_DIW1_TIME_5,RCP_DIW1_TIME_6};
		int id2Diw1[6]={RCP_DIW1_UP_1,RCP_DIW1_UP_2,RCP_DIW1_UP_3,RCP_DIW1_UP_4,RCP_DIW1_UP_5,RCP_DIW1_UP_6}; 
		int id3Diw1[6]={RCP_DIW1_DOWN_1,RCP_DIW1_DOWN_2,RCP_DIW1_DOWN_3,RCP_DIW1_DOWN_4,RCP_DIW1_DOWN_5,RCP_DIW1_DOWN_6};
		int id4Diw1[6]={RCP_DIW1_BUBBLE_1,RCP_DIW1_BUBBLE_2,RCP_DIW1_BUBBLE_3,RCP_DIW1_BUBBLE_4,RCP_DIW1_BUBBLE_5,RCP_DIW1_BUBBLE_6};
		int id5Diw1[6]={RCP_DIW1_DRAIN_1,RCP_DIW1_DRAIN_2,RCP_DIW1_DRAIN_3,RCP_DIW1_DRAIN_4,RCP_DIW1_DRAIN_5,RCP_DIW1_DRAIN_6};
		for(int i=0;i<6;i++)
		{
			GetCtrlVal(panelDiw1, id1Diw1[i], &sys->rcp.rcpDIW1.uiRemain[i]);
			sys->rcp.rcpDIW1.uiCmd[i]=0;
			GetCtrlVal(panelDiw1, id2Diw1[i], &tmp);if(tmp) setBit(&sys->rcp.rcpDIW1.uiCmd[i],0);
			GetCtrlVal(panelDiw1, id3Diw1[i], &tmp);if(tmp) setBit(&sys->rcp.rcpDIW1.uiCmd[i],1);
			GetCtrlVal(panelDiw1, id4Diw1[i], &tmp);if(tmp) setBit(&sys->rcp.rcpDIW1.uiCmd[i],2);
			GetCtrlVal(panelDiw1, id5Diw1[i], &tmp);if(tmp) setBit(&sys->rcp.rcpDIW1.uiCmd[i],3);
		}
		sys->rcp.rcpDIW1.proc_time = sys->rcp.rcpDIW1.uiRemain[0] + 
			(sys->rcp.rcpDIW1.uiRemain[1] + sys->rcp.rcpDIW1.uiRemain[2] + sys->rcp.rcpDIW1.uiRemain[3])*sys->rcp.rcpDIW1.LoopCount + 
			sys->rcp.rcpDIW1.uiRemain[4] + sys->rcp.rcpDIW1.uiRemain[5];
		
		
		///////////////////////////////////////////////////////////////////////////////
		GetCtrlVal(panelAcid, RCP_ACID_TIME, &sys->rcp.rcpACID.proc_time);
		GetCtrlVal(panelAcid, RCP_ACID_TAKE_WEIGHT, &sys->rcp.rcpACID.take_weight);
		
		int id0Acid[6]={RCP_ACID_NEXT1,RCP_ACID_NEXT2,RCP_ACID_NEXT3,RCP_ACID_NEXT4};
		sys->rcp.rcpACID.next_tank=0; 
		for(int i=0;i<4;i++)
		{
			GetCtrlVal(panelAcid, id0Acid[i], &tmp);if(tmp) setBit(&sys->rcp.rcpACID.next_tank,i);
		}
		
		
		
		/////////////////////////////////////////////////////////////////////
		GetCtrlVal(panelDiw2, RCP_DIW2_TAKE_WEIGHT, &sys->rcp.rcpDIW2.take_weight);
		int id0Diw2[6]={RCP_DIW2_NEXT1,RCP_DIW2_NEXT2,RCP_DIW2_NEXT3};
		sys->rcp.rcpDIW2.next_tank=0; 
		for(int i=0;i<3;i++)
		{
			GetCtrlVal(panelDiw2, id0Diw2[i], &tmp);if(tmp) setBit(&sys->rcp.rcpDIW2.next_tank,i);
		}
		
		GetCtrlVal(panelDiw2, RCP_DIW2_TIMES, &sys->rcp.rcpDIW2.LoopCount);
		
		
		int id1Diw2[6]={RCP_DIW2_TIME_1,RCP_DIW2_TIME_2,RCP_DIW2_TIME_3,RCP_DIW2_TIME_4,RCP_DIW2_TIME_5,RCP_DIW2_TIME_6};
		int id2Diw2[6]={RCP_DIW2_UP_1,RCP_DIW2_UP_2,RCP_DIW2_UP_3,RCP_DIW2_UP_4,RCP_DIW2_UP_5,RCP_DIW2_UP_6}; 
		int id3Diw2[6]={RCP_DIW2_DOWN_1,RCP_DIW2_DOWN_2,RCP_DIW2_DOWN_3,RCP_DIW2_DOWN_4,RCP_DIW2_DOWN_5,RCP_DIW2_DOWN_6};
		int id4Diw2[6]={RCP_DIW2_BUBBLE_1,RCP_DIW2_BUBBLE_2,RCP_DIW2_BUBBLE_3,RCP_DIW2_BUBBLE_4,RCP_DIW2_BUBBLE_5,RCP_DIW2_BUBBLE_6};
		int id5Diw2[6]={RCP_DIW2_DRAIN_1,RCP_DIW2_DRAIN_2,RCP_DIW2_DRAIN_3,RCP_DIW2_DRAIN_4,RCP_DIW2_DRAIN_5,RCP_DIW2_DRAIN_6};
		for(int i=0;i<6;i++)
		{
			GetCtrlVal(panelDiw2, id1Diw2[i], &sys->rcp.rcpDIW2.uiRemain[i]);
			sys->rcp.rcpDIW2.uiCmd[i]=0;
			GetCtrlVal(panelDiw2, id2Diw2[i], &tmp);if(tmp) setBit(&sys->rcp.rcpDIW2.uiCmd[i],0);
			GetCtrlVal(panelDiw2, id3Diw2[i], &tmp);if(tmp) setBit(&sys->rcp.rcpDIW2.uiCmd[i],1);
			GetCtrlVal(panelDiw2, id4Diw2[i], &tmp);if(tmp) setBit(&sys->rcp.rcpDIW2.uiCmd[i],2);
			GetCtrlVal(panelDiw2, id5Diw2[i], &tmp);if(tmp) setBit(&sys->rcp.rcpDIW2.uiCmd[i],3);
		}
		sys->rcp.rcpDIW2.proc_time = sys->rcp.rcpDIW2.uiRemain[0] + 
			(sys->rcp.rcpDIW2.uiRemain[1] + sys->rcp.rcpDIW2.uiRemain[2] + sys->rcp.rcpDIW2.uiRemain[3])*sys->rcp.rcpDIW2.LoopCount + 
			sys->rcp.rcpDIW2.uiRemain[4] + sys->rcp.rcpDIW2.uiRemain[5];
		
		
		///////////////////////////////////////////////////////////////////////////////
		GetCtrlVal(panelKoh, RCP_KOH_TIME, &sys->rcp.rcpKOH.proc_time);
		GetCtrlVal(panelKoh, RCP_KOH_TAKE_WEIGHT, &sys->rcp.rcpKOH.take_weight);
		int id0Koh[6]={RCP_KOH_NEXT1,RCP_KOH_NEXT2};
		sys->rcp.rcpKOH.next_tank=0; 
		for(int i=0;i<2;i++)
		{
			GetCtrlVal(panelKoh, id0Koh[i], &tmp);if(tmp) setBit(&sys->rcp.rcpKOH.next_tank,i);
		}
		
		
		
		
		/////////////////////////////////////////////////////////////////////
		GetCtrlVal(panelDiw3, RCP_DIW3_TAKE_WEIGHT, &sys->rcp.rcpDIW3.take_weight);
		GetCtrlVal(panelDiw3, RCP_DIW3_TIMES, &sys->rcp.rcpDIW3.LoopCount);
		sys->rcp.rcpDIW3.next_tank=1;
		
		
		int id1Diw3[6]={RCP_DIW3_TIME_1,RCP_DIW3_TIME_2,RCP_DIW3_TIME_3,RCP_DIW3_TIME_4,RCP_DIW3_TIME_5,RCP_DIW3_TIME_6};
		int id2Diw3[6]={RCP_DIW3_UP_1,RCP_DIW3_UP_2,RCP_DIW3_UP_3,RCP_DIW3_UP_4,RCP_DIW3_UP_5,RCP_DIW3_UP_6}; 
		int id3Diw3[6]={RCP_DIW3_DOWN_1,RCP_DIW3_DOWN_2,RCP_DIW3_DOWN_3,RCP_DIW3_DOWN_4,RCP_DIW3_DOWN_5,RCP_DIW3_DOWN_6};
		int id4Diw3[6]={RCP_DIW3_BUBBLE_1,RCP_DIW3_BUBBLE_2,RCP_DIW3_BUBBLE_3,RCP_DIW3_BUBBLE_4,RCP_DIW3_BUBBLE_5,RCP_DIW3_BUBBLE_6};
		int id5Diw3[6]={RCP_DIW3_DRAIN_1,RCP_DIW3_DRAIN_2,RCP_DIW3_DRAIN_3,RCP_DIW3_DRAIN_4,RCP_DIW3_DRAIN_5,RCP_DIW3_DRAIN_6};
		for(int i=0;i<6;i++)
		{
			GetCtrlVal(panelDiw3, id1Diw3[i], &sys->rcp.rcpDIW3.uiRemain[i]);
			sys->rcp.rcpDIW3.uiCmd[i]=0;
			GetCtrlVal(panelDiw3, id2Diw3[i], &tmp);if(tmp) setBit(&sys->rcp.rcpDIW3.uiCmd[i],0);
			GetCtrlVal(panelDiw3, id3Diw3[i], &tmp);if(tmp) setBit(&sys->rcp.rcpDIW3.uiCmd[i],1);
			GetCtrlVal(panelDiw3, id4Diw3[i], &tmp);if(tmp) setBit(&sys->rcp.rcpDIW3.uiCmd[i],2);
			GetCtrlVal(panelDiw3, id5Diw3[i], &tmp);if(tmp) setBit(&sys->rcp.rcpDIW3.uiCmd[i],3);
		}
		sys->rcp.rcpDIW3.proc_time = sys->rcp.rcpDIW3.uiRemain[0] + 
			(sys->rcp.rcpDIW3.uiRemain[1] + sys->rcp.rcpDIW3.uiRemain[2] + sys->rcp.rcpDIW3.uiRemain[3])*sys->rcp.rcpDIW3.LoopCount + 
			sys->rcp.rcpDIW3.uiRemain[4] + sys->rcp.rcpDIW3.uiRemain[5];
		
		
		/////////////////////////////////////////////////////////////////////////////////////////
		WriteFile(fSAVE,(char*)&sys->rcp,sizeof(RECIPE));
		CloseFile (	fSAVE );
		
		char cDateSTR[32];  
		FormatDateTimeString (sys->rcp.date, "%Y/%m/%d %H:%M:%S", cDateSTR, 20);
		SetCtrlVal (panel, RCP_SYS_DATE, cDateSTR);
	}else{
	   MessagePopup("message","保存配方文件出错");
	}

}

int CVICALLBACK Call_Recipe (int panel, int control, int event,void *callbackData, int eventData1, int eventData2)
{
	int  RcipID = 0;

	switch (event) {
		case EVENT_COMMIT:
			switch (control) {
				case RCP_SYS_COFM:
					if(CheckAuth(OP_RCP) == 0)
						break;
					if (!ConfirmPopup("操作确认","是否确定执行您选择的功能？"))		
						break;
					
					writeRecipe();
					break;
				case RCP_SYS_COPY:
					if(CheckAuth(OP_RCP) == 0)
						break;
					if (!ConfirmPopup("操作确认","是否确定执行您选择的功能？"))		
						break;
					GetCtrlVal(panelSys, RCP_SYS_RING, &copyRcipID);
					SetCtrlAttribute (panel, RCP_SYS_PASTE, ATTR_DIMMED, 0);
					
					break;
					
				case RCP_SYS_PASTE:
					if(CheckAuth(OP_RCP) == 0)
						break;
					if (!ConfirmPopup("操作确认","是否确定执行您选择的功能？"))		
						break;
					LoadRecipeData(panel,copyRcipID);
					
					break;
					
					
				case RCP_SYS_SAVE:
					if(CheckAuth(OP_RCP) == 0)
						break;
					if (!ConfirmPopup("操作确认","是否确定执行您选择的功能？"))		
						break;

					SetWaitCursor (1);
					ProcessSystemEvents();

					GetCtrlVal(panelSys, RCP_SYS_RING, &RcipID);
					saveRecipeData(panel,RcipID);
					
					SetCtrlAttribute (panel, RCP_SYS_SAVE, ATTR_CTRL_VAL, 0);
					SetCtrlAttribute (panel, RCP_SYS_SAVE, ATTR_DIMMED, 1);
					SetWaitCursor (0);
					
					//ActionLog(RCP_SAVE_ACT_EVENT,RcipID,0,0,0,0); 
					break;
			
		
	/// =================================== Recipe Select
				case RCP_SYS_RING:
					SetWaitCursor (1);
					ProcessSystemEvents();

					GetCtrlVal(panelSys, RCP_SYS_RING, &RcipID);
					LoadRecipeData(panel,RcipID);

					SetWaitCursor (0);
					break;
			}
			break;
			
		case EVENT_VAL_CHANGED:
				SetCtrlAttribute (panel, RCP_SYS_SAVE, ATTR_DIMMED, 0);

			break;
	}
	return 0;
}

void initRecipePanel(int panel,int rcpId)
{
	GetPanelHandleFromTabPage (panel, PANEL_RCP_TAB, 0, &panelSys);
	GetPanelHandleFromTabPage (panel, PANEL_RCP_TAB, 1, &panelDiw1); 
	GetPanelHandleFromTabPage (panel, PANEL_RCP_TAB, 2, &panelAcid);
	GetPanelHandleFromTabPage (panel, PANEL_RCP_TAB, 3, &panelDiw2);
	GetPanelHandleFromTabPage (panel, PANEL_RCP_TAB, 4, &panelKoh);
	GetPanelHandleFromTabPage (panel, PANEL_RCP_TAB, 5, &panelDiw3);
	
	SetCtrlVal(panelSys, RCP_SYS_RING, rcpId);
	LoadRecipeData(panel,rcpId);	
}

