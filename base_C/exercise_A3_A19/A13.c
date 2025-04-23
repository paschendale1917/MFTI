
//вывод произведения цифр любого трехзначного положительного числа

#include <stdio.h>
#include <stdint.h>

void sum(void);

int main(void) {
    sum();
    return 0;
}

void sum(void) {
    uint8_t digit[3]= {0,};
    uint32_t  number=0;
    uint16_t result=0;
    scanf("%u",&number);
    if(number>999||number<0) return;
    digit[0]=number%10;
    digit[1]=number/10%10;
    digit[2]=number/100;
    result=digit[0]*digit[1]*digit[2];
    printf("%u",result);
}
