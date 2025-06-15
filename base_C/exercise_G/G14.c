// В файле input.txt в одной строке фамилию, имя и отчество. Сформировать файл
// приветствие output.txt, где останутся имя и фамилия
// Формат: Фамилия Имя Отчество

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MAX_CHAR 100

FILE *f_in, *f_out;
char *file_in = "input.txt";
char *file_out = "output.txt";

char *payload_start= "Hello, ";
char *payload_stop= "!";
char output[MAX_CHAR] = "";


void greeting(char *str, uint8_t stringsize, char *payload, uint8_t payloadsize, char *out);

char string[MAX_CHAR] = "";

int main(void) {
  f_in = fopen(file_in, "r");
  f_out = fopen(file_out, "w");
  fscanf(f_in, "%[^\n]s", string);
  greeting(string,strlen(string),payload_start,strlen(payload_start),output); 
  fprintf(f_out, "%s", output);
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

void greeting(char *str, uint8_t stringsize, char *payload, uint8_t payloadsize, char *out) {
  uint16_t char_cntr = 0;
  uint16_t surname_lenth = 0;
  uint8_t offset = 0;
  for(uint8_t i=0;i<payloadsize;i++){
    *(out+i)=*(payload+i);
  }                                  //запилил приветствие
    while (*(str + char_cntr) != ' ') { //узнал размер фамилии
     char_cntr++;
    }
    surname_lenth=char_cntr;
    char_cntr += num_space(str, char_cntr); //снюхал количество пробелов между фамилией и именем

   while (*(str + char_cntr) != ' ') {          //перенес в целевой массив имя  
      *(out +payloadsize++) = *(str + char_cntr++);
    }
    *(out +payloadsize) = ' ';
    payloadsize++;
    char_cntr =0;

     while (*(str + char_cntr) != ' ') {          //перенес в целевой массив фамилию 
        offset=payloadsize + char_cntr;
      *(out + offset) = *(str + char_cntr);
        char_cntr++;
    }
*(out +offset+1) = '!';

}
