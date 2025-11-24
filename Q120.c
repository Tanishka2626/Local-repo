#include <stdio.h>
#include <string.h>  // For strlen()
#include <ctype.h>   // For isspace(), toupper(), tolower()

// Maximum size for the input string
#define MAX_STR_LEN 1000

/**
 * @brief Converts a string to Title Case (first letter of every word capitalized).
 *
 * The function modifies the string in-place.
 *
 * @param str The input string (will be modified).
 */
void toTitleCase(char *str) {
    if (str == NULL || *str == '\0') {
        return;
    }

    // Flag to indicate if the current character is at the start of a word.
    // It is true initially because the first character starts a word.
    int start_of_word = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        char current_char = str[i];

        if (isspace(current_char)) {
            // If the character is a space or punctuation, the next non-space
            // character will be the start of a new word.
            start_of_word = 1;
        } else if (start_of_word) {
            // If it's the start of a word, convert the character to uppercase.
            str[i] = toupper(current_char);
            start_of_word = 0; // Reset flag until the next separator is found.
        } else {
            // If it's inside a word, convert the character to lowercase.
            str[i] = tolower(current_char);
        }
    }
}

// Main function to test the program
int main() {
    // Note: We use fixed-size arrays here to allow in-place modification, 
    // as string literals (char *s = "...") cannot be modified.
    char s1[MAX_STR_LEN] = "I am trying to build logic.";
    char s2[MAX_STR_LEN] = "The classes are supposed to start early.";
    char s3[MAX_STR_LEN] = "We are going to look at 26 different test cases.";
    char s4[MAX_STR_LEN] = "MIXED CASE input TEST.";
    
    // --- Input 1 ---
    printf("Input 1:\nstr = %s\n", s1);
    toTitleCase(s1);
    printf("Output 1:\n%s\n\n", s1);

    // --- Input 2 ---
    printf("Input 2:\nstr = %s\n", s2);
    toTitleCase(s2);
    printf("Output 2:\n%s\n\n", s2);

    // --- Input 3 ---
    printf("Input 3:\nstr = %s\n", s3);
    toTitleCase(s3);
    printf("Output 3:\n%s\n\n", s3);
    
    // --- Custom Test 4 (Test case robustness) ---
    printf("Input 4 (Custom):\nstr = %s\n", s4);
    toTitleCase(s4);
    printf("Output 4:\n%s\n", s4); // Expected: Mixed Case Input Test.

    return 0;
}