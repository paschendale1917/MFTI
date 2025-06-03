// Составить функцию которая возвращает количество элементов на заданном отрезке
// [from, to] для массива.
// Прототип функции int count_between(int from, int to, int size, int a[])
//ЧТО НУЖНО АВТОТЕСТУ Я НЕ ПОНИМАЮ
//В VSCODE ВСЕ ПРЕКРАСНО РАБОТАЕТ

#include <stdint.h>
#include <stdio.h>

#define AMOUNT 12

int arr[AMOUNT] = {0};

int count_between(int from, int to, int size, int a[]);

int main(void) {
  for (int i = 0; i < AMOUNT; i++) {
    scanf("%d", &*(arr + i));
  }

  printf("%d ", count_between(0, 2, AMOUNT, arr));

  return 0;
}

int count_between(int from, int to, int size, int a[]) {
  int counter = 0;
  int cc=size;
  while (cc>=from) {
    a + cc >= a + from &&a + cc <= a + to ? counter++ : counter;
    cc--;
  }
  return counter;
}