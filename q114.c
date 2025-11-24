#include <stdio.h>
#include <string.h> // Required for strlen
#include <stdlib.h> // Required for general utilities

// Define a size for the character set. 256 covers all standard ASCII characters.
#define ASCII_SIZE 256

/**
 * @brief Finds the length of the longest substring without repeating characters.
 *
 * This function implements the O(N) Sliding Window approach. It uses a character
 * set array to store the index of the last seen position of each character.
 *
 * @param s The input string.
 * @return int The length of the longest substring with unique characters.
 */
int lengthOfLongestSubstring(char *s) {
    if (s == NULL || *s == '\0') {
        return 0; // Handle null or empty string
    }

    int n = strlen(s);
    int max_length = 0;
    
    // The 'char_set' array acts as a map to store the index of the last time
    // a character was seen. Initialize all to -1 (indicating not seen).
    int char_set[ASCII_SIZE];
    for (int i = 0; i < ASCII_SIZE; i++) {
        char_set[i] = -1;
    }

    int left = 0; // The left pointer of the sliding window

    // The 'right' pointer iterates through the string, expanding the window.
    for (int right = 0; right < n; right++) {
        int current_char_index = (int)s[right];

        // 1. Check for repetition: 
        // If the current character (s[right]) has been seen, AND its last seen index
        // is within the current window (i.e., >= left), we have a repetition.
        if (char_set[current_char_index] != -1 && char_set[current_char_index] >= left) {
            
            // Move the left pointer to the position *after* the previous occurrence
            // of the repeating character to shrink the window.
            left = char_set[current_char_index] + 1;
        }

        // 2. Update the character's last seen index:
        // Update the map with the current index of the character.
        char_set[current_char_index] = right;

        // 3. Update maximum length:
        // The current length is (right - left + 1).
        int current_length = right - left + 1;
        if (current_length > max_length) {
            max_length = current_length;
        }
    }

    return max_length;
}

// Main function to test the program
int main() {
    // --- Input 1 ---
    char *s1 = "abcabcbb";
    int result1 = lengthOfLongestSubstring(s1);
    printf("Input 1: s = \"%s\"\n", s1);
    printf("Output 1: %d\n", result1);
    printf("Explanation 1: The answer is \"abc\", with the length of 3.\n\n"); // Expected: 3

    // --- Input 2 ---
    char *s2 = "bbbbb";
    int result2 = lengthOfLongestSubstring(s2);
    printf("Input 2: s = \"%s\"\n", s2);
    printf("Output 2: %d\n", result2);
    printf("Explanation 2: The answer is \"b\", with the length of 1.\n\n"); // Expected: 1

    // --- Input 3 ---
    char *s3 = "pwwkew";
    int result3 = lengthOfLongestSubstring(s3);
    printf("Input 3: s = \"%s\"\n", s3);
    printf("Output 3: %d\n", result3);
    printf("Explanation 3: The answer is \"wke\", with the length of 3.\n\n"); // Expected: 3

    // --- Input 4 (Custom Test) ---
    char *s4 = "dvdf";
    int result4 = lengthOfLongestSubstring(s4);
    printf("Input 4: s = \"%s\"\n", s4);
    printf("Output 4: %d\n", result4); // Expected: 3 ("vdf")

    return 0;
}