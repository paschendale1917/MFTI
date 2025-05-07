
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define F_APB2                  100000000 //смотрим в секцию RCC
#define BAUDRATE             		115200  //bod
#define USARTDIV                (float)F_APB2/(8*(2-OVER8_VALUE)*BAUDRATE)
#define OVER8_VALUE             0

uint16_t mantissa=0;
float fraction=0;

int32_t get_float_from_mem(float float_num);
void float2brr(float float_num, uint16_t *mant, float *fr);

int main(void)
{
   float2brr(USARTDIV,&mantissa,&fraction);
    printf("%d %.5f", mantissa, fraction);
}

int32_t get_float_from_mem(float float_num){
	int32_t int_num=0;
	uint8_t temp=0;
	for (uint8_t i=0; i < 4; i++){
		temp=*((uint8_t*)(&float_num) + (4-i-1));
		int_num|=(uint32_t)temp<<(8*(4-i-1));
	}
	return int_num;
}

void float2brr(float float_num, uint16_t *mant, float *fr){
	//float myfloat=USARTDIV;
	int32_t tmp_exp=get_float_from_mem(USARTDIV);
	int32_t tmp_mant=get_float_from_mem(USARTDIV);
	
	tmp_exp=(((tmp_exp&0x7FFFFFFF)>>23)&0xff)-127;
	tmp_exp=pow(2,tmp_exp);
	float fract=0;
	tmp_mant=tmp_mant&0x7FFFFF;
	fract=(tmp_mant|0x3F800000);//(0x7f<<23);
//	float fract = 1, div = 2;
//	for (uint8_t i = 23; i >0; i--) {
 //  int32_t bitValue = ((0x01 << (i-1)) & tmp_mant) >> (i-0x01);
//   fract += bitValue / div;
 //  div *= 2;
// }
	*mant=((uint16_t)(tmp_exp*fract));
	*fr=fract;
}