#include "temp_api.h"
#include <stdint.h>
#include <stdio.h>


record june_meas[NUM_MEAS]={2025,June,20,19,35,26,
                            2025,June,20,19,36,26,
                            2025,June,20,19,37,27,
                            2025,June,20,19,38,26,
                            2025,June,20,19,39,25,
                            2025,June,20,19,40,29,
};


int main(void) {
  printf("%s", "It's alive!\n");
  printf("%d\n", NUM_MEAS);
  printf("%s: %d\n", "Average", month_average_temp(june_meas, NUM_MEAS));
  return 0;
}