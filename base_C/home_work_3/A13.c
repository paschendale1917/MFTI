
// вывод произведения цифр любого трехзначного положительного числа

#include <stdio.h>
#include <stdint.h>

uint8_t digit[3] = {0,};
uint32_t number = 0;

uint32_t mult(uint16_t num);

int main(void)
{
    scanf("%u", &number);
    printf("%u", mult(number));
    return 0;
}

uint32_t mult(uint16_t num)
{
    uint32_t result = 0;
    if (num > 999 || num < 0)
        return 1;
    digit[0] = number % 10;
    digit[1] = number / 10 % 10;
    digit[2] = number / 100;
    result = digit[0] * digit[1] * digit[2];
    return result;
}
