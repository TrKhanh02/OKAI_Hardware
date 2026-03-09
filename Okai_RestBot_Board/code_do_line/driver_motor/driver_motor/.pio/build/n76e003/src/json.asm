;--------------------------------------------------------
; File Created by SDCC : free open source ISO C Compiler 
; Version 4.4.0 #14620 (MINGW32)
;--------------------------------------------------------
	.module json
	.optsdcc -mmcs51 --model-small
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _parse_json_PARM_9
	.globl _parse_json_PARM_8
	.globl _parse_json_PARM_7
	.globl _parse_json_PARM_6
	.globl _parse_json_PARM_5
	.globl _parse_json_PARM_4
	.globl _parse_json_PARM_3
	.globl _parse_json_PARM_2
	.globl _parse_json
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
_parse_json_PARM_2:
	.ds 3
_parse_json_PARM_3:
	.ds 3
_parse_json_PARM_4:
	.ds 3
_parse_json_PARM_5:
	.ds 3
_parse_json_PARM_6:
	.ds 3
_parse_json_PARM_7:
	.ds 3
_parse_json_PARM_8:
	.ds 3
_parse_json_PARM_9:
	.ds 3
_parse_json_p_10000_3:
	.ds 3
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
;Allocation info for local variables in function 'parse_json'
;------------------------------------------------------------
;AngleA                    Allocated with name '_parse_json_PARM_2'
;sAngleA                   Allocated with name '_parse_json_PARM_3'
;AngleB                    Allocated with name '_parse_json_PARM_4'
;sAngleB                   Allocated with name '_parse_json_PARM_5'
;MotorA                    Allocated with name '_parse_json_PARM_6'
;sMotorA                   Allocated with name '_parse_json_PARM_7'
;MotorB                    Allocated with name '_parse_json_PARM_8'
;sMotorB                   Allocated with name '_parse_json_PARM_9'
;buf                       Allocated to registers 
;p                         Allocated with name '_parse_json_p_10000_3'
;------------------------------------------------------------
;	src\json.c:3: uint8_t parse_json(const char *buf, int *AngleA, int *sAngleA, int *AngleB, int *sAngleB, int *MotorA, int *sMotorA, int *MotorB, int *sMotorB)
;	-----------------------------------------
;	 function parse_json
;	-----------------------------------------
_parse_json:
	ar7 = 0x07
	ar6 = 0x06
	ar5 = 0x05
	ar4 = 0x04
	ar3 = 0x03
	ar2 = 0x02
	ar1 = 0x01
	ar0 = 0x00
	mov	r5, dpl
	mov	r6, dph
	mov	r7, b
;	src\json.c:8: while (*p && (*p < '0' || *p > '9'))
00103$:
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r4,a
	jz	00105$
	cjne	r4,#0x30,00480$
00480$:
	jc	00104$
	mov	a,r4
	add	a,#0xff - 0x39
	jnc	00105$
00104$:
;	src\json.c:9: p++;
	inc	r5
	cjne	r5,#0x00,00103$
	inc	r6
	sjmp	00103$
00105$:
;	src\json.c:10: *AngleA = 0;
	mov	r2,_parse_json_PARM_2
	mov	r3,(_parse_json_PARM_2 + 1)
	mov	r4,(_parse_json_PARM_2 + 2)
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	clr	a
	lcall	__gptrput
	inc	dptr
	lcall	__gptrput
;	src\json.c:11: while (*p >= '0' && *p <= '9')
	mov	_parse_json_p_10000_3,r5
	mov	(_parse_json_p_10000_3 + 1),r6
	mov	(_parse_json_p_10000_3 + 2),r7
00107$:
	mov	dpl,_parse_json_p_10000_3
	mov	dph,(_parse_json_p_10000_3 + 1)
	mov	b,(_parse_json_p_10000_3 + 2)
	lcall	__gptrget
	mov	r1,a
	cjne	r1,#0x30,00484$
00484$:
	jc	00183$
	mov	a,r1
	add	a,#0xff - 0x39
	jc	00183$
;	src\json.c:13: *AngleA = *AngleA * 10 + (*p - '0');
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	__mulint_PARM_2,a
	inc	dptr
	lcall	__gptrget
	mov	(__mulint_PARM_2 + 1),a
	mov	dptr,#0x000a
	push	ar4
	push	ar3
	push	ar2
	push	ar1
	lcall	__mulint
	mov	r0, dpl
	mov	r7, dph
	pop	ar1
	pop	ar2
	pop	ar3
	pop	ar4
	mov	r6,#0x00
	mov	a,r1
	add	a,#0xd0
	mov	r1,a
	mov	a,r6
	addc	a,#0xff
	mov	r6,a
	mov	a,r1
	add	a, r0
	mov	r0,a
	mov	a,r6
	addc	a, r7
	mov	r7,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	mov	a,r0
	lcall	__gptrput
	inc	dptr
	mov	a,r7
	lcall	__gptrput
;	src\json.c:14: p++;
	inc	_parse_json_p_10000_3
	clr	a
;	src\json.c:16: while (*p && (*p < '0' || *p > '9'))
	cjne	a,_parse_json_p_10000_3,00107$
	inc	(_parse_json_p_10000_3 + 1)
	sjmp	00107$
00183$:
	mov	r5,_parse_json_p_10000_3
	mov	r6,(_parse_json_p_10000_3 + 1)
	mov	r7,(_parse_json_p_10000_3 + 2)
00112$:
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r4,a
	jz	00114$
	cjne	r4,#0x30,00489$
00489$:
	jc	00113$
	mov	a,r4
	add	a,#0xff - 0x39
	jnc	00114$
00113$:
;	src\json.c:17: p++;
	inc	r5
	cjne	r5,#0x00,00112$
	inc	r6
	sjmp	00112$
00114$:
;	src\json.c:18: *sAngleA = 0;
	mov	r2,_parse_json_PARM_3
	mov	r3,(_parse_json_PARM_3 + 1)
	mov	r4,(_parse_json_PARM_3 + 2)
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	clr	a
	lcall	__gptrput
	inc	dptr
	lcall	__gptrput
;	src\json.c:19: while (*p >= '0' && *p <= '9')
	mov	_parse_json_p_10000_3,r5
	mov	(_parse_json_p_10000_3 + 1),r6
	mov	(_parse_json_p_10000_3 + 2),r7
00116$:
	mov	dpl,_parse_json_p_10000_3
	mov	dph,(_parse_json_p_10000_3 + 1)
	mov	b,(_parse_json_p_10000_3 + 2)
	lcall	__gptrget
	mov	r1,a
	cjne	r1,#0x30,00493$
00493$:
	jc	00189$
	mov	a,r1
	add	a,#0xff - 0x39
	jc	00189$
;	src\json.c:21: *sAngleA = *sAngleA * 10 + (*p - '0');
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	__mulint_PARM_2,a
	inc	dptr
	lcall	__gptrget
	mov	(__mulint_PARM_2 + 1),a
	mov	dptr,#0x000a
	push	ar4
	push	ar3
	push	ar2
	push	ar1
	lcall	__mulint
	mov	r0, dpl
	mov	r7, dph
	pop	ar1
	pop	ar2
	pop	ar3
	pop	ar4
	mov	r6,#0x00
	mov	a,r1
	add	a,#0xd0
	mov	r1,a
	mov	a,r6
	addc	a,#0xff
	mov	r6,a
	mov	a,r1
	add	a, r0
	mov	r0,a
	mov	a,r6
	addc	a, r7
	mov	r7,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	mov	a,r0
	lcall	__gptrput
	inc	dptr
	mov	a,r7
	lcall	__gptrput
;	src\json.c:22: p++;
	inc	_parse_json_p_10000_3
	clr	a
;	src\json.c:25: while (*p && (*p < '0' || *p > '9'))
	cjne	a,_parse_json_p_10000_3,00116$
	inc	(_parse_json_p_10000_3 + 1)
	sjmp	00116$
00189$:
	mov	r5,_parse_json_p_10000_3
	mov	r6,(_parse_json_p_10000_3 + 1)
	mov	r7,(_parse_json_p_10000_3 + 2)
00121$:
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r4,a
	jz	00123$
	cjne	r4,#0x30,00498$
00498$:
	jc	00122$
	mov	a,r4
	add	a,#0xff - 0x39
	jnc	00123$
00122$:
;	src\json.c:26: p++;
	inc	r5
	cjne	r5,#0x00,00121$
	inc	r6
	sjmp	00121$
00123$:
;	src\json.c:27: *AngleB = 0;
	mov	r2,_parse_json_PARM_4
	mov	r3,(_parse_json_PARM_4 + 1)
	mov	r4,(_parse_json_PARM_4 + 2)
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	clr	a
	lcall	__gptrput
	inc	dptr
	lcall	__gptrput
;	src\json.c:28: while (*p >= '0' && *p <= '9')
	mov	_parse_json_p_10000_3,r5
	mov	(_parse_json_p_10000_3 + 1),r6
	mov	(_parse_json_p_10000_3 + 2),r7
00125$:
	mov	dpl,_parse_json_p_10000_3
	mov	dph,(_parse_json_p_10000_3 + 1)
	mov	b,(_parse_json_p_10000_3 + 2)
	lcall	__gptrget
	mov	r1,a
	cjne	r1,#0x30,00502$
00502$:
	jc	00195$
	mov	a,r1
	add	a,#0xff - 0x39
	jc	00195$
;	src\json.c:30: *AngleB = *AngleB * 10 + (*p - '0');
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	__mulint_PARM_2,a
	inc	dptr
	lcall	__gptrget
	mov	(__mulint_PARM_2 + 1),a
	mov	dptr,#0x000a
	push	ar4
	push	ar3
	push	ar2
	push	ar1
	lcall	__mulint
	mov	r0, dpl
	mov	r7, dph
	pop	ar1
	pop	ar2
	pop	ar3
	pop	ar4
	mov	r6,#0x00
	mov	a,r1
	add	a,#0xd0
	mov	r1,a
	mov	a,r6
	addc	a,#0xff
	mov	r6,a
	mov	a,r1
	add	a, r0
	mov	r0,a
	mov	a,r6
	addc	a, r7
	mov	r7,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	mov	a,r0
	lcall	__gptrput
	inc	dptr
	mov	a,r7
	lcall	__gptrput
;	src\json.c:31: p++;
	inc	_parse_json_p_10000_3
	clr	a
;	src\json.c:33: while (*p && (*p < '0' || *p > '9'))
	cjne	a,_parse_json_p_10000_3,00125$
	inc	(_parse_json_p_10000_3 + 1)
	sjmp	00125$
00195$:
	mov	r5,_parse_json_p_10000_3
	mov	r6,(_parse_json_p_10000_3 + 1)
	mov	r7,(_parse_json_p_10000_3 + 2)
00130$:
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r4,a
	jz	00132$
	cjne	r4,#0x30,00507$
00507$:
	jc	00131$
	mov	a,r4
	add	a,#0xff - 0x39
	jnc	00132$
00131$:
;	src\json.c:34: p++;
	inc	r5
	cjne	r5,#0x00,00130$
	inc	r6
	sjmp	00130$
00132$:
;	src\json.c:35: *sAngleB = 0;
	mov	r2,_parse_json_PARM_5
	mov	r3,(_parse_json_PARM_5 + 1)
	mov	r4,(_parse_json_PARM_5 + 2)
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	clr	a
	lcall	__gptrput
	inc	dptr
	lcall	__gptrput
;	src\json.c:36: while (*p >= '0' && *p <= '9')
	mov	_parse_json_p_10000_3,r5
	mov	(_parse_json_p_10000_3 + 1),r6
	mov	(_parse_json_p_10000_3 + 2),r7
00134$:
	mov	dpl,_parse_json_p_10000_3
	mov	dph,(_parse_json_p_10000_3 + 1)
	mov	b,(_parse_json_p_10000_3 + 2)
	lcall	__gptrget
	mov	r1,a
	cjne	r1,#0x30,00511$
00511$:
	jc	00201$
	mov	a,r1
	add	a,#0xff - 0x39
	jc	00201$
;	src\json.c:38: *sAngleB = *sAngleB * 10 + (*p - '0');
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	__mulint_PARM_2,a
	inc	dptr
	lcall	__gptrget
	mov	(__mulint_PARM_2 + 1),a
	mov	dptr,#0x000a
	push	ar4
	push	ar3
	push	ar2
	push	ar1
	lcall	__mulint
	mov	r0, dpl
	mov	r7, dph
	pop	ar1
	pop	ar2
	pop	ar3
	pop	ar4
	mov	r6,#0x00
	mov	a,r1
	add	a,#0xd0
	mov	r1,a
	mov	a,r6
	addc	a,#0xff
	mov	r6,a
	mov	a,r1
	add	a, r0
	mov	r0,a
	mov	a,r6
	addc	a, r7
	mov	r7,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	mov	a,r0
	lcall	__gptrput
	inc	dptr
	mov	a,r7
	lcall	__gptrput
;	src\json.c:39: p++;
	inc	_parse_json_p_10000_3
	clr	a
;	src\json.c:42: while (*p && (*p < '0' || *p > '9'))
	cjne	a,_parse_json_p_10000_3,00134$
	inc	(_parse_json_p_10000_3 + 1)
	sjmp	00134$
00201$:
	mov	r5,_parse_json_p_10000_3
	mov	r6,(_parse_json_p_10000_3 + 1)
	mov	r7,(_parse_json_p_10000_3 + 2)
00139$:
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r4,a
	jz	00141$
	cjne	r4,#0x30,00516$
00516$:
	jc	00140$
	mov	a,r4
	add	a,#0xff - 0x39
	jnc	00141$
00140$:
;	src\json.c:43: p++;
	inc	r5
	cjne	r5,#0x00,00139$
	inc	r6
	sjmp	00139$
00141$:
;	src\json.c:44: *MotorA = 0;
	mov	r2,_parse_json_PARM_6
	mov	r3,(_parse_json_PARM_6 + 1)
	mov	r4,(_parse_json_PARM_6 + 2)
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	clr	a
	lcall	__gptrput
	inc	dptr
	lcall	__gptrput
;	src\json.c:45: while (*p >= '0' && *p <= '9')
	mov	_parse_json_p_10000_3,r5
	mov	(_parse_json_p_10000_3 + 1),r6
	mov	(_parse_json_p_10000_3 + 2),r7
00143$:
	mov	dpl,_parse_json_p_10000_3
	mov	dph,(_parse_json_p_10000_3 + 1)
	mov	b,(_parse_json_p_10000_3 + 2)
	lcall	__gptrget
	mov	r1,a
	cjne	r1,#0x30,00520$
00520$:
	jc	00207$
	mov	a,r1
	add	a,#0xff - 0x39
	jc	00207$
;	src\json.c:47: *MotorA = *MotorA * 10 + (*p - '0');
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	__mulint_PARM_2,a
	inc	dptr
	lcall	__gptrget
	mov	(__mulint_PARM_2 + 1),a
	mov	dptr,#0x000a
	push	ar4
	push	ar3
	push	ar2
	push	ar1
	lcall	__mulint
	mov	r0, dpl
	mov	r7, dph
	pop	ar1
	pop	ar2
	pop	ar3
	pop	ar4
	mov	r6,#0x00
	mov	a,r1
	add	a,#0xd0
	mov	r1,a
	mov	a,r6
	addc	a,#0xff
	mov	r6,a
	mov	a,r1
	add	a, r0
	mov	r0,a
	mov	a,r6
	addc	a, r7
	mov	r7,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	mov	a,r0
	lcall	__gptrput
	inc	dptr
	mov	a,r7
	lcall	__gptrput
;	src\json.c:48: p++;
	inc	_parse_json_p_10000_3
	clr	a
;	src\json.c:50: while (*p && (*p < '0' || *p > '9'))
	cjne	a,_parse_json_p_10000_3,00143$
	inc	(_parse_json_p_10000_3 + 1)
	sjmp	00143$
00207$:
	mov	r5,_parse_json_p_10000_3
	mov	r6,(_parse_json_p_10000_3 + 1)
	mov	r7,(_parse_json_p_10000_3 + 2)
00148$:
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r4,a
	jz	00150$
	cjne	r4,#0x30,00525$
00525$:
	jc	00149$
	mov	a,r4
	add	a,#0xff - 0x39
	jnc	00150$
00149$:
;	src\json.c:51: p++;
	inc	r5
	cjne	r5,#0x00,00148$
	inc	r6
	sjmp	00148$
00150$:
;	src\json.c:52: *sMotorA = 0;
	mov	r2,_parse_json_PARM_7
	mov	r3,(_parse_json_PARM_7 + 1)
	mov	r4,(_parse_json_PARM_7 + 2)
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	clr	a
	lcall	__gptrput
	inc	dptr
	lcall	__gptrput
;	src\json.c:53: while (*p >= '0' && *p <= '9')
	mov	_parse_json_p_10000_3,r5
	mov	(_parse_json_p_10000_3 + 1),r6
	mov	(_parse_json_p_10000_3 + 2),r7
00152$:
	mov	dpl,_parse_json_p_10000_3
	mov	dph,(_parse_json_p_10000_3 + 1)
	mov	b,(_parse_json_p_10000_3 + 2)
	lcall	__gptrget
	mov	r1,a
	cjne	r1,#0x30,00529$
00529$:
	jc	00213$
	mov	a,r1
	add	a,#0xff - 0x39
	jc	00213$
;	src\json.c:55: *sMotorA = *sMotorA * 10 + (*p - '0');
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	__mulint_PARM_2,a
	inc	dptr
	lcall	__gptrget
	mov	(__mulint_PARM_2 + 1),a
	mov	dptr,#0x000a
	push	ar4
	push	ar3
	push	ar2
	push	ar1
	lcall	__mulint
	mov	r0, dpl
	mov	r7, dph
	pop	ar1
	pop	ar2
	pop	ar3
	pop	ar4
	mov	r6,#0x00
	mov	a,r1
	add	a,#0xd0
	mov	r1,a
	mov	a,r6
	addc	a,#0xff
	mov	r6,a
	mov	a,r1
	add	a, r0
	mov	r0,a
	mov	a,r6
	addc	a, r7
	mov	r7,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	mov	a,r0
	lcall	__gptrput
	inc	dptr
	mov	a,r7
	lcall	__gptrput
;	src\json.c:56: p++;
	inc	_parse_json_p_10000_3
	clr	a
;	src\json.c:59: while (*p && (*p < '0' || *p > '9'))
	cjne	a,_parse_json_p_10000_3,00152$
	inc	(_parse_json_p_10000_3 + 1)
	sjmp	00152$
00213$:
	mov	r5,_parse_json_p_10000_3
	mov	r6,(_parse_json_p_10000_3 + 1)
	mov	r7,(_parse_json_p_10000_3 + 2)
00157$:
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r4,a
	jz	00159$
	cjne	r4,#0x30,00534$
00534$:
	jc	00158$
	mov	a,r4
	add	a,#0xff - 0x39
	jnc	00159$
00158$:
;	src\json.c:60: p++;
	inc	r5
	cjne	r5,#0x00,00157$
	inc	r6
	sjmp	00157$
00159$:
;	src\json.c:61: *MotorB = 0;
	mov	r2,_parse_json_PARM_8
	mov	r3,(_parse_json_PARM_8 + 1)
	mov	r4,(_parse_json_PARM_8 + 2)
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	clr	a
	lcall	__gptrput
	inc	dptr
	lcall	__gptrput
;	src\json.c:62: while (*p >= '0' && *p <= '9')
	mov	_parse_json_p_10000_3,r5
	mov	(_parse_json_p_10000_3 + 1),r6
	mov	(_parse_json_p_10000_3 + 2),r7
00161$:
	mov	dpl,_parse_json_p_10000_3
	mov	dph,(_parse_json_p_10000_3 + 1)
	mov	b,(_parse_json_p_10000_3 + 2)
	lcall	__gptrget
	mov	r1,a
	cjne	r1,#0x30,00538$
00538$:
	jc	00219$
	mov	a,r1
	add	a,#0xff - 0x39
	jc	00219$
;	src\json.c:64: *MotorB = *MotorB * 10 + (*p - '0');
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	__mulint_PARM_2,a
	inc	dptr
	lcall	__gptrget
	mov	(__mulint_PARM_2 + 1),a
	mov	dptr,#0x000a
	push	ar4
	push	ar3
	push	ar2
	push	ar1
	lcall	__mulint
	mov	r0, dpl
	mov	r7, dph
	pop	ar1
	pop	ar2
	pop	ar3
	pop	ar4
	mov	r6,#0x00
	mov	a,r1
	add	a,#0xd0
	mov	r1,a
	mov	a,r6
	addc	a,#0xff
	mov	r6,a
	mov	a,r1
	add	a, r0
	mov	r0,a
	mov	a,r6
	addc	a, r7
	mov	r7,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	mov	a,r0
	lcall	__gptrput
	inc	dptr
	mov	a,r7
	lcall	__gptrput
;	src\json.c:65: p++;
	inc	_parse_json_p_10000_3
	clr	a
;	src\json.c:67: while (*p && (*p < '0' || *p > '9'))
	cjne	a,_parse_json_p_10000_3,00161$
	inc	(_parse_json_p_10000_3 + 1)
	sjmp	00161$
00219$:
	mov	r5,_parse_json_p_10000_3
	mov	r6,(_parse_json_p_10000_3 + 1)
	mov	r7,(_parse_json_p_10000_3 + 2)
00166$:
	mov	dpl,r5
	mov	dph,r6
	mov	b,r7
	lcall	__gptrget
	mov	r4,a
	jz	00168$
	cjne	r4,#0x30,00543$
00543$:
	jc	00167$
	mov	a,r4
	add	a,#0xff - 0x39
	jnc	00168$
00167$:
;	src\json.c:68: p++;
	inc	r5
	cjne	r5,#0x00,00166$
	inc	r6
	sjmp	00166$
00168$:
;	src\json.c:69: *sMotorB = 0;
	mov	r2,_parse_json_PARM_9
	mov	r3,(_parse_json_PARM_9 + 1)
	mov	r4,(_parse_json_PARM_9 + 2)
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	clr	a
	lcall	__gptrput
	inc	dptr
	lcall	__gptrput
;	src\json.c:70: while (*p >= '0' && *p <= '9')
	mov	_parse_json_p_10000_3,r5
	mov	(_parse_json_p_10000_3 + 1),r6
	mov	(_parse_json_p_10000_3 + 2),r7
00170$:
	mov	dpl,_parse_json_p_10000_3
	mov	dph,(_parse_json_p_10000_3 + 1)
	mov	b,(_parse_json_p_10000_3 + 2)
	lcall	__gptrget
	mov	r1,a
	cjne	r1,#0x30,00547$
00547$:
	jc	00172$
	mov	a,r1
	add	a,#0xff - 0x39
	jc	00172$
;	src\json.c:72: *sMotorB = *sMotorB * 10 + (*p - '0');
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	lcall	__gptrget
	mov	__mulint_PARM_2,a
	inc	dptr
	lcall	__gptrget
	mov	(__mulint_PARM_2 + 1),a
	mov	dptr,#0x000a
	push	ar4
	push	ar3
	push	ar2
	push	ar1
	lcall	__mulint
	mov	r0, dpl
	mov	r7, dph
	pop	ar1
	pop	ar2
	pop	ar3
	pop	ar4
	mov	r6,#0x00
	mov	a,r1
	add	a,#0xd0
	mov	r1,a
	mov	a,r6
	addc	a,#0xff
	mov	r6,a
	mov	a,r1
	add	a, r0
	mov	r0,a
	mov	a,r6
	addc	a, r7
	mov	r7,a
	mov	dpl,r2
	mov	dph,r3
	mov	b,r4
	mov	a,r0
	lcall	__gptrput
	inc	dptr
	mov	a,r7
	lcall	__gptrput
;	src\json.c:73: p++;
	inc	_parse_json_p_10000_3
	clr	a
	cjne	a,_parse_json_p_10000_3,00170$
	inc	(_parse_json_p_10000_3 + 1)
	sjmp	00170$
00172$:
;	src\json.c:76: return 1; // parse thành công
	mov	dpl, #0x01
;	src\json.c:77: }
	ret
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
	.area CABS    (ABS,CODE)
