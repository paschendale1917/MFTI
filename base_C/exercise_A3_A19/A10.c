//вывод наименьшего из 5 введенных чисел

#include <stdio.h>
#include <stdint.h>

#define NUM     5

int32_t number[NUM]= {0,};

int32_t min(int32_t *num, uint8_t num_digs);

int main(void) {
    for(uint8_t i=0; i<NUM; i++) {
        scanf("%d",&number[i]);
    }
    printf("%d",min(number,NUM));
    return 0;
}

int32_t min(int32_t *num, uint8_t num_digs) {
    int32_t result=0;
    uint8_t cc=1;
    result=num[0];
    while(cc<num_digs) {
        if(!((result-num[cc])&0x80000000)) {
            result=num[cc];
        }
        cc+=1;
    }
   return result;
}
