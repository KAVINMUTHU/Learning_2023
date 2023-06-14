
#include <stdio.h>

int main()
{
    int rollNo;
    char name[50];
    float physics, math, chemistry;
    float totalMarks, percentage;

    // Read inputs
    printf("Enter Roll No: ");
    scanf("%d", &rollNo);

    printf("Enter Name: ");
    scanf(" %[^\n]s", name);

    printf("Enter Marks in Physics: ");
    scanf("%f", &physics);

    printf("Enter Marks in Math: ");
    scanf("%f", &math);

    printf("Enter Marks in Chemistry: ");
    scanf("%f", &chemistry);

    // Calculate total marks and percentage
    totalMarks = physics + math + chemistry;
    percentage = (totalMarks / 300) * 100;

    // Print summary
    printf("\n----- Student Summary -----\n");
    printf("Roll No: %d\n", rollNo);
    printf("Name: %s\n", name);
    printf("Marks in Physics: %.2f\n", physics);
    printf("Marks in Math: %.2f\n", math);
    printf("Marks in Chemistry: %.2f\n", chemistry);
    printf("Total Marks: %.2f\n", totalMarks);
    printf("Percentage: %.2f%%\n", percentage);

    return 0;
}