/*
 * Soil_Moisture_config.h
 *
 *  Created on: Jul 5, 2024
 *      Author: Mostafa Edrees
 */

#ifndef HAL_SOIL_MOISTURE_SENSOR_SOIL_MOISTURE_CONFIG_H_
#define HAL_SOIL_MOISTURE_SENSOR_SOIL_MOISTURE_CONFIG_H_

#include "../../LIB/Error_States.h"
#include "../../LIB/stdTypes.h"

#include "../../MCAL/ADC/ADC_int.h"

#define Soil_Moisture_NUM		1

typedef struct
{
	u8 Soil_Moisture_CHANNEL;
}Soil_Moisture_Configuration_t;

#endif /* HAL_SOIL_MOISTURE_SENSOR_SOIL_MOISTURE_CONFIG_H_ */
