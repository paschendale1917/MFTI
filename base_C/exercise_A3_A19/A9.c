//вывод наибольшего из 5 введенных чисел

#include <stdio.h>
#include <stdint.h>

#define NUM      5

void max(uint8_t num);

int main(void) {
    max(NUM);
    return 0;
}

void max(uint8_t num) {
    if(num>255) return;
    int32_t number[NUM]= {0,};
    int32_t result=0;
    uint8_t cc=1;
    for(uint8_t i=0; i<num; i++) {
        scanf("%d",&number[i]);
    }
    result=number[0];
    while(cc<num) {
        if((result-number[cc])&0x80000000) {
            result=number[cc];
        }
        cc+=1;
    }
    printf("%d",result);
}
