#include <stdio.h>
#include <math.h>

int binaryToDecimal(char binary[], int length)
{
    if (length == 0)
    {
        return 0;
    }

    int decimal = (binary[length - 1] - '0') * pow(2, (strlen(binary) - length));

    return decimal + binaryToDecimal(binary, length - 1);
}

int octalToDecimal(int octal)
{
    if (octal == 0)
    {
        return 0;
    }

    int decimal = (octal % 10) * pow(8, 0);

    return decimal + 8 * octalToDecimal(octal / 10);
}

int hexToDecimal(char hex[], int length)
{
    if (length == 0)
    {
        return 0;
    }

    int decimal;
    if (hex[length - 1] >= '0' && hex[length - 1] <= '9')
    {
        decimal = (hex[length - 1] - '0') * pow(16, (strlen(hex) - length));
    }
    else
    {
        decimal = (hex[length - 1] - 55) * pow(16, (strlen(hex) - length));
    }

    return decimal + hexToDecimal(hex, length - 1);
}

int main()
{
    char binary[] = "11101";
    int octal = 1532;
    char hex[] = "35Z";

    int decimalFromBinary = binaryToDecimal(binary, strlen(binary));
    int decimalFromOctal = octalToDecimal(octal);
    int decimalFromHex = hexToDecimal(hex, strlen(hex));

    printf("Binary to Decimal: %d\n", decimalFromBinary);
    printf("Octal to Decimal: %d\n", decimalFromOctal);
    printf("Hexadecimal to Decimal: %d\n", decimalFromHex);

    return 0;
}
