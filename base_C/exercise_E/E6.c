// Считать массив из 12 элементов и посчитать среднее арифметическое элементов
// массива.

#include <stdint.h>
#include <stdio.h>

#define AMOUNT 12

int32_t numbers[AMOUNT] = {0};

float mean(int32_t *num, uint8_t size);

int main(void) {
  for (uint8_t i = 0; i < AMOUNT; i++) {
    scanf("%d", &numbers[i]);
  }
  printf("%.2f", mean(numbers, AMOUNT));
  return 0;
}

float mean(int32_t *num, uint8_t size) {
  uint8_t cc = 0;
  int32_t result = 0;
  while (cc < size) {
    result += num[cc];
    cc += 1;
  }
  return (float)result/AMOUNT;
}
