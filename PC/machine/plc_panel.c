#include <ansi_c.h>
#include <formatio.h>
#include <utility.h>
#include <userint.h>
//==============================================================================
//
// Title:       plc_panel.c
// Purpose:     A short description of the implementation.
//
// Created on:  2014/7/23 at ¤U¤È 01:59:29 by wang fang.
// Copyright:   hua. All Rights Reserved.
//
//==============================================================================

//==============================================================================
// Include files

#include "robot_panel.h"
#include "type.h"

//==============================================================================
// Constants
#define PLC_INPUT_START 500
#define PLC_OUTPUT_START 550
#define PLC_PC_START 800
#define PC_PLC_START 900

#define TestBit(value,index)  (value & (1 << index))
#define OnBit(value, index)  (value |= (1 << index))
#define OffBit(value, index)  (value &= ~(1 << index))
//==============================================================================
// Types

//==============================================================================
// Static global variables
static int g_table_lock = 0;
static  int on_bitmap_id;
static  int off_bitmap_id;
static char* io_file_name = "iolist.csv";
//==============================================================================
// Static functions

//==============================================================================
// Global variables

//==============================================================================
// Global functions

int fill_tree_item (int Panel_Handle, int Control_ID)
{
    int j = 0;
    SetCtrlAttribute(Panel_Handle, Control_ID, ATTR_ENABLE_DRAG_DROP,0); 
    
    j = InsertTreeItem (Panel_Handle, Control_ID, VAL_SIBLING, 0, VAL_NEXT, "ControlBox1", NULL, NULL,0);
            InsertTreeItem (Panel_Handle, Control_ID, VAL_CHILD, j, VAL_LAST, "Input", NULL, NULL, 0);
            InsertTreeItem (Panel_Handle, Control_ID, VAL_CHILD, j, VAL_LAST, "Output", NULL, NULL, 0); 
            
    j = InsertTreeItem (Panel_Handle, Control_ID, VAL_SIBLING, 0, VAL_NEXT, "ControlBox2", NULL, NULL,0);
            InsertTreeItem (Panel_Handle, Control_ID, VAL_CHILD, j, VAL_LAST, "Input", NULL, NULL, 0);
            InsertTreeItem (Panel_Handle, Control_ID, VAL_CHILD, j, VAL_LAST, "Output", NULL, NULL, 0); 
            
    j = InsertTreeItem (Panel_Handle, Control_ID, VAL_SIBLING, 0, VAL_NEXT, "Handshake", NULL, NULL,0);
            InsertTreeItem (Panel_Handle, Control_ID, VAL_CHILD, j, VAL_LAST, "PC>PLC", NULL, NULL, 0);
            InsertTreeItem (Panel_Handle, Control_ID, VAL_CHILD, j, VAL_LAST, "PLC>PC", NULL, NULL, 0);            
    
    return 1;
}

//==============================================================================
// ????????
//==============================================================================
int init_table (int Panel_Handle, int Control_ID)  
{
    InsertTableColumns (Panel_Handle, Control_ID, -1, 6, VAL_CELL_STRING);  
    SetTableColumnAttribute (Panel_Handle, Control_ID, -1, ATTR_USE_LABEL_TEXT, 1); 
    SetTableColumnAttribute (Panel_Handle, Control_ID, -1, ATTR_LABEL_JUSTIFY , VAL_BOTTOM_LEFT_JUSTIFIED); 
    SetTableColumnAttribute (Panel_Handle, Control_ID, -1, ATTR_NO_EDIT_TEXT , 1); 
    
    SetTableColumnAttribute (Panel_Handle, Control_ID, 1, ATTR_LABEL_TEXT, "Process");
    SetTableColumnAttribute (Panel_Handle, Control_ID, 1, ATTR_COLUMN_WIDTH, 100);
    
    SetTableColumnAttribute (Panel_Handle, Control_ID, 2, ATTR_LABEL_TEXT, "Type");
    SetTableColumnAttribute (Panel_Handle, Control_ID, 2, ATTR_COLUMN_WIDTH, 80);
    
    SetTableColumnAttribute (Panel_Handle, Control_ID, 3, ATTR_LABEL_TEXT, "Address");
    SetTableColumnAttribute (Panel_Handle, Control_ID, 3, ATTR_COLUMN_WIDTH, 80);
    
    SetTableColumnAttribute (Panel_Handle, Control_ID, 4, ATTR_LABEL_TEXT, "PLC Address");
    SetTableColumnAttribute (Panel_Handle, Control_ID, 4, ATTR_COLUMN_WIDTH, 80);
    
    SetTableColumnAttribute (Panel_Handle, Control_ID, 5, ATTR_LABEL_TEXT, "State");
    SetTableColumnAttribute (Panel_Handle, Control_ID, 5, ATTR_COLUMN_WIDTH, 30);
    
    SetTableColumnAttribute (Panel_Handle, Control_ID, 6, ATTR_LABEL_TEXT, "Description");
    SetTableColumnAttribute (Panel_Handle, Control_ID, 6, ATTR_COLUMN_WIDTH, 280);
    
    CmtNewLock (NULL, 0 , &g_table_lock);
    GetCtrlDisplayBitmap (Panel_Handle, PANEL_PLC_LEDOFF, 0, &off_bitmap_id);
    GetCtrlDisplayBitmap (Panel_Handle, PANEL_PLC_LEDON, 0, &on_bitmap_id);
    
    return 1;
}

//==============================================================================
// ????PLC????????
//==============================================================================
void refresh_IO_table(int Panel_Handle, int Control_ID)
{

    CmtGetLock(g_table_lock);
    
    char type[64];
    char comm[128];
    char address[64];
    Point cell;
    int numberOfRows;
    GetNumTableRows (Panel_Handle, Control_ID, &numberOfRows);
    for(cell.y = 1; cell.y <=  numberOfRows; cell.y++)
    {
        
        cell.x = 6;
        GetTableCellAttribute(Panel_Handle, Control_ID, cell, ATTR_CTRL_VAL, comm);
        if(strcmp(comm,"Spare") == 0) 
            continue;
        
        cell.x = 2;
        GetTableCellAttribute(Panel_Handle, Control_ID, cell, ATTR_CTRL_VAL, type);

        int start=0;
        unsigned short* reg = 0;
		BIT_TYPE btype = RB;
        if(strcmp(type,"Input") == 0)                          
        {
            start = PLC_INPUT_START;
            btype = RX; 
        }
        else if(strcmp(type,"Output") == 0)
        {
            start = PLC_OUTPUT_START;
            btype = RY;  
        }
        else if(strcmp(type,"PLC>PC") == 0)
        {
            start = PLC_PC_START;
            btype = RB;  
        }
        else if(strcmp(type,"PC>PLC") == 0)
        {
            start = PC_PLC_START;
            btype = WB; 
        }
        else
            continue;																	 
        
        cell.x = 3;
        GetTableCellAttribute(Panel_Handle, Control_ID, cell, ATTR_CTRL_VAL, address); 

        int a1,a2;
        Scan(address,"D%d.%d",&a1,&a2);
		
		BIT bt;
		bt.wid = a1-start;
		bt.bid = a2;

        cell.x = 5; 
        if(testBit(bt,btype) > 0)
            SetTableCellAttribute (Panel_Handle, Control_ID, cell, ATTR_CTRL_VAL,on_bitmap_id);
        else if(testBit(bt,btype) == 0)
            SetTableCellAttribute (Panel_Handle, Control_ID, cell, ATTR_CTRL_VAL,off_bitmap_id);
		else
		{
			if(test00Bit(btype) > 0)
            	SetTableCellAttribute (Panel_Handle, Control_ID, cell, ATTR_CTRL_VAL,on_bitmap_id);
        	else if(test00Bit(btype) == 0)
            	SetTableCellAttribute (Panel_Handle, Control_ID, cell, ATTR_CTRL_VAL,off_bitmap_id);
		}
    }
    
    CmtReleaseLock(g_table_lock);
}

//==============================================================================
// ??????IOLIST.CSV??????
//==============================================================================
int fill_table_item (int Panel_Handle, int Control_ID,char* process_name, char* type)
{
    char projectDir[MAX_PATHNAME_LEN];
    char fullPath[MAX_PATHNAME_LEN];
	memset(fullPath, 0,  MAX_PATHNAME_LEN);

    if (GetProjectDir (projectDir) < 0)
        return 0;
    else
        MakePathname (projectDir, io_file_name, fullPath);// where fullPath has the following format: c:\myproject\myfile.dat

    int hfile;
    char lineBuffer[512];
    Point cell;
    
    hfile = OpenFile(fullPath,VAL_READ_ONLY,VAL_OPEN_AS_IS,VAL_ASCII);
    if(hfile < 0)
        return 0;
    
    CmtGetLock(g_table_lock); 
    DeleteTableRows (Panel_Handle, Control_ID, 1, -1); 

    cell.y = 1;
    while(ReadLine (hfile, lineBuffer, 510) >= 0)
    {
        char* pname = strtok(lineBuffer,","); 
        if(pname == NULL || strcmp(pname,process_name) != 0)
            continue;
        char* des = strtok(NULL,",");
        if(des == NULL || (type != NULL && strcmp(des,type) != 0) )
            continue;
        
        InsertTableRows (Panel_Handle, Control_ID, cell.y, 1, VAL_CELL_STRING); 
        
        cell.x = 1;
        SetTableCellAttribute(Panel_Handle, Control_ID, cell, ATTR_CTRL_VAL, pname);
        cell.x++;
        SetTableCellAttribute(Panel_Handle, Control_ID, cell, ATTR_CTRL_VAL, des);
        cell.x++;
        
        des = strtok(NULL,",");
		SetTableCellAttribute(Panel_Handle, Control_ID, cell, ATTR_CTRL_VAL, des);
		cell.x++;
		
		des = strtok(NULL,",");
		SetTableCellAttribute(Panel_Handle, Control_ID, cell, ATTR_CTRL_VAL, des);
		cell.x++;

		SetTableCellAttribute (Panel_Handle, Control_ID, cell, ATTR_CELL_TYPE, VAL_CELL_PICTURE);
        SetTableCellAttribute (Panel_Handle, Control_ID, cell, ATTR_FIT_MODE, VAL_PICT_CORNER); 
        cell.x++;
		
		des = strtok(NULL,",");
		if(des == NULL)
			SetTableCellAttribute(Panel_Handle, Control_ID, cell, ATTR_CTRL_VAL, "Spare");
		else
			SetTableCellAttribute(Panel_Handle, Control_ID, cell, ATTR_CTRL_VAL, des);
		
        cell.y++;   
    }
    CloseFile(hfile); 
    
    CmtReleaseLock(g_table_lock);
    refresh_IO_table(Panel_Handle, Control_ID);
    
    return 1;
}


//==============================================================================
// ??????????????
//==============================================================================
int CVICALLBACK TreeSelectChange (int panel, int control, int event,
        void *callbackData, int eventData1, int eventData2)
{
    char proc_name[32];
    switch (event)
    {
        case EVENT_SELECTION_CHANGE:
            if(eventData1 == 1)
            {
                char path[32];
                GetTreeItemPath(panel, control, eventData2, ",", path); 
                
                char* mname = strtok(path,","); 
                char* type = strtok(NULL,","); 
                if(type == NULL)
                {
                    fill_table_item(panel,PANEL_PLC_TABLE,mname,"Input"); 
                    break;
                }
                

                fill_table_item(panel,PANEL_PLC_TABLE,mname,type); 
            }

            break;
    }
    return 0;
}


//==============================================================================
int CVICALLBACK TableEvent (int Panel_Handle, int Control_ID, int event,
        void *callbackData, int eventData1, int eventData2)
{
	static int modify_key;
    switch (event)
    {
        case EVENT_KEYPRESS:
     	     int key = GetKeyPressEventVirtualKey(eventData2);

             if (key == VAL_F1_VKEY)           
			 {
				 if (modify_key == 1)
					 modify_key = 0;
				 else
					 modify_key = 1;
				 
			//	 SetTableCellRangeAttribute (Panel_Handle, Control_ID, VAL_TABLE_COLUMN_RANGE(4) ,ATTR_VERTICAL_GRID_COLOR  , (modify_key==1)?VAL_RED:VAL_LT_GRAY);
			//	 SetTableCellRangeAttribute (Panel_Handle, Control_ID, VAL_TABLE_COLUMN_RANGE(5) ,ATTR_VERTICAL_GRID_COLOR  , (modify_key==1)?VAL_RED:VAL_LT_GRAY);
			
			 }	  
    		 break;
		case EVENT_TABLE_ROW_COL_LABEL_CLICK:
			
			if ((eventData1 > 0) && (modify_key==1))
			{	
				char type[64];
            	char comm[128];
            	char address[64];
            	Point cell;
		    	cell.y = eventData1;
            	cell.x = 6;
            	GetTableCellAttribute(Panel_Handle, Control_ID, cell, ATTR_CTRL_VAL, comm);
            	if(strcmp(comm,"Spare") == 0) 
                	return 0;
        
            	cell.x = 2;
            	GetTableCellAttribute(Panel_Handle, Control_ID, cell, ATTR_CTRL_VAL, type);

            	int start = 0;
            	BIT_TYPE btype = 0;
            	if(strcmp(type,"Input") == 0)                          
            	{
	                start = PLC_INPUT_START;
    	            btype = RX; 
        	    }
            	else if(strcmp(type,"Output") == 0)
        		{
	            	start = PLC_OUTPUT_START;
    	        	btype = RY; 
        		}
        		else if(strcmp(type,"PLC>PC") == 0)
        		{
            		start = PLC_PC_START;
	            	btype = RB; 
    	    	}
        		else if(strcmp(type,"PC>PLC") == 0)
        		{
	            	start = PC_PLC_START;
    	        	btype = WB;
        		}
        		else
	            	break;
        
    	    	cell.x = 3;
        		GetTableCellAttribute(Panel_Handle, Control_ID, cell, ATTR_CTRL_VAL, address); 

	        	int a1,a2;
    	    	Scan(address,"D%d.%d",&a1,&a2);
				
				BIT bt;
				bt.wid = a1 - start;
				bt.bid = a2;

	        	cell.x = 5; 
    	    	if(testBit(bt,btype))   
				{	
					//OffBit(reg[a1-start],a2);   
            		SetTableCellAttribute (Panel_Handle, Control_ID, cell, ATTR_CTRL_VAL,off_bitmap_id);
				}
        		else
				{	
					//OnBit(reg[a1-start],a2);	
    	        	SetTableCellAttribute (Panel_Handle, Control_ID, cell, ATTR_CTRL_VAL,on_bitmap_id);
				}
			}	
			break;
	}
	return 0;
}	

int CVICALLBACK iotimer (int panel, int control, int event,
		void *callbackData, int eventData1, int eventData2)
{
	switch (event)
	{
		case EVENT_TIMER_TICK:
			refresh_IO_table(panel,PANEL_PLC_TABLE);
			break;
	}
	return 0;
}



void initPlcPanel(int panel)
{
	init_table(panel,PANEL_PLC_TABLE);
	fill_tree_item(panel,PANEL_PLC_TREE);
    init_table(panel,PANEL_PLC_TABLE);
    fill_table_item(panel, PANEL_PLC_TABLE,"??","Input");	
}
