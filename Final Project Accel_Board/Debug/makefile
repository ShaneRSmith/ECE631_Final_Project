################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include startup/subdir.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: Final\ Project\ Accel_Board.elf

dependents:
	-cd E:/Final\ Project/stm32f411e-disco_stdperiph_lib/Debug && $(MAKE) all

# Tool invocations
Final\ Project\ Accel_Board.elf: $(OBJS) $(USER_OBJS) E:/Final\ Project/stm32f411e-disco_stdperiph_lib/Debug/libstm32f411e-disco_stdperiph_lib.a
	@echo 'Building target: $@'
	@echo 'Invoking: MCU GCC Linker'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -L"E:\Final Project\stm32f411e-disco_stdperiph_lib\Debug" -T"E:\Final Project\Final Project Accel_Board\LinkerScript.ld" -Wl,-Map=output.map -Wl,--gc-sections -lm -o "Final Project Accel_Board.elf" @"objects.list" $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

post-build:
	-@echo 'Generating binary and Printing size information:'
	arm-none-eabi-objcopy -O binary "Final Project Accel_Board.elf" "Final Project Accel_Board.bin"
	arm-none-eabi-size "Final Project Accel_Board.elf"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build
E:/Final\ Project/stm32f411e-disco_stdperiph_lib/Debug/libstm32f411e-disco_stdperiph_lib.a:

-include ../makefile.targets
