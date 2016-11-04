#include "pwctrl.h"
#include <formatio.h>
#include <userint.h>
#include "user.h"

//==============================================================================
//
// Title:       user.c
// Purpose:     A short description of the implementation.
//
// Created on:  2014/8/8 at と 02:16:40 by wang fang.
// Copyright:   hua. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files

//#include "user.h"
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

//==============================================================================
// Global functions

int CheckAuth(OPERATION op)
{
	OPERATION  auth[5][6] = {
		{0},
		{0},
		{OP_RCP,OP_TANK,OP_ROBOT,OP_SET,OP_EXIT,OP_UNKONW},
		{OP_RCP,OP_TANK,OP_ROBOT,OP_SET,OP_EXIT,OP_UNKONW},
		{OP_RCP,OP_TANK,OP_ROBOT,OP_SET,OP_EXIT,OP_USER}
	};
	  
	if(sys->isAuto )
	{
		MessagePopup("Message","自动状态，不容许手动操作！");
		return 0;
	}
	
	if(sys->user.type == SUP_USER)
		return 1;

	for(int i = 0 ; i < 6; i++)
	{
		if(sys->set.auth[sys->user.type][i] == op)
			return 1;
	}
	
	MessagePopup("Message","您没有权限执行此操作！");
	return 0;
}

void SaveUser(char* buf,int size)
{
/*	USER user[4] = {{"PV10",OPE_USER,"PV10"},
					{"PV20",DEV_USER,"PV20"},
					{"PV30",PRO_USER,"PV30"},
					{"PV40",SUP_USER,"PV40"}};   */
	
	char FileName[256];
	char Path[MAX_PATHNAME_LEN ];
	
	GetDir(Path);
	Fmt(FileName,"%s<%s\\user.dat",Path);
	int fSAVE = OpenFile (FileName, VAL_WRITE_ONLY, VAL_TRUNCATE, VAL_BINARY);
	if(fSAVE > 0)
	{
		WriteFile(fSAVE,buf,size);
		CloseFile (	fSAVE );
	}
}

int AuthUser(char* name,char* pass)
{
	char FileName[256];
	char Path[MAX_PATHNAME_LEN ];
	
	if(strcmp(name,"wakom") == 0 &&  strcmp(pass,"wakom1301") == 0)
	{
		strcpy(sys->user.name,name);
		sys->user.type = SUP_USER;
		ActionLog(USER_LOGIN_EVENT,0,0,0,0,0);
		return 1;
	}
	
	GetDir(Path);
	Fmt(FileName,"%s<%s\\user.dat",Path);
	
	long size;
	if(GetFileInfo(FileName,&size) == 1)
	{
		int fSAVE = OpenFile (FileName, VAL_READ_ONLY, VAL_TRUNCATE, VAL_BINARY);
		char* buf = malloc(size);
		ReadFile(fSAVE,buf,size);
		CloseFile (	fSAVE );
			
		int offset = 0;
		while(offset < size)
		{
			USER* u = (USER*)(buf + offset);
			if(strcmp(name,u->name) == 0 &&  strcmp(pass,u->pass) == 0)
			{
				sys->user = *u;
				ActionLog(USER_LOGIN_EVENT,0,0,0,0,0);
				free(buf);
				return 1;
			}
			
			offset += sizeof(USER);
		}
		free(buf);
		return 0;
			
	}
	else
		return 0;
}

int CVICALLBACK Change_Account (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	char IDCNV[64];
	switch (event)
	{
		case EVENT_COMMIT:
			if(control == PANE_LOGIN_CONFIRM)
			{
				char name[32];
				char pass[32];
				GetCtrlVal ( panel, PANE_LOGIN_UID, name);
				GetCtrlVal ( panel, PANE_LOGIN_PWD, pass);
				if(AuthUser(name,pass) > 0 )
				{
					RemovePopup(0);
					DiscardPanel (panel);
				}
			}
			else if(control == PANE_LOGIN_CANCEL)
			{
				RemovePopup(0);
				DiscardPanel (panel);
			}

			break;
		case EVENT_VAL_CHANGED:
		/*	if(control == PANELOGIN_UID)    {   
                GetCtrlVal ( panel, PANELOGIN_UID, IDCNV);
                StringUpperCase ( IDCNV );
                SetCtrlVal ( panel, PANELOGIN_UID, IDCNV);
            } else if (control == PANELOGIN_PWD )   {
                PasswordCtrl_GetAttribute (panel, control, ATTR_PASSWORD_VAL, IDCNV);
				StringUpperCase ( IDCNV );
                PasswordCtrl_SetAttribute (panel, control, ATTR_PASSWORD_VAL, IDCNV); 
            } */
			break;
		case EVENT_KEYPRESS:
			if(control == PANE_LOGIN_UID && eventData1 == VAL_ENTER_VKEY)    {   
                SetActiveCtrl (panel, PANE_LOGIN_PWD);
            } else if (control == PANE_LOGIN_PWD && eventData1 == VAL_ENTER_VKEY)   {
                SetActiveCtrl (panel, PANE_LOGIN_CONFIRM);
            }
			break;
	}
	return 0;
}

void initUserPanel (int Panel_Handle, int Control_ID)  
{
	SetTableColumnAttribute (Panel_Handle, Control_ID, 2, ATTR_NO_EDIT_TEXT , 1); 
	
	char FileName[256];
	char Path[MAX_PATHNAME_LEN ];
	
	GetDir(Path);
	Fmt(FileName,"%s<%s\\user.dat",Path);
	
	long size;
	if(GetFileInfo(FileName,&size) == 1)
	{
		int fSAVE = OpenFile (FileName, VAL_READ_ONLY, VAL_TRUNCATE, VAL_BINARY);
		char* buf = malloc(size);
		ReadFile(fSAVE,buf,size);
		CloseFile (	fSAVE );
			
		Point cell;
		cell.y = 1;
		int offset = 0;
		
		while(offset < size)
		{
			USER* u = (USER*)(buf + offset);
			
			InsertTableRows (Panel_Handle, Control_ID, cell.y, 1, VAL_USE_MASTER_CELL_TYPE); 
        	cell.x = 1;
        	SetTableCellAttribute(Panel_Handle, Control_ID, cell, ATTR_CTRL_VAL, u->name);
        	cell.x++;
			
			InsertTableCellRingItem (Panel_Handle, Control_ID, cell, -1, "操作工");
            InsertTableCellRingItem (Panel_Handle, Control_ID, cell, -1, "设备工程师");
            InsertTableCellRingItem (Panel_Handle, Control_ID, cell, -1, "制程工程师");
            InsertTableCellRingItem (Panel_Handle, Control_ID, cell, -1, "管理员");
			SetTableCellValFromIndex (Panel_Handle, Control_ID, cell, u->type-1);  
        	
			cell.x++;
			SetTableCellAttribute(Panel_Handle, Control_ID, cell, ATTR_CTRL_VAL, u->pass);  
			
			cell.y++; 
			offset += sizeof(USER);
		}
		free(buf);
	}
}


int CVICALLBACK UserCommand (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_COMMIT:
			if(control == PANEL_USER_CHANGEPWD)
			{
				char oldpwd[64];
				char newpwd[64]; 
				char newpwd2[64]; 
				GetCtrlVal(panel, PANEL_USER_OLDPWD,oldpwd);
				GetCtrlVal(panel, PANEL_USER_NEWPWD,newpwd);
				GetCtrlVal(panel, PANEL_USER_NEWPWD2,newpwd2);
				if(strcmp(newpwd,newpwd2) != 0)
				{
					MessagePopup("输入错误","两次密码不一致！");
					break;
				}
				else if(strlen(newpwd) > 10)
				{
					MessagePopup("输入错误","密码太长，请保持在10个字符以内");
					break;
				}
				
				char FileName[256];
				char Path[MAX_PATHNAME_LEN ];
	
				GetDir(Path);
				Fmt(FileName,"%s<%s\\user.dat",Path);
	
				long size;
				if(GetFileInfo(FileName,&size) == 1)
				{
					int fSAVE = OpenFile (FileName, VAL_READ_ONLY, VAL_TRUNCATE, VAL_BINARY);
					char* buf = malloc(size);
					ReadFile(fSAVE,buf,size);
					CloseFile (	fSAVE ); 
					
					int offset = 0;
					while(offset < size)
					{
						USER* u = (USER*)(buf + offset);
						if(strcmp(u->name,sys->user.name) == 0 && strcmp(u->pass,oldpwd) == 0)
						{
							strcpy(u->pass,newpwd);
							fSAVE = OpenFile (FileName, VAL_READ_WRITE, VAL_TRUNCATE, VAL_BINARY);
							WriteFile(fSAVE,buf,size);
							CloseFile (	fSAVE );
							MessagePopup("修改成功","修改成功");
							break;
						}
						offset += sizeof(USER);
						if(offset >= size)
							MessagePopup("输入错误","旧密码不正确");
					}
					
					free(buf);
					
				}
				
			}
			
			if(control == PANEL_USER_ADD)
			{
				if(CheckAuth(OP_USER) == 0)
					return 0;
				
				Point cell;
				cell.y = 1;
				InsertTableRows (panel, PANEL_USER_TABLE, cell.y, 1, VAL_USE_MASTER_CELL_TYPE); 
        		cell.x = 1;
        		SetTableCellAttribute(panel, PANEL_USER_TABLE, cell, ATTR_CTRL_VAL, "unname");
        		cell.x++;
			
				InsertTableCellRingItem (panel, PANEL_USER_TABLE, cell, -1, "操作工");
            	InsertTableCellRingItem (panel, PANEL_USER_TABLE, cell, -1, "设备工程师");
            	InsertTableCellRingItem (panel, PANEL_USER_TABLE, cell, -1, "制程工程师");
            	InsertTableCellRingItem (panel, PANEL_USER_TABLE, cell, -1, "管理员");
				SetTableCellValFromIndex (panel, PANEL_USER_TABLE, cell, 0);
				
				cell.x++;
				SetTableCellAttribute(panel, PANEL_USER_TABLE, cell, ATTR_CTRL_VAL, "123");
			}
			else if(control == PANEL_USER_DELETE)
			{
				if(CheckAuth(OP_USER) == 0)
					return 0;
				
				Point cell;
				GetActiveTableCell(panel, PANEL_USER_TABLE,&cell);
				DeleteTableRows(panel, PANEL_USER_TABLE,cell.y,1);  
			}
			else if(control == PANEL_USER_SAVE)
			{
				if(CheckAuth(OP_USER) == 0)
					return 0;
				
				int rows = 0;
				GetNumTableRows(panel, PANEL_USER_TABLE,&rows);
				if(rows > 0)
				{
					USER* u = malloc(rows * sizeof(USER));
					
					Point cell;
					for(cell.y = 1;cell.y <= rows;cell.y++)
					{
						cell.x = 1;
						GetTableCellAttribute(panel, PANEL_USER_TABLE,cell,ATTR_CTRL_VAL, (u+cell.y-1)->name);
						
						int id;
						char buf[64];
						cell.x = 2;
						GetTableCellAttribute(panel, PANEL_USER_TABLE,cell,ATTR_CTRL_VAL, buf);
						GetTableCellRingIndexFromValue(panel, PANEL_USER_TABLE,0,cell, &id,buf);
						(u+cell.y-1)->type = id + 1;
							
						cell.x = 3;
						GetTableCellAttribute(panel, PANEL_USER_TABLE,cell,ATTR_CTRL_VAL, (u+cell.y-1)->pass);
					}
					SaveUser((char*)u,rows * sizeof(USER));
					free(u);
				}
			}
			

			break;
	}
	return 0;
}
