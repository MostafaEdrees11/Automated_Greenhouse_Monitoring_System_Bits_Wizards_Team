/*
 * BUZZER_int.h
 *
 *  Created on: Jul 5, 2024
 *      Author: Mostafa Edrees
 */

#ifndef HAL_BUZZER_BUZZER_INT_H_
#define HAL_BUZZER_BUZZER_INT_H_

ES_t BUZZER_enuInit(BUZZER_t *Copy_AstrBuzzerConfig);

ES_t BUZZER_enuTurnON(u8 Copy_u8BuzzerID);

ES_t BUZZER_enuTurnOFF(u8 Copy_u8BuzzerID);

#endif /* HAL_BUZZER_BUZZER_INT_H_ */
