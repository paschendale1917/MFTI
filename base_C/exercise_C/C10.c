// Составить функцию, печать всех простых множителей числа. Использовать ее для печати всех простых множителей числа. void print_simple(int n).Целое положительное число.

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

uint32_t num = 0;

void print_simple(int32_t n);

int main(void)
{
    scanf("%d", &num);
    print_simple(num);
}

void print_simple(int32_t n)
{
    uint8_t simple_mult[10] = {
        0,
    };
    uint8_t cntr = 0;
    uint8_t xx = 2;
    while (n > 1)
    {

  //  next_it:
        if (!(n % xx))                  //если остаток от деления равен нулю
        {
            simple_mult[cntr] = xx;     // записываем делитель в массив
            n /= xx;
            cntr++;
        }
        else                           //иначе увеличиваем делитель на единицу и проверяем условие выше. как только оно выполнится, то записываеm значение делителя в массив.
        {
            xx++;
        //    goto next_it;
        }
    }
    for (uint8_t u = 0; u < cntr; u++)
        printf("%u ", *(simple_mult + u));
}
