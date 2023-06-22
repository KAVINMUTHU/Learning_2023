#include <stdio.h>

#define BUFFER_SIZE 4096

int main()
{
    FILE *sourceFile, *destinationFile;
    char sourceFileName[100], destinationFileName[100];
    char buffer[BUFFER_SIZE];
    size_t bytesRead;

    // Input file name
    printf("Enter the source file name: ");
    scanf("%s", sourceFileName);

    // Open source file
    sourceFile = fopen(sourceFileName, "rb");
    if (sourceFile == NULL)
    {
        printf("Unable to open source file.\n");
        return 1;
    }

    // Input destination file name
    printf("Enter the destination file name: ");
    scanf("%s", destinationFileName);

    // Open destination file
    destinationFile = fopen(destinationFileName, "wb");
    if (destinationFile == NULL)
    {
        printf("Unable to create destination file.\n");
        fclose(sourceFile);
        return 1;
    }

    // Copy content from source to destination file
    while ((bytesRead = fread(buffer, 1, BUFFER_SIZE, sourceFile)) > 0)
    {
        fwrite(buffer, 1, bytesRead, destinationFile);
    }

    printf("File copied successfully.\n");

    // Close files
    fclose(sourceFile);
    fclose(destinationFile);

    return 0;
}
