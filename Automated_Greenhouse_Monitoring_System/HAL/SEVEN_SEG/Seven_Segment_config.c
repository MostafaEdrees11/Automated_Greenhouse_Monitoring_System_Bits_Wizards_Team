/**
 ******************************************************************************
 * @file           : Seven_Segment_config.c
 * @author         : Mostafa Edrees
 * @brief          : Configuration file of Seven Segment.
 * @date           : 10/20/2023
 * @board          : ATMEGA32
 ******************************************************************************
**/

#include "../../MCAL/DIO/DIO_int.h"

#include "Seven_Segment_config.h"
#include "Seven_Segment_priv.h"

SEG_t SEV_SEG_AstrSEGConfig[SEG_NUM] = 
{
	{
		DIO_u8PORTA, DIO_u8PIN0,
		DIO_u8PORTA, DIO_u8PIN1,
		DIO_u8PORTA, DIO_u8PIN2,
		DIO_u8PORTA, DIO_u8PIN3,
		DIO_u8PORTA, DIO_u8PIN4,
		DIO_u8PORTA, DIO_u8PIN5,
		DIO_u8PORTA, DIO_u8PIN6,
		NOT_CONNECTED, NOT_CONNECTED,
		NOT_CONNECTED, NOT_CONNECTED,
		COMMON_CATHODE
	},
	
	{
		DIO_u8PORTC, DIO_u8PIN0,
		DIO_u8PORTC, DIO_u8PIN1,
		DIO_u8PORTC, DIO_u8PIN2,
		DIO_u8PORTC, DIO_u8PIN3,
		DIO_u8PORTC, DIO_u8PIN4,
		DIO_u8PORTC, DIO_u8PIN5,
		DIO_u8PORTC, DIO_u8PIN6,
		NOT_CONNECTED, NOT_CONNECTED,
		NOT_CONNECTED, NOT_CONNECTED,
		COMMON_CATHODE
	}
};