/*
 * BUZZER_config.c
 *
 *  Created on: Jul 5, 2024
 *      Author: Mostafa Edrees
 */


#include "../../MCAL/DIO/DIO_int.h"

#include "BUZZER_config.h"

/*
 * Connection of Buzzer:
 * 			- Connect the 1st line from buzzer with 12 DC power supply
 * 			- Connect the 2nd line from buzzer with collector of BJT (2N2222A)
 * 			- Connect the base of the BJT with the pin of MCU
 * 			- Connect the emmitter with ground
 *
 * 					12 Volt
 * 					^
 * 					|
 * 					------- 2nd Buzzer
 *
 * 					------- 1st Buzzer
 * 					| C
 * 					|
 * MCU_PIN 	B -----				"2N2222A"
 * 					|
 * 					| E
 * 					-- GND
 */

BUZZER_t BUZZER_AstrBuzzerConfig[BUZZER_NUM] =
{
	{DIO_u8PORTC, DIO_u8PIN7, BUZZER_u8OFF}
};
