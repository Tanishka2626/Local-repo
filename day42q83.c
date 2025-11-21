//Count vowels and consonants in a string.
#include <stdio.h>

int main() {
    char sentence[100];   // to store the input string
    int i = 0, vowels = 0, consonants = 0;

    // Input the string
    printf("Enter a string: ");
    gets(sentence);  // reads input (use fgets() for safer input in real code)

    // Traverse each character of the string
    while(sentence[i] != '\0') {
        char ch = sentence[i];

        // Check if the character is an alphabet
        if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {

            // Check if the character is a vowel
            if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ||
               ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowels++;
            } 
            else {
                consonants++;
            }
        }

        i++;
    }

    // Display results
    printf("Number of vowels = %d\n", vowels);
    printf("Number of consonants = %d\n", consonants);

    return 0;
}
