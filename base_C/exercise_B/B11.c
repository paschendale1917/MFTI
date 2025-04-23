// Ввести целое число и «перевернуть» его, так чтобы первая цифра стала последней и т.д.

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

uint32_t num = 0;

uint32_t turner(uint32_t number);

int main(void)
{
  scanf("%u", &num);
  printf("%u", turner(num));
}

uint32_t turner(uint32_t number)
{
  uint8_t counter = 0;
  uint32_t temp = number;
  uint32_t turned_number = 0;

  while (temp)
  {
    temp /= 10;
    counter++;
  }
  for (uint8_t i = counter; i > 0; i--)
  {
    temp = number;
    temp = temp / pow(10, counter - i);
    temp %= 10;
    turned_number += temp * pow(10, i - 1);
  }

  return turned_number;
}
