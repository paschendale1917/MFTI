//нахождение  наибольшего их цифр, составляющих трехзначное положительное число
#include <stdio.h>
#include <stdint.h>

uint8_t digit[3]= {0,};

void dig_parser(uint16_t num);
uint16_t max(void);

int main(void) {
    printf("%d",max());
    return 0;
}
void dig_parser(uint16_t number) {
    if(number>999||number<0) return;
    digit[0]=number%10;
    digit[1]=number/10%10;
    digit[2]=number/100;
}

uint16_t max(void) {
    uint32_t number;
    uint8_t result=0;
    uint8_t cc=1;
    scanf("%d",&number);
    dig_parser(number);
    result=digit[0];
    while(cc<3) {
        if((result-digit[cc])&0x80000000) {
            result=digit[cc];
        }
        cc+=1;
    }
    return result;
}



