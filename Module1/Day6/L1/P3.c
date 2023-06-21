// Write a function to display all members in the above array of structures
#include <stdio.h>

struct Student
{
    int rollno;
    char name[20];
    float marks;
};

void displayStudentArray(struct Student *students, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        printf("Student %d:\n", i + 1);
        printf("Roll Number: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("--------------------\n");
    }
}

int main()
{
    int n = 3;
    struct Student students[n];
    int i;

    // Assuming the array of structures has been initialized with data

    displayStudentArray(students, n);

    return 0;
}
