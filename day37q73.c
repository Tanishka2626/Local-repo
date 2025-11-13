//Find the sum of each row of a matrix and store it in an array.
#include <stdio.h>
int main() {
    int mat[10][10], r, c, i, j, rowSum[10];

    printf("Enter rows and columns: ");
    scanf("%d%d", &r, &c);

    printf("Enter matrix elements:\n");
    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++)
            scanf("%d", &mat[i][j]);

    for(i = 0; i < r; i++) {
        rowSum[i] = 0;
        for(j = 0; j < c; j++)
            rowSum[i] += mat[i][j];
    }

    printf("Row-wise sums:\n");
    for(i = 0; i < r; i++)
        printf("Row %d = %d\n", i + 1, rowSum[i]);

    return 0;
}
