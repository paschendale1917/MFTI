
// Функция Аккермана определяется рекурсивно для неотрицательных целых чисел m и n следующим образом:

// Реализуйте данную функцию по прототипу
//int akkerman(int m, int n)

#include <stdio.h>
#include <stdint.h>

int32_t n = 0;
uint32_t p = 0;

int32_t akkerman(int32_t number, uint8_t power);

int main(void)
{
    scanf("%d%u", &n, &p);
    printf("%d", recurs_power(n, p));
    return 0;
}

int32_t akkerman(int32_t number, uint8_t power)
{
    static int32_t result = 1;
    if (power)
    {
        result *= number;
        recurs_power(number, power - 1);
    }
    return result;
}