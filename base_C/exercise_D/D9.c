// Дано натуральное число N. Вычислите сумму его цифр. Необходимо составить рекурсивную функцию.
//int sum_digits(int n)

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int32_t num = 0;

int32_t sum(int32_t number);

int main(void)
{
    scanf("%d", &num);
    printf("%d", sum(num));
    return 0;
}

int32_t sum(int32_t number)
{
    if (number)
    {
        return number % 10 + sum(number / 10);
    }
    else
    {
        return 0;
    }
}
