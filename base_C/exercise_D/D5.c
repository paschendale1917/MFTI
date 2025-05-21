//Перевести натуральное число в двоичную систему счисления. Необходимо реализовать рекурсивную функцию.

#include <stdio.h>
#include <stdint.h>

int32_t num = 0;

uint8_t print_dig(uint32_t number);
uint32_t rev(uint32_t);

int main(void)
{
    scanf("%u", &num);
    print_dig(num);
    return 0;
}

uint8_t print_dig(uint32_t number)
{
    number / 2 ? print_dig(number / 2) : number;
    printf("%u", number % 2);
}
