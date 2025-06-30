#include "temp_api.h"
// #include <stdint.h>
// #include <stdio.h>
// #include <string.h>

record june_meas[NUM_MEAS] = {2025, june, 20, 19,   35,   26, 2025, june, 20,
                              19,   36,   26, 2025, june, 20, 19,   37,   27,
                              2025, june, 20, 19,   38,   26, 2025, june, 20,
                              19,   39,   25, 2025, june, 20, 19,   40,   29};

record july_meas[NUM_MEAS] = {2025, july, 20, 19,   35,   45, 2025, july, 20,
                              19,   36,   40, 2025, july, 20, 19,   37,   23,
                              2025, july, 20, 19,   38,   36, 2025, july, 20,
                              19,   39,   18, 2025, july, 20, 19,   40,   39};


char csvfile_name[] = "temperature_small.csv";
char csvbigfile_name[] ="temperature_big.csv";
data jan = {1, 0}, feb = {1, 0}, mar = {1, 0}, apr = {1, 0}, my = {1, 0},
     jun = {1, 0}, jul = {1, 0}, aug = {1, 0}, sept = {1, 0}, oct = {1, 0},
     nov = {1, 0}, dec = {1, 0};
const char month_name[12][10] = {
    "January", "February", "March",     "April",   "May",      "June",
    "July",    "August",   "September", "October", "November", "December"};

const char frame_month[10][50] = {
    "|-----------------------------------------------|",
    "|                                               |",
    "|                                               |",
    "|---------------|---------------|---------------|",
    "|               |               |               |",
    "|               |               |               |",
    "|---------------|---------------|---------------|",
    "|               |               |               |",
    "|               |               |               |",
    "|---------------|---------------|---------------|"};

void print_frame(const char *frame, uint8_t num_strings, uint8_t stringsize) {
  for (int i = 0; i < num_strings; i++) {
    printf("%s\n", frame + i * stringsize);
  }
}

// функция перестановки местами структур как элементов массива типа record
void swap(record *dt, uint32_t i, uint32_t j) {
  record temp;
  temp = *(dt + i);
  *(dt + i) = *(dt + j);
  *(dt + j) = temp;
}

// упорядочиваем данные в массиве структур типа record по возрастанию
// температуры
void sortByTemp(record *dt, uint32_t n) {
  for (uint32_t i = 0; i < n; ++i)
    for (uint32_t j = i; j < n; ++j)
      if ((dt + i)->temp >= (dt + j)->temp)
        swap(dt, i, j);
}

uint64_t encode_date(record *dt) {
  return (uint64_t)dt->year << 32 | (uint32_t)dt->month << 24 |
         (uint32_t)dt->day << 16 | (uint32_t)dt->hour << 8 | dt->min;
}

// упорядочиваем данные в массиве структур типа record по возрастанию даты
void sortByDate(record *dt, uint32_t n) {
  for (uint32_t i = 0; i < n; ++i)
    for (uint32_t j = i; j < n; ++j)
      if (encode_date(dt + i) >= encode_date(dt + j))
        swap(dt, i, j);
}

// функция заполнения 1 структуры данными
//*dt-указатель на структуру, num_meas - номер структуры как элемента массива,
// далее поля структуры
void add_record(record *dt, uint32_t num_meas, uint16_t year, uint8_t month,
                uint8_t day, uint8_t hour, uint8_t min, int8_t temp) {
  dt[num_meas].year = year;
  dt[num_meas].month = month;
  dt[num_meas].day = day;
  dt[num_meas].hour = hour;
  dt[num_meas].min = min;
  dt[num_meas].temp = temp;
}

// пока не ясно, нахрена козе баян
void add_info(record *dt_source, record *dt_dest, uint32_t num_records) {
  for (uint32_t i = 0; i < num_records; i++) {
    add_record(dt_dest, i, (dt_source + i)->year, (dt_source + i)->month,
               (dt_source + i)->day, (dt_source + i)->hour,
               (dt_source + i)->min, (dt_source + i)->temp);
  }
}

// пишем в структуру  типа data данные за отдельно взятый месяц и в его поле
// meas_amount помещаем количество снятых за месяц замеров(при импорте из файла
// нужно будет отсчитать)
void add_year_info(record *dt_source, data *dt_dest, uint8_t month_number,
                   uint32_t num_records) {
  dt_dest->meas_amount = num_records;
  for (uint32_t i = 0; i < num_records; i++) {
    dt_dest->measure[i] = *(dt_source + i);
  }
}

// функция вывода num_records записей из массива записей температуры
void print_records(record *dt, uint32_t num_records) {
  for (uint32_t i = 0; i < num_records; i++) {
    printf("%04d-%02d-%02d %02d:%02d t =%3d\n", (dt + i)->year, (dt + i)->month,
           (dt + i)->day, (dt + i)->hour, (dt + i)->min, (dt + i)->temp);
  }
}

// предположительно будет 12 массивов структур,которые будут помещены в
// структуры типа data в  массив буду помещать данные по одному из месяцев в
// структуре типа data производится хранение данных за месяц, где
// meas_amount==количество замеров
// функция расчета средней температуры в отдельно взятом месяце
int8_t month_average_temp(record *dt, uint32_t num_meas) {
  int16_t result = 0;
  for (uint8_t i = 0; i < num_meas; i++) {
    result += dt[i].temp;
  }
  return result / num_meas;
}

int8_t month_min_temp(record *dt, uint32_t num_meas) {
  sortByTemp(dt, num_meas);
  return dt[0].temp;
}

int8_t month_max_temp(record *dt, uint32_t num_meas) {
  sortByTemp(dt, num_meas);
  return dt[num_meas - 1].temp;
}

int8_t year_average_temp(data *dt, uint32_t num_meas) {
  int16_t result = 0;
  for (uint8_t i = 0; i < num_meas; i++) {
    result += dt->measure[i].temp;
  }
  return result / num_meas;
}

// получаем адрес структуры типа data, в каждой из которых содержится количество
// замеров и массив структур далее нужно будет написать функцию снюхивания
// данных по месяцам и раскидыванию их по струтурам типа data,
//   также нужно будет записывать в поле num_meas количество считанных данных по
//   снюханному месяцу
data *get_month(uint8_t num_month) {
  switch (num_month) {
  case january:
    return &jan;
    break;
  case february:
    return &feb;
    break;
  case march:
    return &mar;
    break;
  case april:
    return &apr;
    break;
  case may:
    return &my;
    break;
  case june:
    return &jun;
    break;
  case july:
    return &jul;
    break;
  case august:
    return &aug;
    break;
  case september:
    return &sept;
    break;
  case october:
    return &oct;
    break;
  case november:
    return &nov;
    break;
  case december:
    return &dec;
    break;
  }
  return 0;
}

void print_title(void) {
  printf("%-15s %-14s %-10s %s\n", "month", "average_temp", "min_temp",
         "max_temp");
  printf("------------ ---------------- ---------- ----------\n");
}

void print_month_info(uint8_t num_month) {
  add_year_info(july_meas, &jul, july, NUM_MEAS);
  add_year_info(june_meas, &jun, june, NUM_MEAS);
  printf("\n===============STATISTICS BY MONTH===============\n\n");
  print_title();
  int8_t av = 0, min = 0, max = 0;
  data *p = get_month(num_month);
  av = month_average_temp(p->measure, p->meas_amount);
  sortByTemp(p->measure, p->meas_amount);
  printf("%s%s %d%s%s %d%s%s %d%s\n", month_name[num_month - 1],
         "              ", av, "°C", "         ", p->measure[0].temp, "°C",
         "       ", p->measure[p->meas_amount - 1].temp, "°C");
  printf("\n===============All data for %s===============\n\n",
         month_name[num_month - 1]);
  printf("%-21s %-14s %-10s\n", "date", "time", "temp");
  printf("-----------          ------         ------\n");
  sortByDate(p->measure, p->meas_amount);
  for (int32_t i = p->meas_amount - 1; i >= 0; i--) {
    printf("%02u/%02u/%04u", p->measure[i].day, p->measure[i].month,
           p->measure[i].year);
    printf("%s%02u:%02u", "           ", p->measure[i].hour, p->measure[i].min);
    printf("%s%d%s\n", "           ", p->measure[i].temp, "°C");
  }
}
// вывод всех месяцев в году
void print_year_info(void) {
  printf(
      "\n===============STATISTICS BY MONTH FOR THE YEAR===============\n\n");
  print_title();
  for (uint8_t i = 1; i <= 12; i++) {
    int8_t av = 0, min = 0, max = 0;
    data *p = get_month(i);
    av = month_average_temp(p->measure, p->meas_amount);
    sortByTemp(p->measure, p->meas_amount);
    printf("%-19s %d%s%s %d%s%s %d%s\n", month_name[i - 1], av, "°C",
           "         ", p->measure[0].temp, "°C", "        ",
           p->measure[p->meas_amount - 1].temp, "°C");
  }
}
// статистика за год(три значения)
void print_yearstat_info(void) {
  int8_t max_temp = 0, min_temp = 100;
  int16_t av = 0;
  for (uint8_t i = 1; i <= 12; i++) {
    int8_t av = 0, min = 0, max = 0;
    data *p = get_month(i);
    av += month_average_temp(p->measure, p->meas_amount);
    sortByTemp(p->measure, p->meas_amount);
    min_temp > p->measure[0].temp ? min_temp = p->measure[0].temp : min_temp;
    max_temp < p->measure[p->meas_amount - 1].temp
        ? max_temp = p->measure[p->meas_amount - 1].temp
        : max_temp;
  }
  printf("\n===============STATISTICS FOR THE YEAR==========\n\n");
  printf("%-15s %-10s %s\n", "average_temp", "min_temp", "max_temp");
  printf("-------------  ---------  --------\n");
  printf("%s %d%s%s %d%s%s %d%s\n", "    ", av / 12, "°C", "         ",
         min_temp, "°C", "       ", max_temp, "°C");
}
// // чтение/запись из файла

// void rw_data(data *dt, uint32_t num_meas, char *csv_name, uint8_t mode) {
//   char *str;
//   switch (mode) {
//   case readFromFile:
//     FILE *rd = fopen(csv_name, "rb");
//     if(rd==NULL){
//       printf("Read error");
//       return;
//     }
//     fread(str, sizeof(dt->measure), 1, rd);
//     fclose(rd);
//     break;
//   case writeToFile:
//     FILE *wr = fopen(csv_name, "wb");
//     fwrite(&(dt->measure), num_meas * sizeof(dt->measure), 1, wr);
//     fclose(wr);
//     break;
//   }
// }

//НАДО ПРИДУМАТЬ,КАК НАЙТИ КОСЯЧНУЮ СТРОКУ
int32_t char2num(char *p, char stop_symb) {
  int32_t num = 0;
  uint8_t negative = 0;
  while (*p != stop_symb && *p != '\r' && *p != '\000') {
    if (*p == '-') {
      negative = 1;
      p++;
    } else if (*p >= '0' && *p <= '9') {
      num = num * 10 + (*p - '0');
      p++;
    } else {
      p++;
     // return TEMP_ERROR;
    }
  }
  return negative ? -num : num;
}

void clear_string(char *string) {
  for (uint8_t i = 0; i < STRING_LENTH; i++) {
    *(string + i) = 0;
  }
}


void read_data(data *dt, char *csv_name) {
  uint32_t meas_cntr = 0;
  uint16_t year = 0;
  uint8_t month = 0;
  uint8_t day = 0;
  uint8_t hour = 0;
  uint8_t min = 0;
  int8_t temp = 0;
  uint8_t endoffile = 1;
  char str[STRING_LENTH] = "";
  uint32_t cntr = 0;
  FILE *rd = fopen(csv_name, "rb");
  if (rd == NULL) {
    printf("Read error");
    return;
  }
  while (endoffile) {
    while (endoffile && *(str + cntr - 1) != '\n') {
      endoffile = fread(str + cntr, 1, 1, rd);
      cntr++;
    }
    year = char2num(str, ';');
    month = char2num(str + 5, ';');
    day = char2num(str + 8, ';');
    hour = char2num(str + 11, ';');
    min = char2num(str + 14, ';');
    temp = char2num(str + 17, ';');
   // if(temp!=TEMP_ERROR){
      add_record(dt->measure, meas_cntr, year, month, day, hour, min, temp);
      dt->meas_amount = meas_cntr++;
    // } else{
    //   printf("String %d data format not supported\n",meas_cntr);
    // }
    cntr = 0;
    clear_string(str);
  }

  fclose(rd);
}