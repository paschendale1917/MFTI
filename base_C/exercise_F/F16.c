// Известно, что шахматная доска имеет размерность 8х8 и состоит из клеток 2х
// цветов, например, черного и белого (см. рисунок). Каждая клетка имеет
// координату, состоящую из буквы и цифры. Горизонтальное расположение клетки
// определяется буквой от A до H, а вертикальное – цифрой от 1 до 8. Заметим,
// что клетка с координатой А1 имеет черный цвет. Требуется по заданной
// координате определить цвет клетки.


#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>

#define WHITE 0
#define BLACK 1

char str[2] = "";
uint8_t arr[8][8] = {
    {BLACK, WHITE, BLACK, WHITE, BLACK, WHITE, BLACK, WHITE},
    {WHITE, BLACK, WHITE, BLACK, WHITE, BLACK, WHITE, BLACK},
    {BLACK, WHITE, BLACK, WHITE, BLACK, WHITE, BLACK, WHITE},
    {WHITE, BLACK, WHITE, BLACK, WHITE, BLACK, WHITE, BLACK},
    {BLACK, WHITE, BLACK, WHITE, BLACK, WHITE, BLACK, WHITE},
    {WHITE, BLACK, WHITE, BLACK, WHITE, BLACK, WHITE, BLACK},
    {BLACK, WHITE, BLACK, WHITE, BLACK, WHITE, BLACK, WHITE},
    {WHITE, BLACK, WHITE, BLACK, WHITE, BLACK, WHITE, BLACK},
};

uint16_t string_parser(char *string);

int main(void) {

  scanf("%s", str);
  arr[string_parser(str)>>8][(uint8_t)string_parser(str)]?printf("BLACK"):printf("WHITE");
  return 0;
}

uint16_t string_parser(char *string) {
  uint8_t cntr = 0;
  uint8_t x_coord = 0;
  uint8_t y_coord = 0;
  while (*(string + cntr)) {
    *(string + cntr) >= '1' && *(string + cntr) <= '8'? y_coord = *(string + cntr) - '1'  : y_coord;
    *(string + cntr) >= 'A' && *(string + cntr) <= 'H'? x_coord = *(string + cntr) - 'A' : x_coord;
    cntr++;
  }
  return (uint16_t)x_coord << 8 | y_coord;
}
