/*
 * LDR_int.h
 *
 *  Created on: Jul 4, 2024
 *      Author: user
 */

#ifndef HAL_LDR_LDR_INT_H_
#define HAL_LDR_LDR_INT_H_

#include"../../LIB/Error_States.h"
#include "../../LIB/stdTypes.h"
#include "LDR_Config.h"
// Function prototypes
ES_t LDR_enuInit(LDR_t* Copy_PstrLDRconfig);
ES_t LDR_enuGetValue(u16 *Copy_pu16ReadValue, u8 Copy_u8ChannelID);
#endif /* HAL_LDR_LDR_INT_H_ */
