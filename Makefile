#==========================================================
#   Makefile for STM8
#	Denis Zheleznyakov aka ZiB @ http://ziblog.ru
#==========================================================
# 定义要编译的C源文件
SRC_C  = stm8s_clk.c
SRC_C += stm8s_gpio.c
SRC_C += stm8s_tim1.c
SRC_C += main.c
SRC_C += stm8_interrupt_vector.c

#CROSS_PATH = D:/Tools/Cosmic/
#CROSS = $(CROSS_PATH)/4.3.7/
#定义编译工具所在的目录 
CROSS =""

# 定义头文件所在的所有可能位置
INCLUDES += -iLibraries/inc
INCLUDES += -iHstm8
# 查找依赖文件和目标文件的路径
VPATH += Libraries/inc
VPATH += Libraries/src
VPATH += target

# 定义编译命令的参数
#FLAGS_C  = +debug +warn +modsl0 -pxp -pp +fast +split -l -gge -pge
#FLAGS_C  = +mods0 -pp

#cxstm8 +mods0 +debug -pxp -no -pp -l -ilibraries\inc -i..\libraries\inc -i"C:\Program Files (x86)\COSMIC\FSE_Compilers\CXSTM8\Hstm8"  -clDebug\ -coDebug\ libraries\src\stm8s_clk.c
FLAGS_C = +mods0 +debug -pxp -no -pp -l

all: clean
	@echo '-----------------------all: job -------------------------------'
	@make -s -j job
#	@make job
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

$(SRC_C:%.c=target/%.o): target/%.o: %.c
	@echo '--------------------%.c -> %.o ----------------------------------'
#	@echo $(SRC_C:%.c=target/%.o)
#	@$(CROSS)cxstm8 $(FLAGS_C) $(INCLUDES) -i. -i$(CROSS)/Hstm8 -cl'target' -co'target' $<
#	echo $(CROSS)cxstm8 $(FLAGS_C) $(INCLUDES)  -cl'target' -co'target' $<
	$(CROSS)cxstm8 $(FLAGS_C) $(INCLUDES)  -cl'target' -co'target' $<
#	cxstm8 +mods0 +debug -pxp -no -pp -l -ilibraries\inc -i..\libraries\inc -i"C:\Program Files (x86)\COSMIC\FSE_Compilers\CXSTM8\Hstm8"  -clDebug\ -coDebug\ stm8_interrupt_vector.c
	echo $<
#	@$(CROSS)cxstm8 $(FLAGS_C) -ilibraries\inc -i..\libraries\inc -iHstm8  -cl\target -co\target $<

$(SRC_S:%.S=target/%.o): target/%.o: %.S
#	@echo '--------------------%.s -> %.o ----------------------------------'
#	@$(CROSS)cxstm8 +debug +warn -l -no $(INCLUDES) -i. -i$(CROSS)/Hstm8 -cl'target' -co'target' $<

%.elf: $(SRC_C:%.c=target/%.o) $(SRC_S:%.S=target/%.o)
	@echo '--------------------%.elf----------------------------------'
	@echo linking: $@
#	clnk -l"C:\Program Files (x86)\COSMIC\FSE_Compilers\CXSTM8\Lib"  -o Debug\bldc.sm8 -mDebug\bldc.map Debug\bldc.lkf 
	$(CROSS)clnk -l"C:\Program Files (x86)\COSMIC\FSE_Compilers\Lib"  -o'target/target.sm8' -m'Debug/bldc.map' Debug/bldc.lkf    
	$(CROSS)cvdwarf target/target.sm8
	$(CROSS)chex -o target/target.s19 target/target.sm8
#	@rm -f target/*.o    # 删除中间文件（目标文件） 

size:
	@echo '------------------size-------------------------------------'
	@$(CROSS)cobj -n target/target.sm8 | $(CROSS_PATH)cosmic_format 'mcu/stm8s003f3.lsf'

clean:
	@echo '------------------clean------------------------------------'
	@mkdir -p target
	@echo '------------------clean last target------------------------------------'
	@rm -f target/*.*

mcu_program:
	@echo '------------------upload program------------------------------------'
# D:/Tools/STMicroelectronics/toolset/stvp/STVP_CmdLine.exe -BoardName=ST-LINK -Device=STM8S003F3 -Port=USB -ProgMode=SWIM -no_loop -no_log -FileProg=target/target.s19
	"C:\Program Files (x86)\STMicroelectronics\st_toolset\stvp\STVP_CmdLine.exe" -BoardName=ST-LINK -Device=STM8S003F3 -Port=USB -ProgMode=SWIM -no_loop -no_log -FileProg=target/target.s19
#	make mcu_restart
mcu_restart:
#	@D:/Tools/STMicroelectronics/toolset/stvd/gdb7.exe --quiet --command=mcu/stm8s003f3.ini
	@echo '------------------restart mcu------------------------------------'
#	"C:\Program Files (x86)\STMicroelectronics\st_toolset\stvd\gdb7.exe" --quiet --command=stm8s003f3.ini