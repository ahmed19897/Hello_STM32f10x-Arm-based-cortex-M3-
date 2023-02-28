#include "RCC_interface.h"
#include "GPIO_INTERFACE.h"
#include "STK_interface.h"
#include "STDbool.h"
#include <LEDMRX_Interface.h>

bool KeepPrintingCurrentLetter=true;

int Data_Array[8] ={0, 124,  18, 18, 18, 124,   0, 0};
int Data_Array2[8]={0, 126,  16, 16, 16,  16, 126, 0};
int Data_Array3[8]={0,   0, 126,  4,  8,   4, 126, 0};
int *PData_Array;
int *PData_Array2;
int *PData_Array3;

void main (void)
{

	PData_Array=Data_Array;
	PData_Array2=Data_Array2;
	PData_Array3=Data_Array3;


	RCC_VoidInitSysClock();
	RCC_VoidEnableClock(RCC_APB2,2);
	RCC_VoidEnableClock(RCC_APB2,3);

	MSTK_voidInit();

	HLEDMRX_VoidInit();

	while(1)
		{

			HLEDMRX_VoidDisplay(PData_Array,4500);
			KeepPrintingCurrentLetter=true;
			PData_Array++;

			HLEDMRX_VoidDisplay(PData_Array,4500);
			KeepPrintingCurrentLetter=true;
			PData_Array++;

		}

}
