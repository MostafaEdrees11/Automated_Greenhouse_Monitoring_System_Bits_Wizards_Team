/*
 * NodeRed_Communication_prog.c
 *
 *  Created on: Jul 9, 2024
 *      Author: Mostafa Edrees
 */

#include "../../LIB/Error_States.h"
#include "../../LIB/stdTypes.h"

#include "../../APP/Sensors/Sensors_int.h"

#include "../../MCAL/DIO/DIO_int.h"
#include "../../MCAL/USART/USART_int.h"

#include "NodeRed_Communication_int.h"
#include "NodeRed_Communication_config.h"
#include "NodeRed_Communication_priv.h"

ES_t NodeRed_Communication_enuInit()
{
	ES_t Local_enuErrorState = ES_NOK;

	DIO_enuSetPinDirection(DIO_u8PORTD, DIO_u8PIN1, DIO_u8OUTPUT);	//Tx
	DIO_enuSetPinDirection(DIO_u8PORTD, DIO_u8PIN0, DIO_u8INPUT);	//Rx

	USART_enuInit();

	return Local_enuErrorState;
}


ES_t NodeRed_Communication_enuSendDatatoServer(Data_Reading_t *Copy_PstrSensorsReading)
{
	ES_t Local_enuErrorState = ES_NOK;

	char SensorReading_String[30];

	structToStr(Copy_PstrSensorsReading, SensorReading_String);

	Local_enuErrorState = USART_enuSendString(SensorReading_String);

	return Local_enuErrorState;
}


// Helper function to reverse a string
static void reverse(char str[], int length)
{
	int start = 0;
	int end = length - 1;
	while (start < end) {
		char temp = str[start];
		str[start] = str[end];
		str[end] = temp;
		start++;
		end--;
	}
}

// Function to convert an integer to a string
static void intToStr(int num, char str[])
{
	int isNegative = 0;
	int i = 0;

	// Handle 0 explicitly, otherwise empty string is printed for 0
	if (num == 0) {
		str[i++] = '0';
		str[i] = '\0';
		return;
	}

	// Handle negative numbers
	if (num < 0) {
		isNegative = 1;
		num = -num;
	}

	// Process individual digits
	while (num != 0) {
		int rem = num % 10;
		str[i++] = rem + '0';
		num = num / 10;
	}

	// If number is negative, append '-'
	if (isNegative) {
		str[i++] = '-';
	}

	str[i] = '\0'; // Append string terminator

	// Reverse the string
	reverse(str, i);
}

// Function to convert the struct members to a single string
static void structToStr(Data_Reading_t *data, char resultStr[])
{
	char dataStr1[10];
	char dataStr2[10];
	char dataStr3[10];
	char dataStr4[10];
	char dataStr5[10];

	// Convert each number to string
	intToStr(data->Temperture, dataStr1);
	intToStr(data->Humidity, dataStr2);
	intToStr(data->Soil_Moisture, dataStr3);
	intToStr(data->Light_Intensity, dataStr4);
	intToStr(data->State, dataStr5);

	// Combine all strings with semicolon separators
	strcpy(resultStr, dataStr1);
	strcat(resultStr, ";");
	strcat(resultStr, dataStr2);
	strcat(resultStr, ";");
	strcat(resultStr, dataStr3);
	strcat(resultStr, ";");
	strcat(resultStr, dataStr4);
	strcat(resultStr, ";");
	strcat(resultStr, dataStr5);
	strcat(resultStr, ";");
	strcat(resultStr, "$");
}
