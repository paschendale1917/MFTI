// В файле input.txt дана символьная строка не более 1000 символов. Необходимо
// заменить все буквы "а" на буквы "b" и наоборот, как заглавные, так и
// строчные. Результат записать в output.txt.

#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MAX_CHAR 1000

FILE *f_in, *f_out;
char *file_in = "input.txt";
char *file_out = "output.txt";

char string[MAX_CHAR] = "";

int main(void) {
  f_in = fopen(file_in, "r");
  f_out = fopen(file_out, "w");
  fscanf(f_in, "%[^\n]s", string);
  for (uint16_t i = 0; i < strlen(string); i++) {
    switch (*(string + i)) {
    case 'A':
      *(string + i) = 'B';
      break;
    case 'B':
      *(string + i) = 'A';
      break;
    case 'a':
      *(string + i) = 'b';
      break;
    case 'b':
      *(string + i) = 'a';
      break;
    }
  }
  fprintf(f_out, "%s", string);
  fclose(f_in);
  fclose(f_out);
  return 0;
}
