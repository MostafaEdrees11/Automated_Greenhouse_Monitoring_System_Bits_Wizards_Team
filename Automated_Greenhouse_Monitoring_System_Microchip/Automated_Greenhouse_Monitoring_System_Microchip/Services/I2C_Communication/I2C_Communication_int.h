/*
 * I2C_Communication_int.h
 *
 *  Created on: Jul 8, 2024
 *      Author: Mostafa Edrees
 */

#ifndef SERVICES_I2C_COMMUNICATION_I2C_COMMUNICATION_INT_H_
#define SERVICES_I2C_COMMUNICATION_I2C_COMMUNICATION_INT_H_

#include "../../APP/Sensors/Sensors_int.h"

typedef union
{
	u8 Data[6];
	struct
	{
		u8 Temp;
		u8 Humi;
		u8 Soil;
		u8 LDRI;
		System_State_t State;
		u8 Check_Sum;
	};
}Communication_Frame_t;

ES_t Communication_enuInitMaster(void);

ES_t Communication_enuInitSlave(void);

ES_t Communication_enuSendFrame(Communication_Frame_t *Copy_uniSentFrame);

ES_t Communication_enuReceiveFrame(Communication_Frame_t *Copy_uniReceivedFrame);

#endif /* SERVICES_I2C_COMMUNICATION_I2C_COMMUNICATION_INT_H_ */
