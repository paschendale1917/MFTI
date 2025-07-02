#include "temp_api.h"
#include <stdint.h>
#include <stdio.h>
// #include <string.h>


char *version = "v1.2";
char filename[] = "";
char argum[] = "";
 uint8_t u=0;

uint8_t get_filename(char *sourse, char *dest_name) {
  char *pp = sourse;
  uint8_t t = 0;
  while (*pp != '\000' /*  && *pp != ' ' */) {
    *(dest_name + (t++)) = *(pp++);
  };
  return t;
}

void print_help(void) {
 // printf("\nThis is a simple temperature statistic program %s\n", version);
  printf("Supported arguments:\n");
  printf("-h                                 -- help\n");
  printf("-f <filename.csv> -m <month>       -- .csv file to load. without -m argument  will show statistics by month for the year\n");
  printf("-y                                 -- year average, minimum and maximum temperature\n");
  printf("-v                                 -- version\n");
}

void print_about(void) {
  printf("\n======================================================\n");
  printf("\nThis is a simple temperature statistic program (%s).\n", version);
  printf("To get help use the key -h.\n");
  printf("\n======================================================\n\n");
}

void args(int32_t argc, char *argv[]) {
  for (uint8_t i = 0; i < argc; i++) {
    char *p = argv[i];
    if (*p == '-') {
      p++;
      switch (*p) {
      case 'h':
        print_help();
        break;
      case 'v':
        printf("%s\n", version);
        break;
      case 'm':
        p+=2;
        if(!read_data(&full_data, filename)){
          print_month_info(&full_data,&m_data,char2num(p, '\000'));
        }
        break;
      case 'y':
      //  print_yearstat_info();
        break;
      case 'f':
      uint8_t t=0;
       p+=2;
       t=get_filename(p, filename);
       read_data(&full_data, filename);
       if(*(p+t+1)!='-'){
        print_yearstat_info(&full_data, &m_data);  
       }        
        break;
      default:
        printf("Unknown option: %s\n", argv[i]);
        break;
      }
    } else if (argc < 2) {
      print_about();
    }
  }
}

int main(int32_t argc, char *argv[]) {
  args(argc, argv);
  read_data(&full_data, csvbigfile_name);
   //print_yearstat_info(&full_data, &m_data); 
  //printf("%s\n", filename);
 // printf("%s\n%d\n", arg, u);
  // read_data(&full_data, csvbigfile_name );
 //  print_month_info(&full_data,&m_data, january);
  // print_yearstat_info(&full_data, &m_data);
   //get_month_data(&full_data, january);
  // int8_t av = month_average_temp(&m_data);
 // printf("%s\n%s\n%d\n", name, arg, full_data.meas_amount);
  // printf("%d",m_data.measure_month[43199].min);
  //print_month_info(6);
  return 0;
}