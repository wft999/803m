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
#define  PANEL_HEATER04                   20
#define  PANEL_HEATER02                   21
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
#define  PANEL_INPROC_02                  34
#define  PANEL_INPROC_03                  35
#define  PANEL_INPROC_04                  36
#define  PANEL_INPROC_05                  37
#define  PANEL_INPROC_06                  38
#define  PANEL_INPROC_ULD                 39
#define  PANEL_INPROC_ULDA                40
#define  PANEL_INPROC_ILDB                41
#define  PANEL_INPROC_ILD                 42
#define  PANEL_INPROC_ILDA                43
#define  PANEL_DECORATION_8               44
#define  PANEL_DECORATION_11              45
#define  PANEL_TNK_02                     46      /* callback function: ShowManuDialog */
#define  PANEL_COUNT_01                   47
#define  PANEL_COUNT_14                   48
#define  PANEL_TNK_03                     49      /* callback function: ShowManuDialog */
#define  PANEL_TNK_04                     50      /* callback function: ShowManuDialog */
#define  PANEL_TNK_05                     51      /* callback function: ShowManuDialog */
#define  PANEL_COUNT_06                   52
#define  PANEL_COUNT_05                   53
#define  PANEL_COUNT_04                   54
#define  PANEL_COUNT_03                   55
#define  PANEL_COUNT_02                   56
#define  PANEL_TNK_ILD                    57
#define  PANEL_TNK_ULD                    58
#define  PANEL_DOR_ILD                    59
#define  PANEL_DOR_ULD                    60
#define  PANEL_PRCTM_02                   61
#define  PANEL_EXH_10                     62
#define  PANEL_EXH_1                      63
#define  PANEL_EXH_2                      64
#define  PANEL_PRCTM_03                   65
#define  PANEL_EXH_3                      66
#define  PANEL_PRCTM_04                   67
#define  PANEL_PRCTM_05                   68
#define  PANEL_PRCTM_06                   69
#define  PANEL_EXH_9                      70
#define  PANEL_TNK_01                     71      /* callback function: ShowManuDialog */
#define  PANEL_UNLOADER                   72      /* callback function: ShowManuDialog */
#define  PANEL_TM_ULD                     73
#define  PANEL_TM_06                      74
#define  PANEL_TM_05                      75
#define  PANEL_TM_04                      76
#define  PANEL_TM_03                      77
#define  PANEL_TM_02                      78
#define  PANEL_TM_ILD                     79
#define  PANEL_PRCTM_ILD                  80
#define  PANEL_ROBOT1                     81      /* callback function: ShowManuDialog */
#define  PANEL_PRCTM_ULD                  82
#define  PANEL_F_LEAK                     83
#define  PANEL_DECORATION_18              84
#define  PANEL_DECORATION_17              85
#define  PANEL_ROBOT11                    86      /* callback function: ShowManuDialog */
#define  PANEL_LOADER                     87      /* callback function: ShowManuDialog */
#define  PANEL_SHUT_04                    88
#define  PANEL_SHUT_02                    89
#define  PANEL_SYS_DATE                   90
#define  PANEL_USERNAME                   91
#define  PANEL_USERTYPE                   92
#define  PANEL_RECIPEID                   93
#define  PANEL_DECORATION_2               94
#define  PANEL_DECORATION_19              95
#define  PANEL_RESET_COUNT                96      /* callback function: showPanel */
#define  PANEL_TEXTMSG                    97
#define  PANEL_LIGHT                      98
#define  PANEL_BUZZ                       99
#define  PANEL_FEED                       100
#define  PANEL_DECORATION                 101


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK panelCB(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK PriTimer(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK ShowManuDialog(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK showPanel(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
