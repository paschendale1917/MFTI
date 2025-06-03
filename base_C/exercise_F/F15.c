// Составить функцию которая определяет в массиве, состоящем из положительных и
// отрицательных чисел, сколько элементов превосходят по модулю максимальный
// элемент.
// Прототип функции int count_bigger_abs(int n, int a[]);

#include <stdint.h>

#define AMOUNT 100

int arr[AMOUNT] = {0};

int abs(int num);
int count_bigger_abs(int n, int a[]);

// int main(void) {
//   for (int i = 0; i < AMOUNT; i++) {
//     scanf("%d", &*(arr + i));
//   }

//   printf("%d ", count_bigger_abs(AMOUNT, arr));

//   return 0;
// }

int abs(int num) {
  if (!num)
    return -num;
  else
    return num;
}

int count_bigger_abs(int n, int a[]) {
  int num_cntr = 0;
  int max = 0;
  // поиск максимального элемента
  for (int j = 0; j < n; j++) {
    if (*(a + j) > max) {
      max = *(a + j);
    }
  }

  for (int j = 0; j < n; j++) {
    if (*(a + j) & 0x80000000) {
      abs(*(a + j)) > max ? num_cntr++ : num_cntr;
    }
  }
  return num_cntr;
}
