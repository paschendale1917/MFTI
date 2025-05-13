// Описать функцию вычисления f(x) по формуле:
//  f(x)= x*x при -2 ≤ x < 2;
//  x*x+4x+5 при x ≥ 2;
//  4 при x < -2.
//  Используя эту функцию для n заданных чисел, вычислить f(x). Среди вычисленных значений найти наибольшее.
// Последовательность не нулевых целых чисел, в конце последовательности число 0.

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int32_t num = 0;
uint8_t temp = 0;

int32_t calc_formula(int32_t number);

int main(void)
{
    do
    {
        scanf("%d", &num);
        temp < calc_formula(num) ? temp = calc_formula(num) : temp;
    } while (num);

    printf("%d", temp);
    return 0;
}

int32_t calc_formula(int32_t number)
{
    int32_t result = 0;
    if (number >= -2 && number < 2)
    {
        result = number * number;
    }
    else if (number >= 2)
    {
        result = number * number + 4 * number + 5;
    }
    else
    {
        result = 4;
    }
    return result;
}
