// Count positive, negative, and zero elements in an array.

#include <stdio.h>
int main() {
    int num[30], total, i;
    int pos = 0, neg = 0, zero = 0;

    printf("Enter count: ");
    scanf("%d", &total);

    for(i = 0; i < total; i++) {
        scanf("%d", &num[i]);
        if(num[i] > 0)
            pos++;
        else if(num[i] < 0)
            neg++;
        else
            zero++;
    }

    printf("Positive=%d Negative=%d Zero=%d", pos, neg, zero);
    return 0;
}
