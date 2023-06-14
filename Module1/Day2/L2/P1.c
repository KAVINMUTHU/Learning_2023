// Write a program to swap every alternate element of a given array#include <stdio.h>

void swapAlternate(int *arr, int size)
{
    for (int i = 0; i < size - 1; i += 2)
    {
        int temp = arr[i];
        arr[i] = arr[i + 1];
        arr[i + 1] = temp;
    }
}

int main()
{
    int a1[5] = {10, 20, 30, 40, 50};
    int n1 = sizeof(a1) / sizeof(a1[0]);

    printf("Before swap: ");
    for (int i = 0; i < n1; i++)
    {
        printf("%d ", a1[i]);
    }

    swapAlternate(a1, n1);

    printf("\nAfter swap: ");
    for (int i = 0; i < n1; i++)
    {
        printf("%d ", a1[i]);
    }

    int a2[6] = {10, 20, 30, 40, 50, 60};
    int n2 = sizeof(a2) / sizeof(a2[0]);

    printf("\n\nBefore swap: ");
    for (int i = 0; i < n2; i++)
    {
        printf("%d ", a2[i]);
    }

    swapAlternate(a2, n2);

    printf("\nAfter swap: ");
    for (int i = 0; i < n2; i++)
    {
        printf("%d ", a2[i]);
    }

    return 0;
}
