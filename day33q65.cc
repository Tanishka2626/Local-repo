// Search in a sorted array using binary search.
#include <stdio.h>
int main() {
    int arr[30], n, key, low = 0, high, mid;
    printf("Enter size of array: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter element to search: ");
    scanf("%d", &key);

    high = n - 1;
    while(low <= high) {
        mid = (low + high) / 2;
        if(arr[mid] == key) {
            printf("Found at position %d", mid + 1);
            return 0;
        }
        else if(arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }

    printf("Not found");
    return 0;
}
