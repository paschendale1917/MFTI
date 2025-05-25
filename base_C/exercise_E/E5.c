// Считать массив из 10 элементов и посчитать сумму положительных элементов
// массива.

#include <stdint.h>
#include <stdio.h>

#define AMOUNT 10

int32_t numbers[AMOUNT] = {0};

int32_t sum_positive(int32_t *num,uint8_t size);

int main(void) {
  for (uint8_t i = 0; i < AMOUNT; i++) {
    scanf("%d", &numbers[i]);
  }
  printf("%d", sum_positive(numbers,AMOUNT));
  return 0;
}

int32_t sum_positive(int32_t *num,uint8_t size) {
  uint8_t cc = 0;
  int32_t result = 0;
  while (cc < size) {
    if (!(num[cc] & 0x80000000)) {
      result += num[cc];
    }
    cc += 1;
  }
  return result;
}
