// Дана последовательность ненулевых целых чисел, в конце последовательности число 0. Посчитать количество четных чисел. Последовательность ненулевых целых чисел. В конце последовательности число ноль.

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

uint32_t num = 0;
uint16_t repetition = 0;

int main(void)
{
    do
    {
        scanf("%u", &num);
        if(!(num%2))repetition++;
    } while (num);
    printf("%u", repetition - 1);
}
