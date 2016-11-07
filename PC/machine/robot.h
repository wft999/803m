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

#define  PANEL_RB                         1       /* callback function: ExitDialog */
#define  PANEL_RB_LEDOFF                  2
#define  PANEL_RB_LEDON                   3
#define  PANEL_RB_Z_DOWN                  4
#define  PANEL_RB_TABLE                   5
#define  PANEL_RB_DECORATION_30           6
#define  PANEL_RB_JOG_UP                  7       /* callback function: RobotManuAdj */
#define  PANEL_RB_JOG_DOWN                8       /* callback function: RobotManuAdj */
#define  PANEL_RB_JOG_LEFT                9       /* callback function: RobotManuAdj */
#define  PANEL_RB_JOG_RIGHT               10      /* callback function: RobotManuAdj */
#define  PANEL_RB_FORCE_STOP              11
#define  PANEL_RB_TEXTMSG_27              12
#define  PANEL_RB_TEXTMSG_32              13
#define  PANEL_RB_TEXTMSG_24              14
#define  PANEL_RB_X_UNLOCK                15
#define  PANEL_RB_X_LOCK                  16
#define  PANEL_RB_CHECKBOX_PERMIT_SAVE    17      /* callback function: ManualInput */
#define  PANEL_RB_CHECKBOX_PERMIT_INPUT   18      /* callback function: ManualInput */
#define  PANEL_RB_CMD_TAKE                19      /* callback function: RobotCommand */
#define  PANEL_RB_CMD_PUT                 20      /* callback function: RobotCommand */
#define  PANEL_RB_CHUCK_OFF               21      /* callback function: RobotCommand */
#define  PANEL_RB_CHUCK_ON                22      /* callback function: RobotCommand */
#define  PANEL_RB_CMD_HOME                23      /* callback function: RobotCommand */
#define  PANEL_RB_CMD_CLEAN               24      /* callback function: RobotCommand */
#define  PANEL_RB_CMD_MOVE_UNLOCK         25      /* callback function: RobotCommand */
#define  PANEL_RB_REMOVE_CAR              26      /* callback function: RobotCommand */
#define  PANEL_RB_ADD_CAR                 27      /* callback function: RobotCommand */
#define  PANEL_RB_CMD_MOVE_LOCK           28      /* callback function: RobotCommand */
#define  PANEL_RB_RING                    29      /* callback function: tankChange */
#define  PANEL_RB_TEXTMSG_22              30
#define  PANEL_RB_DECORATION_28           31
#define  PANEL_RB_DECORATION_29           32
#define  PANEL_RB_SET_X_UNLOCK            33      /* callback function: SavePosition */
#define  PANEL_RB_SET_Z_DOWN              34      /* callback function: SavePosition */
#define  PANEL_RB_SET_X_LOCK              35      /* callback function: SavePosition */
#define  PANEL_RB_TIMER                   36      /* callback function: RobotTimer */
#define  PANEL_RB_TEACH_BOX               37      /* callback function: ManualInput */
#define  PANEL_RB_Z_JOG_SPEED             38      /* callback function: ManualInput */
#define  PANEL_RB_X_JOG_SPEED             39      /* callback function: ManualInput */


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK ExitDialog(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK ManualInput(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK RobotCommand(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK RobotManuAdj(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK RobotTimer(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK SavePosition(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK tankChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
