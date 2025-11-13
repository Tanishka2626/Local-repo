// Find the digit that occurs the most times in an integer number.

#include <stdio.h>
int main() {
    long num, temp;
    int digit, freq[10] = {0}, max = 0, i;

    printf("Enter number: ");
    scanf("%ld", &num);

    temp = num;
    while(temp != 0) {
        digit = temp % 10;
        freq[digit]++;
        temp /= 10;
    }

    for(i = 0; i < 10; i++) {
        if(freq[i] > freq[max])
            max = i;
    }

    printf("Most frequent digit = %d", max);
    return 0;
}
