// Ввести целое число и найти сумму его цифр.
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

uint32_t num = 0;

int main(void)
{
  scanf("%u", &num);
  uint32_t sum = 0;
  while (num)
  {
    sum += num % 10;
    num /= 10;
  }
  printf("%u", sum);

}

