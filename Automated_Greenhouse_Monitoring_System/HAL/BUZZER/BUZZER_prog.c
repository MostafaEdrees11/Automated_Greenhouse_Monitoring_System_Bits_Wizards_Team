/*
 * BUZZER_prog.c
 *
 *  Created on: Jul 5, 2024
 *      Author: Mostafa Edrees
 */


#include "../../LIB/Error_States.h"
#include "../../LIB/stdTypes.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "BUZZER_priv.h"
#include "BUZZER_config.h"

extern BUZZER_t BUZZER_AstrBuzzerConfig[BUZZER_NUM];

ES_t BUZZER_enuInit(BUZZER_t *Copy_pAstrBuzzerConfig)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_pAstrBuzzerConfig != NULL)
	{
		u8 Local_u8Iterator;
		for(Local_u8Iterator = 0; Local_u8Iterator < BUZZER_NUM; Local_u8Iterator++)
		{
			DIO_enuSetPinDirection(Copy_pAstrBuzzerConfig[Local_u8Iterator].BUZZER_u8PortID, Copy_pAstrBuzzerConfig[Local_u8Iterator].BUZZER_u8PinID, DIO_u8OUTPUT);
			if(Copy_pAstrBuzzerConfig[Local_u8Iterator].BUZZER_u8InitState == BUZZER_u8ON)
			{
				Local_enuErrorState = DIO_enuSetPinVal(Copy_pAstrBuzzerConfig[Local_u8Iterator].BUZZER_u8PortID, Copy_pAstrBuzzerConfig[Local_u8Iterator].BUZZER_u8PinID, DIO_u8HIGH);
			}
			else if(Copy_pAstrBuzzerConfig[Local_u8Iterator].BUZZER_u8InitState == BUZZER_u8OFF)
			{
				Local_enuErrorState = DIO_enuSetPinVal(Copy_pAstrBuzzerConfig[Local_u8Iterator].BUZZER_u8PortID, Copy_pAstrBuzzerConfig[Local_u8Iterator].BUZZER_u8PinID, DIO_u8LOW);
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

ES_t BUZZER_enuTurnON(u8 Copy_u8BuzzerID)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_u8BuzzerID < BUZZER_NUM)
	{
		DIO_enuSetPinDirection(BUZZER_AstrBuzzerConfig[Copy_u8BuzzerID].BUZZER_u8PortID, BUZZER_AstrBuzzerConfig[Copy_u8BuzzerID].BUZZER_u8PinID, DIO_u8OUTPUT);
		Local_enuErrorState = DIO_enuSetPinVal(BUZZER_AstrBuzzerConfig[Copy_u8BuzzerID].BUZZER_u8PortID, BUZZER_AstrBuzzerConfig[Copy_u8BuzzerID].BUZZER_u8PinID, DIO_u8HIGH);
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}

ES_t BUZZER_enuTurnOFF(u8 Copy_u8BuzzerID)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_u8BuzzerID < BUZZER_NUM)
	{
		DIO_enuSetPinDirection(BUZZER_AstrBuzzerConfig[Copy_u8BuzzerID].BUZZER_u8PortID, BUZZER_AstrBuzzerConfig[Copy_u8BuzzerID].BUZZER_u8PinID, DIO_u8OUTPUT);
		Local_enuErrorState = DIO_enuSetPinVal(BUZZER_AstrBuzzerConfig[Copy_u8BuzzerID].BUZZER_u8PortID, BUZZER_AstrBuzzerConfig[Copy_u8BuzzerID].BUZZER_u8PinID, DIO_u8LOW);
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}
