/*
 * DC_MOTOR_config.c
 *
 *  Created on: Jul 5, 2024
 *      Author: Mostafa Edrees
 */


#include "../../MCAL/DIO/DIO_int.h"

#include "DC_MOTOR_config.h"

DC_MOTOR_t DC_MOTOR_AstrDcMotorConfig[DC_MOTOR_NUM] =
{
	{DIO_u8PORTC, DIO_u8PIN0, DIO_u8PORTC, DIO_u8PIN1}
};
