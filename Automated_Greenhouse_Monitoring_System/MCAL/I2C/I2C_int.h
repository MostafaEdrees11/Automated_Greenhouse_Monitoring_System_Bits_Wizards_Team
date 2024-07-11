/*
 * I2C_int.h
 *
 *  Created on: Jul 4, 2024
 *      Author: samar ibrahim
 */

#ifndef MCAL_I2C_I2C_INT_H_
#define MCAL_I2C_I2C_INT_H_
#include "../../LIB/Error_States.h"
#include "../../LIB/stdTypes.h"
ES_t I2C_enuInitMaster	(void);

ES_t I2C_enuInitSlave	(void);

ES_t I2C_enuStartCondition	(void);

ES_t I2C_enuRepeatStartCondition	(void);

ES_t I2C_enuStopCondition	(void);

ES_t I2C_enuSendSlaveAddress	(u8 Copy_u8SlaveAddress , u8 Copy_u8Action);

ES_t I2C_enuSlaveCheckItsAdress (void);

ES_t I2C_enuMasterSendData	(u8 Copy_u8Data);

ES_t I2C_enuSlaveRecieveData	(u8 * Copy_Pu8Data);


#endif /* MCAL_I2C_I2C_INT_H_ */
