// Считать массив из 10 элементов и отсортировать его по последней цифре.

#include <stdint.h>
#include <stdio.h>

#define AMOUNT 10

int32_t numbers[AMOUNT] = {0};

void sorter(int32_t *num, uint8_t mas_size);

int main(void) {
  for (uint8_t i = 0; i < AMOUNT; i++) {
    scanf("%d", &numbers[i]);
  }
  sorter(numbers, AMOUNT);
  for (uint8_t i = 0; i < AMOUNT; i++) {
    printf("%d ", *(numbers + i));
  }
  return 0;
}

void sorter(int32_t *num, uint8_t mas_size) {
  for (uint8_t i = 0; i < mas_size; i++) {
    int32_t temp = 0;
    for (uint8_t j = 0; j < mas_size - 1; j++) {
      if (num[j] % 10 > num[j + 1] % 10) {
        temp = num[j];
        num[j] = num[j + 1];
        num[j + 1] = temp;
      }
    }
  }
}
