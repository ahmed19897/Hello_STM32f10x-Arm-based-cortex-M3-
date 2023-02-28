/*********************************************************************************/
/* Author    : Ahmed Osama                                                       */
/* Version   : V01                                                               */
/* Date      : 10 October 2022                                                    */
/*********************************************************************************/
#include "BIT_MATH.h"
#include "STD_TYPES.h"

#include "MDMA_PRIVATE.h"
#include "MDMA_INTERFACE.h"
#include "MDMA_CONFIG.h"


void MDMA_VoidChannelInit(void)
{
						/*
						1-mem to mem
						2-Priority Vhigh
						3-Source size, Destination size=32 bit
						4-MINC,PINC activated
						5-NO circular
						6-direction :
						7-transfer interrupt enable
						*/
	
		#if (CHANNEL_ID ==1)
			CLR_BIT(DMA->Channel[0].CCR,0);
			DMA->Channel[0].CCR=0b111101011011010;

		#endif


}

void MDMA_VoidChannelStart(u32 *Copy_Pu32SourceAdress,u32 *Copy_Pu32DestinationAdress,u16 Copy_u16BlockLenght)
{
	/*make sure channel is disabled so we can write on it*/
	CLR_BIT(DMA->Channel[0].CCR,0);
	
	/*write Address*/
	DMA->Channel[0].CMAR=Copy_Pu32SourceAdress;
	DMA->Channel[0].CPAR=Copy_Pu32DestinationAdress;
	
	/*Block length*/
	DMA->Channel[0].CNDTR=Copy_u16BlockLenght;
	
	/*make sure channel is enabled at the end of the start function*/
	SET_BIT(DMA->Channel[0].CCR,0);
}


