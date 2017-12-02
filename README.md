# bldc
bldc for fan
## 分析代码
### 思路
* 这项实验用了哪些端口，将要测试这些端口上的波形
    - 在datasheet中可以找 PORT A，找相关的信息。
    - 可有"PA1"去找对应的"pin no."
        - GPIO_PIN_3 是由stm8s_gpio.h 中定义的 0x08
        - 所有MOSFET控制都有PORRT C/E控制，PC1/2/3/6/7 5个＋PE5 1个 (确认PE5 pin no.17 是不是接的下桥mosfet4)
        
* 程序的一些基本定义
    - 定义下桥三个FET的开/关（低电平开，查看P/N型MOSFET工作原理）
    - 解读: #define PWM_A_OFF MCO0_PORT->ODR |= (u8)MCO0_PIN;
        - 当某处调用PWM_A_OFF时，实际上执行的是：为MCO0_PORT的ODR赋新的值，新值为原值与MCO0_PIN的或值  (参考: i |= j;即 i = i || j;:)。即，两个值只要有一个为1, PWM_A_OFF就为1。
        - 理解MCO0_PORT->ODR, "->"是取结构中的成员，MCO0_PORT是一个结构，内含一个ODR成员。ODR是什么呢？
            - 首先了解i/o port硬件寄存器的结构：一个port寄存器结构约有5个寄存器，其中有ODR（在其port结构中排第一）为该port输出数据寄存器,它有8个位
            - 输出模式下，写入该寄存器的值，通过锁存器加到相应的引脚上。读ODR的值，返回之前锁存器的值（因为在输出模式下，写入寄存器的值是不会存入寄存器）
            - MCO0_PIN 它是宏 GPIO_PIN 的代名词, 在一个gpio.h头文件中定义，该头文件定义了，GPIO外围的功能函数原型和宏。
            - 总结：为MCO0端输出数据寄存器赋新值，新值会受MCO0_PIN的影响

* 分析程序的调用逻辑
    - 库是怎么调用的，用到了库的什么功能

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
