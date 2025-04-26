// Составить функцию, которая определяет сумму всех чисел от 1 до N и привести пример ее использования. 

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int32_t num_a = 0;
int32_t num_b = 0;
int32_t numbers_in[25] = {0,};
int32_t numbers_out[25] = {0,};
uint8_t cnt = 0;

void calc_formula(int32_t *buf_in, int32_t *buf_out);
void comparator(int32_t *buf, uint8_t num_units);

int main(void)
{
    do
    {
        scanf("%d", &numbers_in[cnt]);
        cnt++;
    } while (numbers_in[cnt - 1] != 0x00);
    calc_formula(numbers_in, numbers_out);
    comparator(numbers_out, cnt);
    printf("%d", *numbers_out); // выводим нулевой элемент массива с результатами вычислений
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

void comparator(int32_t *buf, uint8_t num_units) // сортировка чисел бОльшим числом в начало массива
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
}
