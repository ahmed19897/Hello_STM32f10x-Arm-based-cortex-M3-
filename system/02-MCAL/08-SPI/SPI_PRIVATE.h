/*********************************************************************************/
/* Author    : Ahmed Osama                                                       */
/* Version   : V01                                                               */
/* Date      : 29 October 2022                                                   */
/*********************************************************************************/


#ifndef SPI_PRIVATE_H
#define SPI_PRIVATE_H



typedef struct
{
	volatile u32 CR1	;
	volatile u32 CR2	;
	volatile u32 SR		;  
	volatile u32 DR		;
	volatile u32 CRCPR	;
	volatile u32 RXCRC	;
	volatile u32 TXCRC	;
	volatile u32 I2SCFGR;
	volatile u32 I2SPR	;
	
}SPI_REGISTERS

#define MSPI ((SPI_REGISTERS *)0x40013000)

#endif