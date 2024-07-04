 /**
 ******************************************************************************
 * @file           : ADC_config.h
 * @author         : Mostafa Edrees
 * @brief          : Configuration file of ADC.
 * @date           : 26/1/2023
 * @board          : ATMEGA32
 ******************************************************************************
**/


#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

/* Configuration of Reference Voltage */
#define ADC_VOLT_REF						AVCC_REF

/* if you use AREF_REF enter the voltage in mV (between 0 to 5000) */
#define REFERENCE_VOLTAGE					5000UL

/* Configuration of Adjustment */
#define ADC_ADJUST							RIGHT_ADJUST

/* Configuration of PreScalar */
#define ADC_PRESCALER						DIVISION_FACTOR_8

/* ADC Resolution */
#define ADC_RESOLUTION						1024.0



#endif /* ADC_CONFIG_H_ */