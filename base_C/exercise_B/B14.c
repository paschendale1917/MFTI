// Дана последовательность ненулевых целых чисел, в конце последовательности число 0. Посчитать количество чисел. Целые ненулевые числа. В конце последовательности ноль. Ноль в последовательность не входит.

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
        repetition++;
    } while (num);
    printf("%u", repetition - 1);
}
