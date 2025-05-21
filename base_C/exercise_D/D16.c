// Написать логическую рекурсивную функцию и используя ее определить является ли введенное натуральное число точной степенью двойки.
//int is2pow(int n)

#include <stdio.h>
#include <stdint.h>

uint32_t num = 0;

uint8_t is2pow(uint32_t number);

int main(void)
{
    scanf("%u", &num);
    is2pow(num) ? printf("YES") : printf("NO");
    return 0;
}

uint8_t is2pow(uint32_t number)
{
    static uint32_t temp = 1;
    static uint32_t pow= 0;
    if (number == (temp <<pow))            // cдвигаем temp на pow битов влево(0b00000001<<0=0b00000001 в первой итерации.каждый сдвиг равносилен уиножению на 2). и сравниваем полученное значение с введенным числом
    { 
        return 1;
    }
    else if (number < temp <<pow|| !number)     //на некоторой итерации temp<<pow либо сравняется с введенным числом(если четное), либо станет больше чем оно(нечетное)
    {
        return 0;
    }
    pow++;
     is2pow(number);
}