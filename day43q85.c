#include <stdio.h>

int main() {
    char line[100];      // array to store string
    int end = 0, temp;   // variables for counting and swapping
    char rev[100];       // another array for reversed string

    // Input string
    printf("Enter a string: ");
    gets(line);

    // Find length manually
    while(line[end] != '\0') {
        end++;
    }

    // Reverse by copying characters from end to start
    for(int i = 0; i < end; i++) {
        rev[i] = line[end - i - 1];
    }
    rev[end] = '\0';  // add null terminator

    // Display reversed string
    printf("Reversed string: %s\n", rev);

    return 0;
}

