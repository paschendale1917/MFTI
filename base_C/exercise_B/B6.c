// Ввести целое число и определить, верно ли, что в его записи есть две одинаковые цифры, стоящие рядом.

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

uint32_t num = 0;

uint16_t dig_parser(uint32_t number, uint8_t *buf);
uint8_t searcher(uint32_t number);

int main(void)
{
    scanf("%u", &num);
    switch (searcher(num))
    {
    case 0:
        printf("NO");
        break;
    case 1:
        printf("YES");
        break;
    default:
        break;
    }
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

uint8_t searcher(uint32_t number)
{
    uint8_t digits[10] = {0, };
    uint16_t num_digits = dig_parser(number, digits);
    uint16_t result = 0;
    for (uint8_t i = 0; i < num_digits; i++)
    {
        if (!(digits[i] - digits[i + 1]))
            return 1;
    }
    return 0;
}