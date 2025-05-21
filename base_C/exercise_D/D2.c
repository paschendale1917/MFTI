//Составить рекурсивную функцию, которая определяет сумму всех чисел от 1 до N

#include <stdio.h>
#include <stdint.h>

int32_t num = 0;

uint32_t sum(uint32_t number);

int main(void)
{
    scanf("%u", &num);
    printf("%u ", sum(num));
    return 0;
}

uint32_t sum(uint32_t number)
{
    if (number >= 1)
    {
        return number + sum(number - 1);
    }
    else
    {
        return 0;
    }
}
