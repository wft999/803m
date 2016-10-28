//==============================================================================
//
// Title:       const.h
// Purpose:     A short description of the interface.
//
// Created on:  2014/7/5 at ¤W¤È 08:57:16 by wang fang.
// Copyright:   hua. All Rights Reserved.
//
//==============================================================================

#ifndef __const_H__
#define __const_H__

#ifdef __cplusplus
    extern "C" {
#endif

//==============================================================================
// Include files

#include "cvidef.h"

#define MAX_HANDSHAKE_LEN 100
//==============================================================================
// Constants
//#define SIMULATE
#define ROBOT_NUM 3
#define PRO_TANK_NUM 17
#define AUX_TANK_NUM 6
#define RTANK_NUM 26
		
#define MAX_COMMAND_NUM 10 
#define MAX_ALARM_NUM	600
		
#define TREND_DATA_LEN  100 

		
		
//ALARM 
#define PLC_ALARM_START 600		

#define PC_ALARM_WID		31
#define PCA_DOG_BID			0
#define PCA_PLC_BID			1
#define PCA_RKC_BID			2
#define PCA_TAG1_BID		3
#define PCA_TAG2_BID		4
#define PCA_SCRUN_BID		5
#define PCA_TEXARUN_BID		6
#define PCA_TEXBRUN_BID		7
#define PCA_HFRUN_BID		8
#define PCA_SCTIME_BID		9
#define PCA_TEXATIME_BID	10
#define PCA_TEXBTIME_BID	11
#define PCA_HFTIME_BID		12
//==============================================================================
// Types
typedef enum _BIT_TYPE{
	RB = 0,
	WB=1,
	RX=2,
	RY=3,
}BIT_TYPE;		
		
typedef enum _TANK_TYPE{
	TANK_ULD = 0,TANK_CHEM,TANK_DIW,TANK_HDIW,TANK_AKF,TANK_DRY
	
}TANK_TYPE;

typedef enum _ROBOT_ID{
	RB01 = 0,RB02,RB03
}ROBOT_ID;

typedef enum _POS_TYPE{
	TANK_POS = 0,CLEAN_POS,SAFE_POS
}POS_TYPE;

typedef enum _TANK_ID{
	TANK_01 = 0,
	TANK_02,
	TANK_03,
	TANK_04,
	TANK_05,
	TANK_06,
	TANK_07,
	TANK_08,
	TANK_09,
	TANK_10,
	TANK_11,
	TANK_12,
	TANK_13,
	TANK_14,
	TANK_15,
	TANK_16,
	TANK_17,
	TANK_AUX_PH1,
	TANK_AUX_PH2,
	TANK_AUX_IN,
	TANK_AUX_DIW,
	TANK_AUX_TEX,
	TANK_AUX_HF,
	TANK_UNKNOW
}TANK_ID;

typedef enum _RTANK_ID{
	RTK_01 = 0,
	RTK_02_01,
	RTK_02_02,
	RTK_03_01,
	RTK_03_02,
	RTK_04_01,
	RTK_04_02,
	RTK_05_01,
	RTK_05_02,
	RTK_06,
	RTK_07_01,
	RTK_07_02,
	RTK_08_01,
	RTK_08_02,
	RTK_09,
	RTK_10_01,
	RTK_10_02,
	RTK_11_01,
	RTK_11_02,
	RTK_12,
	RTK_13_01,
	RTK_13_02,
	RTK_14,
	RTK_15,
	RTK_16,
	RTK_17,
	RTK_UNKNOW
}RTANK_ID;

typedef enum _SYS_STATUS{
	UNKNOW_SYS_STATUS = 0,
	MANUAL_STATUS = 1,
	AUTO_STATUS = 2
}SYS_STATUS;

typedef enum _COMMAND_TYPE{
	UNKNOW_COMMAND = 0,
	GET_COMMAND = 1,
	PUT_COMMAND = 2,
	MOVE_COMMAND = 3,
	BLOW_COMMAND = 4,
	WASH_COMMAND = 5,
	HOME_COMMAND = 6
}COMMAND_TYPE;

typedef enum _LOG_TYPE{
	UNKNOW_LOG = 0,
	PLC_LOG,
	ALARM_LOG,
	ROBOT_LOG,
	DOSING_LOG,
	ACTION_LOG,
	CAR_LOG,
	PDRAIN_LOG
	
}LOG_TYPE;

typedef enum _ROBOT_EVENT_TYPE{
	UNKNOW_ROBOT_EVENT = 0,
	START_ROBOT_EVENT,
	FINISH_ROBOT_EVENT,
	CANCEL_ROBOT_EVENT
	
}ROBOT_EVENT_TYPE;

typedef enum _PLC_EVENT_TYPE{
	UNKNOW_PLC_EVENT = 0,
	RECIPE_PLC_EVENT,
	DOSING_PLC_EVENT,
	MAKE_PLC_EVENT,
	SETTING_PLC_EVENT,
	RBPOS_PLC_EVENT,
}PLC_EVENT_TYPE;

typedef enum _ACT_EVENT_TYPE{
	UNKNOW_ACT_EVENT = 0,
	TANK_WASH_ACT_EVENT,
	TANK_DOWN_ACT_EVENT,
	TANK_PUMP_ACT_EVENT,
	TANK_HEAT_ACT_EVENT,
	TANK_ADD_WATER_ACT_EVENT,
	TANK_SHUT_ACT_EVENT,
	TANK_BUBB_ACT_EVENT,
	TANK_CAR_ACT_EVENT,
	TANK_DRAIN_ACT_EVENT,
	
	TANK_MAKE_ACT_EVENT,
	TANK_MMAKE_ACT_EVENT,
	TANK_DOS_ACT_EVENT,
	
	AKF_HOME_ACT_EVENT,
	AKF_AUTO_ACT_EVENT,
	AKF_UP_ACT_EVENT,
	AKF_DOWN_ACT_EVENT,
	
	RCP_SAVE_ACT_EVENT,
	RCP_SEL_ACT_EVENT,
	
	ULD_DOOR_ACT_EVENT,
	ULD_INIT_ACT_EVENT,
	ULD_UP_ACT_EVENT,
	ULD_DOWN_ACT_EVENT,
	ULD_LEFT_ACT_EVENT,
	ULD_RIGHT_ACT_EVENT,
	
	CV_AUTO_ACT_EVENT,
	CV_ON_ACT_EVENT,
	
	SET_SAVE_ACT_EVENT,
	
	RB_UP_ACT_EVENT,
	RB_DOWN_ACT_EVENT,
	RB_LEFT_ACT_EVENT,
	RB_RIGHT_ACT_EVENT,
	
	RB_UUP_ACT_EVENT,
	RB_DDOWN_ACT_EVENT,
	RB_LLEFT_ACT_EVENT,
	RB_RRIGHT_ACT_EVENT,
	
	RB_TEACH_ACT_EVENT,
	RB_POS_SAVE_ACT_EVENT,
	
	RB_MOVE_ACT_EVENT,
	RB_HOME_ACT_EVENT,
	RB_GET_ACT_EVENT,
	RB_PUT_ACT_EVENT,
	RB_CLEAN_ACT_EVENT,
	RB_CHUCK_ACT_EVENT,
	RB_CAR_ACT_EVENT,
	
	USER_LOGIN_EVENT,
	USER_LOGOUT_EVENT,
	USER_EXIT_EVENT,
	
	SYS_START,
	SYS_MANUAL,
	SYS_AUTO
	
}ACT_EVENT_TYPE;

typedef enum _DOSING_TYPE{
	DOSING_BY_RUN = 0,
	DOSING_BY_TIME,
	DOSING_BY_MANUAL,
	PARTIAL_DRAIN,
	MANUAL_MIX_ACID,
	AUTO_MIX_ACID
}DOSING_TYPE;

typedef enum _PDRAIN_TYPE{
	PDRAIN_ALL = 0,
	PDRAIN_PART
}PDRAIN_TYPE;

typedef enum _USER_TYPE{
	UNKNOW_USER_TYPE = 0,
	OPE_USER,
	DEV_USER,
	PRO_USER,
	SUP_USER
}USER_TYPE;

typedef enum _OPERATION{
	OP_UNKONW = 0,
	OP_RCP,
	OP_TANK,
	OP_USER,
	OP_SET,
	OP_ROBOT,
	OP_EXIT
}OPERATION;
//==============================================================================
// External variables

//==============================================================================
// Global functions


#ifdef __cplusplus
    }
#endif

#endif  /* ndef __const_H__ */
