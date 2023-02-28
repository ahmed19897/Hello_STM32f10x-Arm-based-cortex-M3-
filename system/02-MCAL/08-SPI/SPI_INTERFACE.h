/*********************************************************************************/
/* Author    : Ahmed Osama                                                       */
/* Version   : V01                                                               */
/* Date      : 29 October 2022                                                   */
/*********************************************************************************/

#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

void MSPI1_VoidInit(void);

void MSPI1_VoidSendReceiveSynch(u8 Copy_U8DataToTransmit, u8 *Copy_u8DataToReceive);


#endif