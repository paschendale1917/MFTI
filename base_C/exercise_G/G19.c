// В файле input.txt необходимо удалить все лишние пробелы (в начале предложения
// и сдвоенные пробелы). Для решения задачи разработать функцию. Результат
// записать в output.txt.

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MAX_CHAR 2000

FILE *f_in, *f_out;
char *file_in = "input.txt";
char *file_out = "output.txt";

char output[MAX_CHAR] = "";
char string[MAX_CHAR] = "";

void exchange(char *str);

int main(void) {
  f_in = fopen(file_in, "r");
  f_out = fopen(file_out, "w");
  fscanf(f_in, "%[^\n]s", string);
  exchange(string);
  fprintf(f_out, "%s", string);
  fclose(f_in);
  fclose(f_out);
  return 0;
}

void replace(char *str1, char *str2) {
  char temp = *str1;
  *str1 = *str2;
  *str2 = temp;
}

uint16_t space_quantity(char *str, uint16_t cntr) {
  uint16_t space_counter = 0;
  while (*(str + cntr + space_counter) == ' ') {
    space_counter++;
  }
  return space_counter;
}
void transfer(char *str, uint16_t offset_start, uint8_t num_skips, uint16_t stringsize) {
  for (uint16_t i = 0; i < stringsize - offset_start; i++) { 
    *(str + offset_start + i) = *(str + offset_start+ num_skips + i);
  }
}

void exchange(char *str) {
  uint16_t string_pos = 0;
  uint16_t num_spaces = 0;
  if(*str==' '){                                                       //если есть пробел в начале строки, то сразу сдвинем строку на имеющееся количество пробелов
     num_spaces = space_quantity(str, string_pos);
     transfer(str, 0, num_spaces, strlen(str));
  }
  while (*(str + string_pos) != '\000') {
    if (*(str + string_pos) == ' ') {                                //при встрече с пробелом посчитаем количество пробелов, сдвигаем на 1 знакоместо, чтобы организовать 1 пробел и сдвигаем всю строку до получившейся позиции
      num_spaces = space_quantity(str, string_pos);          
      num_spaces > 1 ? string_pos++ : string_pos;
      transfer(str, string_pos-1, num_spaces-1, strlen(str));
    }
    string_pos++;
  }
}
