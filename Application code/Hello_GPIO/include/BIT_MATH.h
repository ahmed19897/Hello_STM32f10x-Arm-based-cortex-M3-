/****************************************************************************/
/* Auther      : Ahmed Osama                                                */
/* Date        : 29 july 2020                                               */
/* Version     : V01                                                        */
/****************************************************************************/
#ifndef _BIT_MATH_h
#define _BIT_MATH_h
/*guard file to prevent super loop of text replacment*/


#define SET_BIT(value,bit_num)      value|=(1<<bit_num)
/*set_bit will write 1 into the Bit_NUM in value Port*/


#define CLR_BIT(value,bit_num)    value&=~(1<<bit_num)
/*clear_bit will write 0 into Bit_NUM in value port*/

#define GET_BIT(value,bit_num)      ((value >> bit_num) & 1)
/*get_bit will return the value of the corrosponding bit*/

#define toggle_bit(value,bit_num)   value^=(1<<bit_num) 
/*toggle_bit will toggle the Bit_NUM in  Port value*/

#define Rotate_bit(REG,bit_num)     REG=(REG>>(bit_num)|(REG<<8-bit_num)) 
/* rotate bits from left to right (e.g 00000001->00000010.....etc) */

/*end of guard file */
#endif
