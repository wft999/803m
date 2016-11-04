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

//==============================================================================
// Global variables
int copyRcipID=-1;
RECIPE rcp; 
int panelSys;
int panelDiw1;
//==============================================================================
// Global functions
void LoadRecipeData(int panel, int rcpId)
{
	char FileName[256];
	char Path[MAX_PATHNAME_LEN ];
	
	GetDir(Path);
	Fmt(FileName,"%s<%s\\recipe\\%d.rcp",Path,rcpId);
	int fSAVE = OpenFile (FileName, VAL_READ_ONLY, VAL_OPEN_AS_IS, VAL_BINARY);
	if(fSAVE > 0)
	{
		ReadFile(fSAVE,(char*)&rcp,sizeof(RECIPE));
		CloseFile (	fSAVE );
	}else{
		rcp.date=0;
		strcpy(rcp.comment,"配方没有设定");
		rcp.rcpDIW1.LoopCount=10;
		rcp.rcpDIW1.uiRemain[0]=10;
		rcp.rcpDIW1.uiRemain[1]=20; 
		rcp.rcpDIW1.uiRemain[2]=30; 
		rcp.rcpDIW1.uiRemain[3]=40; 
		rcp.rcpDIW1.uiRemain[4]=50; 
		rcp.rcpDIW1.uiRemain[5]=60; 
		rcp.rcpDIW1.uiCmd[0]=1;
		rcp.rcpDIW1.uiCmd[1]=2; 
		rcp.rcpDIW1.uiCmd[2]=4; 
		rcp.rcpDIW1.uiCmd[3]=8; 
		rcp.rcpDIW1.uiCmd[4]=3; 
		rcp.rcpDIW1.uiCmd[5]=10; 
	}
	
	
	/////////////////////////////////////////////////////////////////////////////
	char cDateSTR[32];  
	FormatDateTimeString (rcp.date, "%Y/%m/%d %H:%M:%S", cDateSTR, 20);
	SetCtrlVal (panelSys, RCP_SYS_DATE, cDateSTR);
	
	ResetTextBox(panelSys, RCP_SYS_COMMENT, rcp.comment);  
	
	
	
	/////////////////////////////////////////////////////////////////////////////
	SetCtrlVal(panelDiw1, RCP_DIW1_TIMES, rcp.rcpDIW1.LoopCount);
	
	int id1[6]={RCP_DIW1_TIME_1,RCP_DIW1_TIME_2,RCP_DIW1_TIME_3,RCP_DIW1_TIME_4,RCP_DIW1_TIME_5,RCP_DIW1_TIME_6};
	int id2[6]={RCP_DIW1_UP_1,RCP_DIW1_UP_2,RCP_DIW1_UP_3,RCP_DIW1_UP_4,RCP_DIW1_UP_5,RCP_DIW1_UP_6}; 
	int id3[6]={RCP_DIW1_DOWN_1,RCP_DIW1_DOWN_2,RCP_DIW1_DOWN_3,RCP_DIW1_DOWN_4,RCP_DIW1_DOWN_5,RCP_DIW1_DOWN_6};
	int id4[6]={RCP_DIW1_BUBBLE_1,RCP_DIW1_BUBBLE_2,RCP_DIW1_BUBBLE_3,RCP_DIW1_BUBBLE_4,RCP_DIW1_BUBBLE_5,RCP_DIW1_BUBBLE_6};
	int id5[6]={RCP_DIW1_DRAIN_1,RCP_DIW1_DRAIN_2,RCP_DIW1_DRAIN_3,RCP_DIW1_DRAIN_4,RCP_DIW1_DRAIN_5,RCP_DIW1_DRAIN_6};
	for(int i=0;i<6;i++)
	{
		SetCtrlVal(panelDiw1, id1[i], rcp.rcpDIW1.uiRemain[i]);
		SetCtrlVal(panelDiw1, id2[i], getBit(rcp.rcpDIW1.uiCmd[i],0));  
		SetCtrlVal(panelDiw1, id3[i], getBit(rcp.rcpDIW1.uiCmd[i],1));  
		SetCtrlVal(panelDiw1, id4[i], getBit(rcp.rcpDIW1.uiCmd[i],2));  
		SetCtrlVal(panelDiw1, id5[i], getBit(rcp.rcpDIW1.uiCmd[i],3));  
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
		////////////////////////////////////////////////////////////////////
		GetCurrentDateTime (&rcp.date);
		GetCtrlVal(panelSys,RCP_SYS_COMMENT,rcp.comment);
		
		
		/////////////////////////////////////////////////////////////////////
		GetCtrlVal(panelDiw1, RCP_DIW1_TIMES, &rcp.rcpDIW1.LoopCount);
		
		int tmp;
		int id1[6]={RCP_DIW1_TIME_1,RCP_DIW1_TIME_2,RCP_DIW1_TIME_3,RCP_DIW1_TIME_4,RCP_DIW1_TIME_5,RCP_DIW1_TIME_6};
		int id2[6]={RCP_DIW1_UP_1,RCP_DIW1_UP_2,RCP_DIW1_UP_3,RCP_DIW1_UP_4,RCP_DIW1_UP_5,RCP_DIW1_UP_6}; 
		int id3[6]={RCP_DIW1_DOWN_1,RCP_DIW1_DOWN_2,RCP_DIW1_DOWN_3,RCP_DIW1_DOWN_4,RCP_DIW1_DOWN_5,RCP_DIW1_DOWN_6};
		int id4[6]={RCP_DIW1_BUBBLE_1,RCP_DIW1_BUBBLE_2,RCP_DIW1_BUBBLE_3,RCP_DIW1_BUBBLE_4,RCP_DIW1_BUBBLE_5,RCP_DIW1_BUBBLE_6};
		int id5[6]={RCP_DIW1_DRAIN_1,RCP_DIW1_DRAIN_2,RCP_DIW1_DRAIN_3,RCP_DIW1_DRAIN_4,RCP_DIW1_DRAIN_5,RCP_DIW1_DRAIN_6};
		for(int i=0;i<6;i++)
		{
			GetCtrlVal(panelDiw1, id1[i], &rcp.rcpDIW1.uiRemain[i]);
			rcp.rcpDIW1.uiCmd[i]=0;
			GetCtrlVal(panelDiw1, id2[i], &tmp);if(tmp) setBit(&rcp.rcpDIW1.uiCmd[i],0);
			GetCtrlVal(panelDiw1, id3[i], &tmp);if(tmp) setBit(&rcp.rcpDIW1.uiCmd[i],1);
			GetCtrlVal(panelDiw1, id4[i], &tmp);if(tmp) setBit(&rcp.rcpDIW1.uiCmd[i],2);
			GetCtrlVal(panelDiw1, id5[i], &tmp);if(tmp) setBit(&rcp.rcpDIW1.uiCmd[i],3);
		}
		
		
		//////////////////////////////////////////////////////////////////
		WriteFile(fSAVE,(char*)&rcp,sizeof(RECIPE));
		CloseFile (	fSAVE );
		
		char cDateSTR[32];  
		FormatDateTimeString (rcp.date, "%Y/%m/%d %H:%M:%S", cDateSTR, 20);
		SetCtrlVal (panel, RCP_SYS_DATE, cDateSTR);
	}else{
	   MessagePopup("message","保存配方文件出错");
	}

}

int CVICALLBACK RecipeConfirm (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			if(CheckAuth(OP_RCP) == 0)
				return 0;
			if (!ButtonConfirm (panel,control))		
				return 0; 

			
			//ActionLog(RCP_SEL_ACT_EVENT,sys->rcp.ID,0,0,0,0);  
			
			RemovePopup(0);
			DiscardPanel (panel); 
			
			
			break;
	}
	return 0;
}

int CVICALLBACK Call_Recipe (int panel, int control, int event,void *callbackData, int eventData1, int eventData2)
{
	int  RcipID = 0;
	int RecipeErr = 0;
	
	// Exchange Data

	switch (event) {
	/// =================================== Recipe Saving
		case EVENT_COMMIT:
			switch (control) {
				case RCP_SYS_COPY:
					//if(CheckAuth(OP_RCP) == 0)
					//	break;
					//if (!ButtonConfirm (panel,control))		
					//	break;
					GetCtrlIndex(panelSys, RCP_SYS_RING, &copyRcipID);
					SetCtrlAttribute (panel, RCP_SYS_PASTE, ATTR_DIMMED, 0);
					
					break;
					
				case RCP_SYS_PASTE:
					//if(CheckAuth(OP_RCP) == 0)
					//	break;
					//if (!ButtonConfirm (panel,control))		
					//	break;
					LoadRecipeData(panel,copyRcipID);
					
					break;
					
					
				case RCP_SYS_SAVE:
				//	if(CheckAuth(OP_RCP) == 0)
				//		break;

					SetWaitCursor (1);
					ProcessSystemEvents();

					GetCtrlIndex(panelSys, RCP_SYS_RING, &RcipID);
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

					GetCtrlIndex(panelSys, RCP_SYS_RING, &RcipID);
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
	SetCtrlIndex(panelSys, RCP_SYS_RING, rcpId);
	LoadRecipeData(panel,rcpId);	
}

