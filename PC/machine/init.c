//==============================================================================
//
// Title:       init.c
// Purpose:     A short description of the implementation.
//
// Created on:  2014/7/15 at ¤W¤È 08:39:17 by wang fang.
// Copyright:   hua. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files
#include <formatio.h>
#include "machine.h"
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
int InitLog (void);
void UninitLog(void);
//==============================================================================
// Global functions
void configRobotData(void)
{
	////////////////////////////////////////////////////////////////////
	///
	sys->rb[0].rid = RB01;
	sys->rb[1].rid = RB02;
	sys->rb[2].rid = RB03;
	strncpy(sys->rb[0].name,"robot1",11);
	strncpy(sys->rb[1].name,"robot2",11);
	strncpy(sys->rb[2].name,"robot3",11);

	sys->rb[0].hsHomeStatus.wid = 1; sys->rb[0].hsHomeStatus.bid = 0;
	sys->rb[1].hsHomeStatus.wid = 1; sys->rb[1].hsHomeStatus.bid = 1;
	sys->rb[2].hsHomeStatus.wid = 1; sys->rb[2].hsHomeStatus.bid = 2;	
	
	sys->rb[0].hsBusyStatus.wid = 1; sys->rb[0].hsBusyStatus.bid = 5;
	sys->rb[1].hsBusyStatus.wid = 1; sys->rb[1].hsBusyStatus.bid = 6;
	sys->rb[2].hsBusyStatus.wid = 1; sys->rb[2].hsBusyStatus.bid = 7;
	
	sys->rb[0].hsSetCommandData.wid = 2; sys->rb[0].hsSetCommandData.bid = 0;	
	sys->rb[0].hsAbortCommand.wid = 2; 	sys->rb[0].hsAbortCommand.bid = 1;
	sys->rb[0].hsHome.wid = 2;			sys->rb[0].hsHome.bid = 2;
	sys->rb[0].hsGet.wid = 2;			sys->rb[0].hsGet.bid = 3;
	sys->rb[0].hsPut.wid = 2;			sys->rb[0].hsPut.bid = 4;
	sys->rb[0].hsMove.wid = 2;			sys->rb[0].hsMove.bid = 5;
	sys->rb[0].hsBlow.wid = 2;			sys->rb[0].hsBlow.bid = 6;
	sys->rb[0].hsWash.wid = 2;			sys->rb[0].hsWash.bid = 7;
	
	sys->rb[1].hsSetCommandData.wid = 2;	sys->rb[1].hsSetCommandData.bid = 8;	
	sys->rb[1].hsAbortCommand.wid = 2;	sys->rb[1].hsAbortCommand.bid = 1;
	sys->rb[1].hsHome.wid = 2;	sys->rb[1].hsHome.bid = 10;
	sys->rb[1].hsGet.wid = 2;	sys->rb[1].hsGet.bid = 11;
	sys->rb[1].hsPut.wid = 2;	sys->rb[1].hsPut.bid = 12;
	sys->rb[1].hsMove.wid = 2;	sys->rb[1].hsMove.bid = 13;
	sys->rb[1].hsBlow.wid = 2;	sys->rb[1].hsBlow.bid = 14;
	sys->rb[1].hsWash.wid = 2;	sys->rb[1].hsWash.bid = 15;
	
	sys->rb[2].hsSetCommandData.wid = 3;	sys->rb[2].hsSetCommandData.bid = 0;	
	sys->rb[2].hsAbortCommand.wid = 2;	sys->rb[2].hsAbortCommand.bid = 1;
	sys->rb[2].hsHome.wid = 3;	sys->rb[2].hsHome.bid = 2;
	sys->rb[2].hsGet.wid = 3;	sys->rb[2].hsGet.bid = 3;
	sys->rb[2].hsPut.wid = 3;	sys->rb[2].hsPut.bid = 4;
	sys->rb[2].hsMove.wid = 3;	sys->rb[2].hsMove.bid = 5;
	sys->rb[2].hsBlow.wid = 3;	sys->rb[2].hsBlow.bid = 6;
	sys->rb[2].hsWash.wid = 3;	sys->rb[2].hsWash.bid = 7;
	
	
	sys->rb[0].hsJogSpdX.wid = 18;	sys->rb[0].hsJogSpdX.bid = 0;
	sys->rb[0].hsJogPX.wid = 18;	sys->rb[0].hsJogPX.bid = 1;
	sys->rb[0].hsJogNX.wid = 18;	sys->rb[0].hsJogNX.bid = 2;
	sys->rb[0].hsJogSpdY.wid = 18;	sys->rb[0].hsJogSpdY.bid = 3;
	sys->rb[0].hsJogPY.wid = 18;	sys->rb[0].hsJogPY.bid = 4;
	sys->rb[0].hsJogNY.wid = 18;	sys->rb[0].hsJogNY.bid = 5;
	
	
	sys->rb[1].hsJogSpdX.wid = 18;	sys->rb[1].hsJogSpdX.bid = 6;
	sys->rb[1].hsJogPX.wid = 18;	sys->rb[1].hsJogPX.bid = 7;
	sys->rb[1].hsJogNX.wid = 18;	sys->rb[1].hsJogNX.bid = 8;
	sys->rb[1].hsJogSpdY.wid = 18;	sys->rb[1].hsJogSpdY.bid = 9;
	sys->rb[1].hsJogPY.wid = 18;	sys->rb[1].hsJogPY.bid = 10;
	sys->rb[1].hsJogNY.wid = 18;	sys->rb[1].hsJogNY.bid = 11;
	
	sys->rb[2].hsJogSpdX.wid = 19;	sys->rb[2].hsJogSpdX.bid = 0;
	sys->rb[2].hsJogPX.wid = 19;	sys->rb[2].hsJogPX.bid = 1;
	sys->rb[2].hsJogNX.wid = 19;	sys->rb[2].hsJogNX.bid = 2;
	sys->rb[2].hsJogSpdY.wid = 19;	sys->rb[2].hsJogSpdY.bid = 3;
	sys->rb[2].hsJogPY.wid = 19;	sys->rb[2].hsJogPY.bid = 4;
	sys->rb[2].hsJogNY.wid = 19;	sys->rb[2].hsJogNY.bid = 5;
	
	sys->rb[0].hsFill.wid = 19;	sys->rb[0].hsFill.bid = 10;
	sys->rb[1].hsFill.wid = 19;	sys->rb[1].hsFill.bid = 11;
	sys->rb[2].hsFill.wid = 19;	sys->rb[2].hsFill.bid = 12;   
	
/*	sys->rb[0].hsSafeMode.wid = 24;	sys->rb[0].hsSafeMode.bid = 0;
	sys->rb[1].hsSafeMode.wid = 24;	sys->rb[1].hsSafeMode.bid = 0;
	sys->rb[2].hsSafeMode.wid = 24;	sys->rb[2].hsSafeMode.bid = 0;  */
	
	sys->rb[0].hsTeach.wid = 23;	sys->rb[0].hsTeach.bid = 6;
	sys->rb[1].hsTeach.wid = 23;	sys->rb[1].hsTeach.bid = 6;
	sys->rb[2].hsTeach.wid = 23;	sys->rb[2].hsTeach.bid = 6;
	
	sys->rb[0].hsChuck.wid = 23;	sys->rb[0].hsChuck.bid = 7;
	sys->rb[1].hsChuck.wid = 23;	sys->rb[1].hsChuck.bid = 8;
	sys->rb[2].hsChuck.wid = 23;	sys->rb[2].hsChuck.bid = 9;
	
	////////////////////////////////////////////////////////////////////
	//output

	////////////////////////////////////////////////////////////////////
	sys->rb[0].UIPosTop = 310.0;
	sys->rb[0].UIPosLow = 350.0;
	sys->rb[0].UIPosLeft = 165.0;
	sys->rb[0].UIPosRight = 5*50.0 + 165.0;
	
	sys->rb[1].UIPosTop = 310.0;
	sys->rb[1].UIPosLow = 350.0;
	sys->rb[1].UIPosLeft = 415.0;
	sys->rb[1].UIPosRight = 6*50.0 + 415.0;
	
	sys->rb[2].UIPosTop = 310.0;
	sys->rb[2].UIPosLow = 350.0;
	sys->rb[2].UIPosLeft = 715.0;
	sys->rb[2].UIPosRight = 5*50.0 + 715.0;
	
	/////////////////////////////////////////////////////////////////
	RTANK_ID t;
	t = RTK_05_01; ListInsertItem(sys->rb[0].rtkPriList, &t, END_OF_LIST);
	t = RTK_05_02; ListInsertItem(sys->rb[0].rtkPriList, &t, END_OF_LIST);
	
	t = RTK_04_01; ListInsertItem(sys->rb[0].rtkPriList, &t, END_OF_LIST);
	t = RTK_04_02; ListInsertItem(sys->rb[0].rtkPriList, &t, END_OF_LIST);
	
	t = RTK_02_01; ListInsertItem(sys->rb[0].rtkPriList, &t, END_OF_LIST);
	t = RTK_02_02; ListInsertItem(sys->rb[0].rtkPriList, &t, END_OF_LIST);
	
	t = RTK_03_01; ListInsertItem(sys->rb[0].rtkPriList, &t, END_OF_LIST);
	t = RTK_03_02; ListInsertItem(sys->rb[0].rtkPriList, &t, END_OF_LIST);
	
	t = RTK_01; ListInsertItem(sys->rb[0].rtkPriList, &t, END_OF_LIST);
	
	sys->rb[0].firstRid = RTK_01; 
	sys->rb[0].lastRid = RTK_06;
	sys->rb[0].standbyRid = RTK_03_02;
	

	//////////////////////////////////////////////////////////////////////////////////////////
	t = RTK_07_01; ListInsertItem(sys->rb[1].rtkPriList, &t, END_OF_LIST);
	t = RTK_07_02; ListInsertItem(sys->rb[1].rtkPriList, &t, END_OF_LIST);
	t = RTK_08_01; ListInsertItem(sys->rb[1].rtkPriList, &t, END_OF_LIST);
	t = RTK_08_02; ListInsertItem(sys->rb[1].rtkPriList, &t, END_OF_LIST);
	t = RTK_06; ListInsertItem(sys->rb[1].rtkPriList, &t, END_OF_LIST);
	t = RTK_11_01; ListInsertItem(sys->rb[1].rtkPriList, &t, END_OF_LIST);
	t = RTK_11_02; ListInsertItem(sys->rb[1].rtkPriList, &t, END_OF_LIST);
	t = RTK_09; ListInsertItem(sys->rb[1].rtkPriList, &t, END_OF_LIST);
	t = RTK_10_01; ListInsertItem(sys->rb[1].rtkPriList, &t, END_OF_LIST);
	t = RTK_10_02; ListInsertItem(sys->rb[1].rtkPriList, &t, END_OF_LIST);
	
	sys->rb[1].standbyRid = RTK_08_01;
	sys->rb[1].firstRid = RTK_06;
	sys->rb[1].lastRid = RTK_12;

	

	///////////////////////////////////////////////////////////////////////////////////////
	t = RTK_12; ListInsertItem(sys->rb[2].rtkPriList, &t, END_OF_LIST);
	t = RTK_13_01; ListInsertItem(sys->rb[2].rtkPriList, &t, END_OF_LIST);
	t = RTK_13_02; ListInsertItem(sys->rb[2].rtkPriList, &t, END_OF_LIST); 
	t = RTK_14; ListInsertItem(sys->rb[2].rtkPriList, &t, END_OF_LIST);
	t = RTK_15; ListInsertItem(sys->rb[2].rtkPriList, &t, END_OF_LIST);
	t = RTK_16; ListInsertItem(sys->rb[2].rtkPriList, &t, END_OF_LIST);
	
	sys->rb[2].standbyRid = RTK_14;
	sys->rb[2].firstRid = RTK_12;
	sys->rb[2].lastRid = RTK_17; 
	
}

void initRTankData(void)
{
	sys->rtk[RTK_03_01].putClean = 1;
	sys->rtk[RTK_03_02].putClean = 1;
	sys->rtk[RTK_06].putClean = 1;
	
	sys->rtk[RTK_02_01].putDirty = 1;
	sys->rtk[RTK_02_02].putDirty = 1;
	sys->rtk[RTK_04_01].putDirty = 1;
	sys->rtk[RTK_04_02].putDirty = 1;
	sys->rtk[RTK_05_01].putDirty = 1;
	sys->rtk[RTK_05_02].putDirty = 1;
		
	sys->rtk[RTK_06].isOverlap  = 1;
	sys->rtk[RTK_12].isOverlap  = 1;
	
	sys->rtk[RTK_01].tid = TANK_01;
	sys->rtk[RTK_02_01].tid = TANK_02;
	sys->rtk[RTK_02_02].tid = TANK_02;
	sys->rtk[RTK_03_01].tid = TANK_03;
	sys->rtk[RTK_03_02].tid = TANK_03;
	sys->rtk[RTK_04_01].tid = TANK_04;
	sys->rtk[RTK_04_02].tid = TANK_04;
	sys->rtk[RTK_05_01].tid = TANK_05;
	sys->rtk[RTK_05_02].tid = TANK_05;
	sys->rtk[RTK_06].tid = TANK_06;
	sys->rtk[RTK_07_01].tid = TANK_07;
	sys->rtk[RTK_07_02].tid = TANK_07;
	sys->rtk[RTK_08_01].tid = TANK_08;
	sys->rtk[RTK_08_02].tid = TANK_08;
	sys->rtk[RTK_09].tid = TANK_09;
	sys->rtk[RTK_10_01].tid = TANK_10;
	sys->rtk[RTK_10_02].tid = TANK_10;
	sys->rtk[RTK_11_01].tid = TANK_11;
	sys->rtk[RTK_11_02].tid = TANK_11;
	sys->rtk[RTK_12].tid = TANK_12;
	sys->rtk[RTK_13_01].tid = TANK_13;
	sys->rtk[RTK_13_02].tid = TANK_13;
	sys->rtk[RTK_14].tid = TANK_14;
	sys->rtk[RTK_15].tid = TANK_15;
	sys->rtk[RTK_16].tid = TANK_16;
	sys->rtk[RTK_17].tid = TANK_17;
	
	sys->rtk[RTK_01].group = 1;
	sys->rtk[RTK_02_01].group = 2;
	sys->rtk[RTK_02_02].group = 2;
	sys->rtk[RTK_03_01].group = 3;
	sys->rtk[RTK_03_02].group = 3;
	sys->rtk[RTK_04_01].group = 4;
	sys->rtk[RTK_04_02].group = 4;
	sys->rtk[RTK_05_01].group = 4;
	sys->rtk[RTK_05_02].group = 4;
	sys->rtk[RTK_06].group = 6;
	sys->rtk[RTK_07_01].group = 7;
	sys->rtk[RTK_07_02].group = 7;
	sys->rtk[RTK_08_01].group = 7;
	sys->rtk[RTK_08_02].group = 7;
	sys->rtk[RTK_09].group = 10;
	sys->rtk[RTK_10_01].group = 10;
	sys->rtk[RTK_10_02].group = 10;
	sys->rtk[RTK_11_01].group = 11;
	sys->rtk[RTK_11_02].group = 11;
	sys->rtk[RTK_12].group = 12;
	sys->rtk[RTK_13_01].group = 13;
	sys->rtk[RTK_13_02].group = 13;
	sys->rtk[RTK_14].group = 14;
	sys->rtk[RTK_15].group = 14;
	sys->rtk[RTK_16].group = 16;
	sys->rtk[RTK_17].group = 17;
	
	sys->rtk[RTK_01].hsPermitGet.wid = 0; sys->rtk[RTK_01].hsPermitGet.bid = 8;
	sys->rtk[RTK_16].hsPermitGet.wid = 0; sys->rtk[RTK_16].hsPermitGet.bid = 10;//???
	sys->rtk[RTK_16].hsPermitPut.wid = 0; sys->rtk[RTK_16].hsPermitPut.bid = 10;
	sys->rtk[RTK_17].hsPermitPut.wid = 0; sys->rtk[RTK_17].hsPermitPut.bid = 13;
	
	sys->rtk[RTK_01].hsFill.wid = 20; 		sys->rtk[RTK_01].hsFill.bid = 0;
	sys->rtk[RTK_02_01].hsFill.wid = 20; 	sys->rtk[RTK_02_01].hsFill.bid = 1;
	sys->rtk[RTK_02_02].hsFill.wid = 20; 	sys->rtk[RTK_02_02].hsFill.bid = 2;
	sys->rtk[RTK_03_01].hsFill.wid = 20; 	sys->rtk[RTK_03_01].hsFill.bid = 3;
	sys->rtk[RTK_03_02].hsFill.wid = 20; 	sys->rtk[RTK_03_02].hsFill.bid = 4;
	sys->rtk[RTK_04_01].hsFill.wid = 20; 	sys->rtk[RTK_04_01].hsFill.bid = 5;
	sys->rtk[RTK_04_02].hsFill.wid = 20; 	sys->rtk[RTK_04_02].hsFill.bid = 6;
	sys->rtk[RTK_05_01].hsFill.wid = 20; 	sys->rtk[RTK_05_01].hsFill.bid = 7;
	sys->rtk[RTK_05_02].hsFill.wid = 20; 	sys->rtk[RTK_05_02].hsFill.bid = 8;
	sys->rtk[RTK_06].hsFill.wid = 20; 		sys->rtk[RTK_06].hsFill.bid = 9;
	sys->rtk[RTK_07_01].hsFill.wid = 20; 	sys->rtk[RTK_07_01].hsFill.bid = 10;
	sys->rtk[RTK_07_02].hsFill.wid = 20; 	sys->rtk[RTK_07_02].hsFill.bid = 11;
	sys->rtk[RTK_08_01].hsFill.wid = 20; 	sys->rtk[RTK_08_01].hsFill.bid = 12;
	sys->rtk[RTK_08_02].hsFill.wid = 20; 	sys->rtk[RTK_08_02].hsFill.bid = 13;
	sys->rtk[RTK_09].hsFill.wid = 20; 		sys->rtk[RTK_09].hsFill.bid = 14;
	sys->rtk[RTK_10_01].hsFill.wid = 20; 	sys->rtk[RTK_10_01].hsFill.bid = 15;
	sys->rtk[RTK_10_02].hsFill.wid = 21; 	sys->rtk[RTK_10_02].hsFill.bid = 0;
	sys->rtk[RTK_11_01].hsFill.wid = 21; 	sys->rtk[RTK_11_01].hsFill.bid = 1;
	sys->rtk[RTK_11_02].hsFill.wid = 21; 	sys->rtk[RTK_11_02].hsFill.bid = 2;
	sys->rtk[RTK_12].hsFill.wid = 21; 		sys->rtk[RTK_12].hsFill.bid = 3;
	sys->rtk[RTK_13_01].hsFill.wid = 21; sys->rtk[RTK_13_01].hsFill.bid = 4;
	sys->rtk[RTK_13_02].hsFill.wid = 21; sys->rtk[RTK_13_02].hsFill.bid = 5;
	sys->rtk[RTK_14].hsFill.wid = 21; sys->rtk[RTK_14].hsFill.bid = 6;
	sys->rtk[RTK_15].hsFill.wid = 21; sys->rtk[RTK_15].hsFill.bid = 7;
	sys->rtk[RTK_16].hsFill.wid = 21; sys->rtk[RTK_16].hsFill.bid = 8;
	sys->rtk[RTK_17].hsFill.wid = 21; sys->rtk[RTK_17].hsFill.bid = 9;
	

	sys->rtk[RTK_01].cmdBeforeGet.status = AUTO_STATUS;
	sys->rtk[RTK_01].cmdBeforeGet.rid = RTK_01;
	sys->rtk[RTK_01].cmdBeforeGet.type = BLOW_COMMAND;
	
	sys->rtk[RTK_01].uiCAR = PANEL_INPROC_01;
	sys->rtk[RTK_02_01].uiCAR = PANEL_INPROC_02;
	sys->rtk[RTK_02_02].uiCAR = PANEL_INPROC_02_1;
	sys->rtk[RTK_03_01].uiCAR = PANEL_INPROC_03;
	sys->rtk[RTK_03_02].uiCAR = PANEL_INPROC_03_1;
	sys->rtk[RTK_04_01].uiCAR = PANEL_INPROC_04;
	sys->rtk[RTK_04_02].uiCAR = PANEL_INPROC_04_1;
	sys->rtk[RTK_05_01].uiCAR = PANEL_INPROC_05;
	sys->rtk[RTK_05_02].uiCAR = PANEL_INPROC_05_1;
	sys->rtk[RTK_06].uiCAR = PANEL_INPROC_06;
	sys->rtk[RTK_07_01].uiCAR = PANEL_INPROC_07;
	sys->rtk[RTK_07_02].uiCAR = PANEL_INPROC_07_1;
	sys->rtk[RTK_08_01].uiCAR = PANEL_INPROC_08;
	sys->rtk[RTK_08_02].uiCAR = PANEL_INPROC_08_1;
	sys->rtk[RTK_09].uiCAR = PANEL_INPROC_09;
	sys->rtk[RTK_10_01].uiCAR = PANEL_INPROC_10;
	sys->rtk[RTK_10_02].uiCAR = PANEL_INPROC_10_1;
	sys->rtk[RTK_11_01].uiCAR = PANEL_INPROC_11;
	sys->rtk[RTK_11_02].uiCAR = PANEL_INPROC_11_1;
	sys->rtk[RTK_12].uiCAR = PANEL_INPROC_12;
	sys->rtk[RTK_13_01].uiCAR = PANEL_INPROC_13;
	sys->rtk[RTK_13_02].uiCAR = PANEL_INPROC_13_1;
	sys->rtk[RTK_14].uiCAR = PANEL_INPROC_14;
	sys->rtk[RTK_15].uiCAR = PANEL_INPROC_15;
	sys->rtk[RTK_16].uiCAR = PANEL_INPROC_16;
	sys->rtk[RTK_17].uiCAR = PANEL_INPROC_17;
	
	sys->rtk[RTK_01].uiTM = PANEL_TM_01;
	sys->rtk[RTK_02_01].uiTM = PANEL_TM_02;
	sys->rtk[RTK_02_02].uiTM = PANEL_TM_02_1;
	sys->rtk[RTK_03_01].uiTM = PANEL_TM_03;
	sys->rtk[RTK_03_02].uiTM = PANEL_TM_03_1;
	sys->rtk[RTK_04_01].uiTM = PANEL_TM_04;
	sys->rtk[RTK_04_02].uiTM = PANEL_TM_04_1;
	sys->rtk[RTK_05_01].uiTM = PANEL_TM_05;
	sys->rtk[RTK_05_02].uiTM = PANEL_TM_05_1;
	sys->rtk[RTK_06].uiTM = PANEL_TM_06;
	sys->rtk[RTK_07_01].uiTM = PANEL_TM_07;
	sys->rtk[RTK_07_02].uiTM = PANEL_TM_07_1;
	sys->rtk[RTK_08_01].uiTM = PANEL_TM_08;
	sys->rtk[RTK_08_02].uiTM = PANEL_TM_08_1;
	sys->rtk[RTK_09].uiTM = PANEL_TM_09;
	sys->rtk[RTK_10_01].uiTM = PANEL_TM_10;
	sys->rtk[RTK_10_02].uiTM = PANEL_TM_10_1;
	sys->rtk[RTK_11_01].uiTM = PANEL_TM_11;
	sys->rtk[RTK_11_02].uiTM = PANEL_TM_11_1;
	sys->rtk[RTK_12].uiTM = PANEL_TM_12;
	sys->rtk[RTK_13_01].uiTM = PANEL_TM_13;
	sys->rtk[RTK_13_02].uiTM = PANEL_TM_13_1;
	sys->rtk[RTK_14].uiTM = PANEL_TM_14;
	sys->rtk[RTK_15].uiTM = PANEL_TM_15;
	sys->rtk[RTK_16].uiTM = PANEL_TM_16;
	sys->rtk[RTK_17].uiTM = PANEL_TM_17;
	
	for(int j = 0; j < RTANK_NUM; j++)
	{
		CmtNewLock(NULL, 0, &sys->rtk[j].collisionLock);
	}
}

void initRobotData(void)
{
	//////////////////////////////////////////////////////////////
	//robot1
	//sys->rb[0].curPosX = 3000*10000;
//	sys->rb[0].curPosY = 0*10000;
	
/*	sys->rb[1].curPosX = 2000*10000;
	sys->rb[1].curPosY = 500*10000;
	
	sys->rb[2].curPosX = 2000*10000;
	sys->rb[2].curPosY = 500*10000;  */


	for(int i =0; i< ROBOT_NUM; i++)
	{
		sys->rb[i].rtkPriList = ListCreate(sizeof(RTANK_ID));
		sys->rb[i].cmdList =  ListCreate(sizeof(ROBOT_COMMAND));
		sys->rb[i].rid = i;
	}
	

	configRobotData(); 
	
}

void configTankData(void)
{
	strcpy(sys->tk[TANK_01].name,"Loader");
	strcpy(sys->tk[TANK_02].name,"DIW1");
	strcpy(sys->tk[TANK_03].name,"HF");
	strcpy(sys->tk[TANK_04].name,"DIW2");
	strcpy(sys->tk[TANK_05].name,"KOH");
	strcpy(sys->tk[TANK_06].name,"DIW3");
	strcpy(sys->tk[TANK_07].name,"Unloader");
/*	strcpy(sys->tk[TANK_08].name,"TEX4");
	strcpy(sys->tk[TANK_09].name,"HDIW3");
	strcpy(sys->tk[TANK_10].name,"HDIW4");
	strcpy(sys->tk[TANK_11].name,"HF");
	strcpy(sys->tk[TANK_12].name,"HDIW5");
	strcpy(sys->tk[TANK_13].name,"HDIW6");
	strcpy(sys->tk[TANK_14].name,"HDIW7");
	strcpy(sys->tk[TANK_15].name,"HDIW8");
	strcpy(sys->tk[TANK_16].name,"AKF");
	strcpy(sys->tk[TANK_17].name,"DRY");
	strcpy(sys->tk[TANK_AUX_PH1].name,"PreHeat01");
	strcpy(sys->tk[TANK_AUX_PH2].name,"PreHeat02");
	strcpy(sys->tk[TANK_AUX_IN].name,"Inline");
	strcpy(sys->tk[TANK_AUX_DIW].name,"¼o²GDIW");
	strcpy(sys->tk[TANK_AUX_TEX].name,"¼o²GTEX");
	strcpy(sys->tk[TANK_AUX_HF].name,"¼o²GHF");  */
	
	////////////////////////////////////////////////////////////////
	//handshake
	sys->tk[TANK_AUX_PH1].hsPHStart.wid = 0; sys->tk[TANK_AUX_PH1].hsPHStart.bid = 11;
	sys->tk[TANK_AUX_PH2].hsPHStart.wid = 0; sys->tk[TANK_AUX_PH2].hsPHStart.bid = 12;
	
	sys->tk[TANK_01].hsShutOpen.wid = 4; sys->tk[TANK_01].hsShutOpen.bid = 0;
	sys->tk[TANK_02].hsShutOpen.wid = 4; sys->tk[TANK_02].hsShutOpen.bid = 1; 

	sys->tk[TANK_04].hsShutOpen.wid = 4; sys->tk[TANK_04].hsShutOpen.bid = 2; 
	sys->tk[TANK_05].hsShutOpen.wid = 4; sys->tk[TANK_05].hsShutOpen.bid = 3; 

	sys->tk[TANK_07].hsShutOpen.wid = 4; sys->tk[TANK_07].hsShutOpen.bid = 4; 
	sys->tk[TANK_08].hsShutOpen.wid = 4; sys->tk[TANK_08].hsShutOpen.bid = 5; 

	sys->tk[TANK_11].hsShutOpen.wid = 4; sys->tk[TANK_11].hsShutOpen.bid = 6; 

//	sys->tk[TANK_14].hsShutOpen.wid = 4; sys->tk[TANK_14].hsShutOpen.bid = 7; 
//	sys->tk[TANK_15].hsShutOpen.wid = 4; sys->tk[TANK_15].hsShutOpen.bid = 8;
	sys->tk[TANK_17].hsShutOpen.wid = 4; sys->tk[TANK_17].hsShutOpen.bid = 9;
	
	
	sys->tk[TANK_01].hsShutClose.wid = 5; sys->tk[TANK_01].hsShutClose.bid = 0;
	sys->tk[TANK_02].hsShutClose.wid = 5; sys->tk[TANK_02].hsShutClose.bid = 1; 
	
	sys->tk[TANK_04].hsShutClose.wid = 5; sys->tk[TANK_04].hsShutClose.bid = 2; 
	sys->tk[TANK_05].hsShutClose.wid = 5; sys->tk[TANK_05].hsShutClose.bid = 3; 

	sys->tk[TANK_07].hsShutClose.wid = 5; sys->tk[TANK_07].hsShutClose.bid = 4; 
	sys->tk[TANK_08].hsShutClose.wid = 5; sys->tk[TANK_08].hsShutClose.bid = 5; 

	sys->tk[TANK_11].hsShutClose.wid = 5; sys->tk[TANK_11].hsShutClose.bid = 6; 

	//sys->tk[TANK_14].hsShutClose.wid = 5; sys->tk[TANK_14].hsShutClose.bid = 7; 
//	sys->tk[TANK_15].hsShutClose.wid = 5; sys->tk[TANK_15].hsShutClose.bid = 8;
	sys->tk[TANK_17].hsShutClose.wid = 5; sys->tk[TANK_17].hsShutClose.bid = 9;
	
	
	sys->tk[TANK_AUX_PH1].hsPump.wid = 6; sys->tk[TANK_AUX_PH1].hsPump.bid = 0; 
	sys->tk[TANK_AUX_PH2].hsPump.wid = 6; sys->tk[TANK_AUX_PH2].hsPump.bid = 1;
	sys->tk[TANK_02].hsPump.wid = 6; sys->tk[TANK_02].hsPump.bid = 2;

	sys->tk[TANK_04].hsPumpIn.wid = 6; sys->tk[TANK_04].hsPumpIn.bid = 3;
	sys->tk[TANK_04].hsPump.wid = 6; sys->tk[TANK_04].hsPump.bid = 4;
	sys->tk[TANK_05].hsPump.wid = 6; sys->tk[TANK_05].hsPump.bid = 5;
	
	sys->tk[TANK_07].hsPumpIn.wid = 6; sys->tk[TANK_07].hsPumpIn.bid = 6;
	sys->tk[TANK_07].hsPump.wid = 6; sys->tk[TANK_07].hsPump.bid = 7;
	sys->tk[TANK_08].hsPump.wid = 6; sys->tk[TANK_08].hsPump.bid = 8;
	
	sys->tk[TANK_14].hsPump.wid = 6; sys->tk[TANK_14].hsPump.bid = 9;
	sys->tk[TANK_15].hsPump.wid = 6; sys->tk[TANK_15].hsPump.bid = 10;
	sys->tk[TANK_16].hsPump.wid = 6; sys->tk[TANK_16].hsPump.bid = 11;
	sys->tk[TANK_17].hsPump.wid = 6; sys->tk[TANK_17].hsPump.bid = 12;
	
	sys->tk[TANK_AUX_IN].hsPump.wid = 7; sys->tk[TANK_AUX_IN].hsPump.bid = 1; 
	
	sys->tk[TANK_AUX_PH1].hsHeat.wid = 8; sys->tk[TANK_AUX_PH1].hsHeat.bid = 0;
	sys->tk[TANK_AUX_PH2].hsHeat.wid = 8; sys->tk[TANK_AUX_PH2].hsHeat.bid = 1;
	sys->tk[TANK_02].hsHeat.wid = 8; sys->tk[TANK_02].hsHeat.bid = 2;
	sys->tk[TANK_03].hsHeat.wid = 8; sys->tk[TANK_03].hsHeat.bid = 3;
	sys->tk[TANK_04].hsHeat.wid = 8; sys->tk[TANK_04].hsHeat.bid = 4;
	
	sys->tk[TANK_06].hsHeat.wid = 8; sys->tk[TANK_06].hsHeat.bid = 5;
	sys->tk[TANK_07].hsHeat.wid = 8; sys->tk[TANK_07].hsHeat.bid = 6;
	
	sys->tk[TANK_09].hsHeat.wid = 8; sys->tk[TANK_09].hsHeat.bid = 7;
	sys->tk[TANK_10].hsHeat.wid = 8; sys->tk[TANK_10].hsHeat.bid = 8;
	
	sys->tk[TANK_12].hsHeat.wid = 8; sys->tk[TANK_12].hsHeat.bid = 9;
	sys->tk[TANK_13].hsHeat.wid = 8; sys->tk[TANK_13].hsHeat.bid = 10;
	sys->tk[TANK_14].hsHeat.wid = 8; sys->tk[TANK_14].hsHeat.bid = 11;
	sys->tk[TANK_15].hsHeat.wid = 8; sys->tk[TANK_15].hsHeat.bid = 12;
	sys->tk[TANK_AUX_IN].hsHeat.wid = 8; sys->tk[TANK_AUX_IN].hsHeat.bid = 13;
	sys->tk[TANK_16].hsHeat.wid = 8; sys->tk[TANK_16].hsHeat.bid = 14;
	sys->tk[TANK_17].hsHeat.wid = 8; sys->tk[TANK_17].hsHeat.bid = 15;
	
	
	sys->tk[TANK_02].hsDown.wid = 10; sys->tk[TANK_02].hsDown.bid = 0;
	sys->tk[TANK_04].hsDown.wid = 10; sys->tk[TANK_04].hsDown.bid = 1; 
	sys->tk[TANK_07].hsDown.wid = 10; sys->tk[TANK_07].hsDown.bid = 2;
	sys->tk[TANK_11].hsDown.wid = 10; sys->tk[TANK_11].hsDown.bid = 3;
	sys->tk[TANK_03].hsDown.wid = 10; sys->tk[TANK_03].hsDown.bid = 4;
	sys->tk[TANK_06].hsDown.wid = 10; sys->tk[TANK_06].hsDown.bid = 5;
	sys->tk[TANK_09].hsDown.wid = 10; sys->tk[TANK_09].hsDown.bid = 6;
	sys->tk[TANK_10].hsDown.wid = 10; sys->tk[TANK_10].hsDown.bid = 7;
	sys->tk[TANK_12].hsDown.wid = 10; sys->tk[TANK_12].hsDown.bid = 8;
	sys->tk[TANK_13].hsDown.wid = 10; sys->tk[TANK_13].hsDown.bid = 9;
	sys->tk[TANK_14].hsDown.wid = 10; sys->tk[TANK_14].hsDown.bid = 10;
	sys->tk[TANK_15].hsDown.wid = 10; sys->tk[TANK_15].hsDown.bid = 11;
	
	sys->tk[TANK_03].hsAddWater.wid = 11; sys->tk[TANK_03].hsAddWater.bid = 0;
	sys->tk[TANK_06].hsAddWater.wid = 11; sys->tk[TANK_06].hsAddWater.bid = 1;
	sys->tk[TANK_09].hsAddWater.wid = 11; sys->tk[TANK_09].hsAddWater.bid = 2;
	sys->tk[TANK_10].hsAddWater.wid = 11; sys->tk[TANK_10].hsAddWater.bid = 3;
	sys->tk[TANK_12].hsAddWater.wid = 11; sys->tk[TANK_12].hsAddWater.bid = 4;
	sys->tk[TANK_13].hsAddWater.wid = 11; sys->tk[TANK_13].hsAddWater.bid = 5;
	sys->tk[TANK_14].hsAddWater.wid = 11; sys->tk[TANK_14].hsAddWater.bid = 6;
	sys->tk[TANK_15].hsAddWater.wid = 11; sys->tk[TANK_15].hsAddWater.bid = 7;
	
	sys->tk[TANK_02].hsWash.wid = 12; sys->tk[TANK_02].hsWash.bid = 0;
	sys->tk[TANK_04].hsWash.wid = 12; sys->tk[TANK_04].hsWash.bid = 1;
	sys->tk[TANK_07].hsWash.wid = 12; sys->tk[TANK_07].hsWash.bid = 2;
	sys->tk[TANK_11].hsWash.wid = 12; sys->tk[TANK_11].hsWash.bid = 3;
	

	sys->tk[TANK_02].hsMake.wid = 14; sys->tk[TANK_02].hsMake.bid = 0;
	sys->tk[TANK_04].hsMake.wid = 14; sys->tk[TANK_04].hsMake.bid = 1;
	sys->tk[TANK_07].hsMake.wid = 14; sys->tk[TANK_07].hsMake.bid = 2;
	sys->tk[TANK_11].hsMake.wid = 14; sys->tk[TANK_11].hsMake.bid = 3;
	
	sys->tk[TANK_04].hsPDrain.wid = 14; sys->tk[TANK_04].hsPDrain.bid = 4;
	sys->tk[TANK_07].hsPDrain.wid = 14; sys->tk[TANK_07].hsPDrain.bid = 5;
	
	sys->tk[TANK_02].hsMMake.wid = 14; sys->tk[TANK_02].hsMMake.bid = 6;
	sys->tk[TANK_04].hsMMake.wid = 14; sys->tk[TANK_04].hsMMake.bid = 7;
	sys->tk[TANK_07].hsMMake.wid = 14; sys->tk[TANK_07].hsMMake.bid = 8;
	sys->tk[TANK_11].hsMMake.wid = 14; sys->tk[TANK_11].hsMMake.bid = 9;
	
	
	sys->tk[TANK_02].hsMakeEnd.wid = 13; sys->tk[TANK_02].hsMakeEnd.bid = 0;
	sys->tk[TANK_04].hsMakeEnd.wid = 13; sys->tk[TANK_04].hsMakeEnd.bid = 1;
	sys->tk[TANK_07].hsMakeEnd.wid = 13; sys->tk[TANK_07].hsMakeEnd.bid = 2;
	sys->tk[TANK_11].hsMakeEnd.wid = 13; sys->tk[TANK_11].hsMakeEnd.bid = 3;
	
	sys->tk[TANK_12].hsDrainOn.wid = 14; sys->tk[TANK_12].hsDrainOn.bid = 15;
	
	sys->tk[TANK_02].hsAC1Dos.wid = 16; sys->tk[TANK_02].hsAC1Dos.bid = 0;
	sys->tk[TANK_02].hsAC2Dos.wid = 16; sys->tk[TANK_02].hsAC2Dos.bid = 1;
	sys->tk[TANK_02].hsAC3Dos.wid = 16; sys->tk[TANK_02].hsAC3Dos.bid = 2;
	
	sys->tk[TANK_04].hsAC1Dos.wid = 16; sys->tk[TANK_04].hsAC1Dos.bid = 3;
	sys->tk[TANK_04].hsAC2Dos.wid = 16; sys->tk[TANK_04].hsAC2Dos.bid = 4;
	sys->tk[TANK_04].hsAC3Dos.wid = 16; sys->tk[TANK_04].hsAC3Dos.bid = 5;
	
	sys->tk[TANK_07].hsAC1Dos.wid = 16; sys->tk[TANK_07].hsAC1Dos.bid = 6;
	sys->tk[TANK_07].hsAC2Dos.wid = 16; sys->tk[TANK_07].hsAC2Dos.bid = 7;
	sys->tk[TANK_07].hsAC3Dos.wid = 16; sys->tk[TANK_07].hsAC3Dos.bid = 8;
	
	sys->tk[TANK_11].hsAC1Dos.wid = 16; sys->tk[TANK_11].hsAC1Dos.bid = 9;
	sys->tk[TANK_11].hsAC2Dos.wid = 16; sys->tk[TANK_11].hsAC2Dos.bid = 10;
	sys->tk[TANK_11].hsAC3Dos.wid = 16; sys->tk[TANK_11].hsAC3Dos.bid = 11;
	
	sys->tk[TANK_04].hsAC4Dos.wid = 16; sys->tk[TANK_04].hsAC4Dos.bid = 12;
	sys->tk[TANK_07].hsAC4Dos.wid = 16; sys->tk[TANK_07].hsAC4Dos.bid = 13;
	
	sys->tk[TANK_AUX_PH1].hsAddWater.wid = 17; sys->tk[TANK_AUX_PH1].hsAddWater.bid = 0;
	sys->tk[TANK_AUX_PH2].hsAddWater.wid = 17; sys->tk[TANK_AUX_PH2].hsAddWater.bid = 1;
	
	sys->tk[TANK_01].hsLDAuto.wid = 22; sys->tk[TANK_01].hsLDAuto.bid = 0;
	sys->tk[TANK_01].hsLDDoor.wid = 22; sys->tk[TANK_01].hsLDDoor.bid = 1;
	
	sys->tk[TANK_01].hsLDTop.wid = 22; sys->tk[TANK_01].hsLDTop.bid = 2;
	sys->tk[TANK_01].hsLDBottom.wid = 22; sys->tk[TANK_01].hsLDBottom.bid = 3;
	sys->tk[TANK_01].hsLDTop2.wid = 22; sys->tk[TANK_01].hsLDTop2.bid = 4;
	sys->tk[TANK_01].hsLDBottom2.wid = 22; sys->tk[TANK_01].hsLDBottom2.bid = 5;
	
	sys->tk[TANK_01].hsLDLeft.wid = 22; sys->tk[TANK_01].hsLDLeft.bid = 7;
	sys->tk[TANK_01].hsLDRight.wid = 22; sys->tk[TANK_01].hsLDRight.bid = 6;
	
	sys->tk[TANK_17].hsLDAuto.wid = 22; sys->tk[TANK_17].hsLDAuto.bid = 12;
	sys->tk[TANK_17].hsLDInit.wid = 22; sys->tk[TANK_17].hsLDInit.bid = 13;
	sys->tk[TANK_17].hsLDDoor.wid = 22; sys->tk[TANK_17].hsLDDoor.bid = 14;

	
	sys->tk[TANK_01].hsLDOnline.wid = 23; sys->tk[TANK_01].hsLDOnline.bid = 11; 
	
	sys->tk[TANK_AUX_DIW].hsDown.wid = 23; sys->tk[TANK_AUX_DIW].hsDown.bid = 12; 
	sys->tk[TANK_AUX_TEX].hsDown.wid = 23; sys->tk[TANK_AUX_TEX].hsDown.bid = 13;
	sys->tk[TANK_AUX_HF].hsDown.wid = 23; sys->tk[TANK_AUX_HF].hsDown.bid = 14;
	
	sys->tk[TANK_16].hsAKFAuto.wid = 22;sys->tk[TANK_16].hsAKFAuto.bid = 8;
	sys->tk[TANK_16].hsAKFHome.wid = 22;sys->tk[TANK_16].hsAKFHome.bid = 9; 
	sys->tk[TANK_16].hsAKFUp.wid = 22;sys->tk[TANK_16].hsAKFUp.bid = 10;
	sys->tk[TANK_16].hsAKFBottom.wid = 22;sys->tk[TANK_16].hsAKFBottom.bid = 11;
	
	sys->tk[TANK_17].hsCVAuto.wid = 22;sys->tk[TANK_17].hsCVAuto.bid = 12;
	sys->tk[TANK_17].hsCVOn.wid = 22;sys->tk[TANK_17].hsCVOn.bid = 13;
	sys->tk[TANK_17].hsCVDoor.wid = 22;sys->tk[TANK_17].hsCVDoor.bid = 14;
	

	/////////////////////////////////////////////////////////////////////////////
	//INPUT
	
	//loader
	sys->tk[TANK_01].xPosA1.wid = 3; sys->tk[TANK_01].xPosA1.bid = 7;
	sys->tk[TANK_01].xPosB1.wid = 3; sys->tk[TANK_01].xPosB1.bid = 8;
	sys->tk[TANK_01].xPosA2.wid = 3; sys->tk[TANK_01].xPosA2.bid = 9;
	sys->tk[TANK_01].xPosB2.wid = 3; sys->tk[TANK_01].xPosB2.bid = 10;
	sys->tk[TANK_01].xPosA3.wid = 3; sys->tk[TANK_01].xPosA3.bid = 11;
	sys->tk[TANK_01].xPosB3.wid = 3; sys->tk[TANK_01].xPosB3.bid = 12;
	sys->tk[TANK_01].xShutOpen.wid = 4; sys->tk[TANK_01].xShutOpen.bid = 4;
	sys->tk[TANK_01].xShutClose.wid = 4; sys->tk[TANK_01].xShutClose.bid = 3;
	sys->tk[TANK_01].xDoorOpen.wid = 4; sys->tk[TANK_01].xDoorOpen.bid = 8;
	sys->tk[TANK_01].xDoorClose.wid = 4; sys->tk[TANK_01].xDoorClose.bid = 7;
	
	//inline
	sys->tk[TANK_AUX_IN].xTempH.wid = 22; sys->tk[TANK_AUX_IN].xTempH.bid = 1;
	sys->tk[TANK_AUX_IN].xTempL.wid = 22; sys->tk[TANK_AUX_IN].xTempL.bid = 0;
	
	sys->tk[TANK_AUX_IN].xLevHH.wid = 22; sys->tk[TANK_AUX_IN].xLevHH.bid = 8;
	sys->tk[TANK_AUX_IN].xLevH.wid = 22; sys->tk[TANK_AUX_IN].xLevH.bid = 7;
	sys->tk[TANK_AUX_IN].xLevL.wid = 22; sys->tk[TANK_AUX_IN].xLevL.bid = 6;
	sys->tk[TANK_AUX_IN].xLevLL.wid = 22; sys->tk[TANK_AUX_IN].xLevLL.bid = 5;
	
	//tank02
	sys->tk[TANK_02].xTempH.wid = 5; sys->tk[TANK_02].xTempH.bid = 7;
	sys->tk[TANK_02].xTempL.wid = 5; sys->tk[TANK_02].xTempL.bid = 6;
	
	sys->tk[TANK_02].xLevUP.wid = 6; sys->tk[TANK_02].xLevUP.bid = 0;
	sys->tk[TANK_02].xLevHH.wid = 6; sys->tk[TANK_02].xLevHH.bid = 4;
	sys->tk[TANK_02].xLevH.wid = 6; sys->tk[TANK_02].xLevH.bid = 3;
	sys->tk[TANK_02].xLevL.wid = 6; sys->tk[TANK_02].xLevL.bid = 2;
	sys->tk[TANK_02].xLevLL.wid = 6; sys->tk[TANK_02].xLevLL.bid = 1;
	
	sys->tk[TANK_02].xShutOpen.wid = 5; sys->tk[TANK_02].xShutOpen.bid = 13;
	sys->tk[TANK_02].xShutClose.wid = 5; sys->tk[TANK_02].xShutClose.bid = 12;
	
/*	sys->tk[TANK_02].xMakeAc1LevH.wid = 7; sys->tk[TANK_02].xMakeAc1LevH.bid = 11;
	sys->tk[TANK_02].xMakeAc1LevL.wid = 7; sys->tk[TANK_02].xMakeAc1LevL.bid = 12;
	sys->tk[TANK_02].xMakeAc2LevH.wid = 7; sys->tk[TANK_02].xMakeAc2LevH.bid = 8;
	sys->tk[TANK_02].xMakeAc2LevL.wid = 7; sys->tk[TANK_02].xMakeAc2LevL.bid = 9; */
	
	sys->tk[TANK_02].xDosAc1LevH.wid = 6; sys->tk[TANK_02].xDosAc1LevH.bid = 11;
	sys->tk[TANK_02].xDosAc1LevL.wid = 6; sys->tk[TANK_02].xDosAc1LevL.bid = 12;
	sys->tk[TANK_02].xDosAc2LevH.wid = 6; sys->tk[TANK_02].xDosAc2LevH.bid = 13;
	sys->tk[TANK_02].xDosAc2LevL.wid = 6; sys->tk[TANK_02].xDosAc2LevL.bid = 14;
	
	
	//tank03
	sys->tk[TANK_03].xTempH.wid = 7; sys->tk[TANK_03].xTempH.bid = 7;
	sys->tk[TANK_03].xTempL.wid = 7; sys->tk[TANK_03].xTempL.bid = 6;
	
	sys->tk[TANK_03].xLevHH.wid = 7; sys->tk[TANK_03].xLevHH.bid = 15;
	sys->tk[TANK_03].xLevH.wid = 7; sys->tk[TANK_03].xLevH.bid = 14;
	//sys->tk[TANK_03].xLevL.wid = 7; sys->tk[TANK_03].xLevL.bid = 13;
	sys->tk[TANK_03].xLevLL.wid = 7; sys->tk[TANK_03].xLevLL.bid = 12;
	
	//tank04
	sys->tk[TANK_04].xTempH.wid = 8; sys->tk[TANK_04].xTempH.bid = 9;
	sys->tk[TANK_04].xTempL.wid = 8; sys->tk[TANK_04].xTempL.bid = 8;
	
	sys->tk[TANK_04].xLevUP.wid = 9; sys->tk[TANK_04].xLevUP.bid = 1; 
	sys->tk[TANK_04].xLevHH.wid = 9; sys->tk[TANK_04].xLevHH.bid = 6;
	sys->tk[TANK_04].xLevH.wid = 9; sys->tk[TANK_04].xLevH.bid = 5;
	sys->tk[TANK_04].xLevL.wid = 9; sys->tk[TANK_04].xLevL.bid = 4;
	sys->tk[TANK_04].xLevLL.wid = 9; sys->tk[TANK_04].xLevLL.bid = 3;
	
	sys->tk[TANK_04].xShutOpen.wid = 8; sys->tk[TANK_04].xShutOpen.bid = 1;
	sys->tk[TANK_04].xShutClose.wid = 8; sys->tk[TANK_04].xShutClose.bid = 0;
	
/*	sys->tk[TANK_04].xMakeAc1LevH.wid = 10; sys->tk[TANK_04].xMakeAc1LevH.bid = 8;
	sys->tk[TANK_04].xMakeAc1LevL.wid = 10; sys->tk[TANK_04].xMakeAc1LevL.bid = 9;
	sys->tk[TANK_04].xMakeAc2LevH.wid = 10; sys->tk[TANK_04].xMakeAc2LevH.bid = 5;
	sys->tk[TANK_04].xMakeAc2LevL.wid = 10; sys->tk[TANK_04].xMakeAc2LevL.bid = 6; */
	
	sys->tk[TANK_04].xDosAc1LevH.wid = 9; sys->tk[TANK_04].xDosAc1LevH.bid = 10;
	sys->tk[TANK_04].xDosAc1LevL.wid = 9; sys->tk[TANK_04].xDosAc1LevL.bid = 11;
	sys->tk[TANK_04].xDosAc2LevH.wid = 9; sys->tk[TANK_04].xDosAc2LevH.bid = 12;
	sys->tk[TANK_04].xDosAc2LevL.wid = 9; sys->tk[TANK_04].xDosAc2LevL.bid = 13;
	sys->tk[TANK_04].xDosAc3LevH.wid = 9; sys->tk[TANK_04].xDosAc3LevH.bid = 14;
	sys->tk[TANK_04].xDosAc3LevL.wid = 9; sys->tk[TANK_04].xDosAc3LevL.bid = 15;
	sys->tk[TANK_04].xDosAc4LevH.wid = 10; sys->tk[TANK_04].xDosAc4LevH.bid = 1;
	sys->tk[TANK_04].xDosAc4LevL.wid = 10; sys->tk[TANK_04].xDosAc4LevL.bid = 2;
	
	//tank05
	sys->tk[TANK_05].xTempH.wid = 8; sys->tk[TANK_05].xTempH.bid = 9;
	sys->tk[TANK_05].xTempL.wid = 8; sys->tk[TANK_05].xTempL.bid = 8;
	
	sys->tk[TANK_05].xShutOpen.wid = 8; sys->tk[TANK_05].xShutOpen.bid = 5;
	sys->tk[TANK_05].xShutClose.wid = 8; sys->tk[TANK_05].xShutClose.bid = 4;
	
	sys->tk[TANK_05].xLevUP.wid = 9; sys->tk[TANK_05].xLevUP.bid = 2;
	sys->tk[TANK_05].xLevHH.wid =9; sys->tk[TANK_05].xLevHH.bid = 6;
	sys->tk[TANK_05].xLevH.wid = 9; sys->tk[TANK_05].xLevH.bid = 5;
	sys->tk[TANK_05].xLevL.wid = 9; sys->tk[TANK_05].xLevL.bid = 4;
	sys->tk[TANK_05].xLevLL.wid = 9; sys->tk[TANK_05].xLevLL.bid = 3;
	
	//tank06
	sys->tk[TANK_06].xTempH.wid = 10; sys->tk[TANK_06].xTempH.bid = 12;
	sys->tk[TANK_06].xTempL.wid = 10; sys->tk[TANK_06].xTempL.bid = 11;
	
	sys->tk[TANK_06].xLevHH.wid = 11; sys->tk[TANK_06].xLevHH.bid = 4;
	sys->tk[TANK_06].xLevH.wid = 11; sys->tk[TANK_06].xLevH.bid = 3;
	//sys->tk[TANK_06].xLevL.wid = 11; sys->tk[TANK_06].xLevL.bid = 2;
	sys->tk[TANK_06].xLevLL.wid = 11; sys->tk[TANK_06].xLevLL.bid = 1;
	
	//tank07
	sys->tk[TANK_07].xTempH.wid = 11; sys->tk[TANK_07].xTempH.bid = 14;
	sys->tk[TANK_07].xTempL.wid = 11; sys->tk[TANK_07].xTempL.bid = 13;
	
	sys->tk[TANK_07].xLevUP.wid = 12; sys->tk[TANK_07].xLevUP.bid = 5;
	sys->tk[TANK_07].xLevHH.wid = 12; sys->tk[TANK_07].xLevHH.bid = 10;
	sys->tk[TANK_07].xLevH.wid = 12; sys->tk[TANK_07].xLevH.bid = 9;
	sys->tk[TANK_07].xLevL.wid = 12; sys->tk[TANK_07].xLevL.bid = 8;
	sys->tk[TANK_07].xLevLL.wid = 12; sys->tk[TANK_07].xLevLL.bid = 7;
	
	sys->tk[TANK_07].xShutOpen.wid = 11; sys->tk[TANK_07].xShutOpen.bid = 6;
	sys->tk[TANK_07].xShutClose.wid = 11; sys->tk[TANK_07].xShutClose.bid = 5;
	
	sys->tk[TANK_07].xDosAc1LevH.wid = 12; sys->tk[TANK_07].xDosAc1LevH.bid = 14;
	sys->tk[TANK_07].xDosAc1LevL.wid = 12; sys->tk[TANK_07].xDosAc1LevL.bid = 15;
	sys->tk[TANK_07].xDosAc2LevH.wid = 13; sys->tk[TANK_07].xDosAc2LevH.bid = 0;
	sys->tk[TANK_07].xDosAc2LevL.wid = 13; sys->tk[TANK_07].xDosAc2LevL.bid = 1;
	sys->tk[TANK_07].xDosAc3LevH.wid = 13; sys->tk[TANK_07].xDosAc3LevH.bid = 2;
	sys->tk[TANK_07].xDosAc3LevL.wid = 13; sys->tk[TANK_07].xDosAc3LevL.bid = 3;

	
	//tank08
	sys->tk[TANK_08].xTempH.wid = 11; sys->tk[TANK_08].xTempH.bid = 14;
	sys->tk[TANK_08].xTempL.wid = 11; sys->tk[TANK_08].xTempL.bid = 13;
	
	sys->tk[TANK_08].xLevUP.wid = 12; sys->tk[TANK_08].xLevUP.bid = 6; 
	sys->tk[TANK_08].xLevHH.wid = 12; sys->tk[TANK_08].xLevHH.bid = 10;
	sys->tk[TANK_08].xLevH.wid = 12; sys->tk[TANK_08].xLevH.bid = 9;
	sys->tk[TANK_08].xLevL.wid = 12; sys->tk[TANK_08].xLevL.bid = 8;
	sys->tk[TANK_08].xLevLL.wid = 12; sys->tk[TANK_08].xLevLL.bid = 7;
	
	sys->tk[TANK_08].xShutOpen.wid = 11; sys->tk[TANK_08].xShutOpen.bid = 10;
	sys->tk[TANK_08].xShutClose.wid = 11; sys->tk[TANK_08].xShutClose.bid = 9;
	
	
	//preheat1
	sys->tk[TANK_AUX_PH1].xTempH.wid = 13; sys->tk[TANK_AUX_PH1].xTempH.bid = 6;
	sys->tk[TANK_AUX_PH1].xTempL.wid = 13; sys->tk[TANK_AUX_PH1].xTempL.bid = 5;
	
	sys->tk[TANK_AUX_PH1].xLevHH.wid = 13; sys->tk[TANK_AUX_PH1].xLevHH.bid = 13;
	sys->tk[TANK_AUX_PH1].xLevH.wid = 13; sys->tk[TANK_AUX_PH1].xLevH.bid = 12;
	sys->tk[TANK_AUX_PH1].xLevL.wid = 13; sys->tk[TANK_AUX_PH1].xLevL.bid = 11;
	sys->tk[TANK_AUX_PH1].xLevLL.wid = 13; sys->tk[TANK_AUX_PH1].xLevLL.bid = 10;
	
	
	//preheat2
	sys->tk[TANK_AUX_PH2].xTempH.wid = 14; sys->tk[TANK_AUX_PH2].xTempH.bid = 3;
	sys->tk[TANK_AUX_PH2].xTempL.wid = 14; sys->tk[TANK_AUX_PH2].xTempL.bid = 2;
	
	sys->tk[TANK_AUX_PH2].xLevHH.wid = 14; sys->tk[TANK_AUX_PH2].xLevHH.bid = 10;
	sys->tk[TANK_AUX_PH2].xLevH.wid = 14; sys->tk[TANK_AUX_PH2].xLevH.bid = 9;
	sys->tk[TANK_AUX_PH2].xLevL.wid = 14; sys->tk[TANK_AUX_PH2].xLevL.bid = 8;
	sys->tk[TANK_AUX_PH2].xLevLL.wid = 14; sys->tk[TANK_AUX_PH2].xLevLL.bid = 7;
	
	
	//tank09
	sys->tk[TANK_09].xTempH.wid = 23; sys->tk[TANK_09].xTempH.bid = 8;
	sys->tk[TANK_09].xTempL.wid = 23; sys->tk[TANK_09].xTempL.bid = 7;
	
	sys->tk[TANK_09].xLevHH.wid = 23; sys->tk[TANK_09].xLevHH.bid = 15;
	sys->tk[TANK_09].xLevH.wid = 23; sys->tk[TANK_09].xLevH.bid = 14;
	//sys->tk[TANK_09].xLevL.wid = 23; sys->tk[TANK_09].xLevL.bid = 13;
	sys->tk[TANK_09].xLevLL.wid = 23; sys->tk[TANK_09].xLevLL.bid =12;
	
	//tank10
	sys->tk[TANK_10].xTempH.wid = 24; sys->tk[TANK_10].xTempH.bid = 5;
	sys->tk[TANK_10].xTempL.wid = 24; sys->tk[TANK_10].xTempL.bid = 4;
	
	sys->tk[TANK_10].xLevHH.wid = 24; sys->tk[TANK_10].xLevHH.bid = 12;
	sys->tk[TANK_10].xLevH.wid = 24; sys->tk[TANK_10].xLevH.bid = 11;
	//sys->tk[TANK_10].xLevL.wid = 24; sys->tk[TANK_10].xLevL.bid = 10;
	sys->tk[TANK_10].xLevLL.wid = 24; sys->tk[TANK_10].xLevLL.bid =9;
	
	//tank11
	sys->tk[TANK_11].xLevHH.wid = 25; sys->tk[TANK_11].xLevHH.bid = 5;
	sys->tk[TANK_11].xLevH.wid = 25; sys->tk[TANK_11].xLevH.bid = 4;
	sys->tk[TANK_11].xLevL.wid = 25; sys->tk[TANK_11].xLevL.bid = 3;
	sys->tk[TANK_11].xLevLL.wid = 25; sys->tk[TANK_11].xLevLL.bid =2;
	
	sys->tk[TANK_11].xShutOpen.wid = 24; sys->tk[TANK_11].xShutOpen.bid = 15;
	sys->tk[TANK_11].xShutClose.wid = 24; sys->tk[TANK_11].xShutClose.bid = 14;
	
	sys->tk[TANK_11].xMakeAc1LevL.wid = 25; sys->tk[TANK_11].xMakeAc1LevL.bid = 6;
	sys->tk[TANK_11].xMakeAc2LevL.wid = 25; sys->tk[TANK_11].xMakeAc2LevL.bid = 7; 
	
	sys->tk[TANK_11].xDosAc1LevH.wid = 25; sys->tk[TANK_11].xDosAc1LevH.bid = 9;
	sys->tk[TANK_11].xDosAc1LevL.wid = 25; sys->tk[TANK_11].xDosAc1LevL.bid = 10;
	sys->tk[TANK_11].xDosAc2LevH.wid = 25; sys->tk[TANK_11].xDosAc2LevH.bid = 11;
	sys->tk[TANK_11].xDosAc2LevL.wid = 25; sys->tk[TANK_11].xDosAc2LevL.bid = 12;

	
	//tank12
	sys->tk[TANK_12].xTempH.wid = 26; sys->tk[TANK_12].xTempH.bid = 4;
	sys->tk[TANK_12].xTempL.wid = 26; sys->tk[TANK_12].xTempL.bid = 3;
	
	sys->tk[TANK_12].xLevHH.wid = 26; sys->tk[TANK_12].xLevHH.bid = 11;
	sys->tk[TANK_12].xLevH.wid = 26; sys->tk[TANK_12].xLevH.bid = 10;
	//sys->tk[TANK_12].xLevL.wid = 26; sys->tk[TANK_12].xLevL.bid = 9;
	sys->tk[TANK_12].xLevLL.wid = 26; sys->tk[TANK_12].xLevLL.bid = 8;
	
	//tank13
	sys->tk[TANK_13].xTempH.wid = 27; sys->tk[TANK_13].xTempH.bid = 1;
	sys->tk[TANK_13].xTempL.wid = 27; sys->tk[TANK_13].xTempL.bid = 0;
	
	sys->tk[TANK_13].xLevHH.wid = 27; sys->tk[TANK_13].xLevHH.bid = 8;
	sys->tk[TANK_13].xLevH.wid = 27; sys->tk[TANK_13].xLevH.bid = 7;
	//sys->tk[TANK_13].xLevL.wid = 27; sys->tk[TANK_13].xLevL.bid = 6;
	sys->tk[TANK_13].xLevLL.wid = 27; sys->tk[TANK_13].xLevLL.bid = 5;
	
	//tank14
	sys->tk[TANK_14].xTempH.wid = 27; sys->tk[TANK_14].xTempH.bid = 15;
	sys->tk[TANK_14].xTempL.wid = 27; sys->tk[TANK_14].xTempL.bid = 14;
	
//	sys->tk[TANK_14].xShutOpen.wid = 27; sys->tk[TANK_14].xShutOpen.bid = 11;
//	sys->tk[TANK_14].xShutClose.wid = 27; sys->tk[TANK_14].xShutClose.bid = 10;
	
	sys->tk[TANK_14].xLevUP.wid = 28; sys->tk[TANK_14].xLevUP.bid = 3;
	sys->tk[TANK_14].xLevHH.wid = 28; sys->tk[TANK_14].xLevHH.bid = 7;
	sys->tk[TANK_14].xLevH.wid = 28; sys->tk[TANK_14].xLevH.bid = 6;
	sys->tk[TANK_14].xLevL.wid = 28; sys->tk[TANK_14].xLevL.bid = 5;
	sys->tk[TANK_14].xLevLL.wid = 28; sys->tk[TANK_14].xLevLL.bid = 4;
	
	//tank15
	sys->tk[TANK_15].xTempH.wid = 28; sys->tk[TANK_15].xTempH.bid = 14;
	sys->tk[TANK_15].xTempL.wid = 28; sys->tk[TANK_15].xTempL.bid = 13;
	
//	sys->tk[TANK_15].xShutOpen.wid = 28; sys->tk[TANK_15].xShutOpen.bid = 10;
//	sys->tk[TANK_15].xShutClose.wid = 28; sys->tk[TANK_15].xShutClose.bid = 9;
	
	sys->tk[TANK_15].xLevUP.wid = 29; sys->tk[TANK_15].xLevUP.bid = 2;
	sys->tk[TANK_15].xLevHH.wid = 29; sys->tk[TANK_15].xLevHH.bid = 6;
	sys->tk[TANK_15].xLevH.wid = 29; sys->tk[TANK_15].xLevH.bid = 5;
	sys->tk[TANK_15].xLevL.wid = 29; sys->tk[TANK_15].xLevL.bid = 4;
	sys->tk[TANK_15].xLevLL.wid = 29; sys->tk[TANK_15].xLevLL.bid = 3;
	
	//inline
	sys->tk[TANK_AUX_IN].xTempH.wid = 29; sys->tk[TANK_AUX_IN].xTempH.bid = 9;
	sys->tk[TANK_AUX_IN].xTempL.wid = 29; sys->tk[TANK_AUX_IN].xTempL.bid = 8;
	
	//tank16
	sys->tk[TANK_16].xTempH.wid = 30; sys->tk[TANK_16].xTempH.bid = 1;
	sys->tk[TANK_16].xTempL.wid = 30; sys->tk[TANK_16].xTempL.bid = 0;
	
	//unloader
	sys->tk[TANK_17].xTempH.wid = 30; sys->tk[TANK_17].xTempH.bid = 13;
	sys->tk[TANK_17].xTempL.wid = 30; sys->tk[TANK_17].xTempL.bid = 12;
	
	sys->tk[TANK_17].xPosA1.wid = 20; sys->tk[TANK_17].xPosA1.bid = 0;
	sys->tk[TANK_17].xPosB1.wid = 20; sys->tk[TANK_17].xPosB1.bid = 2;
	sys->tk[TANK_17].xPosA2.wid = 20; sys->tk[TANK_17].xPosA2.bid = 4;
	sys->tk[TANK_17].xPosB2.wid = 20; sys->tk[TANK_17].xPosB2.bid = 6;
	sys->tk[TANK_17].xPosA3.wid = 20; sys->tk[TANK_17].xPosA3.bid = 8;
	sys->tk[TANK_17].xPosB3.wid = 20; sys->tk[TANK_17].xPosB3.bid = 10;
	sys->tk[TANK_17].xPosA4.wid = 20; sys->tk[TANK_17].xPosA4.bid = 12;
	sys->tk[TANK_17].xPosB4.wid = 20; sys->tk[TANK_17].xPosB4.bid = 14;
	sys->tk[TANK_17].xPosA5.wid = 21; sys->tk[TANK_17].xPosA5.bid = 0;
	sys->tk[TANK_17].xPosB5.wid = 21; sys->tk[TANK_17].xPosB5.bid = 2;
	sys->tk[TANK_17].xPosA6.wid = 21; sys->tk[TANK_17].xPosA6.bid = 4;
	sys->tk[TANK_17].xPosB6.wid = 21; sys->tk[TANK_17].xPosB6.bid = 6;
	sys->tk[TANK_17].xShutOpen.wid = 22; sys->tk[TANK_17].xShutOpen.bid = 10;
	sys->tk[TANK_17].xShutClose.wid = 22; sys->tk[TANK_17].xShutClose.bid = 9;
	sys->tk[TANK_17].xDoorOpen.wid = 22; sys->tk[TANK_17].xDoorOpen.bid = 14;
	sys->tk[TANK_17].xDoorClose.wid = 22; sys->tk[TANK_17].xDoorClose.bid = 13;
	
	//HDIW
	sys->tk[TANK_AUX_DIW].xLevHH.wid = 31; sys->tk[TANK_AUX_DIW].xLevHH.bid = 11;
	sys->tk[TANK_AUX_DIW].xLevH.wid = 31; sys->tk[TANK_AUX_DIW].xLevH.bid = 10;
	//sys->tk[TANK_AUX_DIW].xLevL.wid = 29; sys->tk[TANK_AUX_DIW].xLevL.bid = 4;
	sys->tk[TANK_AUX_DIW].xLevLL.wid = 31; sys->tk[TANK_AUX_DIW].xLevLL.bid = 9;
	
	//TEX
	sys->tk[TANK_AUX_TEX].xLevHH.wid = 32; sys->tk[TANK_AUX_TEX].xLevHH.bid = 3;
	sys->tk[TANK_AUX_TEX].xLevH.wid = 33; sys->tk[TANK_AUX_TEX].xLevH.bid = 2;
	//sys->tk[TANK_AUX_TEX].xLevL.wid = 29; sys->tk[TANK_AUX_TEX].xLevL.bid = 4;
	sys->tk[TANK_AUX_TEX].xLevLL.wid = 32; sys->tk[TANK_AUX_TEX].xLevLL.bid = 1; 
	
	//HF
	sys->tk[TANK_AUX_HF].xLevHH.wid = 32; sys->tk[TANK_AUX_HF].xLevHH.bid = 11;
	sys->tk[TANK_AUX_HF].xLevH.wid = 32; sys->tk[TANK_AUX_HF].xLevH.bid = 10;
	//sys->tk[TANK_AUX_HF].xLevL.wid = 29; sys->tk[TANK_AUX_HF].xLevL.bid = 4;
	sys->tk[TANK_AUX_HF].xLevLL.wid = 32; sys->tk[TANK_AUX_HF].xLevLL.bid = 9;
	
	
	
	/////////////////////////////////////////////////////////////////////////////
	//OUTPUT
	///inline

	sys->tk[TANK_AUX_IN].yHeat.wid = 18; sys->tk[TANK_AUX_IN].yHeat.bid = 6;
	sys->tk[TANK_AUX_IN].yPump.wid = 17; sys->tk[TANK_AUX_IN].yPump.bid = 14;
	sys->tk[TANK_AUX_IN].yValveDiwIn.wid = 17; sys->tk[TANK_AUX_IN].yValveDiwIn.bid = 10; 
	sys->tk[TANK_AUX_IN].yValveDown.wid = 17; sys->tk[TANK_AUX_IN].yValveDown.bid = 12;
	
	///tank02
	sys->tk[TANK_02].yHeat.wid = 4; sys->tk[TANK_02].yHeat.bid = 8;
	sys->tk[TANK_02].yPump.wid = 4; sys->tk[TANK_02].yPump.bid = 3;
	
	sys->tk[TANK_02].yValveDiwIn.wid = 3; sys->tk[TANK_02].yValveDiwIn.bid = 13;
	sys->tk[TANK_02].yValveQDown.wid = 3; sys->tk[TANK_02].yValveQDown.bid = 8;
	sys->tk[TANK_02].yValveDown.wid = 3; sys->tk[TANK_02].yValveDown.bid = 8;
	
	sys->tk[TANK_02].yValveMakeAc1In.wid = 3; sys->tk[TANK_02].yValveMakeAc1In.bid = 11;
	sys->tk[TANK_02].yValveMakeAc2In.wid = 3; sys->tk[TANK_02].yValveMakeAc2In.bid = 10;
	sys->tk[TANK_02].yValveMakeAc3In.wid = 3; sys->tk[TANK_02].yValveMakeAc3In.bid = 9; 
	
	sys->tk[TANK_02].yValveDosAc1In.wid = 4; sys->tk[TANK_02].yValveDosAc1In.bid = 11;
	sys->tk[TANK_02].yValveDosAc1Out.wid = 4; sys->tk[TANK_02].yValveDosAc1Out.bid = 12;
	sys->tk[TANK_02].yValveDosAc2In.wid = 4; sys->tk[TANK_02].yValveDosAc2In.bid = 13;
	sys->tk[TANK_02].yValveDosAc2Out.wid = 4; sys->tk[TANK_02].yValveDosAc2Out.bid = 14;
	
	///tank03
	sys->tk[TANK_03].yHeat.wid = 5; sys->tk[TANK_03].yHeat.bid = 8;
	sys->tk[TANK_03].yValveDiwIn.wid = 5; sys->tk[TANK_03].yValveDiwIn.bid = 6; 
	sys->tk[TANK_03].yValveDown.wid = 5; sys->tk[TANK_03].yValveDown.bid = 5;

	
	///tank04
	sys->tk[TANK_04].yHeat.wid = 7; sys->tk[TANK_04].yHeat.bid = 14;
	sys->tk[TANK_04].yPump.wid = 7; sys->tk[TANK_04].yPump.bid = 1;
	
	sys->tk[TANK_04].yValveDiwIn.wid = 6; sys->tk[TANK_04].yValveDiwIn.bid = 11; 
	sys->tk[TANK_04].yValveQDown.wid = 6; sys->tk[TANK_04].yValveQDown.bid = 0;
	sys->tk[TANK_04].yValveDown.wid = 6; sys->tk[TANK_04].yValveDown.bid = 3;
	
	sys->tk[TANK_04].yPumpIn.wid = 6; sys->tk[TANK_04].yPumpIn.bid = 13;
	
	sys->tk[TANK_04].yValveMakeAc1In.wid = 6; sys->tk[TANK_04].yValveMakeAc1In.bid = 9;
	sys->tk[TANK_04].yValveMakeAc2In.wid = 6; sys->tk[TANK_04].yValveMakeAc2In.bid = 8;
	sys->tk[TANK_04].yValveMakeAc3In.wid = 6; sys->tk[TANK_04].yValveMakeAc3In.bid = 7;
	
	sys->tk[TANK_04].yValveDosAc1In.wid = 8; sys->tk[TANK_04].yValveDosAc1In.bid = 1;
	sys->tk[TANK_04].yValveDosAc1Out.wid = 8; sys->tk[TANK_04].yValveDosAc1Out.bid = 2;
	sys->tk[TANK_04].yValveDosAc2In.wid = 8; sys->tk[TANK_04].yValveDosAc2In.bid = 3;
	sys->tk[TANK_04].yValveDosAc2Out.wid = 8; sys->tk[TANK_04].yValveDosAc2Out.bid = 4;
	sys->tk[TANK_04].yValveDosAc3In.wid = 8; sys->tk[TANK_04].yValveDosAc3In.bid = 5;
	sys->tk[TANK_04].yValveDosAc3Out.wid = 8; sys->tk[TANK_04].yValveDosAc3Out.bid = 6;
	
	///tank05
	sys->tk[TANK_05].yPump.wid = 7; sys->tk[TANK_05].yPump.bid = 7; 
	sys->tk[TANK_05].yValveQDown.wid = 6; sys->tk[TANK_05].yValveQDown.bid = 1;
	
	///tank06
	sys->tk[TANK_06].yHeat.wid = 9; sys->tk[TANK_06].yHeat.bid = 3;
	sys->tk[TANK_06].yValveDiwIn.wid = 9; sys->tk[TANK_06].yValveDiwIn.bid = 1; 
	sys->tk[TANK_06].yValveDown.wid = 9; sys->tk[TANK_06].yValveDown.bid = 0;
	
	///tank07
	sys->tk[TANK_07].yHeat.wid = 11; sys->tk[TANK_07].yHeat.bid = 14;
	sys->tk[TANK_07].yPump.wid = 10; sys->tk[TANK_07].yPump.bid = 10;
	
	sys->tk[TANK_07].yValveDiwIn.wid = 10; sys->tk[TANK_07].yValveDiwIn.bid = 6; 
	sys->tk[TANK_07].yValveQDown.wid = 9; sys->tk[TANK_07].yValveQDown.bid = 11;
	sys->tk[TANK_07].yValveDown.wid = 9; sys->tk[TANK_07].yValveDown.bid = 14;
	
	sys->tk[TANK_07].yPumpIn.wid = 10; sys->tk[TANK_07].yPumpIn.bid = 8;
	
	sys->tk[TANK_07].yValveMakeAc1In.wid = 10; sys->tk[TANK_07].yValveMakeAc1In.bid = 4;
	sys->tk[TANK_07].yValveMakeAc2In.wid = 10; sys->tk[TANK_07].yValveMakeAc2In.bid = 3;
	sys->tk[TANK_07].yValveMakeAc3In.wid = 10; sys->tk[TANK_07].yValveMakeAc3In.bid = 2;
	
	sys->tk[TANK_07].yValveDosAc1In.wid = 11; sys->tk[TANK_07].yValveDosAc1In.bid = 7;
	sys->tk[TANK_07].yValveDosAc1Out.wid = 11; sys->tk[TANK_07].yValveDosAc1Out.bid = 8;
	sys->tk[TANK_07].yValveDosAc2In.wid = 11; sys->tk[TANK_07].yValveDosAc2In.bid = 9;
	sys->tk[TANK_07].yValveDosAc2Out.wid = 11; sys->tk[TANK_07].yValveDosAc2Out.bid = 10;
	sys->tk[TANK_07].yValveDosAc3In.wid = 11; sys->tk[TANK_07].yValveDosAc3In.bid = 11;
	sys->tk[TANK_07].yValveDosAc3Out.wid = 11; sys->tk[TANK_07].yValveDosAc3Out.bid = 12;
	
	///tank08
	sys->tk[TANK_08].yPump.wid = 11; sys->tk[TANK_08].yPump.bid = 0;
	sys->tk[TANK_08].yValveQDown.wid = 9; sys->tk[TANK_08].yValveQDown.bid = 12;
	
	///preheat1
	sys->tk[TANK_AUX_PH1].yHeat.wid = 12; sys->tk[TANK_AUX_PH1].yHeat.bid = 6;
	sys->tk[TANK_AUX_PH1].yPump.wid = 12; sys->tk[TANK_AUX_PH1].yPump.bid = 5;
	
	///preheat1
	sys->tk[TANK_AUX_PH2].yHeat.wid = 12; sys->tk[TANK_AUX_PH2].yHeat.bid = 14;
	sys->tk[TANK_AUX_PH2].yPump.wid = 12; sys->tk[TANK_AUX_PH2].yPump.bid = 13;
	

	///tank09
	sys->tk[TANK_09].yHeat.wid = 18; sys->tk[TANK_09].yHeat.bid = 9;
	sys->tk[TANK_09].yValveDiwIn.wid = 18; sys->tk[TANK_09].yValveDiwIn.bid = 7; 
	sys->tk[TANK_09].yValveDown.wid = 18; sys->tk[TANK_09].yValveDown.bid = 6;
	
	///tank10
	sys->tk[TANK_10].yHeat.wid = 19; sys->tk[TANK_10].yHeat.bid = 2;
	sys->tk[TANK_10].yValveDiwIn.wid = 19; sys->tk[TANK_10].yValveDiwIn.bid = 0; 
	sys->tk[TANK_10].yValveDown.wid = 18; sys->tk[TANK_10].yValveDown.bid = 15;
	
	///tank11
	sys->tk[TANK_11].yValveDiwIn.wid = 19; sys->tk[TANK_11].yValveDiwIn.bid = 10; 
	sys->tk[TANK_11].yValveDown.wid = 19; sys->tk[TANK_11].yValveDown.bid = 8;
	sys->tk[TANK_11].yPump.wid = 20; sys->tk[TANK_11].yPump.bid = 4;
	
	sys->tk[TANK_11].yValveDosAc1In.wid = 20; sys->tk[TANK_11].yValveDosAc1In.bid = 0;
	sys->tk[TANK_11].yValveDosAc1Out.wid = 20; sys->tk[TANK_11].yValveDosAc1Out.bid = 1;
	sys->tk[TANK_11].yValveDosAc2In.wid = 19; sys->tk[TANK_11].yValveDosAc2In.bid = 14;
	sys->tk[TANK_11].yValveDosAc2Out.wid = 19; sys->tk[TANK_11].yValveDosAc2Out.bid = 15;
	
	///tank12
	sys->tk[TANK_12].yHeat.wid = 20; sys->tk[TANK_12].yHeat.bid = 11;
	sys->tk[TANK_12].yValveDiwIn.wid = 20; sys->tk[TANK_12].yValveDiwIn.bid = 9; 
	sys->tk[TANK_12].yValveDown.wid = 20; sys->tk[TANK_12].yValveDown.bid = 8;
	
	///tank13
	sys->tk[TANK_13].yHeat.wid = 21; sys->tk[TANK_13].yHeat.bid = 4;
	sys->tk[TANK_13].yValveDiwIn.wid = 21; sys->tk[TANK_13].yValveDiwIn.bid = 2; 
	sys->tk[TANK_13].yValveDown.wid = 21; sys->tk[TANK_13].yValveDown.bid = 1;
	
	///tank14
	sys->tk[TANK_14].yHeat.wid = 21; sys->tk[TANK_14].yHeat.bid = 13;
	sys->tk[TANK_14].yValveDiwIn.wid = 21; sys->tk[TANK_14].yValveDiwIn.bid = 11; 
	sys->tk[TANK_14].yValveQDown.wid = 21; sys->tk[TANK_14].yValveQDown.bid = 9;
	sys->tk[TANK_14].yValveDown.wid = 21; sys->tk[TANK_14].yValveDown.bid = 10;
	sys->tk[TANK_14].yPump.wid = 22; sys->tk[TANK_14].yPump.bid = 0;
	
	///tank15
	sys->tk[TANK_15].yHeat.wid = 22; sys->tk[TANK_15].yHeat.bid = 12;
	sys->tk[TANK_15].yValveDiwIn.wid = 22; sys->tk[TANK_15].yValveDiwIn.bid = 10; 
	sys->tk[TANK_15].yValveQDown.wid = 22; sys->tk[TANK_15].yValveQDown.bid = 11;
	sys->tk[TANK_15].yValveDown.wid = 22; sys->tk[TANK_15].yValveDown.bid = 9;
	sys->tk[TANK_15].yPump.wid = 23; sys->tk[TANK_15].yPump.bid = 1;
	
	///tank16
	sys->tk[TANK_16].yHeat.wid = 23; sys->tk[TANK_16].yHeat.bid = 8;
	
	///tank17
	sys->tk[TANK_17].yHeat.wid = 23; sys->tk[TANK_17].yHeat.bid = 15;
	sys->tk[TANK_17].yPump.wid = 24; sys->tk[TANK_17].yPump.bid = 1; 
	
	sys->tk[TANK_AUX_DIW].yPump.wid = 24; sys->tk[TANK_AUX_DIW].yPump.bid = 10;
	sys->tk[TANK_AUX_TEX].yPump.wid = 24; sys->tk[TANK_AUX_TEX].yPump.bid = 14;
	sys->tk[TANK_AUX_HF].yPump.wid = 25; sys->tk[TANK_AUX_HF].yPump.bid = 2;
	
	///////////////////////////////////////////
	//UI data
	sys->tk[TANK_01].uiCARNum = PANEL_COUNT_01;
	sys->tk[TANK_02].uiCARNum = PANEL_COUNT_02; 
	sys->tk[TANK_03].uiCARNum = PANEL_COUNT_03; 
	sys->tk[TANK_04].uiCARNum = PANEL_COUNT_04; 
	sys->tk[TANK_05].uiCARNum = PANEL_COUNT_05;
	sys->tk[TANK_06].uiCARNum = PANEL_COUNT_06;
	sys->tk[TANK_07].uiCARNum = PANEL_COUNT_07;
	sys->tk[TANK_08].uiCARNum = PANEL_COUNT_08;
	sys->tk[TANK_09].uiCARNum = PANEL_COUNT_09;
	sys->tk[TANK_10].uiCARNum = PANEL_COUNT_10;
	sys->tk[TANK_11].uiCARNum = PANEL_COUNT_11;
	sys->tk[TANK_12].uiCARNum = PANEL_COUNT_12;
	sys->tk[TANK_13].uiCARNum = PANEL_COUNT_13;
	sys->tk[TANK_14].uiCARNum = PANEL_COUNT_14;
	sys->tk[TANK_15].uiCARNum = PANEL_COUNT_15;
	sys->tk[TANK_16].uiCARNum = PANEL_COUNT_16;
	sys->tk[TANK_17].uiCARNum = PANEL_COUNT_17; 

	
	sys->tk[TANK_01].uiTANK = PANEL_TNK_01;
	sys->tk[TANK_02].uiTANK = PANEL_TNK_02; 
	sys->tk[TANK_03].uiTANK = PANEL_TNK_03; 
	sys->tk[TANK_04].uiTANK = PANEL_TNK_04; 
	sys->tk[TANK_05].uiTANK = PANEL_TNK_05;
	sys->tk[TANK_06].uiTANK = PANEL_TNK_06;
	sys->tk[TANK_07].uiTANK = PANEL_TNK_07;
	sys->tk[TANK_08].uiTANK = PANEL_TNK_08;
	sys->tk[TANK_09].uiTANK = PANEL_TNK_09;
	sys->tk[TANK_10].uiTANK = PANEL_TNK_10;
	sys->tk[TANK_11].uiTANK = PANEL_TNK_11;
	sys->tk[TANK_12].uiTANK = PANEL_TNK_12;
	sys->tk[TANK_13].uiTANK = PANEL_TNK_13;
	sys->tk[TANK_14].uiTANK = PANEL_TNK_14; 
	sys->tk[TANK_15].uiTANK = PANEL_TNK_15;
	sys->tk[TANK_16].uiTANK = PANEL_TNK_16;
	sys->tk[TANK_17].uiTANK = PANEL_TNK_17;
	sys->tk[TANK_AUX_PH1].uiTANK = PANEL_TNK_PH1;
	sys->tk[TANK_AUX_PH2].uiTANK = PANEL_TNK_PH2;
	sys->tk[TANK_AUX_IN].uiTANK = PANEL_TNK_INLINE;
	sys->tk[TANK_AUX_DIW].uiTANK = PANEL_TNK_DIW;
	sys->tk[TANK_AUX_TEX].uiTANK = PANEL_TNK_TEX;
	sys->tk[TANK_AUX_HF].uiTANK = PANEL_TNK_HF;
	
	
	sys->tk[TANK_01].uiProcTM = PANEL_PRCTM_01;
	sys->tk[TANK_02].uiProcTM = PANEL_PRCTM_02; 
	sys->tk[TANK_03].uiProcTM = PANEL_PRCTM_03; 
	sys->tk[TANK_04].uiProcTM = PANEL_PRCTM_04; 
	sys->tk[TANK_05].uiProcTM = PANEL_PRCTM_05;
	sys->tk[TANK_06].uiProcTM = PANEL_PRCTM_06;
	sys->tk[TANK_07].uiProcTM = PANEL_PRCTM_07;
	sys->tk[TANK_08].uiProcTM = PANEL_PRCTM_08;
	sys->tk[TANK_09].uiProcTM = PANEL_PRCTM_09;
	sys->tk[TANK_10].uiProcTM = PANEL_PRCTM_10;
	sys->tk[TANK_11].uiProcTM = PANEL_PRCTM_11;
	sys->tk[TANK_12].uiProcTM = PANEL_PRCTM_12;
	sys->tk[TANK_13].uiProcTM = PANEL_PRCTM_13;
	sys->tk[TANK_14].uiProcTM = PANEL_PRCTM_14;	
	sys->tk[TANK_15].uiProcTM = PANEL_PRCTM_15;
	sys->tk[TANK_16].uiProcTM = PANEL_PRCTM_16;
	
	sys->tk[TANK_01].uiShut = PANEL_SHUT_01;
	sys->tk[TANK_02].uiShut = PANEL_SHUT_02; 
	//sys->tk[TANK_03].uiShut = PANEL_SHUT_03; 
	sys->tk[TANK_04].uiShut = PANEL_SHUT_04; 
	sys->tk[TANK_05].uiShut = PANEL_SHUT_05;
	//sys->tk[TANK_06].uiShut = PANEL_SHUT_06;
	sys->tk[TANK_07].uiShut = PANEL_SHUT_07;
	sys->tk[TANK_08].uiShut = PANEL_SHUT_08;
	//sys->tk[TANK_09].uiShut = PANEL_SHUT_09;
	//sys->tk[TANK_10].uiShut = PANEL_SHUT_10;
	sys->tk[TANK_11].uiShut = PANEL_SHUT_11;
	//sys->tk[TANK_12].uiShut = PANEL_SHUT_12;
	//sys->tk[TANK_13].uiShut = PANEL_SHUT_13;
	sys->tk[TANK_14].uiShut = PANEL_SHUT_14;
	sys->tk[TANK_15].uiShut = PANEL_SHUT_15;
	sys->tk[TANK_17].uiShut = PANEL_SHUT_17;
	
	
 /*
	sys->tk[TANK_02].uiPump = PANEL_PUMP_02; 
	//sys->tk[TANK_03].uiPump = PANEL_PUMP_03; 
	sys->tk[TANK_04].uiPump = PANEL_PUMP_04; 
	sys->tk[TANK_04].uiPumpIn = PANEL_PUMP_TEXA;
	sys->tk[TANK_05].uiPump = PANEL_PUMP_05;
	//sys->tk[TANK_06].uiPump = PANEL_PUMP_06;
	sys->tk[TANK_07].uiPump = PANEL_PUMP_07;
	sys->tk[TANK_07].uiPumpIn = PANEL_PUMP_TEXB; 
	sys->tk[TANK_08].uiPump = PANEL_PUMP_08;
	//sys->tk[TANK_09].uiPump = PANEL_PUMP_09;
	//sys->tk[TANK_10].uiPump = PANEL_PUMP_10;
	//sys->tk[TANK_11].uiPump = PANEL_PUMP_11;
	//sys->tk[TANK_12].uiPump = PANEL_PUMP_12;
	//sys->tk[TANK_13].uiPump = PANEL_PUMP_13;
	sys->tk[TANK_14].uiPump = PANEL_PUMP_14;
	sys->tk[TANK_15].uiPump = PANEL_PUMP_15;
	sys->tk[TANK_16].uiPump = PANEL_PUMP_16;
	sys->tk[TANK_17].uiPump = PANEL_PUMP_17;
	sys->tk[TANK_AUX_IN].uiPump = PANEL_PUMP_INLINE;
	sys->tk[TANK_AUX_PH1].uiPump = PANEL_PUMP_PH1;
	sys->tk[TANK_AUX_PH2].uiPump = PANEL_PUMP_PH2;
//	sys->tk[TANK_AUX_DIW].uiPump = PANEL_PUMP_DIW;
//	sys->tk[TANK_AUX_HF].uiPump = PANEL_PUMP_HF;
//	sys->tk[TANK_AUX_TEX].uiPump = PANEL_PUMP_TEX;
*/	
	sys->tk[TANK_02].uiHeat = PANEL_HEATER_02; 
	sys->tk[TANK_03].uiHeat = PANEL_HEATER_03; 
	sys->tk[TANK_04].uiHeat = PANEL_HEATER_04; 
	//sys->tk[TANK_05].uiHeat = PANEL_HEATER_05;
	sys->tk[TANK_06].uiHeat = PANEL_HEATER_06;
	sys->tk[TANK_07].uiHeat = PANEL_HEATER_07;
	//sys->tk[TANK_08].uiHeat = PANEL_HEATER_08;
	sys->tk[TANK_09].uiHeat = PANEL_HEATER_09;
	sys->tk[TANK_10].uiHeat = PANEL_HEATER_10;
	//sys->tk[TANK_11].uiHeat = PANEL_HEATER_11;
	sys->tk[TANK_12].uiHeat = PANEL_HEATER_12;
	sys->tk[TANK_13].uiHeat = PANEL_HEATER_13;
	sys->tk[TANK_14].uiHeat = PANEL_HEATER_14;
	sys->tk[TANK_15].uiHeat = PANEL_HEATER_15;
	sys->tk[TANK_16].uiHeat = PANEL_HEATER_16;
	sys->tk[TANK_17].uiHeat = PANEL_HEATER_17;
	sys->tk[TANK_AUX_IN].uiHeat = PANEL_HEATER_INLINE;
	sys->tk[TANK_AUX_PH1].uiHeat = PANEL_HEATER_PH1;
	sys->tk[TANK_AUX_PH2].uiHeat = PANEL_HEATER_PH2;  
	
/*	sys->tk[TANK_03].uiBubble01 = PANEL_BUBBLE03_1;
	sys->tk[TANK_03].uiBubble02 = PANEL_BUBBLE03_2;
	sys->tk[TANK_03].uiBubble03 = PANEL_BUBBLE03_3;
	
	sys->tk[TANK_05].uiBubble01 = PANEL_BUBBLE05_1;
	sys->tk[TANK_05].uiBubble02 = PANEL_BUBBLE05_2;
	sys->tk[TANK_05].uiBubble03 = PANEL_BUBBLE05_3;
	
	sys->tk[TANK_06].uiBubble01 = PANEL_BUBBLE06_1;
	sys->tk[TANK_06].uiBubble02 = PANEL_BUBBLE06_2;
	sys->tk[TANK_06].uiBubble03 = PANEL_BUBBLE06_3;
	
	sys->tk[TANK_07].uiBubble01 = PANEL_BUBBLE07_1;
	sys->tk[TANK_07].uiBubble02 = PANEL_BUBBLE07_2;
	sys->tk[TANK_07].uiBubble03 = PANEL_BUBBLE07_3;
	
	sys->tk[TANK_08].uiBubble01 = PANEL_BUBBLE08_1;
	sys->tk[TANK_08].uiBubble02 = PANEL_BUBBLE08_2;
	sys->tk[TANK_08].uiBubble03 = PANEL_BUBBLE08_3; */
	////////////////////////////////////////////////////////////
	//other

	
/*	sys->tk[TANK_05].cmdAfterPut.tid = TANK_04;
	sys->tk[TANK_05].cmdAfterPut.type = MOVE_COMMAND;
	
	sys->tk[TANK_08].cmdAfterPut.tid = TANK_06;
	sys->tk[TANK_08].cmdAfterPut.type = MOVE_COMMAND;
	
	sys->tk[TANK_11].cmdAfterPut.tid = TANK_09;
	sys->tk[TANK_11].cmdAfterPut.type = MOVE_COMMAND;
	sys->tk[TANK_12].cmdAfterPut.tid = TANK_09;
	sys->tk[TANK_12].cmdAfterPut.type = MOVE_COMMAND;
	sys->tk[TANK_13].cmdAfterPut.tid = TANK_09;
	sys->tk[TANK_13].cmdAfterPut.type = MOVE_COMMAND;	
	
	sys->tk[TANK_03].putClean = 1;
	sys->tk[TANK_05].putClean = 1;
	sys->tk[TANK_04].putDirty = 1;
	sys->tk[TANK_08].getDirty = 1;  */
	

}
void initTankData(void)
{

	configTankData();
}

void configSystem(void)
{
	sys->hsWDT.wid = 0; sys->hsWDT.bid = 0;
	sys->hsAlarm.wid = 0; sys->hsAlarm.bid = 1;
	sys->hsAuto.wid = 0; sys->hsAuto.bid = 2;
	sys->hsManu.wid = 0; sys->hsManu.bid = 3;
	sys->hsEMGROBOT.wid = 0; sys->hsEMGROBOT.bid = 4;
	sys->hsEMGALL.wid = 0; sys->hsEMGALL.bid = 5;
	sys->hsRcpChange.wid = 0; sys->hsRcpChange.bid = 6;
	sys->hsAlarmBuzzOff.wid = 0; sys->hsAlarmBuzzOff.bid = 15;
	
	sys->hsChuckCheck.wid = 1;sys->hsChuckCheck.bid = 9;
	sys->hsDoorCheck.wid = 1;sys->hsDoorCheck.bid = 10;
	sys->hsExhaustCheck.wid = 1;sys->hsExhaustCheck.bid = 11;
	sys->hsEMOContine.wid = 1; sys->hsEMOContine.bid = 12;
	sys->hsBuzzCmd.wid = 1; sys->hsBuzzCmd.bid = 13;
	
	sys->hsIPABufferMode.wid = 11;sys->hsIPABufferMode.bid = 15;
	//sys->hsFillChange.wid = 1; sys->hsFillChange.bid = 12; 
	
	sys->hsLight1.wid = 23; sys->hsLight1.bid = 0; 
	sys->hsLight2.wid = 23; sys->hsLight2.bid = 1;
	sys->hsLight3.wid = 23; sys->hsLight3.bid = 2;
	sys->hsLight4.wid = 23; sys->hsLight4.bid = 3;
}

void InitAlarm(void)
{
	char projectDir[MAX_PATHNAME_LEN];
    char fullPath[MAX_PATHNAME_LEN];
	memset(fullPath, 0,  MAX_PATHNAME_LEN);

    if (GetProjectDir (projectDir) < 0)
        return;
    else
        MakePathname (projectDir, "alarmlist.csv", fullPath);// where fullPath has the following format: c:\myproject\myfile.dat

    int hfile;
    char lineBuffer[512];
	
	hfile = OpenFile(fullPath,VAL_READ_ONLY,VAL_OPEN_AS_IS,VAL_ASCII);
    if(hfile < 0)
        return;
	int i = 0;
	while(i < MAX_ALARM_NUM && ReadLine (hfile, lineBuffer, 510) >= 0)
	{
		if(strcmp(lineBuffer,"") == 0)
		{
			sys->alarmDesc[i] = malloc(strlen("spare") + 1);
			if(sys->alarmDesc[i] != NULL) 
				strcpy(sys->alarmDesc[i], "Spare");
		}
		else
		{
			sys->alarmDesc[i] = malloc(strlen(lineBuffer) + 1);
			if(sys->alarmDesc[i] != NULL) 
				strcpy(sys->alarmDesc[i], lineBuffer); 
		}
		
		i++;
	}
	CloseFile(hfile);
	
}

void SaveSystem(void)
{
	char FileName[256];
	char Path[MAX_PATHNAME_LEN ];
	
	GetDir(Path);
	Fmt(FileName,"%s<%s\\system.dat",Path);
	int fSAVE = OpenFile (FileName, VAL_WRITE_ONLY, VAL_TRUNCATE, VAL_BINARY);
	if(fSAVE > 0)
	{
		WriteFile(fSAVE,(char*)sys,sizeof(SYSTEM));
		CloseFile (	fSAVE );
	}
}

void RestoreSystem(void)
{
	char FileName[256];
	char Path[MAX_PATHNAME_LEN ];
	
	GetDir(Path);
	Fmt(FileName,"%s<%s\\system.dat",Path);
	int fSAVE = OpenFile (FileName, VAL_READ_ONLY, VAL_TRUNCATE, VAL_BINARY);
	if(fSAVE > 0)
	{
		SYSTEM s;
		ReadFile(fSAVE,(char*)&s,sizeof(SYSTEM));
		CloseFile (	fSAVE );
		
		memcpy(&sys->set,&s.set, sizeof(SETTING));
		
		sys->rcp.ID = s.rcp.ID;
		for(int i = 0; i < ROBOT_NUM; i++)
			sys->rb[i].car = s.rb[i].car;
		
		for(int i = 0; i < RTANK_NUM; i++)
			sys->rtk[i].car = s.rtk[i].car;
		
		for(int i = 0; i < PRO_TANK_NUM; i++)
		{
			sys->tk[i].carNumber = s.tk[i].carNumber;
			sys->tk[i].rcp.ProcTM = s.tk[i].rcp.ProcTM; 
			sys->tk[i].rcp.PreGetTM = s.tk[i].rcp.PreGetTM;
			
			sys->tk[i].runAC1Dos = s.tk[i].runAC1Dos;
			sys->tk[i].runAC2Dos = s.tk[i].runAC2Dos;
			sys->tk[i].runAC3Dos = s.tk[i].runAC3Dos;
			sys->tk[i].runAC4Dos = s.tk[i].runAC4Dos;
			
			sys->tk[i].lifeRun = s.tk[i].lifeRun;
			sys->tk[i].lifeTime = s.tk[i].lifeTime;
			sys->tk[i].autoMakeStep = s.tk[i].autoMakeStep;
			
		}
	}
	else
	{
		for(int i = 0; i < PRO_TANK_NUM; i++)
		{
			GetCurrentDateTime ( &sys->tk[i].lifeTime);
			sys->tk[i].lifeTime += 60 * 6000;
			sys->tk[i].lifeRun = 100;
			sys->tk[i].autoMakeStep = 0; 
		}
	}
	
	sys->set.auth[4][0] = OP_RCP;
	sys->set.auth[4][1] = OP_TANK;
	sys->set.auth[4][2] = OP_ROBOT;
	sys->set.auth[4][3] = OP_SET;
	sys->set.auth[4][4] = OP_EXIT;
	sys->set.auth[4][5] = OP_USER;
}

int initSystem(void)
{
	 
	
	sys = (SYSTEM*)malloc(sizeof(SYSTEM));
	memset(sys,0,sizeof(SYSTEM));
	RestoreSystem();
	
	initRTankData();
	initRobotData();
	initTankData();
	
#ifdef SIMULATE	
	LoadPositionData();
#endif
	
	configSystem();

	InitAlarm();
	InitLog();
	
//	strcpy(sys->user.name,"test");
//	sys->user.type = SUP_USER;//UNKNOW_USER_TYPE;
	
    return 1;
}

void unInitSystem(void)
{
	SaveSystem();
	
	for(int i = 0; i < ROBOT_NUM; i++)
	{
		ListDispose(sys->rb[i].rtkPriList);	
		ListDispose(sys->rb[i].cmdList);
	}
	
	for(int j = 0; j < RTANK_NUM; j++)
	{
		CmtDiscardLock (sys->rtk[j].collisionLock);
	}

	
	for(int i = 0; i < MAX_ALARM_NUM; i++)
	{
		if(sys->alarmDesc[i] != NULL)
			free(sys->alarmDesc[i]);

	}
	
	UninitLog();
	
	free(sys);
}
