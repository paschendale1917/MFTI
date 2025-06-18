#include "temp_api.h"
#include <stdint.h>
//#include <string.h>

char binfile_name[] = "temperature_small.csv";



int16_t month_average_temp(record *dt, uint32_t num_meas) {
  int16_t result = 0;
  uint8_t real_meas=0;
  for (uint8_t i = 0; i < num_meas; i++) {
    result += (dt + i)->temp;
    (dt + i)->temp?real_meas++:real_meas;
  }
  return result/real_meas;
}

//*dt-указатель на структуру, num_meas - номер замера, далее поля структуры
// void AddRecord(record *dt,uint8_t num_meas ,uint16_t year,uint8_t month,uint8_t day,int8_t temp){ 
//     (dt+num_meas)->year = year;
//     (dt+num_meas)->month = month;
//     (dt+num_meas)->day = day;
//     (dt+num_meas)->temp = temp;
// }

//чтение/запись из файла
// void rw_data (data *dt, uint32_t num_meas, char *bin_name, uint8_t mode)
// {
//     switch(mode){
//       case read:
//         FILE* rd = fopen(bin_name,"rb");
//         fread(&(dt->measure),sizeof(dt->measure),1,rd);
//         fclose(rd);
//         break;
//       case write:
//         FILE* wr = fopen(bin_name,"wb");
//         fwrite(&(dt->measure),num_meas*sizeof(dt->measure),1,wr);
//         fclose(wr);
//         break;
//     }
    
}