/*	IO DEFINITIONS FOR STLUX385A processor
 *	Copyright (c) 2015 by COSMIC Software
 */

/*	PORTS section
 */
/*	Port 0
 */
volatile char P0_ODR        @0x5000;	/* Data Output Latch reg */
volatile char P0_IDR        @0x5001;	/* Input Pin Value reg */
volatile char P0_DDR        @0x5002;	/* Data Direction */
volatile char P0_CR1        @0x5003;	/* Control register 1 */
volatile char P0_CR2        @0x5004;	/* Control register 2 */

/*	Port 1
 */
volatile char P1_ODR        @0x5005;	/* Data Output Latch reg */
volatile char P1_IDR        @0x5006;	/* Input Pin Value reg */
volatile char P1_DDR        @0x5007;	/* Data Direction */
volatile char P1_CR1        @0x5008;	/* Control register 1 */
volatile char P1_CR2        @0x5009;	/* Control register 2 */

/*	MISC section
 */
volatile char MSC_CFGP00    @0x5010;	/* P00 input line control */
volatile char MSC_CFGP01    @0x5011;	/* P01 input line control */
volatile char MSC_CFGP02    @0x5012;	/* P02 input line control */
volatile char MSC_CFGP03    @0x5013;	/* P03 input line control */
volatile char MSC_CFGP04    @0x5014;	/* P04 input line control */
volatile char MSC_CFGP05    @0x5015;	/* P05 input line control */
volatile char MSC_CFGP20    @0x5016;	/* P20 input line control */
volatile char MSC_CFGP21    @0x5017;	/* P21 input line control */
volatile char MSC_CFGP22    @0x5018;	/* P22 input line control */
volatile char MSC_CFGP23    @0x5019;	/* P23 input line control */
volatile char MSC_CFGP24    @0x501a;	/* P24 input line control */
volatile char MSC_CFGP25    @0x501b;	/* P25 input line control */
volatile char MSC_STSP0     @0x501c;	/* Port0 status control */
volatile char MSC_STSP2     @0x501d;	/* Port2 status control */
volatile char MSC_INPP2     @0x501e;	/* Port2 read */
volatile char MSC_DACCTR    @0x5020;	/* COMP4/DAC4 configuration */
volatile char MSC_DACIN0    @0x5021;	/* DAC0 input data */
volatile char MSC_DACIN1    @0x5022;	/* DAC1 input data */
volatile char MSC_DACIN2    @0x5023;	/* DAC2 input data */
volatile char MSC_DACIN3    @0x5024;	/* DAC3 input data */
volatile char MSC_SMDCFG01  @0x5025;	/* SMED 0-1 behaviour */
volatile char MSC_SMDCFG23  @0x5026;	/* SMED 2-3 behaviour */
volatile char MSC_SMDCFG45  @0x5027;	/* SMED 4-5 behaviour */
volatile char MSC_SMSWEV    @0x5028;	/* SMED software events */
volatile char MSC_SMUNLOCK  @0x5029;	/* SMED unlock */
volatile char MSC_CBOXS0    @0x502a;	/* SMED 0 connection matrix */

/*	FLASH section
 */
volatile char FLASH_CR1     @0x505a;	/* Flash Control Register 1 */
volatile char FLASH_CR2     @0x505b;	/* Flash Control Register 2 */
volatile char FLASH_nCR2    @0x505c;	/* Flash Control Register 2 comp. */
volatile char FLASH_FPR     @0x505d;	/* Flash memory protection */
volatile char FLASH_nFPR    @0x505e;	/* Flash memory protection comp. */
volatile char FLASH_IAPSR   @0x505f;	/* Flash in-appl Prog. Status reg */
volatile char FLASH_PUKR    @0x5062;	/* Flash memory unprotection reg */
volatile char FLASH_DUKR    @0x5064;	/* Data EEPROM unprotection reg */
volatile char FLASH_WAIT    @0x5064;	/* Flash wait-state register */

/*	RST section
 */
volatile char RST_SR        @0x50b3;	/* Reset Status register */

/*	CLOCK section
 */
volatile char CLK_SMD0      @0x50b4;	/* SMED 0 clock configuration */
volatile char CLK_SMD1      @0x50b5;	/* SMED 1 clock configuration */
volatile char CLK_SMD2      @0x50b6;	/* SMED 2 clock configuration */
volatile char CLK_SMD3      @0x50b7;	/* SMED 3 clock configuration */
volatile char CLK_SMD4      @0x50b8;	/* SMED 4 clock configuration */
volatile char CLK_SMD5      @0x50b9;	/* SMED 5 clock configuration */
volatile char CLK_PLLDIV    @0x50be;	/* PLL clock divisor */
volatile char CLK_AWUDIV    @0x50bf;	/* AWU clock divisor */
volatile char CLK_ICKCR     @0x50c0;	/* Internal Clock Control reg */
volatile char CLK_ECKCR     @0x50c1;	/* External Clock Control reg */
volatile char CLK_PLLR      @0x50c2;	/* PLL control register */
volatile char CLK_CMSR      @0x50c3;	/* Master Status reg */
volatile char CLK_SWR       @0x50c4;	/* Master Switch reg */
volatile char CLK_SWCR      @0x50c5;	/* Switch Control reg */
volatile char CLK_CKDIVR    @0x50c6;	/* Clock Dividers reg */
volatile char CLK_PCKENR1   @0x50c7;	/* Peripheral Clock Gating reg 1 */
volatile char CLK_CSSR      @0x50c8;	/* Security System register */
volatile char CLK_CCOR      @0x50c9;	/* Configurable Clock Ctrl reg */
volatile char CLK_PCKENR2   @0x50ca;	/* Peripheral Clock Gating reg 2 */
volatile char CLK_HSITRIMR  @0x50cb;	/* HSI Calibration Trimming reg */
volatile char CLK_SWIMCCR   @0x50cd;	/* SWIM clock division reg */
volatile char CLK_CCODIVR   @0x50ce;	/* CCO divider reg */
volatile char CLK_ADCR      @0x50cf;	/* ADC clock configuration reg */

/*	WATCHDOG section
 */
volatile char WWDG_CR       @0x50d1;	/* WWDG Control register */
volatile char WWDG_WR       @0x50d2;	/* WWDG Window register */
volatile char IWDG_KR       @0x50e0;	/* IWDG Key register */
volatile char IWDG_PR       @0x50e1;	/* IWDG Prescaler register */
volatile char IWDG_RLR      @0x50e2;	/* IWDG Reload register */

/*	AWU section
 */
volatile char AWU_CSR       @0x50f0;	/* AWU control status */
volatile char AWU_APR       @0x50f1;	/* AWU asynch. prescaler buffer */
volatile char AWU_TBR       @0x50f2;	/* AWU time base selection */

/*	I2C section
 */
volatile char I2C_CR1       @0x5210;	/* Control register 1 */
volatile char I2C_CR2       @0x5211;	/* Control register 2 */
volatile char I2C_FREQR     @0x5212;	/* Frequency register */
volatile char I2C_OARL      @0x5213;	/* Own Address reg low */
volatile char I2C_OARH      @0x5214;	/* Own Address reg high */
volatile char I2C_DR        @0x5216;	/* Data Register */
volatile char I2C_SR1       @0x5217;	/* Status Register 1 */
volatile char I2C_SR2       @0x5218;	/* Status Register 2 */
volatile char I2C_SR3       @0x5219;	/* Status Register 3 */
volatile char I2C_ITR       @0x521a;	/* Interrupt Control reg */
volatile char I2C_CCRL      @0x521b;	/* Clock Control reg low */
volatile char I2C_CCRH      @0x521c;	/* Clock Control reg high */
volatile char I2C_TRISER    @0x521d;	/* Trise reg */

/*	USART section
 */
volatile char USART_SR      @0x5230;	/* Status register */
volatile char USART_DR      @0x5231;	/* Data register */
volatile char USART_BRR1    @0x5232;	/* Baud Rate reg 1 */
volatile char USART_BRR2    @0x5233;	/* Baud Rate reg 2 */
volatile char USART_CR1     @0x5234;	/* Control register 1 */
volatile char USART_CR2     @0x5235;	/* Control register 2 */
volatile char USART_CR3     @0x5236;	/* Control register 3 */
volatile char USART_CR4     @0x5237;	/* Control register 4 */
volatile char USART_CR5     @0x5238;	/* Control register 5 */
volatile char USART_GTR     @0x5239;	/* Guard Time register */
volatile char USART_PSCR    @0x523a;	/* Prescaler register */

/*	SYSTEM TIMER section
 */
volatile char STMR_CR1      @0x5340;	/* Control register 1 */
volatile char STMR_IER      @0x5341;	/* Interrupt Enable reg */
volatile char STMR_SR1      @0x5342;	/* Status register 1 */
volatile char STMR_EGR      @0x5343;	/* Event Generation reg */
volatile char STMR_CNTH     @0x5344;	/* Counter reg High */
volatile char STMR_CNTL     @0x5345;	/* Counter reg Low */
volatile char STMR_PSCL     @0x5346;	/* Prescaler reg Low */
volatile char STMR_ARRH     @0x5347;	/* Auto-reload reg High */
volatile char STMR_ARRL     @0x5348;	/* Auto-reload reg Low */

/*	DALI section
 */
volatile char DALI_CLK_L    @0x53c0;	/* Data rate control low */
volatile char DALI_CLK_H    @0x53c1;	/* Data rate control high */
volatile char DALI_FB0      @0x53c2;	/* Forward Message 0 */
volatile char DALI_FB1      @0x53c3;	/* Forward Message 1 */
volatile char DALI_FB2      @0x53c4;	/* Forward Message 2 */
volatile char DALI_BD       @0x53c5;	/* Backward Message */
volatile char DALI_CR       @0x53c6;	/* Control register */
volatile char DALI_CSR      @0x53c7;	/* Control and Status register */
volatile char DALI_CSR1     @0x53c8;	/* Control and Status register 1 */
volatile char DALI_REVLN    @0x53c9;	/* Control reverse signal line */

/*	ADC section
 */
volatile char ADC_CFG       @0x5400;	/* Configuration reg */
volatile char ADC_SOC       @0x5401;	/* Start of conversion */
volatile char ADC_IER       @0x5402;	/* Interrupt enable */
volatile char ADC_SEQ       @0x5403;	/* Sequencer */
volatile char ADC_DATL_0    @0x5404;	/* Data reg 0 low */
volatile char ADC_DATH_0    @0x5405;	/* Data reg 0 high */
volatile char ADC_DATL_1    @0x5406;	/* Data reg 1 low */
volatile char ADC_DATH_1    @0x5407;	/* Data reg 1 high */
volatile char ADC_DATL_2    @0x5408;	/* Data reg 2 low */
volatile char ADC_DATH_2    @0x5409;	/* Data reg 2 high */
volatile char ADC_DATL_3    @0x540a;	/* Data reg 3 low */
volatile char ADC_DATH_3    @0x540b;	/* Data reg 3 high */
volatile char ADC_DATL_4    @0x540c;	/* Data reg 4 low */
volatile char ADC_DATH_4    @0x540d;	/* Data reg 4 high */
volatile char ADC_DATL_5    @0x540e;	/* Data reg 5 low */
volatile char ADC_DATH_5    @0x540f;	/* Data reg 5 high */
volatile char ADC_DATL_6    @0x5410;	/* Data reg 6 low */
volatile char ADC_DATH_6    @0x5411;	/* Data reg 6 high */
volatile char ADC_DATL_7    @0x5412;	/* Data reg 7 low */
volatile char ADC_DATH_7    @0x5413;	/* Data reg 7 high */
volatile char ADC_SR        @0x5414;	/* Status register */
volatile char ADC_DLYCNT    @0x5415;	/* SOC delay counter */

/*	SMED section
 */
volatile char SMD0_CTR      @0x5500;	/* SMED0 Control */
volatile char SMD0_CTR_TMR  @0x5501;	/* SMED0 Control time */
volatile char SMD0_CTR_INP  @0x5502;	/* SMED0 Control input */
volatile char SMD0_CTR_DTR  @0x5503;	/* SMED0 Dithering */
volatile char SMD0_CTR_T0L  @0x5504;	/* SMED0 Time T0 LSB */
volatile char SMD0_CTR_T0H  @0x5505;	/* SMED0 Time T0 MSB */
volatile char SMD0_CTR_T1L  @0x5506;	/* SMED0 Time T1 LSB */
volatile char SMD0_CTR_T1H  @0x5507;	/* SMED0 Time T1 MSB */
volatile char SMD0_CTR_T2L  @0x5508;	/* SMED0 Time T2 LSB */
volatile char SMD0_CTR_T2H  @0x5509;	/* SMED0 Time T2 MSB */
volatile char SMD0_CTR_T3L  @0x550a;	/* SMED0 Time T3 LSB */
volatile char SMD0_CTR_T3H  @0x550b;	/* SMED0 Time T3 MSB */
volatile char SMD0_CTR_ID0  @0x550c;	/* SMED0 IDLE State parameter 0 */
volatile char SMD0_CTR_ID1  @0x550d;	/* SMED0 IDLE State parameter 1 */
volatile char SMD0_CTR_ID2  @0x550e;	/* SMED0 IDLE State parameter 2 */
volatile char SMD0_CTR_S00  @0x550f;	/* SMED0 S0 State parameter 0 */
volatile char SMD0_CTR_S01  @0x5510;	/* SMED0 S0 State parameter 1 */
volatile char SMD0_CTR_S02  @0x5511;	/* SMED0 S0 State parameter 2 */
volatile char SMD0_CTR_S10  @0x5512;	/* SMED0 S1 State parameter 0 */
volatile char SMD0_CTR_S11  @0x5513;	/* SMED0 S1 State parameter 1 */
volatile char SMD0_CTR_S12  @0x5514;	/* SMED0 S1 State parameter 2 */
volatile char SMD0_CTR_S20  @0x5515;	/* SMED0 S2 State parameter 0 */
volatile char SMD0_CTR_S21  @0x5516;	/* SMED0 S2 State parameter 1 */
volatile char SMD0_CTR_S22  @0x5517;	/* SMED0 S2 State parameter 2 */
volatile char SMD0_CTR_S30  @0x5518;	/* SMED0 S3 State parameter 0 */
volatile char SMD0_CTR_S31  @0x5519;	/* SMED0 S3 State parameter 1 */
volatile char SMD0_CTR_S32  @0x551a;	/* SMED0 S3 State parameter 2 */
volatile char SMD0_CTR_CFG  @0x551b;	/* SMED0 Timer configuration */
volatile char SMD0_CTR_DMP_L @0x551c;	/* SMED0 Counter dump LSB */
volatile char SMD0_CTR_DMP_H @0x551d;	/* SMED0 Counter dump MSB */
volatile char SMD0_CTR_GSTS @0x551e;	/* SMED0 General status */
volatile char SMD0_CTR_IRQ  @0x551f;	/* SMED0 Interrupt request */
volatile char SMD0_CTR_IER  @0x5520;	/* SMED0 Interrupt enable */
volatile char SMD0_CTR_ISEL @0x5521;	/* SMED0 External event control */
volatile char SMD0_CTR_DMP  @0x5522;	/* SMED0 Dump enable */
volatile char SMD0_CTR_FSM_STS @0x5523;	/* SMED0 FSM core status */

volatile char SMD1_CTR      @0x5540;	/* SMED1 Control */
volatile char SMD1_CTR_TMR  @0x5541;	/* SMED1 Control time */
volatile char SMD1_CTR_INP  @0x5542;	/* SMED1 Control input */
volatile char SMD1_CTR_DTR  @0x5543;	/* SMED1 Dithering */
volatile char SMD1_CTR_T0L  @0x5544;	/* SMED1 Time T0 LSB */
volatile char SMD1_CTR_T0H  @0x5545;	/* SMED1 Time T0 MSB */
volatile char SMD1_CTR_T1L  @0x5546;	/* SMED1 Time T1 LSB */
volatile char SMD1_CTR_T1H  @0x5547;	/* SMED1 Time T1 MSB */
volatile char SMD1_CTR_T2L  @0x5548;	/* SMED1 Time T2 LSB */
volatile char SMD1_CTR_T2H  @0x5549;	/* SMED1 Time T2 MSB */
volatile char SMD1_CTR_T3L  @0x554a;	/* SMED1 Time T3 LSB */
volatile char SMD1_CTR_T3H  @0x554b;	/* SMED1 Time T3 MSB */
volatile char SMD1_CTR_ID0  @0x554c;	/* SMED1 IDLE State parameter 0 */
volatile char SMD1_CTR_ID1  @0x554d;	/* SMED1 IDLE State parameter 1 */
volatile char SMD1_CTR_ID2  @0x554e;	/* SMED1 IDLE State parameter 2 */
volatile char SMD1_CTR_S00  @0x554f;	/* SMED1 S0 State parameter 0 */
volatile char SMD1_CTR_S01  @0x5550;	/* SMED1 S0 State parameter 1 */
volatile char SMD1_CTR_S02  @0x5551;	/* SMED1 S0 State parameter 2 */
volatile char SMD1_CTR_S10  @0x5552;	/* SMED1 S1 State parameter 0 */
volatile char SMD1_CTR_S11  @0x5553;	/* SMED1 S1 State parameter 1 */
volatile char SMD1_CTR_S12  @0x5554;	/* SMED1 S1 State parameter 2 */
volatile char SMD1_CTR_S20  @0x5555;	/* SMED1 S2 State parameter 0 */
volatile char SMD1_CTR_S21  @0x5556;	/* SMED1 S2 State parameter 1 */
volatile char SMD1_CTR_S22  @0x5557;	/* SMED1 S2 State parameter 2 */
volatile char SMD1_CTR_S30  @0x5558;	/* SMED1 S3 State parameter 0 */
volatile char SMD1_CTR_S31  @0x5559;	/* SMED1 S3 State parameter 1 */
volatile char SMD1_CTR_S32  @0x555a;	/* SMED1 S3 State parameter 2 */
volatile char SMD1_CTR_CFG  @0x555b;	/* SMED1 Timer configuration */
volatile char SMD1_CTR_DMP_L @0x555c;	/* SMED1 Counter dump LSB */
volatile char SMD1_CTR_DMP_H @0x555d;	/* SMED1 Counter dump MSB */
volatile char SMD1_CTR_GSTS @0x555e;	/* SMED1 General status */
volatile char SMD1_CTR_IRQ  @0x555f;	/* SMED1 Interrupt request */
volatile char SMD1_CTR_IER  @0x5560;	/* SMED1 Interrupt enable */
volatile char SMD1_CTR_ISEL @0x5561;	/* SMED1 External event control */
volatile char SMD1_CTR_DMP  @0x5562;	/* SMED1 Dump enable */
volatile char SMD1_CTR_FSM_STS @0x5563;	/* SMED1 FSM core status */

volatile char SMD2_CTR      @0x5580;	/* SMED2 Control */
volatile char SMD2_CTR_TMR  @0x5581;	/* SMED2 Control time */
volatile char SMD2_CTR_INP  @0x5582;	/* SMED2 Control input */
volatile char SMD2_CTR_DTR  @0x5583;	/* SMED2 Dithering */
volatile char SMD2_CTR_T0L  @0x5584;	/* SMED2 Time T0 LSB */
volatile char SMD2_CTR_T0H  @0x5585;	/* SMED2 Time T0 MSB */
volatile char SMD2_CTR_T1L  @0x5586;	/* SMED2 Time T1 LSB */
volatile char SMD2_CTR_T1H  @0x5587;	/* SMED2 Time T1 MSB */
volatile char SMD2_CTR_T2L  @0x5588;	/* SMED2 Time T2 LSB */
volatile char SMD2_CTR_T2H  @0x5589;	/* SMED2 Time T2 MSB */
volatile char SMD2_CTR_T3L  @0x558a;	/* SMED2 Time T3 LSB */
volatile char SMD2_CTR_T3H  @0x558b;	/* SMED2 Time T3 MSB */
volatile char SMD2_CTR_ID0  @0x558c;	/* SMED2 IDLE State parameter 0 */
volatile char SMD2_CTR_ID1  @0x558d;	/* SMED2 IDLE State parameter 1 */
volatile char SMD2_CTR_ID2  @0x558e;	/* SMED2 IDLE State parameter 2 */
volatile char SMD2_CTR_S00  @0x558f;	/* SMED2 S0 State parameter 0 */
volatile char SMD2_CTR_S01  @0x5590;	/* SMED2 S0 State parameter 1 */
volatile char SMD2_CTR_S02  @0x5591;	/* SMED2 S0 State parameter 2 */
volatile char SMD2_CTR_S10  @0x5592;	/* SMED2 S1 State parameter 0 */
volatile char SMD2_CTR_S11  @0x5593;	/* SMED2 S1 State parameter 1 */
volatile char SMD2_CTR_S12  @0x5594;	/* SMED2 S1 State parameter 2 */
volatile char SMD2_CTR_S20  @0x5595;	/* SMED2 S2 State parameter 0 */
volatile char SMD2_CTR_S21  @0x5596;	/* SMED2 S2 State parameter 1 */
volatile char SMD2_CTR_S22  @0x5597;	/* SMED2 S2 State parameter 2 */
volatile char SMD2_CTR_S30  @0x5598;	/* SMED2 S3 State parameter 0 */
volatile char SMD2_CTR_S31  @0x5599;	/* SMED2 S3 State parameter 1 */
volatile char SMD2_CTR_S32  @0x559a;	/* SMED2 S3 State parameter 2 */
volatile char SMD2_CTR_CFG  @0x559b;	/* SMED2 Timer configuration */
volatile char SMD2_CTR_DMP_L @0x559c;	/* SMED2 Counter dump LSB */
volatile char SMD2_CTR_DMP_H @0x559d;	/* SMED2 Counter dump MSB */
volatile char SMD2_CTR_GSTS @0x559e;	/* SMED2 General status */
volatile char SMD2_CTR_IRQ  @0x559f;	/* SMED2 Interrupt request */
volatile char SMD2_CTR_IER  @0x55a0;	/* SMED2 Interrupt enable */
volatile char SMD2_CTR_ISEL @0x55a1;	/* SMED2 External event control */
volatile char SMD2_CTR_DMP  @0x55a2;	/* SMED2 Dump enable */
volatile char SMD2_CTR_FSM_STS @0x55a3;	/* SMED2 FSM core status */

volatile char SMD3_CTR      @0x55c0;	/* SMED3 Control */
volatile char SMD3_CTR_TMR  @0x55c1;	/* SMED3 Control time */
volatile char SMD3_CTR_INP  @0x55c2;	/* SMED3 Control input */
volatile char SMD3_CTR_DTR  @0x55c3;	/* SMED3 Dithering */
volatile char SMD3_CTR_T0L  @0x55c4;	/* SMED3 Time T0 LSB */
volatile char SMD3_CTR_T0H  @0x55c5;	/* SMED3 Time T0 MSB */
volatile char SMD3_CTR_T1L  @0x55c6;	/* SMED3 Time T1 LSB */
volatile char SMD3_CTR_T1H  @0x55c7;	/* SMED3 Time T1 MSB */
volatile char SMD3_CTR_T2L  @0x55c8;	/* SMED3 Time T2 LSB */
volatile char SMD3_CTR_T2H  @0x55c9;	/* SMED3 Time T2 MSB */
volatile char SMD3_CTR_T3L  @0x55ca;	/* SMED3 Time T3 LSB */
volatile char SMD3_CTR_T3H  @0x55cb;	/* SMED3 Time T3 MSB */
volatile char SMD3_CTR_ID0  @0x55cc;	/* SMED3 IDLE State parameter 0 */
volatile char SMD3_CTR_ID1  @0x55cd;	/* SMED3 IDLE State parameter 1 */
volatile char SMD3_CTR_ID2  @0x55ce;	/* SMED3 IDLE State parameter 2 */
volatile char SMD3_CTR_S00  @0x55cf;	/* SMED3 S0 State parameter 0 */
volatile char SMD3_CTR_S01  @0x55d0;	/* SMED3 S0 State parameter 1 */
volatile char SMD3_CTR_S02  @0x55d1;	/* SMED3 S0 State parameter 2 */
volatile char SMD3_CTR_S10  @0x55d2;	/* SMED3 S1 State parameter 0 */
volatile char SMD3_CTR_S11  @0x55d3;	/* SMED3 S1 State parameter 1 */
volatile char SMD3_CTR_S12  @0x55d4;	/* SMED3 S1 State parameter 2 */
volatile char SMD3_CTR_S20  @0x55d5;	/* SMED3 S2 State parameter 0 */
volatile char SMD3_CTR_S21  @0x55d6;	/* SMED3 S2 State parameter 1 */
volatile char SMD3_CTR_S22  @0x55d7;	/* SMED3 S2 State parameter 2 */
volatile char SMD3_CTR_S30  @0x55d8;	/* SMED3 S3 State parameter 0 */
volatile char SMD3_CTR_S31  @0x55d9;	/* SMED3 S3 State parameter 1 */
volatile char SMD3_CTR_S32  @0x55da;	/* SMED3 S3 State parameter 2 */
volatile char SMD3_CTR_CFG  @0x55db;	/* SMED3 Timer configuration */
volatile char SMD3_CTR_DMP_L @0x55dc;	/* SMED3 Counter dump LSB */
volatile char SMD3_CTR_DMP_H @0x55dd;	/* SMED3 Counter dump MSB */
volatile char SMD3_CTR_GSTS @0x55de;	/* SMED3 General status */
volatile char SMD3_CTR_IRQ  @0x55df;	/* SMED3 Interrupt request */
volatile char SMD3_CTR_IER  @0x55e0;	/* SMED3 Interrupt enable */
volatile char SMD3_CTR_ISEL @0x55e1;	/* SMED3 External event control */
volatile char SMD3_CTR_DMP  @0x55e2;	/* SMED3 Dump enable */
volatile char SMD3_CTR_FSM_STS @0x55e3;	/* SMED3 FSM core status */

volatile char SMD4_CTR      @0x5600;	/* SMED4 Control */
volatile char SMD4_CTR_TMR  @0x5601;	/* SMED4 Control time */
volatile char SMD4_CTR_INP  @0x5602;	/* SMED4 Control input */
volatile char SMD4_CTR_DTR  @0x5603;	/* SMED4 Dithering */
volatile char SMD4_CTR_T0L  @0x5604;	/* SMED4 Time T0 LSB */
volatile char SMD4_CTR_T0H  @0x5605;	/* SMED4 Time T0 MSB */
volatile char SMD4_CTR_T1L  @0x5606;	/* SMED4 Time T1 LSB */
volatile char SMD4_CTR_T1H  @0x5607;	/* SMED4 Time T1 MSB */
volatile char SMD4_CTR_T2L  @0x5608;	/* SMED4 Time T2 LSB */
volatile char SMD4_CTR_T2H  @0x5609;	/* SMED4 Time T2 MSB */
volatile char SMD4_CTR_T3L  @0x560a;	/* SMED4 Time T3 LSB */
volatile char SMD4_CTR_T3H  @0x560b;	/* SMED4 Time T3 MSB */
volatile char SMD4_CTR_ID0  @0x560c;	/* SMED4 IDLE State parameter 0 */
volatile char SMD4_CTR_ID1  @0x560d;	/* SMED4 IDLE State parameter 1 */
volatile char SMD4_CTR_ID2  @0x560e;	/* SMED4 IDLE State parameter 2 */
volatile char SMD4_CTR_S00  @0x560f;	/* SMED4 S0 State parameter 0 */
volatile char SMD4_CTR_S01  @0x5610;	/* SMED4 S0 State parameter 1 */
volatile char SMD4_CTR_S02  @0x5611;	/* SMED4 S0 State parameter 2 */
volatile char SMD4_CTR_S10  @0x5612;	/* SMED4 S1 State parameter 0 */
volatile char SMD4_CTR_S11  @0x5613;	/* SMED4 S1 State parameter 1 */
volatile char SMD4_CTR_S12  @0x5614;	/* SMED4 S1 State parameter 2 */
volatile char SMD4_CTR_S20  @0x5615;	/* SMED4 S2 State parameter 0 */
volatile char SMD4_CTR_S21  @0x5616;	/* SMED4 S2 State parameter 1 */
volatile char SMD4_CTR_S22  @0x5617;	/* SMED4 S2 State parameter 2 */
volatile char SMD4_CTR_S30  @0x5618;	/* SMED4 S3 State parameter 0 */
volatile char SMD4_CTR_S31  @0x5619;	/* SMED4 S3 State parameter 1 */
volatile char SMD4_CTR_S32  @0x561a;	/* SMED4 S3 State parameter 2 */
volatile char SMD4_CTR_CFG  @0x561b;	/* SMED4 Timer configuration */
volatile char SMD4_CTR_DMP_L @0x561c;	/* SMED4 Counter dump LSB */
volatile char SMD4_CTR_DMP_H @0x561d;	/* SMED4 Counter dump MSB */
volatile char SMD4_CTR_GSTS @0x561e;	/* SMED4 General status */
volatile char SMD4_CTR_IRQ  @0x561f;	/* SMED4 Interrupt request */
volatile char SMD4_CTR_IER  @0x5620;	/* SMED4 Interrupt enable */
volatile char SMD4_CTR_ISEL @0x5621;	/* SMED4 External event control */
volatile char SMD4_CTR_DMP  @0x5622;	/* SMED4 Dump enable */
volatile char SMD4_CTR_FSM_STS @0x5623;	/* SMED4 FSM core status */

volatile char SMD5_CTR      @0x5640;	/* SMED5 Control */
volatile char SMD5_CTR_TMR  @0x5641;	/* SMED5 Control time */
volatile char SMD5_CTR_INP  @0x5642;	/* SMED5 Control input */
volatile char SMD5_CTR_DTR  @0x5643;	/* SMED5 Dithering */
volatile char SMD5_CTR_T0L  @0x5644;	/* SMED5 Time T0 LSB */
volatile char SMD5_CTR_T0H  @0x5645;	/* SMED5 Time T0 MSB */
volatile char SMD5_CTR_T1L  @0x5646;	/* SMED5 Time T1 LSB */
volatile char SMD5_CTR_T1H  @0x5647;	/* SMED5 Time T1 MSB */
volatile char SMD5_CTR_T2L  @0x5648;	/* SMED5 Time T2 LSB */
volatile char SMD5_CTR_T2H  @0x5649;	/* SMED5 Time T2 MSB */
volatile char SMD5_CTR_T3L  @0x564a;	/* SMED5 Time T3 LSB */
volatile char SMD5_CTR_T3H  @0x564b;	/* SMED5 Time T3 MSB */
volatile char SMD5_CTR_ID0  @0x564c;	/* SMED5 IDLE State parameter 0 */
volatile char SMD5_CTR_ID1  @0x564d;	/* SMED5 IDLE State parameter 1 */
volatile char SMD5_CTR_ID2  @0x564e;	/* SMED5 IDLE State parameter 2 */
volatile char SMD5_CTR_S00  @0x564f;	/* SMED5 S0 State parameter 0 */
volatile char SMD5_CTR_S01  @0x5650;	/* SMED5 S0 State parameter 1 */
volatile char SMD5_CTR_S02  @0x5651;	/* SMED5 S0 State parameter 2 */
volatile char SMD5_CTR_S10  @0x5652;	/* SMED5 S1 State parameter 0 */
volatile char SMD5_CTR_S11  @0x5653;	/* SMED5 S1 State parameter 1 */
volatile char SMD5_CTR_S12  @0x5654;	/* SMED5 S1 State parameter 2 */
volatile char SMD5_CTR_S20  @0x5655;	/* SMED5 S2 State parameter 0 */
volatile char SMD5_CTR_S21  @0x5656;	/* SMED5 S2 State parameter 1 */
volatile char SMD5_CTR_S22  @0x5657;	/* SMED5 S2 State parameter 2 */
volatile char SMD5_CTR_S30  @0x5658;	/* SMED5 S3 State parameter 0 */
volatile char SMD5_CTR_S31  @0x5659;	/* SMED5 S3 State parameter 1 */
volatile char SMD5_CTR_S32  @0x565a;	/* SMED5 S3 State parameter 2 */
volatile char SMD5_CTR_CFG  @0x565b;	/* SMED5 Timer configuration */
volatile char SMD5_CTR_DMP_L @0x565c;	/* SMED5 Counter dump LSB */
volatile char SMD5_CTR_DMP_H @0x565d;	/* SMED5 Counter dump MSB */
volatile char SMD5_CTR_GSTS @0x565e;	/* SMED5 General status */
volatile char SMD5_CTR_IRQ  @0x565f;	/* SMED5 Interrupt request */
volatile char SMD5_CTR_IER  @0x5660;	/* SMED5 Interrupt enable */
volatile char SMD5_CTR_ISEL @0x5661;	/* SMED5 External event control */
volatile char SMD5_CTR_DMP  @0x5662;	/* SMED5 Dump enable */
volatile char SMD5_CTR_FSM_STS @0x5663;	/* SMED5 FSM core status */

volatile char SMD6_CTR      @0x5680;	/* SMED6 Control */
volatile char SMD6_CTR_TMR  @0x5681;	/* SMED6 Control time */
volatile char SMD6_CTR_INP  @0x5682;	/* SMED6 Control input */
volatile char SMD6_CTR_DTR  @0x5683;	/* SMED6 Dithering */
volatile char SMD6_CTR_T0L  @0x5684;	/* SMED6 Time T0 LSB */
volatile char SMD6_CTR_T0H  @0x5685;	/* SMED6 Time T0 MSB */
volatile char SMD6_CTR_T1L  @0x5686;	/* SMED6 Time T1 LSB */
volatile char SMD6_CTR_T1H  @0x5687;	/* SMED6 Time T1 MSB */
volatile char SMD6_CTR_T2L  @0x5688;	/* SMED6 Time T2 LSB */
volatile char SMD6_CTR_T2H  @0x5689;	/* SMED6 Time T2 MSB */
volatile char SMD6_CTR_T3L  @0x568a;	/* SMED6 Time T3 LSB */
volatile char SMD6_CTR_T3H  @0x568b;	/* SMED6 Time T3 MSB */
volatile char SMD6_CTR_ID0  @0x568c;	/* SMED6 IDLE State parameter 0 */
volatile char SMD6_CTR_ID1  @0x568d;	/* SMED6 IDLE State parameter 1 */
volatile char SMD6_CTR_ID2  @0x568e;	/* SMED6 IDLE State parameter 2 */
volatile char SMD6_CTR_S00  @0x568f;	/* SMED6 S0 State parameter 0 */
volatile char SMD6_CTR_S01  @0x5690;	/* SMED6 S0 State parameter 1 */
volatile char SMD6_CTR_S02  @0x5691;	/* SMED6 S0 State parameter 2 */
volatile char SMD6_CTR_S10  @0x5692;	/* SMED6 S1 State parameter 0 */
volatile char SMD6_CTR_S11  @0x5693;	/* SMED6 S1 State parameter 1 */
volatile char SMD6_CTR_S12  @0x5694;	/* SMED6 S1 State parameter 2 */
volatile char SMD6_CTR_S20  @0x5695;	/* SMED6 S2 State parameter 0 */
volatile char SMD6_CTR_S21  @0x5696;	/* SMED6 S2 State parameter 1 */
volatile char SMD6_CTR_S22  @0x5697;	/* SMED6 S2 State parameter 2 */
volatile char SMD6_CTR_S30  @0x5698;	/* SMED6 S3 State parameter 0 */
volatile char SMD6_CTR_S31  @0x5699;	/* SMED6 S3 State parameter 1 */
volatile char SMD6_CTR_S32  @0x569a;	/* SMED6 S3 State parameter 2 */
volatile char SMD6_CTR_CFG  @0x569b;	/* SMED6 Timer configuration */
volatile char SMD6_CTR_DMP_L @0x569c;	/* SMED6 Counter dump LSB */
volatile char SMD6_CTR_DMP_H @0x569d;	/* SMED6 Counter dump MSB */
volatile char SMD6_CTR_GSTS @0x569e;	/* SMED6 General status */
volatile char SMD6_CTR_IRQ  @0x569f;	/* SMED6 Interrupt request */
volatile char SMD6_CTR_IER  @0x56a0;	/* SMED6 Interrupt enable */
volatile char SMD6_CTR_ISEL @0x56a1;	/* SMED6 External event control */
volatile char SMD6_CTR_DMP  @0x56a2;	/* SMED6 Dump enable */
volatile char SMD6_CTR_FSM_STS @0x56a3;	/* SMED6 FSM core status */

volatile char SMD7_CTR      @0x56c0;	/* SMED7 Control */
volatile char SMD7_CTR_TMR  @0x56c1;	/* SMED7 Control time */
volatile char SMD7_CTR_INP  @0x56c2;	/* SMED7 Control input */
volatile char SMD7_CTR_DTR  @0x56c3;	/* SMED7 Dithering */
volatile char SMD7_CTR_T0L  @0x56c4;	/* SMED7 Time T0 LSB */
volatile char SMD7_CTR_T0H  @0x56c5;	/* SMED7 Time T0 MSB */
volatile char SMD7_CTR_T1L  @0x56c6;	/* SMED7 Time T1 LSB */
volatile char SMD7_CTR_T1H  @0x56c7;	/* SMED7 Time T1 MSB */
volatile char SMD7_CTR_T2L  @0x56c8;	/* SMED7 Time T2 LSB */
volatile char SMD7_CTR_T2H  @0x56c9;	/* SMED7 Time T2 MSB */
volatile char SMD7_CTR_T3L  @0x56ca;	/* SMED7 Time T3 LSB */
volatile char SMD7_CTR_T3H  @0x56cb;	/* SMED7 Time T3 MSB */
volatile char SMD7_CTR_ID0  @0x56cc;	/* SMED7 IDLE State parameter 0 */
volatile char SMD7_CTR_ID1  @0x56cd;	/* SMED7 IDLE State parameter 1 */
volatile char SMD7_CTR_ID2  @0x56ce;	/* SMED7 IDLE State parameter 2 */
volatile char SMD7_CTR_S00  @0x56cf;	/* SMED7 S0 State parameter 0 */
volatile char SMD7_CTR_S01  @0x56d0;	/* SMED7 S0 State parameter 1 */
volatile char SMD7_CTR_S02  @0x56d1;	/* SMED7 S0 State parameter 2 */
volatile char SMD7_CTR_S10  @0x56d2;	/* SMED7 S1 State parameter 0 */
volatile char SMD7_CTR_S11  @0x56d3;	/* SMED7 S1 State parameter 1 */
volatile char SMD7_CTR_S12  @0x56d4;	/* SMED7 S1 State parameter 2 */
volatile char SMD7_CTR_S20  @0x56d5;	/* SMED7 S2 State parameter 0 */
volatile char SMD7_CTR_S21  @0x56d6;	/* SMED7 S2 State parameter 1 */
volatile char SMD7_CTR_S22  @0x56d7;	/* SMED7 S2 State parameter 2 */
volatile char SMD7_CTR_S30  @0x56d8;	/* SMED7 S3 State parameter 0 */
volatile char SMD7_CTR_S31  @0x56d9;	/* SMED7 S3 State parameter 1 */
volatile char SMD7_CTR_S32  @0x56da;	/* SMED7 S3 State parameter 2 */
volatile char SMD7_CTR_CFG  @0x56db;	/* SMED7 Timer configuration */
volatile char SMD7_CTR_DMP_L @0x56dc;	/* SMED7 Counter dump LSB */
volatile char SMD7_CTR_DMP_H @0x56dd;	/* SMED7 Counter dump MSB */
volatile char SMD7_CTR_GSTS @0x56de;	/* SMED7 General status */
volatile char SMD7_CTR_IRQ  @0x56df;	/* SMED7 Interrupt request */
volatile char SMD7_CTR_IER  @0x56e0;	/* SMED7 Interrupt enable */
volatile char SMD7_CTR_ISEL @0x56e1;	/* SMED7 External event control */
volatile char SMD7_CTR_DMP  @0x56e2;	/* SMED7 Dump enable */
volatile char SMD7_CTR_FSM_STS @0x56e3;	/* SMED7 FSM core status */

/*	CFG section
 */
volatile char CFG_GCR       @0x7f60;	/* Global Configuration */

/*	ITC section
 */
volatile char ITC_SPR0      @0x7f70;	/* Interrupt SW Priority Reg 0 */
volatile char ITC_SPR1      @0x7f71;	/* Interrupt SW Priority Reg 1 */
volatile char ITC_SPR2      @0x7f72;	/* Interrupt SW Priority Reg 2 */
volatile char ITC_SPR3      @0x7f73;	/* Interrupt SW Priority Reg 3 */
volatile char ITC_SPR4      @0x7f74;	/* Interrupt SW Priority Reg 4 */
volatile char ITC_SPR5      @0x7f75;	/* Interrupt SW Priority Reg 5 */
volatile char ITC_SPR6      @0x7f76;	/* Interrupt SW Priority Reg 6 */
volatile char ITC_SPR7      @0x7f77;	/* Interrupt SW Priority Reg 7 */

/*	SWIM section
 */
volatile char SWIM_CSR      @0x7f80;	/* SWIM Control Status Register */

