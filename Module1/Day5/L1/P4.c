// write a program to Store Data for n students in Structures Dynamically.
#include <stdio.h>
#include <stdlib.h>

// Structure to represent student data
struct Student
{
    char name[50];
    int age;
    float marks;
};

int main()
{
    int n, i;
    struct Student *students;

    // Read the number of students
    printf("Enter the number of students: ");
    scanf("%d", &n);

    // Allocate memory for n students
    students = (struct Student *)malloc(n * sizeof(struct Student));

    // Read data for each student
    for (i = 0; i < n; i++)
    {
        printf("\nEnter details for student %d:\n", i + 1);

        // Read the name
        printf("Name: ");
        scanf("%s", students[i].name);

        // Read the age
        printf("Age: ");
        scanf("%d", &students[i].age);

        // Read the marks
        printf("Marks: ");
        scanf("%f", &students[i].marks);
    }

    // Display data for each student
    printf("\nStudent data:\n");
    for (i = 0; i < n; i++)
    {
        printf("\nDetails for student %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Age: %d\n", students[i].age);
        printf("Marks: %.2f\n", students[i].marks);
    }

    // Free the allocated memory
    free(students);

    return 0;
}
