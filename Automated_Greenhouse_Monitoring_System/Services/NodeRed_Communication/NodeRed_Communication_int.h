/*
 * NodeRed_Communication_int.h
 *
 *  Created on: Jul 9, 2024
 *      Author: Mostafa Edrees
 */

#ifndef SERVICES_NODERED_COMMUNICATION_NODERED_COMMUNICATION_INT_H_
#define SERVICES_NODERED_COMMUNICATION_NODERED_COMMUNICATION_INT_H_

ES_t NodeRed_Communication_enuInit();

ES_t NodeRed_Communication_enuSendDatatoServer(Data_Reading_t *Copy_PstrSensorsReading);

#endif /* SERVICES_NODERED_COMMUNICATION_NODERED_COMMUNICATION_INT_H_ */
