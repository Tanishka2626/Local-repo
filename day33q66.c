//Insert an element in a sorted array at the appropriate position.
#include <stdio.h>
int main() {
    int arr[20], n, newVal, i;
    printf("Enter size of sorted array: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("Enter value to insert: ");
    scanf("%d", &newVal);

    i = n - 1;
    while(i >= 0 && arr[i] > newVal) {
        arr[i + 1] = arr[i];
        i--;
    }
    arr[i + 1] = newVal;
    n++;

    printf("Updated array: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}
