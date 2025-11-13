// Find the sum of main diagonal elements for a square matrix.
#include <stdio.h>

int main() {
    int size;  // variable to store size of square matrix
    int mat[10][10];  // matrix declaration (max size 10x10)
    int i, j;  // loop counters
    int diagSum = 0;  // variable to store sum of diagonal elements

    // Input size of the square matrix
    printf("Enter the size of the square matrix: ");
    scanf("%d", &size);

    // Input elements into the matrix
    printf("Enter the elements of the matrix:\n");
    for(i = 0; i < size; i++) {
        for(j = 0; j < size; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    // Calculate the sum of main diagonal elements
    // (main diagonal elements are where row index == column index)
    for(i = 0; i < size; i++) {
        diagSum += mat[i][i];
    }

    // Display the result
    printf("Sum of main diagonal elements = %d\n", diagSum);

    return 0;
}
