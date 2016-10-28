//==============================================================================
//
// Title:       rkc.c
// Purpose:     A short description of the implementation.
//
// Created on:  2014/7/23 at ¤W¤È 10:04:05 by wang fang.
// Copyright:   hua. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files

//#include "rkc.h"

#include <formatio.h>
#include <rs232.h>
#include "type.h"


//==============================================================================
// Constants
#define _STX	0x02
#define _ETX	0x03
#define _EOT	0x04
#define _ENQ	0x05
#define _ACK	0x06
#define _NAK	0x15

#define	Config	0x00

#define getTP	0x10
#define getSP	0x11
#define getAL1	0x12
#define getAL2	0x13
#define	getAT	0x14
#define	getST	0x15

#define	setRUN  0x20
#define setSP	0x21
#define setAL1	0x22
#define setAL2	0x23
#define setAT   0x24
#define setST   0x25
#define setPB   0x26
//==============================================================================
// Types
typedef struct
{
	int		COM;
	int		Baud;	// 19200;
	int		Pari;	// None
	int		Dbit;	// 8bit
	int		Sbit;	// 1bit
	int		Flc;	// NoneHW
	double	Tout;	// 0.050
} RKCcomm;
//==============================================================================
// Static global variables

//==============================================================================
// Static functions
static RKCcomm rkc;
//==============================================================================
// Global variables
int g_writeTemp2Plc = 0;
int g_setupTemp = 0; 
extern int g_exitThread;

//==============================================================================
// Global functions

int RKC_CommData ( int _ACT, int _ID, double *_Val)
{
	int rLop = 0;
	int RTNval = 0;
	int BuffLEN = 0;
	char Buff[128]={0};
	char BBC = 0x00;
	char dTRN[64] = {0};
	static int Rs232Err = 0, NullPort = 0;
	
	switch (_ACT)
	{
		case Config:
			CloseCom(rkc.COM);
			if (Rs232Err = ReturnRS232Err (), Rs232Err < 0)
				return  Rs232Err;
			
			OpenComConfig(rkc.COM, "", rkc.Baud, rkc.Pari, rkc.Dbit, rkc.Sbit, 512, 512);
			if (Rs232Err = ReturnRS232Err (), Rs232Err < 0)
			{
				NullPort = 1;
				return  Rs232Err;
			}
			
			SetCTSMode(rkc.COM, rkc.Flc);
			if (Rs232Err = ReturnRS232Err (), Rs232Err < 0)
				return  Rs232Err;

			SetComTime(rkc.COM, rkc.Tout);
			if (Rs232Err = ReturnRS232Err (), Rs232Err < 0)
				return  Rs232Err;
			
			NullPort = 0;
		break;
			
		case getTP:
			
			Fmt(Buff, "%c%i[w2p0]%s[w2]%c", _EOT, (_ID & 0xFF), "M1", _ENQ);
			// MessagePopup("getTP",Buff);  //DJ_Added_0502KB_12_57
			
			break;
											   
		case getSP:
			Fmt(Buff, "%c%i[w2p0]%s[w2]%c", _EOT, (_ID & 0xFF), "S1", _ENQ);
		break;

		case getAL1:
			Fmt(Buff, "%c%i[w2p0]%s[w2]%c", _EOT, (_ID & 0xFF), "A1", _ENQ);
		break;

		case getAL2:
			Fmt(Buff, "%c%i[w2p0]%s[w2]%c", _EOT, (_ID & 0xFF), "A2", _ENQ);
		break;

		case getAT:
			Fmt(Buff, "%c%i[w2p0]%s[w2]%c", _EOT, (_ID & 0xFF), "G1", _ENQ);
		break;

		case getST:
			Fmt(Buff, "%c%i[w2p0]%s[w2]%c", _EOT, (_ID & 0xFF), "G2", _ENQ);
		break;

		case setRUN:
			Fmt(Buff, "%c%i[w2p0]%c%s[w2]%f[p1]%c", _EOT, (_ID & 0xFF), _STX, "SR", *_Val, _ETX);
		break;

		case setSP:
			Fmt(Buff, "%c%i[w2p0]%c%s[w2]%f[p1]%c", _EOT, (_ID & 0xFF), _STX, "S1", *_Val, _ETX);
		break;

		case setAL1:
			Fmt(Buff, "%c%i[w2p0]%c%s[w2]%f[p1]%c", _EOT, (_ID & 0xFF), _STX, "A1", *_Val, _ETX);
		break;

		case setAL2:
			Fmt(Buff, "%c%i[w2p0]%c%s[w2]%f[p1]%c", _EOT, (_ID & 0xFF), _STX, "A2", *_Val, _ETX);
		break;

		case setAT:
			Fmt(Buff, "%c%i[w2p0]%c%s[w2]%f[p1]%c", _EOT, (_ID & 0xFF), _STX, "G1", *_Val, _ETX);
		break;

		case setST:
			Fmt(Buff, "%c%i[w2p0]%c%s[w2]%f[p1]%c", _EOT, (_ID & 0xFF), _STX, "G2", *_Val, _ETX);
		break;
			
		case setPB:
			Fmt(Buff, "%c%i[w2p0]%c%s[w2]%f[p1]%c", _EOT, (_ID & 0xFF), _STX, "PB", *_Val, _ETX);
		break;
	}

	if (NullPort)
	{
		*_Val = 0.00;
	}
	
	// Command Transfer Process
	if ((_ACT > 0x1F) && (NullPort == 0))
	{
		// ========================================================= [ Set RKC Data ]
		// Flush Out Queue
		FlushOutQ (rkc.COM);
		Delay(0.5);
		
		// Count Buffer Length
		BuffLEN = StringLength (Buff);
		// Calc BBC
		BBC = 0x00;
		for (rLop=4; rLop < BuffLEN; rLop++)	BBC ^= Buff[rLop];
		// Append BBC
		Fmt ( Buff, "%s[a]<%c", BBC); 
		BuffLEN +=1;
		// Sending Command
		ComWrt ( rkc.COM, Buff, BuffLEN);
		
		// Flush In Queue	
		FlushInQ (rkc.COM);
		Delay(0.5);
		ComRd (rkc.COM, dTRN, 1);

		if (dTRN[0] == 0x06)
			RTNval =   0;	// Sending OK
		else if (dTRN[0] == 0x15)
			RTNval = -10;	// Sending Lost
		else	
			RTNval =  -1;	// Connect Lost
	} 
	else if ((_ACT > 0x0F) && (NullPort == 0))
	{
		// ========================================================= [ Get RKC Data ]
		// Flush OUT Queue	
		FlushOutQ (rkc.COM);
		Delay(0.5);

		// Send CMD
		ComWrt ( rkc.COM, Buff, 6);
		
		// Flush IN Queue
		FlushInQ (rkc.COM);
		Delay(0.5);

		// Receive CMD
		dTRN[0] = 0x00;
		ComRd (rkc.COM, dTRN, 11);
		Rs232Err = ReturnRS232Err();
		if (ReturnRS232Err() == 0)
			Scan (dTRN ,"%s[i5]>%f", _Val);


		Delay(0.5);
		Fmt ( Buff, "%c%c", _EOT, 0x00);
		ComWrt (rkc.COM, Buff, 1);	
	}
	return RTNval;
}

int CVICALLBACK rkcThread (void *Data)
{
	rkc.COM  = 3;
	rkc.Baud = 19200;
	rkc.Pari = 0;
	rkc.Dbit = 8;
	rkc.Sbit = 1;
	rkc.Flc  = 0;
	rkc.Tout = 0.050;

	if(RKC_CommData ( Config, 0, NULL) != 0)
	{
		SendPcAlarm(PCA_RKC_BID,1); 
		return 0;	
	}
	
	PTANK * tk[16] = {
		&sys->tk[TANK_AUX_PH1],
		&sys->tk[TANK_AUX_PH2],
		&sys->tk[TANK_02],
		&sys->tk[TANK_03],
		&sys->tk[TANK_04],
		&sys->tk[TANK_06],
		&sys->tk[TANK_07],
		&sys->tk[TANK_09],
		&sys->tk[TANK_10],
		&sys->tk[TANK_12],
		&sys->tk[TANK_13],
		&sys->tk[TANK_14],
		&sys->tk[TANK_15],
		&sys->tk[TANK_AUX_IN],
		&sys->tk[TANK_16],
		&sys->tk[TANK_17]};
	
	int cnt = 0;
	while (g_exitThread == 0){
		Delay(30);
		
		if (g_setupTemp == 1)
		{
			// =====================================================
			// Write Temperature SetPoint
			for(int i = 0; i < 16;i++)
			{
				RKC_CommData(setSP, i+1, &tk[i]->rcp.Temp);	Delay(0.5);
				RKC_CommData(setAL1,i+1, &tk[i]->rcp.TempL);	Delay(0.5);
				RKC_CommData(setAL2,i+1, &tk[i]->rcp.TempH);	Delay(0.5);
				RKC_CommData(setPB,i+1, &tk[i]->rcp.TempP);	Delay(0.5);
			}

					
			g_setupTemp = 0;
		}
		
		cnt++; 
		if(cnt >= 2)
		{
			cnt = 0;
			if(sys->curTempTrendPos >= TREND_DATA_LEN - 1)
				sys->curTempTrendPos = 0;
			else
				sys->curTempTrendPos++;
		}
		
		for(int i = 0; i < 16;i++)
		{
			RKC_CommData ( getTP, i+1, &tk[i]->curTemp);
			if(cnt == 0 && tk[i]->curTemp != 0)
				tk[i]->tempData[sys->curTempTrendPos] = tk[i]->curTemp;
			if(g_exitThread)
				return 0;
		}
		sys->tk[TANK_05].curTemp = sys->tk[TANK_04].curTemp;
		sys->tk[TANK_08].curTemp = sys->tk[TANK_07].curTemp;
		
		if(g_writeTemp2Plc == 0)
			g_writeTemp2Plc = 1;
		
		if(sys->tk[TANK_AUX_PH1].curTemp >= sys->tk[TANK_AUX_PH1].rcp.StartTemp)
			setBit(sys->tk[TANK_AUX_PH1].hsPHStart);
		else if(sys->tk[TANK_AUX_PH1].curTemp < sys->tk[TANK_AUX_PH1].rcp.StopTemp)
			resetBit(sys->tk[TANK_AUX_PH1].hsPHStart);
		
		if(sys->tk[TANK_AUX_PH2].curTemp >= sys->tk[TANK_AUX_PH2].rcp.StartTemp)
			setBit(sys->tk[TANK_AUX_PH2].hsPHStart);
		else if(sys->tk[TANK_AUX_PH2].curTemp < sys->tk[TANK_AUX_PH2].rcp.StopTemp)
			resetBit(sys->tk[TANK_AUX_PH2].hsPHStart);

	}
	
	return 0;
}
