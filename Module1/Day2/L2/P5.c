/// Write a program to encode any given string such that it gets converted into an unrecognizable form.
/// Also write a decode function to get back the original string.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to encode the string
char *encodeString(const char *str, int key)
{
    int length = strlen(str);
    char *encodedStr = (char *)malloc((length + 1) * sizeof(char));

    for (int i = 0; i < length; i++)
    {
        encodedStr[i] = str[i] + key;
    }
    encodedStr[length] = '\0';

    return encodedStr;
}

// Function to decode the encoded string
char *decodeString(const char *encodedStr, int key)
{
    int length = strlen(encodedStr);
    char *decodedStr = (char *)malloc((length + 1) * sizeof(char));

    for (int i = 0; i < length; i++)
    {
        decodedStr[i] = encodedStr[i] - key;
    }
    decodedStr[length] = '\0';

    return decodedStr;
}

int main()
{
    const char *originalStr = "Hello, World!";
    int key = 5;

    printf("Original String: %s\n", originalStr);

    // Encoding the string
    char *encodedStr = encodeString(originalStr, key);
    printf("Encoded String: %s\n", encodedStr);

    // Decoding the encoded string
    char *decodedStr = decodeString(encodedStr, key);
    printf("Decoded String: %s\n", decodedStr);

    free(encodedStr);
    free(decodedStr);

    return 0;
}
