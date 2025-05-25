// Считать массив из 10 элементов и выделить в другой массив все числа, которые
// встречаются более одного раза. В результирующем массиве эти числа не должны
// повторяться.

#include <stdint.h>
#include <stdio.h>

#define AMOUNT 10

int32_t numbers[AMOUNT] = {0};
int32_t out[AMOUNT] = {0};
uint8_t counter = 0;                                        //глобальный счетчик для передачи количества отсортированных значений на вывод

void sorter(int32_t *num, int32_t *num_out, uint8_t mas_size);

int main(void) {
  for (uint8_t i = 0; i < AMOUNT; i++) {
    scanf("%d", &numbers[i]);
  }
  sorter(numbers, out, AMOUNT);
  for (uint8_t i = 0; i < counter; i++) {
    printf("%d ", *(out + i));
  }

  return 0;
}


void sorter(int32_t *num_in, int32_t *num_out, uint8_t mas_size) {
  int8_t cntr=1;                                             //локальный счетчик повторений
  for (uint8_t i = 0; i < mas_size; i++) {          
    for (uint8_t j = i + 1; j < mas_size; j++) {
      if(num_in[i] == num_in[j]&&num_in[i]!=0xff){           //i-тый элемент массива последовательно сравниваем со всеми остальными элементами массива
        cntr++;                                              //счетчик увеличивается, если есть совпадение
        num_in[j]=0xff;                                      //затираем совпадающие  значения, чтобы он дальше не выносили мозг
      }
    }
       if(cntr>1) {                                         
        num_out[counter] = num_in[i];
        counter++;
        cntr=1;
    }
  }
}

