//Дано целое не отрицательное число N. Выведите все его цифры по одной, в обратном порядке, разделяя их пробелами или новыми строками.

#include <stdio.h>
#include <stdint.h>

int32_t num = 0;

uint8_t print_dig(uint32_t number);

int main(void)
{
    scanf("%u", &num);
    print_dig(num);
    return 0;
}

uint8_t print_dig(uint32_t number)
{
    printf("%u ", number % 10);
    if (number/10)
        print_dig(number / 10);
   
}
