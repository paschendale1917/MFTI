#ifndef temp_api_h
#define temp_api_h

#include <stdint.h>
#include <stdio.h>

#define NUM_MEAS    16   

enum{
  January=1,
  February,
  March,
  April,
  May,
  June,
  July,
  August,
  September,
  October,
  November,
  December
};

enum mode{
  read=0,
  write
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
    uint32_t meas_cntr;
    record measure[NUM_MEAS];
}data;


extern  data dt;
extern char binfile_name[];
extern enum mode md;

int16_t month_average_temp(record *dt, uint32_t num_meas);
void month_min_temp(record *dt);
void month_max_temp(record *dt);
void year_stat(record *dt);


#endif