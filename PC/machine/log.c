#include <cviauto.h>
#include "msie.h"
#include <userint.h>
#include "robot_panel.h"
#include "base64.h"
//==============================================================================
//
// Title:       log.c
// Purpose:     A short description of the implementation.
//
// Created on:  2014/7/20 at 下午 01:20:27 by wang fang.
// Copyright:   hua. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files

//#include "log.h"
#include <formatio.h>
#include "type.h"
#include "main.h"

//==============================================================================
// Constants
#define MAX_ITEMS_IN_QUEUE 1000
//#define MAX_ITEMS_IN_QUEUE_READ_BLOCK 50
//#define MAX_ITEMS_IN_QUEUE_WRITE_BLOCK 500
#define READ_THREAD_WAIT_TIME 0 
#define PHPCOMD "d:\\server\\php\\php.exe D:\\server\\moodle\\shunfeng\\yii.php"
extern const unsigned short bitvalue[];
//==============================================================================
// Types

//==============================================================================
// Static global variables
static int tsqHandle;
static int getLogCallbackID;
static int logLockHandle;
             
//==============================================================================
// Static functions

//==============================================================================
// Global variables
 extern int panelHandle; 
//==============================================================================
// Global functions
 
void PutLogToQueue(LOG* log, int numItems)
{
	CmtGetLock(logLockHandle);
	CmtWriteTSQData (tsqHandle, log, numItems,0, NULL);
	CmtReleaseLock(logLockHandle);
}

void ActionLog(ACT_EVENT_TYPE etype,int data1,int data2,int data3,int data4,int data5)
{
/*	char tmp[256];
	char content[256];
	switch(etype)
	{
		case TANK_MAKE_ACT_EVENT:
			if(data2 == 1)
			{
				int i = 0;
				char* schem[3][4] = {{"H2O2","KOH","DIW",""}, {"IPA","KOH","DIW","ADD"}, {"HF","HCL","DIW",""}};
				if(data1 == TANK_02)
					i = 0;
				else if(data1 == TANK_04 || data1 == TANK_07)
					i = 1; 
				else if(data1 == TANK_11)
					i = 2;
				Fmt(tmp,"%s<啟動自動配槽(%s:%f[p1],%s:%f[p1],%s:%f[p1],%s:%f[p1])",
					schem[i][0],sys->tk[data1].MakeCH1,
					schem[i][1],sys->tk[data1].MakeCH2,
					schem[i][2],sys->tk[data1].MakeCH3,
					schem[i][3],sys->tk[data1].MakeCH4);
			}
			else
				Fmt(tmp,"%s<取消自動配槽");
			break;
		case TANK_MMAKE_ACT_EVENT:
			if(data2 == 1)
			{
				int i = 0;
				char* schem[3][4] = {{"H2O2","KOH","DIW",""}, {"IPA","KOH","DIW","ADD"}, {"HF","HCL","DIW",""}};
				if(data1 == TANK_02)
					i = 0;
				else if(data1 == TANK_04 || data1 == TANK_07)
					i = 1; 
				else if(data1 == TANK_11)
					i = 2;
				Fmt(tmp,"%s<啟動手動配槽(%s:%f[p1],%s:%f[p1],%s:%f[p1],%s:%f[p1])",
					schem[i][0],sys->tk[data1].MMakeCH1,
					schem[i][1],sys->tk[data1].MMakeCH2,
					schem[i][2],sys->tk[data1].MMakeCH3,
					schem[i][3],sys->tk[data1].MMakeCH4);
			}
			else
				Fmt(tmp,"%s<取消手動配槽");
			break;
		case TANK_DOS_ACT_EVENT:
			if(data3 == 1)
			{
				Fmt(tmp,"%s<啟動補液(CH%d)",data2);
				DosingLog(DOSING_BY_MANUAL,data1,data2,sys->tk[data1].carNumber);
			}
			else
				Fmt(tmp,"%s<取消補液(CH%d)",data2);
			break;
			
		case TANK_WASH_ACT_EVENT:
			if(data2 == 1)
				Fmt(tmp,"%s<啟動洗槽");
			else
				Fmt(tmp,"%s<取消洗槽");
			break;
			
		case TANK_DOWN_ACT_EVENT:
			if(data2 == 1)
				Fmt(tmp,"%s<啟動當槽");
			else
				Fmt(tmp,"%s<取消當槽");
			break;
			
		case TANK_DRAIN_ACT_EVENT:
			if(data2 == 1)
				Fmt(tmp,"%s<啟動快排");
			else
				Fmt(tmp,"%s<取消快排");
			break;
			
		case TANK_PUMP_ACT_EVENT:
			if(data2 == 1)
				Fmt(tmp,"%s<啟動Pump");
			else
				Fmt(tmp,"%s<停止Pump");
			break;
			
		case TANK_HEAT_ACT_EVENT:
			if(data2 == 1)
				Fmt(tmp,"%s<啟動加熱");
			else
				Fmt(tmp,"%s<停止加熱");
			break;
			
		case TANK_ADD_WATER_ACT_EVENT:
			if(data2 == 1)
				Fmt(tmp,"%s<啟動補水");
			else
				Fmt(tmp,"%s<停止補水");
			break;	
			
		case TANK_SHUT_ACT_EVENT:
			if(data2 == 1)
				Fmt(tmp,"%s<開啟上蓋");
			else
				Fmt(tmp,"%s<關閉上蓋");
			break;
			
		case TANK_BUBB_ACT_EVENT:
			if(data2 == 1)
				Fmt(tmp,"%s<啟動氣泡");
			else
				Fmt(tmp,"%s<停止氣泡");
			break;
			
		case TANK_CAR_ACT_EVENT:
			if(data2 == 1)
				Fmt(tmp,"%s<添加帳料");
			else
				Fmt(tmp,"%s<刪除帳料");
			break;
			
		case ULD_DOOR_ACT_EVENT:
			if(data2 == 1)
				Fmt(tmp,"%s<開啟自動門");
			else
				Fmt(tmp,"%s<關閉自動門");
			break;
			
		case ULD_INIT_ACT_EVENT:
			if(data2 == 1)
				Fmt(tmp,"%s<啟動氣壓缸復歸");
			else
				Fmt(tmp,"%s<取消氣壓缸復歸");
			break;
			
		case AKF_UP_ACT_EVENT:
			Fmt(tmp,"%s<AKF上");
			break;
		case AKF_DOWN_ACT_EVENT:
			Fmt(tmp,"%s<AKF下");
			break;
		case AKF_HOME_ACT_EVENT:
			Fmt(tmp,"%s<AKF復歸");
			break;	
		case AKF_AUTO_ACT_EVENT:
			if(data2 == 1)
				Fmt(tmp,"%s<AKF自動");
			else
				Fmt(tmp,"%s<AKF手動");
			break;	
			
		case ULD_UP_ACT_EVENT:
			Fmt(tmp,"%s<汽缸上");
			break;
		case ULD_DOWN_ACT_EVENT:
			Fmt(tmp,"%s<汽缸下");
			break;
		case ULD_LEFT_ACT_EVENT:
			Fmt(tmp,"%s<汽缸左");
			break;
		case ULD_RIGHT_ACT_EVENT:
			Fmt(tmp,"%s<汽缸右");
			break;
			
		case CV_AUTO_ACT_EVENT:
			if(data2 == 1)
				Fmt(tmp,"%s<傳送帶自動");
			else
				Fmt(tmp,"%s<傳送帶手動");
			data1 = -1;
			break;
			
		case CV_ON_ACT_EVENT:
			if(data2 == 1)
				Fmt(tmp,"%s<傳送帶啟動");
			else
				Fmt(tmp,"%s<傳送帶停止");
			data1 = -1;
			break;	
		
		case SET_SAVE_ACT_EVENT:
			Fmt(tmp,"%s<修改系統設定");
			data1 = -1;
			break;
			
		case RCP_SEL_ACT_EVENT:
			Fmt(tmp,"%s<啟用Recipe:%d",data1);
			data1 = -1;
			break;
			
		case RCP_SAVE_ACT_EVENT:
			Fmt(tmp,"%s<修改Recipe:%d",data1);
			data1 = -1;
			break;
			
		case RB_CHUCK_ACT_EVENT:
			if(data2 == 1)
				Fmt(tmp,"%s<啟動%sChuck",sys->rb[data1].name);
			else
				Fmt(tmp,"%s<取消%sChuck",sys->rb[data1].name);
			data1 = -1;
			break;
			
		case RB_TEACH_ACT_EVENT:
			if(data2 == 1)
				Fmt(tmp,"%s<啟動%sTeachBox",sys->rb[data1].name);
			else
				Fmt(tmp,"%s<取消%sTeachBox",sys->rb[data1].name);
			data1 = -1;
			break;
			
		case RB_CAR_ACT_EVENT:
			if(data2 == 1)
				Fmt(tmp,"%s<添加%s帳料",sys->rb[data1].name);
			else
				Fmt(tmp,"%s<刪除%s帳料",sys->rb[data1].name);
			data1 = -1;
			break;	
			
		case RB_PUT_ACT_EVENT:
			Fmt(tmp,"%s<%s置料",sys->rb[data1].name);
			data1 = sys->rtk[data2].tid;
			break;
		case RB_GET_ACT_EVENT:
			Fmt(tmp,"%s<%s取料",sys->rb[data1].name);
			data1 = sys->rtk[data2].tid;
			break;
		case RB_MOVE_ACT_EVENT:
			Fmt(tmp,"%s<%s移載",sys->rb[data1].name);
			data1 = sys->rtk[data2].tid;
			break;
		case RB_HOME_ACT_EVENT:
			Fmt(tmp,"%s<%s原點",sys->rb[data1].name);
			data1 = -1;
			break;
		case RB_CLEAN_ACT_EVENT:
			Fmt(tmp,"%s<%s吹乾",sys->rb[data1].name);
			data1 = -1;
			break;
			
		case RB_UP_ACT_EVENT:
			Fmt(tmp,"%s<%s上",sys->rb[data1].name);
			data1 = -1;
			break;
		case RB_DOWN_ACT_EVENT:
			Fmt(tmp,"%s<%s下",sys->rb[data1].name);
			data1 = -1;
			break;
		case RB_LEFT_ACT_EVENT:
			Fmt(tmp,"%s<%s左",sys->rb[data1].name);
			data1 = -1;
			break;
		case RB_RIGHT_ACT_EVENT:
			Fmt(tmp,"%s<%s右",sys->rb[data1].name);
			data1 = -1;
			break;
			
		case RB_UUP_ACT_EVENT:
			Fmt(tmp,"%s<%s高速上",sys->rb[data1].name);
			data1 = -1;
			break;
		case RB_DDOWN_ACT_EVENT:
			Fmt(tmp,"%s<%s高速下",sys->rb[data1].name);
			data1 = -1;
			break;
		case RB_LLEFT_ACT_EVENT:
			Fmt(tmp,"%s<%s高速左",sys->rb[data1].name);
			data1 = -1;
			break;
		case RB_RRIGHT_ACT_EVENT:
			Fmt(tmp,"%s<%s高速右",sys->rb[data1].name);
			data1 = -1;
			break;	
			
		case RB_POS_SAVE_ACT_EVENT:
			if(data2 == 0)
				Fmt(tmp,"%s<%s變更夾爪%s脫鉤位置",sys->rb[data1].name,sys->rtk[data3].name);
			else if(data2 == 1)
				Fmt(tmp,"%s<%s變更夾爪%s掛入位置 ",sys->rb[data1].name,sys->rtk[data3].name);
			else
				Fmt(tmp,"%s<%s變更移載安全高度",sys->rb[data1].name);
			data1 = -1;
			break;
			
		case USER_LOGIN_EVENT:
			data1 = -1;
			Fmt(tmp,"%s<登入");
			break;
		case USER_LOGOUT_EVENT:
			data1 = -1;
			Fmt(tmp,"%s<登出");
			break;
		case USER_EXIT_EVENT:
			data1 = -1;
			Fmt(tmp,"%s<退出系統");
			break;
			
		case SYS_START:
			data1 = -1;
			Fmt(tmp,"%s<啟動系統");
			break;
		case SYS_MANUAL:
			data1 = -1;
			Fmt(tmp,"%s<系統手動");
			break;
		case SYS_AUTO:
			data1 = -1;
			Fmt(tmp,"%s<系統自動");
			break;
			
			
	}
	
	char str[256];
	char encode[256];
	char encode1[256]; 
	unicode_to_utf8(tmp,encode,256);
	Base64Encode(encode,strlen(encode),encode1); 
	if(data1 >= 0)
		sprintf(str,"%s operation/insert %s %s %s",PHPCOMD,sys->user.name,sys->tk[data1].name,encode1);
	else
		sprintf(str,"%s operation/insert %s system %s",PHPCOMD,sys->user.name,encode1);
	LaunchExecutableEx(str,LE_HIDE,NULL);  */
}

void DosingLog(DOSING_TYPE type,TANK_ID tid, unsigned int chem, unsigned int carNumber)
{
/*	int i = 0;
	char tmp[256];
	char* stype[] = {"ByRunDosing","ByTimeDosing","ManualDosing","PartialDrain","ManualMixAcid","AutoMixAcid"}; 
	
	char* schem[3][4] = {{"H2O2","KOH","DIW",""}, {"IPA","KOH","DIW","ADD"}, {"HF","HCL","DIW",""}};
	if(tid == TANK_02)
		i = 0;
	else if(tid == TANK_04 || tid == TANK_07)
		i = 1; 
	else if(tid == TANK_11)
		i = 2;
	
	double vol = 0;
	if(type == DOSING_BY_RUN || type == DOSING_BY_TIME || type == DOSING_BY_MANUAL)
	{
		if(chem == 1)
			vol = sys->tk[tid].rcp.DosCH1;
		else if(chem == 2)
			vol = sys->tk[tid].rcp.DosCH2;
		else if(chem == 3)
			vol = sys->tk[tid].rcp.DosCH3;
		else if(chem == 4)
			vol = sys->tk[tid].rcp.DosCH4;
		else
			vol = 0;
	}
	else if(type == PARTIAL_DRAIN )
	{
		if(chem == 1)
			vol = sys->tk[tid].rcp.PdCH1;
		else if(chem == 2)
			vol = sys->tk[tid].rcp.PdCH2;
		else if(chem == 3)
			vol = sys->tk[tid].rcp.PdCH3;
		else if(chem == 4)
			vol = sys->tk[tid].rcp.PdCH4;
		else
			vol = 0;
	}
	else if(type == MANUAL_MIX_ACID )
	{
		if(chem == 1)
			vol = sys->tk[tid].MMakeCountCH1/10.0;
		else if(chem == 2)
			vol = sys->tk[tid].MMakeCountCH2/10.0;
		else if(chem == 3)
			vol = sys->tk[tid].MMakeCountCH3/10.0;
		else if(chem == 4)
			vol = sys->tk[tid].MMakeCountCH4/1.0;
		else
			vol = 0;
	}
	else if(type == AUTO_MIX_ACID )
	{
		if(chem == 1)
			vol = sys->tk[tid].MakeCountCH1/10.0;
		else if(chem == 2)
			vol = sys->tk[tid].MakeCountCH2/10.0;
		else if(chem == 3)
			vol = sys->tk[tid].MakeCountCH3/10.0;
		else if(chem == 4)
			vol = sys->tk[tid].MakeCountCH4/1.0;
		else
			vol = 0;
	}
	
	if(vol > 0)
	{
		sprintf(tmp,"%s dosing/insert %s %s %s %f %d",PHPCOMD,sys->tk[tid].name,schem[i][chem-1],stype[type],vol,carNumber);
		LaunchExecutableEx(tmp,LE_HIDE,NULL);
	}   */
}

void PDrainLog(PDRAIN_TYPE type,TANK_ID tid,  unsigned int carNumber)  
{
/*	char tmp[256];
	if(type == PDRAIN_PART)
	{
		Fmt(tmp,"%s<啟動PartialDrain(CarNumber:%d)(DrainVol:%f)(IPA:%f)(KOH:%f)(DIW:%f)(ADD:%f)",
			carNumber,
			sys->tk[tid].rcp.PdVol,
			sys->tk[tid].rcp.PdCH1,
			sys->tk[tid].rcp.PdCH2,
			sys->tk[tid].rcp.PdCH3,
			sys->tk[tid].rcp.PdCH4);
		
		DosingLog(PARTIAL_DRAIN,tid,1,carNumber);
		DosingLog(PARTIAL_DRAIN,tid,2,carNumber);
		DosingLog(PARTIAL_DRAIN,tid,3,carNumber);
		DosingLog(PARTIAL_DRAIN,tid,4,carNumber);
	}
	else
	{
		if(carNumber == 1)
			Fmt(tmp,"%s<自動換酸準備中");
		else if(carNumber == 2)
			Fmt(tmp,"%s<自動換酸當槽中");
		else if(carNumber == 3)
		{
			int i = 0;
			char* schem[3][4] = {{"H2O2","KOH","DIW",""}, {"IPA","KOH","DIW","ADD"}, {"HF","HCL","DIW",""}};
			if(tid == TANK_02)
				i = 0;
			else if(tid == TANK_04 || tid == TANK_07)
				i = 1; 
			else if(tid == TANK_11)
				i = 2;

			Fmt(tmp,"%s<自動換酸配槽(%s:%f[p1],%s:%f[p1],%s:%f[p1],%s:%f[p1])",
					schem[i][0],sys->tk[tid].MakeCH1,
					schem[i][1],sys->tk[tid].MakeCH2,
					schem[i][2],sys->tk[tid].MakeCH3,
					schem[i][3],sys->tk[tid].MakeCH4);
		}
		else if(carNumber == 0)
		{
			Fmt(tmp,"%s<自動換酸完成");
			
			DosingLog(AUTO_MIX_ACID,tid,1,carNumber);
			DosingLog(AUTO_MIX_ACID,tid,2,carNumber);
			DosingLog(AUTO_MIX_ACID,tid,3,carNumber);
			DosingLog(AUTO_MIX_ACID,tid,4,carNumber); 
		}
	}
	
	char str[256];
	char encode[256];
	char encode1[256]; 
	unicode_to_utf8(tmp,encode,256);
	Base64Encode(encode,strlen(encode),encode1); 
	sprintf(str,"%s operation/insert %s %s %s",PHPCOMD,sys->user.name,sys->tk[tid].name,encode1);
	LaunchExecutableEx(str,LE_HIDE,NULL);	  */
}

void HandleAlarmLog(LOG* log)
{
	char tmp[32];
	char tmstr[32];
	char LogString[512];
	unsigned short rm = log->alarm.rMBak ^ log->alarm.rM;
	
	for(int i = 0; i < 16; i++)
	{
		if( (rm & bitvalue[i]) == 0)
			continue;
					
		int AlmID = log->alarm.wid * 16 + i;
		if(log->alarm.rM & bitvalue[i])
		{
			//set alarm
			int index = -1;
		//	GetTreeItemFromValue(panelHandle, PANEL_TREE_CURR,VAL_ALL,0,0,VAL_NEXT_PLUS_SELF,0,&index,AlmID);
		//	if(index == -1)
			{
				FormatDateTimeString (log->tm, "%Y/%m/%d %H:%M:%S", tmstr, 30);
				InsertTreeItem (panelHandle, PANEL_TREE_CURR, VAL_SIBLING, 0, VAL_FIRST, tmstr, "", NULL, AlmID);
			
				if(sys->isAuto){
					sprintf(LogString,"%s alarm/insert %d %d %d",PHPCOMD,AlmID,1,1);   
					sprintf(tmp,"AutoAlarmSet(%d)", AlmID);
				}
				else{
					sprintf(LogString,"%s alarm/insert %d %d %d",PHPCOMD,AlmID,1,0);
					sprintf(tmp,"ManualAlarmSet(%d)", AlmID);
				}
			
				SetTreeCellAttribute (panelHandle, PANEL_TREE_CURR, 0, 1, ATTR_LABEL_TEXT, tmp);
				SetTreeCellAttribute (panelHandle, PANEL_TREE_CURR, 0, 2, ATTR_LABEL_TEXT, sys->alarmDesc[AlmID]);
				
				LaunchExecutableEx(LogString,LE_HIDE,NULL);
			}
		}
		else
		{
			//reset alarm
			int index = 0;
			GetNumListItems(panelHandle, PANEL_TREE_CURR,&index);
			if(index < 1)
				return;
			//do{
				GetTreeItemFromValue(panelHandle, PANEL_TREE_CURR,VAL_ALL,0,0,VAL_NEXT_PLUS_SELF,0,&index,AlmID);
				if(index >= 0)
					DeleteListItem(panelHandle, PANEL_TREE_CURR,index,1);
		//	}while(index >= 0);
			
			FormatDateTimeString (log->tm, "%Y/%m/%d %H:%M:%S", tmstr, 30);
			
			if(sys->isAuto){
				sprintf(LogString,"%s alarm/insert %d %d %d",PHPCOMD,AlmID,0,1);   
			}
			else{
				sprintf(LogString,"%s alarm/insert %d %d %d",PHPCOMD,AlmID,0,0);
			}
			
			LaunchExecutableEx(LogString,LE_HIDE,NULL);
		}
	}	
}

void HandleRobotLog(LOG* log)
{
/*	char LogString[512];
	char* cmdAutotype[] = {"unknow","AutoGet","AutoPut","AutoMove","AutoBlow","AutoWash","AutoHome"}; 
	char* cmdManualtype[] = {"unknow","ManualGet","ManualPut","ManualMove","ManualBlow","ManualWash","ManualHome"};
	char* type[] = {"unknow","Start","Finish","Cancel"}; 

	if(testBit(sys->hsAuto,RB)>0)
		sprintf(LogString,"%s robot/insert %s %s %s %s",PHPCOMD,sys->rb[log->robot.rid].name,sys->tk[log->robot.cmd.tid].name, cmdAutotype[log->robot.cmd.type],type[log->robot.etype]);
	else
		sprintf(LogString,"%s robot/insert %s %s %s %s",PHPCOMD,sys->rb[log->robot.rid].name,sys->tk[log->robot.cmd.tid].name, cmdManualtype[log->robot.cmd.type],type[log->robot.etype]);

	LaunchExecutableEx(LogString,LE_HIDE,NULL); 
	
//	Fmt(tmp,"%s<%s,Event:%s,Tank:%d,Rid:%d,Command:%s",tmstr, type[log->robot.etype],log->robot.cmd.tid+1,log->robot.cmd.rid, cmdtype[log->robot.cmd.type]);
//	LogToFile(log,tmp);
	
	if(log->robot.etype == FINISH_ROBOT_EVENT && (log->robot.cmd.type == GET_COMMAND || log->robot.cmd.type == PUT_COMMAND))
		SaveSystem();	  */
}

void HandleCarLog(LOG* log)
{
	char tmp[2048];
	char tm[32];
	
	Fmt(tmp,"%s<%s prod/insert %d,%s,%s,",PHPCOMD,log->car.sn,log->car.tag1,log->car.tag2);
	
	int i = 0;
	for(int i = 0;i < PRO_TANK_NUM;i++)
	{
		FormatDateTimeString (log->car.iPrcTM[i], "%H:%M:%S", tm, 32);
		Fmt(tmp,"%s[a]<Enter:%s(%f[p1])-",tm,log->car.iPrcTemp[i]);
		FormatDateTimeString (log->car.oPrcTM[i], "%H:%M:%S", tm, 32);
		Fmt(tmp,"%s[a]<Leave:%s(%f[p1]),",tm,log->car.oPrcTemp[i]);
	}

	
	LaunchExecutableEx(tmp,LE_HIDE,NULL);
//	LogToFile(log,tmp);
}

void HandlePLCLog(LOG* log)
{
	char tmp[256];
	char* type[] = {"unknow","SetupRecipe","SetupDosing","SetupMake","SetupSystemSetting","SetupRobotPosition"}; 

//	char tmstr[32];
//	FormatDateTimeString (log->tm, "%H:%M:%S", tmstr, 30); 
	
//	Fmt(tmp,"%s<%s,Event:%s",tmstr, type[log->plc.etype]);
//	LogToFile(log,tmp);
	char encode1[256]; 
	Base64Encode(type[log->plc.etype],strlen(type[log->plc.etype]),encode1);
	sprintf(tmp,"%s operation/insert %s PLC %s",PHPCOMD,sys->user.name,encode1);
	LaunchExecutableEx(tmp,LE_HIDE,NULL);
}

static void CVICALLBACK GetLogFromQueueCallback (int queueHandle, unsigned int event,
                           int value, void *callbackData)
{

	int num;
	LOG readBuffer;

	while(1)
	{
		CmtGetLock(logLockHandle);
		num = CmtReadTSQData (tsqHandle, &readBuffer, 1, READ_THREAD_WAIT_TIME, 0);
		CmtReleaseLock(logLockHandle);
		
		if(num != 1)
			break;
		
		switch(readBuffer.type)
		{
			case ALARM_LOG:
				HandleAlarmLog(&readBuffer);
				break;
/*			case CAR_LOG:
				HandleCarLog(&readBuffer);
				break;
			case PLC_LOG:
				HandlePLCLog(&readBuffer);
				break;
			case ROBOT_LOG:
				HandleRobotLog(&readBuffer);
				break;
			case DOSING_LOG:
				HandleDosingLog(&readBuffer);
				break;
			case ACTION_LOG:
				HandleActLog(&readBuffer); 
				break;
			case PDRAIN_LOG:
				HandlePDrainLog(&readBuffer); 
				break; */
			default:
				break;
		}
		
	} 
}

int InitLog (void)
{
	CmtNewLock(NULL,0,&logLockHandle);
	CmtNewTSQ (MAX_ITEMS_IN_QUEUE, sizeof (LOG), 0, &tsqHandle);
	CmtInstallTSQCallback (tsqHandle, EVENT_TSQ_ITEMS_IN_QUEUE,
                                   1,
                                   GetLogFromQueueCallback, NULL,
                                   CmtGetCurrentThreadID(), &getLogCallbackID);

	return 1;
}

void UninitLog(void)
{
	CmtUninstallTSQCallback (tsqHandle, getLogCallbackID);
	if (tsqHandle != 0)
        CmtDiscardTSQ (tsqHandle);	
	CmtDiscardLock(logLockHandle);
	
}

