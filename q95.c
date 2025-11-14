#include <stdio.h>
#include <string.h>

int main() {
    char a[100], b[100], combo[200];

    printf("Enter first string: ");
    fgets(a, sizeof(a), stdin);

    printf("Enter second string: ");
    fgets(b, sizeof(b), stdin);

    // removing newline if present
    a[strcspn(a, "\n")] = '\0';
    b[strcspn(b, "\n")] = '\0';

    // if lengths differ → cannot be rotation
    if(strlen(a) != strlen(b)) {
        printf("Not a rotation.\n");
        return 0;
    }

    // make a big string a+a (concatenation)
    strcpy(combo, a);
    strcat(combo, a);

    // check if b is inside combo
    if(strstr(combo, b) != NULL)
        printf("Strings are rotation of each other.\n");
    else
        printf("Not a rotation.\n");

    return 0;
}
