#include "temp_api.h"
#include <stdint.h>

// 1)читаем из файла
// 2)получаем задачу:либо инфа за месяц, либо инфа за год
// 3)если за год, то ищем данные  месяца, закидываем в отдельную структуру,
// производим манипуляции, выводим(так для каждого месяца) 
// 4) если за месяц, то находим данные за него, производим вычисления, выводим

//для отладки
char csvfile_name[] = "temperature_small.csv";
char csvbigfile_name[] = "temperature_big.csv";

//заголовки 
char stat_month[]="STATISTICS BY MONTH";
char stat_month_by_year[]="STATISTICS BY MONTH FOR THE YEAR";
char stat_year[]="STATISTICS FOR THE YEAR";

//структуры для хранения импортированных данных и данных за месяц
data full_data;
data_month m_data;

const char month_name[12][10] = {
    "January", "February", "March",     "April",   "May",      "June",
    "July",    "August",   "September", "October", "November", "December"};



// функция перестановки местами структур как элементов массива типа record
void swap(record *dt, uint32_t i, uint32_t j) {
  record temp;
  temp = *(dt + i);
  *(dt + i) = *(dt + j);
  *(dt + j) = temp;
}

// упорядочиваем данные в массиве структур типа data_month по возрастанию
// температуры
void sortByTemp(data_month *dt) {
  for (uint32_t i = 0; i < dt->meas_month; ++i)
    for (uint32_t j = i; j < dt->meas_month; ++j)
      if (dt->measure_month[i].temp >= dt->measure_month[j].temp)
        swap(dt->measure_month, i, j);
}

uint64_t encode_date(record *dt) {
  return (uint64_t)dt->year << 32 | (uint32_t)dt->month << 24 |
         (uint32_t)dt->day << 16 | (uint32_t)dt->hour << 8 | dt->min;
}

// упорядочиваем данные в массиве структур типаdata_month по возрастанию даты
void sortByDate(data_month *dt) {
  for (uint32_t i = 0; i < dt->meas_month; ++i)
    for (uint32_t j = i; j < dt->meas_month; ++j)
      if (encode_date(dt->measure_month + i) >=
          encode_date(dt->measure_month + j))
        swap(dt->measure_month, i, j);
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

void clear_record(record *dt, uint32_t num_meas) {
  dt[num_meas].year = 0;
  dt[num_meas].month = 0;
  dt[num_meas].day = 0;
  dt[num_meas].hour = 0;
  dt[num_meas].min = 0;
  dt[num_meas].temp = 0;
}

void clear_month_data(data_month *dt){
  for (uint16_t i = 0; i < dt->meas_month; i++) {
      clear_record(dt->measure_month, i);
    }
    dt->meas_month = 0;
}

// забираем данные за месяц из импортированного .csv файла
void get_month_data(data *dt_source, data_month *dt_dest,
                    uint8_t month_number) {
  uint32_t num_records = 0; // счетчик для замеров за отдельно взятый месяц
  for (uint32_t i = 0; i < dt_source->meas_amount; i++) {
    if (month_number == dt_source->measure[i].month) {
      dt_dest->measure_month[num_records] = dt_source->measure[i];
      num_records++;
    }
  }
  dt_dest->meas_month = num_records;
}

// функция расчета средней температуры в отдельно взятом месяце
float month_average_temp(data_month *dt) {
  int16_t result = 0;
  for (uint16_t i = 0; i < dt->meas_month; i++) {
    result += dt->measure_month[i].temp;
  }
  return (float)result / dt->meas_month;
}


/*дурные функции, постоянно заставляющие сортировать огромные массивы данных*/
int8_t month_min_temp(data_month *dt) {
  sortByTemp(dt);
  return dt->measure_month[0].temp;
}

int8_t month_max_temp(data_month *dt) {
  sortByTemp(dt);
  return dt->measure_month[dt->meas_month - 1].temp;
}
/* ************************************************************************** */


int8_t year_average_temp(data *dt) {
  int16_t result = 0;
  for (uint8_t i = 0; i < dt->meas_amount; i++) {
    result += dt->measure[i].temp;
  }
  return result / dt->meas_amount;
}

void print_title(void) {
  printf("%-8s %-12s %-16s %-8s %11s\n","year", "month", "average_temp", "min_temp",
         "max_temp");
  printf("-----   ----------    ------------    ----------  ----------\n");
}

void print_title_name(char *title_name){
printf("\n====================%s====================\n\n",title_name);
}

void print_month_data(data_month *dt_dest,uint8_t num_month,float average){
  printf("%-8d %-15s %0.1f%-14s %d%-10s %d%s\n",dt_dest->measure_month[0].year, month_name[num_month - 1],
          average, "°C",  dt_dest->measure_month[0].temp,
         "°C", dt_dest->measure_month[dt_dest->meas_month - 1].temp,
         "°C");
}

void print_year_data(float avg,int8_t max,int8_t min){
  printf("%-15s %-10s %s\n", "average_temp", "min_temp", "max_temp");
  printf("-------------  ---------  --------\n");
  printf("%s %0.1f%s%s %d%s%s %d%s\n\n", "   ", avg / 12, "°C", "       ",
       min, "°C", "      ", max, "°C");
}

void print_month_info(data *dt_source, data_month *dt_dest, uint8_t num_month) {
  float av = 0;
  if(num_month>12||num_month<1){
    printf("\nPlease enter the correct month\n\n");
    return;
  }
  get_month_data(dt_source, dt_dest,
                 num_month); // забрал данные из импортированного .csv файла
  av = month_average_temp(dt_dest);
  sortByTemp(dt_dest);
  print_title_name(stat_month);
  print_title();
  print_month_data(dt_dest, num_month, av);
  printf("\n");
}

void print_yearstat_info(data *dt_source, data_month *dt_dest) {
  int8_t year_max=0,year_min=0;
  float year_avg=0;
  print_title_name(stat_month_by_year);
  print_title();
  for (uint8_t j = 1; j <= 12; j++) {
    float av = 0;
    get_month_data(dt_source, dt_dest,
                   j); // забрал данные за искомый месяц из импортированного .csv файла
    sortByTemp(dt_dest);       
    av = month_average_temp(dt_dest);//посчитал среднюю температуру
    year_min=dt_dest->measure_month[0].temp; //после сортировки минимальная температура по месяцу в нулевом элементе массива структур
    print_month_data(dt_dest, j, av);
    year_max<dt_dest->measure_month[dt_dest->meas_month - 1].temp?year_max=dt_dest->measure_month[dt_dest->meas_month - 1].temp:year_max;
    year_min>dt_dest->measure_month[0].temp?year_min=dt_dest->measure_month[0].temp:year_min;
    year_avg+=av;
    clear_month_data(dt_dest); //на свякий случай чистим структуру от данных только что выведенного на эран месяца(может помочь при выводе статистики всех месяцев подряд)
  }
  print_title_name(stat_year);
  print_year_data(year_avg,year_max,year_min);
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

// НАДО ПРИДУМАТЬ,КАК НАЙТИ КОСЯЧНУЮ СТРОКУ
int32_t char2num(char *p, char stop_symb) {
  int32_t num = 0;
  uint8_t negative = 0;
  while (*p != stop_symb && *p != '\n'&& *p != '\r' && *p != '\000') {
    *p!=' '?p:p++;   //проверил, нет ли случаем пробелов перед значащим символом
    if (*p == '-') { //если минус, то поднимаем флаг отрицательного числа
      negative = 1;
      p++;
    } else if (*p >= '0' && *p <= '9') { //из символов в число
      num = num * 10 + (*p - '0');
      p++;
    } else {   //если какие-то иные символы, то возвращаем ошибку
      p++;
       return DATA_ERROR;
    }
  }
  return negative ? -num : num;
}

void clear_string(char *string) {
  for (uint8_t i = 0; i < STRING_LENTH; i++) {
    *(string + i) = 0;
  }
}

uint8_t read_data(data *dt, char *csv_name) {
  uint32_t meas_cntr = 0;
  uint16_t year = 0;
  uint8_t month = 0,day = 0,hour = 0,min = 0,endoffile = 1;
  int8_t temp = 0;
  char str[STRING_LENTH] = ""; 
  uint32_t cntr = 0;
  FILE *rd = fopen(csv_name, "rb");
  if (rd == NULL) {
    printf("\nAchtung!Read error or unknown option!\n\n");
    return ERROR;
  }
  //fread возвращает 0, когда достигнут конец файла
  //здесь читаю посимвольно каждую строку и пишу в str
  //возможно, нужно уйти от жесткой привязки длины строки с помощью дефайна STRING_LENTH
  while (endoffile) {
    while (endoffile && *(str + cntr - 1) != '\n') {
      endoffile = fread(str + cntr, 1, 1, rd);
      cntr++;
    }
    //разбираю получившуюся строку на запчасти
    year = char2num(str, ';');
    month = char2num(str + 5, ';');
    day = char2num(str + 8, ';');
    hour = char2num(str + 11, ';');
    min = char2num(str + 14, ';');
    temp = char2num(str + 17, ';');
     if(temp!=DATA_ERROR){
    add_record(dt->measure, meas_cntr, year, month, day, hour, min, temp);
    dt->meas_amount = ++meas_cntr;
     } else{
       printf("String %d data format not supported\n",meas_cntr);
     }
    cntr = 0;
    clear_string(str);
  }

  fclose(rd);
  return SUCCESS;
}