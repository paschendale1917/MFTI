// Считать массив из 12 элементов и выполнить инверсию для каждой трети массива.

#include <stdint.h>
#include <stdio.h>

#define AMOUNT 12
#define NUM_PARTS 3

int32_t numbers[AMOUNT] = {0};

void transposition(int32_t *num, uint8_t mas_size, uint8_t num_parts);

int main(void) {
  if (AMOUNT % 2)
    return 1;
  for (uint8_t i = 0; i < AMOUNT; i++) {
    scanf("%d", &numbers[i]);
  }
  transposition(numbers, AMOUNT, NUM_PARTS);
  for (uint8_t i = 0; i < AMOUNT; i++) {
    printf("%d ", *(numbers + i));
  }
  return 0;
}

void transposition(int32_t *num, uint8_t mas_size, uint8_t num_parts) {
  int32_t temp = 0;
  uint8_t num_elements = mas_size / num_parts;                                       // количество элементов в каждой из частей
  for (uint8_t u = 0; u < num_parts; u++) {
    uint8_t offset =u * num_elements;                                              // смещение индекса элемента массива в зависимости от количества частей, на которые разбивается  массив
    for (uint8_t i = 0; i < (num_elements / 2); i++) {
      temp = num[i + offset];
      num[i + offset] = num[num_elements - 1 - i + offset];
      num[num_elements - 1 - i + offset] = temp;
    }
  }
}
