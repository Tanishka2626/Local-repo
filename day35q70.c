//Rotate an array to the right by k positions.
#include <stdio.h>
int main() {
    int arr[50], n, k, i, temp[50];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter k (number of rotations): ");
    scanf("%d", &k);

    k = k % n;  // in case k > n

    // right rotation
    for(i = 0; i < n; i++)
        temp[(i + k) % n] = arr[i];

    printf("Array after rotating right by %d positions:\n", k);
    for(i = 0; i < n; i++)
        printf("%d ", temp[i]);

    return 0;
}
