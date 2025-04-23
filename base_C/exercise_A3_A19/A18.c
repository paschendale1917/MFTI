//Ввести два числа. Если первое число больше второго, то программа печатает слово Above. Если первое число меньше второго, то программа печатает слово Less. А если числа равны, программа напечатает сообщение Equal.

#include <stdio.h>
#include <stdint.h>

int32_t num_f=0;
int32_t num_s=0;

int main(void) {
    scanf("%d%d",&num_f,&num_s);
    if(num_f-num_s>0) {
        printf("Above");
    } else if(num_f-num_s==0) {
        printf("Equal");
    } else printf("Less");
    return 0;
}
