// Переставить цифры в числе так, что бы получилось максимальное число.

#include <math.h>
#include <stdint.h>
#include <stdio.h>


int32_t number = 0;



uint32_t max_num(int32_t num);

int main(void) {

  scanf("%d", &number);
  printf("%d ", max_num(number));

  return 0;
}

uint32_t max_num(int32_t num) {
  uint32_t result = 0;
  int32_t out[10] = {0};
  uint8_t counter = 0;
  while (num) {
    *(out + counter) = num % 10;
    num /= 10;
    counter++;
  }
  result=out[0];
  for (uint8_t i = 0; i < counter; i++) {
    if (out[i] < out[i + 1]) {
      result += out[i + 1] * pow(10, counter - 1);
      out[i + 1] = 0;
    }
  }
  return result;
}
