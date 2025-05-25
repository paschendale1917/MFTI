// Дан массив из 10 элементов. Определить, какое число в массиве встречается чаще всего. Гарантируется, что такое число ровно 1. 

#include <stdint.h>
#include <stdio.h>

#define AMOUNT 10

int32_t numbers[AMOUNT] = {0};
uint8_t counter=0;


int64_t sorter(int32_t *num, uint8_t mas_size);

int main(void) {
  for (uint8_t i = 0; i < AMOUNT; i++) {
    scanf("%d", &numbers[i]);
  }
  printf("%d ", (int32_t)(sorter(numbers, AMOUNT)>>8));
  return 0;
}


int64_t sorter(int32_t *num_in, uint8_t mas_size) {
  uint8_t cntr=1; 
  uint8_t cc=0;                                            //локальный счетчик повторений
  int64_t repnum=0;       
  int64_t out[AMOUNT] = {0};                                     
  for (uint8_t i = 0; i < mas_size; i++) {          
    for (uint8_t j = i + 1; j < mas_size; j++) {
      if(num_in[i] == num_in[j]&&num_in[i]!=0xff){           //i-тый элемент массива последовательно сравниваем со всеми остальными элементами массива
        cntr++;                                              //счетчик увеличивается, если есть совпадение
        num_in[j]=0xff;                                      //затираем совпадающие  значения, чтобы он дальше не выносили мозг
      }
    }
       if(cntr>1) {                                         
        out[counter] = num_in[i]<<8|cntr;
        counter++;
        cntr=1;
    }
  }
  repnum=*(out+cc);
  while(*(out+cc)){
    if((uint8_t)*(out+cc)<(uint8_t)*(out+cc+1)){
        repnum=*(out+cc+1);   
    } 
    cc+=1;
  }
   return repnum;
}