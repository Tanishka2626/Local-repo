
/*Write a program to print the following pattern:
1
12
123
1234
12345
*/
#include <stdio.h>
int main() {
    int x, y; // x for rows, y for numbers
    for(x = 1; x <= 5; x++) {
        for(y = 1; y <= x; y++) {
            printf("%d", y);
        }
        printf("\n");
    }
    return 0;
}
