//вывод наибольшего из 3х введенных чисел

#include <stdio.h>
#include <stdint.h>

#define NUM     3

int32_t number[NUM]= {0,};

int32_t max(int32_t *num, uint8_t num_digs);

int main(void) {
    printf("%d",max(number, NUM));
    return 0;
}

int32_t max(int32_t *num, uint8_t num_digs) {
    int32_t result=0;
    uint8_t cc=1;
    for(uint8_t i=0; i<num_digs; i++) {
        scanf("%d",&num[i]);
    }
    result=num[0];
    while(cc<num_digs) {
    (result-num[cc])&0x80000000?result=num[cc]:result;
        cc+=1;
    }
    return result;
}
