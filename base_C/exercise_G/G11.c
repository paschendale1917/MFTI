// В файле input.txt дано предложение. Необходимо определить, сколько слов
// заканчиваются на букву 'а'. Ответ записать в файл output.txt.

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MAX_CHAR 2000

FILE *f_in, *f_out;
char *file_in = "input.txt";
char *file_out = "output.txt";

uint16_t find_a(char *str, uint16_t stringsize);

char string[MAX_CHAR] = "";

int main(void) {
  f_in = fopen(file_in, "r");
  f_out = fopen(file_out, "w");
  fscanf(f_in, "%[^\n]s", string);
  fprintf(f_out, "%u", find_a(string, strlen(string)));
  fclose(f_in);
  fclose(f_out);
  return 0;
}

uint16_t find_char(char *str, uint16_t cntr) {
  uint16_t space_counter = 0;
  while (*(str + cntr + space_counter) == ' ') {
    space_counter++;
  }
  return space_counter;
}

uint16_t find_a(char *str, uint16_t stringsize) {
  uint16_t char_cntr = 0;
  uint16_t space_cntr = 0;
  uint8_t char_a = 0;
  uint16_t i = 0;
  while (i < stringsize) {
    while (*(str + char_cntr) != ' ') {
      if (*(str + char_cntr) == '\000')
        break;
      char_cntr++;
    }
    (*(str + char_cntr-1)) == 'a' ? char_a++ : char_a;
    space_cntr = find_char(str, char_cntr);
    char_cntr += space_cntr;

    i = char_cntr;
  }
  return char_a;
}
