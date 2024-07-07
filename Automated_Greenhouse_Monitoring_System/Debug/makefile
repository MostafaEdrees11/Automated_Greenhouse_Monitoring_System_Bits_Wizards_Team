################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/USART/subdir.mk
-include MCAL/TIMER1/subdir.mk
-include MCAL/TIMER0/subdir.mk
-include MCAL/SPI/subdir.mk
-include MCAL/I2C/subdir.mk
-include MCAL/GIE/subdir.mk
-include MCAL/EXTI/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/Soil\ Moisture\ Sensor/subdir.mk
-include HAL/SWITCH/subdir.mk
-include HAL/SEVEN_SEG/subdir.mk
-include HAL/LED/subdir.mk
-include HAL/LDR/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/KEYPAD/subdir.mk
-include HAL/DC_MOTOR/subdir.mk
-include HAL/BUZZER/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Automated_Greenhouse_Monitoring_System.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: Automated_Greenhouse_Monitoring_System.elf secondary-outputs

# Tool invocations
Automated_Greenhouse_Monitoring_System.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Automated_Greenhouse_Monitoring_System.map -mmcu=atmega32 -o "Automated_Greenhouse_Monitoring_System.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Automated_Greenhouse_Monitoring_System.lss: Automated_Greenhouse_Monitoring_System.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Automated_Greenhouse_Monitoring_System.elf  >"Automated_Greenhouse_Monitoring_System.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Automated_Greenhouse_Monitoring_System.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Automated_Greenhouse_Monitoring_System.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Automated_Greenhouse_Monitoring_System.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
