                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ISO C Compiler
                                      3 ; Version 4.5.10 #15664 (MINGW32)
                                      4 ;--------------------------------------------------------
                                      5 	.module main
                                      6 	
                                      7 	.optsdcc -mmcs51 --model-small
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _main
                                     12 	.globl _Send_Hex_Format
                                     13 	.globl _Send_Binary_String
                                     14 	.globl _Send_JSON_Format
                                     15 	.globl _Send_Individual_Values
                                     16 	.globl _Send_Pattern_Decimal
                                     17 	.globl _Get_Line_Pattern
                                     18 	.globl _Read_Line_Sensors
                                     19 	.globl _UART_Init
                                     20 	.globl _GPIO_Init
                                     21 	.globl _Timer0_Delay1ms
                                     22 	.globl _InitialUART0_Timer1
                                     23 	.globl _printf
                                     24 	.globl _MOSI
                                     25 	.globl _P00
                                     26 	.globl _MISO
                                     27 	.globl _P01
                                     28 	.globl _RXD_1
                                     29 	.globl _P02
                                     30 	.globl _P03
                                     31 	.globl _STADC
                                     32 	.globl _P04
                                     33 	.globl _P05
                                     34 	.globl _TXD
                                     35 	.globl _P06
                                     36 	.globl _RXD
                                     37 	.globl _P07
                                     38 	.globl _IT0
                                     39 	.globl _IE0
                                     40 	.globl _IT1
                                     41 	.globl _IE1
                                     42 	.globl _TR0
                                     43 	.globl _TF0
                                     44 	.globl _TR1
                                     45 	.globl _TF1
                                     46 	.globl _P10
                                     47 	.globl _P11
                                     48 	.globl _P12
                                     49 	.globl _SCL
                                     50 	.globl _P13
                                     51 	.globl _SDA
                                     52 	.globl _P14
                                     53 	.globl _P15
                                     54 	.globl _TXD_1
                                     55 	.globl _P16
                                     56 	.globl _P17
                                     57 	.globl _RI
                                     58 	.globl _TI
                                     59 	.globl _RB8
                                     60 	.globl _TB8
                                     61 	.globl _REN
                                     62 	.globl _SM2
                                     63 	.globl _SM1
                                     64 	.globl _FE
                                     65 	.globl _SM0
                                     66 	.globl _P20
                                     67 	.globl _EX0
                                     68 	.globl _ET0
                                     69 	.globl _EX1
                                     70 	.globl _ET1
                                     71 	.globl _ES
                                     72 	.globl _EBOD
                                     73 	.globl _EADC
                                     74 	.globl _EA
                                     75 	.globl _P30
                                     76 	.globl _PX0
                                     77 	.globl _PT0
                                     78 	.globl _PX1
                                     79 	.globl _PT1
                                     80 	.globl _PS
                                     81 	.globl _PBOD
                                     82 	.globl _PADC
                                     83 	.globl _I2CPX
                                     84 	.globl _AA
                                     85 	.globl _SI
                                     86 	.globl _STO
                                     87 	.globl _STA
                                     88 	.globl _I2CEN
                                     89 	.globl _CM_RL2
                                     90 	.globl _TR2
                                     91 	.globl _TF2
                                     92 	.globl _P
                                     93 	.globl _OV
                                     94 	.globl _RS0
                                     95 	.globl _RS1
                                     96 	.globl _F0
                                     97 	.globl _AC
                                     98 	.globl _CY
                                     99 	.globl _CLRPWM
                                    100 	.globl _PWMF
                                    101 	.globl _LOAD
                                    102 	.globl _PWMRUN
                                    103 	.globl _ADCHS0
                                    104 	.globl _ADCHS1
                                    105 	.globl _ADCHS2
                                    106 	.globl _ADCHS3
                                    107 	.globl _ETGSEL0
                                    108 	.globl _ETGSEL1
                                    109 	.globl _ADCS
                                    110 	.globl _ADCF
                                    111 	.globl _RI_1
                                    112 	.globl _TI_1
                                    113 	.globl _RB8_1
                                    114 	.globl _TB8_1
                                    115 	.globl _REN_1
                                    116 	.globl _SM2_1
                                    117 	.globl _SM1_1
                                    118 	.globl _FE_1
                                    119 	.globl _SM0_1
                                    120 	.globl _EIPH1
                                    121 	.globl _EIP1
                                    122 	.globl _PMD
                                    123 	.globl _PMEN
                                    124 	.globl _PDTCNT
                                    125 	.globl _PDTEN
                                    126 	.globl _SCON_1
                                    127 	.globl _EIPH
                                    128 	.globl _AINDIDS
                                    129 	.globl _SPDR
                                    130 	.globl _SPSR
                                    131 	.globl _SPCR2
                                    132 	.globl _SPCR
                                    133 	.globl _CAPCON4
                                    134 	.globl _CAPCON3
                                    135 	.globl _B
                                    136 	.globl _EIP
                                    137 	.globl _C2H
                                    138 	.globl _C2L
                                    139 	.globl _PIF
                                    140 	.globl _PIPEN
                                    141 	.globl _PINEN
                                    142 	.globl _PICON
                                    143 	.globl _ADCCON0
                                    144 	.globl _C1H
                                    145 	.globl _C1L
                                    146 	.globl _C0H
                                    147 	.globl _C0L
                                    148 	.globl _ADCDLY
                                    149 	.globl _ADCCON2
                                    150 	.globl _ADCCON1
                                    151 	.globl _ACC
                                    152 	.globl _PWMCON1
                                    153 	.globl _PIOCON0
                                    154 	.globl _PWM3L
                                    155 	.globl _PWM2L
                                    156 	.globl _PWM1L
                                    157 	.globl _PWM0L
                                    158 	.globl _PWMPL
                                    159 	.globl _PWMCON0
                                    160 	.globl _FBD
                                    161 	.globl _PNP
                                    162 	.globl _PWM3H
                                    163 	.globl _PWM2H
                                    164 	.globl _PWM1H
                                    165 	.globl _PWM0H
                                    166 	.globl _PWMPH
                                    167 	.globl _PSW
                                    168 	.globl _ADCMPH
                                    169 	.globl _ADCMPL
                                    170 	.globl _PWM5L
                                    171 	.globl _TH2
                                    172 	.globl _PWM4L
                                    173 	.globl _TL2
                                    174 	.globl _RCMP2H
                                    175 	.globl _RCMP2L
                                    176 	.globl _T2MOD
                                    177 	.globl _T2CON
                                    178 	.globl _TA
                                    179 	.globl _PIOCON1
                                    180 	.globl _RH3
                                    181 	.globl _PWM5H
                                    182 	.globl _RL3
                                    183 	.globl _PWM4H
                                    184 	.globl _T3CON
                                    185 	.globl _ADCRH
                                    186 	.globl _ADCRL
                                    187 	.globl _I2ADDR
                                    188 	.globl _I2CON
                                    189 	.globl _I2TOC
                                    190 	.globl _I2CLK
                                    191 	.globl _I2STAT
                                    192 	.globl _I2DAT
                                    193 	.globl _SADDR_1
                                    194 	.globl _SADEN_1
                                    195 	.globl _SADEN
                                    196 	.globl _IP
                                    197 	.globl _PWMINTC
                                    198 	.globl _IPH
                                    199 	.globl _P2S
                                    200 	.globl _P1SR
                                    201 	.globl _P1M2
                                    202 	.globl _P1S
                                    203 	.globl _P1M1
                                    204 	.globl _P0SR
                                    205 	.globl _P0M2
                                    206 	.globl _P0S
                                    207 	.globl _P0M1
                                    208 	.globl _P3
                                    209 	.globl _IAPCN
                                    210 	.globl _IAPFD
                                    211 	.globl _P3SR
                                    212 	.globl _P3M2
                                    213 	.globl _P3S
                                    214 	.globl _P3M1
                                    215 	.globl _BODCON1
                                    216 	.globl _WDCON
                                    217 	.globl _SADDR
                                    218 	.globl _IE
                                    219 	.globl _IAPAH
                                    220 	.globl _IAPAL
                                    221 	.globl _IAPUEN
                                    222 	.globl _IAPTRG
                                    223 	.globl _BODCON0
                                    224 	.globl _AUXR1
                                    225 	.globl _P2
                                    226 	.globl _CHPCON
                                    227 	.globl _EIE1
                                    228 	.globl _EIE
                                    229 	.globl _SBUF_1
                                    230 	.globl _SBUF
                                    231 	.globl _SCON
                                    232 	.globl _CKEN
                                    233 	.globl _CKSWT
                                    234 	.globl _CKDIV
                                    235 	.globl _CAPCON2
                                    236 	.globl _CAPCON1
                                    237 	.globl _CAPCON0
                                    238 	.globl _SFRS
                                    239 	.globl _P1
                                    240 	.globl _WKCON
                                    241 	.globl _CKCON
                                    242 	.globl _TH1
                                    243 	.globl _TH0
                                    244 	.globl _TL1
                                    245 	.globl _TL0
                                    246 	.globl _TMOD
                                    247 	.globl _TCON
                                    248 	.globl _PCON
                                    249 	.globl _RWK
                                    250 	.globl _RCTRIM1
                                    251 	.globl _RCTRIM0
                                    252 	.globl _DPH
                                    253 	.globl _DPL
                                    254 	.globl _SP
                                    255 	.globl _P0
                                    256 	.globl _line_pattern
                                    257 	.globl _line_sensors
                                    258 	.globl _putchar
                                    259 ;--------------------------------------------------------
                                    260 ; special function registers
                                    261 ;--------------------------------------------------------
                                    262 	.area RSEG    (ABS,DATA)
      000000                        263 	.org 0x0000
                           000080   264 _P0	=	0x0080
                           000081   265 _SP	=	0x0081
                           000082   266 _DPL	=	0x0082
                           000083   267 _DPH	=	0x0083
                           000084   268 _RCTRIM0	=	0x0084
                           000085   269 _RCTRIM1	=	0x0085
                           000086   270 _RWK	=	0x0086
                           000087   271 _PCON	=	0x0087
                           000088   272 _TCON	=	0x0088
                           000089   273 _TMOD	=	0x0089
                           00008A   274 _TL0	=	0x008a
                           00008B   275 _TL1	=	0x008b
                           00008C   276 _TH0	=	0x008c
                           00008D   277 _TH1	=	0x008d
                           00008E   278 _CKCON	=	0x008e
                           00008F   279 _WKCON	=	0x008f
                           000090   280 _P1	=	0x0090
                           000091   281 _SFRS	=	0x0091
                           000092   282 _CAPCON0	=	0x0092
                           000093   283 _CAPCON1	=	0x0093
                           000094   284 _CAPCON2	=	0x0094
                           000095   285 _CKDIV	=	0x0095
                           000096   286 _CKSWT	=	0x0096
                           000097   287 _CKEN	=	0x0097
                           000098   288 _SCON	=	0x0098
                           000099   289 _SBUF	=	0x0099
                           00009A   290 _SBUF_1	=	0x009a
                           00009B   291 _EIE	=	0x009b
                           00009C   292 _EIE1	=	0x009c
                           00009F   293 _CHPCON	=	0x009f
                           0000A0   294 _P2	=	0x00a0
                           0000A2   295 _AUXR1	=	0x00a2
                           0000A3   296 _BODCON0	=	0x00a3
                           0000A4   297 _IAPTRG	=	0x00a4
                           0000A5   298 _IAPUEN	=	0x00a5
                           0000A6   299 _IAPAL	=	0x00a6
                           0000A7   300 _IAPAH	=	0x00a7
                           0000A8   301 _IE	=	0x00a8
                           0000A9   302 _SADDR	=	0x00a9
                           0000AA   303 _WDCON	=	0x00aa
                           0000AB   304 _BODCON1	=	0x00ab
                           0000AC   305 _P3M1	=	0x00ac
                           0000AC   306 _P3S	=	0x00ac
                           0000AD   307 _P3M2	=	0x00ad
                           0000AD   308 _P3SR	=	0x00ad
                           0000AE   309 _IAPFD	=	0x00ae
                           0000AF   310 _IAPCN	=	0x00af
                           0000B0   311 _P3	=	0x00b0
                           0000B1   312 _P0M1	=	0x00b1
                           0000B1   313 _P0S	=	0x00b1
                           0000B2   314 _P0M2	=	0x00b2
                           0000B2   315 _P0SR	=	0x00b2
                           0000B3   316 _P1M1	=	0x00b3
                           0000B3   317 _P1S	=	0x00b3
                           0000B4   318 _P1M2	=	0x00b4
                           0000B4   319 _P1SR	=	0x00b4
                           0000B5   320 _P2S	=	0x00b5
                           0000B7   321 _IPH	=	0x00b7
                           0000B7   322 _PWMINTC	=	0x00b7
                           0000B8   323 _IP	=	0x00b8
                           0000B9   324 _SADEN	=	0x00b9
                           0000BA   325 _SADEN_1	=	0x00ba
                           0000BB   326 _SADDR_1	=	0x00bb
                           0000BC   327 _I2DAT	=	0x00bc
                           0000BD   328 _I2STAT	=	0x00bd
                           0000BE   329 _I2CLK	=	0x00be
                           0000BF   330 _I2TOC	=	0x00bf
                           0000C0   331 _I2CON	=	0x00c0
                           0000C1   332 _I2ADDR	=	0x00c1
                           0000C2   333 _ADCRL	=	0x00c2
                           0000C3   334 _ADCRH	=	0x00c3
                           0000C4   335 _T3CON	=	0x00c4
                           0000C4   336 _PWM4H	=	0x00c4
                           0000C5   337 _RL3	=	0x00c5
                           0000C5   338 _PWM5H	=	0x00c5
                           0000C6   339 _RH3	=	0x00c6
                           0000C6   340 _PIOCON1	=	0x00c6
                           0000C7   341 _TA	=	0x00c7
                           0000C8   342 _T2CON	=	0x00c8
                           0000C9   343 _T2MOD	=	0x00c9
                           0000CA   344 _RCMP2L	=	0x00ca
                           0000CB   345 _RCMP2H	=	0x00cb
                           0000CC   346 _TL2	=	0x00cc
                           0000CC   347 _PWM4L	=	0x00cc
                           0000CD   348 _TH2	=	0x00cd
                           0000CD   349 _PWM5L	=	0x00cd
                           0000CE   350 _ADCMPL	=	0x00ce
                           0000CF   351 _ADCMPH	=	0x00cf
                           0000D0   352 _PSW	=	0x00d0
                           0000D1   353 _PWMPH	=	0x00d1
                           0000D2   354 _PWM0H	=	0x00d2
                           0000D3   355 _PWM1H	=	0x00d3
                           0000D4   356 _PWM2H	=	0x00d4
                           0000D5   357 _PWM3H	=	0x00d5
                           0000D6   358 _PNP	=	0x00d6
                           0000D7   359 _FBD	=	0x00d7
                           0000D8   360 _PWMCON0	=	0x00d8
                           0000D9   361 _PWMPL	=	0x00d9
                           0000DA   362 _PWM0L	=	0x00da
                           0000DB   363 _PWM1L	=	0x00db
                           0000DC   364 _PWM2L	=	0x00dc
                           0000DD   365 _PWM3L	=	0x00dd
                           0000DE   366 _PIOCON0	=	0x00de
                           0000DF   367 _PWMCON1	=	0x00df
                           0000E0   368 _ACC	=	0x00e0
                           0000E1   369 _ADCCON1	=	0x00e1
                           0000E2   370 _ADCCON2	=	0x00e2
                           0000E3   371 _ADCDLY	=	0x00e3
                           0000E4   372 _C0L	=	0x00e4
                           0000E5   373 _C0H	=	0x00e5
                           0000E6   374 _C1L	=	0x00e6
                           0000E7   375 _C1H	=	0x00e7
                           0000E8   376 _ADCCON0	=	0x00e8
                           0000E9   377 _PICON	=	0x00e9
                           0000EA   378 _PINEN	=	0x00ea
                           0000EB   379 _PIPEN	=	0x00eb
                           0000EC   380 _PIF	=	0x00ec
                           0000ED   381 _C2L	=	0x00ed
                           0000EE   382 _C2H	=	0x00ee
                           0000EF   383 _EIP	=	0x00ef
                           0000F0   384 _B	=	0x00f0
                           0000F1   385 _CAPCON3	=	0x00f1
                           0000F2   386 _CAPCON4	=	0x00f2
                           0000F3   387 _SPCR	=	0x00f3
                           0000F3   388 _SPCR2	=	0x00f3
                           0000F4   389 _SPSR	=	0x00f4
                           0000F5   390 _SPDR	=	0x00f5
                           0000F6   391 _AINDIDS	=	0x00f6
                           0000F7   392 _EIPH	=	0x00f7
                           0000F8   393 _SCON_1	=	0x00f8
                           0000F9   394 _PDTEN	=	0x00f9
                           0000FA   395 _PDTCNT	=	0x00fa
                           0000FB   396 _PMEN	=	0x00fb
                           0000FC   397 _PMD	=	0x00fc
                           0000FE   398 _EIP1	=	0x00fe
                           0000FF   399 _EIPH1	=	0x00ff
                                    400 ;--------------------------------------------------------
                                    401 ; special function bits
                                    402 ;--------------------------------------------------------
                                    403 	.area RSEG    (ABS,DATA)
      000000                        404 	.org 0x0000
                           0000FF   405 _SM0_1	=	0x00ff
                           0000FF   406 _FE_1	=	0x00ff
                           0000FE   407 _SM1_1	=	0x00fe
                           0000FD   408 _SM2_1	=	0x00fd
                           0000FC   409 _REN_1	=	0x00fc
                           0000FB   410 _TB8_1	=	0x00fb
                           0000FA   411 _RB8_1	=	0x00fa
                           0000F9   412 _TI_1	=	0x00f9
                           0000F8   413 _RI_1	=	0x00f8
                           0000EF   414 _ADCF	=	0x00ef
                           0000EE   415 _ADCS	=	0x00ee
                           0000ED   416 _ETGSEL1	=	0x00ed
                           0000EC   417 _ETGSEL0	=	0x00ec
                           0000EB   418 _ADCHS3	=	0x00eb
                           0000EA   419 _ADCHS2	=	0x00ea
                           0000E9   420 _ADCHS1	=	0x00e9
                           0000E8   421 _ADCHS0	=	0x00e8
                           0000DF   422 _PWMRUN	=	0x00df
                           0000DE   423 _LOAD	=	0x00de
                           0000DD   424 _PWMF	=	0x00dd
                           0000DC   425 _CLRPWM	=	0x00dc
                           0000D7   426 _CY	=	0x00d7
                           0000D6   427 _AC	=	0x00d6
                           0000D5   428 _F0	=	0x00d5
                           0000D4   429 _RS1	=	0x00d4
                           0000D3   430 _RS0	=	0x00d3
                           0000D2   431 _OV	=	0x00d2
                           0000D0   432 _P	=	0x00d0
                           0000CF   433 _TF2	=	0x00cf
                           0000CA   434 _TR2	=	0x00ca
                           0000C8   435 _CM_RL2	=	0x00c8
                           0000C6   436 _I2CEN	=	0x00c6
                           0000C5   437 _STA	=	0x00c5
                           0000C4   438 _STO	=	0x00c4
                           0000C3   439 _SI	=	0x00c3
                           0000C2   440 _AA	=	0x00c2
                           0000C0   441 _I2CPX	=	0x00c0
                           0000BE   442 _PADC	=	0x00be
                           0000BD   443 _PBOD	=	0x00bd
                           0000BC   444 _PS	=	0x00bc
                           0000BB   445 _PT1	=	0x00bb
                           0000BA   446 _PX1	=	0x00ba
                           0000B9   447 _PT0	=	0x00b9
                           0000B8   448 _PX0	=	0x00b8
                           0000B0   449 _P30	=	0x00b0
                           0000AF   450 _EA	=	0x00af
                           0000AE   451 _EADC	=	0x00ae
                           0000AD   452 _EBOD	=	0x00ad
                           0000AC   453 _ES	=	0x00ac
                           0000AB   454 _ET1	=	0x00ab
                           0000AA   455 _EX1	=	0x00aa
                           0000A9   456 _ET0	=	0x00a9
                           0000A8   457 _EX0	=	0x00a8
                           0000A0   458 _P20	=	0x00a0
                           00009F   459 _SM0	=	0x009f
                           00009F   460 _FE	=	0x009f
                           00009E   461 _SM1	=	0x009e
                           00009D   462 _SM2	=	0x009d
                           00009C   463 _REN	=	0x009c
                           00009B   464 _TB8	=	0x009b
                           00009A   465 _RB8	=	0x009a
                           000099   466 _TI	=	0x0099
                           000098   467 _RI	=	0x0098
                           000097   468 _P17	=	0x0097
                           000096   469 _P16	=	0x0096
                           000096   470 _TXD_1	=	0x0096
                           000095   471 _P15	=	0x0095
                           000094   472 _P14	=	0x0094
                           000094   473 _SDA	=	0x0094
                           000093   474 _P13	=	0x0093
                           000093   475 _SCL	=	0x0093
                           000092   476 _P12	=	0x0092
                           000091   477 _P11	=	0x0091
                           000090   478 _P10	=	0x0090
                           00008F   479 _TF1	=	0x008f
                           00008E   480 _TR1	=	0x008e
                           00008D   481 _TF0	=	0x008d
                           00008C   482 _TR0	=	0x008c
                           00008B   483 _IE1	=	0x008b
                           00008A   484 _IT1	=	0x008a
                           000089   485 _IE0	=	0x0089
                           000088   486 _IT0	=	0x0088
                           000087   487 _P07	=	0x0087
                           000087   488 _RXD	=	0x0087
                           000086   489 _P06	=	0x0086
                           000086   490 _TXD	=	0x0086
                           000085   491 _P05	=	0x0085
                           000084   492 _P04	=	0x0084
                           000084   493 _STADC	=	0x0084
                           000083   494 _P03	=	0x0083
                           000082   495 _P02	=	0x0082
                           000082   496 _RXD_1	=	0x0082
                           000081   497 _P01	=	0x0081
                           000081   498 _MISO	=	0x0081
                           000080   499 _P00	=	0x0080
                           000080   500 _MOSI	=	0x0080
                                    501 ;--------------------------------------------------------
                                    502 ; overlayable register banks
                                    503 ;--------------------------------------------------------
                                    504 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                        505 	.ds 8
                                    506 ;--------------------------------------------------------
                                    507 ; internal ram data
                                    508 ;--------------------------------------------------------
                                    509 	.area DSEG    (DATA)
      000008                        510 _line_sensors::
      000008                        511 	.ds 11
      000013                        512 _line_pattern::
      000013                        513 	.ds 2
                                    514 ;--------------------------------------------------------
                                    515 ; overlayable items in internal ram
                                    516 ;--------------------------------------------------------
                                    517 	.area	OSEG    (OVR,DATA)
                                    518 	.area	OSEG    (OVR,DATA)
                                    519 ;--------------------------------------------------------
                                    520 ; Stack segment in internal ram
                                    521 ;--------------------------------------------------------
                                    522 	.area SSEG
      000052                        523 __start__stack:
      000052                        524 	.ds	1
                                    525 
                                    526 ;--------------------------------------------------------
                                    527 ; indirectly addressable internal ram data
                                    528 ;--------------------------------------------------------
                                    529 	.area ISEG    (DATA)
                                    530 ;--------------------------------------------------------
                                    531 ; absolute internal ram data
                                    532 ;--------------------------------------------------------
                                    533 	.area IABS    (ABS,DATA)
                                    534 	.area IABS    (ABS,DATA)
                                    535 ;--------------------------------------------------------
                                    536 ; bit data
                                    537 ;--------------------------------------------------------
                                    538 	.area BSEG    (BIT)
                                    539 ;--------------------------------------------------------
                                    540 ; paged external ram data
                                    541 ;--------------------------------------------------------
                                    542 	.area PSEG    (PAG,XDATA)
                                    543 ;--------------------------------------------------------
                                    544 ; uninitialized external ram data
                                    545 ;--------------------------------------------------------
                                    546 	.area XSEG    (XDATA)
                                    547 ;--------------------------------------------------------
                                    548 ; absolute external ram data
                                    549 ;--------------------------------------------------------
                                    550 	.area XABS    (ABS,XDATA)
                                    551 ;--------------------------------------------------------
                                    552 ; initialized external ram data
                                    553 ;--------------------------------------------------------
                                    554 	.area HOME    (CODE)
                                    555 	.area GSINIT0 (CODE)
                                    556 	.area GSINIT1 (CODE)
                                    557 	.area GSINIT2 (CODE)
                                    558 	.area GSINIT3 (CODE)
                                    559 	.area GSINIT4 (CODE)
                                    560 	.area GSINIT5 (CODE)
                                    561 	.area GSINIT  (CODE)
                                    562 	.area GSFINAL (CODE)
                                    563 	.area CSEG    (CODE)
                                    564 ;--------------------------------------------------------
                                    565 ; interrupt vector
                                    566 ;--------------------------------------------------------
                                    567 	.area HOME    (CODE)
      000000                        568 __interrupt_vect:
      000000 02 00 4C         [24]  569 	ljmp	__sdcc_gsinit_startup
                                    570 ; restartable atomic support routines
      000003                        571 	.ds	5
      000008                        572 sdcc_atomic_exchange_rollback_start::
      000008 00               [12]  573 	nop
      000009 00               [12]  574 	nop
      00000A                        575 sdcc_atomic_exchange_pdata_impl:
      00000A E2               [24]  576 	movx	a, @r0
      00000B FB               [12]  577 	mov	r3, a
      00000C EA               [12]  578 	mov	a, r2
      00000D F2               [24]  579 	movx	@r0, a
      00000E 80 2C            [24]  580 	sjmp	sdcc_atomic_exchange_exit
      000010 00               [12]  581 	nop
      000011 00               [12]  582 	nop
      000012                        583 sdcc_atomic_exchange_xdata_impl:
      000012 E0               [24]  584 	movx	a, @dptr
      000013 FB               [12]  585 	mov	r3, a
      000014 EA               [12]  586 	mov	a, r2
      000015 F0               [24]  587 	movx	@dptr, a
      000016 80 24            [24]  588 	sjmp	sdcc_atomic_exchange_exit
      000018                        589 sdcc_atomic_compare_exchange_idata_impl:
      000018 E6               [12]  590 	mov	a, @r0
      000019 B5 02 02         [24]  591 	cjne	a, ar2, .+#5
      00001C EB               [12]  592 	mov	a, r3
      00001D F6               [12]  593 	mov	@r0, a
      00001E 22               [24]  594 	ret
      00001F 00               [12]  595 	nop
      000020                        596 sdcc_atomic_compare_exchange_pdata_impl:
      000020 E2               [24]  597 	movx	a, @r0
      000021 B5 02 02         [24]  598 	cjne	a, ar2, .+#5
      000024 EB               [12]  599 	mov	a, r3
      000025 F2               [24]  600 	movx	@r0, a
      000026 22               [24]  601 	ret
      000027 00               [12]  602 	nop
      000028                        603 sdcc_atomic_compare_exchange_xdata_impl:
      000028 E0               [24]  604 	movx	a, @dptr
      000029 B5 02 02         [24]  605 	cjne	a, ar2, .+#5
      00002C EB               [12]  606 	mov	a, r3
      00002D F0               [24]  607 	movx	@dptr, a
      00002E 22               [24]  608 	ret
      00002F                        609 sdcc_atomic_exchange_rollback_end::
                                    610 
      00002F                        611 sdcc_atomic_exchange_gptr_impl::
      00002F 30 F6 E0         [24]  612 	jnb	b.6, sdcc_atomic_exchange_xdata_impl
      000032 A8 82            [24]  613 	mov	r0, dpl
      000034 20 F5 D3         [24]  614 	jb	b.5, sdcc_atomic_exchange_pdata_impl
      000037                        615 sdcc_atomic_exchange_idata_impl:
      000037 EA               [12]  616 	mov	a, r2
      000038 C6               [12]  617 	xch	a, @r0
      000039 F5 82            [12]  618 	mov	dpl, a
      00003B 22               [24]  619 	ret
      00003C                        620 sdcc_atomic_exchange_exit:
      00003C 8B 82            [24]  621 	mov	dpl, r3
      00003E 22               [24]  622 	ret
      00003F                        623 sdcc_atomic_compare_exchange_gptr_impl::
      00003F 30 F6 E6         [24]  624 	jnb	b.6, sdcc_atomic_compare_exchange_xdata_impl
      000042 A8 82            [24]  625 	mov	r0, dpl
      000044 20 F5 D9         [24]  626 	jb	b.5, sdcc_atomic_compare_exchange_pdata_impl
      000047 80 CF            [24]  627 	sjmp	sdcc_atomic_compare_exchange_idata_impl
                                    628 ;--------------------------------------------------------
                                    629 ; global & static initialisations
                                    630 ;--------------------------------------------------------
                                    631 	.area HOME    (CODE)
                                    632 	.area GSINIT  (CODE)
                                    633 	.area GSFINAL (CODE)
                                    634 	.area GSINIT  (CODE)
                                    635 	.globl __sdcc_gsinit_startup
                                    636 	.globl __sdcc_program_startup
                                    637 	.globl __start__stack
                                    638 	.globl __mcs51_genRAMCLEAR
                                    639 ;	src/main.c:23: unsigned int line_pattern = 0;
      00005F E4               [12]  640 	clr	a
      000060 F5 13            [12]  641 	mov	_line_pattern,a
      000062 F5 14            [12]  642 	mov	(_line_pattern + 1),a
                                    643 	.area GSFINAL (CODE)
      000064 02 00 49         [24]  644 	ljmp	__sdcc_program_startup
                                    645 ;--------------------------------------------------------
                                    646 ; Home
                                    647 ;--------------------------------------------------------
                                    648 	.area HOME    (CODE)
                                    649 	.area HOME    (CODE)
      000049                        650 __sdcc_program_startup:
      000049 02 03 DD         [24]  651 	ljmp	_main
                                    652 ;	return from main will return to caller
                                    653 ;--------------------------------------------------------
                                    654 ; code
                                    655 ;--------------------------------------------------------
                                    656 	.area CSEG    (CODE)
                                    657 ;------------------------------------------------------------
                                    658 ;Allocation info for local variables in function 'putchar'
                                    659 ;------------------------------------------------------------
                                    660 ;c             Allocated to registers r6 r7 
                                    661 ;------------------------------------------------------------
                                    662 ;	src/main.c:14: int putchar(int c) {
                                    663 ;	-----------------------------------------
                                    664 ;	 function putchar
                                    665 ;	-----------------------------------------
      000067                        666 _putchar:
                           000007   667 	ar7 = 0x07
                           000006   668 	ar6 = 0x06
                           000005   669 	ar5 = 0x05
                           000004   670 	ar4 = 0x04
                           000003   671 	ar3 = 0x03
                           000002   672 	ar2 = 0x02
                           000001   673 	ar1 = 0x01
                           000000   674 	ar0 = 0x00
      000067 AE 82            [24]  675 	mov	r6, dpl
      000069 AF 83            [24]  676 	mov	r7, dph
                                    677 ;	src/main.c:15: while (!TI);
      00006B                        678 00101$:
                                    679 ;	src/main.c:16: TI = 0;
                                    680 ;	assignBit
      00006B 10 99 02         [24]  681 	jbc	_TI,00118$
      00006E 80 FB            [24]  682 	sjmp	00101$
      000070                        683 00118$:
                                    684 ;	src/main.c:17: SBUF = c;
      000070 8E 99            [24]  685 	mov	_SBUF,r6
                                    686 ;	src/main.c:18: return c;
      000072 8E 82            [24]  687 	mov	dpl, r6
      000074 8F 83            [24]  688 	mov	dph, r7
                                    689 ;	src/main.c:19: }
      000076 22               [24]  690 	ret
                                    691 ;------------------------------------------------------------
                                    692 ;Allocation info for local variables in function 'GPIO_Init'
                                    693 ;------------------------------------------------------------
                                    694 ;	src/main.c:28: void GPIO_Init(void)
                                    695 ;	-----------------------------------------
                                    696 ;	 function GPIO_Init
                                    697 ;	-----------------------------------------
      000077                        698 _GPIO_Init:
                                    699 ;	src/main.c:31: P15_Input_Mode;
      000077 43 B3 20         [24]  700 	orl	_P1M1,#0x20
      00007A 53 B4 DF         [24]  701 	anl	_P1M2,#0xdf
                                    702 ;	src/main.c:32: set_P1S_5;
                                    703 ;	assignBit
      00007D A2 AF            [12]  704 	mov	c,_EA
      00007F 92 00            [24]  705 	mov	_BIT_TMP,c
      000081 75 C7 AA         [24]  706 	mov	_TA,#0xaa
      000084 75 C7 55         [24]  707 	mov	_TA,#0x55
      000087 75 91 01         [24]  708 	mov	_SFRS,#0x01
      00008A 43 B3 20         [24]  709 	orl	_P1S,#0x20
      00008D 75 C7 AA         [24]  710 	mov	_TA,#0xaa
      000090 75 C7 55         [24]  711 	mov	_TA,#0x55
      000093 75 91 00         [24]  712 	mov	_SFRS,#0x00
                                    713 ;	assignBit
      000096 A2 00            [12]  714 	mov	c,_BIT_TMP
      000098 92 AF            [24]  715 	mov	_EA,c
                                    716 ;	src/main.c:35: P05_Input_Mode;
      00009A 43 B1 20         [24]  717 	orl	_P0M1,#0x20
      00009D 53 B2 DF         [24]  718 	anl	_P0M2,#0xdf
                                    719 ;	src/main.c:36: set_P0S_5;
                                    720 ;	assignBit
      0000A0 A2 AF            [12]  721 	mov	c,_EA
      0000A2 92 00            [24]  722 	mov	_BIT_TMP,c
      0000A4 75 C7 AA         [24]  723 	mov	_TA,#0xaa
      0000A7 75 C7 55         [24]  724 	mov	_TA,#0x55
      0000AA 75 91 01         [24]  725 	mov	_SFRS,#0x01
      0000AD 43 B1 20         [24]  726 	orl	_P0S,#0x20
      0000B0 75 C7 AA         [24]  727 	mov	_TA,#0xaa
      0000B3 75 C7 55         [24]  728 	mov	_TA,#0x55
      0000B6 75 91 00         [24]  729 	mov	_SFRS,#0x00
                                    730 ;	assignBit
      0000B9 A2 00            [12]  731 	mov	c,_BIT_TMP
      0000BB 92 AF            [24]  732 	mov	_EA,c
                                    733 ;	src/main.c:39: P04_Input_Mode;
      0000BD 43 B1 10         [24]  734 	orl	_P0M1,#0x10
      0000C0 53 B2 EF         [24]  735 	anl	_P0M2,#0xef
                                    736 ;	src/main.c:40: set_P0S_4;
                                    737 ;	assignBit
      0000C3 A2 AF            [12]  738 	mov	c,_EA
      0000C5 92 00            [24]  739 	mov	_BIT_TMP,c
      0000C7 75 C7 AA         [24]  740 	mov	_TA,#0xaa
      0000CA 75 C7 55         [24]  741 	mov	_TA,#0x55
      0000CD 75 91 01         [24]  742 	mov	_SFRS,#0x01
      0000D0 43 B1 10         [24]  743 	orl	_P0S,#0x10
      0000D3 75 C7 AA         [24]  744 	mov	_TA,#0xaa
      0000D6 75 C7 55         [24]  745 	mov	_TA,#0x55
      0000D9 75 91 00         [24]  746 	mov	_SFRS,#0x00
                                    747 ;	assignBit
      0000DC A2 00            [12]  748 	mov	c,_BIT_TMP
      0000DE 92 AF            [24]  749 	mov	_EA,c
                                    750 ;	src/main.c:43: P03_Input_Mode;
      0000E0 43 B1 08         [24]  751 	orl	_P0M1,#0x08
      0000E3 53 B2 F7         [24]  752 	anl	_P0M2,#0xf7
                                    753 ;	src/main.c:44: set_P0S_3;
                                    754 ;	assignBit
      0000E6 A2 AF            [12]  755 	mov	c,_EA
      0000E8 92 00            [24]  756 	mov	_BIT_TMP,c
      0000EA 75 C7 AA         [24]  757 	mov	_TA,#0xaa
      0000ED 75 C7 55         [24]  758 	mov	_TA,#0x55
      0000F0 75 91 01         [24]  759 	mov	_SFRS,#0x01
      0000F3 43 B1 08         [24]  760 	orl	_P0S,#0x08
      0000F6 75 C7 AA         [24]  761 	mov	_TA,#0xaa
      0000F9 75 C7 55         [24]  762 	mov	_TA,#0x55
      0000FC 75 91 00         [24]  763 	mov	_SFRS,#0x00
                                    764 ;	assignBit
      0000FF A2 00            [12]  765 	mov	c,_BIT_TMP
      000101 92 AF            [24]  766 	mov	_EA,c
                                    767 ;	src/main.c:47: P01_Input_Mode;
      000103 43 B1 02         [24]  768 	orl	_P0M1,#0x02
      000106 53 B2 FD         [24]  769 	anl	_P0M2,#0xfd
                                    770 ;	src/main.c:48: set_P0S_1;
                                    771 ;	assignBit
      000109 A2 AF            [12]  772 	mov	c,_EA
      00010B 92 00            [24]  773 	mov	_BIT_TMP,c
      00010D 75 C7 AA         [24]  774 	mov	_TA,#0xaa
      000110 75 C7 55         [24]  775 	mov	_TA,#0x55
      000113 75 91 01         [24]  776 	mov	_SFRS,#0x01
      000116 43 B1 02         [24]  777 	orl	_P0S,#0x02
      000119 75 C7 AA         [24]  778 	mov	_TA,#0xaa
      00011C 75 C7 55         [24]  779 	mov	_TA,#0x55
      00011F 75 91 00         [24]  780 	mov	_SFRS,#0x00
                                    781 ;	assignBit
      000122 A2 00            [12]  782 	mov	c,_BIT_TMP
      000124 92 AF            [24]  783 	mov	_EA,c
                                    784 ;	src/main.c:51: P00_Input_Mode;
      000126 43 B1 01         [24]  785 	orl	_P0M1,#0x01
      000129 53 B2 FE         [24]  786 	anl	_P0M2,#0xfe
                                    787 ;	src/main.c:52: set_P0S_0;
                                    788 ;	assignBit
      00012C A2 AF            [12]  789 	mov	c,_EA
      00012E 92 00            [24]  790 	mov	_BIT_TMP,c
      000130 75 C7 AA         [24]  791 	mov	_TA,#0xaa
      000133 75 C7 55         [24]  792 	mov	_TA,#0x55
      000136 75 91 01         [24]  793 	mov	_SFRS,#0x01
      000139 43 B1 01         [24]  794 	orl	_P0S,#0x01
      00013C 75 C7 AA         [24]  795 	mov	_TA,#0xaa
      00013F 75 C7 55         [24]  796 	mov	_TA,#0x55
      000142 75 91 00         [24]  797 	mov	_SFRS,#0x00
                                    798 ;	assignBit
      000145 A2 00            [12]  799 	mov	c,_BIT_TMP
      000147 92 AF            [24]  800 	mov	_EA,c
                                    801 ;	src/main.c:55: P10_Input_Mode;
      000149 43 B3 01         [24]  802 	orl	_P1M1,#0x01
      00014C 53 B4 FE         [24]  803 	anl	_P1M2,#0xfe
                                    804 ;	src/main.c:56: set_P1S_0;
                                    805 ;	assignBit
      00014F A2 AF            [12]  806 	mov	c,_EA
      000151 92 00            [24]  807 	mov	_BIT_TMP,c
      000153 75 C7 AA         [24]  808 	mov	_TA,#0xaa
      000156 75 C7 55         [24]  809 	mov	_TA,#0x55
      000159 75 91 01         [24]  810 	mov	_SFRS,#0x01
      00015C 43 B3 01         [24]  811 	orl	_P1S,#0x01
      00015F 75 C7 AA         [24]  812 	mov	_TA,#0xaa
      000162 75 C7 55         [24]  813 	mov	_TA,#0x55
      000165 75 91 00         [24]  814 	mov	_SFRS,#0x00
                                    815 ;	assignBit
      000168 A2 00            [12]  816 	mov	c,_BIT_TMP
      00016A 92 AF            [24]  817 	mov	_EA,c
                                    818 ;	src/main.c:59: P11_Input_Mode;
      00016C 43 B3 02         [24]  819 	orl	_P1M1,#0x02
      00016F 53 B4 FD         [24]  820 	anl	_P1M2,#0xfd
                                    821 ;	src/main.c:60: set_P1S_1;
                                    822 ;	assignBit
      000172 A2 AF            [12]  823 	mov	c,_EA
      000174 92 00            [24]  824 	mov	_BIT_TMP,c
      000176 75 C7 AA         [24]  825 	mov	_TA,#0xaa
      000179 75 C7 55         [24]  826 	mov	_TA,#0x55
      00017C 75 91 01         [24]  827 	mov	_SFRS,#0x01
      00017F 43 B3 02         [24]  828 	orl	_P1S,#0x02
      000182 75 C7 AA         [24]  829 	mov	_TA,#0xaa
      000185 75 C7 55         [24]  830 	mov	_TA,#0x55
      000188 75 91 00         [24]  831 	mov	_SFRS,#0x00
                                    832 ;	assignBit
      00018B A2 00            [12]  833 	mov	c,_BIT_TMP
      00018D 92 AF            [24]  834 	mov	_EA,c
                                    835 ;	src/main.c:63: P12_Input_Mode;
      00018F 43 B3 04         [24]  836 	orl	_P1M1,#0x04
      000192 53 B4 FB         [24]  837 	anl	_P1M2,#0xfb
                                    838 ;	src/main.c:64: set_P1S_2;
                                    839 ;	assignBit
      000195 A2 AF            [12]  840 	mov	c,_EA
      000197 92 00            [24]  841 	mov	_BIT_TMP,c
      000199 75 C7 AA         [24]  842 	mov	_TA,#0xaa
      00019C 75 C7 55         [24]  843 	mov	_TA,#0x55
      00019F 75 91 01         [24]  844 	mov	_SFRS,#0x01
      0001A2 43 B3 04         [24]  845 	orl	_P1S,#0x04
      0001A5 75 C7 AA         [24]  846 	mov	_TA,#0xaa
      0001A8 75 C7 55         [24]  847 	mov	_TA,#0x55
      0001AB 75 91 00         [24]  848 	mov	_SFRS,#0x00
                                    849 ;	assignBit
      0001AE A2 00            [12]  850 	mov	c,_BIT_TMP
      0001B0 92 AF            [24]  851 	mov	_EA,c
                                    852 ;	src/main.c:67: P13_Input_Mode;
      0001B2 43 B3 08         [24]  853 	orl	_P1M1,#0x08
      0001B5 53 B4 F7         [24]  854 	anl	_P1M2,#0xf7
                                    855 ;	src/main.c:68: set_P1S_3;
                                    856 ;	assignBit
      0001B8 A2 AF            [12]  857 	mov	c,_EA
      0001BA 92 00            [24]  858 	mov	_BIT_TMP,c
      0001BC 75 C7 AA         [24]  859 	mov	_TA,#0xaa
      0001BF 75 C7 55         [24]  860 	mov	_TA,#0x55
      0001C2 75 91 01         [24]  861 	mov	_SFRS,#0x01
      0001C5 43 B3 08         [24]  862 	orl	_P1S,#0x08
      0001C8 75 C7 AA         [24]  863 	mov	_TA,#0xaa
      0001CB 75 C7 55         [24]  864 	mov	_TA,#0x55
      0001CE 75 91 00         [24]  865 	mov	_SFRS,#0x00
                                    866 ;	assignBit
      0001D1 A2 00            [12]  867 	mov	c,_BIT_TMP
      0001D3 92 AF            [24]  868 	mov	_EA,c
                                    869 ;	src/main.c:71: P14_Input_Mode;
      0001D5 43 B3 10         [24]  870 	orl	_P1M1,#0x10
      0001D8 53 B4 EF         [24]  871 	anl	_P1M2,#0xef
                                    872 ;	src/main.c:72: set_P1S_4;
                                    873 ;	assignBit
      0001DB A2 AF            [12]  874 	mov	c,_EA
      0001DD 92 00            [24]  875 	mov	_BIT_TMP,c
      0001DF 75 C7 AA         [24]  876 	mov	_TA,#0xaa
      0001E2 75 C7 55         [24]  877 	mov	_TA,#0x55
      0001E5 75 91 01         [24]  878 	mov	_SFRS,#0x01
      0001E8 43 B3 10         [24]  879 	orl	_P1S,#0x10
      0001EB 75 C7 AA         [24]  880 	mov	_TA,#0xaa
      0001EE 75 C7 55         [24]  881 	mov	_TA,#0x55
      0001F1 75 91 00         [24]  882 	mov	_SFRS,#0x00
                                    883 ;	assignBit
      0001F4 A2 00            [12]  884 	mov	c,_BIT_TMP
      0001F6 92 AF            [24]  885 	mov	_EA,c
                                    886 ;	src/main.c:73: }
      0001F8 22               [24]  887 	ret
                                    888 ;------------------------------------------------------------
                                    889 ;Allocation info for local variables in function 'UART_Init'
                                    890 ;------------------------------------------------------------
                                    891 ;	src/main.c:78: void UART_Init(void)
                                    892 ;	-----------------------------------------
                                    893 ;	 function UART_Init
                                    894 ;	-----------------------------------------
      0001F9                        895 _UART_Init:
                                    896 ;	src/main.c:80: InitialUART0_Timer1(115200);  // 115200 baud rate
      0001F9 90 C2 00         [24]  897 	mov	dptr,#0xc200
      0001FC 75 F0 01         [24]  898 	mov	b, #0x01
      0001FF E4               [12]  899 	clr	a
      000200 12 05 66         [24]  900 	lcall	_InitialUART0_Timer1
                                    901 ;	src/main.c:82: P0M1 &= ~(1 << 6); 
      000203 53 B1 BF         [24]  902 	anl	_P0M1,#0xbf
                                    903 ;	src/main.c:84: P0M2 |= (1 << 6);
      000206 43 B2 40         [24]  904 	orl	_P0M2,#0x40
                                    905 ;	src/main.c:85: }
      000209 22               [24]  906 	ret
                                    907 ;------------------------------------------------------------
                                    908 ;Allocation info for local variables in function 'Read_Line_Sensors'
                                    909 ;------------------------------------------------------------
                                    910 ;	src/main.c:90: void Read_Line_Sensors(void)
                                    911 ;	-----------------------------------------
                                    912 ;	 function Read_Line_Sensors
                                    913 ;	-----------------------------------------
      00020A                        914 _Read_Line_Sensors:
                                    915 ;	src/main.c:92: line_sensors[0]  = P15;  // LINE1
      00020A A2 95            [12]  916 	mov	c,_P15
      00020C E4               [12]  917 	clr	a
      00020D 33               [12]  918 	rlc	a
      00020E F5 08            [12]  919 	mov	_line_sensors, a
                                    920 ;	src/main.c:93: line_sensors[1]  = P05;  // LINE2
      000210 A2 85            [12]  921 	mov	c,_P05
      000212 E4               [12]  922 	clr	a
      000213 33               [12]  923 	rlc	a
      000214 F5 09            [12]  924 	mov	(_line_sensors + 0x0001), a
                                    925 ;	src/main.c:94: line_sensors[2]  = P04;  // LINE3
      000216 A2 84            [12]  926 	mov	c,_P04
      000218 E4               [12]  927 	clr	a
      000219 33               [12]  928 	rlc	a
      00021A F5 0A            [12]  929 	mov	(_line_sensors + 0x0002), a
                                    930 ;	src/main.c:95: line_sensors[3]  = P03;  // LINE4
      00021C A2 83            [12]  931 	mov	c,_P03
      00021E E4               [12]  932 	clr	a
      00021F 33               [12]  933 	rlc	a
      000220 F5 0B            [12]  934 	mov	(_line_sensors + 0x0003), a
                                    935 ;	src/main.c:96: line_sensors[4]  = P01;  // LINE5
      000222 A2 81            [12]  936 	mov	c,_P01
      000224 E4               [12]  937 	clr	a
      000225 33               [12]  938 	rlc	a
      000226 F5 0C            [12]  939 	mov	(_line_sensors + 0x0004), a
                                    940 ;	src/main.c:97: line_sensors[5]  = P00;  // LINE6
      000228 A2 80            [12]  941 	mov	c,_P00
      00022A E4               [12]  942 	clr	a
      00022B 33               [12]  943 	rlc	a
      00022C F5 0D            [12]  944 	mov	(_line_sensors + 0x0005), a
                                    945 ;	src/main.c:98: line_sensors[6]  = P10;  // LINE7
      00022E A2 90            [12]  946 	mov	c,_P10
      000230 E4               [12]  947 	clr	a
      000231 33               [12]  948 	rlc	a
      000232 F5 0E            [12]  949 	mov	(_line_sensors + 0x0006), a
                                    950 ;	src/main.c:99: line_sensors[7]  = P11;  // LINE8
      000234 A2 91            [12]  951 	mov	c,_P11
      000236 E4               [12]  952 	clr	a
      000237 33               [12]  953 	rlc	a
      000238 F5 0F            [12]  954 	mov	(_line_sensors + 0x0007), a
                                    955 ;	src/main.c:100: line_sensors[8]  = P12;  // LINE9
      00023A A2 92            [12]  956 	mov	c,_P12
      00023C E4               [12]  957 	clr	a
      00023D 33               [12]  958 	rlc	a
      00023E F5 10            [12]  959 	mov	(_line_sensors + 0x0008), a
                                    960 ;	src/main.c:101: line_sensors[9]  = P13;  // LINE10
      000240 A2 93            [12]  961 	mov	c,_P13
      000242 E4               [12]  962 	clr	a
      000243 33               [12]  963 	rlc	a
      000244 F5 11            [12]  964 	mov	(_line_sensors + 0x0009), a
                                    965 ;	src/main.c:102: line_sensors[10] = P14;  // LINE11
      000246 A2 94            [12]  966 	mov	c,_P14
      000248 E4               [12]  967 	clr	a
      000249 33               [12]  968 	rlc	a
      00024A F5 12            [12]  969 	mov	(_line_sensors + 0x000a), a
                                    970 ;	src/main.c:103: }
      00024C 22               [24]  971 	ret
                                    972 ;------------------------------------------------------------
                                    973 ;Allocation info for local variables in function 'Get_Line_Pattern'
                                    974 ;------------------------------------------------------------
                                    975 ;pattern       Allocated to registers r6 r7 
                                    976 ;i             Allocated to registers r5 
                                    977 ;------------------------------------------------------------
                                    978 ;	src/main.c:108: unsigned int Get_Line_Pattern(void)
                                    979 ;	-----------------------------------------
                                    980 ;	 function Get_Line_Pattern
                                    981 ;	-----------------------------------------
      00024D                        982 _Get_Line_Pattern:
                                    983 ;	src/main.c:110: unsigned int pattern = 0;
      00024D 7E 00            [12]  984 	mov	r6,#0x00
      00024F 7F 00            [12]  985 	mov	r7,#0x00
                                    986 ;	src/main.c:113: for(i = 0; i < 11; i++)
      000251 7D 00            [12]  987 	mov	r5,#0x00
      000253                        988 00104$:
                                    989 ;	src/main.c:115: if(line_sensors[i] == 1)
      000253 ED               [12]  990 	mov	a,r5
      000254 24 08            [12]  991 	add	a, #_line_sensors
      000256 F9               [12]  992 	mov	r1,a
      000257 87 04            [24]  993 	mov	ar4,@r1
      000259 BC 01 19         [24]  994 	cjne	r4,#0x01,00105$
                                    995 ;	src/main.c:116: pattern |= (1 << i);
      00025C 8D F0            [24]  996 	mov	b,r5
      00025E 05 F0            [12]  997 	inc	b
      000260 7B 01            [12]  998 	mov	r3,#0x01
      000262 7C 00            [12]  999 	mov	r4,#0x00
      000264 80 06            [24] 1000 	sjmp	00130$
      000266                       1001 00129$:
      000266 EB               [12] 1002 	mov	a,r3
      000267 2B               [12] 1003 	add	a,r3
      000268 FB               [12] 1004 	mov	r3,a
      000269 EC               [12] 1005 	mov	a,r4
      00026A 33               [12] 1006 	rlc	a
      00026B FC               [12] 1007 	mov	r4,a
      00026C                       1008 00130$:
      00026C D5 F0 F7         [24] 1009 	djnz	b,00129$
      00026F EB               [12] 1010 	mov	a,r3
      000270 42 06            [12] 1011 	orl	ar6,a
      000272 EC               [12] 1012 	mov	a,r4
      000273 42 07            [12] 1013 	orl	ar7,a
      000275                       1014 00105$:
                                   1015 ;	src/main.c:113: for(i = 0; i < 11; i++)
      000275 0D               [12] 1016 	inc	r5
      000276 BD 0B 00         [24] 1017 	cjne	r5,#0x0b,00131$
      000279                       1018 00131$:
      000279 40 D8            [24] 1019 	jc	00104$
                                   1020 ;	src/main.c:119: return pattern;
      00027B 8E 82            [24] 1021 	mov	dpl, r6
      00027D 8F 83            [24] 1022 	mov	dph, r7
                                   1023 ;	src/main.c:120: }
      00027F 22               [24] 1024 	ret
                                   1025 ;------------------------------------------------------------
                                   1026 ;Allocation info for local variables in function 'Send_Pattern_Decimal'
                                   1027 ;------------------------------------------------------------
                                   1028 ;	src/main.c:126: void Send_Pattern_Decimal(void)
                                   1029 ;	-----------------------------------------
                                   1030 ;	 function Send_Pattern_Decimal
                                   1031 ;	-----------------------------------------
      000280                       1032 _Send_Pattern_Decimal:
                                   1033 ;	src/main.c:128: printf("%u\r\n", line_pattern);
      000280 C0 13            [24] 1034 	push	_line_pattern
      000282 C0 14            [24] 1035 	push	(_line_pattern + 1)
      000284 74 B9            [12] 1036 	mov	a,#___str_0
      000286 C0 E0            [24] 1037 	push	acc
      000288 74 0E            [12] 1038 	mov	a,#(___str_0 >> 8)
      00028A C0 E0            [24] 1039 	push	acc
      00028C 74 80            [12] 1040 	mov	a,#0x80
      00028E C0 E0            [24] 1041 	push	acc
      000290 12 07 0F         [24] 1042 	lcall	_printf
      000293 E5 81            [12] 1043 	mov	a,sp
      000295 24 FB            [12] 1044 	add	a,#0xfb
      000297 F5 81            [12] 1045 	mov	sp,a
                                   1046 ;	src/main.c:129: }
      000299 22               [24] 1047 	ret
                                   1048 ;------------------------------------------------------------
                                   1049 ;Allocation info for local variables in function 'Send_Individual_Values'
                                   1050 ;------------------------------------------------------------
                                   1051 ;i             Allocated to registers r7 
                                   1052 ;------------------------------------------------------------
                                   1053 ;	src/main.c:135: void Send_Individual_Values(void)
                                   1054 ;	-----------------------------------------
                                   1055 ;	 function Send_Individual_Values
                                   1056 ;	-----------------------------------------
      00029A                       1057 _Send_Individual_Values:
                                   1058 ;	src/main.c:139: for(i = 0; i < 11; i++)
      00029A 7F 00            [12] 1059 	mov	r7,#0x00
      00029C                       1060 00104$:
                                   1061 ;	src/main.c:141: printf("%u", line_sensors[i]);
      00029C EF               [12] 1062 	mov	a,r7
      00029D 24 08            [12] 1063 	add	a, #_line_sensors
      00029F F9               [12] 1064 	mov	r1,a
      0002A0 87 06            [24] 1065 	mov	ar6,@r1
      0002A2 7D 00            [12] 1066 	mov	r5,#0x00
      0002A4 C0 07            [24] 1067 	push	ar7
      0002A6 C0 06            [24] 1068 	push	ar6
      0002A8 C0 05            [24] 1069 	push	ar5
      0002AA 74 BE            [12] 1070 	mov	a,#___str_1
      0002AC C0 E0            [24] 1071 	push	acc
      0002AE 74 0E            [12] 1072 	mov	a,#(___str_1 >> 8)
      0002B0 C0 E0            [24] 1073 	push	acc
      0002B2 74 80            [12] 1074 	mov	a,#0x80
      0002B4 C0 E0            [24] 1075 	push	acc
      0002B6 12 07 0F         [24] 1076 	lcall	_printf
      0002B9 E5 81            [12] 1077 	mov	a,sp
      0002BB 24 FB            [12] 1078 	add	a,#0xfb
      0002BD F5 81            [12] 1079 	mov	sp,a
      0002BF D0 07            [24] 1080 	pop	ar7
                                   1081 ;	src/main.c:142: if(i < 10)
      0002C1 BF 0A 00         [24] 1082 	cjne	r7,#0x0a,00127$
      0002C4                       1083 00127$:
      0002C4 50 19            [24] 1084 	jnc	00105$
                                   1085 ;	src/main.c:143: printf(" ");
      0002C6 C0 07            [24] 1086 	push	ar7
      0002C8 74 C1            [12] 1087 	mov	a,#___str_2
      0002CA C0 E0            [24] 1088 	push	acc
      0002CC 74 0E            [12] 1089 	mov	a,#(___str_2 >> 8)
      0002CE C0 E0            [24] 1090 	push	acc
      0002D0 74 80            [12] 1091 	mov	a,#0x80
      0002D2 C0 E0            [24] 1092 	push	acc
      0002D4 12 07 0F         [24] 1093 	lcall	_printf
      0002D7 15 81            [12] 1094 	dec	sp
      0002D9 15 81            [12] 1095 	dec	sp
      0002DB 15 81            [12] 1096 	dec	sp
      0002DD D0 07            [24] 1097 	pop	ar7
      0002DF                       1098 00105$:
                                   1099 ;	src/main.c:139: for(i = 0; i < 11; i++)
      0002DF 0F               [12] 1100 	inc	r7
      0002E0 BF 0B 00         [24] 1101 	cjne	r7,#0x0b,00129$
      0002E3                       1102 00129$:
      0002E3 40 B7            [24] 1103 	jc	00104$
                                   1104 ;	src/main.c:145: printf("\r\n");
      0002E5 74 C3            [12] 1105 	mov	a,#___str_3
      0002E7 C0 E0            [24] 1106 	push	acc
      0002E9 74 0E            [12] 1107 	mov	a,#(___str_3 >> 8)
      0002EB C0 E0            [24] 1108 	push	acc
      0002ED 74 80            [12] 1109 	mov	a,#0x80
      0002EF C0 E0            [24] 1110 	push	acc
      0002F1 12 07 0F         [24] 1111 	lcall	_printf
      0002F4 15 81            [12] 1112 	dec	sp
      0002F6 15 81            [12] 1113 	dec	sp
      0002F8 15 81            [12] 1114 	dec	sp
                                   1115 ;	src/main.c:146: }
      0002FA 22               [24] 1116 	ret
                                   1117 ;------------------------------------------------------------
                                   1118 ;Allocation info for local variables in function 'Send_JSON_Format'
                                   1119 ;------------------------------------------------------------
                                   1120 ;i             Allocated to registers r7 
                                   1121 ;------------------------------------------------------------
                                   1122 ;	src/main.c:152: void Send_JSON_Format(void)
                                   1123 ;	-----------------------------------------
                                   1124 ;	 function Send_JSON_Format
                                   1125 ;	-----------------------------------------
      0002FB                       1126 _Send_JSON_Format:
                                   1127 ;	src/main.c:154: printf("{\"sensors\":[");
      0002FB 74 C6            [12] 1128 	mov	a,#___str_4
      0002FD C0 E0            [24] 1129 	push	acc
      0002FF 74 0E            [12] 1130 	mov	a,#(___str_4 >> 8)
      000301 C0 E0            [24] 1131 	push	acc
      000303 74 80            [12] 1132 	mov	a,#0x80
      000305 C0 E0            [24] 1133 	push	acc
      000307 12 07 0F         [24] 1134 	lcall	_printf
      00030A 15 81            [12] 1135 	dec	sp
      00030C 15 81            [12] 1136 	dec	sp
      00030E 15 81            [12] 1137 	dec	sp
                                   1138 ;	src/main.c:156: for(unsigned char i = 0; i < 11; i++)
      000310 7F 00            [12] 1139 	mov	r7,#0x00
      000312                       1140 00105$:
      000312 BF 0B 00         [24] 1141 	cjne	r7,#0x0b,00128$
      000315                       1142 00128$:
      000315 50 46            [24] 1143 	jnc	00103$
                                   1144 ;	src/main.c:158: printf("%u", line_sensors[i]);
      000317 EF               [12] 1145 	mov	a,r7
      000318 24 08            [12] 1146 	add	a, #_line_sensors
      00031A F9               [12] 1147 	mov	r1,a
      00031B 87 06            [24] 1148 	mov	ar6,@r1
      00031D 7D 00            [12] 1149 	mov	r5,#0x00
      00031F C0 07            [24] 1150 	push	ar7
      000321 C0 06            [24] 1151 	push	ar6
      000323 C0 05            [24] 1152 	push	ar5
      000325 74 BE            [12] 1153 	mov	a,#___str_1
      000327 C0 E0            [24] 1154 	push	acc
      000329 74 0E            [12] 1155 	mov	a,#(___str_1 >> 8)
      00032B C0 E0            [24] 1156 	push	acc
      00032D 74 80            [12] 1157 	mov	a,#0x80
      00032F C0 E0            [24] 1158 	push	acc
      000331 12 07 0F         [24] 1159 	lcall	_printf
      000334 E5 81            [12] 1160 	mov	a,sp
      000336 24 FB            [12] 1161 	add	a,#0xfb
      000338 F5 81            [12] 1162 	mov	sp,a
      00033A D0 07            [24] 1163 	pop	ar7
                                   1164 ;	src/main.c:159: if(i < 10)
      00033C BF 0A 00         [24] 1165 	cjne	r7,#0x0a,00130$
      00033F                       1166 00130$:
      00033F 50 19            [24] 1167 	jnc	00106$
                                   1168 ;	src/main.c:160: printf(",");
      000341 C0 07            [24] 1169 	push	ar7
      000343 74 D3            [12] 1170 	mov	a,#___str_5
      000345 C0 E0            [24] 1171 	push	acc
      000347 74 0E            [12] 1172 	mov	a,#(___str_5 >> 8)
      000349 C0 E0            [24] 1173 	push	acc
      00034B 74 80            [12] 1174 	mov	a,#0x80
      00034D C0 E0            [24] 1175 	push	acc
      00034F 12 07 0F         [24] 1176 	lcall	_printf
      000352 15 81            [12] 1177 	dec	sp
      000354 15 81            [12] 1178 	dec	sp
      000356 15 81            [12] 1179 	dec	sp
      000358 D0 07            [24] 1180 	pop	ar7
      00035A                       1181 00106$:
                                   1182 ;	src/main.c:156: for(unsigned char i = 0; i < 11; i++)
      00035A 0F               [12] 1183 	inc	r7
      00035B 80 B5            [24] 1184 	sjmp	00105$
      00035D                       1185 00103$:
                                   1186 ;	src/main.c:163: printf("],\"pattern\":%u}\r\n", line_pattern);
      00035D C0 13            [24] 1187 	push	_line_pattern
      00035F C0 14            [24] 1188 	push	(_line_pattern + 1)
      000361 74 D5            [12] 1189 	mov	a,#___str_6
      000363 C0 E0            [24] 1190 	push	acc
      000365 74 0E            [12] 1191 	mov	a,#(___str_6 >> 8)
      000367 C0 E0            [24] 1192 	push	acc
      000369 74 80            [12] 1193 	mov	a,#0x80
      00036B C0 E0            [24] 1194 	push	acc
      00036D 12 07 0F         [24] 1195 	lcall	_printf
      000370 E5 81            [12] 1196 	mov	a,sp
      000372 24 FB            [12] 1197 	add	a,#0xfb
      000374 F5 81            [12] 1198 	mov	sp,a
                                   1199 ;	src/main.c:164: }
      000376 22               [24] 1200 	ret
                                   1201 ;------------------------------------------------------------
                                   1202 ;Allocation info for local variables in function 'Send_Binary_String'
                                   1203 ;------------------------------------------------------------
                                   1204 ;i             Allocated to registers r7 
                                   1205 ;------------------------------------------------------------
                                   1206 ;	src/main.c:170: void Send_Binary_String(void)
                                   1207 ;	-----------------------------------------
                                   1208 ;	 function Send_Binary_String
                                   1209 ;	-----------------------------------------
      000377                       1210 _Send_Binary_String:
                                   1211 ;	src/main.c:174: for(i = 0; i < 11; i++)
      000377 7F 00            [12] 1212 	mov	r7,#0x00
      000379                       1213 00102$:
                                   1214 ;	src/main.c:176: printf("%c", line_sensors[i] ? '1' : '0');
      000379 EF               [12] 1215 	mov	a,r7
      00037A 24 08            [12] 1216 	add	a, #_line_sensors
      00037C F9               [12] 1217 	mov	r1,a
      00037D E7               [12] 1218 	mov	a,@r1
      00037E 60 06            [24] 1219 	jz	00106$
      000380 7D 31            [12] 1220 	mov	r5,#0x31
      000382 7E 00            [12] 1221 	mov	r6,#0x00
      000384 80 04            [24] 1222 	sjmp	00107$
      000386                       1223 00106$:
      000386 7D 30            [12] 1224 	mov	r5,#0x30
      000388 7E 00            [12] 1225 	mov	r6,#0x00
      00038A                       1226 00107$:
      00038A C0 07            [24] 1227 	push	ar7
      00038C C0 05            [24] 1228 	push	ar5
      00038E C0 06            [24] 1229 	push	ar6
      000390 74 E7            [12] 1230 	mov	a,#___str_7
      000392 C0 E0            [24] 1231 	push	acc
      000394 74 0E            [12] 1232 	mov	a,#(___str_7 >> 8)
      000396 C0 E0            [24] 1233 	push	acc
      000398 74 80            [12] 1234 	mov	a,#0x80
      00039A C0 E0            [24] 1235 	push	acc
      00039C 12 07 0F         [24] 1236 	lcall	_printf
      00039F E5 81            [12] 1237 	mov	a,sp
      0003A1 24 FB            [12] 1238 	add	a,#0xfb
      0003A3 F5 81            [12] 1239 	mov	sp,a
      0003A5 D0 07            [24] 1240 	pop	ar7
                                   1241 ;	src/main.c:174: for(i = 0; i < 11; i++)
      0003A7 0F               [12] 1242 	inc	r7
      0003A8 BF 0B 00         [24] 1243 	cjne	r7,#0x0b,00128$
      0003AB                       1244 00128$:
      0003AB 40 CC            [24] 1245 	jc	00102$
                                   1246 ;	src/main.c:178: printf("\r\n");
      0003AD 74 C3            [12] 1247 	mov	a,#___str_3
      0003AF C0 E0            [24] 1248 	push	acc
      0003B1 74 0E            [12] 1249 	mov	a,#(___str_3 >> 8)
      0003B3 C0 E0            [24] 1250 	push	acc
      0003B5 74 80            [12] 1251 	mov	a,#0x80
      0003B7 C0 E0            [24] 1252 	push	acc
      0003B9 12 07 0F         [24] 1253 	lcall	_printf
      0003BC 15 81            [12] 1254 	dec	sp
      0003BE 15 81            [12] 1255 	dec	sp
      0003C0 15 81            [12] 1256 	dec	sp
                                   1257 ;	src/main.c:179: }
      0003C2 22               [24] 1258 	ret
                                   1259 ;------------------------------------------------------------
                                   1260 ;Allocation info for local variables in function 'Send_Hex_Format'
                                   1261 ;------------------------------------------------------------
                                   1262 ;	src/main.c:185: void Send_Hex_Format(void)
                                   1263 ;	-----------------------------------------
                                   1264 ;	 function Send_Hex_Format
                                   1265 ;	-----------------------------------------
      0003C3                       1266 _Send_Hex_Format:
                                   1267 ;	src/main.c:187: printf("L:%03X\r\n", line_pattern);
      0003C3 C0 13            [24] 1268 	push	_line_pattern
      0003C5 C0 14            [24] 1269 	push	(_line_pattern + 1)
      0003C7 74 EA            [12] 1270 	mov	a,#___str_8
      0003C9 C0 E0            [24] 1271 	push	acc
      0003CB 74 0E            [12] 1272 	mov	a,#(___str_8 >> 8)
      0003CD C0 E0            [24] 1273 	push	acc
      0003CF 74 80            [12] 1274 	mov	a,#0x80
      0003D1 C0 E0            [24] 1275 	push	acc
      0003D3 12 07 0F         [24] 1276 	lcall	_printf
      0003D6 E5 81            [12] 1277 	mov	a,sp
      0003D8 24 FB            [12] 1278 	add	a,#0xfb
      0003DA F5 81            [12] 1279 	mov	sp,a
                                   1280 ;	src/main.c:188: }
      0003DC 22               [24] 1281 	ret
                                   1282 ;------------------------------------------------------------
                                   1283 ;Allocation info for local variables in function 'main'
                                   1284 ;------------------------------------------------------------
                                   1285 ;	src/main.c:193: void main(void) 
                                   1286 ;	-----------------------------------------
                                   1287 ;	 function main
                                   1288 ;	-----------------------------------------
      0003DD                       1289 _main:
                                   1290 ;	src/main.c:196: Set_All_GPIO_Quasi_Mode;
      0003DD 75 B1 00         [24] 1291 	mov	_P0M1,#0x00
      0003E0 75 B2 00         [24] 1292 	mov	_P0M2,#0x00
      0003E3 75 B3 00         [24] 1293 	mov	_P1M1,#0x00
      0003E6 75 B4 00         [24] 1294 	mov	_P1M2,#0x00
      0003E9 75 AC 00         [24] 1295 	mov	_P3M1,#0x00
      0003EC 75 AD 00         [24] 1296 	mov	_P3M2,#0x00
                                   1297 ;	src/main.c:197: GPIO_Init();
      0003EF 12 00 77         [24] 1298 	lcall	_GPIO_Init
                                   1299 ;	src/main.c:198: UART_Init();
      0003F2 12 01 F9         [24] 1300 	lcall	_UART_Init
                                   1301 ;	src/main.c:201: Timer0_Delay1ms(100);
      0003F5 90 00 64         [24] 1302 	mov	dptr,#0x0064
      0003F8 E4               [12] 1303 	clr	a
      0003F9 F5 F0            [12] 1304 	mov	b,a
      0003FB 12 04 5F         [24] 1305 	lcall	_Timer0_Delay1ms
                                   1306 ;	src/main.c:204: printf("Line Follower Started\r\n");
      0003FE 74 F3            [12] 1307 	mov	a,#___str_9
      000400 C0 E0            [24] 1308 	push	acc
      000402 74 0E            [12] 1309 	mov	a,#(___str_9 >> 8)
      000404 C0 E0            [24] 1310 	push	acc
      000406 74 80            [12] 1311 	mov	a,#0x80
      000408 C0 E0            [24] 1312 	push	acc
      00040A 12 07 0F         [24] 1313 	lcall	_printf
      00040D 15 81            [12] 1314 	dec	sp
      00040F 15 81            [12] 1315 	dec	sp
      000411 15 81            [12] 1316 	dec	sp
                                   1317 ;	src/main.c:206: while(1)
      000413                       1318 00102$:
                                   1319 ;	src/main.c:209: Read_Line_Sensors();
      000413 12 02 0A         [24] 1320 	lcall	_Read_Line_Sensors
                                   1321 ;	src/main.c:212: line_pattern = Get_Line_Pattern();
      000416 12 02 4D         [24] 1322 	lcall	_Get_Line_Pattern
      000419 85 82 13         [24] 1323 	mov	_line_pattern,dpl
      00041C 85 83 14         [24] 1324 	mov	(_line_pattern + 1),dph
                                   1325 ;	src/main.c:222: Send_JSON_Format();
      00041F 12 02 FB         [24] 1326 	lcall	_Send_JSON_Format
                                   1327 ;	src/main.c:231: Timer0_Delay1ms(30);  // 50ms = 20Hz update rate
      000422 90 00 1E         [24] 1328 	mov	dptr,#0x001e
      000425 E4               [12] 1329 	clr	a
      000426 F5 F0            [12] 1330 	mov	b,a
      000428 12 04 5F         [24] 1331 	lcall	_Timer0_Delay1ms
                                   1332 ;	src/main.c:233: }
      00042B 80 E6            [24] 1333 	sjmp	00102$
                                   1334 	.area CSEG    (CODE)
                                   1335 	.area CONST   (CODE)
                                   1336 	.area CONST   (CODE)
      000EB9                       1337 ___str_0:
      000EB9 25 75                 1338 	.ascii "%u"
      000EBB 0D                    1339 	.db 0x0d
      000EBC 0A                    1340 	.db 0x0a
      000EBD 00                    1341 	.db 0x00
                                   1342 	.area CSEG    (CODE)
                                   1343 	.area CONST   (CODE)
      000EBE                       1344 ___str_1:
      000EBE 25 75                 1345 	.ascii "%u"
      000EC0 00                    1346 	.db 0x00
                                   1347 	.area CSEG    (CODE)
                                   1348 	.area CONST   (CODE)
      000EC1                       1349 ___str_2:
      000EC1 20                    1350 	.ascii " "
      000EC2 00                    1351 	.db 0x00
                                   1352 	.area CSEG    (CODE)
                                   1353 	.area CONST   (CODE)
      000EC3                       1354 ___str_3:
      000EC3 0D                    1355 	.db 0x0d
      000EC4 0A                    1356 	.db 0x0a
      000EC5 00                    1357 	.db 0x00
                                   1358 	.area CSEG    (CODE)
                                   1359 	.area CONST   (CODE)
      000EC6                       1360 ___str_4:
      000EC6 7B                    1361 	.ascii "{"
      000EC7 22                    1362 	.db 0x22
      000EC8 73 65 6E 73 6F 72 73  1363 	.ascii "sensors"
      000ECF 22                    1364 	.db 0x22
      000ED0 3A 5B                 1365 	.ascii ":["
      000ED2 00                    1366 	.db 0x00
                                   1367 	.area CSEG    (CODE)
                                   1368 	.area CONST   (CODE)
      000ED3                       1369 ___str_5:
      000ED3 2C                    1370 	.ascii ","
      000ED4 00                    1371 	.db 0x00
                                   1372 	.area CSEG    (CODE)
                                   1373 	.area CONST   (CODE)
      000ED5                       1374 ___str_6:
      000ED5 5D 2C                 1375 	.ascii "],"
      000ED7 22                    1376 	.db 0x22
      000ED8 70 61 74 74 65 72 6E  1377 	.ascii "pattern"
      000EDF 22                    1378 	.db 0x22
      000EE0 3A 25 75 7D           1379 	.ascii ":%u}"
      000EE4 0D                    1380 	.db 0x0d
      000EE5 0A                    1381 	.db 0x0a
      000EE6 00                    1382 	.db 0x00
                                   1383 	.area CSEG    (CODE)
                                   1384 	.area CONST   (CODE)
      000EE7                       1385 ___str_7:
      000EE7 25 63                 1386 	.ascii "%c"
      000EE9 00                    1387 	.db 0x00
                                   1388 	.area CSEG    (CODE)
                                   1389 	.area CONST   (CODE)
      000EEA                       1390 ___str_8:
      000EEA 4C 3A 25 30 33 58     1391 	.ascii "L:%03X"
      000EF0 0D                    1392 	.db 0x0d
      000EF1 0A                    1393 	.db 0x0a
      000EF2 00                    1394 	.db 0x00
                                   1395 	.area CSEG    (CODE)
                                   1396 	.area CONST   (CODE)
      000EF3                       1397 ___str_9:
      000EF3 4C 69 6E 65 20 46 6F  1398 	.ascii "Line Follower Started"
             6C 6C 6F 77 65 72 20
             53 74 61 72 74 65 64
      000F08 0D                    1399 	.db 0x0d
      000F09 0A                    1400 	.db 0x0a
      000F0A 00                    1401 	.db 0x00
                                   1402 	.area CSEG    (CODE)
                                   1403 	.area CABS    (ABS,CODE)
