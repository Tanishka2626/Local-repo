// merge two arrays 
#include <stdio.h>
int main() {
    int arr1[20], arr2[20], merged[40];
    int size1, size2, i, j;

    printf("Enter size of first array: ");
    scanf("%d", &size1);
    for(i = 0; i < size1; i++)
        scanf("%d", &arr1[i]);

    printf("Enter size of second array: ");
    scanf("%d", &size2);
    for(i = 0; i < size2; i++)
        scanf("%d", &arr2[i]);

    for(i = 0; i < size1; i++)
        merged[i] = arr1[i];
    for(j = 0; j < size2; j++)
        merged[i + j] = arr2[j];

    printf("Merged array: ");
    for(i = 0; i < size1 + size2; i++)
        printf("%d ", merged[i]);

    return 0;
}
