
/* Write a program to print the following pattern:
*****
*****
*****
*****
*****
*/
#include <stdio.h>

int main() {
    int row, col;   // row and column counters

    // Outer loop for rows
    for(row = 1; row <= 5; row++) {
        // Inner loop for columns
        for(col = 1; col <= 5; col++) {
            printf("*");
        }
        printf("\n");   // Move to the next line after each row
    }

    return 0;
}
