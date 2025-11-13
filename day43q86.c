//Check if a string is a palindrome.
#include <stdio.h>

int main() {
    char word[100];
    int left = 0, right = 0;
    int isSame = 1;   // assume palindrome initially (1 = true)

    // Input the string
    printf("Enter a string: ");
    gets(word);

    // Find string length manually
    while(word[right] != '\0') {
        right++;
    }
    right--;  // point to last character index

    // Compare characters from both ends
    while(left < right) {
        if(word[left] != word[right]) {
            isSame = 0;  // not palindrome
            break;
        }
        left++;
        right--;
    }

    // Show result
    if(isSame)
        printf("The string is a PALINDROME.\n");
    else
        printf("The string is NOT a palindrome.\n");

    return 0;
}
