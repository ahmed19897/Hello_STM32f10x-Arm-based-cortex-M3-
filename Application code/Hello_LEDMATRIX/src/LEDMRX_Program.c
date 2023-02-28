/*********************************************************************************/
/* Author    : Ahmed Osama                                                       */
/* Version   : V01                                                               */
/* Date      : 14 Sept  2022                                                     */
/*********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "STDbool.h"

#include "GPIO_INTERFACE.h"
#include "STK_Interface.h"

#include "LEDMRX_Interface.h"
#include "LEDMRX_Private.h"
#include "LEDMRX_Config.h"

extern KeepPrintingCurrentLetter;

void HLEDMRX_VoidInit(void)
{
	
	
	 MGPIO_VoidSetPinDirection(GPIOA,GPIN0,OUTPUT_SPEED_2MHZ_PP);
	 MGPIO_VoidSetPinDirection(GPIOA,GPIN1,OUTPUT_SPEED_2MHZ_PP);
	 MGPIO_VoidSetPinDirection(GPIOA,GPIN2,OUTPUT_SPEED_2MHZ_PP);
	 MGPIO_VoidSetPinDirection(GPIOA,GPIN3,OUTPUT_SPEED_2MHZ_PP);
	 MGPIO_VoidSetPinDirection(GPIOA,GPIN4,OUTPUT_SPEED_2MHZ_PP);
	 MGPIO_VoidSetPinDirection(GPIOA,GPIN5,OUTPUT_SPEED_2MHZ_PP);
	 MGPIO_VoidSetPinDirection(GPIOA,GPIN6,OUTPUT_SPEED_2MHZ_PP);
	 
	 MGPIO_VoidSetPinDirection(GPIOB,GPIN0,OUTPUT_SPEED_2MHZ_PP);
	 MGPIO_VoidSetPinDirection(GPIOB,GPIN1,OUTPUT_SPEED_2MHZ_PP);
	 MGPIO_VoidSetPinDirection(GPIOB,GPIN5,OUTPUT_SPEED_2MHZ_PP);
	 MGPIO_VoidSetPinDirection(GPIOB,GPIN6,OUTPUT_SPEED_2MHZ_PP);
	 MGPIO_VoidSetPinDirection(GPIOB,GPIN7,OUTPUT_SPEED_2MHZ_PP);
	 MGPIO_VoidSetPinDirection(GPIOB,GPIN8,OUTPUT_SPEED_2MHZ_PP);
	 MGPIO_VoidSetPinDirection(GPIOB,GPIN9,OUTPUT_SPEED_2MHZ_PP);
	 
	 
}



void HLEDMRX_VoidDisplay(int *u8DataArray,int TimeToSwitchToNextFrame)
{

	int timeout=0;

	while(KeepPrintingCurrentLetter)
	{

		for (int i=0;i<7;i++)
		{

				/*Disable All Columns*/
				DisableAllCols();

				/*enable row*/
				SetRowValues(u8DataArray[i]);

				/*Enable one column at a time */
				MGPIO_VoidSetPinValue(GPIOA,i,GPIO_LOW);

				/*2.5 ms delay*/
				MSTK_voidSetBusyWait(2500);

				timeout++;

				if (timeout>TimeToSwitchToNextFrame)
				{

					KeepPrintingCurrentLetter=false;
					timeout=0;

				}

		}

	}

}



static void DisableAllCols(void)
{
	
	
	MGPIO_VoidSetPinValue(GPIOA,GPIN0,GPIO_HIGH);
	MGPIO_VoidSetPinValue(GPIOA,GPIN1,GPIO_HIGH);
	MGPIO_VoidSetPinValue(GPIOA,GPIN2,GPIO_HIGH);
	MGPIO_VoidSetPinValue(GPIOA,GPIN3,GPIO_HIGH);
	MGPIO_VoidSetPinValue(GPIOA,GPIN4,GPIO_HIGH);
	MGPIO_VoidSetPinValue(GPIOA,GPIN5,GPIO_HIGH);
	MGPIO_VoidSetPinValue(GPIOA,GPIN6,GPIO_HIGH);
	
	
}



static void SetRowValues( int u8DataArray)
{
	
	
	int Local_u8Bit;
	
	Local_u8Bit=GET_BIT(u8DataArray,0);
	MGPIO_VoidSetPinValue(GPIOB,GPIN0,Local_u8Bit);
	
	Local_u8Bit=GET_BIT(u8DataArray,1);
	MGPIO_VoidSetPinValue(GPIOB,GPIN1,Local_u8Bit);
	
	Local_u8Bit=GET_BIT(u8DataArray,2);
	MGPIO_VoidSetPinValue(GPIOB,GPIN5,Local_u8Bit);
	
	Local_u8Bit=GET_BIT(u8DataArray,3);
	MGPIO_VoidSetPinValue(GPIOB,GPIN6,Local_u8Bit);
	
	Local_u8Bit=GET_BIT(u8DataArray,4);
	MGPIO_VoidSetPinValue(GPIOB,GPIN7,Local_u8Bit);
	
	Local_u8Bit=GET_BIT(u8DataArray,5);
	MGPIO_VoidSetPinValue(GPIOB,GPIN8,Local_u8Bit);
	
	Local_u8Bit=GET_BIT(u8DataArray,6);
	MGPIO_VoidSetPinValue(GPIOB,GPIN9,Local_u8Bit);
	
	
}
