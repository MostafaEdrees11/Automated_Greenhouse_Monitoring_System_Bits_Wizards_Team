/**
 ******************************************************************************
 * @file           : LED_int.h
 * @author         : Mostafa Edrees
 * @brief          : interface file of LED.
 * @date           : 10/13/2023
 * @board          : ATMEGA32
 ******************************************************************************
**/

#ifndef LED_INT_H_
#define LED_INT_H_

#include "LED_config.h"

ES_t LED_enuINIT(LED_t *Copy_pAstrLedConfig);

ES_t LED_enuTurnON(LED_t *Copy_pstrLedID);

ES_t LED_enuTurnOFF(LED_t *Copy_pstrLedID);

/*Light Intensity 0:100*/
ES_t LED_enuSetIntensity(u8 Copy_u8LedID, u8 Copy_u8LightIntensity);

#define LED_1			0
#define LED_2			1
#define LED_3			2
#define LED_4			3
#define LED_5			4
#define LED_6			5

#endif /* LED_INT_H_ */
