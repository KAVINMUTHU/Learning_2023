#include <stdio.h>

unsigned char set_bit(unsigned char num, int position)
{
    unsigned char mask = 1 << position;
    return num | mask;
}

unsigned char clear_bit(unsigned char num, int position)
{
    unsigned char mask = ~(1 << position);
    return num & mask;
}

unsigned char toggle_bit(unsigned char num, int position)
{
    unsigned char mask = 1 << position;
    return num ^ mask;
}

int main()
{
    unsigned char num = 0x57; // Example value

    // Set bit at position 3
    unsigned char set_result = set_bit(num, 3);
    printf("After setting bit: 0x%02X\n", set_result);

    // Clear bit at position 6
    unsigned char clear_result = clear_bit(num, 6);
    printf("After clearing bit: 0x%02X\n", clear_result);

    // Toggle bit at position 2
    unsigned char toggle_result = toggle_bit(num, 2);
    printf("After toggling bit: 0x%02X\n", toggle_result);

    return 0;
}
