//Check if a matrix is symmetric.
#include <stdio.h>
int main() {
    int mat[10][10], r, c, i, j, flag = 1;

    printf("Enter rows and columns: ");
    scanf("%d%d", &r, &c);

    if(r != c) {
        printf("Not a square matrix, so not symmetric.");
        return 0;
    }

    printf("Enter matrix elements:\n");
    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++)
            scanf("%d", &mat[i][j]);

    for(i = 0; i < r; i++)
        for(j = 0; j < c; j++)
            if(mat[i][j] != mat[j][i])
                flag = 0;

    if(flag)
        printf("Matrix is symmetric.");
    else
        printf("Matrix is not symmetric.");

    return 0;
}
