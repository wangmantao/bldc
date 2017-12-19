;	C STARTUP FOR STM8
;	WITH AUTOMATIC DATA INITIALISATION
;	Copyright (c) 2006 by COSMIC Software
;
	xref	_main, __memory, __idesc__, __stack
	xref.b	c_x, c_y, __endzp
	xdef	_exit, __stext
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
__stext:
;
;	initialize stack pointer
;
	ldw	x,#__stack		; stack pointer
	ldw	sp,x			; in place
;
;	setup initialized data
;
	ldw	y,__idesc__		; data start address
	ldw	x,#__idesc__+2		; descriptor address
ibcl:
	ld	a,(x)			; test flag byte
	jreq	zero			; no more segment
	bcp	a,#$60			; test for moveable code segment
	jreq	qbcl			; yes, skip it
	ldw	c_x,x			; save pointer
	ldw	x,(3,x)			; move end address
	ldw	c_y,x			; in memory
	ldw	x,c_x			; reload pointer
	ldw	x,(1,x)			; start address
dbcl:
	ld	a,(y)			; transfer
	ld	(x),a			; byte
	incw	x			; increment
	incw	y			; pointers
	cpw	y,c_y			; last byte ?
	jrne	dbcl			; no, loop again
	ldw	x,c_x			; reload pointer
qbcl:
	ldw	y,x			; copy pointer
	ldw	y,(3,y)			; update load address
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
;	may be called by a 'jp' instruction if no return expected
;
	call	_main			; execute main
_exit:
	jra	_exit			; and stay here
;
	end
