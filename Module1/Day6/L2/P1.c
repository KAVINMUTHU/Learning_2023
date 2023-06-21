// Write a function to add a member at the end of the above array of structures
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student
{
    int rollno;
    char name[20];
    float marks;
};

void addStudent(struct Student **students, int *n, int rollno, const char *name, float marks)
{
    struct Student *newStudent;
    int newSize = *n + 1;

    // Reallocate memory for the expanded array
    newStudent = (struct Student *)realloc(*students, newSize * sizeof(struct Student));
    if (newStudent == NULL)
    {
        printf("Memory allocation failed!\n");
        return;
    }

    *students = newStudent;

    // Assign values to the new student
    (*students)[*n].rollno = rollno;
    strcpy((*students)[*n].name, name);
    (*students)[*n].marks = marks;

    *n = newSize;
}

int main()
{
    int n = 3;
    struct Student *students = (struct Student *)malloc(n * sizeof(struct Student));
    int i;

    // Assuming the initial array of structures has been populated

    // Add a new student to the array
    addStudent(&students, &n, 1004, "John", 90.0);

    // Display the updated student data
    for (i = 0; i < n; i++)
    {
        printf("Student %d:\n", i + 1);
        printf("Roll Number: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
    }

    // Free the dynamically allocated memory
    free(students);

    return 0;
}
