                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ISO C Compiler 
                                      3 ; Version 4.4.0 #14620 (MINGW32)
                                      4 ;--------------------------------------------------------
                                      5 	.module Delay
                                      6 	.optsdcc -mmcs51 --model-small
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _MOSI
                                     12 	.globl _P00
                                     13 	.globl _MISO
                                     14 	.globl _P01
                                     15 	.globl _RXD_1
                                     16 	.globl _P02
                                     17 	.globl _P03
                                     18 	.globl _STADC
                                     19 	.globl _P04
                                     20 	.globl _P05
                                     21 	.globl _TXD
                                     22 	.globl _P06
                                     23 	.globl _RXD
                                     24 	.globl _P07
                                     25 	.globl _IT0
                                     26 	.globl _IE0
                                     27 	.globl _IT1
                                     28 	.globl _IE1
                                     29 	.globl _TR0
                                     30 	.globl _TF0
                                     31 	.globl _TR1
                                     32 	.globl _TF1
                                     33 	.globl _P10
                                     34 	.globl _P11
                                     35 	.globl _P12
                                     36 	.globl _SCL
                                     37 	.globl _P13
                                     38 	.globl _SDA
                                     39 	.globl _P14
                                     40 	.globl _P15
                                     41 	.globl _TXD_1
                                     42 	.globl _P16
                                     43 	.globl _P17
                                     44 	.globl _RI
                                     45 	.globl _TI
                                     46 	.globl _RB8
                                     47 	.globl _TB8
                                     48 	.globl _REN
                                     49 	.globl _SM2
                                     50 	.globl _SM1
                                     51 	.globl _FE
                                     52 	.globl _SM0
                                     53 	.globl _P20
                                     54 	.globl _EX0
                                     55 	.globl _ET0
                                     56 	.globl _EX1
                                     57 	.globl _ET1
                                     58 	.globl _ES
                                     59 	.globl _EBOD
                                     60 	.globl _EADC
                                     61 	.globl _EA
                                     62 	.globl _P30
                                     63 	.globl _PX0
                                     64 	.globl _PT0
                                     65 	.globl _PX1
                                     66 	.globl _PT1
                                     67 	.globl _PS
                                     68 	.globl _PBOD
                                     69 	.globl _PADC
                                     70 	.globl _I2CPX
                                     71 	.globl _AA
                                     72 	.globl _SI
                                     73 	.globl _STO
                                     74 	.globl _STA
                                     75 	.globl _I2CEN
                                     76 	.globl _CM_RL2
                                     77 	.globl _TR2
                                     78 	.globl _TF2
                                     79 	.globl _P
                                     80 	.globl _OV
                                     81 	.globl _RS0
                                     82 	.globl _RS1
                                     83 	.globl _F0
                                     84 	.globl _AC
                                     85 	.globl _CY
                                     86 	.globl _CLRPWM
                                     87 	.globl _PWMF
                                     88 	.globl _LOAD
                                     89 	.globl _PWMRUN
                                     90 	.globl _ADCHS0
                                     91 	.globl _ADCHS1
                                     92 	.globl _ADCHS2
                                     93 	.globl _ADCHS3
                                     94 	.globl _ETGSEL0
                                     95 	.globl _ETGSEL1
                                     96 	.globl _ADCS
                                     97 	.globl _ADCF
                                     98 	.globl _RI_1
                                     99 	.globl _TI_1
                                    100 	.globl _RB8_1
                                    101 	.globl _TB8_1
                                    102 	.globl _REN_1
                                    103 	.globl _SM2_1
                                    104 	.globl _SM1_1
                                    105 	.globl _FE_1
                                    106 	.globl _SM0_1
                                    107 	.globl _EIPH1
                                    108 	.globl _EIP1
                                    109 	.globl _PORDIS
                                    110 	.globl _PMD
                                    111 	.globl _PMEN
                                    112 	.globl _PDTCNT
                                    113 	.globl _PDTEN
                                    114 	.globl _SCON_1
                                    115 	.globl _EIPH
                                    116 	.globl _AINDIDS
                                    117 	.globl _SPDR
                                    118 	.globl _SPSR
                                    119 	.globl _SPCR2
                                    120 	.globl _SPCR
                                    121 	.globl _CAPCON4
                                    122 	.globl _CAPCON3
                                    123 	.globl _B
                                    124 	.globl _EIP
                                    125 	.globl _C2H
                                    126 	.globl _C2L
                                    127 	.globl _PIF
                                    128 	.globl _PIPEN
                                    129 	.globl _PINEN
                                    130 	.globl _PICON
                                    131 	.globl _ADCCON0
                                    132 	.globl _C1H
                                    133 	.globl _C1L
                                    134 	.globl _C0H
                                    135 	.globl _C0L
                                    136 	.globl _ADCDLY
                                    137 	.globl _ADCCON2
                                    138 	.globl _ADCCON1
                                    139 	.globl _ACC
                                    140 	.globl _PWMCON1
                                    141 	.globl _PIOCON0
                                    142 	.globl _PWM3L
                                    143 	.globl _PWM2L
                                    144 	.globl _PWM1L
                                    145 	.globl _PWM0L
                                    146 	.globl _PWMPL
                                    147 	.globl _PWMCON0
                                    148 	.globl _FBD
                                    149 	.globl _PNP
                                    150 	.globl _PWM3H
                                    151 	.globl _PWM2H
                                    152 	.globl _PWM1H
                                    153 	.globl _PWM0H
                                    154 	.globl _PWMPH
                                    155 	.globl _PSW
                                    156 	.globl _ADCMPH
                                    157 	.globl _ADCMPL
                                    158 	.globl _PWM5L
                                    159 	.globl _TH2
                                    160 	.globl _PWM4L
                                    161 	.globl _TL2
                                    162 	.globl _RCMP2H
                                    163 	.globl _RCMP2L
                                    164 	.globl _T2MOD
                                    165 	.globl _T2CON
                                    166 	.globl _TA
                                    167 	.globl _PIOCON1
                                    168 	.globl _RH3
                                    169 	.globl _PWM5H
                                    170 	.globl _RL3
                                    171 	.globl _PWM4H
                                    172 	.globl _T3CON
                                    173 	.globl _ADCRH
                                    174 	.globl _ADCRL
                                    175 	.globl _I2ADDR
                                    176 	.globl _I2CON
                                    177 	.globl _I2TOC
                                    178 	.globl _I2CLK
                                    179 	.globl _I2STAT
                                    180 	.globl _I2DAT
                                    181 	.globl _SADDR_1
                                    182 	.globl _SADEN_1
                                    183 	.globl _SADEN
                                    184 	.globl _IP
                                    185 	.globl _PWMINTC
                                    186 	.globl _IPH
                                    187 	.globl _P2S
                                    188 	.globl _P1SR
                                    189 	.globl _P1M2
                                    190 	.globl _P1S
                                    191 	.globl _P1M1
                                    192 	.globl _P0SR
                                    193 	.globl _P0M2
                                    194 	.globl _P0S
                                    195 	.globl _P0M1
                                    196 	.globl _P3
                                    197 	.globl _IAPCN
                                    198 	.globl _IAPFD
                                    199 	.globl _P3SR
                                    200 	.globl _P3M2
                                    201 	.globl _P3S
                                    202 	.globl _P3M1
                                    203 	.globl _BODCON1
                                    204 	.globl _WDCON
                                    205 	.globl _SADDR
                                    206 	.globl _IE
                                    207 	.globl _IAPAH
                                    208 	.globl _IAPAL
                                    209 	.globl _IAPUEN
                                    210 	.globl _IAPTRG
                                    211 	.globl _BODCON0
                                    212 	.globl _AUXR1
                                    213 	.globl _P2
                                    214 	.globl _CHPCON
                                    215 	.globl _EIE1
                                    216 	.globl _EIE
                                    217 	.globl _SBUF_1
                                    218 	.globl _SBUF
                                    219 	.globl _SCON
                                    220 	.globl _CKEN
                                    221 	.globl _CKSWT
                                    222 	.globl _CKDIV
                                    223 	.globl _CAPCON2
                                    224 	.globl _CAPCON1
                                    225 	.globl _CAPCON0
                                    226 	.globl _SFRS
                                    227 	.globl _P1
                                    228 	.globl _WKCON
                                    229 	.globl _CKCON
                                    230 	.globl _TH1
                                    231 	.globl _TH0
                                    232 	.globl _TL1
                                    233 	.globl _TL0
                                    234 	.globl _TMOD
                                    235 	.globl _TCON
                                    236 	.globl _PCON
                                    237 	.globl _RWK
                                    238 	.globl _RCTRIM1
                                    239 	.globl _RCTRIM0
                                    240 	.globl _DPH
                                    241 	.globl _DPL
                                    242 	.globl _SP
                                    243 	.globl _P0
                                    244 	.globl _Timer0_Delay100us
                                    245 	.globl _Timer0_Delay1ms
                                    246 	.globl _Timer0_Delay40ms
                                    247 	.globl _Timer1_Delay10ms
                                    248 	.globl _Timer2_Delay500us
                                    249 	.globl _Timer3_Delay10us
                                    250 	.globl _Timer3_Delay100ms
                                    251 ;--------------------------------------------------------
                                    252 ; special function registers
                                    253 ;--------------------------------------------------------
                                    254 	.area RSEG    (ABS,DATA)
      000000                        255 	.org 0x0000
                           000080   256 _P0	=	0x0080
                           000081   257 _SP	=	0x0081
                           000082   258 _DPL	=	0x0082
                           000083   259 _DPH	=	0x0083
                           000084   260 _RCTRIM0	=	0x0084
                           000085   261 _RCTRIM1	=	0x0085
                           000086   262 _RWK	=	0x0086
                           000087   263 _PCON	=	0x0087
                           000088   264 _TCON	=	0x0088
                           000089   265 _TMOD	=	0x0089
                           00008A   266 _TL0	=	0x008a
                           00008B   267 _TL1	=	0x008b
                           00008C   268 _TH0	=	0x008c
                           00008D   269 _TH1	=	0x008d
                           00008E   270 _CKCON	=	0x008e
                           00008F   271 _WKCON	=	0x008f
                           000090   272 _P1	=	0x0090
                           000091   273 _SFRS	=	0x0091
                           000092   274 _CAPCON0	=	0x0092
                           000093   275 _CAPCON1	=	0x0093
                           000094   276 _CAPCON2	=	0x0094
                           000095   277 _CKDIV	=	0x0095
                           000096   278 _CKSWT	=	0x0096
                           000097   279 _CKEN	=	0x0097
                           000098   280 _SCON	=	0x0098
                           000099   281 _SBUF	=	0x0099
                           00009A   282 _SBUF_1	=	0x009a
                           00009B   283 _EIE	=	0x009b
                           00009C   284 _EIE1	=	0x009c
                           00009F   285 _CHPCON	=	0x009f
                           0000A0   286 _P2	=	0x00a0
                           0000A2   287 _AUXR1	=	0x00a2
                           0000A3   288 _BODCON0	=	0x00a3
                           0000A4   289 _IAPTRG	=	0x00a4
                           0000A5   290 _IAPUEN	=	0x00a5
                           0000A6   291 _IAPAL	=	0x00a6
                           0000A7   292 _IAPAH	=	0x00a7
                           0000A8   293 _IE	=	0x00a8
                           0000A9   294 _SADDR	=	0x00a9
                           0000AA   295 _WDCON	=	0x00aa
                           0000AB   296 _BODCON1	=	0x00ab
                           0000AC   297 _P3M1	=	0x00ac
                           0000AC   298 _P3S	=	0x00ac
                           0000AD   299 _P3M2	=	0x00ad
                           0000AD   300 _P3SR	=	0x00ad
                           0000AE   301 _IAPFD	=	0x00ae
                           0000AF   302 _IAPCN	=	0x00af
                           0000B0   303 _P3	=	0x00b0
                           0000B1   304 _P0M1	=	0x00b1
                           0000B1   305 _P0S	=	0x00b1
                           0000B2   306 _P0M2	=	0x00b2
                           0000B2   307 _P0SR	=	0x00b2
                           0000B3   308 _P1M1	=	0x00b3
                           0000B3   309 _P1S	=	0x00b3
                           0000B4   310 _P1M2	=	0x00b4
                           0000B4   311 _P1SR	=	0x00b4
                           0000B5   312 _P2S	=	0x00b5
                           0000B7   313 _IPH	=	0x00b7
                           0000B7   314 _PWMINTC	=	0x00b7
                           0000B8   315 _IP	=	0x00b8
                           0000B9   316 _SADEN	=	0x00b9
                           0000BA   317 _SADEN_1	=	0x00ba
                           0000BB   318 _SADDR_1	=	0x00bb
                           0000BC   319 _I2DAT	=	0x00bc
                           0000BD   320 _I2STAT	=	0x00bd
                           0000BE   321 _I2CLK	=	0x00be
                           0000BF   322 _I2TOC	=	0x00bf
                           0000C0   323 _I2CON	=	0x00c0
                           0000C1   324 _I2ADDR	=	0x00c1
                           0000C2   325 _ADCRL	=	0x00c2
                           0000C3   326 _ADCRH	=	0x00c3
                           0000C4   327 _T3CON	=	0x00c4
                           0000C4   328 _PWM4H	=	0x00c4
                           0000C5   329 _RL3	=	0x00c5
                           0000C5   330 _PWM5H	=	0x00c5
                           0000C6   331 _RH3	=	0x00c6
                           0000C6   332 _PIOCON1	=	0x00c6
                           0000C7   333 _TA	=	0x00c7
                           0000C8   334 _T2CON	=	0x00c8
                           0000C9   335 _T2MOD	=	0x00c9
                           0000CA   336 _RCMP2L	=	0x00ca
                           0000CB   337 _RCMP2H	=	0x00cb
                           0000CC   338 _TL2	=	0x00cc
                           0000CC   339 _PWM4L	=	0x00cc
                           0000CD   340 _TH2	=	0x00cd
                           0000CD   341 _PWM5L	=	0x00cd
                           0000CE   342 _ADCMPL	=	0x00ce
                           0000CF   343 _ADCMPH	=	0x00cf
                           0000D0   344 _PSW	=	0x00d0
                           0000D1   345 _PWMPH	=	0x00d1
                           0000D2   346 _PWM0H	=	0x00d2
                           0000D3   347 _PWM1H	=	0x00d3
                           0000D4   348 _PWM2H	=	0x00d4
                           0000D5   349 _PWM3H	=	0x00d5
                           0000D6   350 _PNP	=	0x00d6
                           0000D7   351 _FBD	=	0x00d7
                           0000D8   352 _PWMCON0	=	0x00d8
                           0000D9   353 _PWMPL	=	0x00d9
                           0000DA   354 _PWM0L	=	0x00da
                           0000DB   355 _PWM1L	=	0x00db
                           0000DC   356 _PWM2L	=	0x00dc
                           0000DD   357 _PWM3L	=	0x00dd
                           0000DE   358 _PIOCON0	=	0x00de
                           0000DF   359 _PWMCON1	=	0x00df
                           0000E0   360 _ACC	=	0x00e0
                           0000E1   361 _ADCCON1	=	0x00e1
                           0000E2   362 _ADCCON2	=	0x00e2
                           0000E3   363 _ADCDLY	=	0x00e3
                           0000E4   364 _C0L	=	0x00e4
                           0000E5   365 _C0H	=	0x00e5
                           0000E6   366 _C1L	=	0x00e6
                           0000E7   367 _C1H	=	0x00e7
                           0000E8   368 _ADCCON0	=	0x00e8
                           0000E9   369 _PICON	=	0x00e9
                           0000EA   370 _PINEN	=	0x00ea
                           0000EB   371 _PIPEN	=	0x00eb
                           0000EC   372 _PIF	=	0x00ec
                           0000ED   373 _C2L	=	0x00ed
                           0000EE   374 _C2H	=	0x00ee
                           0000EF   375 _EIP	=	0x00ef
                           0000F0   376 _B	=	0x00f0
                           0000F1   377 _CAPCON3	=	0x00f1
                           0000F2   378 _CAPCON4	=	0x00f2
                           0000F3   379 _SPCR	=	0x00f3
                           0000F3   380 _SPCR2	=	0x00f3
                           0000F4   381 _SPSR	=	0x00f4
                           0000F5   382 _SPDR	=	0x00f5
                           0000F6   383 _AINDIDS	=	0x00f6
                           0000F7   384 _EIPH	=	0x00f7
                           0000F8   385 _SCON_1	=	0x00f8
                           0000F9   386 _PDTEN	=	0x00f9
                           0000FA   387 _PDTCNT	=	0x00fa
                           0000FB   388 _PMEN	=	0x00fb
                           0000FC   389 _PMD	=	0x00fc
                           0000FD   390 _PORDIS	=	0x00fd
                           0000FE   391 _EIP1	=	0x00fe
                           0000FF   392 _EIPH1	=	0x00ff
                                    393 ;--------------------------------------------------------
                                    394 ; special function bits
                                    395 ;--------------------------------------------------------
                                    396 	.area RSEG    (ABS,DATA)
      000000                        397 	.org 0x0000
                           0000FF   398 _SM0_1	=	0x00ff
                           0000FF   399 _FE_1	=	0x00ff
                           0000FE   400 _SM1_1	=	0x00fe
                           0000FD   401 _SM2_1	=	0x00fd
                           0000FC   402 _REN_1	=	0x00fc
                           0000FB   403 _TB8_1	=	0x00fb
                           0000FA   404 _RB8_1	=	0x00fa
                           0000F9   405 _TI_1	=	0x00f9
                           0000F8   406 _RI_1	=	0x00f8
                           0000EF   407 _ADCF	=	0x00ef
                           0000EE   408 _ADCS	=	0x00ee
                           0000ED   409 _ETGSEL1	=	0x00ed
                           0000EC   410 _ETGSEL0	=	0x00ec
                           0000EB   411 _ADCHS3	=	0x00eb
                           0000EA   412 _ADCHS2	=	0x00ea
                           0000E9   413 _ADCHS1	=	0x00e9
                           0000E8   414 _ADCHS0	=	0x00e8
                           0000DF   415 _PWMRUN	=	0x00df
                           0000DE   416 _LOAD	=	0x00de
                           0000DD   417 _PWMF	=	0x00dd
                           0000DC   418 _CLRPWM	=	0x00dc
                           0000D7   419 _CY	=	0x00d7
                           0000D6   420 _AC	=	0x00d6
                           0000D5   421 _F0	=	0x00d5
                           0000D4   422 _RS1	=	0x00d4
                           0000D3   423 _RS0	=	0x00d3
                           0000D2   424 _OV	=	0x00d2
                           0000D0   425 _P	=	0x00d0
                           0000CF   426 _TF2	=	0x00cf
                           0000CA   427 _TR2	=	0x00ca
                           0000C8   428 _CM_RL2	=	0x00c8
                           0000C6   429 _I2CEN	=	0x00c6
                           0000C5   430 _STA	=	0x00c5
                           0000C4   431 _STO	=	0x00c4
                           0000C3   432 _SI	=	0x00c3
                           0000C2   433 _AA	=	0x00c2
                           0000C0   434 _I2CPX	=	0x00c0
                           0000BE   435 _PADC	=	0x00be
                           0000BD   436 _PBOD	=	0x00bd
                           0000BC   437 _PS	=	0x00bc
                           0000BB   438 _PT1	=	0x00bb
                           0000BA   439 _PX1	=	0x00ba
                           0000B9   440 _PT0	=	0x00b9
                           0000B8   441 _PX0	=	0x00b8
                           0000B0   442 _P30	=	0x00b0
                           0000AF   443 _EA	=	0x00af
                           0000AE   444 _EADC	=	0x00ae
                           0000AD   445 _EBOD	=	0x00ad
                           0000AC   446 _ES	=	0x00ac
                           0000AB   447 _ET1	=	0x00ab
                           0000AA   448 _EX1	=	0x00aa
                           0000A9   449 _ET0	=	0x00a9
                           0000A8   450 _EX0	=	0x00a8
                           0000A0   451 _P20	=	0x00a0
                           00009F   452 _SM0	=	0x009f
                           00009F   453 _FE	=	0x009f
                           00009E   454 _SM1	=	0x009e
                           00009D   455 _SM2	=	0x009d
                           00009C   456 _REN	=	0x009c
                           00009B   457 _TB8	=	0x009b
                           00009A   458 _RB8	=	0x009a
                           000099   459 _TI	=	0x0099
                           000098   460 _RI	=	0x0098
                           000097   461 _P17	=	0x0097
                           000096   462 _P16	=	0x0096
                           000096   463 _TXD_1	=	0x0096
                           000095   464 _P15	=	0x0095
                           000094   465 _P14	=	0x0094
                           000094   466 _SDA	=	0x0094
                           000093   467 _P13	=	0x0093
                           000093   468 _SCL	=	0x0093
                           000092   469 _P12	=	0x0092
                           000091   470 _P11	=	0x0091
                           000090   471 _P10	=	0x0090
                           00008F   472 _TF1	=	0x008f
                           00008E   473 _TR1	=	0x008e
                           00008D   474 _TF0	=	0x008d
                           00008C   475 _TR0	=	0x008c
                           00008B   476 _IE1	=	0x008b
                           00008A   477 _IT1	=	0x008a
                           000089   478 _IE0	=	0x0089
                           000088   479 _IT0	=	0x0088
                           000087   480 _P07	=	0x0087
                           000087   481 _RXD	=	0x0087
                           000086   482 _P06	=	0x0086
                           000086   483 _TXD	=	0x0086
                           000085   484 _P05	=	0x0085
                           000084   485 _P04	=	0x0084
                           000084   486 _STADC	=	0x0084
                           000083   487 _P03	=	0x0083
                           000082   488 _P02	=	0x0082
                           000082   489 _RXD_1	=	0x0082
                           000081   490 _P01	=	0x0081
                           000081   491 _MISO	=	0x0081
                           000080   492 _P00	=	0x0080
                           000080   493 _MOSI	=	0x0080
                                    494 ;--------------------------------------------------------
                                    495 ; overlayable register banks
                                    496 ;--------------------------------------------------------
                                    497 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        498 	.ds 8
                                    499 ;--------------------------------------------------------
                                    500 ; internal ram data
                                    501 ;--------------------------------------------------------
                                    502 	.area DSEG    (DATA)
                                    503 ;--------------------------------------------------------
                                    504 ; overlayable items in internal ram
                                    505 ;--------------------------------------------------------
                                    506 	.area	OSEG    (OVR,DATA)
                                    507 	.area	OSEG    (OVR,DATA)
                                    508 	.area	OSEG    (OVR,DATA)
                                    509 	.area	OSEG    (OVR,DATA)
                                    510 	.area	OSEG    (OVR,DATA)
                                    511 	.area	OSEG    (OVR,DATA)
                                    512 	.area	OSEG    (OVR,DATA)
                                    513 ;--------------------------------------------------------
                                    514 ; indirectly addressable internal ram data
                                    515 ;--------------------------------------------------------
                                    516 	.area ISEG    (DATA)
                                    517 ;--------------------------------------------------------
                                    518 ; absolute internal ram data
                                    519 ;--------------------------------------------------------
                                    520 	.area IABS    (ABS,DATA)
                                    521 	.area IABS    (ABS,DATA)
                                    522 ;--------------------------------------------------------
                                    523 ; bit data
                                    524 ;--------------------------------------------------------
                                    525 	.area BSEG    (BIT)
                                    526 ;--------------------------------------------------------
                                    527 ; paged external ram data
                                    528 ;--------------------------------------------------------
                                    529 	.area PSEG    (PAG,XDATA)
                                    530 ;--------------------------------------------------------
                                    531 ; uninitialized external ram data
                                    532 ;--------------------------------------------------------
                                    533 	.area XSEG    (XDATA)
                                    534 ;--------------------------------------------------------
                                    535 ; absolute external ram data
                                    536 ;--------------------------------------------------------
                                    537 	.area XABS    (ABS,XDATA)
                                    538 ;--------------------------------------------------------
                                    539 ; initialized external ram data
                                    540 ;--------------------------------------------------------
                                    541 	.area XISEG   (XDATA)
                                    542 	.area HOME    (CODE)
                                    543 	.area GSINIT0 (CODE)
                                    544 	.area GSINIT1 (CODE)
                                    545 	.area GSINIT2 (CODE)
                                    546 	.area GSINIT3 (CODE)
                                    547 	.area GSINIT4 (CODE)
                                    548 	.area GSINIT5 (CODE)
                                    549 	.area GSINIT  (CODE)
                                    550 	.area GSFINAL (CODE)
                                    551 	.area CSEG    (CODE)
                                    552 ;--------------------------------------------------------
                                    553 ; global & static initialisations
                                    554 ;--------------------------------------------------------
                                    555 	.area HOME    (CODE)
                                    556 	.area GSINIT  (CODE)
                                    557 	.area GSFINAL (CODE)
                                    558 	.area GSINIT  (CODE)
                                    559 ;--------------------------------------------------------
                                    560 ; Home
                                    561 ;--------------------------------------------------------
                                    562 	.area HOME    (CODE)
                                    563 	.area HOME    (CODE)
                                    564 ;--------------------------------------------------------
                                    565 ; code
                                    566 ;--------------------------------------------------------
                                    567 	.area CSEG    (CODE)
                                    568 ;------------------------------------------------------------
                                    569 ;Allocation info for local variables in function 'Timer0_Delay100us'
                                    570 ;------------------------------------------------------------
                                    571 ;count                     Allocated to registers r4 r5 r6 r7 
                                    572 ;------------------------------------------------------------
                                    573 ;	lib\N76E003\Delay.c:4: void Timer0_Delay100us(uint32_t count)
                                    574 ;	-----------------------------------------
                                    575 ;	 function Timer0_Delay100us
                                    576 ;	-----------------------------------------
      0001D7                        577 _Timer0_Delay100us:
                           000007   578 	ar7 = 0x07
                           000006   579 	ar6 = 0x06
                           000005   580 	ar5 = 0x05
                           000004   581 	ar4 = 0x04
                           000003   582 	ar3 = 0x03
                           000002   583 	ar2 = 0x02
                           000001   584 	ar1 = 0x01
                           000000   585 	ar0 = 0x00
      0001D7 AC 82            [24]  586 	mov	r4,dpl
      0001D9 AD 83            [24]  587 	mov	r5,dph
      0001DB AE F0            [24]  588 	mov	r6,b
      0001DD FF               [12]  589 	mov	r7,a
                                    590 ;	lib\N76E003\Delay.c:6: clr_T0M;				//T0M=0, Timer0 Clock = Fsys/12
      0001DE 53 8E F7         [24]  591 	anl	_CKCON,#0xf7
                                    592 ;	lib\N76E003\Delay.c:7: TMOD |= 0x01;			//Timer0 is 16-bit mode
      0001E1 43 89 01         [24]  593 	orl	_TMOD,#0x01
                                    594 ;	lib\N76E003\Delay.c:8: set_TR0;				//Start Timer0
                                    595 ;	assignBit
      0001E4 D2 8C            [12]  596 	setb	_TR0
                                    597 ;	lib\N76E003\Delay.c:9: while (count--) {
      0001E6                        598 00104$:
      0001E6 8C 00            [24]  599 	mov	ar0,r4
      0001E8 8D 01            [24]  600 	mov	ar1,r5
      0001EA 8E 02            [24]  601 	mov	ar2,r6
      0001EC 8F 03            [24]  602 	mov	ar3,r7
      0001EE 1C               [12]  603 	dec	r4
      0001EF BC FF 09         [24]  604 	cjne	r4,#0xff,00134$
      0001F2 1D               [12]  605 	dec	r5
      0001F3 BD FF 05         [24]  606 	cjne	r5,#0xff,00134$
      0001F6 1E               [12]  607 	dec	r6
      0001F7 BE FF 01         [24]  608 	cjne	r6,#0xff,00134$
      0001FA 1F               [12]  609 	dec	r7
      0001FB                        610 00134$:
      0001FB E8               [12]  611 	mov	a,r0
      0001FC 49               [12]  612 	orl	a,r1
      0001FD 4A               [12]  613 	orl	a,r2
      0001FE 4B               [12]  614 	orl	a,r3
      0001FF 60 0B            [24]  615 	jz	00106$
                                    616 ;	lib\N76E003\Delay.c:10: TL0 = LOBYTE(TIMER_DIV12_VALUE_100us);
      000201 75 8A 76         [24]  617 	mov	_TL0,#0x76
                                    618 ;	lib\N76E003\Delay.c:11: TH0 = HIBYTE(TIMER_DIV12_VALUE_100us);
      000204 75 8C FF         [24]  619 	mov	_TH0,#0xff
                                    620 ;	lib\N76E003\Delay.c:12: while (TF0 != 1);	//Check Timer0 Time-Out Flag
      000207                        621 00101$:
                                    622 ;	lib\N76E003\Delay.c:13: clr_TF0;
                                    623 ;	assignBit
      000207 10 8D DC         [24]  624 	jbc	_TF0,00104$
      00020A 80 FB            [24]  625 	sjmp	00101$
      00020C                        626 00106$:
                                    627 ;	lib\N76E003\Delay.c:15: clr_TR0;				//Stop Timer0
                                    628 ;	assignBit
      00020C C2 8C            [12]  629 	clr	_TR0
                                    630 ;	lib\N76E003\Delay.c:16: }
      00020E 22               [24]  631 	ret
                                    632 ;------------------------------------------------------------
                                    633 ;Allocation info for local variables in function 'Timer0_Delay1ms'
                                    634 ;------------------------------------------------------------
                                    635 ;count                     Allocated to registers r4 r5 r6 r7 
                                    636 ;------------------------------------------------------------
                                    637 ;	lib\N76E003\Delay.c:18: void Timer0_Delay1ms(uint32_t count)
                                    638 ;	-----------------------------------------
                                    639 ;	 function Timer0_Delay1ms
                                    640 ;	-----------------------------------------
      00020F                        641 _Timer0_Delay1ms:
      00020F AC 82            [24]  642 	mov	r4,dpl
      000211 AD 83            [24]  643 	mov	r5,dph
      000213 AE F0            [24]  644 	mov	r6,b
      000215 FF               [12]  645 	mov	r7,a
                                    646 ;	lib\N76E003\Delay.c:20: clr_T0M;				//T0M=0, Timer0 Clock = Fsys/12
      000216 53 8E F7         [24]  647 	anl	_CKCON,#0xf7
                                    648 ;	lib\N76E003\Delay.c:21: TMOD |= 0x01;			//Timer0 is 16-bit mode
      000219 43 89 01         [24]  649 	orl	_TMOD,#0x01
                                    650 ;	lib\N76E003\Delay.c:22: set_TR0;				//Start Timer0
                                    651 ;	assignBit
      00021C D2 8C            [12]  652 	setb	_TR0
                                    653 ;	lib\N76E003\Delay.c:23: while (count--) {
      00021E                        654 00104$:
      00021E 8C 00            [24]  655 	mov	ar0,r4
      000220 8D 01            [24]  656 	mov	ar1,r5
      000222 8E 02            [24]  657 	mov	ar2,r6
      000224 8F 03            [24]  658 	mov	ar3,r7
      000226 1C               [12]  659 	dec	r4
      000227 BC FF 09         [24]  660 	cjne	r4,#0xff,00134$
      00022A 1D               [12]  661 	dec	r5
      00022B BD FF 05         [24]  662 	cjne	r5,#0xff,00134$
      00022E 1E               [12]  663 	dec	r6
      00022F BE FF 01         [24]  664 	cjne	r6,#0xff,00134$
      000232 1F               [12]  665 	dec	r7
      000233                        666 00134$:
      000233 E8               [12]  667 	mov	a,r0
      000234 49               [12]  668 	orl	a,r1
      000235 4A               [12]  669 	orl	a,r2
      000236 4B               [12]  670 	orl	a,r3
      000237 60 0B            [24]  671 	jz	00106$
                                    672 ;	lib\N76E003\Delay.c:24: TL0 = LOBYTE(TIMER_DIV12_VALUE_1ms);
      000239 75 8A 98         [24]  673 	mov	_TL0,#0x98
                                    674 ;	lib\N76E003\Delay.c:25: TH0 = HIBYTE(TIMER_DIV12_VALUE_1ms);
      00023C 75 8C FA         [24]  675 	mov	_TH0,#0xfa
                                    676 ;	lib\N76E003\Delay.c:26: while (TF0 != 1);	//Check Timer0 Time-Out Flag
      00023F                        677 00101$:
                                    678 ;	lib\N76E003\Delay.c:27: clr_TF0;
                                    679 ;	assignBit
      00023F 10 8D DC         [24]  680 	jbc	_TF0,00104$
      000242 80 FB            [24]  681 	sjmp	00101$
      000244                        682 00106$:
                                    683 ;	lib\N76E003\Delay.c:29: clr_TR0;				//Stop Timer0
                                    684 ;	assignBit
      000244 C2 8C            [12]  685 	clr	_TR0
                                    686 ;	lib\N76E003\Delay.c:30: }
      000246 22               [24]  687 	ret
                                    688 ;------------------------------------------------------------
                                    689 ;Allocation info for local variables in function 'Timer0_Delay40ms'
                                    690 ;------------------------------------------------------------
                                    691 ;count                     Allocated to registers r4 r5 r6 r7 
                                    692 ;------------------------------------------------------------
                                    693 ;	lib\N76E003\Delay.c:32: void Timer0_Delay40ms(uint32_t count)
                                    694 ;	-----------------------------------------
                                    695 ;	 function Timer0_Delay40ms
                                    696 ;	-----------------------------------------
      000247                        697 _Timer0_Delay40ms:
      000247 AC 82            [24]  698 	mov	r4,dpl
      000249 AD 83            [24]  699 	mov	r5,dph
      00024B AE F0            [24]  700 	mov	r6,b
      00024D FF               [12]  701 	mov	r7,a
                                    702 ;	lib\N76E003\Delay.c:34: clr_T0M;				//T0M=0, Timer0 Clock = Fsys/12
      00024E 53 8E F7         [24]  703 	anl	_CKCON,#0xf7
                                    704 ;	lib\N76E003\Delay.c:35: TMOD |= 0x01;			//Timer0 is 16-bit mode
      000251 43 89 01         [24]  705 	orl	_TMOD,#0x01
                                    706 ;	lib\N76E003\Delay.c:36: set_TR0;				//Start Timer0
                                    707 ;	assignBit
      000254 D2 8C            [12]  708 	setb	_TR0
                                    709 ;	lib\N76E003\Delay.c:37: while (count--) {
      000256                        710 00104$:
      000256 8C 00            [24]  711 	mov	ar0,r4
      000258 8D 01            [24]  712 	mov	ar1,r5
      00025A 8E 02            [24]  713 	mov	ar2,r6
      00025C 8F 03            [24]  714 	mov	ar3,r7
      00025E 1C               [12]  715 	dec	r4
      00025F BC FF 09         [24]  716 	cjne	r4,#0xff,00134$
      000262 1D               [12]  717 	dec	r5
      000263 BD FF 05         [24]  718 	cjne	r5,#0xff,00134$
      000266 1E               [12]  719 	dec	r6
      000267 BE FF 01         [24]  720 	cjne	r6,#0xff,00134$
      00026A 1F               [12]  721 	dec	r7
      00026B                        722 00134$:
      00026B E8               [12]  723 	mov	a,r0
      00026C 49               [12]  724 	orl	a,r1
      00026D 4A               [12]  725 	orl	a,r2
      00026E 4B               [12]  726 	orl	a,r3
      00026F 60 0B            [24]  727 	jz	00106$
                                    728 ;	lib\N76E003\Delay.c:38: TL0 = LOBYTE(TIMER_DIV12_VALUE_40ms);
      000271 75 8A DB         [24]  729 	mov	_TL0,#0xdb
                                    730 ;	lib\N76E003\Delay.c:39: TH0 = HIBYTE(TIMER_DIV12_VALUE_40ms);
      000274 75 8C 27         [24]  731 	mov	_TH0,#0x27
                                    732 ;	lib\N76E003\Delay.c:40: while (TF0 != 1);	//Check Timer0 Time-Out Flag
      000277                        733 00101$:
                                    734 ;	lib\N76E003\Delay.c:41: clr_TF0;
                                    735 ;	assignBit
      000277 10 8D DC         [24]  736 	jbc	_TF0,00104$
      00027A 80 FB            [24]  737 	sjmp	00101$
      00027C                        738 00106$:
                                    739 ;	lib\N76E003\Delay.c:43: clr_TR0;				//Stop Timer0
                                    740 ;	assignBit
      00027C C2 8C            [12]  741 	clr	_TR0
                                    742 ;	lib\N76E003\Delay.c:44: }
      00027E 22               [24]  743 	ret
                                    744 ;------------------------------------------------------------
                                    745 ;Allocation info for local variables in function 'Timer1_Delay10ms'
                                    746 ;------------------------------------------------------------
                                    747 ;count                     Allocated to registers r4 r5 r6 r7 
                                    748 ;------------------------------------------------------------
                                    749 ;	lib\N76E003\Delay.c:46: void Timer1_Delay10ms(uint32_t count)
                                    750 ;	-----------------------------------------
                                    751 ;	 function Timer1_Delay10ms
                                    752 ;	-----------------------------------------
      00027F                        753 _Timer1_Delay10ms:
      00027F AC 82            [24]  754 	mov	r4,dpl
      000281 AD 83            [24]  755 	mov	r5,dph
      000283 AE F0            [24]  756 	mov	r6,b
      000285 FF               [12]  757 	mov	r7,a
                                    758 ;	lib\N76E003\Delay.c:48: clr_T1M;				//T1M=0, Timer1 Clock = Fsys/12
      000286 53 8E EF         [24]  759 	anl	_CKCON,#0xef
                                    760 ;	lib\N76E003\Delay.c:49: TMOD |= 0x10;			//Timer1 is 16-bit mode
      000289 43 89 10         [24]  761 	orl	_TMOD,#0x10
                                    762 ;	lib\N76E003\Delay.c:50: set_TR1;				//Start Timer1
                                    763 ;	assignBit
      00028C D2 8E            [12]  764 	setb	_TR1
                                    765 ;	lib\N76E003\Delay.c:51: while (count--) {
      00028E                        766 00104$:
      00028E 8C 00            [24]  767 	mov	ar0,r4
      000290 8D 01            [24]  768 	mov	ar1,r5
      000292 8E 02            [24]  769 	mov	ar2,r6
      000294 8F 03            [24]  770 	mov	ar3,r7
      000296 1C               [12]  771 	dec	r4
      000297 BC FF 09         [24]  772 	cjne	r4,#0xff,00134$
      00029A 1D               [12]  773 	dec	r5
      00029B BD FF 05         [24]  774 	cjne	r5,#0xff,00134$
      00029E 1E               [12]  775 	dec	r6
      00029F BE FF 01         [24]  776 	cjne	r6,#0xff,00134$
      0002A2 1F               [12]  777 	dec	r7
      0002A3                        778 00134$:
      0002A3 E8               [12]  779 	mov	a,r0
      0002A4 49               [12]  780 	orl	a,r1
      0002A5 4A               [12]  781 	orl	a,r2
      0002A6 4B               [12]  782 	orl	a,r3
      0002A7 60 0B            [24]  783 	jz	00106$
                                    784 ;	lib\N76E003\Delay.c:52: TL1 = LOBYTE(TIMER_DIV12_VALUE_10ms);
      0002A9 75 8B F6         [24]  785 	mov	_TL1,#0xf6
                                    786 ;	lib\N76E003\Delay.c:53: TH1 = HIBYTE(TIMER_DIV12_VALUE_10ms);
      0002AC 75 8D C9         [24]  787 	mov	_TH1,#0xc9
                                    788 ;	lib\N76E003\Delay.c:54: while (TF1 != 1);	//Check Timer1 Time-Out Flag
      0002AF                        789 00101$:
                                    790 ;	lib\N76E003\Delay.c:55: clr_TF1;
                                    791 ;	assignBit
      0002AF 10 8F DC         [24]  792 	jbc	_TF1,00104$
      0002B2 80 FB            [24]  793 	sjmp	00101$
      0002B4                        794 00106$:
                                    795 ;	lib\N76E003\Delay.c:57: clr_TR1;				//Stop Timer1
                                    796 ;	assignBit
      0002B4 C2 8E            [12]  797 	clr	_TR1
                                    798 ;	lib\N76E003\Delay.c:58: }
      0002B6 22               [24]  799 	ret
                                    800 ;------------------------------------------------------------
                                    801 ;Allocation info for local variables in function 'Timer2_Delay500us'
                                    802 ;------------------------------------------------------------
                                    803 ;count                     Allocated to registers r4 r5 r6 r7 
                                    804 ;------------------------------------------------------------
                                    805 ;	lib\N76E003\Delay.c:60: void Timer2_Delay500us(uint32_t count)
                                    806 ;	-----------------------------------------
                                    807 ;	 function Timer2_Delay500us
                                    808 ;	-----------------------------------------
      0002B7                        809 _Timer2_Delay500us:
      0002B7 AC 82            [24]  810 	mov	r4,dpl
      0002B9 AD 83            [24]  811 	mov	r5,dph
      0002BB AE F0            [24]  812 	mov	r6,b
      0002BD FF               [12]  813 	mov	r7,a
                                    814 ;	lib\N76E003\Delay.c:62: clr_T2DIV2;				//Timer2 Clock = Fsys/4 
      0002BE 53 C9 BF         [24]  815 	anl	_T2MOD,#0xbf
                                    816 ;	lib\N76E003\Delay.c:63: clr_T2DIV1;
      0002C1 53 C9 DF         [24]  817 	anl	_T2MOD,#0xdf
                                    818 ;	lib\N76E003\Delay.c:64: set_T2DIV0;
      0002C4 43 C9 10         [24]  819 	orl	_T2MOD,#0x10
                                    820 ;	lib\N76E003\Delay.c:65: set_TR2;				//Start Timer2
                                    821 ;	assignBit
      0002C7 D2 CA            [12]  822 	setb	_TR2
                                    823 ;	lib\N76E003\Delay.c:66: while (count--) {
      0002C9                        824 00104$:
      0002C9 8C 00            [24]  825 	mov	ar0,r4
      0002CB 8D 01            [24]  826 	mov	ar1,r5
      0002CD 8E 02            [24]  827 	mov	ar2,r6
      0002CF 8F 03            [24]  828 	mov	ar3,r7
      0002D1 1C               [12]  829 	dec	r4
      0002D2 BC FF 09         [24]  830 	cjne	r4,#0xff,00134$
      0002D5 1D               [12]  831 	dec	r5
      0002D6 BD FF 05         [24]  832 	cjne	r5,#0xff,00134$
      0002D9 1E               [12]  833 	dec	r6
      0002DA BE FF 01         [24]  834 	cjne	r6,#0xff,00134$
      0002DD 1F               [12]  835 	dec	r7
      0002DE                        836 00134$:
      0002DE E8               [12]  837 	mov	a,r0
      0002DF 49               [12]  838 	orl	a,r1
      0002E0 4A               [12]  839 	orl	a,r2
      0002E1 4B               [12]  840 	orl	a,r3
      0002E2 60 0B            [24]  841 	jz	00106$
                                    842 ;	lib\N76E003\Delay.c:67: TL2 = LOBYTE(TIMER_DIV4_VALUE_500us);
      0002E4 75 CC E5         [24]  843 	mov	_TL2,#0xe5
                                    844 ;	lib\N76E003\Delay.c:68: TH2 = HIBYTE(TIMER_DIV4_VALUE_500us);
      0002E7 75 CD F7         [24]  845 	mov	_TH2,#0xf7
                                    846 ;	lib\N76E003\Delay.c:69: while (TF2 != 1);	//Check Timer2 Time-Out Flag
      0002EA                        847 00101$:
                                    848 ;	lib\N76E003\Delay.c:70: clr_TF2;
                                    849 ;	assignBit
      0002EA 10 CF DC         [24]  850 	jbc	_TF2,00104$
      0002ED 80 FB            [24]  851 	sjmp	00101$
      0002EF                        852 00106$:
                                    853 ;	lib\N76E003\Delay.c:72: clr_TR2;				//Stop Timer2
                                    854 ;	assignBit
      0002EF C2 CA            [12]  855 	clr	_TR2
                                    856 ;	lib\N76E003\Delay.c:73: }
      0002F1 22               [24]  857 	ret
                                    858 ;------------------------------------------------------------
                                    859 ;Allocation info for local variables in function 'Timer3_Delay10us'
                                    860 ;------------------------------------------------------------
                                    861 ;count                     Allocated to registers r4 r5 r6 r7 
                                    862 ;------------------------------------------------------------
                                    863 ;	lib\N76E003\Delay.c:75: void Timer3_Delay10us(uint32_t count)
                                    864 ;	-----------------------------------------
                                    865 ;	 function Timer3_Delay10us
                                    866 ;	-----------------------------------------
      0002F2                        867 _Timer3_Delay10us:
      0002F2 AC 82            [24]  868 	mov	r4,dpl
      0002F4 AD 83            [24]  869 	mov	r5,dph
      0002F6 AE F0            [24]  870 	mov	r6,b
      0002F8 FF               [12]  871 	mov	r7,a
                                    872 ;	lib\N76E003\Delay.c:77: T3CON = 0x07;			//Timer3 Clock = Fsys/128
      0002F9 75 C4 07         [24]  873 	mov	_T3CON,#0x07
                                    874 ;	lib\N76E003\Delay.c:78: set_TR3;				//Trigger Timer3
      0002FC 43 C4 08         [24]  875 	orl	_T3CON,#0x08
                                    876 ;	lib\N76E003\Delay.c:79: while (count--) {
      0002FF                        877 00104$:
      0002FF 8C 00            [24]  878 	mov	ar0,r4
      000301 8D 01            [24]  879 	mov	ar1,r5
      000303 8E 02            [24]  880 	mov	ar2,r6
      000305 8F 03            [24]  881 	mov	ar3,r7
      000307 1C               [12]  882 	dec	r4
      000308 BC FF 09         [24]  883 	cjne	r4,#0xff,00134$
      00030B 1D               [12]  884 	dec	r5
      00030C BD FF 05         [24]  885 	cjne	r5,#0xff,00134$
      00030F 1E               [12]  886 	dec	r6
      000310 BE FF 01         [24]  887 	cjne	r6,#0xff,00134$
      000313 1F               [12]  888 	dec	r7
      000314                        889 00134$:
      000314 E8               [12]  890 	mov	a,r0
      000315 49               [12]  891 	orl	a,r1
      000316 4A               [12]  892 	orl	a,r2
      000317 4B               [12]  893 	orl	a,r3
      000318 60 13            [24]  894 	jz	00106$
                                    895 ;	lib\N76E003\Delay.c:80: RL3 = LOBYTE(TIMER_DIV4_VALUE_10us);
      00031A 75 C5 D7         [24]  896 	mov	_RL3,#0xd7
                                    897 ;	lib\N76E003\Delay.c:81: RH3 = HIBYTE(TIMER_DIV4_VALUE_10us);
      00031D 75 C6 FF         [24]  898 	mov	_RH3,#0xff
                                    899 ;	lib\N76E003\Delay.c:82: while ((T3CON&SET_BIT4) != SET_BIT4);	//Check Timer3 Time-Out Flag
      000320                        900 00101$:
      000320 AB C4            [24]  901 	mov	r3,_T3CON
      000322 53 03 10         [24]  902 	anl	ar3,#0x10
      000325 BB 10 F8         [24]  903 	cjne	r3,#0x10,00101$
                                    904 ;	lib\N76E003\Delay.c:83: clr_TF3;
      000328 53 C4 EF         [24]  905 	anl	_T3CON,#0xef
      00032B 80 D2            [24]  906 	sjmp	00104$
      00032D                        907 00106$:
                                    908 ;	lib\N76E003\Delay.c:85: clr_TR3;				//Stop Timer3
      00032D 53 C4 F7         [24]  909 	anl	_T3CON,#0xf7
                                    910 ;	lib\N76E003\Delay.c:86: }
      000330 22               [24]  911 	ret
                                    912 ;------------------------------------------------------------
                                    913 ;Allocation info for local variables in function 'Timer3_Delay100ms'
                                    914 ;------------------------------------------------------------
                                    915 ;count                     Allocated to registers r4 r5 r6 r7 
                                    916 ;------------------------------------------------------------
                                    917 ;	lib\N76E003\Delay.c:88: void Timer3_Delay100ms(uint32_t count)
                                    918 ;	-----------------------------------------
                                    919 ;	 function Timer3_Delay100ms
                                    920 ;	-----------------------------------------
      000331                        921 _Timer3_Delay100ms:
      000331 AC 82            [24]  922 	mov	r4,dpl
      000333 AD 83            [24]  923 	mov	r5,dph
      000335 AE F0            [24]  924 	mov	r6,b
      000337 FF               [12]  925 	mov	r7,a
                                    926 ;	lib\N76E003\Delay.c:90: T3CON = 0x07;			//Timer3 Clock = Fsys/128
      000338 75 C4 07         [24]  927 	mov	_T3CON,#0x07
                                    928 ;	lib\N76E003\Delay.c:91: set_TR3;				//Trigger Timer3
      00033B 43 C4 08         [24]  929 	orl	_T3CON,#0x08
                                    930 ;	lib\N76E003\Delay.c:92: while (count--) {
      00033E                        931 00104$:
      00033E 8C 00            [24]  932 	mov	ar0,r4
      000340 8D 01            [24]  933 	mov	ar1,r5
      000342 8E 02            [24]  934 	mov	ar2,r6
      000344 8F 03            [24]  935 	mov	ar3,r7
      000346 1C               [12]  936 	dec	r4
      000347 BC FF 09         [24]  937 	cjne	r4,#0xff,00134$
      00034A 1D               [12]  938 	dec	r5
      00034B BD FF 05         [24]  939 	cjne	r5,#0xff,00134$
      00034E 1E               [12]  940 	dec	r6
      00034F BE FF 01         [24]  941 	cjne	r6,#0xff,00134$
      000352 1F               [12]  942 	dec	r7
      000353                        943 00134$:
      000353 E8               [12]  944 	mov	a,r0
      000354 49               [12]  945 	orl	a,r1
      000355 4A               [12]  946 	orl	a,r2
      000356 4B               [12]  947 	orl	a,r3
      000357 60 13            [24]  948 	jz	00106$
                                    949 ;	lib\N76E003\Delay.c:93: RL3 = LOBYTE(TIMER_DIV128_VALUE_100ms);
      000359 75 C5 57         [24]  950 	mov	_RL3,#0x57
                                    951 ;	lib\N76E003\Delay.c:94: RH3 = HIBYTE(TIMER_DIV128_VALUE_100ms);
      00035C 75 C6 CD         [24]  952 	mov	_RH3,#0xcd
                                    953 ;	lib\N76E003\Delay.c:95: while ((T3CON&SET_BIT4) != SET_BIT4);	//Check Timer3 Time-Out Flag
      00035F                        954 00101$:
      00035F AB C4            [24]  955 	mov	r3,_T3CON
      000361 53 03 10         [24]  956 	anl	ar3,#0x10
      000364 BB 10 F8         [24]  957 	cjne	r3,#0x10,00101$
                                    958 ;	lib\N76E003\Delay.c:96: clr_TF3;
      000367 53 C4 EF         [24]  959 	anl	_T3CON,#0xef
      00036A 80 D2            [24]  960 	sjmp	00104$
      00036C                        961 00106$:
                                    962 ;	lib\N76E003\Delay.c:98: clr_TR3;				//Stop Timer3
      00036C 53 C4 F7         [24]  963 	anl	_T3CON,#0xf7
                                    964 ;	lib\N76E003\Delay.c:99: }
      00036F 22               [24]  965 	ret
                                    966 	.area CSEG    (CODE)
                                    967 	.area CONST   (CODE)
                                    968 	.area XINIT   (CODE)
                                    969 	.area CABS    (ABS,CODE)
