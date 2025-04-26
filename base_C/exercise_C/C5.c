// Составить функцию, которая определяет сумму всех чисел от 1 до N и привести пример ее использования. 

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int32_t num;
uint8_t cnt = 0;

int32_t calc(int32_t);

int main(void)
{
    scanf("%d", &num);
    printf("%d",  calc(num));
    return 0;
}

int32_t calc(int32_t number)
{
int32_t result=0;
for(uint32_t i=1;i<= number;i++){
 result+=i;
}
return result;
}


