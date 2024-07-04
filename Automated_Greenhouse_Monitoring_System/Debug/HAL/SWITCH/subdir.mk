################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/SWITCH/Switch_config.c \
../HAL/SWITCH/Switch_prog.c 

OBJS += \
./HAL/SWITCH/Switch_config.o \
./HAL/SWITCH/Switch_prog.o 

C_DEPS += \
./HAL/SWITCH/Switch_config.d \
./HAL/SWITCH/Switch_prog.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/SWITCH/%.o: ../HAL/SWITCH/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


