// Составить функцию логическую функцию, которая определяет, верно ли, что в заданном числе все цифры стоят по возрастанию. Используя данную функцию решить задачу. int grow_up(int n)

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint32_t num = 0;

uint16_t dig_parser(uint32_t number, uint8_t *buf);
uint8_t grow_up(uint32_t n);

int main(void)
{
    scanf("%u", &num);
  !grow_up(num)?printf("NO"):printf("YES");
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

uint8_t grow_up(uint32_t number)
{
    uint8_t digits[10] = {
        0,
    };
    uint16_t num_digits = dig_parser(number, digits);
    uint8_t repetition = 0;
    for (uint8_t i = 0; i < num_digits-1; i++)
    {
        if ((digits[i] - digits[i + 1]) & 0x80000000)
            repetition++;
    }
    if (repetition != num_digits - 1)
        return 0;
    else
        return 1;
}