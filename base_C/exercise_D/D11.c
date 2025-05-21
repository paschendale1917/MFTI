//Дано натуральное число N. Посчитать количество «1» в двоичной записи числа.

#include <stdio.h>
#include <stdint.h>

uint32_t num = 0;

uint8_t true_counter(uint32_t number);

int main(void)
{
    scanf("%u", &num);
    printf("%u", true_counter(num));
    return 0;
}

uint8_t true_counter(uint32_t number)
{
    static uint8_t cntr = 0;

        if (number&0x01)
        {
            cntr++;
           return true_counter(number>>1); 
        }
        else
        {
            if(!number)return cntr;
            true_counter(number>>1);
           
        };
}

/* uint8_t true_counter(uint32_t number)
{
    static uint8_t cntr = 0;
    while (number)
    {
        if (number % 2)
        {
            cntr++;
            return true_counter(number / 2);
        }
        else
        {
            return true_counter(number / 2);
        };
    }
    return cntr;
} */
