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
  60                     ; 51 void GPIO_int(void)
  60                     ; 52 {
  62                     	switch	.text
  63  0000               _GPIO_int:
  67                     ; 54 	GPIO_Init(GPIOD, GPIO_PIN_7, GPIO_MODE_OUT_PP_HIGH_FAST);
  69  0000 4bf0          	push	#240
  70  0002 4b80          	push	#128
  71  0004 ae500f        	ldw	x,#20495
  72  0007 cd0000        	call	_GPIO_Init
  74  000a 85            	popw	x
  75                     ; 55 }
  78  000b 81            	ret
 102                     ; 58 void Clock_init(void)
 102                     ; 59 {
 103                     	switch	.text
 104  000c               _Clock_init:
 108                     ; 61   CLK_SYSCLKConfig(CLK_PRESCALER_HSIDIV1);
 110  000c 4f            	clr	a
 111  000d cd0000        	call	_CLK_SYSCLKConfig
 113                     ; 62 }
 116  0010 81            	ret
 140                     ; 65 void PWM_IO_init(void)
 140                     ; 66 {	
 141                     	switch	.text
 142  0011               _PWM_IO_init:
 146                     ; 68 	GPIO_Init(MCO0_PORT, MCO0_PIN,GPIO_MODE_OUT_PP_HIGH_FAST);
 148  0011 4bf0          	push	#240
 149  0013 4b04          	push	#4
 150  0015 ae500a        	ldw	x,#20490
 151  0018 cd0000        	call	_GPIO_Init
 153  001b 85            	popw	x
 154                     ; 69 	GPIO_Init(MCO2_PORT, MCO2_PIN,GPIO_MODE_OUT_PP_HIGH_FAST);
 156  001c 4bf0          	push	#240
 157  001e 4b02          	push	#2
 158  0020 ae500a        	ldw	x,#20490
 159  0023 cd0000        	call	_GPIO_Init
 161  0026 85            	popw	x
 162                     ; 70 	GPIO_Init(MCO4_PORT, MCO4_PIN,GPIO_MODE_OUT_PP_HIGH_FAST);
 164  0027 4bf0          	push	#240
 165  0029 4b20          	push	#32
 166  002b ae5014        	ldw	x,#20500
 167  002e cd0000        	call	_GPIO_Init
 169  0031 85            	popw	x
 170                     ; 73 	GPIO_Init(MCO1_PORT, MCO1_PIN,GPIO_MODE_OUT_PP_LOW_FAST);
 172  0032 4be0          	push	#224
 173  0034 4b08          	push	#8
 174  0036 ae500a        	ldw	x,#20490
 175  0039 cd0000        	call	_GPIO_Init
 177  003c 85            	popw	x
 178                     ; 74 	GPIO_Init(MCO3_PORT, MCO3_PIN,GPIO_MODE_OUT_PP_LOW_FAST);
 180  003d 4be0          	push	#224
 181  003f 4b80          	push	#128
 182  0041 ae500a        	ldw	x,#20490
 183  0044 cd0000        	call	_GPIO_Init
 185  0047 85            	popw	x
 186                     ; 75 	GPIO_Init(MCO5_PORT, MCO5_PIN,GPIO_MODE_OUT_PP_LOW_FAST);		
 188  0048 4be0          	push	#224
 189  004a 4b40          	push	#64
 190  004c ae500a        	ldw	x,#20490
 191  004f cd0000        	call	_GPIO_Init
 193  0052 85            	popw	x
 194                     ; 76 }
 197  0053 81            	ret
 228                     ; 79 void Tim1_init(void)
 228                     ; 80 {
 229                     	switch	.text
 230  0054               _Tim1_init:
 234                     ; 82   TIM1_DeInit();
 236  0054 cd0000        	call	_TIM1_DeInit
 238                     ; 84   TIM1_TimeBaseInit(0, TIM1_COUNTERMODE_UP, hArrPwmVal, 0);
 240  0057 4b00          	push	#0
 241  0059 ae03e8        	ldw	x,#1000
 242  005c 89            	pushw	x
 243  005d 4b00          	push	#0
 244  005f 5f            	clrw	x
 245  0060 cd0000        	call	_TIM1_TimeBaseInit
 247  0063 5b04          	addw	sp,#4
 248                     ; 86   TIM1_OC1Init(TIM1_OCMODE_PWM1, TIM1_OUTPUTSTATE_ENABLE, TIM1_OUTPUTNSTATE_DISABLE, hArrPwmVal*0, TIM1_OCPOLARITY_HIGH, TIM1_OCNPOLARITY_LOW, TIM1_OCIDLESTATE_RESET, TIM1_OCNIDLESTATE_SET); 
 250  0065 4b2a          	push	#42
 251  0067 4b00          	push	#0
 252  0069 4b88          	push	#136
 253  006b 4b00          	push	#0
 254  006d 5f            	clrw	x
 255  006e 89            	pushw	x
 256  006f 4b00          	push	#0
 257  0071 ae6011        	ldw	x,#24593
 258  0074 cd0000        	call	_TIM1_OC1Init
 260  0077 5b07          	addw	sp,#7
 261                     ; 88   TIM1_OC2Init(TIM1_OCMODE_PWM1, TIM1_OUTPUTSTATE_ENABLE, TIM1_OUTPUTNSTATE_DISABLE, hArrPwmVal*0, TIM1_OCPOLARITY_HIGH, TIM1_OCNPOLARITY_LOW, TIM1_OCIDLESTATE_RESET, TIM1_OCNIDLESTATE_SET); 
 263  0079 4b2a          	push	#42
 264  007b 4b00          	push	#0
 265  007d 4b88          	push	#136
 266  007f 4b00          	push	#0
 267  0081 5f            	clrw	x
 268  0082 89            	pushw	x
 269  0083 4b00          	push	#0
 270  0085 ae6011        	ldw	x,#24593
 271  0088 cd0000        	call	_TIM1_OC2Init
 273  008b 5b07          	addw	sp,#7
 274                     ; 90   TIM1_OC3Init(TIM1_OCMODE_PWM1, TIM1_OUTPUTSTATE_ENABLE, TIM1_OUTPUTNSTATE_DISABLE, hArrPwmVal*0, TIM1_OCPOLARITY_HIGH, TIM1_OCNPOLARITY_LOW, TIM1_OCIDLESTATE_RESET, TIM1_OCNIDLESTATE_SET); 
 276  008d 4b2a          	push	#42
 277  008f 4b00          	push	#0
 278  0091 4b88          	push	#136
 279  0093 4b00          	push	#0
 280  0095 5f            	clrw	x
 281  0096 89            	pushw	x
 282  0097 4b00          	push	#0
 283  0099 ae6011        	ldw	x,#24593
 284  009c cd0000        	call	_TIM1_OC3Init
 286  009f 5b07          	addw	sp,#7
 287                     ; 92   TIM1_CCPreloadControl(DISABLE);
 289  00a1 4f            	clr	a
 290  00a2 cd0000        	call	_TIM1_CCPreloadControl
 292                     ; 93 	TIM1_Cmd(ENABLE);
 294  00a5 a601          	ld	a,#1
 295  00a7 cd0000        	call	_TIM1_Cmd
 297                     ; 94 }
 300  00aa 81            	ret
 359                     	switch	.const
 360  000e               L61:
 361  000e 0000c350      	dc.l	50000
 362                     ; 97 main()
 362                     ; 98 {
 363                     	switch	.text
 364  00ab               _main:
 366  00ab 5205          	subw	sp,#5
 367       00000005      OFST:	set	5
 370                     ; 99   unsigned int tem_c=0;
 372                     ; 100 	unsigned char step=0;
 374  00ad 0f03          	clr	(OFST-2,sp)
 376                     ; 101 	unsigned int outpwm=0;
 378                     ; 103 	for(tem_c=0;tem_c<50000;tem_c++);//上电延时，等待系统稳定
 380  00af 5f            	clrw	x
 381  00b0 1f04          	ldw	(OFST-1,sp),x
 383  00b2               L101:
 387  00b2 1e04          	ldw	x,(OFST-1,sp)
 388  00b4 1c0001        	addw	x,#1
 389  00b7 1f04          	ldw	(OFST-1,sp),x
 393  00b9 9c            	rvf
 394  00ba 1e04          	ldw	x,(OFST-1,sp)
 395  00bc cd0000        	call	c_uitolx
 397  00bf ae000e        	ldw	x,#L61
 398  00c2 cd0000        	call	c_lcmp
 400  00c5 2feb          	jrslt	L101
 401                     ; 105 	Clock_init();//指示灯端口初始化
 403  00c7 cd000c        	call	_Clock_init
 405                     ; 106 	GPIO_int();//时钟配置
 407  00ca cd0000        	call	_GPIO_int
 409                     ; 108 	PWM_IO_init();//开关管控制端口初始化
 411  00cd cd0011        	call	_PWM_IO_init
 413                     ; 109 	Tim1_init();//高级定时器配置	
 415  00d0 ad82          	call	_Tim1_init
 417                     ; 110 	outpwm=hArrPwmVal*PWMOUT/100;
 419  00d2 ae0096        	ldw	x,#150
 420  00d5 1f01          	ldw	(OFST-4,sp),x
 422  00d7               L701:
 423                     ; 113 		for(tem_c=0;tem_c<6000;tem_c++);//延时时间
 425  00d7 5f            	clrw	x
 426  00d8 1f04          	ldw	(OFST-1,sp),x
 428  00da               L311:
 432  00da 1e04          	ldw	x,(OFST-1,sp)
 433  00dc 1c0001        	addw	x,#1
 434  00df 1f04          	ldw	(OFST-1,sp),x
 438  00e1 1e04          	ldw	x,(OFST-1,sp)
 439  00e3 a31770        	cpw	x,#6000
 440  00e6 25f2          	jrult	L311
 441                     ; 114 		GPIO_WriteReverse(GPIOD,GPIO_PIN_7);//PD7指示灯反转
 443  00e8 4b80          	push	#128
 444  00ea ae500f        	ldw	x,#20495
 445  00ed cd0000        	call	_GPIO_WriteReverse
 447  00f0 84            	pop	a
 448                     ; 115 		step++;
 450  00f1 0c03          	inc	(OFST-2,sp)
 452                     ; 116 		if(step>=6)step=0;
 454  00f3 7b03          	ld	a,(OFST-2,sp)
 455  00f5 a106          	cp	a,#6
 456  00f7 2502          	jrult	L121
 459  00f9 0f03          	clr	(OFST-2,sp)
 461  00fb               L121:
 462                     ; 117 		Commutation(step,outpwm);
 464  00fb 1e01          	ldw	x,(OFST-4,sp)
 465  00fd 89            	pushw	x
 466  00fe 7b05          	ld	a,(OFST+0,sp)
 467  0100 ad03          	call	_Commutation
 469  0102 85            	popw	x
 471  0103 20d2          	jra	L701
 516                     ; 123 void Commutation(unsigned char bHallStartStep,unsigned int OutPwmValue)
 516                     ; 124 {	
 517                     	switch	.text
 518  0105               _Commutation:
 520  0105 88            	push	a
 521       00000000      OFST:	set	0
 524                     ; 125    TIM1->BKR &= (uint8_t)(~TIM1_BKR_MOE);//禁止PWM输出
 526  0106 721f526d      	bres	21101,#7
 527                     ; 126 	if(bHallStartStep!=3&&bHallStartStep!=4)
 529  010a a103          	cp	a,#3
 530  010c 2708          	jreq	L541
 532  010e a104          	cp	a,#4
 533  0110 2704          	jreq	L541
 534                     ; 127 	PWM_A_OFF;
 536  0112 7214500a      	bset	20490,#2
 537  0116               L541:
 538                     ; 128 	if(bHallStartStep!=0&&bHallStartStep!=5)
 541  0116 0d01          	tnz	(OFST+1,sp)
 542  0118 270a          	jreq	L741
 544  011a 7b01          	ld	a,(OFST+1,sp)
 545  011c a105          	cp	a,#5
 546  011e 2704          	jreq	L741
 547                     ; 129 	PWM_B_OFF;
 549  0120 7212500a      	bset	20490,#1
 550  0124               L741:
 551                     ; 130 	if(bHallStartStep!=1&&bHallStartStep!=2)
 554  0124 7b01          	ld	a,(OFST+1,sp)
 555  0126 a101          	cp	a,#1
 556  0128 270a          	jreq	L151
 558  012a 7b01          	ld	a,(OFST+1,sp)
 559  012c a102          	cp	a,#2
 560  012e 2704          	jreq	L151
 561                     ; 131 	PWM_C_OFF;
 563  0130 721a5014      	bset	20500,#5
 564  0134               L151:
 565                     ; 134 	if(bHallStartStep==0)//AB
 568  0134 0d01          	tnz	(OFST+1,sp)
 569  0136 2610          	jrne	L351
 570                     ; 136 		TIM1->CCR3H = (uint8_t)(OutPwmValue >> 8);
 572  0138 7b04          	ld	a,(OFST+4,sp)
 573  013a c75269        	ld	21097,a
 574                     ; 137     TIM1->CCR3L = (uint8_t)(OutPwmValue);
 576  013d 7b05          	ld	a,(OFST+5,sp)
 577  013f c7526a        	ld	21098,a
 578                     ; 138 		PWM_B_ON;
 580  0142 7213500a      	bres	20490,#1
 583  0146 206c          	jra	L551
 584  0148               L351:
 585                     ; 140   else if(bHallStartStep==1)	//AC
 587  0148 7b01          	ld	a,(OFST+1,sp)
 588  014a a101          	cp	a,#1
 589  014c 2610          	jrne	L751
 590                     ; 142 		TIM1->CCR3H = (uint8_t)(OutPwmValue >> 8);
 592  014e 7b04          	ld	a,(OFST+4,sp)
 593  0150 c75269        	ld	21097,a
 594                     ; 143     TIM1->CCR3L = (uint8_t)(OutPwmValue);
 596  0153 7b05          	ld	a,(OFST+5,sp)
 597  0155 c7526a        	ld	21098,a
 598                     ; 144 	  PWM_C_ON;
 600  0158 721b5014      	bres	20500,#5
 603  015c 2056          	jra	L551
 604  015e               L751:
 605                     ; 146 	else if(bHallStartStep==2)	//BC
 607  015e 7b01          	ld	a,(OFST+1,sp)
 608  0160 a102          	cp	a,#2
 609  0162 2610          	jrne	L361
 610                     ; 148 		TIM1->CCR2H = (uint8_t)(OutPwmValue >> 8);
 612  0164 7b04          	ld	a,(OFST+4,sp)
 613  0166 c75267        	ld	21095,a
 614                     ; 149     TIM1->CCR2L = (uint8_t)(OutPwmValue);
 616  0169 7b05          	ld	a,(OFST+5,sp)
 617  016b c75268        	ld	21096,a
 618                     ; 150 	  PWM_C_ON;
 620  016e 721b5014      	bres	20500,#5
 623  0172 2040          	jra	L551
 624  0174               L361:
 625                     ; 152 	else if(bHallStartStep==3)	//BA
 627  0174 7b01          	ld	a,(OFST+1,sp)
 628  0176 a103          	cp	a,#3
 629  0178 2610          	jrne	L761
 630                     ; 154 		TIM1->CCR2H = (uint8_t)(OutPwmValue >> 8);
 632  017a 7b04          	ld	a,(OFST+4,sp)
 633  017c c75267        	ld	21095,a
 634                     ; 155     TIM1->CCR2L = (uint8_t)(OutPwmValue);
 636  017f 7b05          	ld	a,(OFST+5,sp)
 637  0181 c75268        	ld	21096,a
 638                     ; 156 	  PWM_A_ON;
 640  0184 7215500a      	bres	20490,#2
 643  0188 202a          	jra	L551
 644  018a               L761:
 645                     ; 158 	else if(bHallStartStep==4)//CA
 647  018a 7b01          	ld	a,(OFST+1,sp)
 648  018c a104          	cp	a,#4
 649  018e 2610          	jrne	L371
 650                     ; 160 		TIM1->CCR1H = (uint8_t)(OutPwmValue >> 8);
 652  0190 7b04          	ld	a,(OFST+4,sp)
 653  0192 c75265        	ld	21093,a
 654                     ; 161     TIM1->CCR1L = (uint8_t)(OutPwmValue);
 656  0195 7b05          	ld	a,(OFST+5,sp)
 657  0197 c75266        	ld	21094,a
 658                     ; 162 	  PWM_A_ON;
 660  019a 7215500a      	bres	20490,#2
 663  019e 2014          	jra	L551
 664  01a0               L371:
 665                     ; 164 	else if(bHallStartStep==5)	//CB
 667  01a0 7b01          	ld	a,(OFST+1,sp)
 668  01a2 a105          	cp	a,#5
 669  01a4 260e          	jrne	L551
 670                     ; 166 		TIM1->CCR1H = (uint8_t)(OutPwmValue >> 8);
 672  01a6 7b04          	ld	a,(OFST+4,sp)
 673  01a8 c75265        	ld	21093,a
 674                     ; 167     TIM1->CCR1L = (uint8_t)(OutPwmValue);
 676  01ab 7b05          	ld	a,(OFST+5,sp)
 677  01ad c75266        	ld	21094,a
 678                     ; 168 	  PWM_B_ON;
 680  01b0 7213500a      	bres	20490,#1
 682  01b4               L551:
 683                     ; 171 	TIM1->CCER1=PWM_EN1_TAB[bHallStartStep];
 685  01b4 7b01          	ld	a,(OFST+1,sp)
 686  01b6 5f            	clrw	x
 687  01b7 97            	ld	xl,a
 688  01b8 d60002        	ld	a,(_PWM_EN1_TAB,x)
 689  01bb c7525c        	ld	21084,a
 690                     ; 172 	TIM1->CCER2=PWM_EN2_TAB[bHallStartStep];		
 692  01be 7b01          	ld	a,(OFST+1,sp)
 693  01c0 5f            	clrw	x
 694  01c1 97            	ld	xl,a
 695  01c2 d60008        	ld	a,(_PWM_EN2_TAB,x)
 696  01c5 c7525d        	ld	21085,a
 697                     ; 173 	TIM1->BKR|=TIM1_BKR_MOE;//使能PWM输出
 699  01c8 721e526d      	bset	21101,#7
 700                     ; 174 }
 703  01cc 84            	pop	a
 704  01cd 81            	ret
 748                     	xdef	_main
 749                     	xdef	_Tim1_init
 750                     	xdef	_PWM_IO_init
 751                     	xdef	_Clock_init
 752                     	xdef	_GPIO_int
 753                     	xdef	_Commutation
 754                     	xdef	_PWM_EN2_TAB
 755                     	xdef	_PWM_EN1_TAB
 756                     	xref	_TIM1_CCPreloadControl
 757                     	xref	_TIM1_Cmd
 758                     	xref	_TIM1_OC3Init
 759                     	xref	_TIM1_OC2Init
 760                     	xref	_TIM1_OC1Init
 761                     	xref	_TIM1_TimeBaseInit
 762                     	xref	_TIM1_DeInit
 763                     	xref	_GPIO_WriteReverse
 764                     	xref	_GPIO_Init
 765                     	xref	_CLK_SYSCLKConfig
 784                     	xref	c_lcmp
 785                     	xref	c_uitolx
 786                     	end
