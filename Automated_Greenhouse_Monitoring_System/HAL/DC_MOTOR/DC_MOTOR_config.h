/*
 * DC_MOTOR_config.h
 *
 *  Created on: Jul 5, 2024
 *      Author: Mostafa Edrees
 */

#ifndef HAL_DC_MOTOR_DC_MOTOR_CONFIG_H_
#define HAL_DC_MOTOR_DC_MOTOR_CONFIG_H_

/* specify the number of Dc Motors */
#define DC_MOTOR_NUM				1


/* configuration of Dc Motor states */
#define DC_MOTOR_u8ON			10
#define DC_MOTOR_u8OFF			11

#define MOTOR_1   0
#define MOTOR_2   1
#define MOTOR_3   2
#define MOTOR_4   3
#define MOTOR_5   4
#define MOTOR_6   5
#define MOTOR_7   6
#define MOTOR_8   7

typedef enum
{
	Disable_Motor,
	Enable_Motor
}DC_MOTOR_STATE_t;

typedef struct
{
	u8 DC_MOTOR_u8In1PortID;
	u8 DC_MOTOR_u8In1PinID;

	u8 DC_MOTOR_u8In2PortID;
	u8 DC_MOTOR_u8In2PinID;
}DC_MOTOR_t;

#endif /* HAL_DC_MOTOR_DC_MOTOR_CONFIG_H_ */
