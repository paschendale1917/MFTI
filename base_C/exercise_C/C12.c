// Составить функцию, которая вычисляет синус как сумму ряда (с точностью 0.001)
//sin(x) = x - x3/3! + x5/5! - x7/7! + ...(x в радианах)
//float sinus(float x)



#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

uint32_t num = 0;

float sinus(float x);
uint32_t factorial(uint8_t number);

int main(void)
{
    scanf("%d", &num);
    printf("%.3f", sinus(num) );
}

float sinus(float x){
    float result=0;
    uint8_t cntr=1;
    for(float i=1;i<=x;i+=2){
        float tu=factorial(i);
        float ttu=pow(x,i);
       if(cntr%2)
       result+=ttu/tu;
       else
       result-=ttu/tu;
        cntr++;
    }
    return result;
}

uint32_t factorial(uint8_t number){
    uint32_t result=1;
    for(uint8_t i=1;i<=number;i++){
        result*=i;
    }
    return result;
}

