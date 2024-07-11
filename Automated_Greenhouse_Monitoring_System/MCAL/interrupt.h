/**
 ******************************************************************************
 * @file           : interrupt.h
 * @author         : Mostafa Edrees
 * @brief          : it's contain the interrupt vectors
 * @date           : 27/1/2023
 * @board          : ATMEGA32
 ******************************************************************************
**/

#ifndef INTERRUPT_H_
#define INTERRUPT_H_

#define ISR(VECT_NUM)		void VECT_NUM (void) __attribute__((signal));\
							void VECT_NUM (void) 


#define VECT_INT0			__vector_1
#define VECT_INT1			__vector_2
#define VECT_INT2			__vector_3

#define VECT_ADC			__vector_16

#endif /* INTERRUPT_H_ */