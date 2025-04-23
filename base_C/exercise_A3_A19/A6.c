#include <stdio.h>

int number[2]= {0,};
int result=0;

int main(void) {
    scanf("%d%d",&number[0],&number[1]);
    result=number[0]-number[1];
    printf("%d",result);
    return 0;
}
