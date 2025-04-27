//Составить функцию логическую функцию, которая определяет, верно ли, что сумма его цифр – четное число. Используя эту функцию решить задачу. 

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

uint32_t num = 0;

uint16_t dig_parser(uint32_t number, uint8_t *buf);
uint8_t sum_is_even(uint32_t number);

int main(void)
{
    scanf("%u", &num);
    sum_is_even(num)?printf("NO"):printf("YES");
 
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
    for (uint8_t i = counter; i > 0; i--)
    {
        temp = number;
        temp = temp / pow(10, i - 1);
        temp %= 10;
        buf[counter - i] = temp;
    }
 }
    return counter;
}

uint8_t sum_is_even(uint32_t number)
{
    uint8_t digits[10] = {0,};
    uint16_t num_digits = dig_parser(number, digits);
    uint8_t sum = 0;
    for (uint8_t i = 0; i < num_digits; i++)
    {
       sum+=*(digits+i);
    }
    if (sum%2)
        return 1;
    else
        return 0;
}