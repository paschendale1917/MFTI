// Проверить строку состоящую из скобок "(" и ")" на корректность. На вход подается строка состоящая из символов '(', ')' и заканчивающаяся символом '.'. Размер строки не более 1000 символов.
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

char character = 0;
uint16_t open = 0;  // счетчик открывающих скобок
uint16_t close = 0; // счетчик закрывающих скобок
uint16_t cntr = 0;  // счетчик, позволяющий опеределить, что закрывающая скобка стоит на первом месте

int main(void)
{
    while ((character = getchar()) != '.')
    {
        cntr++;
        if (character == ')' && cntr == 1)
        {
        }
        else
        {
            character == '(' ? open++ : close++;
        }
    };
    open != close ? printf("NO") : printf("YES");
}
