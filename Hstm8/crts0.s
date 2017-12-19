;	C STARTUP FOR STM8
;	WITHOUT ANY DATA INITIALIZATION
;	Copyright (c) 2006 by COSMIC Software
;
	xref	_main, __stack
	xdef	_exit, __stext
;
;	startup routine from reset vector
;
	switch	.text
__stext:
;
;	initialize stack pointer
;
	ldw	x,#__stack	; stack pointer
	ldw	sp,x		; in place
;
;	execute main() function
;	may be called by a 'jp' instruction if no return expected
;
	call	_main		; execute main
_exit:
	jra	_exit		; and stay here
;
	end
