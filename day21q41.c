#include <stdio.h>

int main() {
    int number, temp, firstDigit, lastDigit, result, power = 1;

    printf("Enter a number: ");
    scanf("%d", &number);

    temp = number;
    lastDigit = temp % 10;        // store last digit

    // find first digit and total digits
    while (temp >= 10) {
        temp /= 10;
        power *= 10;              // tracks the place value (10,100,1000,...)
    }
    firstDigit = temp;

    // form new number by swapping
    result = lastDigit * power + (number % power) / 10 * 10 + firstDigit;

    printf("After swapping first and last digit: %d", result);
    return 0;
}
