/*********************************************************************************/
/* Author    : Ahmed Osama                                                       */
/* Version   : V01                                                               */
/* Date      : 19 August 2020                                                    */
/*********************************************************************************/

#include"STD_TYPES.h"
#include"BIT_MATH.h"
//ba3d el libraries el mafrod a include el layers el ta7tya bas hena mafesh 3shan ana f akher layer aslun
#include"NVIC_Interface.h"
#include"NVIC_Private.h"
#include"NVIC_Config.h"


void MNVIC_VoidEnableInterrupt(u8 Copy_u8IntNumber)
{

	if(Copy_u8IntNumber<=31)
	{
		NVIC_ISER0=(1<<Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber<=59)
	{
		Copy_u8IntNumber-=32;
		NVIC_ISER1=(1<<Copy_u8IntNumber);
	}
	else
	{
		/*Return void*/
	}
	
}

void MNVIC_VoidDisableInterrupt(u8 Copy_u8IntNumber)
{

	if(Copy_u8IntNumber<=31)
	{
		NVIC_ICER0=(1<<Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber<=59)
	{
		Copy_u8IntNumber-=32;
		NVIC_ICER1=(1<<Copy_u8IntNumber);
	}
	else
	{
		/*Return void*/
	}
	
}


void MNVIC_voidSetPendingFlag(u8 Copy_u8IntNumber)
{
if(Copy_u8IntNumber<=31)
	{
		NVIC_ISPR0=(1<<Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber<=59)
	{
		Copy_u8IntNumber-=32;
		NVIC_ISPR1=(1<<Copy_u8IntNumber);
	}
	else
	{
		/*Return void*/
	}	
}

void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNumber)
{
if(Copy_u8IntNumber<=31)
	{
		NVIC_ICPR0=(1<<Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber<=59)
	{
		Copy_u8IntNumber-=32;
		NVIC_ICPR1=(1<<Copy_u8IntNumber);
	}
	else
	{
		/*Return void*/
	}	
}

u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber)
{
	u8 Local_u8Result=0;
if(Copy_u8IntNumber<=31)
	{
		Local_u8Result=GET_BIT(NVIC_IABP0,Copy_u8IntNumber);
	}
	else if (Copy_u8IntNumber<=59)
	{
		Copy_u8IntNumber-=32;
		Local_u8Result=GET_BIT(NVIC_IABP1,Copy_u8IntNumber);
	}
	else
	{
		/*Return void*/
	}
	return Local_u8Result;	
}

void MNVIC_voidSetPriority(s8 Copy_s8IntID,u8 Copy_u8GroupPriorty,u8 Copy_u8SubPriority,u8 Copy_u32Group)//set the priority group and sub priority
{
	u8 Local_u8Priority= Copy_u8SubPriority|Copy_u8GroupPriorty<<(Copy_u32Group-0x05FA0300)/256;
	/*  Core Peripheral	   */
	
	/*  External Peripheral*/
	if(Copy_s8IntID >=0)
	{
	NVIC_IPR[Copy_s8IntID]=Local_u8Priority << 4;
	}
	SCB_AIRCR=Copy_u32Group;
}


void MNVIC_voidInit(void)
{
	
	SCB_AIRCR=MNVIC_GROUP_SUB_DISTRIBUTION;
	
}


