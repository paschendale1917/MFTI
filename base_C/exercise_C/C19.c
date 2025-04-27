//Составить функцию, которая преобразует текущий символ цифры в число. Написать программу считающую сумму цифр в тексте. int digit_to_num(char c).Строка состоящая из английских букв, пробелов, знаков препинания. В конце строки символ точка. 

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

char str[100] = "";
uint8_t tt = 0;

uint8_t digit_to_num(char c);
uint16_t sum(char *);

int main(void)
{
    scanf("%[^\n]", str); // множественный ввод с клавиатуры, включая пробелы
    printf("%u", sum(str));
}

uint8_t digit_to_num(char c)
{
    if (c >= '0' && c <= '9') // если элемент массива соответсвует указанным границам(мелкий шрифт)
    {
       return c-'0';
    }
   return 0;
}
uint16_t sum(char *buf)
{
    uint16_t cntr = 0;
    uint16_t sum = 0;
    while (*(buf + cntr) != '.')
    {
        sum+=digit_to_num(*(buf + cntr));
        cntr++;
    }
    return sum;
}
