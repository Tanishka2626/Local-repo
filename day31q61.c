// Search for an element in an array using linear search.
#include <stdio.h>
int main() {
    int arr[25], n, find, k, found = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    for(k = 0; k < n; k++)
        scanf("%d", &arr[k]);

    printf("Enter value to search: ");
    scanf("%d", &find);

    for(k = 0; k < n; k++) {
        if(arr[k] == find) {
            printf("Found at position %d", k + 1);
            found = 1;
            break;
        }
    }

    if(found == 0)
        printf("Not found");

    return 0;
}
