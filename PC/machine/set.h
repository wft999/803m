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

#define  SET                              1       /* callback function: ExitDialog */
#define  SET_CHECKBOX_SAFE                2
#define  SET_CHECKBOX_EXHAUST             3
#define  SET_CHECKBOX_DOOR                4
#define  SET_CHECKBOX_CHUCK               5
#define  SET_SAVE                         6       /* callback function: Save */
#define  SET_AUTH_EXIT3                   7
#define  SET_AUTH_SET3                    8
#define  SET_AUTH_ROBOT3                  9
#define  SET_AUTH_TANK3                   10
#define  SET_AUTH_USER3                   11
#define  SET_AUTH_RECIPE3                 12
#define  SET_AUTH_EXIT2                   13
#define  SET_AUTH_SET2                    14
#define  SET_TEXTMSG_126                  15
#define  SET_AUTH_ROBOT2                  16
#define  SET_AUTH_TANK2                   17
#define  SET_AUTH_USER2                   18
#define  SET_AUTH_RECIPE2                 19
#define  SET_AUTH_EXIT1                   20
#define  SET_AUTH_SET1                    21
#define  SET_TEXTMSG_125                  22
#define  SET_AUTH_ROBOT1                  23
#define  SET_AUTH_TANK1                   24
#define  SET_AUTH_USER1                   25
#define  SET_AUTH_RECIPE1                 26
#define  SET_DECORATION_3                 27
#define  SET_DECORATION_2                 28
#define  SET_TEXTMSG_121                  29
#define  SET_TEXTMSG_122                  30


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK ExitDialog(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Save(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
