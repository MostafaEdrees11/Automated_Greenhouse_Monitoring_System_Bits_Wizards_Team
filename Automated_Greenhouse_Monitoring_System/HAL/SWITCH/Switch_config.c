/**
 ******************************************************************************
 * @file           : Switch_config.c
 * @author         : Mostafa Edrees
 * @brief          : Configuration file of Switch.
 * @date           : 10/13/2023
 * @board          : ATMEGA32
 ******************************************************************************
**/

#include "../../MCAL/DIO/DIO_int.h"

#include "Switch_config.h"

SW_t SW_AstrSwitchConfig[SW_NUM] = 
{
	{DIO_u8PORTA, DIO_u8PIN0, DIO_u8PULL_UP},
	{DIO_u8PORTA, DIO_u8PIN1, DIO_u8PULL_UP},
};
