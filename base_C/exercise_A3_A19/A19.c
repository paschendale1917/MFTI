
//Даны стороны треугольника a, b, c. Определить существует ли такой треугольник.

#include <stdio.h>
#include <stdint.h>

int32_t a=0;
int32_t b=0;
int32_t c=0;

int main(void) {
    scanf("%d%d%d",&a,&b,&c);
    if(a<b+c&&b<a+c&&c<a+b) {
        printf("YES");
    } else printf("NO");
    return 0;
}
