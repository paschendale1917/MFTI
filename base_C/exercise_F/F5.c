// Написать только одну функцию, которая находит максимальный элемент в массиве.
// Всю программу загружать не надо.
// Прототип функции: int find_max_array(int size, int a[])

#include <stdint.h>
#include <stdio.h>

#define AMOUNT 150

int numbers[AMOUNT] = {0};


int find_max_array(int size, int a[]);

int main(void) {

  for (int i = 0; i < AMOUNT; i++) {
    scanf("%d", &numbers[i]);
  }

  printf("%d", find_max_array(AMOUNT, numbers));

  return 0;
}

int find_max_array(int size, int a[]) {
  int result = a[0];
  for (int i = 0; i < size; i++) {
    if (result < a[i]) {
      result = a[i];
    }
  }
  return result;
}