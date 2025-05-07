// Ввести целое число и определить, верно ли, что в его записи есть две одинаковые цифры, стоящие рядом.

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

uint32_t num = 0;
uint8_t temp=0;
uint8_t repetition=0;

int main(void)
{
    scanf("%u", &num);
    while(num){
        temp=num%10;
        num/=10;
        temp!=num%10?repetition:repetition++;
       
    } 
    !repetition?printf("NO"): printf("YES");
}
