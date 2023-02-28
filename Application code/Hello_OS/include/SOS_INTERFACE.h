/*************************************************************************************************************************************************************/
/* Author  :  Ahmed Osama                                                                                                                                    */
/* Version :  V01                                                                                                                                            */
/* Date    : 10 October 2022                                                                                                                                 */
/*************************************************************************************************************************************************************/


#ifndef SOS_INTERFACE_h
#define SOS_INTERFACE_h

void CreateTask(u8 u8Copy_ID,u16 u16Copy_Periodicity,void (*ptr) (void),u8 u8Copy_FirstDelay);
void SOS_VoidStart(void);
void Task_Suspend(u8 u8Copy_TaskID);
void Resume_Suspend(u8 u8Copy_TaskID);
void Delete_Task(u8 u8Copy_TaskID);


#endif
