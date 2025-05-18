// Составить функцию, которая преобразует текущий символ цифры в число. Написать программу считающую сумму цифр в тексте. int digit_to_num(char c).Строка состоящая из английских букв, пробелов, знаков препинания. В конце строки символ точка.

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

char character = 0;
uint16_t result = 0;
uint8_t digit_to_num(char c);

int main(void)
{
    do
    {
        digit_to_num(character = getchar()) ? result += digit_to_num(character) : result;
    } while (character != '.');
    printf("%u", result);
}

uint8_t digit_to_num(char c)
{
    if (c >= '0' && c <= '9') // если элемент массива соответсвует указанным границам
    {
        return c - '0';
    }
    return 0;
}
