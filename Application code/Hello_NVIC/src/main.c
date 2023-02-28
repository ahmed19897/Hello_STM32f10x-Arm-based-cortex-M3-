/*
 * main.c
 *
 *  Created on: Jul 9, 2022
 *      Author: A.N
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_INTERFACE.h"
#include "RCC_interface.h"
#include "NVIC_Interface.h"



void main(void)

{
	/*initialize clocks*/
	RCC_VoidInitSysClock();
	RCC_VoidEnableClock(RCC_APB2,2);/*enable clock on GPIO*/

	/*initialize NVIC*/
	/*3adel el function bta3et el set priority*/
	MNVIC_voidInit();
	MNVIC_voidSetPriority(6, 0b01000000, 0, 1);
	MNVIC_voidSetPriority(6, 0b01000000, 3, 0);
	/*pin Modes*/
	MGPIO_VoidSetPinDirection(GPIOA,GPIN0,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(GPIOA,GPIN1,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(GPIOA,GPIN2,OUTPUT_SPEED_2MHZ_PP);
/*enable EXTI0 Interrupt*/
	MNVIC_VoidEnableInterrupt(6);
	MNVIC_VoidEnableInterrupt(7);
	MNVIC_voidSetPendingFlag(6);
	while(1)
	{

	}

}


void EXTI0_IRQHandler(void)
{
	MGPIO_VoidSetPinValue(GPIOA,GPIN0,GPIO_HIGH);
	MNVIC_voidSetPendingFlag(7);
	MGPIO_VoidSetPinValue(GPIOA,GPIN1,GPIO_HIGH);
	MGPIO_VoidSetPinValue(GPIOA,GPIN2,GPIO_LOW);

}

void EXTI1_IRQHandler(void)
{

	MGPIO_VoidSetPinValue(GPIOA,GPIN2,GPIO_HIGH);
	MGPIO_VoidSetPinValue(GPIOA,GPIN1,GPIO_LOW);
	MGPIO_VoidSetPinValue(GPIOA,GPIN0,GPIO_LOW);

}
