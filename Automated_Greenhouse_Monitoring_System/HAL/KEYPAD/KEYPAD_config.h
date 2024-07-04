/**
 ******************************************************************************
 * @file           : KEYPAD_config.h
 * @author         : Mostafa Edrees
 * @brief          : Configuration file of KEYPAD.
 * @date           : 3/11/2023
 * @board          : ATMEGA32
 ******************************************************************************
**/

#ifndef KEYPAD_CONFIG_H_
#define KEYPAD_CONFIG_H_

/* characters of the keypad */
#define KEYPAD_CHARACTERS						{ {'7', '8', '9', '/'},\
												  {'4', '5', '6', '*'},\
												  {'1', '2', '3', '-'},\
												  {'c', '0', '=', '+'} }

/* no pressed key */
#define KEYPAD_No_Key_Pressed					0xFF

/* Columns pins */

/* C1 */
#define KEYPAD_C1_PORT							DIO_u8PORTC
#define KEYPAD_C1_PIN							DIO_u8PIN0

/* C2 */
#define KEYPAD_C2_PORT							DIO_u8PORTC
#define KEYPAD_C2_PIN							DIO_u8PIN1

/* C3 */
#define KEYPAD_C3_PORT							DIO_u8PORTC
#define KEYPAD_C3_PIN							DIO_u8PIN2

/* C4 */
#define KEYPAD_C4_PORT							DIO_u8PORTC
#define KEYPAD_C4_PIN							DIO_u8PIN3

/* Rows pins */

/* R1 */
#define KEYPAD_R1_PORT							DIO_u8PORTC
#define KEYPAD_R1_PIN							DIO_u8PIN4

/* R2 */
#define KEYPAD_R2_PORT							DIO_u8PORTC
#define KEYPAD_R2_PIN							DIO_u8PIN5

/* R3 */
#define KEYPAD_R3_PORT							DIO_u8PORTC
#define KEYPAD_R3_PIN							DIO_u8PIN6

/* R4 */
#define KEYPAD_R4_PORT							DIO_u8PORTC
#define KEYPAD_R4_PIN							DIO_u8PIN7

#endif /* KEYPAD_CONFIG_H_ */
