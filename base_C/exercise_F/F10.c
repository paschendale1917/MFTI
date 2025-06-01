// Дана строка состоящая из маленьких латинских букв 'a'..'z'. В конце строки
// точка. Необходимо заменить повторяющиеся буквы на <буква><количество
// повторений>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

#define AMOUNT 1000

char unpacked[AMOUNT] = "";
uint16_t packed[AMOUNT] = {0};
uint16_t size_packed = 0;

uint16_t char_counter(char *buf_unpacked, uint16_t *buf_packed,
                      uint16_t size_unpacked);

int main(void) {

  scanf("%[^.]", unpacked);
  size_packed = char_counter(unpacked, packed, strlen((unpacked)));
  for (int i = 0; i < size_packed; i++) {
    printf("%c%d", *(packed + i) >> 8, (uint8_t)*(packed + i));
  }

  return 0;
}

uint16_t char_counter(char *buf_unpacked, uint16_t *buf_packed, uint16_t sz_unpacked) {
  uint16_t cntr = sz_unpacked;
  uint16_t repetition = 1;
  uint16_t packed_cntr = 0;
  do {
    if (*(buf_unpacked + sz_unpacked - cntr) == *(buf_unpacked + sz_unpacked - cntr + 1) && (cntr - 1)) {
      repetition++;
      cntr--;
    } else {
      *(buf_packed + packed_cntr) = *(buf_unpacked + sz_unpacked - cntr) << 8 | repetition;
      repetition = 1;
      packed_cntr++;
      cntr--;
    }
  } while (cntr);

  return packed_cntr;
}
