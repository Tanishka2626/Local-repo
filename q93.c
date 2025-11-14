#include <stdio.h>
#include <string.h>

int main() {
    char s1[100], s2[100];
    int box1[26] = {0}, box2[26] = {0};
    int i;

    printf("Enter first string: ");
    fgets(s1, sizeof(s1), stdin);

    printf("Enter second string: ");
    fgets(s2, sizeof(s2), stdin);

    // counting letters of s1
    for(i = 0; s1[i] != '\0'; i++) {
        if(s1[i] >= 'a' && s1[i] <= 'z')
            box1[s1[i] - 'a']++;
        else if(s1[i] >= 'A' && s1[i] <= 'Z')
            box1[s1[i] - 'A']++;   // converting uppercase
    }

    // counting letters of s2
    for(i = 0; s2[i] != '\0'; i++) {
        if(s2[i] >= 'a' && s2[i] <= 'z')
            box2[s2[i] - 'a']++;
        else if(s2[i] >= 'A' && s2[i] <= 'Z')
            box2[s2[i] - 'A']++;
    }

    // comparing both arrays
    for(i = 0; i < 26; i++) {
        if(box1[i] != box2[i]) {
            printf("Strings are NOT anagrams.\n");
            return 0;
        }
    }

    printf("Strings are anagrams.\n");
    return 0;
}
