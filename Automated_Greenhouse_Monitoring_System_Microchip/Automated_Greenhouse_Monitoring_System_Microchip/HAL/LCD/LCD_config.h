/**
 ******************************************************************************
 * @file           : LCD_config.h
 * @author         : Mostafa Edrees
 * @brief          : Configuration file of LCD.
 * @date           : 11/1/2023
 * @board          : ATMEGA32
 ******************************************************************************
**/

#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

/* LCD Mode 
 * it must be --> EIGHT_BIT or FOUR_BIT */
#define LCD_MODE					FOUR_BIT


/* Control Pins */

/* RS register selection */
#define RS_PORT						DIO_u8PORTB
#define RS_PIN						DIO_u8PIN0

/* RW read write */
#define RW_PORT						DIO_u8PORTB
#define RW_PIN						DIO_u8PIN1

/* EN enable */
#define EN_PORT						DIO_u8PORTB
#define EN_PIN						DIO_u8PIN2

/* Data Pins */

/* D7 */
#define D7_PORT						DIO_u8PORTB
#define D7_PIN						DIO_u8PIN7

/* D6 */
#define D6_PORT						DIO_u8PORTB
#define D6_PIN						DIO_u8PIN6

/* D5 */
#define D5_PORT						DIO_u8PORTB
#define D5_PIN						DIO_u8PIN5

/* D4 */
#define D4_PORT						DIO_u8PORTB
#define D4_PIN						DIO_u8PIN4

/* D3 */
#define D3_PORT						DIO_u8PORTA
#define D3_PIN						DIO_u8PIN3

/* D2 */
#define D2_PORT						DIO_u8PORTA
#define D2_PIN						DIO_u8PIN2

/* D1 */
#define D1_PORT						DIO_u8PORTA
#define D1_PIN						DIO_u8PIN1

/* D0 */
#define D0_PORT						DIO_u8PORTA
#define D0_PIN						DIO_u8PIN0

#endif /* LCD_CONFIG_H_ */
