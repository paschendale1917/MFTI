// В файле input.txt дана строка слов, разделенных пробелами. Найти самое
// длинное слово и вывести его в файл output.txt. Случай, когда самых длинных
// слов может быть несколько, не обрабатывать.

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MAX_CHAR 2000

FILE *f_in, *f_out;
char *file_in = "input.txt";
char *file_out = "output.txt";

uint16_t most_long(char *str, uint16_t stringsize, uint32_t *coord);
void sorter(uint32_t *num, uint32_t mas_size);

char string[MAX_CHAR] = "";
char string_out[MAX_CHAR] = "";
uint32_t coordinates[MAX_CHAR / 10] = {0};
uint32_t size_coord = 0;

int main(void) {
  f_in = fopen(file_in, "r");
  f_out = fopen(file_out, "w");
  fscanf(f_in, "%[^\n]s", string);
  size_coord = most_long(string, strlen(string), coordinates);
  sorter(coordinates, size_coord);
  uint16_t uc = (uint16_t)(coordinates[0]);
  while (*(string + uc) != ' ') {
    if (*(string + uc) == '\000')
        break;
    fprintf(f_out, "%c", *(string + uc));
    uc++;
  }
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

void sorter(uint32_t *num, uint32_t mas_size) {
  for (uint32_t i = 0; i < mas_size; i++) {
    int32_t temp = 0;
    for (uint32_t j = 0; j < mas_size - 1; j++) {
      if ((uint8_t)(num[j] >> 16) < (uint8_t)(num[j + 1] >> 16)) {
        temp = num[j];
        num[j] = num[j + 1];
        num[j + 1] = temp;
      }
    }
  }
}

uint16_t most_long(char *str, uint16_t stringsize, uint32_t *coord) {
  uint16_t char_cntr = 0;
  uint16_t space_cntr = 0;
  uint16_t cc = 0;
  uint16_t i = 0;
  while (i < stringsize) {
    while (*(str + char_cntr) != ' ') {
      if (*(str + char_cntr) == '\000')
        break;
      char_cntr++;
    }
    coord[cc++] = (uint32_t)((char_cntr - i) << 16) | i;
    space_cntr = find_char(str, char_cntr);
    char_cntr += space_cntr;

    i = char_cntr;
  }
  return cc;
}
