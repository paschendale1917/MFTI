// Составить функцию которая меняет в массиве минимальный и максимальный элемент местами.
//Прототип функции void change_max_min(int size, int a[])

#include <stdint.h>
#include <stdio.h>

#define AMOUNT 10

int32_t arr[AMOUNT] = {0};

void change_max_min(int size, int a[]);

int main(void) {
  for (int i = 0; i < AMOUNT; i++) {
    scanf("%d", &*(arr + i));
  }
  change_max_min(AMOUNT, arr);
  for (int i = 0; i < AMOUNT; i++) {
    printf("%d ", *(arr + i));
  }

  return 0;
}

void change_max_min(int size, int a[]) {
  int min = 0x7fffffff, max = 0x80000000;
  int min_cntr=0, max_cntr = 0;
  int temp=0;
  //находим минимальное число и пишем в min
  for (int i = 0; i < size; i++) {
    if (*(a + i) < min) {
      min = *(a + i);
      min_cntr = i;
    }
  }
   //находим максимальное число и пишем в max
  for (int j = 0; j < size; j++) {
    if (*(a + j) > max) {
      max = *(a + j);
      max_cntr=j;
    }
  }
   temp=a[min_cntr];
   a[min_cntr]=a[max_cntr];
   a[max_cntr]=temp;
}
