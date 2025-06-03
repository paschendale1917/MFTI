// Дана целочисленная квадратная матрица 10 х 10. реализовать алгоритм
// вычисления суммы максимальных элементов из каждой строки. Напечатать значение
// этой суммы. Предполагается, что в каждой строке такой элемент единственный.
// Реализовать функцию поиска максимума в строке из 10 элементов

#include <stdint.h>
#include <stdio.h>

#define WIDTH 10
#define HEIGHT 10

int32_t arr[HEIGHT][WIDTH] = {0};

int32_t find_max(int32_t *matrix, uint8_t height, uint8_t width);

int main(void) {

  for (uint8_t i = 0; i < HEIGHT; i++) {
    for (uint8_t j = 0; j < WIDTH; j++) {
      scanf("%d", &arr[i][j]);
    }
  }

  printf("%d", find_max((int32_t *)arr, HEIGHT, WIDTH));
  return 0;
}

int32_t find_max(int32_t *matrix, uint8_t height, uint8_t width) {
  int32_t result = 0;
  for (uint8_t h = 0; h < height; h++) {
    int32_t temp = *(matrix + height * h);
    for (uint8_t w = 0; w < width; w++) {
      temp < *(matrix + height * h + w) ? temp = *(matrix + height * h + w)
                                        : temp;
    }
    result += temp;
  }
  return result;
}
