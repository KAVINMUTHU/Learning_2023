#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void copyFile(FILE *source, FILE *destination, int handleCase)
{
    char c;

    while ((c = fgetc(source)) != EOF)
    {
        if (handleCase == 1)
        {
            fputc(toupper(c), destination);
        }
        else if (handleCase == 2)
        {
            fputc(tolower(c), destination);
        }
        else if (handleCase == 3)
        {
            if (islower(c))
            {
                fputc(toupper(c), destination);
            }
            else
            {
                fputc(c, destination);
            }
        }
        else
        {
            fputc(c, destination);
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Insufficient arguments.\n");
        printf("Usage: ./cp <option> <source_file> <destination_file>\n");
        printf("Options:\n");
        printf("-u : Change file content to Upper Case\n");
        printf("-l : Change file content to Lower Case\n");
        printf("-s : Change file content to Purely Upper Case\n");
        printf("No option: Perform normal copy\n");
        return 1;
    }

    char *option = argv[1];
    char *sourceFile = argv[2];
    char *destinationFile = argv[3];

    FILE *source = fopen(sourceFile, "r");
    if (source == NULL)
    {
        printf("Error opening source file.\n");
        return 1;
    }

    FILE *destination = fopen(destinationFile, "w");
    if (destination == NULL)
    {
        printf("Error creating destination file.\n");
        fclose(source);
        return 1;
    }

    int handleCase = 0; // 0: Normal copy, 1: Upper case, 2: Lower case, 3: Purely upper case

    if (strcmp(option, "-u") == 0)
    {
        handleCase = 1;
    }
    else if (strcmp(option, "-l") == 0)
    {
        handleCase = 2;
    }
    else if (strcmp(option, "-s") == 0)
    {
        handleCase = 3;
    }

    copyFile(source, destination, handleCase);

    printf("File copied successfully.\n");

    fclose(source);
    fclose(destination);

    return 0;
}
