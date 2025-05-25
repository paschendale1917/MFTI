// Считать массив из 10 элементов и выполнить инверсию отдельно для 1-ой и 2-ой
// половин массива. Необходимо изменить считанный массив и напечатать его одним
// циклом.

#include <stdint.h>
#include <stdio.h>

#define AMOUNT 10
#define NUM_PARTS 2

int32_t numbers[AMOUNT] = {0};

//void transposition(int32_t *num, uint8_t size);
void transposition(int32_t *num, uint8_t mas_size, uint8_t num_parts) ;

int main(void) {
  for (uint8_t i = 0; i < AMOUNT; i++) {
    scanf("%d", &numbers[i]);
  }
  transposition(numbers,AMOUNT,NUM_PARTS);
  for (uint8_t i = 0; i < AMOUNT; i++) {
    printf("%d ", *(numbers+i));
  }

  return 0;
}


void transposition(int32_t *num, uint8_t mas_size, uint8_t num_parts) {
  int32_t temp = 0;
  uint8_t num_elements = mas_size / num_parts;                                       // количество элементов в каждой из частей
  for (uint8_t u = 0; u < num_parts; u++) {
    uint8_t offset =u * num_elements;                                              // смещение индекса элемента массива в зависимости от количества частей, на которые разбивается  массив
    for (uint8_t i = 0; i < (num_elements / 2); i++) {
      temp = num[i + offset];
      num[i + offset] = num[num_elements - 1 - i + offset];
      num[num_elements - 1 - i + offset] = temp;
    }
  }
}

//способ "в лоб"
// void transposition(int32_t *num, uint8_t size) {
//   uint8_t cc = 0;
//   int32_t temp = 0;
//   while (cc < ((size/2-1)/2)) {   //округление до uint
//    temp=*(num+cc);
//    *(num+cc)=*(num+size/2-1-cc);
//    *(num+size/2-1-cc)=temp;
//    temp=*(num+size/2+cc);
//    *(num+size/2+cc)=*(num+size-1-cc);
//    *(num+size-1-cc)=temp;
//    cc+=1;
//   }
// }
