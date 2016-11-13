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

#define  PANEL_DIW                        1       /* callback function: ExitDialog */
#define  PANEL_DIW_VALVE_UP               2       /* callback function: DiwCommand */
#define  PANEL_DIW_VALVE_BOBBLE           3       /* callback function: DiwCommand */
#define  PANEL_DIW_VALVE_DRAIN            4       /* callback function: DiwCommand */
#define  PANEL_DIW_VALVE_DOWN             5       /* callback function: DiwCommand */
#define  PANEL_DIW_SPLITTER_11            6
#define  PANEL_DIW_SPLITTER_10            7
#define  PANEL_DIW_SPLITTER_14            8
#define  PANEL_DIW_SPLITTER_15            9
#define  PANEL_DIW_SPLITTER_8             10
#define  PANEL_DIW_SPLITTER_5             11
#define  PANEL_DIW_TANK                   12
#define  PANEL_DIW_BUBBLE1                13
#define  PANEL_DIW_BUBBLE2                14
#define  PANEL_DIW_P_TM_6                 15
#define  PANEL_DIW_REMAIN_6               16
#define  PANEL_DIW_TIME_6                 17
#define  PANEL_DIW_P_TM_5                 18
#define  PANEL_DIW_REMAIN_5               19
#define  PANEL_DIW_TIME_5                 20
#define  PANEL_DIW_P_TM_4                 21
#define  PANEL_DIW_REMAIN_4               22
#define  PANEL_DIW_TIME_4                 23
#define  PANEL_DIW_P_TM_3                 24
#define  PANEL_DIW_REMAIN_3               25
#define  PANEL_DIW_REMOVE_CAR             26      /* callback function: DiwCommand */
#define  PANEL_DIW_ADD_CAR                27      /* callback function: DiwCommand */
#define  PANEL_DIW_TIME_3                 28
#define  PANEL_DIW_P_TM_2                 29
#define  PANEL_DIW_REMAIN_2               30
#define  PANEL_DIW_TIME_2                 31
#define  PANEL_DIW_P_TM_01                32
#define  PANEL_DIW_REMAIN_TIMES           33
#define  PANEL_DIW_TIMES                  34
#define  PANEL_DIW_REMAIN_1               35
#define  PANEL_DIW_TIME_1                 36
#define  PANEL_DIW_BUBBLE3                37
#define  PANEL_DIW_TIMER                  38      /* callback function: DiwTimer */
#define  PANEL_DIW_BUBBLE4                39
#define  PANEL_DIW_BUBBLE5                40
#define  PANEL_DIW_BUBBLE6                41
#define  PANEL_DIW_CAR                    42
#define  PANEL_DIW_BUBBLE7                43
#define  PANEL_DIW_TEXTMSG_12             44
#define  PANEL_DIW_TEXTMSG_11             45
#define  PANEL_DIW_TEXTMSG_10             46
#define  PANEL_DIW_TEXTMSG_9              47
#define  PANEL_DIW_TEXTMSG_13             48
#define  PANEL_DIW_TEXTMSG_14             49
#define  PANEL_DIW_TEXTMSG_8              50
#define  PANEL_DIW_TEXTMSG_6              51
#define  PANEL_DIW_TEXTMSG_7              52
#define  PANEL_DIW_SPLITTER               53
#define  PANEL_DIW_SPLITTER_16            54
#define  PANEL_DIW_SPLITTER_2             55
#define  PANEL_DIW_DRAIN_6                56
#define  PANEL_DIW_BUBBLE_6               57
#define  PANEL_DIW_DOWN_6                 58
#define  PANEL_DIW_UP_6                   59
#define  PANEL_DIW_DRAIN_5                60
#define  PANEL_DIW_BUBBLE_5               61
#define  PANEL_DIW_DOWN_5                 62
#define  PANEL_DIW_UP_5                   63
#define  PANEL_DIW_DRAIN_4                64
#define  PANEL_DIW_BUBBLE_4               65
#define  PANEL_DIW_DOWN_4                 66
#define  PANEL_DIW_UP_4                   67
#define  PANEL_DIW_DRAIN_3                68
#define  PANEL_DIW_BUBBLE_3               69
#define  PANEL_DIW_DOWN_3                 70
#define  PANEL_DIW_UP_3                   71
#define  PANEL_DIW_DRAIN_2                72
#define  PANEL_DIW_BUBBLE_2               73
#define  PANEL_DIW_DOWN_2                 74
#define  PANEL_DIW_UP_2                   75
#define  PANEL_DIW_DRAIN_1                76
#define  PANEL_DIW_BUBBLE_1               77
#define  PANEL_DIW_DOWN_1                 78
#define  PANEL_DIW_UP_1                   79
#define  PANEL_DIW_TOGGLEBUTTON_RUN       80      /* callback function: DiwCommand */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK DiwCommand(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK DiwTimer(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK ExitDialog(int panel, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
