// В файле input.txt строка из меленьких и больших английских букв, знаков
// препинания и пробелов. Требуется удалить из нее повторяющиеся символы и все
// пробелы. Результат записать в файл output.txt.

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MAX_CHAR 1000

FILE *f_in, *f_out;
char *file_in = "input.txt";
char *file_out = "output.txt";

void replace(char *str, uint16_t stringsize);

char string[MAX_CHAR] = "";

int main(void) {
  f_in = fopen(file_in, "r");
  f_out = fopen(file_out, "w");
  fscanf(f_in, "%[^\n]s", string);
  replace(string, strlen(string));
  fclose(f_in);
  fclose(f_out);
  return 0;
}

void replace(char *str, uint16_t stringsize) {
  for (uint16_t i = 0; i < stringsize; i++) {
    for (uint16_t j = i+1; j < stringsize; j++) {
      if (*(str + i) == *(str + j) || *(str + j) == ' ') {
        *(str + j) = 0x7f;
      }
    }
  }
  for (uint16_t i = 0; i < stringsize; i++) {
    *(str + i) != 0x7f&& *(str + i) !=' '?fprintf(f_out,"%c",*(string+i)):i;
  }
}
