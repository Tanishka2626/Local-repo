
#include <stdio.h>

int main() {
    int m, n, p, q;
    int A[10][10], B[10][10], C[10][10];
    int i, j, k;

    printf("Enter rows and columns of matrix A: ");
    scanf("%d%d", &m, &n);

    printf("Enter rows and columns of matrix B: ");
    scanf("%d%d", &p, &q);

    // Check compatibility
    if (n != p) {
        printf("Matrix multiplication not possible. Columns of A must equal rows of B.\n");
        return 0;
    }

    printf("Enter elements of matrix A:\n");
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter elements of matrix B:\n");
    for (i = 0; i < p; i++)
        for (j = 0; j < q; j++)
            scanf("%d", &B[i][j]);

    // Multiply A and B -> C
    for (i = 0; i < m; i++) {
        for (j = 0; j < q; j++) {
            C[i][j] = 0;
            for (k = 0; k < n; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Print matrices
    printf("\nMatrix A:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) printf("%4d", A[i][j]);
        printf("\n");
    }

    printf("\nMatrix B:\n");
    for (i = 0; i < p; i++) {
        for (j = 0; j < q; j++) printf("%4d", B[i][j]);
        printf("\n");
    }

    printf("\nProduct Matrix (A x B):\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < q; j++) printf("%4d", C[i][j]);
        printf("\n");
    }
    return 0;
}
