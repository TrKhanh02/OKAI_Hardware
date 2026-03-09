                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ISO C Compiler 
                                      3 ; Version 4.4.0 #14620 (MINGW32)
                                      4 ;--------------------------------------------------------
                                      5 	.module pwm
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
                                    244 	.globl _PWM_SetDuty_PARM_2
                                    245 	.globl _PWM_Init
                                    246 	.globl _PWM_SetDuty
                                    247 	.globl _PWM_GetDuty
                                    248 ;--------------------------------------------------------
                                    249 ; special function registers
                                    250 ;--------------------------------------------------------
                                    251 	.area RSEG    (ABS,DATA)
      000000                        252 	.org 0x0000
                           000080   253 _P0	=	0x0080
                           000081   254 _SP	=	0x0081
                           000082   255 _DPL	=	0x0082
                           000083   256 _DPH	=	0x0083
                           000084   257 _RCTRIM0	=	0x0084
                           000085   258 _RCTRIM1	=	0x0085
                           000086   259 _RWK	=	0x0086
                           000087   260 _PCON	=	0x0087
                           000088   261 _TCON	=	0x0088
                           000089   262 _TMOD	=	0x0089
                           00008A   263 _TL0	=	0x008a
                           00008B   264 _TL1	=	0x008b
                           00008C   265 _TH0	=	0x008c
                           00008D   266 _TH1	=	0x008d
                           00008E   267 _CKCON	=	0x008e
                           00008F   268 _WKCON	=	0x008f
                           000090   269 _P1	=	0x0090
                           000091   270 _SFRS	=	0x0091
                           000092   271 _CAPCON0	=	0x0092
                           000093   272 _CAPCON1	=	0x0093
                           000094   273 _CAPCON2	=	0x0094
                           000095   274 _CKDIV	=	0x0095
                           000096   275 _CKSWT	=	0x0096
                           000097   276 _CKEN	=	0x0097
                           000098   277 _SCON	=	0x0098
                           000099   278 _SBUF	=	0x0099
                           00009A   279 _SBUF_1	=	0x009a
                           00009B   280 _EIE	=	0x009b
                           00009C   281 _EIE1	=	0x009c
                           00009F   282 _CHPCON	=	0x009f
                           0000A0   283 _P2	=	0x00a0
                           0000A2   284 _AUXR1	=	0x00a2
                           0000A3   285 _BODCON0	=	0x00a3
                           0000A4   286 _IAPTRG	=	0x00a4
                           0000A5   287 _IAPUEN	=	0x00a5
                           0000A6   288 _IAPAL	=	0x00a6
                           0000A7   289 _IAPAH	=	0x00a7
                           0000A8   290 _IE	=	0x00a8
                           0000A9   291 _SADDR	=	0x00a9
                           0000AA   292 _WDCON	=	0x00aa
                           0000AB   293 _BODCON1	=	0x00ab
                           0000AC   294 _P3M1	=	0x00ac
                           0000AC   295 _P3S	=	0x00ac
                           0000AD   296 _P3M2	=	0x00ad
                           0000AD   297 _P3SR	=	0x00ad
                           0000AE   298 _IAPFD	=	0x00ae
                           0000AF   299 _IAPCN	=	0x00af
                           0000B0   300 _P3	=	0x00b0
                           0000B1   301 _P0M1	=	0x00b1
                           0000B1   302 _P0S	=	0x00b1
                           0000B2   303 _P0M2	=	0x00b2
                           0000B2   304 _P0SR	=	0x00b2
                           0000B3   305 _P1M1	=	0x00b3
                           0000B3   306 _P1S	=	0x00b3
                           0000B4   307 _P1M2	=	0x00b4
                           0000B4   308 _P1SR	=	0x00b4
                           0000B5   309 _P2S	=	0x00b5
                           0000B7   310 _IPH	=	0x00b7
                           0000B7   311 _PWMINTC	=	0x00b7
                           0000B8   312 _IP	=	0x00b8
                           0000B9   313 _SADEN	=	0x00b9
                           0000BA   314 _SADEN_1	=	0x00ba
                           0000BB   315 _SADDR_1	=	0x00bb
                           0000BC   316 _I2DAT	=	0x00bc
                           0000BD   317 _I2STAT	=	0x00bd
                           0000BE   318 _I2CLK	=	0x00be
                           0000BF   319 _I2TOC	=	0x00bf
                           0000C0   320 _I2CON	=	0x00c0
                           0000C1   321 _I2ADDR	=	0x00c1
                           0000C2   322 _ADCRL	=	0x00c2
                           0000C3   323 _ADCRH	=	0x00c3
                           0000C4   324 _T3CON	=	0x00c4
                           0000C4   325 _PWM4H	=	0x00c4
                           0000C5   326 _RL3	=	0x00c5
                           0000C5   327 _PWM5H	=	0x00c5
                           0000C6   328 _RH3	=	0x00c6
                           0000C6   329 _PIOCON1	=	0x00c6
                           0000C7   330 _TA	=	0x00c7
                           0000C8   331 _T2CON	=	0x00c8
                           0000C9   332 _T2MOD	=	0x00c9
                           0000CA   333 _RCMP2L	=	0x00ca
                           0000CB   334 _RCMP2H	=	0x00cb
                           0000CC   335 _TL2	=	0x00cc
                           0000CC   336 _PWM4L	=	0x00cc
                           0000CD   337 _TH2	=	0x00cd
                           0000CD   338 _PWM5L	=	0x00cd
                           0000CE   339 _ADCMPL	=	0x00ce
                           0000CF   340 _ADCMPH	=	0x00cf
                           0000D0   341 _PSW	=	0x00d0
                           0000D1   342 _PWMPH	=	0x00d1
                           0000D2   343 _PWM0H	=	0x00d2
                           0000D3   344 _PWM1H	=	0x00d3
                           0000D4   345 _PWM2H	=	0x00d4
                           0000D5   346 _PWM3H	=	0x00d5
                           0000D6   347 _PNP	=	0x00d6
                           0000D7   348 _FBD	=	0x00d7
                           0000D8   349 _PWMCON0	=	0x00d8
                           0000D9   350 _PWMPL	=	0x00d9
                           0000DA   351 _PWM0L	=	0x00da
                           0000DB   352 _PWM1L	=	0x00db
                           0000DC   353 _PWM2L	=	0x00dc
                           0000DD   354 _PWM3L	=	0x00dd
                           0000DE   355 _PIOCON0	=	0x00de
                           0000DF   356 _PWMCON1	=	0x00df
                           0000E0   357 _ACC	=	0x00e0
                           0000E1   358 _ADCCON1	=	0x00e1
                           0000E2   359 _ADCCON2	=	0x00e2
                           0000E3   360 _ADCDLY	=	0x00e3
                           0000E4   361 _C0L	=	0x00e4
                           0000E5   362 _C0H	=	0x00e5
                           0000E6   363 _C1L	=	0x00e6
                           0000E7   364 _C1H	=	0x00e7
                           0000E8   365 _ADCCON0	=	0x00e8
                           0000E9   366 _PICON	=	0x00e9
                           0000EA   367 _PINEN	=	0x00ea
                           0000EB   368 _PIPEN	=	0x00eb
                           0000EC   369 _PIF	=	0x00ec
                           0000ED   370 _C2L	=	0x00ed
                           0000EE   371 _C2H	=	0x00ee
                           0000EF   372 _EIP	=	0x00ef
                           0000F0   373 _B	=	0x00f0
                           0000F1   374 _CAPCON3	=	0x00f1
                           0000F2   375 _CAPCON4	=	0x00f2
                           0000F3   376 _SPCR	=	0x00f3
                           0000F3   377 _SPCR2	=	0x00f3
                           0000F4   378 _SPSR	=	0x00f4
                           0000F5   379 _SPDR	=	0x00f5
                           0000F6   380 _AINDIDS	=	0x00f6
                           0000F7   381 _EIPH	=	0x00f7
                           0000F8   382 _SCON_1	=	0x00f8
                           0000F9   383 _PDTEN	=	0x00f9
                           0000FA   384 _PDTCNT	=	0x00fa
                           0000FB   385 _PMEN	=	0x00fb
                           0000FC   386 _PMD	=	0x00fc
                           0000FD   387 _PORDIS	=	0x00fd
                           0000FE   388 _EIP1	=	0x00fe
                           0000FF   389 _EIPH1	=	0x00ff
                                    390 ;--------------------------------------------------------
                                    391 ; special function bits
                                    392 ;--------------------------------------------------------
                                    393 	.area RSEG    (ABS,DATA)
      000000                        394 	.org 0x0000
                           0000FF   395 _SM0_1	=	0x00ff
                           0000FF   396 _FE_1	=	0x00ff
                           0000FE   397 _SM1_1	=	0x00fe
                           0000FD   398 _SM2_1	=	0x00fd
                           0000FC   399 _REN_1	=	0x00fc
                           0000FB   400 _TB8_1	=	0x00fb
                           0000FA   401 _RB8_1	=	0x00fa
                           0000F9   402 _TI_1	=	0x00f9
                           0000F8   403 _RI_1	=	0x00f8
                           0000EF   404 _ADCF	=	0x00ef
                           0000EE   405 _ADCS	=	0x00ee
                           0000ED   406 _ETGSEL1	=	0x00ed
                           0000EC   407 _ETGSEL0	=	0x00ec
                           0000EB   408 _ADCHS3	=	0x00eb
                           0000EA   409 _ADCHS2	=	0x00ea
                           0000E9   410 _ADCHS1	=	0x00e9
                           0000E8   411 _ADCHS0	=	0x00e8
                           0000DF   412 _PWMRUN	=	0x00df
                           0000DE   413 _LOAD	=	0x00de
                           0000DD   414 _PWMF	=	0x00dd
                           0000DC   415 _CLRPWM	=	0x00dc
                           0000D7   416 _CY	=	0x00d7
                           0000D6   417 _AC	=	0x00d6
                           0000D5   418 _F0	=	0x00d5
                           0000D4   419 _RS1	=	0x00d4
                           0000D3   420 _RS0	=	0x00d3
                           0000D2   421 _OV	=	0x00d2
                           0000D0   422 _P	=	0x00d0
                           0000CF   423 _TF2	=	0x00cf
                           0000CA   424 _TR2	=	0x00ca
                           0000C8   425 _CM_RL2	=	0x00c8
                           0000C6   426 _I2CEN	=	0x00c6
                           0000C5   427 _STA	=	0x00c5
                           0000C4   428 _STO	=	0x00c4
                           0000C3   429 _SI	=	0x00c3
                           0000C2   430 _AA	=	0x00c2
                           0000C0   431 _I2CPX	=	0x00c0
                           0000BE   432 _PADC	=	0x00be
                           0000BD   433 _PBOD	=	0x00bd
                           0000BC   434 _PS	=	0x00bc
                           0000BB   435 _PT1	=	0x00bb
                           0000BA   436 _PX1	=	0x00ba
                           0000B9   437 _PT0	=	0x00b9
                           0000B8   438 _PX0	=	0x00b8
                           0000B0   439 _P30	=	0x00b0
                           0000AF   440 _EA	=	0x00af
                           0000AE   441 _EADC	=	0x00ae
                           0000AD   442 _EBOD	=	0x00ad
                           0000AC   443 _ES	=	0x00ac
                           0000AB   444 _ET1	=	0x00ab
                           0000AA   445 _EX1	=	0x00aa
                           0000A9   446 _ET0	=	0x00a9
                           0000A8   447 _EX0	=	0x00a8
                           0000A0   448 _P20	=	0x00a0
                           00009F   449 _SM0	=	0x009f
                           00009F   450 _FE	=	0x009f
                           00009E   451 _SM1	=	0x009e
                           00009D   452 _SM2	=	0x009d
                           00009C   453 _REN	=	0x009c
                           00009B   454 _TB8	=	0x009b
                           00009A   455 _RB8	=	0x009a
                           000099   456 _TI	=	0x0099
                           000098   457 _RI	=	0x0098
                           000097   458 _P17	=	0x0097
                           000096   459 _P16	=	0x0096
                           000096   460 _TXD_1	=	0x0096
                           000095   461 _P15	=	0x0095
                           000094   462 _P14	=	0x0094
                           000094   463 _SDA	=	0x0094
                           000093   464 _P13	=	0x0093
                           000093   465 _SCL	=	0x0093
                           000092   466 _P12	=	0x0092
                           000091   467 _P11	=	0x0091
                           000090   468 _P10	=	0x0090
                           00008F   469 _TF1	=	0x008f
                           00008E   470 _TR1	=	0x008e
                           00008D   471 _TF0	=	0x008d
                           00008C   472 _TR0	=	0x008c
                           00008B   473 _IE1	=	0x008b
                           00008A   474 _IT1	=	0x008a
                           000089   475 _IE0	=	0x0089
                           000088   476 _IT0	=	0x0088
                           000087   477 _P07	=	0x0087
                           000087   478 _RXD	=	0x0087
                           000086   479 _P06	=	0x0086
                           000086   480 _TXD	=	0x0086
                           000085   481 _P05	=	0x0085
                           000084   482 _P04	=	0x0084
                           000084   483 _STADC	=	0x0084
                           000083   484 _P03	=	0x0083
                           000082   485 _P02	=	0x0082
                           000082   486 _RXD_1	=	0x0082
                           000081   487 _P01	=	0x0081
                           000081   488 _MISO	=	0x0081
                           000080   489 _P00	=	0x0080
                           000080   490 _MOSI	=	0x0080
                                    491 ;--------------------------------------------------------
                                    492 ; overlayable register banks
                                    493 ;--------------------------------------------------------
                                    494 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        495 	.ds 8
                                    496 ;--------------------------------------------------------
                                    497 ; internal ram data
                                    498 ;--------------------------------------------------------
                                    499 	.area DSEG    (DATA)
      00000A                        500 _period:
      00000A                        501 	.ds 2
      00000C                        502 _PWM_SetDuty_PARM_2:
      00000C                        503 	.ds 1
      00000D                        504 _PWM_SetDuty_channel_10000_104:
      00000D                        505 	.ds 1
                                    506 ;--------------------------------------------------------
                                    507 ; overlayable items in internal ram
                                    508 ;--------------------------------------------------------
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
                                    537 	.area XISEG   (XDATA)
                                    538 	.area HOME    (CODE)
                                    539 	.area GSINIT0 (CODE)
                                    540 	.area GSINIT1 (CODE)
                                    541 	.area GSINIT2 (CODE)
                                    542 	.area GSINIT3 (CODE)
                                    543 	.area GSINIT4 (CODE)
                                    544 	.area GSINIT5 (CODE)
                                    545 	.area GSINIT  (CODE)
                                    546 	.area GSFINAL (CODE)
                                    547 	.area CSEG    (CODE)
                                    548 ;--------------------------------------------------------
                                    549 ; global & static initialisations
                                    550 ;--------------------------------------------------------
                                    551 	.area HOME    (CODE)
                                    552 	.area GSINIT  (CODE)
                                    553 	.area GSFINAL (CODE)
                                    554 	.area GSINIT  (CODE)
                                    555 ;--------------------------------------------------------
                                    556 ; Home
                                    557 ;--------------------------------------------------------
                                    558 	.area HOME    (CODE)
                                    559 	.area HOME    (CODE)
                                    560 ;--------------------------------------------------------
                                    561 ; code
                                    562 ;--------------------------------------------------------
                                    563 	.area CSEG    (CODE)
                                    564 ;------------------------------------------------------------
                                    565 ;Allocation info for local variables in function 'PWM_Init'
                                    566 ;------------------------------------------------------------
                                    567 ;Fpwm                      Allocated to registers r6 r7 
                                    568 ;------------------------------------------------------------
                                    569 ;	lib\N76E003\pwm.c:12: void PWM_Init(uint16_t Fpwm)
                                    570 ;	-----------------------------------------
                                    571 ;	 function PWM_Init
                                    572 ;	-----------------------------------------
      0006BC                        573 _PWM_Init:
                           000007   574 	ar7 = 0x07
                           000006   575 	ar6 = 0x06
                           000005   576 	ar5 = 0x05
                           000004   577 	ar4 = 0x04
                           000003   578 	ar3 = 0x03
                           000002   579 	ar2 = 0x02
                           000001   580 	ar1 = 0x01
                           000000   581 	ar0 = 0x00
      0006BC AE 82            [24]  582 	mov	r6, dpl
      0006BE AF 83            [24]  583 	mov	r7, dph
                                    584 ;	lib\N76E003\pwm.c:14: PWM_CLOCK_FSYS;
      0006C0 53 8E BF         [24]  585 	anl	_CKCON,#0xbf
                                    586 ;	lib\N76E003\pwm.c:15: PWM_IMDEPENDENT_MODE;
      0006C3 53 DF 3F         [24]  587 	anl	_PWMCON1,#0x3f
                                    588 ;	lib\N76E003\pwm.c:16: PWM_CLOCK_DIV_8;
      0006C6 43 DF 03         [24]  589 	orl	_PWMCON1,#0x03
      0006C9 53 DF FB         [24]  590 	anl	_PWMCON1,#0xfb
                                    591 ;	lib\N76E003\pwm.c:18: period = PWM_FSYS_DIV_8/Fpwm - 1;
      0006CC 8E 44            [24]  592 	mov	__divulong_PARM_2,r6
      0006CE 8F 45            [24]  593 	mov	(__divulong_PARM_2 + 1),r7
      0006D0 75 46 00         [24]  594 	mov	(__divulong_PARM_2 + 2),#0x00
      0006D3 75 47 00         [24]  595 	mov	(__divulong_PARM_2 + 3),#0x00
      0006D6 90 A9 78         [24]  596 	mov	dptr,#0xa978
      0006D9 75 F0 1F         [24]  597 	mov	b, #0x1f
      0006DC E4               [12]  598 	clr	a
      0006DD 12 15 E3         [24]  599 	lcall	__divulong
      0006E0 AC 82            [24]  600 	mov	r4, dpl
      0006E2 AD 83            [24]  601 	mov	r5, dph
      0006E4 EC               [12]  602 	mov	a,r4
      0006E5 24 FF            [12]  603 	add	a,#0xff
      0006E7 F5 0A            [12]  604 	mov	_period,a
      0006E9 ED               [12]  605 	mov	a,r5
      0006EA 34 FF            [12]  606 	addc	a,#0xff
      0006EC F5 0B            [12]  607 	mov	(_period + 1),a
                                    608 ;	lib\N76E003\pwm.c:20: PWMPH = (period >> 8) & 0xFF;
      0006EE 85 0B D1         [24]  609 	mov	_PWMPH,(_period + 1)
                                    610 ;	lib\N76E003\pwm.c:21: PWMPL = period & 0xFF;
      0006F1 85 0A D9         [24]  611 	mov	_PWMPL,_period
                                    612 ;	lib\N76E003\pwm.c:23: set_LOAD;
                                    613 ;	assignBit
      0006F4 D2 DE            [12]  614 	setb	_LOAD
                                    615 ;	lib\N76E003\pwm.c:24: set_PWMRUN;
                                    616 ;	assignBit
      0006F6 D2 DF            [12]  617 	setb	_PWMRUN
                                    618 ;	lib\N76E003\pwm.c:25: }
      0006F8 22               [24]  619 	ret
                                    620 ;------------------------------------------------------------
                                    621 ;Allocation info for local variables in function 'PWM_SetDuty'
                                    622 ;------------------------------------------------------------
                                    623 ;dutyPercent               Allocated with name '_PWM_SetDuty_PARM_2'
                                    624 ;channel                   Allocated with name '_PWM_SetDuty_channel_10000_104'
                                    625 ;cmr                       Allocated to registers r5 r6 
                                    626 ;------------------------------------------------------------
                                    627 ;	lib\N76E003\pwm.c:27: void PWM_SetDuty(uint8_t channel, uint8_t dutyPercent)
                                    628 ;	-----------------------------------------
                                    629 ;	 function PWM_SetDuty
                                    630 ;	-----------------------------------------
      0006F9                        631 _PWM_SetDuty:
      0006F9 85 82 0D         [24]  632 	mov	_PWM_SetDuty_channel_10000_104,dpl
                                    633 ;	lib\N76E003\pwm.c:30: if (dutyPercent == 0) {
      0006FC E5 0C            [12]  634 	mov	a,_PWM_SetDuty_PARM_2
                                    635 ;	lib\N76E003\pwm.c:31: cmr = 0;
      0006FE 70 04            [24]  636 	jnz	00102$
      000700 FD               [12]  637 	mov	r5,a
      000701 FE               [12]  638 	mov	r6,a
      000702 80 4F            [24]  639 	sjmp	00103$
      000704                        640 00102$:
                                    641 ;	lib\N76E003\pwm.c:33: cmr = ((uint32_t)dutyPercent * (period + 1)) / 100 - 1;
      000704 A9 0C            [24]  642 	mov	r1,_PWM_SetDuty_PARM_2
      000706 7A 00            [12]  643 	mov	r2,#0x00
      000708 7B 00            [12]  644 	mov	r3,#0x00
      00070A 7C 00            [12]  645 	mov	r4,#0x00
      00070C A8 0A            [24]  646 	mov	r0,_period
      00070E AF 0B            [24]  647 	mov	r7,(_period + 1)
      000710 08               [12]  648 	inc	r0
      000711 B8 00 01         [24]  649 	cjne	r0,#0x00,00146$
      000714 0F               [12]  650 	inc	r7
      000715                        651 00146$:
      000715 88 44            [24]  652 	mov	__mullong_PARM_2,r0
      000717 8F 45            [24]  653 	mov	(__mullong_PARM_2 + 1),r7
      000719 75 46 00         [24]  654 	mov	(__mullong_PARM_2 + 2),#0x00
      00071C 75 47 00         [24]  655 	mov	(__mullong_PARM_2 + 3),#0x00
      00071F 89 82            [24]  656 	mov	dpl, r1
      000721 8A 83            [24]  657 	mov	dph, r2
      000723 8B F0            [24]  658 	mov	b, r3
      000725 EC               [12]  659 	mov	a, r4
      000726 12 16 80         [24]  660 	lcall	__mullong
      000729 AA 82            [24]  661 	mov	r2, dpl
      00072B AB 83            [24]  662 	mov	r3, dph
      00072D AC F0            [24]  663 	mov	r4, b
      00072F FF               [12]  664 	mov	r7, a
      000730 75 44 64         [24]  665 	mov	__divulong_PARM_2,#0x64
      000733 E4               [12]  666 	clr	a
      000734 F5 45            [12]  667 	mov	(__divulong_PARM_2 + 1),a
      000736 F5 46            [12]  668 	mov	(__divulong_PARM_2 + 2),a
      000738 F5 47            [12]  669 	mov	(__divulong_PARM_2 + 3),a
      00073A 8A 82            [24]  670 	mov	dpl, r2
      00073C 8B 83            [24]  671 	mov	dph, r3
      00073E 8C F0            [24]  672 	mov	b, r4
      000740 EF               [12]  673 	mov	a, r7
      000741 12 15 E3         [24]  674 	lcall	__divulong
      000744 AA 82            [24]  675 	mov	r2, dpl
      000746 AB 83            [24]  676 	mov	r3, dph
      000748 AC F0            [24]  677 	mov	r4, b
      00074A FF               [12]  678 	mov	r7, a
      00074B EA               [12]  679 	mov	a,r2
      00074C 24 FF            [12]  680 	add	a,#0xff
      00074E FD               [12]  681 	mov	r5,a
      00074F EB               [12]  682 	mov	a,r3
      000750 34 FF            [12]  683 	addc	a,#0xff
      000752 FE               [12]  684 	mov	r6,a
      000753                        685 00103$:
                                    686 ;	lib\N76E003\pwm.c:35: if (cmr > period) cmr = period;
      000753 C3               [12]  687 	clr	c
      000754 E5 0A            [12]  688 	mov	a,_period
      000756 9D               [12]  689 	subb	a,r5
      000757 E5 0B            [12]  690 	mov	a,(_period + 1)
      000759 9E               [12]  691 	subb	a,r6
      00075A 50 04            [24]  692 	jnc	00105$
      00075C AD 0A            [24]  693 	mov	r5,_period
      00075E AE 0B            [24]  694 	mov	r6,(_period + 1)
      000760                        695 00105$:
                                    696 ;	lib\N76E003\pwm.c:37: switch (channel) {
      000760 E5 0D            [12]  697 	mov	a,_PWM_SetDuty_channel_10000_104
      000762 24 FA            [12]  698 	add	a,#0xff - 0x05
      000764 50 03            [24]  699 	jnc	00148$
      000766 02 07 F3         [24]  700 	ljmp	00124$
      000769                        701 00148$:
      000769 E5 0D            [12]  702 	mov	a,_PWM_SetDuty_channel_10000_104
      00076B 75 F0 03         [24]  703 	mov	b,#0x03
      00076E A4               [48]  704 	mul	ab
      00076F 90 07 73         [24]  705 	mov	dptr,#00149$
      000772 73               [24]  706 	jmp	@a+dptr
      000773                        707 00149$:
      000773 02 07 85         [24]  708 	ljmp	00106$
      000776 02 07 8B         [24]  709 	ljmp	00107$
      000779 02 07 91         [24]  710 	ljmp	00108$
      00077C 02 07 97         [24]  711 	ljmp	00109$
      00077F 02 07 9D         [24]  712 	ljmp	00111$
      000782 02 07 C9         [24]  713 	ljmp	00118$
                                    714 ;	lib\N76E003\pwm.c:38: case 0: PWM0H = cmr >> 8; PWM0L = cmr; break;
      000785                        715 00106$:
      000785 8E D2            [24]  716 	mov	_PWM0H,r6
      000787 8D DA            [24]  717 	mov	_PWM0L,r5
                                    718 ;	lib\N76E003\pwm.c:39: case 1: PWM1H = cmr >> 8; PWM1L = cmr; break;
      000789 80 68            [24]  719 	sjmp	00124$
      00078B                        720 00107$:
      00078B 8E D3            [24]  721 	mov	_PWM1H,r6
      00078D 8D DB            [24]  722 	mov	_PWM1L,r5
                                    723 ;	lib\N76E003\pwm.c:40: case 2: PWM2H = cmr >> 8; PWM2L = cmr; break;
      00078F 80 62            [24]  724 	sjmp	00124$
      000791                        725 00108$:
      000791 8E D4            [24]  726 	mov	_PWM2H,r6
      000793 8D DC            [24]  727 	mov	_PWM2L,r5
                                    728 ;	lib\N76E003\pwm.c:41: case 3: PWM3H = cmr >> 8; PWM3L = cmr; break;
      000795 80 5C            [24]  729 	sjmp	00124$
      000797                        730 00109$:
      000797 8E D5            [24]  731 	mov	_PWM3H,r6
      000799 8D DD            [24]  732 	mov	_PWM3L,r5
                                    733 ;	lib\N76E003\pwm.c:42: case 4: set_SFRPAGE; PWM4H = cmr >> 8; PWM4L = cmr; clr_SFRPAGE; break;
      00079B 80 56            [24]  734 	sjmp	00124$
      00079D                        735 00111$:
                                    736 ;	assignBit
      00079D A2 AF            [12]  737 	mov	c,_EA
      00079F 92 00            [24]  738 	mov	_BIT_TMP,c
                                    739 ;	assignBit
      0007A1 C2 AF            [12]  740 	clr	_EA
      0007A3 75 C7 AA         [24]  741 	mov	_TA,#0xaa
      0007A6 75 C7 55         [24]  742 	mov	_TA,#0x55
      0007A9 43 91 01         [24]  743 	orl	_SFRS,#0x01
                                    744 ;	assignBit
      0007AC A2 00            [12]  745 	mov	c,_BIT_TMP
      0007AE 92 AF            [24]  746 	mov	_EA,c
      0007B0 8E C4            [24]  747 	mov	_PWM4H,r6
      0007B2 8D CC            [24]  748 	mov	_PWM4L,r5
                                    749 ;	assignBit
      0007B4 A2 AF            [12]  750 	mov	c,_EA
      0007B6 92 00            [24]  751 	mov	_BIT_TMP,c
                                    752 ;	assignBit
      0007B8 C2 AF            [12]  753 	clr	_EA
      0007BA 75 C7 AA         [24]  754 	mov	_TA,#0xaa
      0007BD 75 C7 55         [24]  755 	mov	_TA,#0x55
      0007C0 53 91 FE         [24]  756 	anl	_SFRS,#0xfe
                                    757 ;	assignBit
      0007C3 A2 00            [12]  758 	mov	c,_BIT_TMP
      0007C5 92 AF            [24]  759 	mov	_EA,c
                                    760 ;	lib\N76E003\pwm.c:43: case 5: set_SFRPAGE; PWM5H = cmr >> 8; PWM5L = cmr; clr_SFRPAGE; break;
      0007C7 80 2A            [24]  761 	sjmp	00124$
      0007C9                        762 00118$:
                                    763 ;	assignBit
      0007C9 A2 AF            [12]  764 	mov	c,_EA
      0007CB 92 00            [24]  765 	mov	_BIT_TMP,c
                                    766 ;	assignBit
      0007CD C2 AF            [12]  767 	clr	_EA
      0007CF 75 C7 AA         [24]  768 	mov	_TA,#0xaa
      0007D2 75 C7 55         [24]  769 	mov	_TA,#0x55
      0007D5 43 91 01         [24]  770 	orl	_SFRS,#0x01
                                    771 ;	assignBit
      0007D8 A2 00            [12]  772 	mov	c,_BIT_TMP
      0007DA 92 AF            [24]  773 	mov	_EA,c
      0007DC 8E C5            [24]  774 	mov	_PWM5H,r6
      0007DE 8D CD            [24]  775 	mov	_PWM5L,r5
                                    776 ;	assignBit
      0007E0 A2 AF            [12]  777 	mov	c,_EA
      0007E2 92 00            [24]  778 	mov	_BIT_TMP,c
                                    779 ;	assignBit
      0007E4 C2 AF            [12]  780 	clr	_EA
      0007E6 75 C7 AA         [24]  781 	mov	_TA,#0xaa
      0007E9 75 C7 55         [24]  782 	mov	_TA,#0x55
      0007EC 53 91 FE         [24]  783 	anl	_SFRS,#0xfe
                                    784 ;	assignBit
      0007EF A2 00            [12]  785 	mov	c,_BIT_TMP
      0007F1 92 AF            [24]  786 	mov	_EA,c
                                    787 ;	lib\N76E003\pwm.c:44: }
      0007F3                        788 00124$:
                                    789 ;	lib\N76E003\pwm.c:46: set_LOAD;
                                    790 ;	assignBit
      0007F3 D2 DE            [12]  791 	setb	_LOAD
                                    792 ;	lib\N76E003\pwm.c:47: }
      0007F5 22               [24]  793 	ret
                                    794 ;------------------------------------------------------------
                                    795 ;Allocation info for local variables in function 'PWM_GetDuty'
                                    796 ;------------------------------------------------------------
                                    797 ;channel                   Allocated to registers r7 
                                    798 ;cmr                       Allocated to registers r5 r6 
                                    799 ;------------------------------------------------------------
                                    800 ;	lib\N76E003\pwm.c:49: uint8_t PWM_GetDuty(uint8_t channel)
                                    801 ;	-----------------------------------------
                                    802 ;	 function PWM_GetDuty
                                    803 ;	-----------------------------------------
      0007F6                        804 _PWM_GetDuty:
      0007F6 AF 82            [24]  805 	mov	r7, dpl
                                    806 ;	lib\N76E003\pwm.c:51: uint16_t cmr = 0;
                                    807 ;	lib\N76E003\pwm.c:52: switch (channel) {
      0007F8 E4               [12]  808 	clr	a
      0007F9 FD               [12]  809 	mov	r5,a
      0007FA FE               [12]  810 	mov	r6,a
      0007FB EF               [12]  811 	mov	a,r7
      0007FC 24 FA            [12]  812 	add	a,#0xff - 0x05
      0007FE 50 03            [24]  813 	jnc	00136$
      000800 02 08 C1         [24]  814 	ljmp	00119$
      000803                        815 00136$:
      000803 EF               [12]  816 	mov	a,r7
      000804 2F               [12]  817 	add	a,r7
                                    818 ;	lib\N76E003\pwm.c:53: case 0: cmr = ((uint16_t)PWM0H << 8) | PWM0L; break;
      000805 90 08 09         [24]  819 	mov	dptr,#00137$
      000808 73               [24]  820 	jmp	@a+dptr
      000809                        821 00137$:
      000809 80 0A            [24]  822 	sjmp	00101$
      00080B 80 19            [24]  823 	sjmp	00102$
      00080D 80 28            [24]  824 	sjmp	00103$
      00080F 80 36            [24]  825 	sjmp	00104$
      000811 80 44            [24]  826 	sjmp	00106$
      000813 80 78            [24]  827 	sjmp	00113$
      000815                        828 00101$:
      000815 AF D2            [24]  829 	mov	r7,_PWM0H
      000817 7C 00            [12]  830 	mov	r4,#0x00
      000819 AA DA            [24]  831 	mov	r2,_PWM0L
      00081B 7B 00            [12]  832 	mov	r3,#0x00
      00081D EA               [12]  833 	mov	a,r2
      00081E 4C               [12]  834 	orl	a,r4
      00081F FD               [12]  835 	mov	r5,a
      000820 EB               [12]  836 	mov	a,r3
      000821 4F               [12]  837 	orl	a,r7
      000822 FE               [12]  838 	mov	r6,a
      000823 02 08 C1         [24]  839 	ljmp	00119$
                                    840 ;	lib\N76E003\pwm.c:54: case 1: cmr = ((uint16_t)PWM1H << 8) | PWM1L; break;
      000826                        841 00102$:
      000826 AF D3            [24]  842 	mov	r7,_PWM1H
      000828 7C 00            [12]  843 	mov	r4,#0x00
      00082A AA DB            [24]  844 	mov	r2,_PWM1L
      00082C 7B 00            [12]  845 	mov	r3,#0x00
      00082E EA               [12]  846 	mov	a,r2
      00082F 4C               [12]  847 	orl	a,r4
      000830 FD               [12]  848 	mov	r5,a
      000831 EB               [12]  849 	mov	a,r3
      000832 4F               [12]  850 	orl	a,r7
      000833 FE               [12]  851 	mov	r6,a
      000834 02 08 C1         [24]  852 	ljmp	00119$
                                    853 ;	lib\N76E003\pwm.c:55: case 2: cmr = ((uint16_t)PWM2H << 8) | PWM2L; break;
      000837                        854 00103$:
      000837 AF D4            [24]  855 	mov	r7,_PWM2H
      000839 7C 00            [12]  856 	mov	r4,#0x00
      00083B AA DC            [24]  857 	mov	r2,_PWM2L
      00083D 7B 00            [12]  858 	mov	r3,#0x00
      00083F EA               [12]  859 	mov	a,r2
      000840 4C               [12]  860 	orl	a,r4
      000841 FD               [12]  861 	mov	r5,a
      000842 EB               [12]  862 	mov	a,r3
      000843 4F               [12]  863 	orl	a,r7
      000844 FE               [12]  864 	mov	r6,a
                                    865 ;	lib\N76E003\pwm.c:56: case 3: cmr = ((uint16_t)PWM3H << 8) | PWM3L; break;
      000845 80 7A            [24]  866 	sjmp	00119$
      000847                        867 00104$:
      000847 AF D5            [24]  868 	mov	r7,_PWM3H
      000849 7C 00            [12]  869 	mov	r4,#0x00
      00084B AA DD            [24]  870 	mov	r2,_PWM3L
      00084D 7B 00            [12]  871 	mov	r3,#0x00
      00084F EA               [12]  872 	mov	a,r2
      000850 4C               [12]  873 	orl	a,r4
      000851 FD               [12]  874 	mov	r5,a
      000852 EB               [12]  875 	mov	a,r3
      000853 4F               [12]  876 	orl	a,r7
      000854 FE               [12]  877 	mov	r6,a
                                    878 ;	lib\N76E003\pwm.c:57: case 4: set_SFRPAGE; cmr = ((uint16_t)PWM4H << 8) | PWM4L; clr_SFRPAGE; break;
      000855 80 6A            [24]  879 	sjmp	00119$
      000857                        880 00106$:
                                    881 ;	assignBit
      000857 A2 AF            [12]  882 	mov	c,_EA
      000859 92 00            [24]  883 	mov	_BIT_TMP,c
                                    884 ;	assignBit
      00085B C2 AF            [12]  885 	clr	_EA
      00085D 75 C7 AA         [24]  886 	mov	_TA,#0xaa
      000860 75 C7 55         [24]  887 	mov	_TA,#0x55
      000863 43 91 01         [24]  888 	orl	_SFRS,#0x01
                                    889 ;	assignBit
      000866 A2 00            [12]  890 	mov	c,_BIT_TMP
      000868 92 AF            [24]  891 	mov	_EA,c
      00086A AF C4            [24]  892 	mov	r7,_PWM4H
      00086C 7C 00            [12]  893 	mov	r4,#0x00
      00086E AA CC            [24]  894 	mov	r2,_PWM4L
      000870 7B 00            [12]  895 	mov	r3,#0x00
      000872 EA               [12]  896 	mov	a,r2
      000873 4C               [12]  897 	orl	a,r4
      000874 FD               [12]  898 	mov	r5,a
      000875 EB               [12]  899 	mov	a,r3
      000876 4F               [12]  900 	orl	a,r7
      000877 FE               [12]  901 	mov	r6,a
                                    902 ;	assignBit
      000878 A2 AF            [12]  903 	mov	c,_EA
      00087A 92 00            [24]  904 	mov	_BIT_TMP,c
                                    905 ;	assignBit
      00087C C2 AF            [12]  906 	clr	_EA
      00087E 75 C7 AA         [24]  907 	mov	_TA,#0xaa
      000881 75 C7 55         [24]  908 	mov	_TA,#0x55
      000884 53 91 FE         [24]  909 	anl	_SFRS,#0xfe
                                    910 ;	assignBit
      000887 A2 00            [12]  911 	mov	c,_BIT_TMP
      000889 92 AF            [24]  912 	mov	_EA,c
                                    913 ;	lib\N76E003\pwm.c:58: case 5: set_SFRPAGE; cmr = ((uint16_t)PWM5H << 8) | PWM5L; clr_SFRPAGE; break;
      00088B 80 34            [24]  914 	sjmp	00119$
      00088D                        915 00113$:
                                    916 ;	assignBit
      00088D A2 AF            [12]  917 	mov	c,_EA
      00088F 92 00            [24]  918 	mov	_BIT_TMP,c
                                    919 ;	assignBit
      000891 C2 AF            [12]  920 	clr	_EA
      000893 75 C7 AA         [24]  921 	mov	_TA,#0xaa
      000896 75 C7 55         [24]  922 	mov	_TA,#0x55
      000899 43 91 01         [24]  923 	orl	_SFRS,#0x01
                                    924 ;	assignBit
      00089C A2 00            [12]  925 	mov	c,_BIT_TMP
      00089E 92 AF            [24]  926 	mov	_EA,c
      0008A0 AF C5            [24]  927 	mov	r7,_PWM5H
      0008A2 7C 00            [12]  928 	mov	r4,#0x00
      0008A4 AA CD            [24]  929 	mov	r2,_PWM5L
      0008A6 7B 00            [12]  930 	mov	r3,#0x00
      0008A8 EA               [12]  931 	mov	a,r2
      0008A9 4C               [12]  932 	orl	a,r4
      0008AA FD               [12]  933 	mov	r5,a
      0008AB EB               [12]  934 	mov	a,r3
      0008AC 4F               [12]  935 	orl	a,r7
      0008AD FE               [12]  936 	mov	r6,a
                                    937 ;	assignBit
      0008AE A2 AF            [12]  938 	mov	c,_EA
      0008B0 92 00            [24]  939 	mov	_BIT_TMP,c
                                    940 ;	assignBit
      0008B2 C2 AF            [12]  941 	clr	_EA
      0008B4 75 C7 AA         [24]  942 	mov	_TA,#0xaa
      0008B7 75 C7 55         [24]  943 	mov	_TA,#0x55
      0008BA 53 91 FE         [24]  944 	anl	_SFRS,#0xfe
                                    945 ;	assignBit
      0008BD A2 00            [12]  946 	mov	c,_BIT_TMP
      0008BF 92 AF            [24]  947 	mov	_EA,c
                                    948 ;	lib\N76E003\pwm.c:59: }
      0008C1                        949 00119$:
                                    950 ;	lib\N76E003\pwm.c:61: if (cmr == 0) return 0;
      0008C1 ED               [12]  951 	mov	a,r5
      0008C2 4E               [12]  952 	orl	a,r6
      0008C3 70 03            [24]  953 	jnz	00121$
      0008C5 F5 82            [12]  954 	mov	dpl,a
      0008C7 22               [24]  955 	ret
      0008C8                        956 00121$:
                                    957 ;	lib\N76E003\pwm.c:62: return (uint8_t)(((uint32_t)(cmr + 1) * 100) / (period + 1));
      0008C8 0D               [12]  958 	inc	r5
      0008C9 BD 00 01         [24]  959 	cjne	r5,#0x00,00139$
      0008CC 0E               [12]  960 	inc	r6
      0008CD                        961 00139$:
      0008CD 8D 44            [24]  962 	mov	__mullong_PARM_2,r5
      0008CF 8E 45            [24]  963 	mov	(__mullong_PARM_2 + 1),r6
      0008D1 75 46 00         [24]  964 	mov	(__mullong_PARM_2 + 2),#0x00
      0008D4 75 47 00         [24]  965 	mov	(__mullong_PARM_2 + 3),#0x00
      0008D7 90 00 64         [24]  966 	mov	dptr,#0x0064
      0008DA E4               [12]  967 	clr	a
      0008DB F5 F0            [12]  968 	mov	b,a
      0008DD 12 16 80         [24]  969 	lcall	__mullong
      0008E0 AC 82            [24]  970 	mov	r4, dpl
      0008E2 AD 83            [24]  971 	mov	r5, dph
      0008E4 AE F0            [24]  972 	mov	r6, b
      0008E6 FF               [12]  973 	mov	r7, a
      0008E7 AA 0A            [24]  974 	mov	r2,_period
      0008E9 AB 0B            [24]  975 	mov	r3,(_period + 1)
      0008EB 0A               [12]  976 	inc	r2
      0008EC BA 00 01         [24]  977 	cjne	r2,#0x00,00140$
      0008EF 0B               [12]  978 	inc	r3
      0008F0                        979 00140$:
      0008F0 8A 44            [24]  980 	mov	__divulong_PARM_2,r2
      0008F2 8B 45            [24]  981 	mov	(__divulong_PARM_2 + 1),r3
      0008F4 75 46 00         [24]  982 	mov	(__divulong_PARM_2 + 2),#0x00
      0008F7 75 47 00         [24]  983 	mov	(__divulong_PARM_2 + 3),#0x00
      0008FA 8C 82            [24]  984 	mov	dpl, r4
      0008FC 8D 83            [24]  985 	mov	dph, r5
      0008FE 8E F0            [24]  986 	mov	b, r6
      000900 EF               [12]  987 	mov	a, r7
                                    988 ;	lib\N76E003\pwm.c:63: }
      000901 02 15 E3         [24]  989 	ljmp	__divulong
                                    990 	.area CSEG    (CODE)
                                    991 	.area CONST   (CODE)
                                    992 	.area XINIT   (CODE)
                                    993 	.area CABS    (ABS,CODE)
