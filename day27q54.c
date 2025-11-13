
 /* Write a program to print the following pattern:

   *
  ***
 *****
*******
 *****
  ***
   *
*/
#include <stdio.h>
int main() {
    int p, q, r;
    // upper pyramid
    for(p = 1; p <= 4; p++) {
        for(q = p; q < 4; q++)
            printf(" ");
        for(r = 1; r <= (2*p - 1); r++)
            printf("*");
        printf("\n");
    }
    // lower inverted pyramid
    for(p = 3; p >= 1; p--) {
        for(q = 4; q > p; q--)
            printf(" ");
        for(r = 1; r <= (2*p - 1); r++)
            printf("*");
        printf("\n");
    }
    return 0;
}
