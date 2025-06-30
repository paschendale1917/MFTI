#include "temp_api.h"
#include <stdint.h>
#include <stdio.h>
// #include <string.h>
//  #include <unistd.h>



char *version = "ver1.1";

data full_data;
//record meas[NUM_MEAS] = {0};



void print_help(void) {
  printf("\nThis is a simple temperature statistic program %s\n", version);
  printf("Supported arguments:\n");
  printf("-h                      -- help\n");
  printf("-f<filename.csv>        -- .csv file to load\n");
  printf("-m<month>               -- month to view statistics. without <month> argument  will show statistics by month for the year\n");
  printf("-y                      -- year average, minimum and maximum temperature\n");
  printf("-v                      -- version\n");
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
        p++;
        char2num(p, '\000') < 1 || char2num(p, '\000') > 12
            ? printf("Unknown option: %s\n", argv[i])
        : *p == '\000' ? print_year_info()
                       : print_month_info(char2num(p, '\000'));
        break;
      case 'y':
        print_yearstat_info();
        break;
      case 'f':
        p++;
       // read_data(&full_data, csvbigfile_name );
        break;
      default:
        printf("Unknown option: %s", argv[i]);
        break;
      }
    } else if (argc < 2) {
      print_help();
    }
  }
}



int main(int32_t argc, char *argv[]) {
  args(argc, argv);
 read_data(&full_data, csvbigfile_name );

  return 0;
}