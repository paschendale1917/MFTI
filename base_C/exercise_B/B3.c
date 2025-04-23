// Ввести два целых числа a и b (a ≤ b) и вывести сумму квадратов всех чисел от a до b.  Два целых числа по модулю не больше 100

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int num_f = 0;
int num_s = 0;
int result = 0;

int main(void)
{
  scanf("%d%d", &num_f, &num_s);
  if (abs(num_f) > 100 || abs(num_s) > 100 || num_f > num_s)
    abort();
  for (int i = abs(num_f); i <= abs(num_s); i++)
  {
    result += pow(i, 2);
  }
  printf("%d ", result);
}
