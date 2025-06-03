// Составить функцию которая находит след матрицы в двумерном массиве. Показать
// пример ее работы на матрице из 5 на 5 элементов. След матрицы - это сумма
// элементов на главной диагонали.

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

#define WIDTH 5
#define HEIGHT 5

int32_t arr[HEIGHT][WIDTH] = {0};

int32_t trace(int32_t *matrix, uint8_t height, uint8_t width);

int main(void) {

  for (uint8_t i = 0; i < HEIGHT; i++) {
    for (uint8_t j = 0; j < WIDTH; j++) {
      scanf("%d", &arr[i][j]);
    }
  }

  printf("%d", trace((int32_t *)arr, HEIGHT, WIDTH));
  return 0;
}

int32_t trace(int32_t *matrix, uint8_t height, uint8_t width) {
  if (height != width)
    return -1;
  int32_t result = 0;
  for (uint8_t h = 0; h < height; h++) {
    result += *(matrix + h + height * h);
  }
  return result;
}
