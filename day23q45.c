#include <stdio.h>

int main() {
    int n, i;
    float num = 2, den = 3, sum = 0;

    // Input number of terms
    printf("Enter number of terms (n): ");
    scanf("%d", &n);

    // Loop to calculate the series sum
    for(i = 1; i <= n; i++) {
        sum += num / den;     // Add current term to sum
        num += 2;             // Numerator increases by 2 each time
        den += 4;             // Denominator increases by 4 each time
    }

    // Display final sum
    printf("Sum of the series up to %d terms = %.2f\n", n, sum);

    return 0;
}
