/*
 * main.c
 *
 *  Created on: Sep 22, 2022
 *      Author: A.N
 */
#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include "STDbool.h"

#include<RCC_interface.h>
#include<GPIO_INTERFACE.h>
#include<NVIC_Interface.h>
#include<STK_interface.h>
#include<EXTI_Interface.h>
#include<LEDMRX_INTERFACE.h>
#include<HIR_INTERFACE.h>

extern volatile u8 u8RemoteControlData;//variable that carry the user's remote data
extern volatile bool KeepPrintingCurrentLetter;//true to keep printing the current letter


void main(void)
{
	int Data_Array[32] ={0,24, 202, 61, 202, 24, 64, 160, 64,     0, 24, 202, 61, 74, 152, 16, 40, 16,        0,24, 202, 61, 202, 24, 4, 10, 4};

	int counter=0;
	int *PData_Array;

	PData_Array=Data_Array;

	/*initialize the clock on GPIOA and GPIOB*/
	RCC_VoidInitSysClock();
	RCC_VoidEnableClock(RCC_APB2,2);
	RCC_VoidEnableClock(RCC_APB2,3);

	/*Declare the GPIOA Pin's States*/
	MGPIO_VoidSetPinDirection(GPIOA,0,0b0100);/*input floating*/
	MGPIO_VoidSetPinDirection(GPIOB,0,0b0010);/*output push pull*/
	MGPIO_VoidSetPinDirection(GPIOB,1,0b0010);/*output push pull*/
	MGPIO_VoidSetPinDirection(GPIOB,2,0b0010);/*output push pull*/

	/*initialize the interruput on External interrupt 0 line */
	MNVIC_voidInit();
	MNVIC_VoidEnableInterrupt(6);

	/*Define which function to execute when we get the interrupt from the IR reciver*/
	MEXTI_VoidSetCallBack( voidGetFrame_TakeAction_Play );
	MEXTI_VoidInit();
	MEXTI_VoidEnableExti(0);

	/*initialize systyk timer*/
	MSTK_voidInit();

	/*initialize LED MATRIX*/
	HLEDMRX_VoidInit();

	/*while(1)
	{
		if (u8RemoteControlData==1)
		{
			MGPIO_VoidSetPinValue(GPIOB,0,GPIO_HIGH);
			MGPIO_VoidSetPinValue(GPIOB,1,GPIO_LOW);
			MGPIO_VoidSetPinValue(GPIOB,2,GPIO_HIGH);
		}
		else if (u8RemoteControlData==2)
		{
			MGPIO_VoidSetPinValue(GPIOB,0,GPIO_HIGH);
			MGPIO_VoidSetPinValue(GPIOB,1,GPIO_HIGH);
			MGPIO_VoidSetPinValue(GPIOB,2,GPIO_LOW);
		}
		else if (u8RemoteControlData==3)
		{
			MGPIO_VoidSetPinValue(GPIOB,0,GPIO_LOW);
			MGPIO_VoidSetPinValue(GPIOB,1,GPIO_HIGH);
			MGPIO_VoidSetPinValue(GPIOB,2,GPIO_HIGH);
		}
		else
		{
			MGPIO_VoidSetPinValue(GPIOB,0,GPIO_LOW);
			MGPIO_VoidSetPinValue(GPIOB,1,GPIO_LOW);
			MGPIO_VoidSetPinValue(GPIOB,2,GPIO_LOW);
		}

	}*/

	while(1)
	{

		if (u8RemoteControlData==1)
		{
			if (counter>=3)
			{
				PData_Array=Data_Array;
				counter=0;
			}

			HLEDMRX_VoidDisplay(PData_Array,1000);
			KeepPrintingCurrentLetter=true;
			PData_Array=PData_Array+9;
			counter++;

		}

		if (u8RemoteControlData==2)
		{
			if (counter>=3)
			{
				PData_Array=Data_Array;
				counter=0;
			}

			HLEDMRX_VoidDisplay(PData_Array,250);
			KeepPrintingCurrentLetter=true;
			PData_Array=PData_Array+9;
			counter++;

		}

		if (u8RemoteControlData==3)
		{
			if (counter>=3)
			{
				PData_Array=Data_Array;
				counter=0;
			}

			HLEDMRX_VoidDisplay(PData_Array,100);
			KeepPrintingCurrentLetter=true;
			PData_Array=PData_Array+9;
			counter++;

		}
		if (u8RemoteControlData==4)
		{
			HLEDMRX_VoidDisplay(PData_Array,1000);
			KeepPrintingCurrentLetter=true;
		}

	}

}
