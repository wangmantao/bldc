   1                     ; C Compiler for STM8 (COSMIC Software)
   2                     ; Parser V4.11.10 - 06 Jul 2017
   3                     ; Generator (Limited) V4.4.7 - 05 Oct 2017
  14                     .const:	section	.text
  15  0000               L3_hArrPwmVal:
  16  0000 03e8          	dc.w	1000
  17  0002               _PWM_EN1_TAB:
  18  0002 00            	dc.b	0
  19  0003 00            	dc.b	0
  20  0004 10            	dc.b	16
  21  0005 10            	dc.b	16
  22  0006 01            	dc.b	1
  23  0007 01            	dc.b	1
  24  0008               _PWM_EN2_TAB:
  25  0008 01            	dc.b	1
  26  0009 01            	dc.b	1
  27  000a 00            	dc.b	0
  28  000b 00            	dc.b	0
  29  000c 00            	dc.b	0
  30  000d 00            	dc.b	0
  59                     ; 60 void GPIO_int(void)
  59                     ; 61 {
  61                     	switch	.text
  62  0000               _GPIO_int:
  66                     ; 65 }
  69  0000 81            	ret
  93                     ; 68 void Clock_init(void)
  93                     ; 69 {
  94                     	switch	.text
  95  0001               _Clock_init:
  99                     ; 71   CLK_SYSCLKConfig(CLK_PRESCALER_HSIDIV1);
 101  0001 4f            	clr	a
 102  0002 cd0000        	call	_CLK_SYSCLKConfig
 104                     ; 72 }
 107  0005 81            	ret
 131                     ; 75 void PWM_IO_init(void)
 131                     ; 76 {	
 132                     	switch	.text
 133  0006               _PWM_IO_init:
 137                     ; 78 	GPIO_Init(MCO0_PORT, MCO0_PIN,GPIO_MODE_OUT_PP_HIGH_FAST);
 139  0006 4bf0          	push	#240
 140  0008 4b20          	push	#32
 141  000a ae500a        	ldw	x,#20490
 142  000d cd0000        	call	_GPIO_Init
 144  0010 85            	popw	x
 145                     ; 79 	GPIO_Init(MCO2_PORT, MCO2_PIN,GPIO_MODE_OUT_PP_HIGH_FAST);
 147  0011 4bf0          	push	#240
 148  0013 4b10          	push	#16
 149  0015 ae500a        	ldw	x,#20490
 150  0018 cd0000        	call	_GPIO_Init
 152  001b 85            	popw	x
 153                     ; 80 	GPIO_Init(MCO4_PORT, MCO4_PIN,GPIO_MODE_OUT_PP_HIGH_FAST);
 155  001c 4bf0          	push	#240
 156  001e 4b04          	push	#4
 157  0020 ae500f        	ldw	x,#20495
 158  0023 cd0000        	call	_GPIO_Init
 160  0026 85            	popw	x
 161                     ; 83 	GPIO_Init(MCO1_PORT, MCO1_PIN,GPIO_MODE_OUT_PP_LOW_FAST);
 163  0027 4be0          	push	#224
 164  0029 4b08          	push	#8
 165  002b ae500a        	ldw	x,#20490
 166  002e cd0000        	call	_GPIO_Init
 168  0031 85            	popw	x
 169                     ; 84 	GPIO_Init(MCO3_PORT, MCO3_PIN,GPIO_MODE_OUT_PP_LOW_FAST);
 171  0032 4be0          	push	#224
 172  0034 4b80          	push	#128
 173  0036 ae500a        	ldw	x,#20490
 174  0039 cd0000        	call	_GPIO_Init
 176  003c 85            	popw	x
 177                     ; 85 	GPIO_Init(MCO5_PORT, MCO5_PIN,GPIO_MODE_OUT_PP_LOW_FAST);		
 179  003d 4be0          	push	#224
 180  003f 4b40          	push	#64
 181  0041 ae500a        	ldw	x,#20490
 182  0044 cd0000        	call	_GPIO_Init
 184  0047 85            	popw	x
 185                     ; 89 }
 188  0048 81            	ret
 219                     ; 92 void Tim1_init(void)
 219                     ; 93 {
 220                     	switch	.text
 221  0049               _Tim1_init:
 225                     ; 95   TIM1_DeInit();
 227  0049 cd0000        	call	_TIM1_DeInit
 229                     ; 97   TIM1_TimeBaseInit(0, TIM1_COUNTERMODE_UP, hArrPwmVal, 0);
 231  004c 4b00          	push	#0
 232  004e ae03e8        	ldw	x,#1000
 233  0051 89            	pushw	x
 234  0052 4b00          	push	#0
 235  0054 5f            	clrw	x
 236  0055 cd0000        	call	_TIM1_TimeBaseInit
 238  0058 5b04          	addw	sp,#4
 239                     ; 99   TIM1_OC1Init(TIM1_OCMODE_PWM1, TIM1_OUTPUTSTATE_ENABLE, TIM1_OUTPUTNSTATE_DISABLE, hArrPwmVal*0, TIM1_OCPOLARITY_HIGH, TIM1_OCNPOLARITY_LOW, TIM1_OCIDLESTATE_RESET, TIM1_OCNIDLESTATE_SET); 
 241  005a 4b2a          	push	#42
 242  005c 4b00          	push	#0
 243  005e 4b88          	push	#136
 244  0060 4b00          	push	#0
 245  0062 5f            	clrw	x
 246  0063 89            	pushw	x
 247  0064 4b00          	push	#0
 248  0066 ae6011        	ldw	x,#24593
 249  0069 cd0000        	call	_TIM1_OC1Init
 251  006c 5b07          	addw	sp,#7
 252                     ; 101   TIM1_OC2Init(TIM1_OCMODE_PWM1, TIM1_OUTPUTSTATE_ENABLE, TIM1_OUTPUTNSTATE_DISABLE, hArrPwmVal*0, TIM1_OCPOLARITY_HIGH, TIM1_OCNPOLARITY_LOW, TIM1_OCIDLESTATE_RESET, TIM1_OCNIDLESTATE_SET); 
 254  006e 4b2a          	push	#42
 255  0070 4b00          	push	#0
 256  0072 4b88          	push	#136
 257  0074 4b00          	push	#0
 258  0076 5f            	clrw	x
 259  0077 89            	pushw	x
 260  0078 4b00          	push	#0
 261  007a ae6011        	ldw	x,#24593
 262  007d cd0000        	call	_TIM1_OC2Init
 264  0080 5b07          	addw	sp,#7
 265                     ; 103   TIM1_OC3Init(TIM1_OCMODE_PWM1, TIM1_OUTPUTSTATE_ENABLE, TIM1_OUTPUTNSTATE_DISABLE, hArrPwmVal*0, TIM1_OCPOLARITY_HIGH, TIM1_OCNPOLARITY_LOW, TIM1_OCIDLESTATE_RESET, TIM1_OCNIDLESTATE_SET); 
 267  0082 4b2a          	push	#42
 268  0084 4b00          	push	#0
 269  0086 4b88          	push	#136
 270  0088 4b00          	push	#0
 271  008a 5f            	clrw	x
 272  008b 89            	pushw	x
 273  008c 4b00          	push	#0
 274  008e ae6011        	ldw	x,#24593
 275  0091 cd0000        	call	_TIM1_OC3Init
 277  0094 5b07          	addw	sp,#7
 278                     ; 105   TIM1_CCPreloadControl(DISABLE);
 280  0096 4f            	clr	a
 281  0097 cd0000        	call	_TIM1_CCPreloadControl
 283                     ; 106 	TIM1_Cmd(ENABLE);
 285  009a a601          	ld	a,#1
 286  009c cd0000        	call	_TIM1_Cmd
 288                     ; 107 }
 291  009f 81            	ret
 348                     	switch	.const
 349  000e               L61:
 350  000e 0000c350      	dc.l	50000
 351                     ; 110 main()
 351                     ; 111 {
 352                     	switch	.text
 353  00a0               _main:
 355  00a0 5205          	subw	sp,#5
 356       00000005      OFST:	set	5
 359                     ; 112   unsigned int tem_c=0;
 361                     ; 113 	unsigned char step=0;
 363  00a2 0f03          	clr	(OFST-2,sp)
 365                     ; 114 	unsigned int outpwm=0;
 367                     ; 116 	for(tem_c=0;tem_c<50000;tem_c++);//上电延时，等待系统稳定
 369  00a4 5f            	clrw	x
 370  00a5 1f04          	ldw	(OFST-1,sp),x
 372  00a7               L101:
 376  00a7 1e04          	ldw	x,(OFST-1,sp)
 377  00a9 1c0001        	addw	x,#1
 378  00ac 1f04          	ldw	(OFST-1,sp),x
 382  00ae 9c            	rvf
 383  00af 1e04          	ldw	x,(OFST-1,sp)
 384  00b1 cd0000        	call	c_uitolx
 386  00b4 ae000e        	ldw	x,#L61
 387  00b7 cd0000        	call	c_lcmp
 389  00ba 2feb          	jrslt	L101
 390                     ; 118 	Clock_init(); //时钟配置
 392  00bc cd0001        	call	_Clock_init
 394                     ; 121 	PWM_IO_init();//开关管控制端口初始化
 396  00bf cd0006        	call	_PWM_IO_init
 398                     ; 122 	Tim1_init();//高级定时器配置	
 400  00c2 ad85          	call	_Tim1_init
 402                     ; 123 	outpwm=hArrPwmVal*PWMOUT/100;
 404  00c4 ae0096        	ldw	x,#150
 405  00c7 1f01          	ldw	(OFST-4,sp),x
 407                     ; 125     PWM_IO_init();//开关管控制端口初始化
 409  00c9 cd0006        	call	_PWM_IO_init
 411  00cc               L701:
 412                     ; 128 		for(tem_c=0;tem_c<6000;tem_c++);//延时时间
 414  00cc 5f            	clrw	x
 415  00cd 1f04          	ldw	(OFST-1,sp),x
 417  00cf               L311:
 421  00cf 1e04          	ldw	x,(OFST-1,sp)
 422  00d1 1c0001        	addw	x,#1
 423  00d4 1f04          	ldw	(OFST-1,sp),x
 427  00d6 1e04          	ldw	x,(OFST-1,sp)
 428  00d8 a31770        	cpw	x,#6000
 429  00db 25f2          	jrult	L311
 430                     ; 130 		step++;
 432  00dd 0c03          	inc	(OFST-2,sp)
 434                     ; 131 		if(step>=6)step=0;
 436  00df 7b03          	ld	a,(OFST-2,sp)
 437  00e1 a106          	cp	a,#6
 438  00e3 2502          	jrult	L121
 441  00e5 0f03          	clr	(OFST-2,sp)
 443  00e7               L121:
 444                     ; 132 		Commutation(step,outpwm);
 446  00e7 1e01          	ldw	x,(OFST-4,sp)
 447  00e9 89            	pushw	x
 448  00ea 7b05          	ld	a,(OFST+0,sp)
 449  00ec ad03          	call	_Commutation
 451  00ee 85            	popw	x
 453  00ef 20db          	jra	L701
 498                     ; 138 void Commutation(unsigned char bHallStartStep,unsigned int OutPwmValue)
 498                     ; 139 {	
 499                     	switch	.text
 500  00f1               _Commutation:
 502  00f1 88            	push	a
 503       00000000      OFST:	set	0
 506                     ; 140    TIM1->BKR &= (uint8_t)(~TIM1_BKR_MOE);//禁止PWM输出
 508  00f2 721f526d      	bres	21101,#7
 509                     ; 141 	if(bHallStartStep!=3&&bHallStartStep!=4)
 511  00f6 a103          	cp	a,#3
 512  00f8 2708          	jreq	L541
 514  00fa a104          	cp	a,#4
 515  00fc 2704          	jreq	L541
 516                     ; 142 	PWM_A_OFF;
 518  00fe 721a500a      	bset	20490,#5
 519  0102               L541:
 520                     ; 144 	if(bHallStartStep!=0&&bHallStartStep!=5)
 523  0102 0d01          	tnz	(OFST+1,sp)
 524  0104 270a          	jreq	L741
 526  0106 7b01          	ld	a,(OFST+1,sp)
 527  0108 a105          	cp	a,#5
 528  010a 2704          	jreq	L741
 529                     ; 145 	PWM_B_OFF;
 531  010c 7218500a      	bset	20490,#4
 532  0110               L741:
 533                     ; 147 	if(bHallStartStep!=1&&bHallStartStep!=2)
 536  0110 7b01          	ld	a,(OFST+1,sp)
 537  0112 a101          	cp	a,#1
 538  0114 270a          	jreq	L151
 540  0116 7b01          	ld	a,(OFST+1,sp)
 541  0118 a102          	cp	a,#2
 542  011a 2704          	jreq	L151
 543                     ; 148 	PWM_C_OFF;
 545  011c 7214500f      	bset	20495,#2
 546  0120               L151:
 547                     ; 152 	if(bHallStartStep==0)//AB
 550  0120 0d01          	tnz	(OFST+1,sp)
 551  0122 2610          	jrne	L351
 552                     ; 154 		TIM1->CCR3H = (uint8_t)(OutPwmValue >> 8);
 554  0124 7b04          	ld	a,(OFST+4,sp)
 555  0126 c75269        	ld	21097,a
 556                     ; 155     TIM1->CCR3L = (uint8_t)(OutPwmValue);
 558  0129 7b05          	ld	a,(OFST+5,sp)
 559  012b c7526a        	ld	21098,a
 560                     ; 156 		PWM_B_ON;
 562  012e 7219500a      	bres	20490,#4
 565  0132 206c          	jra	L551
 566  0134               L351:
 567                     ; 159   else if(bHallStartStep==1)	//AC
 569  0134 7b01          	ld	a,(OFST+1,sp)
 570  0136 a101          	cp	a,#1
 571  0138 2610          	jrne	L751
 572                     ; 161 		TIM1->CCR3H = (uint8_t)(OutPwmValue >> 8);
 574  013a 7b04          	ld	a,(OFST+4,sp)
 575  013c c75269        	ld	21097,a
 576                     ; 162     TIM1->CCR3L = (uint8_t)(OutPwmValue);
 578  013f 7b05          	ld	a,(OFST+5,sp)
 579  0141 c7526a        	ld	21098,a
 580                     ; 163 	  PWM_C_ON;
 582  0144 7215500f      	bres	20495,#2
 585  0148 2056          	jra	L551
 586  014a               L751:
 587                     ; 166 	else if(bHallStartStep==2)	//BC
 589  014a 7b01          	ld	a,(OFST+1,sp)
 590  014c a102          	cp	a,#2
 591  014e 2610          	jrne	L361
 592                     ; 168 		TIM1->CCR2H = (uint8_t)(OutPwmValue >> 8);
 594  0150 7b04          	ld	a,(OFST+4,sp)
 595  0152 c75267        	ld	21095,a
 596                     ; 169     TIM1->CCR2L = (uint8_t)(OutPwmValue);
 598  0155 7b05          	ld	a,(OFST+5,sp)
 599  0157 c75268        	ld	21096,a
 600                     ; 170 	  PWM_C_ON;
 602  015a 7215500f      	bres	20495,#2
 605  015e 2040          	jra	L551
 606  0160               L361:
 607                     ; 173 	else if(bHallStartStep==3)	//BA
 609  0160 7b01          	ld	a,(OFST+1,sp)
 610  0162 a103          	cp	a,#3
 611  0164 2610          	jrne	L761
 612                     ; 175 		TIM1->CCR2H = (uint8_t)(OutPwmValue >> 8);
 614  0166 7b04          	ld	a,(OFST+4,sp)
 615  0168 c75267        	ld	21095,a
 616                     ; 176     TIM1->CCR2L = (uint8_t)(OutPwmValue);
 618  016b 7b05          	ld	a,(OFST+5,sp)
 619  016d c75268        	ld	21096,a
 620                     ; 177 	  PWM_A_ON;
 622  0170 721b500a      	bres	20490,#5
 625  0174 202a          	jra	L551
 626  0176               L761:
 627                     ; 180 	else if(bHallStartStep==4)//CA
 629  0176 7b01          	ld	a,(OFST+1,sp)
 630  0178 a104          	cp	a,#4
 631  017a 2610          	jrne	L371
 632                     ; 182 		TIM1->CCR1H = (uint8_t)(OutPwmValue >> 8);
 634  017c 7b04          	ld	a,(OFST+4,sp)
 635  017e c75265        	ld	21093,a
 636                     ; 183     TIM1->CCR1L = (uint8_t)(OutPwmValue);
 638  0181 7b05          	ld	a,(OFST+5,sp)
 639  0183 c75266        	ld	21094,a
 640                     ; 184 	  PWM_A_ON;
 642  0186 721b500a      	bres	20490,#5
 645  018a 2014          	jra	L551
 646  018c               L371:
 647                     ; 187 	else if(bHallStartStep==5)	//CB
 649  018c 7b01          	ld	a,(OFST+1,sp)
 650  018e a105          	cp	a,#5
 651  0190 260e          	jrne	L551
 652                     ; 189 		TIM1->CCR1H = (uint8_t)(OutPwmValue >> 8);
 654  0192 7b04          	ld	a,(OFST+4,sp)
 655  0194 c75265        	ld	21093,a
 656                     ; 190     TIM1->CCR1L = (uint8_t)(OutPwmValue);
 658  0197 7b05          	ld	a,(OFST+5,sp)
 659  0199 c75266        	ld	21094,a
 660                     ; 191 	  PWM_B_ON;
 662  019c 7219500a      	bres	20490,#4
 664  01a0               L551:
 665                     ; 195 	TIM1->CCER1=PWM_EN1_TAB[bHallStartStep];
 667  01a0 7b01          	ld	a,(OFST+1,sp)
 668  01a2 5f            	clrw	x
 669  01a3 97            	ld	xl,a
 670  01a4 d60002        	ld	a,(_PWM_EN1_TAB,x)
 671  01a7 c7525c        	ld	21084,a
 672                     ; 196 	TIM1->CCER2=PWM_EN2_TAB[bHallStartStep];		
 674  01aa 7b01          	ld	a,(OFST+1,sp)
 675  01ac 5f            	clrw	x
 676  01ad 97            	ld	xl,a
 677  01ae d60008        	ld	a,(_PWM_EN2_TAB,x)
 678  01b1 c7525d        	ld	21085,a
 679                     ; 197 	TIM1->BKR|=TIM1_BKR_MOE;//使能PWM输出
 681  01b4 721e526d      	bset	21101,#7
 682                     ; 198 }
 685  01b8 84            	pop	a
 686  01b9 81            	ret
 730                     	xdef	_main
 731                     	xdef	_Tim1_init
 732                     	xdef	_PWM_IO_init
 733                     	xdef	_Clock_init
 734                     	xdef	_GPIO_int
 735                     	xdef	_Commutation
 736                     	xdef	_PWM_EN2_TAB
 737                     	xdef	_PWM_EN1_TAB
 738                     	xref	_TIM1_CCPreloadControl
 739                     	xref	_TIM1_Cmd
 740                     	xref	_TIM1_OC3Init
 741                     	xref	_TIM1_OC2Init
 742                     	xref	_TIM1_OC1Init
 743                     	xref	_TIM1_TimeBaseInit
 744                     	xref	_TIM1_DeInit
 745                     	xref	_GPIO_Init
 746                     	xref	_CLK_SYSCLKConfig
 765                     	xref	c_lcmp
 766                     	xref	c_uitolx
 767                     	end
