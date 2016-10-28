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

#define  TANK_DIW                         1       /* callback function: ExitDialog */
#define  TANK_DIW_VALVE_MAKE_AC1_IN       2
#define  TANK_DIW_VALVE_DOWN_2            3
#define  TANK_DIW_VALVE_DOWN              4
#define  TANK_DIW_VALVE_MAKE_AC4_IN       5
#define  TANK_DIW_SPLITTER_11             6
#define  TANK_DIW_SPLITTER_10             7
#define  TANK_DIW_SPLITTER_14             8
#define  TANK_DIW_SPLITTER_15             9
#define  TANK_DIW_SPLITTER_8              10
#define  TANK_DIW_SPLITTER_5              11
#define  TANK_DIW_TANK                    12
#define  TANK_DIW_BUBBLE1                 13
#define  TANK_DIW_BUBBLE2                 14
#define  TANK_DIW_P_TM_6                  15
#define  TANK_DIW_REMAIN_6                16
#define  TANK_DIW_TIME_6                  17
#define  TANK_DIW_P_TM_5                  18
#define  TANK_DIW_REMAIN_5                19
#define  TANK_DIW_TIME_5                  20
#define  TANK_DIW_P_TM_4                  21
#define  TANK_DIW_REMAIN_4                22
#define  TANK_DIW_TIME_4                  23
#define  TANK_DIW_P_TM_3                  24
#define  TANK_DIW_REMAIN_3                25
#define  TANK_DIW_TIME_3                  26
#define  TANK_DIW_P_TM_2                  27
#define  TANK_DIW_REMAIN_2                28
#define  TANK_DIW_TIME_2                  29
#define  TANK_DIW_P_TM_01                 30
#define  TANK_DIW_REMAIN_TIMES            31
#define  TANK_DIW_TIMES                   32
#define  TANK_DIW_REMAIN_1                33
#define  TANK_DIW_TIME_1                  34
#define  TANK_DIW_BUBBLE3                 35
#define  TANK_DIW_TIMER                   36      /* callback function: TankTimer */
#define  TANK_DIW_BUBBLE4                 37
#define  TANK_DIW_BUBBLE5                 38
#define  TANK_DIW_BUBBLE6                 39
#define  TANK_DIW_CAR                     40
#define  TANK_DIW_BUBBLE7                 41
#define  TANK_DIW_PROCESS_LAB             42
#define  TANK_DIW_PROCESS_OFF             43      /* callback function: Command */
#define  TANK_DIW_TEXTMSG_12              44
#define  TANK_DIW_PROCESS_ON              45      /* callback function: Command */
#define  TANK_DIW_TEXTMSG_11              46
#define  TANK_DIW_FILL1_LAB               47
#define  TANK_DIW_TEXTMSG_10              48
#define  TANK_DIW_FILL_OFF                49      /* callback function: Command */
#define  TANK_DIW_TEXTMSG_9               50
#define  TANK_DIW_FILL_ON                 51      /* callback function: Command */
#define  TANK_DIW_TEXTMSG_13              52
#define  TANK_DIW_TEXTMSG_14              53
#define  TANK_DIW_TEXTMSG_8               54
#define  TANK_DIW_TEXTMSG_6               55
#define  TANK_DIW_TEXTMSG_7               56
#define  TANK_DIW_SPLITTER                57
#define  TANK_DIW_SPLITTER_16             58
#define  TANK_DIW_SPLITTER_2              59
#define  TANK_DIW_DRAIN_6                 60
#define  TANK_DIW_BUBBLE_6                61
#define  TANK_DIW_DOWN_6                  62
#define  TANK_DIW_UP_6                    63
#define  TANK_DIW_DRAIN_5                 64
#define  TANK_DIW_BUBBLE_5                65
#define  TANK_DIW_DOWN_5                  66
#define  TANK_DIW_UP_5                    67
#define  TANK_DIW_DRAIN_4                 68
#define  TANK_DIW_BUBBLE_4                69
#define  TANK_DIW_DOWN_4                  70
#define  TANK_DIW_UP_4                    71
#define  TANK_DIW_DRAIN_3                 72
#define  TANK_DIW_BUBBLE_3                73
#define  TANK_DIW_DOWN_3                  74
#define  TANK_DIW_UP_3                    75
#define  TANK_DIW_DRAIN_2                 76
#define  TANK_DIW_BUBBLE_2                77
#define  TANK_DIW_DOWN_2                  78
#define  TANK_DIW_UP_2                    79
#define  TANK_DIW_DRAIN_1                 80
#define  TANK_DIW_BUBBLE_1                81
#define  TANK_DIW_DOWN_1                  82
#define  TANK_DIW_UP_1                    83


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK Command(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK ExitDialog(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK TankTimer(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
