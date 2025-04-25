// Составить функцию, возведение числа N в степень P. int power(n, p) и привести пример ее использования.

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int32_t num = 0;
uint8_t pwr = 0;

uint32_t module(uint32_t number);
uint32_t mypow(int32_t number, int8_t power);

int main(void)
{
    scanf("%d%d", &num, &pwr);
    printf("%d", mypow(num, pwr));
}

uint32_t module(uint32_t number)
{
    return number & 0x80000000 ? -number : number;
}

uint32_t mypow(int32_t number, int8_t power)
{
    uint32_t result = number;
    power < 0 ? power = module(power) : power;
    number > 0 ? number = module(number) : number;
    if (!power && !number)
        return 0; 
    if (power > 0)
    {
        for (uint8_t i = 0; i < power - 1; i++)
        {
            (result *= number);
        }
    }
    else
    {
        result /= number;
    }

    return result;
}