// В диапазоне натуральных чисел от 2 до N определить, сколько из них кратны
// любому из чисел в диапазоне от 2 до 9.

#include <stdint.h>
#include <stdio.h>

int32_t number = 0;
uint32_t out[8] = {0};

void div(int32_t num, int32_t *num_out);

int main(void) {

  scanf("%d", &number);

  div(number, out);
  for (uint8_t i = 2; i < 10; i++) {
    printf("%u %u\n", i, *(out + -2 + i));
  }
  return 0;
}

void div(int32_t num, int32_t *num_out) {
  uint16_t temp = 0;
  for (uint8_t i = 2; i < 10; i++) {
    for (uint16_t j = 1; j <=num; j++) {
      num_out[i - 2] = j % i ? temp :++temp;
    }
    temp = 0;
  }
}
