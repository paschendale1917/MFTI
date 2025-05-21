// Дана строка заканчивающаяся символом точка '.' Напечатать строку наоборот. Реализуйте рекурсивную функцию, которая считывает и печатает строку наоборот.
// void reverse_string()


#include <stdio.h>
#include <stdint.h>

void reverse_string(void);

int main(void)
{
reverse_string();
    return 0;
}


void reverse_string(void){
    char character=0;
   if((character=getchar())!='.'){
      reverse_string();
    }
   if(character!='.')putchar(character);
}
