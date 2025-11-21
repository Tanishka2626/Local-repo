#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int a[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int candidate = 0, count = 0;

    for (int i = 0; i < n; i++) {
        if (count == 0)
            candidate = a[i];
        count += (a[i] == candidate) ? 1 : -1;
    }

    // verify
    count = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == candidate)
            count++;

    printf("%d", (count > n / 2) ? candidate : -1);
    return 0;
}
