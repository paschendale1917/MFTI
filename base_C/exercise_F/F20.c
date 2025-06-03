// Дан целочисленный массив из 10 элементов. Необходимо определить количество
// четных и нечетных чисел. Если количество чётных чисел больше, чем количество
// нечётных, заменить каждое нечетное число на произведение нечетных цифр в его
// десятичной записи. Если количество нечётных чисел больше или равно количеству
// чётных, заменить каждое чётное число на произведение чётных цифр в его
// десятичной записи.

#include <stdint.h>
#include <stdio.h>

#define AMOUNT 10
#define ODD 1
#define EVEN 0

int32_t arr[AMOUNT] = {0};

int32_t
mult_odd(int32_t number);                                                           // прототип функции для вычисления произведения нечетных цифр в десятичной записи числа
int32_t mult_even(int32_t number);                                                  // прототип функции для вычисления произведения четных цифр в десятичной записи числа
uint8_t counter(int32_t *array, uint8_t size);                                      // счетчик четных и нечетных чисел в массиве
void changer(int32_t *array, uint8_t size, uint8_t type);

int main(void) {
  for (int i = 0; i < AMOUNT; i++) {
    scanf("%d", &*(arr + i));
  }
 changer(arr,AMOUNT,counter(arr,AMOUNT));
 for (int i = 0; i < AMOUNT; i++) {
    printf("%d ", *(arr + i));
  }

  return 0;
}

int32_t mult_odd(int32_t number) {
  if (!(number % 2))
    return -1;
  int32_t result = 1;
  while (number) {
    number % 10 % 2 ? result *= number % 10 : result;
    number /= 10;
  }
  return result;
}

int32_t mult_even(int32_t number) {
  if (number % 2)
    return -1;
  int32_t result = 1;
  while (number) {
    !(number % 10 % 2) ? result *= number % 10 : result;
    number /= 10;
  }
  return result;
}

uint8_t counter(int32_t *array, uint8_t size) {
  uint8_t odd = 0, even = 0;
  for (uint8_t i = 0; i < size; i++) {
    *(array + i) % 2 ? odd++ : even++;
  }
  if (even > odd)                                            //если четных больше
    return EVEN;
  else
    return ODD;
}

void changer(int32_t *array, uint8_t size, uint8_t type){ //type -even or odd
  switch(type){
    case 0:
        for(uint8_t i=0;i<size;i++){
            *(array+i)%2?*(array+i)=mult_odd(*(array+i)):*(array+i);
        };
        break;
    case 1:
        for(uint8_t i=0;i<size;i++){
            !(*(array+i)%2)?*(array+i)=mult_even(*(array+i)):*(array+i);
        };
        break;
  }
}