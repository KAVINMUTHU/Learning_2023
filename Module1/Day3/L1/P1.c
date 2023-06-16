/// Write a program to print the given pattern below using 3 functions (1st to accept n and to print from 1 to n, 2nd to accept n and print spaces in between, 3rd to accept the n and print from n to 1)
#include <stdio.h>

void print_numbers(int n)
{
    int i;
    for (i = 1; i <= n; i++)
    {
        printf("%d", i);
    }
    for (i = n - 1; i >= 1; i--)
    {
        printf("%d", i);
    }
    printf("\n");
}

void print_spaces(int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf(" ");
    }
}

void print_pattern(int n)
{
    int i;
    for (i = n; i >= 1; i--)
    {
        print_numbers(i);
        if (i > 1)
        {
            print_spaces(2 * (n - i));
            print_numbers(i);
        }
        printf("\n");
    }
}

int main()
{
    int n;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    print_pattern(n);
    return 0;
}