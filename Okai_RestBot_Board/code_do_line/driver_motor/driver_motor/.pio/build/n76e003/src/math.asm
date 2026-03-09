;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler 
; Version 4.4.0 #14620 (MINGW32)
;--------------------------------------------------------
	.module math
	.optsdcc -mmcs51 --model-small
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _map_PARM_5
	.globl _map_PARM_4
	.globl _map_PARM_3
	.globl _map_PARM_2
	.globl _map
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
;--------------------------------------------------------
; special function bits
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
;--------------------------------------------------------
; overlayable register banks
;--------------------------------------------------------
	.area REG_BANK_0	(REL,OVR,DATA)
	.ds 8
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	.area DSEG    (DATA)
_map_PARM_2:
	.ds 2
_map_PARM_3:
	.ds 2
_map_PARM_4:
	.ds 2
_map_PARM_5:
	.ds 2
;--------------------------------------------------------
; overlayable items in internal ram
;--------------------------------------------------------
;--------------------------------------------------------
; indirectly addressable internal ram data
;--------------------------------------------------------
	.area ISEG    (DATA)
;--------------------------------------------------------
; absolute internal ram data
;--------------------------------------------------------
	.area IABS    (ABS,DATA)
	.area IABS    (ABS,DATA)
;--------------------------------------------------------
; bit data
;--------------------------------------------------------
	.area BSEG    (BIT)
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
;Allocation info for local variables in function 'map'
;------------------------------------------------------------
;inMin                     Allocated with name '_map_PARM_2'
;inMax                     Allocated with name '_map_PARM_3'
;outMin                    Allocated with name '_map_PARM_4'
;outMax                    Allocated with name '_map_PARM_5'
;x                         Allocated to registers r6 r7 
;------------------------------------------------------------
;	src\math.c:3: uint16_t map(uint16_t x, uint16_t inMin, uint16_t inMax, uint16_t outMin, uint16_t outMax) {
;	-----------------------------------------
;	 function map
;	-----------------------------------------
_map:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
	mov	r6, dpl
	mov	r7, dph
;	src\math.c:4: return (uint16_t)(((uint32_t)(x - inMin) * (outMax - outMin)) 
	mov	a,r6
	clr	c
	subb	a,_map_PARM_2
	mov	r6,a
	mov	a,r7
	subb	a,(_map_PARM_2 + 1)
	mov	r7,a
	clr	a
	mov	r5,a
	mov	r4,a
	mov	a,_map_PARM_5
	clr	c
	subb	a,_map_PARM_4
	mov	r2,a
	mov	a,(_map_PARM_5 + 1)
	subb	a,(_map_PARM_4 + 1)
	mov	r3,a
	mov	__mullong_PARM_2,r2
	mov	(__mullong_PARM_2 + 1),r3
	mov	(__mullong_PARM_2 + 2),r5
	mov	(__mullong_PARM_2 + 3),r5
;	src\math.c:5: / (inMax - inMin) + outMin);
	mov	dpl, r6
	mov	dph, r7
	mov	b, r5
	mov	a, r4
	lcall	__mullong
	mov	r4, dpl
	mov	r5, dph
	mov	r6, b
	mov	r7, a
	mov	a,_map_PARM_3
	clr	c
	subb	a,_map_PARM_2
	mov	r2,a
	mov	a,(_map_PARM_3 + 1)
	subb	a,(_map_PARM_2 + 1)
	mov	r3,a
	mov	__divulong_PARM_2,r2
	mov	(__divulong_PARM_2 + 1),r3
	mov	(__divulong_PARM_2 + 2),#0x00
	mov	(__divulong_PARM_2 + 3),#0x00
	mov	dpl, r4
	mov	dph, r5
	mov	b, r6
	mov	a, r7
	lcall	__divulong
	mov	r4, dpl
	mov	r5, dph
	mov	a,_map_PARM_4
	add	a, r4
	mov	dpl,a
	mov	a,(_map_PARM_4 + 1)
	addc	a, r5
	mov	dph,a
;	src\math.c:6: }
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
