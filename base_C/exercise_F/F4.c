// Написать только одну функцию. Всю программу отправлять не надо. Вывести в
// порядке возрастания цифры, входящие в строку. Цифра - количество. Функция
// должно строго соответствовать прототипу:
// void print_digit(char s[])

#include <stdint.h>
#include <stdio.h>

#define AMOUNT 1000

char str[AMOUNT] = "";
int counter = 0;

void print_digit(char s[]);

int main(void) {

  scanf("%[^\n]", str);
  print_digit(str);
  return 0;
}

void print_digit(char s[]) {
  int num_in[200],result[200]= {0};
  int char_cntr,num_cntr,result_cntr = 0;
  int repetition = 1;
  while (s[char_cntr] != '\000') {
    if (s[char_cntr] > 47 && s[char_cntr] < 58) {
      num_in[num_cntr] = s[char_cntr] - 48;
      num_cntr++;
    }
    char_cntr++;
  }
  for (int i = 0; i < num_cntr; i++) {
    for (int j = i + 1; j < num_cntr; j++) {
      if (num_in[i] == num_in[j] && num_in[i] != 0xff) {
        repetition++;
        num_in[j] = 0xff;
      }
    }
    if (num_in[i] != 0xff) {
      result[result_cntr] = num_in[i] << 8 | repetition;
      result_cntr++;
    }
    repetition = 1;
  }

  // сортируем целевой массив по убыванию
  for (int i = 0; i < result_cntr; i++) {
    int temp = 0;
    for (int j = 0; j < result_cntr - 1; j++) {
      if ((result[j] >> 8) > (result[j + 1] >> 8)) {
        temp = result[j];
        result[j] = result[j + 1];
        result[j + 1] = temp;
      }
    }
  }
  for (int i = 0; i < result_cntr; i++) {
    printf("%d %d\n", result[i] >> 8, (char)result[i]);
  }
}