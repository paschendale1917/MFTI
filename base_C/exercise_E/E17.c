//Дан массив из 10 элементов. В массиве найти элементы, которые в нем встречаются только один раз, и вывести их на экран. 

#include <stdint.h>
#include <stdio.h>

#define AMOUNT 10

int32_t numbers[AMOUNT] = {0};
int32_t out[AMOUNT]={0};
uint8_t counter=0;


void sorter(int32_t *num, int32_t *num_out, uint8_t mas_size);

int main(void) {
  for (uint8_t i = 0; i < AMOUNT; i++) {
    scanf("%d", &numbers[i]);
  }
  sorter(numbers,out,AMOUNT);
  for(uint8_t i=0;i<counter;i++){
    printf("%d ", *(out + i));
  }
  return 0;
}


void sorter(int32_t *num_in, int32_t *num_out, uint8_t mas_size) {
  uint8_t cntr=1; 
  uint8_t cc=0;                                            //локальный счетчик повторений
  int64_t repnum=0;                                 
  for (uint8_t i = 0; i < mas_size; i++) {          
    for (uint8_t j = i + 1; j < mas_size; j++) {
      if(num_in[i] == num_in[j]&&num_in[i]!=0xff){           //i-тый элемент массива последовательно сравниваем со всеми остальными элементами массива
        cntr++;                                              //счетчик увеличивается, если есть совпадение
        num_in[j]=0xff;                                      //затираем совпадающие  значения, чтобы он дальше не выносили мозг
      }
    }
       if(cntr<2&&num_in[i]!=0xff) {                                         
        out[counter] = num_in[i];
        counter++;
    }
     cntr=1;
  }
}