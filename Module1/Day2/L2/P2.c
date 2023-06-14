/// Write a program to compare the items in a box, assume equal size boxes
/// Boxes shall have unique items stored in random order
/// Boxes are compared True if there is one to one mapping of items
/// return the final result 1 or 0
#include <stdio.h>

int compareBoxes(int *boxA, int *boxB, int size)
{
    int found;

    for (int i = 0; i < size; i++)
    {
        found = 0;

        for (int j = 0; j < size; j++)
        {
            if (boxA[i] == boxB[j])
            {
                found = 1;
                break;
            }
        }

        if (!found)
        {
            return 0;
        }
    }

    return 1;
}

int main()
{
    int A[3] = {200, 10, -90};
    int B[3] = {-90, 200, 10};
    int size = sizeof(A) / sizeof(A[0]);

    int result = compareBoxes(A, B, size);

    if (result)
    {
        printf("Boxes have a one-to-one mapping.\n");
    }
    else
    {
        printf("Boxes do not have a one-to-one mapping.\n");
    }

    return 0;
}
