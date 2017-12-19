/*	IO DEFINITIONS FOR STM8
 *	Copyright (c) 2006 by COSMIC Software
 */

/*	PORTS section
 */
volatile char PA_DR         @0x00;	/* Port A Data Output Latch Register */
volatile char PA_PR         @0x01;	/* Port A Input Pin Value Register */
volatile char PA_DDR        @0x02;	/* Port A Data Direction */
volatile char PA_OR         @0x03;	/* Port A Option register */
volatile char PA_CR         @0x04;	/* Port A Configuration Register */
volatile char PB_DR         @0x05;	/* Port B Data Output Latch Register */
volatile char PB_PR         @0x06;	/* Port B input pin value Register */
volatile char PB_DDR        @0x07;	/* Port B Data Direction */
volatile char PB_OR         @0x08;	/* Port B Option register */
volatile char PB_CR         @0x09;	/* Port B Configuration Register */
volatile char PC_DR         @0x0a;	/* Port C Data Output Latch Register */
volatile char PC_PR         @0x0b;	/* Port C input pin value Register */
volatile char PC_DDR        @0x0c;	/* Port C Data Direction */
volatile char PC_OR         @0x0d;	/* Port C Option register */
volatile char PC_CR         @0x0e;	/* Port C Configuration Register */
volatile char PD_DR         @0x0f;	/* Port D Data Output Latch Register */
volatile char PD_PR         @0x10;	/* Port D input pin value Register */
volatile char PD_DDR        @0x11;	/* Port D Data Direction */
volatile char PD_OR         @0x12;	/* Port D Option register */
volatile char PD_CR         @0x13;	/* Port D Configuration Register */
volatile char PE_DR         @0x14;	/* Port E Data Output Latch Register */
volatile char PE_PR         @0x15;	/* Port E input pin value Register */
volatile char PE_DDR        @0x16;	/* Port E Data Direction */
volatile char PE_OR         @0x17;	/* Port E Option register */
volatile char PE_CR         @0x18;	/* Port E Configuration Register */
volatile char PF_DR         @0x19;	/* Port F Data Output Latch Register */
volatile char PF_PR         @0x1a;	/* Port F input pin value Register */
volatile char PF_DDR        @0x1b;	/* Port F Data Direction */
volatile char PF_OR         @0x1c;	/* Port F Option register */
volatile char PF_CR         @0x1d;	/* Port F Configuration Register */

/*	FLASH section
 */   
volatile char FLASH_CR1     @0x4856;	/* Flash Control Register 1 */
volatile char FLASH_CR2     @0x4857;	/* Flash Control Register 2 */
volatile char FLASH_NCR2    @0x4858;	/* Flash Complementary Control Reg 2 */
volatile char FLASH_IAPSR   @0x4859;	/* Flash in-appl Prog. Status Reg */
volatile char FLASH_FSTPPR  @0x485a;	/* Flash First Page Protected Reg */
volatile char FLASH_NFSTPPR @0x485b;	/* Flash Compl. 1.st Page Prot. Reg */

/*	In-Circuit Debugging section 
 */                                            
volatile char ICE_CR1       @0x4870;	/* IC Debugging Control Register 1 */
volatile char ICE_SR1       @0x4871;	/* IC Debugging Status Register  1 */
volatile char ICE_BK1ER     @0x4872;	/* IC Debugging Breakpoint 1 ESB Reg */
volatile char ICE_BK1RH     @0x4873;	/* IC Debugging Breakpoint 1 High */
volatile char ICE_BK1RL     @0x4874;	/* IC Debugging Breakpoint 1 Low */
volatile char ICE_BK2ER     @0x4875;	/* IC Debugging Breakpoint 2 ESB Reg */
volatile char ICE_BK2RH     @0x4876;	/* IC Debugging Breakpoint 2 High */
volatile char ICE_BK2RL     @0x4877;	/* IC Debugging Breakpoint 2 Low */
volatile char ICE_CR2       @0x4878;	/* IC Debugging Control Register 2 */
volatile char ICE_SR2       @0x4879;	/* IC Debugging Status Register  2 */
volatile char ICE_FER       @0x487a;	/* IC Debugging Function Enable Reg 2 */

/*	SWIM section
 */
volatile char SWIM_CSR      @0x4880;	/* SWIM Control Status Register */
volatile char SWIM_DR       @0x4881;	/* SWIM Data Register */

/*	ITC section
 */
volatile char ITC_SPR0      @0x4890;	/* Interrupt Software Priority Reg 0 */
volatile char ITC_SPR1      @0x4891;	/* Interrupt Software Priority Reg 1 */
volatile char ITC_SPR2      @0x4892;	/* Interrupt Software Priority Reg 2 */
volatile char ITC_SPR3      @0x4893;	/* Interrupt Software Priority Reg 3 */
volatile char ITC_SPR4      @0x4894;	/* Interrupt Software Priority Reg 4 */
volatile char ITC_SPR5      @0x4895;	/* Interrupt Software Priority Reg 5 */
volatile char ITC_SPR6      @0x4896;	/* Interrupt Software Priority Reg 6 */
volatile char ITC_SPR7      @0x4897;	/* Interrupt Software Priority Reg 7 */
volatile char ITC_EICR0     @0x48a0;	/* External Interrupt Control Reg 0 */
volatile char ITC_EICR1     @0x48a1;	/* External Interrupt Control Reg 1 */
volatile char ITC_PAIFR     @0x48a4;	/* Port A Interrupt Flag Register */
volatile char ITC_PBIFR     @0x48a5;	/* Port B Interrupt Flag Register */
volatile char ITC_PCIFR     @0x48a6;	/* Port C Interrupt Flag Register */
volatile char ITC_PDIFR     @0x48a7;	/* Port D Interrupt Flag Register */
volatile char ITC_PEIFR     @0x48a8;	/* Port E Interrupt Flag Register */
volatile char ITC_PFIFR     @0x48a9;	/* Port F Interrupt Flag Register */

/*	RESET section
 */
volatile char RST_CR1       @0x48b0;	/* Reset Control Register 1 */
volatile char RST_CR2       @0x48b1;	/* Reset Control Register 2 */
volatile char RST_NCR2      @0x48b2;	/* Reset Complementary Control Reg 2 */
volatile char RST_SR        @0x48b3;	/* Reset Status Register 1 */

/*	CLOCK section
 */
volatile char CLK_ICKR      @0x48c0;	/* Internal Clock Control Register */
volatile char CLK_ECKR      @0x48c1;	/* External Clock Control Register */
volatile char CLK_CMSR      @0x48c3;	/* Clock Master Status Register */
volatile char CLK_SWR       @0x48c4;	/* Clock Master Switch Register */
volatile char CLK_SWCR      @0x48c5;	/* Clock Switch Control Register */
volatile char CLK_CKDIVR    @0x48c6;	/* Clock Divider Register */
volatile char CLK_PCKENR    @0x48c7;	/* Peripheral Clock Gating Register */
volatile char CLK_CSSR      @0x48c8;	/* Clock Security System Register */
volatile char CLK_CCOR      @0x48c9;	/* Configurable Clock Control Reg */
volatile char CLK_HSESTR    @0x48ca;	/* HSE Clock Startup Time Register */
volatile char CLK_LSESTR    @0x48cb;	/* LSE Clock Startup Time Register */
volatile char CLK_HSICALR   @0x48cc;	/* HSI Clock Calibration Register */
volatile char CLK_NHSICALR  @0x48cd;	/* Complementary HSI Clock Cal. Reg */
volatile char CLK_HSITRIMR  @0x48ce;	/* HSI Clock Calibration Trimming Reg */

/*	WATCHDOG section
 */
volatile char WWDG_CR       @0x48d0;	/* WWDG Control Register */     
volatile char WWDG_WR       @0x48d1;	/* WWDG Window Register */ 
volatile char IWDG_KR       @0x48e0;	/* IWDG Key Register */     
volatile char IWDG_PR       @0x48e1;	/* IWDG Prescaler Register */ 
volatile char IWDG_RR       @0x48e2;	/* IWDG Reload Register */ 

/*	RTCAWU section
 */
volatile char RTCAWU_CSR1   @0x48f0;	/* RTCAWU Control/Status Register 1 */
volatile char RTCAWU_APR    @0x48f1;	/* RTCAWU Async Prescale Buffer Reg */
volatile char RTCAWU_TBR    @0x48f2;	/* RTCAWU Timebase selection Register */
volatile char RTCAWU_CSR2   @0x48f3;	/* RTCAWU Control/Status Register 2 */

/*	SPI section
 */
volatile char SPI_CR1       @0x4a00;	/* SPI Control Register 1 */
volatile char SPI_CR2       @0x4a01;	/* SPI Control Register 2 */
volatile char SPI_ICR       @0x4a02;	/* SPI Interrupt Control Register */
volatile char SPI_SR        @0x4a03;	/* SPI Status Register */
volatile char SPI_DR        @0x4a04;	/* SPI Data Register */
volatile char SPI_CRCPR     @0x4a05;	/* SPI CRC Polynomial Register */
volatile char SPI_RXCRCR    @0x4a06;	/* SPI Rx CRC Register */
volatile char SPI_TXCRCR    @0x4a07;	/* SPI Tx CRC Register */

/*	I2C section
 */
volatile char I2C_CR1       @0x4a10;	/* I2C Control Register 1 */
volatile char I2C_CR2       @0x4a11;	/* I2C Control Register 2 */
volatile char I2C_FREQR     @0x4a12;	/* I2C Frequency Register */
volatile char I2C_OARL      @0x4a13;	/* I2C Own Address Register Low */
volatile char I2C_OARH      @0x4a14;	/* I2C Own Address Register High */
volatile char I2C_DR        @0x4a16;	/* I2C Data Register */
volatile char I2C_SR1       @0x4a17;	/* I2C Status Register 1 */
volatile char I2C_SR2       @0x4a18;	/* I2C Status Register 2 */
volatile char I2C_SR3       @0x4a19;	/* I2C Status Register 3 */
volatile char I2C_CCRL      @0x4a21;	/* I2C Clock Control Register Low */
volatile char I2C_CCRH      @0x4a22;	/* I2C Clock Control Register High */
volatile char I2C_TRISER    @0x4a23;	/* I2C Triser Register */

/*	USART section
 */
volatile char USART_SR      @0x4a30;	/* USART Status Register */
volatile char USART_DR      @0x4a31;	/* USART Data Register */
volatile char USART_BRR1    @0x4a32;	/* USART Baud Rate Register 1 */
volatile char USART_BRR2    @0x4a33;	/* USART Baud Rate Register 2 */
volatile char USART_CR1     @0x4a34;	/* USART Control Register 1 */
volatile char USART_CR2     @0x4a35;	/* USART Control Register 2 */
volatile char USART_CR3     @0x4a36;	/* USART Control Register 3 */
volatile char USART_CR4     @0x4a37;	/* USART Control Register 4 */
volatile char USART_CR5     @0x4a38;	/* USART Control Register 5 */
volatile char USART_GTR     @0x4a39;	/* USART Guard Time Register */
volatile char USART_PSCR    @0x4a3a;	/* USART Prescaler Register */

/*	TIMER 1 section
 */
volatile char TIM1_CR1      @0x4b00;	/* Control Register 1 */
volatile char TIM1_CR2      @0x4b01;	/* Control Register 2 */
volatile char TIM1_SMCR     @0x4b02;	/* Slave Mode Control Register */
volatile char TIM1_ETR      @0x4b03;	/* External Trigger Register */
volatile char TIM1_IER      @0x4b04;	/* Interrupt Enable Register */
volatile char TIM1_SR1      @0x4b05;	/* Status Register 1 */
volatile char TIM1_SR2      @0x4b06;	/* Status Register 2 */
volatile char TIM1_EGR      @0x4b07;	/* Event Generation Register */
volatile char TIM1_CCMR1    @0x4b08;	/* Capture/Compare Mode Register 1 */
volatile char TIM1_CCMR2    @0x4b09;	/* Capture/Compare Mode Register 2 */
volatile char TIM1_CCMR3    @0x4b0a;	/* Capture/Compare Mode Register 3 */
volatile char TIM1_CCER1    @0x4b0b;	/* Capture/Compare Enable Register 1 */
volatile char TIM1_CCER2    @0x4b0c;	/* Capture/Compare Enable Register 2 */
volatile char TIM1_CNTRH    @0x4b0d;	/* Counter Register High */
volatile char TIM1_CNTRL    @0x4b0e;	/* Counter Register Low */
volatile char TIM1_PSCR     @0x4b0f;	/* Prescaler Register */
volatile char TIM1_ARRH     @0x4b10;	/* Auto-reload Register High */
volatile char TIM1_ARRL     @0x4b11;	/* Auto-reload Register Low */
volatile char TIM1_CCR1H    @0x4b12;	/* Capture/Compare Register 1 High */
volatile char TIM1_CCR1L    @0x4b13;	/* Capture/Compare Register 1 Low */
volatile char TIM1_CCR2H    @0x4b14;	/* Capture/Compare Register 2 High */
volatile char TIM1_CCR2L    @0x4b15;	/* Capture/Compare Register 2 Low */
volatile char TIM1_CCR3H    @0x4b16;	/* Capture/Compare Register 3 High */
volatile char TIM1_CCR3L    @0x4b17;	/* Capture/Compare Register 3 Low */
volatile char TIM1_BKR      @0x4b18;	/* Break Register */
volatile char TIM1_OISR     @0x4b19;	/* Output Idle State Register */

/*	TIMER 2 section
 */
volatile char TIM2_CR1      @0x4b20;	/* Control Register 1 */
volatile char TIM2_CR2      @0x4b21;	/* Control Register 2 */
volatile char TIM2_SMCR     @0x4b22;	/* Slave Mode Control Register */
volatile char TIM2_IER      @0x4b23;	/* Interrupt Enable Register */
volatile char TIM2_SR1      @0x4b24;	/* Status Register 1 */
volatile char TIM2_SR2      @0x4b25;	/* Status Register 2 */
volatile char TIM2_EGR      @0x4b26;	/* Event Generation Register */
volatile char TIM2_CCMR1    @0x4b27;	/* Capture/Compare Mode Register 1 */
volatile char TIM2_CCER1    @0x4b28;	/* Capture/Compare Enable Register 1 */
volatile char TIM2_CNTRH    @0x4b29;	/* Counter Register High */
volatile char TIM2_CNTRL    @0x4b2a;	/* Counter Register Low */
volatile char TIM2_PSCR     @0x4b2b;	/* Prescaler Register */
volatile char TIM2_ARRH     @0x4b2c;	/* Auto-reload Register High */
volatile char TIM2_ARRL     @0x4b2d;	/* Auto-reload Register Low */
volatile char TIM2_CCR1H    @0x4b2e;	/* Capture/Compare Register 1 High */
volatile char TIM2_CCR1L    @0x4b2f;	/* Capture/Compare Register 1 Low */

/*	TIMER 3 section
 */
volatile char TIM3_CR       @0x4b40;	/* Control Register */
volatile char TIM3_IER      @0x4b41;	/* Interrupt Enable Register */
volatile char TIM3_SR       @0x4b42;	/* Status Register */
volatile char TIM3_EGR      @0x4b43;	/* Event Generation Register */
volatile char TIM3_CNTRH    @0x4b44;	/* Counter Register High */
volatile char TIM3_CNTRL    @0x4b45;	/* Counter Register Low */
volatile char TIM3_PSCR     @0x4b46;	/* Prescaler Register */
volatile char TIM3_ARR      @0x4b47;	/* Auto-reload Register */

/*	ADC section
 */
volatile char ADC_CSR       @0x4c00;	/* Control/Status Register */
volatile char ADC_CR1       @0x4c01;	/* Configuration Register 1 */
volatile char ADC_CR2       @0x4c02;	/* Configuration Register 2 */
volatile char ADC_CR3       @0x4c03;	/* Configuration Register 3 */
volatile char ADC_DRH       @0x4c04;	/* Data Register High */  
volatile char ADC_DRL       @0x4c05;	/* Data Register Low */
volatile char ADC_TDRH      @0x4c06;	/* Schmitt Trigger Disable Reg High */  
volatile char ADC_TDRL      @0x4c07;	/* Schmitt Trigger Disable Reg Low */

/*	TSENS section
 */
volatile char TSENS_CR      @0x4c10;	/* Temperature Sensor Control Reg */  

