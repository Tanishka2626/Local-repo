//Write  program to find the 1’s complement of a binary number and print it.
#include <stdio.h>
int main() {
    long n, flipped = 0;
    int bit, pos = 1;

    printf("Enter a binary number: ");
    scanf("%ld", &n);

    while(n > 0) {
        bit = n % 10;               // pick last bit
        flipped += (bit == 0 ? 1 : 0) * pos; // flip using ternary operator
        n /= 10;                    // remove last bit
        pos *= 10;                  // move position
    }

    printf("1's complement = %ld\n", flipped);
    return 0;
}

