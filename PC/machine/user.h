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

#define  PANE_LOGIN                       1
#define  PANE_LOGIN_UID                   2       /* callback function: Change_Account */
#define  PANE_LOGIN_PWD                   3       /* callback function: Change_Account */
#define  PANE_LOGIN_CANCEL                4       /* callback function: Change_Account */
#define  PANE_LOGIN_CONFIRM               5       /* callback function: Change_Account */
#define  PANE_LOGIN_DECORATION            6
#define  PANE_LOGIN_DECORATION_2          7

#define  PANEL_USER                       2       /* callback function: ExitDialog */
#define  PANEL_USER_TABLE                 2
#define  PANEL_USER_NEWPWD2               3
#define  PANEL_USER_NEWPWD                4
#define  PANEL_USER_OLDPWD                5
#define  PANEL_USER_DELETE                6       /* callback function: UserCommand */
#define  PANEL_USER_CHANGEPWD             7       /* callback function: UserCommand */
#define  PANEL_USER_ADD                   8       /* callback function: UserCommand */
#define  PANEL_USER_SAVE                  9       /* callback function: UserCommand */
#define  PANEL_USER_DECORATION_2          10
#define  PANEL_USER_DECORATION            11
#define  PANEL_USER_TEXTMSG_122           12


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK Change_Account(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK ExitDialog(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK UserCommand(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
