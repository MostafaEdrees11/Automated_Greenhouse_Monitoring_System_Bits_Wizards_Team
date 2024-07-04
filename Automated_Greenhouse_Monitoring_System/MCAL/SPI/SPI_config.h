/*
 * SPI_config.h
 *
 * Created: 7/2/2024 6:57:28 PM
 *  Author: Mostafa Edrees
 */ 


#ifndef SPI_CONFIG_H_
#define SPI_CONFIG_H_

/*
Options for SPI STATE:
	--> ENABLE_SPI
	--> DISABLE_SPI
*/
#define SPI_STATE			ENABLE_SPI

/*
Options for SPI SPEED:
	--> NORMAL_SPEED
	--> DOUBLE_SPEED	--> only with Master
*/
#define SPI_SPEED			NORMAL_SPEED

/*
Options for SPI MODE:
	--> MASTER
	--> SLAVE
*/
#define SPI_MODE			MASTER
//#define SPI_MODE			SLAVE

/*
Options for SPI CPOL:
	--> IDLE_HIGH
	--> IDLE_LOW
*/
#define SPI_CPOL			IDLE_LOW

/*
Options for SPI CPHA:
	--> READ_FIRST
	--> WRITE_FIRST
*/
#define SPI_CPHA			READ_FIRST

/*
Options for SPI DORD:
	--> MSB_FIRST
	--> LSB_FIRST
*/
#define SPI_DORD			MSB_FIRST

/*
Options for SPI FREQUENCY:
	--> F_DIVIDED_4				--> at Normal Speed Mode
	--> F_DIVIDED_16			--> at Normal Speed Mode
	--> F_DIVIDED_64			--> at Normal Speed Mode or Double Speed Mode
	--> F_DIVIDED_128			--> at Normal Speed Mode
	--> F_DIVIDED_2				--> at Double Speed Mode
	--> F_DIVIDED_8				--> at Double Speed Mode
	--> F_DIVIDED_32			--> at Double Speed Mode
*/
#define SPI_FREQUENCY		F_DIVIDED_128


#endif /* SPI_CONFIG_H_ */