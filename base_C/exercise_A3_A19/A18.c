//Ввести два числа. Если первое число больше второго, то программа печатает слово Above. Если первое число меньше второго, то программа печатает слово Less. А если числа равны, программа напечатает сообщение Equal.

#include <stdio.h>
#include <stdint.h>

int32_t num_f=0;
int32_t num_s=0;

int main(void) {
    scanf("%d%d",&num_f,&num_s);
if((num_f-num_s)){
    !((num_f-num_s)&0x80000000)? printf("Above"):printf("Less");
} else  printf("Equal");
    return 0;
}
