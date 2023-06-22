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

int updateEntry(FILE *file, LogEntry logEntries[], int numEntries, int entryNo)
{
    int i;
    for (i = 0; i < numEntries; i++)
    {
        if (logEntries[i].entryNo == entryNo)
        {
            printf("Enter new values for EntryNo %d:\n", entryNo);
            printf("SensorNo: ");
            scanf("%s", logEntries[i].sensorNo);
            printf("Temperature: ");
            scanf("%f", &logEntries[i].temperature);
            printf("Humidity: ");
            scanf("%d", &logEntries[i].humidity);
            printf("Light: ");
            scanf("%d", &logEntries[i].light);
            printf("Timestamp: ");
            scanf("%s", logEntries[i].timestamp);

            // Update the entry in the file
            fseek(file, 0, SEEK_SET);
            writeLogEntries(file, logEntries, numEntries);
            return 1;
        }
    }

    return 0;
}

int main()
{
    FILE *file;
    LogEntry logEntries[MAX_ENTRIES];
    int numEntries = 0;
    int entryNo;

    // Open the CSV file for reading and writing
    file = fopen("data.csv", "r+");
    if (file == NULL)
    {
        fprintf(stderr, "Error opening file\n");
        return 1;
    }

    // Read the log entries from the file
    readLogEntries(file, logEntries, &numEntries);

    // Prompt the user to enter the EntryNo to update
    printf("Enter the EntryNo to update: ");
    scanf("%d", &entryNo);

    // Update the entry
    int updated = updateEntry(file, logEntries, numEntries, entryNo);
    if (updated)
    {
        printf("EntryNo %d updated successfully.\n", entryNo);
    }
    else
    {
        printf("EntryNo %d not found.\n", entryNo);
    }

    // Close the file
    fclose(file);

    return 0;
}
