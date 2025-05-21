// оставить рекурсивную функцию, Выведите все числа от A до B включительно, в порядке возрастания, если A < B, или в порядке убывания в противном случае.
//Два целых числа через пробел.

#include <stdio.h>
#include <stdint.h>

int32_t num_a = 0;
int32_t num_b = 0;

void num_print(int32_t a, int32_t b);

int main(void)
{
    scanf("%d%d", &num_a, &num_b);
    num_print(num_a, num_b);
    return 0;
}

void num_print(int32_t a, int32_t b)
{
    printf("%d ", a);
    a < b ? num_print(a + 1, b) : a;
    a > b ? num_print(a - 1, b) : a;
}