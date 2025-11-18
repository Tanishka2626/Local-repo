#include <stdio.h>

int main() {
    int size, tvalue;
    
    // Taking size of the array
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    int data[size];

    // Input array elements
    printf("Enter %d sorted elements:\n", size);
    for(int k = 0; k < size; k++) {
        scanf("%d", &data[k]);
    }

    // Taking the target value to search
    printf("Enter the target value: ");
    scanf("%d", &tvalue);

    int firstPos = -1, lastPos = -1;

    // Finding first occurrence
    for(int a = 0; a < size; a++) {
        if(data[a] == tvalue) {
            firstPos = a;
            break;   // stop after first match
        }
    }

    // Finding last occurrence
    for(int b = size - 1; b >= 0; b--) {
        if(data[b] == tvalue) {
            lastPos = b;
            break;   // stop after last match
        }
    }

    // Printing results
    printf("\nFirst Occurrence Index: %d\n", firstPos);
    printf("Last Occurrence Index: %d\n", lastPos);

    return 0;
}
