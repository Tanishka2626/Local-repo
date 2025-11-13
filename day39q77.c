//Check if the elements on the diagonal of a matrix are distinct.
#include <stdio.h>
int main() {
    int mat[10][10], n, i, j, k, unique = 1;

    printf("Enter order of square matrix: ");
    scanf("%d", &n);

    printf("Enter matrix elements:\n");
    for(i = 0; i < n; i++)
        for(j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);

    for(i = 0; i < n; i++)
        for(j = i + 1; j < n; j++)
            if(mat[i][i] == mat[j][j])
                unique = 0;

    if(unique)
        printf("Diagonal elements are distinct.");
    else
        printf("Diagonal elements are NOT distinct.");

    return 0;
}
