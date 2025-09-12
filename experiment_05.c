#include <stdio.h>

int main() {
    int limit = 2000;  // you can change the limit
    int a, b, c, d;
    int result1, result2;

    printf("Ramanujan Numbers up to %d are:\n", limit);

    for (a = 1; a <= 50; a++) {
        for (b = a; b <= 50; b++) {
            result1 = a*a*a + b*b*b;

            for (c = a+1; c <= 50; c++) {
                for (d = c; d <= 50; d++) {
                    result2 = c*c*c + d*d*d;

                    if (result1 == result2 && result1 <= limit) {
                        printf("%d = %d^3 + %d^3 = %d^3 + %d^3\n",
                               result1, a, b, c, d);
                    }
                }
            }
        }
    }

    return 0;
}