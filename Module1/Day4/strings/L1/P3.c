#include <stdio.h>
#include <stdlib.h>

int computeTotalSeconds(const char *timeStr)
{
    int hours, minutes, seconds;
    sscanf(timeStr, "%d:%d:%d", &hours, &minutes, &seconds);

    int totalSeconds = hours * 3600 + minutes * 60 + seconds;
    return totalSeconds;
}

int main()
{
    const char *timeStr = "12:34:56";

    int totalSeconds = computeTotalSeconds(timeStr);

    printf("Total seconds: %d\n", totalSeconds);

    return 0;
}
