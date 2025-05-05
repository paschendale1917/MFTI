// Составить программу для вычисления НОД с помощью алгоритма Евклида. Даны два натуральных числа. Найти наибольший общий делитель. 

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define SWAP

uint32_t num_a = 0;
uint32_t num_b = 0;

void swap(uint32_t *a, uint32_t *b);

int main(void)
{
    scanf("%u %u", &num_a, &num_b);
#ifdef SWAP
    swap(&num_a, &num_b);
    while (num_a && num_b)
    {
        num_a = num_a % num_b;
        if (!num_a)
            break;
        num_b = num_b % num_a;
    }
#else
    if (num_a > num_b)
    {
        while (num_a && num_b)
        {
            num_a = num_a % num_b;
            if (!num_a)
                break;
            num_b = num_b % num_a;
        }
    }
    else
    {
        while (num_b && num_a)
        {
            num_b = num_b % num_a;
            if (!num_b)
                break;
            num_a = num_a % num_b;
        }
    }
#endif
    if (num_a)
    {
        printf("%d", num_a);
    }
    else
        printf("%d", num_b);
}

void swap(uint32_t *a, uint32_t *b)
{
    uint32_t temp = 0;
    if (*a < *b)
    {
        temp = *a;
        *a = *b;
        *b = temp;
    }
}
