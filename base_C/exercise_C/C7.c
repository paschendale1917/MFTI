// // Составить функцию, которая переводит число N из десятичной системы счисления в P-ичную систему счисления. Два целых числа. N ≥ 0 и 2 ≤ P ≤ 9

// #include <stdio.h>
// #include <stdlib.h>
// #include <stdint.h>

// uint32_t num = 0;
// uint8_t base = 0;

// uint32_t transfer(uint32_t n, uint8_t p);
// uint32_t fromDecimal(uint32_t decimal, uint8_t base);

// int main(void)
// {
//     scanf("%u %u", &num, &base);
//     printf("%u", transfer(num, base));
//     return 0;
// }

// uint32_t transfer(uint32_t n, uint8_t p)
// {
//     uint32_t temp = 0;
//     uint32_t digit = 1;
//     uint32_t result = 0;
//     if (!n)
//         return 0;
//     while (n)
//     {
//         result += digit * (n % p);
//         n /= p;
//         digit *= 10;
//     }
//     return result;
// }

//Составить функцию, которая переводит число N из десятичной системы счисления в P-ичную систему счисления. Два целых числа. N ≥ 0 и 2 ≤ P ≤ 9

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <inttypes.h>

uint32_t num = 0;
uint8_t base = 0;
uint8_t cntr = 0;

int32_t transfer(uint32_t n, uint8_t p);

int main(void)
{
    scanf("%u%hhu", &num, &base);


    printf("%d\n", transfer(num, base));
    return 0;
}


int32_t transfer(uint32_t n, uint8_t p)
{
    uint8_t temp = num;
    int32_t result = 0;
      while (temp)
    {
         temp /= p;
         cntr++;
    }
    for(int8_t i=0;i<cntr;i++)
    {
        temp = num;
        num /= p;
        result=result+pow(10,i)*(temp - p * num);
    
    }
    return result;
}


