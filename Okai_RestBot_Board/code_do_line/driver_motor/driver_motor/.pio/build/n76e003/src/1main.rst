                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ISO C Compiler 
                                      3 ; Version 4.4.0 #14620 (MINGW32)
                                      4 ;--------------------------------------------------------
                                      5 	.module 1main
                                      6 	.optsdcc -mmcs51 --model-small
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _main
                                     12 	.globl _Millis
                                     13 	.globl _Millis_Init
                                     14 	.globl _parse_json
                                     15 	.globl _MODIFY_HIRC
                                     16 	.globl _UART0_Available
                                     17 	.globl _UART0_GetChar
                                     18 	.globl _UART0_Init
                                     19 	.globl _PWM_GetDuty
                                     20 	.globl _PWM_SetDuty
                                     21 	.globl _PWM_Init
                                     22 	.globl _MOSI
                                     23 	.globl _P00
                                     24 	.globl _MISO
                                     25 	.globl _P01
                                     26 	.globl _RXD_1
                                     27 	.globl _P02
                                     28 	.globl _P03
                                     29 	.globl _STADC
                                     30 	.globl _P04
                                     31 	.globl _P05
                                     32 	.globl _TXD
                                     33 	.globl _P06
                                     34 	.globl _RXD
                                     35 	.globl _P07
                                     36 	.globl _IT0
                                     37 	.globl _IE0
                                     38 	.globl _IT1
                                     39 	.globl _IE1
                                     40 	.globl _TR0
                                     41 	.globl _TF0
                                     42 	.globl _TR1
                                     43 	.globl _TF1
                                     44 	.globl _P10
                                     45 	.globl _P11
                                     46 	.globl _P12
                                     47 	.globl _SCL
                                     48 	.globl _P13
                                     49 	.globl _SDA
                                     50 	.globl _P14
                                     51 	.globl _P15
                                     52 	.globl _TXD_1
                                     53 	.globl _P16
                                     54 	.globl _P17
                                     55 	.globl _RI
                                     56 	.globl _TI
                                     57 	.globl _RB8
                                     58 	.globl _TB8
                                     59 	.globl _REN
                                     60 	.globl _SM2
                                     61 	.globl _SM1
                                     62 	.globl _FE
                                     63 	.globl _SM0
                                     64 	.globl _P20
                                     65 	.globl _EX0
                                     66 	.globl _ET0
                                     67 	.globl _EX1
                                     68 	.globl _ET1
                                     69 	.globl _ES
                                     70 	.globl _EBOD
                                     71 	.globl _EADC
                                     72 	.globl _EA
                                     73 	.globl _P30
                                     74 	.globl _PX0
                                     75 	.globl _PT0
                                     76 	.globl _PX1
                                     77 	.globl _PT1
                                     78 	.globl _PS
                                     79 	.globl _PBOD
                                     80 	.globl _PADC
                                     81 	.globl _I2CPX
                                     82 	.globl _AA
                                     83 	.globl _SI
                                     84 	.globl _STO
                                     85 	.globl _STA
                                     86 	.globl _I2CEN
                                     87 	.globl _CM_RL2
                                     88 	.globl _TR2
                                     89 	.globl _TF2
                                     90 	.globl _P
                                     91 	.globl _OV
                                     92 	.globl _RS0
                                     93 	.globl _RS1
                                     94 	.globl _F0
                                     95 	.globl _AC
                                     96 	.globl _CY
                                     97 	.globl _CLRPWM
                                     98 	.globl _PWMF
                                     99 	.globl _LOAD
                                    100 	.globl _PWMRUN
                                    101 	.globl _ADCHS0
                                    102 	.globl _ADCHS1
                                    103 	.globl _ADCHS2
                                    104 	.globl _ADCHS3
                                    105 	.globl _ETGSEL0
                                    106 	.globl _ETGSEL1
                                    107 	.globl _ADCS
                                    108 	.globl _ADCF
                                    109 	.globl _RI_1
                                    110 	.globl _TI_1
                                    111 	.globl _RB8_1
                                    112 	.globl _TB8_1
                                    113 	.globl _REN_1
                                    114 	.globl _SM2_1
                                    115 	.globl _SM1_1
                                    116 	.globl _FE_1
                                    117 	.globl _SM0_1
                                    118 	.globl _EIPH1
                                    119 	.globl _EIP1
                                    120 	.globl _PORDIS
                                    121 	.globl _PMD
                                    122 	.globl _PMEN
                                    123 	.globl _PDTCNT
                                    124 	.globl _PDTEN
                                    125 	.globl _SCON_1
                                    126 	.globl _EIPH
                                    127 	.globl _AINDIDS
                                    128 	.globl _SPDR
                                    129 	.globl _SPSR
                                    130 	.globl _SPCR2
                                    131 	.globl _SPCR
                                    132 	.globl _CAPCON4
                                    133 	.globl _CAPCON3
                                    134 	.globl _B
                                    135 	.globl _EIP
                                    136 	.globl _C2H
                                    137 	.globl _C2L
                                    138 	.globl _PIF
                                    139 	.globl _PIPEN
                                    140 	.globl _PINEN
                                    141 	.globl _PICON
                                    142 	.globl _ADCCON0
                                    143 	.globl _C1H
                                    144 	.globl _C1L
                                    145 	.globl _C0H
                                    146 	.globl _C0L
                                    147 	.globl _ADCDLY
                                    148 	.globl _ADCCON2
                                    149 	.globl _ADCCON1
                                    150 	.globl _ACC
                                    151 	.globl _PWMCON1
                                    152 	.globl _PIOCON0
                                    153 	.globl _PWM3L
                                    154 	.globl _PWM2L
                                    155 	.globl _PWM1L
                                    156 	.globl _PWM0L
                                    157 	.globl _PWMPL
                                    158 	.globl _PWMCON0
                                    159 	.globl _FBD
                                    160 	.globl _PNP
                                    161 	.globl _PWM3H
                                    162 	.globl _PWM2H
                                    163 	.globl _PWM1H
                                    164 	.globl _PWM0H
                                    165 	.globl _PWMPH
                                    166 	.globl _PSW
                                    167 	.globl _ADCMPH
                                    168 	.globl _ADCMPL
                                    169 	.globl _PWM5L
                                    170 	.globl _TH2
                                    171 	.globl _PWM4L
                                    172 	.globl _TL2
                                    173 	.globl _RCMP2H
                                    174 	.globl _RCMP2L
                                    175 	.globl _T2MOD
                                    176 	.globl _T2CON
                                    177 	.globl _TA
                                    178 	.globl _PIOCON1
                                    179 	.globl _RH3
                                    180 	.globl _PWM5H
                                    181 	.globl _RL3
                                    182 	.globl _PWM4H
                                    183 	.globl _T3CON
                                    184 	.globl _ADCRH
                                    185 	.globl _ADCRL
                                    186 	.globl _I2ADDR
                                    187 	.globl _I2CON
                                    188 	.globl _I2TOC
                                    189 	.globl _I2CLK
                                    190 	.globl _I2STAT
                                    191 	.globl _I2DAT
                                    192 	.globl _SADDR_1
                                    193 	.globl _SADEN_1
                                    194 	.globl _SADEN
                                    195 	.globl _IP
                                    196 	.globl _PWMINTC
                                    197 	.globl _IPH
                                    198 	.globl _P2S
                                    199 	.globl _P1SR
                                    200 	.globl _P1M2
                                    201 	.globl _P1S
                                    202 	.globl _P1M1
                                    203 	.globl _P0SR
                                    204 	.globl _P0M2
                                    205 	.globl _P0S
                                    206 	.globl _P0M1
                                    207 	.globl _P3
                                    208 	.globl _IAPCN
                                    209 	.globl _IAPFD
                                    210 	.globl _P3SR
                                    211 	.globl _P3M2
                                    212 	.globl _P3S
                                    213 	.globl _P3M1
                                    214 	.globl _BODCON1
                                    215 	.globl _WDCON
                                    216 	.globl _SADDR
                                    217 	.globl _IE
                                    218 	.globl _IAPAH
                                    219 	.globl _IAPAL
                                    220 	.globl _IAPUEN
                                    221 	.globl _IAPTRG
                                    222 	.globl _BODCON0
                                    223 	.globl _AUXR1
                                    224 	.globl _P2
                                    225 	.globl _CHPCON
                                    226 	.globl _EIE1
                                    227 	.globl _EIE
                                    228 	.globl _SBUF_1
                                    229 	.globl _SBUF
                                    230 	.globl _SCON
                                    231 	.globl _CKEN
                                    232 	.globl _CKSWT
                                    233 	.globl _CKDIV
                                    234 	.globl _CAPCON2
                                    235 	.globl _CAPCON1
                                    236 	.globl _CAPCON0
                                    237 	.globl _SFRS
                                    238 	.globl _P1
                                    239 	.globl _WKCON
                                    240 	.globl _CKCON
                                    241 	.globl _TH1
                                    242 	.globl _TH0
                                    243 	.globl _TL1
                                    244 	.globl _TL0
                                    245 	.globl _TMOD
                                    246 	.globl _TCON
                                    247 	.globl _PCON
                                    248 	.globl _RWK
                                    249 	.globl _RCTRIM1
                                    250 	.globl _RCTRIM0
                                    251 	.globl _DPH
                                    252 	.globl _DPL
                                    253 	.globl _SP
                                    254 	.globl _P0
                                    255 	.globl _timeDelay
                                    256 	.globl _previous
                                    257 	.globl _json
                                    258 	.globl _dataRx
                                    259 	.globl _flagMotor
                                    260 	.globl _flagJson
                                    261 	.globl _sigT
                                    262 	.globl _sig2
                                    263 	.globl _sig1
                                    264 	.globl _i
                                    265 ;--------------------------------------------------------
                                    266 ; special function registers
                                    267 ;--------------------------------------------------------
                                    268 	.area RSEG    (ABS,DATA)
      000000                        269 	.org 0x0000
                           000080   270 _P0	=	0x0080
                           000081   271 _SP	=	0x0081
                           000082   272 _DPL	=	0x0082
                           000083   273 _DPH	=	0x0083
                           000084   274 _RCTRIM0	=	0x0084
                           000085   275 _RCTRIM1	=	0x0085
                           000086   276 _RWK	=	0x0086
                           000087   277 _PCON	=	0x0087
                           000088   278 _TCON	=	0x0088
                           000089   279 _TMOD	=	0x0089
                           00008A   280 _TL0	=	0x008a
                           00008B   281 _TL1	=	0x008b
                           00008C   282 _TH0	=	0x008c
                           00008D   283 _TH1	=	0x008d
                           00008E   284 _CKCON	=	0x008e
                           00008F   285 _WKCON	=	0x008f
                           000090   286 _P1	=	0x0090
                           000091   287 _SFRS	=	0x0091
                           000092   288 _CAPCON0	=	0x0092
                           000093   289 _CAPCON1	=	0x0093
                           000094   290 _CAPCON2	=	0x0094
                           000095   291 _CKDIV	=	0x0095
                           000096   292 _CKSWT	=	0x0096
                           000097   293 _CKEN	=	0x0097
                           000098   294 _SCON	=	0x0098
                           000099   295 _SBUF	=	0x0099
                           00009A   296 _SBUF_1	=	0x009a
                           00009B   297 _EIE	=	0x009b
                           00009C   298 _EIE1	=	0x009c
                           00009F   299 _CHPCON	=	0x009f
                           0000A0   300 _P2	=	0x00a0
                           0000A2   301 _AUXR1	=	0x00a2
                           0000A3   302 _BODCON0	=	0x00a3
                           0000A4   303 _IAPTRG	=	0x00a4
                           0000A5   304 _IAPUEN	=	0x00a5
                           0000A6   305 _IAPAL	=	0x00a6
                           0000A7   306 _IAPAH	=	0x00a7
                           0000A8   307 _IE	=	0x00a8
                           0000A9   308 _SADDR	=	0x00a9
                           0000AA   309 _WDCON	=	0x00aa
                           0000AB   310 _BODCON1	=	0x00ab
                           0000AC   311 _P3M1	=	0x00ac
                           0000AC   312 _P3S	=	0x00ac
                           0000AD   313 _P3M2	=	0x00ad
                           0000AD   314 _P3SR	=	0x00ad
                           0000AE   315 _IAPFD	=	0x00ae
                           0000AF   316 _IAPCN	=	0x00af
                           0000B0   317 _P3	=	0x00b0
                           0000B1   318 _P0M1	=	0x00b1
                           0000B1   319 _P0S	=	0x00b1
                           0000B2   320 _P0M2	=	0x00b2
                           0000B2   321 _P0SR	=	0x00b2
                           0000B3   322 _P1M1	=	0x00b3
                           0000B3   323 _P1S	=	0x00b3
                           0000B4   324 _P1M2	=	0x00b4
                           0000B4   325 _P1SR	=	0x00b4
                           0000B5   326 _P2S	=	0x00b5
                           0000B7   327 _IPH	=	0x00b7
                           0000B7   328 _PWMINTC	=	0x00b7
                           0000B8   329 _IP	=	0x00b8
                           0000B9   330 _SADEN	=	0x00b9
                           0000BA   331 _SADEN_1	=	0x00ba
                           0000BB   332 _SADDR_1	=	0x00bb
                           0000BC   333 _I2DAT	=	0x00bc
                           0000BD   334 _I2STAT	=	0x00bd
                           0000BE   335 _I2CLK	=	0x00be
                           0000BF   336 _I2TOC	=	0x00bf
                           0000C0   337 _I2CON	=	0x00c0
                           0000C1   338 _I2ADDR	=	0x00c1
                           0000C2   339 _ADCRL	=	0x00c2
                           0000C3   340 _ADCRH	=	0x00c3
                           0000C4   341 _T3CON	=	0x00c4
                           0000C4   342 _PWM4H	=	0x00c4
                           0000C5   343 _RL3	=	0x00c5
                           0000C5   344 _PWM5H	=	0x00c5
                           0000C6   345 _RH3	=	0x00c6
                           0000C6   346 _PIOCON1	=	0x00c6
                           0000C7   347 _TA	=	0x00c7
                           0000C8   348 _T2CON	=	0x00c8
                           0000C9   349 _T2MOD	=	0x00c9
                           0000CA   350 _RCMP2L	=	0x00ca
                           0000CB   351 _RCMP2H	=	0x00cb
                           0000CC   352 _TL2	=	0x00cc
                           0000CC   353 _PWM4L	=	0x00cc
                           0000CD   354 _TH2	=	0x00cd
                           0000CD   355 _PWM5L	=	0x00cd
                           0000CE   356 _ADCMPL	=	0x00ce
                           0000CF   357 _ADCMPH	=	0x00cf
                           0000D0   358 _PSW	=	0x00d0
                           0000D1   359 _PWMPH	=	0x00d1
                           0000D2   360 _PWM0H	=	0x00d2
                           0000D3   361 _PWM1H	=	0x00d3
                           0000D4   362 _PWM2H	=	0x00d4
                           0000D5   363 _PWM3H	=	0x00d5
                           0000D6   364 _PNP	=	0x00d6
                           0000D7   365 _FBD	=	0x00d7
                           0000D8   366 _PWMCON0	=	0x00d8
                           0000D9   367 _PWMPL	=	0x00d9
                           0000DA   368 _PWM0L	=	0x00da
                           0000DB   369 _PWM1L	=	0x00db
                           0000DC   370 _PWM2L	=	0x00dc
                           0000DD   371 _PWM3L	=	0x00dd
                           0000DE   372 _PIOCON0	=	0x00de
                           0000DF   373 _PWMCON1	=	0x00df
                           0000E0   374 _ACC	=	0x00e0
                           0000E1   375 _ADCCON1	=	0x00e1
                           0000E2   376 _ADCCON2	=	0x00e2
                           0000E3   377 _ADCDLY	=	0x00e3
                           0000E4   378 _C0L	=	0x00e4
                           0000E5   379 _C0H	=	0x00e5
                           0000E6   380 _C1L	=	0x00e6
                           0000E7   381 _C1H	=	0x00e7
                           0000E8   382 _ADCCON0	=	0x00e8
                           0000E9   383 _PICON	=	0x00e9
                           0000EA   384 _PINEN	=	0x00ea
                           0000EB   385 _PIPEN	=	0x00eb
                           0000EC   386 _PIF	=	0x00ec
                           0000ED   387 _C2L	=	0x00ed
                           0000EE   388 _C2H	=	0x00ee
                           0000EF   389 _EIP	=	0x00ef
                           0000F0   390 _B	=	0x00f0
                           0000F1   391 _CAPCON3	=	0x00f1
                           0000F2   392 _CAPCON4	=	0x00f2
                           0000F3   393 _SPCR	=	0x00f3
                           0000F3   394 _SPCR2	=	0x00f3
                           0000F4   395 _SPSR	=	0x00f4
                           0000F5   396 _SPDR	=	0x00f5
                           0000F6   397 _AINDIDS	=	0x00f6
                           0000F7   398 _EIPH	=	0x00f7
                           0000F8   399 _SCON_1	=	0x00f8
                           0000F9   400 _PDTEN	=	0x00f9
                           0000FA   401 _PDTCNT	=	0x00fa
                           0000FB   402 _PMEN	=	0x00fb
                           0000FC   403 _PMD	=	0x00fc
                           0000FD   404 _PORDIS	=	0x00fd
                           0000FE   405 _EIP1	=	0x00fe
                           0000FF   406 _EIPH1	=	0x00ff
                                    407 ;--------------------------------------------------------
                                    408 ; special function bits
                                    409 ;--------------------------------------------------------
                                    410 	.area RSEG    (ABS,DATA)
      000000                        411 	.org 0x0000
                           0000FF   412 _SM0_1	=	0x00ff
                           0000FF   413 _FE_1	=	0x00ff
                           0000FE   414 _SM1_1	=	0x00fe
                           0000FD   415 _SM2_1	=	0x00fd
                           0000FC   416 _REN_1	=	0x00fc
                           0000FB   417 _TB8_1	=	0x00fb
                           0000FA   418 _RB8_1	=	0x00fa
                           0000F9   419 _TI_1	=	0x00f9
                           0000F8   420 _RI_1	=	0x00f8
                           0000EF   421 _ADCF	=	0x00ef
                           0000EE   422 _ADCS	=	0x00ee
                           0000ED   423 _ETGSEL1	=	0x00ed
                           0000EC   424 _ETGSEL0	=	0x00ec
                           0000EB   425 _ADCHS3	=	0x00eb
                           0000EA   426 _ADCHS2	=	0x00ea
                           0000E9   427 _ADCHS1	=	0x00e9
                           0000E8   428 _ADCHS0	=	0x00e8
                           0000DF   429 _PWMRUN	=	0x00df
                           0000DE   430 _LOAD	=	0x00de
                           0000DD   431 _PWMF	=	0x00dd
                           0000DC   432 _CLRPWM	=	0x00dc
                           0000D7   433 _CY	=	0x00d7
                           0000D6   434 _AC	=	0x00d6
                           0000D5   435 _F0	=	0x00d5
                           0000D4   436 _RS1	=	0x00d4
                           0000D3   437 _RS0	=	0x00d3
                           0000D2   438 _OV	=	0x00d2
                           0000D0   439 _P	=	0x00d0
                           0000CF   440 _TF2	=	0x00cf
                           0000CA   441 _TR2	=	0x00ca
                           0000C8   442 _CM_RL2	=	0x00c8
                           0000C6   443 _I2CEN	=	0x00c6
                           0000C5   444 _STA	=	0x00c5
                           0000C4   445 _STO	=	0x00c4
                           0000C3   446 _SI	=	0x00c3
                           0000C2   447 _AA	=	0x00c2
                           0000C0   448 _I2CPX	=	0x00c0
                           0000BE   449 _PADC	=	0x00be
                           0000BD   450 _PBOD	=	0x00bd
                           0000BC   451 _PS	=	0x00bc
                           0000BB   452 _PT1	=	0x00bb
                           0000BA   453 _PX1	=	0x00ba
                           0000B9   454 _PT0	=	0x00b9
                           0000B8   455 _PX0	=	0x00b8
                           0000B0   456 _P30	=	0x00b0
                           0000AF   457 _EA	=	0x00af
                           0000AE   458 _EADC	=	0x00ae
                           0000AD   459 _EBOD	=	0x00ad
                           0000AC   460 _ES	=	0x00ac
                           0000AB   461 _ET1	=	0x00ab
                           0000AA   462 _EX1	=	0x00aa
                           0000A9   463 _ET0	=	0x00a9
                           0000A8   464 _EX0	=	0x00a8
                           0000A0   465 _P20	=	0x00a0
                           00009F   466 _SM0	=	0x009f
                           00009F   467 _FE	=	0x009f
                           00009E   468 _SM1	=	0x009e
                           00009D   469 _SM2	=	0x009d
                           00009C   470 _REN	=	0x009c
                           00009B   471 _TB8	=	0x009b
                           00009A   472 _RB8	=	0x009a
                           000099   473 _TI	=	0x0099
                           000098   474 _RI	=	0x0098
                           000097   475 _P17	=	0x0097
                           000096   476 _P16	=	0x0096
                           000096   477 _TXD_1	=	0x0096
                           000095   478 _P15	=	0x0095
                           000094   479 _P14	=	0x0094
                           000094   480 _SDA	=	0x0094
                           000093   481 _P13	=	0x0093
                           000093   482 _SCL	=	0x0093
                           000092   483 _P12	=	0x0092
                           000091   484 _P11	=	0x0091
                           000090   485 _P10	=	0x0090
                           00008F   486 _TF1	=	0x008f
                           00008E   487 _TR1	=	0x008e
                           00008D   488 _TF0	=	0x008d
                           00008C   489 _TR0	=	0x008c
                           00008B   490 _IE1	=	0x008b
                           00008A   491 _IT1	=	0x008a
                           000089   492 _IE0	=	0x0089
                           000088   493 _IT0	=	0x0088
                           000087   494 _P07	=	0x0087
                           000087   495 _RXD	=	0x0087
                           000086   496 _P06	=	0x0086
                           000086   497 _TXD	=	0x0086
                           000085   498 _P05	=	0x0085
                           000084   499 _P04	=	0x0084
                           000084   500 _STADC	=	0x0084
                           000083   501 _P03	=	0x0083
                           000082   502 _P02	=	0x0082
                           000082   503 _RXD_1	=	0x0082
                           000081   504 _P01	=	0x0081
                           000081   505 _MISO	=	0x0081
                           000080   506 _P00	=	0x0080
                           000080   507 _MOSI	=	0x0080
                                    508 ;--------------------------------------------------------
                                    509 ; overlayable register banks
                                    510 ;--------------------------------------------------------
                                    511 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        512 	.ds 8
                                    513 ;--------------------------------------------------------
                                    514 ; internal ram data
                                    515 ;--------------------------------------------------------
                                    516 	.area DSEG    (DATA)
      000011                        517 _i::
      000011                        518 	.ds 1
      000012                        519 _sig1::
      000012                        520 	.ds 2
      000014                        521 _sig2::
      000014                        522 	.ds 2
      000016                        523 _sigT::
      000016                        524 	.ds 2
      000018                        525 _main_commaCount_30000_128:
      000018                        526 	.ds 2
                                    527 ;--------------------------------------------------------
                                    528 ; overlayable items in internal ram
                                    529 ;--------------------------------------------------------
                                    530 ;--------------------------------------------------------
                                    531 ; Stack segment in internal ram
                                    532 ;--------------------------------------------------------
                                    533 	.area SSEG
      000060                        534 __start__stack:
      000060                        535 	.ds	1
                                    536 
                                    537 ;--------------------------------------------------------
                                    538 ; indirectly addressable internal ram data
                                    539 ;--------------------------------------------------------
                                    540 	.area ISEG    (DATA)
                                    541 ;--------------------------------------------------------
                                    542 ; absolute internal ram data
                                    543 ;--------------------------------------------------------
                                    544 	.area IABS    (ABS,DATA)
                                    545 	.area IABS    (ABS,DATA)
                                    546 ;--------------------------------------------------------
                                    547 ; bit data
                                    548 ;--------------------------------------------------------
                                    549 	.area BSEG    (BIT)
      000002                        550 _flagJson::
      000002                        551 	.ds 1
      000003                        552 _flagMotor::
      000003                        553 	.ds 1
                                    554 ;--------------------------------------------------------
                                    555 ; paged external ram data
                                    556 ;--------------------------------------------------------
                                    557 	.area PSEG    (PAG,XDATA)
                                    558 ;--------------------------------------------------------
                                    559 ; uninitialized external ram data
                                    560 ;--------------------------------------------------------
                                    561 	.area XSEG    (XDATA)
      000001                        562 _dataRx::
      000001                        563 	.ds 8
      000009                        564 _json::
      000009                        565 	.ds 50
                                    566 ;--------------------------------------------------------
                                    567 ; absolute external ram data
                                    568 ;--------------------------------------------------------
                                    569 	.area XABS    (ABS,XDATA)
                                    570 ;--------------------------------------------------------
                                    571 ; initialized external ram data
                                    572 ;--------------------------------------------------------
                                    573 	.area XISEG   (XDATA)
      000059                        574 _previous::
      000059                        575 	.ds 4
      00005D                        576 _timeDelay::
      00005D                        577 	.ds 4
                                    578 	.area HOME    (CODE)
                                    579 	.area GSINIT0 (CODE)
                                    580 	.area GSINIT1 (CODE)
                                    581 	.area GSINIT2 (CODE)
                                    582 	.area GSINIT3 (CODE)
                                    583 	.area GSINIT4 (CODE)
                                    584 	.area GSINIT5 (CODE)
                                    585 	.area GSINIT  (CODE)
                                    586 	.area GSFINAL (CODE)
                                    587 	.area CSEG    (CODE)
                                    588 ;--------------------------------------------------------
                                    589 ; interrupt vector
                                    590 ;--------------------------------------------------------
                                    591 	.area HOME    (CODE)
      000000                        592 __interrupt_vect:
      000000 02 00 29         [24]  593 	ljmp	__sdcc_gsinit_startup
      000003 32               [24]  594 	reti
      000004                        595 	.ds	7
      00000B 02 0E E7         [24]  596 	ljmp	_Timer0_ISR
      00000E                        597 	.ds	5
      000013 32               [24]  598 	reti
      000014                        599 	.ds	7
      00001B 02 15 9E         [24]  600 	ljmp	_Timer1_ISR
      00001E                        601 	.ds	5
      000023 02 0B F1         [24]  602 	ljmp	_SerialPort0_ISR
                                    603 ;--------------------------------------------------------
                                    604 ; global & static initialisations
                                    605 ;--------------------------------------------------------
                                    606 	.area HOME    (CODE)
                                    607 	.area GSINIT  (CODE)
                                    608 	.area GSFINAL (CODE)
                                    609 	.area GSINIT  (CODE)
                                    610 	.globl __sdcc_gsinit_startup
                                    611 	.globl __sdcc_program_startup
                                    612 	.globl __start__stack
                                    613 	.globl __mcs51_genXINIT
                                    614 	.globl __mcs51_genXRAMCLEAR
                                    615 	.globl __mcs51_genRAMCLEAR
                                    616 ;	src\myDefine.h:69: uint8_t i = 0;
      0000B8 75 11 00         [24]  617 	mov	_i,#0x00
                                    618 ;	src\myDefine.h:72: uint16_t sig1 = 0;
      0000BB E4               [12]  619 	clr	a
      0000BC F5 12            [12]  620 	mov	_sig1,a
      0000BE F5 13            [12]  621 	mov	(_sig1 + 1),a
                                    622 ;	src\myDefine.h:73: uint16_t sig2 = 0;
      0000C0 F5 14            [12]  623 	mov	_sig2,a
      0000C2 F5 15            [12]  624 	mov	(_sig2 + 1),a
                                    625 ;	src\myDefine.h:74: uint16_t sigT = 0;
      0000C4 F5 16            [12]  626 	mov	_sigT,a
      0000C6 F5 17            [12]  627 	mov	(_sigT + 1),a
                                    628 ;	src\myDefine.h:70: bit_t flagJson = 0;
                                    629 ;	assignBit
      0000C8 C2 02            [12]  630 	clr	_flagJson
                                    631 ;	src\myDefine.h:71: bit_t flagMotor = 0;
                                    632 ;	assignBit
      0000CA C2 03            [12]  633 	clr	_flagMotor
                                    634 	.area GSFINAL (CODE)
      0000D1 02 00 26         [24]  635 	ljmp	__sdcc_program_startup
                                    636 ;--------------------------------------------------------
                                    637 ; Home
                                    638 ;--------------------------------------------------------
                                    639 	.area HOME    (CODE)
                                    640 	.area HOME    (CODE)
      000026                        641 __sdcc_program_startup:
      000026 02 0C 27         [24]  642 	ljmp	_main
                                    643 ;	return from main will return to caller
                                    644 ;--------------------------------------------------------
                                    645 ; code
                                    646 ;--------------------------------------------------------
                                    647 	.area CSEG    (CODE)
                                    648 ;------------------------------------------------------------
                                    649 ;Allocation info for local variables in function 'main'
                                    650 ;------------------------------------------------------------
                                    651 ;lastPacketTime            Allocated to registers r4 r5 r6 r7 
                                    652 ;safety_i                  Allocated to registers r6 r7 
                                    653 ;safety_j                  Allocated to registers r4 r5 
                                    654 ;c                         Allocated to registers r3 
                                    655 ;commaCount                Allocated with name '_main_commaCount_30000_128'
                                    656 ;k                         Allocated to registers r0 r1 
                                    657 ;------------------------------------------------------------
                                    658 ;	src\1main.c:106: void main(void)
                                    659 ;	-----------------------------------------
                                    660 ;	 function main
                                    661 ;	-----------------------------------------
      000C27                        662 _main:
                           000007   663 	ar7 = 0x07
                           000006   664 	ar6 = 0x06
                           000005   665 	ar5 = 0x05
                           000004   666 	ar4 = 0x04
                           000003   667 	ar3 = 0x03
                           000002   668 	ar2 = 0x02
                           000001   669 	ar1 = 0x01
                           000000   670 	ar0 = 0x00
                                    671 ;	src\1main.c:112: for(safety_i = 0; safety_i < 100; safety_i++) for(safety_j = 0; safety_j < 1000; safety_j++);
      000C27 7E 00            [12]  672 	mov	r6,#0x00
      000C29 7F 00            [12]  673 	mov	r7,#0x00
      000C2B                        674 00184$:
      000C2B 7C E8            [12]  675 	mov	r4,#0xe8
      000C2D 7D 03            [12]  676 	mov	r5,#0x03
      000C2F                        677 00179$:
      000C2F 1C               [12]  678 	dec	r4
      000C30 BC FF 01         [24]  679 	cjne	r4,#0xff,00295$
      000C33 1D               [12]  680 	dec	r5
      000C34                        681 00295$:
      000C34 EC               [12]  682 	mov	a,r4
      000C35 4D               [12]  683 	orl	a,r5
      000C36 70 F7            [24]  684 	jnz	00179$
      000C38 0E               [12]  685 	inc	r6
      000C39 BE 00 01         [24]  686 	cjne	r6,#0x00,00297$
      000C3C 0F               [12]  687 	inc	r7
      000C3D                        688 00297$:
      000C3D C3               [12]  689 	clr	c
      000C3E EE               [12]  690 	mov	a,r6
      000C3F 94 64            [12]  691 	subb	a,#0x64
      000C41 EF               [12]  692 	mov	a,r7
      000C42 94 00            [12]  693 	subb	a,#0x00
      000C44 40 E5            [24]  694 	jc	00184$
                                    695 ;	src\1main.c:114: MODIFY_HIRC(HIRC_166);
      000C46 75 82 08         [24]  696 	mov	dpl, #0x08
      000C49 12 09 22         [24]  697 	lcall	_MODIFY_HIRC
                                    698 ;	src\1main.c:115: UART0_Init(2400); 
      000C4C 90 09 60         [24]  699 	mov	dptr,#0x0960
      000C4F E4               [12]  700 	clr	a
      000C50 F5 F0            [12]  701 	mov	b,a
      000C52 12 0B 67         [24]  702 	lcall	_UART0_Init
                                    703 ;	src\1main.c:116: PWM_Init(1000);
      000C55 90 03 E8         [24]  704 	mov	dptr,#0x03e8
      000C58 12 06 BC         [24]  705 	lcall	_PWM_Init
                                    706 ;	src\1main.c:118: PWM_Congfig(PWM3_MODE, PWM3_PORT, PWM3_EN);
      000C5B 53 B3 FB         [24]  707 	anl	_P1M1,#0xfb
      000C5E 43 B4 04         [24]  708 	orl	_P1M2,#0x04
                                    709 ;	assignBit
      000C61 C2 92            [12]  710 	clr	_P12
      000C63 43 DE 01         [24]  711 	orl	_PIOCON0,#0x01
                                    712 ;	src\1main.c:119: PWM_Congfig(PWM4_MODE, PWM4_PORT, PWM4_EN);
      000C66 53 B1 FE         [24]  713 	anl	_P0M1,#0xfe
      000C69 43 B2 01         [24]  714 	orl	_P0M2,#0x01
                                    715 ;	assignBit
      000C6C C2 80            [12]  716 	clr	_P00
      000C6E 43 DE 08         [24]  717 	orl	_PIOCON0,#0x08
                                    718 ;	src\1main.c:121: PWM_SetDuty(PWM3_CH, 0);
      000C71 75 0C 00         [24]  719 	mov	_PWM_SetDuty_PARM_2,#0x00
      000C74 75 82 00         [24]  720 	mov	dpl, #0x00
      000C77 12 06 F9         [24]  721 	lcall	_PWM_SetDuty
                                    722 ;	src\1main.c:122: dataRx[5] = PWM_GetDuty(PWM3_CH);
      000C7A 75 82 00         [24]  723 	mov	dpl, #0x00
      000C7D 12 07 F6         [24]  724 	lcall	_PWM_GetDuty
      000C80 AF 82            [24]  725 	mov	r7, dpl
      000C82 90 00 06         [24]  726 	mov	dptr,#(_dataRx + 0x0005)
      000C85 EF               [12]  727 	mov	a,r7
      000C86 F0               [24]  728 	movx	@dptr,a
                                    729 ;	src\1main.c:123: PWM_SetDuty(PWM4_CH, 0);
      000C87 75 0C 00         [24]  730 	mov	_PWM_SetDuty_PARM_2,#0x00
      000C8A 75 82 03         [24]  731 	mov	dpl, #0x03
      000C8D 12 06 F9         [24]  732 	lcall	_PWM_SetDuty
                                    733 ;	src\1main.c:124: dataRx[7] = PWM_GetDuty(PWM4_CH);
      000C90 75 82 03         [24]  734 	mov	dpl, #0x03
      000C93 12 07 F6         [24]  735 	lcall	_PWM_GetDuty
      000C96 AF 82            [24]  736 	mov	r7, dpl
      000C98 90 00 08         [24]  737 	mov	dptr,#(_dataRx + 0x0007)
      000C9B EF               [12]  738 	mov	a,r7
      000C9C F0               [24]  739 	movx	@dptr,a
                                    740 ;	src\1main.c:126: DIR_Congfig(Dir3, Dir3_MODE);
      000C9D 53 B3 F7         [24]  741 	anl	_P1M1,#0xf7
      000CA0 43 B4 08         [24]  742 	orl	_P1M2,#0x08
                                    743 ;	assignBit
      000CA3 C2 93            [12]  744 	clr	_P13
                                    745 ;	src\1main.c:127: DIR_Congfig(Dir4, Dir4_MODE);
      000CA5 53 B3 EF         [24]  746 	anl	_P1M1,#0xef
      000CA8 43 B4 10         [24]  747 	orl	_P1M2,#0x10
                                    748 ;	assignBit
      000CAB C2 94            [12]  749 	clr	_P14
                                    750 ;	src\1main.c:130: Millis_Init();
      000CAD 12 15 BF         [24]  751 	lcall	_Millis_Init
                                    752 ;	src\1main.c:131: lastPacketTime = Millis();
      000CB0 12 15 D7         [24]  753 	lcall	_Millis
      000CB3 AC 82            [24]  754 	mov	r4, dpl
      000CB5 AD 83            [24]  755 	mov	r5, dph
      000CB7 AE F0            [24]  756 	mov	r6, b
      000CB9 FF               [12]  757 	mov	r7, a
                                    758 ;	src\1main.c:135: while (UART0_Available() > 0)
      000CBA                        759 00138$:
      000CBA C0 07            [24]  760 	push	ar7
      000CBC C0 06            [24]  761 	push	ar6
      000CBE C0 05            [24]  762 	push	ar5
      000CC0 C0 04            [24]  763 	push	ar4
      000CC2 12 0B E9         [24]  764 	lcall	_UART0_Available
      000CC5 E5 82            [12]  765 	mov	a, dpl
      000CC7 D0 04            [24]  766 	pop	ar4
      000CC9 D0 05            [24]  767 	pop	ar5
      000CCB D0 06            [24]  768 	pop	ar6
      000CCD D0 07            [24]  769 	pop	ar7
      000CCF 60 5B            [24]  770 	jz	00140$
                                    771 ;	src\1main.c:137: char c = UART0_GetChar();
      000CD1 C0 07            [24]  772 	push	ar7
      000CD3 C0 06            [24]  773 	push	ar6
      000CD5 C0 05            [24]  774 	push	ar5
      000CD7 C0 04            [24]  775 	push	ar4
      000CD9 12 0B 9D         [24]  776 	lcall	_UART0_GetChar
      000CDC AB 82            [24]  777 	mov	r3, dpl
      000CDE D0 04            [24]  778 	pop	ar4
      000CE0 D0 05            [24]  779 	pop	ar5
      000CE2 D0 06            [24]  780 	pop	ar6
      000CE4 D0 07            [24]  781 	pop	ar7
                                    782 ;	src\1main.c:138: if (c == '|') {
      000CE6 BB 7C 14         [24]  783 	cjne	r3,#0x7c,00136$
                                    784 ;	src\1main.c:139: json[i] = '\0'; 
      000CE9 E5 11            [12]  785 	mov	a,_i
      000CEB 24 09            [12]  786 	add	a, #_json
      000CED F5 82            [12]  787 	mov	dpl,a
      000CEF E4               [12]  788 	clr	a
      000CF0 34 00            [12]  789 	addc	a, #(_json >> 8)
      000CF2 F5 83            [12]  790 	mov	dph,a
      000CF4 E4               [12]  791 	clr	a
      000CF5 F0               [24]  792 	movx	@dptr,a
                                    793 ;	src\1main.c:140: flagJson = 1;
                                    794 ;	assignBit
      000CF6 D2 02            [12]  795 	setb	_flagJson
                                    796 ;	src\1main.c:141: i = 0; 
      000CF8 75 11 00         [24]  797 	mov	_i,#0x00
      000CFB 80 BD            [24]  798 	sjmp	00138$
      000CFD                        799 00136$:
                                    800 ;	src\1main.c:143: else if (i < MAX_JSON_SIZE - 1) {
      000CFD 74 C1            [12]  801 	mov	a,#0x100 - 0x3f
      000CFF 25 11            [12]  802 	add	a,_i
      000D01 40 24            [24]  803 	jc	00133$
                                    804 ;	src\1main.c:145: if ((c >= '0' && c <= '9') || c == ',' || c == '-') {
      000D03 BB 30 00         [24]  805 	cjne	r3,#0x30,00303$
      000D06                        806 00303$:
      000D06 40 05            [24]  807 	jc	00130$
      000D08 EB               [12]  808 	mov	a,r3
      000D09 24 C6            [12]  809 	add	a,#0xff - 0x39
      000D0B 50 08            [24]  810 	jnc	00127$
      000D0D                        811 00130$:
      000D0D BB 2C 02         [24]  812 	cjne	r3,#0x2c,00306$
      000D10 80 03            [24]  813 	sjmp	00127$
      000D12                        814 00306$:
      000D12 BB 2D A5         [24]  815 	cjne	r3,#0x2d,00138$
      000D15                        816 00127$:
                                    817 ;	src\1main.c:146: json[i++] = c;
      000D15 AA 11            [24]  818 	mov	r2,_i
      000D17 05 11            [12]  819 	inc	_i
      000D19 EA               [12]  820 	mov	a,r2
      000D1A 24 09            [12]  821 	add	a, #_json
      000D1C F5 82            [12]  822 	mov	dpl,a
      000D1E E4               [12]  823 	clr	a
      000D1F 34 00            [12]  824 	addc	a, #(_json >> 8)
      000D21 F5 83            [12]  825 	mov	dph,a
      000D23 EB               [12]  826 	mov	a,r3
      000D24 F0               [24]  827 	movx	@dptr,a
      000D25 80 93            [24]  828 	sjmp	00138$
      000D27                        829 00133$:
                                    830 ;	src\1main.c:149: else { i = 0; }
      000D27 75 11 00         [24]  831 	mov	_i,#0x00
      000D2A 80 8E            [24]  832 	sjmp	00138$
      000D2C                        833 00140$:
                                    834 ;	src\1main.c:153: if (flagJson)
      000D2C 20 02 03         [24]  835 	jb	_flagJson,00309$
      000D2F 02 0E 15         [24]  836 	ljmp	00165$
      000D32                        837 00309$:
                                    838 ;	src\1main.c:157: while(json[k] != '\0') {
      000D32 E4               [12]  839 	clr	a
      000D33 F5 18            [12]  840 	mov	_main_commaCount_30000_128,a
      000D35 F5 19            [12]  841 	mov	(_main_commaCount_30000_128 + 1),a
      000D37 F8               [12]  842 	mov	r0,a
      000D38 F9               [12]  843 	mov	r1,a
      000D39                        844 00143$:
      000D39 E8               [12]  845 	mov	a,r0
      000D3A 24 09            [12]  846 	add	a, #_json
      000D3C FA               [12]  847 	mov	r2,a
      000D3D E9               [12]  848 	mov	a,r1
      000D3E 34 00            [12]  849 	addc	a, #(_json >> 8)
      000D40 FB               [12]  850 	mov	r3,a
      000D41 8A 82            [24]  851 	mov	dpl,r2
      000D43 8B 83            [24]  852 	mov	dph,r3
      000D45 E0               [24]  853 	movx	a,@dptr
      000D46 60 1E            [24]  854 	jz	00145$
                                    855 ;	src\1main.c:158: if(json[k] == ',') commaCount++;
      000D48 E8               [12]  856 	mov	a,r0
      000D49 24 09            [12]  857 	add	a, #_json
      000D4B F5 82            [12]  858 	mov	dpl,a
      000D4D E9               [12]  859 	mov	a,r1
      000D4E 34 00            [12]  860 	addc	a, #(_json >> 8)
      000D50 F5 83            [12]  861 	mov	dph,a
      000D52 E0               [24]  862 	movx	a,@dptr
      000D53 FB               [12]  863 	mov	r3,a
      000D54 BB 2C 08         [24]  864 	cjne	r3,#0x2c,00142$
      000D57 05 18            [12]  865 	inc	_main_commaCount_30000_128
      000D59 E4               [12]  866 	clr	a
      000D5A B5 18 02         [24]  867 	cjne	a,_main_commaCount_30000_128,00313$
      000D5D 05 19            [12]  868 	inc	(_main_commaCount_30000_128 + 1)
      000D5F                        869 00313$:
      000D5F                        870 00142$:
                                    871 ;	src\1main.c:159: k++;
      000D5F 08               [12]  872 	inc	r0
      000D60 B8 00 D6         [24]  873 	cjne	r0,#0x00,00143$
      000D63 09               [12]  874 	inc	r1
      000D64 80 D3            [24]  875 	sjmp	00143$
      000D66                        876 00145$:
                                    877 ;	src\1main.c:161: if (commaCount == 7) 
      000D66 74 07            [12]  878 	mov	a,#0x07
      000D68 B5 18 06         [24]  879 	cjne	a,_main_commaCount_30000_128,00315$
      000D6B E4               [12]  880 	clr	a
      000D6C B5 19 02         [24]  881 	cjne	a,(_main_commaCount_30000_128 + 1),00315$
      000D6F 80 03            [24]  882 	sjmp	00316$
      000D71                        883 00315$:
      000D71 02 0E 13         [24]  884 	ljmp	00163$
      000D74                        885 00316$:
                                    886 ;	src\1main.c:163: parse_json(json, &dataRx[0], &dataRx[1], &dataRx[2], &dataRx[3], &dataRx[4], &dataRx[5], &dataRx[6], &dataRx[7]);
      000D74 75 21 01         [24]  887 	mov	_parse_json_PARM_2,#_dataRx
      000D77 75 22 00         [24]  888 	mov	(_parse_json_PARM_2 + 1),#(_dataRx >> 8)
      000D7A 75 23 00         [24]  889 	mov	(_parse_json_PARM_2 + 2),#0x00
      000D7D 75 24 02         [24]  890 	mov	_parse_json_PARM_3,#(_dataRx + 0x0001)
      000D80 75 25 00         [24]  891 	mov	(_parse_json_PARM_3 + 1),#((_dataRx + 0x0001) >> 8)
      000D83 75 26 00         [24]  892 	mov	(_parse_json_PARM_3 + 2),#0x00
      000D86 75 27 03         [24]  893 	mov	_parse_json_PARM_4,#(_dataRx + 0x0002)
      000D89 75 28 00         [24]  894 	mov	(_parse_json_PARM_4 + 1),#((_dataRx + 0x0002) >> 8)
      000D8C 75 29 00         [24]  895 	mov	(_parse_json_PARM_4 + 2),#0x00
      000D8F 75 2A 04         [24]  896 	mov	_parse_json_PARM_5,#(_dataRx + 0x0003)
      000D92 75 2B 00         [24]  897 	mov	(_parse_json_PARM_5 + 1),#((_dataRx + 0x0003) >> 8)
      000D95 75 2C 00         [24]  898 	mov	(_parse_json_PARM_5 + 2),#0x00
      000D98 75 2D 05         [24]  899 	mov	_parse_json_PARM_6,#(_dataRx + 0x0004)
      000D9B 75 2E 00         [24]  900 	mov	(_parse_json_PARM_6 + 1),#((_dataRx + 0x0004) >> 8)
      000D9E 75 2F 00         [24]  901 	mov	(_parse_json_PARM_6 + 2),#0x00
      000DA1 75 30 06         [24]  902 	mov	_parse_json_PARM_7,#(_dataRx + 0x0005)
      000DA4 75 31 00         [24]  903 	mov	(_parse_json_PARM_7 + 1),#((_dataRx + 0x0005) >> 8)
      000DA7 75 32 00         [24]  904 	mov	(_parse_json_PARM_7 + 2),#0x00
      000DAA 75 33 07         [24]  905 	mov	_parse_json_PARM_8,#(_dataRx + 0x0006)
      000DAD 75 34 00         [24]  906 	mov	(_parse_json_PARM_8 + 1),#((_dataRx + 0x0006) >> 8)
      000DB0 75 35 00         [24]  907 	mov	(_parse_json_PARM_8 + 2),#0x00
      000DB3 75 36 08         [24]  908 	mov	_parse_json_PARM_9,#(_dataRx + 0x0007)
      000DB6 75 37 00         [24]  909 	mov	(_parse_json_PARM_9 + 1),#((_dataRx + 0x0007) >> 8)
      000DB9 75 38 00         [24]  910 	mov	(_parse_json_PARM_9 + 2),#0x00
      000DBC 90 00 09         [24]  911 	mov	dptr,#_json
      000DBF 75 F0 00         [24]  912 	mov	b, #0x00
      000DC2 12 0F F8         [24]  913 	lcall	_parse_json
                                    914 ;	src\1main.c:165: HandlePWM(PWM3_CH, dataRx[5]);
      000DC5 90 00 06         [24]  915 	mov	dptr,#(_dataRx + 0x0005)
      000DC8 E0               [24]  916 	movx	a,@dptr
      000DC9 F5 0C            [12]  917 	mov	_PWM_SetDuty_PARM_2,a
      000DCB 75 82 00         [24]  918 	mov	dpl, #0x00
      000DCE 12 06 F9         [24]  919 	lcall	_PWM_SetDuty
                                    920 ;	src\1main.c:166: HandlePWM(PWM4_CH, dataRx[7]);
      000DD1 90 00 08         [24]  921 	mov	dptr,#(_dataRx + 0x0007)
      000DD4 E0               [24]  922 	movx	a,@dptr
      000DD5 F5 0C            [12]  923 	mov	_PWM_SetDuty_PARM_2,a
      000DD7 75 82 03         [24]  924 	mov	dpl, #0x03
      000DDA 12 06 F9         [24]  925 	lcall	_PWM_SetDuty
                                    926 ;	src\1main.c:167: HandleDir(Dir3, dataRx[4]);
      000DDD 90 00 05         [24]  927 	mov	dptr,#(_dataRx + 0x0004)
      000DE0 E0               [24]  928 	movx	a,@dptr
      000DE1 FB               [12]  929 	mov	r3,a
      000DE2 A2 93            [12]  930 	mov	c,_P13
      000DE4 E4               [12]  931 	clr	a
      000DE5 33               [12]  932 	rlc	a
      000DE6 B5 03 02         [24]  933 	cjne	a,ar3,00317$
      000DE9 80 08            [24]  934 	sjmp	00155$
      000DEB                        935 00317$:
      000DEB 90 00 05         [24]  936 	mov	dptr,#(_dataRx + 0x0004)
      000DEE E0               [24]  937 	movx	a,@dptr
                                    938 ;	assignBit
      000DEF 24 FF            [12]  939 	add	a,#0xff
      000DF1 92 93            [24]  940 	mov	_P13,c
      000DF3                        941 00155$:
                                    942 ;	src\1main.c:168: HandleDir(Dir4, dataRx[6]);
      000DF3 90 00 07         [24]  943 	mov	dptr,#(_dataRx + 0x0006)
      000DF6 E0               [24]  944 	movx	a,@dptr
      000DF7 FB               [12]  945 	mov	r3,a
      000DF8 A2 94            [12]  946 	mov	c,_P14
      000DFA E4               [12]  947 	clr	a
      000DFB 33               [12]  948 	rlc	a
      000DFC B5 03 02         [24]  949 	cjne	a,ar3,00318$
      000DFF 80 08            [24]  950 	sjmp	00160$
      000E01                        951 00318$:
      000E01 90 00 07         [24]  952 	mov	dptr,#(_dataRx + 0x0006)
      000E04 E0               [24]  953 	movx	a,@dptr
                                    954 ;	assignBit
      000E05 24 FF            [12]  955 	add	a,#0xff
      000E07 92 94            [24]  956 	mov	_P14,c
      000E09                        957 00160$:
                                    958 ;	src\1main.c:169: lastPacketTime = Millis(); 
      000E09 12 15 D7         [24]  959 	lcall	_Millis
      000E0C AC 82            [24]  960 	mov	r4, dpl
      000E0E AD 83            [24]  961 	mov	r5, dph
      000E10 AE F0            [24]  962 	mov	r6, b
      000E12 FF               [12]  963 	mov	r7, a
      000E13                        964 00163$:
                                    965 ;	src\1main.c:174: flagJson = 0; 
                                    966 ;	assignBit
      000E13 C2 02            [12]  967 	clr	_flagJson
      000E15                        968 00165$:
                                    969 ;	src\1main.c:177: if (Millis() - lastPacketTime > 1000) {
      000E15 C0 07            [24]  970 	push	ar7
      000E17 C0 06            [24]  971 	push	ar6
      000E19 C0 05            [24]  972 	push	ar5
      000E1B C0 04            [24]  973 	push	ar4
      000E1D 12 15 D7         [24]  974 	lcall	_Millis
      000E20 A8 82            [24]  975 	mov	r0, dpl
      000E22 A9 83            [24]  976 	mov	r1, dph
      000E24 AA F0            [24]  977 	mov	r2, b
      000E26 FB               [12]  978 	mov	r3, a
      000E27 D0 04            [24]  979 	pop	ar4
      000E29 D0 05            [24]  980 	pop	ar5
      000E2B D0 06            [24]  981 	pop	ar6
      000E2D D0 07            [24]  982 	pop	ar7
      000E2F E8               [12]  983 	mov	a,r0
      000E30 C3               [12]  984 	clr	c
      000E31 9C               [12]  985 	subb	a,r4
      000E32 F8               [12]  986 	mov	r0,a
      000E33 E9               [12]  987 	mov	a,r1
      000E34 9D               [12]  988 	subb	a,r5
      000E35 F9               [12]  989 	mov	r1,a
      000E36 EA               [12]  990 	mov	a,r2
      000E37 9E               [12]  991 	subb	a,r6
      000E38 FA               [12]  992 	mov	r2,a
      000E39 EB               [12]  993 	mov	a,r3
      000E3A 9F               [12]  994 	subb	a,r7
      000E3B FB               [12]  995 	mov	r3,a
      000E3C C3               [12]  996 	clr	c
      000E3D 74 E8            [12]  997 	mov	a,#0xe8
      000E3F 98               [12]  998 	subb	a,r0
      000E40 74 03            [12]  999 	mov	a,#0x03
      000E42 99               [12] 1000 	subb	a,r1
      000E43 E4               [12] 1001 	clr	a
      000E44 9A               [12] 1002 	subb	a,r2
      000E45 E4               [12] 1003 	clr	a
      000E46 9B               [12] 1004 	subb	a,r3
      000E47 40 03            [24] 1005 	jc	00319$
      000E49 02 0C BA         [24] 1006 	ljmp	00138$
      000E4C                       1007 00319$:
                                   1008 ;	src\1main.c:178: HandlePWM(PWM3_CH, 0);
      000E4C 75 0C 00         [24] 1009 	mov	_PWM_SetDuty_PARM_2,#0x00
      000E4F 75 82 00         [24] 1010 	mov	dpl, #0x00
      000E52 C0 07            [24] 1011 	push	ar7
      000E54 C0 06            [24] 1012 	push	ar6
      000E56 C0 05            [24] 1013 	push	ar5
      000E58 C0 04            [24] 1014 	push	ar4
      000E5A 12 06 F9         [24] 1015 	lcall	_PWM_SetDuty
                                   1016 ;	src\1main.c:179: HandlePWM(PWM4_CH, 0);
      000E5D 75 0C 00         [24] 1017 	mov	_PWM_SetDuty_PARM_2,#0x00
      000E60 75 82 03         [24] 1018 	mov	dpl, #0x03
      000E63 12 06 F9         [24] 1019 	lcall	_PWM_SetDuty
      000E66 D0 04            [24] 1020 	pop	ar4
      000E68 D0 05            [24] 1021 	pop	ar5
      000E6A D0 06            [24] 1022 	pop	ar6
      000E6C D0 07            [24] 1023 	pop	ar7
                                   1024 ;	src\1main.c:182: }
      000E6E 02 0C BA         [24] 1025 	ljmp	00138$
                                   1026 	.area CSEG    (CODE)
                                   1027 	.area CONST   (CODE)
                                   1028 	.area XINIT   (CODE)
      00172C                       1029 __xinit__previous:
      00172C 00 00 00 00           1030 	.byte #0x00, #0x00, #0x00, #0x00	; 0
      001730                       1031 __xinit__timeDelay:
      001730 E8 03 00 00           1032 	.byte #0xe8, #0x03, #0x00, #0x00	; 1000
                                   1033 	.area CABS    (ABS,CODE)
