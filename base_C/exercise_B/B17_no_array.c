// Ввести натурально число и напечатать все числа от 10 до введенного числа - у которых сумма цифр равна произведению цифр

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

uint32_t num = 0;

int main(void)
{
    scanf("%u", &num);
    for (uint32_t u = 10; u <= num; u++)
    {
        uint32_t sum = 0;
        uint32_t mult = 1;
        uint32_t temp = u;
        while (temp)
        {
            sum += temp % 10;
            mult *= temp % 10;
            temp /= 10;
        }
        if (sum == mult)
            printf("%u ", u);
    }
}