// Ввести натуральное число и определить, верно ли, что сумма его цифр равна 10.

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

uint32_t num = 0;
uint32_t sum = 0;

int main(void)
{
    scanf("%u", &num);

    while (num)
    {
        sum += num % 10;
        num /= 10;
    }
    sum == 10 ? printf("YES") : printf("NO");
}