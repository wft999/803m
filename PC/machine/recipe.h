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

#define  PANEL_RCP                        1       /* callback function: ExitDialog */
#define  PANEL_RCP_TAB                    2

     /* tab page panel controls */
#define  RCP_DIW1_TIME_6                  2
#define  RCP_DIW1_TIME_5                  3
#define  RCP_DIW1_TIME_4                  4
#define  RCP_DIW1_TIME_3                  5
#define  RCP_DIW1_TIME_2                  6
#define  RCP_DIW1_SPLITTER_16             7
#define  RCP_DIW1_TIMES                   8
#define  RCP_DIW1_SPLITTER_2              9
#define  RCP_DIW1_DRAIN_6                 10
#define  RCP_DIW1_TIME_1                  11
#define  RCP_DIW1_BUBBLE_6                12
#define  RCP_DIW1_DOWN_6                  13
#define  RCP_DIW1_UP_6                    14
#define  RCP_DIW1_DRAIN_5                 15
#define  RCP_DIW1_BUBBLE_5                16
#define  RCP_DIW1_DOWN_5                  17
#define  RCP_DIW1_UP_5                    18
#define  RCP_DIW1_DRAIN_4                 19
#define  RCP_DIW1_BUBBLE_4                20
#define  RCP_DIW1_DOWN_4                  21
#define  RCP_DIW1_TEXTMSG_12              22
#define  RCP_DIW1_UP_4                    23
#define  RCP_DIW1_DRAIN_3                 24
#define  RCP_DIW1_TEXTMSG_11              25
#define  RCP_DIW1_BUBBLE_3                26
#define  RCP_DIW1_DOWN_3                  27
#define  RCP_DIW1_TEXTMSG_10              28
#define  RCP_DIW1_UP_3                    29
#define  RCP_DIW1_DRAIN_2                 30
#define  RCP_DIW1_TEXTMSG_9               31
#define  RCP_DIW1_BUBBLE_2                32
#define  RCP_DIW1_DOWN_2                  33
#define  RCP_DIW1_UP_2                    34
#define  RCP_DIW1_TEXTMSG_14              35
#define  RCP_DIW1_DRAIN_1                 36
#define  RCP_DIW1_BUBBLE_1                37
#define  RCP_DIW1_TEXTMSG_20              38
#define  RCP_DIW1_TEXTMSG_19              39
#define  RCP_DIW1_TEXTMSG_18              40
#define  RCP_DIW1_TEXTMSG_17              41
#define  RCP_DIW1_TEXTMSG_16              42
#define  RCP_DIW1_TEXTMSG_15              43
#define  RCP_DIW1_TEXTMSG_6               44
#define  RCP_DIW1_DOWN_1                  45
#define  RCP_DIW1_TEXTMSG_7               46
#define  RCP_DIW1_UP_1                    47
#define  RCP_DIW1_SPLITTER                48

     /* tab page panel controls */
#define  RCP_SYS_RING                     2       /* callback function: Call_Recipe */
#define  RCP_SYS_SAVE                     3       /* callback function: Call_Recipe */
#define  RCP_SYS_PASTE                    4       /* callback function: Call_Recipe */
#define  RCP_SYS_COPY                     5       /* callback function: Call_Recipe */
#define  RCP_SYS_COFM                     6       /* callback function: RecipeConfirm */
#define  RCP_SYS_DATE                     7
#define  RCP_SYS_TEXTMSG_156              8
#define  RCP_SYS_TEXTMSG_155              9
#define  RCP_SYS_TEXTMSG_6                10
#define  RCP_SYS_COMMENT                  11


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK Call_Recipe(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK ExitDialog(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK RecipeConfirm(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
