// Reverse an array without taking extra space.
#include <stdio.h>
int main() {
    int set[50], n, start, end, temp;

    printf("Enter size: ");
    scanf("%d", &n);

    for(start = 0; start < n; start++)
        scanf("%d", &set[start]);

    for(start = 0, end = n - 1; start < end; start++, end--) {
        temp = set[start];
        set[start] = set[end];
        set[end] = temp;
    }

    printf("Reversed array: ");
    for(start = 0; start < n; start++)
        printf("%d ", set[start]);

    return 0;
}
