# ST Visual Debugger Generated MAKE File, based on bldc.stp

ifeq ($(CFG), )
CFG=Debug
$(warning ***No configuration specified. Defaulting to $(CFG)***)
endif

ToolsetRoot=C:\PROGRA~1\COSMIC\CXSTM8
ToolsetBin=C:\Program Files\COSMIC\CXSTM8
ToolsetInc=C:\Program Files\COSMIC\CXSTM8\Hstm8
ToolsetLib=C:\Program Files\COSMIC\CXSTM8\Lib
ToolsetIncOpts=-i"C:\Program Files\COSMIC\CXSTM8\Hstm8" 
ToolsetLibOpts=-l"C:\Program Files\COSMIC\CXSTM8\Lib" 
ObjectExt=o
OutputExt=elf
InputName=$(basename $(notdir $<))


# 
# Debug
# 
ifeq "$(CFG)" "Debug"


OutputPath=Debug
ProjectSFile=bldc
TargetSName=bldc
TargetFName=bldc.elf
IntermPath=$(dir $@)
CFLAGS_PRJ=$(ToolsetBin)\cxstm8  +mods0 +debug -pxp -no -pp -l -i..\libraries\inc $(ToolsetIncOpts) -cl$(IntermPath:%\=%) -co$(IntermPath:%\=%) $<
ASMFLAGS_PRJ=$(ToolsetBin)\castm8  -xx -l $(ToolsetIncOpts) -o$(IntermPath)$(InputName).$(ObjectExt) $<

all : $(OutputPath) bldc.elf

$(OutputPath) : 
	if not exist $(OutputPath)/ mkdir $(OutputPath)

Debug\stm8s_clk.$(ObjectExt) : ..\libraries\src\stm8s_clk.c c:\PROGRA~1\cosmic\cxstm8\hstm8\mods0.h ..\libraries\inc\stm8s_clk.h ..\libraries\inc\stm8s.h ..\libraries\inc\stm8s_conf.h ..\libraries\inc\stm8s_adc1.h ..\libraries\inc\stm8s_awu.h ..\libraries\inc\stm8s_beep.h ..\libraries\inc\stm8s_exti.h ..\libraries\inc\stm8s_flash.h ..\libraries\inc\stm8s_gpio.h ..\libraries\inc\stm8s_i2c.h ..\libraries\inc\stm8s_itc.h ..\libraries\inc\stm8s_iwdg.h ..\libraries\inc\stm8s_rst.h ..\libraries\inc\stm8s_spi.h ..\libraries\inc\stm8s_tim1.h ..\libraries\inc\stm8s_tim5.h ..\libraries\inc\stm8s_tim6.h ..\libraries\inc\stm8s_uart1.h ..\libraries\inc\stm8s_wwdg.h 
	@if not exist $(dir $@)  mkdir $(dir $@)
	$(CFLAGS_PRJ)

Debug\stm8s_gpio.$(ObjectExt) : ..\libraries\src\stm8s_gpio.c c:\PROGRA~1\cosmic\cxstm8\hstm8\mods0.h ..\libraries\inc\stm8s_gpio.h ..\libraries\inc\stm8s.h ..\libraries\inc\stm8s_conf.h ..\libraries\inc\stm8s_adc1.h ..\libraries\inc\stm8s_awu.h ..\libraries\inc\stm8s_beep.h ..\libraries\inc\stm8s_clk.h ..\libraries\inc\stm8s_exti.h ..\libraries\inc\stm8s_flash.h ..\libraries\inc\stm8s_i2c.h ..\libraries\inc\stm8s_itc.h ..\libraries\inc\stm8s_iwdg.h ..\libraries\inc\stm8s_rst.h ..\libraries\inc\stm8s_spi.h ..\libraries\inc\stm8s_tim1.h ..\libraries\inc\stm8s_tim5.h ..\libraries\inc\stm8s_tim6.h ..\libraries\inc\stm8s_uart1.h ..\libraries\inc\stm8s_wwdg.h 
	@if not exist $(dir $@)  mkdir $(dir $@)
	$(CFLAGS_PRJ)

Debug\stm8s_tim1.$(ObjectExt) : ..\libraries\src\stm8s_tim1.c c:\PROGRA~1\cosmic\cxstm8\hstm8\mods0.h ..\libraries\inc\stm8s_tim1.h ..\libraries\inc\stm8s.h ..\libraries\inc\stm8s_conf.h ..\libraries\inc\stm8s_adc1.h ..\libraries\inc\stm8s_awu.h ..\libraries\inc\stm8s_beep.h ..\libraries\inc\stm8s_clk.h ..\libraries\inc\stm8s_exti.h ..\libraries\inc\stm8s_flash.h ..\libraries\inc\stm8s_gpio.h ..\libraries\inc\stm8s_i2c.h ..\libraries\inc\stm8s_itc.h ..\libraries\inc\stm8s_iwdg.h ..\libraries\inc\stm8s_rst.h ..\libraries\inc\stm8s_spi.h ..\libraries\inc\stm8s_tim5.h ..\libraries\inc\stm8s_tim6.h ..\libraries\inc\stm8s_uart1.h ..\libraries\inc\stm8s_wwdg.h 
	@if not exist $(dir $@)  mkdir $(dir $@)
	$(CFLAGS_PRJ)

Debug\main.$(ObjectExt) : main.c c:\PROGRA~1\cosmic\cxstm8\hstm8\mods0.h ..\libraries\inc\stm8s.h ..\libraries\inc\stm8s_conf.h ..\libraries\inc\stm8s_adc1.h ..\libraries\inc\stm8s_awu.h ..\libraries\inc\stm8s_beep.h ..\libraries\inc\stm8s_clk.h ..\libraries\inc\stm8s_exti.h ..\libraries\inc\stm8s_flash.h ..\libraries\inc\stm8s_gpio.h ..\libraries\inc\stm8s_i2c.h ..\libraries\inc\stm8s_itc.h ..\libraries\inc\stm8s_iwdg.h ..\libraries\inc\stm8s_rst.h ..\libraries\inc\stm8s_spi.h ..\libraries\inc\stm8s_tim1.h ..\libraries\inc\stm8s_tim5.h ..\libraries\inc\stm8s_tim6.h ..\libraries\inc\stm8s_uart1.h ..\libraries\inc\stm8s_wwdg.h 
	@if not exist $(dir $@)  mkdir $(dir $@)
	$(CFLAGS_PRJ)

Debug\stm8_interrupt_vector.$(ObjectExt) : stm8_interrupt_vector.c c:\PROGRA~1\cosmic\cxstm8\hstm8\mods0.h 
	@if not exist $(dir $@)  mkdir $(dir $@)
	$(CFLAGS_PRJ)

bldc.elf :  $(OutputPath)\stm8s_clk.o $(OutputPath)\stm8s_gpio.o $(OutputPath)\stm8s_tim1.o $(OutputPath)\main.o $(OutputPath)\stm8_interrupt_vector.o $(OutputPath)\bldc.lkf
	$(ToolsetBin)\clnk  -m $(OutputPath)\$(TargetSName).map $(ToolsetLibOpts) -o $(OutputPath)\$(TargetSName).sm8 $(OutputPath)\$(TargetSName).lkf 
	$(ToolsetBin)\cvdwarf  $(OutputPath)\$(TargetSName).sm8 

	$(ToolsetBin)\chex  -o $(OutputPath)\$(TargetSName).s19 $(OutputPath)\$(TargetSName).sm8
clean : 
	-@erase $(OutputPath)\stm8s_clk.o
	-@erase $(OutputPath)\stm8s_gpio.o
	-@erase $(OutputPath)\stm8s_tim1.o
	-@erase $(OutputPath)\main.o
	-@erase $(OutputPath)\stm8_interrupt_vector.o
	-@erase $(OutputPath)\bldc.elf
	-@erase $(OutputPath)\bldc.map
	-@erase $(OutputPath)\bldc.st7
	-@erase $(OutputPath)\bldc.s19
	-@erase $(OutputPath)\stm8s_clk.ls
	-@erase $(OutputPath)\stm8s_gpio.ls
	-@erase $(OutputPath)\stm8s_tim1.ls
	-@erase $(OutputPath)\main.ls
	-@erase $(OutputPath)\stm8_interrupt_vector.ls
endif

# 
# Release
# 
ifeq "$(CFG)" "Release"


OutputPath=Release
ProjectSFile=bldc
TargetSName=bldc
TargetFName=bldc.elf
IntermPath=$(dir $@)
CFLAGS_PRJ=$(ToolsetBin)\cxstm8  -i..\libraries\inc +mods0 -pp $(ToolsetIncOpts) -cl$(IntermPath:%\=%) -co$(IntermPath:%\=%) $< 
ASMFLAGS_PRJ=$(ToolsetBin)\castm8  $(ToolsetIncOpts) -o$(IntermPath)$(InputName).$(ObjectExt) $<

all : $(OutputPath) bldc.elf

$(OutputPath) : 
	if not exist $(OutputPath)/ mkdir $(OutputPath)

Release\stm8s_clk.$(ObjectExt) : ..\libraries\src\stm8s_clk.c c:\PROGRA~1\cosmic\cxstm8\hstm8\mods0.h ..\libraries\inc\stm8s_clk.h ..\libraries\inc\stm8s.h ..\libraries\inc\stm8s_conf.h ..\libraries\inc\stm8s_adc1.h ..\libraries\inc\stm8s_awu.h ..\libraries\inc\stm8s_beep.h ..\libraries\inc\stm8s_exti.h ..\libraries\inc\stm8s_flash.h ..\libraries\inc\stm8s_gpio.h ..\libraries\inc\stm8s_i2c.h ..\libraries\inc\stm8s_itc.h ..\libraries\inc\stm8s_iwdg.h ..\libraries\inc\stm8s_rst.h ..\libraries\inc\stm8s_spi.h ..\libraries\inc\stm8s_tim1.h ..\libraries\inc\stm8s_tim5.h ..\libraries\inc\stm8s_tim6.h ..\libraries\inc\stm8s_uart1.h ..\libraries\inc\stm8s_wwdg.h 
	@if not exist $(dir $@)  mkdir $(dir $@)
	$(CFLAGS_PRJ)

Release\stm8s_gpio.$(ObjectExt) : ..\libraries\src\stm8s_gpio.c c:\PROGRA~1\cosmic\cxstm8\hstm8\mods0.h ..\libraries\inc\stm8s_gpio.h ..\libraries\inc\stm8s.h ..\libraries\inc\stm8s_conf.h ..\libraries\inc\stm8s_adc1.h ..\libraries\inc\stm8s_awu.h ..\libraries\inc\stm8s_beep.h ..\libraries\inc\stm8s_clk.h ..\libraries\inc\stm8s_exti.h ..\libraries\inc\stm8s_flash.h ..\libraries\inc\stm8s_i2c.h ..\libraries\inc\stm8s_itc.h ..\libraries\inc\stm8s_iwdg.h ..\libraries\inc\stm8s_rst.h ..\libraries\inc\stm8s_spi.h ..\libraries\inc\stm8s_tim1.h ..\libraries\inc\stm8s_tim5.h ..\libraries\inc\stm8s_tim6.h ..\libraries\inc\stm8s_uart1.h ..\libraries\inc\stm8s_wwdg.h 
	@if not exist $(dir $@)  mkdir $(dir $@)
	$(CFLAGS_PRJ)

Release\stm8s_tim1.$(ObjectExt) : ..\libraries\src\stm8s_tim1.c c:\PROGRA~1\cosmic\cxstm8\hstm8\mods0.h ..\libraries\inc\stm8s_tim1.h ..\libraries\inc\stm8s.h ..\libraries\inc\stm8s_conf.h ..\libraries\inc\stm8s_adc1.h ..\libraries\inc\stm8s_awu.h ..\libraries\inc\stm8s_beep.h ..\libraries\inc\stm8s_clk.h ..\libraries\inc\stm8s_exti.h ..\libraries\inc\stm8s_flash.h ..\libraries\inc\stm8s_gpio.h ..\libraries\inc\stm8s_i2c.h ..\libraries\inc\stm8s_itc.h ..\libraries\inc\stm8s_iwdg.h ..\libraries\inc\stm8s_rst.h ..\libraries\inc\stm8s_spi.h ..\libraries\inc\stm8s_tim5.h ..\libraries\inc\stm8s_tim6.h ..\libraries\inc\stm8s_uart1.h ..\libraries\inc\stm8s_wwdg.h 
	@if not exist $(dir $@)  mkdir $(dir $@)
	$(CFLAGS_PRJ)

Release\main.$(ObjectExt) : main.c c:\PROGRA~1\cosmic\cxstm8\hstm8\mods0.h ..\libraries\inc\stm8s.h ..\libraries\inc\stm8s_conf.h ..\libraries\inc\stm8s_adc1.h ..\libraries\inc\stm8s_awu.h ..\libraries\inc\stm8s_beep.h ..\libraries\inc\stm8s_clk.h ..\libraries\inc\stm8s_exti.h ..\libraries\inc\stm8s_flash.h ..\libraries\inc\stm8s_gpio.h ..\libraries\inc\stm8s_i2c.h ..\libraries\inc\stm8s_itc.h ..\libraries\inc\stm8s_iwdg.h ..\libraries\inc\stm8s_rst.h ..\libraries\inc\stm8s_spi.h ..\libraries\inc\stm8s_tim1.h ..\libraries\inc\stm8s_tim5.h ..\libraries\inc\stm8s_tim6.h ..\libraries\inc\stm8s_uart1.h ..\libraries\inc\stm8s_wwdg.h 
	@if not exist $(dir $@)  mkdir $(dir $@)
	$(CFLAGS_PRJ)

Release\stm8_interrupt_vector.$(ObjectExt) : stm8_interrupt_vector.c c:\PROGRA~1\cosmic\cxstm8\hstm8\mods0.h 
	@if not exist $(dir $@)  mkdir $(dir $@)
	$(CFLAGS_PRJ)

bldc.elf :  $(OutputPath)\stm8s_clk.o $(OutputPath)\stm8s_gpio.o $(OutputPath)\stm8s_tim1.o $(OutputPath)\main.o $(OutputPath)\stm8_interrupt_vector.o $(OutputPath)\bldc.lkf
	$(ToolsetBin)\clnk  $(ToolsetLibOpts) -o $(OutputPath)\$(TargetSName).sm8 $(OutputPath)\$(TargetSName).lkf 
	$(ToolsetBin)\cvdwarf  $(OutputPath)\$(TargetSName).sm8 

	$(ToolsetBin)\chex  -o $(OutputPath)\$(TargetSName).s19 $(OutputPath)\$(TargetSName).sm8
clean : 
	-@erase $(OutputPath)\stm8s_clk.o
	-@erase $(OutputPath)\stm8s_gpio.o
	-@erase $(OutputPath)\stm8s_tim1.o
	-@erase $(OutputPath)\main.o
	-@erase $(OutputPath)\stm8_interrupt_vector.o
	-@erase $(OutputPath)\bldc.elf
	-@erase $(OutputPath)\bldc.map
	-@erase $(OutputPath)\bldc.st7
	-@erase $(OutputPath)\bldc.s19
	-@erase $(OutputPath)\stm8s_clk.ls
	-@erase $(OutputPath)\stm8s_gpio.ls
	-@erase $(OutputPath)\stm8s_tim1.ls
	-@erase $(OutputPath)\main.ls
	-@erase $(OutputPath)\stm8_interrupt_vector.ls
endif
