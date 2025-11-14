#include <stdio.h>
#include <string.h>

int main() {
    char line[200], temp[50];
    int i = 0, j = 0, bestLen = 0;
    char longest[50];

    printf("Enter a sentence: ");
    fgets(line, sizeof(line), stdin);

    // reading each character
    while(line[i] != '\0') {

        if(line[i] != ' ' && line[i] != '\n') {
            temp[j] = line[i];
            j++;
        }
        else {
            temp[j] = '\0';  // end current word

            if(strlen(temp) > bestLen) {
                bestLen = strlen(temp);
                strcpy(longest, temp); // store longest word
            }
            j = 0;   // reset for next word
        }
        i++;
    }

    // last word check (if not followed by space)
    temp[j] = '\0';
    if(strlen(temp) > bestLen) {
        strcpy(longest, temp);
    }

    printf("Longest word: %s\n", longest);

    return 0;
}
