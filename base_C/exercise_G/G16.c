// В файле input.txt дано предложение. Необходимо заменить все имена «Ling» на
// «Cao» и результат записать в файл output.txt.

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

uint16_t cao_counter(char *str);
void exchange(char *str_in, char *str_out);

int main(void) {
  f_in = fopen(file_in, "r");
  f_out = fopen(file_out, "w");
  fscanf(f_in, "%[^\n]s", string);
  exchange(string, output);
  fprintf(f_out, "%s", output);
  fclose(f_in);
  fclose(f_out);
  return 0;
}

uint8_t payload_finder(char *str, char *payload, uint8_t payload_size) {
  uint8_t cntr = 0;
  while (cntr < payload_size) {
    if (*(str + cntr) == *(payload + cntr)) {
      cntr++;
    } else {
      break;
    }
  }
  return cntr == payload_size ?  1 : 0;
}

void exchange(char *str_in, char *str_out) {
  uint16_t char_in = 0;
  uint16_t char_out = 0;
  char *payload_out = "Cao";
  char *payload_in = "Ling";
  while (*(str_in + char_in) != '\000') {
    if (payload_finder(str_in + char_in, payload_in,strlen(payload_in))) {
      for (uint8_t u = 0; u < strlen(payload_out); u++) {
        *(str_out + u + char_out) = *(payload_out + u);
      }
      char_out += strlen(payload_out);
      char_in += strlen(payload_in);
    } else {
      *(str_out + char_out) = *(str_in + char_in);
      char_in++;
      char_out++;
    }
  }
}
