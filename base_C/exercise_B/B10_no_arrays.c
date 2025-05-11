// Ввести целое число и определить, верно ли, что все его цифры расположены в порядке возрастания.

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

uint32_t num = 0;
uint32_t temp = 0;
uint8_t cnt = 0;
uint8_t stop_flag = 0;

int main(void)
{
    scanf("%u", &num);
    temp = num;
    while (temp)
    {
        temp /= 10;
        cnt++;
    }

    for (uint8_t i = cnt - 1; i > 0; i--)
    {
        uint32_t temp1, temp2 = 0;
        temp1 = num / pow(10, i);
        temp2 = num / pow(10, i - 1);

        if (temp1 % 10 > temp2 % 10)
        {
            stop_flag = 1;
            break;
        }
    }

    !stop_flag ? printf("YES") : printf("NO");
}