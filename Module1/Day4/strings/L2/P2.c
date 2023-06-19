#include <stdio.h>
#include <string.h>

void rotateString(char *str, int rotation)
{
    int length = strlen(str);
    int offset = rotation % length;

    char rotatedString[length + 1];
    int j = 0;

    // Rotate left
    if (rotation < 0)
    {
        // Calculate the positive offset for left rotation
        offset = length - (-rotation % length);
    }

    // Copy characters from the offset to the end of the original string
    for (int i = offset; i < length; i++)
    {
        rotatedString[j++] = str[i];
    }

    // Copy characters from the beginning to the offset of the original string
    for (int i = 0; i < offset; i++)
    {
        rotatedString[j++] = str[i];
    }

    // Null-terminate the rotated string
    rotatedString[j] = '\0';

    // Copy the rotated string back to the original string
    strcpy(str, rotatedString);
}

int main()
{
    char str[] = "Hello, World!";
    int rotation = 3;

    printf("Original string: %s\n", str);

    rotateString(str, rotation);
    printf("Rotated right string: %s\n", str);

    rotation = -2;
    rotateString(str, rotation);
    printf("Rotated left string: %s\n", str);

    return 0;
}
