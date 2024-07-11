/**
 ******************************************************************************
 * @file           : LED_config.c
 * @author         : Mostafa Edrees
 * @brief          : Configuration file of LED.
 * @date           : 10/13/2023
 * @board          : ATMEGA32
 ******************************************************************************
**/

#include "../../MCAL/DIO/DIO_int.h"

#include "LED_config.h"

LED_t LED_AstrLedConfig[LED_NUM] = 
{
	{DIO_u8PORTC, DIO_u8PIN6, LED_u8SOURCE, LED_u8OFF, LED_PWM_NONE},
	{DIO_u8PORTB, DIO_u8PIN3, LED_u8SOURCE, LED_u8OFF, LED_PWM_OC0},
	{DIO_u8PORTC, DIO_u8PIN5, LED_u8SOURCE, LED_u8OFF, LED_PWM_NONE}
};
