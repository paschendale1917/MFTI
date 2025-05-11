// Ввести целое число и определить, верно ли, что все его цифры четные. 

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

uint32_t num = 0;
uint8_t odd=0;  //счетчик нечетных чисел


int main(void)
{
    scanf("%u", &num);
   while(num){
     num%10%2 ? odd++ : odd;
     num/=10;
    }

    odd? printf("NO") : printf("YES");
}