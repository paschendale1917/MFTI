// Ввести целое число и «перевернуть» его, так чтобы первая цифра стала последней и т.д.

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

uint32_t num = 0;
uint32_t temp = 0;
uint8_t cnt = 0;
uint32_t result = 0;

int main(void)
{
    scanf("%u", &num);
    temp = num;
    while (temp)
    {
        temp /= 10;
        cnt++;
    }

    for (uint8_t i = 0; i < cnt; i++)
    {
        uint32_t tmp = 0;
        tmp = num / pow(10, i);
        tmp %= 10;
        result = result + tmp * pow(10, cnt - i - 1);
    }

    printf("%u", result);
}