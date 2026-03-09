                                      1 ;--------------------------------------------------------
                                      2 ; File Created by SDCC : free open source ISO C Compiler 
                                      3 ; Version 4.4.0 #14620 (MINGW32)
                                      4 ;--------------------------------------------------------
                                      5 	.module math
                                      6 	.optsdcc -mmcs51 --model-small
                                      7 	
                                      8 ;--------------------------------------------------------
                                      9 ; Public variables in this module
                                     10 ;--------------------------------------------------------
                                     11 	.globl _map_PARM_5
                                     12 	.globl _map_PARM_4
                                     13 	.globl _map_PARM_3
                                     14 	.globl _map_PARM_2
                                     15 	.globl _map
                                     16 ;--------------------------------------------------------
                                     17 ; special function registers
                                     18 ;--------------------------------------------------------
                                     19 	.area RSEG    (ABS,DATA)
      000000                         20 	.org 0x0000
                                     21 ;--------------------------------------------------------
                                     22 ; special function bits
                                     23 ;--------------------------------------------------------
                                     24 	.area RSEG    (ABS,DATA)
      000000                         25 	.org 0x0000
                                     26 ;--------------------------------------------------------
                                     27 ; overlayable register banks
                                     28 ;--------------------------------------------------------
                                     29 	.area REG_BANK_0	(REL,OVR,DATA)
      000000                         30 	.ds 8
                                     31 ;--------------------------------------------------------
                                     32 ; internal ram data
                                     33 ;--------------------------------------------------------
                                     34 	.area DSEG    (DATA)
      00003C                         35 _map_PARM_2:
      00003C                         36 	.ds 2
      00003E                         37 _map_PARM_3:
      00003E                         38 	.ds 2
      000040                         39 _map_PARM_4:
      000040                         40 	.ds 2
      000042                         41 _map_PARM_5:
      000042                         42 	.ds 2
                                     43 ;--------------------------------------------------------
                                     44 ; overlayable items in internal ram
                                     45 ;--------------------------------------------------------
                                     46 ;--------------------------------------------------------
                                     47 ; indirectly addressable internal ram data
                                     48 ;--------------------------------------------------------
                                     49 	.area ISEG    (DATA)
                                     50 ;--------------------------------------------------------
                                     51 ; absolute internal ram data
                                     52 ;--------------------------------------------------------
                                     53 	.area IABS    (ABS,DATA)
                                     54 	.area IABS    (ABS,DATA)
                                     55 ;--------------------------------------------------------
                                     56 ; bit data
                                     57 ;--------------------------------------------------------
                                     58 	.area BSEG    (BIT)
                                     59 ;--------------------------------------------------------
                                     60 ; paged external ram data
                                     61 ;--------------------------------------------------------
                                     62 	.area PSEG    (PAG,XDATA)
                                     63 ;--------------------------------------------------------
                                     64 ; uninitialized external ram data
                                     65 ;--------------------------------------------------------
                                     66 	.area XSEG    (XDATA)
                                     67 ;--------------------------------------------------------
                                     68 ; absolute external ram data
                                     69 ;--------------------------------------------------------
                                     70 	.area XABS    (ABS,XDATA)
                                     71 ;--------------------------------------------------------
                                     72 ; initialized external ram data
                                     73 ;--------------------------------------------------------
                                     74 	.area XISEG   (XDATA)
                                     75 	.area HOME    (CODE)
                                     76 	.area GSINIT0 (CODE)
                                     77 	.area GSINIT1 (CODE)
                                     78 	.area GSINIT2 (CODE)
                                     79 	.area GSINIT3 (CODE)
                                     80 	.area GSINIT4 (CODE)
                                     81 	.area GSINIT5 (CODE)
                                     82 	.area GSINIT  (CODE)
                                     83 	.area GSFINAL (CODE)
                                     84 	.area CSEG    (CODE)
                                     85 ;--------------------------------------------------------
                                     86 ; global & static initialisations
                                     87 ;--------------------------------------------------------
                                     88 	.area HOME    (CODE)
                                     89 	.area GSINIT  (CODE)
                                     90 	.area GSFINAL (CODE)
                                     91 	.area GSINIT  (CODE)
                                     92 ;--------------------------------------------------------
                                     93 ; Home
                                     94 ;--------------------------------------------------------
                                     95 	.area HOME    (CODE)
                                     96 	.area HOME    (CODE)
                                     97 ;--------------------------------------------------------
                                     98 ; code
                                     99 ;--------------------------------------------------------
                                    100 	.area CSEG    (CODE)
                                    101 ;------------------------------------------------------------
                                    102 ;Allocation info for local variables in function 'map'
                                    103 ;------------------------------------------------------------
                                    104 ;inMin                     Allocated with name '_map_PARM_2'
                                    105 ;inMax                     Allocated with name '_map_PARM_3'
                                    106 ;outMin                    Allocated with name '_map_PARM_4'
                                    107 ;outMax                    Allocated with name '_map_PARM_5'
                                    108 ;x                         Allocated to registers r6 r7 
                                    109 ;------------------------------------------------------------
                                    110 ;	src\math.c:3: uint16_t map(uint16_t x, uint16_t inMin, uint16_t inMax, uint16_t outMin, uint16_t outMax) {
                                    111 ;	-----------------------------------------
                                    112 ;	 function map
                                    113 ;	-----------------------------------------
      00153C                        114 _map:
                           000007   115 	ar7 = 0x07
                           000006   116 	ar6 = 0x06
                           000005   117 	ar5 = 0x05
                           000004   118 	ar4 = 0x04
                           000003   119 	ar3 = 0x03
                           000002   120 	ar2 = 0x02
                           000001   121 	ar1 = 0x01
                           000000   122 	ar0 = 0x00
      00153C AE 82            [24]  123 	mov	r6, dpl
      00153E AF 83            [24]  124 	mov	r7, dph
                                    125 ;	src\math.c:4: return (uint16_t)(((uint32_t)(x - inMin) * (outMax - outMin)) 
      001540 EE               [12]  126 	mov	a,r6
      001541 C3               [12]  127 	clr	c
      001542 95 3C            [12]  128 	subb	a,_map_PARM_2
      001544 FE               [12]  129 	mov	r6,a
      001545 EF               [12]  130 	mov	a,r7
      001546 95 3D            [12]  131 	subb	a,(_map_PARM_2 + 1)
      001548 FF               [12]  132 	mov	r7,a
      001549 E4               [12]  133 	clr	a
      00154A FD               [12]  134 	mov	r5,a
      00154B FC               [12]  135 	mov	r4,a
      00154C E5 42            [12]  136 	mov	a,_map_PARM_5
      00154E C3               [12]  137 	clr	c
      00154F 95 40            [12]  138 	subb	a,_map_PARM_4
      001551 FA               [12]  139 	mov	r2,a
      001552 E5 43            [12]  140 	mov	a,(_map_PARM_5 + 1)
      001554 95 41            [12]  141 	subb	a,(_map_PARM_4 + 1)
      001556 FB               [12]  142 	mov	r3,a
      001557 8A 44            [24]  143 	mov	__mullong_PARM_2,r2
      001559 8B 45            [24]  144 	mov	(__mullong_PARM_2 + 1),r3
      00155B 8D 46            [24]  145 	mov	(__mullong_PARM_2 + 2),r5
      00155D 8D 47            [24]  146 	mov	(__mullong_PARM_2 + 3),r5
                                    147 ;	src\math.c:5: / (inMax - inMin) + outMin);
      00155F 8E 82            [24]  148 	mov	dpl, r6
      001561 8F 83            [24]  149 	mov	dph, r7
      001563 8D F0            [24]  150 	mov	b, r5
      001565 EC               [12]  151 	mov	a, r4
      001566 12 16 80         [24]  152 	lcall	__mullong
      001569 AC 82            [24]  153 	mov	r4, dpl
      00156B AD 83            [24]  154 	mov	r5, dph
      00156D AE F0            [24]  155 	mov	r6, b
      00156F FF               [12]  156 	mov	r7, a
      001570 E5 3E            [12]  157 	mov	a,_map_PARM_3
      001572 C3               [12]  158 	clr	c
      001573 95 3C            [12]  159 	subb	a,_map_PARM_2
      001575 FA               [12]  160 	mov	r2,a
      001576 E5 3F            [12]  161 	mov	a,(_map_PARM_3 + 1)
      001578 95 3D            [12]  162 	subb	a,(_map_PARM_2 + 1)
      00157A FB               [12]  163 	mov	r3,a
      00157B 8A 44            [24]  164 	mov	__divulong_PARM_2,r2
      00157D 8B 45            [24]  165 	mov	(__divulong_PARM_2 + 1),r3
      00157F 75 46 00         [24]  166 	mov	(__divulong_PARM_2 + 2),#0x00
      001582 75 47 00         [24]  167 	mov	(__divulong_PARM_2 + 3),#0x00
      001585 8C 82            [24]  168 	mov	dpl, r4
      001587 8D 83            [24]  169 	mov	dph, r5
      001589 8E F0            [24]  170 	mov	b, r6
      00158B EF               [12]  171 	mov	a, r7
      00158C 12 15 E3         [24]  172 	lcall	__divulong
      00158F AC 82            [24]  173 	mov	r4, dpl
      001591 AD 83            [24]  174 	mov	r5, dph
      001593 E5 40            [12]  175 	mov	a,_map_PARM_4
      001595 2C               [12]  176 	add	a, r4
      001596 F5 82            [12]  177 	mov	dpl,a
      001598 E5 41            [12]  178 	mov	a,(_map_PARM_4 + 1)
      00159A 3D               [12]  179 	addc	a, r5
      00159B F5 83            [12]  180 	mov	dph,a
                                    181 ;	src\math.c:6: }
      00159D 22               [24]  182 	ret
                                    183 	.area CSEG    (CODE)
                                    184 	.area CONST   (CODE)
                                    185 	.area XINIT   (CODE)
                                    186 	.area CABS    (ABS,CODE)
