// Составить логическую функцию, которая определяет, что текущий символ это цифра. Написать программу считающую количество цифр в тексте. int is_digit(char c).Текст из английских букв и знаков препинания. В конце текста символ точка.

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

char character = 0;
uint8_t dig_cntr = 0;

uint8_t is_digit(char c);

int main(void)
{
    do
    {
        is_digit(character = getchar()) ? dig_cntr++ : dig_cntr;
    } while (character != '.');
    printf("%u", dig_cntr);
}

uint8_t is_digit(char c)
{
    if (c >= '0' && c <= '9') // если элемент массива соответствует указанным границам
        return 1;
    else
        return 0;
}
