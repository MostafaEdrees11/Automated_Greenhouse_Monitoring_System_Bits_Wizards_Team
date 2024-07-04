/**
 ******************************************************************************
 * @file           : Switch_int.h.h
 * @author         : Mostafa Edrees
 * @brief          : interface file of Switch.
 * @date           : 10/13/2023
 * @board          : ATMEGA32
 ******************************************************************************
**/

#ifndef SWITCH_INT_H_
#define SWITCH_INT_H_

ES_t Switch_enuINIT(SW_t * Copy_pAstrSwConfig[]);

ES_t Switch_enuGetState(SW_t * Copy_pstrSwConfigID, u8 * Copy_pu8SwitchState);

ES_t Switch_enuChangeMode(SW_t * Copy_pstrSwConfigID, u8 Copy_u8SwitchStatus);

#endif /* SWITCH_INT_H_ */