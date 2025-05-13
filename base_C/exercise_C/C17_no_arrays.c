// Составить логическую функцию, которая определяет, верно ли, что в заданном числе сумма цифр равна произведению. int is_happy_number(int n).Целое не отрицательное число

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

uint32_t num = 0;
uint8_t is_happy_number(uint32_t n);

int main(void)
{
    scanf("%u", &num);
    is_happy_number(num) ? printf("YES") : printf("NO");
}

uint8_t is_happy_number(uint32_t n)
{
    uint32_t sum = 0;
    uint32_t mult = 1;
    while (n)
    {
        sum = sum + n % 10;
        mult = mult * (n % 10);
        n /= 10;
    }
    {
        if (sum != mult)
            return 0;
        else
            return 1;
    }

}