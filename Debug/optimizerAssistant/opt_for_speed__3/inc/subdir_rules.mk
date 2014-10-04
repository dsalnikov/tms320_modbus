################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
inc/DSP2802x_CpuTimers.obj: ../inc/DSP2802x_CpuTimers.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: C2000 Compiler'
	"c:/ti/ccsv6/tools/compiler/c2000_6.2.5/bin/cl2000" -v28 -ml -mt --opt_for_speed=3 --include_path="c:/ti/ccsv6/tools/compiler/c2000_6.2.5/include" --include_path="C:/Users/lamazavr/workspace_v6_0/tms320_sci/inc" -g --diag_warning=225 --display_error_number --diag_wrap=off --preproc_with_compile --preproc_dependency="inc/DSP2802x_CpuTimers.pp" --obj_directory="inc" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


