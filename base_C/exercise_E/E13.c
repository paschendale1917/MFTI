// Считать массив из 10 элементов и отобрать в другой массив все числа, у которых вторая с конца цифра (число десятков) – ноль. 

#include <stdint.h>
#include <stdio.h>

#define AMOUNT 10

int32_t numbers[AMOUNT] = {0};
int32_t out[AMOUNT]={0};
uint8_t counter=0;

void sorter(int32_t *num,int32_t *num_out, uint8_t mas_size);

int main(void) {
  for (uint8_t i = 0; i < AMOUNT; i++) {
    scanf("%d", &numbers[i]);
  }
 sorter(numbers,out,AMOUNT);
  for (uint8_t i = 0; i < counter; i++) {
    printf("%d ", *(out + i));
  }

  return 0;
}

void sorter(int32_t *num_in,int32_t *num_out, uint8_t mas_size){
    for(uint8_t i=0;i<mas_size;i++){
       if(!(num_in[i]/10%10)){
        num_out[counter]=num_in[i];
        counter++;
       } 
    }
}