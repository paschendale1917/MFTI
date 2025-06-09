// В файле input.txt символьная строка не более 1000 символов. Необходимо
// проверить, является ли она палиндромом (палиндром читается одинаково в обоих
// направлениях). Реализовать логическую функцию is_palindrom(str) и записать
// ответ в файл output.txt.

#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MAX_CHAR 1000

FILE *f_in, *f_out;
char *file_in = "input.txt";
char *file_out = "output.txt";

uint8_t is_palindrom(char *str);

char string[MAX_CHAR] = "";

int main(void) {
  f_in = fopen(file_in, "r");
  f_out = fopen(file_out, "w");
  fscanf(f_in, "%[^\n]s", string);
  is_palindrom(string)?fprintf(f_out, "%s", "NO"):fprintf(f_out, "%s", "YES");
  fclose(f_in);
  fclose(f_out);
  return 0;
}

uint8_t is_palindrom(char *str) {
  uint16_t stringsize = strlen(string);
  for (uint16_t i = 0; i < stringsize / 2; i++) {
    if (*(str + i) != *(str + stringsize - i-1))
      return 1;
  }
  return 0;
}