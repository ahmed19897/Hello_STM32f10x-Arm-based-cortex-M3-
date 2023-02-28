/*
 * main.c
 *
 *  Created on: Jul 13, 2022
 *      Author: A.N
 */
#include <STD_TYPES.h>
#include <BIT_MATH.h>
#include "STK_interface.h"
#include "RCC_interface.h"
#include "GPIO_INTERFACE.h"
void (*callback) (void);
void LedOn(void);
void LedOff(void);
void VoidOpenHandOn(void);
void VoidOpenHandOff(void);
int i=0;
int Intopenhandsright [4]={3,2,1,0};
int Intopenhandsleft  [4]={4,5,6,7};

void main(void)
{
	/*initialize system clock*/
	RCC_VoidInitSysClock();
	/*initialize GPIOA clock*/
	RCC_VoidEnableClock(RCC_APB2,2);
	MGPIO_VoidSetPinDirection(GPIOA,GPIN0,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(GPIOA,GPIN1,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(GPIOA,GPIN2,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(GPIOA,GPIN3,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(GPIOA,GPIN4,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(GPIOA,GPIN5,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(GPIOA,GPIN6,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(GPIOA,GPIN7,OUTPUT_SPEED_2MHZ_PP);


	MSTK_voidInit();

	VoidOpenHandOn();

	while(1)
	{


	}

}


void LedOn(void)
{
	/*set the ODR of PIN0 in PORT B to high to activate the Pull up mode*/
	MGPIO_VoidSetPinValue(GPIOA,i,GPIO_HIGH);
	MSTK_voidSetIntervalPeriodic(320000,LedOff);
}
void LedOff(void)
{
	/*set the ODR of PIN0 in PORT B to high to activate the Pull up mode*/
	MGPIO_VoidSetPinValue(GPIOA,i,GPIO_LOW);
	i++;
	if (i>=8)
	{
		i=0;
	}
	MSTK_voidSetIntervalPeriodic(320000,LedOn);
}
void VoidOpenHandOn(void)
{
	MGPIO_VoidSetPinValue(GPIOA,Intopenhandsright[i],GPIO_HIGH);
	MGPIO_VoidSetPinValue(GPIOA,Intopenhandsleft[i],GPIO_HIGH);
	MSTK_voidSetIntervalPeriodic(640000,VoidOpenHandOff);
}
void VoidOpenHandOff(void)
{
	MGPIO_VoidSetPinValue(GPIOA,Intopenhandsright[i],GPIO_LOW);
	MGPIO_VoidSetPinValue(GPIOA,Intopenhandsleft[i],GPIO_LOW);
	i++;
	if (i>=5)
	{
		i=0;
	}
	MSTK_voidSetIntervalPeriodic(640000,VoidOpenHandOn);
}



