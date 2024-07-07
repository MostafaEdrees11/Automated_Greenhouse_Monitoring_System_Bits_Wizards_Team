/*
 * DHT11_priv.h
 *
 *  Created on: Jul 6, 2024
 *      Author: Mostafa Edrees
 */

#ifndef HAL_DHT11_DHT11_PRIV_H_
#define HAL_DHT11_DHT11_PRIV_H_

typedef union {
	struct{
		u8 humidityInt;
		u8 humidityDec;
		u8 TempInt;
		u8 TempDec;
		u8 sum;
		};
	u8 arr[5];
	}DHT_Reading_t;

static u8 DHT11_ReadByte(void);
static u8 DHT11_CheckResponse(void) ;

#endif /* HAL_DHT11_DHT11_PRIV_H_ */
