#include <stdio.h>

// Function to check if the given year is a leap year
int isLeapYear(int year)
{
    if (year % 400 == 0)
    {
        return 1;
    }
    else if (year % 100 == 0)
    {
        return 0;
    }
    else if (year % 4 == 0)
    {
        return 1;
    }
    return 0;
}

int main()
{
    int day, month, year;
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int daysElapsed = 0;

    printf("Enter the date (dd mm yyyy): ");
    scanf("%d %d %d", &day, &month, &year);

    // Calculate the number of days elapsed for the previous months
    for (int i = 1; i < month; i++)
    {
        daysElapsed += daysInMonth[i - 1];
    }

    // Adjust for leap year if it is a leap year and the month is after February
    if (isLeapYear(year) && month > 2)
    {
        daysElapsed += 1;
    }

    // Add the days of the current month
    daysElapsed += day;

    printf("Number of days elapsed since the start of the year: %d\n", daysElapsed);

    return 0;
}
