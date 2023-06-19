#include <stdio.h>

int stringToInteger(const char *str)
{
    int res = 0;
    int sign = 1; // Sign of the number

    // Handle negative sign if present
    if (str[0] == '-')
    {
        sign = -1;
        str++; // Move the pointer past the negative sign
    }

    // Iterate through each character of the string
    while (*str != '\0')
    {
        // Convert character to integer value
        int ival = *str - '0';

        // Update the result by multiplying by 10 and adding the current digit
        res = res * 10 + ival;

        // Move to the next character
        str++;
    }

    return res * sign;
}

int main()
{
    const char *str = "345";

    int num = stringToInteger(str);

    printf("Integer value: %d\n", num);

    return 0;
}
