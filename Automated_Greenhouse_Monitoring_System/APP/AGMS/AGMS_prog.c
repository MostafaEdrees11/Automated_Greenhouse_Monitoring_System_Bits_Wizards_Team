/*
 * AGMS_prog.c
 *
 *  Created on: Jul 7, 2024
 *      Author: Samar Ibrahim
 */

#include "../../LIB/Error_States.h"
#include "../../LIB/stdTypes.h"
#include "../../LIB/Math.h"

#include "../Sensors/Sensors_int.h"

#include "../Automatic_Control/Automatic_Control_int.h"

#include "../Display/Display_int.h"

#include "../../Services/I2C_Communication/I2C_Communication_int.h"

#include "../../Services/NodeRed_Communication/NodeRed_Communication_int.h"

#include "AGMS_int.h"
#include "AGMS_config.h"
#include "AGMS_priv.h"

Data_Reading_t AC_Sensors_Reading;
Data_Reading_t DS_Sensors_Reading;

ES_t AGMS_enuInit_AutomaticControl(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	/* initialize sensors */
	Sensors_enuInit();

	/* initialize communication */
	Communication_enuInitMaster();

	/* initialize automatic control */
	AC_enuInitSystem();

	return Local_enuErrorState;
}

ES_t AGMS_enuRunning_AutomaticControl(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	Communication_Frame_t Local_uniCommFrame;

	/* Get Sensor Reading */
	Sensors_enuGetReadings(&AC_Sensors_Reading);

	Local_uniCommFrame.Temp = AC_Sensors_Reading.Temperture;
	Local_uniCommFrame.Humi = AC_Sensors_Reading.Humidity;
	Local_uniCommFrame.Soil = AC_Sensors_Reading.Soil_Moisture;
	Local_uniCommFrame.LDRI = AC_Sensors_Reading.Light_Intensity;
	Local_uniCommFrame.State = AC_Sensors_Reading.State;


	/* Send Reading to MCU2 */
	Communication_enuSendFrame(&Local_uniCommFrame);

	/* Control depend on Reading */
	/* Control Heat System */
	AC_enuControlHeatSystem(AC_Sensors_Reading.Temperture, AC_Sensors_Reading.Humidity);

	/* Control Irrigation System */
	AC_enuControlIrrigationSystem(AC_Sensors_Reading.Soil_Moisture);

	/* Control Light System */
	AC_enuControlLightIntensitySystem(AC_Sensors_Reading.Light_Intensity);

	/* Control Alert System */
	AC_enuControlAlertSystem(&AC_Sensors_Reading);

	return Local_enuErrorState;
}

ES_t AGMS_enuInit_Display(void)
{
	ES_t Local_enuErrorState = ES_NOK;

	/* initialize communication */
	Communication_enuInitSlave();

	/* initialize node red */
	NodeRed_Communication_enuInit();

	/* initialize Display */
	Diplay_enuInit();


	return Local_enuErrorState;
}

ES_t AGMS_enuRunning_Display(void)
{
	ES_t Local_enuErrorState = ES_NOK;
	Communication_Frame_t Local_uniCommFrame;

	/* Read Data from MCU1 */
	Communication_enuReceiveFrame(&Local_uniCommFrame);

	DS_Sensors_Reading.Temperture = Local_uniCommFrame.Temp;
	DS_Sensors_Reading.Humidity = Local_uniCommFrame.Humi;
	DS_Sensors_Reading.Soil_Moisture = Local_uniCommFrame.Soil;
	DS_Sensors_Reading.Light_Intensity = Local_uniCommFrame.LDRI;
	DS_Sensors_Reading.State = Local_uniCommFrame.State;

	/* Display Data */
	Display_enuReading(&DS_Sensors_Reading);

	/* Send Data to Node Red */
	NodeRed_Communication_enuSendDatatoServer(&DS_Sensors_Reading);

	return Local_enuErrorState;
}
