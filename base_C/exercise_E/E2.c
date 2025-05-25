//Ввести c клавиатуры массив из 5 элементов, найти минимальный из них. 
#include <stdio.h>
#include <stdint.h>

#define AMOUNT    5

int32_t number[AMOUNT]= {0,};

int32_t min(int32_t *num, uint8_t num_digs);

int main(void) {
    for(uint8_t i=0; i<AMOUNT; i++) {
        scanf("%d",&number[i]);
    }
    printf("%d",min(number,AMOUNT));
    return 0;
}

int32_t min(int32_t *num, uint8_t num_digs) {
    int32_t result=0;
    uint8_t cc=1;
    result=num[0];
    while(cc<num_digs) {
        if(!((result-num[cc])&0x80000000)) { //если разность предыдущего  и следющего элементов массива число отрицательное, тогда в предыдущее пишем последующще, отсортировывая таким образом в переменную result минимальное значение 
            result=num[cc];
        }
        cc+=1;
    }
   return result;
}