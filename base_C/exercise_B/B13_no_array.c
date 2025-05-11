// Посчитать количество четных и нечетных цифр числа.

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

uint32_t num = 0;
uint8_t odd = 0;
uint8_t even = 0;

int main(void)
{
    scanf("%u", &num);
    while (num)
    {
        num % 10 % 2 ? odd++ : even++;
        num /= 10;
    }

    printf("%u %u", even, odd);
}