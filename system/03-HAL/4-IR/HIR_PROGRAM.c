/*********************************************************************************/
/* Author    : Ahmed Osama                                                       */
/* Version   : V01                                                               */
/* Date      : 02 OCT  2022                                                      */
/*********************************************************************************/
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include<GPIO_INTERFACE.h>
#include<STK_interface.h>

#include "HIR_INTERFACE.h"
#include "HIR_PRIVATE.h"
#include "HIR_CONFIG.h"


volatile u8 U8StartFlag		 = 0 	  ;
volatile u32 U32DataFrame[50]={0}	  ;
volatile u8 EdgeCounter		 = 0 	  ;
volatile u8 U8Data			 = 0 	  ;
extern volatile u8 u8RemoteControlData;

void voidGetFrame_TakeAction_Play(void)
{

	if (U8StartFlag==0)
	{
		MSTK_voidSetIntervalSingle(1000000,VoidTakeAction);
		U8StartFlag=1;
	}
	else
	{
		U32DataFrame[EdgeCounter]=MSTK_u32GetElapsedTime();
		MSTK_voidSetIntervalSingle(1000000,VoidTakeAction);
		EdgeCounter++;
	}

}



void VoidTakeAction(void)
{

	u8 i;
	U8Data=0;

	if ((U32DataFrame[0]>=10000) && (U32DataFrame[0]<=14000) && (EdgeCounter>=36))
	{
		for (i=0;i<8;i++)
			{

			if (U32DataFrame[17+i]>=2000 && U32DataFrame[17+i]<=2300)
				{
					SET_BIT(U8Data,i);
				}
				else
					CLR_BIT(U8Data,i);
			}
		VoidPlay();
	}
	else
	{
		U8Data=-1;
	}
	U8StartFlag		= 0	;
	U32DataFrame[0]	= 0 ;
	EdgeCounter		= 0 ;

}



void VoidPlay(void)
{

	switch(U8Data)
	{

	case 12://1
		u8RemoteControlData=1;
		break;

	case 24://2
		u8RemoteControlData=2;
		break;

	case 94://3
		u8RemoteControlData=3;
		break;

	case -1:
		break;

	}

}
