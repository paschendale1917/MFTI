// Составить функцию, которая переводит число N из десятичной системы счисления в P-ичную систему счисления. Два целых числа. N ≥ 0 и 2 ≤ P ≤ 9

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

uint8_t num = 0;
uint8_t base = 0;
uint8_t digits[5] = {
    0,
};
uint8_t cntr = 0;

void transfer(uint8_t n, uint8_t p);

int main(void)
{
    scanf("%u %u", &num, &base);
    transfer(num, base);
    for (int8_t i = cntr - 1; i >= 0; i--)
    {
        printf("%u", *(digits + i));
    }
    return 0;
}

void transfer(uint8_t n, uint8_t p)
{
    uint8_t temp = 0;
    int32_t result = 0;
    while (num)
    {
        temp = num;
        num /= p;
        digits[cntr] = temp - p * num;
        cntr++;
    }
}