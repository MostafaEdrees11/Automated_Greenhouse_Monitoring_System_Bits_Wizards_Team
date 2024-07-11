/*
 * BUZZER_int.h
 *
 *  Created on: Jul 5, 2024
 *      Author: Mostafa Edrees
 */

#ifndef HAL_BUZZER_BUZZER_INT_H_
#define HAL_BUZZER_BUZZER_INT_H_

#include "BUZZER_config.h"

ES_t BUZZER_enuInit(BUZZER_t *Copy_AstrBuzzerConfig);

ES_t BUZZER_enuTurnON(u8 Copy_u8BuzzerID);

ES_t BUZZER_enuTurnOFF(u8 Copy_u8BuzzerID);

#define BUZZER_1			0
#define BUZZER_2			1
#define BUZZER_3			2
#define BUZZER_4			3
#define BUZZER_5			4
#define BUZZER_6			5

#endif /* HAL_BUZZER_BUZZER_INT_H_ */
