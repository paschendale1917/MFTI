// Дана строка заканчивающаяся символом точка '.' Напечатать строку наоборот. Реализуйте рекурсивную функцию, которая считывает и печатает строку наоборот.
//void reverse_string()


#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int32_t num = 0;

void print_num(uint32_t number);

int main(void)
{
    scanf("%u", &num);
    print_num(num);
    return 0;
}


void print_num(uint32_t number)
{

    if (number / 10)
        print_num(number / 10);
    printf("%u ", number % 10);
}
