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
#define  PANEL_ULD_POS1A                  19
#define  PANEL_ULD_POS1B                  20
#define  PANEL_ULD_POS2A                  21
#define  PANEL_ULD_POS2B                  22
#define  PANEL_ULD_POS4A                  23
#define  PANEL_ULD_POS4B                  24
#define  PANEL_ULD_POS5A                  25
#define  PANEL_ULD_POS5B                  26
#define  PANEL_HEATER_17                  27
#define  PANEL_HEATER_16                  28
#define  PANEL_HEATER_15                  29
#define  PANEL_HEATER_14                  30
#define  PANEL_HEATER_13                  31
#define  PANEL_HEATER_12                  32
#define  PANEL_HEATER_10                  33
#define  PANEL_HEATER_09                  34
#define  PANEL_HEATER_07                  35
#define  PANEL_HEATER_06                  36
#define  PANEL_HEATER_04                  37
#define  PANEL_HEATER_03                  38
#define  PANEL_HEATER_INLINE              39
#define  PANEL_HEATER_PH2                 40
#define  PANEL_HEATER_PH1                 41
#define  PANEL_HEATER_02                  42
#define  PANEL_ILD_POS1A                  43
#define  PANEL_ILD_POS1B                  44
#define  PANEL_ILD_POS2A                  45
#define  PANEL_ULD_POS3A                  46
#define  PANEL_ILD_POS2B                  47
#define  PANEL_ILD_POS3A                  48
#define  PANEL_ILD_POS3B                  49
#define  PANEL_ULD_POS3B                  50
#define  PANEL_ULD_POS6A                  51
#define  PANEL_ULD_POS6B                  52
#define  PANEL_INPROC_ILDB                53
#define  PANEL_INPROC_ILDA                54
#define  PANEL_INPROC_13_1                55
#define  PANEL_INPROC_13                  56
#define  PANEL_INPROC_11_1                57
#define  PANEL_INPROC_11                  58
#define  PANEL_INPROC_10_1                59
#define  PANEL_INPROC_10                  60
#define  PANEL_INPROC_08_1                61
#define  PANEL_INPROC_08                  62
#define  PANEL_INPROC_07_1                63
#define  PANEL_INPROC_07                  64
#define  PANEL_INPROC_05_1                65
#define  PANEL_INPROC_05                  66
#define  PANEL_INPROC_04_1                67
#define  PANEL_INPROC_04                  68
#define  PANEL_INPROC_03_1                69
#define  PANEL_INPROC_03                  70
#define  PANEL_INPROC_02_1                71
#define  PANEL_INPROC_02                  72
#define  PANEL_INPROC_ULDA6               73
#define  PANEL_INPROC_ULDA5               74
#define  PANEL_INPROC_ULDA4               75
#define  PANEL_INPROC_ULDA3               76
#define  PANEL_INPROC_ULDA2               77
#define  PANEL_INPROC_17                  78
#define  PANEL_INPROC_16                  79
#define  PANEL_INPROC_15                  80
#define  PANEL_INPROC_14                  81
#define  PANEL_INPROC_12                  82
#define  PANEL_INPROC_09                  83
#define  PANEL_INPROC_06                  84
#define  PANEL_INPROC_01                  85
#define  PANEL_TNK_15                     86      /* callback function: ShowManuDialog */
#define  PANEL_DECORATION_8               87
#define  PANEL_TNK_14                     88      /* callback function: ShowManuDialog */
#define  PANEL_DECORATION_11              89
#define  PANEL_TNK_12                     90      /* callback function: ShowManuDialog */
#define  PANEL_COUNT_17                   91
#define  PANEL_COUNT_16                   92
#define  PANEL_COUNT_15                   93
#define  PANEL_COUNT_02                   94
#define  PANEL_COUNT_03                   95
#define  PANEL_COUNT_04                   96
#define  PANEL_TNK_11                     97      /* callback function: ShowManuDialog */
#define  PANEL_COUNT_05                   98
#define  PANEL_TNK_10                     99      /* callback function: ShowManuDialog */
#define  PANEL_TNK_09                     100     /* callback function: ShowManuDialog */
#define  PANEL_COUNT_06                   101
#define  PANEL_COUNT_07                   102
#define  PANEL_COUNT_08                   103
#define  PANEL_COUNT_09                   104
#define  PANEL_TNK_HF                     105     /* callback function: ShowManuDialog */
#define  PANEL_COUNT_01                   106
#define  PANEL_TNK_TEX                    107     /* callback function: ShowManuDialog */
#define  PANEL_COUNT_10                   108
#define  PANEL_TNK_DIW                    109     /* callback function: ShowManuDialog */
#define  PANEL_COUNT_11                   110
#define  PANEL_TNK_INLINE                 111     /* callback function: ShowManuDialog */
#define  PANEL_COUNT_12                   112
#define  PANEL_TNK_PH2                    113     /* callback function: ShowManuDialog */
#define  PANEL_COUNT_13                   114
#define  PANEL_TNK_PH1                    115     /* callback function: ShowManuDialog */
#define  PANEL_COUNT_14                   116
#define  PANEL_TNK_08                     117     /* callback function: ShowManuDialog */
#define  PANEL_TNK_07                     118     /* callback function: ShowManuDialog */
#define  PANEL_TNK_06                     119     /* callback function: ShowManuDialog */
#define  PANEL_TNK_17                     120     /* callback function: ShowManuDialog */
#define  PANEL_TNK_05                     121     /* callback function: ShowManuDialog */
#define  PANEL_TNK_04                     122     /* callback function: ShowManuDialog */
#define  PANEL_TNK_03                     123     /* callback function: ShowManuDialog */
#define  PANEL_PRCTM_17                   124
#define  PANEL_TEMP17                     125
#define  PANEL_TEMP16                     126
#define  PANEL_TEMP15                     127
#define  PANEL_TEMP14                     128
#define  PANEL_TEMP13                     129
#define  PANEL_TEMP12                     130
#define  PANEL_TEMP10                     131
#define  PANEL_TEMP09                     132
#define  PANEL_TEMP07                     133
#define  PANEL_TEMP06                     134
#define  PANEL_TEMP_IN                    135
#define  PANEL_TEMP_PH2                   136
#define  PANEL_TEMP_PH1                   137
#define  PANEL_TEMP04                     138
#define  PANEL_TEMP03                     139
#define  PANEL_TEMP02                     140
#define  PANEL_TNK_01                     141
#define  PANEL_PRCTM_16                   142
#define  PANEL_PRCTM_15                   143
#define  PANEL_PRCTM_14                   144
#define  PANEL_TNK_02                     145     /* callback function: ShowManuDialog */
#define  PANEL_DOR_ULD                    146
#define  PANEL_DOR_ILD                    147
#define  PANEL_PRCTM_13                   148
#define  PANEL_EXH_1                      149
#define  PANEL_EXH_2                      150
#define  PANEL_EXH_13                     151
#define  PANEL_PRCTM_12                   152
#define  PANEL_EXH_3                      153
#define  PANEL_EXH_6                      154
#define  PANEL_PRCTM_11                   155
#define  PANEL_TNK_16                     156     /* callback function: ShowManuDialog */
#define  PANEL_EXH_4                      157
#define  PANEL_PRCTM_10                   158
#define  PANEL_PRCTM_09                   159
#define  PANEL_EXH_15                     160
#define  PANEL_EXH_9                      161
#define  PANEL_EXH_8                      162
#define  PANEL_EXH_16                     163
#define  PANEL_PRCTM_08                   164
#define  PANEL_EXH_7                      165
#define  PANEL_TM_17                      166
#define  PANEL_EXH_5                      167
#define  PANEL_TM_14                      168
#define  PANEL_TM_15                      169
#define  PANEL_TM_16                      170
#define  PANEL_PRCTM_07                   171
#define  PANEL_TNK_13                     172     /* callback function: ShowManuDialog */
#define  PANEL_TM_02_1                    173
#define  PANEL_TM_03_1                    174
#define  PANEL_TM_04_1                    175
#define  PANEL_LIGHT                      176
#define  PANEL_TM_05_1                    177
#define  PANEL_TM_07_1                    178
#define  PANEL_DECORATION                 179
#define  PANEL_TM_08_1                    180
#define  PANEL_TM_10_1                    181
#define  PANEL_TM_11_1                    182
#define  PANEL_TM_13_1                    183
#define  PANEL_LOADER                     184     /* callback function: ShowManuDialog */
#define  PANEL_ROBOT2                     185     /* callback function: ShowManuDialog */
#define  PANEL_TM_01                      186
#define  PANEL_TM_02                      187
#define  PANEL_TM_03                      188
#define  PANEL_TM_04                      189
#define  PANEL_TM_05                      190
#define  PANEL_TM_06                      191
#define  PANEL_TM_07                      192
#define  PANEL_TM_08                      193
#define  PANEL_TM_09                      194
#define  PANEL_TM_10                      195
#define  PANEL_TM_11                      196
#define  PANEL_TM_12                      197
#define  PANEL_TM_13                      198
#define  PANEL_ROBOT3                     199     /* callback function: ShowManuDialog */
#define  PANEL_PRCTM_01                   200
#define  PANEL_PRCTM_06                   201
#define  PANEL_F_LEAK                     202
#define  PANEL_ROBOT1                     203     /* callback function: ShowManuDialog */
#define  PANEL_DECORATION_18              204
#define  PANEL_ROBOT11                    205
#define  PANEL_DECORATION_17              206
#define  PANEL_ROBOT21                    207
#define  PANEL_LOADER_2                   208     /* callback function: ShowManuDialog */
#define  PANEL_PRCTM_05                   209
#define  PANEL_ROBOT31                    210
#define  PANEL_UNLOADER0                  211
#define  PANEL_PRCTM_04                   212
#define  PANEL_PRCTM_03                   213
#define  PANEL_SHUT_17                    214
#define  PANEL_SHUT_15                    215
#define  PANEL_SHUT_14                    216
#define  PANEL_SHUT_11                    217
#define  PANEL_SHUT_08                    218
#define  PANEL_SHUT_07                    219
#define  PANEL_SHUT_05                    220
#define  PANEL_SHUT_04                    221
#define  PANEL_SHUT_02                    222
#define  PANEL_SHUT_01                    223
#define  PANEL_PRCTM_02                   224
#define  PANEL_BINARYSWITCH               225
#define  PANEL_SYS_DATE                   226
#define  PANEL_USERTYPE                   227
#define  PANEL_PLC_LED                    228
#define  PANEL_DECORATION_2               229
#define  PANEL_PLC_PIC                    230     /* callback function: ShowManuDialog */
#define  PANEL_DECORATION_19              231
#define  PANEL_BUZZ                       232
#define  PANEL_FEED                       233
#define  PANEL_RESET_COUNT                234     /* callback function: showPanel */
#define  PANEL_SPLITTER                   235
#define  PANEL_SPLITTER_5                 236
#define  PANEL_SPLITTER_4                 237
#define  PANEL_SPLITTER_3                 238
#define  PANEL_SPLITTER_2                 239
#define  PANEL_UP_LEV_15                  240
#define  PANEL_UP_LEV_14                  241
#define  PANEL_UP_LEV_08                  242
#define  PANEL_UP_LEV_07                  243
#define  PANEL_UP_LEV_05                  244
#define  PANEL_UP_LEV_04                  245
#define  PANEL_UP_LEV_02                  246
#define  PANEL_RECIPEID                   247
#define  PANEL_USERNAME                   248
#define  PANEL_LIFE_04                    249
#define  PANEL_LIFE_07                    250
#define  PANEL_LIFE_11                    251
#define  PANEL_LIFE_02                    252
#define  PANEL_TEXTMSG                    253
#define  PANEL_TEXTMSG_6                  254
#define  PANEL_AUTOMAKE_02                255
#define  PANEL_AUTOMAKE_04                256
#define  PANEL_AUTOMAKE_07                257
#define  PANEL_AUTOMAKE_11                258


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
