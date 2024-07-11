/*
 * Soil_Moisture_prog.c
 *
 *  Created on: Jul 5, 2024
 *      Author: Mostafa Edrees
 */

#include "../../LIB/Error_States.h"
#include "../../LIB/stdTypes.h"
#include "../../LIB/Math.h"

#include "../../MCAL/ADC/ADC_config.h"
#include "../../MCAL/ADC/ADC_int.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "Soil_Moisture_config.h"
#include "Soil_Moisture_priv.h"

extern Soil_Moisture_Configuration_t Soil_Moisture_AstrSoilMoistureConfig[Soil_Moisture_NUM];

ES_t Soil_Moisture_enuInit(Soil_Moisture_Configuration_t *Copy_PstrSoilMoistureConfig)
{
	ES_t Local_enuErrorState = ES_NOK;

	ADC_enuInit();

	u8 Local_u8Iterrator = 0;
	for(Local_u8Iterrator = 0; Local_u8Iterrator < Soil_Moisture_NUM; Local_u8Iterrator++)
	{
		DIO_enuSetPinDirection(DIO_u8PORTA, Copy_PstrSoilMoistureConfig[Local_u8Iterrator].Soil_Moisture_CHANNEL, DIO_u8INPUT);
		ADC_enuSelectChannel(Copy_PstrSoilMoistureConfig[Local_u8Iterrator].Soil_Moisture_CHANNEL);
	}

	ADC_enuEnable();

	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}

ES_t Soil_Moisture_enuGetMoisureVal(u8 Copy_u8Soil_Moisture_ID, u16 *Copy_Pu16MoistureValue)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_Pu16MoistureValue != NULL)
	{
		if(Copy_u8Soil_Moisture_ID < Soil_Moisture_NUM)
		{
			ADC_Read_From_Ch(Copy_Pu16MoistureValue, Soil_Moisture_AstrSoilMoistureConfig[Copy_u8Soil_Moisture_ID].Soil_Moisture_CHANNEL);
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
