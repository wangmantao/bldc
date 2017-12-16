#==========================================================
#   Makefile for STM8
#	Denis Zheleznyakov aka ZiB @ http://ziblog.ru
#==========================================================
# 定义要编译的C源文件
SRC_C  = usb.c
SRC_C += main.c
SRC_C += macros.c
SRC_C += stm8_interrupt_vector.c
SRC_C += stm8s_it.c
SRC_C += stm8s_clk.c
SRC_C += stm8s_tim1.c
SRC_C += stm8s_tim2.c
SRC_C += stm8s_tim4.c
SRC_C += stm8s_uart1.c

SRC_S += usb_rx.S
SRC_S += usb_tx.S

#CROSS_PATH = D:/Tools/Cosmic/
#CROSS = $(CROSS_PATH)/4.3.7/
#定义编译工具所在的目录 
CROSS =""

# 定义头文件所在的所有可能位置
INCLUDES += -imcu
INCLUDES += -imcu/peripherals
INCLUDES += -imcu/startup
INCLUDES += -imcu/std_lib/inc
INCLUDES += -imcu/std_lib/src
INCLUDES += -idevice
INCLUDES += -idevice/usb
INCLUDES += -iutility

# 查找依赖文件和目标文件的路径
VPATH += mcu
VPATH += mcu/peripherals
VPATH += mcu/startup
VPATH += mcu/std_lib/inc
VPATH += mcu/std_lib/src
VPATH += device
VPATH += device/usb
VPATH += utility

# 定义编译命令的参数
FLAGS_C  = +debug +warn +modsl0 -pxp -pp +fast +split -l -gge -pge

all: clean
	@echo '-----------------------all: job -------------------------------'
#	@make -s -j job
	@make job
	@echo '-----------------------all: cobj -------------------------------'
#	@$(CROSS)cobj -n target/target.sm8 | $(CROSS_PATH)cosmic_format 'mcu/stm8s003f3.lsf'
	@echo '-----------------------all: mcu_program -------------------------------'
# @make -s mcu_program
	@make mcu_program

job: target.elf
	@echo '-----------------------job-------------------------------'

git:
	@echo '-----------------------git-------------------------------'
	@C:/Tools/git/extensions/gitex browse .

git_commit:
	@echo '-----------------------git_commit-------------------------------'
	@C:/Tools/git/extensions/gitex commit .

mcu_all: all
	@echo '-----------------------mcu_all-------------------------------'
#	@make -s mcu_program
	@make -s mcu_program

%.elf: $(SRC_C:%.c=target/%.o) $(SRC_S:%.S=target/%.o)
	@echo '--------------------%.elf----------------------------------'
	@echo linking: $@
	@$(CROSS)clnk -l'$(CROSS)/Lib' -o'target/target.sm8' -m'target/target.map' -sa 'mcu/*.lsf'
	@$(CROSS)cvdwarf target/target.sm8
	@$(CROSS)chex -o target/target.s19 target/target.sm8
	@rm -f target/*.o

$(SRC_C:%.c=target/%.o): target/%.o: %.c
	@echo '--------------------%.c -> %.o ----------------------------------'
	@$(CROSS)cxstm8 $(FLAGS_C) $(INCLUDES) -i. -i$(CROSS)/Hstm8 -cl'target' -co'target' $<

$(SRC_S:%.S=target/%.o): target/%.o: %.S
	@$(CROSS)cxstm8 +debug +warn -l -no $(INCLUDES) -i. -i$(CROSS)/Hstm8 -cl'target' -co'target' $<

size:
	@echo '------------------size-------------------------------------'
	@$(CROSS)cobj -n target/target.sm8 | $(CROSS_PATH)cosmic_format 'mcu/stm8s003f3.lsf'

clean:
	clear
	@echo '------------------clean------------------------------------'
	@mkdir -p target
	@echo '------------------clean last target------------------------------------'
	@rm -f target/*.*

mcu_program:
# D:/Tools/STMicroelectronics/toolset/stvp/STVP_CmdLine.exe -BoardName=ST-LINK -Device=STM8S003F3 -Port=USB -ProgMode=SWIM -no_loop -no_log -FileProg=target/target.s19

mcu_restart:
#	@D:/Tools/STMicroelectronics/toolset/stvd/gdb7.exe --quiet --command=mcu/stm8s003f3.ini
