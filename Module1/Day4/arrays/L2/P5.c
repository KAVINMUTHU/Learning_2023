#include <stdio.h>

int linearSearch(int arr[], int n, int key)
{
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            break;
        }
    }
    if (i == n)
    {
        return -1; // Element not found
    }
    else
    {
        return i; // Element found at index i
    }
}

int main()
{
    int arr[] = {30, 40, 10, 60, 50, 20, 70, 90, 80, 25};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 20;

    int index = linearSearch(arr, n, key);

    if (index == -1)
    {
        printf("Element not found\n");
    }
    else
    {
        printf("Element found at index %d\n", index);
    }

    return 0;
}
