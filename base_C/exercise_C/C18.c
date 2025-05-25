// Составить логическую функцию, которая определяет, что текущий символ это
// цифра. Написать программу считающую количество цифр в тексте. int
// is_digit(char c).Текст из английских букв и знаков препинания. В конце текста
// символ точка.

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

char str[100] = "";
uint8_t tt = 0;

uint8_t is_digit(char c);
uint16_t num_counter(char *);

int main(void) {
  scanf("%[^\n]", str); // множественный ввод с клавиатуры, включая пробелы
  printf("%u", num_counter(str));
}

uint8_t is_digit(char c) {
  if (c >= '0' &&
      c <= '9') // если элемент массива соответствует указанным границам
  {
    return 1;
  }
  return 0;
}
uint16_t num_counter(char *buf) {
  uint16_t cntr = 0;
  uint16_t num_cntr = 0; // счетчик опознанных цифр
  while (*(buf + cntr) != '.') {
    if (is_digit(*(buf + cntr))) {
      num_cntr++;
    }
    cntr++;
  }
  return num_cntr;
}
