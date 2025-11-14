#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char str[100], ch;
    int i, count = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    printf("Enter character to count: ");
    scanf("%c", &ch);

    ch = tolower(ch);   // convert to lowercase once

    for(i = 0; str[i] != '\0'; i++) {
        if(tolower(str[i]) == ch) {  
            count++;
        }
    }

    printf("Frequency of '%c' = %d\n", ch, count);

    return 0;
}
