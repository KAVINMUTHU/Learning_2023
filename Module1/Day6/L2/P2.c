// Write a function to delete a member at the start of the above array of structures
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    int rollno;
    char name[20];
    float marks;
};

void deleteStudent(struct Student **students, int *n)
{
    if (*n == 0)
    {
        printf("No students to delete!\n");
        return;
    }

    // Shift the elements of the array to remove the first student
    memmove(*students, *students + 1, (*n - 1) * sizeof(struct Student));

    // Reduce the size of the array
    *students = (struct Student *)realloc(*students, (*n - 1) * sizeof(struct Student));

    (*n)--;
}

int main()
{
    int n = 3;
    struct Student *students = (struct Student *)malloc(n * sizeof(struct Student));
    int i;

    // Assuming the initial array of structures has been populated

    // Delete the first student from the array
    deleteStudent(&students, &n);

    // Display the updated student data
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
