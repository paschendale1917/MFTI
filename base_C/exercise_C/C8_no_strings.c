// Составить функцию, которая переводит латинскую строчную букву в заглавную. И показать пример ее использования.
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <conio.h>

void translater(void);

int main(void)
{
    translater();
    return 0;
}

void translater(void)
{
    char tt;
    while ((tt = getchar()) != '.')
    {
        tt >= 0x20 && tt <= 0x60 ? putchar(tt) : putchar(tt - 'a' + 'A');
    }
}