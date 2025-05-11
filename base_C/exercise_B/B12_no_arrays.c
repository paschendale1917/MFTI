// Организовать ввод натурального числа с клавиатуры. Программа должна определить наименьшую и наибольшую цифры, которые входят в состав данного натурального числа.

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

uint32_t num = 0;
uint8_t max = 0;
uint8_t min = 0;

int main(void)
{
    scanf("%u", &num);
    max = num % 10;
    min = num % 10;
    while (num)
    {
        uint32_t tmp = num % 10;
        tmp > max ? max = tmp : max;
        tmp < min ? min = tmp : min;
        num /= 10;
    }

    printf("%u %u", min, max);
}