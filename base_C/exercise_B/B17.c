// Ввести натурально число и напечатать все числа от 10 до введенного числа - у которых сумма цифр равна произведению цифр

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

uint32_t num = 0;

uint8_t digits[10] = {0,};

uint16_t dig_parser(uint32_t number, uint8_t *buf);
uint16_t summ(uint32_t number);
uint16_t mult(uint32_t number);

int main(void)
{
    scanf("%u", &num);
    for (uint32_t i = 10; i <= num; i++)
    {
        if (summ(i) == mult(i))
        {
            printf("%d ", i);
        }
    }
}

uint16_t dig_parser(uint32_t number, uint8_t *buf)
{
    uint8_t counter = 0;
    uint32_t temp = number;
    if (!(temp | 0x00000000))
        counter = 1;
    else
    {
        while (temp)
        {
            temp /= 10;
            counter++;
        }
    }
    temp = number;
    for (int8_t i = counter-1; i>=0; i--)
    {
      buf[i]  = temp%10;
        temp/=10;
    }
    return counter;
}

uint16_t summ(uint32_t number)
{
    uint16_t result = 0;
    uint16_t num_digits = dig_parser(number, digits);
    for (uint8_t i = 0; i < num_digits; i++)
    {
        result += *(digits + i);
    }
    return result;
}

uint16_t mult(uint32_t number)
{
    uint16_t result = 0;
    uint16_t num_digits = dig_parser(number, digits);
    result = digits[0];
    for (uint8_t i = 1; i < num_digits; i++)
    {
        result *= *(digits + i);
    }
    return result;
}