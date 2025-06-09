// Считать число N из файла input.txt. Сформировать строку из N символов. N
// четное число, не превосходящее 26. На четных позициях должны находится четные
// цифры в порядке возрастания, кроме 0, на нечетных позициях - заглавные буквы
// в порядке следования в английском алфавите. Результат записать в файл
// output.txt

#include <stdint.h>
#include <stdio.h>
//#include <string.h>

#define MAX_NUM 26

FILE *file;
char *file_in = "input.txt";   // указатель на файл,хранящий символы
char *file_out = "output.txt"; // указатель на файл, куда будем писать итог
char string[MAX_NUM] = "";
uint8_t count = 0;
char literal = 'A';
uint8_t num = 2;

int main(void) {
  file = fopen(file_in, "r");
  fscanf(file, "%u", (int32_t *)&count);
  fclose(file);
  for (uint8_t i = 1; i <= count; i++) {
    switch (i % 2) {
    case 0:
      *(string + i - 1) = num + '0';
      num += 2;
      num > 8 ? num = 2 : num;
      break;
    case 1:
      *(string + i - 1) = literal;
      literal++;
      break;
    }
  }
  file = fopen(file_out, "w");
  fprintf(file, "%s", string);
  fclose(file);
  return 0;
}
