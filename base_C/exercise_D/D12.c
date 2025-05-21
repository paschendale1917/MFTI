// Дана монотонная последовательность, в которой каждое натуральное число k встречается ровно k раз: 1, 2, 2, 3, 3, 3, 4, 4, 4, 4,…
//Выведите первые n членов этой последовательности.

#include <stdio.h>
#include <stdint.h>

uint32_t num = 0;

void output(uint32_t number);

int main(void)
{
    scanf("%u", &num);
    output(num);
    return 0;
}

void output(uint32_t number)        //вводим требуемое для вывода количество членов последовательности
{
    static uint32_t repetition = 1;
    for (uint32_t i = 1; i <= repetition; i++)
    {
        printf("%d ", repetition);
        number--;
        if (!number) return;        //выход из функции, если досчитали до нуля
           
    }
    repetition++;
    output(number);                //рекурсивный вызов функции с новым значением repetition
}
