#include"STD_TYPES.h"
#include"BIT_MATH.h"

#include"GPIO_interface.h"
#include"SevSeg_interface.h"

void SevSeg_voidPrintNum(u8 copy_u8Ports,u8 copy_u8Seven_Segment_Type,u8 copy_PrintedNum)
{
	switch (copy_u8Seven_Segment_Type)
	{
		case SevSeg_Cathode:
			switch (copy_PrintedNum){
				case 0:
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN0,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN1,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN2,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN3,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN4,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN5,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN6,GPIO_LOW);
				break;
			
				case 1:
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN0,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN1,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN2,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN3,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN4,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN5,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN6,GPIO_LOW);
				break;
				
				case 2:
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN0,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN1,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN2,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN3,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN4,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN5,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN6,GPIO_HIGH);
				break;
				
				case 3:
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN0,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN1,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN2,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN3,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN4,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN5,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN6,GPIO_HIGH);
				break;
				
				case 4:
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN0,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN1,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN2,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN3,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN4,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN5,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN6,GPIO_HIGH);
				break;
				
				case 5:
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN0,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN1,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN2,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN3,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN4,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN5,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN6,GPIO_HIGH);
				break;
				
				case 6:
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN0,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN1,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN2,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN3,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN4,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN5,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN6,GPIO_HIGH);
				break;

				case 7:
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN0,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN1,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN2,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN3,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN4,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN5,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN6,GPIO_HIGH);
				break;
				case 8:
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN0,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN1,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN2,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN3,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN4,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN5,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN6,GPIO_HIGH);
				break;

			}
			break;
		
		case SevSeg_Anode:
		switch (copy_PrintedNum){
				case 0:
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN0,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN1,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN2,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN3,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN4,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN5,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN6,GPIO_HIGH);
				break;
				
				case 1:
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN0,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN1,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN2,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN3,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN4,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN5,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN6,GPIO_HIGH);
				break;
				
				case 2:
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN0,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN1,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN2,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN3,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN4,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN5,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN6,GPIO_LOW);
				break;
				
				case 3:
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN0,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN1,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN2,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN3,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN4,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN5,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN6,GPIO_LOW);
				break;
				
				case 4:
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN0,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN1,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN2,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN3,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN4,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN5,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN6,GPIO_LOW);
				break;
				
				case 5:
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN0,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN1,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN2,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN3,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN4,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN5,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN6,GPIO_LOW);
				break;
				
				case 6:
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN0,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN1,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN2,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN3,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN4,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN5,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN6,GPIO_LOW);
				break;
				case 7:
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN0,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN1,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN2,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN3,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN4,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN5,GPIO_HIGH);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN6,GPIO_LOW);
				break;
				case 8:
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN0,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN1,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN2,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN3,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN4,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN5,GPIO_LOW);
				MGPIO_VoidSetPinValue(copy_u8Ports,GPIN6,GPIO_LOW);
				break;


		}
			break;
		
	}
	
}
void voidDelete_Num(u8 copy_u8Ports,u8 copy_u8Seven_Segment_Type)
{
switch (copy_u8Seven_Segment_Type)
	{
		case SevSeg_Cathode:
		MGPIO_VoidSetPinValue(copy_u8Ports,GPIN0,GPIO_LOW);
		MGPIO_VoidSetPinValue(copy_u8Ports,GPIN1,GPIO_LOW);
		MGPIO_VoidSetPinValue(copy_u8Ports,GPIN2,GPIO_LOW);
		MGPIO_VoidSetPinValue(copy_u8Ports,GPIN3,GPIO_LOW);
		MGPIO_VoidSetPinValue(copy_u8Ports,GPIN4,GPIO_LOW);
		MGPIO_VoidSetPinValue(copy_u8Ports,GPIN5,GPIO_LOW);
		MGPIO_VoidSetPinValue(copy_u8Ports,GPIN6,GPIO_LOW);
		break;
		case SevSeg_Anode:
		MGPIO_VoidSetPinValue(copy_u8Ports,GPIN0,GPIO_HIGH);
		MGPIO_VoidSetPinValue(copy_u8Ports,GPIN1,GPIO_HIGH);
		MGPIO_VoidSetPinValue(copy_u8Ports,GPIN2,GPIO_HIGH);
		MGPIO_VoidSetPinValue(copy_u8Ports,GPIN3,GPIO_HIGH);
		MGPIO_VoidSetPinValue(copy_u8Ports,GPIN4,GPIO_HIGH);
		MGPIO_VoidSetPinValue(copy_u8Ports,GPIN5,GPIO_HIGH);
		MGPIO_VoidSetPinValue(copy_u8Ports,GPIN6,GPIO_HIGH);
		break;
	}
}

