// Написать только одну логическую функцию, которая определяет, верно ли, что
// среди элементов массива есть два одинаковых. Если ответ «да», функция
// возвращает 1; если ответ «нет», то 0. Строго согласно прототипу:
// int is_two_same(int size, int a[]);

#include <stdint.h>
#include <stdio.h>


#define AMOUNT 101

int numbers[AMOUNT] = {0};
int counter = 0;

int is_two_same(int size, int a[]);

int main(void) {
  for (int i = 0; i < AMOUNT; i++) {
    scanf("%d", &numbers[i]);
  }
  is_two_same(AMOUNT, numbers) ? printf("YES") : printf("NO");
  return 0;
}

int is_two_same(int size, int a[]) {
  int repetition=1;
  for (int i = 0; i <size ; i++) {
    for (int j = i + 1; j <=size; j++) {
      if (a[i] == a[j] && a[i] != 0xff) {
        repetition++;
        a[j] = 0xff;
      }
      if (repetition == 2)
        return 1;
    }
  }
  return 0;
}