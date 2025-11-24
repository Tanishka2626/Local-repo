#include <stdio.h>
#include <string.h> // Required for strlen

// Define the size of the alphabet for lowercase English letters
#define ALPHABET_SIZE 26

/**
 * @brief Checks if two strings are valid anagrams of each other.
 * * The function uses a frequency counting array to track character counts.
 * It first verifies that both strings have the same length.
 * * @param s The first string.
 * @param t The second string.
 * @return int 1 if the strings are anagrams, 0 otherwise.
 */
int isAnagram(char *s, char *t) {
    int len_s = strlen(s);
    int len_t = strlen(t);

    // 1. Initial Check: If lengths are different, they cannot be anagrams.
    if (len_s != len_t) {
        return 0; // Not Anagram
    }

    // Array to store the frequency difference for each character ('a' through 'z').
    // Index 0 corresponds to 'a', Index 1 to 'b', and so on.
    int counts[ALPHABET_SIZE] = {0};

    // 2. Count Frequencies: Iterate through both strings simultaneously.
    for (int i = 0; i < len_s; i++) {
        // Increment count for characters in s
        // (s[i] - 'a') gives the index (0 for 'a', 1 for 'b', etc.)
        counts[s[i] - 'a']++;

        // Decrement count for characters in t
        counts[t[i] - 'a']--;
    }

    // 3. Final Check: If s and t are anagrams, all counts must be zero.
    // We only need to check the array. If any count is non-zero, it means a character
    // appeared more times in one string than the other.
    for (int i = 0; i < ALPHABET_SIZE; i++) {
        if (counts[i] != 0) {
            return 0; // Not Anagram
        }
    }

    // If all checks pass, they are anagrams.
    return 1; // Anagram
}

// Main function to test the program
int main() {
    // --- Input 1 ---
    char *s1 = "anagram";
    char *t1 = "nagaram";
    int result1 = isAnagram(s1, t1);
    
    printf("Input 1: s = \"%s\", t = \"%s\"\n", s1, t1);
    printf("Output 1: %s\n", result1 ? "Anagram" : "Not Anagram");
    printf("Explanation 1: The strings contain the same characters with the same frequencies.\n\n");

    // --- Input 2 ---
    char *s2 = "rat";
    char *t2 = "car";
    int result2 = isAnagram(s2, t2);
    
    printf("Input 2: s = \"%s\", t = \"%s\"\n", s2, t2);
    printf("Output 2: %s\n", result2 ? "Anagram" : "Not Anagram");
    printf("Explanation 2: The strings do not contain the same characters.\n\n");
    
    // --- Custom Test 3 (Different lengths) ---
    char *s3 = "a";
    char *t3 = "ab";
    int result3 = isAnagram(s3, t3);
    
    printf("Input 3: s = \"%s\", t = \"%s\"\n", s3, t3);
    printf("Output 3: %s\n", result3 ? "Anagram" : "Not Anagram");
    printf("Explanation 3: Lengths are different (1 vs 2).\n");

    return 0;
}