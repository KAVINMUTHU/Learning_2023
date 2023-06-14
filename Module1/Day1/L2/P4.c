#include <stdio.h>

int bit_operations(int num, int oper_type, int pos)
{
    int result;

    switch (oper_type)
    {
    case 1:
        // Set 2 bits from nth bit position
        result = num | (0x3 << pos);
        break;
    case 2:
        // Clear 3 bits from nth bit position
        result = num & ~(0x7 << pos);
        break;
    case 3:
        // Toggle MSB
        result = num ^ (1 << 31);
        break;
    default:
        printf("Invalid operation type\n");
        result = num; // Return the original number if operation type is invalid
        break;
    }

    return result;
}

int main()
{
    int num, oper_type, pos;

    printf("Enter an integer: ");
    scanf("%d", &num);

    printf("Enter the operation type (1: Set bits, 2: Clear bits, 3: Toggle MSB): ");
    scanf("%d", &oper_type);

    printf("Enter the bit position: ");
    scanf("%d", &pos);

    int result = bit_operations(num, oper_type, pos);

    printf("Result: %d\n", result);

    return 0;
}