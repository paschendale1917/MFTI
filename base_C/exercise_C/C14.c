//Составить функцию логическую функцию, которая определяет, верно ли, что сумма его цифр – четное число. Используя эту функцию решить задачу. Одно целое не отрицательное число 

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint32_t num = 0;

uint8_t sum_is_even(uint32_t number);

int main(void)
{
    scanf("%u", &num);
    sum_is_even(num)?printf("NO"):printf("YES");
 
}


uint8_t sum_is_even(uint32_t number)
{
    uint8_t sum = 0;
    while(num){
        sum += num % 10;
        num /= 10;
    }
    if (sum%2)
        return 1;
    else
        return 0;
}