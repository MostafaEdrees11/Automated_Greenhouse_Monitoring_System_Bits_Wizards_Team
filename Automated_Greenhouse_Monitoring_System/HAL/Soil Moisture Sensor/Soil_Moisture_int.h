/*
 * Soil_Moisture_int.h
 *
 *  Created on: Jul 5, 2024
 *      Author: Mostafa Edrees
 */

#ifndef HAL_SOIL_MOISTURE_SENSOR_SOIL_MOISTURE_INT_H_
#define HAL_SOIL_MOISTURE_SENSOR_SOIL_MOISTURE_INT_H_

#include "Soil_Moisture_config.h"

ES_t Soil_Moisture_enuInit(Soil_Moisture_Configuration_t *Copy_PstrSoilMoistureConfig);

ES_t Soil_Moisture_enuGetMoisureVal(u8 Copy_u8Soil_Moisture_ID, u16 *Copy_Pf32MoistureValue);

#endif /* HAL_SOIL_MOISTURE_SENSOR_SOIL_MOISTURE_INT_H_ */
