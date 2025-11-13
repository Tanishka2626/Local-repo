/*  (Nested Loops without Arrays/Strings)
Write a program to print the following pattern:
*
***
*****
*******
*********
*******
*****
***
*/
#include <stdio.h>
int main() {
    int a, b;
    // upper part
    for(a = 1; a <= 5; a++) {
        for(b = 1; b <= (2*a - 1); b++) {
            printf("*");
        }
        printf("\n");
    }
    // lower part
    for(a = 4; a >= 1; a--) {
        for(b = 1; b <= (2*a - 1); b++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
