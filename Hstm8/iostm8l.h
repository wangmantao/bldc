/*	IO DEFINITIONS FOR STM8L15X family
 *	covers: STM8L151x4, STM8L151x6, STM8L152x4, STM8L152x6 families
 *	Copyright (c) 2010 by COSMIC Software
 */

/*	PORTS section
 */
/*	Port A
 */
volatile char PA_ODR        @0x5000;	/* Data Output Latch reg */
volatile char PA_IDR        @0x5001;	/* Input Pin Value reg */
volatile char PA_DDR        @0x5002;	/* Data Direction */
volatile char PA_CR1        @0x5003;	/* Control register 1 */
volatile char PA_CR2        @0x5004;	/* Control register 2 */

/*	Port B
 */
volatile char PB_ODR        @0x5005;	/* Data Output Latch reg */
volatile char PB_IDR        @0x5006;	/* Input Pin Value reg */
volatile char PB_DDR        @0x5007;	/* Data Direction */
volatile char PB_CR1        @0x5008;	/* Control register 1 */
volatile char PB_CR2        @0x5009;	/* Control register 2 */

/*	Port C
 */
volatile char PC_ODR        @0x500a;	/* Data Output Latch reg */
volatile char PC_IDR        @0x500b;	/* Input Pin Value reg */
volatile char PC_DDR        @0x500c;	/* Data Direction */
volatile char PC_CR1        @0x500d;	/* Control register 1 */
volatile char PC_CR2        @0x500e;	/* Control register 2 */

/*	Port D
 */
volatile char PD_ODR        @0x500f;	/* Data Output Latch reg */
volatile char PD_IDR        @0x5010;	/* Input Pin Value reg */
volatile char PD_DDR        @0x5011;	/* Data Direction */
volatile char PD_CR1        @0x5012;	/* Control register 1 */
volatile char PD_CR2        @0x5013;	/* Control register 2 */

/*	Port E
 */
volatile char PE_ODR        @0x5014;	/* Data Output Latch reg */
volatile char PE_IDR        @0x5015;	/* Input Pin Value reg */
volatile char PE_DDR        @0x5016;	/* Data Direction */
volatile char PE_CR1        @0x5017;	/* Control register 1 */
volatile char PE_CR2        @0x5018;	/* Control register 2 */

/*	Port F
 */
volatile char PF_ODR        @0x5019;	/* Data Output Latch reg */
volatile char PF_IDR        @0x501a;	/* Input Pin Value reg */
volatile char PF_DDR        @0x501b;	/* Data Direction */
volatile char PF_CR1        @0x501c;	/* Control register 1 */
volatile char PF_CR2        @0x501d;	/* Control register 2 */

/*	FLASH section
 */
volatile char FLASH_CR1     @0x5050;	/* Flash Control Register 1 */
volatile char FLASH_CR2     @0x5051;	/* Flash Control Register 2 */
volatile char FLASH_PUKR    @0x5052;	/* Flash Program memory unprotection reg */
volatile char FLASH_DUKR    @0x5053;	/* Data EEPROM unprotection reg */
volatile char FLASH_IAPSR   @0x5054;	/* Flash in-appl Prog. Status reg */

/*	DMA section
 */
volatile char DMA1_GCSR	    @0x5070;	/* global configuration & status register */
volatile char DMA1_GIR1	    @0x5071;	/* global interrupt register 1 */
volatile char DMA1_C0CR	    @0x5075;	/* channel 0 configuration register */
volatile char DMA1_C0SPR    @0x5076;	/* channel 0 status & priority register */
volatile char DMA1_C0NDTR   @0x5077;	/* number of data to transfer register (channel 0) */
volatile char DMA1_C0PARH   @0x5078;	/* peripheral address high register (channel 0) */
volatile char DMA1_C0PARL   @0x5079;	/* peripheral address low register (channel 0) */
volatile char DMA1_C0M0ARH  @0x507b;	/* memory 0 address high register (channel 0) */
volatile char DMA1_C0M0ARL  @0x507c;	/* memory 0 address low register (channel 0) */
volatile char DMA1_C1CR     @0x507f;	/* channel 1 configuration register */
volatile char DMA1_C1SPR    @0x5080;	/* channel 1 status & priority register */
volatile char DMA1_C1NDTR   @0x5081;	/* number of data to transfer register (channel 1) */
volatile char DMA1_C1PARH   @0x5082;	/* peripheral address high register (channel 1) */
volatile char DMA1_C1PARL   @0x5083;	/* peripheral address low register (channel 1) */
volatile char DMA1_C1M0ARH  @0x5085;	/* memory 0 address high register (channel 1) */
volatile char DMA1_C1M0ARL  @0x5086;	/* memory 0 address low register (channel 1) */
volatile char DMA1_C2CR     @0x5089;	/* channel 2 configuration register */
volatile char DMA1_C2SPR    @0x508a;	/* channel 2 status & priority register */
volatile char DMA1_C2NDTR   @0x508b;	/* number of data to transfer register (channel 2) */
volatile char DMA1_C2PARH   @0x508c;	/* peripheral address high register (channel 2) */
volatile char DMA1_C2PARL   @0x508d;	/* peripheral address low register (channel 2) */
volatile char DMA1_C2M0ARH  @0x508f;	/* memory 0 address high register (channel 2) */
volatile char DMA1_C2M0ARL  @0x5090;	/* memory 0 address low register (channel 2) */
volatile char DMA1_C3CR     @0x5093;	/* channel 3 configuration register */
volatile char DMA1_C3SPR    @0x5094;	/* channel 3 status & priority register */
volatile char DMA1_C3NDTR   @0x5095;	/* number of data to transfer register (channel 3) */
volatile char DMA1_C3PARH_C3M1ARH   @0x5096;	/* peripheral address high register (channel 3) */
volatile char DMA1_C3PARL_C3M1ARL   @0x5097;	/* peripheral address low register (channel 3) */
volatile char DMA1_C3M0ARH  @0x5099;	/* memory 0 address high register (channel 3) */
volatile char DMA1_C3M0ARL  @0x509a;	/* memory 0 address low register (channel 3) */

/*	REMAP section
 */
volatile char SYSCFG_RMPCR1 @0x509e;	/* Remapping register 1 */
volatile char SYSCFG_RMPCR2 @0x509f;	/* Remapping register 2 */

/*	External Interrupt Controller section
 */
volatile char EXTI_CR1      @0x50a0;	/* Ext Int Ctrl reg 1 */
volatile char EXTI_CR2      @0x50a1;	/* Ext Int Ctrl reg 2 */
volatile char EXTI_CR3      @0x50a2;	/* Ext Int Ctrl reg 3 */
volatile char EXTI_SR1      @0x50a3;	/* Ext Int Status reg 1 */
volatile char EXTI_SR2      @0x50a4;	/* Ext Int Status reg 2 */
volatile char EXTI_CONF     @0x50a5;	/* Ext Int Port Select reg 2 */

/*	WFE section
 */
volatile char WFE_CR1       @0x50a6;	/* Control reg 1 */
volatile char WFE_CR2       @0x50a7;	/* Control reg 2 */
volatile char WFE_CR3       @0x50a8;	/* Control reg 3 */

/*	RSTC section
 */
volatile char RST_CR        @0x50b0;	/* Reset Control register */
volatile char RST_SR        @0x50b1;	/* Reset Status register */

/*	POWER section
 */
volatile char PWR_CSR1      @0x50b2;	/* Power Control and Status reg 1 */
volatile char PWR_CSR2      @0x50b3;	/* Power Control and Status reg 2 */

/*	CLOCK section
 */
volatile char CLK_DIVR      @0x50c0;	/* Master Divider register */
volatile char CLK_CRTCR     @0x50c1;	/* RTC register */
volatile char CLK_ICKCR     @0x50c2;	/* Internal Clock Control reg */
volatile char CLK_PCKENR1   @0x50c3;	/* Peripheral Clock Gating reg 1 */
volatile char CLK_PCKENR2   @0x50c4;	/* Peripheral Clock Gating reg 2 */
volatile char CLK_CCOR      @0x50c5;	/* Configurable Clock Ctrl reg */
volatile char CLK_ECKCR     @0x50c6;	/* External Clock Control reg */
volatile char CLK_CMSR      @0x50c7;	/* Master Status reg */
volatile char CLK_SWR       @0x50c8;	/* Master Switch reg */
volatile char CLK_SWCR      @0x50c9;	/* Switch Control reg */
volatile char CLK_CSSR      @0x50ca;	/* Security System register */
volatile char CLK_CBEEPR    @0x50cb;	/* Clock BEEP reg */
volatile char CLK_HSICALR   @0x50cc;	/* HSI calibration reg */
volatile char CLK_HSITRIMR  @0x50cd;	/* HSI Calibration Trimming reg */
volatile char CLK_HSIUNLCKR @0x50ce;	/* HSI unlock register */
volatile char CLK_REGCSR    @0x50cf;	/* main regulator ctrl/status reg */

/*	WATCHDOG section
 */
volatile char WWDG_CR       @0x50d3;	/* WWDG Control register */
volatile char WWDG_WR       @0x50d4;	/* WWDG Window register */
volatile char IWDG_KR       @0x50e0;	/* IWDG Key register */
volatile char IWDG_PR       @0x50e1;	/* IWDG Prescaler register */
volatile char IWDG_RLR      @0x50e2;	/* IWDG Reload register */

/*	BEEP section
 */
volatile char BEEP_CSR1     @0x50f0;	/* BEEP Control/Status reg 1 */
volatile char BEEP_CSR2     @0x50f3;	/* BEEP control/status reg 2 */

/*	RTC section
 */
volatile char RTC_TR1       @0x5140;	/* Time register 1 */
volatile char RTC_TR2       @0x5141;	/* Time register 2 */
volatile char RTC_TR3       @0x5142;	/* Time register 3 */
volatile char RTC_DR1       @0x5144;	/* Date register 1 */
volatile char RTC_DR2       @0x5145;	/* Date register 2 */
volatile char RTC_DR3       @0x5146;	/* Date register 3 */
volatile char RTC_CR1       @0x5148;	/* Control register 1 */
volatile char RTC_CR2       @0x5149;	/* Control register 2 */
volatile char RTC_CR3       @0x514a;	/* Control register 3 */
volatile char RTC_ISR1      @0x514c;	/* Initialization and status register 1 */
volatile char RTC_ISR2      @0x514d;	/* Initialization and Status register 2 */
volatile char RTC_SPRERH    @0x5150;	/* Synchronous prescaler register high */
volatile char RTC_SPRERL    @0x5151;	/* Synchronous prescaler register low */
volatile char RTC_APRER     @0x5152;	/* Asynchronous prescaler register */
volatile char RTC_WUTRH     @0x5154;	/* Wakeup timer register high */
volatile char RTC_WUTRL     @0x5155;	/* Wakeup timer register low */
volatile char RTC_WPR       @0x5159;	/* Write protection register */
volatile char RTC_ALRMAR1   @0x515c;	/* Alarm A register 1 */
volatile char RTC_ALRMAR2   @0x515d;	/* Alarm A register 2 */
volatile char RTC_ALRMAR3   @0x515e;	/* Alarm A register 3 */
volatile char RTC_ALRMAR4   @0x515f;	/* Alarm A register 4 */

/*	SPI1 section
 */
volatile char SPI1_CR1      @0x5200;	/* SPI Control register 1 */
volatile char SPI1_CR2      @0x5201;	/* SPI Control register 2 */
volatile char SPI1_ICR      @0x5202;	/* SPI Interrupt/Ctrl reg */
volatile char SPI1_SR       @0x5203;	/* SPI Status register */
volatile char SPI1_DR       @0x5204;	/* SPI Data I/O reg */
volatile char SPI1_CRCPR    @0x5205;	/* SPI CRC Polynomial reg */
volatile char SPI1_RXCRCR   @0x5206;	/* SPI Rx CRC register */
volatile char SPI1_TXCRCR   @0x5207;	/* SPI Tx CRC register */

/*	I2C1 section
 */
volatile char I2C1_CR1      @0x5210;	/* Control register 1 */
volatile char I2C1_CR2      @0x5211;	/* Control register 2 */
volatile char I2C1_FREQR    @0x5212;	/* Frequency register */
volatile char I2C1_OARL     @0x5213;	/* Own Address reg low */
volatile char I2C1_OARH     @0x5214;	/* Own Address reg high */
volatile char I2C1_DR       @0x5216;	/* Data Register */
volatile char I2C1_SR1      @0x5217;	/* Status Register 1 */
volatile char I2C1_SR2      @0x5218;	/* Status Register 2 */
volatile char I2C1_SR3      @0x5219;	/* Status Register 3 */
volatile char I2C1_ITR      @0x521a;	/* Interrupt Control reg */
volatile char I2C1_CCRL     @0x521b;	/* Clock Control reg low */
volatile char I2C1_CCRH     @0x521c;	/* Clock Control reg high */
volatile char I2C1_TRISER   @0x521d;	/* Trise reg */
volatile char I2C1_PECR     @0x521e;	/* Packet Error Checking reg */

/*	USART 1 section
 */
volatile char USART1_SR     @0x5230;	/* Status register */
volatile char USART1_DR     @0x5231;	/* Data register */
volatile char USART1_BRR1   @0x5232;	/* Baud Rate reg 1 */
volatile char USART1_BRR2   @0x5233;	/* Baud Rate reg 2 */
volatile char USART1_CR1    @0x5234;	/* Control register 1 */
volatile char USART1_CR2    @0x5235;	/* Control register 2 */
volatile char USART1_CR3    @0x5236;	/* Control register 3 */
volatile char USART1_CR4    @0x5237;	/* Control register 4 */
volatile char USART1_CR5    @0x5238;	/* Control register 5 */
volatile char USART1_GTR    @0x5239;	/* Guard Time register */
volatile char USART1_PSCR   @0x523a;	/* Prescaler register */

/*	TIMER 2 section
 */
volatile char TIM2_CR1      @0x5250;	/* Control register 1 */
volatile char TIM2_CR2      @0x5251;	/* Control register 2 */
volatile char TIM2_SMCR     @0x5252;	/* Slave Mode Control reg */
volatile char TIM2_ETR      @0x5253;	/* External Trigger reg */
volatile char TIM2_DER      @0x5254;	/* DMA1 request enable reg */
volatile char TIM2_IER      @0x5255;	/* Interrupt Enable reg */
volatile char TIM2_SR1      @0x5256;	/* Status register 1 */
volatile char TIM2_SR2      @0x5257;	/* Status register 2 */
volatile char TIM2_EGR      @0x5258;	/* Event Generation reg */
volatile char TIM2_CCMR1    @0x5259;	/* Capture/Compare Mode reg 1 */
volatile char TIM2_CCMR2    @0x525a;	/* Capture/Compare Mode reg 2 */
volatile char TIM2_CCER1    @0x525b;	/* Capture/Compare Enable reg 1 */
volatile char TIM2_CNTRH    @0x525c;	/* Counter reg High */
volatile char TIM2_CNTRL    @0x525d;	/* Counter reg Low */
volatile char TIM2_PSCR     @0x525e;	/* Prescaler reg High */
volatile char TIM2_ARRH     @0x525f;	/* Auto-reload reg High */
volatile char TIM2_ARRL     @0x5260;	/* Auto-reload reg Low */
volatile char TIM2_CCR1H    @0x5261;	/* Capture/Compare reg 1 High */
volatile char TIM2_CCR1L    @0x5262;	/* Capture/Compare reg 1 Low */
volatile char TIM2_CCR2H    @0x5263;	/* Capture/Compare reg 2 High */
volatile char TIM2_CCR2L    @0x5264;	/* Capture/Compare reg 2 Low */
volatile char TIM2_BKR      @0x5265;	/* Break register */
volatile char TIM2_OISR     @0x5266;	/* Output Idle State reg */

/*	TIMER 3 section
 */
volatile char TIM3_CR1      @0x5280;	/* Control register 1 */
volatile char TIM3_CR2      @0x5281;	/* Control register 2 */
volatile char TIM3_SMCR     @0x5282;	/* Slave Mode Control reg */
volatile char TIM3_ETR      @0x5283;	/* External Trigger reg */
volatile char TIM3_DER      @0x5284;	/* DMA1 request enable reg */
volatile char TIM3_IER      @0x5285;	/* Interrupt Enable reg */
volatile char TIM3_SR1      @0x5286;	/* Status register 1 */
volatile char TIM3_SR2      @0x5287;	/* Status register 2 */
volatile char TIM3_EGR      @0x5288;	/* Event Generation reg */
volatile char TIM3_CCMR1    @0x5289;	/* Capture/Compare Mode reg 1 */
volatile char TIM3_CCMR2    @0x528a;	/* Capture/Compare Mode reg 2 */
volatile char TIM3_CCER1    @0x528b;	/* Capture/Compare Enable reg 1 */
volatile char TIM3_CNTRH    @0x528c;	/* Counter reg High */
volatile char TIM3_CNTRL    @0x528d;	/* Counter reg Low */
volatile char TIM3_PSCR     @0x528e;	/* Prescaler reg High */
volatile char TIM3_ARRH     @0x528f;	/* Auto-reload reg High */
volatile char TIM3_ARRL     @0x5290;	/* Auto-reload reg Low */
volatile char TIM3_CCR1H    @0x5291;	/* Capture/Compare reg 1 High */
volatile char TIM3_CCR1L    @0x5292;	/* Capture/Compare reg 1 Low */
volatile char TIM3_CCR2H    @0x5293;	/* Capture/Compare reg 2 High */
volatile char TIM3_CCR2L    @0x5294;	/* Capture/Compare reg 2 Low */
volatile char TIM3_BKR      @0x5295;	/* Break register */
volatile char TIM3_OISR     @0x5296;	/* Output Idle State reg */

/*	TIMER 1 section
 */
volatile char TIM1_CR1      @0x52b0;	/* Control register 1 */
volatile char TIM1_CR2      @0x52b1;	/* Control register 2 */
volatile char TIM1_SMCR     @0x52b2;	/* Slave Mode Control reg */
volatile char TIM1_ETR      @0x52b3;	/* External Trigger reg */
volatile char TIM1_DER      @0x52b4;	/* DMA1 request enable reg */
volatile char TIM1_IER      @0x52b5;	/* Interrupt Enable reg */
volatile char TIM1_SR1      @0x52b6;	/* Status register 1 */
volatile char TIM1_SR2      @0x52b7;	/* Status register 2 */
volatile char TIM1_EGR      @0x52b8;	/* Event Generation reg */
volatile char TIM1_CCMR1    @0x52b9;	/* Capture/Compare Mode reg 1 */
volatile char TIM1_CCMR2    @0x52ba;	/* Capture/Compare Mode reg 2 */
volatile char TIM1_CCMR3    @0x52bb;	/* Capture/Compare Mode reg 3 */
volatile char TIM1_CCMR4    @0x52bc;	/* Capture/Compare Mode reg 4 */
volatile char TIM1_CCER1    @0x52bd;	/* Capture/Compare Enable reg 1 */
volatile char TIM1_CCER2    @0x52be;	/* Capture/Compare Enable reg 2 */
volatile char TIM1_CNTRH    @0x52bf;	/* Counter reg High */
volatile char TIM1_CNTRL    @0x52c0;	/* Counter reg Low */
volatile char TIM1_PSCRH    @0x52c1;	/* Prescaler reg High */
volatile char TIM1_PSCRL    @0x52c2;	/* Prescaler reg Low */
volatile char TIM1_ARRH     @0x52c3;	/* Auto-reload reg High */
volatile char TIM1_ARRL     @0x52c4;	/* Auto-reload reg Low */
volatile char TIM1_RCR      @0x52c5;	/* Repetition Counter reg */
volatile char TIM1_CCR1H    @0x52c6;	/* Capture/Compare reg 1 High */
volatile char TIM1_CCR1L    @0x52c7;	/* Capture/Compare reg 1 Low */
volatile char TIM1_CCR2H    @0x52c8;	/* Capture/Compare reg 2 High */
volatile char TIM1_CCR2L    @0x52c9;	/* Capture/Compare reg 2 Low */
volatile char TIM1_CCR3H    @0x52ca;	/* Capture/Compare reg 3 High */
volatile char TIM1_CCR3L    @0x52cb;	/* Capture/Compare reg 3 Low */
volatile char TIM1_CCR4H    @0x52cc;	/* Capture/Compare reg 4 High */
volatile char TIM1_CCR4L    @0x52cd;	/* Capture/Compare reg 4 Low */
volatile char TIM1_BKR      @0x52ce;	/* Break register */
volatile char TIM1_DTR      @0x52cf;	/* Dead Time register */
volatile char TIM1_OISR     @0x52d0;	/* Output Idle State reg */
volatile char TIM1_DCR1     @0x52d1;	/* DMA1 control register reg 1 */
volatile char TIM1_DCR2     @0x52d2;	/* DMA1 control register reg 2 */
volatile char TIM1_DMA1R    @0x52d3;	/* DMA1 address for burst mode */

/*	TIMER 4 section
 */
volatile char TIM4_CR1      @0x52e0;	/* Control register 1 */
volatile char TIM4_CR2      @0x52e1;	/* Control register 2 */
volatile char TIM4_SMCR     @0x52e2;	/* Slave Mode Control reg */
volatile char TIM4_DER      @0x52e3;	/* DMA1 request enable reg */
volatile char TIM4_IER      @0x52e4;	/* Interrupt enable reg */
volatile char TIM4_SR1      @0x52e5;	/* Status register 1 */
volatile char TIM4_EGR      @0x52e6;	/* Event Generation reg */
volatile char TIM4_CNTR     @0x52e7;	/* Counter register */
volatile char TIM4_PSCR     @0x52e8;	/* Prescaler register */
volatile char TIM4_ARR      @0x52e9;	/* Auto-reload register */

/*	IRTIM section
 */
volatile char IR_CR         @0x52ff;	/* Infra-red control register */

/*	ADC1 section
 */
volatile char ADC1_CR1      @0x5340;	/* Configuration reg 1 */
volatile char ADC1_CR2      @0x5341;	/* Configuration reg 2 */
volatile char ADC1_CR3      @0x5342;	/* Configuration reg 3 */
volatile char ADC1_SR       @0x5343;	/* Status register */
volatile char ADC1_DRH      @0x5344;	/* Data reg high */
volatile char ADC1_DRL      @0x5345;	/* Data reg low */
volatile char ADC1_HTRH     @0x5346;	/* High threshold register high */
volatile char ADC1_HTRL     @0x5347;	/* High threshold register low */
volatile char ADC1_LTRH     @0x5348;	/* Low threshold register high */
volatile char ADC1_LTRL     @0x5349;	/* Low threshold register low */
volatile char ADC1_SQR1     @0x534a;	/* Channel sequence 1 reg */
volatile char ADC1_SQR2     @0x534b;	/* Channel sequence 2 reg */
volatile char ADC1_SQR3     @0x534c;	/* Channel sequence 3 reg */
volatile char ADC1_SQR4     @0x534d;	/* Channel sequence 4 reg */
volatile char ADC1_TRIGR1   @0x534e;	/* Trigger disable 1 */
volatile char ADC1_TRIGR2   @0x534f;	/* Trigger disable 2 */
volatile char ADC1_TRIGR3   @0x5350;	/* Trigger disable 3 */
volatile char ADC1_TRIGR4   @0x5351;	/* Trigger disable 4 */

/*	DAC section
 */
volatile char DAC_CR1       @0x5380;	/* DAC control register 1 */
volatile char DAC_CR2       @0x5381;	/* DAC control register 2 */
volatile char DAC_SWTRIGR   @0x5384;	/* DAC software trigger register */
volatile char DAC_SR        @0x5385;	/* DAC status register */
volatile char DAC_RDHRH     @0x5388;	/* DAC right aligned data holding register high */
volatile char DAC_RDHRL     @0x5389;	/* DAC right aligned data holding register low */
volatile char DAC_LDHRH     @0x538c;	/* DAC left aligned data holding register high */
volatile char DAC_LDHRL     @0x538d;	/* DAC left aligned data holding register low */
volatile char DAC_DHR8      @0x5390;	/* DAC 8-bit data holding register */
volatile char DAC_DORH      @0x53ac;	/* DAC data output register high */
volatile char DAC_DORL      @0x53ad;	/* DAC data output register low */

/*	LCD section
 */
volatile char LCD_CR1       @0x5400;	/* LCD control register 1 */
volatile char LCD_CR2       @0x5401;	/* LCD control register 2 */
volatile char LCD_CR3       @0x5402;	/* LCD control register 3 */
volatile char LCD_FRQ       @0x5403;	/* LCD frequency selection register */
volatile char LCD_PM0       @0x5404;	/* LCD Port mask register 0 */
volatile char LCD_PM1       @0x5405;	/* LCD Port mask register 1 */
volatile char LCD_PM2       @0x5406;	/* LCD Port mask register 2 */
volatile char LCD_PM3       @0x5407;	/* LCD Port mask register 3 */
volatile char LCD_RAM0      @0x540c;	/* LCD display memory 0 */
volatile char LCD_RAM1      @0x540d;	/* LCD display memory 1 */
volatile char LCD_RAM2      @0x540e;	/* LCD display memory 2 */
volatile char LCD_RAM3      @0x540f;	/* LCD display memory 3 */
volatile char LCD_RAM4      @0x5410;	/* LCD display memory 4 */
volatile char LCD_RAM5      @0x5411;	/* LCD display memory 5 */
volatile char LCD_RAM6      @0x5412;	/* LCD display memory 6 */
volatile char LCD_RAM7      @0x5413;	/* LCD display memory 7 */
volatile char LCD_RAM8      @0x5414;	/* LCD display memory 8 */
volatile char LCD_RAM9      @0x5415;	/* LCD display memory 9 */
volatile char LCD_RAM10     @0x5416;	/* LCD display memory 10 */
volatile char LCD_RAM11     @0x5417;	/* LCD display memory 11 */
volatile char LCD_RAM12     @0x5418;	/* LCD display memory 12 */
volatile char LCD_RAM13     @0x5419;	/* LCD display memory 13 */

/*	RI section
 */
volatile char RI_ICR1       @0x5431;	/* Timer input capture routing register 1 */
volatile char RI_ICR2       @0x5432;	/* Timer input capture routing register 2 */
volatile char RI_IOIR1      @0x5433;	/* I/O input register 1 */
volatile char RI_IOIR2      @0x5434;	/* I/O input register 2 */
volatile char RI_IOIR3      @0x5435;	/* I/O input register 3 */
volatile char RI_IOCMR1     @0x5436;	/* I/O control mode register 1 */
volatile char RI_IOCMR2     @0x5437;	/* I/O control mode register 2 */
volatile char RI_IOCMR3     @0x5438;	/* I/O control mode register 3 */
volatile char RI_IOSR1      @0x5439;	/* I/O switch register 1 */
volatile char RI_IOSR2      @0x543a;	/* I/O switch register 2 */
volatile char RI_IOSR3      @0x543b;	/* I/O switch register 3 */
volatile char RI_ASCR1      @0x543d;	/* Analog switch register 1 */
volatile char RI_ASCR2      @0x543e;	/* Analog switch register 2 */
volatile char RI_RCR        @0x543f;	/* Resistor control register 1 */
volatile char COMP_CSR1     @0x5440;	/* Comparator control and status register 1 */
volatile char COMP_CSR2     @0x5441;	/* Comparator control and status register 2 */
volatile char COMP_CSR3     @0x5442;	/* Comparator control and status register 3 */
volatile char COMP_CSR4     @0x5443;	/* Comparator control and status register 4 */
volatile char COMP_CSR5     @0x5444;	/* Comparator control and status register 5 */

/*	CFG section
 */
volatile char CFG_GCR       @0x7f60;	/* Global Configuration register */

/*	ITC section
 */
volatile char ITC_SPR1      @0x7f70;	/* Interrupt Software Priority Reg 1 */
volatile char ITC_SPR2      @0x7f71;	/* Interrupt Software Priority Reg 2 */
volatile char ITC_SPR3      @0x7f72;	/* Interrupt Software Priority Reg 3 */
volatile char ITC_SPR4      @0x7f73;	/* Interrupt Software Priority Reg 4 */
volatile char ITC_SPR5      @0x7f74;	/* Interrupt Software Priority Reg 5 */
volatile char ITC_SPR6      @0x7f75;	/* Interrupt Software Priority Reg 6 */
volatile char ITC_SPR7      @0x7f76;	/* Interrupt Software Priority Reg 7 */
volatile char ITC_SPR8      @0x7f77;	/* Interrupt Software Priority Reg 8 */

/*	SWIM section
 */
volatile char SWIM_CSR      @0x7f80;	/* SWIM Control Status Register */

/*	In-Circuit Debugging section
 */                                            
volatile char DM_BK1RE      @0x7f90;	/* IC Debugging Breakpoint 1 ESB Reg */
volatile char DM_BK1RH      @0x7f91;	/* IC Debugging Breakpoint 1 High */
volatile char DM_BK1RL      @0x7f92;	/* IC Debugging Breakpoint 1 Low */
volatile char DM_BK2RE      @0x7f93;	/* IC Debugging Breakpoint 2 ESB Reg */
volatile char DM_BK2RH      @0x7f94;	/* IC Debugging Breakpoint 2 High */
volatile char DM_BK2RL      @0x7f95;	/* IC Debugging Breakpoint 2 Low */
volatile char DM_CR1        @0x7f96;	/* IC Debugging Control register 1 */
volatile char DM_CR2        @0x7f97;	/* IC Debugging Control register 2 */
volatile char DM_CSR1       @0x7f98;	/* IC Debugging Control/Status reg 1 */
volatile char DM_CSR2       @0x7f99;	/* IC Debugging Control/Status reg 2 */
volatile char DM_ENFCTR     @0x7f9a;	/* IC Debugging Function Enable Reg 2 */
