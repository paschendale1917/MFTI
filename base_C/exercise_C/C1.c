// Составить функцию, модуль числа и привести пример ее использования.

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

int32_t num = 0;

uint32_t module(uint32_t number);

int main(void)
{
    scanf("%d", &num);
    printf("%d", module(num));
    return 0;
}

uint32_t module(uint32_t number)
{
    return number & 0x80000000 ? -number : number;
}