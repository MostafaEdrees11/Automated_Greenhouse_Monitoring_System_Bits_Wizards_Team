/*
 * I2C_Prog.c
 *
 *  Created on: Jul 4, 2024
 *      Author: Samar Ibrahim
 */



#include "../../LIB/Error_States.h"
#include "../../LIB/stdTypes.h"
#include "I2C_Config.h"
#include "I2C_Priv.h"



ES_t I2C_enuInitMaster	(void)
{
	ES_t Local_enuErrorState = ES_NOK;

#if I2C_PRESCALER == I2C_PRESCALER_1
	SET_I2C_PRESCALER_1;
	SET_TWBR_VALUE;
	SET_I2C_ENABLE;
	Local_enuErrorState = ES_OK;

#elif I2C_PRESCALER == I2C_PRESCALER_4
	SET_I2C_PRESCALER_4;
	SET_TWBR_VALUE;
	SET_I2C_ENABLE;
	Local_enuErrorState = ES_OK;

#elif I2C_PRESCALER == I2C_PRESCALER_16
	SET_I2C_PRESCALER_16;
	SET_TWBR_VALUE;
	SET_I2C_ENABLE;
	Local_enuErrorState = ES_OK;

#elif I2C_PRESCALER == I2C_PRESCALER_64
	SET_I2C_PRESCALER_64;
	SET_TWBR_VALUE;
	SET_I2C_ENABLE;
	Local_enuErrorState = ES_OK;

#else
#error"The Selection of I2C_PRESCALER is Wrong"
#endif

	return Local_enuErrorState ;
}



ES_t I2C_enuInitSlave	(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	SET_ECU_ADDRESS;
	SET_I2C_ENABLE;
	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}



ES_t I2C_enuStartCondition	(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	SET_START_CONDITION;
	CLEAR_FLAG;
	while (WAIT_FLAG);
	if (START_CONDITION_TRANSMIT)
		Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}




ES_t I2C_enuRepeatStartCondition	(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	SET_START_CONDITION;
	CLEAR_FLAG;
	while (WAIT_FLAG);
	if (REPEAT_START_CONDITION_TRANSMIT)
		Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}



ES_t I2C_enuStopCondition	(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	SET_STOP_CONDITION;
	CLEAR_FLAG;
	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}



ES_t I2C_enuSendSlaveAddress	(u8 Copy_u8SlaveAddress , u8 Copy_u8Action)
{
	ES_t Local_enuErrorState = ES_NOK;


	if (Copy_u8SlaveAddress <= I2C_MAX_SLAVES) SET_SLAVE_ADDRESS(Copy_u8SlaveAddress);
	if (Copy_u8Action <= I2C_ONE)              SET_SLAVE_ACTION (Copy_u8Action);
	CLEAR_START_CONDITION;
	CLEAR_FLAG;
	while (WAIT_FLAG);
	if (SLA_WRITE_TRANSMIT)
		Local_enuErrorState = ES_OK;

	else if (SLA_READ_TRANSMIT)
		Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}



ES_t I2C_enuSlaveCheckItsAdress (void)
{
	ES_t Local_enuErrorState = ES_NOK;

	SET_ACKNOWLEDGE;
	CLEAR_FLAG;
	while (WAIT_FLAG);
	if (SLAVE_WRITE_RECIEVE_ADDRESS)
		Local_enuErrorState = ES_OK;
	else if(SLAVE_READ_RECIEVE_ADDRESS)
		Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}




ES_t I2C_enuMasterSendData	(u8 Copy_u8Data)
{
	ES_t Local_enuErrorState = ES_NOK;

	TWDR=Copy_u8Data;
	CLEAR_FLAG;
	while (WAIT_FLAG);
	if (MASTER_DATA_TRANSMIT)
		Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}


ES_t I2C_enuSlaveRecieveData	(u8 * Copy_Pu8Data)
{
	ES_t Local_enuErrorState = ES_NOK;

	CLEAR_FLAG;
	while (WAIT_FLAG);
	if (SLAVE_DATA_RECIEVED)
	{
		*Copy_Pu8Data=TWDR; //RECIEVE_DATA
		Local_enuErrorState = ES_OK;
	}

	return Local_enuErrorState;
}
