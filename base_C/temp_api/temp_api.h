#ifndef temp_api_h
#define temp_api_h

#include <stdint.h>
#include <stdio.h>

///#define DEBUG

#define NUM_MEAS_PER_MONTH  31*24*60 //максимальное количество замеров для каждого месяца
#define STRING_LENTH        22 // длина строки с одним блоком данных, включая перенос строки и возврата каретки
#define DATA_ERROR          -127 // маркировка ошибки
#define ERROR               1
#define SUCCESS             0

#ifdef  DEBUG 
  #define NUM_MEAS            100
#else
  #define NUM_MEAS            365*NUM_MEAS_PER_MONTH ///максимальное количество замеров за год, под которые мы отведем для хранения импортированных блоков данных из .csv файла
#endif

enum {
  january = 1,
  february,
  march,
  april,
  may,
  june,
  july,
  august,
  september,
  october,
  november,
  december
};

enum mode { readFromFile = 0, writeToFile };

typedef struct {
  uint16_t year;
  uint8_t month;
  uint8_t day;
  uint8_t hour;
  uint8_t min;
  int8_t temp;
} record;

typedef struct {
  uint32_t meas_amount;
  record measure[(uint32_t)NUM_MEAS];
} data;

typedef struct {
  uint32_t meas_month;
  record measure_month[(uint32_t)NUM_MEAS_PER_MONTH];
} data_month;


 extern data full_data;
 extern data_month m_data;

extern char csvfile_name[];
extern char csvbigfile_name[];
extern enum mode md;


int32_t char2num(char *p, char stop_symb);
uint8_t read_data(data *dt, char *csv_name);  //читаем из csv файла
void get_month_data(data *dt_source, data_month *dt_dest, uint8_t month_number); //забираем данные из считанной струтуры для отдельного месяца
float month_average_temp(data_month *dt); //ищем среднюю температуру по текущему месяцу
int8_t month_min_temp(data_month *dt);     //ищем минимальную температуру
 void print_month_info(data *dt,data_month *dt_dest,uint8_t num_month);
 void print_yearstat_info(data *dt_source, data_month *dt_dest);
#endif