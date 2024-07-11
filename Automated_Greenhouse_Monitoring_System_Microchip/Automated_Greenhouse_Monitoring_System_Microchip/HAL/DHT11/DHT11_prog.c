/*
 * DHT11_prog.c
 *
 *  Created on: Jul 6, 2024
 *      Author: Fathy Anas
 */



#include "../../LIB/Error_States.h"
#include "../../LIB/stdTypes.h"

#include "../../MCAL/DIO/DIO_int.h"

#include "DHT11_int.h"
#include "DHT11_priv.h"
#include "DHT11_config.h"

#define F_CPU 8000000
#include<util/delay.h>

// Global variables
DHT_Reading_t DHT_Reading;


void DHT11_Init(void)
{
	// Set pin direction as output
	DIO_enuSetPinDirection(DHT_PORT,DHT_PIN,DIO_u8OUTPUT);
	// set pin value to 1 as the steady state of the bus
	DIO_enuSetPinVal(DHT_PORT,DHT_PIN,DIO_u8HIGH);
	// delay 1 second in order to pass the unstable status.
	_delay_ms(1000);
}

ES_t DHT_GetReadings(u8*Temp,u8*Humidity)
{
	ES_t Local_Status=ES_OK;
	// Set pin direction as output
	DIO_enuSetPinDirection(DHT_PORT,DHT_PIN,DIO_u8OUTPUT);
	// set pin value to 1 as the steady state of the bus
	//Initiates the communication
	DIO_enuSetPinVal(DHT_PORT,DHT_PIN,DIO_u8LOW);
	// Waits for at least 18ms to let DHT11 detects the signal
	_delay_ms(18);
	// set pin value to 1
	DIO_enuSetPinVal(DHT_PORT,DHT_PIN,DIO_u8HIGH);

	// Set pin direction as input
	DIO_enuSetPinDirection(DHT_PORT,DHT_PIN,DIO_u8INPUT);

	// Check the response from DHT11
	if (DHT11_CheckResponse() == 0)
	{
		Local_Status=ES_NOK;      // No response
	}
	else
	{
		// Read 5 bytes of data
		for (u8 i = 0; i < 5; i++)
		{
			 DHT_Reading.arr[i] = DHT11_ReadByte();
		}
	    // Verify checksum
		if (DHT_Reading.arr[4] != (u8)((DHT_Reading.arr[0] + DHT_Reading.arr[1] + DHT_Reading.arr[2] + DHT_Reading.arr[3])) )
		{
			 Local_Status=ES_NOK; // Checksum error
		}
	}

	*Temp = DHT_Reading.TempInt;
	*Humidity = DHT_Reading.humidityInt;

	return Local_Status;

}


// Private function to check for response from DHT11
static u8 DHT11_CheckResponse(void)
{
	u8 Local_Response = 0,Local_PinValue;
	_delay_us(40);

	DIO_enuGetPinVal(DHT_PORT,DHT_PIN,&Local_PinValue);

	if (Local_PinValue == DIO_u8LOW)
	{
		_delay_us(80);
		DIO_enuGetPinVal(DHT_PORT,DHT_PIN,&Local_PinValue);
		if (Local_PinValue == DIO_u8HIGH)
		{
			Local_Response = 1;
		}
		while (Local_PinValue == DIO_u8HIGH)
		{
			DIO_enuGetPinVal(DHT_PORT,DHT_PIN,&Local_PinValue);
		}
	}
	return Local_Response;
}

// Private function to read a byte from DHT11
static u8 DHT11_ReadByte(void)
{
	u8 Local_Data = 0,Local_PinValue;
	for (u8 i = 0; i < 8; i++)
	{

		while (Local_PinValue == DIO_u8LOW) // Wait for pin to go high
		{
			DIO_enuGetPinVal(DHT_PORT,DHT_PIN,&Local_PinValue);
		}
		_delay_us(30); // Wait for 30 us

		DIO_enuGetPinVal(DHT_PORT,DHT_PIN,&Local_PinValue);
		if (Local_PinValue == DIO_u8HIGH)
		{
			Local_Data |= (1 << (7 - i));
		}
		else
		{
			Local_Data &= (~(1 << (7 - i)));
		}
		while (Local_PinValue == DIO_u8HIGH) // Wait for pin to go low
		{
			DIO_enuGetPinVal(DHT_PORT,DHT_PIN,&Local_PinValue);
		}
	}
	return Local_Data;
}
