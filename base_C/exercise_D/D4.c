//Дано натуральное число N. Выведите все его цифры по одной, в прямом порядке, разделяя их пробелами или новыми строками. Необходимо реализовать рекурсивную функцию.
// void print_num(int num)

#include <stdio.h>
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
