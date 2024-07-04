/**
 ******************************************************************************
 * @file           : LED_config.h
 * @author         : Mostafa Edrees
 * @brief          : Configuration file of LED.
 * @date           : 10/13/2023
 * @board          : ATMEGA32
 ******************************************************************************
**/

#ifndef LED_CONFIG_H_
#define LED_CONFIG_H_

/* specify the number of leds */
#define LED_NUM				8


/* configuration of led states */
#define LED_u8ON			10
#define LED_u8OFF			11

/* configuration of led connection states*/
#define LED_u8SINK			12
#define LED_u8SOURCE		13

typedef struct
{
	/* LED_u8PortID --> must specify according to @ref configuration of names of 4 ports at DIO_int.h */
	u8 LED_u8PortID;
	
	/* LED_u8PinID --> must specify according to @ref configuration of names of pins at DIO_int.h */
	u8 LED_u8PinID;
	
	/* LED_u8Connection --> must specify according to @ref configuration of names of pins at LED_config.h */
	u8 LED_u8Connection;
	
	/* LED_u8InitState --> must specify according to @ref configuration of led connection states at LED_config.h */
	u8 LED_u8InitState;	
}LED_t;



#endif /* LED_CONFIG_H_ */