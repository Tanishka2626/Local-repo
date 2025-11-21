#include <stdio.h>

int main() {

    int n, xvalue;
    
    // Taking size of array
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input sorted array
    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input target value
    printf("Enter x value: ");
    scanf("%d", &xvalue);

    int position = -1;

    // Find first element >= xvalue
    for (int j = 0; j < n; j++) {
        if (arr[j] >= xvalue) {
            position = j;   // store index
            break;          // stop at first match
        }
    }

    // Print result
    printf("\nCeil Index: %d\n", position);

    return 0;
}
