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
#define  PANEL_DIW_VALVE_MAKE_AC1_IN      2
#define  PANEL_DIW_VALVE_DOWN_2           3
#define  PANEL_DIW_VALVE_DOWN             4
#define  PANEL_DIW_VALVE_MAKE_AC4_IN      5
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
#define  PANEL_DIW_TIME_3                 26
#define  PANEL_DIW_P_TM_2                 27
#define  PANEL_DIW_REMAIN_2               28
#define  PANEL_DIW_TIME_2                 29
#define  PANEL_DIW_P_TM_01                30
#define  PANEL_DIW_REMAIN_TIMES           31
#define  PANEL_DIW_TIMES                  32
#define  PANEL_DIW_REMAIN_1               33
#define  PANEL_DIW_TIME_1                 34
#define  PANEL_DIW_BUBBLE3                35
#define  PANEL_DIW_TIMER                  36      /* callback function: TankTimer */
#define  PANEL_DIW_BUBBLE4                37
#define  PANEL_DIW_BUBBLE5                38
#define  PANEL_DIW_BUBBLE6                39
#define  PANEL_DIW_CAR                    40
#define  PANEL_DIW_BUBBLE7                41
#define  PANEL_DIW_PROCESS_LAB            42
#define  PANEL_DIW_PROCESS_OFF            43      /* callback function: Command */
#define  PANEL_DIW_TEXTMSG_12             44
#define  PANEL_DIW_PROCESS_ON             45      /* callback function: Command */
#define  PANEL_DIW_TEXTMSG_11             46
#define  PANEL_DIW_FILL1_LAB              47
#define  PANEL_DIW_TEXTMSG_10             48
#define  PANEL_DIW_FILL_OFF               49      /* callback function: Command */
#define  PANEL_DIW_TEXTMSG_9              50
#define  PANEL_DIW_FILL_ON                51      /* callback function: Command */
#define  PANEL_DIW_TEXTMSG_13             52
#define  PANEL_DIW_TEXTMSG_14             53
#define  PANEL_DIW_TEXTMSG_8              54
#define  PANEL_DIW_TEXTMSG_6              55
#define  PANEL_DIW_TEXTMSG_7              56
#define  PANEL_DIW_SPLITTER               57
#define  PANEL_DIW_SPLITTER_16            58
#define  PANEL_DIW_SPLITTER_2             59
#define  PANEL_DIW_DRAIN_6                60
#define  PANEL_DIW_BUBBLE_6               61
#define  PANEL_DIW_DOWN_6                 62
#define  PANEL_DIW_UP_6                   63
#define  PANEL_DIW_DRAIN_5                64
#define  PANEL_DIW_BUBBLE_5               65
#define  PANEL_DIW_DOWN_5                 66
#define  PANEL_DIW_UP_5                   67
#define  PANEL_DIW_DRAIN_4                68
#define  PANEL_DIW_BUBBLE_4               69
#define  PANEL_DIW_DOWN_4                 70
#define  PANEL_DIW_UP_4                   71
#define  PANEL_DIW_DRAIN_3                72
#define  PANEL_DIW_BUBBLE_3               73
#define  PANEL_DIW_DOWN_3                 74
#define  PANEL_DIW_UP_3                   75
#define  PANEL_DIW_DRAIN_2                76
#define  PANEL_DIW_BUBBLE_2               77
#define  PANEL_DIW_DOWN_2                 78
#define  PANEL_DIW_UP_2                   79
#define  PANEL_DIW_DRAIN_1                80
#define  PANEL_DIW_BUBBLE_1               81
#define  PANEL_DIW_DOWN_1                 82
#define  PANEL_DIW_UP_1                   83


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK Command(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK ExitDialog(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK TankTimer(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
