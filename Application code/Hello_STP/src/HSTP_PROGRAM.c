/*********************************************************************************/
/* Author    : Ahmed Osama                                                       */
/* Version   : V01                                                               */
/* Date      : 25 October 2022                                                   */
/*********************************************************************************/
#include"BIT_MATH.h"
#include"STD_TYPES.h"

#include"RCC_interface.h"
#include"GPIO_INTERFACE.h"
#include"STK_interface.h"

#include"HSTP_CONFIG.h"
#include"HSTP_PRIVATE.h"
#include"HSTP_INTERFACE.h"

void VoidSendSynchrons(u8 u8Copy_DataToSend)
{
	s8 Local_Bit;
	
	for(s8 s8_LocalCounter=7;s8_LocalCounter>=0;s8_LocalCounter--)
	{
		/*send bit by bit the u8Copy_DataToSend*/
		Local_Bit=GET_BIT(u8Copy_DataToSend,s8_LocalCounter);
		MGPIO_VoidSetPinValue(SD_PIN,Local_Bit);
		
		/*pulse to shift clock to send the next bit*/
		MSTK_voidSetBusyWait(1);
		MGPIO_VoidSetPinValue(SERIAL_SHIFT_PIN,GPIO_HIGH);
		MSTK_voidSetBusyWait(1);
		MGPIO_VoidSetPinValue(SERIAL_SHIFT_PIN,GPIO_LOW);
	}
	/*pulse to shift clock to send the next bit*/
	MSTK_voidSetBusyWait(1);
	MGPIO_VoidSetPinValue(SERIAL_STORAGE_PIN,GPIO_HIGH);
	MSTK_voidSetBusyWait(1);
	MGPIO_VoidSetPinValue(SERIAL_STORAGE_PIN,GPIO_LOW);
}
