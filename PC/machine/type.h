//==============================================================================
//
// Title:       type.h
// Purpose:     A short description of the interface.
//
// Created on:  2014/7/3 at �U�� 12:58:59 by wang fang.
// Copyright:   hua. All Rights Reserved.
//
//==============================================================================

#ifndef __type_H__
#define __type_H__
  	

#ifdef __cplusplus
    extern "C" {
#endif

//==============================================================================
// Include files


#include "cvidef.h"
#include "toolbox.h"
#include "const.h"
		
//==============================================================================
// Constants
#define PLC_ALARM_ADD			100		
#define PLC_CMD_ADD				900
#define PLC_SYS_STATUS_ADD		1000 
#define PLC_RB_STATUS_ADD		1100
#define PLC_TK_STATUS_ADD		1200
		
		
#define PLC_RCP_ADD				1000
#define PLC_TK_POS_ADD			2000
		

#define MAX_TK_STATUS_LEN 	50 
#define MAX_RB_STATUS_LEN 	50 
#define MAX_CMD_LEN 		100 

#define MAX_ALARM_LEN 		20
#define	MAX_TK_POS_LEN 		12
		
#pragma pack(2)
//==============================================================================
// Types

//==============================================================================
// PLC Types	

union DatCnv
{
	int				_I32;
	unsigned int	_U32;
	unsigned short	_U16[2];
	short	int		_I16[2];
};

typedef struct _PLC_SYS_STATUS{
	unsigned short rcpid;
	unsigned short tk_remain_time[TANK_NUM];
	unsigned short tk_car_count[TANK_NUM];
	unsigned short tk_temp[TANK_NUM];
	unsigned short tk_bit[TANK_NUM];
	unsigned int   rb_h_pos[ROBOT_NUM];
	unsigned int   rb_v_pos[ROBOT_NUM];
	unsigned short sys_bit;	
}PLC_SYS_STATUS;

typedef struct _PLC_AXIS_STATUS{
	int cur_pos[2];
	int cur_speed[2];
	int address[2];
 	int speed[2];
	short error_code[2];
	short alarm_code[2];
	short serve_alarm_code[2];
	short action_status[2];
	short status[2];
	short xy_bit[2];
	short status_bit[2];
	
}PLC_AXIS_STATUS;

typedef struct _PLC_RB_STATUS{
	PLC_AXIS_STATUS axis;
	
	short rb_state;
	short target_tid;
	short cur_tid;
	short from_tid;
	short to_tid;
	short rb_bit;
	
}PLC_RB_STATUS;

struct Q02hReg {
	
	unsigned short	alarm[MAX_ALARM_LEN];
	unsigned short	alarmBak[MAX_ALARM_LEN];
	PLC_SYS_STATUS	sysStatus;
	unsigned short	tkStatus[MAX_TK_STATUS_LEN];
	PLC_RB_STATUS	rbStatus;
	
	unsigned short	cmdWrite[MAX_CMD_LEN];
	unsigned short	cmdRead[MAX_CMD_LEN];
	unsigned short	tkPos[MAX_TK_POS_LEN];
};


//==============================================================================
// RECIPE Types
typedef struct _DIW_RCP{
	unsigned short proc_time;
	unsigned short take_weight;		
	unsigned short next_tank;		
	
	unsigned short LoopCount;
	unsigned short uiRemain[6];
	unsigned short uiCmd[6];
	
	unsigned short spare[34]; 
	
}DIW_RCP;

typedef struct _ACID_RCP{
	unsigned short proc_time;
	unsigned short take_weight;		
	unsigned short next_tank;	
	
	unsigned short spare[47]; 
	
}ACID_RCP;

typedef struct _KOH_RCP{
	unsigned short proc_time;
	unsigned short take_weight;		
	unsigned short next_tank;
	
	unsigned short spare[47]; 
	
}KOH_RCP;

typedef struct _SYS_RCP{
	unsigned short proc_time;
	unsigned short take_weight;		
	unsigned short next_tank;
	
	unsigned short id;
	unsigned short spare[46]; 
	
}SYS_RCP;


typedef struct _RECIPE{
	unsigned char	comment[64];		// Recipe Name
	double	date;		// Recipe Name

	SYS_RCP rcpSYS;
	DIW_RCP rcpDIW1;
	ACID_RCP rcpACID;
	DIW_RCP rcpDIW2;
	KOH_RCP rcpKOH;
	DIW_RCP rcpDIW3;
	
}RECIPE;


//==============================================================================
// CAR Types

typedef struct _CAR{
	unsigned char   	tag1[16];
	unsigned char   	tag2[16];
	unsigned int		isTexured;
	unsigned int		sn;
	TANK_ID				curTank;
	double				iPrcTM[TANK_NUM];	
	double				oPrcTM[TANK_NUM];
	double				iPrcTemp[TANK_NUM];	
	double				oPrcTemp[TANK_NUM];
	
}CAR;


//==============================================================================
// TANK Types
typedef struct _TANK_POS{
	int		xLock;
	int		xUnlock;		
	int		zDown;	
	
	int		xLock2;
	int		xUnlock2;		
	int		zDown2;	
}TANK_POS;

//==============================================================================
// robot Types		



/////////////////////////////////////////////////////////////////////////////////
//system type

typedef struct _SETTING{
	
	unsigned int	ChuckLock_Check_Enabled;
	unsigned int 	Door_Interlock_Check_Enabled;
	unsigned int 	Exhaust_Check_Enabled;
	unsigned int 	SaveHeightMode_Enabled;
	
	OPERATION  auth[5][6];
}SETTING;

typedef struct _USER{
	char		name[32];
	USER_TYPE	type;
	char		pass[32];
	
}USER;

/////////////////////////////////////////////////////////////////////////////////
//system type
typedef struct _MACHINE{
	int			isAuto;
	int			isManual;
	int			curTempTrendPos;
	
	TANK_POS	tkPos[TANK_NUM];

	SETTING		set;
	USER		user;
	RECIPE 		rcp;
	
	char*		alarmDesc[MAX_ALARM_NUM];
	
}SYSTEM;


typedef struct _ALARM
{
	unsigned short	wid;
	unsigned short	rM;
	unsigned short	rMBak;
	
}ALARM;


typedef struct _ACT_EVENT
{
	ACT_EVENT_TYPE		etype;
	int					data1;
	int					data2;
	int					data3;
	int					data4;
	int					data5;
}ACT_EVENT;

typedef struct _DOSING_EVENT
{
	DOSING_TYPE			type;
	TANK_ID				tid;
	unsigned int		chem;
	unsigned int		carNumber;
}DOSING_EVENT;


typedef struct _LOG{
	
	LOG_TYPE		type;
	double 			tm;
	
	union 
	{
		ALARM 			alarm;
		CAR				car;
		ACT_EVENT		act;
		DOSING_EVENT	dos;
	};
}LOG;



//==============================================================================
// External variables
extern SYSTEM* sys; 
extern struct Q02hReg Q2h;
//==============================================================================
// Global functions
int getBit(short data,int id) ;
void setBit(unsigned short* data,int id) ;
int writeCommand(int len);
void SendPcAlarm(int id,int onOff);


int CheckAuth(OPERATION op);

void PutLogToQueue(LOG* log, int numItems); 
void ActionLog(ACT_EVENT_TYPE etype,int data1,int data2,int data3,int data4,int data5);
void DosingLog(DOSING_TYPE type,TANK_ID tid, unsigned int chem, unsigned int run);


#ifdef __cplusplus
    }
#endif

#endif  /* ndef __type_H__ */
