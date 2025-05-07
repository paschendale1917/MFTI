// Ввести целое число и определить, верно ли, что в нём ровно одна цифра «9». 

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

uint32_t num = 0;
uint8_t repetition=0;

int main(void)
{
    scanf("%u", &num);
   while(num){
     num%10!=9 ? repetition : repetition++;
     num/=10;
    }

    repetition!=1? printf("NO") : printf("YES");
}