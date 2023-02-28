/*********************************************************************************/
/* Author    : Ahmed Osama                                                       */
/* Version   : V01                                                               */
/* Date      : 19 August 2020                                                    */
/*********************************************************************************/
#ifndef NVIC_Interface_h
#define NVIC_Interface_h




#define GROUP3 0x05FA0300/*4 bits for group ,No sub priority*/
#define GROUP4 0x05FA0400/*3 bits for group ,1 sub priority*/
#define GROUP5 0x05FA0500/*2 bits for group ,2 sub priority*/
#define GROUP6 0x05FA0600/*1 bits for group ,3 sub priority*/
#define GROUP7 0x05FA0700/*0 bits for group ,4 sub priority*/



void MNVIC_VoidEnableInterrupt(u8 Copy_u8IntNumber);
void MNVIC_VoidDisableInterrupt(u8 Copy_u8IntNumber);
void MNVIC_voidSetPendingFlag(u8 Copy_u8IntNumber);
void MNVIC_voidClearPendingFlag(u8 Copy_u8IntNumber);
u8 MNVIC_u8GetActiveFlag(u8 Copy_u8IntNumber);
void MNVIC_voidSetPriority(s8 Copy_s8IntID,u8 Copy_u8GroupPriorty,u8 Copy_u8SubPriority,u8 Copy_u32Group);//set the priority group and sub priority
void MNVIC_voidInit();//distribute the priorty as wriiten in config (group and sub) 


#endif
