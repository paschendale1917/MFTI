// Составить функцию, модуль числа и привести пример ее использования.

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int32_t num = 0;

uint32_t module(int32_t number);

int main(void) {
  scanf("%d", &num);
  printf("%d", module(num));
  return 0;
}

uint32_t module(int32_t number) {
  return number & 0x80000000 ? -number : number;
}