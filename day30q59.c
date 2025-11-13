//Count even and odd numbers in an array.
#include <stdio.h>
int main() {
    int value[20], n, i, even = 0, odd = 0;
    printf("Enter how many: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        scanf("%d", &value[i]);
        if(value[i] % 2 == 0)
            even++;
        else
            odd++;
    }

    printf("Even = %d, Odd = %d", even, odd);
    return 0;
}
