// Write a function to sort the array of structures in descending order based on marks
#include <stdio.h>

struct Student
{
    int rollno;
    char name[20];
    float marks;
};

void sortStudentArray(struct Student *students, int n)
{
    int i, j;
    struct Student temp;

    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (students[j].marks < students[j + 1].marks)
            {
                // Swap the positions of students[j] and students[j + 1]
                temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int n = 3;
    struct Student students[n];
    int i;

    // Assuming the array of structures has been initialized with data

    // Sort the array of structures based on marks in descending order
    sortStudentArray(students, n);

    // Display the sorted student data
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
