// Считать массив из 10 элементов и отсортировать первую половину по
// возрастанию, а вторую – по убыванию.

#include <stdint.h>
#include <stdio.h>

#define AMOUNT 10
#define NUM_PARTS 2

enum { up = 0, down };

int32_t numbers[AMOUNT] = {0};

void sorter(int32_t *num, uint8_t mas_size, uint8_t direction);

int main(void) {
  for (uint8_t i = 0; i < AMOUNT; i++) {
    scanf("%d", &numbers[i]);
  }
  sorter(numbers,AMOUNT/2,up);
  sorter(&numbers[AMOUNT/2],AMOUNT/2,down); 
  for (uint8_t i = 0; i < AMOUNT; i++) {
    printf("%d ", *(numbers + i));
  }

  return 0;
}



void sorter(int32_t *num, uint8_t mas_size, uint8_t direction) {
  switch (direction) {
  case up:
    for (uint8_t i = 0; i < mas_size; i++) {
      int32_t temp = 0;
      for (uint8_t j = 0; j < mas_size - 1; j++) {
        if (num[j]  > num[j + 1] ) {
          temp = num[j];
          num[j] = num[j + 1];
          num[j + 1] = temp;
        }
      }
    }
    break;
  case down:
    for (uint8_t i = 0; i < mas_size; i++) {
      int32_t temp = 0;
      for (uint8_t j = 0; j < mas_size - 1; j++) {
        if (num[j]  < num[j + 1] ) {
          temp = num[j];
          num[j] = num[j + 1];
          num[j + 1] = temp;
        }
      }
    }
    break;
  }
}
