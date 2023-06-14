#include <stdio.h>

char getGrade(int score)
{
    char grade;

    switch (score)
    {
    case 90 ... 100:
        grade = 'A';
        break;
    case 75 ... 89:
        grade = 'B';
        break;
    case 60 ... 74:
        grade = 'C';
        break;
    case 50 ... 59:
        grade = 'D';
        break;
    case 36 ... 49:
        grade = 'E';
        break;
    case 0 ... 35:
        grade = 'F';
        break;
    default:
        grade = 'N'; // Invalid score
        break;
    }

    return grade;
}

int main()
{
    int score;

    printf("Enter the student's score: ");
    scanf("%d", &score);

    char grade = getGrade(score);

    switch (score)
    {
    case 65:
        printf("Grade A\n");
        break;
    case 66:
        printf("Grade B\n");
        break;
    case 67:
        printf("Grade C\n");
        break;
    case 68:
        printf("Grade D\n");
        break;
    case 69:
        printf("Grade E\n");
        break;
    case 70:
        printf("Grade F\n");
        break;
    default:
        printf("Invalid score\n");
        break;
    }

    return 0;
}