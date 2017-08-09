################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Each subdirectory must supply rules for building sources it contributes
rotate/move.obj: ../rotate/move.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=vfplib --abi=eabi -me --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/include" --include_path="C:/ti/CC3200SDK_1.1.0/cc3200-sdk/example/common" --include_path="C:/ti/CC3200SDK_1.1.0/cc3200-sdk/inc" --include_path="C:/ti/CC3200SDK_1.1.0/cc3200-sdk/simplelink/" --include_path="C:/ti/CC3200SDK_1.2.0/cc3200-sdk/simplelink_extlib/provisioninglib" --include_path="C:/ti/CC3200SDK_1.1.0/cc3200-sdk/simplelink/include" --include_path="C:/ti/CC3200SDK_1.1.0/cc3200-sdk/simplelink/source" --include_path="C:/ti/CC3200SDK_1.1.0/cc3200-sdk/driverlib/" --include_path="C:/ti/CC3200SDK_1.1.0/cc3200-sdk/oslib/" --include_path="C:/ti/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/" --include_path="C:/ti/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/source/" --include_path="C:/ti/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/source/include" --include_path="C:/ti/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/source/portable/CCS/ARM_CM3" -g --gcc --define=ccs --define=SL_PLATFORM_MULTI_THREADED --define=USE_FREERTOS --define=cc3200 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="rotate/move.d" --obj_directory="rotate" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '

rotate/rotate.obj: ../rotate/rotate.c $(GEN_OPTS) $(GEN_HDRS)
	@echo 'Building file: $<'
	@echo 'Invoking: ARM Compiler'
	"C:/ti/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=vfplib --abi=eabi -me --include_path="C:/ti/ccsv6/tools/compiler/ti-cgt-arm_15.12.1.LTS/include" --include_path="C:/ti/CC3200SDK_1.1.0/cc3200-sdk/example/common" --include_path="C:/ti/CC3200SDK_1.1.0/cc3200-sdk/inc" --include_path="C:/ti/CC3200SDK_1.1.0/cc3200-sdk/simplelink/" --include_path="C:/ti/CC3200SDK_1.2.0/cc3200-sdk/simplelink_extlib/provisioninglib" --include_path="C:/ti/CC3200SDK_1.1.0/cc3200-sdk/simplelink/include" --include_path="C:/ti/CC3200SDK_1.1.0/cc3200-sdk/simplelink/source" --include_path="C:/ti/CC3200SDK_1.1.0/cc3200-sdk/driverlib/" --include_path="C:/ti/CC3200SDK_1.1.0/cc3200-sdk/oslib/" --include_path="C:/ti/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/" --include_path="C:/ti/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/source/" --include_path="C:/ti/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/source/include" --include_path="C:/ti/CC3200SDK_1.1.0/cc3200-sdk/third_party/FreeRTOS/source/portable/CCS/ARM_CM3" -g --gcc --define=ccs --define=SL_PLATFORM_MULTI_THREADED --define=USE_FREERTOS --define=cc3200 --display_error_number --diag_warning=225 --diag_wrap=off --preproc_with_compile --preproc_dependency="rotate/rotate.d" --obj_directory="rotate" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: $<'
	@echo ' '


