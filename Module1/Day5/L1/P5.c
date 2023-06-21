// Write a program to demonstrate the swapping the fields of two structures using pointers
#include <stdio.h>
#include <string.h>

// Structure to represent a person
struct Person
{
    char name[50];
    int age;
};

// Function to swap the fields of two structures
void swapStructures(struct Person *person1, struct Person *person2)
{
    // Swap the name field
    char temp[50];
    strcpy(temp, person1->name);
    strcpy(person1->name, person2->name);
    strcpy(person2->name, temp);

    // Swap the age field
    int ageTemp = person1->age;
    person1->age = person2->age;
    person2->age = ageTemp;
}

int main()
{
    struct Person person1, person2;

    // Read data for person 1
    printf("Enter details for person 1:\n");
    printf("Name: ");
    scanf("%s", person1.name);
    printf("Age: ");
    scanf("%d", &person1.age);

    // Read data for person 2
    printf("\nEnter details for person 2:\n");
    printf("Name: ");
    scanf("%s", person2.name);
    printf("Age: ");
    scanf("%d", &person2.age);

    // Display the original data
    printf("\nOriginal data:\n");
    printf("Person 1: Name - %s, Age - %d\n", person1.name, person1.age);
    printf("Person 2: Name - %s, Age - %d\n", person2.name, person2.age);

    // Swap the fields using pointers
    swapStructures(&person1, &person2);

    // Display the swapped data
    printf("\nSwapped data:\n");
    printf("Person 1: Name - %s, Age - %d\n", person1.name, person1.age);
    printf("Person 2: Name - %s, Age - %d\n", person2.name, person2.age);

    return 0;
}
