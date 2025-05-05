// Посчитать количество четных и нечетных цифр числа.

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

uint32_t num = 0;
uint8_t repetition_even = 0; // переменная для подсчета четных цифр
uint8_t repetition_odd = 0;  // переменная для подсчета нечетных цифр

uint16_t dig_parser(uint32_t number, uint8_t *buf);
void searcher(uint32_t number);

int main(void)
{
    scanf("%u", &num);
    searcher(num);
    printf("%u %u", repetition_even, repetition_odd);
}

uint16_t dig_parser(uint32_t number, uint8_t *buf)
{
    uint8_t counter = 0;
    uint32_t temp = number;
    while (temp)
    {
        temp /= 10;
        counter++;
    }
    temp = number;
    for (int8_t i = counter-1; i>=0; i--)
    {
      buf[i]  = temp%10;
        temp/=10;
    }
    return counter;
}

void searcher(uint32_t number)
{
    uint8_t digits[10] = {0,};
    uint16_t num_digits = dig_parser(number, digits);
    for (uint8_t i = 0; i < num_digits; i++)
    {
        if (!(digits[i] % 2))
            repetition_even++;
        else
            repetition_odd++;
    }
}