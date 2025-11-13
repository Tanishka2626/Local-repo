#include <stdio.h>

int main() {
    char word[100];   // to store the string
    int i = 0;

    // Input the string
    printf("Enter a lowercase string: ");
    gets(word);

    // Convert lowercase letters to uppercase manually
    while(word[i] != '\0') {
        if(word[i] >= 'a' && word[i] <= 'z') {
            word[i] = word[i] - 32;  // ASCII difference between lowercase and uppercase
        }
        i++;
    }

    // Display the converted string
    printf("Uppercase string: %s\n", word);

    return 0;
}
