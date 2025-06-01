// Написать только одну функцию, которая сортирует массив по возрастанию. void sort_array(int size, int a[]). 

#include <stdint.h>
#include <stdio.h>

#define AMOUNT 20

int numbers[AMOUNT] = {0};

void sort_array(int size,int a[]);

int main(void) {
   for (uint8_t i = 0; i < AMOUNT; i++) {
    scanf("%d", &numbers[i]);
  }
  sort_array(AMOUNT,numbers);
  for (uint8_t i = 0; i < AMOUNT; i++) {
    printf("%d ", *(numbers + i));
  }

  return 0;

}

void sort_array(int size,int a[]){
 for (int i = 0; i < size; i++) {
      int temp = 0;
      for (int j = 0; j < size - 1; j++) {
        if (a[j]  > a[j + 1] ) {
          temp = a[j];
          a[j] = a[j + 1];
          a[j + 1] = temp;
        }
      }
    }
}