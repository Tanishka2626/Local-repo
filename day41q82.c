//Print each character of a string on a new line.
#include <stdio.h>

int main() {
    char message[100];   // array to hold string
    int i = 0;

    // Input string
    printf("Enter a string: ");
    gets(message);

    // Print each character on a new line
    printf("Characters in the string are:\n");
    while(message[i] != '\0') {
        printf("%c\n", message[i]);
        i++;
    }

    return 0;
}
