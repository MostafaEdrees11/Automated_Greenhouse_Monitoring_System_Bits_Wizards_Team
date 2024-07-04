/**
 ******************************************************************************
 * @file           : ADC_priv.h
 * @author         : Mostafa Edrees
 * @brief          : Private file of ADC.
 * @date           : 26/1/2023
 * @board          : ATMEGA32
 ******************************************************************************
**/

#ifndef ADC_PRIV_H_
#define ADC_PRIV_H_

/* ADC registers */
#define ADMUX						*((volatile u8 *)0x27)
#define ADCSRA						*((volatile u8 *)0x26)
#define ADCH						*((volatile u8 *)0x25)
#define ADCL						*((volatile u8 *)0x24)
#define SFIOR						*((volatile u8 *)0x50)

/* bits of ADMUX register */
#define REFS1						7
#define REFS0						6
#define ADLAR						5
#define MUX4						4
#define MUX3						3
#define MUX2						2
#define MUX1						1
#define MUX0						0
#define MUX4						4

/* bits of ADCSRA register */
#define ADEN						7
#define ADSC						6
#define ADATE						5
#define ADIF						4
#define ADIE						3
#define ADPS2						2
#define ADPS1						1
#define ADPS0						0

/* bits of SFIOR register */
#define ADTS2						7
#define ADTS1						6
#define ADTS0						5

/* Voltage Reference Selections for ADC */
#define AREF_REF					REFERENCE_VOLTAGE
#define AVCC_REF					5000UL
#define INTERNAL_REF				2560UL

/* Left or Right Adjustment */
#define RIGHT_ADJUST				0
#define LEFT_ADJUST					1

/* ADC PreScaler Select */
#define DIVISION_FACTOR_2			2
#define DIVISION_FACTOR_4			4
#define DIVISION_FACTOR_8			8
#define DIVISION_FACTOR_16			16
#define DIVISION_FACTOR_32			32
#define DIVISION_FACTOR_64			64
#define DIVISION_FACTOR_128			128

/* ADC Auto Trigger Source Selections */
#define FREE_RUNNING				0
#define ANALOG_COMPARATOR			1
#define EXTI0_TRIG					2
#define TIMER0_COMPARE_MATCH_TRIG	3
#define TIMER0_OVERFLOW_TRIG		4
#define TIMER1_COMPARE_MATCH_TRIG	5
#define TIMER1_OVERFLOW_TRIG		6
#define TIMER1_CAPUTRE_TRIG			7


#define MASK_BIT					1
#define VOLT_REF_MASK				0x3F
#define PRESCALER_MASK				0xF8
#define CHANNALS_MASK				0xE0
#define AUTO_TRIGGER_MASK			0x1F


#endif /* ADC_PRIV_H_ */