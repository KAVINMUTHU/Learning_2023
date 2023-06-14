/// Suppose 7 names are stored in an array of pointers names[] as shown below:
///  char *name[]={
///         "Santosh", "Amol", "Santosh Jain", "Kishore", "Rahul", "Amolkumar", "Hemant"
///           }
///   Write a program to arrange these names in alphabetical order.

#include <stdio.h>
#include <string.h>

#define NUM_NAMES 7

void sortNames(char *names[], int numNames)
{
    char *temp;

    for (int i = 0; i < numNames - 1; i++)
    {
        for (int j = i + 1; j < numNames; j++)
        {
            if (strcmp(names[i], names[j]) > 0)
            {
                temp = names[i];
                names[i] = names[j];
                names[j] = temp;
            }
        }
    }
}

int main()
{
    char *names[] = {
        "Santosh", "Amol", "Santosh Jain", "Kishore", "Rahul", "Amolkumar", "Hemant"};
    int numNames = NUM_NAMES;

    printf("Names before sorting:\n");
    for (int i = 0; i < numNames; i++)
    {
        printf("%s\n", names[i]);
    }

    sortNames(names, numNames);

    printf("\nNames after sorting:\n");
    for (int i = 0; i < numNames; i++)
    {
        printf("%s\n", names[i]);
    }

    return 0;
}
