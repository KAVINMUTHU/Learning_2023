// Write a function to initialize all members in the above array of structures
#include <stdio.h>
#include <string.h>

struct Student
{
    int rollno;
    char name[20];
    float marks;
};

void initializeStudentArray(struct Student *students, int n)
{
    int i;

    for (i = 0; i < n; i++)
    {
        students[i].rollno = 0;
        strcpy(students[i].name, "");
        students[i].marks = 0.0;
    }
}

int main()
{
    int n = 3;
    struct Student students[n];
    int i;

    initializeStudentArray(students, n);

    // Display the student data
    for (i = 0; i < n; i++)
    {
        printf("Student %d:\n", i + 1);
        printf("Roll Number: %d\n", students[i].rollno);
        printf("Name: %s\n", students[i].name);
        printf("Marks: %.2f\n", students[i].marks);
        printf("--------------------\n");
    }

    return 0;
}
