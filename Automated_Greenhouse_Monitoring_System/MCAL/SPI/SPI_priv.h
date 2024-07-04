/*
 * SPI_priv.h
 *
 * Created: 7/2/2024 6:57:16 PM
 *  Author: Mostafa Edrees
 */ 


#ifndef SPI_PRIV_H_
#define SPI_PRIV_H_

#define ENABLE_SPI				5
#define DISABLE_SPI				6

#define NORMAL_SPEED			2
#define DOUBLE_SPEED			1

#define MASTER					11
#define SLAVE					12

#define IDLE_HIGH				16
#define IDLE_LOW				17

#define READ_FIRST				23
#define WRITE_FIRST				24

#define MSB_FIRST				28
#define LSB_FIRST				29

#define F_DIVIDED_4				41
#define F_DIVIDED_16			42
#define F_DIVIDED_64			43
#define F_DIVIDED_128			44
#define F_DIVIDED_2				45
#define F_DIVIDED_8				46
#define F_DIVIDED_32			47

#define SPDR					*((volatile u8 *)0x2F)
#define SPSR					*((volatile u8 *)0x2E)
#define SPCR					*((volatile u8 *)0x2D)


#define SPR0					0
#define SPR1					1
#define CPHA					2
#define CPOL					3
#define MSTR					4
#define DORD					5
#define SPE						6
#define SPIE					7

#define SPI2X					0
#define WCOL					6
#define SPIF					7

#define MASK_BIT				1

#endif /* SPI_PRIV_H_ */