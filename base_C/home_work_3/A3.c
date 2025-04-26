

#include <stdio.h>


int number[3]= {0,};
int result=0;

int main(void) {
    scanf("%d%d%d",&number[0],&number[1],&number[2]);
    for(int k=0; k<sizeof(number)/sizeof(number[0]); k++) {
        result+=number[k];
    }
    printf("%d+%d+%d=%d",number[0],number[1],number[2],result);
    return 0;
}

