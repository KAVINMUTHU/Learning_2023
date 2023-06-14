// prints the exponent part of a double variable in hexadecimal and binary format using pointers and bitwise operators:
#include <stdio.h>

void printExponent(double num)
{
    unsigned long long *ptr = (unsigned long long *)&num;
    unsigned long long exponent = (*ptr >> 52) & 0x7FF;

    printf("Hexadecimal: 0x%llx\n", exponent);

    printf("Binary: 0b");
    for (int i = 11; i >= 0; i--)
    {
        unsigned long long bit = (exponent >> i) & 1;
        printf("%llu", bit);
    }
    printf("\n");
}

int main()
{
    double x = 0.7;
    printExponent(x);

    return 0;
}
