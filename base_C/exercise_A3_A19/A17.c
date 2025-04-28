//Ввести номер месяца и вывести название времени года.

#include <stdio.h>
#include <stdint.h>

#define ERROR         1
#define SUCCESS       0

uint32_t month_num=0;

int main(void) {
    scanf("%u",&month_num);
    if(month_num<1||month_num>12) return ERROR;
    switch( month_num) {
    case 1:
    case 2:
    case 12:
        printf("winter");
        break;
    case 3:
    case 4:
    case 5:
        printf("spring");
        break;
    case 6:
    case 7:
    case 8:
        printf("summer");
        break;
    case 9:
    case 10:
    case 11:
        printf("autumn");
        break;
    }
    return SUCCESS;
}
