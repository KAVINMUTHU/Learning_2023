// Write a function to rotate the above array of structures by K positions
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    int rollno;
    char name[20];
    float marks;
};

void rotateStudents(struct Student *students, int n, int k)
{
    int i, j;
    struct Student temp;

    // Perform k rotations
    for (i = 0; i < k; i++)
    {
        // Store the first student in a temporary variable
        temp = students[0];

        // Shift each student to the left by one position
        for (j = 0; j < n - 1; j++)
        {
            students[j] = students[j + 1];
        }

        // Assign the temporary student to the last position
        students[n - 1] = temp;
    }
}

int main()
{
    int n = 5;
    struct Student *students = (struct Student *)malloc(n * sizeof(struct Student));
    int i;

    // Assuming the array of structures has been initialized with data

    // Display the initial student data
    printf("Before Rotation:\n");
    for (i = 0; i < n; i++)
    {
        printf("Student %d:\n", i + 1);
        printf("Roll Number: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("--------------------\n");
    }

    // Get user input for the number of positions to rotate
    int k;
    printf("Enter the number of positions to rotate: ");
    scanf("%d", &k);

    // Perform the rotation
    rotateStudents(students, n, k);

    // Display the updated student data after rotation
    printf("After Rotation:\n");
    for (i = 0; i < n; i++)
    {
        printf("Student %d:\n", i + 1);
        printf("Roll Number: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("--------------------\n");
    }

    // Free the dynamically allocated memory
    free(students);

    return 0;
}
