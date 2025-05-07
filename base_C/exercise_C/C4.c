// Описать функцию вычисления f(x) по формуле:
//  f(x)= x*x при -2 ≤ x < 2;
//  x*x+4x+5 при x ≥ 2;
//  4 при x < -2.
//  Используя эту функцию для n заданных чисел, вычислить f(x). Среди вычисленных значений найти наибольшее.
// Последовательность не нулевых целых чисел, в конце последовательности число 0. 

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int32_t num_a = 0;
int32_t num_b = 0;
int32_t numbers_in[25] = {0,};
int32_t numbers_out[25] = {0,};
uint8_t cnt = 0;

void calc_formula(int32_t *buf_in, int32_t *buf_out);
int32_t sorter(int32_t *buf, uint8_t num_units);

int main(void)
{
    do
    {
        scanf("%d", &numbers_in[cnt]);
        cnt++;                               //счетчик введенных цифр
    } while (numbers_in[cnt - 1] != 0x00);
    calc_formula(numbers_in, numbers_out);
    printf("%d", sorter(numbers_out, cnt)); // выводим нулевой элемент массива с результатами вычислений
    return 0;
}

void calc_formula(int32_t *buf_in, int32_t *buf_out)
{
    for (uint8_t k = 0; k < cnt; k++)
    {
        int32_t result = 0;
        if (buf_in[k] >= -2 && buf_in[k] < 2)
        {
            result = buf_in[k] * buf_in[k];
        }
        else if (buf_in[k] >= 2)
        {
            result = buf_in[k] * buf_in[k] + 4 * buf_in[k] + 5;
        }
        else
        {
            result = 4;
        }
        *(buf_out + k) = result;
    }
}

int32_t sorter(int32_t *buf, uint8_t num_units) // сортировка чисел бОльшим числом в начало массива
{
    for (uint8_t i = 0; i < num_units - 1; i++)
    {
        for (uint8_t j = 0; j < num_units - 1; j++)
        {
            uint8_t temp = 0;
            if ((buf[j] - buf[j + 1]) & 0x80000000)
            {
                temp = buf[j];
                buf[j] = buf[j + 1];
                buf[j + 1] = temp;
            }
        }
    }
    return *buf;
}
