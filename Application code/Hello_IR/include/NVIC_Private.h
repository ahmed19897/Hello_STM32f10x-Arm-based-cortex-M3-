/*********************************************************************************/
/* Author    : Ahmed Osama                                                       */
/* Version   : V01                                                               */
/* Date      : 19 August 2020                                                    */
/*********************************************************************************/
#ifndef NVIC_Private_h
#define NVIC_Private_h
/*0xE000E100 NVIC base address*/
#define NVIC_ISER0		*((u32*)0xE000E100)/*enable external interrupts from 00 to 31*/
#define NVIC_ISER1		*((u32*)0xE000E104)/*enable external interrupts from 32 to 59*/

#define NVIC_ICER0		*((u32*)0xE000E180)/*Disbale external interrupts from 00 to 31*/
#define NVIC_ICER1		*((u32*)0xE000E184)/*Disbale external interrupts from 32 to 63*/

#define NVIC_ISPR0		*((u32*)0xE000E200)/*Set bending flag for interrupts from 00 to 31*/
#define NVIC_ISPR1		*((u32*)0xE000E204)/*Set bending flag for interrupts from 32 to 59*/
 
#define NVIC_ICPR0		*((u32*)0xE000E280)/*clear bendings flag for interrupts from 00 to 31*/
#define NVIC_ICPR1		*((u32*)0xE000E284)/*clear bendings flag for interrupts from 32 to 59*/

#define NVIC_IABP0		*((volatile u32*)0xE000E300)/*Reads active flag for interrupts from 00 to 31*/
#define NVIC_IABP1		*((volatile u32*)0xE000E304)/*/*Reads active flag for interrupts from 32 to 59*/

#define NVIC_IPR 		((volatile u8*)0xE000E400)/*set the SW priority*/
#define SCB_AIRCR 		*((volatile u32*)0xE000ED0C)/*to determine how many gorups and sub group bits*/


#define MNVIC_GROUP_4_SUB_0  0x05FA0300
#define MNVIC_GROUP_3_SUB_1  0x05FA0400
#define MNVIC_GROUP_2_SUB_2  0x05FA0500
#define MNVIC_GROUP_1_SUB_3  0x05FA0600 
#define MNVIC_GROUP_0_SUB_4  0x05FA0700 





#endif
