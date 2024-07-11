/*
 * Atuomatic_Control_config.h
 *
 *  Created on: Jul 8, 2024
 *      Author: Fathy Anas
 */

#ifndef APP_AUTOMATIC_CONTROL_AUTOMATIC_CONTROL_CONFIG_H_
#define APP_AUTOMATIC_CONTROL_AUTOMATIC_CONTROL_CONFIG_H_

#define TEMP_MAX			26
#define TEMP_MIN			18
#define TEMP_ERROR_MIN		10
#define TEMP_ERROR_MAX		40
#define TEMP_HYS			2

#define HUMI_MAX			70
#define HUMI_MIN			40
#define HUMI_ERROR_MIN		20
#define HUMI_ERROR_MAX		80
#define HUMI_HYS			5

#define SOIL_MAX			60
#define SOIL_MIN			30
#define SOIL_ERROR_MIN		10
#define SOIL_ERROR_MAX		80

#define LDRI_MAX			75
#define LDRI_MIN			45
#define LDRI_ERROR_MIN		20
#define LDRI_ERROR_MAX		90

#define FAN_MOTOR			MOTOR_1
#define HEATER_MOTOR		MOTOR_2
#define PUMP_MOTOR			MOTOR_3

#define STATE_LED			LED_1
#define LAMP_LED			LED_2
#define ERROR_LED			LED_3

#define SYSTEM_BUZZER		BUZZER_1


#endif /* APP_AUTOMATIC_CONTROL_AUTOMATIC_CONTROL_CONFIG_H_ */
