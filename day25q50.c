/* Write  program to print the following pattern:
*****
 ****
  ***
   **
    *
 */
#include <stdio.h>
int main() {
    int r, s, k;
    for(r = 5; r >= 1; r--) {
        for(s = 5; s > r; s--) {
            printf(" ");
        }
        for(k = 1; k <= r; k++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
