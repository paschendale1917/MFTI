// В файле input.txt дана строка из не более 1000 символов. Показать номера
// символов, совпадающих с последним символом строки.
// Результат записать в файл output.txt

#include <stdint.h>
#include <stdio.h>

#define MAX_CHAR 1000

FILE *f_in, *f_out;
char *file_in = "input.txt";
char *file_out = "output.txt";
char string[MAX_CHAR] = "";
uint16_t counter = 0;
char end_literal = 0;
char temp = 0;

int main(void) {
  f_in = fopen(file_in, "r");
  f_out = fopen(file_out, "w");
  fscanf(f_in, "%[^\n]s", string);
  while (*(string + counter) != '\000') {
    end_literal = *(string + counter);
    counter++;
  }
  *(string + counter - 1) = '*';
  counter = 0;
  while (*(string + counter) != '*') {
    end_literal == *(string + counter) ? fprintf(f_out, "%u ", counter)
                                       : counter;
    counter++;
  }

  fclose(f_in);
  fclose(f_out);
  return 0;
}
