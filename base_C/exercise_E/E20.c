// Переставить цифры в числе так, что бы получилось максимальное число.ПОКА еще
// не решено

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
  int32_t result = 0;
  int32_t out[10] = {0};
  uint16_t counter = 0;
  while (num) {
    *(out + counter) = num % 10;
    num /= 10;
    counter++;
  }
  // bubble sorter
  for (uint8_t j = 0; j < counter; j++) {
    uint32_t temp = 0;
    for (uint8_t i = j + 1; i < counter; i++) {
      if (out[j] <= out[i]) {
        temp = out[j];
        out[j] = out[i];
        out[i] = temp;
      }
    }
  }
  for (uint8_t u = 0; u < counter; u++) {
    result += *(out + u) * pow(10, counter - u - 1);
  }
  return result;
}
