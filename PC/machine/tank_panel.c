#include <userint.h>

//==============================================================================
//
// Title:       tank_panel.c
// Purpose:     A short description of the implementation.
//
// Created on:  2014/7/24 at 下午 04:12:52 by wang fang.
// Copyright:   hua. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files

//#include "tank_panel.h"
#include "robot_panel.h"
#include "type.h"

//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// Static global variables
static TANK_ID	curTankId;
static RTANK_ID	curRTankId1 = RTK_UNKNOW;
static RTANK_ID	curRTankId2 = RTK_UNKNOW;
static int  preTempTrendPos; 
//==============================================================================
// Static functions

//==============================================================================
// Global variables
extern int g_setupMake;
extern BIT g_makeBit;
extern BIT	g_dosingBit;
extern int g_setupMMake;
extern BIT g_mmakeBit;
//==============================================================================
// Global functions		 

void initTankPanel(int panel,TANK_ID tid,RTANK_ID rid1,RTANK_ID rid2)
{
	curTankId = tid;
	curRTankId1 = rid1;
	curRTankId2 = rid2;
	SetPanelAttribute(panel,ATTR_TITLE, sys->tk[tid].name);

	
	//heater
	int v = (sys->tk[tid].hsHeat.wid == 0 && sys->tk[tid].hsHeat.wid == 0)?0:1;
	SetCtrlAttribute(panel,PANEL_TANK_TEMP, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_HEATER, ATTR_VISIBLE, v);

	//valve
	v = (tid > TANK_15 || (sys->tk[tid].hsDown.wid == 0 && sys->tk[tid].hsDown.wid == 0))?0:1;
	SetCtrlAttribute(panel,PANEL_TANK_VALVE_DIW_IN, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_VALVE_DOWN, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_SPLITTER_9, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_SPLITTER_10, ATTR_VISIBLE, v);
	
	//dosing and make
	v = (sys->tk[tid].hsMake.wid == 0 && sys->tk[tid].hsMake.wid == 0)?0:1;
	SetCtrlAttribute(panel,PANEL_TANK_VALVE_MAKE_AC1_IN, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_VALVE_MAKE_AC2_IN, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_VALVE_MAKE_AC3_IN, ATTR_VISIBLE, v);
	
	if(tid == TANK_04 || tid == TANK_07)
		SetCtrlAttribute(panel,PANEL_TANK_VALVE_MAKE_AC4_IN, ATTR_VISIBLE, v);

	SetCtrlAttribute(panel,PANEL_TANK_VALVE_DOS_AC1_IN, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_AC1_DOS_BUF, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_VALVE_DOS_AC1_OUT, ATTR_VISIBLE, v);
	
	SetCtrlAttribute(panel,PANEL_TANK_VALVE_DOS_AC2_IN, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_AC2_DOS_BUF, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_VALVE_DOS_AC2_OUT, ATTR_VISIBLE, v);
	
	SetCtrlAttribute(panel,PANEL_TANK_VALVE_DOS_AC3_IN, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_AC3_DOS_BUF, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_VALVE_DOS_AC3_OUT, ATTR_VISIBLE, v);
	
	if(tid == TANK_04 || tid == TANK_07)
	{
		SetCtrlAttribute(panel,PANEL_TANK_VALVE_DOS_AC4_IN, ATTR_VISIBLE, v);
		SetCtrlAttribute(panel,PANEL_TANK_AC4_DOS_BUF, ATTR_VISIBLE, v);
		SetCtrlAttribute(panel,PANEL_TANK_VALVE_DOS_AC4_OUT, ATTR_VISIBLE, v);
		SetCtrlAttribute(panel,PANEL_TANK_SPLITTER_4, ATTR_VISIBLE, v); 
		SetCtrlAttribute(panel,PANEL_TANK_SPLITTER_8, ATTR_VISIBLE, v);
		SetCtrlAttribute(panel,PANEL_TANK_SPLITTER_14, ATTR_VISIBLE, v);
	}
	
	SetCtrlAttribute(panel,PANEL_TANK_SPLITTER, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_SPLITTER_2, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_SPLITTER_3, ATTR_VISIBLE, v);
	
	SetCtrlAttribute(panel,PANEL_TANK_SPLITTER_5, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_SPLITTER_6, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_SPLITTER_7, ATTR_VISIBLE, v);
	
	
	SetCtrlAttribute(panel,PANEL_TANK_SPLITTER_11, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_SPLITTER_12, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_SPLITTER_13, ATTR_VISIBLE, v);
	
	
	SetCtrlAttribute(panel,PANEL_TANK_AC1_MAKE, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_AC2_MAKE, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_AC3_MAKE, ATTR_VISIBLE, v);
	
	if(tid == TANK_04 || tid == TANK_07)
		SetCtrlAttribute(panel,PANEL_TANK_AC4_MAKE, ATTR_VISIBLE, v);
	
	SetCtrlAttribute(panel,PANEL_TANK_MMAKE_OFF, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_MMAKE_ON, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_MMAKE_LAB, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_AMAKE_OFF, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_AMAKE_ON, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_AMAKE_LAB, ATTR_VISIBLE, v);
	
	SetCtrlAttribute(panel,PANEL_TANK_AC1_DOS_OFF, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_AC1_DOS_ON, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_AC2_DOS_OFF, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_AC2_DOS_ON, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_AC3_DOS_OFF, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_AC3_DOS_ON, ATTR_VISIBLE, v);
	
	if(tid == TANK_04 || tid == TANK_07)
	{
	SetCtrlAttribute(panel,PANEL_TANK_AC4_DOS_OFF, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_AC4_DOS_ON, ATTR_VISIBLE, v);
	}
	
	SetCtrlAttribute(panel,PANEL_TANK_AC1_DOS_LAB, ATTR_VISIBLE, v);   
	SetCtrlAttribute(panel,PANEL_TANK_AC2_DOS_LAB, ATTR_VISIBLE, v); 
	SetCtrlAttribute(panel,PANEL_TANK_AC3_DOS_LAB, ATTR_VISIBLE, v); 
	
	if(tid == TANK_04 || tid == TANK_07)
		SetCtrlAttribute(panel,PANEL_TANK_AC4_DOS_LAB, ATTR_VISIBLE, v);
	
	SetCtrlAttribute(panel,PANEL_TANK_DECORATION_MAKE, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_DECORATION_DOS, ATTR_VISIBLE, v);
	
	SetCtrlAttribute(panel,PANEL_TANK_MAKE_CH1, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_MAKE_CH2, ATTR_VISIBLE, v); 
	SetCtrlAttribute(panel,PANEL_TANK_MAKE_CH3, ATTR_VISIBLE, v);
	
	SetCtrlAttribute(panel,PANEL_TANK_MMAKE_CH1, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_MMAKE_CH2, ATTR_VISIBLE, v); 
	SetCtrlAttribute(panel,PANEL_TANK_MMAKE_CH3, ATTR_VISIBLE, v);
	
	if(tid == TANK_04 || tid == TANK_07)
	{
		SetCtrlAttribute(panel,PANEL_TANK_MAKE_CH4, ATTR_VISIBLE, v);
		SetCtrlAttribute(panel,PANEL_TANK_MMAKE_CH4, ATTR_VISIBLE, v);
	}
	
	SetCtrlAttribute(panel,PANEL_TANK_DOS_CH1, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_DOS_CH2, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_DOS_CH3, ATTR_VISIBLE, v);
	
	if(tid == TANK_04 || tid == TANK_07)
		SetCtrlAttribute(panel,PANEL_TANK_DOS_CH4, ATTR_VISIBLE, v);
	
	//SetCtrlAttribute(panel,PANEL_TANK_FLOW, ATTR_VISIBLE, v);
	
	//wash
	v = (sys->tk[tid].hsWash.wid == 0 && sys->tk[tid].hsWash.wid == 0)?0:1;
	SetCtrlAttribute(panel,PANEL_TANK_WASH_OFF, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_WASH_ON, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_WASH_LAB, ATTR_VISIBLE, v);
	
	//down
	v = (sys->tk[tid].hsDown.wid == 0 && sys->tk[tid].hsDown.wid == 0)?0:1;
	SetCtrlAttribute(panel,PANEL_TANK_DOWN_OFF, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_DOWN_ON, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_DOWN_LAB, ATTR_VISIBLE, v);
	
	//PUMP
	v = (sys->tk[tid].hsPump.wid == 0 && sys->tk[tid].hsPump.wid == 0)?0:1;
	SetCtrlAttribute(panel,PANEL_TANK_PUMP_OFF, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_PUMP_ON, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_PUMP_LAB, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_PUMP, ATTR_VISIBLE, v);
	
	if(tid == TANK_AUX_DIW || tid == TANK_AUX_TEX || tid == TANK_AUX_HF)
		SetCtrlAttribute(panel,PANEL_TANK_PUMP, ATTR_VISIBLE, 1);
	
	//inlne PUMP
	v = (sys->tk[tid].hsPumpIn.wid == 0 && sys->tk[tid].hsPumpIn.wid == 0)?0:1;
	SetCtrlAttribute(panel,PANEL_TANK_PUMPIN_OFF, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_PUMPIN_ON, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_PUMPIN_LAB, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_PUMPIN, ATTR_VISIBLE, v);
	
	
	//HEAT
	v = (sys->tk[tid].hsHeat.wid == 0 && sys->tk[tid].hsHeat.wid == 0)?0:1;
	SetCtrlAttribute(panel,PANEL_TANK_HEAT_OFF, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_HEAT_ON, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_HEAT_LAB, ATTR_VISIBLE, v);
	
	//SHUT
	v = (sys->tk[tid].hsShutOpen.wid == 0 && sys->tk[tid].hsShutOpen.wid == 0)?0:1;
	SetCtrlAttribute(panel,PANEL_TANK_SHUT_OFF, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_SHUT_ON, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_SHUT_LAB, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_SHUT, ATTR_VISIBLE, v);
	
	
	//CAR
	v = (rid1 == RTK_UNKNOW || (sys->rtk[rid1].hsFill.wid == 0 && sys->rtk[rid1].hsFill.wid == 0))?0:1;
	SetCtrlAttribute(panel,PANEL_TANK_FILL_OFF, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_FILL_ON, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_FILL1_LAB, ATTR_VISIBLE, v);
	
	v = (rid2 == RTK_UNKNOW)?0:1;
	SetCtrlAttribute(panel,PANEL_TANK_FILL2_OFF, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_FILL2_ON, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_FILL2_LAB, ATTR_VISIBLE, v);
	
	//add water
	v = (sys->tk[tid].hsAddWater.wid == 0 && sys->tk[tid].hsAddWater.wid == 0)?0:1;
	SetCtrlAttribute(panel,PANEL_TANK_ADD_WATER_OFF, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_ADD_WATER_ON, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_ADD_WATER_LAB, ATTR_VISIBLE, v);
	
	//BUBBle
/*	v = (sys->tk[tid].hsBubble.wid == 0 && sys->tk[tid].hsBubble.wid == 0)?0:1;
	SetCtrlAttribute(panel,PANEL_TANK_BUBB_OFF, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_BUBB_ON, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_BUBB_LAB, ATTR_VISIBLE, v);*/
	
//	SetCtrlAttribute(panel,PANEL_TANK_COND, ATTR_VISIBLE, v);
	
	//drain
/*	v = (sys->tk[tid].hsDrain.wid == 0 && sys->tk[tid].hsDrain.wid == 0)?0:1;
	SetCtrlAttribute(panel,PANEL_TANK_DRAIN_OFF, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_DRAIN_ON, ATTR_VISIBLE, v);
	SetCtrlAttribute(panel,PANEL_TANK_DRAIN_LAB, ATTR_VISIBLE, v);
*/	
	if(tid == TANK_02)
	{
		SetCtrlAttribute(panel,PANEL_TANK_VALVE_MAKE_AC1_IN, ATTR_LABEL_TEXT, "H2O2\n配槽");
		SetCtrlAttribute(panel,PANEL_TANK_VALVE_DOS_AC1_IN, ATTR_LABEL_TEXT, "H2O2\n補液");
		SetCtrlAttribute(panel,PANEL_TANK_AC1_MAKE, ATTR_LABEL_TEXT, "H2O2(L) ");
		SetCtrlVal(panel,PANEL_TANK_AC1_DOS_LAB, "H2O2補液");
		
		SetCtrlAttribute(panel,PANEL_TANK_VALVE_MAKE_AC2_IN, ATTR_LABEL_TEXT, "KOH\n配槽");
		SetCtrlAttribute(panel,PANEL_TANK_VALVE_DOS_AC2_IN, ATTR_LABEL_TEXT, "KOH\n補液");
		SetCtrlAttribute(panel,PANEL_TANK_AC2_MAKE, ATTR_LABEL_TEXT, "KOH(L) ");
		SetCtrlVal(panel,PANEL_TANK_AC2_DOS_LAB, "KOH補液");
		
		SetCtrlAttribute(panel,PANEL_TANK_VALVE_MAKE_AC3_IN, ATTR_LABEL_TEXT, "DIW\n配槽");
		SetCtrlAttribute(panel,PANEL_TANK_VALVE_DOS_AC3_IN, ATTR_LABEL_TEXT, "DIW\n補液");
		SetCtrlAttribute(panel,PANEL_TANK_AC3_MAKE, ATTR_LABEL_TEXT, "DIW(L) ");
		SetCtrlVal(panel,PANEL_TANK_AC3_DOS_LAB, "DIW補液");

	}
	if(tid == TANK_04 || tid == TANK_07)
	{
		SetCtrlAttribute(panel,PANEL_TANK_VALVE_MAKE_AC1_IN, ATTR_LABEL_TEXT, "IPA\n配槽");
		SetCtrlAttribute(panel,PANEL_TANK_VALVE_DOS_AC3_IN, ATTR_LABEL_TEXT, "IPA\n補液");
		SetCtrlAttribute(panel,PANEL_TANK_AC1_MAKE, ATTR_LABEL_TEXT, "IPA(L) ");
		SetCtrlVal(panel,PANEL_TANK_AC1_DOS_LAB, "IPA補液");
		
		
		SetCtrlAttribute(panel,PANEL_TANK_AC1_MAKE, ATTR_DIMMED, 1);
		SetCtrlAttribute(panel,PANEL_TANK_AC1_DOS_OFF, ATTR_DIMMED, 1);
		SetCtrlAttribute(panel,PANEL_TANK_AC1_DOS_ON, ATTR_DIMMED, 1);
		/*SetCtrlAttribute(panel,PANEL_TANK_AC1_MAKE, ATTR_VISIBLE, 0);
		SetCtrlAttribute(panel,PANEL_TANK_AC1_DOS_LAB, ATTR_VISIBLE, 0);
		SetCtrlAttribute(panel,PANEL_TANK_AC1_DOS_OFF, ATTR_VISIBLE, 0);
		SetCtrlAttribute(panel,PANEL_TANK_AC1_DOS_ON, ATTR_VISIBLE, 0); */
		
		SetCtrlAttribute(panel,PANEL_TANK_VALVE_MAKE_AC2_IN, ATTR_LABEL_TEXT, "KOH\n配槽");
		SetCtrlAttribute(panel,PANEL_TANK_VALVE_DOS_AC2_IN, ATTR_LABEL_TEXT, "KOH\n補液");
		SetCtrlAttribute(panel,PANEL_TANK_AC2_MAKE, ATTR_LABEL_TEXT, "KOH(L) ");
		SetCtrlVal(panel,PANEL_TANK_AC2_DOS_LAB, "KOH補液");
		
		SetCtrlAttribute(panel,PANEL_TANK_VALVE_MAKE_AC3_IN, ATTR_LABEL_TEXT, "DIW\n配槽");
		SetCtrlAttribute(panel,PANEL_TANK_VALVE_DOS_AC1_IN, ATTR_LABEL_TEXT, "DIW\n補液");
		SetCtrlAttribute(panel,PANEL_TANK_AC3_MAKE, ATTR_LABEL_TEXT, "DIW(L) ");
		SetCtrlVal(panel,PANEL_TANK_AC3_DOS_LAB, "DIW補液");
		
		SetCtrlAttribute(panel,PANEL_TANK_VALVE_MAKE_AC4_IN, ATTR_LABEL_TEXT, "ADD\n配槽");
		SetCtrlAttribute(panel,PANEL_TANK_VALVE_DOS_AC4_IN, ATTR_LABEL_TEXT, "ADD\n補液");
		SetCtrlAttribute(panel,PANEL_TANK_AC4_MAKE, ATTR_LABEL_TEXT, "ADD(ML) ");
		SetCtrlVal(panel,PANEL_TANK_AC4_DOS_LAB, "ADD補液");

	}
	else if(tid == TANK_11)
	{
		SetCtrlAttribute(panel,PANEL_TANK_VALVE_MAKE_AC2_IN, ATTR_LABEL_TEXT, "HF\n配槽");
		SetCtrlAttribute(panel,PANEL_TANK_VALVE_DOS_AC2_IN, ATTR_LABEL_TEXT, "HF\n補液");
		SetCtrlAttribute(panel,PANEL_TANK_AC2_MAKE, ATTR_LABEL_TEXT, "HF(L) ");
		SetCtrlVal(panel,PANEL_TANK_AC2_DOS_LAB, "HF補液");
		
		SetCtrlAttribute(panel,PANEL_TANK_VALVE_MAKE_AC1_IN, ATTR_LABEL_TEXT, "HCL\n配槽");
		SetCtrlAttribute(panel,PANEL_TANK_VALVE_DOS_AC1_IN, ATTR_LABEL_TEXT, "HCL\n補液");
		SetCtrlAttribute(panel,PANEL_TANK_AC1_MAKE, ATTR_LABEL_TEXT, "HCL(L) ");
		SetCtrlVal(panel,PANEL_TANK_AC1_DOS_LAB, "HCL補液");
		
		SetCtrlAttribute(panel,PANEL_TANK_VALVE_MAKE_AC3_IN, ATTR_LABEL_TEXT, "DIW\n配槽");
		SetCtrlAttribute(panel,PANEL_TANK_VALVE_DOS_AC3_IN, ATTR_LABEL_TEXT, "DIW\n補液");
		SetCtrlAttribute(panel,PANEL_TANK_AC3_MAKE, ATTR_LABEL_TEXT, "DIW(L) ");
		SetCtrlVal(panel,PANEL_TANK_AC3_DOS_LAB, "DIW補液");

	}
	
	if(tid == TANK_02 || tid == TANK_04 || tid == TANK_07 || tid == TANK_11)
	{
		if(testBit(sys->tk[tid].hsMake,RB) > 0)
		{
			SetCtrlVal(panel,PANEL_TANK_AC1_MAKE,sys->tk[tid].MakeCH1);
			SetCtrlVal(panel,PANEL_TANK_AC2_MAKE,sys->tk[tid].MakeCH2); 
			SetCtrlVal(panel,PANEL_TANK_AC3_MAKE,sys->tk[tid].MakeCH3);
			SetCtrlVal(panel,PANEL_TANK_AC4_MAKE,sys->tk[tid].MakeCH4);
		}
		else if(testBit(sys->tk[tid].hsMMake,RB) > 0)
		{
			SetCtrlVal(panel,PANEL_TANK_AC1_MAKE,sys->tk[tid].MMakeCH1);
			SetCtrlVal(panel,PANEL_TANK_AC2_MAKE,sys->tk[tid].MMakeCH2); 
			SetCtrlVal(panel,PANEL_TANK_AC3_MAKE,sys->tk[tid].MMakeCH3);
			SetCtrlVal(panel,PANEL_TANK_AC4_MAKE,sys->tk[tid].MMakeCH4);
		}
	}
	
	preTempTrendPos = sys->curTempTrendPos;
	if(sys->tk[curTankId].tempData[TREND_DATA_LEN - sys->curTempTrendPos - 1] != 0) 
	PlotStripChart (panel, PANEL_TANK_STRIPCHART, sys->tk[curTankId].tempData, TREND_DATA_LEN - sys->curTempTrendPos - 1, sys->curTempTrendPos+1, 0, VAL_DOUBLE);
	PlotStripChart (panel, PANEL_TANK_STRIPCHART, sys->tk[curTankId].tempData, sys->curTempTrendPos + 1, 0, 0, VAL_DOUBLE);
	
}



int CVICALLBACK TankTimer (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_TIMER_TICK:
			//shut
			if(testBit(sys->tk[curTankId].xShutOpen,RX) > 0 && testBit(sys->tk[curTankId].xShutClose,RX) == 0 )
				SetCtrlVal(panel,PANEL_TANK_SHUT, 2);
			else if(testBit(sys->tk[curTankId].xShutOpen,RX) == 0 && testBit(sys->tk[curTankId].xShutClose,RX) > 0 )
				SetCtrlVal(panel,PANEL_TANK_SHUT, 1);
			else
				SetCtrlVal(panel,PANEL_TANK_SHUT, 3);
			
			//temp
			if(preTempTrendPos != sys->curTempTrendPos && sys->tk[curTankId].curTemp != 0)
			{
				preTempTrendPos = sys->curTempTrendPos;
				PlotStripChart (panel, PANEL_TANK_STRIPCHART, &sys->tk[curTankId].curTemp, 1, 0, 0, VAL_DOUBLE);
			}
			SetCtrlVal(panel,PANEL_TANK_TEMP, sys->tk[curTankId].curTemp); 
			
			//valve
			SetCtrlVal(panel,PANEL_TANK_VALVE_DIW_IN, testBit(sys->tk[curTankId].yValveDiwIn,RY)>0 ? 1 : 0);
			SetCtrlVal(panel,PANEL_TANK_VALVE_DOWN, testBit(sys->tk[curTankId].yValveDown,RY)>0 ? 1 : 0);
			
			//heater
			SetCtrlAttribute(panel,PANEL_TANK_HEATER, ATTR_VISIBLE, testBit(sys->tk[curTankId].yHeat,RY)>0 ? 1 : 0);
			
			//car
			SetCtrlVal(panel,PANEL_TANK_CAR1, (curRTankId1 != RTK_UNKNOW && testBit(sys->rtk[curRTankId1].hsFill,WB)>0) ? 1 : 0);
			SetCtrlVal(panel,PANEL_TANK_CAR2, (curRTankId2 != RTK_UNKNOW && testBit(sys->rtk[curRTankId2].hsFill,WB)>0) ? 1 : 0);
			
			//pump
			SetCtrlVal(panel,PANEL_TANK_PUMP, testBit(sys->tk[curTankId].yPump,RY)>0 ? 1 : 0);
			SetCtrlVal(panel,PANEL_TANK_PUMP, testBit(sys->tk[curTankId].yPumpIn,RY)>0 ? 1 : 0); 
			
			//level
			int lev = (testBit(sys->tk[curTankId].xLevLL,RX)>0 ? 1 : 0);
			lev +=  (testBit(sys->tk[curTankId].xLevL,RX)>0 ? 1 : 0);
			lev +=  (testBit(sys->tk[curTankId].xLevH,RX)>0 ? 1 : 0);
			lev +=  (testBit(sys->tk[curTankId].xLevHH,RX)>0 ? 1 : 0);
			SetCtrlVal(panel,PANEL_TANK_TANK, lev);
			
			//make buf tank
			SetCtrlVal(panel,PANEL_TANK_VALVE_MAKE_AC1_IN, testBit(sys->tk[curTankId].yValveMakeAc1In,RY)>0 ? 1 : 0);
			SetCtrlVal(panel,PANEL_TANK_VALVE_MAKE_AC2_IN, testBit(sys->tk[curTankId].yValveMakeAc2In,RY)>0 ? 1 : 0);
			SetCtrlVal(panel,PANEL_TANK_VALVE_MAKE_AC3_IN, testBit(sys->tk[curTankId].yValveMakeAc3In,RY)>0 ? 1 : 0);
			SetCtrlVal(panel,PANEL_TANK_VALVE_MAKE_AC4_IN, testBit(sys->tk[curTankId].yValveMakeAc4In,RY)>0 ? 1 : 0);

/*			lev = (testBit(sys->tk[curTankId].xMakeAc1LevH,RX)>0 ? 1 : 0);
			lev +=  (testBit(sys->tk[curTankId].xMakeAc1LevL,RX)>0 ? 1 : 0);
			SetCtrlVal(panel,PANEL_TANK_AC1_MAKE_BUF, lev); 

			lev = (testBit(sys->tk[curTankId].xMakeAc2LevH,RX)>0 ? 1 : 0);
			lev +=  (testBit(sys->tk[curTankId].xMakeAc2LevL,RX)>0 ? 1 : 0);
			SetCtrlVal(panel,PANEL_TANK_AC2_MAKE_BUF, lev);   */
			
			SetCtrlVal(panel,PANEL_TANK_MAKE_CH1, sys->tk[curTankId].MakeCountCH1/10.0);
			SetCtrlVal(panel,PANEL_TANK_MAKE_CH2, sys->tk[curTankId].MakeCountCH2/10.0);
			SetCtrlVal(panel,PANEL_TANK_MAKE_CH3, sys->tk[curTankId].MakeCountCH3/10.0);
			SetCtrlVal(panel,PANEL_TANK_MAKE_CH4, sys->tk[curTankId].MakeCountCH4/1.0);
			
			
			SetCtrlVal(panel,PANEL_TANK_MMAKE_CH1, sys->tk[curTankId].MMakeCountCH1/10.0);
			SetCtrlVal(panel,PANEL_TANK_MMAKE_CH2, sys->tk[curTankId].MMakeCountCH2/10.0);
			SetCtrlVal(panel,PANEL_TANK_MMAKE_CH3, sys->tk[curTankId].MMakeCountCH3/10.0);
			SetCtrlVal(panel,PANEL_TANK_MMAKE_CH4, sys->tk[curTankId].MMakeCountCH4/1.0);
																				   
			SetCtrlVal(panel,PANEL_TANK_DOS_CH1, sys->tk[curTankId].DosingCountCH1);
			SetCtrlVal(panel,PANEL_TANK_DOS_CH2, sys->tk[curTankId].DosingCountCH2);
			SetCtrlVal(panel,PANEL_TANK_DOS_CH3, sys->tk[curTankId].DosingCountCH3);
			SetCtrlVal(panel,PANEL_TANK_DOS_CH4, sys->tk[curTankId].DosingCountCH4);
			
			SetCtrlVal(panel,PANEL_TANK_FLOW, sys->tk[curTankId].Flow/10.0);
			
			SetCtrlVal(panel,PANEL_TANK_COND, sys->tk[curTankId].Cond/1.0);
			
			//dosing buf tank																 
			SetCtrlVal(panel,PANEL_TANK_VALVE_DOS_AC1_IN, testBit(sys->tk[curTankId].yValveDosAc1In,RY)>0 ? 1 : 0);
			SetCtrlVal(panel,PANEL_TANK_VALVE_DOS_AC1_OUT, testBit(sys->tk[curTankId].yValveDosAc1Out,RY)>0 ? 1 : 0);
			SetCtrlVal(panel,PANEL_TANK_VALVE_DOS_AC2_IN, testBit(sys->tk[curTankId].yValveDosAc2In,RY)>0 ? 1 : 0);
			SetCtrlVal(panel,PANEL_TANK_VALVE_DOS_AC2_OUT, testBit(sys->tk[curTankId].yValveDosAc2Out,RY)>0 ? 1 : 0);
			SetCtrlVal(panel,PANEL_TANK_VALVE_DOS_AC3_IN, testBit(sys->tk[curTankId].yValveDosAc3In,RY)>0 ? 1 : 0);
			SetCtrlVal(panel,PANEL_TANK_VALVE_DOS_AC3_OUT, testBit(sys->tk[curTankId].yValveDosAc3Out,RY)>0 ? 1 : 0);
			SetCtrlVal(panel,PANEL_TANK_VALVE_DOS_AC4_IN, testBit(sys->tk[curTankId].yValveDosAc4In,RY)>0 ? 1 : 0);
			SetCtrlVal(panel,PANEL_TANK_VALVE_DOS_AC4_OUT, testBit(sys->tk[curTankId].yValveDosAc4Out,RY)>0 ? 1 : 0);
			
			lev = (testBit(sys->tk[curTankId].xDosAc1LevH,RX)>0 ? 1 : 0);
			lev +=  (testBit(sys->tk[curTankId].xDosAc1LevL,RX)>0 ? 1 : 0);
			SetCtrlVal(panel,PANEL_TANK_AC1_DOS_BUF, lev);

			lev = (testBit(sys->tk[curTankId].xDosAc2LevH,RX)>0 ? 1 : 0);
			lev +=  (testBit(sys->tk[curTankId].xDosAc2LevL,RX)>0 ? 1 : 0);
			SetCtrlVal(panel,PANEL_TANK_AC2_DOS_BUF, lev);
			
			lev = (testBit(sys->tk[curTankId].xDosAc3LevH,RX)>0 ? 1 : 0);
			lev +=  (testBit(sys->tk[curTankId].xDosAc3LevL,RX)>0 ? 1 : 0);
			SetCtrlVal(panel,PANEL_TANK_AC3_DOS_BUF, lev);

			lev = (testBit(sys->tk[curTankId].xDosAc4LevH,RX)>0 ? 1 : 0);
			lev +=  (testBit(sys->tk[curTankId].xDosAc4LevL,RX)>0 ? 1 : 0);
			SetCtrlVal(panel,PANEL_TANK_AC4_DOS_BUF, lev);
				  
			//bubble
			if(testBit(sys->tk[curTankId].hsBubble,WB) > 0)
			{
				bubble(panel, PANEL_TANK_BUBBLE1,180,290,30);
				bubble(panel, PANEL_TANK_BUBBLE2,180,290,30);
				bubble(panel, PANEL_TANK_BUBBLE3,180,290,30);
				bubble(panel, PANEL_TANK_BUBBLE4,180,290,30);
				bubble(panel, PANEL_TANK_BUBBLE5,180,290,30);
				bubble(panel, PANEL_TANK_BUBBLE6,180,290,30);
				bubble(panel, PANEL_TANK_BUBBLE7,180,290,30);
			}
			
			//button
			if(sys->tk[curTankId].hsMake.wid != 0 || sys->tk[curTankId].hsMake.bid != 0)
			{
				SetCtrlAttribute(panel,PANEL_TANK_AMAKE_OFF, ATTR_VISIBLE, testBit(sys->tk[curTankId].hsMake,RB) > 0 ? 0 : 1);
				SetCtrlAttribute(panel,PANEL_TANK_AMAKE_ON, ATTR_VISIBLE, testBit(sys->tk[curTankId].hsMake,RB) > 0 ? 1 : 0);
				
				SetCtrlAttribute(panel,PANEL_TANK_MMAKE_OFF, ATTR_VISIBLE, testBit(sys->tk[curTankId].hsMMake,RB) > 0 ? 0 : 1);
				SetCtrlAttribute(panel,PANEL_TANK_MMAKE_ON, ATTR_VISIBLE, testBit(sys->tk[curTankId].hsMMake,RB) > 0 ? 1 : 0);
			}
			
			if(sys->tk[curTankId].hsAC1Dos.wid != 0 || sys->tk[curTankId].hsAC1Dos.bid != 0)
			{
				SetCtrlAttribute(panel,PANEL_TANK_AC1_DOS_OFF, ATTR_VISIBLE, testBit(sys->tk[curTankId].hsAC1Dos,WB) > 0 ? 0 : 1);
				SetCtrlAttribute(panel,PANEL_TANK_AC1_DOS_ON, ATTR_VISIBLE, testBit(sys->tk[curTankId].hsAC1Dos,WB) > 0 ? 1 : 0);
			}
			
			if(sys->tk[curTankId].hsAC2Dos.wid != 0 || sys->tk[curTankId].hsAC2Dos.bid != 0)
			{
				SetCtrlAttribute(panel,PANEL_TANK_AC2_DOS_OFF, ATTR_VISIBLE, testBit(sys->tk[curTankId].hsAC2Dos,WB) > 0 ? 0 : 1);
				SetCtrlAttribute(panel,PANEL_TANK_AC2_DOS_ON, ATTR_VISIBLE, testBit(sys->tk[curTankId].hsAC2Dos,WB) > 0 ? 1 : 0);
			}
			
			if(sys->tk[curTankId].hsAC3Dos.wid != 0 || sys->tk[curTankId].hsAC3Dos.bid != 0)
			{
				SetCtrlAttribute(panel,PANEL_TANK_AC3_DOS_OFF, ATTR_VISIBLE, testBit(sys->tk[curTankId].hsAC3Dos,WB) > 0 ? 0 : 1);
				SetCtrlAttribute(panel,PANEL_TANK_AC3_DOS_ON, ATTR_VISIBLE, testBit(sys->tk[curTankId].hsAC3Dos,WB) > 0 ? 1 : 0);
			}
			
			if(sys->tk[curTankId].hsAC4Dos.wid != 0 || sys->tk[curTankId].hsAC4Dos.bid != 0)
			{
				SetCtrlAttribute(panel,PANEL_TANK_AC4_DOS_OFF, ATTR_VISIBLE, testBit(sys->tk[curTankId].hsAC4Dos,WB) > 0 ? 0 : 1);
				SetCtrlAttribute(panel,PANEL_TANK_AC4_DOS_ON, ATTR_VISIBLE, testBit(sys->tk[curTankId].hsAC4Dos,WB) > 0 ? 1 : 0);
			}
			
			
			if(sys->tk[curTankId].hsWash.wid != 0 || sys->tk[curTankId].hsWash.bid != 0)
			{
				SetCtrlAttribute(panel,PANEL_TANK_WASH_OFF, ATTR_VISIBLE, testBit(sys->tk[curTankId].hsWash,WB) > 0 ? 0 : 1);
				SetCtrlAttribute(panel,PANEL_TANK_WASH_ON, ATTR_VISIBLE, testBit(sys->tk[curTankId].hsWash,WB) > 0 ? 1 : 0);
			}
			
			if(sys->tk[curTankId].hsDown.wid != 0 || sys->tk[curTankId].hsDown.bid != 0)
			{
				SetCtrlAttribute(panel,PANEL_TANK_DOWN_OFF, ATTR_VISIBLE, testBit(sys->tk[curTankId].hsDown,WB) > 0 ? 0 : 1);
				SetCtrlAttribute(panel,PANEL_TANK_DOWN_ON, ATTR_VISIBLE, testBit(sys->tk[curTankId].hsDown,WB) > 0 ? 1 : 0);
			}
			
			if(sys->tk[curTankId].hsPump.wid != 0 || sys->tk[curTankId].hsPump.bid != 0)
			{
				SetCtrlAttribute(panel,PANEL_TANK_PUMP_OFF, ATTR_VISIBLE, testBit(sys->tk[curTankId].hsPump,WB) > 0 ? 1 : 0);
				SetCtrlAttribute(panel,PANEL_TANK_PUMP_ON, ATTR_VISIBLE, testBit(sys->tk[curTankId].hsPump,WB) > 0 ? 0 : 1); 
			}
			
			if(sys->tk[curTankId].hsPumpIn.wid != 0 || sys->tk[curTankId].hsPumpIn.bid != 0)
			{
				SetCtrlAttribute(panel,PANEL_TANK_PUMPIN_OFF, ATTR_VISIBLE, testBit(sys->tk[curTankId].hsPumpIn,WB) > 0 ? 1 : 0);
				SetCtrlAttribute(panel,PANEL_TANK_PUMPIN_ON, ATTR_VISIBLE, testBit(sys->tk[curTankId].hsPumpIn,WB) > 0 ? 0 : 1); 
			}
			
			if(sys->tk[curTankId].hsHeat.wid != 0 || sys->tk[curTankId].hsHeat.bid != 0)
			{
				SetCtrlAttribute(panel,PANEL_TANK_HEAT_OFF, ATTR_VISIBLE, testBit(sys->tk[curTankId].hsHeat,WB) > 0 ? 1 : 0);
				SetCtrlAttribute(panel,PANEL_TANK_HEAT_ON, ATTR_VISIBLE, testBit(sys->tk[curTankId].hsHeat,WB) > 0 ? 0 : 1);
			}
			
			if(sys->tk[curTankId].hsAddWater.wid != 0 || sys->tk[curTankId].hsAddWater.bid != 0)
			{
				SetCtrlAttribute(panel,PANEL_TANK_ADD_WATER_ON, ATTR_VISIBLE, testBit(sys->tk[curTankId].hsAddWater,WB) > 0 ? 1 : 0);
				SetCtrlAttribute(panel,PANEL_TANK_ADD_WATER_OFF, ATTR_VISIBLE, testBit(sys->tk[curTankId].hsAddWater,WB) > 0 ? 0 : 1);
			}
			
			if(sys->tk[curTankId].hsShutOpen.wid != 0 || sys->tk[curTankId].hsShutOpen.bid != 0 )
			{
				SetCtrlAttribute(panel,PANEL_TANK_SHUT_OFF, ATTR_VISIBLE, testBit(sys->tk[curTankId].hsShutOpen,WB) > 0 ? 0 : 1);
				SetCtrlAttribute(panel,PANEL_TANK_SHUT_ON, ATTR_VISIBLE, testBit(sys->tk[curTankId].hsShutOpen,WB) > 0 ? 1 : 0);
			}
			
	/*		if(sys->tk[curTankId].hsBubble.wid != 0 || sys->tk[curTankId].hsBubble.bid != 0)
			{
				SetCtrlAttribute(panel,PANEL_TANK_BUBB_OFF, ATTR_VISIBLE, testBit(sys->tk[curTankId].hsBubble,WB) > 0 ? 0 : 1);
				SetCtrlAttribute(panel,PANEL_TANK_BUBB_ON, ATTR_VISIBLE, testBit(sys->tk[curTankId].hsBubble,WB) > 0 ? 1 : 0);
			}  */
			
			if(curRTankId1 != RTK_UNKNOW && (sys->rtk[curRTankId1].hsFill.wid != 0 || sys->rtk[curRTankId1].hsFill.bid != 0))
			{
				SetCtrlAttribute(panel,PANEL_TANK_FILL_OFF, ATTR_VISIBLE, testBit(sys->rtk[curRTankId1].hsFill,WB) > 0 ? 0 : 1);
				SetCtrlAttribute(panel,PANEL_TANK_FILL_ON, ATTR_VISIBLE, testBit(sys->rtk[curRTankId1].hsFill,WB) > 0 ? 1 : 0);
			} 
			
			if(curRTankId2 != RTK_UNKNOW && (sys->rtk[curRTankId2].hsFill.wid != 0 || sys->rtk[curRTankId2].hsFill.bid != 0) )
			{
				SetCtrlAttribute(panel,PANEL_TANK_FILL2_OFF, ATTR_VISIBLE, testBit(sys->rtk[curRTankId2].hsFill,WB) > 0 ? 0 : 1);
				SetCtrlAttribute(panel,PANEL_TANK_FILL2_ON, ATTR_VISIBLE, testBit(sys->rtk[curRTankId2].hsFill,WB) > 0 ? 1 : 0);
			}
			
/*			if(sys->tk[curTankId].hsDrain.wid != 0 || sys->tk[curTankId].hsDrain.bid != 0)
			{
				SetCtrlAttribute(panel,PANEL_TANK_DRAIN_OFF, ATTR_VISIBLE, testBit(sys->tk[curTankId].hsDrain,WB) > 0 ? 0 : 1);
				SetCtrlAttribute(panel,PANEL_TANK_DRAIN_ON, ATTR_VISIBLE, testBit(sys->tk[curTankId].hsDrain,WB) > 0 ? 1 : 0);
			} */
			
			break;
	}
	return 0;
}

int CVICALLBACK Command (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	if(event != EVENT_LEFT_CLICK)
		return 0;
	
	if(CheckAuth(OP_TANK) == 0)
		return 0;
	if (!ButtonConfirm (panel,control))		
		return 0; 
	
	switch (control) {
		case PANEL_TANK_AMAKE_OFF:
			if(testBit(sys->tk[curTankId].hsMakeEnd,RB) > 0)
			{
				MessagePopup("操作條件不滿足","請先排放，才可執行配槽！");
				break;
			}
			if(g_setupMake == 0)
			{
				GetCtrlVal(panel,PANEL_TANK_AC1_MAKE,&sys->tk[curTankId].MakeCH1);
				GetCtrlVal(panel,PANEL_TANK_AC2_MAKE,&sys->tk[curTankId].MakeCH2); 
				GetCtrlVal(panel,PANEL_TANK_AC3_MAKE,&sys->tk[curTankId].MakeCH3);
				GetCtrlVal(panel,PANEL_TANK_AC4_MAKE,&sys->tk[curTankId].MakeCH4);
				g_makeBit = sys->tk[curTankId].hsMake;
				g_setupMake = 1;
				
				ActionLog(TANK_MAKE_ACT_EVENT,curTankId,1,sys->tk[curTankId].MakeCH1,sys->tk[curTankId].MakeCH2,sys->tk[curTankId].MakeCH3);
			}
			break;
		case PANEL_TANK_AMAKE_ON:
			resetBit(sys->tk[curTankId].hsMake);
			
			ActionLog(TANK_MAKE_ACT_EVENT,curTankId,0,0,0,0);
			break;
			
		case PANEL_TANK_MMAKE_OFF:
			if(testBit(sys->tk[curTankId].hsMakeEnd,RB) == 0)
			{
				MessagePopup("操作條件不滿足","配槽未完成，不可添加！");
				break;
			}
			if(g_setupMMake == 0)
			{
				GetCtrlVal(panel,PANEL_TANK_AC1_MAKE,&sys->tk[curTankId].MMakeCH1);
				GetCtrlVal(panel,PANEL_TANK_AC2_MAKE,&sys->tk[curTankId].MMakeCH2); 
				GetCtrlVal(panel,PANEL_TANK_AC3_MAKE,&sys->tk[curTankId].MMakeCH3);
				GetCtrlVal(panel,PANEL_TANK_AC4_MAKE,&sys->tk[curTankId].MMakeCH4);
				g_mmakeBit = sys->tk[curTankId].hsMMake;
				g_setupMMake = 1;
				
				ActionLog(TANK_MMAKE_ACT_EVENT,curTankId,1,sys->tk[curTankId].MMakeCH1,sys->tk[curTankId].MMakeCH2,sys->tk[curTankId].MMakeCH3);
			}
			break;
		case PANEL_TANK_MMAKE_ON:
			resetBit(sys->tk[curTankId].hsMMake);
			
			ActionLog(TANK_MAKE_ACT_EVENT,curTankId,0,0,0,0);
			break;	
			
		case PANEL_TANK_AC1_DOS_OFF:
			setBit(sys->tk[curTankId].hsAC1Dos);
			ActionLog(TANK_DOS_ACT_EVENT,curTankId,1,1,0,0);
			
			break;
		case PANEL_TANK_AC1_DOS_ON:
			resetBit(sys->tk[curTankId].hsAC1Dos);
			
			ActionLog(TANK_DOS_ACT_EVENT,curTankId,1,0,0,0);
			break;	
			
		case PANEL_TANK_AC2_DOS_OFF:
			setBit(sys->tk[curTankId].hsAC2Dos);
			ActionLog(TANK_DOS_ACT_EVENT,curTankId,2,1,0,0);
			
			break;
		case PANEL_TANK_AC2_DOS_ON:
			resetBit(sys->tk[curTankId].hsAC2Dos);
			
			ActionLog(TANK_DOS_ACT_EVENT,curTankId,2,0,0,0);
			break;
			
		case PANEL_TANK_AC3_DOS_OFF:
			setBit(sys->tk[curTankId].hsAC3Dos);
			ActionLog(TANK_DOS_ACT_EVENT,curTankId,3,1,0,0);
			
			break;
		case PANEL_TANK_AC3_DOS_ON:
			resetBit(sys->tk[curTankId].hsAC3Dos);
			
			ActionLog(TANK_DOS_ACT_EVENT,curTankId,3,0,0,0);
			break;	
			
		case PANEL_TANK_AC4_DOS_OFF:
			setBit(sys->tk[curTankId].hsAC4Dos);
			ActionLog(TANK_DOS_ACT_EVENT,curTankId,4,1,0,0);
			
			break;
		case PANEL_TANK_AC4_DOS_ON:
			resetBit(sys->tk[curTankId].hsAC4Dos);
			
			ActionLog(TANK_DOS_ACT_EVENT,curTankId,4,0,0,0);
			break;	
			
        case PANEL_TANK_WASH_OFF:
			setBit(sys->tk[curTankId].hsWash);
			
			ActionLog(TANK_WASH_ACT_EVENT,curTankId,1,0,0,0);
			break;
		case PANEL_TANK_WASH_ON:
			resetBit(sys->tk[curTankId].hsWash);
			
			ActionLog(TANK_WASH_ACT_EVENT,curTankId,0,0,0,0);
			break;
			
		case PANEL_TANK_DOWN_OFF:
			if(testBit(sys->tk[curTankId].hsMakeEnd,RB) == 0)
			{
				MessagePopup("操作條件不滿足","配槽未完成，不可排放！！");
				break;
			}
			setBit(sys->tk[curTankId].hsDown);
			ActionLog(TANK_DOWN_ACT_EVENT,curTankId,1,0,0,0);
			break;
		case PANEL_TANK_DOWN_ON:
			resetBit(sys->tk[curTankId].hsDown);
			ActionLog(TANK_DOWN_ACT_EVENT,curTankId,0,0,0,0);
			break;
			
		case PANEL_TANK_PUMP_OFF:
			resetBit(sys->tk[curTankId].hsPump);
			ActionLog(TANK_PUMP_ACT_EVENT,curTankId,1,0,0,0);
			break;
		case PANEL_TANK_PUMP_ON:
			ActionLog(TANK_PUMP_ACT_EVENT,curTankId,0,0,0,0);
			setBit(sys->tk[curTankId].hsPump);
			break;
			
		case PANEL_TANK_PUMPIN_OFF:
			resetBit(sys->tk[curTankId].hsPumpIn);
			ActionLog(TANK_PUMP_ACT_EVENT,curTankId,1,0,0,0);
			break;
		case PANEL_TANK_PUMPIN_ON:
			ActionLog(TANK_PUMP_ACT_EVENT,curTankId,0,0,0,0);
			setBit(sys->tk[curTankId].hsPumpIn);
			break;	
			
		case PANEL_TANK_HEAT_OFF:
			resetBit(sys->tk[curTankId].hsHeat);
			ActionLog(TANK_HEAT_ACT_EVENT,curTankId,1,0,0,0);
			break;
		case PANEL_TANK_HEAT_ON:
			setBit(sys->tk[curTankId].hsHeat);
			ActionLog(TANK_HEAT_ACT_EVENT,curTankId,0,0,0,0);
			break;
			
		case PANEL_TANK_ADD_WATER_OFF:
			setBit(sys->tk[curTankId].hsAddWater);
			ActionLog(TANK_ADD_WATER_ACT_EVENT,curTankId,1,0,0,0);
			break;
		case PANEL_TANK_ADD_WATER_ON:
			resetBit(sys->tk[curTankId].hsAddWater);
			ActionLog(TANK_ADD_WATER_ACT_EVENT,curTankId,0,0,0,0);
			break;	
			
		case PANEL_TANK_SHUT_OFF:
			setBit(sys->tk[curTankId].hsShutOpen);
			resetBit(sys->tk[curTankId].hsShutClose);
			ActionLog(TANK_SHUT_ACT_EVENT,curTankId,1,0,0,0);
			break;
		case PANEL_TANK_SHUT_ON:
			setBit(sys->tk[curTankId].hsShutClose);
			resetBit(sys->tk[curTankId].hsShutOpen);
			ActionLog(TANK_SHUT_ACT_EVENT,curTankId,0,0,0,0);
			break;	
			
/*		case PANEL_TANK_BUBB_OFF:
			setBit(sys->tk[curTankId].hsBubble);
			ActionLog(TANK_BUBB_ACT_EVENT,curTankId,1,0,0,0);
			break;
		case PANEL_TANK_BUBB_ON:
			resetBit(sys->tk[curTankId].hsBubble);
			ActionLog(TANK_BUBB_ACT_EVENT,curTankId,0,0,0,0);
			break;
					   
		case PANEL_TANK_DRAIN_OFF:
			setBit(sys->tk[curTankId].hsDrain);
			ActionLog(TANK_DRAIN_ACT_EVENT,curTankId,1,0,0,0);
			break;
		case PANEL_TANK_DRAIN_ON:
			resetBit(sys->tk[curTankId].hsDrain);
			ActionLog(TANK_DRAIN_ACT_EVENT,curTankId,0,0,0,0);
			break;	
	*/	
			
		case PANEL_TANK_FILL_OFF:
			//ChangFillStatus(sys->rtk[curRTankId1].hsFill,1);
			setBit(sys->rtk[curRTankId1].hsFill);
			GetCurrentDateTime(&sys->rtk[curRTankId1].car.iPrcTM[curTankId]);
			ActionLog(TANK_CAR_ACT_EVENT,curTankId,1,0,0,0);
			break;
		case PANEL_TANK_FILL_ON:
			resetBit(sys->rtk[curRTankId1].hsFill);
			//ChangFillStatus(sys->rtk[curRTankId1].hsFill,0);
			ActionLog(TANK_CAR_ACT_EVENT,curTankId,0,0,0,0);
			break;	
			
		case PANEL_TANK_FILL2_OFF:
			setBit(sys->rtk[curRTankId2].hsFill);
			GetCurrentDateTime(&sys->rtk[curRTankId2].car.iPrcTM[curTankId]);
			//ChangFillStatus(sys->rtk[curRTankId2].hsFill,1);
			ActionLog(TANK_CAR_ACT_EVENT,curTankId,1,0,0,0);
			break;
		case PANEL_TANK_FILL2_ON:
			resetBit(sys->rtk[curRTankId2].hsFill);
			//ChangFillStatus(sys->rtk[curRTankId2].hsFill,0);
			ActionLog(TANK_CAR_ACT_EVENT,curTankId,0,0,0,0);
			break;	
	}
	
	return 0;
}
