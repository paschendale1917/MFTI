// В файле input.txt дана строка, не более 1000 символов, содержащая буквы,
// целые числа и иные символы. Требуется все числа, которые встречаются в
// строке, поместить в отдельный целочисленный массив. Например, если дана
// строка "data 48 call 9 read13 blank0a", то в массиве числа 48, 9, 13 и 0.
// Вывести массив по возрастанию в файл output.txt.

#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define MAX_CHAR 1001

FILE *f_in, *f_out;
char *file_in = "input.txt";
char *file_out = "output.txt";

uint32_t finder(char *str, int32_t *out);
void sorter(int32_t *num, uint32_t mas_size);

char string[MAX_CHAR] = "";
int32_t out_buf[MAX_CHAR] = {0};
uint32_t out_size=0;

int main(void) {
  f_in = fopen(file_in, "r");
  f_out = fopen(file_out, "w");
  fscanf(f_in, "%[^\n]s", string);
  out_size=finder(string, out_buf);
  sorter(out_buf,out_size);
  for(uint32_t u=0;u<out_size;u++){
    fprintf(f_out, "%d ",*(out_buf+u));
  }
  fclose(f_in);
  fclose(f_out);
  return 0;
}

uint32_t finder(char *str, int32_t *out) {
  uint8_t temp[10] = {0};
  uint8_t temp_cntr = 0, out_cntr = 0;
  uint32_t num = 0;
  uint16_t stringsize = strlen(string);
  for (uint16_t i = 0; i < stringsize; i++) {
    if (*(str + i) > 0x2F && *(str + i) < 0x3A) {
      while (*(str + temp_cntr+i)>='0'&&*(str + temp_cntr+i)<='9') {
        *(temp+temp_cntr) = *(str + temp_cntr+i) - '0';
        temp_cntr++;
      }
       i+=temp_cntr;
    } else
      continue;
    for (uint8_t j= 0; j < temp_cntr; j++) {
      num += temp[j] * pow(10,  temp_cntr - j - 1);
    }
    out[out_cntr] = num;
    out_cntr++;
    temp_cntr = 0;
    num=0;
  }
  return out_cntr;
}

void sorter(int32_t *num, uint32_t mas_size) {
    for (uint8_t i = 0; i < mas_size; i++) {
      int32_t temp = 0;
      for (uint8_t j = 0; j < mas_size - 1; j++) {
        if (num[j]  > num[j + 1] ) {
          temp = num[j];
          num[j] = num[j + 1];
          num[j + 1] = temp;
        }
      }
    }
}