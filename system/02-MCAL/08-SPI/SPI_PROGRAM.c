/*********************************************************************************/
/* Author    : Ahmed Osama                                                       */
/* Version   : V01                                                               */
/* Date      : 29 October 2022                                                   */
/*********************************************************************************/


void MSPI1_VoidSendReceiveSynch(u8 Copy_U8DataToTransmit, u8 *Copy_u8DataToReceive);
{
	/*pull the select slave pin low to start sending the data */
	MGPIO_VoidSetPinValue(MSPI1SlaveLocation,LOW);
	
	/*send the data*/
	MSPI1->=Copy_U8DataToTransmit;
	
	/*wait till done sending*/
	while((GET_BIT(MSPI1->SR,7)==1));
	
	/*get the received data */
	*Copy_u8DataToReceive=MSPI1->DR;
	
	/* push the select slave pin high to end the selection*/
	MGPIO_VoidSetPinValue(MSPI1SlaveLocation,High);
	
	
	
}
