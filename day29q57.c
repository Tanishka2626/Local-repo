// Find sum of array elements.
#include <stdio.h>
int main() {
    int data[30], n, k, add = 0;
    printf("Enter size: ");
    scanf("%d", &n);

    for(k = 0; k < n; k++) {
        printf("Value %d: ", k + 1);
        scanf("%d", &data[k]);
        add += data[k];
    }

    printf("Sum = %d", add);
    return 0;
}
