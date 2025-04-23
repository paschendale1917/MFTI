// Ввести натуральное число вывести квадраты и кубы всех чисел от 1 до этого числа. Число не превосходит 100.

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

uint8_t num = 0;

uint16_t pow_2(uint8_t);
uint32_t pow_3(uint8_t);
uint32_t mypow(uint8_t, uint8_t);

int main(void)
{
	scanf("%u", (uint32_t *)&num);
	if (num < 1 || num > 100)
		abort();
	for (uint8_t i = 1; i <= num; i++)
	{
		printf("%d %d %d\n", i, mypow(i, 2), mypow(i, 3));
	}
}

uint16_t pow_2(uint8_t x)
{
	return x * x;
}
uint32_t pow_3(uint8_t x)
{
	return x * x * x;
}

uint32_t mypow(uint8_t a, uint8_t b)
{
	uint32_t result = a;
	for (uint8_t j = 0; j < b - 1; j++)
	{
		result *= a;
	}
	return result;
}
