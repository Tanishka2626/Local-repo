#include <stdio.h>
#include <string.h>

int main() {
    char s[100];
    int i, j, k;

    printf("Enter a string: ");
    fgets(s, sizeof(s), stdin);

    // remove newline
    s[strcspn(s, "\n")] = '\0';

    int len = strlen(s);

    // starting index i
    for(i = 0; i < len; i++) {
        // ending index j
        for(j = i; j < len; j++) {

            // print substring s[i..j]
            for(k = i; k <= j; k++) {
                printf("%c", s[k]);
            }
            printf("\n"); // next substring
        }
    }

    return 0;
}
