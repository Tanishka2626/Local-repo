//Write  program to check if a number is a perfect number.
#include <stdio.h>

int main() {
    int value, factor, total = 0;   // 'value' = number to check, 'factor' = possible divisor, 'total' = sum of divisors

    //  Input from user
    printf(" Enter any number: ");
    scanf("%d", &value);

    printf("\n Divisors of %d are: ", value);

    //  Loop through numbers from 1 to one less than the number itself
    for(factor = 1; factor < value; factor++) {
        if(value % factor == 0) {      // If 'factor' divides the number completely
            printf("%d ", factor);     // Display the divisor
            total += factor;           // Add it to the total sum
        }
    }

    // Show total of divisors
    printf("\n Sum of divisors = %d", total);

    //  Check if number is perfect
    if(total == value)
        printf("\n %d is a PERFECT number!\n", value);
    else
        printf("\n %d is NOT a perfect number.\n", value);

    return 0;
}
