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

void readLogEntries(FILE *file, LogEntry logEntries[], int *numEntries)
{
    char line[MAX_LINE_LENGTH];
    char *token;
    int lineNum = 0;

    // Skip the header line
    fgets(line, sizeof(line), file);

    // Read each line of the CSV file
    while (fgets(line, sizeof(line), file))
    {
        lineNum++;

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

int compareLogEntries(const void *a, const void *b)
{
    const LogEntry *entryA = (const LogEntry *)a;
    const LogEntry *entryB = (const LogEntry *)b;

    if (entryA->temperature > entryB->temperature)
        return -1;
    else if (entryA->temperature < entryB->temperature)
        return 1;
    else
        return 0;
}

void writeLogEntries(FILE *file, LogEntry logEntries[], int numEntries)
{
    int i;
    fprintf(file, "EntryNo,SensorNo,Temperature,Humidity,Light,Timestamp\n");
    for (i = 0; i < numEntries; i++)
    {
        fprintf(file, "%d,%s,%.1f,%d,%d,%s\n",
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

    // Open the CSV file for reading
    file = fopen("data.csv", "r");
    if (file == NULL)
    {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    // Read the log entries from the file
    readLogEntries(file, logEntries, &numEntries);

    // Close the file
    fclose(file);

    // Sort the log entries based on temperature in descending order
    qsort(logEntries, numEntries, sizeof(LogEntry), compareLogEntries);

    // Open the CSV file for writing (overwrite the original file)
    file = fopen("data.csv", "w");
    if (file == NULL)
    {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    // Write the sorted log entries to the file
    writeLogEntries(file, logEntries, numEntries);

    // Close the file
    fclose(file);

    // Display the sorted log entries
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

    return 0;
}
