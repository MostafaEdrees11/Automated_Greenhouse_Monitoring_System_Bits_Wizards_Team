/**
 ******************************************************************************
 * @file           : Seven_Segment_priv.h
 * @author         : Mostafa Edrees
 * @brief          : Private file of Seven Segment.
 * @date           : 10/20/2023
 * @board          : ATMEGA32
 ******************************************************************************
**/

#ifndef SEVEN_SEGMENT_PRIV_H_
#define SEVEN_SEGMENT_PRIV_H_

/* Configuration of Seven Segment Type */
#define COMMON_ANODE			5
#define COMMON_CATHODE			6

#define NOT_CONNECTED			10

/* Values of Seven Segment (cathode) */
static u8 SEGCth_Numbers[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F};

/* positions of pins of 7 Segment */
#define APIN_POS				0
#define BPIN_POS				1
#define CPIN_POS				2
#define DPIN_POS				3
#define EPIN_POS				4
#define FPIN_POS				5
#define GPIN_POS				6

#define MASK_BIT				1

#endif /* SEVEN_SEGMENT_PRIV_H_ */