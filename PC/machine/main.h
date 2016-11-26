/**************************************************************************/
/* LabWindows/CVI User Interface Resource (UIR) Include File              */
/* Copyright (c) National Instruments 2016. All Rights Reserved.          */
/*                                                                        */
/* WARNING: Do not add to, delete from, or otherwise modify the contents  */
/*          of this include file.                                         */
/**************************************************************************/

#include <userint.h>

#ifdef __cplusplus
    extern "C" {
#endif

     /* Panels and Controls: */

#define  PANEL                            1       /* callback function: panelCB */
#define  PANEL_TREE_CURR                  2
#define  PANEL_RLT_R                      3
#define  PANEL_RLT_Y                      4
#define  PANEL_RLT_G                      5
#define  PANEL_FLT_R                      6
#define  PANEL_FLT_Y                      7
#define  PANEL_PICTURE                    8
#define  PANEL_FLT_G                      9
#define  PANEL_PRI_TM                     10      /* callback function: PriTimer */
#define  PANEL_LOGIN                      11      /* callback function: showPanel */
#define  PANEL_LOGOUT                     12      /* callback function: showPanel */
#define  PANEL_EXIT                       13      /* callback function: showPanel */
#define  PANEL_SHOW_HELP                  14      /* callback function: showPanel */
#define  PANEL_SHOW_SET                   15      /* callback function: showPanel */
#define  PANEL_SHOW_HIS                   16      /* callback function: showPanel */
#define  PANEL_SHOW_USER                  17      /* callback function: showPanel */
#define  PANEL_SHOW_RCP                   18      /* callback function: showPanel */
#define  PANEL_ILD_POS3B                  19
#define  PANEL_HEATER_04                  20
#define  PANEL_HEATER_02                  21
#define  PANEL_ILD_POS3A                  22
#define  PANEL_ILD_POS2B                  23
#define  PANEL_ILD_POS2A                  24
#define  PANEL_ULD_POS3B                  25
#define  PANEL_ULD_POS3A                  26
#define  PANEL_ULD_POS2B                  27
#define  PANEL_ULD_POS2A                  28
#define  PANEL_ULD_POS1B                  29
#define  PANEL_ULD_POS1A                  30
#define  PANEL_ILD_POS1B                  31
#define  PANEL_ILD_POS1A                  32
#define  PANEL_INPROC_ULDB                33
#define  PANEL_INPROC_01                  34
#define  PANEL_INPROC_02                  35
#define  PANEL_INPROC_03                  36
#define  PANEL_INPROC_04                  37
#define  PANEL_INPROC_05                  38
#define  PANEL_INPROC_ULD                 39
#define  PANEL_INPROC_ULDA                40
#define  PANEL_INPROC_ILDB                41
#define  PANEL_INPROC_ILD                 42
#define  PANEL_INPROC_ILDA                43
#define  PANEL_DECORATION_8               44
#define  PANEL_DECORATION_11              45
#define  PANEL_TNK_02                     46      /* callback function: ShowManuDialog */
#define  PANEL_TNK_03                     47      /* callback function: ShowManuDialog */
#define  PANEL_TNK_04                     48      /* callback function: ShowManuDialog */
#define  PANEL_TNK_05                     49      /* callback function: ShowManuDialog */
#define  PANEL_TNK_ILD                    50      /* callback function: ShowManuDialog */
#define  PANEL_TNK_ULD                    51      /* callback function: ShowManuDialog */
#define  PANEL_DOR_ILD                    52
#define  PANEL_DOR_ULD                    53
#define  PANEL_PRCTM_01                   54
#define  PANEL_EXH_10                     55
#define  PANEL_EXH_1                      56
#define  PANEL_EXH_2                      57
#define  PANEL_PRCTM_02                   58
#define  PANEL_EXH_3                      59
#define  PANEL_PRCTM_03                   60
#define  PANEL_PRCTM_04                   61
#define  PANEL_PRCTM_05                   62
#define  PANEL_EXH_9                      63
#define  PANEL_TNK_01                     64      /* callback function: ShowManuDialog */
#define  PANEL_UNLOADER                   65      /* callback function: ShowManuDialog */
#define  PANEL_TM_ULD                     66
#define  PANEL_TM_05                      67
#define  PANEL_TM_04                      68
#define  PANEL_TM_03                      69
#define  PANEL_TM_02                      70
#define  PANEL_TM_01                      71
#define  PANEL_TM_ILD                     72
#define  PANEL_PRCTM_ILD                  73
#define  PANEL_ROBOT1                     74      /* callback function: ShowManuDialog */
#define  PANEL_PRCTM_ULD                  75
#define  PANEL_F_LEAK                     76
#define  PANEL_DECORATION_18              77
#define  PANEL_DECORATION_17              78
#define  PANEL_ROBOT11                    79      /* callback function: ShowManuDialog */
#define  PANEL_LOADER                     80      /* callback function: ShowManuDialog */
#define  PANEL_SHUT_04                    81
#define  PANEL_SHUT_02                    82
#define  PANEL_SYS_DATE                   83
#define  PANEL_USERNAME                   84
#define  PANEL_MODE                       85
#define  PANEL_RECIPEID                   86
#define  PANEL_DECORATION_2               87
#define  PANEL_DECORATION_19              88
#define  PANEL_RESET_COUNT                89      /* callback function: sysCommand */
#define  PANEL_TEXTMSG                    90
#define  PANEL_COUNT_ILD                  91
#define  PANEL_COUNT_01                   92
#define  PANEL_COUNT_02                   93
#define  PANEL_COUNT_03                   94
#define  PANEL_COUNT_04                   95
#define  PANEL_COUNT_05                   96
#define  PANEL_COUNT_ULD                  97
#define  PANEL_TEMP_04                    98
#define  PANEL_TEMP_02                    99
#define  PANEL_UP_LEV_02                  100
#define  PANEL_UP_LEV_04                  101
#define  PANEL_TOGGLEBUTTON_BUZZ          102     /* callback function: sysCommand */
#define  PANEL_TOGGLEBUTTON_LIGHT         103     /* callback function: sysCommand */
#define  PANEL_DECORATION                 104


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK panelCB(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK PriTimer(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK ShowManuDialog(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK showPanel(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK sysCommand(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
