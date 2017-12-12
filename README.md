# bldc
bldc for fan

## 为了linux体验(SDCC)
* 中断向量表的问题 void handler(void) __trap (...) 
* 相关软件
    - stm8flash, a utility for interfacing your ST-Link dongle
    - sdcc 
* 教程
    - https://www.ondrovo.com/a/20170107-stm8-getting-started/
* 概念
    - 标准外设库 （SPL）反映底层（寄存器）的。
    - 先从官网下载官网的库及手册(是chm格式 kchmviewer)  (/home/wmt/soft 存放)
    - 有个兼容SPL库用于SDCC https://github.com/gicking/SPL_2.2.0_SDCC_patch 
        - 暂不知道其作用，及怎么用

## 进展
* 做出电路图，给CUSTOMER打板。
    - 可能是个有缺陷的电路图，但是可以给他们先做，做好做坏先不管。
    - 当务之急是先把万能板功能先添加起来。
	- 画出反电动势检测电路
	- 研究反电动势程序与实现

* 照客户的思路
	- 不用做硬件的安装，缺点时效性长。但可能客户的产品调试都会成为自己的任务。
	- 所以不要在客户板上做实验，但是负责任的说法是：程序要在客户板上运行产能说的过去。
	- 客户没提供板与电路，程序也没地方跑。
	 
* 要买的物件
    - 三极管   (保险丝)

* 修改示例程序可以产生正常的PWM
    - PC1/PC2 用PC4/PC5 代替，用于下管驱动
    - Option Byte设置： AFR0= PC5为TIM2_CH1 / PC6 为TIM1_CH1 / PC7 为TIM1_CH2

* 由于要驱动马达，大马达要用12伏，P管不方便驱动，要买三极管。先用5V驱动小马达之前要做的工作：
    - 用Y型电阻代替三相马达，检流电阻不要。
    - 分析出高驱动还是低驱动，并实现。
        - H pwm 15% duty 怎么换在低电平有效
        - 找到控制脚输出的指令，并把经求反，看可不可行
        - 为了实现5V 驱动P MOSFET, H PWM 有低电平有效，方法：改变CCER1/2 CCiP = 1。
            - 但是，无PWM时，无PWM时，不能使其置位于无效的高电平。参考一下 PWM_A_OFF 干了些什么.

    - 查看每相电阻的电流。（需要用上ADC工具，还要做出分压采样电阻）

## 分析代码
### 思路
* 由于参考书的MCU型号与当前MCU型号不一致，所以要换
    - PORTC 1/2/3/6/7 (5个）  SOP20只有3/4/5/6/7, 没有1/2， 只能对应3/6/7; 用4、5 替换 1、2
    - PORT  
    - PORTE 5 (1个)
    确认STM8S003F3 有哪些port, 这些port在示例中是用来干什么的？（网络好了，再实施）
    了解6步法 (通读第7、8章） 
	完成端口改造，并测波形分析6步法
* 程序的一些基本定义
    - 定义下桥三个FET的开/关（低电平开，查看P/N型MOSFET工作原理）
    - 解读: #define PWM_A_OFF MCO0_PORT->ODR |= (u8)MCO0_PIN;
        - 例，port c的数据存器是0000 1111，即要求此时port c的低4位脚输出，但时A路(桥臂)控制受3脚影响
        - 当某处调用PWM_A_OFF时，实际上执行的是：为MCO0_PORT的ODR赋新的值，新值为原值与MCO0_PIN的或值  (参考: i |= j;即 i = i || j;:)。即，两个值只要有一个为1, PWM_A_OFF就为1。
        - 理解MCO0_PORT->ODR, "->"是取结构中的成员，MCO0_PORT是一个结构，内含一个ODR成员。ODR是什么呢？
            - 首先了解i/o port硬件寄存器的结构：一个port寄存器结构约有5个寄存器，其中有ODR（在其port结构中排第一）为该port输出数据寄存器,它有8个位
            - 输出模式下，写入该寄存器的值，通过锁存器加到相应的引脚上。读ODR的值，返回之前锁存器的值（因为在输出模式下，写入寄存器的值是不会存入寄存器）
            - MCO0_PIN 它是宏 GPIO_PIN_3 的代名词, 在一个gpio.h头文件中定义，该头文件定义了，GPIO外围的功能函数原型和宏。
            - 总为MCO0端输出数据寄存器赋新值，新值会受MCO0_PIN的影响

* 分析程序的调用逻辑
    - 库是怎么调用的，用到了库的什么功能
    - main的运行：4个初始化
        - 指示端口
        - 时钟
        - 开关管的控制
        - 高级定时器

* 应用STM库，须要学说STM的术语（概念）
    - 时钟_系统时钟配置 （可能还有其它时种）
    - GPIO_初始化
  
* 代码分析
GIO_Init(端口，pin类型，pin模式） 
该函数利用这些参数，去配置ODR(数据方向寄存器),DDR(数据输出锁存器),CR1(控制器1),CR2(控制器2) 
CR1 控制：
CR2 控制：
控制寄存器1(CR1)和控制寄存器2(CR2)用于对输入/输出进行配置。任何一个I/O引脚可以通过
对DDR,ODR,CR1和CR2寄存器的相应位进行编程来配置。
寄存器中的位n对应于口的引脚 n 。

 	GPIO_Init(GPIOD, GPIO_PIN_7, GPIO_MODE_OUT_PP_HIGH_FAST); //PD7 输出

	GPIO_Init(MCO0_PORT, MCO0_PIN,GPIO_MODE_OUT_PP_HIGH_FAST); 下管;推拉式，高电平，10MHz (寄存器值：1111 0000)
	GPIO_Init(MCO2_PORT, MCO2_PIN,GPIO_MODE_OUT_PP_HIGH_FAST);
 	GPIO_Init(MCO4_PORT, MCO4_PIN,GPIO_MODE_OUT_PP_HIGH_FAST);
 	GPIO_Init(MCO1_PORT, MCO1_PIN,GPIO_MODE_OUT_PP_LOW_FAST);  上管;
 	GPIO_Init(MCO3_PORT, MCO3_PIN,GPIO_MODE_OUT_PP_LOW_FAST);
 	GPIO_Init(MCO5_PORT, MCO5_PIN,GPIO_MODE_OUT_PP_LOW_FAST);	
总结： 上/下管都初始化为输出推拉式，快速工作状态，下管置高，上管置低

模式说明(GPIO_MODE_OUT_PP_HIGH_FAST):
	GPIO_MODE_OUT_PP_LOW_SLOW  = (uint8_t)0xC0,  /*!< Output push-pull, low level, 2MHz */
	GPIO_MODE_OUT_OD_HIZ_FAST  = (uint8_t)0xB0,  /*!< Output open-drain, high-impedance level,10MHz */
	GPIO_MODE_OUT_PP_HIGH_FAST = (uint8_t)0xF0,  /*!< Output push-pull, high level, 10MHz */
	GPIO_MODE_OUT_OD_HIZ_SLOW  = (uint8_t)0x90,  /*!< Output open-drain, high-impedance level, 2MHz */
	GPIO_MODE_OUT_PP_HIGH_SLOW = (uint8_t)0xD0   /*!< Output push-pull, high level, 2MHz */

* 除了有main.c的程序外，还有库中timer相关。有没时间细分了，接下来看《基于STM8S》和库的手册（用库函数名去搜索）
-------------------------------------------------------------------------------
## 遇到的问题及对策
### 每次开机都要打开哪些与项目相关的文件，一个个的找费时。所有找到工具：
devilspie 和 wmctrl(命令行工具）  

-------------------------------------------------------------------------------
## 建立Git环境，可多处编译并提交，所有平台保持代码同步
### git 基本用法
* git add ===要添加git仓库的文件
* git commit -m "dajfeasjdfe" === 本次提交文件的说明
* git stauts / git diff 	=== 可以看到本地git管理下的文件状态。并且可s查看文件的历史变更具体不同点。

总结： 在持续的文件编辑下，在某次修改、编辑后想在此打一个Mark，表示这次主要完成的一个什么目的。就用"git add 文件名" & "git commit -m 'mark内容'"，这样的话，将来用"git log" 就可以看到每次完成任务的mark。


* git log	=== 查看提交的历史
* git reset --hard HEAD^	=== 版本回退  
* git reflog 	===查看命令的历史

配置相关： 本地的git总要与远程服务器保持同步，所以要配置关于committer的远程相关的账号。

* git config --global --edit	===编辑配置文件
* git commit --amend --reset-author	===配置完后，修改本次提交所使用的用户身份

 [spacemacs命令] http://blog.csdn.net/u011729865/article/details/52793134
