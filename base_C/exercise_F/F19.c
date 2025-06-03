// Определить количество положительных элементов квадратной матрицы, превышающих
// по величине среднее арифметическое всех элементов главной диагонали.
// Реализовать функцию среднее арифметическое главной диагонали.

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

#define WIDTH 5
#define HEIGHT 5

int32_t arr[HEIGHT][WIDTH] = {0};

int32_t mean(int32_t *matrix, uint8_t height, uint8_t width);
uint8_t counter(int32_t *matrix, uint8_t height, uint8_t width);

int main(void) {

  for (uint8_t i = 0; i < HEIGHT; i++) {
    for (uint8_t j = 0; j < WIDTH; j++) {
      scanf("%d", &arr[i][j]);
    }
  }

  printf("%d", counter((int32_t *)arr, HEIGHT, WIDTH));
  return 0;
}

int32_t mean(int32_t *matrix, uint8_t height, uint8_t width) {
  if (height != width)
    return -1;
  int32_t result = 0;
  for (uint8_t h = 0; h < height; h++) {
    result += *(matrix + h + height * h);
  }
  return result / height;
}

uint8_t counter(int32_t *matrix, uint8_t height, uint8_t width) {
  int32_t arith_mean = mean(matrix, height, width);
  uint8_t num_cntr = 0;
  for (uint8_t size = 0; size < height * width; size++) {
    if (!(*(matrix + size) & 0x80000000)) {
      arith_mean < *(matrix + size) ? num_cntr++ : num_cntr;
    }
  }
  return num_cntr;
}
