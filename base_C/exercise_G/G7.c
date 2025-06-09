// В файле input.txt считать символьную строку, не более 10 000 символов.
// Посчитать количество строчных (маленьких) и прописных (больших) букв в
// введенной строке. Учитывать только английские буквы. Результат записать в
// файл output.txt.

#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MAX_CHAR 10000

FILE *f_in, *f_out;
char *file_in = "input.txt";
char *file_out = "output.txt";

uint32_t counter(char *str);

char string[MAX_CHAR] = "";

int main(void) {
  f_in = fopen(file_in, "r");
  f_out = fopen(file_out, "w");
  fscanf(f_in, "%[^\n]s", string);
  fprintf(f_out, "%u %u", counter(string) >> 16, (uint16_t)counter(string));
  fclose(f_in);
  fclose(f_out);
  return 0;
}

uint32_t counter(char *str) {
  uint16_t big = 0, small = 0;
  uint16_t stringsize = strlen(string);
  for (uint16_t i = 0; i < stringsize; i++) {
    if (*(str + i) != ' ') {
      *(str + i) > 0x40 && *(str + i)<0x5B ? big++ : big;
      *(str + i) > 0x60 && *(str + i)<0x7B ? small++ : small;
    }
  }
  return (uint16_t)small << 16 | big;
}