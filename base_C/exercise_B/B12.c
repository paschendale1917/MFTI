// Организовать ввод натурального числа с клавиатуры. Программа должна определить наименьшую и наибольшую цифры, которые входят в состав данного натурального числа.

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

uint32_t num = 0;
uint8_t digits[10] = {0,};
uint16_t num_digits = 0;

uint16_t dig_parser(uint32_t number, uint8_t *buf);
void sorter(uint8_t *array);

int main(void)
{
    scanf("%u", &num);
    sorter(digits);
    printf("%d %d", digits[0], digits[num_digits-1]);
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

void sorter(uint8_t *array)
{
    uint8_t temp = 0;
    num_digits = dig_parser(num, array);
    for (uint8_t i = 0; i < num_digits - 1; i++)
    {
        for (uint8_t j = 0; j < num_digits - i - 1; j++)
        {
            if (*(array + j) > *(array + j + 1))
            {
                temp = *(array + j);
                *(array + j) = *(array + j + 1);
                *(array + j + 1) = temp;
            }
        }
    }
}