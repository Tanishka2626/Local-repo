#include <stdio.h>
#include <string.h>

int main() {
    char line[200];
    char temp[50];
    int i = 0, k = 0, end;

    printf("Enter a sentence: ");
    fgets(line, sizeof(line), stdin);

    // reading the sentence char by char
    while(line[i] != '\0') {

        if(line[i] != ' ' && line[i] != '\n') {
            temp[k] = line[i];
            k++;
        } 
        else {
            temp[k] = '\0';    // end current word

            // reverse the word
            for(end = k - 1; end >= 0; end--) {
                printf("%c", temp[end]);
            }
            printf(" ");

            k = 0;   // start collecting next word
        }
        i++;
    }

    // for last word (if no space at end)
    temp[k] = '\0';
    for(end = k - 1; end >= 0; end--) {
        printf("%c", temp[end]);
    }

    return 0;
}
