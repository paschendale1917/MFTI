// Вывести в порядке следования цифры, входящие в десятичную запись натурального
// числа N.

#include <stdint.h>
#include <stdio.h>

int32_t number = 0;
int32_t out[10] = {0};
uint8_t counter = 0;

void grow_up(int32_t num, int32_t *num_out);

int main(void) {

  scanf("%d", &number);

  grow_up(number, out);
  for (int8_t i = counter - 1; i >= 0; i--) {
    printf("%d ", *(out + i));
  }
  return 0;
}

void grow_up(int32_t num, int32_t *num_out) {
  while (num) {
    *(num_out + counter) = num % 10;
    num /= 10;
    counter++;
  }
}
