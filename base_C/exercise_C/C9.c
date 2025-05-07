// Составить функцию вычисления N!. Использовать ее при вычислении факториала int factorial(int n).Целое положительное число не больше 20 

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

uint8_t num = 0;

uint32_t factorial(uint8_t number);

int main(void)
{
    scanf("%u", &num);
    printf("%u",factorial(num));
}


uint32_t factorial(uint8_t number){
    uint32_t result=1;
    for(uint8_t i=1;i<=number;i++){
        result*=i;
    }
    return result;
}