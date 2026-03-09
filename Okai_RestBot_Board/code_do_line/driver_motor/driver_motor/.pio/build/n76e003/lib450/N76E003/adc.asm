;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler 
; Version 4.4.0 #14620 (MINGW32)
;--------------------------------------------------------
	.module adc
	.optsdcc -mmcs51 --model-small
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _ADC_ComapreMode_PARM_2
	.globl _ADC_ConvertTime_PARM_2
	.globl _MOSI
	.globl _P00
	.globl _MISO
	.globl _P01
	.globl _RXD_1
	.globl _P02
	.globl _P03
	.globl _STADC
	.globl _P04
	.globl _P05
	.globl _TXD
	.globl _P06
	.globl _RXD
	.globl _P07
	.globl _IT0
	.globl _IE0
	.globl _IT1
	.globl _IE1
	.globl _TR0
	.globl _TF0
	.globl _TR1
	.globl _TF1
	.globl _P10
	.globl _P11
	.globl _P12
	.globl _SCL
	.globl _P13
	.globl _SDA
	.globl _P14
	.globl _P15
	.globl _TXD_1
	.globl _P16
	.globl _P17
	.globl _RI
	.globl _TI
	.globl _RB8
	.globl _TB8
	.globl _REN
	.globl _SM2
	.globl _SM1
	.globl _FE
	.globl _SM0
	.globl _P20
	.globl _EX0
	.globl _ET0
	.globl _EX1
	.globl _ET1
	.globl _ES
	.globl _EBOD
	.globl _EADC
	.globl _EA
	.globl _P30
	.globl _PX0
	.globl _PT0
	.globl _PX1
	.globl _PT1
	.globl _PS
	.globl _PBOD
	.globl _PADC
	.globl _I2CPX
	.globl _AA
	.globl _SI
	.globl _STO
	.globl _STA
	.globl _I2CEN
	.globl _CM_RL2
	.globl _TR2
	.globl _TF2
	.globl _P
	.globl _OV
	.globl _RS0
	.globl _RS1
	.globl _F0
	.globl _AC
	.globl _CY
	.globl _CLRPWM
	.globl _PWMF
	.globl _LOAD
	.globl _PWMRUN
	.globl _ADCHS0
	.globl _ADCHS1
	.globl _ADCHS2
	.globl _ADCHS3
	.globl _ETGSEL0
	.globl _ETGSEL1
	.globl _ADCS
	.globl _ADCF
	.globl _RI_1
	.globl _TI_1
	.globl _RB8_1
	.globl _TB8_1
	.globl _REN_1
	.globl _SM2_1
	.globl _SM1_1
	.globl _FE_1
	.globl _SM0_1
	.globl _EIPH1
	.globl _EIP1
	.globl _PORDIS
	.globl _PMD
	.globl _PMEN
	.globl _PDTCNT
	.globl _PDTEN
	.globl _SCON_1
	.globl _EIPH
	.globl _AINDIDS
	.globl _SPDR
	.globl _SPSR
	.globl _SPCR2
	.globl _SPCR
	.globl _CAPCON4
	.globl _CAPCON3
	.globl _B
	.globl _EIP
	.globl _C2H
	.globl _C2L
	.globl _PIF
	.globl _PIPEN
	.globl _PINEN
	.globl _PICON
	.globl _ADCCON0
	.globl _C1H
	.globl _C1L
	.globl _C0H
	.globl _C0L
	.globl _ADCDLY
	.globl _ADCCON2
	.globl _ADCCON1
	.globl _ACC
	.globl _PWMCON1
	.globl _PIOCON0
	.globl _PWM3L
	.globl _PWM2L
	.globl _PWM1L
	.globl _PWM0L
	.globl _PWMPL
	.globl _PWMCON0
	.globl _FBD
	.globl _PNP
	.globl _PWM3H
	.globl _PWM2H
	.globl _PWM1H
	.globl _PWM0H
	.globl _PWMPH
	.globl _PSW
	.globl _ADCMPH
	.globl _ADCMPL
	.globl _PWM5L
	.globl _TH2
	.globl _PWM4L
	.globl _TL2
	.globl _RCMP2H
	.globl _RCMP2L
	.globl _T2MOD
	.globl _T2CON
	.globl _TA
	.globl _PIOCON1
	.globl _RH3
	.globl _PWM5H
	.globl _RL3
	.globl _PWM4H
	.globl _T3CON
	.globl _ADCRH
	.globl _ADCRL
	.globl _I2ADDR
	.globl _I2CON
	.globl _I2TOC
	.globl _I2CLK
	.globl _I2STAT
	.globl _I2DAT
	.globl _SADDR_1
	.globl _SADEN_1
	.globl _SADEN
	.globl _IP
	.globl _PWMINTC
	.globl _IPH
	.globl _P2S
	.globl _P1SR
	.globl _P1M2
	.globl _P1S
	.globl _P1M1
	.globl _P0SR
	.globl _P0M2
	.globl _P0S
	.globl _P0M1
	.globl _P3
	.globl _IAPCN
	.globl _IAPFD
	.globl _P3SR
	.globl _P3M2
	.globl _P3S
	.globl _P3M1
	.globl _BODCON1
	.globl _WDCON
	.globl _SADDR
	.globl _IE
	.globl _IAPAH
	.globl _IAPAL
	.globl _IAPUEN
	.globl _IAPTRG
	.globl _BODCON0
	.globl _AUXR1
	.globl _P2
	.globl _CHPCON
	.globl _EIE1
	.globl _EIE
	.globl _SBUF_1
	.globl _SBUF
	.globl _SCON
	.globl _CKEN
	.globl _CKSWT
	.globl _CKDIV
	.globl _CAPCON2
	.globl _CAPCON1
	.globl _CAPCON0
	.globl _SFRS
	.globl _P1
	.globl _WKCON
	.globl _CKCON
	.globl _TH1
	.globl _TH0
	.globl _TL1
	.globl _TL0
	.globl _TMOD
	.globl _TCON
	.globl _PCON
	.globl _RWK
	.globl _RCTRIM1
	.globl _RCTRIM0
	.globl _DPH
	.globl _DPL
	.globl _SP
	.globl _P0
	.globl _ADC_Init_PARM_2
	.globl _ADC_ConvertTime
	.globl _ADC_StartConv
	.globl _ADC_IsBusy
	.globl _ADC_GetData
	.globl _ADC_ClearFlag
	.globl _ADC_Disable
	.globl _ADC_ComapreMode
	.globl _ADC_Init
	.globl _ADC_SelectChannel
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
_P0	=	0x0080
_SP	=	0x0081
_DPL	=	0x0082
_DPH	=	0x0083
_RCTRIM0	=	0x0084
_RCTRIM1	=	0x0085
_RWK	=	0x0086
_PCON	=	0x0087
_TCON	=	0x0088
_TMOD	=	0x0089
_TL0	=	0x008a
_TL1	=	0x008b
_TH0	=	0x008c
_TH1	=	0x008d
_CKCON	=	0x008e
_WKCON	=	0x008f
_P1	=	0x0090
_SFRS	=	0x0091
_CAPCON0	=	0x0092
_CAPCON1	=	0x0093
_CAPCON2	=	0x0094
_CKDIV	=	0x0095
_CKSWT	=	0x0096
_CKEN	=	0x0097
_SCON	=	0x0098
_SBUF	=	0x0099
_SBUF_1	=	0x009a
_EIE	=	0x009b
_EIE1	=	0x009c
_CHPCON	=	0x009f
_P2	=	0x00a0
_AUXR1	=	0x00a2
_BODCON0	=	0x00a3
_IAPTRG	=	0x00a4
_IAPUEN	=	0x00a5
_IAPAL	=	0x00a6
_IAPAH	=	0x00a7
_IE	=	0x00a8
_SADDR	=	0x00a9
_WDCON	=	0x00aa
_BODCON1	=	0x00ab
_P3M1	=	0x00ac
_P3S	=	0x00ac
_P3M2	=	0x00ad
_P3SR	=	0x00ad
_IAPFD	=	0x00ae
_IAPCN	=	0x00af
_P3	=	0x00b0
_P0M1	=	0x00b1
_P0S	=	0x00b1
_P0M2	=	0x00b2
_P0SR	=	0x00b2
_P1M1	=	0x00b3
_P1S	=	0x00b3
_P1M2	=	0x00b4
_P1SR	=	0x00b4
_P2S	=	0x00b5
_IPH	=	0x00b7
_PWMINTC	=	0x00b7
_IP	=	0x00b8
_SADEN	=	0x00b9
_SADEN_1	=	0x00ba
_SADDR_1	=	0x00bb
_I2DAT	=	0x00bc
_I2STAT	=	0x00bd
_I2CLK	=	0x00be
_I2TOC	=	0x00bf
_I2CON	=	0x00c0
_I2ADDR	=	0x00c1
_ADCRL	=	0x00c2
_ADCRH	=	0x00c3
_T3CON	=	0x00c4
_PWM4H	=	0x00c4
_RL3	=	0x00c5
_PWM5H	=	0x00c5
_RH3	=	0x00c6
_PIOCON1	=	0x00c6
_TA	=	0x00c7
_T2CON	=	0x00c8
_T2MOD	=	0x00c9
_RCMP2L	=	0x00ca
_RCMP2H	=	0x00cb
_TL2	=	0x00cc
_PWM4L	=	0x00cc
_TH2	=	0x00cd
_PWM5L	=	0x00cd
_ADCMPL	=	0x00ce
_ADCMPH	=	0x00cf
_PSW	=	0x00d0
_PWMPH	=	0x00d1
_PWM0H	=	0x00d2
_PWM1H	=	0x00d3
_PWM2H	=	0x00d4
_PWM3H	=	0x00d5
_PNP	=	0x00d6
_FBD	=	0x00d7
_PWMCON0	=	0x00d8
_PWMPL	=	0x00d9
_PWM0L	=	0x00da
_PWM1L	=	0x00db
_PWM2L	=	0x00dc
_PWM3L	=	0x00dd
_PIOCON0	=	0x00de
_PWMCON1	=	0x00df
_ACC	=	0x00e0
_ADCCON1	=	0x00e1
_ADCCON2	=	0x00e2
_ADCDLY	=	0x00e3
_C0L	=	0x00e4
_C0H	=	0x00e5
_C1L	=	0x00e6
_C1H	=	0x00e7
_ADCCON0	=	0x00e8
_PICON	=	0x00e9
_PINEN	=	0x00ea
_PIPEN	=	0x00eb
_PIF	=	0x00ec
_C2L	=	0x00ed
_C2H	=	0x00ee
_EIP	=	0x00ef
_B	=	0x00f0
_CAPCON3	=	0x00f1
_CAPCON4	=	0x00f2
_SPCR	=	0x00f3
_SPCR2	=	0x00f3
_SPSR	=	0x00f4
_SPDR	=	0x00f5
_AINDIDS	=	0x00f6
_EIPH	=	0x00f7
_SCON_1	=	0x00f8
_PDTEN	=	0x00f9
_PDTCNT	=	0x00fa
_PMEN	=	0x00fb
_PMD	=	0x00fc
_PORDIS	=	0x00fd
_EIP1	=	0x00fe
_EIPH1	=	0x00ff
;--------------------------------------------------------
; special function bits
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
_SM0_1	=	0x00ff
_FE_1	=	0x00ff
_SM1_1	=	0x00fe
_SM2_1	=	0x00fd
_REN_1	=	0x00fc
_TB8_1	=	0x00fb
_RB8_1	=	0x00fa
_TI_1	=	0x00f9
_RI_1	=	0x00f8
_ADCF	=	0x00ef
_ADCS	=	0x00ee
_ETGSEL1	=	0x00ed
_ETGSEL0	=	0x00ec
_ADCHS3	=	0x00eb
_ADCHS2	=	0x00ea
_ADCHS1	=	0x00e9
_ADCHS0	=	0x00e8
_PWMRUN	=	0x00df
_LOAD	=	0x00de
_PWMF	=	0x00dd
_CLRPWM	=	0x00dc
_CY	=	0x00d7
_AC	=	0x00d6
_F0	=	0x00d5
_RS1	=	0x00d4
_RS0	=	0x00d3
_OV	=	0x00d2
_P	=	0x00d0
_TF2	=	0x00cf
_TR2	=	0x00ca
_CM_RL2	=	0x00c8
_I2CEN	=	0x00c6
_STA	=	0x00c5
_STO	=	0x00c4
_SI	=	0x00c3
_AA	=	0x00c2
_I2CPX	=	0x00c0
_PADC	=	0x00be
_PBOD	=	0x00bd
_PS	=	0x00bc
_PT1	=	0x00bb
_PX1	=	0x00ba
_PT0	=	0x00b9
_PX0	=	0x00b8
_P30	=	0x00b0
_EA	=	0x00af
_EADC	=	0x00ae
_EBOD	=	0x00ad
_ES	=	0x00ac
_ET1	=	0x00ab
_EX1	=	0x00aa
_ET0	=	0x00a9
_EX0	=	0x00a8
_P20	=	0x00a0
_SM0	=	0x009f
_FE	=	0x009f
_SM1	=	0x009e
_SM2	=	0x009d
_REN	=	0x009c
_TB8	=	0x009b
_RB8	=	0x009a
_TI	=	0x0099
_RI	=	0x0098
_P17	=	0x0097
_P16	=	0x0096
_TXD_1	=	0x0096
_P15	=	0x0095
_P14	=	0x0094
_SDA	=	0x0094
_P13	=	0x0093
_SCL	=	0x0093
_P12	=	0x0092
_P11	=	0x0091
_P10	=	0x0090
_TF1	=	0x008f
_TR1	=	0x008e
_TF0	=	0x008d
_TR0	=	0x008c
_IE1	=	0x008b
_IT1	=	0x008a
_IE0	=	0x0089
_IT0	=	0x0088
_P07	=	0x0087
_RXD	=	0x0087
_P06	=	0x0086
_TXD	=	0x0086
_P05	=	0x0085
_P04	=	0x0084
_STADC	=	0x0084
_P03	=	0x0083
_P02	=	0x0082
_RXD_1	=	0x0082
_P01	=	0x0081
_MISO	=	0x0081
_P00	=	0x0080
_MOSI	=	0x0080
;--------------------------------------------------------
; overlayable register banks
;--------------------------------------------------------
	.area REG_BANK_0	(REL,OVR,DATA)
	.ds 8
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	.area DSEG    (DATA)
_ADC_GetData_initialized_10000_108:
	.ds 1
_ADC_Init_PARM_2:
	.ds 1
;--------------------------------------------------------
; overlayable items in internal ram
;--------------------------------------------------------
	.area	OSEG    (OVR,DATA)
_ADC_ConvertTime_PARM_2:
	.ds 1
	.area	OSEG    (OVR,DATA)
	.area	OSEG    (OVR,DATA)
_ADC_ComapreMode_PARM_2:
	.ds 2
	.area	OSEG    (OVR,DATA)
;--------------------------------------------------------
; indirectly addressable internal ram data
;--------------------------------------------------------
	.area ISEG    (DATA)
_ADC_GetData_raw_10000_108:
	.ds 12
_ADC_GetData_filtered_10000_108:
	.ds 12
;--------------------------------------------------------
; absolute internal ram data
;--------------------------------------------------------
	.area IABS    (ABS,DATA)
	.area IABS    (ABS,DATA)
;--------------------------------------------------------
; bit data
;--------------------------------------------------------
	.area BSEG    (BIT)
_ADC_IsBusy_sloc0_1_0:
	.ds 1
;--------------------------------------------------------
; paged external ram data
;--------------------------------------------------------
	.area PSEG    (PAG,XDATA)
;--------------------------------------------------------
; uninitialized external ram data
;--------------------------------------------------------
	.area XSEG    (XDATA)
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area XABS    (ABS,XDATA)
;--------------------------------------------------------
; initialized external ram data
;--------------------------------------------------------
	.area XISEG   (XDATA)
	.area HOME    (CODE)
	.area GSINIT0 (CODE)
	.area GSINIT1 (CODE)
	.area GSINIT2 (CODE)
	.area GSINIT3 (CODE)
	.area GSINIT4 (CODE)
	.area GSINIT5 (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area CSEG    (CODE)
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME    (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area GSINIT  (CODE)
;------------------------------------------------------------
;Allocation info for local variables in function 'ADC_GetData'
;------------------------------------------------------------
;initialized               Allocated with name '_ADC_GetData_initialized_10000_108'
;raw                       Allocated with name '_ADC_GetData_raw_10000_108'
;filtered                  Allocated with name '_ADC_GetData_filtered_10000_108'
;channel                   Allocated to registers r7 
;------------------------------------------------------------
;	lib\N76E003\adc.c:45: __idata static uint16_t filtered[6] = {0};
	mov	r0,#_ADC_GetData_filtered_10000_108
	mov	@r0,#0x00
	inc	r0
	mov	@r0,#0x00
	mov	r0,#(_ADC_GetData_filtered_10000_108 + 0x0002)
	mov	@r0,#0x00
	inc	r0
	mov	@r0,#0x00
	mov	r0,#(_ADC_GetData_filtered_10000_108 + 0x0004)
	mov	@r0,#0x00
	inc	r0
	mov	@r0,#0x00
	mov	r0,#(_ADC_GetData_filtered_10000_108 + 0x0006)
	mov	@r0,#0x00
	inc	r0
	mov	@r0,#0x00
	mov	r0,#(_ADC_GetData_filtered_10000_108 + 0x0008)
	mov	@r0,#0x00
	inc	r0
	mov	@r0,#0x00
	mov	r0,#(_ADC_GetData_filtered_10000_108 + 0x000a)
	mov	@r0,#0x00
	inc	r0
	mov	@r0,#0x00
;	lib\N76E003\adc.c:46: static uint8_t initialized = 0;
	mov	_ADC_GetData_initialized_10000_108,#0x00
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME    (CODE)
	.area HOME    (CODE)
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG    (CODE)
;------------------------------------------------------------
;Allocation info for local variables in function 'ADC_ConvertTime'
;------------------------------------------------------------
;u8ADCAQT                  Allocated with name '_ADC_ConvertTime_PARM_2'
;u8ADCDIV                  Allocated to registers r7 
;------------------------------------------------------------
;	lib\N76E003\adc.c:13: void ADC_ConvertTime(uint8_t u8ADCDIV, uint8_t u8ADCAQT)
;	-----------------------------------------
;	 function ADC_ConvertTime
;	-----------------------------------------
_ADC_ConvertTime:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
	mov	r7, dpl
;	lib\N76E003\adc.c:15: clr_ADCF;
;	assignBit
	clr	_ADCF
;	lib\N76E003\adc.c:16: set_ADCS;
;	assignBit
	setb	_ADCS
;	lib\N76E003\adc.c:18: SFRS = 0;
	mov	_SFRS,#0x00
;	lib\N76E003\adc.c:19: ADCCON1 &= 0x8F;
	anl	_ADCCON1,#0x8f
;	lib\N76E003\adc.c:20: ADCCON1 |= (u8ADCDIV & 0x07) << 4;
	anl	ar7,#0x07
	mov	a,r7
	swap	a
	anl	a,#0xf0
	orl	_ADCCON1,a
;	lib\N76E003\adc.c:21: ADCCON2 &= 0xF1;
	anl	_ADCCON2,#0xf1
;	lib\N76E003\adc.c:22: ADCCON2 |= (u8ADCAQT & 0x07) << 1;
	mov	a,_ADC_ConvertTime_PARM_2
	anl	a,#0x07
	add	a,acc
	orl	_ADCCON2,a
;	lib\N76E003\adc.c:23: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'ADC_StartConv'
;------------------------------------------------------------
;	lib\N76E003\adc.c:25: void ADC_StartConv(void)
;	-----------------------------------------
;	 function ADC_StartConv
;	-----------------------------------------
_ADC_StartConv:
;	lib\N76E003\adc.c:27: ADCS = 1;
;	assignBit
	setb	_ADCS
;	lib\N76E003\adc.c:28: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'ADC_IsBusy'
;------------------------------------------------------------
;	lib\N76E003\adc.c:30: uint8_t ADC_IsBusy(void)
;	-----------------------------------------
;	 function ADC_IsBusy
;	-----------------------------------------
_ADC_IsBusy:
;	lib\N76E003\adc.c:32: return !ADCF;
	mov	c,_ADCF
	cpl	c
	mov  _ADC_IsBusy_sloc0_1_0,c
	clr	a
	rlc	a
	mov	dpl,a
;	lib\N76E003\adc.c:33: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'ADC_GetData'
;------------------------------------------------------------
;initialized               Allocated with name '_ADC_GetData_initialized_10000_108'
;raw                       Allocated with name '_ADC_GetData_raw_10000_108'
;filtered                  Allocated with name '_ADC_GetData_filtered_10000_108'
;channel                   Allocated to registers r7 
;------------------------------------------------------------
;	lib\N76E003\adc.c:42: uint16_t ADC_GetData(uint8_t channel)
;	-----------------------------------------
;	 function ADC_GetData
;	-----------------------------------------
_ADC_GetData:
;	lib\N76E003\adc.c:48: raw[channel] = ((uint16_t)ADCRH << 4) | (ADCRL & 0x0F);
	mov	a,dpl
	mov	r7,a
	add	a,acc
	mov	r6,a
	add	a, #_ADC_GetData_raw_10000_108
	mov	r1,a
	mov	r4,_ADCRH
	clr	a
	swap	a
	anl	a,#0xf0
	xch	a,r4
	swap	a
	xch	a,r4
	xrl	a,r4
	xch	a,r4
	anl	a,#0xf0
	xch	a,r4
	xrl	a,r4
	mov	r5,a
	mov	r2,_ADCRL
	anl	ar2,#0x0f
	mov	r3,#0x00
	mov	a,r4
	orl	ar2,a
	mov	a,r5
	orl	ar3,a
	mov	@r1,ar2
	inc	r1
	mov	@r1,ar3
	dec	r1
;	lib\N76E003\adc.c:50: if (!(initialized & (1 << channel)))
	mov	b,r7
	inc	b
	mov	r4,#0x01
	mov	r5,#0x00
	sjmp	00113$
00112$:
	mov	a,r4
	add	a,r4
	mov	r4,a
	mov	a,r5
	rlc	a
	mov	r5,a
00113$:
	djnz	b,00112$
	mov	r2,_ADC_GetData_initialized_10000_108
	mov	r3,#0x00
	mov	a,r2
	anl	ar4,a
	mov	a,r3
	anl	ar5,a
	mov	a,r4
	orl	a,r5
	jnz	00102$
;	lib\N76E003\adc.c:52: filtered[channel] = raw[channel];
	mov	a,r6
	add	a, #_ADC_GetData_filtered_10000_108
	mov	r0,a
	mov	ar4,@r1
	inc	r1
	mov	ar5,@r1
	dec	r1
	mov	@r0,ar4
	inc	r0
	mov	@r0,ar5
;	lib\N76E003\adc.c:53: initialized |= (1 << channel); // Đánh dấu đã khởi tạo
	mov	b,r7
	inc	b
	mov	a,#0x01
	sjmp	00116$
00115$:
	add	a,acc
00116$:
	djnz	b,00115$
	orl	_ADC_GetData_initialized_10000_108,a
	sjmp	00103$
00102$:
;	lib\N76E003\adc.c:57: filtered[channel] = ((filtered[channel] << 3) - filtered[channel] + raw[channel]) >> 3;
	mov	a,r6
	add	a, #_ADC_GetData_filtered_10000_108
	mov	r0,a
	mov	ar5,@r0
	inc	r0
	mov	ar7,@r0
	dec	r0
	mov	ar3,r5
	mov	a,r7
	swap	a
	rr	a
	anl	a,#0xf8
	xch	a,r3
	swap	a
	rr	a
	xch	a,r3
	xrl	a,r3
	xch	a,r3
	anl	a,#0xf8
	xch	a,r3
	xrl	a,r3
	mov	r4,a
	mov	a,r3
	clr	c
	subb	a,r5
	mov	r5,a
	mov	a,r4
	subb	a,r7
	mov	r7,a
	mov	ar3,@r1
	inc	r1
	mov	ar4,@r1
	mov	a,r3
	add	a, r5
	mov	r5,a
	mov	a,r4
	addc	a, r7
	swap	a
	rl	a
	xch	a,r5
	swap	a
	rl	a
	anl	a,#0x1f
	xrl	a,r5
	xch	a,r5
	anl	a,#0x1f
	xch	a,r5
	xrl	a,r5
	xch	a,r5
	mov	r7,a
	mov	@r0,ar5
	inc	r0
	mov	@r0,ar7
00103$:
;	lib\N76E003\adc.c:60: return filtered[channel];
	mov	a,r6
	add	a, #_ADC_GetData_filtered_10000_108
	mov	r1,a
	mov	dpl,@r1
	inc	r1
	mov	dph,@r1
;	lib\N76E003\adc.c:61: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'ADC_ClearFlag'
;------------------------------------------------------------
;	lib\N76E003\adc.c:63: void ADC_ClearFlag(void)
;	-----------------------------------------
;	 function ADC_ClearFlag
;	-----------------------------------------
_ADC_ClearFlag:
;	lib\N76E003\adc.c:65: ADCF = 0;
;	assignBit
	clr	_ADCF
;	lib\N76E003\adc.c:66: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'ADC_Disable'
;------------------------------------------------------------
;	lib\N76E003\adc.c:68: void ADC_Disable(void)
;	-----------------------------------------
;	 function ADC_Disable
;	-----------------------------------------
_ADC_Disable:
;	lib\N76E003\adc.c:70: ADCCON1 &= 0xFE;
	anl	_ADCCON1,#0xfe
;	lib\N76E003\adc.c:71: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'ADC_ComapreMode'
;------------------------------------------------------------
;u16ADCCMPVALUE            Allocated with name '_ADC_ComapreMode_PARM_2'
;u8ADCCMPEN                Allocated to registers r7 
;------------------------------------------------------------
;	lib\N76E003\adc.c:73: void ADC_ComapreMode(uint8_t u8ADCCMPEN, uint16_t u16ADCCMPVALUE)
;	-----------------------------------------
;	 function ADC_ComapreMode
;	-----------------------------------------
_ADC_ComapreMode:
	mov	r7, dpl
;	lib\N76E003\adc.c:75: SFRS = 0;
	mov	_SFRS,#0x00
;	lib\N76E003\adc.c:76: ADCMPL = u16ADCCMPVALUE & 0x000F;
	mov	r6,_ADC_ComapreMode_PARM_2
	mov	a,#0x0f
	anl	a,r6
	mov	_ADCMPL,a
;	lib\N76E003\adc.c:77: ADCMPH = u16ADCCMPVALUE >> 4;
	mov	r5,_ADC_ComapreMode_PARM_2
	mov	a,(_ADC_ComapreMode_PARM_2 + 1)
	swap	a
	xch	a,r5
	swap	a
	anl	a,#0x0f
	xrl	a,r5
	xch	a,r5
	anl	a,#0x0f
	xch	a,r5
	xrl	a,r5
	xch	a,r5
	mov	_ADCMPH,r5
;	lib\N76E003\adc.c:78: if (u8ADCCMPEN)
	mov	a,r7
	jz	00102$
;	lib\N76E003\adc.c:80: set_ADCMPEN;
	orl	_ADCCON2,#0x20
	ret
00102$:
;	lib\N76E003\adc.c:84: clr_ADCMPEN;
	anl	_ADCCON2,#0xdf
;	lib\N76E003\adc.c:86: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'ADC_Init'
;------------------------------------------------------------
;div                       Allocated with name '_ADC_Init_PARM_2'
;channel                   Allocated to registers r7 
;------------------------------------------------------------
;	lib\N76E003\adc.c:88: void ADC_Init(uint8_t channel, uint8_t div)
;	-----------------------------------------
;	 function ADC_Init
;	-----------------------------------------
_ADC_Init:
;	lib\N76E003\adc.c:90: switch (channel)
	mov	a,dpl
	mov	r7,a
	add	a,#0xff - 0x08
	jnc	00170$
	ret
00170$:
	mov	a,r7
	add	a,#(00171$-3-.)
	movc	a,@a+pc
	mov	dpl,a
	mov	a,r7
	add	a,#(00172$-3-.)
	movc	a,@a+pc
	mov	dph,a
	clr	a
	jmp	@a+dptr
00171$:
	.db	00105$
	.db	00112$
	.db	00119$
	.db	00126$
	.db	00133$
	.db	00140$
	.db	00147$
	.db	00154$
	.db	00158$
00172$:
	.db	00105$>>8
	.db	00112$>>8
	.db	00119$>>8
	.db	00126$>>8
	.db	00133$>>8
	.db	00140$>>8
	.db	00147$>>8
	.db	00154$>>8
	.db	00158$>>8
;	lib\N76E003\adc.c:93: Enable_ADC_AIN0;
00105$:
	anl	_ADCCON0,#0xf0
	orl	_P1M1,#0x80
	anl	_P1M2,#0x7f
	mov	_AINDIDS,#0x00
	orl	_AINDIDS,#0x01
	orl	_ADCCON1,#0x01
;	lib\N76E003\adc.c:94: ADC_ConvertTime(div, ADC_ADCAQT0);
	mov	_ADC_ConvertTime_PARM_2,#0x00
	mov	dpl, _ADC_Init_PARM_2
	lcall	_ADC_ConvertTime
;	lib\N76E003\adc.c:95: clr_ADCF;
;	assignBit
	clr	_ADCF
;	lib\N76E003\adc.c:96: set_ADCS;
;	assignBit
	setb	_ADCS
;	lib\N76E003\adc.c:97: break;
	ret
;	lib\N76E003\adc.c:99: Enable_ADC_AIN1;
00112$:
	anl	_ADCCON0,#0xf0
	orl	_ADCCON0,#0x01
	orl	_P3M1,#0x01
	anl	_P3M2,#0xfe
	mov	_AINDIDS,#0x00
	orl	_AINDIDS,#0x02
	orl	_ADCCON1,#0x01
;	lib\N76E003\adc.c:100: ADC_ConvertTime(div, ADC_ADCAQT1);
	mov	_ADC_ConvertTime_PARM_2,#0x01
	mov	dpl, _ADC_Init_PARM_2
	lcall	_ADC_ConvertTime
;	lib\N76E003\adc.c:101: clr_ADCF;
;	assignBit
	clr	_ADCF
;	lib\N76E003\adc.c:102: set_ADCS;
;	assignBit
	setb	_ADCS
;	lib\N76E003\adc.c:103: break;
	ret
;	lib\N76E003\adc.c:105: Enable_ADC_AIN2;
00119$:
	anl	_ADCCON0,#0xf0
	orl	_ADCCON0,#0x02
	orl	_P0M1,#0x80
	anl	_P0M2,#0x7f
	mov	_AINDIDS,#0x00
	orl	_AINDIDS,#0x04
	orl	_ADCCON1,#0x01
;	lib\N76E003\adc.c:106: ADC_ConvertTime(div, ADC_ADCAQT2);
	mov	_ADC_ConvertTime_PARM_2,#0x02
	mov	dpl, _ADC_Init_PARM_2
	lcall	_ADC_ConvertTime
;	lib\N76E003\adc.c:107: clr_ADCF;
;	assignBit
	clr	_ADCF
;	lib\N76E003\adc.c:108: set_ADCS;
;	assignBit
	setb	_ADCS
;	lib\N76E003\adc.c:109: break;
	ret
;	lib\N76E003\adc.c:111: Enable_ADC_AIN3;
00126$:
	anl	_ADCCON0,#0xf0
	orl	_ADCCON0,#0x03
	orl	_P0M1,#0x40
	anl	_P0M2,#0xbf
	mov	_AINDIDS,#0x00
	orl	_AINDIDS,#0x08
	orl	_ADCCON1,#0x01
;	lib\N76E003\adc.c:112: ADC_ConvertTime(div, ADC_ADCAQT3);
	mov	_ADC_ConvertTime_PARM_2,#0x03
	mov	dpl, _ADC_Init_PARM_2
	lcall	_ADC_ConvertTime
;	lib\N76E003\adc.c:113: clr_ADCF;
;	assignBit
	clr	_ADCF
;	lib\N76E003\adc.c:114: set_ADCS;
;	assignBit
	setb	_ADCS
;	lib\N76E003\adc.c:115: break;
	ret
;	lib\N76E003\adc.c:117: Enable_ADC_AIN4;
00133$:
	anl	_ADCCON0,#0xf0
	orl	_ADCCON0,#0x04
	orl	_P0M1,#0x20
	anl	_P0M2,#0xdf
	mov	_AINDIDS,#0x00
	orl	_AINDIDS,#0x10
	orl	_ADCCON1,#0x01
;	lib\N76E003\adc.c:118: ADC_ConvertTime(div, ADC_ADCAQT4);
	mov	_ADC_ConvertTime_PARM_2,#0x04
	mov	dpl, _ADC_Init_PARM_2
	lcall	_ADC_ConvertTime
;	lib\N76E003\adc.c:119: clr_ADCF;
;	assignBit
	clr	_ADCF
;	lib\N76E003\adc.c:120: set_ADCS;
;	assignBit
	setb	_ADCS
;	lib\N76E003\adc.c:121: break;
	ret
;	lib\N76E003\adc.c:123: Enable_ADC_AIN5;
00140$:
	anl	_ADCCON0,#0xf0
	orl	_ADCCON0,#0x05
	orl	_P0M1,#0x10
	anl	_P0M2,#0xef
	mov	_AINDIDS,#0x00
	orl	_AINDIDS,#0x20
	orl	_ADCCON1,#0x01
;	lib\N76E003\adc.c:124: ADC_ConvertTime(div, ADC_ADCAQT5);
	mov	_ADC_ConvertTime_PARM_2,#0x05
	mov	dpl, _ADC_Init_PARM_2
	lcall	_ADC_ConvertTime
;	lib\N76E003\adc.c:125: clr_ADCF;
;	assignBit
	clr	_ADCF
;	lib\N76E003\adc.c:126: set_ADCS;
;	assignBit
	setb	_ADCS
;	lib\N76E003\adc.c:127: break;
;	lib\N76E003\adc.c:129: Enable_ADC_AIN6;
	ret
00147$:
	anl	_ADCCON0,#0xf0
	orl	_ADCCON0,#0x06
	orl	_P0M1,#0x08
	anl	_P0M2,#0xf7
	mov	_AINDIDS,#0x00
	orl	_AINDIDS,#0x40
	orl	_ADCCON1,#0x01
;	lib\N76E003\adc.c:130: ADC_ConvertTime(div, ADC_ADCAQT6);
	mov	_ADC_ConvertTime_PARM_2,#0x06
	mov	dpl, _ADC_Init_PARM_2
	lcall	_ADC_ConvertTime
;	lib\N76E003\adc.c:131: clr_ADCF;
;	assignBit
	clr	_ADCF
;	lib\N76E003\adc.c:132: set_ADCS;
;	assignBit
	setb	_ADCS
;	lib\N76E003\adc.c:133: break;
;	lib\N76E003\adc.c:135: Enable_ADC_AIN7;
	ret
00154$:
	anl	_ADCCON0,#0xf0
	orl	_ADCCON0,#0x07
	orl	_P1M1,#0x02
	anl	_P1M2,#0xfd
	mov	_AINDIDS,#0x00
	orl	_AINDIDS,#0x80
	orl	_ADCCON1,#0x01
;	lib\N76E003\adc.c:136: ADC_ConvertTime(div, ADC_ADCAQT7);
	mov	_ADC_ConvertTime_PARM_2,#0x07
	mov	dpl, _ADC_Init_PARM_2
	lcall	_ADC_ConvertTime
;	lib\N76E003\adc.c:137: clr_ADCF;
;	assignBit
	clr	_ADCF
;	lib\N76E003\adc.c:138: set_ADCS;
;	assignBit
	setb	_ADCS
;	lib\N76E003\adc.c:139: break;
;	lib\N76E003\adc.c:141: Enable_ADC_BandGap;
	ret
00158$:
	anl	_ADCCON1,#0xfe
	anl	_ADCCON0,#0xf0
	orl	_ADCCON0,#0x08
	anl	_ADCCON0,#0xf8
	orl	_ADCCON1,#0x01
;	lib\N76E003\adc.c:142: clr_ADCF;
;	assignBit
	clr	_ADCF
;	lib\N76E003\adc.c:143: set_ADCS;
;	assignBit
	setb	_ADCS
;	lib\N76E003\adc.c:145: }
;	lib\N76E003\adc.c:146: }
	ret
;------------------------------------------------------------
;Allocation info for local variables in function 'ADC_SelectChannel'
;------------------------------------------------------------
;channel                   Allocated to registers r7 
;------------------------------------------------------------
;	lib\N76E003\adc.c:148: void ADC_SelectChannel(uint8_t channel)
;	-----------------------------------------
;	 function ADC_SelectChannel
;	-----------------------------------------
_ADC_SelectChannel:
;	lib\N76E003\adc.c:150: switch (channel)
	mov	a,dpl
	mov	r7,a
	add	a,#0xff - 0x08
	jnc	00170$
	ret
00170$:
	mov	a,r7
	add	a,#(00171$-3-.)
	movc	a,@a+pc
	mov	dpl,a
	mov	a,r7
	add	a,#(00172$-3-.)
	movc	a,@a+pc
	mov	dph,a
	clr	a
	jmp	@a+dptr
00171$:
	.db	00105$
	.db	00112$
	.db	00119$
	.db	00126$
	.db	00133$
	.db	00140$
	.db	00147$
	.db	00154$
	.db	00158$
00172$:
	.db	00105$>>8
	.db	00112$>>8
	.db	00119$>>8
	.db	00126$>>8
	.db	00133$>>8
	.db	00140$>>8
	.db	00147$>>8
	.db	00154$>>8
	.db	00158$>>8
;	lib\N76E003\adc.c:153: Enable_ADC_AIN0;
00105$:
	anl	_ADCCON0,#0xf0
	orl	_P1M1,#0x80
	anl	_P1M2,#0x7f
	mov	_AINDIDS,#0x00
	orl	_AINDIDS,#0x01
	orl	_ADCCON1,#0x01
;	lib\N76E003\adc.c:154: break;
	ret
;	lib\N76E003\adc.c:156: Enable_ADC_AIN1;
00112$:
	anl	_ADCCON0,#0xf0
	orl	_ADCCON0,#0x01
	orl	_P3M1,#0x01
	anl	_P3M2,#0xfe
	mov	_AINDIDS,#0x00
	orl	_AINDIDS,#0x02
	orl	_ADCCON1,#0x01
;	lib\N76E003\adc.c:157: break;
	ret
;	lib\N76E003\adc.c:159: Enable_ADC_AIN2;
00119$:
	anl	_ADCCON0,#0xf0
	orl	_ADCCON0,#0x02
	orl	_P0M1,#0x80
	anl	_P0M2,#0x7f
	mov	_AINDIDS,#0x00
	orl	_AINDIDS,#0x04
	orl	_ADCCON1,#0x01
;	lib\N76E003\adc.c:160: break;
	ret
;	lib\N76E003\adc.c:162: Enable_ADC_AIN3;
00126$:
	anl	_ADCCON0,#0xf0
	orl	_ADCCON0,#0x03
	orl	_P0M1,#0x40
	anl	_P0M2,#0xbf
	mov	_AINDIDS,#0x00
	orl	_AINDIDS,#0x08
	orl	_ADCCON1,#0x01
;	lib\N76E003\adc.c:163: break;
;	lib\N76E003\adc.c:165: Enable_ADC_AIN4;
	ret
00133$:
	anl	_ADCCON0,#0xf0
	orl	_ADCCON0,#0x04
	orl	_P0M1,#0x20
	anl	_P0M2,#0xdf
	mov	_AINDIDS,#0x00
	orl	_AINDIDS,#0x10
	orl	_ADCCON1,#0x01
;	lib\N76E003\adc.c:166: break;
;	lib\N76E003\adc.c:168: Enable_ADC_AIN5;
	ret
00140$:
	anl	_ADCCON0,#0xf0
	orl	_ADCCON0,#0x05
	orl	_P0M1,#0x10
	anl	_P0M2,#0xef
	mov	_AINDIDS,#0x00
	orl	_AINDIDS,#0x20
	orl	_ADCCON1,#0x01
;	lib\N76E003\adc.c:169: break;
;	lib\N76E003\adc.c:171: Enable_ADC_AIN6;
	ret
00147$:
	anl	_ADCCON0,#0xf0
	orl	_ADCCON0,#0x06
	orl	_P0M1,#0x08
	anl	_P0M2,#0xf7
	mov	_AINDIDS,#0x00
	orl	_AINDIDS,#0x40
	orl	_ADCCON1,#0x01
;	lib\N76E003\adc.c:172: break;
;	lib\N76E003\adc.c:174: Enable_ADC_AIN7;
	ret
00154$:
	anl	_ADCCON0,#0xf0
	orl	_ADCCON0,#0x07
	orl	_P1M1,#0x02
	anl	_P1M2,#0xfd
	mov	_AINDIDS,#0x00
	orl	_AINDIDS,#0x80
	orl	_ADCCON1,#0x01
;	lib\N76E003\adc.c:175: break;
;	lib\N76E003\adc.c:177: Enable_ADC_BandGap;
	ret
00158$:
	anl	_ADCCON1,#0xfe
	anl	_ADCCON0,#0xf0
	orl	_ADCCON0,#0x08
	anl	_ADCCON0,#0xf8
	orl	_ADCCON1,#0x01
;	lib\N76E003\adc.c:179: }
;	lib\N76E003\adc.c:180: }
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
