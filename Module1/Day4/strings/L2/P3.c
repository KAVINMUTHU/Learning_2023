#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isAlphanumeric(char ch)
{
    return isalnum(ch) || ch == '.';
}

int isLowercaseAlphabet(char ch)
{
    return islower(ch);
}

int validateEmail(const char *email)
{
    int length = strlen(email);
    int atIndex = -1;
    int dotIndex = -1;
    int i;

    // Check if the email has at least one '@' character and one '.' character
    for (i = 0; i < length; i++)
    {
        if (email[i] == '@')
        {
            atIndex = i;
        }
        else if (email[i] == '.')
        {
            dotIndex = i;
        }
    }

    if (atIndex == -1 || dotIndex == -1)
    {
        return 0; // Email format is invalid
    }

    // Check the username part
    for (i = 0; i < atIndex; i++)
    {
        if (!isAlphanumeric(email[i]))
        {
            return 0; // Email format is invalid
        }
    }

    // Check the domain name part
    for (i = atIndex + 1; i < dotIndex; i++)
    {
        if (!isLowercaseAlphabet(email[i]))
        {
            return 0; // Email format is invalid
        }
    }

    // Check the extension part
    for (i = dotIndex + 1; i < length; i++)
    {
        if (!isLowercaseAlphabet(email[i]))
        {
            return 0; // Email format is invalid
        }
    }

    return 1; // Email format is valid
}

int main()
{
    const char *email = "test@example.com";

    if (validateEmail(email))
    {
        printf("Email is valid\n");
    }
    else
    {
        printf("Email is invalid\n");
    }

    return 0;
}
