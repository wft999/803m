#include <cvidef.h>

/* ####################################################################################################### */
/* ##						Function for HP-4339b External Linking										## */
/* ##								HP-4339b Hi-Volt Meter												## */
/* ####################################################################################################### */
/* ##　初始化呼叫方式																					## */
/* ##	 Meter2410 ( _Initial, NULL, NULL, NULL, NULL, *DataBuffer);									## */
/* ##																									## */
/* ##　ReStore 方式																						## */
/* ##	 Meter2410 ( _ReStore, NULL, NULL, NULL, NULL, *DataBuffer);									## */
/* ##																									## */
/* ##　Terminal 檢查方式																				## */
/* ##	 Meter2410 ( _TermCHK, MeterIndex, NULL, NULL, NULL, *DataBuffer);								## */
/* ##			return 值：  0[REAR];  1[FRONT];														## */
/* ##																									## */
/* ##　Terminal 設定方式																				## */
/* ##	 Meter2410 ( _TermSET, [ 0 | 1 ], NULL, NULL, NULL, NULL, *DataBuffer);							## */
/* ##			PARA1： 0[REAR];  1[FRONT];																## */
/* ####################################################################################################### */

//=============================================================================[ Meter ]
// COM Port Used
#define _PLC_COMM_PORT		1

// PLC Data Register
#define _BR_X	0x01	// INPUT	Relay	A:X0000-X07FF	AnA/ANU:
#define _BR_Y	0x02	// OutPut	Relay	A:Y0000-Y07FF
#define _BR_M	0x05	// Internal Relay	A:M0000-M2047
#define _BR_L	0x04	// Latch	Relay	A:L0000-L2047
#define _BR_S	0x06	// Step		Relay	A:S0000-S2047
#define _BR_B	0x07	// Link		Relay	A:B0000-B03FF
#define _BR_F	0x08	// Annunciator		A:F0000-F0255
#define _BR_D	0x09	// Data 	Reg		A:D0000-D1023
#define _BR_TS	0x0A	// Timer(Contact)	A:TS000-TS255
#define _BR_TC	0x0B	// Timer(coil)		A:TC000-TC255
#define _BR_TN	0x0C	// Timer(Curr.Val)	A:TN000-TN255
#define _BR_CS	0x0D	// Counter(Contact)	A:CS000-CS255
#define _BR_CC	0x0E	// Counter(coil)	A:CC000-CC255
#define _BR_CN	0x0F	// Counter(Curr.Val)A:CN000-CN255
#define _BR_W	0x11	// Link		Reg		A:W0000-W03FF
#define _BR_R	0x12	// File		Reg		A:R0000-R8191

#define _WR_X	0x41	// INPUT	Relay	A:X0000-X07FF
#define _WR_Y	0x42	// OutPut	Relay	A:Y0000-Y07FF
#define _WR_M	0x45	// Internal Relay	A:M0000-M2047
#define _WR_L	0x44	// Latch	Relay	A:L0000-L2047
#define _WR_S	0x46	// Step		Relay	A:S0000-S2047
#define _WR_B	0x47	// Link		Relay	A:B0000-B03FF
#define _WR_F	0x48	// Annunciator		A:F0000-F0255
#define _WR_D	0x49	// Data 	Reg		A:D0000-D1023
#define _WR_TS	0x4A	// Timer(Contact)	A:TS000-TS255
#define _WR_TC	0x4B	// Timer(coil)		A:TC000-TC255
#define _WR_TN	0x4C	// Timer(Curr.Val)	A:TN000-TN255
#define _WR_CS	0x4D	// Counter(Contact)	A:CS000-CS255
#define _WR_CC	0x4E	// Counter(coil)	A:CC000-CC255
#define _WR_CN	0x4F	// Counter(Curr.Val)A:CN000-CN255
#define _WR_W	0x51	// Link		Reg		A:W0000-W03FF
#define _WR_R	0x52	// File		Reg		A:R0000-R8191

#define _BW_X	0x81	// INPUT	Relay	A:X0000-X07FF
#define _BW_Y	0x82	// OutPut	Relay	A:Y0000-Y07FF
#define _BW_M	0x85	// Internal Relay	A:M0000-M2047
#define _BW_L	0x84	// Latch	Relay	A:L0000-L2047
#define _BW_S	0x86	// Step		Relay	A:S0000-S2047
#define _BW_B	0x87	// Link		Relay	A:B0000-B03FF
#define _BW_F	0x88	// Annunciator		A:F0000-F0255
#define _BW_D	0x89	// Data 	Reg		A:D0000-D1023
#define _BW_TS	0x8A	// Timer(Contact)	A:TS000-TS255
#define _BW_TC	0x8B	// Timer(coil)		A:TC000-TC255
#define _BW_TN	0x8C	// Timer(Curr.Val)	A:TN000-TN255
#define _BW_CS	0x8D	// Counter(Contact)	A:CS000-CS255
#define _BW_CC	0x8E	// Counter(coil)	A:CC000-CC255
#define _BW_CN	0x8F	// Counter(Curr.Val)A:CN000-CN255
#define _BW_W	0x91	// Link		Reg		A:W0000-W03FF
#define _BW_R	0x92	// File		Reg		A:R0000-R8191

#define _WW_X	0xC1	// INPUT	Relay	A:X0000-X07FF
#define _WW_Y	0xC2	// OutPut	Relay	A:Y0000-Y07FF
#define _WW_M	0xC5	// Internal Relay	A:M0000-M2047
#define _WW_L	0xC4	// Latch	Relay	A:L0000-L2047
#define _WW_S	0xC6	// Step		Relay	A:S0000-S2047
#define _WW_B	0xC7	// Link		Relay	A:B0000-B03FF
#define _WW_F	0xC8	// Annunciator		A:F0000-F0255
#define _WW_D	0xC9	// Data 	Reg		A:D0000-D1023
#define _WW_TS	0xCA	// Timer(Contact)	A:TS000-TS255
#define _WW_TC	0xCB	// Timer(coil)		A:TC000-TC255
#define _WW_TN	0xCC	// Timer(Curr.Val)	A:TN000-TN255
#define _WW_CS	0xCD	// Counter(Contact)	A:CS000-CS255
#define _WW_CC	0xCE	// Counter(coil)	A:CC000-CC255
#define _WW_CN	0xCF	// Counter(Curr.Val)A:CN000-CN255
#define _WW_W	0xD1	// Link		Reg		A:W0000-W03FF
#define _WW_R	0xD2	// File		Reg		A:R0000-R8191


// Error Code
#define QERR_0000		0	// Success...
#define QERR_0001	-1001	//
#define QERR_0010	-1010	// No Function...
#define QERR_0020	-1020	// Retry Full Error...
#define QERR_0030	-1030	// Sending DataStruct Error... 
#define QERR_0031	-1031	// Data Length Error...
#define QERR_0040	-1040	// SumCode Error...


//=============================================================================[ Meter 變數宣告 ]
typedef struct 
{
	int		COM;			// COM.PORT USED
	long	Bau;			// COM.PORT Baudrate
	int		Par;			// COM.PORT Parity
	int		Dbit;			// COM.PORT DataBit
	int		Sbit;			// COM.PORT StopBit
	double	Tout;			// COM.PORT TimeOut
	int		Hctl;			// COM.PORT HardFlowControl
	int		useNet;			// PLC Net.ID
	unsigned char PlcID;	// PLC Station.ID
	unsigned char NetID;	// PLC Net.ID
	int 	ErrCD;			// COM.PORT ErrorCode
	char	DTRN[512];		// COM.PORT Respond String
//	int		TR_PHNDL;		// TX-RX LED Panel Handle
//	int		TX_HNDL;		// TX LED Control Handle
//	int		RX_HNDL;		// RX LED Control Handle
} MiPLC;

//=============================================================================[ Meter 函式宣告 ]
/* Remove 2008-04-12
int Mi_QPLC_CFG ( MiPLC *PLC);
int Mi_QPLC_GET ( int _Register, int _CmdDelay, int _sCH, int _nCH, MiPLC *PLC);
int Mi_QPLC_GET_Ex ( char* ReadMode, int _CmdDelay, char *DataReg, MiPLC *PLC);
int Mi_QPLC_SET ( int _Register, int _CmdDelay, int _sCH, int _nCH, char* Result, MiPLC *PLC);
int Mi_QPLC_END ( MiPLC *PLC);
*/
// =============================================================================
// Q CPU @ Frame_1C
//	int Cfg_Q_1CF1 ( MiPLC *PLC);
//	int Get_Q_1CF1 ( int _Register, int _CmdDelay, int _sCH, int _nCH, MiPLC *PLC);
//	int Set_Q_1CF1 ( int _Register, int _CmdDelay, int _sCH, int _nCH, char* Result, MiPLC *PLC);
//	int Cfg_Q_1CF2 ( MiPLC *PLC);
//	int Get_Q_1CF2 ( int _Register, int _CmdDelay, int _sCH, int _nCH, MiPLC *PLC);
//	int Set_Q_1CF2 ( int _Register, int _CmdDelay, int _sCH, int _nCH, char* Result, MiPLC *PLC);
//	int Cfg_Q_1CF3 ( MiPLC *PLC);
//	int Get_Q_1CF3 ( int _Register, int _CmdDelay, int _sCH, int _nCH, MiPLC *PLC);
//	int Set_Q_1CF3 ( int _Register, int _CmdDelay, int _sCH, int _nCH, char* Result, MiPLC *PLC);
	int Cfg_Q_1CF4 ( MiPLC *PLC);
	int Get_Q_1CF4 ( int _Register, int _CmdDelay, int _sCH, int _nCH, MiPLC *PLC);
	int Set_Q_1CF4 ( int _Register, int _CmdDelay, int _sCH, int _nCH, char* Result, MiPLC *PLC);
	int Get_Q_1CF4_Ex ( char* ReadMode, int _CmdDelay, char *DataReg, MiPLC *PLC);
	
//	int Cfg_Q_1CF5 ( MiPLC *PLC);
//	int Get_Q_1CF5 ( int _Register, int _CmdDelay, int _sCH, int _nCH, MiPLC *PLC);
//	int Set_Q_1CF5 ( int _Register, int _CmdDelay, int _sCH, int _nCH, char* Result, MiPLC *PLC);

// =============================================================================
// A CPU @ Frame_1C
//	int Cfg_A_1CF1 ( MiPLC *PLC);
//	int Get_A_1CF1 ( int _Register, int _CmdDelay, int _sCH, int _nCH, MiPLC *PLC);
//	int Set_A_1CF1 ( int _Register, int _CmdDelay, int _sCH, int _nCH, char* Result, MiPLC *PLC);
//	int Cfg_A_1CF2 ( MiPLC *PLC);
//	int Get_A_1CF2 ( int _Register, int _CmdDelay, int _sCH, int _nCH, MiPLC *PLC);
//	int Set_A_1CF2 ( int _Register, int _CmdDelay, int _sCH, int _nCH, char* Result, MiPLC *PLC);
//	int Cfg_A_1CF3 ( MiPLC *PLC);
//	int Get_A_1CF3 ( int _Register, int _CmdDelay, int _sCH, int _nCH, MiPLC *PLC);
//	int Set_A_1CF3 ( int _Register, int _CmdDelay, int _sCH, int _nCH, char* Result, MiPLC *PLC);
	int Cfg_A_1CF4 ( MiPLC *PLC);
	int Get_A_1CF4 ( int _Register, int _CmdDelay, int _sCH, int _nCH, MiPLC *PLC);
	int Set_A_1CF4 ( int _Register, int _CmdDelay, int _sCH, int _nCH, char* Result, MiPLC *PLC);
//	int Cfg_A_1CF5 ( MiPLC *PLC);
//	int Get_A_1CF5 ( int _Register, int _CmdDelay, int _sCH, int _nCH, MiPLC *PLC);
//	int Set_A_1CF5 ( int _Register, int _CmdDelay, int _sCH, int _nCH, char* Result, MiPLC *PLC);

// =============================================================================
// AnA/AnU @ Frame_1C
//	int Cfg_AnA_1CF1  ( MiPLC *PLC);
//	int Get_AnA_1CF1  ( int _Register, int _CmdDelay, int _sCH, int _nCH, MiPLC *PLC);
//	int Set_AnA_1CF1  ( int _Register, int _CmdDelay, int _sCH, int _nCH, char* Result, MiPLC *PLC);
//	int Cfg_AnA_1CF2  ( MiPLC *PLC);
//	int Get_AnA_1CF2  ( int _Register, int _CmdDelay, int _sCH, int _nCH, MiPLC *PLC);
//	int Set_AnA_1CF2  ( int _Register, int _CmdDelay, int _sCH, int _nCH, char* Result, MiPLC *PLC);
//	int Cfg_AnA_1CF3  ( MiPLC *PLC);
//	int Get_AnA_1CF3  ( int _Register, int _CmdDelay, int _sCH, int _nCH, MiPLC *PLC);
//	int Set_AnA_1CF3  ( int _Register, int _CmdDelay, int _sCH, int _nCH, char* Result, MiPLC *PLC);
	int Cfg_AnA_1CF4  ( MiPLC *PLC);
	int Get_AnA_1CF4  ( int _Register, int _CmdDelay, int _sCH, int _nCH, MiPLC *PLC);
	int Set_AnA_1CF4  ( int _Register, int _CmdDelay, int _sCH, int _nCH, char* Result, MiPLC *PLC);
//	int Cfg_AnA_1CF5  ( MiPLC *PLC);
//	int Get_AnA_1CF5  ( int _Register, int _CmdDelay, int _sCH, int _nCH, MiPLC *PLC);
//	int Set_AnA_1CF5  ( int _Register, int _CmdDelay, int _sCH, int _nCH, char* Result, MiPLC *PLC);

// =============================================================================
int Mi_QPLC_END ( MiPLC *PLC);
int End_PLC_Comm ( MiPLC *PLC);

