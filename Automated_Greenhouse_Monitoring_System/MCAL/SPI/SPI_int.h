/*
 * SPI_int.h
 *
 * Created: 7/2/2024 6:57:04 PM
 *  Author: Mostafa Edrees
 */ 


#ifndef SPI_INT_H_
#define SPI_INT_H_

ES_t SPI_enuInit();

ES_t SPI_enuSendData_Master(u8 Copy_u8MasterData, u8 *Copy_pu8SlaveData);

ES_t SPI_enuReceiveData_Master(u8 *Copy_pu8MasterData, u8 Copy_u8SlaveData);

ES_t SPI_enuEnableInterrupt();

ES_t SPI_enuCallBackFunc(void (* Copy_pAppFunc)(void *), void *Copy_pAppParameter);

#endif /* SPI_INT_H_ */