#include <stdio.h>

int main() {
    char text[150];    // to store the input string
    int i = 0;         // index counter
    int spaceCnt = 0, digitCnt = 0, specialCnt = 0;

    // Take string input
    printf("Enter a string: ");
    gets(text);

    // Go through each character
    while(text[i] != '\0') {
        if(text[i] == ' ') {
            spaceCnt++;  // count spaces
        }
        else if(text[i] >= '0' && text[i] <= '9') {
            digitCnt++;  // count digits
        }
        else if( (text[i] >= 'A' && text[i] <= 'Z') || 
                 (text[i] >= 'a' && text[i] <= 'z') ) {
            // do nothing for alphabets
        }
        else {
            specialCnt++; // everything else = special character
        }
        i++;
    }

    // Display the results
    printf("Number of spaces = %d\n", spaceCnt);
    printf("Number of digits = %d\n", digitCnt);
    printf("Number of special characters = %d\n", specialCnt);

    return 0;
}
