/*
 * Display_prog.c
 *
 *  Created on: Jul 8, 2024
 *      Author: Fathy Anas
 */


#include "../../HAL/LCD/LCD_int.h"

#include "../Sensors/Sensors_int.h"

#include "Display_int.h"
#include "Display_config.h"
#include "Display_priv.h"

ES_t Diplay_enuInit(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	LCD_enuInit();

	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}


ES_t Display_enuReading(Data_Reading_t *Copy_PstrSensorsReading)
{
	/*
	 * Temp: 00C||Humi: 55%
	 * Soil: 60 %||LDR: 60%
	 * --------------------
	 * << State: Normal >>
	 */
	ES_t Local_enuErrorState = ES_NOK;

	LCD_enuGoToPosition(0,0);
	LCD_enuWriteString("Temp: ");
	LCD_enuWriteIntNumber(Copy_PstrSensorsReading->Temperture);
	LCD_enuWriteString("C  ");
	LCD_enuGoToPosition(0,10);
	LCD_enuWriteString("Humi: ");
	LCD_enuWriteIntNumber(Copy_PstrSensorsReading->Humidity);
	LCD_enuWriteString("%  ");

	LCD_enuGoToPosition(1,0);
	LCD_enuWriteString("Soil: ");
	LCD_enuWriteIntNumber(Copy_PstrSensorsReading->Soil_Moisture);
	LCD_enuWriteString("%  ");
	LCD_enuGoToPosition(1,10);
	LCD_enuWriteString("LDRI: ");
	LCD_enuWriteIntNumber(Copy_PstrSensorsReading->Light_Intensity);
	LCD_enuWriteString("%  ");

	LCD_enuGoToPosition(2,0);
	LCD_enuWriteString("--------------------");

	LCD_enuGoToPosition(3,0);
	if(Copy_PstrSensorsReading->State == AGMS_NORMAL)
		LCD_enuWriteString("<< State: Normal >>");
	else if(Copy_PstrSensorsReading->State == AGMS_ERROR)
		LCD_enuWriteString("<< State: Error >>");

	return Local_enuErrorState;
}
