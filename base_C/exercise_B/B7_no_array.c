// Ввести целое число и определить, верно ли, что в его записи есть  две одинаковые цифры, НЕ обязательно стоящие рядом.

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

uint32_t num = 0;
uint32_t temp = 0;
uint8_t cnt = 0;            //счетчик количества цифр
uint8_t repetition = 0;     //счетчик повторений цифры

int main(void)
{
    scanf("%u", &num);
    temp = num;
    while (temp)
    {
        temp /= 10;
        cnt++;
    }
    while(cnt){
    temp = num % 10;
    for (uint8_t i = 1; i < cnt ; i++)
    {
        temp != (uint32_t)(num/pow(10,i))%10 ? repetition : repetition++;
    }
    num/=10;
    cnt--;
}

    !repetition ? printf("NO") : printf("YES");
}
