// Составить функцию логическую функцию, которая определяет, верно ли, что в заданном числе все цифры стоят по возрастанию. Используя данную функцию решить задачу. int grow_up(int n)

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint32_t num = 0;

uint8_t grow_up(uint32_t n);

int main(void)
{
    scanf("%u", &num);
    !grow_up(num) ? printf("NO") : printf("YES");
}

uint8_t grow_up(uint32_t number)
{
    while (number)
    {
        if (number % 10 <= number / 10 % 10)
            return 0;
        number /= 10;
    }
    return 1;
}