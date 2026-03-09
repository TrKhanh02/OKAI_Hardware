                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ISO C Compiler 
                                      3 ; Version 4.4.0 #14620 (MINGW32)
                                      4 ;--------------------------------------------------------
                                      5 	.module json
                                      6 	.optsdcc -mmcs51 --model-small
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _parse_json_PARM_9
                                     12 	.globl _parse_json_PARM_8
                                     13 	.globl _parse_json_PARM_7
                                     14 	.globl _parse_json_PARM_6
                                     15 	.globl _parse_json_PARM_5
                                     16 	.globl _parse_json_PARM_4
                                     17 	.globl _parse_json_PARM_3
                                     18 	.globl _parse_json_PARM_2
                                     19 	.globl _parse_json
                                     20 ;--------------------------------------------------------
                                     21 ; special function registers
                                     22 ;--------------------------------------------------------
                                     23 	.area RSEG    (ABS,DATA)
      000000                         24 	.org 0x0000
                                     25 ;--------------------------------------------------------
                                     26 ; special function bits
                                     27 ;--------------------------------------------------------
                                     28 	.area RSEG    (ABS,DATA)
      000000                         29 	.org 0x0000
                                     30 ;--------------------------------------------------------
                                     31 ; overlayable register banks
                                     32 ;--------------------------------------------------------
                                     33 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                         34 	.ds 8
                                     35 ;--------------------------------------------------------
                                     36 ; internal ram data
                                     37 ;--------------------------------------------------------
                                     38 	.area DSEG    (DATA)
      000021                         39 _parse_json_PARM_2:
      000021                         40 	.ds 3
      000024                         41 _parse_json_PARM_3:
      000024                         42 	.ds 3
      000027                         43 _parse_json_PARM_4:
      000027                         44 	.ds 3
      00002A                         45 _parse_json_PARM_5:
      00002A                         46 	.ds 3
      00002D                         47 _parse_json_PARM_6:
      00002D                         48 	.ds 3
      000030                         49 _parse_json_PARM_7:
      000030                         50 	.ds 3
      000033                         51 _parse_json_PARM_8:
      000033                         52 	.ds 3
      000036                         53 _parse_json_PARM_9:
      000036                         54 	.ds 3
      000039                         55 _parse_json_p_10000_3:
      000039                         56 	.ds 3
                                     57 ;--------------------------------------------------------
                                     58 ; overlayable items in internal ram
                                     59 ;--------------------------------------------------------
                                     60 ;--------------------------------------------------------
                                     61 ; indirectly addressable internal ram data
                                     62 ;--------------------------------------------------------
                                     63 	.area ISEG    (DATA)
                                     64 ;--------------------------------------------------------
                                     65 ; absolute internal ram data
                                     66 ;--------------------------------------------------------
                                     67 	.area IABS    (ABS,DATA)
                                     68 	.area IABS    (ABS,DATA)
                                     69 ;--------------------------------------------------------
                                     70 ; bit data
                                     71 ;--------------------------------------------------------
                                     72 	.area BSEG    (BIT)
                                     73 ;--------------------------------------------------------
                                     74 ; paged external ram data
                                     75 ;--------------------------------------------------------
                                     76 	.area PSEG    (PAG,XDATA)
                                     77 ;--------------------------------------------------------
                                     78 ; uninitialized external ram data
                                     79 ;--------------------------------------------------------
                                     80 	.area XSEG    (XDATA)
                                     81 ;--------------------------------------------------------
                                     82 ; absolute external ram data
                                     83 ;--------------------------------------------------------
                                     84 	.area XABS    (ABS,XDATA)
                                     85 ;--------------------------------------------------------
                                     86 ; initialized external ram data
                                     87 ;--------------------------------------------------------
                                     88 	.area XISEG   (XDATA)
                                     89 	.area HOME    (CODE)
                                     90 	.area GSINIT0 (CODE)
                                     91 	.area GSINIT1 (CODE)
                                     92 	.area GSINIT2 (CODE)
                                     93 	.area GSINIT3 (CODE)
                                     94 	.area GSINIT4 (CODE)
                                     95 	.area GSINIT5 (CODE)
                                     96 	.area GSINIT  (CODE)
                                     97 	.area GSFINAL (CODE)
                                     98 	.area CSEG    (CODE)
                                     99 ;--------------------------------------------------------
                                    100 ; global & static initialisations
                                    101 ;--------------------------------------------------------
                                    102 	.area HOME    (CODE)
                                    103 	.area GSINIT  (CODE)
                                    104 	.area GSFINAL (CODE)
                                    105 	.area GSINIT  (CODE)
                                    106 ;--------------------------------------------------------
                                    107 ; Home
                                    108 ;--------------------------------------------------------
                                    109 	.area HOME    (CODE)
                                    110 	.area HOME    (CODE)
                                    111 ;--------------------------------------------------------
                                    112 ; code
                                    113 ;--------------------------------------------------------
                                    114 	.area CSEG    (CODE)
                                    115 ;------------------------------------------------------------
                                    116 ;Allocation info for local variables in function 'parse_json'
                                    117 ;------------------------------------------------------------
                                    118 ;AngleA                    Allocated with name '_parse_json_PARM_2'
                                    119 ;sAngleA                   Allocated with name '_parse_json_PARM_3'
                                    120 ;AngleB                    Allocated with name '_parse_json_PARM_4'
                                    121 ;sAngleB                   Allocated with name '_parse_json_PARM_5'
                                    122 ;MotorA                    Allocated with name '_parse_json_PARM_6'
                                    123 ;sMotorA                   Allocated with name '_parse_json_PARM_7'
                                    124 ;MotorB                    Allocated with name '_parse_json_PARM_8'
                                    125 ;sMotorB                   Allocated with name '_parse_json_PARM_9'
                                    126 ;buf                       Allocated to registers 
                                    127 ;p                         Allocated with name '_parse_json_p_10000_3'
                                    128 ;------------------------------------------------------------
                                    129 ;	src\json.c:3: uint8_t parse_json(const char *buf, int *AngleA, int *sAngleA, int *AngleB, int *sAngleB, int *MotorA, int *sMotorA, int *MotorB, int *sMotorB)
                                    130 ;	-----------------------------------------
                                    131 ;	 function parse_json
                                    132 ;	-----------------------------------------
      000FF8                        133 _parse_json:
                           000007   134 	ar7 = 0x07
                           000006   135 	ar6 = 0x06
                           000005   136 	ar5 = 0x05
                           000004   137 	ar4 = 0x04
                           000003   138 	ar3 = 0x03
                           000002   139 	ar2 = 0x02
                           000001   140 	ar1 = 0x01
                           000000   141 	ar0 = 0x00
      000FF8 AD 82            [24]  142 	mov	r5, dpl
      000FFA AE 83            [24]  143 	mov	r6, dph
      000FFC AF F0            [24]  144 	mov	r7, b
                                    145 ;	src\json.c:8: while (*p && (*p < '0' || *p > '9'))
      000FFE                        146 00103$:
      000FFE 8D 82            [24]  147 	mov	dpl,r5
      001000 8E 83            [24]  148 	mov	dph,r6
      001002 8F F0            [24]  149 	mov	b,r7
      001004 12 16 EE         [24]  150 	lcall	__gptrget
      001007 FC               [12]  151 	mov	r4,a
      001008 60 11            [24]  152 	jz	00105$
      00100A BC 30 00         [24]  153 	cjne	r4,#0x30,00480$
      00100D                        154 00480$:
      00100D 40 05            [24]  155 	jc	00104$
      00100F EC               [12]  156 	mov	a,r4
      001010 24 C6            [12]  157 	add	a,#0xff - 0x39
      001012 50 07            [24]  158 	jnc	00105$
      001014                        159 00104$:
                                    160 ;	src\json.c:9: p++;
      001014 0D               [12]  161 	inc	r5
      001015 BD 00 E6         [24]  162 	cjne	r5,#0x00,00103$
      001018 0E               [12]  163 	inc	r6
      001019 80 E3            [24]  164 	sjmp	00103$
      00101B                        165 00105$:
                                    166 ;	src\json.c:10: *AngleA = 0;
      00101B AA 21            [24]  167 	mov	r2,_parse_json_PARM_2
      00101D AB 22            [24]  168 	mov	r3,(_parse_json_PARM_2 + 1)
      00101F AC 23            [24]  169 	mov	r4,(_parse_json_PARM_2 + 2)
      001021 8A 82            [24]  170 	mov	dpl,r2
      001023 8B 83            [24]  171 	mov	dph,r3
      001025 8C F0            [24]  172 	mov	b,r4
      001027 E4               [12]  173 	clr	a
      001028 12 16 48         [24]  174 	lcall	__gptrput
      00102B A3               [24]  175 	inc	dptr
      00102C 12 16 48         [24]  176 	lcall	__gptrput
                                    177 ;	src\json.c:11: while (*p >= '0' && *p <= '9')
      00102F 8D 39            [24]  178 	mov	_parse_json_p_10000_3,r5
      001031 8E 3A            [24]  179 	mov	(_parse_json_p_10000_3 + 1),r6
      001033 8F 3B            [24]  180 	mov	(_parse_json_p_10000_3 + 2),r7
      001035                        181 00107$:
      001035 85 39 82         [24]  182 	mov	dpl,_parse_json_p_10000_3
      001038 85 3A 83         [24]  183 	mov	dph,(_parse_json_p_10000_3 + 1)
      00103B 85 3B F0         [24]  184 	mov	b,(_parse_json_p_10000_3 + 2)
      00103E 12 16 EE         [24]  185 	lcall	__gptrget
      001041 F9               [12]  186 	mov	r1,a
      001042 B9 30 00         [24]  187 	cjne	r1,#0x30,00484$
      001045                        188 00484$:
      001045 40 59            [24]  189 	jc	00183$
      001047 E9               [12]  190 	mov	a,r1
      001048 24 C6            [12]  191 	add	a,#0xff - 0x39
      00104A 40 54            [24]  192 	jc	00183$
                                    193 ;	src\json.c:13: *AngleA = *AngleA * 10 + (*p - '0');
      00104C 8A 82            [24]  194 	mov	dpl,r2
      00104E 8B 83            [24]  195 	mov	dph,r3
      001050 8C F0            [24]  196 	mov	b,r4
      001052 12 16 EE         [24]  197 	lcall	__gptrget
      001055 F5 44            [12]  198 	mov	__mulint_PARM_2,a
      001057 A3               [24]  199 	inc	dptr
      001058 12 16 EE         [24]  200 	lcall	__gptrget
      00105B F5 45            [12]  201 	mov	(__mulint_PARM_2 + 1),a
      00105D 90 00 0A         [24]  202 	mov	dptr,#0x000a
      001060 C0 04            [24]  203 	push	ar4
      001062 C0 03            [24]  204 	push	ar3
      001064 C0 02            [24]  205 	push	ar2
      001066 C0 01            [24]  206 	push	ar1
      001068 12 16 63         [24]  207 	lcall	__mulint
      00106B A8 82            [24]  208 	mov	r0, dpl
      00106D AF 83            [24]  209 	mov	r7, dph
      00106F D0 01            [24]  210 	pop	ar1
      001071 D0 02            [24]  211 	pop	ar2
      001073 D0 03            [24]  212 	pop	ar3
      001075 D0 04            [24]  213 	pop	ar4
      001077 7E 00            [12]  214 	mov	r6,#0x00
      001079 E9               [12]  215 	mov	a,r1
      00107A 24 D0            [12]  216 	add	a,#0xd0
      00107C F9               [12]  217 	mov	r1,a
      00107D EE               [12]  218 	mov	a,r6
      00107E 34 FF            [12]  219 	addc	a,#0xff
      001080 FE               [12]  220 	mov	r6,a
      001081 E9               [12]  221 	mov	a,r1
      001082 28               [12]  222 	add	a, r0
      001083 F8               [12]  223 	mov	r0,a
      001084 EE               [12]  224 	mov	a,r6
      001085 3F               [12]  225 	addc	a, r7
      001086 FF               [12]  226 	mov	r7,a
      001087 8A 82            [24]  227 	mov	dpl,r2
      001089 8B 83            [24]  228 	mov	dph,r3
      00108B 8C F0            [24]  229 	mov	b,r4
      00108D E8               [12]  230 	mov	a,r0
      00108E 12 16 48         [24]  231 	lcall	__gptrput
      001091 A3               [24]  232 	inc	dptr
      001092 EF               [12]  233 	mov	a,r7
      001093 12 16 48         [24]  234 	lcall	__gptrput
                                    235 ;	src\json.c:14: p++;
      001096 05 39            [12]  236 	inc	_parse_json_p_10000_3
      001098 E4               [12]  237 	clr	a
                                    238 ;	src\json.c:16: while (*p && (*p < '0' || *p > '9'))
      001099 B5 39 99         [24]  239 	cjne	a,_parse_json_p_10000_3,00107$
      00109C 05 3A            [12]  240 	inc	(_parse_json_p_10000_3 + 1)
      00109E 80 95            [24]  241 	sjmp	00107$
      0010A0                        242 00183$:
      0010A0 AD 39            [24]  243 	mov	r5,_parse_json_p_10000_3
      0010A2 AE 3A            [24]  244 	mov	r6,(_parse_json_p_10000_3 + 1)
      0010A4 AF 3B            [24]  245 	mov	r7,(_parse_json_p_10000_3 + 2)
      0010A6                        246 00112$:
      0010A6 8D 82            [24]  247 	mov	dpl,r5
      0010A8 8E 83            [24]  248 	mov	dph,r6
      0010AA 8F F0            [24]  249 	mov	b,r7
      0010AC 12 16 EE         [24]  250 	lcall	__gptrget
      0010AF FC               [12]  251 	mov	r4,a
      0010B0 60 11            [24]  252 	jz	00114$
      0010B2 BC 30 00         [24]  253 	cjne	r4,#0x30,00489$
      0010B5                        254 00489$:
      0010B5 40 05            [24]  255 	jc	00113$
      0010B7 EC               [12]  256 	mov	a,r4
      0010B8 24 C6            [12]  257 	add	a,#0xff - 0x39
      0010BA 50 07            [24]  258 	jnc	00114$
      0010BC                        259 00113$:
                                    260 ;	src\json.c:17: p++;
      0010BC 0D               [12]  261 	inc	r5
      0010BD BD 00 E6         [24]  262 	cjne	r5,#0x00,00112$
      0010C0 0E               [12]  263 	inc	r6
      0010C1 80 E3            [24]  264 	sjmp	00112$
      0010C3                        265 00114$:
                                    266 ;	src\json.c:18: *sAngleA = 0;
      0010C3 AA 24            [24]  267 	mov	r2,_parse_json_PARM_3
      0010C5 AB 25            [24]  268 	mov	r3,(_parse_json_PARM_3 + 1)
      0010C7 AC 26            [24]  269 	mov	r4,(_parse_json_PARM_3 + 2)
      0010C9 8A 82            [24]  270 	mov	dpl,r2
      0010CB 8B 83            [24]  271 	mov	dph,r3
      0010CD 8C F0            [24]  272 	mov	b,r4
      0010CF E4               [12]  273 	clr	a
      0010D0 12 16 48         [24]  274 	lcall	__gptrput
      0010D3 A3               [24]  275 	inc	dptr
      0010D4 12 16 48         [24]  276 	lcall	__gptrput
                                    277 ;	src\json.c:19: while (*p >= '0' && *p <= '9')
      0010D7 8D 39            [24]  278 	mov	_parse_json_p_10000_3,r5
      0010D9 8E 3A            [24]  279 	mov	(_parse_json_p_10000_3 + 1),r6
      0010DB 8F 3B            [24]  280 	mov	(_parse_json_p_10000_3 + 2),r7
      0010DD                        281 00116$:
      0010DD 85 39 82         [24]  282 	mov	dpl,_parse_json_p_10000_3
      0010E0 85 3A 83         [24]  283 	mov	dph,(_parse_json_p_10000_3 + 1)
      0010E3 85 3B F0         [24]  284 	mov	b,(_parse_json_p_10000_3 + 2)
      0010E6 12 16 EE         [24]  285 	lcall	__gptrget
      0010E9 F9               [12]  286 	mov	r1,a
      0010EA B9 30 00         [24]  287 	cjne	r1,#0x30,00493$
      0010ED                        288 00493$:
      0010ED 40 59            [24]  289 	jc	00189$
      0010EF E9               [12]  290 	mov	a,r1
      0010F0 24 C6            [12]  291 	add	a,#0xff - 0x39
      0010F2 40 54            [24]  292 	jc	00189$
                                    293 ;	src\json.c:21: *sAngleA = *sAngleA * 10 + (*p - '0');
      0010F4 8A 82            [24]  294 	mov	dpl,r2
      0010F6 8B 83            [24]  295 	mov	dph,r3
      0010F8 8C F0            [24]  296 	mov	b,r4
      0010FA 12 16 EE         [24]  297 	lcall	__gptrget
      0010FD F5 44            [12]  298 	mov	__mulint_PARM_2,a
      0010FF A3               [24]  299 	inc	dptr
      001100 12 16 EE         [24]  300 	lcall	__gptrget
      001103 F5 45            [12]  301 	mov	(__mulint_PARM_2 + 1),a
      001105 90 00 0A         [24]  302 	mov	dptr,#0x000a
      001108 C0 04            [24]  303 	push	ar4
      00110A C0 03            [24]  304 	push	ar3
      00110C C0 02            [24]  305 	push	ar2
      00110E C0 01            [24]  306 	push	ar1
      001110 12 16 63         [24]  307 	lcall	__mulint
      001113 A8 82            [24]  308 	mov	r0, dpl
      001115 AF 83            [24]  309 	mov	r7, dph
      001117 D0 01            [24]  310 	pop	ar1
      001119 D0 02            [24]  311 	pop	ar2
      00111B D0 03            [24]  312 	pop	ar3
      00111D D0 04            [24]  313 	pop	ar4
      00111F 7E 00            [12]  314 	mov	r6,#0x00
      001121 E9               [12]  315 	mov	a,r1
      001122 24 D0            [12]  316 	add	a,#0xd0
      001124 F9               [12]  317 	mov	r1,a
      001125 EE               [12]  318 	mov	a,r6
      001126 34 FF            [12]  319 	addc	a,#0xff
      001128 FE               [12]  320 	mov	r6,a
      001129 E9               [12]  321 	mov	a,r1
      00112A 28               [12]  322 	add	a, r0
      00112B F8               [12]  323 	mov	r0,a
      00112C EE               [12]  324 	mov	a,r6
      00112D 3F               [12]  325 	addc	a, r7
      00112E FF               [12]  326 	mov	r7,a
      00112F 8A 82            [24]  327 	mov	dpl,r2
      001131 8B 83            [24]  328 	mov	dph,r3
      001133 8C F0            [24]  329 	mov	b,r4
      001135 E8               [12]  330 	mov	a,r0
      001136 12 16 48         [24]  331 	lcall	__gptrput
      001139 A3               [24]  332 	inc	dptr
      00113A EF               [12]  333 	mov	a,r7
      00113B 12 16 48         [24]  334 	lcall	__gptrput
                                    335 ;	src\json.c:22: p++;
      00113E 05 39            [12]  336 	inc	_parse_json_p_10000_3
      001140 E4               [12]  337 	clr	a
                                    338 ;	src\json.c:25: while (*p && (*p < '0' || *p > '9'))
      001141 B5 39 99         [24]  339 	cjne	a,_parse_json_p_10000_3,00116$
      001144 05 3A            [12]  340 	inc	(_parse_json_p_10000_3 + 1)
      001146 80 95            [24]  341 	sjmp	00116$
      001148                        342 00189$:
      001148 AD 39            [24]  343 	mov	r5,_parse_json_p_10000_3
      00114A AE 3A            [24]  344 	mov	r6,(_parse_json_p_10000_3 + 1)
      00114C AF 3B            [24]  345 	mov	r7,(_parse_json_p_10000_3 + 2)
      00114E                        346 00121$:
      00114E 8D 82            [24]  347 	mov	dpl,r5
      001150 8E 83            [24]  348 	mov	dph,r6
      001152 8F F0            [24]  349 	mov	b,r7
      001154 12 16 EE         [24]  350 	lcall	__gptrget
      001157 FC               [12]  351 	mov	r4,a
      001158 60 11            [24]  352 	jz	00123$
      00115A BC 30 00         [24]  353 	cjne	r4,#0x30,00498$
      00115D                        354 00498$:
      00115D 40 05            [24]  355 	jc	00122$
      00115F EC               [12]  356 	mov	a,r4
      001160 24 C6            [12]  357 	add	a,#0xff - 0x39
      001162 50 07            [24]  358 	jnc	00123$
      001164                        359 00122$:
                                    360 ;	src\json.c:26: p++;
      001164 0D               [12]  361 	inc	r5
      001165 BD 00 E6         [24]  362 	cjne	r5,#0x00,00121$
      001168 0E               [12]  363 	inc	r6
      001169 80 E3            [24]  364 	sjmp	00121$
      00116B                        365 00123$:
                                    366 ;	src\json.c:27: *AngleB = 0;
      00116B AA 27            [24]  367 	mov	r2,_parse_json_PARM_4
      00116D AB 28            [24]  368 	mov	r3,(_parse_json_PARM_4 + 1)
      00116F AC 29            [24]  369 	mov	r4,(_parse_json_PARM_4 + 2)
      001171 8A 82            [24]  370 	mov	dpl,r2
      001173 8B 83            [24]  371 	mov	dph,r3
      001175 8C F0            [24]  372 	mov	b,r4
      001177 E4               [12]  373 	clr	a
      001178 12 16 48         [24]  374 	lcall	__gptrput
      00117B A3               [24]  375 	inc	dptr
      00117C 12 16 48         [24]  376 	lcall	__gptrput
                                    377 ;	src\json.c:28: while (*p >= '0' && *p <= '9')
      00117F 8D 39            [24]  378 	mov	_parse_json_p_10000_3,r5
      001181 8E 3A            [24]  379 	mov	(_parse_json_p_10000_3 + 1),r6
      001183 8F 3B            [24]  380 	mov	(_parse_json_p_10000_3 + 2),r7
      001185                        381 00125$:
      001185 85 39 82         [24]  382 	mov	dpl,_parse_json_p_10000_3
      001188 85 3A 83         [24]  383 	mov	dph,(_parse_json_p_10000_3 + 1)
      00118B 85 3B F0         [24]  384 	mov	b,(_parse_json_p_10000_3 + 2)
      00118E 12 16 EE         [24]  385 	lcall	__gptrget
      001191 F9               [12]  386 	mov	r1,a
      001192 B9 30 00         [24]  387 	cjne	r1,#0x30,00502$
      001195                        388 00502$:
      001195 40 59            [24]  389 	jc	00195$
      001197 E9               [12]  390 	mov	a,r1
      001198 24 C6            [12]  391 	add	a,#0xff - 0x39
      00119A 40 54            [24]  392 	jc	00195$
                                    393 ;	src\json.c:30: *AngleB = *AngleB * 10 + (*p - '0');
      00119C 8A 82            [24]  394 	mov	dpl,r2
      00119E 8B 83            [24]  395 	mov	dph,r3
      0011A0 8C F0            [24]  396 	mov	b,r4
      0011A2 12 16 EE         [24]  397 	lcall	__gptrget
      0011A5 F5 44            [12]  398 	mov	__mulint_PARM_2,a
      0011A7 A3               [24]  399 	inc	dptr
      0011A8 12 16 EE         [24]  400 	lcall	__gptrget
      0011AB F5 45            [12]  401 	mov	(__mulint_PARM_2 + 1),a
      0011AD 90 00 0A         [24]  402 	mov	dptr,#0x000a
      0011B0 C0 04            [24]  403 	push	ar4
      0011B2 C0 03            [24]  404 	push	ar3
      0011B4 C0 02            [24]  405 	push	ar2
      0011B6 C0 01            [24]  406 	push	ar1
      0011B8 12 16 63         [24]  407 	lcall	__mulint
      0011BB A8 82            [24]  408 	mov	r0, dpl
      0011BD AF 83            [24]  409 	mov	r7, dph
      0011BF D0 01            [24]  410 	pop	ar1
      0011C1 D0 02            [24]  411 	pop	ar2
      0011C3 D0 03            [24]  412 	pop	ar3
      0011C5 D0 04            [24]  413 	pop	ar4
      0011C7 7E 00            [12]  414 	mov	r6,#0x00
      0011C9 E9               [12]  415 	mov	a,r1
      0011CA 24 D0            [12]  416 	add	a,#0xd0
      0011CC F9               [12]  417 	mov	r1,a
      0011CD EE               [12]  418 	mov	a,r6
      0011CE 34 FF            [12]  419 	addc	a,#0xff
      0011D0 FE               [12]  420 	mov	r6,a
      0011D1 E9               [12]  421 	mov	a,r1
      0011D2 28               [12]  422 	add	a, r0
      0011D3 F8               [12]  423 	mov	r0,a
      0011D4 EE               [12]  424 	mov	a,r6
      0011D5 3F               [12]  425 	addc	a, r7
      0011D6 FF               [12]  426 	mov	r7,a
      0011D7 8A 82            [24]  427 	mov	dpl,r2
      0011D9 8B 83            [24]  428 	mov	dph,r3
      0011DB 8C F0            [24]  429 	mov	b,r4
      0011DD E8               [12]  430 	mov	a,r0
      0011DE 12 16 48         [24]  431 	lcall	__gptrput
      0011E1 A3               [24]  432 	inc	dptr
      0011E2 EF               [12]  433 	mov	a,r7
      0011E3 12 16 48         [24]  434 	lcall	__gptrput
                                    435 ;	src\json.c:31: p++;
      0011E6 05 39            [12]  436 	inc	_parse_json_p_10000_3
      0011E8 E4               [12]  437 	clr	a
                                    438 ;	src\json.c:33: while (*p && (*p < '0' || *p > '9'))
      0011E9 B5 39 99         [24]  439 	cjne	a,_parse_json_p_10000_3,00125$
      0011EC 05 3A            [12]  440 	inc	(_parse_json_p_10000_3 + 1)
      0011EE 80 95            [24]  441 	sjmp	00125$
      0011F0                        442 00195$:
      0011F0 AD 39            [24]  443 	mov	r5,_parse_json_p_10000_3
      0011F2 AE 3A            [24]  444 	mov	r6,(_parse_json_p_10000_3 + 1)
      0011F4 AF 3B            [24]  445 	mov	r7,(_parse_json_p_10000_3 + 2)
      0011F6                        446 00130$:
      0011F6 8D 82            [24]  447 	mov	dpl,r5
      0011F8 8E 83            [24]  448 	mov	dph,r6
      0011FA 8F F0            [24]  449 	mov	b,r7
      0011FC 12 16 EE         [24]  450 	lcall	__gptrget
      0011FF FC               [12]  451 	mov	r4,a
      001200 60 11            [24]  452 	jz	00132$
      001202 BC 30 00         [24]  453 	cjne	r4,#0x30,00507$
      001205                        454 00507$:
      001205 40 05            [24]  455 	jc	00131$
      001207 EC               [12]  456 	mov	a,r4
      001208 24 C6            [12]  457 	add	a,#0xff - 0x39
      00120A 50 07            [24]  458 	jnc	00132$
      00120C                        459 00131$:
                                    460 ;	src\json.c:34: p++;
      00120C 0D               [12]  461 	inc	r5
      00120D BD 00 E6         [24]  462 	cjne	r5,#0x00,00130$
      001210 0E               [12]  463 	inc	r6
      001211 80 E3            [24]  464 	sjmp	00130$
      001213                        465 00132$:
                                    466 ;	src\json.c:35: *sAngleB = 0;
      001213 AA 2A            [24]  467 	mov	r2,_parse_json_PARM_5
      001215 AB 2B            [24]  468 	mov	r3,(_parse_json_PARM_5 + 1)
      001217 AC 2C            [24]  469 	mov	r4,(_parse_json_PARM_5 + 2)
      001219 8A 82            [24]  470 	mov	dpl,r2
      00121B 8B 83            [24]  471 	mov	dph,r3
      00121D 8C F0            [24]  472 	mov	b,r4
      00121F E4               [12]  473 	clr	a
      001220 12 16 48         [24]  474 	lcall	__gptrput
      001223 A3               [24]  475 	inc	dptr
      001224 12 16 48         [24]  476 	lcall	__gptrput
                                    477 ;	src\json.c:36: while (*p >= '0' && *p <= '9')
      001227 8D 39            [24]  478 	mov	_parse_json_p_10000_3,r5
      001229 8E 3A            [24]  479 	mov	(_parse_json_p_10000_3 + 1),r6
      00122B 8F 3B            [24]  480 	mov	(_parse_json_p_10000_3 + 2),r7
      00122D                        481 00134$:
      00122D 85 39 82         [24]  482 	mov	dpl,_parse_json_p_10000_3
      001230 85 3A 83         [24]  483 	mov	dph,(_parse_json_p_10000_3 + 1)
      001233 85 3B F0         [24]  484 	mov	b,(_parse_json_p_10000_3 + 2)
      001236 12 16 EE         [24]  485 	lcall	__gptrget
      001239 F9               [12]  486 	mov	r1,a
      00123A B9 30 00         [24]  487 	cjne	r1,#0x30,00511$
      00123D                        488 00511$:
      00123D 40 59            [24]  489 	jc	00201$
      00123F E9               [12]  490 	mov	a,r1
      001240 24 C6            [12]  491 	add	a,#0xff - 0x39
      001242 40 54            [24]  492 	jc	00201$
                                    493 ;	src\json.c:38: *sAngleB = *sAngleB * 10 + (*p - '0');
      001244 8A 82            [24]  494 	mov	dpl,r2
      001246 8B 83            [24]  495 	mov	dph,r3
      001248 8C F0            [24]  496 	mov	b,r4
      00124A 12 16 EE         [24]  497 	lcall	__gptrget
      00124D F5 44            [12]  498 	mov	__mulint_PARM_2,a
      00124F A3               [24]  499 	inc	dptr
      001250 12 16 EE         [24]  500 	lcall	__gptrget
      001253 F5 45            [12]  501 	mov	(__mulint_PARM_2 + 1),a
      001255 90 00 0A         [24]  502 	mov	dptr,#0x000a
      001258 C0 04            [24]  503 	push	ar4
      00125A C0 03            [24]  504 	push	ar3
      00125C C0 02            [24]  505 	push	ar2
      00125E C0 01            [24]  506 	push	ar1
      001260 12 16 63         [24]  507 	lcall	__mulint
      001263 A8 82            [24]  508 	mov	r0, dpl
      001265 AF 83            [24]  509 	mov	r7, dph
      001267 D0 01            [24]  510 	pop	ar1
      001269 D0 02            [24]  511 	pop	ar2
      00126B D0 03            [24]  512 	pop	ar3
      00126D D0 04            [24]  513 	pop	ar4
      00126F 7E 00            [12]  514 	mov	r6,#0x00
      001271 E9               [12]  515 	mov	a,r1
      001272 24 D0            [12]  516 	add	a,#0xd0
      001274 F9               [12]  517 	mov	r1,a
      001275 EE               [12]  518 	mov	a,r6
      001276 34 FF            [12]  519 	addc	a,#0xff
      001278 FE               [12]  520 	mov	r6,a
      001279 E9               [12]  521 	mov	a,r1
      00127A 28               [12]  522 	add	a, r0
      00127B F8               [12]  523 	mov	r0,a
      00127C EE               [12]  524 	mov	a,r6
      00127D 3F               [12]  525 	addc	a, r7
      00127E FF               [12]  526 	mov	r7,a
      00127F 8A 82            [24]  527 	mov	dpl,r2
      001281 8B 83            [24]  528 	mov	dph,r3
      001283 8C F0            [24]  529 	mov	b,r4
      001285 E8               [12]  530 	mov	a,r0
      001286 12 16 48         [24]  531 	lcall	__gptrput
      001289 A3               [24]  532 	inc	dptr
      00128A EF               [12]  533 	mov	a,r7
      00128B 12 16 48         [24]  534 	lcall	__gptrput
                                    535 ;	src\json.c:39: p++;
      00128E 05 39            [12]  536 	inc	_parse_json_p_10000_3
      001290 E4               [12]  537 	clr	a
                                    538 ;	src\json.c:42: while (*p && (*p < '0' || *p > '9'))
      001291 B5 39 99         [24]  539 	cjne	a,_parse_json_p_10000_3,00134$
      001294 05 3A            [12]  540 	inc	(_parse_json_p_10000_3 + 1)
      001296 80 95            [24]  541 	sjmp	00134$
      001298                        542 00201$:
      001298 AD 39            [24]  543 	mov	r5,_parse_json_p_10000_3
      00129A AE 3A            [24]  544 	mov	r6,(_parse_json_p_10000_3 + 1)
      00129C AF 3B            [24]  545 	mov	r7,(_parse_json_p_10000_3 + 2)
      00129E                        546 00139$:
      00129E 8D 82            [24]  547 	mov	dpl,r5
      0012A0 8E 83            [24]  548 	mov	dph,r6
      0012A2 8F F0            [24]  549 	mov	b,r7
      0012A4 12 16 EE         [24]  550 	lcall	__gptrget
      0012A7 FC               [12]  551 	mov	r4,a
      0012A8 60 11            [24]  552 	jz	00141$
      0012AA BC 30 00         [24]  553 	cjne	r4,#0x30,00516$
      0012AD                        554 00516$:
      0012AD 40 05            [24]  555 	jc	00140$
      0012AF EC               [12]  556 	mov	a,r4
      0012B0 24 C6            [12]  557 	add	a,#0xff - 0x39
      0012B2 50 07            [24]  558 	jnc	00141$
      0012B4                        559 00140$:
                                    560 ;	src\json.c:43: p++;
      0012B4 0D               [12]  561 	inc	r5
      0012B5 BD 00 E6         [24]  562 	cjne	r5,#0x00,00139$
      0012B8 0E               [12]  563 	inc	r6
      0012B9 80 E3            [24]  564 	sjmp	00139$
      0012BB                        565 00141$:
                                    566 ;	src\json.c:44: *MotorA = 0;
      0012BB AA 2D            [24]  567 	mov	r2,_parse_json_PARM_6
      0012BD AB 2E            [24]  568 	mov	r3,(_parse_json_PARM_6 + 1)
      0012BF AC 2F            [24]  569 	mov	r4,(_parse_json_PARM_6 + 2)
      0012C1 8A 82            [24]  570 	mov	dpl,r2
      0012C3 8B 83            [24]  571 	mov	dph,r3
      0012C5 8C F0            [24]  572 	mov	b,r4
      0012C7 E4               [12]  573 	clr	a
      0012C8 12 16 48         [24]  574 	lcall	__gptrput
      0012CB A3               [24]  575 	inc	dptr
      0012CC 12 16 48         [24]  576 	lcall	__gptrput
                                    577 ;	src\json.c:45: while (*p >= '0' && *p <= '9')
      0012CF 8D 39            [24]  578 	mov	_parse_json_p_10000_3,r5
      0012D1 8E 3A            [24]  579 	mov	(_parse_json_p_10000_3 + 1),r6
      0012D3 8F 3B            [24]  580 	mov	(_parse_json_p_10000_3 + 2),r7
      0012D5                        581 00143$:
      0012D5 85 39 82         [24]  582 	mov	dpl,_parse_json_p_10000_3
      0012D8 85 3A 83         [24]  583 	mov	dph,(_parse_json_p_10000_3 + 1)
      0012DB 85 3B F0         [24]  584 	mov	b,(_parse_json_p_10000_3 + 2)
      0012DE 12 16 EE         [24]  585 	lcall	__gptrget
      0012E1 F9               [12]  586 	mov	r1,a
      0012E2 B9 30 00         [24]  587 	cjne	r1,#0x30,00520$
      0012E5                        588 00520$:
      0012E5 40 59            [24]  589 	jc	00207$
      0012E7 E9               [12]  590 	mov	a,r1
      0012E8 24 C6            [12]  591 	add	a,#0xff - 0x39
      0012EA 40 54            [24]  592 	jc	00207$
                                    593 ;	src\json.c:47: *MotorA = *MotorA * 10 + (*p - '0');
      0012EC 8A 82            [24]  594 	mov	dpl,r2
      0012EE 8B 83            [24]  595 	mov	dph,r3
      0012F0 8C F0            [24]  596 	mov	b,r4
      0012F2 12 16 EE         [24]  597 	lcall	__gptrget
      0012F5 F5 44            [12]  598 	mov	__mulint_PARM_2,a
      0012F7 A3               [24]  599 	inc	dptr
      0012F8 12 16 EE         [24]  600 	lcall	__gptrget
      0012FB F5 45            [12]  601 	mov	(__mulint_PARM_2 + 1),a
      0012FD 90 00 0A         [24]  602 	mov	dptr,#0x000a
      001300 C0 04            [24]  603 	push	ar4
      001302 C0 03            [24]  604 	push	ar3
      001304 C0 02            [24]  605 	push	ar2
      001306 C0 01            [24]  606 	push	ar1
      001308 12 16 63         [24]  607 	lcall	__mulint
      00130B A8 82            [24]  608 	mov	r0, dpl
      00130D AF 83            [24]  609 	mov	r7, dph
      00130F D0 01            [24]  610 	pop	ar1
      001311 D0 02            [24]  611 	pop	ar2
      001313 D0 03            [24]  612 	pop	ar3
      001315 D0 04            [24]  613 	pop	ar4
      001317 7E 00            [12]  614 	mov	r6,#0x00
      001319 E9               [12]  615 	mov	a,r1
      00131A 24 D0            [12]  616 	add	a,#0xd0
      00131C F9               [12]  617 	mov	r1,a
      00131D EE               [12]  618 	mov	a,r6
      00131E 34 FF            [12]  619 	addc	a,#0xff
      001320 FE               [12]  620 	mov	r6,a
      001321 E9               [12]  621 	mov	a,r1
      001322 28               [12]  622 	add	a, r0
      001323 F8               [12]  623 	mov	r0,a
      001324 EE               [12]  624 	mov	a,r6
      001325 3F               [12]  625 	addc	a, r7
      001326 FF               [12]  626 	mov	r7,a
      001327 8A 82            [24]  627 	mov	dpl,r2
      001329 8B 83            [24]  628 	mov	dph,r3
      00132B 8C F0            [24]  629 	mov	b,r4
      00132D E8               [12]  630 	mov	a,r0
      00132E 12 16 48         [24]  631 	lcall	__gptrput
      001331 A3               [24]  632 	inc	dptr
      001332 EF               [12]  633 	mov	a,r7
      001333 12 16 48         [24]  634 	lcall	__gptrput
                                    635 ;	src\json.c:48: p++;
      001336 05 39            [12]  636 	inc	_parse_json_p_10000_3
      001338 E4               [12]  637 	clr	a
                                    638 ;	src\json.c:50: while (*p && (*p < '0' || *p > '9'))
      001339 B5 39 99         [24]  639 	cjne	a,_parse_json_p_10000_3,00143$
      00133C 05 3A            [12]  640 	inc	(_parse_json_p_10000_3 + 1)
      00133E 80 95            [24]  641 	sjmp	00143$
      001340                        642 00207$:
      001340 AD 39            [24]  643 	mov	r5,_parse_json_p_10000_3
      001342 AE 3A            [24]  644 	mov	r6,(_parse_json_p_10000_3 + 1)
      001344 AF 3B            [24]  645 	mov	r7,(_parse_json_p_10000_3 + 2)
      001346                        646 00148$:
      001346 8D 82            [24]  647 	mov	dpl,r5
      001348 8E 83            [24]  648 	mov	dph,r6
      00134A 8F F0            [24]  649 	mov	b,r7
      00134C 12 16 EE         [24]  650 	lcall	__gptrget
      00134F FC               [12]  651 	mov	r4,a
      001350 60 11            [24]  652 	jz	00150$
      001352 BC 30 00         [24]  653 	cjne	r4,#0x30,00525$
      001355                        654 00525$:
      001355 40 05            [24]  655 	jc	00149$
      001357 EC               [12]  656 	mov	a,r4
      001358 24 C6            [12]  657 	add	a,#0xff - 0x39
      00135A 50 07            [24]  658 	jnc	00150$
      00135C                        659 00149$:
                                    660 ;	src\json.c:51: p++;
      00135C 0D               [12]  661 	inc	r5
      00135D BD 00 E6         [24]  662 	cjne	r5,#0x00,00148$
      001360 0E               [12]  663 	inc	r6
      001361 80 E3            [24]  664 	sjmp	00148$
      001363                        665 00150$:
                                    666 ;	src\json.c:52: *sMotorA = 0;
      001363 AA 30            [24]  667 	mov	r2,_parse_json_PARM_7
      001365 AB 31            [24]  668 	mov	r3,(_parse_json_PARM_7 + 1)
      001367 AC 32            [24]  669 	mov	r4,(_parse_json_PARM_7 + 2)
      001369 8A 82            [24]  670 	mov	dpl,r2
      00136B 8B 83            [24]  671 	mov	dph,r3
      00136D 8C F0            [24]  672 	mov	b,r4
      00136F E4               [12]  673 	clr	a
      001370 12 16 48         [24]  674 	lcall	__gptrput
      001373 A3               [24]  675 	inc	dptr
      001374 12 16 48         [24]  676 	lcall	__gptrput
                                    677 ;	src\json.c:53: while (*p >= '0' && *p <= '9')
      001377 8D 39            [24]  678 	mov	_parse_json_p_10000_3,r5
      001379 8E 3A            [24]  679 	mov	(_parse_json_p_10000_3 + 1),r6
      00137B 8F 3B            [24]  680 	mov	(_parse_json_p_10000_3 + 2),r7
      00137D                        681 00152$:
      00137D 85 39 82         [24]  682 	mov	dpl,_parse_json_p_10000_3
      001380 85 3A 83         [24]  683 	mov	dph,(_parse_json_p_10000_3 + 1)
      001383 85 3B F0         [24]  684 	mov	b,(_parse_json_p_10000_3 + 2)
      001386 12 16 EE         [24]  685 	lcall	__gptrget
      001389 F9               [12]  686 	mov	r1,a
      00138A B9 30 00         [24]  687 	cjne	r1,#0x30,00529$
      00138D                        688 00529$:
      00138D 40 59            [24]  689 	jc	00213$
      00138F E9               [12]  690 	mov	a,r1
      001390 24 C6            [12]  691 	add	a,#0xff - 0x39
      001392 40 54            [24]  692 	jc	00213$
                                    693 ;	src\json.c:55: *sMotorA = *sMotorA * 10 + (*p - '0');
      001394 8A 82            [24]  694 	mov	dpl,r2
      001396 8B 83            [24]  695 	mov	dph,r3
      001398 8C F0            [24]  696 	mov	b,r4
      00139A 12 16 EE         [24]  697 	lcall	__gptrget
      00139D F5 44            [12]  698 	mov	__mulint_PARM_2,a
      00139F A3               [24]  699 	inc	dptr
      0013A0 12 16 EE         [24]  700 	lcall	__gptrget
      0013A3 F5 45            [12]  701 	mov	(__mulint_PARM_2 + 1),a
      0013A5 90 00 0A         [24]  702 	mov	dptr,#0x000a
      0013A8 C0 04            [24]  703 	push	ar4
      0013AA C0 03            [24]  704 	push	ar3
      0013AC C0 02            [24]  705 	push	ar2
      0013AE C0 01            [24]  706 	push	ar1
      0013B0 12 16 63         [24]  707 	lcall	__mulint
      0013B3 A8 82            [24]  708 	mov	r0, dpl
      0013B5 AF 83            [24]  709 	mov	r7, dph
      0013B7 D0 01            [24]  710 	pop	ar1
      0013B9 D0 02            [24]  711 	pop	ar2
      0013BB D0 03            [24]  712 	pop	ar3
      0013BD D0 04            [24]  713 	pop	ar4
      0013BF 7E 00            [12]  714 	mov	r6,#0x00
      0013C1 E9               [12]  715 	mov	a,r1
      0013C2 24 D0            [12]  716 	add	a,#0xd0
      0013C4 F9               [12]  717 	mov	r1,a
      0013C5 EE               [12]  718 	mov	a,r6
      0013C6 34 FF            [12]  719 	addc	a,#0xff
      0013C8 FE               [12]  720 	mov	r6,a
      0013C9 E9               [12]  721 	mov	a,r1
      0013CA 28               [12]  722 	add	a, r0
      0013CB F8               [12]  723 	mov	r0,a
      0013CC EE               [12]  724 	mov	a,r6
      0013CD 3F               [12]  725 	addc	a, r7
      0013CE FF               [12]  726 	mov	r7,a
      0013CF 8A 82            [24]  727 	mov	dpl,r2
      0013D1 8B 83            [24]  728 	mov	dph,r3
      0013D3 8C F0            [24]  729 	mov	b,r4
      0013D5 E8               [12]  730 	mov	a,r0
      0013D6 12 16 48         [24]  731 	lcall	__gptrput
      0013D9 A3               [24]  732 	inc	dptr
      0013DA EF               [12]  733 	mov	a,r7
      0013DB 12 16 48         [24]  734 	lcall	__gptrput
                                    735 ;	src\json.c:56: p++;
      0013DE 05 39            [12]  736 	inc	_parse_json_p_10000_3
      0013E0 E4               [12]  737 	clr	a
                                    738 ;	src\json.c:59: while (*p && (*p < '0' || *p > '9'))
      0013E1 B5 39 99         [24]  739 	cjne	a,_parse_json_p_10000_3,00152$
      0013E4 05 3A            [12]  740 	inc	(_parse_json_p_10000_3 + 1)
      0013E6 80 95            [24]  741 	sjmp	00152$
      0013E8                        742 00213$:
      0013E8 AD 39            [24]  743 	mov	r5,_parse_json_p_10000_3
      0013EA AE 3A            [24]  744 	mov	r6,(_parse_json_p_10000_3 + 1)
      0013EC AF 3B            [24]  745 	mov	r7,(_parse_json_p_10000_3 + 2)
      0013EE                        746 00157$:
      0013EE 8D 82            [24]  747 	mov	dpl,r5
      0013F0 8E 83            [24]  748 	mov	dph,r6
      0013F2 8F F0            [24]  749 	mov	b,r7
      0013F4 12 16 EE         [24]  750 	lcall	__gptrget
      0013F7 FC               [12]  751 	mov	r4,a
      0013F8 60 11            [24]  752 	jz	00159$
      0013FA BC 30 00         [24]  753 	cjne	r4,#0x30,00534$
      0013FD                        754 00534$:
      0013FD 40 05            [24]  755 	jc	00158$
      0013FF EC               [12]  756 	mov	a,r4
      001400 24 C6            [12]  757 	add	a,#0xff - 0x39
      001402 50 07            [24]  758 	jnc	00159$
      001404                        759 00158$:
                                    760 ;	src\json.c:60: p++;
      001404 0D               [12]  761 	inc	r5
      001405 BD 00 E6         [24]  762 	cjne	r5,#0x00,00157$
      001408 0E               [12]  763 	inc	r6
      001409 80 E3            [24]  764 	sjmp	00157$
      00140B                        765 00159$:
                                    766 ;	src\json.c:61: *MotorB = 0;
      00140B AA 33            [24]  767 	mov	r2,_parse_json_PARM_8
      00140D AB 34            [24]  768 	mov	r3,(_parse_json_PARM_8 + 1)
      00140F AC 35            [24]  769 	mov	r4,(_parse_json_PARM_8 + 2)
      001411 8A 82            [24]  770 	mov	dpl,r2
      001413 8B 83            [24]  771 	mov	dph,r3
      001415 8C F0            [24]  772 	mov	b,r4
      001417 E4               [12]  773 	clr	a
      001418 12 16 48         [24]  774 	lcall	__gptrput
      00141B A3               [24]  775 	inc	dptr
      00141C 12 16 48         [24]  776 	lcall	__gptrput
                                    777 ;	src\json.c:62: while (*p >= '0' && *p <= '9')
      00141F 8D 39            [24]  778 	mov	_parse_json_p_10000_3,r5
      001421 8E 3A            [24]  779 	mov	(_parse_json_p_10000_3 + 1),r6
      001423 8F 3B            [24]  780 	mov	(_parse_json_p_10000_3 + 2),r7
      001425                        781 00161$:
      001425 85 39 82         [24]  782 	mov	dpl,_parse_json_p_10000_3
      001428 85 3A 83         [24]  783 	mov	dph,(_parse_json_p_10000_3 + 1)
      00142B 85 3B F0         [24]  784 	mov	b,(_parse_json_p_10000_3 + 2)
      00142E 12 16 EE         [24]  785 	lcall	__gptrget
      001431 F9               [12]  786 	mov	r1,a
      001432 B9 30 00         [24]  787 	cjne	r1,#0x30,00538$
      001435                        788 00538$:
      001435 40 59            [24]  789 	jc	00219$
      001437 E9               [12]  790 	mov	a,r1
      001438 24 C6            [12]  791 	add	a,#0xff - 0x39
      00143A 40 54            [24]  792 	jc	00219$
                                    793 ;	src\json.c:64: *MotorB = *MotorB * 10 + (*p - '0');
      00143C 8A 82            [24]  794 	mov	dpl,r2
      00143E 8B 83            [24]  795 	mov	dph,r3
      001440 8C F0            [24]  796 	mov	b,r4
      001442 12 16 EE         [24]  797 	lcall	__gptrget
      001445 F5 44            [12]  798 	mov	__mulint_PARM_2,a
      001447 A3               [24]  799 	inc	dptr
      001448 12 16 EE         [24]  800 	lcall	__gptrget
      00144B F5 45            [12]  801 	mov	(__mulint_PARM_2 + 1),a
      00144D 90 00 0A         [24]  802 	mov	dptr,#0x000a
      001450 C0 04            [24]  803 	push	ar4
      001452 C0 03            [24]  804 	push	ar3
      001454 C0 02            [24]  805 	push	ar2
      001456 C0 01            [24]  806 	push	ar1
      001458 12 16 63         [24]  807 	lcall	__mulint
      00145B A8 82            [24]  808 	mov	r0, dpl
      00145D AF 83            [24]  809 	mov	r7, dph
      00145F D0 01            [24]  810 	pop	ar1
      001461 D0 02            [24]  811 	pop	ar2
      001463 D0 03            [24]  812 	pop	ar3
      001465 D0 04            [24]  813 	pop	ar4
      001467 7E 00            [12]  814 	mov	r6,#0x00
      001469 E9               [12]  815 	mov	a,r1
      00146A 24 D0            [12]  816 	add	a,#0xd0
      00146C F9               [12]  817 	mov	r1,a
      00146D EE               [12]  818 	mov	a,r6
      00146E 34 FF            [12]  819 	addc	a,#0xff
      001470 FE               [12]  820 	mov	r6,a
      001471 E9               [12]  821 	mov	a,r1
      001472 28               [12]  822 	add	a, r0
      001473 F8               [12]  823 	mov	r0,a
      001474 EE               [12]  824 	mov	a,r6
      001475 3F               [12]  825 	addc	a, r7
      001476 FF               [12]  826 	mov	r7,a
      001477 8A 82            [24]  827 	mov	dpl,r2
      001479 8B 83            [24]  828 	mov	dph,r3
      00147B 8C F0            [24]  829 	mov	b,r4
      00147D E8               [12]  830 	mov	a,r0
      00147E 12 16 48         [24]  831 	lcall	__gptrput
      001481 A3               [24]  832 	inc	dptr
      001482 EF               [12]  833 	mov	a,r7
      001483 12 16 48         [24]  834 	lcall	__gptrput
                                    835 ;	src\json.c:65: p++;
      001486 05 39            [12]  836 	inc	_parse_json_p_10000_3
      001488 E4               [12]  837 	clr	a
                                    838 ;	src\json.c:67: while (*p && (*p < '0' || *p > '9'))
      001489 B5 39 99         [24]  839 	cjne	a,_parse_json_p_10000_3,00161$
      00148C 05 3A            [12]  840 	inc	(_parse_json_p_10000_3 + 1)
      00148E 80 95            [24]  841 	sjmp	00161$
      001490                        842 00219$:
      001490 AD 39            [24]  843 	mov	r5,_parse_json_p_10000_3
      001492 AE 3A            [24]  844 	mov	r6,(_parse_json_p_10000_3 + 1)
      001494 AF 3B            [24]  845 	mov	r7,(_parse_json_p_10000_3 + 2)
      001496                        846 00166$:
      001496 8D 82            [24]  847 	mov	dpl,r5
      001498 8E 83            [24]  848 	mov	dph,r6
      00149A 8F F0            [24]  849 	mov	b,r7
      00149C 12 16 EE         [24]  850 	lcall	__gptrget
      00149F FC               [12]  851 	mov	r4,a
      0014A0 60 11            [24]  852 	jz	00168$
      0014A2 BC 30 00         [24]  853 	cjne	r4,#0x30,00543$
      0014A5                        854 00543$:
      0014A5 40 05            [24]  855 	jc	00167$
      0014A7 EC               [12]  856 	mov	a,r4
      0014A8 24 C6            [12]  857 	add	a,#0xff - 0x39
      0014AA 50 07            [24]  858 	jnc	00168$
      0014AC                        859 00167$:
                                    860 ;	src\json.c:68: p++;
      0014AC 0D               [12]  861 	inc	r5
      0014AD BD 00 E6         [24]  862 	cjne	r5,#0x00,00166$
      0014B0 0E               [12]  863 	inc	r6
      0014B1 80 E3            [24]  864 	sjmp	00166$
      0014B3                        865 00168$:
                                    866 ;	src\json.c:69: *sMotorB = 0;
      0014B3 AA 36            [24]  867 	mov	r2,_parse_json_PARM_9
      0014B5 AB 37            [24]  868 	mov	r3,(_parse_json_PARM_9 + 1)
      0014B7 AC 38            [24]  869 	mov	r4,(_parse_json_PARM_9 + 2)
      0014B9 8A 82            [24]  870 	mov	dpl,r2
      0014BB 8B 83            [24]  871 	mov	dph,r3
      0014BD 8C F0            [24]  872 	mov	b,r4
      0014BF E4               [12]  873 	clr	a
      0014C0 12 16 48         [24]  874 	lcall	__gptrput
      0014C3 A3               [24]  875 	inc	dptr
      0014C4 12 16 48         [24]  876 	lcall	__gptrput
                                    877 ;	src\json.c:70: while (*p >= '0' && *p <= '9')
      0014C7 8D 39            [24]  878 	mov	_parse_json_p_10000_3,r5
      0014C9 8E 3A            [24]  879 	mov	(_parse_json_p_10000_3 + 1),r6
      0014CB 8F 3B            [24]  880 	mov	(_parse_json_p_10000_3 + 2),r7
      0014CD                        881 00170$:
      0014CD 85 39 82         [24]  882 	mov	dpl,_parse_json_p_10000_3
      0014D0 85 3A 83         [24]  883 	mov	dph,(_parse_json_p_10000_3 + 1)
      0014D3 85 3B F0         [24]  884 	mov	b,(_parse_json_p_10000_3 + 2)
      0014D6 12 16 EE         [24]  885 	lcall	__gptrget
      0014D9 F9               [12]  886 	mov	r1,a
      0014DA B9 30 00         [24]  887 	cjne	r1,#0x30,00547$
      0014DD                        888 00547$:
      0014DD 40 59            [24]  889 	jc	00172$
      0014DF E9               [12]  890 	mov	a,r1
      0014E0 24 C6            [12]  891 	add	a,#0xff - 0x39
      0014E2 40 54            [24]  892 	jc	00172$
                                    893 ;	src\json.c:72: *sMotorB = *sMotorB * 10 + (*p - '0');
      0014E4 8A 82            [24]  894 	mov	dpl,r2
      0014E6 8B 83            [24]  895 	mov	dph,r3
      0014E8 8C F0            [24]  896 	mov	b,r4
      0014EA 12 16 EE         [24]  897 	lcall	__gptrget
      0014ED F5 44            [12]  898 	mov	__mulint_PARM_2,a
      0014EF A3               [24]  899 	inc	dptr
      0014F0 12 16 EE         [24]  900 	lcall	__gptrget
      0014F3 F5 45            [12]  901 	mov	(__mulint_PARM_2 + 1),a
      0014F5 90 00 0A         [24]  902 	mov	dptr,#0x000a
      0014F8 C0 04            [24]  903 	push	ar4
      0014FA C0 03            [24]  904 	push	ar3
      0014FC C0 02            [24]  905 	push	ar2
      0014FE C0 01            [24]  906 	push	ar1
      001500 12 16 63         [24]  907 	lcall	__mulint
      001503 A8 82            [24]  908 	mov	r0, dpl
      001505 AF 83            [24]  909 	mov	r7, dph
      001507 D0 01            [24]  910 	pop	ar1
      001509 D0 02            [24]  911 	pop	ar2
      00150B D0 03            [24]  912 	pop	ar3
      00150D D0 04            [24]  913 	pop	ar4
      00150F 7E 00            [12]  914 	mov	r6,#0x00
      001511 E9               [12]  915 	mov	a,r1
      001512 24 D0            [12]  916 	add	a,#0xd0
      001514 F9               [12]  917 	mov	r1,a
      001515 EE               [12]  918 	mov	a,r6
      001516 34 FF            [12]  919 	addc	a,#0xff
      001518 FE               [12]  920 	mov	r6,a
      001519 E9               [12]  921 	mov	a,r1
      00151A 28               [12]  922 	add	a, r0
      00151B F8               [12]  923 	mov	r0,a
      00151C EE               [12]  924 	mov	a,r6
      00151D 3F               [12]  925 	addc	a, r7
      00151E FF               [12]  926 	mov	r7,a
      00151F 8A 82            [24]  927 	mov	dpl,r2
      001521 8B 83            [24]  928 	mov	dph,r3
      001523 8C F0            [24]  929 	mov	b,r4
      001525 E8               [12]  930 	mov	a,r0
      001526 12 16 48         [24]  931 	lcall	__gptrput
      001529 A3               [24]  932 	inc	dptr
      00152A EF               [12]  933 	mov	a,r7
      00152B 12 16 48         [24]  934 	lcall	__gptrput
                                    935 ;	src\json.c:73: p++;
      00152E 05 39            [12]  936 	inc	_parse_json_p_10000_3
      001530 E4               [12]  937 	clr	a
      001531 B5 39 99         [24]  938 	cjne	a,_parse_json_p_10000_3,00170$
      001534 05 3A            [12]  939 	inc	(_parse_json_p_10000_3 + 1)
      001536 80 95            [24]  940 	sjmp	00170$
      001538                        941 00172$:
                                    942 ;	src\json.c:76: return 1; // parse thành công
      001538 75 82 01         [24]  943 	mov	dpl, #0x01
                                    944 ;	src\json.c:77: }
      00153B 22               [24]  945 	ret
                                    946 	.area CSEG    (CODE)
                                    947 	.area CONST   (CODE)
                                    948 	.area XINIT   (CODE)
                                    949 	.area CABS    (ABS,CODE)
