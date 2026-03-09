                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ISO C Compiler 
                                      3 ; Version 4.4.0 #14620 (MINGW32)
                                      4 ;--------------------------------------------------------
                                      5 	.module Common
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
                                    244 	.globl _BIT_TMP
                                    245 	.globl _InitialUART0_Timer1
                                    246 	.globl _InitialUART0_Timer3
                                    247 	.globl _Receive_Data_From_UART0
                                    248 	.globl _Send_Data_To_UART0
                                    249 	.globl _InitialUART1_Timer3
                                    250 	.globl _Receive_Data_From_UART1
                                    251 	.globl _Send_Data_To_UART1
                                    252 ;--------------------------------------------------------
                                    253 ; special function registers
                                    254 ;--------------------------------------------------------
                                    255 	.area RSEG    (ABS,DATA)
      000000                        256 	.org 0x0000
                           000080   257 _P0	=	0x0080
                           000081   258 _SP	=	0x0081
                           000082   259 _DPL	=	0x0082
                           000083   260 _DPH	=	0x0083
                           000084   261 _RCTRIM0	=	0x0084
                           000085   262 _RCTRIM1	=	0x0085
                           000086   263 _RWK	=	0x0086
                           000087   264 _PCON	=	0x0087
                           000088   265 _TCON	=	0x0088
                           000089   266 _TMOD	=	0x0089
                           00008A   267 _TL0	=	0x008a
                           00008B   268 _TL1	=	0x008b
                           00008C   269 _TH0	=	0x008c
                           00008D   270 _TH1	=	0x008d
                           00008E   271 _CKCON	=	0x008e
                           00008F   272 _WKCON	=	0x008f
                           000090   273 _P1	=	0x0090
                           000091   274 _SFRS	=	0x0091
                           000092   275 _CAPCON0	=	0x0092
                           000093   276 _CAPCON1	=	0x0093
                           000094   277 _CAPCON2	=	0x0094
                           000095   278 _CKDIV	=	0x0095
                           000096   279 _CKSWT	=	0x0096
                           000097   280 _CKEN	=	0x0097
                           000098   281 _SCON	=	0x0098
                           000099   282 _SBUF	=	0x0099
                           00009A   283 _SBUF_1	=	0x009a
                           00009B   284 _EIE	=	0x009b
                           00009C   285 _EIE1	=	0x009c
                           00009F   286 _CHPCON	=	0x009f
                           0000A0   287 _P2	=	0x00a0
                           0000A2   288 _AUXR1	=	0x00a2
                           0000A3   289 _BODCON0	=	0x00a3
                           0000A4   290 _IAPTRG	=	0x00a4
                           0000A5   291 _IAPUEN	=	0x00a5
                           0000A6   292 _IAPAL	=	0x00a6
                           0000A7   293 _IAPAH	=	0x00a7
                           0000A8   294 _IE	=	0x00a8
                           0000A9   295 _SADDR	=	0x00a9
                           0000AA   296 _WDCON	=	0x00aa
                           0000AB   297 _BODCON1	=	0x00ab
                           0000AC   298 _P3M1	=	0x00ac
                           0000AC   299 _P3S	=	0x00ac
                           0000AD   300 _P3M2	=	0x00ad
                           0000AD   301 _P3SR	=	0x00ad
                           0000AE   302 _IAPFD	=	0x00ae
                           0000AF   303 _IAPCN	=	0x00af
                           0000B0   304 _P3	=	0x00b0
                           0000B1   305 _P0M1	=	0x00b1
                           0000B1   306 _P0S	=	0x00b1
                           0000B2   307 _P0M2	=	0x00b2
                           0000B2   308 _P0SR	=	0x00b2
                           0000B3   309 _P1M1	=	0x00b3
                           0000B3   310 _P1S	=	0x00b3
                           0000B4   311 _P1M2	=	0x00b4
                           0000B4   312 _P1SR	=	0x00b4
                           0000B5   313 _P2S	=	0x00b5
                           0000B7   314 _IPH	=	0x00b7
                           0000B7   315 _PWMINTC	=	0x00b7
                           0000B8   316 _IP	=	0x00b8
                           0000B9   317 _SADEN	=	0x00b9
                           0000BA   318 _SADEN_1	=	0x00ba
                           0000BB   319 _SADDR_1	=	0x00bb
                           0000BC   320 _I2DAT	=	0x00bc
                           0000BD   321 _I2STAT	=	0x00bd
                           0000BE   322 _I2CLK	=	0x00be
                           0000BF   323 _I2TOC	=	0x00bf
                           0000C0   324 _I2CON	=	0x00c0
                           0000C1   325 _I2ADDR	=	0x00c1
                           0000C2   326 _ADCRL	=	0x00c2
                           0000C3   327 _ADCRH	=	0x00c3
                           0000C4   328 _T3CON	=	0x00c4
                           0000C4   329 _PWM4H	=	0x00c4
                           0000C5   330 _RL3	=	0x00c5
                           0000C5   331 _PWM5H	=	0x00c5
                           0000C6   332 _RH3	=	0x00c6
                           0000C6   333 _PIOCON1	=	0x00c6
                           0000C7   334 _TA	=	0x00c7
                           0000C8   335 _T2CON	=	0x00c8
                           0000C9   336 _T2MOD	=	0x00c9
                           0000CA   337 _RCMP2L	=	0x00ca
                           0000CB   338 _RCMP2H	=	0x00cb
                           0000CC   339 _TL2	=	0x00cc
                           0000CC   340 _PWM4L	=	0x00cc
                           0000CD   341 _TH2	=	0x00cd
                           0000CD   342 _PWM5L	=	0x00cd
                           0000CE   343 _ADCMPL	=	0x00ce
                           0000CF   344 _ADCMPH	=	0x00cf
                           0000D0   345 _PSW	=	0x00d0
                           0000D1   346 _PWMPH	=	0x00d1
                           0000D2   347 _PWM0H	=	0x00d2
                           0000D3   348 _PWM1H	=	0x00d3
                           0000D4   349 _PWM2H	=	0x00d4
                           0000D5   350 _PWM3H	=	0x00d5
                           0000D6   351 _PNP	=	0x00d6
                           0000D7   352 _FBD	=	0x00d7
                           0000D8   353 _PWMCON0	=	0x00d8
                           0000D9   354 _PWMPL	=	0x00d9
                           0000DA   355 _PWM0L	=	0x00da
                           0000DB   356 _PWM1L	=	0x00db
                           0000DC   357 _PWM2L	=	0x00dc
                           0000DD   358 _PWM3L	=	0x00dd
                           0000DE   359 _PIOCON0	=	0x00de
                           0000DF   360 _PWMCON1	=	0x00df
                           0000E0   361 _ACC	=	0x00e0
                           0000E1   362 _ADCCON1	=	0x00e1
                           0000E2   363 _ADCCON2	=	0x00e2
                           0000E3   364 _ADCDLY	=	0x00e3
                           0000E4   365 _C0L	=	0x00e4
                           0000E5   366 _C0H	=	0x00e5
                           0000E6   367 _C1L	=	0x00e6
                           0000E7   368 _C1H	=	0x00e7
                           0000E8   369 _ADCCON0	=	0x00e8
                           0000E9   370 _PICON	=	0x00e9
                           0000EA   371 _PINEN	=	0x00ea
                           0000EB   372 _PIPEN	=	0x00eb
                           0000EC   373 _PIF	=	0x00ec
                           0000ED   374 _C2L	=	0x00ed
                           0000EE   375 _C2H	=	0x00ee
                           0000EF   376 _EIP	=	0x00ef
                           0000F0   377 _B	=	0x00f0
                           0000F1   378 _CAPCON3	=	0x00f1
                           0000F2   379 _CAPCON4	=	0x00f2
                           0000F3   380 _SPCR	=	0x00f3
                           0000F3   381 _SPCR2	=	0x00f3
                           0000F4   382 _SPSR	=	0x00f4
                           0000F5   383 _SPDR	=	0x00f5
                           0000F6   384 _AINDIDS	=	0x00f6
                           0000F7   385 _EIPH	=	0x00f7
                           0000F8   386 _SCON_1	=	0x00f8
                           0000F9   387 _PDTEN	=	0x00f9
                           0000FA   388 _PDTCNT	=	0x00fa
                           0000FB   389 _PMEN	=	0x00fb
                           0000FC   390 _PMD	=	0x00fc
                           0000FD   391 _PORDIS	=	0x00fd
                           0000FE   392 _EIP1	=	0x00fe
                           0000FF   393 _EIPH1	=	0x00ff
                                    394 ;--------------------------------------------------------
                                    395 ; special function bits
                                    396 ;--------------------------------------------------------
                                    397 	.area RSEG    (ABS,DATA)
      000000                        398 	.org 0x0000
                           0000FF   399 _SM0_1	=	0x00ff
                           0000FF   400 _FE_1	=	0x00ff
                           0000FE   401 _SM1_1	=	0x00fe
                           0000FD   402 _SM2_1	=	0x00fd
                           0000FC   403 _REN_1	=	0x00fc
                           0000FB   404 _TB8_1	=	0x00fb
                           0000FA   405 _RB8_1	=	0x00fa
                           0000F9   406 _TI_1	=	0x00f9
                           0000F8   407 _RI_1	=	0x00f8
                           0000EF   408 _ADCF	=	0x00ef
                           0000EE   409 _ADCS	=	0x00ee
                           0000ED   410 _ETGSEL1	=	0x00ed
                           0000EC   411 _ETGSEL0	=	0x00ec
                           0000EB   412 _ADCHS3	=	0x00eb
                           0000EA   413 _ADCHS2	=	0x00ea
                           0000E9   414 _ADCHS1	=	0x00e9
                           0000E8   415 _ADCHS0	=	0x00e8
                           0000DF   416 _PWMRUN	=	0x00df
                           0000DE   417 _LOAD	=	0x00de
                           0000DD   418 _PWMF	=	0x00dd
                           0000DC   419 _CLRPWM	=	0x00dc
                           0000D7   420 _CY	=	0x00d7
                           0000D6   421 _AC	=	0x00d6
                           0000D5   422 _F0	=	0x00d5
                           0000D4   423 _RS1	=	0x00d4
                           0000D3   424 _RS0	=	0x00d3
                           0000D2   425 _OV	=	0x00d2
                           0000D0   426 _P	=	0x00d0
                           0000CF   427 _TF2	=	0x00cf
                           0000CA   428 _TR2	=	0x00ca
                           0000C8   429 _CM_RL2	=	0x00c8
                           0000C6   430 _I2CEN	=	0x00c6
                           0000C5   431 _STA	=	0x00c5
                           0000C4   432 _STO	=	0x00c4
                           0000C3   433 _SI	=	0x00c3
                           0000C2   434 _AA	=	0x00c2
                           0000C0   435 _I2CPX	=	0x00c0
                           0000BE   436 _PADC	=	0x00be
                           0000BD   437 _PBOD	=	0x00bd
                           0000BC   438 _PS	=	0x00bc
                           0000BB   439 _PT1	=	0x00bb
                           0000BA   440 _PX1	=	0x00ba
                           0000B9   441 _PT0	=	0x00b9
                           0000B8   442 _PX0	=	0x00b8
                           0000B0   443 _P30	=	0x00b0
                           0000AF   444 _EA	=	0x00af
                           0000AE   445 _EADC	=	0x00ae
                           0000AD   446 _EBOD	=	0x00ad
                           0000AC   447 _ES	=	0x00ac
                           0000AB   448 _ET1	=	0x00ab
                           0000AA   449 _EX1	=	0x00aa
                           0000A9   450 _ET0	=	0x00a9
                           0000A8   451 _EX0	=	0x00a8
                           0000A0   452 _P20	=	0x00a0
                           00009F   453 _SM0	=	0x009f
                           00009F   454 _FE	=	0x009f
                           00009E   455 _SM1	=	0x009e
                           00009D   456 _SM2	=	0x009d
                           00009C   457 _REN	=	0x009c
                           00009B   458 _TB8	=	0x009b
                           00009A   459 _RB8	=	0x009a
                           000099   460 _TI	=	0x0099
                           000098   461 _RI	=	0x0098
                           000097   462 _P17	=	0x0097
                           000096   463 _P16	=	0x0096
                           000096   464 _TXD_1	=	0x0096
                           000095   465 _P15	=	0x0095
                           000094   466 _P14	=	0x0094
                           000094   467 _SDA	=	0x0094
                           000093   468 _P13	=	0x0093
                           000093   469 _SCL	=	0x0093
                           000092   470 _P12	=	0x0092
                           000091   471 _P11	=	0x0091
                           000090   472 _P10	=	0x0090
                           00008F   473 _TF1	=	0x008f
                           00008E   474 _TR1	=	0x008e
                           00008D   475 _TF0	=	0x008d
                           00008C   476 _TR0	=	0x008c
                           00008B   477 _IE1	=	0x008b
                           00008A   478 _IT1	=	0x008a
                           000089   479 _IE0	=	0x0089
                           000088   480 _IT0	=	0x0088
                           000087   481 _P07	=	0x0087
                           000087   482 _RXD	=	0x0087
                           000086   483 _P06	=	0x0086
                           000086   484 _TXD	=	0x0086
                           000085   485 _P05	=	0x0085
                           000084   486 _P04	=	0x0084
                           000084   487 _STADC	=	0x0084
                           000083   488 _P03	=	0x0083
                           000082   489 _P02	=	0x0082
                           000082   490 _RXD_1	=	0x0082
                           000081   491 _P01	=	0x0081
                           000081   492 _MISO	=	0x0081
                           000080   493 _P00	=	0x0080
                           000080   494 _MOSI	=	0x0080
                                    495 ;--------------------------------------------------------
                                    496 ; overlayable register banks
                                    497 ;--------------------------------------------------------
                                    498 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        499 	.ds 8
                                    500 ;--------------------------------------------------------
                                    501 ; internal ram data
                                    502 ;--------------------------------------------------------
                                    503 	.area DSEG    (DATA)
                                    504 ;--------------------------------------------------------
                                    505 ; overlayable items in internal ram
                                    506 ;--------------------------------------------------------
                                    507 	.area	OSEG    (OVR,DATA)
                                    508 	.area	OSEG    (OVR,DATA)
                                    509 	.area	OSEG    (OVR,DATA)
                                    510 	.area	OSEG    (OVR,DATA)
                                    511 ;--------------------------------------------------------
                                    512 ; indirectly addressable internal ram data
                                    513 ;--------------------------------------------------------
                                    514 	.area ISEG    (DATA)
                                    515 ;--------------------------------------------------------
                                    516 ; absolute internal ram data
                                    517 ;--------------------------------------------------------
                                    518 	.area IABS    (ABS,DATA)
                                    519 	.area IABS    (ABS,DATA)
                                    520 ;--------------------------------------------------------
                                    521 ; bit data
                                    522 ;--------------------------------------------------------
                                    523 	.area BSEG    (BIT)
      000000                        524 _BIT_TMP::
      000000                        525 	.ds 1
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
                                    569 ;Allocation info for local variables in function 'InitialUART0_Timer1'
                                    570 ;------------------------------------------------------------
                                    571 ;baudrate                  Allocated to registers r4 r5 r6 r7 
                                    572 ;------------------------------------------------------------
                                    573 ;	lib\N76E003\Common.c:6: void InitialUART0_Timer1(uint32_t baudrate) //T1M = 1, SMOD = 1
                                    574 ;	-----------------------------------------
                                    575 ;	 function InitialUART0_Timer1
                                    576 ;	-----------------------------------------
      0000D4                        577 _InitialUART0_Timer1:
                           000007   578 	ar7 = 0x07
                           000006   579 	ar6 = 0x06
                           000005   580 	ar5 = 0x05
                           000004   581 	ar4 = 0x04
                           000003   582 	ar3 = 0x03
                           000002   583 	ar2 = 0x02
                           000001   584 	ar1 = 0x01
                           000000   585 	ar0 = 0x00
      0000D4 AC 82            [24]  586 	mov	r4,dpl
      0000D6 AD 83            [24]  587 	mov	r5,dph
      0000D8 AE F0            [24]  588 	mov	r6,b
      0000DA FF               [12]  589 	mov	r7,a
                                    590 ;	lib\N76E003\Common.c:8: P06_Quasi_Mode;			//Setting UART pin as Quasi mode for transmit
      0000DB 53 B1 BF         [24]  591 	anl	_P0M1,#0xbf
      0000DE 53 B2 BF         [24]  592 	anl	_P0M2,#0xbf
                                    593 ;	lib\N76E003\Common.c:9: P07_Quasi_Mode;			//Setting UART pin as Quasi mode for transmit
      0000E1 53 B1 7F         [24]  594 	anl	_P0M1,#0x7f
      0000E4 53 B2 7F         [24]  595 	anl	_P0M2,#0x7f
                                    596 ;	lib\N76E003\Common.c:11: SCON = 0x50;			//UART0 Mode1,REN=1,TI=1
      0000E7 75 98 50         [24]  597 	mov	_SCON,#0x50
                                    598 ;	lib\N76E003\Common.c:12: TMOD |= 0x20;			//Timer1 Mode1
      0000EA 43 89 20         [24]  599 	orl	_TMOD,#0x20
                                    600 ;	lib\N76E003\Common.c:14: set_SMOD;				//UART0 Double Rate Enable
      0000ED 43 87 80         [24]  601 	orl	_PCON,#0x80
                                    602 ;	lib\N76E003\Common.c:15: set_T1M;
      0000F0 43 8E 10         [24]  603 	orl	_CKCON,#0x10
                                    604 ;	lib\N76E003\Common.c:16: clr_BRCK;				//Serial port 0 baud rate clock source = Timer1
      0000F3 53 C4 DF         [24]  605 	anl	_T3CON,#0xdf
                                    606 ;	lib\N76E003\Common.c:21: TH1 = 256 - (1037500/baudrate);
      0000F6 8C 44            [24]  607 	mov	__divulong_PARM_2,r4
      0000F8 8D 45            [24]  608 	mov	(__divulong_PARM_2 + 1),r5
      0000FA 8E 46            [24]  609 	mov	(__divulong_PARM_2 + 2),r6
      0000FC 8F 47            [24]  610 	mov	(__divulong_PARM_2 + 3),r7
      0000FE 90 D4 BC         [24]  611 	mov	dptr,#0xd4bc
      000101 75 F0 0F         [24]  612 	mov	b, #0x0f
      000104 E4               [12]  613 	clr	a
      000105 12 15 E3         [24]  614 	lcall	__divulong
      000108 AC 82            [24]  615 	mov	r4, dpl
      00010A C3               [12]  616 	clr	c
      00010B E4               [12]  617 	clr	a
      00010C 9C               [12]  618 	subb	a,r4
      00010D F5 8D            [12]  619 	mov	_TH1,a
                                    620 ;	lib\N76E003\Common.c:24: set_TR1;
                                    621 ;	assignBit
      00010F D2 8E            [12]  622 	setb	_TR1
                                    623 ;	lib\N76E003\Common.c:25: set_TI;					//For printf function must setting TI = 1
                                    624 ;	assignBit
      000111 D2 99            [12]  625 	setb	_TI
                                    626 ;	lib\N76E003\Common.c:26: }
      000113 22               [24]  627 	ret
                                    628 ;------------------------------------------------------------
                                    629 ;Allocation info for local variables in function 'InitialUART0_Timer3'
                                    630 ;------------------------------------------------------------
                                    631 ;baudrate                  Allocated to registers r4 r5 r6 r7 
                                    632 ;------------------------------------------------------------
                                    633 ;	lib\N76E003\Common.c:28: void InitialUART0_Timer3(uint32_t baudrate) //use timer3 as Baudrate generator
                                    634 ;	-----------------------------------------
                                    635 ;	 function InitialUART0_Timer3
                                    636 ;	-----------------------------------------
      000114                        637 _InitialUART0_Timer3:
      000114 AC 82            [24]  638 	mov	r4,dpl
      000116 AD 83            [24]  639 	mov	r5,dph
      000118 AE F0            [24]  640 	mov	r6,b
      00011A FF               [12]  641 	mov	r7,a
                                    642 ;	lib\N76E003\Common.c:30: P06_Quasi_Mode;			//Setting UART pin as Quasi mode for transmit
      00011B 53 B1 BF         [24]  643 	anl	_P0M1,#0xbf
      00011E 53 B2 BF         [24]  644 	anl	_P0M2,#0xbf
                                    645 ;	lib\N76E003\Common.c:31: P07_Quasi_Mode;			//Setting UART pin as Quasi mode for transmit	
      000121 53 B1 7F         [24]  646 	anl	_P0M1,#0x7f
      000124 53 B2 7F         [24]  647 	anl	_P0M2,#0x7f
                                    648 ;	lib\N76E003\Common.c:33: SCON = 0x50;			//UART0 Mode1,REN=1,TI=1
      000127 75 98 50         [24]  649 	mov	_SCON,#0x50
                                    650 ;	lib\N76E003\Common.c:34: set_SMOD;				//UART0 Double Rate Enable
      00012A 43 87 80         [24]  651 	orl	_PCON,#0x80
                                    652 ;	lib\N76E003\Common.c:35: T3CON &= 0xF8;			//T3PS2=0,T3PS1=0,T3PS0=0(Prescale=1)
      00012D 53 C4 F8         [24]  653 	anl	_T3CON,#0xf8
                                    654 ;	lib\N76E003\Common.c:36: set_BRCK;				//UART0 baud rate clock source = Timer3
      000130 43 C4 20         [24]  655 	orl	_T3CON,#0x20
                                    656 ;	lib\N76E003\Common.c:42: RH3 = HIBYTE(65536 - (1037500/baudrate));
      000133 8C 44            [24]  657 	mov	__divulong_PARM_2,r4
      000135 8D 45            [24]  658 	mov	(__divulong_PARM_2 + 1),r5
      000137 8E 46            [24]  659 	mov	(__divulong_PARM_2 + 2),r6
      000139 8F 47            [24]  660 	mov	(__divulong_PARM_2 + 3),r7
      00013B 90 D4 BC         [24]  661 	mov	dptr,#0xd4bc
      00013E 75 F0 0F         [24]  662 	mov	b, #0x0f
      000141 E4               [12]  663 	clr	a
      000142 12 15 E3         [24]  664 	lcall	__divulong
      000145 AC 82            [24]  665 	mov	r4, dpl
      000147 AD 83            [24]  666 	mov	r5, dph
      000149 AE F0            [24]  667 	mov	r6, b
      00014B FF               [12]  668 	mov	r7, a
      00014C E4               [12]  669 	clr	a
      00014D C3               [12]  670 	clr	c
      00014E 9C               [12]  671 	subb	a,r4
      00014F E4               [12]  672 	clr	a
      000150 9D               [12]  673 	subb	a,r5
      000151 F9               [12]  674 	mov	r1,a
      000152 74 01            [12]  675 	mov	a,#0x01
      000154 9E               [12]  676 	subb	a,r6
      000155 E4               [12]  677 	clr	a
      000156 9F               [12]  678 	subb	a,r7
      000157 89 C6            [24]  679 	mov	_RH3,r1
                                    680 ;	lib\N76E003\Common.c:43: RL3 = LOBYTE(65536 - (1037500/baudrate));
      000159 C3               [12]  681 	clr	c
      00015A E4               [12]  682 	clr	a
      00015B 9C               [12]  683 	subb	a,r4
      00015C FC               [12]  684 	mov	r4,a
      00015D 8C C5            [24]  685 	mov	_RL3,r4
                                    686 ;	lib\N76E003\Common.c:46: set_TR3;				//Trigger Timer3
      00015F 43 C4 08         [24]  687 	orl	_T3CON,#0x08
                                    688 ;	lib\N76E003\Common.c:47: set_TI;					//For printf function must setting TI = 1
                                    689 ;	assignBit
      000162 D2 99            [12]  690 	setb	_TI
                                    691 ;	lib\N76E003\Common.c:48: }
      000164 22               [24]  692 	ret
                                    693 ;------------------------------------------------------------
                                    694 ;Allocation info for local variables in function 'Receive_Data_From_UART0'
                                    695 ;------------------------------------------------------------
                                    696 ;c                         Allocated to registers 
                                    697 ;------------------------------------------------------------
                                    698 ;	lib\N76E003\Common.c:50: uint8_t Receive_Data_From_UART0(void)
                                    699 ;	-----------------------------------------
                                    700 ;	 function Receive_Data_From_UART0
                                    701 ;	-----------------------------------------
      000165                        702 _Receive_Data_From_UART0:
                                    703 ;	lib\N76E003\Common.c:53: while (!RI);
      000165                        704 00101$:
      000165 30 98 FD         [24]  705 	jnb	_RI,00101$
                                    706 ;	lib\N76E003\Common.c:54: c = SBUF;
      000168 85 99 82         [24]  707 	mov	dpl,_SBUF
                                    708 ;	lib\N76E003\Common.c:55: RI = 0;
                                    709 ;	assignBit
      00016B C2 98            [12]  710 	clr	_RI
                                    711 ;	lib\N76E003\Common.c:56: return (c);
                                    712 ;	lib\N76E003\Common.c:57: }
      00016D 22               [24]  713 	ret
                                    714 ;------------------------------------------------------------
                                    715 ;Allocation info for local variables in function 'Send_Data_To_UART0'
                                    716 ;------------------------------------------------------------
                                    717 ;c                         Allocated to registers r7 
                                    718 ;------------------------------------------------------------
                                    719 ;	lib\N76E003\Common.c:59: void Send_Data_To_UART0 (uint8_t c)
                                    720 ;	-----------------------------------------
                                    721 ;	 function Send_Data_To_UART0
                                    722 ;	-----------------------------------------
      00016E                        723 _Send_Data_To_UART0:
      00016E AF 82            [24]  724 	mov	r7, dpl
                                    725 ;	lib\N76E003\Common.c:61: TI = 0;
                                    726 ;	assignBit
      000170 C2 99            [12]  727 	clr	_TI
                                    728 ;	lib\N76E003\Common.c:62: SBUF = c;
      000172 8F 99            [24]  729 	mov	_SBUF,r7
                                    730 ;	lib\N76E003\Common.c:63: while(TI==0);
      000174                        731 00101$:
      000174 30 99 FD         [24]  732 	jnb	_TI,00101$
                                    733 ;	lib\N76E003\Common.c:64: }
      000177 22               [24]  734 	ret
                                    735 ;------------------------------------------------------------
                                    736 ;Allocation info for local variables in function 'InitialUART1_Timer3'
                                    737 ;------------------------------------------------------------
                                    738 ;baudrate                  Allocated to registers r4 r5 r6 r7 
                                    739 ;------------------------------------------------------------
                                    740 ;	lib\N76E003\Common.c:66: void InitialUART1_Timer3(uint32_t baudrate) //use timer3 as Baudrate generator
                                    741 ;	-----------------------------------------
                                    742 ;	 function InitialUART1_Timer3
                                    743 ;	-----------------------------------------
      000178                        744 _InitialUART1_Timer3:
      000178 AC 82            [24]  745 	mov	r4,dpl
      00017A AD 83            [24]  746 	mov	r5,dph
      00017C AE F0            [24]  747 	mov	r6,b
      00017E FF               [12]  748 	mov	r7,a
                                    749 ;	lib\N76E003\Common.c:68: P02_Quasi_Mode;			//Setting UART pin as Quasi mode for transmit
      00017F 53 B1 FB         [24]  750 	anl	_P0M1,#0xfb
      000182 53 B2 FB         [24]  751 	anl	_P0M2,#0xfb
                                    752 ;	lib\N76E003\Common.c:69: P16_Quasi_Mode;			//Setting UART pin as Quasi mode for transmit
      000185 53 B3 BF         [24]  753 	anl	_P1M1,#0xbf
      000188 53 B4 BF         [24]  754 	anl	_P1M2,#0xbf
                                    755 ;	lib\N76E003\Common.c:71: SCON_1 = 0x50;			//UART1 Mode1,REN_1=1,TI_1=1
      00018B 75 F8 50         [24]  756 	mov	_SCON_1,#0x50
                                    757 ;	lib\N76E003\Common.c:72: T3CON = 0x08;			//T3PS2=0,T3PS1=0,T3PS0=0(Prescale=1), UART1 in MODE 1
      00018E 75 C4 08         [24]  758 	mov	_T3CON,#0x08
                                    759 ;	lib\N76E003\Common.c:73: clr_BRCK;
      000191 53 C4 DF         [24]  760 	anl	_T3CON,#0xdf
                                    761 ;	lib\N76E003\Common.c:79: RH3 = HIBYTE(65536 - (1037500/baudrate));
      000194 8C 44            [24]  762 	mov	__divulong_PARM_2,r4
      000196 8D 45            [24]  763 	mov	(__divulong_PARM_2 + 1),r5
      000198 8E 46            [24]  764 	mov	(__divulong_PARM_2 + 2),r6
      00019A 8F 47            [24]  765 	mov	(__divulong_PARM_2 + 3),r7
      00019C 90 D4 BC         [24]  766 	mov	dptr,#0xd4bc
      00019F 75 F0 0F         [24]  767 	mov	b, #0x0f
      0001A2 E4               [12]  768 	clr	a
      0001A3 12 15 E3         [24]  769 	lcall	__divulong
      0001A6 AC 82            [24]  770 	mov	r4, dpl
      0001A8 AD 83            [24]  771 	mov	r5, dph
      0001AA AE F0            [24]  772 	mov	r6, b
      0001AC FF               [12]  773 	mov	r7, a
      0001AD E4               [12]  774 	clr	a
      0001AE C3               [12]  775 	clr	c
      0001AF 9C               [12]  776 	subb	a,r4
      0001B0 E4               [12]  777 	clr	a
      0001B1 9D               [12]  778 	subb	a,r5
      0001B2 F9               [12]  779 	mov	r1,a
      0001B3 74 01            [12]  780 	mov	a,#0x01
      0001B5 9E               [12]  781 	subb	a,r6
      0001B6 E4               [12]  782 	clr	a
      0001B7 9F               [12]  783 	subb	a,r7
      0001B8 89 C6            [24]  784 	mov	_RH3,r1
                                    785 ;	lib\N76E003\Common.c:80: RL3 = LOBYTE(65536 - (1037500/baudrate));
      0001BA C3               [12]  786 	clr	c
      0001BB E4               [12]  787 	clr	a
      0001BC 9C               [12]  788 	subb	a,r4
      0001BD FC               [12]  789 	mov	r4,a
      0001BE 8C C5            [24]  790 	mov	_RL3,r4
                                    791 ;	lib\N76E003\Common.c:83: set_TR3;				//Trigger Timer3
      0001C0 43 C4 08         [24]  792 	orl	_T3CON,#0x08
                                    793 ;	lib\N76E003\Common.c:84: }
      0001C3 22               [24]  794 	ret
                                    795 ;------------------------------------------------------------
                                    796 ;Allocation info for local variables in function 'Receive_Data_From_UART1'
                                    797 ;------------------------------------------------------------
                                    798 ;c                         Allocated to registers 
                                    799 ;------------------------------------------------------------
                                    800 ;	lib\N76E003\Common.c:86: uint8_t Receive_Data_From_UART1(void)
                                    801 ;	-----------------------------------------
                                    802 ;	 function Receive_Data_From_UART1
                                    803 ;	-----------------------------------------
      0001C4                        804 _Receive_Data_From_UART1:
                                    805 ;	lib\N76E003\Common.c:89: while (!RI_1);
      0001C4                        806 00101$:
      0001C4 30 F8 FD         [24]  807 	jnb	_RI_1,00101$
                                    808 ;	lib\N76E003\Common.c:90: c = SBUF_1;
      0001C7 85 9A 82         [24]  809 	mov	dpl,_SBUF_1
                                    810 ;	lib\N76E003\Common.c:91: RI_1 = 0;
                                    811 ;	assignBit
      0001CA C2 F8            [12]  812 	clr	_RI_1
                                    813 ;	lib\N76E003\Common.c:92: return (c);
                                    814 ;	lib\N76E003\Common.c:93: }
      0001CC 22               [24]  815 	ret
                                    816 ;------------------------------------------------------------
                                    817 ;Allocation info for local variables in function 'Send_Data_To_UART1'
                                    818 ;------------------------------------------------------------
                                    819 ;c                         Allocated to registers r7 
                                    820 ;------------------------------------------------------------
                                    821 ;	lib\N76E003\Common.c:95: void Send_Data_To_UART1 (uint8_t c)
                                    822 ;	-----------------------------------------
                                    823 ;	 function Send_Data_To_UART1
                                    824 ;	-----------------------------------------
      0001CD                        825 _Send_Data_To_UART1:
      0001CD AF 82            [24]  826 	mov	r7, dpl
                                    827 ;	lib\N76E003\Common.c:97: TI_1 = 0;
                                    828 ;	assignBit
      0001CF C2 F9            [12]  829 	clr	_TI_1
                                    830 ;	lib\N76E003\Common.c:98: SBUF_1 = c;
      0001D1 8F 9A            [24]  831 	mov	_SBUF_1,r7
                                    832 ;	lib\N76E003\Common.c:99: while(TI_1==0);
      0001D3                        833 00101$:
      0001D3 30 F9 FD         [24]  834 	jnb	_TI_1,00101$
                                    835 ;	lib\N76E003\Common.c:100: }
      0001D6 22               [24]  836 	ret
                                    837 	.area CSEG    (CODE)
                                    838 	.area CONST   (CODE)
                                    839 	.area XINIT   (CODE)
                                    840 	.area CABS    (ABS,CODE)
