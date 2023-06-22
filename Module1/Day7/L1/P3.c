#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ENTRIES 100
#define MAX_LINE_LENGTH 1024

typedef struct
{
    int entryNo;
    char sensorNo[10];
    float temperature;
    int humidity;
    int light;
    char timestamp[10];
} LogEntry;

void extractLogEntries(FILE *file, LogEntry logEntries[], int *numEntries)
{
    char line[MAX_LINE_LENGTH];
    char *token;
    int lineNum = 0;

    // Read each line of the CSV file
    while (fgets(line, sizeof(line), file))
    {
        lineNum++;

        // Skip empty lines or lines starting with a comment character
        if (line[0] == '\n' || line[0] == '#')
            continue;

        // Extract data from the line using comma as the delimiter
        token = strtok(line, ",");
        if (token == NULL)
        {
            fprintf(stderr, "Error parsing line %d\n", lineNum);
            continue;
        }

        // Store data in the logEntries array
        logEntries[*numEntries].entryNo = atoi(token);

        token = strtok(NULL, ",");
        if (token == NULL)
        {
            fprintf(stderr, "Error parsing line %d\n", lineNum);
            continue;
        }
        strncpy(logEntries[*numEntries].sensorNo, token, sizeof(logEntries[*numEntries].sensorNo));

        token = strtok(NULL, ",");
        if (token == NULL)
        {
            fprintf(stderr, "Error parsing line %d\n", lineNum);
            continue;
        }
        logEntries[*numEntries].temperature = atof(token);

        token = strtok(NULL, ",");
        if (token == NULL)
        {
            fprintf(stderr, "Error parsing line %d\n", lineNum);
            continue;
        }
        logEntries[*numEntries].humidity = atoi(token);

        token = strtok(NULL, ",");
        if (token == NULL)
        {
            fprintf(stderr, "Error parsing line %d\n", lineNum);
            continue;
        }
        logEntries[*numEntries].light = atoi(token);

        token = strtok(NULL, ",");
        if (token == NULL)
        {
            fprintf(stderr, "Error parsing line %d\n", lineNum);
            continue;
        }
        strncpy(logEntries[*numEntries].timestamp, token, sizeof(logEntries[*numEntries].timestamp));

        (*numEntries)++;

        // Break if the maximum number of entries is reached
        if (*numEntries >= MAX_ENTRIES)
            break;
    }
}

void displayLogEntries(LogEntry logEntries[], int numEntries)
{
    int i;
    printf("EntryNo\tSensorNo\tTemperature\tHumidity\tLight\tTimestamp\n");
    for (i = 0; i < numEntries; i++)
    {
        printf("%d\t%s\t\t%.1f\t\t%d\t\t%d\t%s\n",
               logEntries[i].entryNo,
               logEntries[i].sensorNo,
               logEntries[i].temperature,
               logEntries[i].humidity,
               logEntries[i].light,
               logEntries[i].timestamp);
    }
}

int main()
{
    FILE *file;
    LogEntry logEntries[MAX_ENTRIES];
    int numEntries = 0;

    // Open the CSV file
    file = fopen("data.csv", "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    // Extract log entries from the file
    extractLogEntries(file, logEntries, &numEntries);

    // Close the file
    fclose(file);

    // Display the log entries
    displayLogEntries(logEntries, numEntries);

    return 0;
}
