/*
 * Sensors_int.h
 *
 *  Created on: Jul 8, 2024
 *      Author: Samar Ibrahim
 */

#ifndef APP_SENSORS_SENSORS_INT_H_
#define APP_SENSORS_SENSORS_INT_H_

typedef enum
{
	AGMS_ERROR,
	AGMS_NORMAL
}System_State_t;

typedef struct
{
	u8 Temperture;
	u8 Humidity;
	u8 Soil_Moisture;
	u8 Light_Intensity;
	System_State_t State;
}Data_Reading_t;

ES_t Sensors_enuInit(void);

ES_t Sensors_enuGetReadings(Data_Reading_t *Copy_PstrSensorsReading);

#endif /* APP_SENSORS_SENSORS_INT_H_ */
