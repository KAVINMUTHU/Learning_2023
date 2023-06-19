#include <stdio.h>

// Function to convert decimal to binary recursively
void decimalToBinaryRecursive(int decimal)
{
    if (decimal > 0)
    {
        decimalToBinaryRecursive(decimal / 2);
        printf("%d", decimal % 2);
    }
}

// Function to convert decimal to octal recursively
void decimalToOctalRecursive(int decimal)
{
    if (decimal > 0)
    {
        decimalToOctalRecursive(decimal / 8);
        printf("%d", decimal % 8);
    }
}

// Function to convert decimal to hexadecimal recursively
void decimalToHexadecimalRecursive(int decimal)
{
    if (decimal > 0)
    {
        decimalToHexadecimalRecursive(decimal / 16);
        int remainder = decimal % 16;
        if (remainder < 10)
        {
            printf("%d", remainder);
        }
        else
        {
            printf("%c", remainder + 'A' - 10);
        }
    }
}

int main()
{
    int decimal;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    printf("Binary: ");
    decimalToBinaryRecursive(decimal);
    printf("\n");

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    printf("Octal: ");
    decimalToOctalRecursive(decimal);
    printf("\n");

    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    printf("Hexadecimal: ");
    decimalToHexadecimalRecursive(decimal);
    printf("\n");

    return 0;
}
