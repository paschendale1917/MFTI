//Дан текст состоящий из английских букв и цифр, заканчивается символом «.» Перевести все заглавные английские буквы в строчные. 

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

char str[100] = "";
uint8_t tt = 0;

int main(void)
{
    scanf("%[^\n]", str);

    while (*(str + tt) != '.')
    {
        // if (*(str + tt) == 0x20)
        // {
        //     printf("%c", 0x20);
        // }
        // else 
        if (*(str + tt) >= 'a' && (*(str + tt)) <= 'z')
        {
            printf("%c", *(str + tt));
        }
        else
        {
            printf("%c", *(str + tt) - 'A' + 'a');
        }
        tt++;
    }
}
