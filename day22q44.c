//Write program to find the sum of the series: 1 + 3/4 + 5/6 + 7/8 + … up to n terms.
#include <stdio.h>

int main() {
    int term, count;
    float numerator = 1, denominator = 1, sum = 0;

    // Input number of terms from user
    printf("Enter number of terms (n): ");
    scanf("%d", &term);

    // Loop through n terms
    for(count = 1; count <= term; count++) {
        sum += numerator / denominator;   // Add current term to sum
        numerator += 2;                   // Increase numerator by 2
        denominator += 2;                 // Increase denominator by 2
    }

    // Display final result
    printf("Sum of the series up to %d terms = %.2f\n", term, sum);

    return 0;
}
