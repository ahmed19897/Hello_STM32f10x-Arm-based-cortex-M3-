
#include"BIT_MATH.h"
#include "STD_TYPES.h"

#include "RCC_interface.h"
#include "NVIC_Interface.h"
#include "MDMA_INTERFACE.h"
#include "MDMA_PRIVATE.h"

u32 Arr1[1000]={[0 ... 999]=4};
u32 Arr2[1000];

u32 Arr3[1000]={[0 ... 999]=1};
u32 Arr4[1000];

void main(void)
{
	
	
	
	RCC_VoidInitSysClock();
	RCC_VoidEnableClock(RCC_AHB,0);

	MDMA_VoidChannelInit();
	
	MNVIC_voidInit();
	MNVIC_VoidEnableInterrupt(11);
	
	MDMA_VoidChannelStart(Arr1,Arr2,1000);
	
	for (u16 i=0;i<1000;i++)
	{
		Arr4[i]=Arr3[i];
	}
	while(1)
	{
		
	}
	
}
void DMA1_Channel1_IRQHandler(void)
{
	/*clear GIF*/
	DMA->IFCR=1<<0;
	/*clear TC*/
	DMA->IFCR=1<<1;
}
