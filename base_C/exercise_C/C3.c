// Написать функцию, которая возвращает среднее арифметическое двух переданных ей аргументов (параметров). int middle(int a, int b).Два целых не отрицательных числа 

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int32_t num_a = 0;
int32_t num_b = 0;;

uint32_t middle(int32_t a, int32_t b);

int main(void)
{
    scanf("%d%d", &num_a, &num_b);
    printf("%d",middle(num_a,num_b));
    return 0;
}

uint32_t middle(int32_t a, int32_t b)
{
    uint32_t result = (a+b)/2;
    return result;
}