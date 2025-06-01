// В последовательности записаны целые числа от M до N ( M меньше N, M больше
// или равно 1)в произвольном порядке, но одно из чисел пропущено (остальные
// встречаются ровно по одному разу). N не превосходит 1000. Последовательность
// заканчивается числом 0. Определить пропущенное число.

#include <stdint.h>
#include <stdio.h>

#define AMOUNT 1000

uint32_t arr[AMOUNT] = {0};
int counter = 1;

void sort(uint32_t *buf, uint16_t buf_size);
uint32_t search_na(uint32_t *buf);

int main(void) {
  do {
    scanf("%d", &arr[counter - 1]);
    counter++;
  } while (arr[counter - 2]);
  sort(arr, counter - 2);
  printf("%d", search_na(arr));
  return 0;
}

void sort(uint32_t *buf, uint16_t buf_size) {
  for (int i = 0; i < buf_size; i++) {
    int temp = 0;
    for (int j = 0; j < buf_size - 1; j++) {
      if ((buf[j]) > (buf[j + 1])) {
        temp = buf[j];
        buf[j] = buf[j + 1];
        buf[j + 1] = temp;
      }
    }
  }
}

uint32_t search_na(uint32_t *buf) {
  uint16_t cntr = 0;
  while (*(buf + cntr + 1)) {
    if ((*(buf + cntr + 1) - *(buf + cntr)) != 1) {
      return *(buf + cntr) + 1;
    }
    cntr++;
  }
  return 0;
}