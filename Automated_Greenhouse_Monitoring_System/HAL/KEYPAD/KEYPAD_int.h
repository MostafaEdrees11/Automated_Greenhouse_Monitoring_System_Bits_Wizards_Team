/**
 ******************************************************************************
 * @file           : KEYPAD_int.h
 * @author         : Mostafa Edrees
 * @brief          : interface file of KEYPAD.
 * @date           : 3/11/2023
 * @board          : ATMEGA32
 ******************************************************************************
**/


#ifndef KEYPAD_INT_H_
#define KEYPAD_INT_H_

ES_t KEYPAD_enuInit(void);

u8 KEYPAD_u8GetPressedKey(void);


#endif /* KEYPAD_INT_H_ */