//вывод наибольшего из 5 введенных чисел

#include <stdio.h>
#include <stdint.h>

#define NUM      5

int32_t numbers[NUM]= {0,};

int32_t max(int32_t *num, uint8_t nyam);

int main(void) {
    for(uint8_t i=0; i<NUM; i++) {
        scanf("%d",&numbers[i]);
    }
    printf("%d",max(numbers,NUM));
    return 0;
}

int32_t max(int32_t *num,uint8_t nyam) { 
    int32_t result=0;
    uint8_t cc=1;
    result=num[0];
    while(cc<nyam) {
        if(result<num[cc]){
            result=num[cc];
        }
        cc+=1;
    }
    return result;
}
