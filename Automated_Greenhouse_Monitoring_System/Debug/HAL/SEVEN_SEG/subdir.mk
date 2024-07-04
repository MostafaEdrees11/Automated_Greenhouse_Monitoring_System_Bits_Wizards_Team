################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/SEVEN_SEG/Seven_Segment_config.c \
../HAL/SEVEN_SEG/Seven_Segment_prog.c 

OBJS += \
./HAL/SEVEN_SEG/Seven_Segment_config.o \
./HAL/SEVEN_SEG/Seven_Segment_prog.o 

C_DEPS += \
./HAL/SEVEN_SEG/Seven_Segment_config.d \
./HAL/SEVEN_SEG/Seven_Segment_prog.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/SEVEN_SEG/%.o: ../HAL/SEVEN_SEG/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


