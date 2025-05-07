// Составить функцию, которая переводит латинскую строчную букву в заглавную. И показать пример ее использования.
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

char str[100] = "";

uint8_t char_counter = 0;

void translater(char *buf);

int main(void)
{

    scanf("%[^\n]", str); // множественный ввод с клавиатуры, включая пробелы
    translater(str);
}

void translater(char *buf)
{
    uint8_t tt = 0;
    while (*(str + tt) != '.')
    {
        if (*(str + tt) >= 0x20 && (*(str + tt)) <= 0x60)               // если элемент массива соответствует указанным границам
        {
            printf("%c", *(str + tt));                                  // то выводим как есть
        }
        else                                                    // иначе высчитываем разницу в положении между строчными символами в таблице ASCII и прибавляем ее к началу заглавных символов, тем самым указывая на требуемый нам символ в таблице
        {
            printf("%c", *(str + tt) - 'a' + 'A');
        }
        tt++;
    }
}