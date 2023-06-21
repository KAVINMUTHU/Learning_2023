// Function to read a complex number from the user
// Function to write a complex number to the console
// Function to add two complex numbers
// Function to multiply two complex numbers
#include <stdio.h>

// Structure to represent a complex number
struct Complex
{
    float real;
    float imaginary;
};

void readComplex(struct Complex *number)
{
    printf("Enter the real part: ");
    scanf("%f", &(number->real));

    printf("Enter the imaginary part: ");
    scanf("%f", &(number->imaginary));
}

void writeComplex(struct Complex number)
{
    printf("Complex number: %.2f + %.2fi\n", number.real, number.imaginary);
}

struct Complex addComplex(struct Complex number1, struct Complex number2)
{
    struct Complex result;
    result.real = number1.real + number2.real;
    result.imaginary = number1.imaginary + number2.imaginary;
    return result;
}

struct Complex multiplyComplex(struct Complex number1, struct Complex number2)
{
    struct Complex result;
    result.real = (number1.real * number2.real) - (number1.imaginary * number2.imaginary);
    result.imaginary = (number1.real * number2.imaginary) + (number1.imaginary * number2.real);
    return result;
}

int main()
{
    struct Complex complex1, complex2, sum, product;

    printf("Enter the first complex number:\n");
    readComplex(&complex1);

    printf("Enter the second complex number:\n");
    readComplex(&complex2);

    sum = addComplex(complex1, complex2);

    product = multiplyComplex(complex1, complex2);

    printf("\nFirst complex number:\n");
    writeComplex(complex1);

    printf("Second complex number:\n");
    writeComplex(complex2);

    printf("Sum of the two complex numbers:\n");
    writeComplex(sum);

    printf("Product of the two complex numbers:\n");
    writeComplex(product);

    return 0;
}
