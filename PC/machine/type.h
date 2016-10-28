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
	unsigned short	rB[32];		// D0800-D0815 PLC -> PC
	unsigned short	wB[MAX_HANDSHAKE_LEN];	// D0900-D0915 PC -> PLC
	unsigned short	rX[48];		// D0500-D0535 INPUT
	unsigned short	rY[48];		// D0550-D0579 OUTPUT
	unsigned short	rM[48];		// D0600-D0631 ALARM
	unsigned short	rMBak[48];
	
	unsigned short  rD[80];		//D2000-D2080 
};

typedef struct _BIT{
	unsigned char wid;
	unsigned char bid;
}BIT;


//==============================================================================
// RECIPE Types
typedef struct _RECIPE{
	int				isReady;
	unsigned int	ID;				// Recipe ID
	unsigned char	Name[64];		// Recipe Name
	unsigned char	CrDay[64];		// Recipe Create Date
	
	unsigned char	PartNo[64];
	unsigned char	LotNo[64];
	unsigned char	CarNo[64];
	unsigned int	QTY_SET;	 
	
}RECIPE;

typedef struct _DosSetting{
	unsigned int	round;	
	double			amount; 
	
}DosSetting;

typedef struct _TRECIPE{

	unsigned int 	PreGetTM;
	unsigned int 	ProcTM;
	
	double			Temp;	
	double			TempL;	
	double			TempH;
	double			TempP;
	
	union{
		struct _CHEM_RCP{

			double			DosTmp;		
			double			DosCH1;
			unsigned int	DosCH1Run;
			unsigned int	DosCH1Time;
			double			DosCH2;
			unsigned int	DosCH2Run;
			unsigned int	DosCH2Time;
			double			DosCH3;
			unsigned int	DosCH3Run;
			unsigned int	DosCH3Time;
			double			DosCH4;
			unsigned int	DosCH4Run;
			unsigned int	DosCH4Time;
			
			unsigned int	DrainRun;
			unsigned int	DrainTime;
			double			DrainCH1;
			double			DrainCH2;
			double			DrainCH3;
			double			DrainCH4;
			
			unsigned int	PdStart;
			unsigned int	PdRun;
			double			PdVol;
			double			PdCH1;
			double			PdCH2;
			double			PdCH3;
			double			PdCH4;
			
			ListType 		DosList[4];
			
		};
		
		struct _DIW_RCP{
			unsigned int	DrainRun;
			unsigned int	DrainTempOn;

		};
		
		struct _PH_RCP{
			double	StartTemp;
			double	StopTemp;
		};
	};
	
}TRECIPE;
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
typedef struct _ROBOT_COMMAND{
	
	SYS_STATUS		status;
	COMMAND_TYPE	type;
	RTANK_ID		rid;
	TANK_ID			tid;
	
}ROBOT_COMMAND;

typedef struct  _ROBOT_TANK{
	char				name[16];
	TANK_ID				tid;  //parent tank id
	
	CAR					car;
	int					collisionLock;
	
	unsigned int		isOverlap;
	unsigned int		group;
	ROBOT_COMMAND		cmdBeforeGet;
	ROBOT_COMMAND		cmdAfterPut;
	int					putClean;
	int					putDirty;
	int					getDirty;
	
	BIT					hsFill;
	BIT					hsPermitGet;
	BIT					hsPermitPut;
	
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
	
//	union{
//		struct _ULD_TANK{
			BIT		xPosA1;
			BIT		xPosB1;	
			BIT		xPosA2;
			BIT		xPosB2;	
			BIT		xPosA3;
			BIT		xPosB3;
			BIT		xPosA4;
			BIT		xPosB4;	
			BIT		xPosA5;
			BIT		xPosB5;	
			BIT		xPosA6;
			BIT		xPosB6;
			
			BIT		xDoorClose;
			BIT		xDoorOpen;
	
			BIT		hsLDOnline;
			BIT		hsLDAuto;
			BIT		hsLDInit;
			BIT		hsLDDoor;

			BIT		hsLDLeft;
			BIT		hsLDRight;
			BIT		hsLDTop;
			BIT		hsLDBottom;
			BIT		hsLDTop2;
			BIT		hsLDBottom2;
//		};
//		struct _CHEM_TANK{
			
			int		lifeRun;
			double	lifeTime;
			int		autoMakeStep;
			
			double	tmAC1Dos;
			double	tmAC2Dos;
			double	tmAC3Dos;
			double	tmAC4Dos;
			
			unsigned int runAC1Dos;
			unsigned int runAC2Dos;
			unsigned int runAC3Dos;
			unsigned int runAC4Dos;
			
			unsigned int PdRun;
			
			BIT		hsAC1Dos;
			BIT		hsAC2Dos;
			BIT		hsAC3Dos;
			BIT		hsAC4Dos;
			
			BIT		hsMake;
			BIT		hsMMake;
			BIT		hsMakeEnd;
			BIT		hsPDrain;
			
			BIT		hsWash;
			BIT		hsWashEnd;
			
			BIT		hsPumpIn;
			
			BIT		xMakeAc1LevH;
			BIT		xMakeAc1LevL; 
			BIT		xMakeAc2LevH;
			BIT		xMakeAc2LevL;
	
			BIT		xDosAc1LevH;
			BIT		xDosAc1LevL; 
			BIT		xDosAc2LevH;
			BIT		xDosAc2LevL;
			BIT		xDosAc3LevH;
			BIT		xDosAc3LevL; 
			BIT		xDosAc4LevH;
			BIT		xDosAc4LevL;
			
			BIT		yPumpIn;
			
			BIT		yValveMakeAc1In;
			BIT		yValveMakeAc2In;
			BIT		yValveMakeAc3In;
			BIT		yValveMakeAc4In;

	
			BIT		yValveDosAc1In;
			BIT		yValveDosAc1Out;
			BIT		yValveDosAc2In;
			BIT		yValveDosAc2Out;
			BIT		yValveDosAc3In;
			BIT		yValveDosAc3Out;
			BIT		yValveDosAc4In;
			BIT		yValveDosAc4Out;
	
			//write to PLC
			double	MakeCH1;	// Chemical #1 ???
			double	MakeCH2;	// Chemical #2 ???
			double	MakeCH3;	// Chemical #3 ???
			double	MakeCH4;	// Chemical #3 ???
			
			double	MMakeCH1;	// Chemical #1 ???
			double	MMakeCH2;	// Chemical #2 ???
			double	MMakeCH3;	// Chemical #3 ???
			double	MMakeCH4;	// Chemical #3 ???
			
			//read from PLC
			unsigned int	DosingCountCH1;
			unsigned int	DosingCountCH2;
			unsigned int	DosingCountCH3;
			unsigned int	DosingCountCH4;
			
			unsigned int	MakeCountCH1;
			unsigned int	MakeCountCH2;
			unsigned int	MakeCountCH3;
			unsigned int	MakeCountCH4;
			
			unsigned int	MMakeCountCH1;
			unsigned int	MMakeCountCH2;
			unsigned int	MMakeCountCH3;
			unsigned int	MMakeCountCH4;
			
			unsigned int	PDrainVol;
			unsigned int	PMakeCountCH1;
			unsigned int	PMakeCountCH2;
			unsigned int	PMakeCountCH3;
			
			unsigned int	Flow;
			
			int				uiPumpIn;
//		};
		
//		struct _DIW_TANK{
			BIT				hsPHStart;
			BIT				hsDrainOn;
			BIT				hsAddWater;
//		};
		
//		struct _AKF_TANK{
			int		curAKFPos;
			BIT		hsAKFAuto;
			BIT		hsAKFHome;
			BIT		hsAKFUp;
			BIT		hsAKFBottom;
//		};
		
//		struct _DRY_TANK{
			BIT		hsCVOn;
			BIT		hsCVAuto;
			BIT		hsCVDoor;

//		};
		
//	};
	

	//runtime data
	TRECIPE				rcp;
	double				curTemp;
	double				tempData[TREND_DATA_LEN+10];
	unsigned int 		carNumber;
	int					Cond;
	int					isWashing;
	int					isMaking;
	int					isMMaking;
	
	//init data
	char				name[16];
	
	//handshake
	
	BIT					hsHeat;
	BIT					hsBubble;
	BIT					hsDown;
	BIT					hsDownEnd;
	BIT					hsPump;
	BIT					hsShutOpen;
	BIT					hsShutClose;
	BIT					hsDrain;
	
	
	//INPUT
	BIT					xTempH;
	BIT					xTempL;
	
	BIT					xLevUP;
	BIT					xLevHH;
	BIT					xLevH;
	BIT					xLevL;
	BIT					xLevLL;
	
	BIT					xShutOpen;
	BIT					xShutClose;

	
	//OUTPUT
	BIT					yBubble;
	BIT					yHeat;
	BIT					yPump;
	BIT					yValveDiwIn;
	BIT					yValveDown;
	BIT					yValveQDown;
	
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

	//runtime data
	int					isDirty;
	int					simStep;
	int 				write2Plc;
	ListType 			cmdList;
	int 				threadId;
	int					resetCommand; 

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

	//handshake data
	BIT 				hsBusyStatus;
	BIT 				hsHomeStatus;
	
	BIT 				hsSetCommandData;
	BIT 				hsAbortCommand;
	BIT 				hsHome;
	BIT 				hsGet;
	BIT 				hsPut;
	BIT 				hsMove;
	BIT 				hsBlow;
	BIT 				hsWash;
	
	BIT 				hsChuck;
	BIT 				hsTeach;
	
	BIT					hsSafeMode;
	
	BIT					hsJogSpdX;
	BIT 				hsJogPX;
	BIT 				hsJogNX;
	BIT					hsJogSpdY;
	BIT 				hsJogPY;
	BIT 				hsJogNY;
	
	BIT					hsFill;
	
	//output

	
	//tank data
	char				name[16];
	ListType 			rtkPriList;
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
	int			curTempTrendPos;
	int			EMOStatus;
	
	///
	BIT			hsChuckCheck;
	BIT			hsDoorCheck;
	BIT			hsExhaustCheck;
	BIT			hsSaveHeightMode;
	
	////
	BIT			hsWDT;
	BIT			hsAlarm;
	BIT			hsAuto;
	BIT			hsManu;
	BIT			hsEMGROBOT;
	BIT			hsEMGALL;
	BIT			hsRcpChange;
	BIT			hsEMOContine;
	
	BIT			hsAlarmBuzzOff;
	BIT			hsBuzzCmd;
	BIT			hsLight1;
	BIT			hsLight2;
	BIT			hsLight3;
	BIT			hsLight4;
	
	//BIT			hsFillChange;
	BIT			hsIPABufferMode;
	
	RECIPE		rcp;
	ROBOT		rb[ROBOT_NUM];
	RTANK		rtk[RTANK_NUM];
	PTANK		tk[PRO_TANK_NUM+AUX_TANK_NUM];

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
	ROBOT_COMMAND 		cmd;
	
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
void setBit(BIT bt);
void resetBit(BIT bt);
int test00Bit(BIT_TYPE type);
int testBit(BIT bt,BIT_TYPE type);
void ChangFillStatus(BIT bt,int fill);

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
