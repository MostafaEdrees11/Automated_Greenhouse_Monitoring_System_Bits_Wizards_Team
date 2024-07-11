/*
 * Sensors_prog.c
 *
 *  Created on: Jul 8, 2024
 *      Author: Samar Ibrahim
 */


#include "../../LIB/Error_States.h"
#include "../../LIB/stdTypes.h"
#include "../../LIB/Math.h"

#include "../../HAL/LDR/LDR_int.h"

#include "../../HAL/Soil Moisture Sensor/Soil_Moisture_int.h"

#include "../../HAL/DHT11/DHT11_int.h"

#include "../../MCAL/ADC/ADC_int.h"

#include "Sensors_int.h"
#include "Sensors_priv.h"
#include "Sensors_config.h"

ES_t Sensors_enuInit(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	/* Initialize ADC */
	ADC_enuInit();

	/* Initialize LDR --> PORTA PIN0 */
	LDR_enuInit(&LDR_Config);

	/* Initialize Soil Moisture --> PORTA PIN1 */
	Soil_Moisture_enuInit(&Soil_Moisture_AstrSoilMoistureConfig);

	/* Initialize DHT11 --> PORTA PIN2 */
	DHT11_Init();

	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}

ES_t Sensors_enuGetReadings(Data_Reading_t *Copy_PstrSensorsReading)
{
	ES_t Local_enuErrorState = ES_NOK;

	u16 Local_u16ADCvalue_LDR = 0, Local_u16ADCvalue_Soil;

	if(Copy_PstrSensorsReading != NULL)
	{
		/* Get LDR value */
		LDR_enuGetValue(&Local_u16ADCvalue_LDR, LDR_1);
		Copy_PstrSensorsReading->Light_Intensity = Math_Mapping(0, 100, 0, 1023, Local_u16ADCvalue_LDR);

		/* Get Soil Moisture value */
		Soil_Moisture_enuGetMoisureVal(SOIL_MOISTURE_1, &Local_u16ADCvalue_Soil);
		Copy_PstrSensorsReading->Soil_Moisture = Math_Mapping(0, 100, 0, 1023, Local_u16ADCvalue_Soil);

		/* Get Temp & Humi value */
		DHT_GetReadings(&Copy_PstrSensorsReading->Temperture, &Copy_PstrSensorsReading->Humidity);

		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}
