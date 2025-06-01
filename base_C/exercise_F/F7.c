// Написать функцию, которая сжимает серии массива, состоящего из единиц и нулей
// по следующему принципу: например, массив [0,0,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1]
// преобразуется в [4,7,2,4] (т.к. начинается с нуля, то сразу записывается
// количество элементов первой серии); а массив [1,1,1,0,0,0,0,0,0,0]
// преобразуется в [0,3,7] (т.к. первая серия - это единицы, то первый элемент
// преобразованного массива 0).
// int compression(int a[], int b[], int N)

#include <stdint.h>
#include <stdio.h>

#define AMOUNT 100

int unpacked[AMOUNT], packed[AMOUNT] = {0};
int packed_cntr = 0;

int compression(int a[], int b[], int N);

int main(void) {
  for (int i = 0; i < AMOUNT; i++) {
    scanf("%d", &unpacked[i]);
  }
  compression(unpacked, packed, AMOUNT);

  for (uint8_t i = 0; i < packed_cntr; i++) {
    printf("%d ", *(packed + i));
  }

  return 0;
}


int compression(int a[], int b[], int N) {
  int cntr = N;
  int repetition = 1;
  switch (a[0]) {
  case 0:
    do {
      if (a[N - cntr] == a[N - cntr + 1] && (cntr - 1)) {
        repetition++;
        cntr--;
      } else {
        b[packed_cntr] = repetition;
        repetition = 1;
        packed_cntr++;
        cntr--;
      }
    } while (cntr);
    break;
  case 1:
    b[0] = 0;
    packed_cntr = 1;
    do {
      if (a[N - cntr] == a[N - cntr + 1] && (cntr - 1)) {
        repetition++;
        cntr--;
      } else {
        b[packed_cntr] = repetition;
        repetition = 1;
        packed_cntr++;
        cntr--;
      }
    } while (cntr);
    break;
  }
  return packed_cntr;
}