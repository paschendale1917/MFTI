// Составить логическую функцию, которая определяет, верно ли, что в заданном
// числе сумма цифр равна произведению. int is_happy_number(int n).Целое не
// отрицательное число

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

uint32_t num = 0;

uint16_t dig_parser(uint32_t number, uint8_t *buf);
uint16_t summ(uint32_t number);
uint16_t mult(uint32_t number);
uint8_t is_happy_number(uint32_t n);

int main(void) {
  scanf("%u", &num);
  is_happy_number(num) ? printf("YES") : printf("NO");
}

uint16_t dig_parser(uint32_t number, uint8_t *buf) {
  uint8_t counter = 0;
  uint32_t temp = number;
  if (!(temp | 0x00000000))
    counter = 1;
  else {
    while (temp) {
      temp /= 10;
      counter++;
    }
  }
  temp = number;
  for (int8_t i = counter - 1; i >= 0; i--) {
    buf[i] = temp % 10;
    temp /= 10;
  }
  return counter;
}

uint16_t summ(uint32_t number) {
  uint16_t result = 0;
  uint8_t digits[10] = {
      0,
  };
  uint16_t num_digits = dig_parser(number, digits);
  for (uint8_t i = 0; i < num_digits; i++) {
    result += *(digits + i);
  }
  return result;
}

uint16_t mult(uint32_t number) {
  uint16_t result = 0;
  uint8_t digits[10] = {
      0,
  };
  uint16_t num_digits = dig_parser(number, digits);
  result = digits[0];
  for (uint8_t i = 1; i < num_digits; i++) {
    result *= *(digits + i);
  }
  return result;
}

uint8_t is_happy_number(uint32_t n) {
  if (summ(n) == mult(n))
    return 1;
  return 0;
}