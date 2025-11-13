//Find the second largest element in an array.
#include <stdio.h>
int main() {
    int a[50], n, i, max1, max2;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    max1 = max2 = a[0];

    for(i = 1; i < n; i++) {
        if(a[i] > max1) {
            max2 = max1;
            max1 = a[i];
        }
        else if(a[i] > max2 && a[i] != max1)
            max2 = a[i];
    }

    printf("Second largest element = %d", max2);

    return 0;
}
