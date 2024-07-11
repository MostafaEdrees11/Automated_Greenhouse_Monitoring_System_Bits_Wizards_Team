/*
 * Atuomatic_Control_int.h
 *
 *  Created on: Jul 8, 2024
 *      Author: Fathy Anas
 */

#ifndef APP_AUTOMATIC_CONTROL_AUTOMATIC_CONTROL_INT_H_
#define APP_AUTOMATIC_CONTROL_AUTOMATIC_CONTROL_INT_H_

ES_t AC_enuInitSystem(void);

ES_t AC_enuControlHeatSystem(u8 Copy_u8Temp, u8 Copy_u8Hemu);

ES_t AC_enuControlIrrigationSystem(u8 Copy_u8SoilMoisture);

ES_t AC_enuControlLightIntensitySystem(u8 Copy_u8LDR);

ES_t AC_enuControlAlertSystem(Data_Reading_t *Copy_PstrSystemReadings);

#endif /* APP_AUTOMATIC_CONTROL_AUTOMATIC_CONTROL_INT_H_ */
