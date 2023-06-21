// Write a function to perform a search operation on the array of structures based on name of the student
#include <stdio.h>
#include <string.h>

struct Student
{
    int rollno;
    char name[20];
    float marks;
};

void searchStudentByName(struct Student *students, int n, const char *searchName)
{
    int i;
    int found = 0;

    for (i = 0; i < n; i++)
    {
        if (strcmp(students[i].name, searchName) == 0)
        {
            printf("Student Found!\n");
            printf("Roll Number: %d\n", students[i].rollno);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Student Not Found!\n");
    }
}

int main()
{
    int n = 3;
    struct Student students[n];
    int i;
    const char *searchName = "Aron";

    // Assuming the array of structures has been initialized with data

    // Search for a student by name
    searchStudentByName(students, n, searchName);

    return 0;
}
