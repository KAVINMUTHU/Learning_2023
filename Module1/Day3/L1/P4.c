// Find the largest number by deleting single digit in a 4 digit number 5872 - 872, 9856 - 986
// Concepts to be used.

#include <stdio.h>

int find_largest_number(int num)
{
    char num_str[5];
    sprintf(num_str, "%d", num);
    int largest_num = -1;
    int i, j;

    for (i = 0; i < 4; i++)
    {
        char new_num_str[4];
        for (j = 0; j < i; j++)
        {
            new_num_str[j] = num_str[j];
        }
        for (j = i + 1; j < 4; j++)
        {
            new_num_str[j - 1] = num_str[j];
        }
        new_num_str[3] = '\0';
        int new_num = atoi(new_num_str);
        if (new_num > largest_num)
        {
            largest_num = new_num;
        }
    }

    return largest_num;
}

int main()
{
    int number;
    printf("Enter a 4-digit number: ");
    scanf("%d", &number);
    int largest_number = find_largest_number(number);
    printf("Largest number after deleting a digit from %d is: %d\n", number, largest_number);
    return 0;
}
