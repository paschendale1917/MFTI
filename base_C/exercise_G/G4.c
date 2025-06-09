// В файле input.txt даны два слова не более 100 символов каждое, разделенные
// одним пробелом. Найдите только те символы слов, которые встречаются в обоих
// словах только один раз. Напечатайте их через пробел в файл output.txt в
// лексикографическом порядке.

#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MAX_CHAR 200

FILE *f_in, *f_out;
char *file_in = "input.txt";
char *file_out = "output.txt";

char string[MAX_CHAR * 2] = "";
char first[MAX_CHAR] = "";
char second[MAX_CHAR] = "";

uint16_t first_c[MAX_CHAR] = {0};
uint16_t second_c[MAX_CHAR] = {0};

uint8_t size_first_c = 0;
uint8_t size_second_c = 0;
uint8_t max_size = 0;

uint16_t counter = 0;
uint16_t temp = 0;

uint16_t char_counter(char *buf_unpacked, uint16_t *buf_packed,
                      uint16_t sz_unpacked);

int main(void) {
  f_in = fopen(file_in, "r");
  f_out = fopen(file_out, "w");
  fscanf(f_in, "%[^\n]s", string);
  while (*(string + counter) != ' ') {
    counter++;
  }
  strncpy(first, string, counter);
  strcpy(second, string + counter + 1);
  size_first_c = char_counter(first, first_c, strlen(first));
  size_second_c = char_counter(second, second_c, strlen(second));
  if (size_first_c <= size_second_c) {
    for (uint8_t i = 0; i < size_first_c; i++) {
      temp = first_c[i];
      for (uint8_t j = 0; j < size_second_c; j++) {
        temp == second_c[j] && (uint8_t)temp == 1
            ? fprintf(f_out, "%c ", temp >> 8)
            : temp;
      }
    }
  } else {
    for (uint8_t i = 0; i < size_second_c; i++) {
      temp = second_c[i];
      for (uint8_t j = 0; j < size_first_c; j++) {
        temp == first_c[j] && (uint8_t)temp == 1
            ? fprintf(f_out, "%c ", temp >> 8)
            : temp;
      }
    }
  }

  fclose(f_in);
  fclose(f_out);
  return 0;
}

uint16_t char_counter(char *buf_unpacked, uint16_t *buf_packed, uint16_t sz_unpacked) {
  uint16_t cntr = sz_unpacked;
  uint16_t repetition = 0;
  uint16_t packed_cntr = 0;

  for (uint16_t x = 0; x < sz_unpacked; x++) {
    char temp = *(buf_unpacked + x);
    for (uint16_t y = x; y < sz_unpacked; y++) {
      if (temp == *(buf_unpacked + y) && temp != 0x7f) {
        repetition++;
        *(buf_unpacked + y) = 0x7f;
      }
    }
    if (temp != 0x7f) {
      *(buf_packed + packed_cntr) = temp << 8 | repetition;
      packed_cntr++;
    }
    repetition = 0;
  }

  return packed_cntr;
}