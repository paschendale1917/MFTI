// Дана строка из английских символов, пробелов и знаков препинания. В конце строки символ точка. Необходимо реализовать рекурсивную функцию, которая считывает данную строку со стандартного потока ввода и возвращает целое число - количество символов 'a' в данной строке.
// int acounter(void)
//Используя данную функцию решить задачу.

#include <stdio.h>
#include <stdint.h>

uint8_t acounter(void);

int main(void)
{
    printf("%u", acounter());
    return 0;
}

uint8_t acounter(void)
{
    char character = 0;
    static uint8_t counter = 0;

    if ((character = getchar()) != '.')
    {
        character == 'a' ? counter++ : counter;
        acounter();
    }
    return counter;
}