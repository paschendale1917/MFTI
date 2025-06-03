// Дан целочисленный массив из 30 элементов. Элементы массива могут принимать
// произвольные целые значения помещающиеся в int. Необходимо создать функцию,
// которая находит и выводит в порядке возрастания номера двух элементов
// массива, сумма которых минимальна.

#include <stdint.h>
#include <stdio.h>

#define AMOUNT 30

int32_t arr[AMOUNT] = {0};

uint16_t min_max(int32_t *buf, uint8_t size);

int main(void) {
  for (int i = 0; i < AMOUNT; i++) {
    scanf("%d", &*(arr + i));
  }
  printf("%u %u", (uint8_t)(min_max(arr, AMOUNT) >> 8),(uint8_t)min_max(arr, AMOUNT) );

  return 0;
}

uint16_t min_max(int32_t *buf, uint8_t size) {
  int32_t min1 = 0x7fffffff, min2 = 0x80000000;
  uint8_t min1_cntr=0, min2_cntr = 0;
  uint16_t result=0;
  //находим минимальное число и пишем в min1
  for (uint8_t i = 0; i < size; i++) {
    if (*(buf + i) < min1) {
      min1 = *(buf + i);
      min1_cntr = i;
    }
  }
   //находим максимальное число и пишем в min2
  for (uint8_t j = 0; j < size; j++) {
    if (*(buf + j) > min2) {
      min2 = *(buf + j);
    }
  }
//находим минимальное число, исключая min1
  for (uint8_t k = 0; k < size; k++) {
    if (*(buf + k) == min1&&k!=min1_cntr) {
      min2_cntr = k;
      return (uint16_t)min1_cntr << 8 | min2_cntr;                              //выходим из функции, если встретилось то же число, что записано в min1
    } else if (*(buf + k) > min1 && k!=min1_cntr && *(buf + k)<=min2) {         //исключаем значение min1 и индекс min1 при поиске второго минимального значения
      min2 = *(buf + k);
      min2_cntr = k;
    }
  }
   if(min1_cntr<min2_cntr){
    return (uint16_t)min1_cntr << 8 | min2_cntr;
   } else {
      return (uint16_t)min2_cntr << 8 | min1_cntr;
   }
}
