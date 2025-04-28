//вывод суммы максимального и минимального из введенных значений

#include <stdio.h>
#include <stdint.h>

#define NUM     5

int32_t number[NUM]= {0,};

int32_t sum_minmax(int32_t *num);

int main(void) {
    for(uint8_t i=0; i<NUM; i++) {
        scanf("%d",&number[i]);
    }
    printf("%d",sum_minmax(number));
    return 0;
}

int32_t sum_minmax(int32_t *num) {
    int32_t result_max=num[0];;
    int32_t result_min=num[0];
    int32_t result_total=0;
    uint8_t cc=1;
    while(cc<NUM) {
        if((result_max-num[cc])&0x80000000) {
            result_max=num[cc];
        } else if(!((result_min-num[cc])&0x80000000)) {
            result_min=num[cc];
        }
        cc+=1;
    }
    return result_total=result_max+result_min;
}


