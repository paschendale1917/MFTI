// вывод суммы цифр любого трехзначного числа

#include <stdio.h>
#include <stdint.h>

uint32_t number = 0;
uint8_t digit[3] = {0,};

uint16_t sum(uint32_t num);

int main(void)
{
    scanf("%u", &number);
    printf("%u", sum(number));
    return 0;
}

uint16_t sum(uint32_t num)
{
    uint16_t result = 0;
    if (number > 999 || number < 0)
        return 1;
    digit[0] = number % 10;
    digit[1] = number / 10 % 10;
    digit[2] = number / 100;
    result = digit[0] + digit[1] + digit[2];
    return result;
}
