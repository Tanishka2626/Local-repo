//Write  program to check if a number is a strong number.
#include <stdio.h>

int main() {
    int num, temp, digit, sum = 0, fact, i;

    // Input number from user
    printf("Enter a number to check if it's a Strong number: ");
    scanf("%d", &num);

    temp = num;  // Store original number

    // Loop to extract each digit and calculate factorial
    while (temp > 0) {
        digit = temp % 10;   // Get last digit
        fact = 1;

        // Find factorial of the digit
        for (i = 1; i <= digit; i++) {
            fact *= i;
        }

        sum += fact;          // Add factorial to sum
        temp /= 10;           // Remove last digit
    }

    // Check if number equals sum of factorials of its digits
    if (sum == num)
        printf("%d is a Strong number.\n", num);
    else
        printf("%d is not a Strong number.\n", num);

    return 0;
}
