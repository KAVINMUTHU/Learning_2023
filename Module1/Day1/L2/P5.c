#include <stdio.h>

int characterType(char ch)
{
    int type;

    if (ch >= 'A' && ch <= 'Z')
    {
        type = 1; // Uppercase alphabets
    }
    else if (ch >= 'a' && ch <= 'z')
    {
        type = 2; // Lowercase alphabets
    }
    else if (ch >= '0' && ch <= '9')
    {
        type = 3; // Digits
    }
    else if (ch >= ' ' && ch <= '~')
    {
        type = 4; // Printable symbols
    }
    else
    {
        type = 5; // Non-printable symbols
    }

    return type;
}

int main()
{
    char ch;

    printf("Enter a character: ");
    scanf("%c", &ch);

    int result = characterType(ch);

    switch (result)
    {
    case 1:
        printf("Type: Uppercase Alphabet (A-Z)\n");
        break;
    case 2:
        printf("Type: Lowercase Alphabet (a-z)\n");
        break;
    case 3:
        printf("Type: Digit (0-9)\n");
        break;
    case 4:
        printf("Type: Printable Symbol\n");
        break;
    case 5:
        printf("Type: Non-Printable Symbol\n");
        break;
    default:
        printf("Invalid character\n");
        break;
    }

    return 0;
}