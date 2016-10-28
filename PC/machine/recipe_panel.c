#include <formatio.h>
#include "inifile.h"
#include <userint.h>
#include "robot_panel.h"

//==============================================================================
//
// Title:       recipe_panel.c
// Purpose:     A short description of the implementation.
//
// Created on:  2014/7/12 at ¤U¤È 01:04:12 by wang fang.
// Copyright:   hua. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files

//#include "recipe_panel.h"
#include "type.h"
#include "machine.h"
//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// Static global variables
int copyRecipeID = -1;
//==============================================================================
// Static functions
ListType dosList[4][4];
static int curTankId = 0;
static int curChId = 0;
//==============================================================================
// Global variables
extern int g_setupRecipe;
extern int g_setupTemp;
extern int panelHandle;

//==============================================================================
// Global functions
int SetupRecipeBody ( int _pHNDL)
{
	int _ProcTM = 0;
	int _ProcD = 0;
	int _Rcp100, _Rcp010, _Rcp001;
	
	// Part Lot Data
	GetCtrlVal ( _pHNDL, PANEL_RCP_PARTID, 				sys->rcp.PartNo);
	GetCtrlVal ( _pHNDL, PANEL_RCP_LOTID,				sys->rcp.LotNo);
	GetCtrlVal ( _pHNDL, PANEL_RCP_QTY,					&sys->rcp.QTY_SET);

	// Recipe Data
	GetCtrlVal ( _pHNDL, PANEL_RCP_RCIP_X00,			&_Rcp100);
	GetCtrlVal ( _pHNDL, PANEL_RCP_RCIP_0X0,			&_Rcp010);
	GetCtrlVal ( _pHNDL, PANEL_RCP_RCIP_00X,			&_Rcp001);
	sys->rcp.ID = _Rcp100*100 + _Rcp010*10 + _Rcp001;
	GetCtrlVal ( _pHNDL, PANEL_RCP_RCIP_NAME,			sys->rcp.Name);
	GetCtrlVal ( _pHNDL, PANEL_RCP_RCIP_CREATE,			sys->rcp.CrDay);
	// ==================================================================

	// ==================================================================
	// Process Time
	GetCtrlVal ( _pHNDL, PANEL_RCP_P_TM_01,	&sys->tk[TANK_01].rcp.ProcTM);
	GetCtrlVal ( _pHNDL, PANEL_RCP_P_TM_02,	&sys->tk[TANK_02].rcp.ProcTM);
	GetCtrlVal ( _pHNDL, PANEL_RCP_P_TM_03,	&sys->tk[TANK_03].rcp.ProcTM);
	GetCtrlVal ( _pHNDL, PANEL_RCP_P_TM_04,	&sys->tk[TANK_04].rcp.ProcTM);
	GetCtrlVal ( _pHNDL, PANEL_RCP_P_TM_05,	&sys->tk[TANK_05].rcp.ProcTM);
	GetCtrlVal ( _pHNDL, PANEL_RCP_P_TM_06,	&sys->tk[TANK_06].rcp.ProcTM);
	GetCtrlVal ( _pHNDL, PANEL_RCP_P_TM_07,	&sys->tk[TANK_07].rcp.ProcTM);
	GetCtrlVal ( _pHNDL, PANEL_RCP_P_TM_08,	&sys->tk[TANK_08].rcp.ProcTM);
	GetCtrlVal ( _pHNDL, PANEL_RCP_P_TM_09,	&sys->tk[TANK_09].rcp.ProcTM);
	GetCtrlVal ( _pHNDL, PANEL_RCP_P_TM_10,	&sys->tk[TANK_10].rcp.ProcTM);
	GetCtrlVal ( _pHNDL, PANEL_RCP_P_TM_11,	&sys->tk[TANK_11].rcp.ProcTM);
	GetCtrlVal ( _pHNDL, PANEL_RCP_P_TM_12,	&sys->tk[TANK_12].rcp.ProcTM);
	GetCtrlVal ( _pHNDL, PANEL_RCP_P_TM_13,	&sys->tk[TANK_13].rcp.ProcTM);
	GetCtrlVal ( _pHNDL, PANEL_RCP_P_TM_14,	&sys->tk[TANK_14].rcp.ProcTM);
	GetCtrlVal ( _pHNDL, PANEL_RCP_P_TM_15,	&sys->tk[TANK_15].rcp.ProcTM);
	GetCtrlVal ( _pHNDL, PANEL_RCP_P_TM_16,	&sys->tk[TANK_16].rcp.ProcTM);
	sys->tk[TANK_17].rcp.ProcTM = 1;

	
	GetCtrlVal ( _pHNDL, PANEL_RCP_PRE_TM01,	&sys->tk[TANK_01].rcp.PreGetTM);
	GetCtrlVal ( _pHNDL, PANEL_RCP_PRE_TM02,	&sys->tk[TANK_02].rcp.PreGetTM);
	GetCtrlVal ( _pHNDL, PANEL_RCP_PRE_TM03,	&sys->tk[TANK_03].rcp.PreGetTM);
	GetCtrlVal ( _pHNDL, PANEL_RCP_PRE_TM04,	&sys->tk[TANK_04].rcp.PreGetTM);
	GetCtrlVal ( _pHNDL, PANEL_RCP_PRE_TM05,	&sys->tk[TANK_05].rcp.PreGetTM);
	GetCtrlVal ( _pHNDL, PANEL_RCP_PRE_TM06,	&sys->tk[TANK_06].rcp.PreGetTM);
	GetCtrlVal ( _pHNDL, PANEL_RCP_PRE_TM07,	&sys->tk[TANK_07].rcp.PreGetTM);
	GetCtrlVal ( _pHNDL, PANEL_RCP_PRE_TM08,	&sys->tk[TANK_08].rcp.PreGetTM);
	GetCtrlVal ( _pHNDL, PANEL_RCP_PRE_TM09,	&sys->tk[TANK_09].rcp.PreGetTM);
	GetCtrlVal ( _pHNDL, PANEL_RCP_PRE_TM10,	&sys->tk[TANK_10].rcp.PreGetTM); 
	GetCtrlVal ( _pHNDL, PANEL_RCP_PRE_TM11,	&sys->tk[TANK_11].rcp.PreGetTM);
	GetCtrlVal ( _pHNDL, PANEL_RCP_PRE_TM12,	&sys->tk[TANK_12].rcp.PreGetTM);
	GetCtrlVal ( _pHNDL, PANEL_RCP_PRE_TM13,	&sys->tk[TANK_13].rcp.PreGetTM);
	GetCtrlVal ( _pHNDL, PANEL_RCP_PRE_TM14,	&sys->tk[TANK_14].rcp.PreGetTM);
	GetCtrlVal ( _pHNDL, PANEL_RCP_PRE_TM15,	&sys->tk[TANK_15].rcp.PreGetTM);
	GetCtrlVal ( _pHNDL, PANEL_RCP_PRE_TM16,	&sys->tk[TANK_16].rcp.PreGetTM);
	
//	sys->tk[TANK_18].rcp.ProcTM = 5.0;	
														
	// ==================================================================
	// Temperature - FRONT
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_2,		&sys->tk[TANK_02].rcp.Temp);
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_L_2,		&sys->tk[TANK_02].rcp.TempL);
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_H_2,		&sys->tk[TANK_02].rcp.TempH);
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_P_2,		&sys->tk[TANK_02].rcp.TempP);
	
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_3,		&sys->tk[TANK_03].rcp.Temp);
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_L_3,		&sys->tk[TANK_03].rcp.TempL);
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_H_3,		&sys->tk[TANK_03].rcp.TempH);
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_P_3,		&sys->tk[TANK_03].rcp.TempP);
	
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_4,		&sys->tk[TANK_04].rcp.Temp);
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_L_4,		&sys->tk[TANK_04].rcp.TempL);
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_H_4,		&sys->tk[TANK_04].rcp.TempH);
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_P_4,		&sys->tk[TANK_04].rcp.TempP);
	
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_6,		&sys->tk[TANK_06].rcp.Temp);
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_L_6,		&sys->tk[TANK_06].rcp.TempL);
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_H_6,		&sys->tk[TANK_06].rcp.TempH);
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_P_6,		&sys->tk[TANK_06].rcp.TempP);
	
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_7,		&sys->tk[TANK_07].rcp.Temp);
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_L_7,		&sys->tk[TANK_07].rcp.TempL);
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_H_7,		&sys->tk[TANK_07].rcp.TempH);
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_P_7,		&sys->tk[TANK_07].rcp.TempP);
	
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_9,		&sys->tk[TANK_09].rcp.Temp);
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_L_9,		&sys->tk[TANK_09].rcp.TempL);
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_H_9,		&sys->tk[TANK_09].rcp.TempH);
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_P_9,		&sys->tk[TANK_09].rcp.TempP);
	
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_10,		&sys->tk[TANK_10].rcp.Temp);
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_L_10,	&sys->tk[TANK_10].rcp.TempL);
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_H_10,	&sys->tk[TANK_10].rcp.TempH);
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_P_10,	&sys->tk[TANK_10].rcp.TempP);

	
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_12,		&sys->tk[TANK_12].rcp.Temp);
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_L_12,	&sys->tk[TANK_12].rcp.TempL);
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_H_12,	&sys->tk[TANK_12].rcp.TempH);
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_P_12,	&sys->tk[TANK_12].rcp.TempP);
	
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_13,		&sys->tk[TANK_13].rcp.Temp);
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_L_13,	&sys->tk[TANK_13].rcp.TempL);
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_H_13,	&sys->tk[TANK_13].rcp.TempH);
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_P_13,	&sys->tk[TANK_13].rcp.TempP);
	
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_14,		&sys->tk[TANK_14].rcp.Temp);
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_L_14,	&sys->tk[TANK_14].rcp.TempL);
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_H_14,	&sys->tk[TANK_14].rcp.TempH);
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_P_14,	&sys->tk[TANK_14].rcp.TempP);
	
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_15,		&sys->tk[TANK_15].rcp.Temp);
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_L_15,	&sys->tk[TANK_15].rcp.TempL);
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_H_15,	&sys->tk[TANK_15].rcp.TempH);
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_P_15,	&sys->tk[TANK_15].rcp.TempP);
	
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_16,		&sys->tk[TANK_16].rcp.Temp);
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_L_16,	&sys->tk[TANK_16].rcp.TempL);
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_H_16,	&sys->tk[TANK_16].rcp.TempH);
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_P_16,	&sys->tk[TANK_16].rcp.TempP);
	
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_17,		&sys->tk[TANK_17].rcp.Temp);
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_L_17,	&sys->tk[TANK_17].rcp.TempL);
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_H_17,	&sys->tk[TANK_17].rcp.TempH);
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_P_17,	&sys->tk[TANK_17].rcp.TempP);
	
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_PH1,		&sys->tk[TANK_AUX_PH1].rcp.Temp);
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_L_PH1,	&sys->tk[TANK_AUX_PH1].rcp.TempL);
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_H_PH1,	&sys->tk[TANK_AUX_PH1].rcp.TempH);
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_P_PH1,	&sys->tk[TANK_AUX_PH1].rcp.TempP);
	
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_PH2,		&sys->tk[TANK_AUX_PH2].rcp.Temp);
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_L_PH2,	&sys->tk[TANK_AUX_PH2].rcp.TempL);
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_H_PH2,	&sys->tk[TANK_AUX_PH2].rcp.TempH);
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_P_PH2,	&sys->tk[TANK_AUX_PH2].rcp.TempP);
	
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_IN,		&sys->tk[TANK_AUX_IN].rcp.Temp);
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_L_IN,	&sys->tk[TANK_AUX_IN].rcp.TempL);
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_H_IN,	&sys->tk[TANK_AUX_IN].rcp.TempH);
	GetCtrlVal ( _pHNDL, PANEL_RCP_TMP_P_IN,	&sys->tk[TANK_AUX_IN].rcp.TempP);


	
	//  Dosing
	GetCtrlVal ( _pHNDL, PANEL_RCP_DOS_TEMP_02,	&sys->tk[TANK_02].rcp.DosTmp);
	GetCtrlVal ( _pHNDL, PANEL_RCP_DOS_02_AC1, 	&sys->tk[TANK_02].rcp.DosCH1);
	GetCtrlVal ( _pHNDL, PANEL_RCP_DOS_02_AC1_R,&sys->tk[TANK_02].rcp.DosCH1Run);
	GetCtrlVal ( _pHNDL, PANEL_RCP_DOS_02_AC1_S,&sys->tk[TANK_02].rcp.DosCH1Time);
	
	GetCtrlVal ( _pHNDL, PANEL_RCP_DOS_02_AC2,  &sys->tk[TANK_02].rcp.DosCH2);	
	GetCtrlVal ( _pHNDL, PANEL_RCP_DOS_02_AC2_R,&sys->tk[TANK_02].rcp.DosCH2Run);
	GetCtrlVal ( _pHNDL, PANEL_RCP_DOS_02_AC2_S,&sys->tk[TANK_02].rcp.DosCH2Time);
	
	GetCtrlVal ( _pHNDL, PANEL_RCP_DOS_02_AC3, 	&sys->tk[TANK_02].rcp.DosCH3);
	GetCtrlVal ( _pHNDL, PANEL_RCP_DOS_02_AC3_R,&sys->tk[TANK_02].rcp.DosCH3Run);
	GetCtrlVal ( _pHNDL, PANEL_RCP_DOS_02_AC3_S,&sys->tk[TANK_02].rcp.DosCH3Time);
	
	GetCtrlVal ( _pHNDL, PANEL_RCP_DRAIN_02_R,&sys->tk[TANK_02].rcp.DrainRun);
	GetCtrlVal ( _pHNDL, PANEL_RCP_DRAIN_02_T,&sys->tk[TANK_02].rcp.DrainTime);

	///////////////////////////////////////////////////////////////////////////////
	GetCtrlVal ( _pHNDL, PANEL_RCP_DOS_TEMP_04,	&sys->tk[TANK_04].rcp.DosTmp);
	GetCtrlVal ( _pHNDL, PANEL_RCP_DOS_04_AC1, 	&sys->tk[TANK_04].rcp.DosCH1);
	GetCtrlVal ( _pHNDL, PANEL_RCP_DOS_04_AC1_R,&sys->tk[TANK_04].rcp.DosCH1Run);
	GetCtrlVal ( _pHNDL, PANEL_RCP_DOS_04_AC1_S,&sys->tk[TANK_04].rcp.DosCH1Time);
	
	GetCtrlVal ( _pHNDL, PANEL_RCP_DOS_04_AC2,  &sys->tk[TANK_04].rcp.DosCH2);	
	GetCtrlVal ( _pHNDL, PANEL_RCP_DOS_04_AC2_R,&sys->tk[TANK_04].rcp.DosCH2Run);
	GetCtrlVal ( _pHNDL, PANEL_RCP_DOS_04_AC2_S,&sys->tk[TANK_04].rcp.DosCH2Time);
	
	GetCtrlVal ( _pHNDL, PANEL_RCP_DOS_04_AC3, 	&sys->tk[TANK_04].rcp.DosCH3);
	GetCtrlVal ( _pHNDL, PANEL_RCP_DOS_04_AC3_R,&sys->tk[TANK_04].rcp.DosCH3Run);
	GetCtrlVal ( _pHNDL, PANEL_RCP_DOS_04_AC3_S,&sys->tk[TANK_04].rcp.DosCH3Time);
	
	GetCtrlVal ( _pHNDL, PANEL_RCP_DOS_04_AC4, 	&sys->tk[TANK_04].rcp.DosCH4);
	GetCtrlVal ( _pHNDL, PANEL_RCP_DOS_04_AC4_R,&sys->tk[TANK_04].rcp.DosCH4Run);
	GetCtrlVal ( _pHNDL, PANEL_RCP_DOS_04_AC4_S,&sys->tk[TANK_04].rcp.DosCH4Time);
	
	GetCtrlVal ( _pHNDL, PANEL_RCP_DRAIN_04_R,&sys->tk[TANK_04].rcp.DrainRun);
	GetCtrlVal ( _pHNDL, PANEL_RCP_DRAIN_04_T,&sys->tk[TANK_04].rcp.DrainTime);

	////////////////////////////////////////////////////////////////////////////////
	GetCtrlVal ( _pHNDL, PANEL_RCP_DOS_TEMP_07,	&sys->tk[TANK_07].rcp.DosTmp);
	GetCtrlVal ( _pHNDL, PANEL_RCP_DOS_07_AC1, 	&sys->tk[TANK_07].rcp.DosCH1);
	GetCtrlVal ( _pHNDL, PANEL_RCP_DOS_07_AC1_R,&sys->tk[TANK_07].rcp.DosCH1Run);
	GetCtrlVal ( _pHNDL, PANEL_RCP_DOS_07_AC1_S,&sys->tk[TANK_07].rcp.DosCH1Time);
	
	GetCtrlVal ( _pHNDL, PANEL_RCP_DOS_07_AC2,  &sys->tk[TANK_07].rcp.DosCH2);	
	GetCtrlVal ( _pHNDL, PANEL_RCP_DOS_07_AC2_R,&sys->tk[TANK_07].rcp.DosCH2Run);
	GetCtrlVal ( _pHNDL, PANEL_RCP_DOS_07_AC2_S,&sys->tk[TANK_07].rcp.DosCH2Time);
	
	GetCtrlVal ( _pHNDL, PANEL_RCP_DOS_07_AC3, 	&sys->tk[TANK_07].rcp.DosCH3);
	GetCtrlVal ( _pHNDL, PANEL_RCP_DOS_07_AC3_R,&sys->tk[TANK_07].rcp.DosCH3Run);
	GetCtrlVal ( _pHNDL, PANEL_RCP_DOS_07_AC3_S,&sys->tk[TANK_07].rcp.DosCH3Time);
	
	GetCtrlVal ( _pHNDL, PANEL_RCP_DOS_07_AC4, 	&sys->tk[TANK_07].rcp.DosCH4);
	GetCtrlVal ( _pHNDL, PANEL_RCP_DOS_07_AC4_R,&sys->tk[TANK_07].rcp.DosCH4Run);
	GetCtrlVal ( _pHNDL, PANEL_RCP_DOS_07_AC4_S,&sys->tk[TANK_07].rcp.DosCH4Time);
	
	GetCtrlVal ( _pHNDL, PANEL_RCP_DRAIN_07_R,&sys->tk[TANK_07].rcp.DrainRun);
	GetCtrlVal ( _pHNDL, PANEL_RCP_DRAIN_07_T,&sys->tk[TANK_07].rcp.DrainTime);
	/////////////////////////////////////////////////////////////////////////////
	//GetCtrlVal ( _pHNDL, PANEL_RCP_DOS_TEMP_11,	&sys->tk[TANK_11].rcp.DosTmp);
	GetCtrlVal ( _pHNDL, PANEL_RCP_DOS_11_AC1, 	&sys->tk[TANK_11].rcp.DosCH1);
	GetCtrlVal ( _pHNDL, PANEL_RCP_DOS_11_AC1_R,&sys->tk[TANK_11].rcp.DosCH1Run);
	GetCtrlVal ( _pHNDL, PANEL_RCP_DOS_11_AC1_S,&sys->tk[TANK_11].rcp.DosCH1Time);
	
	GetCtrlVal ( _pHNDL, PANEL_RCP_DOS_11_AC2,  &sys->tk[TANK_11].rcp.DosCH2);	
	GetCtrlVal ( _pHNDL, PANEL_RCP_DOS_11_AC2_R,&sys->tk[TANK_11].rcp.DosCH2Run);
	GetCtrlVal ( _pHNDL, PANEL_RCP_DOS_11_AC2_S,&sys->tk[TANK_11].rcp.DosCH2Time);
	
	GetCtrlVal ( _pHNDL, PANEL_RCP_DOS_11_AC3, 	&sys->tk[TANK_11].rcp.DosCH3);
	GetCtrlVal ( _pHNDL, PANEL_RCP_DOS_11_AC3_R,&sys->tk[TANK_11].rcp.DosCH3Run);
	GetCtrlVal ( _pHNDL, PANEL_RCP_DOS_11_AC3_S,&sys->tk[TANK_11].rcp.DosCH3Time);
	
	GetCtrlVal ( _pHNDL, PANEL_RCP_DRAIN_11_R,&sys->tk[TANK_11].rcp.DrainRun);
	GetCtrlVal ( _pHNDL, PANEL_RCP_DRAIN_11_T,&sys->tk[TANK_11].rcp.DrainTime);
	
	////////////////////////////////////////////////////////////////////////////////
	GetCtrlVal ( _pHNDL, PANEL_RCP_PD_START, 	&sys->tk[TANK_04].rcp.PdStart);
	GetCtrlVal ( _pHNDL, PANEL_RCP_PD_CYCLE, 	&sys->tk[TANK_04].rcp.PdRun);
	GetCtrlVal ( _pHNDL, PANEL_RCP_PDRAIN_04, 	&sys->tk[TANK_04].rcp.PdVol);
	GetCtrlVal ( _pHNDL, PANEL_RCP_PDCH1_04, 	&sys->tk[TANK_04].rcp.PdCH1);
	GetCtrlVal ( _pHNDL, PANEL_RCP_PDCH2_04, 	&sys->tk[TANK_04].rcp.PdCH2);
	GetCtrlVal ( _pHNDL, PANEL_RCP_PDCH3_04, 	&sys->tk[TANK_04].rcp.PdCH3);
	GetCtrlVal ( _pHNDL, PANEL_RCP_PDCH4_04, 	&sys->tk[TANK_04].rcp.PdCH4);
	
	GetCtrlVal ( _pHNDL, PANEL_RCP_DRAINCH1_02, 	&sys->tk[TANK_02].rcp.DrainCH1);
	GetCtrlVal ( _pHNDL, PANEL_RCP_DRAINCH2_02, 	&sys->tk[TANK_02].rcp.DrainCH2);
	GetCtrlVal ( _pHNDL, PANEL_RCP_DRAINCH3_02, 	&sys->tk[TANK_02].rcp.DrainCH3);
	
	GetCtrlVal ( _pHNDL, PANEL_RCP_DRAINCH1_04, 	&sys->tk[TANK_04].rcp.DrainCH1);
	GetCtrlVal ( _pHNDL, PANEL_RCP_DRAINCH2_04, 	&sys->tk[TANK_04].rcp.DrainCH2);
	GetCtrlVal ( _pHNDL, PANEL_RCP_DRAINCH3_04, 	&sys->tk[TANK_04].rcp.DrainCH3);
	GetCtrlVal ( _pHNDL, PANEL_RCP_DRAINCH4_04, 	&sys->tk[TANK_04].rcp.DrainCH4);
	
	GetCtrlVal ( _pHNDL, PANEL_RCP_PD_START, 	&sys->tk[TANK_07].rcp.PdStart);
	GetCtrlVal ( _pHNDL, PANEL_RCP_PD_CYCLE, 	&sys->tk[TANK_07].rcp.PdRun);
	GetCtrlVal ( _pHNDL, PANEL_RCP_PDRAIN_07, 	&sys->tk[TANK_07].rcp.PdVol);
	GetCtrlVal ( _pHNDL, PANEL_RCP_PDCH1_07, 	&sys->tk[TANK_07].rcp.PdCH1);
	GetCtrlVal ( _pHNDL, PANEL_RCP_PDCH2_07, 	&sys->tk[TANK_07].rcp.PdCH2);
	GetCtrlVal ( _pHNDL, PANEL_RCP_PDCH3_07, 	&sys->tk[TANK_07].rcp.PdCH3);
	GetCtrlVal ( _pHNDL, PANEL_RCP_PDCH4_07, 	&sys->tk[TANK_07].rcp.PdCH4);
	
	GetCtrlVal ( _pHNDL, PANEL_RCP_DRAINCH1_07, 	&sys->tk[TANK_07].rcp.DrainCH1);
	GetCtrlVal ( _pHNDL, PANEL_RCP_DRAINCH2_07, 	&sys->tk[TANK_07].rcp.DrainCH2);
	GetCtrlVal ( _pHNDL, PANEL_RCP_DRAINCH3_07, 	&sys->tk[TANK_07].rcp.DrainCH3);
	GetCtrlVal ( _pHNDL, PANEL_RCP_DRAINCH4_07, 	&sys->tk[TANK_07].rcp.DrainCH4);
	
	GetCtrlVal ( _pHNDL, PANEL_RCP_DRAINCH1_11, 	&sys->tk[TANK_11].rcp.DrainCH1);
	GetCtrlVal ( _pHNDL, PANEL_RCP_DRAINCH2_11, 	&sys->tk[TANK_11].rcp.DrainCH2);
	GetCtrlVal ( _pHNDL, PANEL_RCP_DRAINCH3_11, 	&sys->tk[TANK_11].rcp.DrainCH3);
	
	GetCtrlVal ( _pHNDL, PANEL_RCP_PH1_TEMP_START, 	&sys->tk[TANK_AUX_PH1].rcp.StartTemp);
	GetCtrlVal ( _pHNDL, PANEL_RCP_PH1_TEMP_STOP, 	&sys->tk[TANK_AUX_PH1].rcp.StopTemp);
	GetCtrlVal ( _pHNDL, PANEL_RCP_PH2_TEMP_START, 	&sys->tk[TANK_AUX_PH2].rcp.StartTemp);
	GetCtrlVal ( _pHNDL, PANEL_RCP_PH2_TEMP_STOP, 	&sys->tk[TANK_AUX_PH2].rcp.StopTemp);
	
	GetCtrlVal ( _pHNDL, PANEL_RCP_HDIW5_RUN, 		&sys->tk[TANK_12].rcp.DrainRun);
	GetCtrlVal ( _pHNDL, PANEL_RCP_CHECKBOX_HDIW5, 	&sys->tk[TANK_12].rcp.DrainTempOn);
	
	///////////////////////////////////////////////////////////////////////////////////////////
	sys->tk[TANK_02].rcp.DosList[0] = ListCopy(dosList[0][0]);
	sys->tk[TANK_02].rcp.DosList[1] = ListCopy(dosList[0][1]);
	sys->tk[TANK_02].rcp.DosList[2] = ListCopy(dosList[0][2]);
	sys->tk[TANK_02].rcp.DosList[3] = ListCopy(dosList[0][3]);
	
	sys->tk[TANK_04].rcp.DosList[0] = ListCopy(dosList[1][0]);
	sys->tk[TANK_04].rcp.DosList[1] = ListCopy(dosList[1][1]);
	sys->tk[TANK_04].rcp.DosList[2] = ListCopy(dosList[1][2]);
	sys->tk[TANK_04].rcp.DosList[3] = ListCopy(dosList[1][3]);
	
	sys->tk[TANK_07].rcp.DosList[0] = ListCopy(dosList[2][0]);
	sys->tk[TANK_07].rcp.DosList[1] = ListCopy(dosList[2][1]);
	sys->tk[TANK_07].rcp.DosList[2] = ListCopy(dosList[2][2]);
	sys->tk[TANK_07].rcp.DosList[3] = ListCopy(dosList[2][3]);
	
	sys->tk[TANK_11].rcp.DosList[0] = ListCopy(dosList[3][0]);
	sys->tk[TANK_11].rcp.DosList[1] = ListCopy(dosList[3][1]);
	sys->tk[TANK_11].rcp.DosList[2] = ListCopy(dosList[3][2]);
	sys->tk[TANK_11].rcp.DosList[3] = ListCopy(dosList[3][3]);
	
	for(int i = 0; i < 4; i++)
	{
		TANK_ID tid = TANK_01;
		int carNumber=0;
		if(i == 0)
		{
			tid = TANK_02;
			carNumber = sys->tk[tid].carNumber;
		}
		else if(i == 1)
		{
			tid = TANK_04;
			carNumber = sys->tk[tid].carNumber;
			carNumber += sys->tk[tid+1].carNumber;
		}
		else if(i == 2)
		{
			tid = TANK_07;
			carNumber = sys->tk[tid].carNumber;
			carNumber += sys->tk[tid+1].carNumber;
		}
		else if(i == 3)
		{
			tid = TANK_11;
			carNumber = sys->tk[tid].carNumber;
		}
		
		for(int j = 0; j < 4; j++)
		{
			int total = ListNumItems(dosList[i][j]);
			for(int t = 0; t < total; t++)
			{
				DosSetting ds;
				ListGetItem (dosList[i][j], &ds, t+1);
				if(carNumber >= ds.round)
				{
					if(j == 0)
						sys->tk[tid].rcp.DosCH1 = ds.amount;
					else if(j == 1)
						sys->tk[tid].rcp.DosCH2 = ds.amount;
					else if(j == 2)
						sys->tk[tid].rcp.DosCH3 = ds.amount;
					else if(j == 3)
						sys->tk[tid].rcp.DosCH4 = ds.amount;
				
				}
			}
		}
	}
	
	

	// Write to PLC
	g_setupRecipe = 1;
	g_setupTemp = 1;
	
	char str[64];
	sprintf(str,"RecipeID:%d",sys->rcp.ID);
	SetCtrlVal ( panelHandle, PANEL_RECIPEID, str);
	
	for(int i = 0; i < PRO_TANK_NUM-1; i++) 
	{
		SetCtrlVal ( panelHandle, sys->tk[i].uiProcTM,	sys->tk[i].rcp.ProcTM);  
		//SetCtrlAttribute (panelHandle, sys->tk[i].uiTANK,ATTR_DIMMED,(sys->tk[i].rcp.ProcTM== 0));
	}
	/*
#ifndef SIMULATE 	
	while(g_setupRecipe == 1 || g_setupTemp == 1)
	{
		ProcessSystemEvents ();
		Delay(1);
	}
#endif
	*/
	sys->rcp.isReady = 1; 
	

	return 0;
}

int Enable_Setup_Page (int PanelHNDL, int _Mode)
{
	// ===================== Enable All Data
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_P_TM_01, ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_P_TM_02,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_P_TM_03,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_P_TM_04,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_P_TM_05,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_P_TM_06,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_P_TM_07,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_P_TM_08,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_P_TM_09,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_P_TM_10,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_P_TM_11,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_P_TM_12,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_P_TM_13,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_P_TM_14,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_P_TM_15,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_P_TM_16,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	
	
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_PRE_TM01, ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_PRE_TM02,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_PRE_TM03,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_PRE_TM04,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_PRE_TM05,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_PRE_TM06,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_PRE_TM07,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_PRE_TM08,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_PRE_TM09,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_PRE_TM10,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_PRE_TM11,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_PRE_TM12,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_PRE_TM13,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );	
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_PRE_TM14,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_PRE_TM15,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_PRE_TM16,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_2,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_3,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_4,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_6,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_7,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	//SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_8,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_9,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_10,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	//SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_11,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_12,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_13,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_14,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_15,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_16,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_17,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_PH1,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_PH2,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_IN,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_L_2,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_H_2,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_P_2,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_L_3,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_H_3,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_P_3,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_L_4,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_H_4,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_P_4,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_L_6,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_H_6,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_P_6,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_L_7,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_H_7,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_P_7,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_L_9,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_H_9,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_P_9,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_L_10,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_H_10,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_P_10,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_L_12,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_H_12,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_P_12,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_L_13,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_H_13,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_P_13,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_L_14,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_H_14,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_P_14,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_L_15,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_H_15,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_P_15,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_L_16,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_H_16,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_P_16,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_L_17,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_H_17,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_P_17,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_L_PH1,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_H_PH1,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_P_PH1,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_L_PH2,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_H_PH2,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_P_PH2,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_L_IN,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_H_IN,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TMP_P_IN,   ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );


	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DOS_TEMP_02,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DOS_TEMP_04,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DOS_TEMP_07,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	
	///////////
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DOS_02_AC1,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DOS_02_AC1_R,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DOS_02_AC1_S,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DOS_02_AC2,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DOS_02_AC2_R,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DOS_02_AC2_S,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DOS_02_AC3,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DOS_02_AC3_R,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DOS_02_AC3_S,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DRAIN_02_R,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DRAIN_02_T,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	
	///////////
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DOS_04_AC1,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DOS_04_AC1_R,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DOS_04_AC1_S,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DOS_04_AC2,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DOS_04_AC2_R,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DOS_04_AC2_S,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DOS_04_AC3,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DOS_04_AC3_R,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DOS_04_AC3_S,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DOS_04_AC4,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DOS_04_AC4_R,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DOS_04_AC4_S,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DRAIN_04_R,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DRAIN_04_T,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	///////////
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DOS_07_AC1,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DOS_07_AC1_R,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DOS_07_AC1_S,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DOS_07_AC2,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DOS_07_AC2_R,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DOS_07_AC2_S,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DOS_07_AC3,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DOS_07_AC3_R,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DOS_07_AC3_S,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DOS_07_AC4,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DOS_07_AC4_R,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DOS_07_AC4_S,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DRAIN_07_R,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DRAIN_07_T,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	///////////
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DOS_11_AC1,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DOS_11_AC1_R,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DOS_11_AC1_S,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DOS_11_AC2,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DOS_11_AC2_R,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DOS_11_AC2_S,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DOS_11_AC3,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DOS_11_AC3_R,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DOS_11_AC3_S,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DRAIN_11_R,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DRAIN_11_T,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );

	//////////////////////
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_PD_START,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_PD_CYCLE,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_PDRAIN_04,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_PDCH1_04,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_PDCH2_04,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_PDCH3_04,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_PDCH4_04,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_PDRAIN_07,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_PDCH1_07,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_PDCH2_07,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_PDCH3_07,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_PDCH4_07,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DRAINCH1_02,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DRAINCH2_02,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DRAINCH3_02,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DRAINCH1_04,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DRAINCH2_04,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DRAINCH3_04,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DRAINCH4_04,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );

	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DRAINCH1_07,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DRAINCH2_07,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DRAINCH3_07,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DRAINCH4_07,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DRAINCH1_11,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DRAINCH2_11,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DRAINCH3_11,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );

	//////////////////////////
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_PH1_TEMP_START,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_PH1_TEMP_STOP,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_PH2_TEMP_START,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_PH2_TEMP_STOP,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_HDIW5_RUN,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_CHECKBOX_HDIW5,  ATTR_CTRL_MODE, ((_Mode)?VAL_VALIDATE:VAL_INDICATOR) );
	
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_TABLE,  ATTR_DIMMED, ((_Mode)?0:1) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_ADD,  ATTR_DIMMED, ((_Mode)?0:1) );
	SetCtrlAttribute ( PanelHNDL, PANEL_RCP_DELETE,  ATTR_DIMMED, ((_Mode)?0:1) );

	return 0;
}

int SaveRecipeData(int panel,int ID)
{
	IniText iniHNDL={0};
	char path[300];
	char FileName[256];
	int Temp;
	double Temp1;
	unsigned char str[64];

	GetDir(path);
	Fmt(FileName,"%s<%s\\Recipe\\%d.txt", path, ID); 
	iniHNDL = Ini_New(TRUE);

	GetCtrlVal(panel, PANEL_RCP_P_TM_01, &Temp);
	Ini_PutInt(iniHNDL, "ProcTM", "P_TM_01", Temp);
	GetCtrlVal(panel, PANEL_RCP_P_TM_02, &Temp);
	Ini_PutInt(iniHNDL, "ProcTM", "P_TM_02", Temp);
	GetCtrlVal(panel, PANEL_RCP_P_TM_03, &Temp);
	Ini_PutInt(iniHNDL, "ProcTM", "P_TM_03", Temp);
	GetCtrlVal(panel, PANEL_RCP_P_TM_04, &Temp);
	Ini_PutInt(iniHNDL, "ProcTM", "P_TM_04", Temp);
	GetCtrlVal(panel, PANEL_RCP_P_TM_05, &Temp);
	Ini_PutInt(iniHNDL, "ProcTM", "P_TM_05", Temp);
	GetCtrlVal(panel, PANEL_RCP_P_TM_06, &Temp);
	Ini_PutInt(iniHNDL, "ProcTM", "P_TM_06", Temp);
	GetCtrlVal(panel, PANEL_RCP_P_TM_07, &Temp);
	Ini_PutInt(iniHNDL, "ProcTM", "P_TM_07", Temp);
	GetCtrlVal(panel, PANEL_RCP_P_TM_08, &Temp);
	Ini_PutInt(iniHNDL, "ProcTM", "P_TM_08", Temp);
	GetCtrlVal(panel, PANEL_RCP_P_TM_09, &Temp);
	Ini_PutInt(iniHNDL, "ProcTM", "P_TM_09", Temp);
	GetCtrlVal(panel, PANEL_RCP_P_TM_10, &Temp);
	Ini_PutInt(iniHNDL, "ProcTM", "P_TM_10", Temp);
	GetCtrlVal(panel, PANEL_RCP_P_TM_11, &Temp);
	Ini_PutInt(iniHNDL, "ProcTM", "P_TM_11", Temp);
	GetCtrlVal(panel, PANEL_RCP_P_TM_12, &Temp);
	Ini_PutInt(iniHNDL, "ProcTM", "P_TM_12", Temp);
	GetCtrlVal(panel, PANEL_RCP_P_TM_13, &Temp);
	Ini_PutInt(iniHNDL, "ProcTM", "P_TM_13", Temp);
	GetCtrlVal(panel, PANEL_RCP_P_TM_14, &Temp);
	Ini_PutInt(iniHNDL, "ProcTM", "P_TM_14", Temp);
	GetCtrlVal(panel, PANEL_RCP_P_TM_15, &Temp);
	Ini_PutInt(iniHNDL, "ProcTM", "P_TM_15", Temp);
	GetCtrlVal(panel, PANEL_RCP_P_TM_16, &Temp);
	Ini_PutInt(iniHNDL, "ProcTM", "P_TM_16", Temp);
	
	
	GetCtrlVal(panel, PANEL_RCP_PRE_TM01, &Temp);
	Ini_PutInt(iniHNDL, "PreTM", "PRE_TM01", Temp);
	GetCtrlVal(panel, PANEL_RCP_PRE_TM02, &Temp);
	Ini_PutInt(iniHNDL, "PreTM", "PRE_TM02", Temp);
	GetCtrlVal(panel, PANEL_RCP_PRE_TM03, &Temp);
	Ini_PutInt(iniHNDL, "PreTM", "PRE_TM03", Temp);
	GetCtrlVal(panel, PANEL_RCP_PRE_TM04, &Temp);
	Ini_PutInt(iniHNDL, "PreTM", "PRE_TM04", Temp);
	GetCtrlVal(panel, PANEL_RCP_PRE_TM05, &Temp);
	Ini_PutInt(iniHNDL, "PreTM", "PRE_TM05", Temp);
	GetCtrlVal(panel, PANEL_RCP_PRE_TM06, &Temp);
	Ini_PutInt(iniHNDL, "PreTM", "PRE_TM06", Temp);
	GetCtrlVal(panel, PANEL_RCP_PRE_TM07, &Temp);
	Ini_PutInt(iniHNDL, "PreTM", "PRE_TM07", Temp);
	GetCtrlVal(panel, PANEL_RCP_PRE_TM08, &Temp);
	Ini_PutInt(iniHNDL, "PreTM", "PRE_TM08", Temp);
	GetCtrlVal(panel, PANEL_RCP_PRE_TM09, &Temp);
	Ini_PutInt(iniHNDL, "PreTM", "PRE_TM09", Temp);
	GetCtrlVal(panel, PANEL_RCP_PRE_TM10, &Temp);
	Ini_PutInt(iniHNDL, "PreTM", "PRE_TM10", Temp);
	GetCtrlVal(panel, PANEL_RCP_PRE_TM11, &Temp);
	Ini_PutInt(iniHNDL, "PreTM", "PRE_TM11", Temp);
	GetCtrlVal(panel, PANEL_RCP_PRE_TM12, &Temp);
	Ini_PutInt(iniHNDL, "PreTM", "PRE_TM12", Temp);
	GetCtrlVal(panel, PANEL_RCP_PRE_TM13, &Temp);
	Ini_PutInt(iniHNDL, "PreTM", "PRE_TM13", Temp);
	GetCtrlVal(panel, PANEL_RCP_PRE_TM14, &Temp);
	Ini_PutInt(iniHNDL, "PreTM", "PRE_TM14", Temp);
	GetCtrlVal(panel, PANEL_RCP_PRE_TM15, &Temp);
	Ini_PutInt(iniHNDL, "PreTM", "PRE_TM15", Temp);
	GetCtrlVal(panel, PANEL_RCP_PRE_TM16, &Temp);
	Ini_PutInt(iniHNDL, "PreTM", "PRE_TM16", Temp);
	
	
	GetCtrlVal(panel, PANEL_RCP_TMP_2, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_2", Temp1);
	GetCtrlVal(panel, PANEL_RCP_TMP_3, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_3", Temp1);
	GetCtrlVal(panel, PANEL_RCP_TMP_4, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_4", Temp1);
	GetCtrlVal(panel, PANEL_RCP_TMP_6, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_6", Temp1);
	GetCtrlVal(panel, PANEL_RCP_TMP_7, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_7", Temp1);
	GetCtrlVal(panel, PANEL_RCP_TMP_9, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_9", Temp1);
	GetCtrlVal(panel, PANEL_RCP_TMP_10, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_10", Temp1);
	GetCtrlVal(panel, PANEL_RCP_TMP_12, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_12", Temp1);
	GetCtrlVal(panel, PANEL_RCP_TMP_13, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_13", Temp1);
	GetCtrlVal(panel, PANEL_RCP_TMP_14, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_14", Temp1);
	GetCtrlVal(panel, PANEL_RCP_TMP_15, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_15", Temp1);
	GetCtrlVal(panel, PANEL_RCP_TMP_16, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_16", Temp1);
	GetCtrlVal(panel, PANEL_RCP_TMP_17, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_17", Temp1);
	GetCtrlVal(panel, PANEL_RCP_TMP_PH1, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_PH1", Temp1);
	GetCtrlVal(panel, PANEL_RCP_TMP_PH2, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_PH2", Temp1);
	GetCtrlVal(panel, PANEL_RCP_TMP_IN, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_IN", Temp1);


	GetCtrlVal(panel, PANEL_RCP_TMP_L_2, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_L_2", Temp1);
	GetCtrlVal(panel, PANEL_RCP_TMP_H_2, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_H_2", Temp1);
	GetCtrlVal(panel, PANEL_RCP_TMP_P_2, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_P_2", Temp1);
	
	GetCtrlVal(panel, PANEL_RCP_TMP_L_3, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_L_3", Temp1);
	GetCtrlVal(panel, PANEL_RCP_TMP_H_3, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_H_3", Temp1);
	GetCtrlVal(panel, PANEL_RCP_TMP_P_3, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_P_3", Temp1);
	
	GetCtrlVal(panel, PANEL_RCP_TMP_L_4, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_L_4", Temp1);
	GetCtrlVal(panel, PANEL_RCP_TMP_H_4, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_H_4", Temp1);
	GetCtrlVal(panel, PANEL_RCP_TMP_P_4, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_P_4", Temp1);
	
	GetCtrlVal(panel, PANEL_RCP_TMP_L_6, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_L_6", Temp1);
	GetCtrlVal(panel, PANEL_RCP_TMP_H_6, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_H_6", Temp1);
	GetCtrlVal(panel, PANEL_RCP_TMP_P_6, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_P_6", Temp1);
	
	GetCtrlVal(panel, PANEL_RCP_TMP_L_7, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_L_7", Temp1);
	GetCtrlVal(panel, PANEL_RCP_TMP_H_7, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_H_7", Temp1);
	GetCtrlVal(panel, PANEL_RCP_TMP_P_7, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_P_7", Temp1);
	
	GetCtrlVal(panel, PANEL_RCP_TMP_L_9, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_L_9", Temp1);
	GetCtrlVal(panel, PANEL_RCP_TMP_H_9, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_H_9", Temp1);
	GetCtrlVal(panel, PANEL_RCP_TMP_P_9, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_P_9", Temp1);
	
	GetCtrlVal(panel, PANEL_RCP_TMP_L_10, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_L_10", Temp1);
	GetCtrlVal(panel, PANEL_RCP_TMP_H_10, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_H_10", Temp1);
	GetCtrlVal(panel, PANEL_RCP_TMP_P_10, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_P_10", Temp1);
	
	GetCtrlVal(panel, PANEL_RCP_TMP_L_12, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_L_12", Temp1);
	GetCtrlVal(panel, PANEL_RCP_TMP_H_12, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_H_12", Temp1);
	GetCtrlVal(panel, PANEL_RCP_TMP_P_12, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_P_12", Temp1);
	
	GetCtrlVal(panel, PANEL_RCP_TMP_L_13, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_L_13", Temp1);
	GetCtrlVal(panel, PANEL_RCP_TMP_H_13, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_H_13", Temp1);
	GetCtrlVal(panel, PANEL_RCP_TMP_P_13, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_P_13", Temp1);
	
	GetCtrlVal(panel, PANEL_RCP_TMP_L_14, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_L_14", Temp1);
	GetCtrlVal(panel, PANEL_RCP_TMP_H_14, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_H_14", Temp1);
	GetCtrlVal(panel, PANEL_RCP_TMP_P_14, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_P_14", Temp1);
	
	GetCtrlVal(panel, PANEL_RCP_TMP_L_15, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_L_15", Temp1);
	GetCtrlVal(panel, PANEL_RCP_TMP_H_15, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_H_15", Temp1);
	GetCtrlVal(panel, PANEL_RCP_TMP_P_15, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_P_15", Temp1);
	
	GetCtrlVal(panel, PANEL_RCP_TMP_L_16, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_L_16", Temp1);
	GetCtrlVal(panel, PANEL_RCP_TMP_H_16, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_H_16", Temp1);
	GetCtrlVal(panel, PANEL_RCP_TMP_P_16, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_P_16", Temp1);
	
	GetCtrlVal(panel, PANEL_RCP_TMP_L_17, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_L_17", Temp1);
	GetCtrlVal(panel, PANEL_RCP_TMP_H_17, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_H_17", Temp1);
	GetCtrlVal(panel, PANEL_RCP_TMP_P_17, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_P_17", Temp1);
	
	GetCtrlVal(panel, PANEL_RCP_TMP_L_PH1, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_L_PH1", Temp1);
	GetCtrlVal(panel, PANEL_RCP_TMP_H_PH1, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_H_PH1", Temp1);
	GetCtrlVal(panel, PANEL_RCP_TMP_P_PH1, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_P_PH1", Temp1);
	
	GetCtrlVal(panel, PANEL_RCP_TMP_L_PH2, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_L_PH2", Temp1);
	GetCtrlVal(panel, PANEL_RCP_TMP_H_PH2, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_H_PH2", Temp1);
	GetCtrlVal(panel, PANEL_RCP_TMP_P_PH2, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_P_PH2", Temp1);
	
	GetCtrlVal(panel, PANEL_RCP_TMP_L_IN, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_L_IN", Temp1);
	GetCtrlVal(panel, PANEL_RCP_TMP_H_IN, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_H_IN", Temp1);
	GetCtrlVal(panel, PANEL_RCP_TMP_P_IN, &Temp1);
	Ini_PutDouble(iniHNDL, "ProcTMP", "P_TMP_P_IN", Temp1);
	

	GetCtrlVal(panel, PANEL_RCP_DOS_TEMP_02, &Temp1);
	Ini_PutDouble(iniHNDL, "DOSTMP", "DOS_TMP_02", Temp1);
	GetCtrlVal(panel, PANEL_RCP_DOS_TEMP_04, &Temp1);
	Ini_PutDouble(iniHNDL, "DOSTMP", "DOS_TMP_04", Temp1);
	GetCtrlVal(panel, PANEL_RCP_DOS_TEMP_07, &Temp1);
	Ini_PutDouble(iniHNDL, "DOSTMP", "DOS_TMP_07", Temp1);
	

	////////////////////////////////////////////////
	GetCtrlVal(panel, PANEL_RCP_DOS_02_AC1, &Temp1);
	Ini_PutDouble(iniHNDL, "DOSAC", "DOS_02_AC1", Temp1);
	GetCtrlVal(panel, PANEL_RCP_DOS_02_AC1_R, &Temp);
	Ini_PutInt(iniHNDL, "DOSAC", "DOS_02_AC1_R", Temp);
	GetCtrlVal(panel, PANEL_RCP_DOS_02_AC1_S, &Temp);
	Ini_PutInt(iniHNDL, "DOSAC", "DOS_02_AC1_S", Temp);
	
	GetCtrlVal(panel, PANEL_RCP_DOS_02_AC2, &Temp1);
	Ini_PutDouble(iniHNDL, "DOSAC", "DOS_02_AC2", Temp1);
	GetCtrlVal(panel, PANEL_RCP_DOS_02_AC2_R, &Temp);
	Ini_PutInt(iniHNDL, "DOSAC", "DOS_02_AC2_R", Temp);
	GetCtrlVal(panel, PANEL_RCP_DOS_02_AC2_S, &Temp);
	Ini_PutInt(iniHNDL, "DOSAC", "DOS_02_AC2_S", Temp);
	
	GetCtrlVal(panel, PANEL_RCP_DOS_02_AC3, &Temp1);
	Ini_PutDouble(iniHNDL, "DOSAC", "DOS_02_AC3", Temp1);
	GetCtrlVal(panel, PANEL_RCP_DOS_02_AC3_R, &Temp);
	Ini_PutInt(iniHNDL, "DOSAC", "DOS_02_AC3_R", Temp);
	GetCtrlVal(panel, PANEL_RCP_DOS_02_AC3_S, &Temp);
	Ini_PutInt(iniHNDL, "DOSAC", "DOS_02_AC3_S", Temp);
	
	GetCtrlVal(panel, PANEL_RCP_DRAIN_02_R, &Temp);
	Ini_PutInt(iniHNDL, "DOSAC", "DRAIN_02_R", Temp);
	GetCtrlVal(panel, PANEL_RCP_DRAIN_02_T, &Temp);
	Ini_PutInt(iniHNDL, "DOSAC", "DRAIN_02_T", Temp);
	
	////////////////////////////////////////////////
	GetCtrlVal(panel, PANEL_RCP_DOS_04_AC1, &Temp1);
	Ini_PutDouble(iniHNDL, "DOSAC", "DOS_04_AC1", Temp1);
	GetCtrlVal(panel, PANEL_RCP_DOS_04_AC1_R, &Temp);
	Ini_PutInt(iniHNDL, "DOSAC", "DOS_04_AC1_R", Temp);
	GetCtrlVal(panel, PANEL_RCP_DOS_04_AC1_S, &Temp);
	Ini_PutInt(iniHNDL, "DOSAC", "DOS_04_AC1_S", Temp);
	
	GetCtrlVal(panel, PANEL_RCP_DOS_04_AC2, &Temp1);
	Ini_PutDouble(iniHNDL, "DOSAC", "DOS_04_AC2", Temp1);
	GetCtrlVal(panel, PANEL_RCP_DOS_04_AC2_R, &Temp);
	Ini_PutInt(iniHNDL, "DOSAC", "DOS_04_AC2_R", Temp);
	GetCtrlVal(panel, PANEL_RCP_DOS_04_AC2_S, &Temp);
	Ini_PutInt(iniHNDL, "DOSAC", "DOS_04_AC2_S", Temp);
	
	GetCtrlVal(panel, PANEL_RCP_DOS_04_AC3, &Temp1);
	Ini_PutDouble(iniHNDL, "DOSAC", "DOS_04_AC3", Temp1);
	GetCtrlVal(panel, PANEL_RCP_DOS_04_AC3_R, &Temp);
	Ini_PutInt(iniHNDL, "DOSAC", "DOS_04_AC3_R", Temp);
	GetCtrlVal(panel, PANEL_RCP_DOS_04_AC3_S, &Temp);
	Ini_PutInt(iniHNDL, "DOSAC", "DOS_04_AC3_S", Temp);
	
	GetCtrlVal(panel, PANEL_RCP_DOS_04_AC4, &Temp1);
	Ini_PutDouble(iniHNDL, "DOSAC", "DOS_04_AC4", Temp1);
	GetCtrlVal(panel, PANEL_RCP_DOS_04_AC4_R, &Temp);
	Ini_PutInt(iniHNDL, "DOSAC", "DOS_04_AC4_R", Temp);
	GetCtrlVal(panel, PANEL_RCP_DOS_04_AC4_S, &Temp);
	Ini_PutInt(iniHNDL, "DOSAC", "DOS_04_AC4_S", Temp);
	
	GetCtrlVal(panel, PANEL_RCP_DRAIN_04_R, &Temp);
	Ini_PutInt(iniHNDL, "DOSAC", "DRAIN_04_R", Temp);
	GetCtrlVal(panel, PANEL_RCP_DRAIN_04_T, &Temp);
	Ini_PutInt(iniHNDL, "DOSAC", "DRAIN_04_T", Temp);
	
	////////////////////////////////////////////////
	GetCtrlVal(panel, PANEL_RCP_DOS_07_AC1, &Temp1);
	Ini_PutDouble(iniHNDL, "DOSAC", "DOS_07_AC1", Temp1);
	GetCtrlVal(panel, PANEL_RCP_DOS_07_AC1_R, &Temp);
	Ini_PutInt(iniHNDL, "DOSAC", "DOS_07_AC1_R", Temp);
	GetCtrlVal(panel, PANEL_RCP_DOS_07_AC1_S, &Temp);
	Ini_PutInt(iniHNDL, "DOSAC", "DOS_07_AC1_S", Temp);
	
	GetCtrlVal(panel, PANEL_RCP_DOS_07_AC2, &Temp1);
	Ini_PutDouble(iniHNDL, "DOSAC", "DOS_07_AC2", Temp1);
	GetCtrlVal(panel, PANEL_RCP_DOS_07_AC2_R, &Temp);
	Ini_PutInt(iniHNDL, "DOSAC", "DOS_07_AC2_R", Temp);
	GetCtrlVal(panel, PANEL_RCP_DOS_07_AC2_S, &Temp);
	Ini_PutInt(iniHNDL, "DOSAC", "DOS_07_AC2_S", Temp);
	
	GetCtrlVal(panel, PANEL_RCP_DOS_07_AC3, &Temp1);
	Ini_PutDouble(iniHNDL, "DOSAC", "DOS_07_AC3", Temp1);
	GetCtrlVal(panel, PANEL_RCP_DOS_07_AC3_R, &Temp);
	Ini_PutInt(iniHNDL, "DOSAC", "DOS_07_AC3_R", Temp);
	GetCtrlVal(panel, PANEL_RCP_DOS_07_AC3_S, &Temp);
	Ini_PutInt(iniHNDL, "DOSAC", "DOS_07_AC3_S", Temp);
	
	GetCtrlVal(panel, PANEL_RCP_DOS_07_AC4, &Temp1);
	Ini_PutDouble(iniHNDL, "DOSAC", "DOS_07_AC4", Temp1);
	GetCtrlVal(panel, PANEL_RCP_DOS_07_AC4_R, &Temp);
	Ini_PutInt(iniHNDL, "DOSAC", "DOS_07_AC4_R", Temp);
	GetCtrlVal(panel, PANEL_RCP_DOS_07_AC4_S, &Temp);
	Ini_PutInt(iniHNDL, "DOSAC", "DOS_07_AC4_S", Temp);
	
	GetCtrlVal(panel, PANEL_RCP_DRAIN_07_R, &Temp);
	Ini_PutInt(iniHNDL, "DOSAC", "DRAIN_07_R", Temp);
	GetCtrlVal(panel, PANEL_RCP_DRAIN_07_T, &Temp);
	Ini_PutInt(iniHNDL, "DOSAC", "DRAIN_07_T", Temp);
	
	////////////////////////////////////////////////
	GetCtrlVal(panel, PANEL_RCP_DOS_11_AC1, &Temp1);
	Ini_PutDouble(iniHNDL, "DOSAC", "DOS_11_AC1", Temp1);
	GetCtrlVal(panel, PANEL_RCP_DOS_11_AC1_R, &Temp);
	Ini_PutInt(iniHNDL, "DOSAC", "DOS_11_AC1_R", Temp);
	GetCtrlVal(panel, PANEL_RCP_DOS_11_AC1_S, &Temp);
	Ini_PutInt(iniHNDL, "DOSAC", "DOS_11_AC1_S", Temp);
	
	GetCtrlVal(panel, PANEL_RCP_DOS_11_AC2, &Temp1);
	Ini_PutDouble(iniHNDL, "DOSAC", "DOS_11_AC2", Temp1);
	GetCtrlVal(panel, PANEL_RCP_DOS_11_AC2_R, &Temp);
	Ini_PutInt(iniHNDL, "DOSAC", "DOS_11_AC2_R", Temp);
	GetCtrlVal(panel, PANEL_RCP_DOS_11_AC2_S, &Temp);
	Ini_PutInt(iniHNDL, "DOSAC", "DOS_11_AC2_S", Temp);
	
	GetCtrlVal(panel, PANEL_RCP_DOS_11_AC3, &Temp1);
	Ini_PutDouble(iniHNDL, "DOSAC", "DOS_11_AC3", Temp1);
	GetCtrlVal(panel, PANEL_RCP_DOS_11_AC3_R, &Temp);
	Ini_PutInt(iniHNDL, "DOSAC", "DOS_11_AC3_R", Temp);
	GetCtrlVal(panel, PANEL_RCP_DOS_11_AC3_S, &Temp);
	Ini_PutInt(iniHNDL, "DOSAC", "DOS_11_AC3_S", Temp);
	
	GetCtrlVal(panel, PANEL_RCP_DRAIN_11_R, &Temp);
	Ini_PutInt(iniHNDL, "DOSAC", "DRAIN_11_R", Temp);
	GetCtrlVal(panel, PANEL_RCP_DRAIN_11_T, &Temp);
	Ini_PutInt(iniHNDL, "DOSAC", "DRAIN_11_T", Temp);
	
	
	////////////////////////////////////////////////////
	GetCtrlVal(panel, PANEL_RCP_PD_START, &Temp);
	Ini_PutInt(iniHNDL, "PDRAIN", "PD_START", Temp);
	GetCtrlVal(panel, PANEL_RCP_PD_CYCLE, &Temp);
	Ini_PutInt(iniHNDL, "PDRAIN", "PD_CYCLE", Temp);
	
	GetCtrlVal(panel, PANEL_RCP_PDRAIN_04, &Temp1);
	Ini_PutDouble(iniHNDL, "PDRAIN", "PDRAIN_04", Temp1);
	GetCtrlVal(panel, PANEL_RCP_PDCH1_04, &Temp1);
	Ini_PutDouble(iniHNDL, "PDRAIN", "PDCH1_04", Temp1);
	GetCtrlVal(panel, PANEL_RCP_PDCH2_04, &Temp1);
	Ini_PutDouble(iniHNDL, "PDRAIN", "PDCH2_04", Temp1);
	GetCtrlVal(panel, PANEL_RCP_PDCH3_04, &Temp1);
	Ini_PutDouble(iniHNDL, "PDRAIN", "PDCH3_04", Temp1);
	GetCtrlVal(panel, PANEL_RCP_PDCH4_04, &Temp1);
	Ini_PutDouble(iniHNDL, "PDRAIN", "PDCH4_04", Temp1);
	
	GetCtrlVal(panel, PANEL_RCP_DRAINCH1_02, &Temp1);
	Ini_PutDouble(iniHNDL, "DRAIN", "DRAINCH1_02", Temp1);
	GetCtrlVal(panel, PANEL_RCP_DRAINCH2_02, &Temp1);
	Ini_PutDouble(iniHNDL, "DRAIN", "DRAINCH2_02", Temp1);
	GetCtrlVal(panel, PANEL_RCP_DRAINCH3_02, &Temp1);
	Ini_PutDouble(iniHNDL, "DRAIN", "DRAINCH3_02", Temp1);
	
	GetCtrlVal(panel, PANEL_RCP_DRAINCH1_04, &Temp1);
	Ini_PutDouble(iniHNDL, "DRAIN", "DRAINCH1_04", Temp1);
	GetCtrlVal(panel, PANEL_RCP_DRAINCH2_04, &Temp1);
	Ini_PutDouble(iniHNDL, "DRAIN", "DRAINCH2_04", Temp1);
	GetCtrlVal(panel, PANEL_RCP_DRAINCH3_04, &Temp1);
	Ini_PutDouble(iniHNDL, "DRAIN", "DRAINCH3_04", Temp1);
	GetCtrlVal(panel, PANEL_RCP_DRAINCH4_04, &Temp1);
	Ini_PutDouble(iniHNDL, "DRAIN", "DRAINCH4_04", Temp1);
	
	///////////////////////
	GetCtrlVal(panel, PANEL_RCP_PDRAIN_07, &Temp1);
	Ini_PutDouble(iniHNDL, "PDRAIN", "PDRAIN_07", Temp1);
	GetCtrlVal(panel, PANEL_RCP_PDCH1_07, &Temp1);
	Ini_PutDouble(iniHNDL, "PDRAIN", "PDCH1_07", Temp1);
	GetCtrlVal(panel, PANEL_RCP_PDCH2_07, &Temp1);
	Ini_PutDouble(iniHNDL, "PDRAIN", "PDCH2_07", Temp1);
	GetCtrlVal(panel, PANEL_RCP_PDCH3_07, &Temp1);
	Ini_PutDouble(iniHNDL, "PDRAIN", "PDCH3_07", Temp1);
	GetCtrlVal(panel, PANEL_RCP_PDCH4_07, &Temp1);
	Ini_PutDouble(iniHNDL, "PDRAIN", "PDCH4_07", Temp1);
	
	GetCtrlVal(panel, PANEL_RCP_DRAINCH1_07, &Temp1);
	Ini_PutDouble(iniHNDL, "DRAIN", "DRAINCH1_07", Temp1);
	GetCtrlVal(panel, PANEL_RCP_DRAINCH2_07, &Temp1);
	Ini_PutDouble(iniHNDL, "DRAIN", "DRAINCH2_07", Temp1);
	GetCtrlVal(panel, PANEL_RCP_DRAINCH3_07, &Temp1);
	Ini_PutDouble(iniHNDL, "DRAIN", "DRAINCH3_07", Temp1);
	GetCtrlVal(panel, PANEL_RCP_DRAINCH4_07, &Temp1);
	Ini_PutDouble(iniHNDL, "DRAIN", "DRAINCH4_07", Temp1);
	
	GetCtrlVal(panel, PANEL_RCP_DRAINCH1_11, &Temp1);
	Ini_PutDouble(iniHNDL, "DRAIN", "DRAINCH1_11", Temp1);
	GetCtrlVal(panel, PANEL_RCP_DRAINCH2_11, &Temp1);
	Ini_PutDouble(iniHNDL, "DRAIN", "DRAINCH2_11", Temp1);
	GetCtrlVal(panel, PANEL_RCP_DRAINCH3_11, &Temp1);
	Ini_PutDouble(iniHNDL, "DRAIN", "DRAINCH3_11", Temp1);
	
	//////////////////////////////////////////
	GetCtrlVal(panel, PANEL_RCP_PH1_TEMP_START, &Temp1);
	Ini_PutDouble(iniHNDL, "PH", "PH1_TEMP_START", Temp1);
	GetCtrlVal(panel, PANEL_RCP_PH1_TEMP_STOP, &Temp1);
	Ini_PutDouble(iniHNDL, "PH", "PH1_TEMP_STOP", Temp1);
	
	GetCtrlVal(panel, PANEL_RCP_PH2_TEMP_START, &Temp1);
	Ini_PutDouble(iniHNDL, "PH", "PH2_TEMP_START", Temp1);
	GetCtrlVal(panel, PANEL_RCP_PH2_TEMP_STOP, &Temp1);
	Ini_PutDouble(iniHNDL, "PH", "PH2_TEMP_STOP", Temp1);

	
	GetCtrlVal(panel, PANEL_RCP_HDIW5_RUN, &Temp);
	Ini_PutInt(iniHNDL, "HDIW", "HDIW5_RUN", Temp);
	
	GetCtrlVal(panel, PANEL_RCP_CHECKBOX_HDIW5, &Temp);
	Ini_PutInt(iniHNDL, "HDIW", "CHECKBOX_HDIW5", Temp);
	

	GetCtrlVal(panel, PANEL_RCP_TEXTBOX, str);
	Ini_PutString(iniHNDL, "SYSTEM", "TEXTBOX", str);
	GetCtrlVal(panel, PANEL_RCP_RCIP_NAME, str);
	Ini_PutString(iniHNDL, "SYSTEM", "RCIP_NAME", str);	
	GetCtrlVal(panel, PANEL_RCP_RCIP_CREATE, str);
	Ini_PutString(iniHNDL, "SYSTEM", "RCIP_CREATE", str);
	GetCtrlVal(panel, PANEL_RCP_PARTID, str);
	Ini_PutString(iniHNDL, "SYSTEM", "PARTID", str);
	GetCtrlVal(panel, PANEL_RCP_LOTID, str);
	Ini_PutString(iniHNDL, "SYSTEM", "LOTID", str);
	GetCtrlVal(panel, PANEL_RCP_QTY, &Temp);
	Ini_PutInt(iniHNDL, "SYSTEM", "QTY", Temp);
	
	//////////////////////////////////////////////////////
	DosSetting ds;
	int total;
	Point cell;
	ListDispose(dosList[curTankId][curChId]);
	dosList[curTankId][curChId] = ListCreate(sizeof(DosSetting));
	GetNumTableRows(panel, PANEL_RCP_TABLE,&total);
	for(cell.y = 1;cell.y <= total;cell.y++)
	{
		cell.x = 1;
		GetTableCellAttribute(panel, PANEL_RCP_TABLE,cell,ATTR_CTRL_VAL, &ds.round);
		cell.x = 2;
		GetTableCellAttribute(panel, PANEL_RCP_TABLE,cell,ATTR_CTRL_VAL, &ds.amount);		
		ListInsertItem(dosList[curTankId][curChId], &ds, END_OF_LIST);
	}
	
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			int total = ListNumItems(dosList[i][j]);
			for(int t = 0; t < total; t++)
			{
				
				ListGetItem (dosList[i][j], &ds, t+1);
		
				char* tank[4] = {"Tank02","Tank04","Tank07","Tank11"};
				char name[32];

				Fmt(name,"%i_ROUND_CH%i_%s",t,j,tank[i]);
				Ini_PutInt(iniHNDL, "DosRound", name, ds.round);
				Fmt(name,"%i_AMOUNT_CH%i_%s",t,j,tank[i]);
				Ini_PutDouble(iniHNDL, "DosRound", name, ds.amount);
		
			}
		}
	}

	Ini_WriteToFile(iniHNDL, FileName);
	Ini_Dispose(iniHNDL);

	return 0;
}

int LoadRecipeData(int panel,int ID)
{
	IniText iniHNDL={0};
	char path[300];
	char FileName[256];
	int Temp;
	double Temp1;
	char *str;

	GetDir(path);
	Fmt(FileName,"%s<%s\\Recipe\\%d.txt", path, ID); 
	iniHNDL = Ini_New(TRUE);
	if (Ini_ReadFromFile(iniHNDL, FileName) < 0)
		return -1;

	Ini_GetInt(iniHNDL, "ProcTM", "P_TM_01", &Temp);
	SetCtrlVal(panel, PANEL_RCP_P_TM_01, Temp);
	Ini_GetInt(iniHNDL, "ProcTM", "P_TM_02", &Temp);
	SetCtrlVal(panel, PANEL_RCP_P_TM_02, Temp);
	Ini_GetInt(iniHNDL, "ProcTM", "P_TM_03", &Temp);
	SetCtrlVal(panel, PANEL_RCP_P_TM_03, Temp);
	Ini_GetInt(iniHNDL, "ProcTM", "P_TM_04", &Temp);
	SetCtrlVal(panel, PANEL_RCP_P_TM_04, Temp);
	Ini_GetInt(iniHNDL, "ProcTM", "P_TM_05", &Temp);
	SetCtrlVal(panel, PANEL_RCP_P_TM_05, Temp);
	Ini_GetInt(iniHNDL, "ProcTM", "P_TM_06", &Temp);
	SetCtrlVal(panel, PANEL_RCP_P_TM_06, Temp);
	Ini_GetInt(iniHNDL, "ProcTM", "P_TM_07", &Temp);
	SetCtrlVal(panel, PANEL_RCP_P_TM_07, Temp);
	Ini_GetInt(iniHNDL, "ProcTM", "P_TM_08", &Temp);
	SetCtrlVal(panel, PANEL_RCP_P_TM_08, Temp);
	Ini_GetInt(iniHNDL, "ProcTM", "P_TM_09", &Temp);
	SetCtrlVal(panel, PANEL_RCP_P_TM_09, Temp);
	Ini_GetInt(iniHNDL, "ProcTM", "P_TM_11", &Temp);
	SetCtrlVal(panel, PANEL_RCP_P_TM_11, Temp);
	Ini_GetInt(iniHNDL, "ProcTM", "P_TM_10", &Temp);
	SetCtrlVal(panel, PANEL_RCP_P_TM_10, Temp);
	Ini_GetInt(iniHNDL, "ProcTM", "P_TM_12", &Temp);
	SetCtrlVal(panel, PANEL_RCP_P_TM_12, Temp);
	Ini_GetInt(iniHNDL, "ProcTM", "P_TM_13", &Temp);
	SetCtrlVal(panel, PANEL_RCP_P_TM_13, Temp);
	Ini_GetInt(iniHNDL, "ProcTM", "P_TM_14", &Temp);
	SetCtrlVal(panel, PANEL_RCP_P_TM_14, Temp);
	Ini_GetInt(iniHNDL, "ProcTM", "P_TM_15", &Temp);
	SetCtrlVal(panel, PANEL_RCP_P_TM_15, Temp);
	Ini_GetInt(iniHNDL, "ProcTM", "P_TM_16", &Temp);
	SetCtrlVal(panel, PANEL_RCP_P_TM_16, Temp);
	
	
	Ini_GetInt(iniHNDL, "PreTM", "PRE_TM01", &Temp);
	SetCtrlVal(panel, PANEL_RCP_PRE_TM01, Temp);
	Ini_GetInt(iniHNDL, "PreTM", "PRE_TM02", &Temp);
	SetCtrlVal(panel, PANEL_RCP_PRE_TM02, Temp);
	Ini_GetInt(iniHNDL, "PreTM", "PRE_TM03", &Temp);
	SetCtrlVal(panel, PANEL_RCP_PRE_TM03, Temp);
	Ini_GetInt(iniHNDL, "PreTM", "PRE_TM04", &Temp);
	SetCtrlVal(panel, PANEL_RCP_PRE_TM04, Temp);
	Ini_GetInt(iniHNDL, "PreTM", "PRE_TM05", &Temp);
	SetCtrlVal(panel, PANEL_RCP_PRE_TM05, Temp);
	Ini_GetInt(iniHNDL, "PreTM", "PRE_TM06", &Temp);
	SetCtrlVal(panel, PANEL_RCP_PRE_TM06, Temp);
	Ini_GetInt(iniHNDL, "PreTM", "PRE_TM07", &Temp);
	SetCtrlVal(panel, PANEL_RCP_PRE_TM07, Temp);
	Ini_GetInt(iniHNDL, "PreTM", "PRE_TM08", &Temp);
	SetCtrlVal(panel, PANEL_RCP_PRE_TM08, Temp);
	Ini_GetInt(iniHNDL, "PreTM", "PRE_TM09", &Temp);
	SetCtrlVal(panel, PANEL_RCP_PRE_TM09, Temp);
	Ini_GetInt(iniHNDL, "PreTM", "PRE_TM10", &Temp);
	SetCtrlVal(panel, PANEL_RCP_PRE_TM10, Temp);
	Ini_GetInt(iniHNDL, "PreTM", "PRE_TM11", &Temp);
	SetCtrlVal(panel, PANEL_RCP_PRE_TM11, Temp);
	Ini_GetInt(iniHNDL, "PreTM", "PRE_TM12", &Temp);
	SetCtrlVal(panel, PANEL_RCP_PRE_TM12, Temp);
	Ini_GetInt(iniHNDL, "PreTM", "PRE_TM13", &Temp);
	SetCtrlVal(panel, PANEL_RCP_PRE_TM13, Temp);
	Ini_GetInt(iniHNDL, "PreTM", "PRE_TM14", &Temp);
	SetCtrlVal(panel, PANEL_RCP_PRE_TM14, Temp);
	Ini_GetInt(iniHNDL, "PreTM", "PRE_TM15", &Temp);
	SetCtrlVal(panel, PANEL_RCP_PRE_TM15, Temp);
	Ini_GetInt(iniHNDL, "PreTM", "PRE_TM16", &Temp);
	SetCtrlVal(panel, PANEL_RCP_PRE_TM16, Temp);
	

	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_2", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_2, Temp1);
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_3", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_3, Temp1);
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_4", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_4, Temp1);
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_6", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_6, Temp1);
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_7", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_7, Temp1);
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_9", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_9, Temp1);
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_10", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_10, Temp1);
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_12", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_12, Temp1);
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_13", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_13, Temp1);
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_14", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_14, Temp1);
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_15", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_15, Temp1);
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_16", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_16, Temp1);
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_17", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_17, Temp1);
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_PH1", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_PH1, Temp1);
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_PH2", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_PH2, Temp1);
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_IN", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_IN, Temp1);


	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_L_2", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_L_2, Temp1);
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_H_2", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_H_2, Temp1);
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_P_2", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_P_2, Temp1);
	
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_L_3", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_L_3, Temp1);
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_H_3", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_H_3, Temp1);
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_P_3", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_P_3, Temp1);
	
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_L_4", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_L_4, Temp1);
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_H_4", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_H_4, Temp1);
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_P_4", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_P_4, Temp1);
	
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_L_6", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_L_6, Temp1);
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_H_6", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_H_6, Temp1);
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_P_6", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_P_6, Temp1);
	
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_L_7", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_L_7, Temp1);
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_H_7", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_H_7, Temp1);
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_P_7", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_P_7, Temp1);
	
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_L_9", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_L_9, Temp1);
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_H_9", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_H_9, Temp1);
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_P_9", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_P_9, Temp1);
	
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_L_10", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_L_10, Temp1);
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_H_10", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_H_10, Temp1);
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_P_10", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_P_10, Temp1);
	
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_L_12", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_L_12, Temp1);
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_H_12", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_H_12, Temp1);
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_P_12", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_P_12, Temp1);
	
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_L_13", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_L_13, Temp1);
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_H_13", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_H_13, Temp1);
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_P_13", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_P_13, Temp1);
	
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_L_14", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_L_14, Temp1);
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_H_14", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_H_14, Temp1);
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_P_14", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_P_14, Temp1);
	
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_L_15", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_L_15, Temp1);
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_H_15", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_H_15, Temp1);
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_P_15", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_P_15, Temp1);
	
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_L_16", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_L_16, Temp1);
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_H_16", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_H_16, Temp1);
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_P_16", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_P_16, Temp1);
	
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_L_17", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_L_17, Temp1);
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_H_17", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_H_17, Temp1);
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_P_17", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_P_17, Temp1);
	
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_L_PH1", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_L_PH1, Temp1);
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_H_PH1", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_H_PH1, Temp1);
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_P_PH1", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_P_PH1, Temp1);
	
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_L_PH2", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_L_PH2, Temp1);
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_H_PH2", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_H_PH2, Temp1);
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_P_PH2", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_P_PH2, Temp1);
	
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_L_IN", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_L_IN, Temp1);
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_H_IN", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_H_IN, Temp1);
	Ini_GetDouble(iniHNDL, "ProcTMP", "P_TMP_P_IN", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_TMP_P_IN, Temp1);
	
	///////////////////////////////////////////////////////
	Ini_GetDouble(iniHNDL, "DOSTMP", "DOS_TMP_02", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_DOS_TEMP_02, Temp1);
	Ini_GetDouble(iniHNDL, "DOSTMP", "DOS_TMP_04", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_DOS_TEMP_04, Temp1);
	Ini_GetDouble(iniHNDL, "DOSTMP", "DOS_TMP_07", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_DOS_TEMP_07, Temp1);

	////////////////////////////////////////////////////////
	Ini_GetDouble(iniHNDL, "DOSAC", "DOS_02_AC1", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_DOS_02_AC1, Temp1);
	Ini_GetInt(iniHNDL, "DOSAC", "DOS_02_AC1_R", &Temp);
	SetCtrlVal(panel, PANEL_RCP_DOS_02_AC1_R, Temp);
	Ini_GetInt(iniHNDL, "DOSAC", "DOS_02_AC1_S", &Temp);
	SetCtrlVal(panel, PANEL_RCP_DOS_02_AC1_S, Temp);
	
	Ini_GetDouble(iniHNDL, "DOSAC", "DOS_02_AC2", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_DOS_02_AC2, Temp1);
	Ini_GetInt(iniHNDL, "DOSAC", "DOS_02_AC2_R", &Temp);
	SetCtrlVal(panel, PANEL_RCP_DOS_02_AC2_R, Temp);
	Ini_GetInt(iniHNDL, "DOSAC", "DOS_02_AC2_S", &Temp);
	SetCtrlVal(panel, PANEL_RCP_DOS_02_AC2_S, Temp);
	
	Ini_GetDouble(iniHNDL, "DOSAC", "DOS_02_AC3", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_DOS_02_AC3, Temp1);
	Ini_GetInt(iniHNDL, "DOSAC", "DOS_02_AC3_R", &Temp);
	SetCtrlVal(panel, PANEL_RCP_DOS_02_AC3_R, Temp);
	Ini_GetInt(iniHNDL, "DOSAC", "DOS_02_AC3_S", &Temp);
	SetCtrlVal(panel, PANEL_RCP_DOS_02_AC3_S, Temp);
	
	Ini_GetInt(iniHNDL, "DOSAC", "DRAIN_02_R", &Temp);
	SetCtrlVal(panel, PANEL_RCP_DRAIN_02_R, Temp);
	Ini_GetInt(iniHNDL, "DOSAC", "DRAIN_02_T", &Temp);
	SetCtrlVal(panel, PANEL_RCP_DRAIN_02_T, Temp);
	
	////////////////////////////////////////////////////////
	Ini_GetDouble(iniHNDL, "DOSAC", "DOS_04_AC1", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_DOS_04_AC1, Temp1);
	Ini_GetInt(iniHNDL, "DOSAC", "DOS_04_AC1_R", &Temp);
	SetCtrlVal(panel, PANEL_RCP_DOS_04_AC1_R, Temp);
	Ini_GetInt(iniHNDL, "DOSAC", "DOS_04_AC1_S", &Temp);
	SetCtrlVal(panel, PANEL_RCP_DOS_04_AC1_S, Temp);
	
	Ini_GetDouble(iniHNDL, "DOSAC", "DOS_04_AC2", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_DOS_04_AC2, Temp1);
	Ini_GetInt(iniHNDL, "DOSAC", "DOS_04_AC2_R", &Temp);
	SetCtrlVal(panel, PANEL_RCP_DOS_04_AC2_R, Temp);
	Ini_GetInt(iniHNDL, "DOSAC", "DOS_04_AC2_S", &Temp);
	SetCtrlVal(panel, PANEL_RCP_DOS_04_AC2_S, Temp);
	
	Ini_GetDouble(iniHNDL, "DOSAC", "DOS_04_AC3", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_DOS_04_AC3, Temp1);
	Ini_GetInt(iniHNDL, "DOSAC", "DOS_04_AC3_R", &Temp);
	SetCtrlVal(panel, PANEL_RCP_DOS_04_AC3_R, Temp);
	Ini_GetInt(iniHNDL, "DOSAC", "DOS_04_AC3_S", &Temp);
	SetCtrlVal(panel, PANEL_RCP_DOS_04_AC3_S, Temp);
	
	Ini_GetDouble(iniHNDL, "DOSAC", "DOS_04_AC4", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_DOS_04_AC4, Temp1);
	Ini_GetInt(iniHNDL, "DOSAC", "DOS_04_AC4_R", &Temp);
	SetCtrlVal(panel, PANEL_RCP_DOS_04_AC4_R, Temp);
	Ini_GetInt(iniHNDL, "DOSAC", "DOS_04_AC4_S", &Temp);
	SetCtrlVal(panel, PANEL_RCP_DOS_04_AC4_S, Temp);
	
	Ini_GetInt(iniHNDL, "DOSAC", "DRAIN_04_R", &Temp);
	SetCtrlVal(panel, PANEL_RCP_DRAIN_04_R, Temp);
	Ini_GetInt(iniHNDL, "DOSAC", "DRAIN_04_T", &Temp);
	SetCtrlVal(panel, PANEL_RCP_DRAIN_04_T, Temp);
	
	////////////////////////////////////////////////////////
	Ini_GetDouble(iniHNDL, "DOSAC", "DOS_07_AC1", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_DOS_07_AC1, Temp1);
	Ini_GetInt(iniHNDL, "DOSAC", "DOS_07_AC1_R", &Temp);
	SetCtrlVal(panel, PANEL_RCP_DOS_07_AC1_R, Temp);
	Ini_GetInt(iniHNDL, "DOSAC", "DOS_07_AC1_S", &Temp);
	SetCtrlVal(panel, PANEL_RCP_DOS_07_AC1_S, Temp);
	
	Ini_GetDouble(iniHNDL, "DOSAC", "DOS_07_AC2", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_DOS_07_AC2, Temp1);
	Ini_GetInt(iniHNDL, "DOSAC", "DOS_07_AC2_R", &Temp);
	SetCtrlVal(panel, PANEL_RCP_DOS_07_AC2_R, Temp);
	Ini_GetInt(iniHNDL, "DOSAC", "DOS_07_AC2_S", &Temp);
	SetCtrlVal(panel, PANEL_RCP_DOS_07_AC2_S, Temp);
	
	Ini_GetDouble(iniHNDL, "DOSAC", "DOS_07_AC3", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_DOS_07_AC3, Temp1);
	Ini_GetInt(iniHNDL, "DOSAC", "DOS_07_AC3_R", &Temp);
	SetCtrlVal(panel, PANEL_RCP_DOS_07_AC3_R, Temp);
	Ini_GetInt(iniHNDL, "DOSAC", "DOS_07_AC3_S", &Temp);
	SetCtrlVal(panel, PANEL_RCP_DOS_07_AC3_S, Temp);
	
	Ini_GetDouble(iniHNDL, "DOSAC", "DOS_07_AC4", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_DOS_07_AC4, Temp1);
	Ini_GetInt(iniHNDL, "DOSAC", "DOS_07_AC4_R", &Temp);
	SetCtrlVal(panel, PANEL_RCP_DOS_07_AC4_R, Temp);
	Ini_GetInt(iniHNDL, "DOSAC", "DOS_07_AC4_S", &Temp);
	SetCtrlVal(panel, PANEL_RCP_DOS_07_AC4_S, Temp);
	
	Ini_GetInt(iniHNDL, "DOSAC", "DRAIN_07_R", &Temp);
	SetCtrlVal(panel, PANEL_RCP_DRAIN_07_R, Temp);
	Ini_GetInt(iniHNDL, "DOSAC", "DRAIN_07_T", &Temp);
	SetCtrlVal(panel, PANEL_RCP_DRAIN_07_T, Temp);
	
	////////////////////////////////////////////////////////
	Ini_GetDouble(iniHNDL, "DOSAC", "DOS_11_AC1", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_DOS_11_AC1, Temp1);
	Ini_GetInt(iniHNDL, "DOSAC", "DOS_11_AC1_R", &Temp);
	SetCtrlVal(panel, PANEL_RCP_DOS_11_AC1_R, Temp);
	Ini_GetInt(iniHNDL, "DOSAC", "DOS_11_AC1_S", &Temp);
	SetCtrlVal(panel, PANEL_RCP_DOS_11_AC1_S, Temp);
	
	Ini_GetDouble(iniHNDL, "DOSAC", "DOS_11_AC2", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_DOS_11_AC2, Temp1);
	Ini_GetInt(iniHNDL, "DOSAC", "DOS_11_AC2_R", &Temp);
	SetCtrlVal(panel, PANEL_RCP_DOS_11_AC2_R, Temp);
	Ini_GetInt(iniHNDL, "DOSAC", "DOS_11_AC2_S", &Temp);
	SetCtrlVal(panel, PANEL_RCP_DOS_11_AC2_S, Temp);
	
	Ini_GetDouble(iniHNDL, "DOSAC", "DOS_11_AC3", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_DOS_11_AC3, Temp1);
	Ini_GetInt(iniHNDL, "DOSAC", "DOS_11_AC3_R", &Temp);
	SetCtrlVal(panel, PANEL_RCP_DOS_11_AC3_R, Temp);
	Ini_GetInt(iniHNDL, "DOSAC", "DOS_11_AC3_S", &Temp);
	SetCtrlVal(panel, PANEL_RCP_DOS_11_AC3_S, Temp);
	
	Ini_GetInt(iniHNDL, "DOSAC", "DRAIN_11_R", &Temp);
	SetCtrlVal(panel, PANEL_RCP_DRAIN_11_R, Temp);
	Ini_GetInt(iniHNDL, "DOSAC", "DRAIN_11_T", &Temp);
	SetCtrlVal(panel, PANEL_RCP_DRAIN_11_T, Temp);

	/////////////////////////////////////////////////
	Ini_GetInt(iniHNDL, "PDRAIN", "PD_START", &Temp);
	SetCtrlVal(panel, PANEL_RCP_PD_START, Temp);
	Ini_GetInt(iniHNDL, "PDRAIN", "PD_CYCLE", &Temp);
	SetCtrlVal(panel, PANEL_RCP_PD_CYCLE, Temp);
	

	Ini_GetDouble(iniHNDL, "PDRAIN", "PDRAIN_04", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_PDRAIN_04, Temp1);
	
	Ini_GetDouble(iniHNDL, "PDRAIN", "PDCH1_04", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_PDCH1_04, Temp1);
	Ini_GetDouble(iniHNDL, "PDRAIN", "PDCH2_04", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_PDCH2_04, Temp1);
	Ini_GetDouble(iniHNDL, "PDRAIN", "PDCH3_04", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_PDCH3_04, Temp1);
	Ini_GetDouble(iniHNDL, "PDRAIN", "PDCH4_04", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_PDCH4_04, Temp1);
	
	Ini_GetDouble(iniHNDL, "DRAIN", "DRAINCH1_02", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_DRAINCH1_02, Temp1);
	Ini_GetDouble(iniHNDL, "DRAIN", "DRAINCH2_02", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_DRAINCH2_02, Temp1);
	Ini_GetDouble(iniHNDL, "DRAIN", "DRAINCH3_02", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_DRAINCH3_02, Temp1);
	
	Ini_GetDouble(iniHNDL, "DRAIN", "DRAINCH1_04", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_DRAINCH1_04, Temp1);
	Ini_GetDouble(iniHNDL, "DRAIN", "DRAINCH2_04", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_DRAINCH2_04, Temp1);
	Ini_GetDouble(iniHNDL, "DRAIN", "DRAINCH3_04", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_DRAINCH3_04, Temp1);
	Ini_GetDouble(iniHNDL, "DRAIN", "DRAINCH4_04", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_DRAINCH4_04, Temp1);
	
	Ini_GetDouble(iniHNDL, "PDRAIN", "PDRAIN_07", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_PDRAIN_07, Temp1);
	
	Ini_GetDouble(iniHNDL, "PDRAIN", "PDCH1_07", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_PDCH1_07, Temp1);
	Ini_GetDouble(iniHNDL, "PDRAIN", "PDCH2_07", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_PDCH2_07, Temp1);
	Ini_GetDouble(iniHNDL, "PDRAIN", "PDCH3_07", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_PDCH3_07, Temp1);
	Ini_GetDouble(iniHNDL, "PDRAIN", "PDCH4_07", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_PDCH4_07, Temp1);
	
	Ini_GetDouble(iniHNDL, "DRAIN", "DRAINCH1_07", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_DRAINCH1_07, Temp1);
	Ini_GetDouble(iniHNDL, "DRAIN", "DRAINCH2_07", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_DRAINCH2_07, Temp1);
	Ini_GetDouble(iniHNDL, "DRAIN", "DRAINCH3_07", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_DRAINCH3_07, Temp1);
	Ini_GetDouble(iniHNDL, "DRAIN", "DRAINCH4_07", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_DRAINCH4_07, Temp1);
	
	Ini_GetDouble(iniHNDL, "DRAIN", "DRAINCH1_11", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_DRAINCH1_11, Temp1);
	Ini_GetDouble(iniHNDL, "DRAIN", "DRAINCH2_11", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_DRAINCH2_11, Temp1);
	Ini_GetDouble(iniHNDL, "DRAIN", "DRAINCH3_11", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_DRAINCH3_11, Temp1);
	
	/////////////////////////////////////////////
	Ini_GetDouble(iniHNDL, "PH", "PH1_TEMP_START", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_PH1_TEMP_START, Temp1);
	
	Ini_GetDouble(iniHNDL, "PH", "PH1_TEMP_STOP", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_PH1_TEMP_STOP, Temp1);
	
	Ini_GetDouble(iniHNDL, "PH", "PH2_TEMP_START", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_PH2_TEMP_START, Temp1);
	
	Ini_GetDouble(iniHNDL, "PH", "PH2_TEMP_STOP", &Temp1);
	SetCtrlVal(panel, PANEL_RCP_PH2_TEMP_STOP, Temp1);
	
	Ini_GetInt(iniHNDL, "HDIW", "HDIW5_RUN", &Temp);
	SetCtrlVal(panel, PANEL_RCP_HDIW5_RUN, Temp);
	
	Ini_GetInt(iniHNDL, "HDIW", "CHECKBOX_HDIW5", &Temp);
	SetCtrlVal(panel, PANEL_RCP_CHECKBOX_HDIW5, Temp);
	
	
	////////////////////////////////////

	Ini_GetPointerToString(iniHNDL, "SYSTEM", "TEXTBOX", &str);
	ResetTextBox(panel, PANEL_RCP_TEXTBOX, str);
	Ini_GetPointerToString(iniHNDL, "SYSTEM", "RCIP_NAME", &str);	
	SetCtrlVal(panel, PANEL_RCP_RCIP_NAME, str);
	Ini_GetPointerToString(iniHNDL, "SYSTEM", "RCIP_CREATE", &str);
	SetCtrlVal(panel, PANEL_RCP_RCIP_CREATE, str);
	Ini_GetPointerToString(iniHNDL, "SYSTEM", "PARTID", &str);
	SetCtrlVal(panel, PANEL_RCP_PARTID, str);
	Ini_GetPointerToString(iniHNDL, "SYSTEM", "LOTID", &str);
	SetCtrlVal(panel, PANEL_RCP_LOTID, str);
	Ini_GetInt(iniHNDL, "SYSTEM", "QTY", &Temp);
	SetCtrlVal(panel, PANEL_RCP_QTY, Temp);
	
	////////////////////////////////////////////////////////////
	DeleteTableRows(panel, PANEL_RCP_TABLE,1,-1);
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			for(int t = 0; t < 100; t++)
			{
				DosSetting ds;
				char* tank[4] = {"Tank02","Tank04","Tank07","Tank11"};
				char name[32];
				
				if(t == 0)
				{
					if(dosList[i][j] != 0 && dosList[i][j] != NULL) ListDispose(dosList[i][j]);
					dosList[i][j] = ListCreate(sizeof(DosSetting));
				}

				Fmt(name,"%i_ROUND_CH%i_%s",t,j,tank[i]);
				if(Ini_GetInt(iniHNDL, "DosRound", name, &ds.round) <= 0)
					break;
				Fmt(name,"%i_AMOUNT_CH%i_%s",t,j,tank[i]);
				if(Ini_GetDouble(iniHNDL, "DosRound", name, &ds.amount) <= 0)
					break;
				
				ListInsertItem(dosList[i][j], &ds, END_OF_LIST); 

				if(i == 0 && j == 0)
				{
					Point cell;
					cell.y = t+1;
					InsertTableRows (panel, PANEL_RCP_TABLE, cell.y, 1, VAL_USE_MASTER_CELL_TYPE); 
        			cell.x = 1;
        			SetTableCellAttribute(panel, PANEL_RCP_TABLE, cell, ATTR_CTRL_VAL, ds.round);
        			cell.x = 2;
					SetTableCellAttribute(panel, PANEL_RCP_TABLE, cell, ATTR_CTRL_VAL, ds.amount);	
				}
		
			}
		}
	}
	


//	Last_ID = ID;

	Ini_Dispose(iniHNDL);
	return 0;
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
			SetupRecipeBody(panel);
			
			ActionLog(RCP_SEL_ACT_EVENT,sys->rcp.ID,0,0,0,0);  
			
			RemovePopup(0);
			DiscardPanel (panel); 
			
			for(int i = 0; i < 4; i++)
				for(int j = 0; j < 4; j++)
					if(dosList[i][j] != 0 && dosList[i][j] != NULL) 
						ListDispose(dosList[i][j]);
			
			break;
	}
	return 0;
}

int CVICALLBACK Call_Recipe (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	static int Rcip_x00 = 0, Rcip_0x0 = 0, Rcip_00x = 0, RcipID = 0, _Modify = 0;
	int RecipeErr = 0;
	int Modify_Rcp;
	double cDate;
	char cDateSTR[32];
	// Exchange Data

	char path[100];
	char FileName[200];

	
	switch (event) {
	/// =================================== Recipe Saving
		case EVENT_COMMIT:
			switch (control) {
				case PANEL_RCP_RCIP_PAST:
					if(CheckAuth(OP_RCP) == 0)
						break;
					if (!ButtonConfirm (panel,control))		
						break;
					
					LoadRecipeData(panel,copyRecipeID);
					break;
					
				case PANEL_RCP_RCIP_COPY:
					if(CheckAuth(OP_RCP) == 0)
						break;
					
					GetCtrlVal ( panel, PANEL_RCP_RCIP_X00, &Rcip_x00);
					GetCtrlVal ( panel, PANEL_RCP_RCIP_0X0, &Rcip_0x0);
					GetCtrlVal ( panel, PANEL_RCP_RCIP_00X, &Rcip_00x);
					copyRecipeID = (Rcip_x00 * 100) + (Rcip_0x0 * 10) + (Rcip_00x);
					
					SetCtrlAttribute (panel, PANEL_RCP_RCIP_PAST, ATTR_DIMMED, 0);
					break;
					
				case PANEL_RCP_RCIP_SAVE:
					if(CheckAuth(OP_RCP) == 0)
						break;

					SetWaitCursor (1);
					ProcessSystemEvents();

					GetCurrentDateTime (&cDate);
					FormatDateTimeString (cDate, "%Y/%m/%d %H:%M:%S", cDateSTR, 20);
					SetCtrlVal (panel, PANEL_RCP_RCIP_CREATE, cDateSTR);
					
					// Save Recipe Data
					GetCtrlVal ( panel, PANEL_RCP_RCIP_X00, &Rcip_x00);
					GetCtrlVal ( panel, PANEL_RCP_RCIP_0X0, &Rcip_0x0);
					GetCtrlVal ( panel, PANEL_RCP_RCIP_00X, &Rcip_00x);
					RcipID = (Rcip_x00 * 100) + (Rcip_0x0 * 10) + (Rcip_00x);

					SaveRecipeData(panel,RcipID);
					
					// Disable All Data
					Enable_Setup_Page ( panel, 0);
					SetCtrlAttribute (panel, PANEL_RCP_RCIP_SAVE, ATTR_CTRL_VAL, 0);
					SetCtrlAttribute (panel, PANEL_RCP_RCIP_SAVE, ATTR_DIMMED, 1);
					SetWaitCursor (0);
					
					ActionLog(RCP_SAVE_ACT_EVENT,RcipID,0,0,0,0); 
					break;
			
	/// =================================== Recipe Confirm
				case PANEL_RCP_RCIP_MODIFY:
					if(CheckAuth(OP_RCP) == 0)
						break;
					
					SetWaitCursor (1);
					ProcessSystemEvents();
					GetCtrlVal ( panel , PANEL_RCP_RCIP_MODIFY, &_Modify);
					
					// Enable All Data
					Enable_Setup_Page ( panel, ((_Modify)?1:0) );
					SetCtrlAttribute (panel, PANEL_RCP_RCIP_SAVE, ATTR_DIMMED, 0);
					SetCtrlAttribute (panel, PANEL_RCP_RCIP_SAVE, ATTR_CTRL_VAL, 0);
					SetWaitCursor (0);

					GetCtrlVal ( panel, PANEL_RCP_RCIP_X00		,&Rcip_x00);
					GetCtrlVal ( panel, PANEL_RCP_RCIP_0X0		,&Rcip_0x0);
					GetCtrlVal ( panel, PANEL_RCP_RCIP_00X		,&Rcip_00x);
					Modify_Rcp = Rcip_x00*100 + Rcip_0x0*10 + Rcip_00x;

					//AddFuncLog("Modify Recipe");
					break;
		
	/// =================================== Recipe Select
				case PANEL_RCP_RING:
					GetCtrlVal ( panel, PANEL_RCP_RING, &RcipID);
					SetCtrlVal ( panel, PANEL_RCP_RCIP_X00, RcipID/100);
					SetCtrlVal ( panel, PANEL_RCP_RCIP_0X0, (RcipID/10)%10);
					SetCtrlVal ( panel, PANEL_RCP_RCIP_00X, RcipID%10);
				case PANEL_RCP_RCIP_X00:
				case PANEL_RCP_RCIP_0X0:
				case PANEL_RCP_RCIP_00X:
					SetWaitCursor (1);
					ProcessSystemEvents();

					GetCtrlVal ( panel, PANEL_RCP_RCIP_X00, &Rcip_x00);
					GetCtrlVal ( panel, PANEL_RCP_RCIP_0X0, &Rcip_0x0);
					GetCtrlVal ( panel, PANEL_RCP_RCIP_00X, &Rcip_00x);
					RcipID = (Rcip_x00 * 100) + (Rcip_0x0 * 10) + (Rcip_00x);
					
					// Reload Recipe
					if (LoadRecipeData(panel,RcipID) < 0)
					{
						DefaultPanel (panel);
						SetCtrlVal ( panel, PANEL_RCP_RCIP_X00, Rcip_x00);
						SetCtrlVal ( panel, PANEL_RCP_RCIP_0X0, Rcip_0x0);
						SetCtrlVal ( panel, PANEL_RCP_RCIP_00X, Rcip_00x);
					}

					
					// Disable All Data
					Enable_Setup_Page ( panel, 0);
					SetWaitCursor (0);
					break;
			}
			break;
			
		case EVENT_VAL_CHANGED:
			if ((control == PANEL_RCP_RCIP_X00) || (control == PANEL_RCP_RCIP_0X0) || (control == PANEL_RCP_RCIP_00X)) {
				SetCtrlAttribute (panel, PANEL_RCP_RCIP_SAVE, ATTR_DIMMED, 1);
			}
			break;
	}
	return 0;
}

void initRecipePanel(int panel)
{
	memset(dosList,0,sizeof(dosList));
	LoadRecipeData(panel,sys->rcp.ID);	
	
	SetCtrlVal ( panel, PANEL_RCP_RCIP_X00, sys->rcp.ID/100);
	SetCtrlVal ( panel, PANEL_RCP_RCIP_0X0, (sys->rcp.ID%100)/10);
	SetCtrlVal ( panel, PANEL_RCP_RCIP_00X, sys->rcp.ID%10);
	
    IniText iniHNDL={0};
    char path[300];
	char recipe_path[256];
	char Filepath[256];
    char FileName[256];
    int i = 0;

    GetDir(path);
    Fmt(recipe_path,"%s<%s\\Recipe\\*", path);  
	InsertListItem(panel,PANEL_RCP_RING,i++,"ID(Name--Date--Desc)",-1);
    if(GetFirstFile (recipe_path, 1, 0, 0, 0, 0, 0, FileName) == 0)
    {
        do
        {
            iniHNDL = Ini_New(TRUE);
            Fmt(Filepath,"%s<%s\\Recipe\\%s", path,FileName); 
            if (Ini_ReadFromFile(iniHNDL, Filepath) < 0)
            {
                Ini_Dispose(iniHNDL);
                continue;
            }

            char* p= strstr(FileName,".");
            if(p)
                *p = 0;
            
			char label[512];
            char* str;
			memset(label,0,512);
			Fmt(label,"%s[a]<%s(", FileName);
            Ini_GetPointerToString(iniHNDL, "SYSTEM", "RCIP_NAME", &str); 
			Fmt(label,"%s[a]<%s--", str);
            Ini_GetPointerToString(iniHNDL, "SYSTEM", "RCIP_CREATE", &str);
			Fmt(label,"%s[a]<%s--", str); 
            Ini_GetPointerToString(iniHNDL, "SYSTEM", "TEXTBOX", &str);
			Fmt(label,"%s[a]<%s)", str); 
			InsertListItem(panel,PANEL_RCP_RING,i++,label,atoi(FileName));
			
			Ini_Dispose(iniHNDL);
        }while(GetNextFile(FileName) == 0);
    }
	
}

int CVICALLBACK addDosingSetting (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			if(control == PANEL_RCP_ADD)
			{
				Point cell;
				GetActiveTableCell(panel, PANEL_RCP_TABLE,&cell);
				cell.y++;
				InsertTableRows (panel, PANEL_RCP_TABLE, cell.y, 1, VAL_USE_MASTER_CELL_TYPE); 
        		cell.x = 1;
        		SetTableCellAttribute(panel, PANEL_RCP_TABLE, cell, ATTR_CTRL_VAL, 0);
        		cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RCP_TABLE, cell, ATTR_CTRL_VAL, 0.0);
				
				//DosSetting ds;ds.amount=0;ds.round=0;
				//ListInsertItem(dosList[curTankId][curChId], &ds, cell.y);
			}
			else if(control == PANEL_RCP_DELETE)
			{

				Point cell;
				GetActiveTableCell(panel, PANEL_RCP_TABLE,&cell);
				DeleteTableRows(panel, PANEL_RCP_TABLE,cell.y,1); 
				//ListRemoveItem(dosList[curTankId][curChId], NULL, cell.y);
			}

			break;
	}
	return 0;
}

int CVICALLBACK changTankCh (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	int total;
	int rows = 0;
	Point cell;
	DosSetting ds;
	switch (event)
	{
		case EVENT_LEFT_CLICK:
			ListDispose(dosList[curTankId][curChId]);
			dosList[curTankId][curChId] = ListCreate(sizeof(DosSetting));
			GetNumTableRows(panel, PANEL_RCP_TABLE,&rows);
			for(cell.y = 1;cell.y <= rows;cell.y++)
			{
				cell.x = 1;
				GetTableCellAttribute(panel, PANEL_RCP_TABLE,cell,ATTR_CTRL_VAL, &ds.round);
				cell.x = 2;
				GetTableCellAttribute(panel, PANEL_RCP_TABLE,cell,ATTR_CTRL_VAL, &ds.amount);		
				ListInsertItem(dosList[curTankId][curChId], &ds, END_OF_LIST);
			}
			
			if(control == PANEL_RCP_DOS_02_AC1)
			{
				SetCtrlVal(panel,PANEL_RCP_TEXTMSG_205,"SC-H2O2");
				curTankId = 0;
				curChId = 0;
			}
			else if(control == PANEL_RCP_DOS_02_AC2)
			{
				SetCtrlVal(panel,PANEL_RCP_TEXTMSG_205,"SC-KOH");
				curTankId = 0;
				curChId = 1;
			}
			else if(control == PANEL_RCP_DOS_02_AC3)
			{
				SetCtrlVal(panel,PANEL_RCP_TEXTMSG_205,"SC-DIW");
				curTankId = 0;
				curChId = 2;
			}
			else if(control == PANEL_RCP_DOS_04_AC1)
			{
				SetCtrlVal(panel,PANEL_RCP_TEXTMSG_205,"TEX-A-IPA");
				curTankId = 1;
				curChId = 0;
			}
			else if(control == PANEL_RCP_DOS_04_AC2)
			{
				SetCtrlVal(panel,PANEL_RCP_TEXTMSG_205,"TEX-A-KOH");
				curTankId = 1;
				curChId = 1;
			}
			else if(control == PANEL_RCP_DOS_04_AC3)
			{
				SetCtrlVal(panel,PANEL_RCP_TEXTMSG_205,"TEX-A-DIW");
				curTankId = 1;
				curChId = 2;
			}
			else if(control == PANEL_RCP_DOS_04_AC4)
			{
				SetCtrlVal(panel,PANEL_RCP_TEXTMSG_205,"TEX-A-ADD");
				curTankId = 1;
				curChId = 3;
			}
			else if(control == PANEL_RCP_DOS_07_AC1)
			{
				SetCtrlVal(panel,PANEL_RCP_TEXTMSG_205,"TEX-B-IPA");
				curTankId = 2;
				curChId = 0;
			}
			else if(control == PANEL_RCP_DOS_07_AC2)
			{
				SetCtrlVal(panel,PANEL_RCP_TEXTMSG_205,"TEX-B-KOH");
				curTankId = 2;
				curChId = 1;
			}
			else if(control == PANEL_RCP_DOS_07_AC3)
			{
				SetCtrlVal(panel,PANEL_RCP_TEXTMSG_205,"TEX-B-DIW");
				curTankId = 2;
				curChId = 2;
			}
			else if(control == PANEL_RCP_DOS_07_AC4)
			{
				SetCtrlVal(panel,PANEL_RCP_TEXTMSG_205,"TEX-B-ADD");
				curTankId = 2;
				curChId = 3;
			}
			else if(control == PANEL_RCP_DOS_11_AC1)
			{
				SetCtrlVal(panel,PANEL_RCP_TEXTMSG_205,"HF-HF");
				curTankId = 3;
				curChId = 0;
			}
			else if(control == PANEL_RCP_DOS_11_AC2)
			{
				SetCtrlVal(panel,PANEL_RCP_TEXTMSG_205,"HF-HCL");
				curTankId = 3;
				curChId = 1;
			}
			else if(control == PANEL_RCP_DOS_11_AC3)
			{
				SetCtrlVal(panel,PANEL_RCP_TEXTMSG_205,"HF-DIW");
				curTankId = 3;
				curChId = 2;
			}
			
			////////////////////////////
			DeleteTableRows(panel, PANEL_RCP_TABLE,1,-1);
			total = ListNumItems(dosList[curTankId][curChId]);
			for(int t = 0; t < total; t++)
			{
				ListGetItem (dosList[curTankId][curChId], &ds, t+1);
				Point cell;
				cell.y = t+1;
				InsertTableRows (panel, PANEL_RCP_TABLE, cell.y, 1, VAL_USE_MASTER_CELL_TYPE); 
        		cell.x = 1;
        		SetTableCellAttribute(panel, PANEL_RCP_TABLE, cell, ATTR_CTRL_VAL, ds.round);
        		cell.x = 2;
				SetTableCellAttribute(panel, PANEL_RCP_TABLE, cell, ATTR_CTRL_VAL, ds.amount);	
			}
			
			/////////////////////////
			
			break;
	}
	return 0;
}

