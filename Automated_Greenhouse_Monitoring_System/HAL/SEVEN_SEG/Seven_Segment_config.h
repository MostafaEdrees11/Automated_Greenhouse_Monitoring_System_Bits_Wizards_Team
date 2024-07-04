/**
 ******************************************************************************
 * @file           : Seven_Segment_config.h
 * @author         : Mostafa Edrees
 * @brief          : Configuration file of Seven Segment.
 * @date           : 10/20/2023
 * @board          : ATMEGA32
 ******************************************************************************
**/

#ifndef SEVEN_SEGMENT_CONFIG_H_
#define SEVEN_SEGMENT_CONFIG_H_

#define SEG_NUM				2

typedef struct
{
	u8 SEG_APORT;
	u8 SEG_APIN;
	
	u8 SEG_BPORT;
	u8 SEG_BPIN;
	
	u8 SEG_CPORT;
	u8 SEG_CPIN;
	
	u8 SEG_DPORT;
	u8 SEG_DPIN;
	
	u8 SEG_EPORT;
	u8 SEG_EPIN;
	
	u8 SEG_FPORT;
	u8 SEG_FPIN;
	
	u8 SEG_GPORT;
	u8 SEG_GPIN;
	
	u8 SEG_CMN_PORT;
	u8 SEG_CMN_PIN;
	
	u8 SEG_DOT_PORT;
	u8 SEG_DOT_PIN;
	
	u8 SEG_TYPE;
}SEG_t;



#endif /* SEVEN_SEGMENT_CONFIG_H_ */