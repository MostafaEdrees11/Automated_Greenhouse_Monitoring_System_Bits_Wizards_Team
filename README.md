# Automated Greenhouse Monitoring System

## Overview
Maintaining optimal conditions in a greenhouse is crucial for ensuring healthy plant growth and maximizing yield. 
Traditional manual monitoring and adjusting of environmental factors such as temperature, humidity, light, 
and soil moisture can be labor-intensive and prone to human error. These challenges can lead to inconsistent growing conditions, 
which adversely affect plant health and productivity. This project aims to provide a more efficient and reliable solution to automate 
and optimize the monitoring and control of greenhouse environments.
![gitHub](https://github.com/MostafaEdrees11/Automated_Greenhouse_Monitoring_System_Bits_Wizards_Team/blob/master/Documetation/images/project.jpg)
___

## Project Requirements
### 1. Monitoring
* Monitor the following environmental parameters:
	* Temperature
	* Humidity 
	* Soil moisture 
	* Light intensity
	
### 2. Display
* Display current readings on an LCD screen for easy observation and monitoring.

### 3. Control Systems
* Automatically control the following systems based on sensor readings to maintain optimal conditions:
	* Fans
	* Heaters
	* Irrigation systems
	* Grow lights
### 4. Alerts
* Provide alerts if any environmental parameter goes out of the optimal range to prompt immediate corrective actions.
___

## Project Architecture 
### Layers
![gitHub](https://github.com/MostafaEdrees11/Automated_Greenhouse_Monitoring_System_Bits_Wizards_Team/blob/master/Documetation/images/Project%20Layers.JPG)
### Communication with Node Red
![gitHub](https://github.com/MostafaEdrees11/Automated_Greenhouse_Monitoring_System_Bits_Wizards_Team/blob/master/Documetation/images/Communication_MCU1_to_NodeRed.JPG)
___

## Monitoring 
### Temperature & Humidity
We use `DHT11 sensor` to get reading of Temperature and Humidity.
### Soil Moisture
We use `soil moisture sensor` to get the value of Soil Moisture.
### Light Intensity 
We use `LDR sensor` to get the value of Light Intensity.

## Display
We use `LCD 20*4` to display the readings of the sensors and we send these readings to node red server via serial to display the reading on `Node Red Dashboard`
### LCD view
![gitHub](https://github.com/MostafaEdrees11/Automated_Greenhouse_Monitoring_System_Bits_Wizards_Team/blob/master/Documetation/images/LCD.gif)
### Node Red Dashboard view
![gitHub](https://github.com/MostafaEdrees11/Automated_Greenhouse_Monitoring_System_Bits_Wizards_Team/blob/master/Documetation/images/NodeRed_Dashborad.gif)

## Control Systems
We use `DC Motors` to represent `Fan, Heater & Irrigation System`.
### Heater
* We turn on the `heater` when `Temperature < 18 && Humidity < 40`
![gitHub](https://github.com/MostafaEdrees11/Automated_Greenhouse_Monitoring_System_Bits_Wizards_Team/blob/master/Documetation/images/Heater_On.gif)
* We turn off the `heater` when `Temperature > 20 && Humidity > 45`
![gitHub](https://github.com/MostafaEdrees11/Automated_Greenhouse_Monitoring_System_Bits_Wizards_Team/blob/master/Documetation/images/Heater_Off.gif)

### Fan
* We turn on the `fan` when `Temperature > 26 && Humidity > 70`
![gitHub](https://github.com/MostafaEdrees11/Automated_Greenhouse_Monitoring_System_Bits_Wizards_Team/blob/master/Documetation/images/Fan_On.gif)
* We turn off the `fan` when `Temperature < 28 && Humidity < 75`
![gitHub](https://github.com/MostafaEdrees11/Automated_Greenhouse_Monitoring_System_Bits_Wizards_Team/blob/master/Documetation/images/Fan_Off.gif)

### Pump
* We turn on the `pump ⛽` when `Soil Moisture < 30`
![gitHub](https://github.com/MostafaEdrees11/Automated_Greenhouse_Monitoring_System_Bits_Wizards_Team/blob/master/Documetation/images/Pump_On.gif)
* We turn off the `pump ⛽` when `Soil Moisture > 60`
![gitHub](https://github.com/MostafaEdrees11/Automated_Greenhouse_Monitoring_System_Bits_Wizards_Team/blob/master/Documetation/images/Pump_Off.gif)

### Lamp
* We increase the `light intensity` when `Light intensity < 45`
* We decrease the `light intensity` when `Light intensity > 75`
![gitHub](https://github.com/MostafaEdrees11/Automated_Greenhouse_Monitoring_System_Bits_Wizards_Team/blob/master/Documetation/images/Lamp.gif)

## Alerts
We have a two leds and buzzer:
* the green led will on when the system in normal state and the buzzer will be off
* the red led will on when the system in error state and the buzzer will be on and we send notification to the user on the mobile app when there is error in the system

### Ranges of Error State
```
* Temperature < 10                              * Temperature > 40
* Humidity < 20                                 * Humidity > 80
* Soil Moisture < 10                            * Soil Moisture > 80
* Light Intensity < 20                          * Light Intensity > 90
```
![gitHub](https://github.com/MostafaEdrees11/Automated_Greenhouse_Monitoring_System_Bits_Wizards_Team/blob/master/Documetation/images/Buzzer_when_Error.mp4)
![gitHub](https://github.com/MostafaEdrees11/Automated_Greenhouse_Monitoring_System_Bits_Wizards_Team/blob/master/Documetation/images/Notification_for_System_Error.jpg)

___

## Testing Sensors
#### Test Temperature 
![gitHub](https://github.com/MostafaEdrees11/Automated_Greenhouse_Monitoring_System_Bits_Wizards_Team/blob/master/Documetation/images/Temperature.gif)
#### Test Humidity 
![gitHub](https://github.com/MostafaEdrees11/Automated_Greenhouse_Monitoring_System_Bits_Wizards_Team/blob/master/Documetation/images/Humidity.gif)
#### Test Soil Moisture
![gitHub](https://github.com/MostafaEdrees11/Automated_Greenhouse_Monitoring_System_Bits_Wizards_Team/blob/master/Documetation/images/Soil_Moisture.gif)
#### Test Light Intensity 
![gitHub](https://github.com/MostafaEdrees11/Automated_Greenhouse_Monitoring_System_Bits_Wizards_Team/blob/master/Documetation/images/Light_Intensity.gif)
___

## Log Readings into Text File
we log data to text file instead of using EEPROM
![gitHub](https://github.com/MostafaEdrees11/Automated_Greenhouse_Monitoring_System_Bits_Wizards_Team/blob/master/Documetation/images/Data_Logged.JPG)
___

### Project Schematic on Proteus
![gitHub](https://github.com/MostafaEdrees11/Automated_Greenhouse_Monitoring_System_Bits_Wizards_Team/blob/master/Documetation/images/Project_Schematic_on_Proteus.JPG)

### Node Red Dashboard
![gitHub](https://github.com/MostafaEdrees11/Automated_Greenhouse_Monitoring_System_Bits_Wizards_Team/blob/master/Documetation/images/NodeRed_Functions.JPG)
![gitHub](https://github.com/MostafaEdrees11/Automated_Greenhouse_Monitoring_System_Bits_Wizards_Team/blob/master/Documetation/images/Node_Red_Dashboard.JPG)
___

## Final Overview
![gitHub](https://github.com/MostafaEdrees11/Automated_Greenhouse_Monitoring_System_Bits_Wizards_Team/blob/master/Documetation/images/Proteus_with_Server_with_Mobile_App.jpg)
You can see the video for the final output in this link [Video Project]()
and the Report of the project [Report Link]() and the Presentation [Presentation Link](https://www.canva.com/design/DAGKqLtwIz0/0gDAwP-sjlxO_CZzNDPGyw/edit)
___

## Contributors
* [Mostafa Edrees](https://www.linkedin.com/in/mostafa-edrees-427373225/)
* [Fathy Anas](https://www.linkedin.com/in/fathy-anas/)
* [Samar Ibrahim](https://www.linkedin.com/in/samar-ibrahim-b6b2a1272/?originalSubdomain=eg)

Supervisor: [Menna Eid](https://www.linkedin.com/in/menna-eid-084115240?utm_source=share&utm_campaign=share_via&utm_content=profile&utm_medium=android_app)   
___

## Company
### [CAT Reloaded Embedded Circle](https://www.linkedin.com/company/cat-reloaded/mycompany/)

![gitHub](https://github.com/MostafaEdrees11/Bits_Wizards/blob/master/Documetation/images/CAT.png)

Head: [Yasmeen Mohamed](https://www.linkedin.com/in/yasmeen-mohamed-48a061225?utm_source=share&utm_campaign=share_via&utm_content=profile&utm_medium=android_app)