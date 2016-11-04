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
#define  PANEL_RB_CHECKBOX_TEACH_BOX      18      /* callback function: ManualInput */
#define  PANEL_RB_CHECKBOX_Z_JOG_SPEED    19      /* callback function: ManualInput */
#define  PANEL_RB_CHECKBOX_X_JOG_SPEED    20      /* callback function: ManualInput */
#define  PANEL_RB_CHECKBOX_PERMIT_INPUT   21      /* callback function: ManualInput */
#define  PANEL_RB_CMD_TAKE                22      /* callback function: RobotCommand */
#define  PANEL_RB_CMD_PUT                 23      /* callback function: RobotCommand */
#define  PANEL_RB_CHUCK_OFF               24      /* callback function: RobotCommand */
#define  PANEL_RB_CHUCK_ON                25      /* callback function: RobotCommand */
#define  PANEL_RB_CMD_HOME                26      /* callback function: RobotCommand */
#define  PANEL_RB_CMD_CLEAN               27      /* callback function: RobotCommand */
#define  PANEL_RB_CMD_MOVE_UNLOCK         28      /* callback function: RobotCommand */
#define  PANEL_RB_REMOVE_CAR              29      /* callback function: RobotCommand */
#define  PANEL_RB_ADD_CAR                 30      /* callback function: RobotCommand */
#define  PANEL_RB_CMD_MOVE_LOCK           31      /* callback function: RobotCommand */
#define  PANEL_RB_RING                    32      /* callback function: tankChange */
#define  PANEL_RB_TEXTMSG_22              33
#define  PANEL_RB_DECORATION_28           34
#define  PANEL_RB_DECORATION_29           35
#define  PANEL_RB_SET_X_UNLOCK            36      /* callback function: SavePosition */
#define  PANEL_RB_SET_Z_DOWN              37      /* callback function: SavePosition */
#define  PANEL_RB_SET_X_LOCK              38      /* callback function: SavePosition */
#define  PANEL_RB_TIMER                   39      /* callback function: RobotTimer */


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
