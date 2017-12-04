/* MAIN.C file
ժҪ??
1.PD7?ʱ??ת??ָʾϵͳ?????
2.??磬??ָ??PWM????ʱ?????ʵ????????ת?????
2013.5.8
 */
#include "stm8s.h"

#define STM8_FREQ_MHZ 16
#define PWM_FREQUENCY 16000

static const u16 hArrPwmVal = ((u16)((STM8_FREQ_MHZ * (u32)1000000)/PWM_FREQUENCY));
//PWM?????

#define PWMOUT 15
//??15%ռ?ձ??

const unsigned char PWM_EN1_TAB[6]={0x00,0x00,0x10,0x10,0x01,0x01};
//?????????CH1\CH2ͨ???????ʹ???
const unsigned char PWM_EN2_TAB[6]={0x01,0x01,0x00,0x00,0x00,0x00};
//?????????CH3ͨ???????ʹ???

//???ۿ??ؿ?ƶ˿ڶ??
#define MCO1_PORT GPIOC
#define MCO1_PIN	GPIO_PIN_3
#define MCO3_PORT GPIOC
#define MCO3_PIN	GPIO_PIN_7
#define MCO5_PORT GPIOC
#define MCO5_PIN	GPIO_PIN_6
 //???ۿ??ؿ?ƶ˿ڶ??
#define MCO0_PORT GPIOC
#define MCO0_PIN	GPIO_PIN_2     // 用PC5替换PC2
#define MCO2_PORT GPIOC
#define MCO2_PIN	GPIO_PIN_1     // 用PC4替换PC1
#define MCO4_PORT GPIOE
#define MCO4_PIN	GPIO_PIN_5
//???۵͵?????عܵ?ͨ
#define PWM_A_OFF MCO0_PORT->ODR |= (u8)MCO0_PIN; 
#define PWM_B_OFF MCO2_PORT->ODR |= (u8)MCO2_PIN; 
#define PWM_C_OFF MCO4_PORT->ODR |= (u8)MCO4_PIN; 

#define PWM_A_ON MCO0_PORT->ODR &= (u8)(~MCO0_PIN); 
#define PWM_B_ON MCO2_PORT->ODR &= (u8)(~MCO2_PIN); 
#define PWM_C_ON MCO4_PORT->ODR &= (u8)(~MCO4_PIN); 

//?????????
void Commutation(unsigned char bHallStartStep,unsigned int OutPwmValue);

//??ʼ????????ָʾ?ƶ˿?
void GPIO_int(void)
{
	 /* LEDs */
	GPIO_Init(GPIOD, GPIO_PIN_5, GPIO_MODE_OUT_PP_HIGH_FAST);
}

//ϵͳʱ????????16M
void Clock_init(void)
{
	/* Select fCPU = 16MHz */
  CLK_SYSCLKConfig(CLK_PRESCALER_HSIDIV1);
}

//?????????ع?O??ʼ??
void PWM_IO_init(void)
{	
  //PB012 ?????Ч ,??Ϊ?ߵ??
	GPIO_Init(MCO0_PORT, MCO0_PIN,GPIO_MODE_OUT_PP_HIGH_FAST);
	GPIO_Init(MCO2_PORT, MCO2_PIN,GPIO_MODE_OUT_PP_HIGH_FAST);
	GPIO_Init(MCO4_PORT, MCO4_PIN,GPIO_MODE_OUT_PP_HIGH_FAST);
	
	//PC123 ?????Ч,??Ϊ?͵??	
	GPIO_Init(MCO1_PORT, MCO1_PIN,GPIO_MODE_OUT_PP_LOW_FAST);
	GPIO_Init(MCO3_PORT, MCO3_PIN,GPIO_MODE_OUT_PP_LOW_FAST);
	GPIO_Init(MCO5_PORT, MCO5_PIN,GPIO_MODE_OUT_PP_LOW_FAST);		
}

//?߼???ʱ???ʼ????
void Tim1_init(void)
{
	 /* TIM1 Peripheral Configuration */ 
  TIM1_DeInit();

  TIM1_TimeBaseInit(0, TIM1_COUNTERMODE_UP, hArrPwmVal, 0);

  TIM1_OC1Init(TIM1_OCMODE_PWM1, TIM1_OUTPUTSTATE_ENABLE, TIM1_OUTPUTNSTATE_DISABLE, hArrPwmVal*0, TIM1_OCPOLARITY_HIGH, TIM1_OCNPOLARITY_LOW, TIM1_OCIDLESTATE_RESET, TIM1_OCNIDLESTATE_SET); 

  TIM1_OC2Init(TIM1_OCMODE_PWM1, TIM1_OUTPUTSTATE_ENABLE, TIM1_OUTPUTNSTATE_DISABLE, hArrPwmVal*0, TIM1_OCPOLARITY_HIGH, TIM1_OCNPOLARITY_LOW, TIM1_OCIDLESTATE_RESET, TIM1_OCNIDLESTATE_SET); 

  TIM1_OC3Init(TIM1_OCMODE_PWM1, TIM1_OUTPUTSTATE_ENABLE, TIM1_OUTPUTNSTATE_DISABLE, hArrPwmVal*0, TIM1_OCPOLARITY_HIGH, TIM1_OCNPOLARITY_LOW, TIM1_OCIDLESTATE_RESET, TIM1_OCNIDLESTATE_SET); 

  TIM1_CCPreloadControl(DISABLE);
	TIM1_Cmd(ENABLE);
}


main()
{
  unsigned int tem_c=0;
	unsigned char step=0;
	unsigned int outpwm=0;
	
	for(tem_c=0;tem_c<50000;tem_c++);//????????ȴ?ϵͳ???

	Clock_init();//ָʾ?ƶ˿ڳ?ʼ??
	GPIO_int();//ʱ???
	
	PWM_IO_init();//???عܿ?ƶ˿ڳ?ʼ??
	Tim1_init();//?߼???ʱ???	
	outpwm=hArrPwmVal*PWMOUT/100;
	while (1)
	{
		for(tem_c=0;tem_c<6000;tem_c++);//?ʱʱ??
		GPIO_WriteReverse(GPIOD,GPIO_PIN_5);//PD7ָʾ?Ʒ?ת
		step++;
		if(step>=6)step=0;
		Commutation(step,outpwm);
	}
}

//??????PWMֵ??
//bHallStartStep:??ǰ??????0-5??OutPwmValue ???PWMֵ
void Commutation(unsigned char bHallStartStep,unsigned int OutPwmValue)
{	
   TIM1->BKR &= (uint8_t)(~TIM1_BKR_MOE);//??ֹPWM???
	if(bHallStartStep!=3&&bHallStartStep!=4)
	PWM_A_OFF;
	if(bHallStartStep!=0&&bHallStartStep!=5)
	PWM_B_OFF;
	if(bHallStartStep!=1&&bHallStartStep!=2)
	PWM_C_OFF;
	 
	//???ݻ????????򿪲?ͬ?Ŀ??عܣ???ʩ???ȷ??WM???
	if(bHallStartStep==0)//AB
	{
		TIM1->CCR3H = (uint8_t)(OutPwmValue >> 8);
    TIM1->CCR3L = (uint8_t)(OutPwmValue);
		PWM_B_ON;
	}
  else if(bHallStartStep==1)	//AC
	{
		TIM1->CCR3H = (uint8_t)(OutPwmValue >> 8);
    TIM1->CCR3L = (uint8_t)(OutPwmValue);
	  PWM_C_ON;
	}
	else if(bHallStartStep==2)	//BC
	{
		TIM1->CCR2H = (uint8_t)(OutPwmValue >> 8);
    TIM1->CCR2L = (uint8_t)(OutPwmValue);
	  PWM_C_ON;
	}
	else if(bHallStartStep==3)	//BA
	{
		TIM1->CCR2H = (uint8_t)(OutPwmValue >> 8);
    TIM1->CCR2L = (uint8_t)(OutPwmValue);
	  PWM_A_ON;
	}
	else if(bHallStartStep==4)//CA
	{
		TIM1->CCR1H = (uint8_t)(OutPwmValue >> 8);
    TIM1->CCR1L = (uint8_t)(OutPwmValue);
	  PWM_A_ON;
	}
	else if(bHallStartStep==5)	//CB
	{
		TIM1->CCR1H = (uint8_t)(OutPwmValue >> 8);
    TIM1->CCR1L = (uint8_t)(OutPwmValue);
	  PWM_B_ON;
	}
	
	TIM1->CCER1=PWM_EN1_TAB[bHallStartStep];
	TIM1->CCER2=PWM_EN2_TAB[bHallStartStep];		
	TIM1->BKR|=TIM1_BKR_MOE;//ʹ?PWM???
}

#ifdef USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval : None
  */
void assert_failed(u8* file, u32 line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif