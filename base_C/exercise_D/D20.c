// Написать рекурсивную функцию возведения целого числа n в степень p.
// int recurs_power(int n, int p)
// Используя данную функцию, решить задачу.
//Два целых числа -100 ≤ n ≤ 100 и 0 ≤ p ≤ 100

#include <stdio.h>
#include <stdint.h>

int32_t n = 0;
uint32_t p = 0;

int32_t recurs_power(int32_t number, uint8_t power);

int main(void)
{
    scanf("%d%u", &n, &p);
    printf("%d", recurs_power(n, p));
    return 0;
}

int32_t recurs_power(int32_t number, uint8_t power)
{
    static int32_t result = 1;
    if (power)
    {
        result *= number;
        recurs_power(number, power - 1);
    }
    return result;
}