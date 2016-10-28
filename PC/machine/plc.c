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
//==============================================================================
// Static functions

//==============================================================================
// Global variables
int 		g_updatePos = 0;
ROBOT_ID	g_updatePosRBid;
RTANK_ID	g_updatePosRTid;
POS_TYPE	g_updatePosType;

int g_setupMake = 0;
BIT g_makeBit;
int g_setupMMake = 0;
BIT g_mmakeBit;
int g_setupDosing = 0;
BIT	g_dosingBit;

int g_setupRecipe = 0;
int g_setupSetting = 0;

extern int g_writeTemp2Plc;
extern int g_exitThread;

struct Q02hReg Q2h;

const unsigned short bitvalue[] = {0x0001,0x0002,0x0004,0x0008,0x0010,0x0020,0x0040,0x0080,0x0100,0x0200,0x0400,0x0800,0x1000,0x2000,0x4000,0x8000};
//==============================================================================
// Global functions
void setBit(BIT bt)
{
	Q2h.wB[bt.wid] |= bitvalue[bt.bid];	
}


void resetBit(BIT bt)
{
	Q2h.wB[bt.wid] &= ~bitvalue[bt.bid];	
}


int testBit(BIT bt,BIT_TYPE type)
{
	if(bt.wid == 0 && bt.bid == 0)
		return -1;
	
	if(type == RB)
		return (Q2h.rB[bt.wid] & bitvalue[bt.bid]);
	else if(type == WB)
		return (Q2h.wB[bt.wid] & bitvalue[bt.bid]);
	else if(type == RX)
		return (Q2h.rX[bt.wid] & bitvalue[bt.bid]);
	else if(type == RY)
		return (Q2h.rY[bt.wid] & bitvalue[bt.bid]);
	else
		return -1;
}

int test00Bit(BIT_TYPE type)
{
	if(type == RB)
		return (Q2h.rB[0] & bitvalue[0]);
	else if(type == WB)
		return (Q2h.wB[0] & bitvalue[0]);
	else if(type == RX)
		return (Q2h.rX[0] & bitvalue[0]);
	else if(type == RY)
		return (Q2h.rY[0] & bitvalue[0]);
	else
		return -1;
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

void CheckHandshake(void)
{
	////////////////////////////////////////
	//watch dog
	static unsigned short lastPlcWdt = 0;
	static unsigned short plcWdtErr = 0;
	BIT bit;
	bit.wid = 0;bit.bid=7; 
	if(testBit(bit,RB) > 0) 
		resetBit(bit);
	

	if (Q2h.rB[0] & 0x0001) 
		Q2h.wB[0] |= 0x0001;
	else
		Q2h.wB[0] &= ~0x0001;
				
	if((Q2h.rB[0] & 0x0001) == lastPlcWdt)
	{
		plcWdtErr++;
		if(plcWdtErr == 50)
			SendPcAlarm(PCA_DOG_BID,1);
	}
	else
	{
		if(plcWdtErr >= 50)
			SendPcAlarm(PCA_DOG_BID,0);	
		plcWdtErr = 0;
	}
					
	lastPlcWdt = Q2h.rB[0] & 0x0001;
	
	///////////////////////////////////////////////////
	//chang car status
//	if(testBit(sys->hsFillChange,RB) > 0) 
//		resetBit(sys->hsFillChange); 
	
	//tank wash\make\down
	TANK_ID tk[12] = {TANK_02,TANK_03,TANK_04,TANK_06,TANK_07,TANK_09,TANK_10,TANK_11,TANK_12,TANK_13,TANK_14,TANK_15};
	for(int j = 0; j < 12; j++)
	{
		TANK_ID i = tk[j];
		if(testBit(sys->tk[i].hsAC1Dos,RB) > 0)
			resetBit(sys->tk[i].hsAC1Dos);
		
		if(testBit(sys->tk[i].hsAC2Dos,RB) > 0)
			resetBit(sys->tk[i].hsAC2Dos);
		
		if(testBit(sys->tk[i].hsAC3Dos,RB) > 0)
			resetBit(sys->tk[i].hsAC3Dos);
		
		if(testBit(sys->tk[i].hsAC4Dos,RB) > 0)
			resetBit(sys->tk[i].hsAC4Dos);
		
		if(testBit(sys->tk[i].hsPDrain,RB) > 0)
			resetBit(sys->tk[i].hsPDrain);
		

		if(testBit(sys->tk[i].hsMake,RB) > 0)
		{
			resetBit(sys->tk[i].hsMake);
			sys->tk[i].isMaking = 1; 
		}
		
		if(testBit(sys->tk[i].hsMMake,RB) > 0)
		{
			sys->tk[i].isMMaking = 1;
			resetBit(sys->tk[i].hsMMake);
		}

		if(testBit(sys->tk[i].hsMMake,RB) == 0 && sys->tk[i].isMMaking == 1)
		{
				sys->tk[i].isMMaking = 0;
				DosingLog(MANUAL_MIX_ACID,i,1,sys->tk[i].carNumber);
				DosingLog(MANUAL_MIX_ACID,i,2,sys->tk[i].carNumber);
				DosingLog(MANUAL_MIX_ACID,i,3,sys->tk[i].carNumber);
				DosingLog(MANUAL_MIX_ACID,i,4,sys->tk[i].carNumber);
		}
			
		
		
		if(sys->tk[i].isMaking == 1 && testBit(sys->tk[i].hsMakeEnd,RB) > 0)
		{
			DosingLog(AUTO_MIX_ACID,i,1,sys->tk[i].carNumber);
			DosingLog(AUTO_MIX_ACID,i,2,sys->tk[i].carNumber);
			DosingLog(AUTO_MIX_ACID,i,3,sys->tk[i].carNumber);
			DosingLog(AUTO_MIX_ACID,i,4,sys->tk[i].carNumber);
			
				
			resetBit(sys->tk[i].hsMMake);
			resetBit(sys->tk[i].hsMake);
			double cTM;
			GetCurrentDateTime ( &cTM);
			sys->tk[i].isMaking = 0;
			sys->tk[i].lifeRun = sys->tk[i].rcp.DrainRun;
			sys->tk[i].lifeTime = cTM + 60 * sys->tk[i].rcp.DrainTime;
			
			sys->tk[i].tmAC1Dos = cTM;
			sys->tk[i].tmAC2Dos = cTM;
			sys->tk[i].tmAC3Dos = cTM;
			sys->tk[i].tmAC4Dos = cTM;
			
			
			if(i == TANK_02)
			{
				SendPcAlarm(PCA_SCTIME_BID,0);
				SendPcAlarm(PCA_SCRUN_BID,0);
				
				sys->tk[i].runAC1Dos = sys->tk[TANK_02].carNumber; 
				sys->tk[i].runAC2Dos = sys->tk[TANK_02].carNumber;
				sys->tk[i].runAC3Dos = sys->tk[TANK_02].carNumber;
				sys->tk[i].runAC4Dos = sys->tk[TANK_02].carNumber;
			}
			else if(i == TANK_04)
			{
				SendPcAlarm(PCA_TEXATIME_BID,0);
				SendPcAlarm(PCA_TEXARUN_BID,0);
				sys->tk[TANK_05].lifeRun = sys->tk[i].rcp.DrainRun;
				sys->tk[TANK_05].lifeTime = cTM + 60 * sys->tk[i].rcp.DrainTime;
				
				sys->tk[i].runAC1Dos = sys->tk[TANK_04].carNumber + sys->tk[TANK_05].carNumber; 
				sys->tk[i].runAC2Dos = sys->tk[TANK_04].carNumber + sys->tk[TANK_05].carNumber;
				sys->tk[i].runAC3Dos = sys->tk[TANK_04].carNumber + sys->tk[TANK_05].carNumber;
				sys->tk[i].runAC4Dos = sys->tk[TANK_04].carNumber + sys->tk[TANK_05].carNumber;
				
				sys->tk[i].PdRun  = sys->tk[i].rcp.PdStart  + sys->tk[TANK_04].carNumber + sys->tk[TANK_05].carNumber;
			}
			else if(i == TANK_07)
			{
				SendPcAlarm(PCA_TEXBTIME_BID,0);
				SendPcAlarm(PCA_TEXBRUN_BID,0);
				sys->tk[TANK_08].lifeRun = sys->tk[i].rcp.DrainRun;
				sys->tk[TANK_08].lifeTime = cTM + 60 * sys->tk[i].rcp.DrainTime;
				
				sys->tk[i].runAC1Dos = sys->tk[TANK_07].carNumber + sys->tk[TANK_08].carNumber; 
				sys->tk[i].runAC2Dos = sys->tk[TANK_07].carNumber + sys->tk[TANK_08].carNumber;
				sys->tk[i].runAC3Dos = sys->tk[TANK_07].carNumber + sys->tk[TANK_08].carNumber;
				sys->tk[i].runAC4Dos = sys->tk[TANK_07].carNumber + sys->tk[TANK_08].carNumber;
				
				sys->tk[i].PdRun  = sys->tk[i].rcp.PdStart  + sys->tk[TANK_07].carNumber + sys->tk[TANK_08].carNumber;
			}
			else if(i == TANK_11)
			{
				SendPcAlarm(PCA_HFTIME_BID,0);
				SendPcAlarm(PCA_HFRUN_BID,0);
				
				sys->tk[i].runAC1Dos = sys->tk[TANK_11].carNumber; 
				sys->tk[i].runAC2Dos = sys->tk[TANK_11].carNumber;
				sys->tk[i].runAC3Dos = sys->tk[TANK_11].carNumber;
				sys->tk[i].runAC4Dos = sys->tk[TANK_11].carNumber;
			}
		}
		
		if(testBit(sys->tk[i].hsMakeEnd,RB) == 0)
			resetBit(sys->tk[i].hsDown); 
		
		
		if(testBit(sys->tk[i].hsWash,RB) > 0 )
			sys->tk[i].isWashing = 1; 
		if(testBit(sys->tk[i].hsDown,RB) > 0)
			sys->tk[i].isWashing = 1;
		
		if(sys->tk[i].isWashing == 1) 
		{
			if(testBit(sys->tk[i].hsWash,RB) == 0 && testBit(sys->tk[i].hsWash,WB) > 0)
			{
				sys->tk[i].isWashing = 0;
				resetBit(sys->tk[i].hsWash);
			}
			if(testBit(sys->tk[i].hsDown,RB) == 0 && testBit(sys->tk[i].hsDown,WB) > 0)
			{
				sys->tk[i].isWashing = 0;
				resetBit(sys->tk[i].hsDown);
			}
		}
			
	}
	
	if(testBit(sys->hsRcpChange,RB) > 0)
		resetBit(sys->hsRcpChange);
	
	if(testBit(sys->hsEMOContine,RB) > 0)
		resetBit(sys->hsEMOContine);
	
	if(testBit(sys->rb[0].hsAbortCommand,RB) > 0)
		resetBit(sys->rb[0].hsAbortCommand);
	
		
}

int InitReadFromPLC(void)
{
	union DatCnv cnv;
	int cLop = 0;
	int DatSFT = 0; 
	
	/////////////////////////////////////////////
	//handsake out
	if(Get_Q_1CF4 (_WR_D, 0x00, 900, 30, &mPLC) < 0) 
		return -1;
	for (cLop = 0; cLop < 25; cLop++){
		if(cLop == 1 || cLop > 3)
			Scan ( mPLC.DTRN, "%s[i*w4]>%x[b2]", DatSFT, &Q2h.wB[cLop]);
		DatSFT += 4;
	}

	
	///////////////////////////////////////////
	//
	DatSFT = 0;
	if(Get_Q_1CF4 (_WR_D, 0x00, 1100, 12, &mPLC) < 0) 
		return -1;
	for (cLop = 0; cLop < 12; cLop++){
		Scan ( mPLC.DTRN, "%s[i*w4]>%x[b2]", DatSFT, &Q2h.rD[cLop]);
		DatSFT += 4;
	}
	cnv._I16[0] = Q2h.rD[0]; 
	cnv._I16[1] = Q2h.rD[1];
	sys->rb[0].safeHight = cnv._I32;
	
	cnv._I16[0] = Q2h.rD[4]; 
	cnv._I16[1] = Q2h.rD[5];
	sys->rb[1].safeHight = cnv._I32;
	
	cnv._I16[0] = Q2h.rD[8]; 
	cnv._I16[1] = Q2h.rD[9];
	sys->rb[2].safeHight = cnv._I32;
	
	///////////////////////////////////////////////////
	//rb1 position
	for(RTANK_ID i = RTK_01; i<= RTK_06; i++)
	{
		if(Get_Q_1CF4 (_WR_D, 0x00, 1116+(i - RTK_01)*6, 6, &mPLC) < 0) 
			return -1;
		
		DatSFT = 0;
		for (cLop = 0; cLop < 6; cLop++){
			Scan ( mPLC.DTRN, "%s[i*w4]>%x[b2]", DatSFT, &Q2h.rD[cLop]);
			DatSFT += 4;
		}
		
		int j = 0;
		cnv._I16[0] = Q2h.rD[j++]; 
		cnv._I16[1] = Q2h.rD[j++];
		sys->rtk[i].xUnlock = cnv._I32;
		
		cnv._I16[0] = Q2h.rD[j++]; 
		cnv._I16[1] = Q2h.rD[j++];
		sys->rtk[i].xLock = cnv._I32;
		
		cnv._I16[0] = Q2h.rD[j++]; 
		cnv._I16[1] = Q2h.rD[j++];
		sys->rtk[i].zDown = cnv._I32;
	}
	
	///////////////////////////////////////////////////
	//rb2 position
	for(RTANK_ID i = RTK_06; i<= RTK_12; i++)
	{
		DatSFT = 0;
		if(Get_Q_1CF4 (_WR_D, 0x00, 1176+(i-RTK_06)*6, 6, &mPLC) < 0) 
			return -1;
		
		for (cLop = 0; cLop < 6; cLop++){
			Scan ( mPLC.DTRN, "%s[i*w4]>%x[b2]", DatSFT, &Q2h.rD[cLop]);
			DatSFT += 4;
		}
	
		int j = 0;
		if(i == RTK_06)
		{
			cnv._I16[0] = Q2h.rD[j++]; 
			cnv._I16[1] = Q2h.rD[j++];
			sys->rtk[i].xUnlock2 = cnv._I32;
		
			cnv._I16[0] = Q2h.rD[j++]; 
			cnv._I16[1] = Q2h.rD[j++];
			sys->rtk[i].xLock2 = cnv._I32;
		
			cnv._I16[0] = Q2h.rD[j++]; 
			cnv._I16[1] = Q2h.rD[j++];
			sys->rtk[i].zDown2 = cnv._I32;
		}
		else
		{
			cnv._I16[0] = Q2h.rD[j++]; 
			cnv._I16[1] = Q2h.rD[j++];
			sys->rtk[i].xUnlock = cnv._I32;
		
			cnv._I16[0] = Q2h.rD[j++]; 
			cnv._I16[1] = Q2h.rD[j++];
			sys->rtk[i].xLock = cnv._I32;
		
			cnv._I16[0] = Q2h.rD[j++]; 
			cnv._I16[1] = Q2h.rD[j++];
			sys->rtk[i].zDown = cnv._I32;
		}
	}
	
	///////////////////////////////////////////////////
	//rb3 position
	for(RTANK_ID i = RTK_12; i<= RTK_17; i++)
	{
		int j = 0;
		DatSFT = 0;
		
		if(Get_Q_1CF4 (_WR_D, 0x00, 1242+(i-RTK_12)*6, 6, &mPLC) < 0) 
			return -1;
		for (cLop = 0; cLop < 6; cLop++){
			Scan ( mPLC.DTRN, "%s[i*w4]>%x[b2]", DatSFT, &Q2h.rD[cLop]);
			DatSFT += 4;
		}
	
		if(i == RTK_12)
		{
			cnv._I16[0] = Q2h.rD[j++]; 
			cnv._I16[1] = Q2h.rD[j++];
			sys->rtk[i].xUnlock2 = cnv._I32;
		
			cnv._I16[0] = Q2h.rD[j++]; 
			cnv._I16[1] = Q2h.rD[j++];
			sys->rtk[i].xLock2 = cnv._I32;
		
			cnv._I16[0] = Q2h.rD[j++]; 
			cnv._I16[1] = Q2h.rD[j++];
			sys->rtk[i].zDown2 = cnv._I32;
		}
		else
		{
			cnv._I16[0] = Q2h.rD[j++]; 
			cnv._I16[1] = Q2h.rD[j++];
			sys->rtk[i].xUnlock = cnv._I32;
		
			cnv._I16[0] = Q2h.rD[j++]; 
			cnv._I16[1] = Q2h.rD[j++];
			sys->rtk[i].xLock = cnv._I32;
		
			cnv._I16[0] = Q2h.rD[j++]; 
			cnv._I16[1] = Q2h.rD[j++];
			sys->rtk[i].zDown = cnv._I32;
		}
	}
	
	////////////////////////////////////
	//clean
	int j = 0;
	DatSFT = 0;
		
	if(Get_Q_1CF4 (_WR_D, 0x00, 1284, 6, &mPLC) < 0) 
		return -1;
	for (cLop = 0; cLop < 6; cLop++){
		Scan ( mPLC.DTRN, "%s[i*w4]>%x[b2]", DatSFT, &Q2h.rD[cLop]);
		DatSFT += 4;
	}
	
	cnv._I16[0] = Q2h.rD[j++]; 
	cnv._I16[1] = Q2h.rD[j++];
	sys->rb[0].cleanPosH = cnv._I32;
		
	cnv._I16[0] = Q2h.rD[j++]; 
	cnv._I16[1] = Q2h.rD[j++];
	sys->rb[0].cleanLock = cnv._I32;
		
	cnv._I16[0] = Q2h.rD[j++]; 
	cnv._I16[1] = Q2h.rD[j++];
	sys->rb[0].cleanPosV = cnv._I32;
	
	return 1;
}

//==============================================================================
// Global functions
int CVICALLBACK plcThread (void *Data)
{
	mPLC.COM	= 1;
	mPLC.Bau	= 57600;
	mPLC.Par	= 0;		// 0:None	1:??OOD	2:??EVEN
	mPLC.Dbit	= 8;		// 5 - 8 bit
	mPLC.Sbit	= 1;		// 1 - 2 bit
	mPLC.Hctl	= 1;		// 0:None	1:CTS/RTS/DTR	2:CTS/RTS
	mPLC.Tout	= 0.05;
	mPLC.useNet	= 0x00;
	mPLC.PlcID	= 0x00;
	mPLC.NetID	= 0xFF;

	if (Cfg_Q_1CF4(&mPLC) < 0)
	{
		SendPcAlarm(PCA_PLC_BID,1); 
		return 0;
	}
	
	if(InitReadFromPLC() < 0)
	{
		SendPcAlarm(PCA_PLC_BID,1); 
		return 0;	
	}
	
	int step = 0;
	int step2 = 0;
	const int maxStep = 10; 
	
	union DatCnv cnv;
	
	int cLop = 0;
	int DatSFT = 0;
	char SwpSTR[1024];
				
	while (g_exitThread == 0){
		Delay(0.01);
		
		switch (step%maxStep){
			//-------------------------------------------------
			// Read  D800 - D824 (HANDSHAKE IN)
			case 0:			
			case 3:
			case 6:
				DatSFT = 0;
				if ( Get_Q_1CF4 (_WR_D, 0x00, 800, 26, &mPLC) < 0 )		continue;
				for (cLop = 0; cLop < 26; cLop++){
					Scan ( mPLC.DTRN, "%s[i*w4]>%x[b2]", DatSFT, &Q2h.rB[cLop]);
					DatSFT += 4;
				}
				CheckHandshake();
				break;	
			//-------------------------------------------------
			// Write  D900 - D924 (HANDSHAKE OUT)
			case 2:
			case 5:
			case 8:
				Fmt (SwpSTR, "%s<%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]",
									 Q2h.wB[0], Q2h.wB[1], Q2h.wB[2], Q2h.wB[3], Q2h.wB[4], Q2h.wB[5], Q2h.wB[6], Q2h.wB[7],
									 Q2h.wB[8], Q2h.wB[9], Q2h.wB[10], Q2h.wB[11], Q2h.wB[12], Q2h.wB[13], Q2h.wB[14], Q2h.wB[15]);
				Fmt (SwpSTR, "%s[a]<%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]",
									 Q2h.wB[16], Q2h.wB[17], Q2h.wB[18], Q2h.wB[19], Q2h.wB[20], Q2h.wB[21], Q2h.wB[22], Q2h.wB[23],
									 Q2h.wB[24], Q2h.wB[25],Q2h.wB[26], Q2h.wB[27],Q2h.wB[28], Q2h.wB[29]);
				StringUpperCase (SwpSTR);
				if ( Set_Q_1CF4 (_WW_D, 0x00, 900, 30, SwpSTR, &mPLC) < 0 )		continue;

				//Save_Plc_HandShake();
				break;

			//-------------------------------------------------
			// Read  D500-D535, D550-D579 (I/O)
			case 1:
				//-------------------------------------------------
				// Read  D550 (input)
				DatSFT = 0;
				if ( Get_Q_1CF4 (_WR_D, 0x00, 500, 42, &mPLC) < 0)		continue;
				for (cLop = 0; cLop < 42; cLop++){
					Scan ( mPLC.DTRN, "%s[i*w4]>%x[b2]", DatSFT+0, &Q2h.rX[cLop]);
					DatSFT += 4;
				}
			case 4: 
				//-------------------------------------------------
				// Read  D550 (output)
				DatSFT = 0;									
				if ( Get_Q_1CF4 (_WR_D, 0x00, 550, 36, &mPLC) < 0)		continue;
				for (cLop = 0; cLop < 36; cLop++){
					Scan ( mPLC.DTRN, "%s[i*w4]>%x[b2]", DatSFT+0, &Q2h.rY[cLop]);
					DatSFT += 4;
				}
				
			case 7:
				//-------------------------------------------------
				// Read  D600-D631 (ALARM)
				if(testBit(sys->hsAlarm,RB) > 0 && testBit(sys->hsAlarm,WB) == 0)
				{
					setBit(sys->hsAlarm);
					
					LOG log;
					log.type = ALARM_LOG;
					GetCurrentDateTime(&log.tm);
					
					DatSFT = 0;
					if ( Get_Q_1CF4 (_WR_D, 0x01, 600, 39, &mPLC) < 0 )		continue;
					for (cLop = 0; cLop < 39; cLop++)
					{
						Q2h.rMBak[cLop] = Q2h.rM[cLop];
						Scan ( mPLC.DTRN, "%s[i*w4]>%x[b2]", DatSFT, &Q2h.rM[cLop]);
						DatSFT += 4;
						
						if(Q2h.rMBak[cLop] == Q2h.rM[cLop])
							continue;
						
						log.alarm.wid = cLop;
						log.alarm.rM =  Q2h.rM[cLop];
						log.alarm.rMBak = Q2h.rMBak[cLop];
						PutLogToQueue(&log, 1);
						
					}
					
				}
				else if (testBit(sys->hsAlarm,RB) == 0 && testBit(sys->hsAlarm,WB) > 0)
					resetBit(sys->hsAlarm);

				break;	 
			//-------------------------------------------------
			//ad
			case 9:
				//-------------------------------------------------
				// Read  D2000 - D2015 (Recipe Data) RB1~RB4??
				DatSFT = 0;
				if ( Get_Q_1CF4 (_WR_D, 0x00, 2000, 18, &mPLC) < 0)		continue;
				for (cLop = 0; cLop < 18; cLop++){
					Scan ( mPLC.DTRN, "%s[i*w4]>%x[b2]", DatSFT, &Q2h.rD[cLop]);
					DatSFT += 4;								 
				}
				
				union DatCnv cnv;
				cnv._I16[0] = Q2h.rD[0]; 
				cnv._I16[1] = Q2h.rD[1];
				sys->rb[0].curPosX = cnv._I32;
				cnv._I16[0] = Q2h.rD[2]; 
				cnv._I16[1] = Q2h.rD[3];
				sys->rb[0].curPosY = cnv._I32;
				
				cnv._I16[0] = Q2h.rD[4]; 
				cnv._I16[1] = Q2h.rD[5];
				sys->rb[1].curPosX = cnv._I32;
				cnv._I16[0] = Q2h.rD[6]; 
				cnv._I16[1] = Q2h.rD[7];
				sys->rb[1].curPosY = cnv._I32;
				
				cnv._I16[0] = Q2h.rD[8]; 
				cnv._I16[1] = Q2h.rD[9];
				sys->rb[2].curPosX = cnv._I32;
				cnv._I16[0] = Q2h.rD[10]; 
				cnv._I16[1] = Q2h.rD[11];
				sys->rb[2].curPosY = cnv._I32;
				
				cnv._I16[0] = Q2h.rD[16]; 
				cnv._I16[1] = Q2h.rD[17];
				sys->tk[TANK_16].curAKFPos = cnv._I32;
				
				///dosing count
				if(step2 == 3)
				{
					DatSFT = 0;
					if ( Get_Q_1CF4 (_WR_D, 0x00, 2020, 17, &mPLC) < 0)		continue;
					for (cLop = 0; cLop < 17; cLop++){
						Scan ( mPLC.DTRN, "%s[i*w4]>%x[b2]", DatSFT, &Q2h.rD[cLop]);
						DatSFT += 4;								 
					}
				
					sys->tk[TANK_02].DosingCountCH1 = Q2h.rD[0];
					sys->tk[TANK_02].DosingCountCH2 = Q2h.rD[1];
					sys->tk[TANK_02].DosingCountCH3 = Q2h.rD[2];
				
					sys->tk[TANK_04].DosingCountCH1 = Q2h.rD[6];
					sys->tk[TANK_04].DosingCountCH2 = Q2h.rD[7];
					sys->tk[TANK_04].DosingCountCH3 = Q2h.rD[8];
				
					sys->tk[TANK_07].DosingCountCH1 = Q2h.rD[9];
					sys->tk[TANK_07].DosingCountCH2 = Q2h.rD[0];
					sys->tk[TANK_07].DosingCountCH3 = Q2h.rD[1];
				
					sys->tk[TANK_11].DosingCountCH1 = Q2h.rD[12];
					sys->tk[TANK_11].DosingCountCH2 = Q2h.rD[13];
					sys->tk[TANK_11].DosingCountCH3 = Q2h.rD[14];
				
					sys->tk[TANK_04].DosingCountCH4 = Q2h.rD[15];
					sys->tk[TANK_07].DosingCountCH4 = Q2h.rD[16];
				}
				
				if(step2 == 5 && (testBit(sys->tk[TANK_02].hsMake,RB) == 0||
					testBit(sys->tk[TANK_04].hsMake,RB) == 0||	
					testBit(sys->tk[TANK_07].hsMake,RB) == 0||
					testBit(sys->tk[TANK_11].hsMake,RB) == 0||
					testBit(sys->tk[TANK_04].hsPDrain,RB) == 0||
					testBit(sys->tk[TANK_07].hsPDrain,RB) == 0))
				{
					DatSFT = 0;
					if ( Get_Q_1CF4 (_WR_D, 0x00, 2040, 29, &mPLC) < 0)		continue;
					for (cLop = 0; cLop < 29; cLop++){
						Scan ( mPLC.DTRN, "%s[i*w4]>%x[b2]", DatSFT, &Q2h.rD[cLop]);
						DatSFT += 4;								 
					}
					sys->tk[TANK_02].MakeCountCH1 = Q2h.rD[1];
					sys->tk[TANK_02].MakeCountCH2 = Q2h.rD[2];
					sys->tk[TANK_02].MakeCountCH3 = Q2h.rD[3];
				
					sys->tk[TANK_04].MakeCountCH1 = Q2h.rD[7];
					sys->tk[TANK_04].MakeCountCH2 = Q2h.rD[8];
					sys->tk[TANK_04].MakeCountCH3 = Q2h.rD[9];
					
					sys->tk[TANK_07].MakeCountCH1 = Q2h.rD[10];
					sys->tk[TANK_07].MakeCountCH2 = Q2h.rD[11];
					sys->tk[TANK_07].MakeCountCH3 = Q2h.rD[12];
					
					sys->tk[TANK_11].MakeCountCH1 = Q2h.rD[13];
					sys->tk[TANK_11].MakeCountCH2 = Q2h.rD[14];
					sys->tk[TANK_11].MakeCountCH3 = Q2h.rD[15];
					
					sys->tk[TANK_04].PDrainVol = Q2h.rD[18];
					sys->tk[TANK_04].PMakeCountCH1 = Q2h.rD[19];
					sys->tk[TANK_04].PMakeCountCH2 = Q2h.rD[20];
					sys->tk[TANK_04].PMakeCountCH3 = Q2h.rD[21];
					
					sys->tk[TANK_07].PDrainVol = Q2h.rD[22];
					sys->tk[TANK_07].PMakeCountCH1 = Q2h.rD[23];
					sys->tk[TANK_07].PMakeCountCH2 = Q2h.rD[24];
					sys->tk[TANK_07].PMakeCountCH3 = Q2h.rD[25];
					
					sys->tk[TANK_04].MakeCountCH4 = Q2h.rD[27];
					sys->tk[TANK_07].MakeCountCH4 = Q2h.rD[28];
				}
				
				if(step2 == 8)
				{
					DatSFT = 0;
					if ( Get_Q_1CF4 (_WR_D, 0x00, 2070, 13, &mPLC) < 0)		continue;
					for (cLop = 0; cLop < 13; cLop++){
						Scan ( mPLC.DTRN, "%s[i*w4]>%x[b2]", DatSFT, &Q2h.rD[cLop]);
						DatSFT += 4;								 
					}
					sys->tk[TANK_04].Flow = Q2h.rD[1]; 
					sys->tk[TANK_05].Flow = Q2h.rD[2];
					sys->tk[TANK_07].Flow = Q2h.rD[3];
					sys->tk[TANK_08].Flow = Q2h.rD[4];
					
					sys->tk[TANK_04].Cond = Q2h.rD[6];
					sys->tk[TANK_07].Cond = Q2h.rD[8];
					sys->tk[TANK_14].Cond = Q2h.rD[10];
					sys->tk[TANK_15].Cond = Q2h.rD[12];

				}
				
				if(step2 == 5 && (testBit(sys->tk[TANK_02].hsMMake,RB) == 0||
					testBit(sys->tk[TANK_04].hsMMake,RB) == 0||	
					testBit(sys->tk[TANK_07].hsMMake,RB) == 0||
					testBit(sys->tk[TANK_11].hsMMake,RB) == 0))
				{
					DatSFT = 0;
					if ( Get_Q_1CF4 (_WR_D, 0x00, 2085, 14, &mPLC) < 0)		continue;
					for (cLop = 0; cLop < 14; cLop++){
						Scan ( mPLC.DTRN, "%s[i*w4]>%x[b2]", DatSFT, &Q2h.rD[cLop]);
						DatSFT += 4;								 
					}
					sys->tk[TANK_02].MMakeCountCH1 = Q2h.rD[0];
					sys->tk[TANK_02].MMakeCountCH2 = Q2h.rD[1];
					sys->tk[TANK_02].MMakeCountCH3 = Q2h.rD[2];
				
					sys->tk[TANK_04].MMakeCountCH1 = Q2h.rD[3];
					sys->tk[TANK_04].MMakeCountCH2 = Q2h.rD[4];
					sys->tk[TANK_04].MMakeCountCH3 = Q2h.rD[5];
					sys->tk[TANK_04].MMakeCountCH4 = Q2h.rD[6];
					
					sys->tk[TANK_07].MMakeCountCH1 = Q2h.rD[7];
					sys->tk[TANK_07].MMakeCountCH2 = Q2h.rD[8];
					sys->tk[TANK_07].MMakeCountCH3 = Q2h.rD[9];
					sys->tk[TANK_07].MMakeCountCH4 = Q2h.rD[10];
					
					sys->tk[TANK_11].MMakeCountCH1 = Q2h.rD[11];
					sys->tk[TANK_11].MMakeCountCH2 = Q2h.rD[12];
					sys->tk[TANK_11].MMakeCountCH3 = Q2h.rD[13];
				}

				
				step2++;
				if(step2 == maxStep) step2 = 0;
				
				break;  
		}
		
		if(++step == maxStep) step = 0;
		
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////
		///Setup Recipe to DM Data
		if (g_setupRecipe){
			Fmt (SwpSTR, "%s<%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]",
                        (int)(sys->tk[TANK_02].rcp.DosCH1*10.0),(int)(sys->tk[TANK_02].rcp.DosCH2*10.0),(int)(sys->tk[TANK_02].rcp.DosCH3*10.0),
                        (int)(sys->tk[TANK_04].rcp.DosCH1*10.0),(int)(sys->tk[TANK_04].rcp.DosCH2*10.0),(int)(sys->tk[TANK_04].rcp.DosCH3*10.0),
                        (int)(sys->tk[TANK_07].rcp.DosCH1*10.0),(int)(sys->tk[TANK_07].rcp.DosCH2*10.0),(int)(sys->tk[TANK_07].rcp.DosCH3*10.0),
                        (int)(sys->tk[TANK_11].rcp.DosCH1*10.0),(int)(sys->tk[TANK_11].rcp.DosCH2*10.0),(int)(sys->tk[TANK_11].rcp.DosCH3*10.0),
                        (int)(sys->tk[TANK_04].rcp.DosCH4*1.0),(int)(sys->tk[TANK_07].rcp.DosCH4*1.0));
                                     
           	if (Set_Q_1CF4 (_WW_D, 0x01, 1008,14, SwpSTR, &mPLC) < 0)       continue;
			
			
			Fmt (SwpSTR, "%s<%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]",
				(int)(sys->tk[TANK_04].rcp.PdCH4*1.0),(int)(sys->tk[TANK_07].rcp.PdCH4*1.0),
                        (int)(sys->tk[TANK_04].rcp.PdVol*10.0),(int)(sys->tk[TANK_04].rcp.PdCH1*10.0),(int)(sys->tk[TANK_04].rcp.PdCH2*10.0),(int)(sys->tk[TANK_04].rcp.PdCH3*10.0),
                        (int)(sys->tk[TANK_04].rcp.PdVol*10.0),(int)(sys->tk[TANK_07].rcp.PdCH1*10.0),(int)(sys->tk[TANK_07].rcp.PdCH2*10.0),(int)(sys->tk[TANK_07].rcp.PdCH3*10.0));
                        
            if (Set_Q_1CF4 (_WW_D, 0x01, 1047,10, SwpSTR, &mPLC) < 0)        continue;
			
			
			Fmt (SwpSTR, "%s<%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]",
                        sys->tk[TANK_02].rcp.ProcTM,sys->tk[TANK_02].rcp.ProcTM,sys->tk[TANK_04].rcp.ProcTM,
                        sys->tk[TANK_04].rcp.ProcTM,sys->tk[TANK_05].rcp.ProcTM,sys->tk[TANK_05].rcp.ProcTM,
                        sys->tk[TANK_07].rcp.ProcTM,sys->tk[TANK_07].rcp.ProcTM,sys->tk[TANK_08].rcp.ProcTM,
                        sys->tk[TANK_08].rcp.ProcTM,sys->tk[TANK_11].rcp.ProcTM,sys->tk[TANK_11].rcp.ProcTM,
                        0,0,sys->tk[TANK_16].rcp.ProcTM);

            if ( Set_Q_1CF4 (_WW_D, 0x01, 1057, 15, SwpSTR, &mPLC) < 0)      continue;
			
			Fmt (SwpSTR, "%s<%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]",
                        (int)(sys->tk[TANK_AUX_PH1].rcp.Temp*10.0),(int)(sys->tk[TANK_AUX_PH2].rcp.Temp*10.0),(int)(sys->tk[TANK_02].rcp.Temp*10.0),
                        (int)(sys->tk[TANK_03].rcp.Temp*10.0),(int)(sys->tk[TANK_04].rcp.Temp*10.0),(int)(sys->tk[TANK_06].rcp.Temp*10.0),
                        (int)(sys->tk[TANK_07].rcp.Temp*10.0),(int)(sys->tk[TANK_09].rcp.Temp*10.0),(int)(sys->tk[TANK_10].rcp.Temp*10.0),
                        (int)(sys->tk[TANK_12].rcp.Temp*10.0),(int)(sys->tk[TANK_13].rcp.Temp*10.0),(int)(sys->tk[TANK_14].rcp.Temp*10.0),
                        (int)(sys->tk[TANK_15].rcp.Temp*10.0),(int)(sys->tk[TANK_AUX_IN].rcp.Temp*10.0),(int)(sys->tk[TANK_16].rcp.Temp*10.0),
						(int)(sys->tk[TANK_17].rcp.Temp*10.0));
                                     
			if (Set_Q_1CF4 (_WW_D, 0x01, 1600,16, SwpSTR, &mPLC) < 0)       continue;
						
			setBit(sys->hsRcpChange);
			g_setupRecipe = 0;
			
			LogPLCEvent(RECIPE_PLC_EVENT);
		}
		// ========================================================
		// ReSetup Dosing Data
		if (g_setupDosing){
			Fmt (SwpSTR, "%s<%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]",
					(int)(sys->tk[TANK_02].rcp.DosCH1*10.0), (int)(sys->tk[TANK_02].rcp.DosCH2*10.0),(int)(sys->tk[TANK_02].rcp.DosCH3*10.0),
					(int)(sys->tk[TANK_04].rcp.DosCH1*10.0), (int)(sys->tk[TANK_04].rcp.DosCH2*10.0),(int)(sys->tk[TANK_04].rcp.DosCH3*10.0),
					(int)(sys->tk[TANK_07].rcp.DosCH1*10.0), (int)(sys->tk[TANK_07].rcp.DosCH2*10.0),(int)(sys->tk[TANK_07].rcp.DosCH3*10.0), 
					(int)(sys->tk[TANK_11].rcp.DosCH1*10.0), (int)(sys->tk[TANK_11].rcp.DosCH2*10.0),(int)(sys->tk[TANK_11].rcp.DosCH3*10.0),
					(int)(sys->tk[TANK_04].rcp.DosCH4*1.0), (int)(sys->tk[TANK_07].rcp.DosCH4*1.0));
			if (Set_Q_1CF4 (_WW_D, 0x01, 1008, 14, SwpSTR, &mPLC) < 0)		continue;
			 
			setBit(g_dosingBit);
			setBit(sys->hsRcpChange);
			g_setupDosing = 0;
			
			LogPLCEvent(DOSING_PLC_EVENT);
		}
		// ========================================================
		// pump 
		if (g_setupSetting){
			memset(SwpSTR, 0x0, 255);
			Fmt (SwpSTR, "%s<%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]", 
				(int)(sys->set.down_delay_02*10),(int)(sys->set.down_delay_03*10),(int)(sys->set.down_delay_04*10)
				,(int)(sys->set.down_delay_05*10),(int)(sys->set.down_delay_06*10),(int)(sys->set.down_delay_07*10)
				,(int)(sys->set.down_delay_08*10),(int)(sys->set.down_delay_09*10),(int)(sys->set.down_delay_10*10)
				,(int)(sys->set.down_delay_11*10),(int)(sys->set.down_delay_12*10),(int)(sys->set.down_delay_13*10)
				,(int)(sys->set.down_delay_14*10),(int)(sys->set.down_delay_15*10)); 
			if ( Set_Q_1CF4 (_WW_D, 0x01, 1370, 14, SwpSTR, &mPLC) < 0 )		continue;
		/*	memset(SwpSTR, 0x0, 255);
			Fmt (SwpSTR, "%s<%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]", 
				sys->set.tank02_H2O2_pump,
				sys->set.tank02_HCL_pump,
				sys->set.tank04_HF_pump,
				sys->set.tank04_HCL_pump); 
			if ( Set_Q_1CF4 (_WW_D, 0x01, 1062, 4, SwpSTR, &mPLC) < 0 )		continue;
			
			
			union DatCnv cnv1,cnv2;
			cnv1._I32 = sys->set.akfLowPos; 
			cnv2._I32 = sys->set.akfUpPos;
			memset(SwpSTR, 0x0, 255);
			Fmt (SwpSTR, "%s[a]<%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]", 
				cnv1._I16[0],
				cnv1._I16[1],
				cnv2._I16[0],
				cnv2._I16[1]);
			if ( Set_Q_1CF4 (_WW_D, 0x01, 1300, 4, SwpSTR, &mPLC) < 0 )		continue; */
			
			g_setupSetting = 0;
			
			LogPLCEvent(SETTING_PLC_EVENT);  
			
		}

		// ========================================================
		// ReSetup Make Data
		if (g_setupMake){
			Fmt (SwpSTR, "%s<%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]",
					0,(int)(sys->tk[TANK_02].MakeCH1*10.0), (int)(sys->tk[TANK_02].MakeCH2*10.0), (int)(sys->tk[TANK_02].MakeCH3*10.0),0,
					0,(int)(sys->tk[TANK_04].MakeCH1*10.0), (int)(sys->tk[TANK_04].MakeCH2*10.0), (int)(sys->tk[TANK_04].MakeCH3*10.0),(int)(sys->tk[TANK_04].MakeCH4),
					0,(int)(sys->tk[TANK_07].MakeCH1*10.0), (int)(sys->tk[TANK_07].MakeCH2*10.0), (int)(sys->tk[TANK_07].MakeCH3*10.0),(int)(sys->tk[TANK_07].MakeCH4),
					0,(int)(sys->tk[TANK_11].MakeCH1*10.0), (int)(sys->tk[TANK_11].MakeCH2*10.0), (int)(sys->tk[TANK_11].MakeCH3*10.0),0);
			if (Set_Q_1CF4 (_WW_D, 0x01, 1024, 20, SwpSTR, &mPLC) < 0)		continue;
					
			setBit(sys->hsRcpChange);
			setBit(g_makeBit);
			g_setupMake = 0;
			
			LogPLCEvent(MAKE_PLC_EVENT);
		}
		
		// ========================================================
		// ReSetup MMake Data
		if (g_setupMMake){
			Fmt (SwpSTR, "%s<%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]",
					(int)(sys->tk[TANK_02].MMakeCH1*10.0), (int)(sys->tk[TANK_02].MMakeCH2*10.0), (int)(sys->tk[TANK_02].MMakeCH3*10.0),
					(int)(sys->tk[TANK_04].MMakeCH1*10.0), (int)(sys->tk[TANK_04].MMakeCH2*10.0), (int)(sys->tk[TANK_04].MMakeCH3*10.0),(int)(sys->tk[TANK_04].MMakeCH4),
					(int)(sys->tk[TANK_07].MMakeCH1*10.0), (int)(sys->tk[TANK_07].MMakeCH2*10.0), (int)(sys->tk[TANK_07].MMakeCH3*10.0),(int)(sys->tk[TANK_07].MMakeCH4),
					(int)(sys->tk[TANK_11].MMakeCH1*10.0), (int)(sys->tk[TANK_11].MMakeCH2*10.0), (int)(sys->tk[TANK_11].MMakeCH3*10.0));
			if (Set_Q_1CF4 (_WW_D, 0x01, 1079, 14, SwpSTR, &mPLC) < 0)		continue;
					
			setBit(sys->hsRcpChange);
			setBit(g_mmakeBit);
			g_setupMMake = 0;
			
			LogPLCEvent(MAKE_PLC_EVENT);
		}
		
		
		//////////////////////////////////////////
		//
		if(g_writeTemp2Plc == 1)
		{
			g_writeTemp2Plc = 0;
			
			memset(SwpSTR, 0x0, sizeof(SwpSTR));
            Fmt (SwpSTR, "%s<%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]%i[r16w4p0]", 
                    (int)(sys->tk[TANK_AUX_PH1].curTemp*10.0), (int)(sys->tk[TANK_AUX_PH2].curTemp*10.0), 
					(int)(sys->tk[TANK_02].curTemp*10.0), (int)(sys->tk[TANK_03].curTemp*10.0), 
					(int)(sys->tk[TANK_04].curTemp*10.0), (int)(sys->tk[TANK_06].curTemp*10.0), 
					(int)(sys->tk[TANK_07].curTemp*10.0), (int)(sys->tk[TANK_09].curTemp*10.0),
                    (int)(sys->tk[TANK_10].curTemp*10.0), (int)(sys->tk[TANK_12].curTemp*10.0), 
					(int)(sys->tk[TANK_13].curTemp*10.0), (int)(sys->tk[TANK_14].curTemp*10.0), 
					(int)(sys->tk[TANK_15].curTemp*10.0), (int)(sys->tk[TANK_AUX_IN].curTemp*10.0), 
					(int)(sys->tk[TANK_16].curTemp*10.0), (int)(sys->tk[TANK_17].curTemp*10.0));

            if ( Set_Q_1CF4 (_WW_D, 0x01, 1620, 16, SwpSTR, &mPLC) < 0 )     continue;
		}
	}

	return 1;
}
 
void ChangFillStatus(BIT bt,int fill)
{
/*	Q2h.wB[20] = Q2h.rB[20];
	Q2h.wB[21] = Q2h.rB[21];
	
	if(fill > 0)
		setBit(bt);
	else
		resetBit(bt);
	
	setBit(sys->hsFillChange);   */
}  


#ifdef SIMULATE
void setRBit(BIT bt)
{
	Q2h.rB[bt.wid] |= bitvalue[bt.bid];	
}

void resetRBit(BIT bt)
{
	Q2h.rB[bt.wid] &= ~bitvalue[bt.bid];	
}
void setRXBit(BIT bt)
{
	Q2h.rX[bt.wid] |= bitvalue[bt.bid];	
}

void resetRXBit(BIT bt)
{
	Q2h.rX[bt.wid] &= ~bitvalue[bt.bid];	
}

void setRYBit(BIT bt)
{
	Q2h.rY[bt.wid] |= bitvalue[bt.bid];	
}

void resetRYBit(BIT bt)
{
	Q2h.rY[bt.wid] &= ~bitvalue[bt.bid];	
}
void SavePlcWB(void)
{
	char FileName[256];
	char Path[MAX_PATHNAME_LEN ];
	
	GetDir(Path);
	Fmt(FileName,"%s<%s\\plc.dat",Path);
	int fSAVE = OpenFile (FileName, VAL_WRITE_ONLY, VAL_TRUNCATE, VAL_BINARY);
	if(fSAVE > 0)
	{
		WriteFile(fSAVE,(char*)Q2h.rB,sizeof(Q2h.rB));
		CloseFile (	fSAVE );
	}
}

void RestorePlcWB(void)
{
	char FileName[256];
	char Path[MAX_PATHNAME_LEN ];
	
	GetDir(Path);
	Fmt(FileName,"%s<%s\\plc.dat",Path);
	int fSAVE = OpenFile (FileName, VAL_READ_ONLY, VAL_TRUNCATE, VAL_BINARY);
	if(fSAVE > 0)
	{
		unsigned short	rB[32];
		ReadFile(fSAVE,(char*)rB,sizeof(rB));
		CloseFile (	fSAVE );
		
		Q2h.rB[19] = rB[19];
		Q2h.rB[20] = rB[20];
		Q2h.rB[21] = rB[21];
	}
	
	
}

#endif

static int plcLock;

void closePlc(void)
{
	CmtDiscardLock(plcLock);	
}

int openPlc(void)
{
	CmtNewLock(NULL, OPT_TL_PROCESS_EVENTS_WHILE_WAITING, &plcLock); 
	
	mPLC.COM	= 1;
	mPLC.Bau	= 57600;
	mPLC.Par	= 0;		// 0:None	1:??OOD	2:??EVEN
	mPLC.Dbit	= 8;		// 5 - 8 bit
	mPLC.Sbit	= 1;		// 1 - 2 bit
	mPLC.Hctl	= 1;		// 0:None	1:CTS/RTS/DTR	2:CTS/RTS
	mPLC.Tout	= 0.05;
	mPLC.useNet	= 0x00;
	mPLC.PlcID	= 0x00;
	mPLC.NetID	= 0xFF;

	if (Cfg_Q_1CF4(&mPLC) < 0)
	{
		SendPcAlarm(PCA_PLC_BID,1); 
		return 0;
	}
	
	
	
	return 1;
}

int readHandshake(void)
{
	CmtGetLock(plcLock);
	if(Get_Q_1CF4 (_WR_D, 0x00, 900, 10, &mPLC) < 0)
	{
		CmtReleaseLock(plcLock);
		return -1;
	}
	
	
	int DatSFT = 0;
	for (int cLop = 0; cLop < 10; cLop++){
		Scan ( mPLC.DTRN, "%s[i*w4]>%x[b2]", DatSFT, &Q2h.rD[cLop]);
		DatSFT += 4;
	}
	
	CmtReleaseLock(plcLock);
	
	
	return 0;
}

void writeHandshake(int len)
{
	if(len > MAX_HANDSHAKE_LEN){
		MessagePopup("message","写入数据太长");
		return;
	}
	
	CmtGetLock(plcLock);
	
	if(Get_Q_1CF4 (_WR_D, 0x00, 900, 1, &mPLC) < 0)
	{
		CmtReleaseLock(plcLock);
		
		MessagePopup("message","读取PLC出错");
		return;
	}
	
	
	int DatSFT = 0;
	for (int cLop = 0; cLop < 1; cLop++){
		Scan ( mPLC.DTRN, "%s[i*w4]>%x[b2]", DatSFT, &Q2h.rD[cLop]);
		DatSFT += 4;
	}
	if(Q2h.rD[0]%10 != 0){
		
		CmtReleaseLock(plcLock);
		
		MessagePopup("message","PLC忙");
		return;
	}
	
	char SwpSTR[1024];
	for(int i=0;i<len;i++)
		Fmt (SwpSTR, "%s[a]<%i[r16w4p0]", Q2h.wB[i]);
	StringUpperCase (SwpSTR);
	if(Set_Q_1CF4 (_WW_D, 0x00, 900, len, SwpSTR, &mPLC) < 0)
		MessagePopup("message","写入PLC出错");
	
	CmtReleaseLock(plcLock); 
	

}

int readRobotStatus(int rid,unsigned int* data)
{
    CmtGetLock(plcLock);
	if(Get_Q_1CF4 (_WR_D, 0x00, 500+rid*38, 38, &mPLC) < 0)
	{
		CmtReleaseLock(plcLock);
		return -1;
	}
		
	int DatSFT = 0;
	for (int cLop = 0; cLop < 38; cLop++){
		Scan ( mPLC.DTRN, "%s[i*w4]>%x[b2]", DatSFT, &data[cLop]);
		DatSFT += 4;
	}
	
/*	int j = 0;
	union DatCnv cnv;  
	
	cnv._I16[0] = Q2h.rD[j++]; 
	cnv._I16[1] = Q2h.rD[j++];
	sys->rb[rid].curPosX = cnv._I32;

	cnv._I16[0] = Q2h.rD[j++]; 
	cnv._I16[1] = Q2h.rD[j++];
	sys->rb[rid].curPosY = cnv._I32;
*/		
	
	CmtReleaseLock(plcLock);  
	
	return 0;
}


int readTankPos(int tid)
{
    CmtGetLock(plcLock);
	if(Get_Q_1CF4 (_WR_D, 0x00, 1000+tid*12, 12, &mPLC) < 0)
	{
		CmtReleaseLock(plcLock);
		return -1;
	}
	
		
	int DatSFT = 0;
	for (int cLop = 0; cLop < 12; cLop++){
		Scan ( mPLC.DTRN, "%s[i*w4]>%x[b2]", DatSFT, &Q2h.rD[cLop]);
		DatSFT += 4;
	}
	
	int j = 0;
	union DatCnv cnv;  
	
	cnv._I16[0] = Q2h.rD[j++]; 
	cnv._I16[1] = Q2h.rD[j++];
	sys->rtk[tid].xLock = cnv._I32;

	cnv._I16[0] = Q2h.rD[j++]; 
	cnv._I16[1] = Q2h.rD[j++];
	sys->rtk[tid].xUnlock = cnv._I32;
		
	cnv._I16[0] = Q2h.rD[j++]; 
	cnv._I16[1] = Q2h.rD[j++];
	sys->rtk[tid].zDown = cnv._I32;
	
	cnv._I16[0] = Q2h.rD[j++]; 
	cnv._I16[1] = Q2h.rD[j++];
	sys->rtk[tid].xLock2 = cnv._I32;

	cnv._I16[0] = Q2h.rD[j++]; 
	cnv._I16[1] = Q2h.rD[j++];
	sys->rtk[tid].xUnlock2 = cnv._I32;
		
	cnv._I16[0] = Q2h.rD[j++]; 
	cnv._I16[1] = Q2h.rD[j++];
	sys->rtk[tid].zDown2 = cnv._I32;
	
	CmtReleaseLock(plcLock);  
	
	return 0;
}
