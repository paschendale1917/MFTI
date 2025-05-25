
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void print_float_bin(float num);

int main(void)
{
   print_float_bin(15.65);
    return 0;
}

void print_float_bin(float num) {
    unsigned int* fi = (unsigned int*)&num;
    for(int i=31;i>=0;i--) {
        // if(i==30 || i==22)
        //     putchar(' ');
        if(*fi&(1<<i))
            putchar('1');
        else
            putchar('0');
    }
    putchar('\n');
}