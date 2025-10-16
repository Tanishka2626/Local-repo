// write a program to input two numbers and display their sum, difference, product ,quotient
#include <stdio.h>

int main(){
    float num1, num2, sum , difference, product, quotient;

    // Input two numbers
    printf("Enter first number: ");
    scanf("%f", &num1);

    printf("Enter second number: ");
    scanf("%f", &num2);

    // Perform operations
    sum = num1 + num2;
    difference = num1 - num2;
    product = num1 * num2;
     
   // Check if divisor is not zero before dividing
   if (num2 != 0)
       quotient = num1 / num2;
   else
       quotient = 0; // to avoid division by zero
       
       // display result
       printf("\nResults:\n");
       printf("Sum = %.2f\n", sum); // %.2f ( displays numbers with two decimal places)
       printf("Difference = %.2f\n", difference);
       printf("Product = %.2f\n", product);

       if (num2 != 0)
           printf("Quotient = %.2f\n", quotient);
       else
           printf("Quotient = Undefined ( division by zero)\n");

    return 0;       
}