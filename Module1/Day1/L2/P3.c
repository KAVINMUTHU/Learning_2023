#include <stdio.h>

int isVowel(char ch)
{
    int isVowel = 0; // Initialize isVowel as 0

    switch (ch)
    {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
        isVowel = 1; // Set isVowel to 1 if character is a vowel
        break;
    default:
        isVowel = 0; // Set isVowel to 0 if character is not a vowel
        break;
    }

    return isVowel;
}

int main()
{
    char ch;

    printf("Enter a character: ");
    scanf("%c", &ch);

    int result = isVowel(ch);

    if (result == 1)
    {
        printf("Vowel\n");
    }
    else
    {
        printf("Not Vowel\n");
    }

    return 0;
}