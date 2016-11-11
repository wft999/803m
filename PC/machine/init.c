//==============================================================================
//
// Title:       init.c
// Purpose:     A short description of the implementation.
//
// Created on:  2014/7/15 at ¤W¤È 08:39:17 by wang fang.
// Copyright:   hua. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files
#include <formatio.h>

#include "type.h"

//==============================================================================
// Constants

//==============================================================================
// Types

//==============================================================================
// Static global variables

//==============================================================================
// Static functions

//==============================================================================
// Global variables
int InitLog (void);
void UninitLog(void);
void closePlc(void);
int openPlc(void);
//==============================================================================
// Global functions

int initTankData(void)
{
	char FileName[256];
	char Path[MAX_PATHNAME_LEN ];
	
	GetDir(Path);
	Fmt(FileName,"%s<%s\\pos.dat",Path);
	int fSAVE = OpenFile (FileName, VAL_READ_ONLY, VAL_TRUNCATE, VAL_BINARY);
	if(fSAVE > 0)
	{
		ReadFile(fSAVE,(char*)sys->tkPos,sizeof(sys->tkPos));
		CloseFile (	fSAVE );
		return 1;
	}
	
	return 0;
}



void InitAlarm(void)
{
	char projectDir[MAX_PATHNAME_LEN];
    char fullPath[MAX_PATHNAME_LEN];
	memset(fullPath, 0,  MAX_PATHNAME_LEN);

    if (GetProjectDir (projectDir) < 0)
        return;
    else
        MakePathname (projectDir, "alarmlist.csv", fullPath);

    int hfile;
    char lineBuffer[512];
	
	hfile = OpenFile(fullPath,VAL_READ_ONLY,VAL_OPEN_AS_IS,VAL_ASCII);
    if(hfile < 0)
        return;
	int i = 0;
	while(i < MAX_ALARM_NUM && ReadLine (hfile, lineBuffer, 510) >= 0)
	{
		if(strcmp(lineBuffer,"") == 0)
		{
			sys->alarmDesc[i] = malloc(strlen("spare") + 1);
			if(sys->alarmDesc[i] != NULL) 
				strcpy(sys->alarmDesc[i], "Spare");
		}
		else
		{
			sys->alarmDesc[i] = malloc(strlen(lineBuffer) + 1);
			if(sys->alarmDesc[i] != NULL) 
				strcpy(sys->alarmDesc[i], lineBuffer); 
		}
		
		i++;
	}
	CloseFile(hfile);
	
}

void SaveSystem(void)
{
	char FileName[256];
	char Path[MAX_PATHNAME_LEN ];
	
	GetDir(Path);
	Fmt(FileName,"%s<%s\\system.dat",Path);
	int fSAVE = OpenFile (FileName, VAL_WRITE_ONLY, VAL_TRUNCATE, VAL_BINARY);
	if(fSAVE > 0)
	{
		WriteFile(fSAVE,(char*)sys,sizeof(SYSTEM));
		CloseFile (	fSAVE );
	}
}

void RestoreSystem(void)
{
/*	char FileName[256];
	char Path[MAX_PATHNAME_LEN ];
	
	GetDir(Path);
	Fmt(FileName,"%s<%s\\system.dat",Path);
	int fSAVE = OpenFile (FileName, VAL_READ_ONLY, VAL_TRUNCATE, VAL_BINARY);
	if(fSAVE > 0)
	{
		SYSTEM s;
		ReadFile(fSAVE,(char*)&s,sizeof(SYSTEM));
		CloseFile (	fSAVE );
		
		memcpy(&sys->set,&s.set, sizeof(SETTING));
		
		sys->rcp.ID = s.rcp.ID;
		for(int i = 0; i < ROBOT_NUM; i++)
			sys->rb[i].car = s.rb[i].car;
		
		for(int i = 0; i < RTANK_NUM; i++)
			sys->rtk[i].car = s.rtk[i].car;
		
		for(int i = 0; i < PRO_TANK_NUM; i++)
		{
			sys->tk[i].carNumber = s.tk[i].carNumber;
			sys->tk[i].rcp.ProcTM = s.tk[i].rcp.ProcTM; 
			sys->tk[i].rcp.PreGetTM = s.tk[i].rcp.PreGetTM;
			
			sys->tk[i].runAC1Dos = s.tk[i].runAC1Dos;
			sys->tk[i].runAC2Dos = s.tk[i].runAC2Dos;
			sys->tk[i].runAC3Dos = s.tk[i].runAC3Dos;
			sys->tk[i].runAC4Dos = s.tk[i].runAC4Dos;
			
			sys->tk[i].lifeRun = s.tk[i].lifeRun;
			sys->tk[i].lifeTime = s.tk[i].lifeTime;
			sys->tk[i].autoMakeStep = s.tk[i].autoMakeStep;
			
		}
	}
	else
	{
		for(int i = 0; i < PRO_TANK_NUM; i++)
		{
			GetCurrentDateTime ( &sys->tk[i].lifeTime);
			sys->tk[i].lifeTime += 60 * 6000;
			sys->tk[i].lifeRun = 100;
			sys->tk[i].autoMakeStep = 0; 
		}
	}
	
	sys->set.auth[4][0] = OP_RCP;
	sys->set.auth[4][1] = OP_TANK;
	sys->set.auth[4][2] = OP_ROBOT;
	sys->set.auth[4][3] = OP_SET;
	sys->set.auth[4][4] = OP_EXIT;
	sys->set.auth[4][5] = OP_USER;	  */
}

int initSystem(void)
{
	sys = (SYSTEM*)malloc(sizeof(SYSTEM));
	memset(sys,0,sizeof(SYSTEM));
	
	
//	RestoreSystem();
	initTankData();
//	initRobotData();
	

	InitAlarm();
	InitLog();
	
	openPlc();
	ActionLog(SYS_START,0,0,0,0,0);
	
	strcpy(sys->user.name,"test");
	sys->user.type = SUP_USER;
	
    return 1;
}

void unInitSystem(void)
{
	closePlc();
//	SaveSystem();
	
	for(int i = 0; i < MAX_ALARM_NUM; i++)
	{
		if(sys->alarmDesc[i] != NULL)
			free(sys->alarmDesc[i]);

	}
	
	UninitLog();
	
	free(sys);
}
