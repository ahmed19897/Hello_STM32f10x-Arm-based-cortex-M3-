/*********************************************************************************/
/* Author    : Ahmed Osama                                                       */
/* Version   : V01                                                               */
/* Date      : 30 August 2020                                                    */
/*********************************************************************************/
#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include"EXTI_Interface.h"
#include"EXTI_Config.h"
#include"EXTI_Private.h"

void (*EXTI0_CallBack) (void);
/* line and mode needs to be checked using # defines*/
void MEXTI_VoidInit(void)
{

	CLR_BIT(EXTI->IMR,EXTRI_LINE);/*during initialization we should shutoff interrupt just to make sure nothing interrupt our initialization*/

	#if (EXTRI_MODE==RISING)
	SET_BIT(EXTI->RSIR,EXTRI_LINE);

	#elif (EXTRI_MODE==FALLING)
	SET_BIT(EXTI->FTR,EXTRI_LINE);

	#elif (EXTRI_MODE==ON_CHANGE)
	{
	SET_BIT(EXTI->RSIR,EXTRI_LINE);
	SET_BIT(EXTI->FTSR,EXTRI_LINE);
	}
	#endif

}


void MEXTI_VoidEnableExti(u8 Copy_u8Line)
{

	SET_BIT(EXTI->IMR,Copy_u8Line);

}


void MEXTI_VoidDisableExti(u8 Copy_u8Line)
{

	CLR_BIT(EXTI->IMR,Copy_u8Line);

}


void MEXTI_VoidSwTrigger(u8 Copy_u8Line)
{

	SET_BIT(EXTI->SWIER,Copy_u8Line);

}


void MEXTI_VoidSetSignalLatch(u8 Copy_u8Line,u8 Copy_u8Mode)//change the trigger in run time
{

	switch (Copy_u8Mode)
	{
		case RISING	  :	SET_BIT(EXTI->RSIR,EXTRI_LINE); break;
		case FALLING  : SET_BIT(EXTI->FTR,EXTRI_LINE); break;
		case ON_CHANGE: SET_BIT(EXTI->RSIR,EXTRI_LINE); break;
						SET_BIT(EXTI->FTR,EXTRI_LINE); break;
	}

}


void MEXTI_VoidSetCallBack(void (*ptr)(void) )
{

	EXTI0_CallBack=ptr;

}


void EXTI0_IRQHandler(void)
{

	SET_BIT( EXTI->PR , 0 );
	EXTI0_CallBack();

}
