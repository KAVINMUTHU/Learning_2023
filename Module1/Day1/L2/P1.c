#include <stdio.h>

int findGreatest(int a, int b, int c)
{
    int greatest = a; // Assume a is the greatest initially

    if (b > greatest)
    {
        greatest = b;
    }

    if (c > greatest)
    {
        greatest = c;
    }

    return greatest;
}

int main()
{
    int num1, num2, num3;

    printf("Enter three numbers: ");
    scanf("%d %d %d", &num1, &num2, &num3);

    int result = findGreatest(num1, num2, num3);

    printf("The greatest number is: %d\n", result);
    return 0;
}