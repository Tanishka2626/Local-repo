//Count characters in a string without using built-in length functions.
#include <stdio.h>

int main() {
    char text[100];     // array to store the string
    int index = 0, count = 0;

    // Input string from user
    printf("Enter a string: ");
    gets(text);  // reads input including spaces (not recommended in real use, but ok for basic programs)

    // Count characters manually (stop when null character '\0' is found)
    while(text[index] != '\0') {
        count++;
        index++;
    }

    // Display result
    printf("Total number of characters in the string = %d\n", count);

    return 0;
}
