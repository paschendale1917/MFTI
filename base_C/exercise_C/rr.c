#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

#define eps 1e-3

double Sin( double x )
{
    double an, sum;
    
    sum = an = x *= ( 3.14 / 180. );
    for( size_t n = 0; fabs( an ) > eps; n++ )
    {
        an  *= -x * x / ( 2 * n + 2 ) / ( 2 * n + 3 );
        sum += an;
    }
    return sum;
}
 
int main()
{
    double grade;
 
    printf( "Enter the angle (in degrees): " );
    if( scanf( "%lf", &grade ) != 1 )   return 1;
 
    printf( "Sin(%g) = %.3g\n", grade, Sin( grade ) );
    printf( "sin(%g) = %.3g\n", grade, sin( grade *3.14 / 180 ) );
 
    return 0;
}