// Проверить строку состоящую из скобок "(" и ")" на корректность. На вход подается строка состоящая из символов '(', ')' и заканчивающаяся символом '.'. Размер строки не более 1000 символов. 
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

char str[100] = "";

uint8_t resolver(char *);

int main(void)
{
    scanf("%[^\n]", str); // множественный ввод с клавиатуры, включая пробелы
    resolver(str)?printf("YES"):printf("NO");
}


uint8_t resolver(char *buf)
{
    uint16_t cntr = 0;
    uint16_t open = 0;   //счетчик открывающих скобок
    uint16_t close = 0;   //счетчик закрывающих скобок
    while (*(buf + cntr) != '.') 
    {
       *(buf + cntr)=='('&&*buf!=')'?open++:close++;
       cntr++;
    }
    return open==close?1:0;
}
