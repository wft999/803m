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


//==============================================================================
// Constants
#define  CMD_ROBOT					10
#define  CMD_SAVE_TK_POS			40
#define  CMD_SAVE_TK_POS_PC			50
#define  CMD_SAVE_TK_RCP			60
#define  CMD_TANK					200 		
#define  CMD_SYS					1000
		
		
#define MAX PLC_ERR_COUNT 5 
		
//#define SIMULATE
#define ROBOT_NUM 1
#define TANK_NUM 7		

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
	
		
typedef enum _ROBOT_ID{
	RB01 = 0,RB02,RB03
}ROBOT_ID;

typedef enum _TANK_ID{
	TANK_ILD = 0,
	TANK_DIW1,
	TANK_ACID,
	TANK_DIW2,
	TANK_KOH,
	TANK_DIW3,
	TANK_ULD
}TANK_ID;

typedef enum _LOG_TYPE{
	UNKNOW_LOG = 0,
	ALARM_LOG,
	DOSING_LOG,
	ACTION_LOG,
	CAR_LOG
}LOG_TYPE;

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
