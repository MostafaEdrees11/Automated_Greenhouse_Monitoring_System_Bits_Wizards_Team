/*
 * Soil_Moisture_int.h
 *
 *  Created on: Jul 5, 2024
 *      Author: Mostafa Edrees
 */

#ifndef HAL_SOIL_MOISTURE_SENSOR_SOIL_MOISTURE_INT_H_
#define HAL_SOIL_MOISTURE_SENSOR_SOIL_MOISTURE_INT_H_

#include "Soil_Moisture_config.h"

#define SOIL_MOISTURE_1				0
#define SOIL_MOISTURE_2				1
#define SOIL_MOISTURE_3				2
#define SOIL_MOISTURE_4				3
#define SOIL_MOISTURE_5				4
#define SOIL_MOISTURE_6				5
#define SOIL_MOISTURE_7				6
#define SOIL_MOISTURE_8				7


ES_t Soil_Moisture_enuInit(Soil_Moisture_Configuration_t *Copy_PstrSoilMoistureConfig);

ES_t Soil_Moisture_enuGetMoisureVal(u8 Copy_u8Soil_Moisture_ID, u16 *Copy_Pu16MoistureValue);

#endif /* HAL_SOIL_MOISTURE_SENSOR_SOIL_MOISTURE_INT_H_ */
