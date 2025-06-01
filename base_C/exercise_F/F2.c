// Написать только одну функцию, которая ставит в начало массива все четные
// элементы, а в конец – все нечетные. Не нарушайте порядок следования чисел
// между собой. Строго согласно прототипу:.
// void sort_even_odd(int n, int a[])

#include <stdint.h>
#include <stdio.h>

#define AMOUNT 20

int numbers[AMOUNT] = {0};
int counter = 0;

void sort_even_odd(int size, int a[]);

int main(void) {

   for(int i=0;i<AMOUNT;i++){
    scanf("%d", &numbers[i]);
   }

  sort_even_odd(AMOUNT, numbers);
  for (uint8_t i = 0; i < AMOUNT; i++) {
    printf("%d ", *(numbers + i));
  }
  return 0;
}

void sort_even_odd(int size, int a[]) {
  int even[20] = {0};
  int odd[20] = {0};
  int cntr_even = 0;
  int cntr_odd = 0;
  // разбиваем входной массив на четные и нечетные и считаем количество четных и
  // нечетных элементов
  for (int i = 0; i < size; i++) {
    if (!(a[i] % 2)) {
      even[cntr_even] = a[i];
      cntr_even++;
    } else {
      odd[cntr_odd] = a[i];
      cntr_odd++;
    }
  }
  // пишем в исходный массив полученные результаты
  for (int i = 0; i < cntr_even; i++) {
    a[i] = even[i];
  }
  for (int i = cntr_even; i < cntr_even + cntr_odd; i++) {
    a[i] = odd[i-cntr_even];
  }
}
