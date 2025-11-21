#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for (int i = 0; i < n; i++) {
        int next = -1;

        // Find next greater element on the right
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[i]) {
                next = arr[j];
                break;
            }
        }

        // Print with comma (but no comma after last element)
        if (i == n - 1)
            printf("%d", next);
        else
            printf("%d, ", next);
    }

    return 0;
}
