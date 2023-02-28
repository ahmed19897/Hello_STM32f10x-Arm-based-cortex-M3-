/*********************************************************************************/
/* Author    : Ahmed Osama                                                       */
/* Version   : V01                                                               */
/* Date      : 30 August 2020                                                    */
/*********************************************************************************/
#ifndef EXTI_Interface_h
#define EXTI_Interface_h


void MEXTI_VoidInit(void);
void MEXTI_VoidEnableExti(u8 Copy_u8Line);
void MEXTI_VoidDisableExti(u8 Copy_u8Line);
void MEXTI_VoidSwTrigger(u8 Copy_u8Line);
void MEXTI_VoidSetSignalLatch(u8 Copy_u8Line,u8 Copy_u8Mode);

void MEXTI_VoidSetCallBack(void (*ptr)(void) );

#endif
