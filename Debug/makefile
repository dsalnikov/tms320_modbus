################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

CG_TOOL_ROOT := c:/ti/ccsv6/tools/compiler/c2000_6.2.7

ORDERED_OBJS += \
$(GEN_CMDS__FLAG) \
"./DSP2802x_CodeStartBranch.obj" \
"./DSP2802x_DefaultIsr.obj" \
"./DSP2802x_EPwm.obj" \
"./DSP2802x_GlobalVariableDefs.obj" \
"./DSP2802x_PieCtrl.obj" \
"./DSP2802x_PieVect.obj" \
"./DSP2802x_SysCtrl.obj" \
"./DSP2802x_usDelay.obj" \
"./main.obj" \
"./inc/DSP2802x_CpuTimers.obj" \
"../28027_RAM_lnk.cmd" \
"../DSP2802x_Headers_nonBIOS.cmd" \
-l"libc.a" \

-include ../makefile.init

RM := DEL /F
RMDIR := RMDIR /S/Q

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir_vars.mk
-include inc/subdir_vars.mk
-include subdir_rules.mk
-include inc/subdir_rules.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(S62_DEPS)),)
-include $(S62_DEPS)
endif
ifneq ($(strip $(C64_DEPS)),)
-include $(C64_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(S55_DEPS)),)
-include $(S55_DEPS)
endif
ifneq ($(strip $(C67_DEPS)),)
-include $(C67_DEPS)
endif
ifneq ($(strip $(C??_DEPS)),)
-include $(C??_DEPS)
endif
ifneq ($(strip $(CLA_DEPS)),)
-include $(CLA_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(S??_DEPS)),)
-include $(S??_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C62_DEPS)),)
-include $(C62_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(ASM_UPPER_DEPS)),)
-include $(ASM_UPPER_DEPS)
endif
ifneq ($(strip $(K_DEPS)),)
-include $(K_DEPS)
endif
ifneq ($(strip $(C43_DEPS)),)
-include $(C43_DEPS)
endif
ifneq ($(strip $(S67_DEPS)),)
-include $(S67_DEPS)
endif
ifneq ($(strip $(SA_DEPS)),)
-include $(SA_DEPS)
endif
ifneq ($(strip $(S43_DEPS)),)
-include $(S43_DEPS)
endif
ifneq ($(strip $(OPT_DEPS)),)
-include $(OPT_DEPS)
endif
ifneq ($(strip $(S64_DEPS)),)
-include $(S64_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(C55_DEPS)),)
-include $(C55_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
EXE_OUTPUTS += \
tms320_modbus.out \

EXE_OUTPUTS__QUOTED += \
"tms320_modbus.out" \

BIN_OUTPUTS += \
tms320_modbus.hex \

BIN_OUTPUTS__QUOTED += \
"tms320_modbus.hex" \


# All Target
all: tms320_modbus.out

# Tool invocations
tms320_modbus.out: $(OBJS) $(CMD_SRCS) $(GEN_CMDS)
	@echo 'Building target: $@'
	@echo 'Invoking: C2000 Linker'
	"c:/ti/ccsv6/tools/compiler/c2000_6.2.7/bin/cl2000" -v28 -ml -mt -g --diag_warning=225 --display_error_number --diag_wrap=off -z -m"tms320_modbus.map" --stack_size=0x300 --warn_sections -i"c:/ti/ccsv6/tools/compiler/c2000_6.2.7/lib" -i"c:/ti/ccsv6/tools/compiler/c2000_6.2.7/include" --reread_libs --display_error_number --diag_wrap=off --xml_link_info="tms320_modbus_linkInfo.xml" --rom_model -o "tms320_modbus.out" $(ORDERED_OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

tms320_modbus.hex: $(EXE_OUTPUTS)
	@echo 'Invoking: C2000 Hex Utility'
	"c:/ti/ccsv6/tools/compiler/c2000_6.2.7/bin/hex2000"  -o "tms320_modbus.hex" $(EXE_OUTPUTS__QUOTED)
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXE_OUTPUTS__QUOTED)$(BIN_OUTPUTS__QUOTED)
	-$(RM) "DSP2802x_DefaultIsr.pp" "DSP2802x_EPwm.pp" "DSP2802x_GlobalVariableDefs.pp" "DSP2802x_PieCtrl.pp" "DSP2802x_PieVect.pp" "DSP2802x_SysCtrl.pp" "main.pp" "inc\DSP2802x_CpuTimers.pp" 
	-$(RM) "DSP2802x_CodeStartBranch.obj" "DSP2802x_DefaultIsr.obj" "DSP2802x_EPwm.obj" "DSP2802x_GlobalVariableDefs.obj" "DSP2802x_PieCtrl.obj" "DSP2802x_PieVect.obj" "DSP2802x_SysCtrl.obj" "DSP2802x_usDelay.obj" "main.obj" "inc\DSP2802x_CpuTimers.obj" 
	-$(RM) "DSP2802x_CodeStartBranch.pp" "DSP2802x_usDelay.pp" 
	-@echo 'Finished clean'
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets

