//Составить рекурсивную функцию, печать всех чисел от N до 1.

#include <stdio.h>
#include <stdint.h>

int32_t num = 0;

void num_print(uint32_t number);

int main(void)
{
    scanf("%u", &num);
    num_print(num);
    return 0;
}

void num_print(uint32_t number)
{
    printf("%u ", number);
    number > 1 ? num_print(number - 1) : number;
}