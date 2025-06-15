// В файле input.txt записаны символы. Необходимо разработать функцию, которая
// меняет местами пары соседних символов не обращая внимание на символы пробел.
// Если количество символов нечетно (пробелы не считаем), то последний символ не
// меняем. Результат записать в файл output.txt.

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

void exchange(char *str_in);

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

uint32_t odd_or_even(char *str) {
  uint16_t i = 0;
  uint16_t char_cntr = 0;
  while (*(str + i) != '\000') {
    *(str + i) != ' ' ? char_cntr++ : char_cntr;
    i++;
  }
  return char_cntr % 2 ? (uint32_t)char_cntr << 16 | 1
                       : (uint32_t)char_cntr << 16 | 0;
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

void exchange(char *str) {
  uint16_t num_chars = odd_or_even(str) >> 16;
  uint16_t num_replacements = 0;
  uint16_t str_position = 0;
  uint8_t num_spaces = 0;
  switch ((uint16_t)odd_or_even(str)) {
  case 0:
    while (num_replacements <= num_chars / 2) {
      if (*(str + str_position + 1) != ' ' && *(str + str_position) != ' ') {
        replace(str + str_position, str + str_position + 1);
        str_position += 2;
        num_replacements++;
      } else if (*(str + str_position) == ' ') {
        num_spaces = space_quantity(str, str_position);
        str_position += num_spaces;
      } else {
        num_spaces = space_quantity(str, str_position + 1);
        replace(str + str_position, str + str_position + num_spaces + 1);
        str_position += num_spaces + 2;
        num_replacements++;
      }
    }
    break;
  case 1:
    while (num_replacements < num_chars / 2) {
      if (*(str + str_position + 1) != ' ' && *(str + str_position) != ' ') {   //если ни текущая позиция в строке, ни последующая не являются пробелом, то просто меняем их местами
        replace(str + str_position, str + str_position + 1);
        str_position += 2;
        num_replacements++;                                                     //считаем количество замен
      } else if (*(str + str_position) == ' ') {                                //если текущая позиция является пробелом, тогда нужно посчитать количество пробелов и увеличить счетчик позиции в строке на полученное значение
        num_spaces = space_quantity(str, str_position);
        str_position += num_spaces;
      } else {                                                                  //если последующая позиция в строке является пробелом, тогда отсчитываем количество пробелов и меняем местами символ на текущей позиции и символ   на позиции с учетом пробелов
        num_spaces = space_quantity(str, str_position + 1);
        replace(str + str_position, str + str_position + num_spaces + 1);
        str_position += num_spaces + 2;                                         //увеличиваем позицию на количество пробелов + 2 символа, которые поменяли местами
        num_replacements++;
      }
    }
    break;
  }
}
