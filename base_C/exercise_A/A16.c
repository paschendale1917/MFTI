//Ввести три числа и определить, верно ли, что они вводились в порядке возрастания.

#include <stdio.h>
#include <stdint.h>

#define NUM      3

int32_t numbers[NUM]= {0,};
uint8_t result=0;

uint8_t increase(int32_t *num, uint8_t num_digs);

int main(void ) {
    for(uint8_t i=0; i<NUM; i++) {
        scanf("%d",&numbers[i]);
    }
    switch( increase(numbers,NUM)) {
    case 0:
        printf("NO");
        break;
    case 1:
        printf("YES");
        break;
    }
    return 0;
}

uint8_t increase(int32_t *num, uint8_t num_digs) {
    uint8_t cc=0;
    while(cc<num_digs-1) {
        if((numbers[cc]-numbers[cc+1])&0x80000000) {
        } else return 0;
        cc+=1;
    }
    return 1;
}
