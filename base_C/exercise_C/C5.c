// Составить функцию, которая определяет сумму всех чисел от 1 до N и привести пример ее использования.
//Одно целое положительное число N 

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

int32_t num;

uint32_t calc(uint32_t);

int main(void)
{
    scanf("%u", &num);
    printf("%u", calc(num));
    return 0;
}

uint32_t calc(uint32_t number)
{
    uint32_t result = 0;
    for (uint32_t i = 1; i <=number; i++)
    {
        result += i;
    }
    return result;
}