/*
 * Math.c
 *
 *  Created on: Jul 7, 2024
 *      Author: Fathy Anas
 */


#include "stdTypes.h"

s16 interpolation (s16 y1,s16 y2,s16 x1,s16 x2,s16 x)
{
	s16 y;
	y = ( ((s32)(y2-y1)*(x-x1))/(x2-x1) ) + y1;

	return y;
}
