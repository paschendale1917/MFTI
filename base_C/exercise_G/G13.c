// В файле input.txt записан полный адрес файла (возможно, без расширения).
// Необходимо изменить его расширение на ".html" и записать результат в файл
// output.txt.

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MAX_CHAR 2000

FILE *f_in, *f_out;
char *file_in = "input.txt";
char *file_out = "output.txt";

char *payload = ".html";

uint32_t get_ext(char *str, uint16_t stringsize, char *payload,
                 uint8_t payloadsize);

char string[MAX_CHAR] = "";

int main(void) {
  f_in = fopen(file_in, "r");
  f_out = fopen(file_out, "w");
  fscanf(f_in, "%[^\n]s", string);
  get_ext(string, strlen(string), payload, strlen(payload));
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

uint32_t get_ext(char *str, uint16_t stringsize, char *payload,
                 uint8_t payloadsize) {
  uint16_t char_cntr = 0;
  uint16_t slash_cntr = 0;
  uint16_t dot_cntr = 0;
  do {
    *(str + stringsize - 1 - char_cntr) == '.' ? dot_cntr++ : dot_cntr;
    *(str + stringsize - 1 - char_cntr) == '/' ? slash_cntr++ : slash_cntr;
    char_cntr++;

  } while (*(str + stringsize - 1 - char_cntr) != '.' &&
           char_cntr < stringsize);

  switch (slash_cntr) { // выясняем, была ли точка до слэша
  case 0: // если слэш оказался первым с конца строки, то расширения нет
    uint8_t cntr = 0;
    while (*(str + stringsize - cntr) != '.') {
      cntr++;
    } // отсчитываем количество символов до точки
    uint8_t offset = stringsize - char_cntr;
    if (payloadsize >
        char_cntr) { // если размер нашего расширения больше длины имеющегося
                     // расширения, то можно не париться и просто перетереть
      for (uint8_t i = 0; i < payloadsize; i++) {
        *(str + offset + i - 1) = *(payload + i);
      }
    } else { // если же длина имеющегося расширения больше нашего расширения, то
             // перетираем нашим некоторое количество, а остальное затираем
             // NULL'ами
      for (uint8_t i = 0; i < char_cntr; i++) {
        *(str + offset + i - 1) = payloadsize-- ? *(payload + i) : 0x00;
      }
    }
    fprintf(f_out, "%s", str);
    break;
  default: // во всех иных случаях расширение есть
    for (uint8_t i = 0; i < payloadsize; i++) {
      *(str + stringsize + i) = *(payload + i);
    }
    fprintf(f_out, "%s", str);
    break;
  }
  return 0;
}
