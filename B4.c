// Ввести целое число и определить, верно ли, что в нём ровно 3 цифры.

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint32_t num = 0;
uint8_t counter = 0;

int main(void)
{
  scanf("%u", &num);
  while (num)
  {
    num /= 10;
    counter++;
  }
  if (counter != 3)
    printf("NO");
  else
    printf("YES");
}
