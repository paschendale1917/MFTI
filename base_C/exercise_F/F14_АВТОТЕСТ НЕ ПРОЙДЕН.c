// Составить функцию которая возвращает сумму элементов в заданном отрезке
// [from, to] для массива.
// Прототип функции int sum_between_ab(int from, int to, int size, int a[])

#include <stdint.h>
#include <stdio.h>

#define AMOUNT 12

int arr[AMOUNT] = {0};

int sum_between_ab(int from, int to, int size, int a[]);

// int main(void) {
//   for (int i = 0; i < AMOUNT; i++) {
//     scanf("%d", &*(arr + i));
//   }

//   printf("%d ", sum_between_ab(0, 2, AMOUNT, arr));

//   return 0;
// }

int sum_between_ab(int from, int to, int size, int a[]) {
  int result = 0;
  int cc=size;
  while (cc >=from) {
    a + cc >= a + from &&a + cc <= a + to ? result += *(a + cc) : result;
    cc--;
  }
  return result;
}