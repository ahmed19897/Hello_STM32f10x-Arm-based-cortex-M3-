/*
 * main.c
 *
 *  Created on: Oct 14, 2022
 *      Author: A.N
 */
#include"BIT_MATH.h"
#include "STD_TYPES.h"

#include"RCC_interface.h"
#include"GPIO_INTERFACE.h"

#include "SOS_INTERFACE.h"

void Led1(void);
void Led2(void);
void Led3(void);

void main(void)
{

	RCC_VoidInitSysClock();
	RCC_VoidEnableClock(RCC_APB2,2);

	MGPIO_VoidSetPinDirection(GPIOA,GPIN0,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(GPIOA,GPIN1,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(GPIOA,GPIN2,OUTPUT_SPEED_2MHZ_PP);

	CreateTask(0,1000,Led1,0);
	CreateTask(1,4000,Led2,1);
	CreateTask(2,4000,Led3,2);

	SOS_VoidStart();

	while(1)
	{

	}
}

void Led1(void)
{
	static u8 u8Local_Toggle=0;
	TOGGLE_BIT(u8Local_Toggle,0);

	MGPIO_VoidSetPinValue(GPIOA,GPIN0,u8Local_Toggle);
}

void Led2(void)
{
	static u8 u8Local_Toggle1=0;
	TOGGLE_BIT(u8Local_Toggle1,0);

	MGPIO_VoidSetPinValue(GPIOA,GPIN1,u8Local_Toggle1);
}

void Led3(void)
{
	static u8 u8Local_Toggle2=0;
	TOGGLE_BIT(u8Local_Toggle2,0);

	MGPIO_VoidSetPinValue(GPIOA,GPIN2,u8Local_Toggle2);
}
