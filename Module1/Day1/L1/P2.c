#include <stdio.h>

void print_grade(int score)
{
    if (score >= 90 && score <= 100)
    {
        printf("Grade A\n");
    }
    else if (score >= 75 && score <= 89)
    {
        printf("Grade B\n");
    }
    else if (score >= 60 && score <= 74)
    {
        printf("Grade C\n");
    }
    else if (score >= 50 && score <= 59)
    {
        printf("Grade D\n");
    }
    else
    {
        printf("Grade F\n");
    }
}

int main()
{
    print_grade(90); // Output: Grade A
    print_grade(85); // Output: Grade B
    print_grade(70); // Output: Grade C
    print_grade(55); // Output: Grade D
    print_grade(30); // Output: Grade F

    return 0;
}
