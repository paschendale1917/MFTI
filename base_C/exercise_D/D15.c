// Дана последовательность ненулевых целых чисел, завершающаяся числом 0. Ноль в последовательность не входит. Определите наибольшее значение числа в этой последовательности. Для решения задачи необходимо написать рекурсивную функцию вида:
//int max_find(int max)

#include <stdio.h>
#include <stdint.h>

int32_t num = 0;

int32_t max_find(int32_t max);

int main(void)
{
   printf("%d",max_find(0));
     return 0;
}

int32_t max_find(int32_t max)
{
 scanf("%d", &num);
 if(!num)return max;           //если встретили в последовательности нуль, то возвращаем значение max
 num>max||!max?max=num:max;          
 return max_find(max);
}
