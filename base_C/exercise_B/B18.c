// Вывести на экран ряд чисел Фибоначчи, состоящий из n элементов.
//Числа Фибоначчи – это элементы числовой последовательности 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144, …, в которой каждое последующее число равно сумме двух предыдущих. 

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

int32_t num = 0;
uint32_t prev = 0;
uint32_t next = 1;
uint32_t result = 0;
uint32_t counter = 0;

int main(void)
{
    scanf("%u", &num);

    while (counter < num)
    {
        printf("%d ", next);
        result = prev + next;
        prev = next;
        next = result;
        counter++;
    }
}
