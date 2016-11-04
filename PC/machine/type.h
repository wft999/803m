//==============================================================================
//
// Title:       type.h
// Purpose:     A short description of the interface.
//
// Created on:  2014/7/3 at ¤U¤È 12:58:59 by wang fang.
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
#define PLC_SYS_STATUS_ADD		1000
#define PLC_TK_STATUS_ADD		1000
#define PLC_RB_STATUS_ADD		1000
#define PLC_CMD_ADD				900
#define PLC_RCP_ADD				1000
#define PLC_ALARM_ADD			100
#define PLC_TK_POS_ADD			1000

#define MAX_SYS_STATUS_LEN 50
#define MAX_TK_STATUS_LEN 50 
#define MAX_RB_STATUS_LEN 50 
#define MAX_CMD_LEN 10 
#define MAX_RCP_LEN 100
#define MAX_ALARM_LEN 20
#define	MAX_TK_POS_LEN 12
		

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

struct Q02hReg {
	
	unsigned short	alarm[MAX_ALARM_LEN];
	unsigned short	alarmBak[MAX_ALARM_LEN];
	unsigned short	sysStatus[MAX_SYS_STATUS_LEN];
	unsigned short	tkStatus[MAX_TK_STATUS_LEN];
	unsigned short	rbStatus[MAX_RB_STATUS_LEN];
	
	unsigned short	cmdWrite[MAX_CMD_LEN];
	unsigned short	cmdRead[MAX_CMD_LEN];
	
	unsigned short	rcp[MAX_RCP_LEN];
	unsigned short	tkPos[MAX_TK_POS_LEN];
};


//==============================================================================
// RECIPE Types
typedef struct _DIW_RCP{
	unsigned short LoopCount;
	unsigned short uiRemain[6];
	unsigned short uiCmd[6];
	unsigned short spare[37];
	
}DIW_RCP;

typedef struct _RECIPE{
	unsigned char	comment[64];		// Recipe Name
	double	date;		// Recipe Name

	DIW_RCP rcpDIW1;
	DIW_RCP rcpACID;
	DIW_RCP rcpDIW2;
	DIW_RCP rcpKOH;
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
	double				iPrcTM[PRO_TANK_NUM];	
	double				oPrcTM[PRO_TANK_NUM];
	double				iPrcTemp[PRO_TANK_NUM];	
	double				oPrcTemp[PRO_TANK_NUM];
	
}CAR;


//==============================================================================
// TANK Types


typedef struct  _ROBOT_TANK{
	char				name[16];
	TANK_ID				tid;  //parent tank id
	
	CAR					car;

	
	
	//robot position
	double				xLock;
	double				xUnlock;		
	double				zDown;	
	
	double				xLock2;
	double				xUnlock2;		
	double				zDown2;	
		
	//ui data
	int					uiCAR;
	int					uiTM;
	
}RTANK;



typedef struct  _PROCESS_TANK{
	TANK_TYPE	type;
	
	

	//runtime data
	//TRECIPE				rcp;
	double				curTemp;
	double				tempData[TREND_DATA_LEN+10];
	unsigned int 		carNumber;
	int					Cond;
	int					isWashing;
	int					isMaking;
	int					isMMaking;
	
	//init data
	char				name[16];
	


	//UI data
	int					uiCARNum;
	int					uiProcTM;
	
	int					uiTANK;
	int					uiShut;
	int					uiHeat;
//	int					uiPump;
	
	int					uiBubble01;
	int					uiBubble02;
	int					uiBubble03;
	
}PTANK;

//==============================================================================
// robot Types		

typedef struct _ROBOT{
	ROBOT_ID			rid;


	int 				exitThread;
	CAR					car;
	long				curPosX;
	long				curPosY;
	
	//file data
	double				cleanPosH;		
	double				cleanPosV;	
	double				cleanLock;
	double 				safeHight;
	
	//config data
	double				UIPosTop;
	double				UIPosLow;
	double				UIPosLeft;
	double				UIPosRight;

	//output

	
	//tank data
	char				name[16];
	unsigned int 		firstRid;
	unsigned int 		lastRid;
	unsigned int		standbyRid;
	
}ROBOT;		

/////////////////////////////////////////////////////////////////////////////////
//system type

typedef struct _SETTING{
//	unsigned int 	akfUpPos;
//	unsigned int 	akfLowPos;
	
	unsigned int	ChuckLock_Check_Enabled;
	unsigned int 	Door_Interlock_Check_Enabled;
	unsigned int 	Exhaust_Check_Enabled;
	unsigned int 	SaveHeightMode_Enabled;
	unsigned int 	IPABufferMode_Enabled;
	
	float			down_delay_02;
	float			down_delay_03;
	float			down_delay_04;
	float			down_delay_05;
	float			down_delay_06;
	float			down_delay_07;
	float			down_delay_08;
	float			down_delay_09;
	float			down_delay_10;
	float			down_delay_11;
	float			down_delay_12;
	float			down_delay_13;
	float			down_delay_14;
	float			down_delay_15;
	
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
	
	unsigned short rcpId;
	
	
	SETTING		set;
	USER		user;

	
	char*		alarmDesc[MAX_ALARM_NUM];
	
}SYSTEM;


typedef struct _ALARM
{
	unsigned short	wid;
	unsigned short	rM;
	unsigned short	rMBak;
	
}ALARM;

typedef struct _ROBOT_EVENT
{
	ROBOT_ID			rid;
	ROBOT_EVENT_TYPE	etype;
//	ROBOT_COMMAND 		cmd;
	
}ROBOT_EVENT;

typedef struct _PLC_EVENT
{
	PLC_EVENT_TYPE	etype;

}PLC_EVENT;

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

typedef struct _PDRAIN_EVENT
{
	PDRAIN_TYPE			type;
	TANK_ID				tid;
	unsigned int		carNumber;
}PDRAIN_EVENT;

typedef struct _LOG{
	
	LOG_TYPE		type;
	double 			tm;
	
	union 
	{
		PLC_EVENT		plc;
		ALARM 			alarm;
		ROBOT_EVENT 	robot;
		CAR				car;
		ACT_EVENT		act;
		DOSING_EVENT	dos;
		PDRAIN_EVENT	pd;
	};
}LOG;



//==============================================================================
// External variables
extern SYSTEM* sys; 
//==============================================================================
// Global functions
int getBit(short data,int id) ;
void setBit(unsigned short* data,int id) ;


int ButtonConfirm (int _pnl, int _ctrl);
int SavePositionData(ROBOT_ID rbid, RTANK_ID rtid, POS_TYPE type);
int LoadPositionData(void);

//int isTankReady(TANK_ID tid);
void PutLogToQueue(LOG* log, int numItems);
void SendPcAlarm(int id,int onOff);
void bubble(int panel,unsigned int id,int up,int low,int r); 

int CheckAuth(OPERATION op);
void ActionLog(ACT_EVENT_TYPE etype,int data1,int data2,int data3,int data4,int data5);
void SaveSystem(void);
void DosingLog(DOSING_TYPE type,TANK_ID tid, unsigned int chem, unsigned int run);
void PDrainLog(PDRAIN_TYPE type,TANK_ID tid,  unsigned int carNumber);
int ReadTag(int id,int com);

#ifdef __cplusplus
    }
#endif

#endif  /* ndef __type_H__ */
