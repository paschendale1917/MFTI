// Считать 10 чисел в диапазоне от -500 до 500 и разложить по двум массивам: в
// одни помещать только положительные, во второй - только отрицательные. Числа,
// равные нулю, игнорировать. Вывести на экран все элементы обоих массивов.

#include <stdint.h>
#include <stdio.h>

#define AMOUNT 10
#define ERROR 1

int32_t numbers[AMOUNT] = {0};
int32_t out_pos[AMOUNT] = {0};
int32_t out_neg[AMOUNT] = {0};
uint8_t cntr_pos, cntr_neg = 0;

void sorter(int32_t *num, int32_t *num_out_pos, int32_t *num_out_neg, uint8_t mas_size);

int main(void) {
  for (uint8_t i = 0; i < AMOUNT; i++) {
    scanf("%d", &numbers[i]);
    if (numbers[i] <= -500 || numbers[i] >= 500)
      return ERROR;
  }
  sorter(numbers, out_pos, out_neg, AMOUNT);
  for(uint8_t i=0;i<cntr_pos;i++){
    printf("%d ", *(out_pos + i));
  }
  for(uint8_t i=0;i<cntr_neg;i++){
    printf("%d ", *(out_neg + i));
  }
  return 0;
}

void sorter(int32_t *num_in, int32_t *num_out_pos, int32_t *num_out_neg, uint8_t mas_size) {
  
  for (uint8_t i = 0; i < mas_size; i++) {
    if (num_in[i] & 0x80000000 && num_in[i]) {
      out_neg[cntr_neg++] = num_in[i];
    }
    else if (!(num_in[i] & 0x80000000) && num_in[i]) {
      out_pos[cntr_pos++] = num_in[i];
    }
  }
}