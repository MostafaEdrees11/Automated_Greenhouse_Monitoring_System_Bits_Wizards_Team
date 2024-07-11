/*
 * DC_MOTOR_config.c
 *
 *  Created on: Jul 5, 2024
 *      Author: Fathy Anas
 */


#include "../../MCAL/DIO/DIO_int.h"

#include "DC_MOTOR_config.h"

DC_MOTOR_t DC_MOTOR_AstrDcMotorConfig[DC_MOTOR_NUM] =
{
	{DIO_u8PORTB, DIO_u8PIN0, DIO_u8PORTB, DIO_u8PIN1, PWM_OC1B},	//Fan
	{DIO_u8PORTB, DIO_u8PIN4, DIO_u8PORTB, DIO_u8PIN5, PWM_OC1A},	//Heater
	{DIO_u8PORTB, DIO_u8PIN6, DIO_u8PORTB, DIO_u8PIN7, PWM_OC2}		//Pump
};
