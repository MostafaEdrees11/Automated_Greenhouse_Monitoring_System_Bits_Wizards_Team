################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/Soil\ Moisture\ Sensor/Soil_Moisture_config.c \
../HAL/Soil\ Moisture\ Sensor/Soil_Moisture_prog.c 

OBJS += \
./HAL/Soil\ Moisture\ Sensor/Soil_Moisture_config.o \
./HAL/Soil\ Moisture\ Sensor/Soil_Moisture_prog.o 

C_DEPS += \
./HAL/Soil\ Moisture\ Sensor/Soil_Moisture_config.d \
./HAL/Soil\ Moisture\ Sensor/Soil_Moisture_prog.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/Soil\ Moisture\ Sensor/Soil_Moisture_config.o: ../HAL/Soil\ Moisture\ Sensor/Soil_Moisture_config.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"HAL/Soil Moisture Sensor/Soil_Moisture_config.d" -MT"HAL/Soil\ Moisture\ Sensor/Soil_Moisture_config.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

HAL/Soil\ Moisture\ Sensor/Soil_Moisture_prog.o: ../HAL/Soil\ Moisture\ Sensor/Soil_Moisture_prog.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"HAL/Soil Moisture Sensor/Soil_Moisture_prog.d" -MT"HAL/Soil\ Moisture\ Sensor/Soil_Moisture_prog.d" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


