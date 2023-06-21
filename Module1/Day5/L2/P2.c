// Write a program to enter to Cartesian coordinate points and display the distance between them.
#include <stdio.h>
#include <math.h>

// Structure to represent a Cartesian coordinate point
struct Point
{
    float x;
    float y;
};

// Function to calculate the distance between two points
float calculateDistance(struct Point p1, struct Point p2)
{
    float distance;
    distance = sqrt(pow((p2.x - p1.x), 2) + pow((p2.y - p1.y), 2));
    return distance;
}

int main()
{
    struct Point point1, point2;
    float distance;

    // Read the first point
    printf("Enter coordinates for the first point:\n");
    printf("x1: ");
    scanf("%f", &point1.x);
    printf("y1: ");
    scanf("%f", &point1.y);

    // Read the second point
    printf("\nEnter coordinates for the second point:\n");
    printf("x2: ");
    scanf("%f", &point2.x);
    printf("y2: ");
    scanf("%f", &point2.y);

    // Calculate the distance
    distance = calculateDistance(point1, point2);

    // Display the distance
    printf("\nDistance between the points: %.2f\n", distance);

    return 0;
}
