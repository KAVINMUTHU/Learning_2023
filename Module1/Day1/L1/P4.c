
#include <stdio.h>

int main()
{
    float num1, num2, result;
    char operator;

    // Read inputs
    printf("Enter Number 1: ");
    scanf("%f", &num1);

    printf("Enter the Operator (+, -, *, /): ");
    scanf(" %c", &operator);

    printf("Enter Number 2: ");
    scanf("%f", &num2);

    // Perform calculations based on the operator
    switch (operator)
    {
    case '+':
        result = num1 + num2;
        break;
    case '-':
        result = num1 - num2;
        break;
    case '*':
        result = num1 * num2;
        break;
    case '/':
        if (num2 != 0)
        {
            result = num1 / num2;
        }
        else
        {
            printf("Error: Division by zero\n");
            return 1; // Exit the program with an error status
        }
        break;
    default:
        printf("Error: Invalid operator\n");
        return 1; // Exit the program with an error status
    }

    // Print the result
    printf("Result: %.2f\n", result);

    return 0;
}