/*
 * BUZZER_config.h
 *
 *  Created on: Jul 5, 2024
 *      Author: Mostafa Edrees
 */

#ifndef HAL_BUZZER_BUZZER_CONFIG_H_
#define HAL_BUZZER_BUZZER_CONFIG_H_

#include "../../MCAL/DIO/DIO_int.h"

/* specify the number of buzzers */
#define BUZZER_NUM				1


/* configuration of buzzer states */
#define BUZZER_u8ON				10
#define BUZZER_u8OFF			11

typedef struct
{
	/* BUZZER_u8PortID --> must specify according to @ref configuration of names of 4 ports at DIO_int.h */
	u8 BUZZER_u8PortID;

	/* BUZZER_u8PinID --> must specify according to @ref configuration of names of pins at DIO_int.h */
	u8 BUZZER_u8PinID;

	/* BUZZER_u8InitState --> must specify according to @ref configuration of led connection states at BUZZER_config.h */
	u8 BUZZER_u8InitState;
}BUZZER_t;

#endif /* HAL_BUZZER_BUZZER_CONFIG_H_ */
