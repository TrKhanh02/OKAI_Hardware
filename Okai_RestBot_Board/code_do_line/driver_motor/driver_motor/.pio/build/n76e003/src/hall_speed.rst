                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ISO C Compiler 
                                      3 ; Version 4.4.0 #14620 (MINGW32)
                                      4 ;--------------------------------------------------------
                                      5 	.module hall_speed
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
                                    244 	.globl _HallSpeed_Init
                                    245 	.globl _HallSpeed_GetCount
                                    246 	.globl _HallSpeed_GetSpeed
                                    247 	.globl _Timer0_ISR
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
      00001A                        500 _ms_counter:
      00001A                        501 	.ds 2
                                    502 ;--------------------------------------------------------
                                    503 ; overlayable items in internal ram
                                    504 ;--------------------------------------------------------
                                    505 	.area	OSEG    (OVR,DATA)
                                    506 	.area	OSEG    (OVR,DATA)
                                    507 ;--------------------------------------------------------
                                    508 ; indirectly addressable internal ram data
                                    509 ;--------------------------------------------------------
                                    510 	.area ISEG    (DATA)
                                    511 ;--------------------------------------------------------
                                    512 ; absolute internal ram data
                                    513 ;--------------------------------------------------------
                                    514 	.area IABS    (ABS,DATA)
                                    515 	.area IABS    (ABS,DATA)
                                    516 ;--------------------------------------------------------
                                    517 ; bit data
                                    518 ;--------------------------------------------------------
                                    519 	.area BSEG    (BIT)
                                    520 ;--------------------------------------------------------
                                    521 ; paged external ram data
                                    522 ;--------------------------------------------------------
                                    523 	.area PSEG    (PAG,XDATA)
                                    524 ;--------------------------------------------------------
                                    525 ; uninitialized external ram data
                                    526 ;--------------------------------------------------------
                                    527 	.area XSEG    (XDATA)
                                    528 ;--------------------------------------------------------
                                    529 ; absolute external ram data
                                    530 ;--------------------------------------------------------
                                    531 	.area XABS    (ABS,XDATA)
                                    532 ;--------------------------------------------------------
                                    533 ; initialized external ram data
                                    534 ;--------------------------------------------------------
                                    535 	.area XISEG   (XDATA)
      000061                        536 _prev_state:
      000061                        537 	.ds 4
      000065                        538 _count:
      000065                        539 	.ds 8
      00006D                        540 _speed:
      00006D                        541 	.ds 8
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
                                    559 ;	src\hall_speed.c:18: static uint16_t ms_counter = 0;
      0000CC E4               [12]  560 	clr	a
      0000CD F5 1A            [12]  561 	mov	_ms_counter,a
      0000CF F5 1B            [12]  562 	mov	(_ms_counter + 1),a
                                    563 ;--------------------------------------------------------
                                    564 ; Home
                                    565 ;--------------------------------------------------------
                                    566 	.area HOME    (CODE)
                                    567 	.area HOME    (CODE)
                                    568 ;--------------------------------------------------------
                                    569 ; code
                                    570 ;--------------------------------------------------------
                                    571 	.area CSEG    (CODE)
                                    572 ;------------------------------------------------------------
                                    573 ;Allocation info for local variables in function 'HallSpeed_Init'
                                    574 ;------------------------------------------------------------
                                    575 ;	src\hall_speed.c:20: void HallSpeed_Init(void)
                                    576 ;	-----------------------------------------
                                    577 ;	 function HallSpeed_Init
                                    578 ;	-----------------------------------------
      000E71                        579 _HallSpeed_Init:
                           000007   580 	ar7 = 0x07
                           000006   581 	ar6 = 0x06
                           000005   582 	ar5 = 0x05
                           000004   583 	ar4 = 0x04
                           000003   584 	ar3 = 0x03
                           000002   585 	ar2 = 0x02
                           000001   586 	ar1 = 0x01
                           000000   587 	ar0 = 0x00
                                    588 ;	src\hall_speed.c:23: P30_Input_Mode;
      000E71 43 AC 01         [24]  589 	orl	_P3M1,#0x01
      000E74 53 AD FE         [24]  590 	anl	_P3M2,#0xfe
                                    591 ;	src\hall_speed.c:24: P05_Input_Mode;
      000E77 43 B1 20         [24]  592 	orl	_P0M1,#0x20
      000E7A 53 B2 DF         [24]  593 	anl	_P0M2,#0xdf
                                    594 ;	src\hall_speed.c:25: P16_Input_Mode;
      000E7D 43 B3 40         [24]  595 	orl	_P1M1,#0x40
      000E80 53 B4 BF         [24]  596 	anl	_P1M2,#0xbf
                                    597 ;	src\hall_speed.c:26: P02_Input_Mode;
      000E83 43 B1 04         [24]  598 	orl	_P0M1,#0x04
      000E86 53 B2 FB         [24]  599 	anl	_P0M2,#0xfb
                                    600 ;	src\hall_speed.c:31: TIMER0_MODE1_ENABLE;
      000E89 53 89 F0         [24]  601 	anl	_TMOD,#0xf0
      000E8C 43 89 01         [24]  602 	orl	_TMOD,#0x01
                                    603 ;	src\hall_speed.c:32: clr_TF0;
                                    604 ;	assignBit
      000E8F C2 8D            [12]  605 	clr	_TF0
                                    606 ;	src\hall_speed.c:33: clr_T0M;
      000E91 53 8E F7         [24]  607 	anl	_CKCON,#0xf7
                                    608 ;	src\hall_speed.c:35: TH0 = HIBYTE(TIMER_DIV12_VALUE_100us);
      000E94 75 8C FF         [24]  609 	mov	_TH0,#0xff
                                    610 ;	src\hall_speed.c:36: TL0 = LOBYTE(TIMER_DIV12_VALUE_100us);
      000E97 75 8A 76         [24]  611 	mov	_TL0,#0x76
                                    612 ;	src\hall_speed.c:38: set_ET0; // cho phép ngắt Timer0
                                    613 ;	assignBit
      000E9A D2 A9            [12]  614 	setb	_ET0
                                    615 ;	src\hall_speed.c:39: set_EA;  // cho phép ngắt toàn cục
                                    616 ;	assignBit
      000E9C D2 AF            [12]  617 	setb	_EA
                                    618 ;	src\hall_speed.c:40: set_TR0; // bật Timer0
                                    619 ;	assignBit
      000E9E D2 8C            [12]  620 	setb	_TR0
                                    621 ;	src\hall_speed.c:41: }
      000EA0 22               [24]  622 	ret
                                    623 ;------------------------------------------------------------
                                    624 ;Allocation info for local variables in function 'HallSpeed_GetCount'
                                    625 ;------------------------------------------------------------
                                    626 ;index                     Allocated to registers r7 
                                    627 ;------------------------------------------------------------
                                    628 ;	src\hall_speed.c:46: uint16_t HallSpeed_GetCount(uint8_t index)
                                    629 ;	-----------------------------------------
                                    630 ;	 function HallSpeed_GetCount
                                    631 ;	-----------------------------------------
      000EA1                        632 _HallSpeed_GetCount:
      000EA1 AF 82            [24]  633 	mov	r7, dpl
                                    634 ;	src\hall_speed.c:48: if (index >= HALL_COUNT)
      000EA3 BF 04 00         [24]  635 	cjne	r7,#0x04,00111$
      000EA6                        636 00111$:
      000EA6 40 04            [24]  637 	jc	00102$
                                    638 ;	src\hall_speed.c:49: return 0;
      000EA8 90 00 00         [24]  639 	mov	dptr,#0x0000
      000EAB 22               [24]  640 	ret
      000EAC                        641 00102$:
                                    642 ;	src\hall_speed.c:50: return count[index];
      000EAC EF               [12]  643 	mov	a,r7
      000EAD 75 F0 02         [24]  644 	mov	b,#0x02
      000EB0 A4               [48]  645 	mul	ab
      000EB1 24 65            [12]  646 	add	a, #_count
      000EB3 F5 82            [12]  647 	mov	dpl,a
      000EB5 74 00            [12]  648 	mov	a,#(_count >> 8)
      000EB7 35 F0            [12]  649 	addc	a, b
      000EB9 F5 83            [12]  650 	mov	dph,a
      000EBB E0               [24]  651 	movx	a,@dptr
      000EBC FE               [12]  652 	mov	r6,a
      000EBD A3               [24]  653 	inc	dptr
      000EBE E0               [24]  654 	movx	a,@dptr
                                    655 ;	src\hall_speed.c:51: }
      000EBF 8E 82            [24]  656 	mov	dpl,r6
      000EC1 F5 83            [12]  657 	mov	dph,a
      000EC3 22               [24]  658 	ret
                                    659 ;------------------------------------------------------------
                                    660 ;Allocation info for local variables in function 'HallSpeed_GetSpeed'
                                    661 ;------------------------------------------------------------
                                    662 ;index                     Allocated to registers r7 
                                    663 ;------------------------------------------------------------
                                    664 ;	src\hall_speed.c:53: uint16_t HallSpeed_GetSpeed(uint8_t index)
                                    665 ;	-----------------------------------------
                                    666 ;	 function HallSpeed_GetSpeed
                                    667 ;	-----------------------------------------
      000EC4                        668 _HallSpeed_GetSpeed:
      000EC4 AF 82            [24]  669 	mov	r7, dpl
                                    670 ;	src\hall_speed.c:55: if (index >= HALL_COUNT)
      000EC6 BF 04 00         [24]  671 	cjne	r7,#0x04,00111$
      000EC9                        672 00111$:
      000EC9 40 04            [24]  673 	jc	00102$
                                    674 ;	src\hall_speed.c:56: return 0;
      000ECB 90 00 00         [24]  675 	mov	dptr,#0x0000
      000ECE 22               [24]  676 	ret
      000ECF                        677 00102$:
                                    678 ;	src\hall_speed.c:57: return speed[index];
      000ECF EF               [12]  679 	mov	a,r7
      000ED0 75 F0 02         [24]  680 	mov	b,#0x02
      000ED3 A4               [48]  681 	mul	ab
      000ED4 24 6D            [12]  682 	add	a, #_speed
      000ED6 F5 82            [12]  683 	mov	dpl,a
      000ED8 74 00            [12]  684 	mov	a,#(_speed >> 8)
      000EDA 35 F0            [12]  685 	addc	a, b
      000EDC F5 83            [12]  686 	mov	dph,a
      000EDE E0               [24]  687 	movx	a,@dptr
      000EDF FE               [12]  688 	mov	r6,a
      000EE0 A3               [24]  689 	inc	dptr
      000EE1 E0               [24]  690 	movx	a,@dptr
                                    691 ;	src\hall_speed.c:58: }
      000EE2 8E 82            [24]  692 	mov	dpl,r6
      000EE4 F5 83            [12]  693 	mov	dph,a
      000EE6 22               [24]  694 	ret
                                    695 ;------------------------------------------------------------
                                    696 ;Allocation info for local variables in function 'Timer0_ISR'
                                    697 ;------------------------------------------------------------
                                    698 ;i                         Allocated to registers r7 
                                    699 ;hall_now                  Allocated to registers r6 
                                    700 ;------------------------------------------------------------
                                    701 ;	src\hall_speed.c:64: void Timer0_ISR(void) __interrupt(1)
                                    702 ;	-----------------------------------------
                                    703 ;	 function Timer0_ISR
                                    704 ;	-----------------------------------------
      000EE7                        705 _Timer0_ISR:
      000EE7 C0 E0            [24]  706 	push	acc
      000EE9 C0 F0            [24]  707 	push	b
      000EEB C0 82            [24]  708 	push	dpl
      000EED C0 83            [24]  709 	push	dph
      000EEF C0 07            [24]  710 	push	ar7
      000EF1 C0 06            [24]  711 	push	ar6
      000EF3 C0 05            [24]  712 	push	ar5
      000EF5 C0 04            [24]  713 	push	ar4
      000EF7 C0 03            [24]  714 	push	ar3
      000EF9 C0 02            [24]  715 	push	ar2
      000EFB C0 D0            [24]  716 	push	psw
      000EFD 75 D0 00         [24]  717 	mov	psw,#0x00
                                    718 ;	src\hall_speed.c:66: clr_TF0; // xóa cờ tràn
                                    719 ;	assignBit
      000F00 C2 8D            [12]  720 	clr	_TF0
                                    721 ;	src\hall_speed.c:71: for (i = 0; i < HALL_COUNT; i++)
      000F02 7F 00            [12]  722 	mov	r7,#0x00
      000F04                        723 00116$:
                                    724 ;	src\hall_speed.c:73: switch (i)
      000F04 EF               [12]  725 	mov	a,r7
      000F05 2F               [12]  726 	add	a,r7
                                    727 ;	src\hall_speed.c:75: case 0:
      000F06 90 0F 0A         [24]  728 	mov	dptr,#00174$
      000F09 73               [24]  729 	jmp	@a+dptr
      000F0A                        730 00174$:
      000F0A 80 06            [24]  731 	sjmp	00101$
      000F0C 80 0B            [24]  732 	sjmp	00102$
      000F0E 80 10            [24]  733 	sjmp	00103$
      000F10 80 15            [24]  734 	sjmp	00104$
      000F12                        735 00101$:
                                    736 ;	src\hall_speed.c:76: hall_now = HALL1;
      000F12 A2 B0            [12]  737 	mov	c,_P30
      000F14 E4               [12]  738 	clr	a
      000F15 33               [12]  739 	rlc	a
      000F16 FE               [12]  740 	mov	r6,a
                                    741 ;	src\hall_speed.c:77: break;
                                    742 ;	src\hall_speed.c:78: case 1:
      000F17 80 13            [24]  743 	sjmp	00105$
      000F19                        744 00102$:
                                    745 ;	src\hall_speed.c:79: hall_now = HALL2;
      000F19 A2 85            [12]  746 	mov	c,_P05
      000F1B E4               [12]  747 	clr	a
      000F1C 33               [12]  748 	rlc	a
      000F1D FE               [12]  749 	mov	r6,a
                                    750 ;	src\hall_speed.c:80: break;
                                    751 ;	src\hall_speed.c:81: case 2:
      000F1E 80 0C            [24]  752 	sjmp	00105$
      000F20                        753 00103$:
                                    754 ;	src\hall_speed.c:82: hall_now = HALL3;
      000F20 A2 96            [12]  755 	mov	c,_P16
      000F22 E4               [12]  756 	clr	a
      000F23 33               [12]  757 	rlc	a
      000F24 FE               [12]  758 	mov	r6,a
                                    759 ;	src\hall_speed.c:83: break;
                                    760 ;	src\hall_speed.c:84: case 3:
      000F25 80 05            [24]  761 	sjmp	00105$
      000F27                        762 00104$:
                                    763 ;	src\hall_speed.c:85: hall_now = HALL4;
      000F27 A2 82            [12]  764 	mov	c,_P02
      000F29 E4               [12]  765 	clr	a
      000F2A 33               [12]  766 	rlc	a
      000F2B FE               [12]  767 	mov	r6,a
                                    768 ;	src\hall_speed.c:87: }
      000F2C                        769 00105$:
                                    770 ;	src\hall_speed.c:90: if (!prev_state[i] && hall_now)
      000F2C EF               [12]  771 	mov	a,r7
      000F2D 24 61            [12]  772 	add	a, #_prev_state
      000F2F FC               [12]  773 	mov	r4,a
      000F30 E4               [12]  774 	clr	a
      000F31 34 00            [12]  775 	addc	a, #(_prev_state >> 8)
      000F33 FD               [12]  776 	mov	r5,a
      000F34 8C 82            [24]  777 	mov	dpl,r4
      000F36 8D 83            [24]  778 	mov	dph,r5
      000F38 E0               [24]  779 	movx	a,@dptr
      000F39 70 27            [24]  780 	jnz	00107$
      000F3B EE               [12]  781 	mov	a,r6
      000F3C 60 24            [24]  782 	jz	00107$
                                    783 ;	src\hall_speed.c:91: count[i]++;
      000F3E EF               [12]  784 	mov	a,r7
      000F3F 75 F0 02         [24]  785 	mov	b,#0x02
      000F42 A4               [48]  786 	mul	ab
      000F43 24 65            [12]  787 	add	a, #_count
      000F45 FC               [12]  788 	mov	r4,a
      000F46 74 00            [12]  789 	mov	a,#(_count >> 8)
      000F48 35 F0            [12]  790 	addc	a, b
      000F4A FD               [12]  791 	mov	r5,a
      000F4B 8C 82            [24]  792 	mov	dpl,r4
      000F4D 8D 83            [24]  793 	mov	dph,r5
      000F4F E0               [24]  794 	movx	a,@dptr
      000F50 FA               [12]  795 	mov	r2,a
      000F51 A3               [24]  796 	inc	dptr
      000F52 E0               [24]  797 	movx	a,@dptr
      000F53 FB               [12]  798 	mov	r3,a
      000F54 0A               [12]  799 	inc	r2
      000F55 BA 00 01         [24]  800 	cjne	r2,#0x00,00177$
      000F58 0B               [12]  801 	inc	r3
      000F59                        802 00177$:
      000F59 8C 82            [24]  803 	mov	dpl,r4
      000F5B 8D 83            [24]  804 	mov	dph,r5
      000F5D EA               [12]  805 	mov	a,r2
      000F5E F0               [24]  806 	movx	@dptr,a
      000F5F EB               [12]  807 	mov	a,r3
      000F60 A3               [24]  808 	inc	dptr
      000F61 F0               [24]  809 	movx	@dptr,a
      000F62                        810 00107$:
                                    811 ;	src\hall_speed.c:93: prev_state[i] = hall_now;
      000F62 EF               [12]  812 	mov	a,r7
      000F63 24 61            [12]  813 	add	a, #_prev_state
      000F65 F5 82            [12]  814 	mov	dpl,a
      000F67 E4               [12]  815 	clr	a
      000F68 34 00            [12]  816 	addc	a, #(_prev_state >> 8)
      000F6A F5 83            [12]  817 	mov	dph,a
      000F6C EE               [12]  818 	mov	a,r6
      000F6D F0               [24]  819 	movx	@dptr,a
                                    820 ;	src\hall_speed.c:71: for (i = 0; i < HALL_COUNT; i++)
      000F6E 0F               [12]  821 	inc	r7
      000F6F BF 04 00         [24]  822 	cjne	r7,#0x04,00178$
      000F72                        823 00178$:
      000F72 40 90            [24]  824 	jc	00116$
                                    825 ;	src\hall_speed.c:96: if (++ms_counter >= 2560) //400us
      000F74 05 1A            [12]  826 	inc	_ms_counter
      000F76 E4               [12]  827 	clr	a
      000F77 B5 1A 02         [24]  828 	cjne	a,_ms_counter,00180$
      000F7A 05 1B            [12]  829 	inc	(_ms_counter + 1)
      000F7C                        830 00180$:
      000F7C AF 1B            [24]  831 	mov	r7,(_ms_counter + 1)
      000F7E 74 F6            [12]  832 	mov	a,#0x100 - 0x0a
      000F80 2F               [12]  833 	add	a,r7
      000F81 50 58            [24]  834 	jnc	00115$
                                    835 ;	src\hall_speed.c:98: for (i = 0; i < HALL_COUNT; i++)
      000F83 7F 00            [12]  836 	mov	r7,#0x00
      000F85                        837 00118$:
                                    838 ;	src\hall_speed.c:100: if (count[i] > 0)
      000F85 EF               [12]  839 	mov	a,r7
      000F86 75 F0 02         [24]  840 	mov	b,#0x02
      000F89 A4               [48]  841 	mul	ab
      000F8A FD               [12]  842 	mov	r5,a
      000F8B AE F0            [24]  843 	mov	r6,b
      000F8D 24 65            [12]  844 	add	a, #_count
      000F8F F5 82            [12]  845 	mov	dpl,a
      000F91 EE               [12]  846 	mov	a,r6
      000F92 34 00            [12]  847 	addc	a, #(_count >> 8)
      000F94 F5 83            [12]  848 	mov	dph,a
      000F96 E0               [24]  849 	movx	a,@dptr
      000F97 FB               [12]  850 	mov	r3,a
      000F98 A3               [24]  851 	inc	dptr
      000F99 E0               [24]  852 	movx	a,@dptr
      000F9A FC               [12]  853 	mov	r4,a
      000F9B 4B               [12]  854 	orl	a,r3
      000F9C 60 11            [24]  855 	jz	00111$
                                    856 ;	src\hall_speed.c:101: speed[i] = count[i]; // có xung → cập nhật
      000F9E ED               [12]  857 	mov	a,r5
      000F9F 24 6D            [12]  858 	add	a, #_speed
      000FA1 F5 82            [12]  859 	mov	dpl,a
      000FA3 EE               [12]  860 	mov	a,r6
      000FA4 34 00            [12]  861 	addc	a, #(_speed >> 8)
      000FA6 F5 83            [12]  862 	mov	dph,a
      000FA8 EB               [12]  863 	mov	a,r3
      000FA9 F0               [24]  864 	movx	@dptr,a
      000FAA EC               [12]  865 	mov	a,r4
      000FAB A3               [24]  866 	inc	dptr
      000FAC F0               [24]  867 	movx	@dptr,a
      000FAD 80 0E            [24]  868 	sjmp	00112$
      000FAF                        869 00111$:
                                    870 ;	src\hall_speed.c:103: speed[i] = 0; // không có xung → bằng 0
      000FAF ED               [12]  871 	mov	a,r5
      000FB0 24 6D            [12]  872 	add	a, #_speed
      000FB2 F5 82            [12]  873 	mov	dpl,a
      000FB4 EE               [12]  874 	mov	a,r6
      000FB5 34 00            [12]  875 	addc	a, #(_speed >> 8)
      000FB7 F5 83            [12]  876 	mov	dph,a
      000FB9 E4               [12]  877 	clr	a
      000FBA F0               [24]  878 	movx	@dptr,a
      000FBB A3               [24]  879 	inc	dptr
      000FBC F0               [24]  880 	movx	@dptr,a
      000FBD                        881 00112$:
                                    882 ;	src\hall_speed.c:104: count[i] = 0;
      000FBD EF               [12]  883 	mov	a,r7
      000FBE 75 F0 02         [24]  884 	mov	b,#0x02
      000FC1 A4               [48]  885 	mul	ab
      000FC2 24 65            [12]  886 	add	a, #_count
      000FC4 F5 82            [12]  887 	mov	dpl,a
      000FC6 74 00            [12]  888 	mov	a,#(_count >> 8)
      000FC8 35 F0            [12]  889 	addc	a, b
      000FCA F5 83            [12]  890 	mov	dph,a
      000FCC E4               [12]  891 	clr	a
      000FCD F0               [24]  892 	movx	@dptr,a
      000FCE A3               [24]  893 	inc	dptr
      000FCF F0               [24]  894 	movx	@dptr,a
                                    895 ;	src\hall_speed.c:98: for (i = 0; i < HALL_COUNT; i++)
      000FD0 0F               [12]  896 	inc	r7
      000FD1 BF 04 00         [24]  897 	cjne	r7,#0x04,00183$
      000FD4                        898 00183$:
      000FD4 40 AF            [24]  899 	jc	00118$
                                    900 ;	src\hall_speed.c:106: ms_counter = 0;
      000FD6 E4               [12]  901 	clr	a
      000FD7 F5 1A            [12]  902 	mov	_ms_counter,a
      000FD9 F5 1B            [12]  903 	mov	(_ms_counter + 1),a
      000FDB                        904 00115$:
                                    905 ;	src\hall_speed.c:110: TH0 = HIBYTE(TIMER_DIV12_VALUE_100us);
      000FDB 75 8C FF         [24]  906 	mov	_TH0,#0xff
                                    907 ;	src\hall_speed.c:111: TL0 = LOBYTE(TIMER_DIV12_VALUE_100us);
      000FDE 75 8A 76         [24]  908 	mov	_TL0,#0x76
                                    909 ;	src\hall_speed.c:112: }
      000FE1 D0 D0            [24]  910 	pop	psw
      000FE3 D0 02            [24]  911 	pop	ar2
      000FE5 D0 03            [24]  912 	pop	ar3
      000FE7 D0 04            [24]  913 	pop	ar4
      000FE9 D0 05            [24]  914 	pop	ar5
      000FEB D0 06            [24]  915 	pop	ar6
      000FED D0 07            [24]  916 	pop	ar7
      000FEF D0 83            [24]  917 	pop	dph
      000FF1 D0 82            [24]  918 	pop	dpl
      000FF3 D0 F0            [24]  919 	pop	b
      000FF5 D0 E0            [24]  920 	pop	acc
      000FF7 32               [24]  921 	reti
                                    922 	.area CSEG    (CODE)
                                    923 	.area CONST   (CODE)
                                    924 	.area XINIT   (CODE)
      001734                        925 __xinit__prev_state:
      001734 00                     926 	.db #0x00	; 0
      001735 00                     927 	.db 0x00
      001736 00                     928 	.db 0x00
      001737 00                     929 	.db 0x00
      001738                        930 __xinit__count:
      001738 00 00                  931 	.byte #0x00, #0x00	; 0
      00173A 00                     932 	.db 0x00
      00173B 00                     933 	.db 0x00
      00173C 00                     934 	.db 0x00
      00173D 00                     935 	.db 0x00
      00173E 00                     936 	.db 0x00
      00173F 00                     937 	.db 0x00
      001740                        938 __xinit__speed:
      001740 00 00                  939 	.byte #0x00, #0x00	; 0
      001742 00                     940 	.db 0x00
      001743 00                     941 	.db 0x00
      001744 00                     942 	.db 0x00
      001745 00                     943 	.db 0x00
      001746 00                     944 	.db 0x00
      001747 00                     945 	.db 0x00
                                    946 	.area CABS    (ABS,CODE)
