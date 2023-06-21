// Write a function to swap 2 members in different indexes (based on user input) in the above array of structures
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    int rollno;
    char name[20];
    float marks;
};

void swapStudents(struct Student *students, int index1, int index2)
{
    struct Student temp;

    temp = students[index1];
    students[index1] = students[index2];
    students[index2] = temp;
}

int main()
{
    int n = 3;
    struct Student *students = (struct Student *)malloc(n * sizeof(struct Student));
    int i;

    // Assuming the array of structures has been initialized with data

    // Display the initial student data
    printf("Before Swap:\n");
    for (i = 0; i < n; i++)
    {
        printf("Student %d:\n", i + 1);
        printf("Roll Number: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("--------------------\n");
    }

    // Get user input for the indexes to swap
    int index1, index2;
    printf("Enter the indexes of the students to swap (0-%d): ", n - 1);
    scanf("%d %d", &index1, &index2);

    // Perform the swap
    swapStudents(students, index1, index2);

    // Display the updated student data
    printf("After Swap:\n");
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
