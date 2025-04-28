//нахождение  наибольшего из цифр, составляющих трехзначное положительное число
#include <stdio.h>
#include <stdint.h>

#define NUM_DIGS  3

uint32_t number;
uint8_t digit[NUM_DIGS]= {0,};

void dig_parser(uint16_t num);
uint16_t max(uint8_t *buf, uint8_t nd);

int main(void) {
    scanf("%d",&number);
    dig_parser(number);
    printf("%d",max(digit,NUM_DIGS));
    return 0;
}

void dig_parser(uint16_t number) {
    if(number>999||number<0) return;
    digit[0]=number%10;
    digit[1]=number/10%10;
    digit[2]=number/100;
}

uint16_t max(uint8_t *buf, uint8_t nd) {
    uint8_t result=0;
    uint8_t cc=1;
   
    result=buf[0];
    while(cc<nd) {
        if((result-buf[cc])&0x80000000) {
            result=buf[cc];
        }
        cc+=1;
    }
    return result;
}



