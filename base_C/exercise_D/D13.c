//Составить рекурсивную функцию, печать всех простых множителей числа.

#include <stdio.h>
#include <stdint.h>

uint32_t num = 0;

void print_simple_divider(uint32_t number);

int main(void)
{
    scanf("%u", &num);
    print_simple_divider(num);
    return 0;
}

void print_simple_divider(uint32_t number)
{
    static uint32_t divider = 2;
    

        if (!(number % divider))                         // если остаток от деления равен нулю
        {
            printf("%d ", divider);                      // выводим делитель
            print_simple_divider(number /= divider);     // рекурсивно вызываем функцию с новым значением числа 
        }
        else                                             
        {
            if(number==1)return;                         //выходим из функции, если число после всех манипуляций стало равно единице
            divider++;                                   // иначе увеличиваем делитель на единицу
            print_simple_divider(number);                // и рекурсивно вызываем функцию без изменения числа 
        }
    
}
