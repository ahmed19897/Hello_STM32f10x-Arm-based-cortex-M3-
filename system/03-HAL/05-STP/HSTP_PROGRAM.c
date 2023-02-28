/*********************************************************************************/
/* Author    : Ahmed Osama                                                       */
/* Version   : V01                                                               */
/* Date      : 25 October 2022                                                   */
/*********************************************************************************/


void VoidSendSynchrons(u8 u8Copy_DataToSend)
{
	s8 Local_Bit;
	
	for(s8 s8_LocalCounter=7;i>=0;i--)
	{
		/*send bit by bit the u8Copy_DataToSend*/
		Local_Bit=GET_BIT(u8Copy_DataToSend,s8_LocalCounter);
		MGPIO_VoidSetPinValue(SD_PIN,Local_Bit);
		
		/*pulse to shift clock to send the next bit*/
		MSTK_voidSetBusyWait(1);
		MGPIO_VoidSetPinValue(SERIAL_CLOCK_PIN,GPIOH);
		MSTK_voidSetBusyWait(1);
		MGPIO_VoidSetPinValue(SERIAL_CLOCK_PIN,GPIOLOW);
	}
	/*pulse to shift clock to send the next bit*/
	MSTK_voidSetBusyWait(1);
	MGPIO_VoidSetPinValue(SERIAL_CLOCK_PIN,GPIOH);
	MSTK_voidSetBusyWait(1);
	MGPIO_VoidSetPinValue(SERIAL_CLOCK_PIN,GPIOLOW);
}