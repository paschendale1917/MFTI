// Написать функцию и программу демонстрирующую работу данной функции. Вывести в
// порядке возрастания цифры, входящие в десятичную запись натурального числа N,
// не более 1000 цифр. Цифра пробел сколько раз данная цифра встречается в
// числе.
#include <stdint.h>
#include <stdio.h>

#define AMOUNT 1000

char str[AMOUNT] = "";
int counter = 0;

void grow_up(int size, char s[]);

int main(void) {

  scanf("%[^\n]", str);
  grow_up(AMOUNT, str);
  return 0;
}

void grow_up(int size, char s[]) {
  int num_in[200],result[200]= {0};
  int char_cntr,num_cntr,result_cntr = 0;
  int repetition = 1;
  // преобразование строки в числовой массив
  while (s[char_cntr] != '\000') {
    num_in[char_cntr] = s[char_cntr] - 48;
    char_cntr++;
  }
  // подсчет количества повторений каждого числа
  for (int i = 0; i < char_cntr; i++) {
    for (int j = i + 1; j < char_cntr; j++) {
      if (num_in[i] == num_in[j] && num_in[i] != 0xff) {
        repetition++;
        num_in[j] = 0xff;
      }
    }
    // кладем число и количество его повторений в отдельный массив
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