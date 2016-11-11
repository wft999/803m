//==============================================================================
//
// Title:       plc.c
// Purpose:     A short description of the implementation.
//
// Created on:  2014/7/3 at と 01:07:52 by wang fang.
// Copyright:   hua. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files

#include <userint.h>
#include <utility.h>
#include <formatio.h>


#include "MiQPLC.h"
#include "type.h"

//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// Static global variables
static MiPLC mPLC;
static int plcLock;
//==============================================================================
// Static functions

//==============================================================================
// Global variables
int plcErrorCount = 0;

struct Q02hReg Q2h;

const unsigned short bitvalue[] = {0x0001,0x0002,0x0004,0x0008,0x0010,0x0020,0x0040,0x0080,0x0100,0x0200,0x0400,0x0800,0x1000,0x2000,0x4000,0x8000};
//==============================================================================
// Global functions

void setBit(unsigned short* data,int id)
{
	*data |= bitvalue[id];	
}

int getBit(short data,int id)
{
	if(data & bitvalue[id])
		return 1;
	else
		return 0;
}

void SendPcAlarm(int id,int onOff)
{
	LOG log;
	log.type = ALARM_LOG;
	GetCurrentDateTime(&log.tm);
	log.alarm.wid = PC_ALARM_WID;
	
	if(onOff)
	{
		log.alarm.rM =  bitvalue[id];
		log.alarm.rMBak =0;
	}
	else
	{
		log.alarm.rM =  0;
		log.alarm.rMBak = bitvalue[id];
	}
	
	PutLogToQueue(&log,1); 	 
}


//==============================================================================
// Global functions

void closePlc(void)
{
	CmtDiscardLock(plcLock);
	Mi_QPLC_END(&mPLC);
}

int openPlc(void)
{
	CmtNewLock(NULL, 0, &plcLock); 
	
	mPLC.COM	= 3;
	mPLC.Bau	= 115200;//57600;
	mPLC.Par	= 1;		// 0:None	1:??OOD	2:??EVEN
	mPLC.Dbit	= 8;		// 5 - 8 bit
	mPLC.Sbit	= 1;		// 1 - 2 bit
	mPLC.Hctl	= 1;		// 0:None	1:CTS/RTS/DTR	2:CTS/RTS
	mPLC.Tout	= 0.05;
	mPLC.useNet	= 0x00;
	mPLC.PlcID	= 0x00;
	mPLC.NetID	= 0xFF;

	int ret = Cfg_Q_1CF4(&mPLC);
	if (ret < 0)
	{
		SendPcAlarm(PCA_PLC_BID,1); 
		return 0;
	}
	
	return 1;
}

int readCommand(void)
{
	int ret;
	CmtGetLock(plcLock);
	ret = Get_Q_1CF4 (_WR_D, 0x00, PLC_CMD_ADD, 10, &mPLC); 
	if(ret < 0)
	{
		CmtReleaseLock(plcLock);
		return -1;
	}
	
	
	int DatSFT = 0;
	for (int cLop = 0; cLop < 10; cLop++){
		Scan ( mPLC.DTRN, "%s[i*w4]>%x[b2]", DatSFT, &Q2h.cmdRead[cLop]);
		DatSFT += 4;
	}
	
	CmtReleaseLock(plcLock);
	
	
	return 0;
}

int writeCommand(int len)
{
	int ret;
	if(len > MAX_CMD_LEN){
		MessagePopup("message","写入数据太长");
		return 0;
	}
	
	CmtGetLock(plcLock);
	
	ret = Get_Q_1CF4 (_WR_D, 0x00, PLC_CMD_ADD, 1, &mPLC);
	if(ret < 0)
	{
		plcErrorCount++;
		CmtReleaseLock(plcLock);
		MessagePopup("message","读取PLC出错");
		return 0;
	}
	
	
	Scan ( mPLC.DTRN, "%s[i*w4]>%x[b2]", 0, &Q2h.cmdRead[0]);
	if(Q2h.cmdRead[0] != 0 && Q2h.cmdRead[0]%10 == 0){
		plcErrorCount++;
		CmtReleaseLock(plcLock);
		MessagePopup("message","PLC忙");
		return 0;
	} 
	
	char SwpSTR[1024];
	memset(SwpSTR,0,sizeof(SwpSTR));
	for(int i=0;i<len;i++)
		Fmt (SwpSTR, "%s[a]<%i[r16w4p0]", Q2h.cmdWrite[i]);
	StringUpperCase (SwpSTR);
	ret = Set_Q_1CF4 (_WW_D, 0x00, PLC_CMD_ADD, len, SwpSTR, &mPLC);
	if(ret < 0){
		plcErrorCount++;
		CmtReleaseLock(plcLock);
		MessagePopup("message","写入PLC出错");
		return 0;
	}
	
	CmtReleaseLock(plcLock); 
	plcErrorCount=0;
	
	return 1;
}

void writeRecipe(void)
{
	int len;
	Q2h.cmdWrite[0] =   CMD_SAVE_TK_RCP;
	
	/////////////////////////////////////////////////////
	//DIW1 recipe
	len = sizeof(sys->rcp.rcpDIW1);
	Q2h.cmdWrite[1] =   TANK_DIW1;
	memcpy((char*)(&Q2h.cmdWrite[2]),(char*)&sys->rcp.rcpDIW1,len);
	writeCommand(len/2+2);
	
	/////////////////////////////////////////////////////
	//ACID recipe
	len = sizeof(sys->rcp.rcpACID);
	Q2h.cmdWrite[1] =   TANK_ACID;
	memcpy((char*)(&Q2h.cmdWrite[2]),(char*)&sys->rcp.rcpACID,len);
	writeCommand(len/2+2);
	
/////////////////////////////////////////////////////
	//DIW2 recipe
	len = sizeof(sys->rcp.rcpDIW2);
	Q2h.cmdWrite[1] =   TANK_DIW2;
	memcpy((char*)(&Q2h.cmdWrite[2]),(char*)&sys->rcp.rcpDIW2,len);
	writeCommand(len/2+2);
	
/////////////////////////////////////////////////////
	//KOH recipe
	len = sizeof(sys->rcp.rcpKOH);
	Q2h.cmdWrite[1] =   TANK_KOH;
	memcpy((char*)(&Q2h.cmdWrite[2]),(char*)&sys->rcp.rcpKOH,len);
	writeCommand(len/2+2);
	
/////////////////////////////////////////////////////
	//DIW3 recipe
	len = sizeof(sys->rcp.rcpDIW3);
	Q2h.cmdWrite[1] =   TANK_DIW3;
	memcpy((char*)(&Q2h.cmdWrite[2]),(char*)&sys->rcp.rcpDIW3,len);
	writeCommand(len/2+2);	
	
	
	/////////////////////////////////////////////////////
	//sys recipe
	len = sizeof(sys->rcp.rcpSYS);
	Q2h.cmdWrite[1] =   0;
	memcpy((char*)(&Q2h.cmdWrite[2]),(char*)&sys->rcp.rcpSYS,len);
	writeCommand(len/2+2);
}

int readAlarm(void)
{
	int ret;
    CmtGetLock(plcLock);
	ret = Get_Q_1CF4 (_WR_D, 0x00, PLC_ALARM_ADD, MAX_ALARM_LEN, &mPLC);
	if(ret < 0)
	{
		plcErrorCount++;
		CmtReleaseLock(plcLock);
		return -1;
	}
		
	int DatSFT = 0;
	for (int cLop = 0; cLop < MAX_ALARM_LEN; cLop++){
		Q2h.alarmBak[cLop] = Q2h.alarm[cLop]; 
		Scan ( mPLC.DTRN, "%s[i*w4]>%x[b2]", DatSFT, &Q2h.alarm[cLop]);
		DatSFT += 4;
		
		if(Q2h.alarmBak[cLop] == Q2h.alarm[cLop])
			continue;
		
					
		LOG log;
		log.type = ALARM_LOG;
		GetCurrentDateTime(&log.tm);
		log.alarm.wid = cLop;
		log.alarm.rM =  Q2h.alarm[cLop];
		log.alarm.rMBak = Q2h.alarmBak[cLop];
		PutLogToQueue(&log, 1);
		
		Q2h.alarmBak[cLop] = Q2h.alarm[cLop]; 
	}
	
	CmtReleaseLock(plcLock); 
	plcErrorCount=0;

	
	return 0;
}

int readSysStatus(void)
{
	int ret = sizeof(PLC_SYS_STATUS)/2;
    CmtGetLock(plcLock);
	ret = Get_Q_1CF4 (_WR_D, 0x00, PLC_SYS_STATUS_ADD, sizeof(PLC_SYS_STATUS)/2, &mPLC);
	if(ret < 0)
	{
		plcErrorCount++;
		CmtReleaseLock(plcLock);
		return -1;
	}
		
	int DatSFT = 0;
	for (int cLop = 0; cLop < sizeof(PLC_SYS_STATUS)/2; cLop++){
		Scan ( mPLC.DTRN, "%s[i*w4]>%x[b2]", DatSFT, ((short*)&Q2h.sysStatus)+cLop);
		DatSFT += 4;
	}
	
	CmtReleaseLock(plcLock); 
	plcErrorCount=0;
	
	 
	
	
	return 0;
}

int readTankStatus(int tid)
{
	int ret;
    CmtGetLock(plcLock);
	ret = Get_Q_1CF4 (_WR_D, 0x00, PLC_TK_STATUS_ADD + tid * MAX_TK_STATUS_LEN, MAX_TK_STATUS_LEN, &mPLC);
	if(ret < 0)
	{
		plcErrorCount++;
		CmtReleaseLock(plcLock);
		return -1;
	}
		
	int DatSFT = 0;
	for (int cLop = 0; cLop < MAX_TK_STATUS_LEN; cLop++){
		Scan ( mPLC.DTRN, "%s[i*w4]>%x[b2]", DatSFT, &Q2h.tkStatus[cLop]);
		DatSFT += 4;
	}
	
	CmtReleaseLock(plcLock);
	plcErrorCount=0;
	
	return 0;
}

int readRobotStatus(int rid)
{
	int ret;
	int len = sizeof(PLC_RB_STATUS)/2;
    CmtGetLock(plcLock);
	ret = Get_Q_1CF4 (_WR_D, 0x00, PLC_RB_STATUS_ADD + rid * len, len, &mPLC);
	if(ret < 0)
	{
		plcErrorCount++;
		CmtReleaseLock(plcLock);
		return -1;
	}
		
	int DatSFT = 0;
	for (int cLop = 0; cLop < len; cLop++){
		Scan ( mPLC.DTRN, "%s[i*w4]>%x[b2]", DatSFT, ((short*)&Q2h.rbStatus)+cLop);
		DatSFT += 4;
	}
	
	CmtReleaseLock(plcLock); 
	plcErrorCount=0;
	
	return 0;
}



