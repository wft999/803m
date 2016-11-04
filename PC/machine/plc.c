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

void LogPLCEvent(PLC_EVENT_TYPE	etype)
{
	LOG log;
	log.type = PLC_LOG;
	GetCurrentDateTime(&log.tm);
	log.plc.etype = etype;	
	
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
	CmtNewLock(NULL, OPT_TL_PROCESS_EVENTS_WHILE_WAITING, &plcLock); 
	
	mPLC.COM	= 3;
	mPLC.Bau	= 57600;
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
	CmtGetLock(plcLock);
	if(Get_Q_1CF4 (_WR_D, 0x00, PLC_CMD_ADD, 10, &mPLC) < 0)
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

void writeCommand(int len)
{
	if(len > MAX_CMD_LEN){
		MessagePopup("message","写入数据太长");
		return;
	}
	
	CmtGetLock(plcLock);
	
	if(Get_Q_1CF4 (_WR_D, 0x00, PLC_CMD_ADD, 1, &mPLC) < 0)
	{
		plcErrorCount++;
		CmtReleaseLock(plcLock);
		MessagePopup("message","读取PLC出错");
		return;
	}
	
	
	int DatSFT = 0;
	for (int cLop = 0; cLop < 1; cLop++){
		Scan ( mPLC.DTRN, "%s[i*w4]>%x[b2]", DatSFT, &Q2h.cmdRead[cLop]);
		DatSFT += 4;
	}
	if(Q2h.cmdRead[0]%10 == 0){
		plcErrorCount++;
		CmtReleaseLock(plcLock);
		MessagePopup("message","PLC忙");
		return;
	}
	
	char SwpSTR[1024];
	for(int i=0;i<len;i++)
		Fmt (SwpSTR, "%s[a]<%i[r16w4p0]", Q2h.cmdWrite[i]);
	StringUpperCase (SwpSTR);
	if(Set_Q_1CF4 (_WW_D, 0x00, PLC_CMD_ADD, len, SwpSTR, &mPLC) < 0){
		plcErrorCount++;
		CmtReleaseLock(plcLock);
		MessagePopup("message","写入PLC出错");
		return;
	}
	
	CmtReleaseLock(plcLock); 
	plcErrorCount=0;
}

void writeRecipe(int len)
{
	if(len > MAX_RCP_LEN){
		MessagePopup("message","写入数据太长");
		return;
	}
	
	CmtGetLock(plcLock);
	
	char SwpSTR[1024];
	for(int i=0;i<len;i++)
		Fmt (SwpSTR, "%s[a]<%i[r16w4p0]", Q2h.cmdWrite[i]);
	StringUpperCase (SwpSTR);
	
	if(Set_Q_1CF4 (_WW_D, 0x00, PLC_RCP_ADD, len, SwpSTR, &mPLC) < 0){
		plcErrorCount++;
		CmtReleaseLock(plcLock);
		MessagePopup("message","写入PLC出错");
		return;
	}
	
	CmtReleaseLock(plcLock); 
	plcErrorCount=0;
}

int readAlarm(void)
{
    CmtGetLock(plcLock);
	if(Get_Q_1CF4 (_WR_D, 0x00, PLC_ALARM_ADD, MAX_ALARM_LEN, &mPLC) < 0)
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
	}
	
	CmtReleaseLock(plcLock); 
	plcErrorCount=0;

	
	return 0;
}

int readSysStatus(void)
{
    CmtGetLock(plcLock);
	if(Get_Q_1CF4 (_WR_D, 0x00, PLC_SYS_STATUS_ADD, MAX_SYS_STATUS_LEN, &mPLC) < 0)
	{
		plcErrorCount++;
		CmtReleaseLock(plcLock);
		return -1;
	}
		
	int DatSFT = 0;
	for (int cLop = 0; cLop < MAX_SYS_STATUS_LEN; cLop++){
		Scan ( mPLC.DTRN, "%s[i*w4]>%x[b2]", DatSFT, &Q2h.sysStatus[cLop]);
		DatSFT += 4;
	}
	
	CmtReleaseLock(plcLock); 
	plcErrorCount=0;
	
	return 0;
}

int readTankStatus(int tid)
{
    CmtGetLock(plcLock);
	if(Get_Q_1CF4 (_WR_D, 0x00, PLC_TK_STATUS_ADD + tid * MAX_TK_STATUS_LEN, MAX_TK_STATUS_LEN, &mPLC) < 0)
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
    CmtGetLock(plcLock);
	if(Get_Q_1CF4 (_WR_D, 0x00, PLC_RB_STATUS_ADD + rid * MAX_RB_STATUS_LEN, MAX_RB_STATUS_LEN, &mPLC) < 0)
	{
		plcErrorCount++;
		CmtReleaseLock(plcLock);
		return -1;
	}
		
	int DatSFT = 0;
	for (int cLop = 0; cLop < MAX_RB_STATUS_LEN; cLop++){
		Scan ( mPLC.DTRN, "%s[i*w4]>%x[b2]", DatSFT, &Q2h.rbStatus[cLop]);
		DatSFT += 4;
	}
	
	CmtReleaseLock(plcLock); 
	plcErrorCount=0;
	
	return 0;
}


int readTankPos(int tid)
{
    CmtGetLock(plcLock);
	if(Get_Q_1CF4 (_WR_D, 0x00, PLC_TK_POS_ADD + tid * MAX_TK_POS_LEN, MAX_TK_POS_LEN, &mPLC) < 0)
	{
		plcErrorCount++;
		CmtReleaseLock(plcLock);
		MessagePopup("message","读取PLC出错"); 
		return -1;
	}
	
		
	int DatSFT = 0;
	for (int cLop = 0; cLop < MAX_TK_POS_LEN; cLop++){
		Scan ( mPLC.DTRN, "%s[i*w4]>%x[b2]", DatSFT, &Q2h.tkPos[cLop]);
		DatSFT += 4;
	}
	
	CmtReleaseLock(plcLock);
	plcErrorCount=0;
	
	return 0;
}
