                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ISO C Compiler
                                      3 ; Version 4.5.10 #15664 (MINGW32)
                                      4 ;--------------------------------------------------------
                                      5 	.module Common
                                      6 	
                                      7 	.optsdcc -mmcs51 --model-small
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl __sdcc_external_startup
                                     12 	.globl _MOSI
                                     13 	.globl _P00
                                     14 	.globl _MISO
                                     15 	.globl _P01
                                     16 	.globl _RXD_1
                                     17 	.globl _P02
                                     18 	.globl _P03
                                     19 	.globl _STADC
                                     20 	.globl _P04
                                     21 	.globl _P05
                                     22 	.globl _TXD
                                     23 	.globl _P06
                                     24 	.globl _RXD
                                     25 	.globl _P07
                                     26 	.globl _IT0
                                     27 	.globl _IE0
                                     28 	.globl _IT1
                                     29 	.globl _IE1
                                     30 	.globl _TR0
                                     31 	.globl _TF0
                                     32 	.globl _TR1
                                     33 	.globl _TF1
                                     34 	.globl _P10
                                     35 	.globl _P11
                                     36 	.globl _P12
                                     37 	.globl _SCL
                                     38 	.globl _P13
                                     39 	.globl _SDA
                                     40 	.globl _P14
                                     41 	.globl _P15
                                     42 	.globl _TXD_1
                                     43 	.globl _P16
                                     44 	.globl _P17
                                     45 	.globl _RI
                                     46 	.globl _TI
                                     47 	.globl _RB8
                                     48 	.globl _TB8
                                     49 	.globl _REN
                                     50 	.globl _SM2
                                     51 	.globl _SM1
                                     52 	.globl _FE
                                     53 	.globl _SM0
                                     54 	.globl _P20
                                     55 	.globl _EX0
                                     56 	.globl _ET0
                                     57 	.globl _EX1
                                     58 	.globl _ET1
                                     59 	.globl _ES
                                     60 	.globl _EBOD
                                     61 	.globl _EADC
                                     62 	.globl _EA
                                     63 	.globl _P30
                                     64 	.globl _PX0
                                     65 	.globl _PT0
                                     66 	.globl _PX1
                                     67 	.globl _PT1
                                     68 	.globl _PS
                                     69 	.globl _PBOD
                                     70 	.globl _PADC
                                     71 	.globl _I2CPX
                                     72 	.globl _AA
                                     73 	.globl _SI
                                     74 	.globl _STO
                                     75 	.globl _STA
                                     76 	.globl _I2CEN
                                     77 	.globl _CM_RL2
                                     78 	.globl _TR2
                                     79 	.globl _TF2
                                     80 	.globl _P
                                     81 	.globl _OV
                                     82 	.globl _RS0
                                     83 	.globl _RS1
                                     84 	.globl _F0
                                     85 	.globl _AC
                                     86 	.globl _CY
                                     87 	.globl _CLRPWM
                                     88 	.globl _PWMF
                                     89 	.globl _LOAD
                                     90 	.globl _PWMRUN
                                     91 	.globl _ADCHS0
                                     92 	.globl _ADCHS1
                                     93 	.globl _ADCHS2
                                     94 	.globl _ADCHS3
                                     95 	.globl _ETGSEL0
                                     96 	.globl _ETGSEL1
                                     97 	.globl _ADCS
                                     98 	.globl _ADCF
                                     99 	.globl _RI_1
                                    100 	.globl _TI_1
                                    101 	.globl _RB8_1
                                    102 	.globl _TB8_1
                                    103 	.globl _REN_1
                                    104 	.globl _SM2_1
                                    105 	.globl _SM1_1
                                    106 	.globl _FE_1
                                    107 	.globl _SM0_1
                                    108 	.globl _EIPH1
                                    109 	.globl _EIP1
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
                                    244 	.globl _InitialUART0_Timer1
                                    245 	.globl _InitialUART0_Timer3
                                    246 	.globl _Receive_Data_From_UART0
                                    247 	.globl _Send_Data_To_UART0
                                    248 	.globl _InitialUART1_Timer3
                                    249 	.globl _Receive_Data_From_UART1
                                    250 	.globl _Send_Data_To_UART1
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
                           0000FE   390 _EIP1	=	0x00fe
                           0000FF   391 _EIPH1	=	0x00ff
                                    392 ;--------------------------------------------------------
                                    393 ; special function bits
                                    394 ;--------------------------------------------------------
                                    395 	.area RSEG    (ABS,DATA)
      000000                        396 	.org 0x0000
                           0000FF   397 _SM0_1	=	0x00ff
                           0000FF   398 _FE_1	=	0x00ff
                           0000FE   399 _SM1_1	=	0x00fe
                           0000FD   400 _SM2_1	=	0x00fd
                           0000FC   401 _REN_1	=	0x00fc
                           0000FB   402 _TB8_1	=	0x00fb
                           0000FA   403 _RB8_1	=	0x00fa
                           0000F9   404 _TI_1	=	0x00f9
                           0000F8   405 _RI_1	=	0x00f8
                           0000EF   406 _ADCF	=	0x00ef
                           0000EE   407 _ADCS	=	0x00ee
                           0000ED   408 _ETGSEL1	=	0x00ed
                           0000EC   409 _ETGSEL0	=	0x00ec
                           0000EB   410 _ADCHS3	=	0x00eb
                           0000EA   411 _ADCHS2	=	0x00ea
                           0000E9   412 _ADCHS1	=	0x00e9
                           0000E8   413 _ADCHS0	=	0x00e8
                           0000DF   414 _PWMRUN	=	0x00df
                           0000DE   415 _LOAD	=	0x00de
                           0000DD   416 _PWMF	=	0x00dd
                           0000DC   417 _CLRPWM	=	0x00dc
                           0000D7   418 _CY	=	0x00d7
                           0000D6   419 _AC	=	0x00d6
                           0000D5   420 _F0	=	0x00d5
                           0000D4   421 _RS1	=	0x00d4
                           0000D3   422 _RS0	=	0x00d3
                           0000D2   423 _OV	=	0x00d2
                           0000D0   424 _P	=	0x00d0
                           0000CF   425 _TF2	=	0x00cf
                           0000CA   426 _TR2	=	0x00ca
                           0000C8   427 _CM_RL2	=	0x00c8
                           0000C6   428 _I2CEN	=	0x00c6
                           0000C5   429 _STA	=	0x00c5
                           0000C4   430 _STO	=	0x00c4
                           0000C3   431 _SI	=	0x00c3
                           0000C2   432 _AA	=	0x00c2
                           0000C0   433 _I2CPX	=	0x00c0
                           0000BE   434 _PADC	=	0x00be
                           0000BD   435 _PBOD	=	0x00bd
                           0000BC   436 _PS	=	0x00bc
                           0000BB   437 _PT1	=	0x00bb
                           0000BA   438 _PX1	=	0x00ba
                           0000B9   439 _PT0	=	0x00b9
                           0000B8   440 _PX0	=	0x00b8
                           0000B0   441 _P30	=	0x00b0
                           0000AF   442 _EA	=	0x00af
                           0000AE   443 _EADC	=	0x00ae
                           0000AD   444 _EBOD	=	0x00ad
                           0000AC   445 _ES	=	0x00ac
                           0000AB   446 _ET1	=	0x00ab
                           0000AA   447 _EX1	=	0x00aa
                           0000A9   448 _ET0	=	0x00a9
                           0000A8   449 _EX0	=	0x00a8
                           0000A0   450 _P20	=	0x00a0
                           00009F   451 _SM0	=	0x009f
                           00009F   452 _FE	=	0x009f
                           00009E   453 _SM1	=	0x009e
                           00009D   454 _SM2	=	0x009d
                           00009C   455 _REN	=	0x009c
                           00009B   456 _TB8	=	0x009b
                           00009A   457 _RB8	=	0x009a
                           000099   458 _TI	=	0x0099
                           000098   459 _RI	=	0x0098
                           000097   460 _P17	=	0x0097
                           000096   461 _P16	=	0x0096
                           000096   462 _TXD_1	=	0x0096
                           000095   463 _P15	=	0x0095
                           000094   464 _P14	=	0x0094
                           000094   465 _SDA	=	0x0094
                           000093   466 _P13	=	0x0093
                           000093   467 _SCL	=	0x0093
                           000092   468 _P12	=	0x0092
                           000091   469 _P11	=	0x0091
                           000090   470 _P10	=	0x0090
                           00008F   471 _TF1	=	0x008f
                           00008E   472 _TR1	=	0x008e
                           00008D   473 _TF0	=	0x008d
                           00008C   474 _TR0	=	0x008c
                           00008B   475 _IE1	=	0x008b
                           00008A   476 _IT1	=	0x008a
                           000089   477 _IE0	=	0x0089
                           000088   478 _IT0	=	0x0088
                           000087   479 _P07	=	0x0087
                           000087   480 _RXD	=	0x0087
                           000086   481 _P06	=	0x0086
                           000086   482 _TXD	=	0x0086
                           000085   483 _P05	=	0x0085
                           000084   484 _P04	=	0x0084
                           000084   485 _STADC	=	0x0084
                           000083   486 _P03	=	0x0083
                           000082   487 _P02	=	0x0082
                           000082   488 _RXD_1	=	0x0082
                           000081   489 _P01	=	0x0081
                           000081   490 _MISO	=	0x0081
                           000080   491 _P00	=	0x0080
                           000080   492 _MOSI	=	0x0080
                                    493 ;--------------------------------------------------------
                                    494 ; overlayable register banks
                                    495 ;--------------------------------------------------------
                                    496 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        497 	.ds 8
                                    498 ;--------------------------------------------------------
                                    499 ; internal ram data
                                    500 ;--------------------------------------------------------
                                    501 	.area DSEG    (DATA)
                                    502 ;--------------------------------------------------------
                                    503 ; overlayable items in internal ram
                                    504 ;--------------------------------------------------------
                                    505 	.area	OSEG    (OVR,DATA)
                                    506 	.area	OSEG    (OVR,DATA)
                                    507 	.area	OSEG    (OVR,DATA)
                                    508 	.area	OSEG    (OVR,DATA)
                                    509 ;--------------------------------------------------------
                                    510 ; indirectly addressable internal ram data
                                    511 ;--------------------------------------------------------
                                    512 	.area ISEG    (DATA)
                                    513 ;--------------------------------------------------------
                                    514 ; absolute internal ram data
                                    515 ;--------------------------------------------------------
                                    516 	.area IABS    (ABS,DATA)
                                    517 	.area IABS    (ABS,DATA)
                                    518 ;--------------------------------------------------------
                                    519 ; bit data
                                    520 ;--------------------------------------------------------
                                    521 	.area BSEG    (BIT)
                                    522 ;--------------------------------------------------------
                                    523 ; paged external ram data
                                    524 ;--------------------------------------------------------
                                    525 	.area PSEG    (PAG,XDATA)
                                    526 ;--------------------------------------------------------
                                    527 ; uninitialized external ram data
                                    528 ;--------------------------------------------------------
                                    529 	.area XSEG    (XDATA)
                                    530 ;--------------------------------------------------------
                                    531 ; absolute external ram data
                                    532 ;--------------------------------------------------------
                                    533 	.area XABS    (ABS,XDATA)
                                    534 ;--------------------------------------------------------
                                    535 ; initialized external ram data
                                    536 ;--------------------------------------------------------
                                    537 	.area HOME    (CODE)
                                    538 	.area GSINIT0 (CODE)
                                    539 	.area GSINIT1 (CODE)
                                    540 	.area GSINIT2 (CODE)
                                    541 	.area GSINIT3 (CODE)
                                    542 	.area GSINIT4 (CODE)
                                    543 	.area GSINIT5 (CODE)
                                    544 	.area GSINIT  (CODE)
                                    545 	.area GSFINAL (CODE)
                                    546 	.area CSEG    (CODE)
                                    547 ;--------------------------------------------------------
                                    548 ; global & static initialisations
                                    549 ;--------------------------------------------------------
                                    550 	.area HOME    (CODE)
                                    551 	.area GSINIT  (CODE)
                                    552 	.area GSFINAL (CODE)
                                    553 	.area GSINIT  (CODE)
                                    554 ;--------------------------------------------------------
                                    555 ; Home
                                    556 ;--------------------------------------------------------
                                    557 	.area HOME    (CODE)
                                    558 	.area HOME    (CODE)
                                    559 ;--------------------------------------------------------
                                    560 ; code
                                    561 ;--------------------------------------------------------
                                    562 	.area CSEG    (CODE)
                                    563 ;------------------------------------------------------------
                                    564 ;Allocation info for local variables in function 'InitialUART0_Timer1'
                                    565 ;------------------------------------------------------------
                                    566 ;u32Baudrate   Allocated to registers r4 r5 r6 r7 
                                    567 ;------------------------------------------------------------
                                    568 ;	lib/Common.c:23: void InitialUART0_Timer1(UINT32 u32Baudrate)    //T1M = 1, SMOD = 1
                                    569 ;	-----------------------------------------
                                    570 ;	 function InitialUART0_Timer1
                                    571 ;	-----------------------------------------
      000566                        572 _InitialUART0_Timer1:
                           000007   573 	ar7 = 0x07
                           000006   574 	ar6 = 0x06
                           000005   575 	ar5 = 0x05
                           000004   576 	ar4 = 0x04
                           000003   577 	ar3 = 0x03
                           000002   578 	ar2 = 0x02
                           000001   579 	ar1 = 0x01
                           000000   580 	ar0 = 0x00
      000566 AC 82            [24]  581 	mov	r4,dpl
      000568 AD 83            [24]  582 	mov	r5,dph
      00056A AE F0            [24]  583 	mov	r6,b
      00056C FF               [12]  584 	mov	r7,a
                                    585 ;	lib/Common.c:25: P06_Quasi_Mode;		//Setting UART pin as Quasi mode for transmit
      00056D 53 B1 BF         [24]  586 	anl	_P0M1,#0xbf
      000570 53 B2 BF         [24]  587 	anl	_P0M2,#0xbf
                                    588 ;	lib/Common.c:26: P07_Quasi_Mode;		//Setting UART pin as Quasi mode for transmit
      000573 53 B1 7F         [24]  589 	anl	_P0M1,#0x7f
      000576 53 B2 7F         [24]  590 	anl	_P0M2,#0x7f
                                    591 ;	lib/Common.c:28: SCON = 0x50;     	//UART0 Mode1,REN=1,TI=1
      000579 75 98 50         [24]  592 	mov	_SCON,#0x50
                                    593 ;	lib/Common.c:29: TMOD |= 0x20;    	//Timer1 Mode1
      00057C 43 89 20         [24]  594 	orl	_TMOD,#0x20
                                    595 ;	lib/Common.c:31: set_SMOD;        	//UART0 Double Rate Enable
      00057F 43 87 80         [24]  596 	orl	_PCON,#0x80
                                    597 ;	lib/Common.c:32: set_T1M;
      000582 43 8E 10         [24]  598 	orl	_CKCON,#0x10
                                    599 ;	lib/Common.c:33: clr_BRCK;        	//Serial port 0 baud rate clock source = Timer1
      000585 53 C4 DF         [24]  600 	anl	_T3CON,#0xdf
                                    601 ;	lib/Common.c:36: TH1 = 256 - (1000000/u32Baudrate+1);               /*16 MHz */
      000588 8C 17            [24]  602 	mov	__divulong_PARM_2,r4
      00058A 8D 18            [24]  603 	mov	(__divulong_PARM_2 + 1),r5
      00058C 8E 19            [24]  604 	mov	(__divulong_PARM_2 + 2),r6
      00058E 8F 1A            [24]  605 	mov	(__divulong_PARM_2 + 3),r7
      000590 90 42 40         [24]  606 	mov	dptr,#0x4240
      000593 75 F0 0F         [24]  607 	mov	b, #0x0f
      000596 E4               [12]  608 	clr	a
      000597 12 06 82         [24]  609 	lcall	__divulong
      00059A AC 82            [24]  610 	mov	r4, dpl
      00059C 0C               [12]  611 	inc	r4
      00059D C3               [12]  612 	clr	c
      00059E E4               [12]  613 	clr	a
      00059F 9C               [12]  614 	subb	a,r4
      0005A0 F5 8D            [12]  615 	mov	_TH1,a
                                    616 ;	lib/Common.c:41: set_TR1;
                                    617 ;	assignBit
      0005A2 D2 8E            [12]  618 	setb	_TR1
                                    619 ;	lib/Common.c:42: set_TI;						//For printf function must setting TI = 1
                                    620 ;	assignBit
      0005A4 D2 99            [12]  621 	setb	_TI
                                    622 ;	lib/Common.c:43: }
      0005A6 22               [24]  623 	ret
                                    624 ;------------------------------------------------------------
                                    625 ;Allocation info for local variables in function 'InitialUART0_Timer3'
                                    626 ;------------------------------------------------------------
                                    627 ;u32Baudrate   Allocated to registers r4 r5 r6 r7 
                                    628 ;------------------------------------------------------------
                                    629 ;	lib/Common.c:45: void InitialUART0_Timer3(UINT32 u32Baudrate) //use timer3 as Baudrate generator
                                    630 ;	-----------------------------------------
                                    631 ;	 function InitialUART0_Timer3
                                    632 ;	-----------------------------------------
      0005A7                        633 _InitialUART0_Timer3:
      0005A7 AC 82            [24]  634 	mov	r4,dpl
      0005A9 AD 83            [24]  635 	mov	r5,dph
      0005AB AE F0            [24]  636 	mov	r6,b
      0005AD FF               [12]  637 	mov	r7,a
                                    638 ;	lib/Common.c:47: P06_Quasi_Mode;		//Setting UART pin as Quasi mode for transmit
      0005AE 53 B1 BF         [24]  639 	anl	_P0M1,#0xbf
      0005B1 53 B2 BF         [24]  640 	anl	_P0M2,#0xbf
                                    641 ;	lib/Common.c:48: P07_Quasi_Mode;		//Setting UART pin as Quasi mode for transmit	
      0005B4 53 B1 7F         [24]  642 	anl	_P0M1,#0x7f
      0005B7 53 B2 7F         [24]  643 	anl	_P0M2,#0x7f
                                    644 ;	lib/Common.c:50: SCON = 0x50;     //UART0 Mode1,REN=1,TI=1
      0005BA 75 98 50         [24]  645 	mov	_SCON,#0x50
                                    646 ;	lib/Common.c:51: set_SMOD;        //UART0 Double Rate Enable
      0005BD 43 87 80         [24]  647 	orl	_PCON,#0x80
                                    648 ;	lib/Common.c:52: T3CON &= 0xF8;   //T3PS2=0,T3PS1=0,T3PS0=0(Prescale=1)
      0005C0 53 C4 F8         [24]  649 	anl	_T3CON,#0xf8
                                    650 ;	lib/Common.c:53: set_BRCK;        //UART0 baud rate clock source = Timer3
      0005C3 43 C4 20         [24]  651 	orl	_T3CON,#0x20
                                    652 ;	lib/Common.c:56: RH3    = HIBYTE(65536 - (1000000/u32Baudrate)-1);  		/*16 MHz */
      0005C6 8C 17            [24]  653 	mov	__divulong_PARM_2,r4
      0005C8 8D 18            [24]  654 	mov	(__divulong_PARM_2 + 1),r5
      0005CA 8E 19            [24]  655 	mov	(__divulong_PARM_2 + 2),r6
      0005CC 8F 1A            [24]  656 	mov	(__divulong_PARM_2 + 3),r7
      0005CE 90 42 40         [24]  657 	mov	dptr,#0x4240
      0005D1 75 F0 0F         [24]  658 	mov	b, #0x0f
      0005D4 E4               [12]  659 	clr	a
      0005D5 12 06 82         [24]  660 	lcall	__divulong
      0005D8 AC 82            [24]  661 	mov	r4, dpl
      0005DA AD 83            [24]  662 	mov	r5, dph
      0005DC AE F0            [24]  663 	mov	r6, b
      0005DE FF               [12]  664 	mov	r7, a
      0005DF 74 FF            [12]  665 	mov	a,#0xff
      0005E1 C3               [12]  666 	clr	c
      0005E2 9C               [12]  667 	subb	a,r4
      0005E3 74 FF            [12]  668 	mov	a,#0xff
      0005E5 9D               [12]  669 	subb	a,r5
      0005E6 F9               [12]  670 	mov	r1,a
      0005E7 E4               [12]  671 	clr	a
      0005E8 9E               [12]  672 	subb	a,r6
      0005E9 E4               [12]  673 	clr	a
      0005EA 9F               [12]  674 	subb	a,r7
      0005EB 89 C6            [24]  675 	mov	_RH3,r1
                                    676 ;	lib/Common.c:57: RL3    = LOBYTE(65536 - (1000000/u32Baudrate)-1);			/*16 MHz */
      0005ED 74 FF            [12]  677 	mov	a,#0xff
      0005EF C3               [12]  678 	clr	c
      0005F0 9C               [12]  679 	subb	a,r4
      0005F1 F5 C5            [12]  680 	mov	_RL3, a
                                    681 ;	lib/Common.c:63: set_TR3;         //Trigger Timer3
      0005F3 43 C4 08         [24]  682 	orl	_T3CON,#0x08
                                    683 ;	lib/Common.c:64: set_TI;					 //For printf function must setting TI = 1
                                    684 ;	assignBit
      0005F6 D2 99            [12]  685 	setb	_TI
                                    686 ;	lib/Common.c:65: }
      0005F8 22               [24]  687 	ret
                                    688 ;------------------------------------------------------------
                                    689 ;Allocation info for local variables in function 'Receive_Data_From_UART0'
                                    690 ;------------------------------------------------------------
                                    691 ;c             Allocated to registers 
                                    692 ;------------------------------------------------------------
                                    693 ;	lib/Common.c:67: UINT8 Receive_Data_From_UART0(void)
                                    694 ;	-----------------------------------------
                                    695 ;	 function Receive_Data_From_UART0
                                    696 ;	-----------------------------------------
      0005F9                        697 _Receive_Data_From_UART0:
                                    698 ;	lib/Common.c:70: while (!RI);
      0005F9                        699 00101$:
      0005F9 30 98 FD         [24]  700 	jnb	_RI,00101$
                                    701 ;	lib/Common.c:71: c = SBUF;
      0005FC 85 99 82         [24]  702 	mov	dpl,_SBUF
                                    703 ;	lib/Common.c:72: RI = 0;
                                    704 ;	assignBit
      0005FF C2 98            [12]  705 	clr	_RI
                                    706 ;	lib/Common.c:73: return (c);
                                    707 ;	lib/Common.c:74: }
      000601 22               [24]  708 	ret
                                    709 ;------------------------------------------------------------
                                    710 ;Allocation info for local variables in function 'Send_Data_To_UART0'
                                    711 ;------------------------------------------------------------
                                    712 ;c             Allocated to registers r7 
                                    713 ;------------------------------------------------------------
                                    714 ;	lib/Common.c:76: void Send_Data_To_UART0 (UINT8 c)
                                    715 ;	-----------------------------------------
                                    716 ;	 function Send_Data_To_UART0
                                    717 ;	-----------------------------------------
      000602                        718 _Send_Data_To_UART0:
      000602 AF 82            [24]  719 	mov	r7, dpl
                                    720 ;	lib/Common.c:78: TI = 0;
                                    721 ;	assignBit
      000604 C2 99            [12]  722 	clr	_TI
                                    723 ;	lib/Common.c:79: SBUF = c;
      000606 8F 99            [24]  724 	mov	_SBUF,r7
                                    725 ;	lib/Common.c:80: while(TI==0);
      000608                        726 00101$:
      000608 30 99 FD         [24]  727 	jnb	_TI,00101$
                                    728 ;	lib/Common.c:81: }
      00060B 22               [24]  729 	ret
                                    730 ;------------------------------------------------------------
                                    731 ;Allocation info for local variables in function 'InitialUART1_Timer3'
                                    732 ;------------------------------------------------------------
                                    733 ;u32Baudrate   Allocated to registers r4 r5 r6 r7 
                                    734 ;------------------------------------------------------------
                                    735 ;	lib/Common.c:87: void InitialUART1_Timer3(UINT32 u32Baudrate) //use timer3 as Baudrate generator
                                    736 ;	-----------------------------------------
                                    737 ;	 function InitialUART1_Timer3
                                    738 ;	-----------------------------------------
      00060C                        739 _InitialUART1_Timer3:
      00060C AC 82            [24]  740 	mov	r4,dpl
      00060E AD 83            [24]  741 	mov	r5,dph
      000610 AE F0            [24]  742 	mov	r6,b
      000612 FF               [12]  743 	mov	r7,a
                                    744 ;	lib/Common.c:89: P02_Quasi_Mode;		//Setting UART pin as Quasi mode for transmit
      000613 53 B1 FB         [24]  745 	anl	_P0M1,#0xfb
      000616 53 B2 FB         [24]  746 	anl	_P0M2,#0xfb
                                    747 ;	lib/Common.c:90: P16_Quasi_Mode;		//Setting UART pin as Quasi mode for transmit
      000619 53 B3 BF         [24]  748 	anl	_P1M1,#0xbf
      00061C 53 B4 BF         [24]  749 	anl	_P1M2,#0xbf
                                    750 ;	lib/Common.c:92: SCON_1 = 0x50;   	//UART1 Mode1,REN_1=1,TI_1=1
      00061F 75 F8 50         [24]  751 	mov	_SCON_1,#0x50
                                    752 ;	lib/Common.c:93: T3CON = 0x08;   	//T3PS2=0,T3PS1=0,T3PS0=0(Prescale=1), UART1 in MODE 1
      000622 75 C4 08         [24]  753 	mov	_T3CON,#0x08
                                    754 ;	lib/Common.c:94: clr_BRCK;
      000625 53 C4 DF         [24]  755 	anl	_T3CON,#0xdf
                                    756 ;	lib/Common.c:97: RH3    = HIBYTE(65536 - (1000000/u32Baudrate)-1);  		/*16 MHz */
      000628 8C 17            [24]  757 	mov	__divulong_PARM_2,r4
      00062A 8D 18            [24]  758 	mov	(__divulong_PARM_2 + 1),r5
      00062C 8E 19            [24]  759 	mov	(__divulong_PARM_2 + 2),r6
      00062E 8F 1A            [24]  760 	mov	(__divulong_PARM_2 + 3),r7
      000630 90 42 40         [24]  761 	mov	dptr,#0x4240
      000633 75 F0 0F         [24]  762 	mov	b, #0x0f
      000636 E4               [12]  763 	clr	a
      000637 12 06 82         [24]  764 	lcall	__divulong
      00063A AC 82            [24]  765 	mov	r4, dpl
      00063C AD 83            [24]  766 	mov	r5, dph
      00063E AE F0            [24]  767 	mov	r6, b
      000640 FF               [12]  768 	mov	r7, a
      000641 74 FF            [12]  769 	mov	a,#0xff
      000643 C3               [12]  770 	clr	c
      000644 9C               [12]  771 	subb	a,r4
      000645 74 FF            [12]  772 	mov	a,#0xff
      000647 9D               [12]  773 	subb	a,r5
      000648 F9               [12]  774 	mov	r1,a
      000649 E4               [12]  775 	clr	a
      00064A 9E               [12]  776 	subb	a,r6
      00064B E4               [12]  777 	clr	a
      00064C 9F               [12]  778 	subb	a,r7
      00064D 89 C6            [24]  779 	mov	_RH3,r1
                                    780 ;	lib/Common.c:98: RL3    = LOBYTE(65536 - (1000000/u32Baudrate)-1);			/*16 MHz */
      00064F 74 FF            [12]  781 	mov	a,#0xff
      000651 C3               [12]  782 	clr	c
      000652 9C               [12]  783 	subb	a,r4
      000653 F5 C5            [12]  784 	mov	_RL3, a
                                    785 ;	lib/Common.c:104: set_TR3;         //Trigger Timer3
      000655 43 C4 08         [24]  786 	orl	_T3CON,#0x08
                                    787 ;	lib/Common.c:105: }
      000658 22               [24]  788 	ret
                                    789 ;------------------------------------------------------------
                                    790 ;Allocation info for local variables in function 'Receive_Data_From_UART1'
                                    791 ;------------------------------------------------------------
                                    792 ;c             Allocated to registers 
                                    793 ;------------------------------------------------------------
                                    794 ;	lib/Common.c:107: UINT8 Receive_Data_From_UART1(void)
                                    795 ;	-----------------------------------------
                                    796 ;	 function Receive_Data_From_UART1
                                    797 ;	-----------------------------------------
      000659                        798 _Receive_Data_From_UART1:
                                    799 ;	lib/Common.c:111: while (!RI_1);
      000659                        800 00101$:
      000659 30 F8 FD         [24]  801 	jnb	_RI_1,00101$
                                    802 ;	lib/Common.c:112: c = SBUF_1;
      00065C 85 9A 82         [24]  803 	mov	dpl,_SBUF_1
                                    804 ;	lib/Common.c:113: RI_1 = 0;
                                    805 ;	assignBit
      00065F C2 F8            [12]  806 	clr	_RI_1
                                    807 ;	lib/Common.c:114: return (c);
                                    808 ;	lib/Common.c:115: }
      000661 22               [24]  809 	ret
                                    810 ;------------------------------------------------------------
                                    811 ;Allocation info for local variables in function 'Send_Data_To_UART1'
                                    812 ;------------------------------------------------------------
                                    813 ;c             Allocated to registers r7 
                                    814 ;------------------------------------------------------------
                                    815 ;	lib/Common.c:117: void Send_Data_To_UART1 (UINT8 c)
                                    816 ;	-----------------------------------------
                                    817 ;	 function Send_Data_To_UART1
                                    818 ;	-----------------------------------------
      000662                        819 _Send_Data_To_UART1:
      000662 AF 82            [24]  820 	mov	r7, dpl
                                    821 ;	lib/Common.c:119: TI_1 = 0;
                                    822 ;	assignBit
      000664 C2 F9            [12]  823 	clr	_TI_1
                                    824 ;	lib/Common.c:120: SBUF_1 = c;
      000666 8F 9A            [24]  825 	mov	_SBUF_1,r7
                                    826 ;	lib/Common.c:121: while(TI_1==0);
      000668                        827 00101$:
      000668 30 F9 FD         [24]  828 	jnb	_TI_1,00101$
                                    829 ;	lib/Common.c:122: }
      00066B 22               [24]  830 	ret
                                    831 ;------------------------------------------------------------
                                    832 ;Allocation info for local variables in function '_sdcc_external_startup'
                                    833 ;------------------------------------------------------------
                                    834 ;	lib/Common.c:135: _sdcc_external_startup (void)
                                    835 ;	-----------------------------------------
                                    836 ;	 function _sdcc_external_startup
                                    837 ;	-----------------------------------------
      00066C                        838 __sdcc_external_startup:
                                    839 ;	lib/Common.c:144: __endasm;
      00066C 75 C7 AA         [24]  840 	mov	0xC7, #0xAA
      00066F 75 C7 55         [24]  841 	mov	0xC7, #0x55
      000672 75 FD 5A         [24]  842 	mov	0xFD, #0x5A
      000675 75 C7 AA         [24]  843 	mov	0xC7, #0xAA
      000678 75 C7 55         [24]  844 	mov	0xC7, #0x55
      00067B 75 FD A5         [24]  845 	mov	0xFD, #0xA5
                                    846 ;	lib/Common.c:145: return 0;
      00067E 75 82 00         [24]  847 	mov	dpl, #0x00
                                    848 ;	lib/Common.c:146: }
      000681 22               [24]  849 	ret
                                    850 	.area CSEG    (CODE)
                                    851 	.area CONST   (CODE)
                                    852 	.area CABS    (ABS,CODE)
