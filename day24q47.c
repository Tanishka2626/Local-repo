/*Q47 (Nested Loops without Arrays/Strings)
Write a program to print the following pattern:
*
**
***
****
*****
*/
#include <stdio.h>
int main() {
    int r, c; // r for rows, c for columns
    for(r = 1; r <= 5; r++) {
        for(c = 1; c <= r; c++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
