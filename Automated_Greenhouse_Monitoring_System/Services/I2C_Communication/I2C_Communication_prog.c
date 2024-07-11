/*
 * I2C_Communication_prog.c
 *
 *  Created on: Jul 8, 2024
 *      Author: Mostafa Edrees
 */

#include "../../LIB/Error_States.h"
#include "../../LIB/stdTypes.h"

#include "../../MCAL/I2C/I2C_int.h"

#include "I2C_Communication_int.h"
#include "I2C_Communication_config.h"
#include "I2C_Communication_priv.h"


ES_t Communication_enuInitMaster(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	Local_enuErrorState = I2C_enuInitMaster();

	return Local_enuErrorState;
}

ES_t Communication_enuInitSlave(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	Local_enuErrorState = I2C_enuInitSlave();

	return Local_enuErrorState;
}

ES_t Communication_enuSendFrame(Communication_Frame_t *Copy_uniSentFrame)
{
	ES_t Local_enuErrorState = ES_NOK;

	Local_enuErrorState = I2C_enuStartCondition();

	Copy_uniSentFrame->Check_Sum = Copy_uniSentFrame->Temp + Copy_uniSentFrame->Humi + Copy_uniSentFrame->Soil + Copy_uniSentFrame->LDRI + Copy_uniSentFrame->State;

	if(Local_enuErrorState == ES_OK)
	{
		Local_enuErrorState = I2C_enuSendSlaveAddress(Slave_Address, 0);

		if(Local_enuErrorState == ES_OK)
		{
			for(u8 Local_u8Iterator = 0; Local_u8Iterator < 6; Local_u8Iterator++)
			{
				Local_enuErrorState = I2C_enuMasterSendData(Copy_uniSentFrame->Data[Local_u8Iterator]);
				if(Local_enuErrorState == ES_OK)
				{
					continue;
				}
				else
				{
					Local_enuErrorState = ES_NOK;
					break;
				}
			}
		}
		else
		{
			Local_enuErrorState = ES_NOK;
		}


	}
	else
	{
		Local_enuErrorState = ES_NOK;
	}

	I2C_enuStopCondition();

	return Local_enuErrorState;
}

ES_t Communication_enuReceiveFrame(Communication_Frame_t *Copy_uniReceivedFrame)
{
	ES_t Local_enuErrorState = ES_NOK;

	Local_enuErrorState = I2C_enuSlaveCheckItsAdress();

	u8 Local_u8CheckSum = 0;

	if(Local_enuErrorState == ES_OK)
	{
		for(u8 Local_u8Iterator = 0; Local_u8Iterator < 6; Local_u8Iterator++)
		{
			Local_enuErrorState = I2C_enuSlaveRecieveData(&Copy_uniReceivedFrame->Data[Local_u8Iterator]);
			if(Local_enuErrorState == ES_OK)
			{

				continue;
			}
			else
			{
				Local_enuErrorState = ES_NOK;
				break;
			}
		}


		Local_u8CheckSum = Copy_uniReceivedFrame->Temp + Copy_uniReceivedFrame->Humi + Copy_uniReceivedFrame->Soil + Copy_uniReceivedFrame->LDRI + Copy_uniReceivedFrame->State;

		if(Local_u8CheckSum == Copy_uniReceivedFrame->Check_Sum)
		{
			Local_enuErrorState = ES_OK;
		}
		else
		{
			Local_enuErrorState = ES_NOK;
		}
	}

	return Local_enuErrorState;
}
