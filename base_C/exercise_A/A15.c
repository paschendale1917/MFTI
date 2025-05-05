//Определить уравнение прямой по координатам двух точек y=k*x+b
#include <stdio.h>
#include <stdint.h>

int32_t x,y,xx,yy;

float calc_k(void);
float calc_b(float k);

int main(void) {
    scanf("%d%d%d%d",&x,&y,&xx,&yy);
    printf("%.2f %.2f",calc_k(),calc_b(calc_k())); //заставил еще разок посчитать k)
    return 0;
}

float calc_k(void) {
    float k;
    k=(float)(y-yy)/(x-xx);
    return k;
}

float calc_b(float k) {
    float b;
    b=(float)(yy-k*xx);
    return b;
}
