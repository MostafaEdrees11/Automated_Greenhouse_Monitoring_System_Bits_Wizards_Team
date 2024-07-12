################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../APP/Automatic_Control/Automatic_Control_prog.c 

OBJS += \
./APP/Automatic_Control/Automatic_Control_prog.o 

C_DEPS += \
./APP/Automatic_Control/Automatic_Control_prog.d 


# Each subdirectory must supply rules for building sources it contributes
APP/Automatic_Control/%.o: ../APP/Automatic_Control/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


