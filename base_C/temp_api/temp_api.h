#ifndef temp_api_h
#define temp_api_h

#include <stdint.h>
#include <stdio.h>

#define NUM_MEAS    6  

enum{
  january=1,
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



enum mode{
  readFromFile=0,
  writeToFile
};

 typedef struct {
  uint16_t year;
  uint8_t month;
  uint8_t day;
  uint8_t hour;
  uint8_t min;
  int8_t temp;
}record;


typedef struct {
    uint8_t meas_amount;
    record measure[NUM_MEAS];
}data;


extern  data jan, feb, mar, apr, my, jun, jul, aug, sept, oct, nov, dec;
extern char csvfile_name[];
extern const char frame_month[][50];
extern enum mode md;

void print_frame(const char *frame, uint8_t num_strings, uint8_t stringsize);

void add_info(record *dt_source, record *dt_dest, uint32_t num_records);
void print_records(record *dt, uint32_t num_records);
void print_month_info(uint8_t month);//вывод средней, максимальной и минимальной температур
void print_year_info(void);          //вывод средней, максимальной и минимальной температур за весь год по месяцам
void print_yearstat_info(void);      //вывод средней, максимальной и минимальной температур за год за все месяцы


int8_t month_average_temp(record *dt, uint32_t num_meas);
int8_t month_min_temp(record *dt, uint32_t num_meas);
int8_t month_max_temp(record *dt, uint32_t num_meas);
data* get_month(uint8_t num_month);

void year_stat(record *dt);

void add_year_info(record *dt_source, data *dt_dest, uint8_t month_number,
                   uint32_t num_records);
#endif