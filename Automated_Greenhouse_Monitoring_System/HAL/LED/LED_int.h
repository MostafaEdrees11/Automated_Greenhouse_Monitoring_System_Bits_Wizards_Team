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

ES_t LED_enuINIT(LED_t *Copy_pAstrLedConfig);

ES_t LED_enuTurnON(LED_t *Copy_pstrLedID);

ES_t LED_enuTurnOFF(LED_t *Copy_pstrLedID);


#endif /* LED_INT_H_ */