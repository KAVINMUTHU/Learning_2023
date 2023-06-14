// Write a program to swap any type of data passed to an function.#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(void *a, void *b, size_t size)
{
    void *temp = malloc(size);
    memcpy(temp, a, size);
    memcpy(a, b, size);
    memcpy(b, temp, size);
    free(temp);
}

int main()
{
    int a = 10;
    int b = 20;
    printf("Before swap: a = %d, b = %d\n", a, b);
    swap(&a, &b, sizeof(int));
    printf("After swap: a = %d, b = %d\n", a, b);

    double x = 1.23;
    double y = 4.56;
    printf("Before swap: x = %lf, y = %lf\n", x, y);
    swap(&x, &y, sizeof(double));
    printf("After swap: x = %lf, y = %lf\n", x, y);

    char c1 = 'A';
    char c2 = 'B';
    printf("Before swap: c1 = %c, c2 = %c\n", c1, c2);
    swap(&c1, &c2, sizeof(char));
    printf("After swap: c1 = %c, c2 = %c\n", c1, c2);

    return 0;
}
