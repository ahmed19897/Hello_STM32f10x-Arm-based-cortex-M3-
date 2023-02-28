#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"RCC_interface.h"
#include"GPIO_interface.h"
#include"SevSeg_Interface.h"

void main(void)
{
	/*initialize system clock*/
	RCC_voidInitSysClock();
	/*initialize GPIOA clock*/
	RCC_voidEnableClock(RCC_APB2,2);
	/*initialize GPIOB clock*/
	RCC_voidEnableClock(RCC_APB2,3);
	/*initialize GPIOC clock*/
	RCC_voidEnableClock(RCC_APB2,4);

	/*set PORT A to output Push/pull*/
	MGPIO_VoidSetPinDirection(GPIOA,GPIN0,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(GPIOA,GPIN1,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(GPIOA,GPIN2,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(GPIOA,GPIN3,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(GPIOA,GPIN4,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(GPIOA,GPIN5,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_VoidSetPinDirection(GPIOA,GPIN6,OUTPUT_SPEED_2MHZ_PP);
	/*set PORT A to output Push/pull*/

	/*set the PIN0 in Port B to input Push Pull mode*/
	MGPIO_VoidSetPinDirection(GPIOB,GPIN0,INPUT_PULL_UP_DOWN);
	/*set the ODR of PIN0 in PORT B to high to activate the Pull up mode*/
	MGPIO_VoidSetPinValue(GPIOB,GPIN0,GPIO_HIGH);
	/*W:variable to set the for loop to count to */
	u16 w=500;
	while(1)
		{
			/*print the numbers from 0 to 8 continously*/
			/*for(u8 i=0;i<=9;i++)
			{
				SevSeg_voidPrintNum(GPIOA,SevSeg_Cathode,i);
				for (u16 i=0;i<w;i++)
					{
						for (u16 j=0;j<w;j++)
						{
							asm("NOP");
						}
					}
				SevSeg_voidDeleteNum(GPIOA,SevSeg_Cathode);
				for (u16 i=0;i<w;i++)
					{
						for (u16 j=0;j<w;j++)
						{
							asm("NOP");
						}
					}
			}*/
			/*print the numbers from 0 to 8 continously*/
			if (MGPIO_u8GetPinValue(GPIOB,GPIN0)==0)
				{
				MGPIO_VoidSetPinValue(GPIOA, GPIN1, GPIO_HIGH);
				}
			else
				MGPIO_VoidSetPinValue(GPIOA, GPIN1, GPIO_LOW);

		}
}
