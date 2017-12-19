;	C STARTUP FOR STM8
;	WITH AUTOMATIC DATA INITIALISATION IN FAR SPACE
;	Copyright (c) 2007 by COSMIC Software
;
	xref	f_main, __memory, __idesc__, __stack
	xref.b	c_x, c_y, __endzp
	xdef	f_exit, f__stext
;
;	start address of zpage
;
	switch	.ubsct
__suzp:
;
;	start address of bss
;
	switch	.bss
__sbss:
;
;	startup routine from reset vector
;
	switch	.text
f__stext:
;
;	initialize stack pointer
;
	ldw	x,#__stack		; stack pointer
	ldw	sp,x			; in place
;
;	setup initialized data
;
	ldf	a,__idesc__		; data start
	ld	yh,a			; address
	ldf	a,__idesc__+1
	ld	yl,a
	subw	y,#__idesc__		; convert to offset
	ldw	x,#2			; descriptor offset
ibcl:
	ldf	a,(__idesc__,x)		; test flag byte
	jreq	zero			; no more segment
	bcp	a,#$60			; test for moveable code segment
	jreq	qbcl			; yes, skip it
	ldw	c_x,x			; save offset
	ldf	a,(__idesc__+4,x)	; load
	push	a			; end
	ldf	a,(__idesc__+3,x)	; address
	push	a
	popw	x			; convert
	subw	x,#__idesc__		; to offset
	ldw	c_y,x			; in memory
	ldw	x,c_x			; reload offset
	ldf	a,(__idesc__+2,x)	; load
	push	a			; start
	ldf	a,(__idesc__+1,x)	; address
	push	a
	popw	x
dbcl:
	ldf	a,(__idesc__,y)		; transfer
	ld	(x),a			; byte
	incw	x			; increment
	incw	y			; pointers
	cpw	y,c_y			; last byte ?
	jrne	dbcl			; no, loop again
	ldw	x,c_x			; reload offset
qbcl:
	addw	x,#5			; next descriptor
	jra	ibcl			; and loop
;
;	reset uninitialized data in zero page
;
zero:
	ldw	x,#__suzp		; start of uninitialized zpage
	jra	loop			; test segment end first
zbcl:
	ld	(x),a			; clear byte
	incw	x			; next byte
loop:
	cpw	x,#__endzp		; end of zpage
	jrne	zbcl			; no, continue
;
;	reset uninitialized data in bss
;
	ldw	x,#__sbss		; start address
	jra	ok			; test segment end first
bbcl:
	ld	(x),a			; clear byte
	incw	x			; next byte
ok:
	cpw	x,#__memory		; compare end
	jrne	bbcl			; not equal, continue
;
;	execute main() function
;	may be called by a 'jpf' instruction if no return expected
;
	callf	f_main			; execute main
f_exit:
	jra	f_exit			; and stay here
;
	end
