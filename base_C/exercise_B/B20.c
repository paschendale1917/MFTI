// Проверить число на простоту.

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

uint32_t num = 0;

uint8_t searcher(uint32_t number);

int main(void)
{
    scanf("%u", &num);
    switch (searcher(num))
    {
    case 2:
        printf("YES");
        break;

    default:
        printf("NO");
        break;
    }
}

uint8_t searcher(uint32_t number)
{
    uint8_t simplicity = 0; // переменная для подсчета количества делителей
    for (uint16_t i = 1; i <= num; i++)
    {
        if (!(num % i))
            simplicity++;
    }
    return simplicity;
}