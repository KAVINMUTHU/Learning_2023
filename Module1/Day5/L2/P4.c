// Write a program to pass a pointer to a structure as a parameter to a function and return back a pointer to structure
//    to the calling function after modifying the members of structure.
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a person
struct Person
{
    char name[50];
    int age;
};

// Function to modify the members of a structure and return a pointer to the structure
struct Person *modifyStructure(struct Person *person)
{
    // Modify the members of the structure
    printf("Enter new name: ");
    scanf("%s", person->name);

    printf("Enter new age: ");
    scanf("%d", &(person->age));

    // Return the pointer to the modified structure
    return person;
}

int main()
{
    struct Person *person;
    struct Person modifiedPerson;

    // Allocate memory for the structure
    person = (struct Person *)malloc(sizeof(struct Person));

    // Read initial data for the structure
    printf("Enter name: ");
    scanf("%s", person->name);

    printf("Enter age: ");
    scanf("%d", &(person->age));

    // Call the modifyStructure function and assign the returned pointer to modifiedPerson
    modifiedPerson = *modifyStructure(person);

    // Display the modified data
    printf("\nModified data:\n");
    printf("Name: %s\n", modifiedPerson.name);
    printf("Age: %d\n", modifiedPerson.age);

    // Free the allocated memory
    free(person);

    return 0;
}
