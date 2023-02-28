/*************************************************************************************************************************************************************/
/* Author  :  Ahmed Osama                                                                                                                                    */
/* Version :  V01                                                                                                                                            */
/* Date    : 10 October 2022                                                                                                                                 */
/*************************************************************************************************************************************************************/


#ifndef SOS_PRIVATE_H
#define SOS_PRIVATE_H

#include"STD_TYPES.h"

typedef struct
{
	u16 Periodicity;
	void (*Fptr) (void);
	u8 FirstDelay;
	u8 state;
	
}Task;

static void Scheduler(void);


#endif
