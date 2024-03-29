// Print minimum and maximum
#include <stdio.h>

int main()
{
    int arr[] = {64, 84, 20, 36, 12, 90, 72, 10, 45, 56};
    int size = sizeof(arr) / sizeof(arr[0]);

    int min = arr[0];
    int max = arr[0];

    // Find minimum and maximum
    for (int i = 1; i < size; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    // Print minimum and maximum
    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);

    return 0;
}
