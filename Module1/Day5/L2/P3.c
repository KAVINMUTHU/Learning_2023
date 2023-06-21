// Implement structures to read, write and compute average- marks and the students scoring above
//    and below the average marks for a class of N students.
#include <stdio.h>
#include <stdlib.h>

// Structure to represent student information
struct Student
{
    char name[50];
    int rollNumber;
    float marks;
};

// Function to read student data
void readStudentData(struct Student *students, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("\nEnter details for student %d:\n", i + 1);

        // Read the name
        printf("Name: ");
        scanf("%s", students[i].name);

        // Read the roll number
        printf("Roll Number: ");
        scanf("%d", &students[i].rollNumber);

        // Read the marks
        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }
}

// Function to write student data
void writeStudentData(struct Student *students, int n)
{
    int i;

    printf("\nStudent data:\n");
    for (i = 0; i < n; i++)
    {
        printf("\nDetails for student %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Roll Number: %d\n", students[i].rollNumber);
        printf("Marks: %.2f\n", students[i].marks);
    }
}

// Function to compute the average marks
float computeAverageMarks(struct Student *students, int n)
{
    int i;
    float sum = 0;

    for (i = 0; i < n; i++)
    {
        sum += students[i].marks;
    }

    return sum / n;
}

// Function to display students scoring above and below average marks
void displayAboveBelowAverage(struct Student *students, int n, float averageMarks)
{
    int i;
    int aboveCount = 0, belowCount = 0;

    printf("\nStudents scoring above average marks:\n");
    for (i = 0; i < n; i++)
    {
        if (students[i].marks > averageMarks)
        {
            printf("%s (Roll Number: %d) - %.2f\n", students[i].name, students[i].rollNumber, students[i].marks);
            aboveCount++;
        }
    }

    printf("\nStudents scoring below average marks:\n");
    for (i = 0; i < n; i++)
    {
        if (students[i].marks < averageMarks)
        {
            printf("%s (Roll Number: %d) - %.2f\n", students[i].name, students[i].rollNumber, students[i].marks);
            belowCount++;
        }
    }

    printf("\nTotal students scoring above average marks: %d\n", aboveCount);
    printf("Total students scoring below average marks: %d\n", belowCount);
}

int main()
{
    int n;
    struct Student *students;
    float averageMarks;

    // Read the number of students
    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Allocate memory for n students
    students = (struct Student *)malloc(n * sizeof(struct Student));

    // Read student data
    readStudentData(students, n);

    // Write student data
    writeStudentData(students, n);

    // Compute average marks
    averageMarks = computeAverageMarks(students, n);
    printf("\nAverage marks: %.2f\n", averageMarks);

    // Display students scoring above and below average marks
    displayAboveBelowAverage(students, n, averageMarks);

    // Free the allocated memory
    free(students);

    return 0;
}
