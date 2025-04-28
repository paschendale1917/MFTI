
#include <stdio.h>


int number[3]= {0,};
int result_sum=0;
int result_mult=1;

int main(void) {
    scanf("%d%d%d",&number[0],&number[1],&number[2]);
    for(int k=0; k<sizeof(number)/sizeof(number[0]); k++) {
        result_sum+=number[k];
        result_mult*=number[k];
    }
    printf("%d+%d+%d=%d\n",number[0],number[1],number[2],result_sum);
    printf("%d*%d*%d=%d",number[0],number[1],number[2],result_mult);
    return 0;
}

