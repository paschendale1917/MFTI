// Ввести целое число и найти сумму его цифр.
// как сделать сложение с максимальными затратами ресурсов
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#define MAX_RESOURSE

uint32_t num = 0;

uint8_t digits[10] = {
    0,
};

uint16_t dig_parser(uint32_t number, uint8_t *buf);
uint16_t summ(uint32_t number, uint8_t *buf);

int main(void)
{
  scanf("%u", &num);
#ifndef MAX_RESOURSE
  uint32_t sum = 0;
  while (num)
  {
    sum += num % 10;
    num /= 10;
  }
  printf("%u", sum);
#else
  printf("%u", summ(num, digits));
#endif
}

// разделение числа на цифры и складирование в буфер
uint16_t dig_parser(uint32_t number, uint8_t *buf)
{
  uint8_t counter = 0;
  uint32_t temp = number;
  while (temp)
  {
    temp /= 10;
    counter++;
  }
  for (uint8_t i = counter; i > 0; i--)
  {
    temp = number;
    temp = temp / pow(10, i - 1);
    temp %= 10;
    buf[counter - i] = temp;
  }
  return counter;
}

uint16_t summ(uint32_t number, uint8_t *buf)
{
  uint16_t result = 0;
  uint16_t num_digits = dig_parser(number, buf);
  for (uint8_t i = 0; i < num_digits; i++)
  {
    result += *(digits + i);
  }
  return result;
}