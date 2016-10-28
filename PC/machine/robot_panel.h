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

#define  PANEL_AKF                        1       /* callback function: ExitDialog */
#define  PANEL_AKF_DECORATION_7           2
#define  PANEL_AKF_DECORATION_6           3
#define  PANEL_AKF_BUBB_LAB               4
#define  PANEL_AKF_HEAT_LAB               5
#define  PANEL_AKF_TIMER                  6       /* callback function: AKFTankTimer */
#define  PANEL_AKF_ONLINE_LAB             7
#define  PANEL_AKF_AUTO_LAB               8
#define  PANEL_AKF_FILL_LAB               9
#define  PANEL_AKF_HEAT_OFF               10      /* callback function: AkfCommand */
#define  PANEL_AKF_UP                     11      /* callback function: AKFAdj */
#define  PANEL_AKF_DOWN                   12      /* callback function: AKFAdj */
#define  PANEL_AKF_HEAT_ON                13      /* callback function: AkfCommand */
#define  PANEL_AKF_HOME_OFF               14      /* callback function: AkfCommand */
#define  PANEL_AKF_HOME_ON                15      /* callback function: AkfCommand */
#define  PANEL_AKF_PUMP_OFF               16      /* callback function: AkfCommand */
#define  PANEL_AKF_AUTO_OFF               17      /* callback function: AkfCommand */
#define  PANEL_AKF_AUTO_ON                18      /* callback function: AkfCommand */
#define  PANEL_AKF_PUMP_ON                19      /* callback function: AkfCommand */
#define  PANEL_AKF_FILL_OFF               20      /* callback function: AkfCommand */
#define  PANEL_AKF_FILL_ON                21      /* callback function: AkfCommand */

#define  PANEL_CFM                        2
#define  PANEL_CFM_NO                     2
#define  PANEL_CFM_YES                    3
#define  PANEL_CFM_DECORATION             4
#define  PANEL_CFM_DECORATION_2           5

#define  PANEL_DRY                        3       /* callback function: ExitDialog */
#define  PANEL_DRY_DECORATION_7           2
#define  PANEL_DRY_DECORATION_6           3
#define  PANEL_DRY_BUBB_LAB               4
#define  PANEL_DRY_SHUT_LAB               5
#define  PANEL_DRY_HEAT_LAB               6
#define  PANEL_DRY_TIMER                  7       /* callback function: DryTankTimer */
#define  PANEL_DRY_ONLINE_LAB             8
#define  PANEL_DRY_AUTO_LAB               9
#define  PANEL_DRY_SHUT_OFF               10      /* callback function: DryCommand */
#define  PANEL_DRY_CV_LAB                 11
#define  PANEL_DRY_HEAT_OFF               12      /* callback function: DryCommand */
#define  PANEL_DRY_HEAT_ON                13      /* callback function: DryCommand */
#define  PANEL_DRY_DOOR_OFF               14      /* callback function: DryCommand */
#define  PANEL_DRY_DOOR_ON                15      /* callback function: DryCommand */
#define  PANEL_DRY_PUMP_OFF               16      /* callback function: DryCommand */
#define  PANEL_DRY_SHUT_ON                17      /* callback function: DryCommand */
#define  PANEL_DRY_AUTO_OFF               18      /* callback function: DryCommand */
#define  PANEL_DRY_AUTO_ON                19      /* callback function: DryCommand */
#define  PANEL_DRY_PUMP_ON                20      /* callback function: DryCommand */
#define  PANEL_DRY_CV_OFF                 21      /* callback function: DryCommand */
#define  PANEL_DRY_CV_ON                  22      /* callback function: DryCommand */

#define  PANEL_EMO                        4
#define  PANEL_EMO_CONTINUE               2       /* callback function: HandleEMO */
#define  PANEL_EMO_RESET                  3       /* callback function: HandleEMO */
#define  PANEL_EMO_TEXTMSG                4

#define  PANEL_HIS                        5       /* callback function: ExitDialog */
#define  PANEL_HIS_RING_TYPE              2
#define  PANEL_HIS_RING_DATE              3
#define  PANEL_HIS_COMMANDBUTTON          4       /* callback function: ViewHis */

#define  PANEL_LOAD                       6       /* callback function: ExitDialog */
#define  PANEL_LOAD_DECORATION_7          2
#define  PANEL_LOAD_DECORATION_6          3
#define  PANEL_LOAD_BUBB_LAB_2            4
#define  PANEL_LOAD_BUBB_LAB              5
#define  PANEL_LOAD_SHUT_LAB              6
#define  PANEL_LOAD_TIMER                 7       /* callback function: LoadTimer */
#define  PANEL_LOAD_ONLINE_LAB            8
#define  PANEL_LOAD_AUTO_LAB              9
#define  PANEL_LOAD_FILL_LAB              10
#define  PANEL_LOAD_SHUT_OFF              11      /* callback function: LoadCommand */
#define  PANEL_LOAD_AC_UP_2               12      /* callback function: LoadAdj */
#define  PANEL_LOAD_AC_UP                 13      /* callback function: LoadAdj */
#define  PANEL_LOAD_AC_DOWN_2             14      /* callback function: LoadAdj */
#define  PANEL_LOAD_AC_DOWN               15      /* callback function: LoadAdj */
#define  PANEL_LOAD_AC_LEFT               16      /* callback function: LoadAdj */
#define  PANEL_LOAD_AC_RIGHT              17      /* callback function: LoadAdj */
#define  PANEL_LOAD_SHUT_ON               18      /* callback function: LoadCommand */
#define  PANEL_LOAD_ONLINE_OFF            19      /* callback function: LoadCommand */
#define  PANEL_LOAD_MLD_OFF               20      /* callback function: LoadCommand */
#define  PANEL_LOAD_ONLINE_ON             21      /* callback function: LoadCommand */
#define  PANEL_LOAD_DOOR_OFF              22      /* callback function: LoadCommand */
#define  PANEL_LOAD_AUTO_OFF              23      /* callback function: LoadCommand */
#define  PANEL_LOAD_AUTO_ON               24      /* callback function: LoadCommand */
#define  PANEL_LOAD_MLD_ON                25      /* callback function: LoadCommand */
#define  PANEL_LOAD_DOOR_ON               26      /* callback function: LoadCommand */
#define  PANEL_LOAD_FILL_OFF              27      /* callback function: LoadCommand */
#define  PANEL_LOAD_FILL_ON               28      /* callback function: LoadCommand */

#define  PANEL_PLC                        7       /* callback function: ExitDialog */
#define  PANEL_PLC_LEDOFF                 2
#define  PANEL_PLC_LEDON                  3
#define  PANEL_PLC_TREE                   4       /* callback function: TreeSelectChange */
#define  PANEL_PLC_TABLE                  5       /* callback function: TableEvent */
#define  PANEL_PLC_TIMER                  6       /* callback function: iotimer */

#define  PANEL_RCP                        8       /* callback function: ExitDialog */
#define  PANEL_RCP_TABLE                  2
#define  PANEL_RCP_PRE_TM12               3
#define  PANEL_RCP_DELETE                 4       /* callback function: addDosingSetting */
#define  PANEL_RCP_ADD                    5       /* callback function: addDosingSetting */
#define  PANEL_RCP_PRE_TM01               6
#define  PANEL_RCP_PRE_TM05               7
#define  PANEL_RCP_PRE_TM04               8
#define  PANEL_RCP_PRE_TM03               9
#define  PANEL_RCP_PRE_TM02               10
#define  PANEL_RCP_PRE_TM06               11
#define  PANEL_RCP_PRE_TM09               12
#define  PANEL_RCP_PRE_TM08               13
#define  PANEL_RCP_PRE_TM07               14
#define  PANEL_RCP_PRE_TM11               15
#define  PANEL_RCP_PRE_TM10               16
#define  PANEL_RCP_PRE_TM16               17
#define  PANEL_RCP_PRE_TM15               18
#define  PANEL_RCP_PRE_TM14               19
#define  PANEL_RCP_PRE_TM13               20
#define  PANEL_RCP_P_TM_12                21
#define  PANEL_RCP_P_TM_05                22
#define  PANEL_RCP_P_TM_01                23
#define  PANEL_RCP_P_TM_04                24
#define  PANEL_RCP_P_TM_03                25
#define  PANEL_RCP_P_TM_02                26
#define  PANEL_RCP_P_TM_06                27
#define  PANEL_RCP_P_TM_08                28
#define  PANEL_RCP_P_TM_09                29
#define  PANEL_RCP_P_TM_07                30
#define  PANEL_RCP_P_TM_16                31
#define  PANEL_RCP_P_TM_15                32
#define  PANEL_RCP_P_TM_11                33
#define  PANEL_RCP_P_TM_10                34
#define  PANEL_RCP_P_TM_14                35
#define  PANEL_RCP_P_TM_13                36
#define  PANEL_RCP_TMP_IN                 37
#define  PANEL_RCP_TMP_P_IN               38
#define  PANEL_RCP_TMP_L_IN               39
#define  PANEL_RCP_TMP_P_PH2              40
#define  PANEL_RCP_TMP_H_IN               41
#define  PANEL_RCP_TMP_L_PH2              42
#define  PANEL_RCP_TMP_P_PH1              43
#define  PANEL_RCP_TMP_H_PH2              44
#define  PANEL_RCP_TMP_P_17               45
#define  PANEL_RCP_TMP_PH2                46
#define  PANEL_RCP_TMP_P_16               47
#define  PANEL_RCP_TMP_L_PH1              48
#define  PANEL_RCP_TMP_H_PH1              49
#define  PANEL_RCP_TMP_P_15               50
#define  PANEL_RCP_TMP_L_17               51
#define  PANEL_RCP_TMP_P_14               52
#define  PANEL_RCP_TMP_H_17               53
#define  PANEL_RCP_TMP_L_16               54
#define  PANEL_RCP_TMP_P_13               55
#define  PANEL_RCP_TMP_PH1                56
#define  PANEL_RCP_TMP_H_16               57
#define  PANEL_RCP_TMP_P_12               58
#define  PANEL_RCP_TMP_L_15               59
#define  PANEL_RCP_TMP_P_10               60
#define  PANEL_RCP_TMP_H_15               61
#define  PANEL_RCP_TMP_L_14               62
#define  PANEL_RCP_TMP_P_9                63
#define  PANEL_RCP_TMP_H_14               64
#define  PANEL_RCP_TMP_17                 65
#define  PANEL_RCP_TMP_L_13               66
#define  PANEL_RCP_TMP_H_13               67
#define  PANEL_RCP_TMP_P_7                68
#define  PANEL_RCP_TMP_16                 69
#define  PANEL_RCP_TMP_L_12               70
#define  PANEL_RCP_TMP_H_12               71
#define  PANEL_RCP_TMP_L_10               72
#define  PANEL_RCP_TMP_15                 73
#define  PANEL_RCP_TMP_P_6                74
#define  PANEL_RCP_TMP_H_10               75
#define  PANEL_RCP_TMP_L_9                76
#define  PANEL_RCP_TMP_14                 77
#define  PANEL_RCP_TMP_H_9                78
#define  PANEL_RCP_TMP_13                 79
#define  PANEL_RCP_TMP_P_4                80
#define  PANEL_RCP_TMP_12                 81
#define  PANEL_RCP_TMP_L_7                82
#define  PANEL_RCP_TMP_10                 83
#define  PANEL_RCP_TEXTMSG_172            84
#define  PANEL_RCP_TMP_P_3                85
#define  PANEL_RCP_TMP_H_7                86
#define  PANEL_RCP_TMP_9                  87
#define  PANEL_RCP_TEXTMSG_171            88
#define  PANEL_RCP_TMP_P_2                89
#define  PANEL_RCP_TMP_L_6                90
#define  PANEL_RCP_TMP_7                  91
#define  PANEL_RCP_TEXTMSG_170            92
#define  PANEL_RCP_TMP_H_6                93
#define  PANEL_RCP_TMP_6                  94
#define  PANEL_RCP_TEXTMSG_169            95
#define  PANEL_RCP_TMP_L_4                96
#define  PANEL_RCP_TMP_4                  97
#define  PANEL_RCP_TEXTMSG_168            98
#define  PANEL_RCP_TMP_H_4                99
#define  PANEL_RCP_TMP_3                  100
#define  PANEL_RCP_TMP_L_3                101
#define  PANEL_RCP_TEXTMSG_167            102
#define  PANEL_RCP_TMP_H_3                103
#define  PANEL_RCP_TMP_2                  104
#define  PANEL_RCP_TMP_L_2                105
#define  PANEL_RCP_TEXTMSG_166            106
#define  PANEL_RCP_TMP_H_2                107
#define  PANEL_RCP_DRAINCH4_04            108
#define  PANEL_RCP_DRAINCH3_02            109
#define  PANEL_RCP_DRAINCH2_02            110
#define  PANEL_RCP_DRAINCH3_04            111
#define  PANEL_RCP_DRAINCH1_02            112
#define  PANEL_RCP_DRAINCH2_04            113
#define  PANEL_RCP_DRAINCH4_07            114
#define  PANEL_RCP_DRAINCH1_04            115
#define  PANEL_RCP_DRAINCH3_11            116
#define  PANEL_RCP_DRAINCH2_11            117
#define  PANEL_RCP_DRAINCH3_07            118
#define  PANEL_RCP_DRAINCH1_11            119
#define  PANEL_RCP_DRAINCH2_07            120
#define  PANEL_RCP_PDCH4_04               121
#define  PANEL_RCP_DRAINCH1_07            122
#define  PANEL_RCP_PDCH3_04               123
#define  PANEL_RCP_PDCH2_04               124
#define  PANEL_RCP_PDCH4_07               125
#define  PANEL_RCP_PDCH1_04               126
#define  PANEL_RCP_PDCH3_07               127
#define  PANEL_RCP_PDRAIN_04              128
#define  PANEL_RCP_PDCH2_07               129
#define  PANEL_RCP_DOS_TEMP_5             130
#define  PANEL_RCP_PDCH1_07               131
#define  PANEL_RCP_DOS_TEMP_04            132
#define  PANEL_RCP_PDRAIN_07              133
#define  PANEL_RCP_TEXTMSG_165            134
#define  PANEL_RCP_PD_CYCLE               135
#define  PANEL_RCP_PD_START               136
#define  PANEL_RCP_DOS_TEMP_07            137
#define  PANEL_RCP_TEXTMSG_164            138
#define  PANEL_RCP_HDIW5_RUN              139
#define  PANEL_RCP_PH2_TEMP_STOP          140
#define  PANEL_RCP_PH2_TEMP_START         141
#define  PANEL_RCP_PH1_TEMP_STOP          142
#define  PANEL_RCP_PH1_TEMP_START         143
#define  PANEL_RCP_DOS_TEMP_02            144
#define  PANEL_RCP_DOS_07_AC4_S           145
#define  PANEL_RCP_TEXTMSG_203            146
#define  PANEL_RCP_DOS_07_AC4_R           147
#define  PANEL_RCP_DOS_07_AC4             148     /* callback function: changTankCh */
#define  PANEL_RCP_DOS_04_AC4_S           149
#define  PANEL_RCP_TEXTMSG_196            150
#define  PANEL_RCP_DRAIN_11_T             151
#define  PANEL_RCP_DRAIN_07_T             152
#define  PANEL_RCP_DRAIN_02_T             153
#define  PANEL_RCP_DRAIN_04_T             154
#define  PANEL_RCP_DRAIN_11_R             155
#define  PANEL_RCP_DRAIN_02_R             156
#define  PANEL_RCP_TEXTMSG_204            157
#define  PANEL_RCP_DRAIN_07_R             158
#define  PANEL_RCP_DRAIN_04_R             159
#define  PANEL_RCP_DOS_04_AC4_R           160
#define  PANEL_RCP_TEXTMSG_197            161
#define  PANEL_RCP_DOS_04_AC4             162     /* callback function: changTankCh */
#define  PANEL_RCP_DOS_11_AC3_S           163
#define  PANEL_RCP_DOS_11_AC3_R           164
#define  PANEL_RCP_TEXTMSG_176            165
#define  PANEL_RCP_DOS_07_AC3_S           166
#define  PANEL_RCP_DOS_11_AC3             167     /* callback function: changTankCh */
#define  PANEL_RCP_DOS_07_AC3_R           168
#define  PANEL_RCP_DOS_04_AC3_S           169
#define  PANEL_RCP_TEXTMSG_198            170
#define  PANEL_RCP_DOS_07_AC3             171     /* callback function: changTankCh */
#define  PANEL_RCP_TEXTMSG_199            172
#define  PANEL_RCP_TEXTMSG_200            173
#define  PANEL_RCP_DOS_04_AC3_R           174
#define  PANEL_RCP_DOS_04_AC3             175     /* callback function: changTankCh */
#define  PANEL_RCP_DOS_02_AC3_S           176
#define  PANEL_RCP_DOS_02_AC3_R           177
#define  PANEL_RCP_TEXTMSG_177            178
#define  PANEL_RCP_DOS_02_AC3             179     /* callback function: changTankCh */
#define  PANEL_RCP_DOS_11_AC2_S           180
#define  PANEL_RCP_DOS_07_AC2_S           181
#define  PANEL_RCP_DOS_11_AC2_R           182
#define  PANEL_RCP_DOS_11_AC2             183     /* callback function: changTankCh */
#define  PANEL_RCP_DOS_07_AC2_R           184
#define  PANEL_RCP_DOS_04_AC2_S           185
#define  PANEL_RCP_DOS_07_AC2             186     /* callback function: changTankCh */
#define  PANEL_RCP_TEXTMSG_201            187
#define  PANEL_RCP_TEXTMSG_178            188
#define  PANEL_RCP_TEXTMSG_202            189
#define  PANEL_RCP_DOS_04_AC2_R           190
#define  PANEL_RCP_TEXTMSG_185            191
#define  PANEL_RCP_TEXTMSG_186            192
#define  PANEL_RCP_DOS_02_AC2_S           193
#define  PANEL_RCP_DOS_04_AC2             194     /* callback function: changTankCh */
#define  PANEL_RCP_DOS_02_AC2_R           195
#define  PANEL_RCP_DOS_11_AC1_S           196
#define  PANEL_RCP_DOS_02_AC2             197     /* callback function: changTankCh */
#define  PANEL_RCP_DOS_07_AC1_S           198
#define  PANEL_RCP_DOS_11_AC1_R           199
#define  PANEL_RCP_DOS_04_AC1_S           200
#define  PANEL_RCP_DOS_11_AC1             201     /* callback function: changTankCh */
#define  PANEL_RCP_DOS_07_AC1_R           202
#define  PANEL_RCP_DOS_07_AC1             203     /* callback function: changTankCh */
#define  PANEL_RCP_DOS_04_AC1_R           204
#define  PANEL_RCP_DOS_04_AC1             205     /* callback function: changTankCh */
#define  PANEL_RCP_TEXTMSG_180            206
#define  PANEL_RCP_DOS_02_AC1_S           207
#define  PANEL_RCP_TEXTMSG_181            208
#define  PANEL_RCP_TEXTMSG_182            209
#define  PANEL_RCP_DOS_02_AC1_R           210
#define  PANEL_RCP_DOS_02_AC1             211     /* callback function: changTankCh */
#define  PANEL_RCP_DECORATION_8           212
#define  PANEL_RCP_TEXTMSG_163            213
#define  PANEL_RCP_TEXTMSG_184            214
#define  PANEL_RCP_PARTID                 215
#define  PANEL_RCP_QTY                    216
#define  PANEL_RCP_TEXTMSG_205            217
#define  PANEL_RCP_TEXTMSG_173            218
#define  PANEL_RCP_RCIP_X00               219     /* callback function: Call_Recipe */
#define  PANEL_RCP_TEXTMSG_162            220
#define  PANEL_RCP_RCIP_0X0               221     /* callback function: Call_Recipe */
#define  PANEL_RCP_RCIP_00X               222     /* callback function: Call_Recipe */
#define  PANEL_RCP_RCIP_NAME              223
#define  PANEL_RCP_TEXTMSG_206            224
#define  PANEL_RCP_TEXTMSG_161            225
#define  PANEL_RCP_TEXTMSG_113            226
#define  PANEL_RCP_TEXTMSG_62             227
#define  PANEL_RCP_TEXTMSG_85             228
#define  PANEL_RCP_TEXTMSG_160            229
#define  PANEL_RCP_RCIP_CREATE            230
#define  PANEL_RCP_TEXTBOX                231
#define  PANEL_RCP_TEXTMSG_174            232
#define  PANEL_RCP_TEXTMSG_159            233
#define  PANEL_RCP_TEXTMSG_123            234
#define  PANEL_RCP_DECORATION_7           235
#define  PANEL_RCP_DECORATION_6           236
#define  PANEL_RCP_TEXTMSG_122            237
#define  PANEL_RCP_TEXTMSG_158            238
#define  PANEL_RCP_TEXTMSG_187            239
#define  PANEL_RCP_TEXTMSG_121            240
#define  PANEL_RCP_RCIP_COPY              241     /* callback function: Call_Recipe */
#define  PANEL_RCP_RCIP_PAST              242     /* callback function: Call_Recipe */
#define  PANEL_RCP_RCIP_MODIFY            243     /* callback function: Call_Recipe */
#define  PANEL_RCP_RCIP_SAVE              244     /* callback function: Call_Recipe */
#define  PANEL_RCP_TEXTMSG_114            245
#define  PANEL_RCP_TEXTMSG_104            246
#define  PANEL_RCP_TEXTMSG_87             247
#define  PANEL_RCP_TEXTMSG_6              248
#define  PANEL_RCP_TEXTMSG_7              249
#define  PANEL_RCP_TEXTMSG_207            250
#define  PANEL_RCP_TEXTMSG_8              251
#define  PANEL_RCP_TEXTMSG_64             252
#define  PANEL_RCP_TEXTMSG_63             253
#define  PANEL_RCP_TEXTMSG_194            254
#define  PANEL_RCP_TEXTMSG_66             255
#define  PANEL_RCP_TEXTMSG_188            256
#define  PANEL_RCP_TEXTMSG_189            257
#define  PANEL_RCP_TEXTMSG_190            258
#define  PANEL_RCP_TEXTMSG_191            259
#define  PANEL_RCP_TEXTMSG_195            260
#define  PANEL_RCP_TEXTMSG_192            261
#define  PANEL_RCP_TEXTMSG_16             262
#define  PANEL_RCP_TEXTMSG_193            263
#define  PANEL_RCP_TEXTMSG_139            264
#define  PANEL_RCP_TEXTMSG_138            265
#define  PANEL_RCP_TEXTMSG_137            266
#define  PANEL_RCP_TEXTMSG_136            267
#define  PANEL_RCP_TEXTMSG_135            268
#define  PANEL_RCP_TEXTMSG_150            269
#define  PANEL_RCP_TEXTMSG_152            270
#define  PANEL_RCP_TEXTMSG_153            271
#define  PANEL_RCP_TEXTMSG_127            272
#define  PANEL_RCP_TEXTMSG_126            273
#define  PANEL_RCP_TEXTMSG_155            274
#define  PANEL_RCP_TEXTMSG_148            275
#define  PANEL_RCP_TEXTMSG_154            276
#define  PANEL_RCP_TEXTMSG_147            277
#define  PANEL_RCP_TEXTMSG_151            278
#define  PANEL_RCP_TEXTMSG_156            279
#define  PANEL_RCP_TEXTMSG_125            280
#define  PANEL_RCP_TEXTMSG_157            281
#define  PANEL_RCP_TEXTMSG_124            282
#define  PANEL_RCP_TEXTMSG_60             283
#define  PANEL_RCP_LOTID                  284
#define  PANEL_RCP_TEXTMSG_83             285
#define  PANEL_RCP_DECORATION_5           286
#define  PANEL_RCP_DECORATION             287
#define  PANEL_RCP_DECORATION_2           288
#define  PANEL_RCP_DECORATION_4           289
#define  PANEL_RCP_RCIP_COFM              290     /* callback function: RecipeConfirm */
#define  PANEL_RCP_CHECKBOX_HDIW5         291
#define  PANEL_RCP_RING                   292     /* callback function: Call_Recipe */

#define  PANEL_SET                        9       /* callback function: ExitDialog */
#define  PANEL_SET_CHECKBOX_IPA           2
#define  PANEL_SET_CHECKBOX_SAFE          3
#define  PANEL_SET_CHECKBOX_EXHAUST       4
#define  PANEL_SET_CHECKBOX_DOOR          5
#define  PANEL_SET_CHECKBOX_CHUCK         6
#define  PANEL_SET_DOWN_DELAY_15          7
#define  PANEL_SET_DOWN_DELAY_14          8
#define  PANEL_SET_DOWN_DELAY_13          9
#define  PANEL_SET_DOWN_DELAY_12          10
#define  PANEL_SET_DOWN_DELAY_11          11
#define  PANEL_SET_DOWN_DELAY_10          12
#define  PANEL_SET_DOWN_DELAY_9           13
#define  PANEL_SET_DOWN_DELAY_8           14
#define  PANEL_SET_DOWN_DELAY_7           15
#define  PANEL_SET_DOWN_DELAY_6           16
#define  PANEL_SET_DOWN_DELAY_5           17
#define  PANEL_SET_DOWN_DELAY_4           18
#define  PANEL_SET_DOWN_DELAY_3           19
#define  PANEL_SET_DOWN_DELAY_2           20
#define  PANEL_SET_SAVE                   21      /* callback function: Save */
#define  PANEL_SET_AUTH_EXIT3             22
#define  PANEL_SET_AUTH_SET3              23
#define  PANEL_SET_AUTH_ROBOT3            24
#define  PANEL_SET_AUTH_TANK3             25
#define  PANEL_SET_AUTH_USER3             26
#define  PANEL_SET_AUTH_RECIPE3           27
#define  PANEL_SET_AUTH_EXIT2             28
#define  PANEL_SET_AUTH_SET2              29
#define  PANEL_SET_TEXTMSG_126            30
#define  PANEL_SET_AUTH_ROBOT2            31
#define  PANEL_SET_AUTH_TANK2             32
#define  PANEL_SET_AUTH_USER2             33
#define  PANEL_SET_AUTH_RECIPE2           34
#define  PANEL_SET_AUTH_EXIT1             35
#define  PANEL_SET_AUTH_SET1              36
#define  PANEL_SET_TEXTMSG_125            37
#define  PANEL_SET_AUTH_ROBOT1            38
#define  PANEL_SET_AUTH_TANK1             39
#define  PANEL_SET_AUTH_USER1             40
#define  PANEL_SET_AUTH_RECIPE1           41
#define  PANEL_SET_DECORATION_3           42
#define  PANEL_SET_DECORATION_2           43
#define  PANEL_SET_DECORATION             44
#define  PANEL_SET_TEXTMSG_121            45
#define  PANEL_SET_TEXTMSG_122            46

#define  PANEL_TAG                        10
#define  PANEL_TAG_ID                     2
#define  PANEL_TAG_OK                     3       /* callback function: ReadTagSelect */
#define  PANEL_TAG_ID_RADIOGROUP          4       /* callback function: ReadTagSelect */
#define  PANEL_TAG_TEXTMSG                5

#define  PANEL_TANK                       11      /* callback function: ExitDialog */
#define  PANEL_TANK_VALVE_MAKE_AC1_IN     2
#define  PANEL_TANK_VALVE_MAKE_AC2_IN     3
#define  PANEL_TANK_VALVE_DOS_AC4_IN      4
#define  PANEL_TANK_VALVE_DOS_AC3_IN      5
#define  PANEL_TANK_VALVE_DOWN            6
#define  PANEL_TANK_AC3_MAKE              7
#define  PANEL_TANK_AC4_MAKE              8
#define  PANEL_TANK_AC1_MAKE              9
#define  PANEL_TANK_AC2_MAKE              10
#define  PANEL_TANK_VALVE_DIW_IN          11
#define  PANEL_TANK_DECORATION_MAKE       12
#define  PANEL_TANK_DECORATION_DOS        13
#define  PANEL_TANK_VALVE_MAKE_AC3_IN     14
#define  PANEL_TANK_DECORATION_6          15
#define  PANEL_TANK_VALVE_MAKE_AC4_IN     16
#define  PANEL_TANK_VALVE_DOS_AC4_OUT     17
#define  PANEL_TANK_VALVE_DOS_AC2_IN      18
#define  PANEL_TANK_VALVE_DOS_AC3_OUT     19
#define  PANEL_TANK_VALVE_DOS_AC1_IN      20
#define  PANEL_TANK_VALVE_DOS_AC2_OUT     21
#define  PANEL_TANK_SPLITTER_11           22
#define  PANEL_TANK_SPLITTER_12           23
#define  PANEL_TANK_VALVE_DOS_AC1_OUT     24
#define  PANEL_TANK_SPLITTER_13           25
#define  PANEL_TANK_SPLITTER_10           26
#define  PANEL_TANK_HEATER                27
#define  PANEL_TANK_SPLITTER_14           28
#define  PANEL_TANK_SPLITTER_9            29
#define  PANEL_TANK_SPLITTER_4            30
#define  PANEL_TANK_SPLITTER_3            31
#define  PANEL_TANK_SHUT                  32
#define  PANEL_TANK_SPLITTER_2            33
#define  PANEL_TANK_PUMPIN                34
#define  PANEL_TANK_PUMP                  35
#define  PANEL_TANK_SPLITTER              36
#define  PANEL_TANK_SPLITTER_8            37
#define  PANEL_TANK_SPLITTER_7            38
#define  PANEL_TANK_SPLITTER_6            39
#define  PANEL_TANK_HEAT_LAB              40
#define  PANEL_TANK_PUMPIN_LAB            41
#define  PANEL_TANK_PUMP_LAB              42
#define  PANEL_TANK_DOWN_LAB              43
#define  PANEL_TANK_AMAKE_LAB             44
#define  PANEL_TANK_ADD_WATER_LAB         45
#define  PANEL_TANK_WASH_LAB              46
#define  PANEL_TANK_SPLITTER_5            47
#define  PANEL_TANK_SHUT_LAB              48
#define  PANEL_TANK_AC3_DOS_BUF           49
#define  PANEL_TANK_AC2_DOS_BUF           50
#define  PANEL_TANK_AC4_DOS_BUF           51
#define  PANEL_TANK_AC1_DOS_BUF           52
#define  PANEL_TANK_CAR2                  53
#define  PANEL_TANK_CAR1                  54
#define  PANEL_TANK_TANK                  55
#define  PANEL_TANK_MMAKE_LAB             56
#define  PANEL_TANK_BUBBLE1               57
#define  PANEL_TANK_BUBBLE2               58
#define  PANEL_TANK_BUBBLE3               59
#define  PANEL_TANK_TIMER                 60      /* callback function: TankTimer */
#define  PANEL_TANK_BUBBLE4               61
#define  PANEL_TANK_BUBBLE5               62
#define  PANEL_TANK_BUBBLE6               63
#define  PANEL_TANK_BUBBLE7               64
#define  PANEL_TANK_AMAKE_OFF             65      /* callback function: Command */
#define  PANEL_TANK_AMAKE_ON              66      /* callback function: Command */
#define  PANEL_TANK_FILL2_LAB             67
#define  PANEL_TANK_ADD_WATER_OFF         68      /* callback function: Command */
#define  PANEL_TANK_FILL1_LAB             69
#define  PANEL_TANK_WASH_OFF              70      /* callback function: Command */
#define  PANEL_TANK_ADD_WATER_ON          71      /* callback function: Command */
#define  PANEL_TANK_WASH_ON               72      /* callback function: Command */
#define  PANEL_TANK_MMAKE_OFF             73      /* callback function: Command */
#define  PANEL_TANK_MMAKE_ON              74      /* callback function: Command */
#define  PANEL_TANK_DOWN_OFF              75      /* callback function: Command */
#define  PANEL_TANK_PUMPIN_OFF            76      /* callback function: Command */
#define  PANEL_TANK_PUMPIN_ON             77      /* callback function: Command */
#define  PANEL_TANK_DOWN_ON               78      /* callback function: Command */
#define  PANEL_TANK_PUMP_OFF              79      /* callback function: Command */
#define  PANEL_TANK_PUMP_ON               80      /* callback function: Command */
#define  PANEL_TANK_HEAT_OFF              81      /* callback function: Command */
#define  PANEL_TANK_STRIPCHART            82
#define  PANEL_TANK_HEAT_ON               83      /* callback function: Command */
#define  PANEL_TANK_SHUT_OFF              84      /* callback function: Command */
#define  PANEL_TANK_FILL2_OFF             85      /* callback function: Command */
#define  PANEL_TANK_SHUT_ON               86      /* callback function: Command */
#define  PANEL_TANK_FILL_OFF              87      /* callback function: Command */
#define  PANEL_TANK_FILL2_ON              88      /* callback function: Command */
#define  PANEL_TANK_FILL_ON               89      /* callback function: Command */
#define  PANEL_TANK_AC2_DOS_ON            90      /* callback function: Command */
#define  PANEL_TANK_AC2_DOS_OFF           91      /* callback function: Command */
#define  PANEL_TANK_AC1_DOS_ON            92      /* callback function: Command */
#define  PANEL_TANK_AC1_DOS_OFF           93      /* callback function: Command */
#define  PANEL_TANK_MMAKE_CH1             94
#define  PANEL_TANK_MMAKE_CH2             95
#define  PANEL_TANK_MMAKE_CH3             96
#define  PANEL_TANK_MAKE_CH1              97
#define  PANEL_TANK_MAKE_CH2              98
#define  PANEL_TANK_MAKE_CH3              99
#define  PANEL_TANK_MMAKE_CH4             100
#define  PANEL_TANK_AC1_DOS_LAB           101
#define  PANEL_TANK_AC2_DOS_LAB           102
#define  PANEL_TANK_AC4_DOS_ON            103     /* callback function: Command */
#define  PANEL_TANK_MAKE_CH4              104
#define  PANEL_TANK_AC4_DOS_OFF           105     /* callback function: Command */
#define  PANEL_TANK_AC3_DOS_ON            106     /* callback function: Command */
#define  PANEL_TANK_AC3_DOS_OFF           107     /* callback function: Command */
#define  PANEL_TANK_AC3_DOS_LAB           108
#define  PANEL_TANK_AC4_DOS_LAB           109
#define  PANEL_TANK_DOS_CH4               110
#define  PANEL_TANK_DOS_CH3               111
#define  PANEL_TANK_DOS_CH2               112
#define  PANEL_TANK_TEMP                  113
#define  PANEL_TANK_COND                  114
#define  PANEL_TANK_FLOW                  115
#define  PANEL_TANK_DOS_CH1               116

#define  PANEL_USER                       12      /* callback function: ExitDialog */
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

#define  PANELOGIN                        13
#define  PANELOGIN_UID                    2       /* callback function: Change_Account */
#define  PANELOGIN_PWD                    3       /* callback function: Change_Account */
#define  PANELOGIN_CANCEL                 4       /* callback function: Change_Account */
#define  PANELOGIN_CONFIRM                5       /* callback function: Change_Account */
#define  PANELOGIN_DECORATION             6
#define  PANELOGIN_DECORATION_2           7


     /* Menu Bars, Menus, and Menu Items: */

          /* (no menu bars in the resource file) */


     /* Callback Prototypes: */

int  CVICALLBACK addDosingSetting(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK AKFAdj(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK AkfCommand(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK AKFTankTimer(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Call_Recipe(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Change_Account(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK changTankCh(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Command(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK DryCommand(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK DryTankTimer(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK ExitDialog(int panel, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK HandleEMO(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK iotimer(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK LoadAdj(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK LoadCommand(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK LoadTimer(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK ReadTagSelect(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK RecipeConfirm(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK Save(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK TableEvent(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK TankTimer(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK TreeSelectChange(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK UserCommand(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);
int  CVICALLBACK ViewHis(int panel, int control, int event, void *callbackData, int eventData1, int eventData2);


#ifdef __cplusplus
    }
#endif
