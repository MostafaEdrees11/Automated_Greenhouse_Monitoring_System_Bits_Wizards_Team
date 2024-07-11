################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Services/I2C_Communication/I2C_Communication_prog.c 

OBJS += \
./Services/I2C_Communication/I2C_Communication_prog.o 

C_DEPS += \
./Services/I2C_Communication/I2C_Communication_prog.d 


# Each subdirectory must supply rules for building sources it contributes
Services/I2C_Communication/%.o: ../Services/I2C_Communication/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


