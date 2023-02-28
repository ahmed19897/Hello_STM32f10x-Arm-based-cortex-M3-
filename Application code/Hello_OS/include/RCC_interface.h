/*********************************************************************************/
/* Author    : Ahmed Assaf                                                       */
/* Version   : V01                                                               */
/* Date      : 8 August 2020                                                     */
/*********************************************************************************/
#include "STD_TYPES.h"

#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

#define RCC_AHB       0 
#define RCC_APB1      1
#define RCC_APB2      2

void RCC_VoidDisableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);
void RCC_VoidEnableClock(u8 Copy_u8BusId, u8 Copy_u8PerId);
void RCC_VoidInitSysClock(void);

#endif
