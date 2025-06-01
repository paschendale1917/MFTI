// Составить только функцию которая в массиве находит максимальный из
// отрицательных элементов и меняет его местами с последним элементом массива.
// Гарантируется, что в массиве только один такой элемент или же такой элемент
// отсутствует. Если отрицательных элементов нет - массив не менять.
// void swap_negmax_last(int size, int a[])

#include <stdint.h>
#include <stdio.h>

#define AMOUNT 10

int arr[AMOUNT] = {0};

void swap_negmax_last(int size, int a[]);

int main(void) {
  for (int i = 0; i < AMOUNT; i++) {
    scanf("%d", &*(arr + i));
  }
  swap_negmax_last(AMOUNT, arr);
  for (int i = 0; i < AMOUNT; i++) {
    printf("%d ", *(arr + i));
  }
  return 0;
}

void swap_negmax_last(int size, int a[]) {
  int result = 0;
  int temp = 0;
  int neg_cntr = 0;
  while(!(*(a+neg_cntr)&0x80000000)){        //поиск индекса первого отрицательного числа в массиве
    neg_cntr++;
    if(neg_cntr>=size)return;                //выходим из функции, если не нашли ни одного отрицательного числа
  }
 result=*(a+neg_cntr);
  for (int j = 0; j < size; j++) {
    if (*(a + j) & 0x80000000 && result < *(a + j)) {
      result = *(a + j);
      neg_cntr = j;
    }
  }
  temp = *(a + size - 1);
  *(a + size - 1) = *(a + neg_cntr);
  *(a + neg_cntr) = temp;
}