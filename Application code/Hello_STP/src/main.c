/*
 * main.c
 *
 *  Created on: Oct 25, 2022
 *      Author: A.N
 */
#include"BIT_MATH.h"
#include"STD_TYPES.h"

#include"RCC_interface.h"
#include"GPIO_INTERFACE.h"
#include"STK_interface.h"

#include"HSTP_INTERFACE.h"

void main(void)
{
	RCC_VoidInitSysClock();
	RCC_VoidEnableClock(RCC_APB2,2);

	MGPIO_VoidSetPinDirection(GPIOA,GPIN0,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(GPIOA,GPIN1,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(GPIOA,GPIN2,OUTPUT_SPEED_2MHZ_PP);

	MSTK_voidInit();



	while(1)
	{
		for (int i=0;i<8;i++)
		{
			VoidSendSynchrons(1<<i);
			MSTK_voidSetBusyWait(300000);
		}

	}
}
