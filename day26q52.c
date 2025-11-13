/* Write a program to print the following pattern:

*

*
*
*

*
*
*
*
*

*
*
*

*
*/
#include <stdio.h>
int main() {
    int x, y;
    for(x = 1; x <= 5; x++) {
        for(y = 1; y <= x; y++) {
            printf("*\n");
        }
        printf("\n");
    }
    return 0;
}

