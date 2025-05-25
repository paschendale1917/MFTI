// Считать массив из 10 элементов и найти в нем максимальный и минимальный
// элементы и их номера.
#include <stdint.h>
#include <stdio.h>


#define AMOUNT 10

int32_t numbers[AMOUNT] = {
    0,
};
int64_t res_min = 0;
int64_t res_max = 0;

int32_t min(int32_t *num, uint8_t num_digs);
int32_t max(int32_t *num, uint8_t num_digs);

int main(void) {
  for (uint8_t i = 0; i < AMOUNT; i++) {
    scanf("%d", &numbers[i]);
  };
  res_min = min(numbers, AMOUNT);
  res_max = max(numbers, AMOUNT);
  printf("%d %d %d %d", (uint8_t)res_max, res_max >> 8, (uint8_t)res_min,
         res_min >> 8); // выводим номер номер максимального элемента и его
                        // значение+номер минимального элемента и его значение
  return 0;
}

int32_t min(int32_t *num, uint8_t num_digs) {
  int64_t result = 0;
  uint8_t cc = 0;
  uint8_t pos = 0;
  int32_t repetiton = 0;
  result = num[0];
  while (cc < num_digs) {
    if (result >= num[cc]) {
      result = num[cc];
      repetiton != result ? pos = cc + 1 : pos;
      repetiton = num[cc];
    }
    cc += 1;
  }
  return (result << 8) | pos;
}

int32_t max(int32_t *num, uint8_t num_digs) {
  int64_t result = 0;
  uint8_t cc = 0;
  uint8_t pos = 0;
  int32_t repetiton = 0;                                    //дополнительная переменная для отслеживания повторящихся чисел в массиве
  result = num[0];
  while (cc < num_digs) {
    if (result <= num[cc]) {
      result = num[cc];
      repetiton != result ? pos = cc + 1 : pos;
      repetiton = num[cc];
    }
    cc += 1;
  }
  return (result << 8) | pos;
}