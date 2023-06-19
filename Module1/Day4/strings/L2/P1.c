#include <stdio.h>

int isLeapYear(int year)
{
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
    {
        return 1; // Leap year
    }
    else
    {
        return 0; // Not a leap year
    }
}

int getMonthDays(int month, int year)
{
    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && isLeapYear(year))
    {
        return 29; // February in a leap year
    }
    else
    {
        return daysInMonth[month - 1];
    }
}

int main()
{
    int month, year;

    printf("Enter the month (1-12): ");
    scanf("%d", &month);

    printf("Enter the year: ");
    scanf("%d", &year);

    int days = getMonthDays(month, year);

    printf("Number of days: %d\n", days);

    return 0;
}
