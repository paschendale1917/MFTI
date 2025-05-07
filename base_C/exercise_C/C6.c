// Составить функцию, которая определяет сумму всех чисел от 1 до N и привести пример ее использования.Цлое число от 1 до 64 

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#define ERROR 1

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
    if(number>64) return ERROR;
    return pow(2, number - 1);
}