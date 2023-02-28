#include"STD_TYPES.h"
#include"BIT_MATH.h"


#include"AFIO_Interface.h"
#include"AFIO_Config.h"
#include"AFIO_Private.h"




void MAFIO_VoidSetEXTIConfig(u8 Copy_u8Line,u8 Copy_u8PortMap);
{
	u8 Local_u8RegIndex=0;
	
	if(Local_u8Line<=3)
	{
		Local_u8RegIndex=0;
	}
	else if(Local_u8Line<=7)
	{
		Local_u8RegIndex  =1;
		Local_u8RegIndex -=4;
	}
	else if(Local_u8Line<=11)
	{
		Local_u8RegIndex  =2;
		Local_u8RegIndex -=8;	
	}
	else if(Local_u8Line<=15)
	{
		Local_u8RegIndex  =3;
		Local_u8RegIndex -=12;	
	} 
	
	AFIO->EXTICR[Local_u8RegInde] &~=((0b1111)<<(Copy_u8Line*4)); 
	AFIO->EXTICR[Local_u8RegInde] |=((Copy_u8PortMap)<<(Copy_u8Line*4)); 
	
}