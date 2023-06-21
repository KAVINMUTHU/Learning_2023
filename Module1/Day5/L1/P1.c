// Calculate the volume and total surface area using the pointer and dot operator
// Calculate the volume and total surface area using the arrow operator
#include <stdio.h>

struct Box
{
    float length;
    float width;
    float height;
};

float calculateVolume(struct Box *box)
{
    return box->length * box->width * box->height;
}

// Function to calculate the total surface area of the box
float calculateSurfaceArea(struct Box *box)
{
    return 2 * (box->length * box->width + box->length * box->height + box->width * box->height);
}

int main()
{

    struct Box myBox;

    myBox.length = 5.0;
    myBox.width = 3.0;
    myBox.height = 2.0;

    struct Box *boxPtr = &myBox;

    float volume = calculateVolume(&myBox);
    float surfaceArea = calculateSurfaceArea(&myBox);

    float volumePtr = calculateVolume(boxPtr);
    float surfaceAreaPtr = calculateSurfaceArea(boxPtr);

    printf("Using dot operator:\n");
    printf("Volume: %.2f\n", volume);
    printf("Surface Area: %.2f\n", surfaceArea);

    printf("Using arrow operator:\n");
    printf("Volume: %.2f\n", volumePtr);
    printf("Surface Area: %.2f\n", surfaceAreaPtr);

    return 0;
}
