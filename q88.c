#include <stdio.h>

int main() {
    char info[150];   // input string
    int p = 0;        // loop index

    // Input the string
    printf("Enter a string: ");
    gets(info);

    // Traverse and replace each space with '-'
    while(info[p] != '\0') {
        if(info[p] == ' ') {
            info[p] = '-';
        }
        p++;
    }

    // Display modified string
    printf("String after replacing spaces with hyphens:\n");
    printf("%s\n", info);

    return 0;
}
