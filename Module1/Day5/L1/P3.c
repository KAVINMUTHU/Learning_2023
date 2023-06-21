// Write a program using structures to calculate the difference between two time periods using a user-defined function.
#include <stdio.h>

// Structure to represent time
struct Time
{
    int hours;
    int minutes;
    int seconds;
};

// Function to calculate the difference between two time periods
struct Time calculateTimeDifference(struct Time start, struct Time end)
{
    struct Time difference;

    if (end.seconds < start.seconds)
    {
        --end.minutes;
        end.seconds += 60;
    }

    difference.seconds = end.seconds - start.seconds;

    if (end.minutes < start.minutes)
    {
        --end.hours;
        end.minutes += 60;
    }

    difference.minutes = end.minutes - start.minutes;
    difference.hours = end.hours - start.hours;

    return difference;
}

int main()
{
    struct Time startTime, endTime, difference;

    // Read the start time
    printf("Enter the start time (hours minutes seconds): ");
    scanf("%d %d %d", &startTime.hours, &startTime.minutes, &startTime.seconds);

    // Read the end time
    printf("Enter the end time (hours minutes seconds): ");
    scanf("%d %d %d", &endTime.hours, &endTime.minutes, &endTime.seconds);

    // Calculate the difference
    difference = calculateTimeDifference(startTime, endTime);

    // Display the difference
    printf("\nTime Difference: %02d:%02d:%02d\n", difference.hours, difference.minutes, difference.seconds);

    return 0;
}