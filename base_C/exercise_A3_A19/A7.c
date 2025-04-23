//Ввести два числа и вывести их в порядке возрастания

#include <stdio.h>

int number[2]= {0,};

int main(void) {
    scanf("%d%d",&number[0],&number[1]);
    if(number[0]<number[1]) {
        printf("%d %d",number[0],number[1]);
    } else {
        printf("%d %d",number[1],number[0]);
    }

    return 0;
}
