// Составить функцию, которая определяет сумму всех чисел от 1 до N и привести пример ее использования.

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

int32_t num;

uint64_t calc(uint8_t);

int main(void)
{
    scanf("%u", &num);
    printf("%llu", calc(num));
    return 0;
}

uint64_t calc(uint8_t number)
{
    return pow(2, number - 1);
}