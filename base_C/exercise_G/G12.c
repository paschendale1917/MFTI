// В файле input.txt дано предложение требуется разобрать его на отдельные
// слова. Напечатать каждое слово на отдельной строке в файл output.txt.

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MAX_CHAR 2000

FILE *f_in, *f_out;
char *file_in = "input.txt";
char *file_out = "output.txt";

void find_word(char *str, uint16_t stringsize);
uint16_t num_space(char *str, uint16_t cntr);

char string[MAX_CHAR] = "";

int main(void) {
  f_in = fopen(file_in, "r");
  f_out = fopen(file_out, "w");
  fscanf(f_in, "%[^\n]s", string);
  find_word(string,strlen(string));
  fclose(f_in);
  fclose(f_out);
  return 0;
}

uint16_t num_space(char *str, uint16_t cntr) {
  uint16_t space_counter = 0;
  while (*(str + cntr + space_counter) == ' ') {
    space_counter++;
  }
  return space_counter;
}

void find_word(char *str, uint16_t stringsize) {
  uint16_t char_cntr = 0;
  uint16_t space_cntr = 0;
  uint8_t word_cntr = 0;
  uint16_t i = 0;
  while (i < stringsize) {
    while (*(str + char_cntr) != ' ') {
      if (*(str + char_cntr) == '\000')
        break;
    fprintf(f_out, "%c", *(str + char_cntr++));
    }
    !char_cntr||char_cntr>=stringsize-1?:fprintf(f_out, "%c", '\n');
    space_cntr = num_space(str, char_cntr);
    char_cntr += space_cntr;
    i = char_cntr;
  }
}
