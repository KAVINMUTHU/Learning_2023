#include <stdio.h>

#define DEC_TO_BCD(decimal) (((decimal / 10) << 4) | (decimal % 10))

void decimal_to_bcd(unsigned char decimal, unsigned char *bcd_high, unsigned char *bcd_low)
{
    *bcd_high = DEC_TO_BCD(decimal / 10);
    *bcd_low = DEC_TO_BCD(decimal % 10);
}

int main()
{
    unsigned char decimal = 25; // Example decimal value
    unsigned char bcd_high, bcd_low;

    decimal_to_bcd(decimal, &bcd_high, &bcd_low);
    printf("Decimal: %d\n", decimal);
    printf("BCD High: 0x%02X\n", bcd_high);
    printf("BCD Low: 0x%02X\n", bcd_low);

    return 0;
}
