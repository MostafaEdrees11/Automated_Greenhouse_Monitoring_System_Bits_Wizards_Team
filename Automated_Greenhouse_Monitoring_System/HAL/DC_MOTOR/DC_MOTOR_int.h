/*
 * DC_MOTOR_int.h
 *
 *  Created on: Jul 5, 2024
 *      Author: Mostafa Edrees
 */

#ifndef HAL_DC_MOTOR_DC_MOTOR_INT_H_
#define HAL_DC_MOTOR_DC_MOTOR_INT_H_


ES_t DC_MOTOR_enuInit(DC_MOTOR_t *Copy_pAstrDcMotorConfig);

ES_t DC_MOTOR_enuOnCW(u8 Copy_u8DcMotorID);

ES_t DC_MOTOR_enuOnCCW(u8 Copy_u8DcMotorID);

ES_t DC_MOTOR_enuOff(u8 Copy_u8DcMotorID);

/*Speed 0:100*/
ES_t DC_MOTOR_SetSpeed(u8 Copy_u8DcMotorID, u8 Copy_u8DcMotorSpeed);

#endif /* HAL_DC_MOTOR_DC_MOTOR_INT_H_ */
