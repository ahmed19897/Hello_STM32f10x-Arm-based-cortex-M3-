/*********************************************************************************/
/* Author    : Ahmed Osama                                                       */
/* Version   : V01                                                               */
/* Date      : 5 June   2022                                                     */
/*********************************************************************************/
#ifndef _SevSeg_interface_h
#define _SevSeg_interface_h

#define SevSeg_Cathode 0
#define SevSeg_Anode 1


void SevSeg_voidPrintNum(u8 copy_u8Ports,u8 copy_u8Seven_Segment_Type,u8 copy_PrintedNum);
void voidDelete_Num(u8 copy_u8Ports,u8 copy_u8Seven_Segment_Type);
#endif