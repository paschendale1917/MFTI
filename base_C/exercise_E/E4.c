// Считать массив из 10 элементов и найти в нем два максимальных элемента и
// напечатать их сумму.
#include <stdint.h>
#include <stdio.h>

#define AMOUNT 10

int32_t numbers[AMOUNT] = {0};

int32_t sum_max(int32_t *num, uint8_t num_digs);

int main(void) {
  for (uint8_t i = 0; i < AMOUNT; i++) {
    scanf("%d", &numbers[i]);
  }
  printf("%d", sum_max(numbers, AMOUNT));
  return 0;
}

int32_t sum_max(int32_t *num, uint8_t num_digs) {
  int32_t temp = 0;
  for (uint8_t i = 0; i < AMOUNT; i++) {
    for (uint8_t j = 0; j < AMOUNT-1; j++) {
      if (num[j] < num[j + 1]) {
        temp = num[j];
        num[j] = num[j + 1];
        num[j + 1] = temp;
      }
    }
  }
  return num[0] + num[1];
}