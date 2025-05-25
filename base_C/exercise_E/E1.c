//Ввести c клавиатуры массив из 5 элементов, найти среднее арифметическое всех элементов массива.

#include <stdio.h>
#include <stdint.h>

#define AMOUNT 5

int numbers[AMOUNT] = {0,};
float result = 0;
uint8_t k = 0;

int main(void) {
    for(uint8_t i = 0; i < AMOUNT; i++) {
        scanf("%d", &numbers[i]);
    }
    while(k < AMOUNT) {
        result += numbers[k];
        k++;
    }
    result /= AMOUNT;
    printf("%.3f", result);
    return 0;
}