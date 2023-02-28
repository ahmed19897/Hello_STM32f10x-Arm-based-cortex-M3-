/*********************************************************************************/
/* Author    : Ahmed Osama                                                       */
/* Version   : V01                                                               */
/* Date      : 30 August 2020                                                    */
/*********************************************************************************/
#ifndef EXTI_Private_h
#define EXTI_Private_h


typedef struct
{
		volatile u32 IMR  ;
		volatile u32 EMR  ;
		volatile u32 RSIR ;
		volatile u32 FTR  ;
		volatile u32 SWIER;
		volatile u32 PR	  ;
	 
}EXTI_t;

#define EXTI ((volatile EXTI_t*)0x40010400)

#define LINE0		0
#define LINE1		1
#define LINE2		2
#define LINE3		3
#define LINE4		4

#define RISING		0
#define FALLING		1
#define ON_CHANGE	2


#endif