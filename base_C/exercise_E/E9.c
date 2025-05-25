// Считать массив из 10 элементов и выполнить циклический сдвиг ВПРАВО на 1.

#include <stdint.h>
#include <stdio.h>

#define AMOUNT 10

int32_t numbers[AMOUNT] = {0};

void shifter(int32_t *num, uint8_t mas_size);

int main(void) {
  for (uint8_t i = 0; i < AMOUNT; i++) {
    scanf("%d", &numbers[i]);
  }
  shifter(numbers, AMOUNT);
  for (uint8_t i = 0; i < AMOUNT; i++) {
    printf("%d ", *(numbers + i));
  }
  return 0;
}

void shifter(int32_t *num, uint8_t mas_size) {
  int32_t temp = num[mas_size - 1];
  for (uint8_t i = 0; i < mas_size; i++) {
    num[mas_size - 1 - i] = num[mas_size - 2 - i];
  }
  num[0] = temp;
}
