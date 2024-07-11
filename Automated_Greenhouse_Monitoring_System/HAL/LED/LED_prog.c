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

#include "../../MCAL/TIMER0/TIMER0_int.h"
#include "../../MCAL/TIMER1/TIMER1_int.h"
#include "../../MCAL/TIMER2/TIMER2_int.h"

#include "LED_int.h"
#include "LED_config.h"
#include "LED_priv.h"

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

ES_t LED_enuSetIntensity(u8 Copy_u8LedID, u8 Copy_u8LightIntensity)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_u8LedID < LED_NUM && Copy_u8LightIntensity <= 100)
	{
		if(Copy_u8LightIntensity == 0)
			DIO_enuSetPinVal(LED_AstrLedConfig[Copy_u8LedID].LED_u8PortID, LED_AstrLedConfig[Copy_u8LedID].LED_u8PinID, DIO_u8LOW);
		else if(Copy_u8LightIntensity == 100)
			DIO_enuSetPinVal(LED_AstrLedConfig[Copy_u8LedID].LED_u8PortID, LED_AstrLedConfig[Copy_u8LedID].LED_u8PinID, DIO_u8HIGH);
		else
		{
			switch(LED_AstrLedConfig[Copy_u8LedID].LED_enuPWM)
			{
			case LED_PWM_NONE:
				Local_enuErrorState = ES_NOK;
				break;

			case LED_PWM_OC0:
				TIMER0_enuGeneratePWM(Copy_u8LightIntensity);
				Local_enuErrorState = ES_OK;
				break;

			case LED_PWM_OC1A:
				TIMER1_enuGeneratePWM_OCR1A(Copy_u8LightIntensity);
				Local_enuErrorState = ES_OK;
				break;

			case LED_PWM_OC1B:
				TIMER1_enuGeneratePWM_OCR1B(Copy_u8LightIntensity);
				Local_enuErrorState = ES_OK;
				break;

			case LED_PWM_OC2:
				TIMER2_enuGeneratePWM(Copy_u8LightIntensity);
				Local_enuErrorState = ES_OK;
				break;

			default:
				Local_enuErrorState = ES_NOK;
				break;
			}
		}
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}
