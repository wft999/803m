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

#define  PANEL_ILD                        1       /* callback function: ExitDialog */
#define  PANEL_ILD_TIMER                  2       /* callback function: LoadTimer */
#define  PANEL_ILD_BACKWARD               3       /* callback function: LoadCommand */
#define  PANEL_ILD_FORWARD                4       /* callback function: LoadCommand */
#define  PANEL_ILD_DOWN                   5       /* callback function: LoadCommand */
#define  PANEL_ILD_UP                     6       /* callback function: LoadCommand */
#define  PANEL_ILD_RUN                    7       /* callback function: LoadCommand */
#define  PANEL_ILD_DECORATION_2           8
#define  PANEL_ILD_A1                     9
#define  PANEL_ILD_B1                     10
#define  PANEL_ILD_A2                     11
#define  PANEL_ILD_CAR1                   12
#define  PANEL_ILD_CAR3                   13
#define  PANEL_ILD_B2                     14
#define  PANEL_ILD_CAR2                   15
#define  PANEL_ILD_A3                     16
#define  PANEL_ILD_B3                     17
#define  PANEL_ILD_T1A                    18
#define  PANEL_ILD_T1B                    19
#define  PANEL_ILD_T2A                    20
#define  PANEL_ILD_T2B                    21


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK ExitDialog(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK LoadCommand(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK LoadTimer(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
