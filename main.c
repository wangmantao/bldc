/* MAIN.C file
摘要：
1.PD7延时反转，指示系统工作。
2.上电，按指定PWM输出延时换相，实现电机基本运转功能。
2013.5.8
 */
#include "stm8s.h"

#define STM8_FREQ_MHZ 16
#define PWM_FREQUENCY 16000

static const u16 hArrPwmVal = ((u16)((STM8_FREQ_MHZ * (u32)1000000)/PWM_FREQUENCY));
//PWM信号周期

#define PWMOUT 15
//按15%占空比输出

//const unsigned char PWM_EN1_TAB[6]={0x00,0x00,0x10,0x10,0x01,0x01};
const unsigned char PWM_EN1_TAB[6]={0x00,0x00,0x30,0x30,0x03,0x03};
//六步法中，CH1\CH2通道极性及使能配置 CH1 PC6 C相 / CH2 PC7 B相

//const unsigned char PWM_EN2_TAB[6]={0x01,0x01,0x00,0x00,0x00,0x00};
const unsigned char PWM_EN2_TAB[6]={0x03,0x03,0x00,0x00,0x00,0x00};
//六步法中，CH3通道极性及使能配置 CH3 PC3 A相
/* 以上总结分析：
    PWM_EN_TAB 指定了所用到的输出比较寄存器，
    TAB1指定了CC1 (step4 & 5) 和 CC2 (step2 & 3)
    TAB2指定了CC3（step0 & 1), CC4没有用
*/

//上桥臂开关控制端口定义
#define MCO1_PORT GPIOC
#define MCO1_PIN	GPIO_PIN_3  
#define MCO3_PORT GPIOC
#define MCO3_PIN	GPIO_PIN_7
#define MCO5_PORT GPIOC
#define MCO5_PIN	GPIO_PIN_6

//下桥臂开关控制端口定义
#define MCO0_PORT GPIOC
#define MCO0_PIN	GPIO_PIN_5  // 用5替换2 (因为003f3没有PC1/2)
#define MCO2_PORT GPIOC
#define MCO2_PIN	GPIO_PIN_4 // 用4替换1
#define MCO4_PORT GPIOD
#define MCO4_PIN	GPIO_PIN_2

//下桥臂低电平开关管导通
#define PWM_A_OFF MCO0_PORT->ODR |= (u8)MCO0_PIN; 
#define PWM_B_OFF MCO2_PORT->ODR |= (u8)MCO2_PIN; 
#define PWM_C_OFF MCO4_PORT->ODR |= (u8)MCO4_PIN; 

#define PWM_A_ON MCO0_PORT->ODR &= (u8)(~MCO0_PIN); 
#define PWM_B_ON MCO2_PORT->ODR &= (u8)(~MCO2_PIN); 
#define PWM_C_ON MCO4_PORT->ODR &= (u8)(~MCO4_PIN); 

//换相子函数声明
void Commutation(unsigned char bHallStartStep,unsigned int OutPwmValue);

//初始化按键，指示灯端口
void GPIO_int(void)
{
	 /* LEDs */
	//GPIO_Init(GPIOD, GPIO_PIN_7, GPIO_MODE_OUT_PP_HIGH_FAST);  //PD7 
    //GPIO_Init(GPIOD, GPIO_PIN_2, GPIO_MODE_OUT_PP_HIGH_FAST);  //PD7 
}

//系统时钟配置：内部16M
void Clock_init(void)
{
	/* Select fCPU = 16MHz */
  CLK_SYSCLKConfig(CLK_PRESCALER_HSIDIV1);
}

//换相电路开关管IO初始化
void PWM_IO_init(void)
{	
    // 下桥臂0有效 ,配置为高电平
	GPIO_Init(MCO0_PORT, MCO0_PIN,GPIO_MODE_OUT_PP_HIGH_FAST);
	GPIO_Init(MCO2_PORT, MCO2_PIN,GPIO_MODE_OUT_PP_HIGH_FAST);
	GPIO_Init(MCO4_PORT, MCO4_PIN,GPIO_MODE_OUT_PP_HIGH_FAST);
	
	//PC 3 6 7 上桥臂1有效,配置为低电平	
	//GPIO_Init(MCO1_PORT, MCO1_PIN,GPIO_MODE_OUT_PP_LOW_FAST);
	//GPIO_Init(MCO3_PORT, MCO3_PIN,GPIO_MODE_OUT_PP_LOW_FAST);
	//GPIO_Init(MCO5_PORT, MCO5_PIN,GPIO_MODE_OUT_PP_LOW_FAST);		
    GPIO_Init(MCO1_PORT, MCO1_PIN,GPIO_MODE_OUT_PP_HIGH_FAST);
    GPIO_Init(MCO3_PORT, MCO3_PIN,GPIO_MODE_OUT_PP_HIGH_FAST);
    GPIO_Init(MCO5_PORT, MCO5_PIN,GPIO_MODE_OUT_PP_HIGH_FAST);       
}

//高级定时器初始化配置
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
	
	for(tem_c=0;tem_c<50000;tem_c++);//上电延时，等待系统稳定

	Clock_init(); //时钟配置
	//GPIO_int(); //指示灯端口初始化
	
	PWM_IO_init();//开关管控制端口初始化
	Tim1_init();//高级定时器配置	
	outpwm=hArrPwmVal*PWMOUT/100;

    PWM_IO_init();//开关管控制端口初始化
	while (1)
	{
		for(tem_c=0;tem_c<6000;tem_c++);//延时时间
		//GPIO_WriteReverse(GPIOD,GPIO_PIN_7);//PD7指示灯反转
		step++;
		if(step>=6)step=0;
		Commutation(step,outpwm);
	}
}

//换向输出PWM值，
//bHallStartStep:当前换相步序0-5，OutPwmValue 输出PWM值
void Commutation(unsigned char bHallStartStep,unsigned int OutPwmValue)
{	
   TIM1->BKR &= (uint8_t)(~TIM1_BKR_MOE);//禁止PWM输出
	if(bHallStartStep!=3&&bHallStartStep!=4)
	//PWM_A_OFF;
    PWM_A_ON;
	if(bHallStartStep!=0&&bHallStartStep!=5)
	//PWM_B_OFF;
    PWM_B_ON;
	if(bHallStartStep!=1&&bHallStartStep!=2)
	//PWM_C_OFF;
    PWM_C_ON;
	 
	//根据换相步序，打开不同的开关管，并施加正确的PWM信号
	if(bHallStartStep==0)//AB
	{
		TIM1->CCR3H = (uint8_t)(OutPwmValue >> 8);
    TIM1->CCR3L = (uint8_t)(OutPwmValue);
		//PWM_B_ON;
        PWM_B_OFF;
	}
  else if(bHallStartStep==1)	//AC
	{
		TIM1->CCR3H = (uint8_t)(OutPwmValue >> 8);
    TIM1->CCR3L = (uint8_t)(OutPwmValue);
	  //PWM_C_ON;
      PWM_C_OFF;
	}
	else if(bHallStartStep==2)	//BC
	{
		TIM1->CCR2H = (uint8_t)(OutPwmValue >> 8);
    TIM1->CCR2L = (uint8_t)(OutPwmValue);
	  //PWM_C_ON;
      PWM_C_OFF;
	}
	else if(bHallStartStep==3)	//BA
	{
		TIM1->CCR2H = (uint8_t)(OutPwmValue >> 8);
    TIM1->CCR2L = (uint8_t)(OutPwmValue);
	  //PWM_A_ON;
      PWM_A_OFF;
	}
	else if(bHallStartStep==4)//CA
	{
		TIM1->CCR1H = (uint8_t)(OutPwmValue >> 8);
    TIM1->CCR1L = (uint8_t)(OutPwmValue);
	  //PWM_A_ON;
      PWM_A_OFF;
	}
	else if(bHallStartStep==5)	//CB
	{
		TIM1->CCR1H = (uint8_t)(OutPwmValue >> 8);
    TIM1->CCR1L = (uint8_t)(OutPwmValue);
	  //PWM_B_ON;
      PWM_B_OFF;
	}
	
	TIM1->CCER1=PWM_EN1_TAB[bHallStartStep];
	TIM1->CCER2=PWM_EN2_TAB[bHallStartStep];		
	TIM1->BKR|=TIM1_BKR_MOE;//使能PWM输出
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