################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/USART.c \
../src/circ_buff.c \
../src/dump.c \
../src/error.c \
../src/hashtable.c \
../src/hashtable_seed.c \
../src/json_coms.c \
../src/load.c \
../src/main.c \
../src/memory.c \
../src/pack_unpack.c \
../src/state_machine.c \
../src/strbuffer.c \
../src/strconv.c \
../src/syscalls.c \
../src/system_stm32f4xx.c \
../src/utf.c \
../src/value.c 

OBJS += \
./src/USART.o \
./src/circ_buff.o \
./src/dump.o \
./src/error.o \
./src/hashtable.o \
./src/hashtable_seed.o \
./src/json_coms.o \
./src/load.o \
./src/main.o \
./src/memory.o \
./src/pack_unpack.o \
./src/state_machine.o \
./src/strbuffer.o \
./src/strconv.o \
./src/syscalls.o \
./src/system_stm32f4xx.o \
./src/utf.o \
./src/value.o 

C_DEPS += \
./src/USART.d \
./src/circ_buff.d \
./src/dump.d \
./src/error.d \
./src/hashtable.d \
./src/hashtable_seed.d \
./src/json_coms.d \
./src/load.d \
./src/main.d \
./src/memory.d \
./src/pack_unpack.d \
./src/state_machine.d \
./src/strbuffer.d \
./src/strconv.d \
./src/syscalls.d \
./src/system_stm32f4xx.d \
./src/utf.d \
./src/value.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo %cd%
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32F411VETx -DSTM32F4 -DSTM32 -DSTM32F411E_DISCO -DDEBUG -DUSE_STDPERIPH_DRIVER -DSTM32F411xE -DHAVE_STD_INT.H -I"E:/Final Project/stm32f411e-disco_stdperiph_lib" -I"E:/Final Project/Final Project Accel_Board/inc" -I"E:/Final Project/stm32f411e-disco_stdperiph_lib/CMSIS/core" -I"E:/Final Project/stm32f411e-disco_stdperiph_lib/CMSIS/device" -I"E:/Final Project/stm32f411e-disco_stdperiph_lib/StdPeriph_Driver/inc" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


