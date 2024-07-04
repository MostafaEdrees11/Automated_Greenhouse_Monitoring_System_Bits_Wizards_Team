/**
 ******************************************************************************
 * @file           : LED_prog.c
 * @author         : Mostafa Edrees
 * @brief          : program file of LED.
 * @date           : 10/13/2023
 * @board          : ATMEGA32
 ******************************************************************************
**/

#include "../../LIB/Error_States.h"
#include "../../LIB/stdTypes.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "LED_priv.h"
#include "LED_config.h"

ES_t LED_enuINIT(LED_t *Copy_pAstrLedConfig)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	if(Copy_pAstrLedConfig != NULL)
	{
		u8 Local_u8Iterator;
		for(Local_u8Iterator = 0; Local_u8Iterator < LED_NUM; Local_u8Iterator++)
		{
			DIO_enuSetPinDirection(Copy_pAstrLedConfig[Local_u8Iterator].LED_u8PortID, Copy_pAstrLedConfig[Local_u8Iterator].LED_u8PinID, DIO_u8OUTPUT);
			if(Copy_pAstrLedConfig[Local_u8Iterator].LED_u8Connection == LED_u8SINK)
			{
				if(Copy_pAstrLedConfig[Local_u8Iterator].LED_u8InitState == LED_u8ON)
				{
					Local_enuErrorState = DIO_enuSetPinVal(Copy_pAstrLedConfig[Local_u8Iterator].LED_u8PortID, Copy_pAstrLedConfig[Local_u8Iterator].LED_u8PinID, DIO_u8LOW);
				}
				else if(Copy_pAstrLedConfig[Local_u8Iterator].LED_u8InitState == LED_u8OFF)
				{
					Local_enuErrorState = DIO_enuSetPinVal(Copy_pAstrLedConfig[Local_u8Iterator].LED_u8PortID, Copy_pAstrLedConfig[Local_u8Iterator].LED_u8PinID, DIO_u8HIGH);
				}
				else
				{
					Local_enuErrorState = ES_OUT_OF_RANGE;
				}
			}
			else if(Copy_pAstrLedConfig[Local_u8Iterator].LED_u8Connection == LED_u8SOURCE)
			{
				if(Copy_pAstrLedConfig[Local_u8Iterator].LED_u8InitState == LED_u8ON)
				{
					Local_enuErrorState = DIO_enuSetPinVal(Copy_pAstrLedConfig[Local_u8Iterator].LED_u8PortID, Copy_pAstrLedConfig[Local_u8Iterator].LED_u8PinID, DIO_u8HIGH);
				}
				else if(Copy_pAstrLedConfig[Local_u8Iterator].LED_u8InitState == LED_u8OFF)
				{
					Local_enuErrorState = DIO_enuSetPinVal(Copy_pAstrLedConfig[Local_u8Iterator].LED_u8PortID, Copy_pAstrLedConfig[Local_u8Iterator].LED_u8PinID, DIO_u8LOW);
				}
				else
				{
					Local_enuErrorState = ES_OUT_OF_RANGE;
				}
			}
			else
			{
				Local_enuErrorState = ES_OUT_OF_RANGE;
			}
		}
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}
	
	return Local_enuErrorState;
}

ES_t LED_enuTurnON(LED_t *Copy_pstrLedID)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	if(Copy_pstrLedID != NULL)
	{
		DIO_enuSetPinDirection(Copy_pstrLedID->LED_u8PortID, Copy_pstrLedID->LED_u8PinID, DIO_u8OUTPUT);
		if(Copy_pstrLedID->LED_u8Connection == LED_u8SINK)
		{
			Local_enuErrorState = DIO_enuSetPinVal(Copy_pstrLedID->LED_u8PortID, Copy_pstrLedID->LED_u8PinID, DIO_u8LOW);
		}
		else if(Copy_pstrLedID->LED_u8Connection == LED_u8SOURCE)
		{
			Local_enuErrorState = DIO_enuSetPinVal(Copy_pstrLedID->LED_u8PortID, Copy_pstrLedID->LED_u8PinID, DIO_u8HIGH);
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}
	
	return Local_enuErrorState;
}

ES_t LED_enuTurnOFF(LED_t *Copy_pstrLedID)
{
	ES_t Local_enuErrorState = ES_NOK;
	
	if(Copy_pstrLedID != NULL)
	{
		DIO_enuSetPinDirection(Copy_pstrLedID->LED_u8PortID, Copy_pstrLedID->LED_u8PinID, DIO_u8OUTPUT);
		if(Copy_pstrLedID->LED_u8Connection == LED_u8SINK)
		{
			Local_enuErrorState = DIO_enuSetPinVal(Copy_pstrLedID->LED_u8PortID, Copy_pstrLedID->LED_u8PinID, DIO_u8HIGH);
		}
		else if(Copy_pstrLedID->LED_u8Connection == LED_u8SOURCE)
		{
			Local_enuErrorState = DIO_enuSetPinVal(Copy_pstrLedID->LED_u8PortID, Copy_pstrLedID->LED_u8PinID, DIO_u8LOW);
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}
	
	return Local_enuErrorState;
}
