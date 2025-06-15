#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define SIZE 30

// Описать структурный тип для представления сбора информации с датчика
// температуры, необходимые поля: дата (день, месяц, год) и температура.
// Используя этот тип, описать функцию, принимающую на вход массив таких данных
// и упорядочивающую его по возрастанию температуры, по дате

struct sensor {
  uint8_t year;
  uint8_t month;
  uint16_t day;
  int8_t temp;
};

typedef struct sensor sensor_t;

sensor_t info[SIZE];

void AddRecord(sensor_t info[], int32_t number, uint16_t year, uint8_t month,
               uint8_t day, int8_t temp) {
  info[number].year = year;
  info[number].month = month;
  info[number].day = day;
  info[number].temp = temp;
}

int32_t AddInfo(sensor_t info[]) {
  int32_t counter = 0;
  AddRecord(info, counter++, 2021, 9, 16, 9);
  AddRecord(info, counter++, 2022, 9, 2, -9);
  AddRecord(info, counter++, 2021, 1, 7, 8);
  AddRecord(info, counter++, 2021, 9, 5, 1);
  return counter;
}

void print(struct sensor *info, int number) {
  printf("===================================\n");
  for (uint32_t i = 0; i < number; i++)
    printf("%04d-%02d-%02d t=%3d\n", info[i].year, info[i].month, info[i].day,
           info[i].temp);
}

int main(void) { return 0; }