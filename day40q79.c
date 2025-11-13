//Perform diagonal traversal of a matrix.
#include <stdio.h>

int main() {
    int rows, cols;
    int mat[10][10];
    int i, j, start;

    // Input size of matrix
    printf("Enter number of rows and columns: ");
    scanf("%d %d", &rows, &cols);

    // Input elements
    printf("Enter the elements of the matrix:\n");
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            scanf("%d", &mat[i][j]);
        }
    }

    printf("\nDiagonal Traversal of the Matrix:\n");

    // Traverse diagonals starting from the first row
    for(start = 0; start < cols; start++) {
        i = 0;
        j = start;
        while(i < rows && j >= 0) {
            printf("%d ", mat[i][j]);
            i++;
            j--;
        }
        printf("\n");
    }

    // Traverse diagonals starting from the last column of other rows
    for(start = 1; start < rows; start++) {
        i = start;
        j = cols - 1;
        while(i < rows && j >= 0) {
            printf("%d ", mat[i][j]);
            i++;
            j--;
        }
        printf("\n");
    }

    return 0;
}
