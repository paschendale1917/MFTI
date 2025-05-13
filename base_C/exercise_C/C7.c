// Составить функцию, которая переводит число N из десятичной системы счисления в P-ичную систему счисления. Два целых числа. N ≥ 0 и 2 ≤ P ≤ 9

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

uint8_t num = 0;
uint8_t base = 0;
uint8_t cntr = 0;

int32_t transfer(uint8_t n, uint8_t p);

int main(void)
{
    scanf("%u %u", &num, &base);

    printf("%d", transfer(num, base));

    return 0;
}

int32_t transfer(uint8_t n, uint8_t p)
{
    uint8_t temp = n;
    int32_t result = 0;
    while (temp)
    {
        temp /= p;
        cntr++;
    }
    for (int8_t i = 0; i < cntr; i++)
    {
        temp = n;                        
        n /= p;                                          
        result = result + pow(10, i) * (temp - p * n);
    }
    return result;
}