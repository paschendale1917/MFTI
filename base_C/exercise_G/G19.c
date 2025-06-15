<<<<<<< HEAD
// Разработать функцию дана строка из маленьких английских букв. Составить из
// символов палиндром максимальной длинны. При составлении палиндрома буквы в
// палиндроме должны быть расположены в лексикографическом порядке. Записать
// ответ в файл output.txt. НЕ СДЕЛАНО
=======
// В файле input.txt необходимо удалить все лишние пробелы (в начале предложения
// и сдвоенные пробелы). Для решения задачи разработать функцию. Результат
// записать в output.txt. НЕ СДЕЛАНО
>>>>>>> a3df7a0d7feba6f3def8ec90613339439d719b42

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

void palindrom(char *str);

int main(void) {
  f_in = fopen(file_in, "r");
  f_out = fopen(file_out, "w");
  fscanf(f_in, "%[^\n]s", string);
 // exchange(string);
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
void transfer(char *str, uint16_t offset_start, uint8_t num_skips,
              uint16_t stringsize) {
  for (uint16_t i = 0; i < stringsize - offset_start; i++) {
    *(str + offset_start + i) = *(str + offset_start + num_skips + i);
  }
}

void palindrom(char *str) {

}
