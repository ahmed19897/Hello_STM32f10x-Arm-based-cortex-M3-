/*************************************************************************************************************************************************************/
/* Author  :  Ahmed Osama                                                                                                                                    */
/* Version :  V01                                                                                                                                            */
/* Date    : 10 October 2022                                                                                                                                 */
/*************************************************************************************************************************************************************/
#include"BIT_MATH.h"
#include"STD_TYPES.h"

#include"SOS_PRIVATE.h"
#include "SOS_CONFIG.h"
#include"SOS_INTERFACE.h"

#include"STK_interface.h"


#define NULL  (void *)0


static Task OS_Task[NumberOfTasks]={NULL};

volatile u16 TickCount=0;

void CreateTask(u8 u8Copy_ID,u16 u16Copy_Periodicity,void (*ptr) (void),u8 u8Copy_FirstDelay)
{

	OS_Task[u8Copy_ID].Periodicity=u16Copy_Periodicity;
	OS_Task[u8Copy_ID].Fptr	  	=ptr			    ;
	OS_Task[u8Copy_ID].FirstDelay =u8Copy_FirstDelay  ;
	OS_Task[u8Copy_ID].state		=TASK_READY			;
}


void SOS_VoidStart(void)
{
	
	/*initialize Systk*/
	MSTK_voidInit();
	
	/*Tick Time ------>1ms*/
	MSTK_voidSetIntervalPeriodic(1000,Scheduler);
	
}

static void Scheduler(void)
{

	for(u8 i=0;i<NumberOfTasks;i++)
	{
		if(OS_Task[i].Fptr!=NULL )
		{

			if(OS_Task[i].FirstDelay==0 && OS_Task[i].state==TASK_READY)
			{
				OS_Task[i].FirstDelay=OS_Task[i].Periodicity-1;
				OS_Task[i].Fptr();
			}
			else
			{
				OS_Task[i].FirstDelay--;
			}
		}
			
	}
	
}


void Task_Suspend(u8 u8Copy_TaskID)
{
	OS_Task[u8Copy_TaskID].state=TASK_SUSPEND;
}

void Resume_Suspend(u8 u8Copy_TaskID)
{
	OS_Task[u8Copy_TaskID].state=TASK_READY;
}

void Delete_Task(u8 u8Copy_TaskID)
{
	OS_Task[u8Copy_TaskID].Fptr=NULL;
}
