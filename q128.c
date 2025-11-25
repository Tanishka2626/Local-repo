#include <stdio.h>
#include <ctype.h>   // for isalpha(), tolower()

int main() {
    char filename[100];
    FILE *fp;
    int ch;
    int vowels = 0, consonants = 0;

    printf("Enter filename: ");
    scanf("%s", filename);

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: File not found!\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {
        if (isalpha(ch)) {          // check if alphabet
            ch = tolower(ch);       // convert to lowercase
            if (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u')
                vowels++;
            else
                consonants++;
        }
    }

    fclose(fp);

    printf("\nVowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);

    return 0;
}
