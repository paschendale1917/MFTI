//В файле input.txt дана строка. Вывести ее в файл output.txt три раза через запятую и показать количество символов в ней. 

#include <stdio.h>
#include <stdint.h>
//#include <string.h>

#define STRING_LENTH        100
#define NUM_REPETITIONS     3

FILE *file;
char *file_in="input.txt";                              //указатель на файл,хранящий символы
char *file_out="output.txt";                            //указатель на файл, куда будем писать итог
char string[STRING_LENTH]="";                           //строка, куда будем копировать символы из файла
uint8_t count=0;
char n=0;

int main(void){
file=fopen(file_in,"r");                 //открываем файл на чтение
while((n=getc(file))!=EOF&&n!='\n'){
    string[count]=n;
    count++;
}
fclose(file);
file=fopen(file_out,"w");
for(uint8_t i=0;i<NUM_REPETITIONS;i++){
  fprintf(file,"%s", string);
  if(i<2){
  fprintf(file,", ");
  }
}
fprintf(file," %d", count);
fclose(file);
return 0;
}