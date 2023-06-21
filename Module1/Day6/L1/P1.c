// Assume User will be providing input in the form of a string as show below.
// Write a function to parse the string and initialize an array of structures.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a student
struct Student
{
    int rollno;
    char name[20];
    float marks;
};

// Function to parse the string and initialize an array of structures
void initializeStudentArray(char *inputString, struct Student *students, int n)
{
    int i;
    char *token;

    // Split the input string into tokens based on space
    token = strtok(inputString, " ");

    for (i = 0; i < n; i++)
    {
        // Extract the roll number from the token
        students[i].rollno = atoi(token);
        token = strtok(NULL, " ");

        // Extract the name from the token
        strcpy(students[i].name, token);
        token = strtok(NULL, " ");

        // Extract the marks from the token
        students[i].marks = atof(token);
        token = strtok(NULL, " ");
    }
}

int main()
{
    int n = 3;
    char inputString[] = "1001 Aron 100.00";
    struct Student students[n];
    int i;

    // Initialize the student array by parsing the input string
    initializeStudentArray(inputString, students, n);

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
