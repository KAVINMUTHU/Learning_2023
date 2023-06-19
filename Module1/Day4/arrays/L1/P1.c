// Print sum and average
#include <stdio.h>

int main()
{
    int arr[] = {12, 84, 20, 36, 64, 56, 72, 10, 45, 90};
    int size = sizeof(arr) / sizeof(arr[0]);

    int sum = 0;
    float avg;

    // Calculate sum
    for (int i = 0; i < size; i++)
    {
        sum += arr[i];
    }

    // Calculate average
    avg = (float)sum / size;

    // Print sum and average
    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", avg);

    return 0;
}
