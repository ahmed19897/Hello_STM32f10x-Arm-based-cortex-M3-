/*
 * main.c
 *
 *  Created on: Oct 18, 2022
 *      Author: A.N
 */

#include"BIT_MATH.h"
#include"STD_TYPES.h"

#include"RCC_interface.h"
#include"GPIO_INTERFACE.h"
#include"STK_interface.h"

#include "GPIO_private.h"

#include"file"

volatile u16 i=0;

void VoidPlaySpeaker(void);

void main(void)
{
	RCC_VoidInitSysClock();
	RCC_VoidEnableClock(RCC_APB2,2);

	MGPIO_VoidSetPinDirection(GPIOA,0,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(GPIOA,1,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(GPIOA,2,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(GPIOA,3,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(GPIOA,4,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(GPIOA,5,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(GPIOA,6,OUTPUT_SPEED_2MHZ_PP);

	MSTK_voidInit();
	MSTK_voidSetIntervalPeriodic(125,VoidPlaySpeaker);


	while(1)
	{

	}
}
void VoidPlaySpeaker(void)
{

	GPIOA_ODR=ARM_raw[i];
	i++;
	if (i==36688)
	{
		i=0;
	}
}
