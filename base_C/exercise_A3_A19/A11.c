//вывод суммы максимального и минимального из введенных значений

#include <stdio.h>
#include <stdint.h>

#define NUM     5

int32_t sum_minmax(uint8_t num);


int main(void) {
    printf("%d",sum_minmax(NUM));
    return 0;
}

int32_t sum_minmax(uint8_t num) {
    if(num>255) return 1;
    int32_t number[NUM]= {0,};
    int32_t result_max=0;
    int32_t result_min=0;
    int32_t result_total=0;
    uint8_t cc=1;
    for(uint8_t i=0; i<num; i++) {
        scanf("%d",&number[i]);
    }
    result_max=number[0];
    result_min=number[0];
    while(cc<num) {
        if((result_max-number[cc])&0x80000000) {
            result_max=number[cc];
        } else if(!((result_min-number[cc])&0x80000000)) {
            result_min=number[cc];
        }
        cc+=1;
    }
    return result_total=result_max+result_min;
}


