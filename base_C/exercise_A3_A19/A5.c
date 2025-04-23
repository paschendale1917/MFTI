#include <stdio.h>


int number[3]= {0,};
float result=0;
int k=0;

int main(void) {
    scanf("%d%d%d",&number[0],&number[1],&number[2]);
    while( k<3) {
        result+=number[k];
        k++;
    }
    result/=3;
    printf("%.2f",result);
    return 0;
}
